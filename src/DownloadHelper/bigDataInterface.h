
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QNetworkInterface>
#include <QObject>
#include <QDateTime>
#include <QThread>
#include <QNetworkProxyQuery>
 
class BigDataHeartbeat : public QThread
{
	Q_OBJECT
public:
	BigDataHeartbeat( QObject *parent = 0);
	void setValue(QString postStr,bool isStart = true);
	void setFileVer(QString fileVertion);
	void run();
protected:
	
private:
	QString m_postStr;
	QString m_strIp;
	QString herderData;
	int m_tcpClientPort;

	QString getHostIpAddress();
	QString getHostMacAddress();

};

