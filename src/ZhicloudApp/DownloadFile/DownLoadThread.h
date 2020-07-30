#ifndef DOWNLOADTHREAD_H
#define DOWNLOADTHREAD_H

#include <QObject>
#include <QThread>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QProcess>
#include <QString>
#include <QTimer>
#include <QRunnable>
enum DOWNLOADETYPE
{
	m_DOWNLOADING,	//下载中
	m_ERROR,		//下载错误
	m_FINISH,		//下载完成
	m_INSTALLFINLSH,//安装完成
	m_INSTALLERROR, //安装错误
	m_PAUSE,		//暂停下载
	m_CLOSE
};

class DownLoadThread : public QThread
{
	Q_OBJECT

public:
	DownLoadThread(QObject *parent = 0);
	~DownLoadThread();

	void downloadFile(QString url, QString fileName, bool appMsg = true);
	void setDownInto(bool isSupportBreakPoint);
	//void stopDownload(bool appMsg); //暂停
	void closeDownload(bool appMsg);//停止
	QString getDownloadUrl();
	void reset();
	void stopWork(bool appMsg);
	//void stopWorkDoanload();//暂停时的停止工作
	void  startAyalseUrl(QString strUrl);
	QString m_fileName;
	DOWNLOADETYPE m_DOWNLOADETYPE;
private:	
	
	void removeFile(QString fileName);

signals:
	void signalDownloadProcess(qint64, qint64);
	void signalReplyFinished(int,QString);
	void signalDownloadError(QString);
	void installFinished(bool);
	
private slots:
	void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
	void onReadyRead();
	void onFinished();
	void onError(QNetworkReply::NetworkError code);

private:
	QNetworkAccessManager* m_networkManager;
	QNetworkReply* m_reply;
	QUrl m_url;
	//QTimer *m_timer;

	bool m_isSupportBreakPoint;

	qint64 m_bytesReceived;
	qint64 m_bytesTotal;
	qint64 m_bytesCurrentReceived;

	bool m_isStop;
protected:
	void run();
};

#endif // DOWNLOADTHREAD_H
