#include "DownLoadThread.h"
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <QNetworkProxyQuery>
#define DOWNLOAD_FILE_SUFFIX	"_tmp"
#define DOWNLOAD_TIMEOUT   10000

//5555
DownLoadThread::DownLoadThread(QObject *parent)
	: QThread(parent)
	, m_networkManager(NULL)
	, m_url(QUrl(""))
	, m_fileName("")
	, m_isSupportBreakPoint(false)
	, m_bytesReceived(0)
	, m_bytesTotal(0)
	, m_bytesCurrentReceived(0)
	, m_isStop(true)
{
	m_networkManager = new QNetworkAccessManager(this);
	m_url = "";
}

DownLoadThread::~DownLoadThread()
{

}

// 设置是否支持断点续传;
void DownLoadThread::setDownInto(bool isSupportBreakPoint)
{
	m_isSupportBreakPoint = isSupportBreakPoint;
}

QString DownLoadThread::getDownloadUrl()
{
	return m_url.toString();
}

// 开始下载文件;
void DownLoadThread::downloadFile(QString url, QString fileName,bool appMsg)
{
	// 防止多次点击开始下载按钮，进行多次下载，只有在停止标志变量为true时才进行下载;
	if (m_isStop)
	{
		m_isStop = false;
		m_url = QUrl::fromUserInput(url);
		// 从url 中获取文件名，但不是都有效;
		QFileInfo fileInfo(m_url.path());
		QString appFileName = fileInfo.fileName();
		if (appFileName.isEmpty())
			appFileName = "invoice.exe";


		// 将当前文件名设置为临时文件名，下载完成时修改回来;  1 排除应用中心的 重叠下载
		m_fileName = fileName.append("/downloadApp/") + "1" +appFileName + DOWNLOAD_FILE_SUFFIX;
		QDir fileD(fileName);
		if (!fileD.exists())
		{
			fileD.mkpath(fileName);
		}
		// 如果当前下载的字节数为0那么说明未下载过或者重新下载
		// 则需要检测本地是否存在之前下载的临时文件，如果有则删除

		QFileInfo fileInfoName(m_fileName);
		if (fileInfoName.exists())
			m_bytesCurrentReceived = fileInfoName.size();
		else
			m_bytesCurrentReceived = 0;

		if (m_bytesCurrentReceived <= 0)
		{
			removeFile(m_fileName);
		}
		startAyalseUrl(url);
		m_DOWNLOADETYPE = m_DOWNLOADING;
	}	
}

// 下载进度信息;
void DownLoadThread::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
	if (!m_isStop)
	{
		m_bytesReceived = bytesReceived;
		m_bytesTotal = bytesTotal;
		// 更新下载进度;(加上 m_bytesCurrentReceived 是为了断点续传时之前下载的字节)
		emit signalDownloadProcess(m_bytesReceived + m_bytesCurrentReceived, m_bytesTotal + m_bytesCurrentReceived);
	}	
}

// 获取下载内容，保存到文件中;
void DownLoadThread::onReadyRead()
{
	if (!m_isStop)
	{
		QFile file(m_fileName);
		if (file.open(QIODevice::WriteOnly | QIODevice::Append))
		{
			file.write(m_reply->readAll());
		}
		file.flush();
		file.close();
	}	
}

// 下载完成;
void DownLoadThread::onFinished()
{
	if (m_DOWNLOADETYPE != m_DOWNLOADING || !m_reply)
	{
		return;
	}
	QVariant statusCode = m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	int nStatusCode = statusCode.toInt();
	if (nStatusCode == 302 || nStatusCode == 301)
	{
		removeFile(m_fileName);
		startAyalseUrl(m_reply->rawHeader("Location"));
	}
	else
	{
		m_isStop = true;
		disconnect(m_reply);
		QString realName;
		if (m_reply->error() == QNetworkReply::NoError)
		{
			// 重命名临时文件;
			QFileInfo fileInfo(m_fileName);
			if (fileInfo.exists())
			{
				int index = m_fileName.lastIndexOf(DOWNLOAD_FILE_SUFFIX);
				realName = m_fileName.left(index);
				QFileInfo realFile(realName);
				if (realFile.exists())
				{
					QFile::remove(realName);
				}
				QFile::rename(m_fileName, realName);
				m_fileName = realName;
			}
			m_DOWNLOADETYPE = m_FINISH;
			emit signalReplyFinished(statusCode.toInt(), realName);
			this->start();  // 用于等待安装完成
		}
		else
		{
			//// 有错误输出错误;
			//QString errorStr;
			//if (m_reply->error() == QNetworkReply::TimeoutError || m_reply->error() == QNetworkReply::NetworkSessionFailedError || m_reply->error() == QNetworkReply::RemoteHostClosedError)
			//{
			//	errorStr = QString::fromLocal8Bit("网络超时，请检查网络连接");
			//}
			//else
			//{
			//	reset();
			//	errorStr = QString::fromLocal8Bit("下载错误。请重新下载");
			//	removeFile(m_fileName);
			//}

			//emit signalDownloadError(errorStr);
			m_DOWNLOADETYPE = m_ERROR;
			return;
		}
	}
}

