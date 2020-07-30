#include "DownloadHelper.h"
#include <QFileInfo>
#include <QSettings>
#include <QFileInfo>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QProcess>
#include <QTextCodec>
#include <QSysInfo>


// 1  开机自启，   2 断点续传， 3  静默，  4 版本可配置 
#define DOWNLOAD_FILE_SUFFIX	"_tmp"
#define STRGETMD5URL "https://91z9v0jc.clouduan.com"
//"https://cliservice.zctest.com"

DownloadHelper::DownloadHelper(QObject *parent)
	: QObject(parent)
	, bigDataHeartbeat(new BigDataHeartbeat(this))
{
	m_networkManager = new QNetworkAccessManager(this);
	QNetworkProxyQuery proxyQuery(QUrl::fromUserInput("https://www.baidu.com"));
	QList<QNetworkProxy> proxyList = QNetworkProxyFactory::systemProxyForQuery(proxyQuery);
	if (proxyList.count() > 0)
	{
		m_networkManager->setProxy(proxyList.at(0));
	}

	QTimer::singleShot(20, this, SLOT(downloadStart()));
}

void DownloadHelper::load()
{
	QFileInfo fileInfo(QUrl::fromUserInput(m_strUrl).path());
	QString appFileName = fileInfo.fileName();
	QString filePath = QCoreApplication::applicationDirPath() + "/";
	m_fileName = filePath + appFileName + DOWNLOAD_FILE_SUFFIX;

	QFileInfo fileInfoName(m_fileName);
	if (fileInfoName.exists())
		m_bytesCurrentReceived = fileInfoName.size();
	else
		m_bytesCurrentReceived = 0;
	file.setFileName(m_fileName);
}

void DownloadHelper::downloadStart()
{
	if (!getUrlMD5())
	{
		qApp->quit();
		return;
	}

	QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{A9D22CBD-1E78-4813-8773-007907D30803}_is1", QSettings::NativeFormat);
	//InstallLocation
	if (settings->contains("InstallLocation") && settings->contains("DisplayName") && isNewVer(settings->value("DisplayVersion", QVariant()).toString(), m_strCur))
	{
		bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP000").arg("PFI007").arg(m_strCur), false);
		delete settings;
		qApp->quit();
		return;
	}
	delete settings;

	load();
	QNetworkRequest request;
	request.setUrl(m_strUrl);
	// 如果支持断点续传，则设置请求头信息;
	if (m_bytesCurrentReceived >  0)
	{
		QString strRange = QString("bytes=%1-").arg(m_bytesCurrentReceived);
		request.setRawHeader("Range", strRange.toLatin1());
	}

	m_reply = m_networkManager->get(request);

	//connect(m_reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
	connect(m_reply, SIGNAL(readyRead()), this, SLOT(onReadyRead()), Qt::DirectConnection);
	connect(m_reply, SIGNAL(finished()), this, SLOT(onFinished()));
	connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
}

void DownloadHelper::starExe(QString exepaht)
{
	//!启动云财税安装程序
	exepaht = "\"" + exepaht + "\"";	//!空格处理
	QProcess *ap = new QProcess(this);
	ap->start(exepaht/* + " /verysilent /suppressmsgboxes"*/);
	ap->waitForFinished(-1);
	QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{A9D22CBD-1E78-4813-8773-007907D30803}_is1", QSettings::NativeFormat);
	if (settings->contains("InstallLocation") && settings->contains("DisplayName") && (m_strCur == settings->value("DisplayVersion", QVariant()).toString()))
	{
		bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP000").arg("PFI005").arg(m_strCur), false);
		QFile::remove(exepaht);
		delete settings;

		//!删除自启动注册表
		QSettings *reg = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
		reg->remove("zhicloud");
		delete reg;

		qApp->quit();
	}
	else
	{
		bigDataHeartbeat->setValue(QString("%1,%2,%3,%4-%5").arg("M00").arg("OP000").arg("PFI006").arg("installError").arg(m_strCur));
		QFile::remove(exepaht);
		delete settings;
		writeFile("starExe Error:" + exepaht);
		errorReset();
	}
}

