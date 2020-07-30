#ifndef CLOUDDOWNLOAD_H
#define CLOUDDOWNLOAD_H
#include <QThread>
#include <QDateTime>
#include <QFile>
#include <QFileInfo>
#include <QEventLoop>
#include <QTimer>
#include <QDir>
#include <QtNetwork/QNetworkReply>
class DownLoadIcon : public QThread
{
    Q_OBJECT

public:
	explicit DownLoadIcon(int msec=3000,QObject *parent = 0);

	void setValue(QString flilePath, QString url, QString id = "");
	QString filePath;//传入的 文件运行路径，返回下载的文件路径
	void run();

	void startAyalseUrl(QString strUrl);
	bool errorFlag = false;
signals:
    void readProgress(qint64 totalBytes,qint64 bytesRead);

    void finished_signal();//下载完成的信号

public slots:
    void requestTimeout();//请求超时

    void requestFinished();//下载完成信号

    void httpReadyRead() ;//有数据可读

private:
    QNetworkAccessManager* m_pNetworkManager;//网络管理类
    QNetworkReply* m_pNetworkReply; //封装请求返回信息
    QEventLoop *loop;

    QTimer * m_pTimer;//超时定时器
    QString m_Url;
	QString appID;
	int		m_msec;
    QFile *file = NULL;
	QString down_name;
protected:
    

};

#endif // CLOUDDOWNLOAD_H
