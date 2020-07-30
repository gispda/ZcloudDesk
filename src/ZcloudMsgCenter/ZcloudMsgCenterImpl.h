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
	//!销毁对象
	virtual void destroy();

	//!打开消息中心
	virtual void openMsgCenter(int nUnread);

	//!刷新消息中心
	virtual void refreshMsgCenter(int nUnread);

	//!点击查看更多打开指定消息
	virtual void openAssignMsgCenter(int nUnread, QString strMsgId);

	//!开始消息线程
	virtual void startMsgThread(QString strUid, QString strToken,QString strCompId);

	//!结束所有消息对话框
	virtual void closeAllMsgWidget();

	//!设置用户数据
	virtual void setUserData(QString strUid, QString strToken, QString strCompId, bool bSetThread = true);

	//!消息弹出程序已读
	virtual void reportMsgInfo(QString strUid, QString strMsgId, QString strCompId);

	//!消息对话框是否显示
	virtual bool msgCenterShow();

	//!减少未读条数
	virtual void reduceUnreadNum();
private:

	//!停止消息轮询线程
	void stopMsgThread();

	//!停止所有消息弹窗程序
	void stopPopupProcess();
	QProcess*			m_processActivity = NULL;
	MsgCenterWidget*	m_pMsgCenterWidget = NULL;
	ZcloudMsgThread*	m_pZcloudMsgThread = NULL;
};

#endif // ZCLOUDMSGCENTERIMPL_H
