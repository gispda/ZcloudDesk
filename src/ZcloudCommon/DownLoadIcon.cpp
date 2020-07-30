#include "DownLoadIcon.h"
#include <QNetworkProxyQuery>
#define DOWNLOAD_FILE_SUFFIX	"_tmp"
DownLoadIcon::DownLoadIcon(int msec,QObject *parent) :
    QThread(parent)
	, m_msec(msec)
{
}
void DownLoadIcon::run()
{
    if(m_Url.isEmpty() || filePath.isEmpty())
    {
        return;
    }
	QDir dir(filePath);
	if(!dir.exists())
	{
		dir.mkdir(filePath);//鍙垱寤轰竴绾у瓙鐩綍锛屽嵆蹇呴』淇濊瘉涓婄骇鐩綍瀛樺湪
	}
    QFileInfo info(QUrl::fromUserInput(m_Url).path());
	
	if (appID.isEmpty())
	{
		down_name = info.fileName();
		if (down_name.isEmpty())
		{
			QString path = info.path();
			QFileInfo info(path);
			QString baseName = info.completeBaseName();
			QString endName = info.suffix();

			if (baseName.isEmpty()) 		
				baseName = QLatin1String("unnamed_download");
			QString directory = filePath + "\\";
			QString name = directory + baseName + QLatin1Char('.') + endName + DOWNLOAD_FILE_SUFFIX;

			QFileInfo realFile(name);
			if (realFile.exists() && !QFile::remove(name))
			{
				int i = 1;
				do {
					name = baseName + QLatin1Char('-') + QString::number(i++) + QLatin1Char('.') + endName + DOWNLOAD_FILE_SUFFIX;
				} while (QFile::exists(name) && !QFile::remove(name));
			}else
				down_name = baseName + QLatin1Char('.') + endName + DOWNLOAD_FILE_SUFFIX;
		}else
			down_name += DOWNLOAD_FILE_SUFFIX;
	}
	else
	{
		down_name = appID + ".png" + DOWNLOAD_FILE_SUFFIX;
	}
	filePath.append("\\").append(down_name);
    file = new QFile(filePath);
    if(!file->exists())
    {
        if(!file->open(QIODevice::ReadWrite))
        {
            delete file;
            file = 0;
            return;
        }
    }else
    {
        file->remove();
        if(!file->open(QIODevice::ReadWrite))
        {
            delete file;
            file = 0;
            return;
        }
    }

    m_pNetworkManager = new QNetworkAccessManager();
//    m_pNetworkManager->moveToThread(this);
    m_pNetworkReply = NULL;
    m_pTimer = new QTimer;

    connect(m_pTimer,SIGNAL(timeout()),this,SLOT(requestTimeout()),Qt::DirectConnection);//杩炴帴瓒呮椂淇″彿
	loop = new QEventLoop();

	startAyalseUrl(m_Url);

	m_pTimer->start(m_msec);
    loop->exec();
}

///////////////////////////////////
//鍑芥暟浣滅敤锛氳缃枃浠惰矾寰勶紝鍜屼笅杞藉湴鍧€
//////////////////////////////
void DownLoadIcon::setValue(QString flilePath, QString url,QString id)
{
    this->filePath = flilePath;
	this->appID = id;//文件名 如果文件名不为空 则以此为文件名
    this->m_Url = url;
}

//璇锋眰瓒呮椂
void DownLoadIcon::requestTimeout()
{
	if (file)
	{
		if (file->exists())
		{
			file->remove();
		}
	}
    this->m_pTimer->stop();//鍏抽棴瀹氭椂鍣?
    loop->quit();
}

//涓嬭浇瀹屾垚淇″彿
void DownLoadIcon::requestFinished()
{
	QVariant statusCode = m_pNetworkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	int nStatusCode = statusCode.toInt();
	if (nStatusCode == 302 || nStatusCode == 301)
	{
		startAyalseUrl(m_pNetworkReply->rawHeader("Location"));
	}
	else
	{
		file->flush();
		file->close();
		if (m_pNetworkReply->error() == QNetworkReply::NoError)
		{
			int index = filePath.lastIndexOf(DOWNLOAD_FILE_SUFFIX);
			QString realName = filePath.left(index);
			QFileInfo realFile(realName);
			if (realFile.exists() && !QFile::remove(realName))
			{
				//如果删除时 被占用  更改名字
				QString baseName = realFile.completeBaseName();
				QString endName = realFile.suffix();
				QString directory = realFile.path() + "//";
				realName = directory + baseName + QLatin1Char('.') + endName;
				int i = 1;
				do {
					realName = directory + baseName + QLatin1Char('_') + QString::number(i++) + QLatin1Char('.') + endName;
				} while (QFile::exists(realName) && !QFile::remove(realName));
			}

			if (QFile::rename(filePath, realName))
			{
				filePath = realName;
			}
			else
			{
				//如果更改文件失败 就用临时文件
				qDebug() << "zcd-0x0000003A:" << QString("rename image Error:filePath=%1,realName = %2").arg(filePath).arg(realName);
			}
			errorFlag = true;
		}
		else
		{
			qDebug() << "zcd-0x0000003B:" << QString("download image Error:%1,httpUrl:%2,code:%3").arg(m_pNetworkReply->error()).arg(m_Url).arg(m_pNetworkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt());
			errorFlag = false;
		}
			
	
		if (!errorFlag)
		{
			if (file->exists())
			{
				file->remove();
			}
		}
		m_pNetworkReply->deleteLater();
		m_pNetworkReply = 0;
		delete file;
		file = NULL;
		emit finished_signal();
		loop->quit();
	}
}

void DownLoadIcon::httpReadyRead() //涓嬭浇
{
	if (file)
	{
		file->write(m_pNetworkReply->readAll());  //濡傛灉鏂囦欢瀛樺湪锛屽垯鍐欏叆鏂囦欢
	}
}

void DownLoadIcon::startAyalseUrl(QString strUrl)
{
	QNetworkRequest netRequest;

	if (strUrl.toLower().startsWith("https"))//https璇锋眰锛岄渶ssl鏀寔(涓嬭浇openssl鎷疯礉libeay32.dll鍜宻sleay32.dll鏂囦欢鑷砆t bin鐩綍鎴栫▼搴忚繍琛岀洰褰?
	{
		QSslConfiguration sslConfig;
		sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
		sslConfig.setProtocol(QSsl::TlsV1_1);
		netRequest.setSslConfiguration(sslConfig);
	}
	netRequest.setUrl(QUrl::fromUserInput(strUrl)); //鍦板潃淇℃伅

	//------------------------注销单独设置代理---------------------------------//

	m_pNetworkReply = m_pNetworkManager->get(netRequest); //鍙戣捣get璇锋眰
	connect(m_pNetworkReply, SIGNAL(downloadProgress(qint64, qint64)), this, SIGNAL(readProgress(qint64, qint64)));//鏇存柊杩涘害鏉?
	connect(m_pNetworkReply, SIGNAL(finished()), this, SLOT(requestFinished())); //璇锋眰瀹屾垚淇″彿
	connect(m_pNetworkReply, SIGNAL(readyRead()), this, SLOT(httpReadyRead())); //鏈夊彲鐢ㄦ暟鎹椂
}
