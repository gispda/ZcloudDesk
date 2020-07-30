#pragma once
#include <QtCore/QCoreApplication>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QFile>
#include "bigDataInterface.h"

class DownloadHelper : public QObject
{
	Q_OBJECT

public:
	DownloadHelper(QObject *parent = Q_NULLPTR);

private:
	QNetworkAccessManager* m_networkManager = NULL;
	QNetworkReply* m_reply = NULL;
	QString m_strUrl = "";
	QString m_strMD5 = "";
	QString	m_strCur = "";
	QFile file;
	QString m_fileName;
	qint64 m_bytesCurrentReceived = 0;
	BigDataHeartbeat * bigDataHeartbeat = NULL;
private:
	void errorReset();
	//!httpPost����     url             post����    ��ʱ���    ��������
	bool getUrlMD5();
	void removeFile();
	void load();
	void starExe(QString exepaht);
	//�������
	void writeFile(QString str);
	QString getMacAddr();
	//ϵͳ�汾
	QString getOsVer();
	//��ȡ˰��
	QString getTaxs();
	//�ж��Ƿ���Ҫ����
	bool isNewVer(QString oldVer, QString newVer);
	bool GetNetIP(QString &province, QString &city);
	//ͨ���ӿڻ�ȡ����IP
	QString  getServerIp();
	QString getWebIp();//ͨ��������ʽ��ȡ����IP�����ã�

	bool getPC(QString netIp, QString &province, QString &city);
private slots:
	void downloadStart();
	void onReadyRead();
	void onFinished();
	void onError(QNetworkReply::NetworkError code);
};
