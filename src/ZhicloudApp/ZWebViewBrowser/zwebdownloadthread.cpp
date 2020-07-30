#include "zwebdownloadthread.h"
#include "zwebviewbrowser.h"

ZWebDownloadThread::ZWebDownloadThread(QObject *parent)
	: QThread(parent)
{
}


ZWebDownloadThread::~ZWebDownloadThread()
{

}


void ZWebDownloadThread::run()
{
	//    if(m_Url.toLower().startsWith("https"))//https请求，需ssl支持(下载openssl拷贝libeay32.dll和ssleay32.dll文件至Qt bin目录或程序运行目录)
	//    {
	//        qDebug() << "https";
	//        QSslConfiguration sslConfig;
	//        sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
	//        sslConfig.setProtocol(QSsl::TlsV1_1);
	//        netRequest.setSslConfiguration(sslConfig);
	//    }

	loop = new QEventLoop();
	loop->moveToThread(this);

	QNetworkProxyQuery proxyQuery(QUrl::fromUserInput("https://www.baidu.com"));
	QList<QNetworkProxy> proxyList = QNetworkProxyFactory::systemProxyForQuery(proxyQuery);
	if (proxyList.count() > 0)
	{
		ZWebViewBrowser::networkAccessManager()->setProxy(proxyList.at(0));
	}
	m_pNetworkReply = ZWebViewBrowser::networkAccessManager()->get(QNetworkRequest(m_request)); //发起get请求
	connect(m_pNetworkReply, SIGNAL(downloadProgress(qint64, qint64)), this, SIGNAL(threadReadProgress(qint64, qint64)));//更新进度条
	connect(m_pNetworkReply, SIGNAL(finished()), this, SLOT(requestFinished())); //请求完成信号
	connect(m_pNetworkReply, SIGNAL(error(QNetworkReply::NetworkError)),
		this, SIGNAL(error_signal(QNetworkReply::NetworkError)));
	//connect(m_pNetworkReply,SIGNAL(finished()), loop, SLOT(quit()));
	connect(m_pNetworkReply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()), Qt::DirectConnection); //有可用数据时
	loop->exec();
}

void ZWebDownloadThread::setValue(QNetworkRequest request, QString fileName)
{
	m_request = request;
	m_file.setFileName(fileName);
}


//下载完成信号
void ZWebDownloadThread::requestFinished()
{
	int nHttpCode = m_pNetworkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();//http返回码

	m_file.flush();
	m_file.close();
	QVariant statusCode = m_pNetworkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (m_pNetworkReply->error() == QNetworkReply::NoError)
	{
		m_pNetworkReply->deleteLater();
		m_pNetworkReply = NULL;
		emit finished_signal();
	}
	else
	{
		errtoText(0, QString::fromLocal8Bit("下载错误:%1").arg(statusCode.toString()));
	}
	loop->quit();
}

void ZWebDownloadThread::httpReadyRead() //下载
{
	if (m_file.fileName().isEmpty())
		return;

	if (!m_file.isOpen()) {
		// in case someone else has already put a file there
		if (!m_file.open(QIODevice::WriteOnly)) {
			errtoText(0,tr("Error opening save file: %1")
				.arg(m_file.errorString()));
			return;
		}
	}
	if (-1 == m_file.write(m_pNetworkReply->readAll())) {
		errtoText(0, tr("Error saving: %1")
			.arg(m_file.errorString()));
	}
}

void ZWebDownloadThread::errtoText(int number, QString text)
{
	suspendDownload();
	removeFile();
	emit errotTxetSignal(number, text);
}

void ZWebDownloadThread::suspendDownload()
{
	if (m_pNetworkReply)
	{
		disconnect(m_pNetworkReply, SIGNAL(finished()), this, SLOT(requestFinished())); //请求完成信号
		disconnect(m_pNetworkReply, SIGNAL(error(QNetworkReply::NetworkError)),
			this, SIGNAL(error_signal(QNetworkReply::NetworkError)));
		m_pNetworkReply->abort();
		disconnect(m_pNetworkReply, SIGNAL(readyRead()), this, SLOT(httpReadyRead())); //有可用数据时
		disconnect(m_pNetworkReply, SIGNAL(downloadProgress(qint64, qint64)), this, SIGNAL(threadReadProgress(qint64, qint64)));//更新进度条
		m_pNetworkReply->deleteLater();
		m_pNetworkReply = NULL;
		loop->quit();
	}
}


// 删除文件;
void ZWebDownloadThread::removeFile()
{
	m_file.close();
	QFileInfo fileInfo(m_file);
	if (fileInfo.exists())
	{
		QFile::remove(fileInfo.filePath() + "/" + fileInfo.fileName());
	}
}