// 获取下载内容，保存到文件中;
void DownloadHelper::onReadyRead()
{
	if (file.fileName().isEmpty())
	{
		writeFile("m_strFile isNull!");
		bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP000").arg("PFI004").arg("m_strFile isNull!" + m_strCur));
		errorReset();
		return;
	}

	if (!file.isOpen()) {
		// in case someone else has already put a file there
		if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
			bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP000").arg("PFI004").arg("openFile Error!" + m_strCur));
			writeFile("openFile Error!");
			errorReset();
			return;
		}
	}
	if (-1 == file.write(m_reply->readAll())) {
		writeFile("writeFile Error!");
		bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP000").arg("PFI004").arg("writeFile Error!" + m_strCur));
		errorReset();
	}
}


// 下载完成;
void DownloadHelper::onFinished()
{
	if (!m_reply) return;
	QVariant statusCode = m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	int nStatusCode = statusCode.toInt();
	if (nStatusCode == 302 || nStatusCode == 301)
	{
		m_strUrl = m_reply->rawHeader("Location");
		writeFile("Location Error!");
		errorReset();
	}
	else
	{
		QString realName;
		if (m_reply->error() == QNetworkReply::NoError || nStatusCode == 200)
		{
			QFileInfo fileInfo(m_fileName);
			if (fileInfo.exists())
			{
				file.close();
				int index = m_fileName.lastIndexOf(DOWNLOAD_FILE_SUFFIX);
				realName = m_fileName.left(index);
				QFileInfo realFile(realName);
				if (realFile.exists())
					QFile::remove(realName);
				
				QFile::rename(m_fileName, realName);

				QFile theFile(realName);
				theFile.open(QIODevice::ReadOnly);
				QByteArray ba = QCryptographicHash::hash(theFile.readAll(), QCryptographicHash::Md5);
				theFile.close();
				QString fileMd5 = ba.toHex().constData();
				fileMd5	=	fileMd5.toUpper();
				if (fileMd5 == m_strMD5)
				{
					bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP000").arg("PFI003").arg(m_strCur));
					starExe(realName);
				}
				else
				{
					writeFile("MD5Error");
					bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP000").arg("PFI004").arg(QString("MD5Error:oldMd5=%1,newMd5:%2").arg(fileMd5).arg(m_strMD5) + "  " +  m_strCur));
					removeFile();
					::_sleep(1000 * 2);
					downloadStart();
				}
			}
		}
		else
		{
			//下载错误 有onError 信号  在此函数中  执行重复下载
		}
	}
}

// 下载过程中出现错误，关闭下载，并上报错误，这里未上报错误类型，可自己定义进行上报;
void DownloadHelper::onError(QNetworkReply::NetworkError code)
{
	writeFile("onError:" + m_reply->errorString());
	bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP000").arg("PFI004").arg("httpError:" + m_reply->errorString() + m_strCur));
	errorReset();
}

void DownloadHelper::errorReset()
{
	if (m_reply->error() == QNetworkReply::TimeoutError || m_reply->error() == QNetworkReply::NetworkSessionFailedError || m_reply->error() == QNetworkReply::RemoteHostClosedError)
	{
		file.close();
		::_sleep(1000 * 30);
	}
	else
		removeFile();

	if (m_reply)
		disconnect(m_reply);
	
	::_sleep(1000 * 2);
	downloadStart();
}


// 删除文件;
void DownloadHelper::removeFile()
{
	// 删除已下载的临时文件;
	file.close();
	QFileInfo fileInfo(m_fileName);
	if (fileInfo.exists())
	{
		QFile::remove(m_fileName);
	}
}

