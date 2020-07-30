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

// �����Ƿ�֧�ֶϵ�����;
void DownLoadThread::setDownInto(bool isSupportBreakPoint)
{
	m_isSupportBreakPoint = isSupportBreakPoint;
}

QString DownLoadThread::getDownloadUrl()
{
	return m_url.toString();
}

// ��ʼ�����ļ�;
void DownLoadThread::downloadFile(QString url, QString fileName,bool appMsg)
{
	// ��ֹ��ε����ʼ���ذ�ť�����ж�����أ�ֻ����ֹͣ��־����Ϊtrueʱ�Ž�������;
	if (m_isStop)
	{
		m_isStop = false;
		m_url = QUrl::fromUserInput(url);
		// ��url �л�ȡ�ļ����������Ƕ���Ч;
		QFileInfo fileInfo(m_url.path());
		QString appFileName = fileInfo.fileName();
		if (appFileName.isEmpty())
			appFileName = "invoice.exe";


		// ����ǰ�ļ�������Ϊ��ʱ�ļ������������ʱ�޸Ļ���;  1 �ų�Ӧ�����ĵ� �ص�����
		m_fileName = fileName.append("/downloadApp/") + "1" +appFileName + DOWNLOAD_FILE_SUFFIX;
		QDir fileD(fileName);
		if (!fileD.exists())
		{
			fileD.mkpath(fileName);
		}
		// �����ǰ���ص��ֽ���Ϊ0��ô˵��δ���ع�������������
		// ����Ҫ��Ȿ���Ƿ����֮ǰ���ص���ʱ�ļ����������ɾ��

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

// ���ؽ�����Ϣ;
void DownLoadThread::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
	if (!m_isStop)
	{
		m_bytesReceived = bytesReceived;
		m_bytesTotal = bytesTotal;
		// �������ؽ���;(���� m_bytesCurrentReceived ��Ϊ�˶ϵ�����ʱ֮ǰ���ص��ֽ�)
		emit signalDownloadProcess(m_bytesReceived + m_bytesCurrentReceived, m_bytesTotal + m_bytesCurrentReceived);
	}	
}

// ��ȡ�������ݣ����浽�ļ���;
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

// �������;
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
			// ��������ʱ�ļ�;
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
			this->start();  // ���ڵȴ���װ���
		}
		else
		{
			//// �д����������;
			//QString errorStr;
			//if (m_reply->error() == QNetworkReply::TimeoutError || m_reply->error() == QNetworkReply::NetworkSessionFailedError || m_reply->error() == QNetworkReply::RemoteHostClosedError)
			//{
			//	errorStr = QString::fromLocal8Bit("���糬ʱ��������������");
			//}
			//else
			//{
			//	reset();
			//	errorStr = QString::fromLocal8Bit("���ش�������������");
			//	removeFile(m_fileName);
			//}

			//emit signalDownloadError(errorStr);
			m_DOWNLOADETYPE = m_ERROR;
			return;
		}
	}
}

// ���ع����г��ִ��󣬹ر����أ����ϱ���������δ�ϱ��������ͣ����Լ���������ϱ�;
void DownLoadThread::onError(QNetworkReply::NetworkError code)
{
	disconnect(m_reply);
	QString errorStr;
	if (m_reply->error() == QNetworkReply::TimeoutError || m_reply->error() == QNetworkReply::NetworkSessionFailedError || m_reply->error() == QNetworkReply::RemoteHostClosedError)
	{
		errorStr = QString::fromLocal8Bit("���糬ʱ��������������");
	}
	else
	{
		errorStr = QString::fromLocal8Bit("���ش�������������");
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

// ֹͣ���ع���; ���ڹر�����
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

//// ֹͣ���ع���;������ͣ����
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
//// ��ͣ���ذ�ť������,��ͣ��ǰ����;
//void DownLoadThread::stopDownload(bool appMsg)
//{
//	// ����m_isStop����Ϊ�˱�����ε����ͣ���ذ�ť������m_bytesCurrentReceived ����ͣ�ۼ�;
//	if (!m_isStop)
//	{
//		//��¼��ǰ�Ѿ������ֽ�����
//		m_bytesCurrentReceived += m_bytesReceived;
//		stopWorkDoanload();
//		m_DOWNLOADETYPE = m_PAUSE;
//		m_isStop = true;
//	}
//}

// ���ò���;
void DownLoadThread::reset()
{
	m_bytesCurrentReceived = 0;
	m_bytesReceived = 0;
	m_bytesTotal = 0;
}

// ɾ���ļ�;
void DownLoadThread::removeFile(QString fileName)
{
	// ɾ�������ص���ʱ�ļ�;
	QFile::remove(fileName);
}

// �ر����أ����ò�������ɾ�����ص���ʱ�ļ�;
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

	// ���֧�ֶϵ�����������������ͷ��Ϣ;
	if (m_isSupportBreakPoint)
	{
		QString strRange = QString("bytes=%1-").arg(m_bytesCurrentReceived);
		request.setRawHeader("Range", strRange.toLatin1());
	}

	//------------------------ע���������ô���---------------------------------//

	m_reply = m_networkManager->get(request);

	connect(m_reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
	connect(m_reply, SIGNAL(readyRead()), this, SLOT(onReadyRead()), Qt::DirectConnection);
	connect(m_reply, SIGNAL(finished()), this, SLOT(onFinished()));
	connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
}
