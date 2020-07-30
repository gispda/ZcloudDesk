#pragma once
#include <QThread>
#include <QQueue>
#include <QWaitCondition>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QNetworkInterface>
#include <QTimer>
class BigDataImpl:public QThread
{
	Q_OBJECT
public:
	~BigDataImpl();
	static BigDataImpl *GetInstance();

	virtual void produceData(QString strMsgClsId, QString strOperationId, QString strOperandId, QString strNotes = "", bool isImmediately = false);

	virtual void stopThread();

	virtual void initData();
public slots:
	//!��Ϊ�ϱ�timer
	void onReportCollection();
protected:
	void run();
private:
	 void destory();

	 void setBuffSize(int nSize = 100);

	 void stopImmediately();

	 void waitForStop();

	 void setReleaseThread();

	 //!��ʼ�߳�
	 void startThread();

	 //!�ϱ����ݵ������ݷ�����
	 void reportCollectionData(QTcpSocket *cli);

	 QString getHostMacAddress();

	explicit BigDataImpl(QObject *parent = 0);

	static BigDataImpl *m_pInstance;
	bool			initialized;
	QString			tcpClientIp;
	QString			strIp;
	int				actionPort;
	int				m_nBufferSize;
	QMutex			m_mutex;
	QMutex			m_boolMutex;
	QQueue<QString> m_BdQueue;
	QQueue<QString> m_SendQueue;
	bool			m_bBreak;
	QByteArray		m_colloctBytes;
	QTimer*			m_pTimerClient;
};

