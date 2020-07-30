#pragma once
#include <QObject>
#include <string>
#include "curl\curl.h"
using namespace std;

class SrvInterface:public QObject
{
	Q_OBJECT
public:
	SrvInterface();
	~SrvInterface();

	//!http调用接口
	bool httpPost(QString strUrl, QString strPost, int nTimeout, QString& strRet);

	QString getHostName();

private:
	bool httpQtPost(QString strUrl, QString strPost, int nTimeout, QString& strRet);
	bool httpCurlPost(QString strUrl, QString strPost, int nTimeout, QString& strRet);
	wstring utf8_to_wstring(const string& str);
	string wstring_to_utf8(const wstring& str);

	void getApiUrl();
	//void getNetProxy();

	CURL* m_pCurl = NULL;
	QString m_strProxyHost;
	QString m_strProxyPort;
	QString m_strHostName;
	//bool m_bHaveProxy = false;
};

