#include "SrvInterface.h"

//#include "ZcloudCommon.h"

#pragma comment(lib,"Ws2_32.lib ")
static size_t write_string_data(void *input, size_t uSize, size_t uCount, void *avg)
{
	size_t uLen = uSize*uCount;
	string *pStr = (string *)(avg);
	pStr->append((char *)(input), uLen);

	// 只有返回uSize*uCount才会返回成功
	return uLen;
}

SrvInterface::SrvInterface()
{
	curl_global_init(CURL_GLOBAL_ALL);
	getApiUrl();
	//getNetProxy();
}


SrvInterface::~SrvInterface()
{
	if (m_pCurl != NULL)
	{
		curl_easy_cleanup(m_pCurl);
		m_pCurl = NULL;
	}
	curl_global_cleanup();
}

void SrvInterface::slotError(QNetworkReply::NetworkError sss)
{
	qDebug() << sss;//<< (QNetworkReply*)sender()->

	
}

bool SrvInterface::httpQtPost(QString strUrl, QString strPost, int nTimeout, QString& strRet)
{
	QNetworkAccessManager login_pNetworkManager;//网络管理类
	QNetworkReply *login_pNetworkReply = NULL; //封装请求返回信息
	QTimer login_pTimer; //请求超时计时器
	QEventLoop loop;
	connect(&login_pTimer, SIGNAL(timeout()), &loop, SLOT(quit()));

	QNetworkRequest netRequest;
	QSslConfiguration config = netRequest.sslConfiguration();
	config.setPeerVerifyMode(QSslSocket::VerifyNone);
	config.setProtocol(QSsl::TlsV1SslV3);
	netRequest.setSslConfiguration(config);
	netRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	netRequest.setUrl(QUrl(strUrl)); //地址信息

	if (login_pNetworkManager.networkAccessible() == QNetworkAccessManager::NotAccessible)
	{
		login_pNetworkManager.setNetworkAccessible(QNetworkAccessManager::Accessible);
	}

	if (strPost.isEmpty())
		login_pNetworkReply = login_pNetworkManager.get(netRequest);
	else
		login_pNetworkReply = login_pNetworkManager.post(netRequest, strPost.toUtf8());//发起post请求


	connect(login_pNetworkReply, SIGNAL(error(QNetworkReply::NetworkError)),
		this, SLOT(slotError(QNetworkReply::NetworkError)));

	connect(login_pNetworkReply, SIGNAL(finished()), &loop, SLOT(quit()));
	login_pTimer.start(nTimeout);
	loop.exec();

	if (login_pNetworkReply->error() == QNetworkReply::ContentNotFoundError)
	{
		QUrl failedUrl;
		failedUrl = login_pNetworkReply->request().url();
		int httpStatus = login_pNetworkReply->attribute(
			QNetworkRequest::HttpStatusCodeAttribute).toInt();
		QString reason = login_pNetworkReply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
		qDebug() << "url" << failedUrl << httpStatus << "   " << reason;
	}

	QByteArray resultContent = login_pNetworkReply->readAll();
	int nHttpCode = login_pNetworkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();//http返回码
	strRet = "";
	if (login_pTimer.isActive())
	{  // 处理响应
		login_pTimer.stop();
		int nErrorCode = login_pNetworkReply->error();
		if (nErrorCode == QNetworkReply::NoError)
		{
			if (nHttpCode == 200)//成功返回
			{
				strRet = QString(resultContent);
			
				return true;
			}
			else
			{
				strRet = QString(resultContent);
				QString str = login_pNetworkReply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
				qDebug() << "zcd-0x10000048:" << QString("code:%1 \r\n ret:%2\r\n info:%3\r\n STRLogin:%4\r\n body:%5").arg(nHttpCode).arg(strRet).arg(str).arg(strUrl).arg(strPost);
			}
		}
		else
		{
			//解析域名
			QString zhiStr = "";
			QByteArray url = m_strHostName.toLatin1();
			struct hostent *h = gethostbyname(url);
			if (h != NULL)
			{
				struct in_addr *in = (in_addr *)h->h_addr;
				char *ch = inet_ntoa(*in);
				zhiStr = QString(QLatin1String(ch));
			}
			// "请求失败" 
			qDebug() << "zcd-0x10000049:" << QString("code:%1\r\n errorCode=%2\r\n domain name=%3\r\n errorMsg=%4\r\n STRLogin = %5\r\n body = %6").arg(nHttpCode).arg(nErrorCode).arg(zhiStr).arg(login_pNetworkReply->errorString()).arg(strUrl).arg(strPost);
		}
	}
	else
	{  
		// 处理超时
		qDebug() << "zcd-0x10000050:" << QString("timeOut:STRLogin = %2,body = %3").arg(strUrl).arg(strPost);
	}
	return false;
}


