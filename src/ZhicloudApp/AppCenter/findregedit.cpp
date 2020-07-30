#include "findregedit.h"
#include <QApplication>
#include "AppCommFun.h"
#include "AppDatabase/AppCenterDatabase.h"
#include <QStandardPaths>
#include <QDir>
#include <QProcess>
#include <QCryptographicHash>
#include <QSettings>
#include <QVector>
#include <tlhelp32.h>// for CreateToolhelp32Snapshot
#include <Psapi.h>   // for GetModuleFileNameEx
#include "Database.h"

extern UserInfoStruct app_userInfo;

FindRegedit::FindRegedit(QObject *parent, AppDataInfo* pData, int model)
	: QThread(parent)
	, m_pData(pData)
	, m_model(model)
{


}

FindRegedit::~FindRegedit()
{

}
void FindRegedit::run()
{
	int time = 60;
	QVector<SOFT_INFO> softInfoList;
	m_fileName = m_pData->m_strAppName;
	if (m_model == 0)//安装查询
	{
		bool flag	=	true;
		while(flag)
		{
			softInfoList.clear();
			AppCommFun::GetSoftInfo(softInfoList);
			SOFT_INFO softInfo ;

			for(int i = 0; i < softInfoList.count(); i ++)
			{
				softInfo = softInfoList.at(i);
				if(softInfo.m_strSoftName.contains(m_fileName,Qt::CaseSensitive))
				{
					if (!m_pData->m_bAppType)
					{
						QString	strInstallLocation	=	softInfo.m_strInstallLocation;
						if (strInstallLocation	==	"")
						{
							break;
						}
						strInstallLocation.replace("\\","/");
						QString	strTemp	=	strInstallLocation.right(1);
						if (strTemp	==	"/")
						{
							strInstallLocation	=	strInstallLocation.mid(0,strInstallLocation.length()-1);
						}
						QString	strExeFullPath	=	strInstallLocation	+	"/" + m_pData->m_strAppExecName;
						QFileInfo	info(strExeFullPath);
						if (info.isFile())
						{
							m_pData->m_strAppExecPathUrl = strExeFullPath;
							m_pData->m_strAppUninstallPath = softInfo.m_strUninstallPth;
						}
						
					}

					//发送 文件名和安装路径
					emit installationCompleteSiganl(softInfo.m_strInstallLocation,m_pData);
					flag = false;
					break;
				}
			}
			if (flag)
			{
				QString	strInstall;
				if (AppCommFun::queryDeskTop(m_fileName, strInstall))
				{
					if (!m_pData->m_bAppType)
					{
						strInstall.replace("\\", "/");
						m_pData->m_strAppExecPathUrl = strInstall;
						emit installationCompleteSiganl(strInstall, m_pData);
						flag = false;
						break;
					}
				}
			}
			time--;
			sleep(5);
			if (time <= 0)
			{
				emit installationCompleteSiganl("", m_pData);
				break;
			}
		}
	}
	else if (m_model == 1)//卸载查询
	{
		bool flag	=	false; 
		while(!flag)
		{
			softInfoList.clear();
			AppCommFun::GetSoftInfo(softInfoList);
			QString strApps;
			SOFT_INFO softInfo ;
			int i	=	0;
			for(; i < softInfoList.count(); i++)
			{
				softInfo = softInfoList.at(i);
				if (softInfo.m_strSoftName.contains(m_fileName, Qt::CaseSensitive))
				{
					time--;
					break;
				}
			}
			if (i == softInfoList.count())
			{
				flag	=	true;
				emit uninstallationCompleteSiganl(m_pData);
				break;
			}
			time--;
			sleep(5);
			if (time <= 0)
			{
				break;
			}
		}
	}
}


