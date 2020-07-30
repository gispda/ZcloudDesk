//管理应用中心的下载 

#include "DownLoadManager.h"
//#include "interface/SrvInterface.h"
//#include <GetInformationInterface.h>
//#include "commDefine/GetInfomation.h"
#include "AppCommFun.h"
//#include "AppCenterComponent.h"
#include "AppDatabase/AppCenterDatabase.h"
#include "RightClassAppWidget.h"
#include <QSettings>
#include <QTextCodec>
#include "Database.h"

extern UserInfoStruct app_userInfo;

DownLoadManager::DownLoadManager(QObject *parent)
	: QObject(parent)
{
	load();
}

DownLoadManager::~DownLoadManager()
{

}
void  DownLoadManager::beginDownload(AppDownLoadThread *m_pDownloadThread, AppDataInfo pData, QString filename, qint64 fileSize, qint64 totalSize)
{
	RightClassAppWidget *ptr = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance()); // 下载完成只链接一次
	if (ptr)
	{
		connect(m_pDownloadThread, SIGNAL(installFinishAdd(AppDataInfo)), ptr, SLOT(installUnnstallSucessed(AppDataInfo)), Qt::QueuedConnection);
		connect(m_pDownloadThread, SIGNAL(closeDowloadSignal(QString)), ptr, SLOT(flushButton(QString)));
	}

	connect(m_pDownloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), this, SLOT(save()));
	m_pDownloadThread->setParent(this);
	m_pDownloadThreads.append(m_pDownloadThread);
	//m_pDownloadThread->setDownInto(true);

	m_pDownloadThread->setDownloadValue(pData.m_strAppDownloadUrl, filename, fileSize, totalSize);
	
}

void  DownLoadManager::beginUninstall(UnInstallThread *uninstallThread)
{

	uninstallThread->setParent(this);
	m_pUnInstallThreads.append(uninstallThread);
	connect(uninstallThread, SIGNAL(removeUninstallThread()), this, SLOT(remvoUnstallThread()));
	
}

void DownLoadManager::remvoUnstallThread()
{
	UnInstallThread *pUninstallThread = qobject_cast<UnInstallThread *>(sender());
	if (pUninstallThread)
	{
		if (pUninstallThread->isRunning() && !pUninstallThread->wait(2000))
		{
		}
		else
		{
			if (m_pUnInstallThreads.contains(pUninstallThread))
			{
				m_pUnInstallThreads.removeOne(pUninstallThread);
			}
		}
	}
}

UnInstallThread * DownLoadManager::isRightUninstallManager(QString strAppId)
{
	QList<UnInstallThread*>::iterator	itr = m_pUnInstallThreads.begin();
	for (; itr != m_pUnInstallThreads.end(); ++itr)
	{
		UnInstallThread* pDownLoadUninstallThread = (*itr);
		if(pDownLoadUninstallThread->isHaveUninstall(strAppId))
			return pDownLoadUninstallThread;
	}
	return NULL;
}



AppDownLoadThread * DownLoadManager::isRightManager(QString strAppName, QString strAppId)
{
	QList<AppDownLoadThread*>::iterator	itr = m_pDownloadThreads.begin();
	for (; itr != m_pDownloadThreads.end(); ++itr)
	{
		AppDownLoadThread* pDownLoadThread = (*itr);
		
		APPDOWNLOADETYPE  tyep = pDownLoadThread->isHaveDowanload(strAppName, strAppId);
		if (tyep != mapp_CLOSE)
		{
			return pDownLoadThread;
		}
	}
	return NULL;
}


void DownLoadManager::managerRemoveThread(AppDownLoadThread *downLoadThread)
{
	if (downLoadThread)
	{
		if (downLoadThread->isRunning())
		{
			if (!downLoadThread->wait(10000))
				return;
		}
		//if (mutexCLicke.tryLock(-1))
		{
			m_pDownloadThreads.removeOne(downLoadThread);
			downLoadThread->deleteLater();
			downLoadThread = NULL;
			//mutexCLicke.unlock();
		}
	}
}