std::wstring SrvInterface::utf8_to_wstring(const string& str)
{
	wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.from_bytes(str);
}

std::string SrvInterface::wstring_to_utf8(const wstring& str)
{
	wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.to_bytes(str);
}

bool SrvInterface::httpCurlPost(QString strUrl, QString strPost, int nTimeout, QString& strRet)
{
	string strTemp = "";
	CURLcode ret;
	curl_global_init(CURL_GLOBAL_ALL);
	if (m_pCurl == NULL)
		m_pCurl = curl_easy_init();

	curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, "Content-Type:application/x-www-form-urlencoded; charset=UTF-8");
	if (m_pCurl)
	{
		curl_easy_setopt(m_pCurl, CURLOPT_HTTPHEADER, http_headers);
		curl_easy_setopt(m_pCurl, CURLOPT_URL, strUrl.toUtf8().data());
		curl_easy_setopt(m_pCurl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(m_pCurl, CURLOPT_SSL_VERIFYHOST, 0L);

		//打开调试信息
		//curl_easy_setopt(m_pCurl, CURLOPT_VERBOSE, 1L);//调试信息打开	
		//设置要post的数据 
		wstring data = strPost.toStdWString();
		string strPostData = wstring_to_utf8(data);
		if (strPost.length() > 0)
		{
			curl_easy_setopt(m_pCurl, CURLOPT_POST, true);
			curl_easy_setopt(m_pCurl, CURLOPT_POSTFIELDS, strPostData.c_str());
		}
		//if (m_bHaveProxy)
		//{
		//	//!设置代理host
		//	char *strHostData = m_strProxyHost.toLatin1().data();
		//	curl_easy_setopt(m_pCurl, CURLOPT_PROXY, strHostData);

		//	//!设置代理port
		//	char *strPortData = m_strProxyPort.toLatin1().data();
		//	curl_easy_setopt(m_pCurl, CURLOPT_PROXYPORT, strPortData);
		//}

		////!设置代理身份验证
		//string strUserData = wstring_to_utf8(m_strUserInfo);
		//if (!strUserData.empty())
		//{
		//	curl_easy_setopt(m_pCurl, CURLOPT_PROXYUSERPWD, strUserData.c_str());
		//}

		//设置连接超时	
		curl_easy_setopt(m_pCurl, CURLOPT_CONNECTTIMEOUT, nTimeout);
		//设置数据接收回调函数 
		curl_easy_setopt(m_pCurl, CURLOPT_WRITEFUNCTION, write_string_data);
		curl_easy_setopt(m_pCurl, CURLOPT_WRITEDATA, &strTemp);

		try
		{
			ret = curl_easy_perform(m_pCurl);
			if (ret == CURLE_OK)
			{
				curl_easy_cleanup(m_pCurl);
				m_pCurl = NULL;
				strRet = QString::fromStdString(strTemp);
				return true;
			}
			else
			{
				curl_easy_cleanup(m_pCurl);
				qDebug() << "zcd-0x10000051:" << QString("http curl failed! ret=%1 \r\n STRLogin = %2\r\n body = %3").arg(ret).arg(strUrl).arg(strPost);
				m_pCurl = NULL;
				strRet = "";
			}
		}
		catch (...)
		{
			curl_easy_cleanup(m_pCurl);
			qDebug() << "zcd-0x10000052:" << QString("http curl failed!\r\n STRLogin = %1\r\n body = %2").arg(strUrl).arg(strPost);
			m_pCurl = NULL;
			strRet = QString::fromStdString(strTemp);
		}
	}
	return false;
}

//void SrvInterface::getNetProxy()
//{
//	QSettings *settings = new QSettings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet Settings", QSettings::NativeFormat);
//	QStringList keys = settings->allKeys();
//	if (settings->value("ProxyEnable").toInt() == 1) {
//		if (keys.contains("ProxyServer") && settings->value("ProxyServer") != "") {
//			QStringList sets = settings->value("ProxyServer").toString().split(":");
//			m_strProxyHost = sets[0];
//			m_strProxyPort = sets[1];
//			m_bHaveProxy = true;
//		}
//	}
//	delete settings;
//}

bool SrvInterface::httpPost(QString strUrl, QString strPost, int nTimeout, QString& strRet, int _type)
{
	if (_type == 1) //使用新的接口地址
	{
		return httpQtPost(m_strHostName_new + strUrl, strPost, nTimeout, strRet);
	}
	return httpQtPost(m_strHostName + strUrl, strPost, nTimeout, strRet);
}

void SrvInterface::getApiUrl()
{
	QString strIniPath = QApplication::applicationDirPath();
	QSettings settings(strIniPath+ "/config.ini", QSettings::IniFormat);
	m_strHostName	= settings.value("api/hostName").toString();
	m_strHostName_new = settings.value("api/hostGw").toString();
}

QString SrvInterface::getHostName()
{
	return m_strHostName;
}