void DownloadHelper::writeFile(QString str)
{
	//bigDataHeartbeat->setValue(QString("%1,%2,%3,%4-%5").arg("M00").arg("OP000").arg("PFI004").arg(str).arg(m_strCur));

	QFile file(QCoreApplication::applicationDirPath() + "//DownloadHelper.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream text_stream(&file);
	QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
	text_stream << current_date_time + ":" + str << "\r\n";
	file.flush();
	file.close();
}

bool  DownloadHelper::getUrlMD5()
{
	QString STRLogin = STRGETMD5URL;

	QNetworkAccessManager login_pNetworkManager;//网络管理类
	QNetworkReply *login_pNetworkReply = NULL; //封装请求返回信息
	QEventLoop loop;

	QNetworkRequest netRequest;
	QSslConfiguration config = netRequest.sslConfiguration();
	config.setPeerVerifyMode(QSslSocket::VerifyNone);
	config.setProtocol(QSsl::TlsV1SslV3);
	netRequest.setSslConfiguration(config);
	netRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

	QString strUrl = STRLogin + "/general/get-download-assistant";
	QString strBody = "mac=" + getMacAddr() + "&os_version="  + getOsVer() + "&tax_number=" + "[" + getTaxs() + "]";
	QString province;
	QString city;
	if (GetNetIP(province, city) && !city.isEmpty() && !province.isEmpty())
	{
		strBody.append("&province=" + province + "&city=" + city);
	}
	netRequest.setUrl(QUrl(strUrl)); //地址信息

	QNetworkProxyQuery proxyQuery(QUrl::fromUserInput("https://www.baidu.com"));
	QList<QNetworkProxy> proxyList = QNetworkProxyFactory::systemProxyForQuery(proxyQuery);
	if (proxyList.count() > 0)
	{
		login_pNetworkManager.setProxy(proxyList.at(0));
	}
	//login_pNetworkReply = login_pNetworkManager.get(netRequest);
	login_pNetworkReply = login_pNetworkManager.post(netRequest, strBody.toUtf8());//发起post请求
	connect(login_pNetworkReply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();
	writeFile("url:" + strUrl + "     body:" + strBody);
	QByteArray resultContent = login_pNetworkReply->readAll();
	int nHttpCode = login_pNetworkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();//http返回码
	if (login_pNetworkReply->error() == QNetworkReply::NoError)
	{
		if (nHttpCode == 200)//成功返回
		{
			QJsonParseError json_error;
			QJsonDocument parse_doucment = QJsonDocument::fromJson(resultContent, &json_error);
			if (json_error.error != QJsonParseError::NoError || !parse_doucment.isObject())
			{
				writeFile("jsonError:" + QString(resultContent));
				bigDataHeartbeat->setFileVer("-1");
				bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP000").arg("PFI001").arg("jsonError:" + QString(resultContent)), false);
				return false;
			}

			QJsonObject obj = parse_doucment.object();
			int code = obj.take("status").toInt();
			if (code != 0 )
			{
				if (30015 == code || 30016 == code)
				{
					//3015  税号在白名单中
					//3016 mac 在白名单中

					////!删除自启动注册表
					//QSettings *reg = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
					//reg->remove("zhicloud");
					//delete reg;

					bigDataHeartbeat->setFileVer("-1");
					bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP000").arg("PFI001").arg("Not install:" + QString::number(code)), false);
					qApp->quit();
					return false;
				}
				else
				{
					writeFile("jsonError:" + QString(resultContent));
					bigDataHeartbeat->setFileVer("-1");
					bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP000").arg("PFI001").arg("jsonError:" + QString(resultContent)), false);
					return false;
				}	
			}
				
			QJsonObject dataObj = obj.take("data").toObject();
			m_strUrl = dataObj.take("download_url").toString();
			m_strMD5 = dataObj.take("md5").toString();
			m_strCur = dataObj.take("version").toString();
			m_strMD5 = m_strMD5.toUpper();

			bigDataHeartbeat->setFileVer(m_strCur);

			if (!m_strUrl.isEmpty() && !m_strMD5.isEmpty())
			{
				bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP001").arg("PFI001").arg(m_strCur));
				return true;
			}
		}
	}
	bigDataHeartbeat->setValue(QString("%1,%2,%3,%4").arg("M00").arg("OP001").arg("PFI002").arg("http interface requre failed:" + QString::number(nHttpCode) + "STRLogin:" + STRLogin), false);
	writeFile("http interface requre failed:" + QString::number(nHttpCode) + "STRLogin:" + STRLogin);
	return false;
}

QString DownloadHelper::getMacAddr()
{
	QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表  
	int nCnt = nets.count();
	QString strMacAddr = "";
	for (int i = 0; i < nCnt; i++)
	{
		// 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址  
		if (nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
		{
			strMacAddr = nets[i].hardwareAddress();
			break;
		}
	}
	return strMacAddr;
}

QString  DownloadHelper::getOsVer(){

	QSysInfo::WinVersion ver = QSysInfo::windowsVersion();
	QString ovVer = "";
	switch (ver)
	{
	case QSysInfo::WV_None:
		ovVer = QString("WV_None");
		break;
	case QSysInfo::WV_32s:
		ovVer = QString("WV_32s");
		break;
	case QSysInfo::WV_95:
		ovVer = QString("WV_95");
		break;
	case QSysInfo::WV_98:
		ovVer = QString("WV_98");
		break;
	case QSysInfo::WV_Me:
		ovVer = QString("WV_Me");
		break;
	case QSysInfo::WV_DOS_based:
		ovVer = QString("WV_DOS_based");
		break;
	case QSysInfo::WV_NT:
		ovVer = QString("WV_NT");
		break;
	case QSysInfo::WV_2000:
		ovVer = QString("WV_2000");
		break;
	case QSysInfo::WV_XP:
		ovVer = QString("WV_XP");
		break;
	case QSysInfo::WV_2003:
		ovVer = QString("WV_2003");
		break;
	case QSysInfo::WV_VISTA:
		ovVer = QString("WV_VISTA");
		break;
	case QSysInfo::WV_WINDOWS7:
		ovVer = QString("WV_WINDOWS7");
		break;
	case QSysInfo::WV_WINDOWS8:
		ovVer = QString("WV_WINDOWS8");
		break;
	case QSysInfo::WV_WINDOWS8_1:
		ovVer = QString("WV_WINDOWS8_1");
		break;
	case QSysInfo::WV_WINDOWS10:
		ovVer = QString("WV_WINDOWS10");
		break;
	case QSysInfo::WV_NT_based:
		ovVer = QString("WV_NT_based");
		break;
	//case QSysInfo::WV_4_0:
	//	break;
	//case QSysInfo::WV_5_0:
	//	break;
	//case QSysInfo::WV_5_1:
	//	break;
	//case QSysInfo::WV_5_2:
	//	break;
	//case QSysInfo::WV_6_0:
	//	break;
	//case QSysInfo::WV_6_1:
	//	break;
	//case QSysInfo::WV_6_2:
	//	break;
	//case QSysInfo::WV_6_3:
	//	break;
	//case QSysInfo::WV_10_0:
	//	break;
	case QSysInfo::WV_CE:
		ovVer = QString("WV_CE");
		break;
	case QSysInfo::WV_CENET:
		ovVer = QString("WV_CENET");
		break;
	case QSysInfo::WV_CE_5:
		ovVer = QString("WV_CE_5");
		break;
	case QSysInfo::WV_CE_6:
		ovVer = QString("WV_CE_6");
		break;
	case QSysInfo::WV_CE_based:
		ovVer = QString("WV_CE_based");
		break;
	default:
		ovVer = QString("WV_other");
		break;
	}
	return ovVer;
}


QString DownloadHelper::getTaxs()
{
	QStringList taxList;
	//读取税号
	QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
	QStringList groupsList = settings->childGroups();
	for (int i = groupsList.size() - 1; i >= 0; i--)
	{
		QString group = groupsList[i];
		settings->beginGroup(group);
		QString strTaxNo = settings->value("code", QVariant()).toString();			//！企业税号
		strTaxNo.replace(" ", "");
		if (!strTaxNo.isEmpty()) taxList << strTaxNo;
		//strMachine = settings->value("machine", QVariant()).toString();		//！主机号分机号
		settings->endGroup();
	}
	delete settings;
	//如果大于10
	if (taxList.size() > 10)
	{
		for (size_t i = taxList.size() - 1; i > 0; i--)
		{
			QString strTax = taxList.at(i);
			//9开头的 18位的税号
			if (strTax.size() != 18 || strTax.left(1) != "9")
			{
				taxList.removeAt(i);
			}
			if (taxList.size() <= 10) break;
		}
	}
	if (taxList.size() > 10)
		taxList = taxList.mid(0, 10);

	//加引号 拼接json
	QStringList reTaxNumberList;
	for each (QString var in taxList)
	{
		var = "\"" + var + "\"";
		reTaxNumberList << var;
	}
	return reTaxNumberList.join(',');
}

bool DownloadHelper::isNewVer(QString oldVer,QString newVer)
{
	QStringList oldVerList = oldVer.split(".");
	QStringList newVerList = newVer.split(".");
	for (size_t i = 0; i < (oldVerList.size() > newVerList.size() ? newVerList.size() : oldVerList.size()); i++)
	{
		if (oldVerList.at(i).toInt() != newVerList.at(i).toInt())
		{
			if (oldVerList.at(i).toInt() < newVerList.at(i).toInt())
				return false;
			return true;
		}	
	}
	return true;
}


//获取本机公网IP地址
bool DownloadHelper::GetNetIP(QString &province, QString &city) {
	QString netIp = getServerIp();
	if (!netIp.isEmpty())
	{
		if (getPC(netIp, province, city))
		{
			return true;;
		}
	}
	netIp = getWebIp();
	if (!netIp.isEmpty())
	{
		if (getPC(netIp, province, city))
		{
			return true;;
		}
	}
	return false;
}

QString DownloadHelper::getWebIp()
{
	QString url = "http://whois.pconline.com.cn/";
	QNetworkAccessManager *manager = new QNetworkAccessManager();
	QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(url)));
	QByteArray responseData;
	QEventLoop eventLoop;
	QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
	eventLoop.exec();
	responseData = reply->readAll();


	QString web = responseData.replace(" ", "");
	web = web.replace("\r", "");
	web = web.replace("\n", "");
	QStringList list = web.split("<br/>");

	if (list.size() > 4)
	{
		QString tar = list[4];
		QStringList ip = tar.split("=");
		if (ip.size() > 1)
		{
			QString netIp = ip[1];
			QStringList ipList = netIp.split(",");
			if (ipList.size() > 0)
			{
				netIp = ipList.at(0);
				return netIp;
			}
		}
	}
	return "";
}

QString  DownloadHelper::getServerIp()
{
	QString strUrl = STRGETMD5URL + QString("/general/get-server-time");

	QNetworkAccessManager *manager = new QNetworkAccessManager();
	QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(strUrl)));
	QByteArray responseData;
	QEventLoop eventLoop;
	QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
	eventLoop.exec();
	responseData = reply->readAll();

	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError && parse_doucment.isObject())
	{
		QJsonObject obj = parse_doucment.object();
		int code = obj.take("status").toInt();
		if (code == 0)
		{
			QJsonObject data = obj.take("data").toObject();
			QString netIp = data.take("client_ip").toString();
			return netIp;
		}
	}
	return "";
}



bool DownloadHelper::getPC(QString netIp, QString &province, QString &city)
{
	QNetworkAccessManager *manager = new QNetworkAccessManager();
	QByteArray responseData;
	QNetworkReply *reply = manager->get(QNetworkRequest(QUrl("http://api.map.baidu.com/location/ip?ak=aaiHrfToeg63rSDdoPg8SgXE&ip=" + netIp)));
	QEventLoop eventLoop;
	QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
	eventLoop.exec();
	responseData = reply->readAll();

	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
	if (json_error.error == QJsonParseError::NoError && parse_doucment.isObject())
	{
		QJsonObject obj = parse_doucment.object();
		int code = obj.take("status").toInt();
		if (code == 0)
		{
			QJsonObject address_detail = obj.take("content").toObject().take("address_detail").toObject();
			province = address_detail.take("province").toString().toUtf8();
			city = address_detail.take("city").toString().toUtf8();
			if (!province.isEmpty() && !city.isEmpty())
				return true;
		}
	}
	return false;
}