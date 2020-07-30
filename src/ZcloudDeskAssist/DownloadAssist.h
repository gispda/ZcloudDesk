#pragma once
#include <QObject>
#include <QTimer>
#include <QFile>

class DownloadAssist : public QObject
{
	Q_OBJECT

public:
	DownloadAssist(QObject *parent=Q_NULLPTR);
	~DownloadAssist();

private slots:
	void onTimerOut();

private:
	//!开始
	bool startWork();

	//!下载
	bool download(QString strDownloadUrl,QString strMd5,QString& strFileName);

	//!安装
	bool install(QString strFileName);

	//!获取下载助手信息
	bool winHttpGetDownloadAssistant(QString& strUrl,QString& strVer,QString& strMd5);

private:
	//!系统版本
	QString getOsVer();

	//!获取税号
	QString getTaxs();

	//!获取mac地址
	QString getMacAddr();

	//！获取公网IP
	QString getPublicIp();

	//!获取省市
	bool getLocation(QString& strPro, QString& strCity);

	//!http请求
	bool httpPost(QString strDownloadUrl, QString strPost, int nTimeout, QString& strRet);

	//!对比版本号
	bool isNewVer(QString oldVer, QString newVer);

	QTimer*	m_pTimer = NULL;
};
