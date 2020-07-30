#include "HttpDownload.h"
#include <QFileInfo>
#include <QNetworkRequest>
#include <QUrl>
#include <QDir>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QTimer>

#define  DOWNLOAD_FILE_SUFFIX "_tmp_download"
HttpDownload::HttpDownload(QString strDirName, QString strDownloadUrl, QString strMd5, bool bCompareMd5,QObject *parent)
	: QObject(parent)
	, m_strMd5(strMd5)
	, m_bCompareMd5(bCompareMd5)
{
	getDownloadFilePath(strDirName, strDownloadUrl);
}

HttpDownload::~HttpDownload()
{
}

void HttpDownload::getDownloadFilePath(QString strDirName, QString strDownloadUrl)
{
	QFileInfo fileInfo(QUrl::fromUserInput(strDownloadUrl).path());
	QString strAppFileName = fileInfo.fileName();

	QDir dir(strDirName);
	if (!dir.exists())
	{
		dir.mkdir(strDirName);
	}

	m_strFileFullName = strDirName + strAppFileName + DOWNLOAD_FILE_SUFFIX;
	QFileInfo fileInfoName(m_strFileFullName);
	if (fileInfoName.exists())
		m_bytesCurrentReceived = fileInfoName.size();
	else
		m_bytesCurrentReceived = 0;

	m_file.setFileName(m_strFileFullName);
}

bool HttpDownload::startDownload(QString strDownloadUrl)
{
	QNetworkRequest request;
	if (strDownloadUrl.toLower().startsWith("https"))
	{
		QSslConfiguration sslConfig;
		sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
		sslConfig.setProtocol(QSsl::TlsV1_1);
		request.setSslConfiguration(sslConfig);
	}
	request.setUrl(strDownloadUrl);

	if (m_bytesCurrentReceived > 0)
	{
		QString strRange = QString("bytes=%1-").arg(m_bytesCurrentReceived);
		request.setRawHeader("Range", strRange.toLatin1());
	}
	QNetworkAccessManager	networkManager(this);
	m_reply = networkManager.get(request);

	//!请求超时计时器
	QTimer timer; 
	QEventLoop loop;
	connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));

	connect(m_reply, SIGNAL(downloadProgress(qint64, qint64)), this, SIGNAL(sigDownloadProgress(qint64, qint64)));
	connect(m_reply, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
	connect(m_reply, SIGNAL(finished()), &loop, SLOT(quit()));

	//! 10分钟过期时间
	timer.start(1000*60*10);
	loop.exec();

	//!http返回码
	int nHttpCode = m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	if (timer.isActive())
	{  
		timer.stop();
		//!重定向
		if (nHttpCode == 301 || nHttpCode	==	302)
		{
			disconnect(m_reply);
			startDownload(m_reply->rawHeader("Location"));
		}
		else
		{
			if (m_reply->error() == QNetworkReply::NoError)
			{
				if (nHttpCode == 200)//成功返回
				{
					QFileInfo fileInfo(m_strFileFullName);
					if (fileInfo.exists())
					{
						m_file.close();
						int index = m_strFileFullName.lastIndexOf(DOWNLOAD_FILE_SUFFIX);
						QString strRealName = m_strFileFullName.left(index);
						qDebug() << "download sucessed the file path is" << strRealName;
						QFileInfo realFile(strRealName);
						if (realFile.exists())
							QFile::remove(strRealName);

						if (!QFile::rename(m_strFileFullName, strRealName))
						{
							qDebug() << "rename failed";
							removeFile();
							return false;
						}
						if (m_bCompareMd5)
						{
							QFile theFile(strRealName);
							theFile.open(QIODevice::ReadOnly);
							QByteArray ba = QCryptographicHash::hash(theFile.readAll(), QCryptographicHash::Md5);
							theFile.close();
							QString fileMd5 = ba.toHex().constData();
							fileMd5 = fileMd5.toUpper();
							if (fileMd5 == m_strMd5)
							{
								m_strFileName = strRealName;
								return true;
							}
							else
							{
								//----------------------------------------------------------------cf--------------//
								qDebug() << "md5 compare failed,download file md5:" << fileMd5 <<" interface file md5:"<< m_strMd5;
								removeFile();
								return false;
							}
						}
						else
						{
							m_strFileName = strRealName;
							return true;
						}
						
					}
				}
			}
		}
	}
	removeFile();
	return false;
}

void HttpDownload::onReadyRead()
{
	if (m_file.fileName().isEmpty())
	{
		removeFile();
		return;
	}

	if (!m_file.isOpen()) 
	{
		if (!m_file.open(QIODevice::WriteOnly | QIODevice::Append)) 
		{
			removeFile();
			return;
		}
	}
	if (-1 == m_file.write(m_reply->readAll())) 
	{
		removeFile();
	}
}

void HttpDownload::removeFile()
{
	m_file.close();
	QFileInfo fileInfo(m_strFileFullName);
	if (fileInfo.exists())
	{
		QFile::remove(m_strFileFullName);
	}

	int index = m_strFileFullName.lastIndexOf(DOWNLOAD_FILE_SUFFIX);
	QString strRealName = m_strFileFullName.left(index);
	QFileInfo fileInfo1(strRealName);
	if (fileInfo1.exists())
	{
		QFile::remove(strRealName);
	}
}

QString HttpDownload::getFileName()
{
	return m_strFileName;
}