// 下载过程中出现错误，关闭下载，并上报错误，这里未上报错误类型，可自己定义进行上报;
void DownLoadThread::onError(QNetworkReply::NetworkError code)
{
	disconnect(m_reply);
	QString errorStr;
	if (m_reply->error() == QNetworkReply::TimeoutError || m_reply->error() == QNetworkReply::NetworkSessionFailedError || m_reply->error() == QNetworkReply::RemoteHostClosedError)
	{
		errorStr = QString::fromLocal8Bit("网络超时，请检查网络连接");
	}
	else
	{
		errorStr = QString::fromLocal8Bit("下载错误。请重新下载");
		reset();
		removeFile(m_fileName);
	}
	qDebug() << "zcd-0x0000001B:" << "uil=" << m_reply->url().toString() << errorStr;
	emit signalDownloadError(errorStr);
	//stopWork(false);
	m_DOWNLOADETYPE = m_ERROR;
}

void DownLoadThread::run()
{
	QProcess *ap = new QProcess(NULL);
	ap->setProgram(m_fileName);
	ap->start();
	emit installFinished(ap->waitForFinished(-1));
}

// 停止下载工作; 用于关闭下载
void DownLoadThread::stopWork(bool appMsg)
{
	m_isStop = true;
	reset();
	if (m_reply != NULL)
	{
		disconnect(m_reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
		disconnect(m_reply, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
		disconnect(m_reply, SIGNAL(finished()), this, SLOT(onFinished()));
		disconnect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
		m_reply->abort();
		m_reply->deleteLater();
		m_reply = NULL;
	}
}

//// 停止下载工作;用于暂停下载
//void DownLoadThread::stopWorkDoanload()
//{
//	m_isStop = true;
//	if (m_reply != NULL)
//	{
//		disconnect(m_reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
//		disconnect(m_reply, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
//		disconnect(m_reply, SIGNAL(finished()), this, SLOT(onFinished()));
//		disconnect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
//		m_reply->abort();
//		m_reply->deleteLater();
//		m_reply = NULL;
//	}
//}
//// 暂停下载按钮被按下,暂停当前下载;
//void DownLoadThread::stopDownload(bool appMsg)
//{
//	// 这里m_isStop变量为了保护多次点击暂停下载按钮，导致m_bytesCurrentReceived 被不停累加;
//	if (!m_isStop)
//	{
//		//记录当前已经下载字节数；
//		m_bytesCurrentReceived += m_bytesReceived;
//		stopWorkDoanload();
//		m_DOWNLOADETYPE = m_PAUSE;
//		m_isStop = true;
//	}
//}

// 重置参数;
void DownLoadThread::reset()
{
	m_bytesCurrentReceived = 0;
	m_bytesReceived = 0;
	m_bytesTotal = 0;
}

// 删除文件;
void DownLoadThread::removeFile(QString fileName)
{
	// 删除已下载的临时文件;
	QFile::remove(fileName);
}

// 关闭下载，重置参数，并删除下载的临时文件;
void DownLoadThread::closeDownload(bool appMsg)
{
	stopWork(appMsg);
	reset();
	//removeFile(m_fileName);
	m_DOWNLOADETYPE = m_CLOSE;
}

void DownLoadThread::startAyalseUrl(QString strUrl)
{
	QNetworkRequest request;
	request.setUrl(QUrl::fromUserInput(strUrl));

	// 如果支持断点续传，则设置请求头信息;
	if (m_isSupportBreakPoint)
	{
		QString strRange = QString("bytes=%1-").arg(m_bytesCurrentReceived);
		request.setRawHeader("Range", strRange.toLatin1());
	}

	//------------------------注销单独设置代理---------------------------------//

	m_reply = m_networkManager->get(request);

	connect(m_reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
	connect(m_reply, SIGNAL(readyRead()), this, SLOT(onReadyRead()), Qt::DirectConnection);
	connect(m_reply, SIGNAL(finished()), this, SLOT(onFinished()));
	connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
}
