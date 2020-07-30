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

	void finished_signal();//������ɵ��ź�

	void error_signal(QNetworkReply::NetworkError);

	void errotTxetSignal(int number, QString text);

private slots:

	void requestFinished();//��������ź�

	void httpReadyRead();//�����ݿɶ�

private:
	QNetworkReply* m_pNetworkReply; //��װ���󷵻���Ϣ
	QNetworkRequest m_request;
	QEventLoop *loop;
	QFile m_file;

protected:
	void run();
private:
	void errtoText(int number, QString text);
	
};

