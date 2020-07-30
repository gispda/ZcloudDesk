#include "CheckServiceThread.h"
#include "Database.h"
#include <QSettings>
#include "HttpInterface.h"
#include <qt_windows.h>
#include <QFileInfo>
#include <QApplication>
#include <QStandardPaths>
#include <QDir>
#include "ZcloudBigData.h"
#include "io.h"
#include "rs.h"

CheckServiceThread::CheckServiceThread(QString strUid, QString strToken, QString strHzsId,QObject *parent)
	: QThread(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
	, m_strHzsId(strHzsId)
{
}

CheckServiceThread::~CheckServiceThread()
{
}

void CheckServiceThread::run()
{
	sleep(1);
	OperService(true);

	sleep(1);
	submitTaxs();

	sleep(1);
	submitDeskApp();

	m_bBreak = true;

	QDateTime last = QDateTime::currentDateTime();
	QDateTime now;

	while (true)
	{
		for (int i = 0; i < 36; ++i)
		{
			sleep(5);
			QMutexLocker locker(&m_mutex);
			if (!m_bBreak)
			{
				return;
			}
		}
		OperService(true);	

		/*now = QDateTime::currentDateTime();
		if (last.msecsTo(now) >= 60 * 60 * 1000 && now.time().hour()	==	17)
		{
			QString strlogFileName = QString("%1.txt").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
			uploadFileToQiniu(QApplication::applicationDirPath() + "/logs/" + strlogFileName);
			last = now;
		}*/
	}
}

void CheckServiceThread::submitTaxs()
{
	QStringList taxInfoList;
	QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
	QStringList groupsList = settings->childGroups();
	foreach(QString group, groupsList)
	{
		settings->beginGroup(group);
		QString strCode = settings->value("code", QVariant()).toString();			//！企业税号
		QString strMachine = settings->value("machine", QVariant()).toString();		//！主机号分机号
		strCode = strCode.replace(" ", "");
		if (strCode.length() != 18 || strCode.left(1) != "9")
		{
			settings->endGroup();
			continue;
		}
		if (Database::GetInstance()->findTaxIsExist(strCode))
		{
			settings->endGroup();
			continue;
		}
		settings->endGroup();
		taxInfoList.append(strCode);
		if (taxInfoList.size() == 20)
		{
			break;
		}
	}
	delete settings;

	if (taxInfoList.size() > 0)
	{
		QString strTaxs;
		QStringList::iterator	itr = taxInfoList.begin();
		for (; itr != taxInfoList.end(); ++itr)
		{
			strTaxs += (QString)itr->data();
			strTaxs += ",";
		}
		strTaxs = strTaxs.left(strTaxs.length() - 1);
		Database::GetInstance()->insertTaxInfo(taxInfoList);

		HttpInterface hInter;
		QString    strRet;
		hInter.winHttpTaxResponse(m_strUid, m_strToken, strTaxs, strRet);
	}
}

void CheckServiceThread::stopImmediately()
{
	QMutexLocker	locker(&m_mutex);
	this->m_bBreak = false;
}

void CheckServiceThread::OperService(bool bStart)
{
	QString strServiceName = "zyservice";
	SC_HANDLE hSCM = ::OpenSCManager(NULL, // local machine
		NULL, // ServicesActive database
		SC_MANAGER_ALL_ACCESS); // full access
	if (NULL == hSCM)
	{
		return;
	}
	SC_HANDLE hService = ::OpenService(hSCM, strServiceName.toStdWString().data(), SERVICE_ALL_ACCESS);
	if (hService)
	{
		SERVICE_STATUS ssStatus;
		::QueryServiceStatus(hService, &ssStatus);//查看该Service的状态
		if (bStart)
		{
			if (ssStatus.dwCurrentState == SERVICE_STOPPED)
			{
				::StartService(hService, 0, NULL);
			}
		}
		else
		{
			if (ssStatus.dwCurrentState != SERVICE_STOPPED)
			{
				::ControlService(hService, SERVICE_CONTROL_STOP, &ssStatus);
			}
		}

		::CloseServiceHandle(hService);
	}
	::CloseServiceHandle(hSCM);
}

void CheckServiceThread::uploadFileToQiniu(QString qstrLocalFile)
{
	QFileInfo info(qstrLocalFile);
	if (!info.isFile())
	{
		return;
	}
	QString qstrDescFile = QString("devEnv/%1/%2/%3").arg(m_strHzsId).arg(m_strUid).arg(info.fileName());
	QByteArray baDescFile = qstrDescFile.toLocal8Bit();
	std::string strDescFile = std::string(baDescFile);

	QByteArray baLocalFile = qstrLocalFile.toLocal8Bit();
	std::string strLocalFile = std::string(baLocalFile);

	Qiniu_Client client;
	// 初始化
	Qiniu_Global_Init(-1);
	Qiniu_Client_InitNoAuth(&client, 1024);
	
	//!设置上次凭证
	Qiniu_Mac mac;
	mac.accessKey = "dVsVZoLFbgXuu7KgEsY8-n_2zsBLFW_Isdyhm8uh";
	mac.secretKey = "8y3sfbCFa8vvz4dqxdEWd9p_0_CMHYi-uCCsjS2c";
	char* bucket = "zhicloud-desk-logs";

	//!获取上传token
	Qiniu_RS_PutPolicy putPolicy;
	Qiniu_Zero(putPolicy);
	putPolicy.scope = bucket;
	char *uptoken = Qiniu_RS_PutPolicy_Token(&putPolicy, &mac);
	Qiniu_Use_Zone_Huanan(Qiniu_False);

	Qiniu_Io_PutRet putRet;
	Qiniu_Error error = Qiniu_Io_PutFile(&client, &putRet, uptoken, strDescFile.c_str(), strLocalFile.c_str(), NULL);
	if (error.code != 200)
	{
		qDebug("zcd-0x10000002:Upload File %s To %s:%s error.\n", strLocalFile.c_str(), bucket, strDescFile.c_str());
	}
	Qiniu_Free(uptoken);
	Qiniu_Client_Cleanup(&client);
	Qiniu_Global_Cleanup();
}

void CheckServiceThread::submitDeskApp()
{
	//上报桌面快捷方式 一次报10个

	QList<StLnkNameExeName > oldStLnkExeList;
	QStringList linExeList;
	if (Database::GetInstance()->findLnkExeName(oldStLnkExeList))
	{
		for each (StLnkNameExeName stLnkNameExeName in oldStLnkExeList)
		{
			linExeList << stLnkNameExeName.strExeName;
		}
	}
	

	QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
	QDir dir(desktop_path);
	QFileInfoList file_list = dir.entryInfoList(QDir::Files);

	QFileInfoList::iterator itr = file_list.begin();
	for (; itr != file_list.end(); ++itr)
	{
		QFileInfo	fileInfo = (*itr);
		if (fileInfo.isSymLink() || fileInfo.suffix() == "lnk")
		{
			QString lnk_name = fileInfo.fileName();
			QString exe_Path = fileInfo.symLinkTarget();
			if (!lnk_name.isEmpty() && !exe_Path.isEmpty())
			{
				QFileInfo exeFileInfo(exe_Path);
				QString exe_name = exeFileInfo.fileName();
				if (!exe_name.isEmpty())
				{
					if (!linExeList.contains(exe_name))
					{
						StLnkNameExeName stLnkNameExeName;
						stLnkNameExeName.strLnkName = lnk_name;
						stLnkNameExeName.strExeName = exe_name;
						stLnkNameExeName.isUp = false;
						if (!Database::GetInstance()->replaceLnkExeName(stLnkNameExeName))
						{
							return;
						}
					}
					//qDebug() << "lnk_name" << lnk_name.toStdString().c_str() << "exe_name" << exe_name.toStdString().c_str();
				}
			}
		}
	}

	QList<StLnkNameExeName > uploadStLnkExeList;
	if (!Database::GetInstance()->findLnkExeName(uploadStLnkExeList))
	{
		return;
	}

	int uploadStSize = 0;
	for each (StLnkNameExeName stLnkNameExeName in uploadStLnkExeList)
	{
		if (uploadStSize >= 10) break;
		if (!stLnkNameExeName.isUp)
		{
			stLnkNameExeName.isUp = true;
			if (Database::GetInstance()->replaceLnkExeName(stLnkNameExeName))
			{
				uploadStSize++;
				QString lnk_name = stLnkNameExeName.strLnkName;
				QString exe_Path = stLnkNameExeName.strExeName;
				lnk_name = QString(lnk_name.toUtf8().toBase64());
				exe_Path = QString(exe_Path.toUtf8().toBase64());
				ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "UPD001", QString("%1-%2").arg(lnk_name).arg(exe_Path));
			}
		}
	}
}
