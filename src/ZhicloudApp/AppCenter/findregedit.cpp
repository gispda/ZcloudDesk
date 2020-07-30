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
	if (m_model == 0)//��װ��ѯ
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

					//���� �ļ����Ͱ�װ·��
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
	else if (m_model == 1)//ж�ز�ѯ
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


//���²���Ӧ��   
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
	//�ж� �Ƿ�װ ���δ��װ  ֱ��ж�����
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
			//��ȡ��ǰ�ļ���MD5
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
				//�����Ƿ�����ʱ�ļ�����  ���ж�����ε����
				sleep(3); //���ֵ��� ����û������ȥ��ѯpid ��ѯ���� ����������ʱ�� 2��
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
	//��ȡ��ʱ�ļ�MD5
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
					//�п��ܳ��ֶ�� Md5��ͬ���ļ�
					tempNameList.append(mfi.fileName());
				}
			}
		}

		//ͨ�����ֻ�ȡ pid
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

HWND UnInstallThread::GetProcessID(LPCWSTR procName)//procName �����ý�������
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


//���� Ӧ�� �汾 ��ִ��·��
FindAppPath::FindAppPath(QObject *parent)
	: QThread(parent)
{

}

FindAppPath::~FindAppPath()
{

}

void FindAppPath::run()
{
	bool isSend = false;//�Ƿ����źŸ�������
	QList<AppDataInfo > updateAppList;
	if (AppCenterDatabase::instance()->findClassAppList( updateAppList))
	{
		foreach(AppDataInfo pData, updateAppList)
		{
			if (m_runReturn) return;
			if (!pData.m_bAppType && !pData.m_strAppDownloadUrl.isEmpty())
			{
				//���� ����汾����ʱʱ����
				QString installPath = pData.m_strAppExecPathUrl;
				QFileInfo fileInfo(installPath);
	
				if (installPath.isEmpty() || !fileInfo.exists())//|| !QFileInfo::exists(installPath) || pData.m_strAppCurrentVerson.isEmpty())
				{
					if (AppCommFun::isSoftInstall(&pData)){
						isSend = true;
						//��ȡ��ǰ��½��˰�� �Ŀ�Ʊ����汾
						if (pData.m_strAppName == QString::fromLocal8Bit("��Ʊ���") || pData.m_strAppAlias == QString::fromLocal8Bit("��Ʊ���"))
						{
							QString	strConfigPath = app_userInfo.m_strTaxNumber;						//����ҵ˰��
							QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
							QStringList groupsList = settings->childGroups();
							foreach(QString group, groupsList)
							{
								settings->beginGroup(group);
								QString strCode = settings->value("code", QVariant()).toString();			//����ҵ˰��
								strCode = strCode.replace(" ", "");
								QString machine = settings->value("machine", QVariant()).toString();
								QString strConfigMachine = app_userInfo.m_strMachine;
								if (strCode == strConfigPath && strConfigMachine == machine)//���˰����ͬ
								{
									pData.m_strAppCurrentVerson = settings->value("Version", QVariant()).toString();		//���汾
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
