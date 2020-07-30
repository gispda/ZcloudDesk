#include "DownloadAssist.h"
#include <QEventLoop>
#include <QSettings>
#include <QNetworkInterface>
#include <QJsonDocument>
#include <QJsonObject>
#include <QCoreApplication>
#include <QFileInfo>
#include <QDir>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QProcess>
#include <QWaitCondition>
#include "HttpDownload.h"
#include <QDebug>
#include "BigDataImpl.h"
//const QString strHttpUrl = "https://91z9v0jc.clouduan.com";		//!全国
//const QString strHttpUrl = "https://gz91z9v0jc.clouduan.com";		//!贵州
const QString strHttpUrl = "https://testpay.zhicloud.com";			//!测试

DownloadAssist::DownloadAssist(QObject *parent)
	: QObject(parent)
	, m_pTimer(new QTimer(this))
{
	//!延迟启动
	connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimerOut()));
	m_pTimer->start(1000);
}

DownloadAssist::~DownloadAssist()
{
}

bool DownloadAssist::httpPost(QString strUrl, QString strPost, int nTimeout, QString& strRet)
{
	QNetworkAccessManager networkManager;//网络管理类
	QNetworkReply *pNetworkReply = NULL; //封装请求返回信息
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

	if (strPost.isEmpty())
		pNetworkReply = networkManager.get(netRequest);
	else
		pNetworkReply = networkManager.post(netRequest, strPost.toUtf8());//发起post请求
	connect(pNetworkReply, SIGNAL(finished()), &loop, SLOT(quit()));

	login_pTimer.start(nTimeout);
	loop.exec();
	QByteArray resultContent = pNetworkReply->readAll();
	int nHttpCode = pNetworkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();//http返回码
	strRet = "";
	if (login_pTimer.isActive())
	{  // 处理响应
		login_pTimer.stop();
		if (pNetworkReply->error() == QNetworkReply::NoError)
		{
			if (nHttpCode == 200)//成功返回
			{
				strRet = QString(resultContent);
				return true;
			}
		}
	}
	return false;
}

bool DownloadAssist::winHttpGetDownloadAssistant(QString& strDownloadUrl, QString& strVer, QString& strMd5)
{
	QString strUrl = strHttpUrl + "/general/get-download-assistant";
	QString strBody = "mac=" + getMacAddr() + "&os_version=" + getOsVer() + "&tax_number=" + "[" + getTaxs() + "]";

	QString strLocation,strPro, strCity;
	if (getLocation(strPro, strCity))
	{
		strLocation = QString("&province=%1&city=%2").arg(strPro).arg(strCity);
		strBody += strLocation;
	}
	qDebug() << "http url:" << strUrl;
	qDebug() << "http post:" << strBody;
	QString strRet;
	if (!httpPost(strUrl, strBody, 5000, strRet))
	{
		qDebug() << "http failed!";
		return false;
	}

	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return false;
	}
	if (!parse_doucment.isObject())
	{
		return false;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("status").toInt();
	if (30015 == status || 30016 == status)
	{
		//3015  税号在白名单中
		//3016	mac在白名单中
		qDebug() << "white list, code is" << status;
		return false;
	}
	else if (0 == status)
	{
		QJsonObject dataObj = obj.take("data").toObject();
		strDownloadUrl	= dataObj.take("download_url").toString();
		strVer			= dataObj.take("version").toString();
		strMd5			= dataObj.take("md5").toString();
		strMd5			= strMd5.toUpper();

		if (!strDownloadUrl.isEmpty() && !strVer.isEmpty() && !strMd5.isEmpty())
		{
			return true;
		}
		else
		{
			//-------------------------------cf-----------------//
			qDebug() << "some of 3 params are empty!";
		}
	}
	return false;
}

