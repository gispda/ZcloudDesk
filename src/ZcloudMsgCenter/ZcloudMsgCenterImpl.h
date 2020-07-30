#ifndef ZCLOUDMSGCENTERIMPL_H
#define ZCLOUDMSGCENTERIMPL_H
#include "ZcloudMsgCenter.h"
#include "MsgCenterWidget.h"
#include "ZcloudMsgThread.h"
#include <QVector>
#include <QProcess>
class ZcloudMsgCenterImpl : public ZcloudMsgCenter
{
	Q_OBJECT
public:
	ZcloudMsgCenterImpl();
	 ~ZcloudMsgCenterImpl();

private slots:
	void reviceMsgInfo(QStringList strParamList	, int nCount);
	void reviceActivityInfo(QStringList strParamList);
private:
	//!���ٶ���
	virtual void destroy();

	//!����Ϣ����
	virtual void openMsgCenter(int nUnread);

	//!ˢ����Ϣ����
	virtual void refreshMsgCenter(int nUnread);

	//!����鿴�����ָ����Ϣ
	virtual void openAssignMsgCenter(int nUnread, QString strMsgId);

	//!��ʼ��Ϣ�߳�
	virtual void startMsgThread(QString strUid, QString strToken,QString strCompId);

	//!����������Ϣ�Ի���
	virtual void closeAllMsgWidget();

	//!�����û�����
	virtual void setUserData(QString strUid, QString strToken, QString strCompId, bool bSetThread = true);

	//!��Ϣ���������Ѷ�
	virtual void reportMsgInfo(QString strUid, QString strMsgId, QString strCompId);

	//!��Ϣ�Ի����Ƿ���ʾ
	virtual bool msgCenterShow();

	//!����δ������
	virtual void reduceUnreadNum();
private:

	//!ֹͣ��Ϣ��ѯ�߳�
	void stopMsgThread();

	//!ֹͣ������Ϣ��������
	void stopPopupProcess();
	QProcess*			m_processActivity = NULL;
	MsgCenterWidget*	m_pMsgCenterWidget = NULL;
	ZcloudMsgThread*	m_pZcloudMsgThread = NULL;
};

#endif // ZCLOUDMSGCENTERIMPL_H
