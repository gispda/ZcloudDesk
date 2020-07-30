#include "bigDataInterface.h"
#include <QString>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include "WinSock.h"
#include "inaddr.h"
#include "qt_windows.h"
#pragma comment(lib,"ws2_32.lib")

QString BigDataHeartbeat::getHostIpAddress()
{
	QString strIpAddress;
	QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
	// ��ȡ��һ����������IPv4��ַ  
	int nListSize = ipAddressesList.size();
	for (int i = 0; i < nListSize; ++i)
	{
		if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
			ipAddressesList.at(i).toIPv4Address()) {
			strIpAddress = ipAddressesList.at(i).toString();
			break;
		}
	}
	// ���û���ҵ������Ա���IP��ַΪIP  
	if (strIpAddress.isEmpty())
		strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
	return strIpAddress;
}

QString BigDataHeartbeat::getHostMacAddress()
{
	QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// ��ȡ��������ӿ��б�  
	int nCnt = nets.count();
	QString strMacAddr = "";
	for (int i = 0; i < nCnt; i++)
	{
		// ���������ӿڱ�������������в��Ҳ��ǻػ���ַ�������������Ҫ�ҵ�Mac��ַ  
		if (nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
		{
			strMacAddr = nets[i].hardwareAddress();
			break;
		}
	}
	return strMacAddr;
}


//��ʼ��
static void initialise(void)
{
#ifdef _WIN32
	WSADATA data;
	if (WSAStartup(MAKEWORD(1, 1), &data) != 0)
	{
		fputs("Could not initialise Winsock.\n", stderr);
	}
#endif
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
BigDataHeartbeat::BigDataHeartbeat( QObject *parent)
	: m_postStr(""),
	m_strIp("bds.zhicloud.com"),
	//m_strIp("172.18.10.66"),
	m_tcpClientPort(8987),
	QThread(parent)
{
	initialise();
	QByteArray url = m_strIp.toLatin1();
	struct hostent *h = gethostbyname(url);
	if (h != NULL)
	{
		struct in_addr *in = (in_addr *)h->h_addr;
		char *ch = inet_ntoa(*in);
		m_strIp = QString(QLatin1String(ch));
	}
	else
	{
		switch (h_errno)
		{
		case HOST_NOT_FOUND:
			qDebug("The host was not found.\n", stderr);
			break;
		case NO_ADDRESS:
			qDebug("The name is valid but it has no address.\n", stderr);
			break;
		case NO_RECOVERY:
			qDebug("A non-recoverable name server error occurred.\n", stderr);
			break;
		case TRY_AGAIN:
			qDebug("The name server is temporarily unavailable.", stderr);
			break;
		}
	}
}

void BigDataHeartbeat::setFileVer(QString fileVertion)
{
	herderData.clear();						
	//�û�id	Ϊ��
	herderData.append("ACTION#")
		.append(QString(",") + QString(",") + getHostMacAddress() + "," + fileVertion);					
}

void BigDataHeartbeat::setValue(QString postStr, bool isStart)
{
	//��������еȴ� 20��
	if (this->isRunning())
	{
		wait(1000 * 20);
			//return;
	}
	m_postStr = postStr;
	isStart ? this->start() : this->run();
}

void BigDataHeartbeat::run()
{
	QString timeStr = QString::number(QDateTime::currentDateTime().toTime_t());//ʱ��
	QString writeStr = herderData + "," + timeStr + QString(",") + m_postStr + "\r\n";

	QTcpSocket heartbeatTcp;


	QNetworkProxyQuery proxyQuery(QUrl("https://www.baidu.com"));
	QList<QNetworkProxy> proxyList = QNetworkProxyFactory::systemProxyForQuery(proxyQuery);
	if (proxyList.count() > 0)
	{
		heartbeatTcp.setProxy(proxyList.at(0));
	}

	heartbeatTcp.connectToHost(QHostAddress(m_strIp), m_tcpClientPort);
	if (heartbeatTcp.waitForConnected(1000))
	{
		heartbeatTcp.write(writeStr.toLocal8Bit());
		heartbeatTcp.waitForBytesWritten(1000);
		//if (heartbeatTcp.waitForReadyRead(1000))
		//	qDebug() << heartbeatTcp.readAll() << writeStr;
		heartbeatTcp.disconnectFromHost();
	}
}


