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
	//!httpPost请求     url             post数据    超时检查    返回数据
	bool getUrlMD5();
	void removeFile();
	void load();
	void starExe(QString exepaht);
	//错误输出
	void writeFile(QString str);
	QString getMacAddr();
	//系统版本
	QString getOsVer();
	//获取税号
	QString getTaxs();
	//判断是否需要下载
	bool isNewVer(QString oldVer, QString newVer);
	bool GetNetIP(QString &province, QString &city);
	//通过接口获取外网IP
	QString  getServerIp();
	QString getWebIp();//通过其它方式获取外网IP（备用）

	bool getPC(QString netIp, QString &province, QString &city);
private slots:
	void downloadStart();
	void onReadyRead();
	void onFinished();
	void onError(QNetworkReply::NetworkError code);
};