QString DownloadAssist::getOsVer()
{
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

QString DownloadAssist::getTaxs()
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

QString DownloadAssist::getMacAddr()
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

QString DownloadAssist::getPublicIp()
{
	QString strUrl = strHttpUrl + QString("/general/get-server-time");
	QString strRet;
	if (!httpPost(strUrl,"",5000,strRet))
	{
		//!获取IP失败
		return "";
	}
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return "";
	}
	if (!parse_doucment.isObject())
	{
		return "";
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("status").toInt();
	if (0 == status)
	{
		QJsonObject data = obj.take("data").toObject();
		return data.take("client_ip").toString();
	}
	return "";
}

bool DownloadAssist::getLocation(QString& strPro, QString& strCity)
{
	QString strPublic = getPublicIp();
	if (strPublic.isEmpty())
	{
		return false;
	}
	QString strRet;
	if (!httpPost(QString("http://api.map.baidu.com/location/ip?ak=aaiHrfToeg63rSDdoPg8SgXE&ip=%1").arg(strPublic), "", 5000, strRet))
	{
		return false;
	}
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return false;
	}
	if (!parse_doucment.isObject())
	{
		return false;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("status").toInt();
	if (0 == status)
	{
		QJsonObject address_detail = obj.take("content").toObject().take("address_detail").toObject();
		strPro	= address_detail.take("province").toString().toUtf8();
		strCity = address_detail.take("city").toString().toUtf8();
		if (!strPro.isEmpty() && !strCity.isEmpty())
			return true;
	}
	return false;
}

bool DownloadAssist::startWork()
{
	//!十分钟随机
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	unsigned long test = qrand() % 1000 * 60 * 3;
	QMutex mutex;
	QWaitCondition sleep;
	mutex.lock();
	sleep.wait(&mutex, test);
	mutex.unlock();

	QString strDownloadUrl, strVer, strMd5;
	//!下载地址获取失败
	if (!winHttpGetDownloadAssistant(strDownloadUrl, strVer, strMd5))
	{
		BigDataImpl::GetInstance()->produceData("M00", "OP001", "PFI002");
		qDebug() << "http failed!";
		return false;
	}
	BigDataImpl::GetInstance()->produceData("M00", "OP001", "PFI001");

	QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{A9D22CBD-1E78-4813-8773-007907D30803}_is1", QSettings::NativeFormat);
	if (settings->contains("InstallLocation") && settings->contains("DisplayName") && isNewVer(settings->value("DisplayVersion", QVariant()).toString(), strVer))
	{
		BigDataImpl::GetInstance()->produceData("M00", "OP000", "PFI007");
		qDebug() << "local has higher ver than interface!";
		delete settings;
		return true;
	}
	delete settings;

	//!下载失败
	QString strFileName;
	if (!download(strDownloadUrl, strMd5, strFileName))
	{
		BigDataImpl::GetInstance()->produceData("M00", "OP000", "PFI004");
		qDebug() << "download failed!";
		return false;
	}
	BigDataImpl::GetInstance()->produceData("M00", "OP000", "PFI003");

	//!安装失败
	if (!install(strFileName))
	{
		BigDataImpl::GetInstance()->produceData("M00", "OP000", "PFI006");
		qDebug() << "start install process failed!";
		return false;
	}
	
	QSettings *settings1 = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{A9D22CBD-1E78-4813-8773-007907D30803}_is1", QSettings::NativeFormat);
	if (settings1->contains("InstallLocation") && settings1->contains("DisplayName") && isNewVer(settings1->value("DisplayVersion", QVariant()).toString(), strVer))
	{
		BigDataImpl::GetInstance()->produceData("M00", "OP000", "PFI005");

		//!删除文件
		QFile::remove(strFileName);
		delete settings1;

		//!删除自启动注册表
		QSettings *reg = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
		reg->remove("zhicloud");
		delete reg;
	}
	else
	{
		//-----------------------------------------------------cf-------------------------//
		qDebug() << "install failed!";
		return false;
	}
	return true;
}

void DownloadAssist::onTimerOut()
{
	if (!startWork())
	{
		m_pTimer->start(1000*60*60*2);
	}
	else
	{
		m_pTimer->stop();
		qApp->quit();
	}
}

bool DownloadAssist::download(QString strDownloadUrl, QString strMd5, QString& strFileName)
{
	HttpDownload*	pHttpDownload = new HttpDownload(QApplication::applicationDirPath()+"/", strDownloadUrl, strMd5, true, this);
	bool bSucessed	=	pHttpDownload->startDownload(strDownloadUrl);
	strFileName		=	pHttpDownload->getFileName();

	QFileInfo file(strFileName);
	return (bSucessed	&&	file.isFile());
}

bool DownloadAssist::install(QString strFileName)
{
	strFileName = "\"" + strFileName + "\"";	//!空格处理
	QProcess *ap = new QProcess(this);
	ap->start(strFileName);
	return ap->waitForFinished(-1);
}

bool DownloadAssist::isNewVer(QString oldVer, QString newVer)
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