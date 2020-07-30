#pragma once
#include <QThread>
#include <QDebug>
#include <QDateTime>
#include <QtNetwork/QNetworkReply>
#include <QFile>
#include <QFileInfo>
#include <QEventLoop>
#include <QTimer>
#include <QSslSocket>
#include <QDir>
#include <QApplication>
#include <QDebug>

class ZWebDownloadThread :
	public QThread
{
	Q_OBJECT
public:
	ZWebDownloadThread(QObject *parent = 0);
	~ZWebDownloadThread();
	void setValue(QNetworkRequest request, QString fileName);

	void suspendDownload();
	void removeFile();

signals:
	void threadReadProgress(qint64 totalBytes, qint64 bytesRead);

	void finished_signal();//下载完成的信号

	void error_signal(QNetworkReply::NetworkError);

	void errotTxetSignal(int number, QString text);

private slots:

	void requestFinished();//下载完成信号

	void httpReadyRead();//有数据可读

private:
	QNetworkReply* m_pNetworkReply; //封装请求返回信息
	QNetworkRequest m_request;
	QEventLoop *loop;
	QFile m_file;

protected:
	void run();
private:
	void errtoText(int number, QString text);
	
};

