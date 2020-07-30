#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>
#include <QTime>
#include "AppDownLoadThread.h"
#include "AppCenter/findregedit.h"
#include "ZhicloudAppDataDefine.h"
class DownLoadManager : public QObject
{
	friend class AppDownLoadAppWidget;
	Q_OBJECT
public:

	DownLoadManager(QObject *parent=0);
	~DownLoadManager();
	void deleteUUThread();
	//!开始下载
	void beginDownload(AppDownLoadThread *m_pDownloadThread, AppDataInfo pData, QString fileName, qint64 fileSize, qint64 totalSize);
	//开始卸载
	void beginUninstall(UnInstallThread *m_pUninstallThread);
	//是否有卸载
	UnInstallThread * isRightUninstallManager(QString strAppId);
	//是否有下载
	AppDownLoadThread * isRightManager(QString strAppName, QString strAppId);


	
public slots:
	void managerRemoveThread(AppDownLoadThread *downLoadThread);
	//保存下载列表
	void save();
	void load();
	void remvoUnstallThread();
private:
	QMutex mutexCLicke;
	QList<AppDownLoadThread*>	m_pDownloadThreads;
	QList<UnInstallThread *> m_pUnInstallThreads;
	


};

#endif // DOWNLOADMANAGER_H
