#ifndef APPDOWNLOADTHREAD_H
#define APPDOWNLOADTHREAD_H

#include <QObject>
#include <QThread>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QProcess>
#include <QString>
#include <QRunnable>
#include <QEventLoop>
#include <QFile>
#include "ZhicloudAppDataDefine.h"

class AppDownLoadThread : public QThread
{
	Q_OBJECT
	friend class DownLoadManager;
	friend class AppDownLoadAppWidget;
	friend class AppCenterTools;
	friend class AppCenterWidget;
	friend class AppDownLoadItem;
	friend class AppParticularsDialog;
public:
	AppDownLoadThread(AppDataInfo pData, QObject *parent = 0);
	~AppDownLoadThread();
	
	QString getDownloadUrl();
	void reset();
	QString m_fileName;
	//下载是否完成
	APPDOWNLOADETYPE downloadedSuccessfully();
private:	
	
	void removeFile(QString fileName);

signals:
	void signalDownloadProcess(qint64, qint64);
	void signalStatusChanged(APPDOWNLOADETYPE);
	void installFinishAdd(AppDataInfo);
	void closeDowloadSignal(QString classId);
private slots:
	void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
	void onReadyRead();
	void onFinished();
	void onError(QNetworkReply::NetworkError code);

private:
	QNetworkAccessManager* m_networkManager = NULL;
	QNetworkReply* m_reply = NULL;
	QString m_strUrl;
	qint64 m_bytesReceived = 0;
	qint64 m_bytesTotal = 0;
	qint64 m_bytesCurrentReceived = 0;

protected:
	void run();
public slots:
	void stopDownload(); //暂停
	void closeDownload();//停止
	void continueDownload();		//继续下载
	void reDownload(); //重新下载
public:
	//判断是否是当前下载
	APPDOWNLOADETYPE isHaveDowanload(QString, QString);
	//当前状态
	APPDOWNLOADETYPE getType();
	//获取进度 0 表示当前下载    其他表示总进度
	qint64 getProcese(int totalReceived);
	void setDownloadValue(QString url, QString fileName ,qint64 bytesCurrentReceived, qint64 totalSize);
	
private:
	APPDOWNLOADETYPE m_APPDOWNLOADETYPE = mapp_PAUSE;
	AppDataInfo m_pData;
	QFile file;
	QEventLoop *loop = NULL;
	//当前应用是否存在
	bool m_isHaveApp = false;
	//用于 上次下载成功 客户端退出了 
	bool m_downloadFilish = false;
private:
	//错误重置
	void errorReset(int errorInt);
};

#endif // APPDOWNLOADTHREAD_H
