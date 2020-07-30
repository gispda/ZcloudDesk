#pragma once
#include <QObject>
#include <QNetworkReply>
#include <QFile>

//!×èÈûÏÂÔØÎÄ¼þ
class HttpDownload : public QObject
{
	Q_OBJECT
public:
	HttpDownload(QString strDirName, QString strDownloadUrl, QString strMd5, bool bCompareMd5,QObject *parent = Q_NULLPTR);
	~HttpDownload();

	QString getFileName();

	bool startDownload(QString strDownloadUrl);
signals:
	void sigDownloadProgress(qint64, qint64);
private slots:
	void onReadyRead();
private:
	void getDownloadFilePath(QString strDirName, QString strDownloadUrl);

	void removeFile();

	QString			m_strFileFullName;
	QString			m_strFileName;
	qint64			m_bytesCurrentReceived = 0;
	QNetworkReply*  m_reply = NULL;
	QFile			m_file;
	QString			m_strMd5;
	bool			m_bCompareMd5;
};
