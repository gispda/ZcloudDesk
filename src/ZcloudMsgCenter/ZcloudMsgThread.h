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
	//!拉取消息
	int pullMsg(QString strUid,QString strToken,QString strCompId);

	//!拉取活动
	void pullActivity(QString strUid, QString strToken, QString strCompId);

	//!获取消息
	bool winHttpGetMessage(QString strUid,QString strToken, QString& strRet);

	//!获取最新活动
	bool winHttpGetActivity(QString strUid, QString strToken, QString& strRet);

	//!QJsonObject转QString
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