//重新查找应用   
void FindRegedit::findPath(bool &isHave)
{
	if (isHave)
	{

		QVector<SOFT_INFO> softInfoList;
		softInfoList.clear();
		AppCommFun::GetSoftInfo(softInfoList);
		SOFT_INFO softInfo;
		for (int i = 0; i < softInfoList.count(); i++)
		{
			softInfo = softInfoList.at(i);
			
			if (softInfo.m_strSoftName.contains(m_pData->m_strAppName, Qt::CaseSensitive))
			{
				if (!m_pData->m_bAppType)
				{
					QString	strInstallLocation = softInfo.m_strInstallLocation;
					if (strInstallLocation == "")
					{
						isHave = false;
						return;
					}
					strInstallLocation.replace("\\", "/");
					QString	strTemp = strInstallLocation.right(1);
					if (strTemp == "/")
					{
						strInstallLocation = strInstallLocation.mid(0, strInstallLocation.length() - 1);
					}
					QString	strExeFullPath = strInstallLocation + "/" + m_pData->m_strAppExecName;
					QFileInfo	info(strExeFullPath);
					if (info.isFile())
					{
						m_pData->m_strAppExecPathUrl = strExeFullPath;
						m_pData->m_strAppUninstallPath = softInfo.m_strUninstallPth;
					}
				}
				isHave = true;
				return;
			}
		}
	}
	QString	strInstall;
	if (AppCommFun::queryDeskTop(m_pData->m_strAppName, strInstall))
	{
		if (!m_pData->m_bAppType)
		{
			strInstall.replace("\\", "/");
			m_pData->m_strAppExecPathUrl = strInstall;

			isHave = true;
			return;
		}
	}
	isHave = false;
	return;
}


UnInstallThread::UnInstallThread(AppDataInfo	pData, QObject *parent)
	: QThread(parent), m_pData(pData)
{

}

UnInstallThread::~UnInstallThread()
{

}

void UnInstallThread::run()
{
	//判断 是否安装 如果未安装  直接卸载完成
	if (AppCommFun::isSoftInstall(&m_pData))
	{
		QString strUninstallPath = m_pData.m_strAppUninstallPath;
		if (strUninstallPath != "")
		{
			int index = strUninstallPath.indexOf(".exe");
			QString path = strUninstallPath.left(index + 4);
			path.replace("\"", "");
			QString strpram = strUninstallPath.mid(index + 5);
			strpram.replace("\"", "");
			strpram.trimmed();
			QStringList pram = strpram.split(" ");
			QProcess *ap = new QProcess(NULL);
			//ap->startDetached(path, pram);
			//获取当前文件的MD5
			QString fileMd5 = getFileMd5(path);
			if (strpram.isEmpty())
			{
				ap->setProgram(strUninstallPath);
				ap->start();
			}
			else
			{
				ap->start(strUninstallPath);
			}
			
			//ap->closeWriteChannel();
			//QString tempStr = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
			ap->waitForStarted();
			ap->waitForFinished(-1);
			
			if (AppCommFun::isSoftInstall(&m_pData))
			{
				//查找是否有临时文件存在  解决卸载两次的情况
				sleep(3); //部分电脑 程序还没启动就去查询pid 查询不到 给程序启动时间 2秒
				findTemporary(fileMd5);
				if (AppCommFun::isSoftInstall(&m_pData))
				{
					emit uninstallationCompleteSiganl(m_pData, false);
					emit removeUninstallThread();
					return;
				}
			}
		}
	}
	
	m_pData.m_bAppIsInstall = false;
	AppCenterDatabase::instance()->updateApp( m_pData, true);
	emit uninstallationCompleteSiganl(m_pData, true);
	emit removeUninstallThread();

}

void UnInstallThread::findTemporary(QString fileMd5)
{
	//获取临时文件MD5
	QString temPath =  QStandardPaths::writableLocation(QStandardPaths::TempLocation);
	temPath.append("/~nsu.tmp");
	QDir dir(temPath);
	while (1)
	{
		QStringList tempNameList;
		foreach(QFileInfo mfi, dir.entryInfoList())
		{
			if (mfi.isFile())
			{
				QString fileInfoName = mfi.fileName();
				QString temMd5 = getFileMd5(mfi.absolutePath() + "\\" + fileInfoName);
				if (fileMd5 == temMd5)
				{
					//有可能出现多个 Md5相同的文件
					tempNameList.append(mfi.fileName());
				}
			}
		}

		//通过名字获取 pid
		if (tempNameList.size())
		{
			sleep(3);
			bool havePid = false;
			for each (QString tempName in tempNameList)
			{
				HWND pid = GetProcessID(tempName.toStdWString().c_str());
				if (pid)
				{
					havePid = true;
					continue;
				}
			}
			if (havePid)
			{
				sleep(3);
				continue;
			}
		}
		return;
	}
}

