#include "AppDownLoadThread.h"

#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <QSettings>
#include <QApplication>
#include <QTextCodec>
#include "AppCommFun.h"
#include "AppDatabase/AppCenterDatabase.h"
#include <QNetworkProxyQuery>

AppDownLoadThread::AppDownLoadThread(AppDataInfo pData, QObject *parent)
	: QThread(parent)
	, m_pData(pData)
	, m_fileName("")
	, m_bytesReceived(0)
	, m_bytesTotal(0)
	, m_bytesCurrentReceived(0)
{
	m_networkManager = new QNetworkAccessManager(this);
}

AppDownLoadThread::~AppDownLoadThread()
{

}

void AppDownLoadThread::setDownloadValue(QString url, QString fileName, qint64 bytesCurrentReceived, qint64 totalSize)
{
	m_strUrl = url;
	m_fileName = fileName;
	// 如果当前下载的字节数为0那么说明未下载过或者重新下载
	// 则需要检测本地是否存在之前下载的临时文件，如果有则删除
	m_bytesCurrentReceived = bytesCurrentReceived;
	m_bytesTotal = totalSize - bytesCurrentReceived;
	if (m_bytesCurrentReceived <= 0)
	{
		removeFile(m_fileName);
	}
	else
	{
		if (bytesCurrentReceived && totalSize && bytesCurrentReceived >= totalSize)
			emit signalDownloadProcess(bytesCurrentReceived, totalSize);
		else
			emit signalDownloadProcess(0, 100);
	}
	file.setFileName(m_fileName);
	if (bytesCurrentReceived == totalSize && totalSize != 0)
		m_downloadFilish = true;
}

void AppDownLoadThread::run()
{
	bool isNewVerson = false;//是否是 最新版本
	if (m_APPDOWNLOADETYPE == mapp_FINISH)
	{
		emit signalDownloadProcess(100,100);
		emit signalStatusChanged(mapp_FINISH);
		QProcess *ap = new QProcess(NULL);
		ap->setProgram(m_fileName);
		ap->start();
		ap->waitForFinished(-1);
		if (!m_isHaveApp)//如果之前不存在 则直接 把线上版本设置为当前版本
			m_pData.m_strAppCurrentVerson = m_pData.m_strAppOnLineVerson;
		//如果是首次安装则不匹配 版本 
		bool isInstallFlag = AppCommFun::isHaveNewVerson(m_pData, isNewVerson);
		if (isInstallFlag && (!m_isHaveApp || isNewVerson))//判断 已经安装了的  且是最新版本(如果是第一次安装 就不会判定版本)
		{
			m_APPDOWNLOADETYPE = mapp_INSTALLFINLSH;
			//保存app下载更新情况
			m_pData.m_statusAppButton = mapp_INSTALLFINLSH;
			AppCenterDatabase::instance()->updateApp(m_pData);

			m_pData.m_bAppIsInstall = true;

			emit signalStatusChanged(mapp_INSTALLFINLSH);
			emit installFinishAdd(m_pData);
			return;
		}	
		else
		{
			if (isInstallFlag)
			{
				//上报大数据 待处理
			}
			else
			{

			}
			//m_pData.m_statusAppButton = mapp_INSTALLERROR;
			//AppCenterDatabase::instance()->updateApp(m_pData);
			m_APPDOWNLOADETYPE = mapp_INSTALLERROR;

			//保存app下载更新情况
			m_pData.m_statusAppButton = mapp_INSTALLERROR;
			AppCenterDatabase::instance()->updateApp(m_pData);
			emit signalStatusChanged(mapp_INSTALLERROR);
			return;
		}
	}
	else	
	{
		m_pData.m_statusAppButton = mapp_DOWNLOADING;
		m_APPDOWNLOADETYPE = mapp_DOWNLOADING;


		//保存app下载更新情况
		m_pData.m_statusAppButton = mapp_DOWNLOADING;
		AppCenterDatabase::instance()->updateApp(m_pData);

		emit signalStatusChanged(mapp_DOWNLOADING);
		if (m_bytesCurrentReceived <= 0)
		{
			if (AppCommFun::isHaveNewVerson(m_pData, isNewVerson))//判断 已经安装了的  且是最新版本
			{
				if (isNewVerson)
				{

					//保存app下载更新情况
					m_pData.m_statusAppButton = mapp_INSTALLFINLSH;
					AppCenterDatabase::instance()->updateApp(m_pData);
					m_APPDOWNLOADETYPE = mapp_INSTALLFINLSH;
					m_pData.m_bAppIsInstall = true;
					m_pData.m_statusAppButton = mapp_INSTALLFINLSH;
					AppCenterDatabase::instance()->updateApp( m_pData, true);
					emit signalStatusChanged(mapp_INSTALLFINLSH);
					emit installFinishAdd(m_pData);
					return;
				}
				m_isHaveApp = true;
			}
			else
				m_isHaveApp = false;
			//由于查询注册表 耗时 比较多   中途有可能点击了  暂停或者关闭
			if (m_APPDOWNLOADETYPE != mapp_DOWNLOADING)
				return;
		}
		if (!loop)
		{
			loop = new QEventLoop();
			loop->moveToThread(this);
		}
		QNetworkRequest request;
		request.setUrl(QUrl::fromUserInput( m_strUrl));
		// 如果支持断点续传，则设置请求头信息;
		if (m_bytesCurrentReceived >  0)
		{
			QString strRange = QString("bytes=%1-").arg(m_bytesCurrentReceived);
			request.setRawHeader("Range", strRange.toLatin1());
		}
		//------------------------注销单独设置代理---------------------------------//
		if (m_reply)
		{
			m_reply->disconnect();
			m_reply->deleteLater();
			m_reply = NULL;
		}

		m_reply = m_networkManager->get(request);
		if (m_reply)
		{
			connect(m_reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
			connect(m_reply, SIGNAL(readyRead()), this, SLOT(onReadyRead()), Qt::DirectConnection);
			connect(m_reply, SIGNAL(finished()), this, SLOT(onFinished()));
			connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
			loop->exec();
			if (m_APPDOWNLOADETYPE == mapp_FINISH)
				this->run();
		}
	}
}

// 下载进度信息;
void AppDownLoadThread::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
	if (m_APPDOWNLOADETYPE != mapp_DOWNLOADING) return;
	if (!m_bytesTotal && !m_bytesCurrentReceived)//发送文件大小
		emit signalStatusChanged(mapp_DOWNLOADING);
	m_bytesTotal = bytesTotal;
	
	m_bytesReceived = bytesReceived;
	// 更新下载进度;(加上 m_bytesCurrentReceived 是为了断点续传时之前下载的字节)
	emit signalDownloadProcess(m_bytesReceived + m_bytesCurrentReceived, m_bytesTotal + m_bytesCurrentReceived);
}

