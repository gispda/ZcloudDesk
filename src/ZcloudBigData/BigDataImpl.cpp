#include "BigDataImpl.h"
#include "ZcloudCommon.h"
#include "WinSock.h"
#include "inaddr.h"
#include <QDateTime>
#include <QNetworkProxyQuery>
#include <QApplication>
#include <QSettings>
#pragma comment(lib,"ws2_32.lib")

BigDataImpl *BigDataImpl::m_pInstance = NULL;

ZcloudBigDataInterface *ZcloudBigDataInterface::GetInstance()
{
	WSADATA data;
	WSAStartup(MAKEWORD(1, 1), &data);
	return BigDataImpl::GetInstance();
}

BigDataImpl::~BigDataImpl()
{
	if (NULL != m_pTimerHeart)
	{
		m_pTimerHeart->deleteLater();
		m_pTimerHeart = NULL;
	}
	if (NULL != m_pTimerClient)
	{
		m_pTimerClient->deleteLater();
		m_pTimerClient = NULL;
	}
	WSACleanup();
}

BigDataImpl * BigDataImpl::GetInstance()
{
	if (m_pInstance == NULL)
	{
		QString strIniPath = QApplication::applicationDirPath();
		QSettings settings(strIniPath + "/config.ini", QSettings::IniFormat);
		m_pInstance = new BigDataImpl();
		m_pInstance->tcpClientIp	= settings.value("BD/hostName").toString();
		m_pInstance->heartPort		= settings.value("BD/heartbeatPort").toInt();
		m_pInstance->actionPort		= settings.value("BD/collectionPort").toInt();

		QByteArray url = m_pInstance->tcpClientIp.toLatin1();
		struct hostent *h = gethostbyname(url);
		if (h != NULL)
		{
			struct in_addr *in = (in_addr *)h->h_addr;
			char *ch = inet_ntoa(*in);
			m_pInstance->strIp = QString(QLatin1String(ch));
		}
		else
		{
			m_pInstance->strIp = m_pInstance->tcpClientIp;
		}

		m_pInstance->setReleaseThread();
		m_pInstance->setBuffSize();
		m_pInstance->initialized = false;
		m_pInstance->initData("-1", "-1", "-1", "-1", "-1", "-1");
		m_pInstance->startThread();	
	}
	return m_pInstance;
}

void BigDataImpl::initData(QString strUserId, QString strCompanyId, QString strHzsId, QString strProvinceId, QString strCityId, QString strAreaId, QString strFlag)
{
	QMutexLocker	locker(&m_boolMutex);
	if (strCompanyId.isEmpty())
	{
		strCompanyId = "-1";
	}
	QString strMac = ZcloudComFun::getHostMacAddress();
	QString strVer = ZcloudComFun::getFileVertion(QApplication::applicationFilePath());
	m_colloctBytes.clear();
	m_colloctBytes.append("ACTION#")
		.append(strUserId)
		.append(",").append(strCompanyId)
		.append(",").append(strMac)
		.append(",").append(strVer);

	if (strCityId	==	"")
	{
		strCityId = "-1";
	}
	if (strAreaId	== "")
	{
		strAreaId = "-1";
	}
	m_heartBytes.clear();
	m_heartBytes.append("HEART5")
		.append(",").append(strHzsId)					//合作商id
		.append("_").append("-1")						//用户类型 (未知-1，企业账户1，企业子账户2)
		.append("_").append(strProvinceId)				//省id
		.append("_").append(strCityId)					//市id
		.append("_").append(strAreaId)					//区id
		.append("_").append("-1")						//行业一级Id
		.append("_").append("-1")						//行业一级Id
		.append(",").append(strUserId)
		.append("_").append(strMac)
		.append("_").append(strVer)
		.append(",").append(strFlag)
		.append("\r\n");
	initialized = true;
}

void BigDataImpl::destory()
{
	delete this;
}

