#pragma once
#include <QObject>
#include <string>
#include "curl\curl.h"
using namespace std;


#include <QTimer>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkProxy>
#include <QEventLoop>
#include <codecvt>
#include <QSettings>
#include <QApplication>
#include <WinSock2.h>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QHttpMultiPart>

class SrvInterface:public QObject
{
	Q_OBJECT
public:
	SrvInterface();
	~SrvInterface();

	//!http调用接口
	bool httpPost(QString strUrl, QString strPost, int nTimeout, QString& strRet, int _type = 0);

	bool httpPost(QString strUrl, QByteArray strPost, int nTimeout, QString& strRet, int _type = 0);




	QString getHostName();

	private slots:
	void slotError(QNetworkReply::NetworkError);

private:
	bool httpQtPost(QString strUrl, QString strPost, int nTimeout, QString& strRet);
	bool httpQtPost(QString strUrl, QByteArray strPost, int nTimeout, QString& strRet);
	bool httpCurlPost(QString strUrl, QString strPost, int nTimeout, QString& strRet);
	wstring utf8_to_wstring(const string& str);
	string wstring_to_utf8(const wstring& str);

	void getApiUrl();
	//void getNetProxy();

	CURL* m_pCurl = NULL;
	QString m_strProxyHost;
	QString m_strProxyPort;
	QString m_strHostName;
	QString m_strHostName_new;
	//bool m_bHaveProxy = false;
};

