#pragma once
#include <QThread>
#include <QQueue>
#include <QWaitCondition>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QNetworkInterface>
#include "ZcloudBigData.h"
#include <QTimer>
class BigDataImpl:public QThread,public ZcloudBigDataInterface
{
	Q_OBJECT
public:
	~BigDataImpl();
	static BigDataImpl *GetInstance();

	virtual void produceData(QString strMsgClsId, QString strOperationId, QString strOperandId, QString strNotes = "", bool isImmediately = false);

	virtual void stopThread();

	virtual void initData(QString strUserId, QString strCompanyId, QString strHzsId, QString strProvinceId, QString strCityId, QString strAreaId, QString strFlag="1");
public slots:
	//!心跳timer
	void onReportHeartBeat();
	//!行为上报timer
	void onReportCollection();
protected:
	void run();
private:
	 void destory();

	 void setBuffSize(int nSize = 100);

	 void stopImmediately();

	 void waitForStop();

	 void setReleaseThread();

	 //!开始线程
	 void startThread();

	 //!上报数据到大数据服务器
	 void reportCollectionData(QTcpSocket *cli);

	 //!上报心跳
	 void reportHeartbeatData(QTcpSocket *cli);

	explicit BigDataImpl(QObject *parent = 0)
		:QThread(parent){};

	static BigDataImpl *m_pInstance;
	bool			initialized;
	QString			tcpClientIp;
	QString			strIp;
	int				heartPort;
	int				actionPort;
	int				m_nBufferSize;
	QMutex			m_mutex;
	QMutex			m_boolMutex;
	QQueue<QString> m_BdQueue;
	QQueue<QString> m_SendQueue;
	bool			m_bBreak;
	QByteArray		m_heartBytes;
	QByteArray		m_colloctBytes;
	QTimer*			m_pTimerHeart;
	QTimer*			m_pTimerClient;
};

