#pragma once

#include <QObject>

class ZcloudClient : public QObject
{
	Q_OBJECT

public:
	ZcloudClient(QObject *parent);
	~ZcloudClient();

public:

	bool winHttpUpdatebankInfo(QString strUid, QString strToken, QString& strRet);

	static bool winHttpUploadImage(QString strFile, QString strToken, QString& strRet);

	//bool winHttpCreateCompanyInfo(QString strUid, QString strToken, QString& strRet);

	//bool winHttpCreateCompanyInfo(QString strUid, QString strToken, QString& strRet);
};
