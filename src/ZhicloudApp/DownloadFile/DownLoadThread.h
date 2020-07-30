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
	m_DOWNLOADING,	//������
	m_ERROR,		//���ش���
	m_FINISH,		//�������
	m_INSTALLFINLSH,//��װ���
	m_INSTALLERROR, //��װ����
	m_PAUSE,		//��ͣ����
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
	//void stopDownload(bool appMsg); //��ͣ
	void closeDownload(bool appMsg);//ֹͣ
	QString getDownloadUrl();
	void reset();
	void stopWork(bool appMsg);
	//void stopWorkDoanload();//��ͣʱ��ֹͣ����
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