// 获取下载内容，保存到文件中;
void AppDownLoadThread::onReadyRead()
{
	if (file.fileName().isEmpty())
		return;

	if (!file.isOpen()) {
		// in case someone else has already put a file there
		if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
			errorReset(-1);
			return;
		}
	}
	if (-1 == file.write(m_reply->readAll())) {
		errorReset(-1);
	}
}

// 下载完成;
void AppDownLoadThread::onFinished()
{
	if (!m_reply) return;
	QVariant statusCode = m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	int nStatusCode	=	 statusCode.toInt();
	if (nStatusCode == 302 || nStatusCode == 301)
	{
		m_strUrl = m_reply->rawHeader("Location");
		loop->quit();
		if (this->isRunning() && this->wait(500))
		{
		}
		this->start();
	}
	else
	{
		QString realName;
		if ((m_reply->error() == QNetworkReply::NoError || nStatusCode == 200) && m_APPDOWNLOADETYPE == mapp_DOWNLOADING)
		{
			//保存app下载更新情况
			m_pData.m_statusAppButton = mapp_FINISH;
			AppCenterDatabase::instance()->updateApp(m_pData);

			m_APPDOWNLOADETYPE = mapp_FINISH;

			//保存app下载更新情况
			m_pData.m_statusAppButton = mapp_FINISH;
			AppCenterDatabase::instance()->updateApp(m_pData);

			// 重命名临时文件;
			QFileInfo fileInfo(m_fileName);
			if (fileInfo.exists())
			{
				file.close();
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
			loop->quit();

		}
		else
		{
			//会产生两次错误   忽略此次
			// 有错误输出错误;
			//errorReset(nStatusCode);
			return;
		}
	}	
}

// 下载过程中出现错误，关闭下载，并上报错误，这里未上报错误类型，可自己定义进行上报;
void AppDownLoadThread::onError(QNetworkReply::NetworkError code)
{
	QString strError = m_reply->errorString();
	QVariant statusCode = m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	errorReset(statusCode.toInt());
}

void AppDownLoadThread::errorReset(int errorInt)
{
	if (m_reply->error() == QNetworkReply::TimeoutError || m_reply->error() == QNetworkReply::NetworkSessionFailedError || m_reply->error() == QNetworkReply::RemoteHostClosedError)
	{
		//保存app下载更新情况
		m_pData.m_statusAppButton = mapp_PAUSE;
		AppCenterDatabase::instance()->updateApp(m_pData);
		m_APPDOWNLOADETYPE = mapp_PAUSE;
		emit signalStatusChanged(mapp_TIMEOUTERROR);
	}
	else
	{
		//保存app下载更新情况
		m_pData.m_statusAppButton = mapp_ERROR;
		AppCenterDatabase::instance()->updateApp(m_pData);
		m_APPDOWNLOADETYPE = mapp_ERROR;
		emit signalStatusChanged(mapp_ERROR);
		reset();
	}
	if (m_reply && loop)
	{
		disconnect(m_reply);
		m_reply->deleteLater();
		m_reply = NULL;
		loop->quit();
	}
}

void AppDownLoadThread::continueDownload()
{
	if (m_APPDOWNLOADETYPE == mapp_DOWNLOADING || m_APPDOWNLOADETYPE == mapp_FINISH)
	{
		return;
	}

	if (m_downloadFilish)
	{
		m_downloadFilish = false;

		//保存app下载更新情况
		m_pData.m_statusAppButton = mapp_FINISH;
		AppCenterDatabase::instance()->updateApp(m_pData);

		m_APPDOWNLOADETYPE = mapp_FINISH;
		this->start();
		return;
	}

	//if (m_bytesCurrentReceived + m_bytesReceived == m_bytesTotal && m_bytesTotal != 0)
	//{
	//	m_APPDOWNLOADETYPE = mapp_FINISH;
	//	this->start();
	//	return;
	//}

	// 如果当前下载的字节数为0那么说明未下载过或者重新下载
	// 则需要检测本地是否存在之前下载的临时文件，如果有则删除
	//if (m_bytesCurrentReceived <= 0)
	//{
	//	removeFile(m_fileName);
	//}else
	m_bytesCurrentReceived = file.size();
	this->start();
}

void AppDownLoadThread::reDownload()
{
	if (m_APPDOWNLOADETYPE == mapp_DOWNLOADING || m_APPDOWNLOADETYPE == mapp_FINISH)
	{
		return;
	}
	reset();

	//保存app下载更新情况
	m_pData.m_statusAppButton = mapp_DOWNLOADING;
	AppCenterDatabase::instance()->updateApp(m_pData);
	m_APPDOWNLOADETYPE = mapp_DOWNLOADING;
	this->start();
}

// 关闭下载，重置参数，并删除下载的临时文件;
void AppDownLoadThread::closeDownload()
{
	if (m_reply && loop)
	{
		if (m_APPDOWNLOADETYPE == mapp_FINISH)
		{
			emit signalStatusChanged(mapp_CLOSE);
			return;
		}
		m_reply->abort();
		disconnect(m_reply);
		m_reply->deleteLater();
		m_reply = NULL;
		removeFile(m_fileName);
		loop->quit();
	}
	//保存app下载更新情况
	m_pData.m_statusAppButton = mapp_CLOSE;
	AppCenterDatabase::instance()->updateApp(m_pData);
	m_APPDOWNLOADETYPE = mapp_CLOSE;
	emit signalStatusChanged(mapp_CLOSE);
	//通知右侧分类刷新
	if (!m_pData.m_bAppIsInstall)
		emit closeDowloadSignal(m_pData.mStrAppCateId);
	//usleep(200);	
}


// 暂停下载按钮被按下,暂停当前下载;
void AppDownLoadThread::stopDownload()
{
	emit signalStatusChanged(mapp_PAUSE);
	m_APPDOWNLOADETYPE = mapp_PAUSE;


	// 这里m_isStop变量为了保护多次点击暂停下载按钮，导致m_bytesCurrentReceived 被不停累加;
	//记录当前已经下载字节数；
	if (m_reply != NULL)
	{
		if (m_APPDOWNLOADETYPE == mapp_FINISH){
			//保存app下载更新情况
			m_pData.m_statusAppButton = mapp_FINISH;
			AppCenterDatabase::instance()->updateApp(m_pData);
			return;
		}
		//保存app下载更新情况
		m_pData.m_statusAppButton = mapp_PAUSE;
		AppCenterDatabase::instance()->updateApp(m_pData);
		disconnect(m_reply, SIGNAL(finished()), this, SLOT(onFinished()));
		disconnect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
		m_reply->abort();
		usleep(5);
		disconnect(m_reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
		disconnect(m_reply, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
		m_reply->deleteLater();
		m_reply = NULL;
		m_bytesTotal = 0;
		m_bytesCurrentReceived += m_bytesReceived;
		m_bytesReceived = 0;
		loop->quit();
	}
}

// 重置参数;
void AppDownLoadThread::reset()
{
	if (!m_fileName.contains(DOWNLOAD_FILE_SUFFIX))
		m_fileName.append(DOWNLOAD_FILE_SUFFIX);
	file.close();
	removeFile(m_fileName);
	file.setFileName(m_fileName);
	m_bytesTotal = 0;
	m_bytesCurrentReceived = 0;
	m_bytesReceived = 0;
	
}

// 删除文件;
void AppDownLoadThread::removeFile(QString fileName)
{
	// 删除已下载的临时文件;
	file.close();
	QFileInfo fileInfo(fileName);
	if (fileInfo.exists())
	{
		QFile::remove(fileName);
	}
}

APPDOWNLOADETYPE AppDownLoadThread::isHaveDowanload(QString appName, QString appId)
{
	if (m_pData.m_strAppId == appId)//m_pData.m_strAppName == appName && 
		return m_APPDOWNLOADETYPE;
	else
		return mapp_CLOSE;
}

APPDOWNLOADETYPE AppDownLoadThread::getType()
{
	return m_APPDOWNLOADETYPE;
}

qint64 AppDownLoadThread::getProcese(int totalReceived)
{
	if (totalReceived == 0)
	{
		return  m_bytesTotal;
	}
	else
		return m_bytesReceived + m_bytesCurrentReceived;
}



APPDOWNLOADETYPE AppDownLoadThread::downloadedSuccessfully()
{
	return m_APPDOWNLOADETYPE;
}


QString AppDownLoadThread::getDownloadUrl()
{
	return m_strUrl;
}

