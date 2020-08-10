#pragma once

#include <QObject>
#include "Database.h"
class ZcloudClient : public QObject
{
	Q_OBJECT

public:
	ZcloudClient(QObject *parent);
	~ZcloudClient();

public:

	static bool winHttpUpdatebankInfo(CompanyBankInfo _bankinfo, QString strToken, QString& strRet,QString& strMsg);

	static bool winHttpUploadImage(QString strFile, QString strToken, QString& strRet,QString& strMsg);


	bool winHttpGetStarlabels(QString strcompanyid, QString strToken, QString& strRet);
	bool winHttpPostsubmitComment(QString strPost, QString strToken, QString& strRet);

	//bool winHttpCreateCompanyInfo(QString strUid, QString strToken, QString& strRet);

	//bool winHttpCreateCompanyInfo(QString strUid, QString strToken, QString& strRet);
};