void DownLoadManager::save()
{
	if (app_userInfo.m_strUserId.isEmpty())
		return;
	AppDownLoadThread *pDownloadThread = qobject_cast<AppDownLoadThread *>(sender());
	if (pDownloadThread)
	{
		AppDataInfo  appInfo = pDownloadThread->m_pData;
		QString chooseStr = app_userInfo.m_strUserId + "." + appInfo.m_strAppId;
		QString key = QString(QLatin1String("download_"));
		QSettings settings(QLatin1String("ZCloudDesk"), QLatin1String("zhiCloud\\zCloudDownloadmanager\\") + chooseStr);
		settings.setIniCodec(QTextCodec::codecForName("GB2312"));
		if (pDownloadThread->downloadedSuccessfully() == mapp_CLOSE || pDownloadThread->downloadedSuccessfully() == mapp_INSTALLFINLSH)
		{
			//删除线程
			if (mutexCLicke.tryLock(-1))
			{
				managerRemoveThread(pDownloadThread);
				settings.remove("");
				mutexCLicke.unlock();
			}
			return;
		}
		else
		{
			settings.setValue(key + QLatin1String("userId"), app_userInfo.m_strUserId);
			settings.setValue(key + QLatin1String("totalSize"), pDownloadThread->m_bytesTotal + pDownloadThread->m_bytesCurrentReceived);
			settings.setValue(key + QLatin1String("url"), pDownloadThread->m_strUrl);
			settings.setValue(key + QLatin1String("appId"), appInfo.m_strAppId);
			settings.setValue(key + QLatin1String("location"), pDownloadThread->m_fileName);
			settings.setValue(key + QLatin1String("done"), pDownloadThread->downloadedSuccessfully());
		}
	}
}

void DownLoadManager::load()
{
	if (app_userInfo.m_strUserId.isEmpty())
		return;
	QSettings settings(QLatin1String("ZCloudDesk"), QLatin1String("zhiCloud\\zCloudDownloadmanager"));
	settings.setIniCodec(QTextCodec::codecForName("GB2312"));
	QString key = QString(QLatin1String("download_"));
	QStringList appNameList;

	QStringList groupsList = settings.childGroups();
	foreach(QString group, groupsList)
	{
		settings.beginGroup(group);
		QString url = settings.value(key + QLatin1String("url")).toString();
		QString userId = settings.value(key + QLatin1String("userId")).toString();
		QString fileName = settings.value(key + QLatin1String("location")).toString();
		QString appId = settings.value(key + QLatin1String("appId")).toString();
		quint64 totalSize = settings.value(key + QLatin1String("totalSize")).toUInt();
		int done = settings.value(key + QLatin1String("done")).toInt();

		if (appNameList.contains(appId))
		{
			//删除异常 未处理
			settings.remove("");
			settings.endGroup();
			continue;
		}
			
		appNameList.append(appId);

		if (done != mapp_CLOSE && !url.isEmpty() && !fileName.isEmpty() && !appId.isEmpty() && userId == app_userInfo.m_strUserId) {
			AppDataInfo pData;
			pData.m_strAppId = appId;
			if (AppCenterDatabase::instance()->findApp(pData))
			{
				pData.m_strAppDownloadUrl = url;
				AppDownLoadThread *downloadThread = new AppDownLoadThread(pData);
				RightClassAppWidget *ptr = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance()); // 下载完成只链接一次
				if (ptr)
					connect(downloadThread, SIGNAL(installFinishAdd(AppDataInfo)), ptr, SLOT(installUnnstallSucessed(AppDataInfo)), Qt::QueuedConnection);
				QFile file(fileName);
				this->beginDownload(downloadThread, pData, fileName, file.size(), totalSize);				
			}
		}
		settings.endGroup();
	}
	foreach(QString group, groupsList)
	{
		settings.beginGroup(group);
		int done = settings.value(key + QLatin1String("done")).toInt();
		if (done == mapp_CLOSE)
		{
			//删除异常 未处理
			settings.remove("");
		}
	}
	
}

//删除下载线程和卸载线程
void DownLoadManager::deleteUUThread()
{
	if (mutexCLicke.tryLock(-1))
	{
		qDeleteAll(m_pDownloadThreads);
		m_pDownloadThreads.clear();
		qDeleteAll(m_pUnInstallThreads);
		m_pUnInstallThreads.clear();
		mutexCLicke.unlock();
	}
}

