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

BigDataImpl::BigDataImpl(QObject *parent)
	:QThread(parent)
{
	WSADATA data;
	WSAStartup(MAKEWORD(1, 1), &data);
}

BigDataImpl::~BigDataImpl()
{
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
		m_pInstance = new BigDataImpl();
		m_pInstance->tcpClientIp	= "172.18.10.58";
		m_pInstance->actionPort		= 8987;

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
		m_pInstance->initData();
		m_pInstance->startThread();	
	}
	return m_pInstance;
}

void BigDataImpl::initData()
{
	QMutexLocker	locker(&m_boolMutex);
	m_colloctBytes.clear();
	m_colloctBytes.append("ACTION#")
		.append("-1")
		.append(",").append("-1")
		.append(",").append(getHostMacAddress())
		.append(",").append("-1");
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
		, this, &QObject::deleteLater);//�߳̽��������deleteLater�����ٷ�����ڴ�
}

void BigDataImpl::stopThread()
{
	stopImmediately();
	waitForStop();
	destory();
}
void BigDataImpl::onReportCollection()
{
	QTcpSocket *act_client = new QTcpSocket();
	//!�������ϱ������ݲɼ���Ϣ
	m_mutex.lock();
	//�����һ��δ�ϱ��ɹ��������һ���ϱ�����
	if (!m_SendQueue.isEmpty())
		m_SendQueue.clear();
	//�����ݴ洢������Ϣ������ϱ�����
	while (!m_BdQueue.isEmpty())
	{
		QString str = m_BdQueue.dequeue();
		m_SendQueue.push_back(str);
	}
	m_mutex.unlock();
	if (!m_SendQueue.isEmpty())
		reportCollectionData(act_client);
}

QString BigDataImpl::getHostMacAddress()
{
	QString strMacAddr = "";
	for each (QNetworkInterface net in QNetworkInterface::allInterfaces()) // ��ȡ��������ӿ��б�  
	{
		// ���������ӿڱ�������������в��Ҳ��ǻػ���ַ�������������Ҫ�ҵ�Mac��ַ  
		if (net.flags().testFlag(QNetworkInterface::IsUp) && net.flags().testFlag(QNetworkInterface::IsRunning) && !net.flags().testFlag(QNetworkInterface::IsLoopBack))
		{
			strMacAddr = net.hardwareAddress();
			break;
		}
	}
	return strMacAddr;
}