QString UnInstallThread::getFileMd5(QString fileNamePath)
{
	QFile theFile(fileNamePath);
	theFile.open(QIODevice::ReadOnly);
	QByteArray ba = QCryptographicHash::hash(theFile.readAll(), QCryptographicHash::Md5);
	theFile.close();
	QString fileMd5 = ba.toHex().constData();
	return fileMd5.toUpper();
}

HWND UnInstallThread::GetProcessID(LPCWSTR procName)//procName 被调用进程名称
{	
	DWORD iProcID = 0;	
	PROCESSENTRY32 pEntry = { sizeof(PROCESSENTRY32) };
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);	
	if (hSnapshot != INVALID_HANDLE_VALUE)	
	{		
		if (Process32First(hSnapshot, &pEntry))		
		{			
			while (Process32Next(hSnapshot, &pEntry))			
			{				
				if (lstrcmpi(procName, pEntry.szExeFile) == 0)				
				{					
					iProcID = pEntry.th32ProcessID;					
					CloseHandle(hSnapshot);					
					break;				
				}			
			}		
		}	
	}	
	HWND hwnd = ::GetTopWindow(NULL);	
	while (hwnd)	
	{		
		DWORD pid = 0;		
		DWORD dwProcessId = GetWindowThreadProcessId(hwnd, &pid);		
		if (dwProcessId != 0)		
		{			
			if (pid == iProcID)			
			{				
				return hwnd;			
			}		
		}		
		hwnd = ::GetNextWindow(hwnd, GW_HWNDNEXT);	
	}	
	return NULL;
}

bool UnInstallThread::isHaveUninstall(QString appId)
{
	return m_pData.m_strAppId == appId;
}


//查找 应用 版本 和执行路径
FindAppPath::FindAppPath(QObject *parent)
	: QThread(parent)
{

}

FindAppPath::~FindAppPath()
{

}

void FindAppPath::run()
{
	bool isSend = false;//是否发送信号给主函数
	QList<AppDataInfo > updateAppList;
	if (AppCenterDatabase::instance()->findClassAppList( updateAppList))
	{
		foreach(AppDataInfo pData, updateAppList)
		{
			if (m_runReturn) return;
			if (!pData.m_bAppType && !pData.m_strAppDownloadUrl.isEmpty())
			{
				//这样 软件版本不会时时更新
				QString installPath = pData.m_strAppExecPathUrl;
				QFileInfo fileInfo(installPath);
	
				if (installPath.isEmpty() || !fileInfo.exists())//|| !QFileInfo::exists(installPath) || pData.m_strAppCurrentVerson.isEmpty())
				{
					if (AppCommFun::isSoftInstall(&pData)){
						isSend = true;
						//读取当前登陆的税号 的开票软件版本
						if (pData.m_strAppName == QString::fromLocal8Bit("开票软件") || pData.m_strAppAlias == QString::fromLocal8Bit("开票软件"))
						{
							QString	strConfigPath = app_userInfo.m_strTaxNumber;						//！企业税号
							QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
							QStringList groupsList = settings->childGroups();
							foreach(QString group, groupsList)
							{
								settings->beginGroup(group);
								QString strCode = settings->value("code", QVariant()).toString();			//！企业税号
								strCode = strCode.replace(" ", "");
								QString machine = settings->value("machine", QVariant()).toString();
								QString strConfigMachine = app_userInfo.m_strMachine;
								if (strCode == strConfigPath && strConfigMachine == machine)//如果税号相同
								{
									pData.m_strAppCurrentVerson = settings->value("Version", QVariant()).toString();		//！版本
									pData.m_strAppCurrentVerson.replace("V", "");
									pData.m_strAppCurrentVerson.replace("v", "");
									pData.m_strAppCurrentVerson.replace(" ", "");
								}
								settings->endGroup();
							}
						}
						AppCenterDatabase::instance()->updateApp(pData);
					}
				}
			}
		}
		if (isSend) emit filishFindAppPathSignal();
	}
}
