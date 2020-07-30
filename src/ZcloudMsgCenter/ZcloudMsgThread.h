#ifndef ZCLOUDMSGTHREAD_H
#define ZCLOUDMSGTHREAD_H

#include <QThread>
#include <QMutex>
#include "MsgInfoDenfine.h"
class ZcloudMsgThread : public QThread
{
	Q_OBJECT

public:
	ZcloudMsgThread(QObject *parent=0);
	~ZcloudMsgThread();

	void stopImmediately();
	void setUserData(QString strUId,QString strToken,QString strCompId);
signals:
	void sendMsgInfo(QStringList strParam, int nCount);
	void sendActivityInfo(QStringList strParam);
	void checkTokenFailed(int);
protected:
	void run();
private:
	//!��ȡ��Ϣ
	int pullMsg(QString strUid,QString strToken,QString strCompId);

	//!��ȡ�
	void pullActivity(QString strUid, QString strToken, QString strCompId);

	//!��ȡ��Ϣ
	bool winHttpGetMessage(QString strUid,QString strToken, QString& strRet);

	//!��ȡ���»
	bool winHttpGetActivity(QString strUid, QString strToken, QString& strRet);

	//!QJsonObjectתQString
	QString getStringFromJsonObject(const QJsonObject& jsonObject);
private:
	bool		m_bBreak;
	QMutex		m_mutex;
	QString     m_strUid;
	QString		m_strToken;
	QString		m_strCompId;
	QString     m_strActivityId;
};

#endif // ZCLOUDMSGTHREAD_H