void BigDataImpl::produceData(QString strMsgClsId, QString strOperationId, QString strOperandId, QString strNotes, bool isImmediately)
{
	if (!m_mutex.tryLock())
	{
		return;
	}
	if (m_BdQueue.size() == m_nBufferSize)
	{
		m_mutex.unlock();
		return;
	}
	QString sendData;
	sendData.append(m_colloctBytes)
		.append(",").append(QString::number(QDateTime::currentDateTime().toTime_t()))
		.append(",").append(strMsgClsId)
		.append(",").append(strOperationId)
		.append(",").append(strOperandId)
		.append(",").append(strNotes)
		.append("\r\n");

	if (!isImmediately)
	{
		m_BdQueue.append(sendData);
	}
	else
	{
		QTcpSocket *act_client = new QTcpSocket();
		act_client->connectToHost(QHostAddress(strIp), actionPort);
		if (act_client->waitForConnected(1000))
		{
			QByteArray writeData;
			writeData.append(sendData);
			act_client->write(writeData);
			act_client->waitForBytesWritten(1000);
		}
		act_client->deleteLater();
		act_client = NULL;
	}
	m_mutex.unlock();
}

void BigDataImpl::run()
{
	m_pTimerHeart = new QTimer;
	connect(m_pTimerHeart, SIGNAL(timeout()), this, SLOT(onReportHeartBeat()));
	m_pTimerHeart->start(60 * 1000);

	m_pTimerClient = new QTimer;
	connect(m_pTimerClient, SIGNAL(timeout()), this, SLOT(onReportCollection()));
	m_pTimerClient->start(1000);

	exec();
}

void BigDataImpl::startThread()
{
	this->start();
}

void BigDataImpl::setBuffSize(int nSize /*= 100*/)
{
	m_nBufferSize = nSize;
}

void BigDataImpl::reportCollectionData(QTcpSocket *cli)
{
	QByteArray writeData;
	QString strSend;
	cli->connectToHost(QHostAddress(strIp), actionPort);
	if (cli->waitForConnected(1000))
	{
		while (!m_SendQueue.isEmpty()) {
			strSend = m_SendQueue.dequeue();
			writeData.clear();
			writeData.append(strSend);
			cli->write(writeData);
			cli->waitForBytesWritten(1000);
			usleep(100);
		}
		cli->disconnectFromHost();
	}
}

void BigDataImpl::stopImmediately()
{
	QMutexLocker	locker(&m_boolMutex);
	this->m_bBreak = false;
}

void BigDataImpl::waitForStop()
{
	this->wait();
}

void BigDataImpl::setReleaseThread()
{
	connect(this, &QThread::finished
		, this, &QObject::deleteLater);//线程结束后调用deleteLater来销毁分配的内存
}

void BigDataImpl::stopThread()
{
	stopImmediately();
	waitForStop();
	destory();
}
void BigDataImpl::reportHeartbeatData(QTcpSocket *cli)
{
	if (initialized)
	{
		QMutexLocker	locker(&m_boolMutex);
		cli->connectToHost(QHostAddress(strIp), heartPort);
		if (cli->waitForConnected(1000))
		{
			cli->write(m_heartBytes);
			cli->waitForBytesWritten(1000);
			cli->disconnectFromHost();
		}
	}
}

void BigDataImpl::onReportHeartBeat()
{
	QTcpSocket *heart_client = new QTcpSocket();
	reportHeartbeatData(heart_client);
}

void BigDataImpl::onReportCollection()
{
	QTcpSocket *act_client = new QTcpSocket();
	//!消费者上报大数据采集信息
	m_mutex.lock();
	//如果上一轮未上报成功，清空上一轮上报数据
	if (!m_SendQueue.isEmpty())
		m_SendQueue.clear();
	//将数据存储队列信息移入待上报队列
	while (!m_BdQueue.isEmpty())
	{
		QString str = m_BdQueue.dequeue();
		m_SendQueue.push_back(str);
	}
	m_mutex.unlock();
	if (!m_SendQueue.isEmpty())
		reportCollectionData(act_client);
}
