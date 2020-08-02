#ifndef ZCLOUDMSGCENTER_H
#define ZCLOUDMSGCENTER_H
#include <QtCore/qglobal.h>
#include <QObject>
#ifdef ZCLOUDMSGCENTER_LIB
# define ZCLOUDMSGCENTER_EXPORT Q_DECL_EXPORT
#else
# define ZCLOUDMSGCENTER_EXPORT Q_DECL_IMPORT
#endif

class ZCLOUDMSGCENTER_EXPORT ZcloudMsgCenter:public QObject
{
	Q_OBJECT
public:
	//创建实例对象
	static ZcloudMsgCenter * createNew();

	//!销毁对象
	virtual void destroy()			=	0; 

	//!开始消息线程
	virtual void startMsgThread(QString strUid, QString strToken, QString strCompId) = 0;


	//!打开消息中心
	virtual void openMsgCenter(int nUnread)	=	0;

	//!刷新消息中心
	virtual void refreshMsgCenter(int nUnread) = 0;

	//!点击查看更多打开指定消息
	virtual void openAssignMsgCenter(int nUnread,QString strMsgId) =0;

	//!停止消息轮询线程
	virtual void stopMsgThread()	=	0;

	//!关闭所有消息弹框
	virtual void closeAllMsgWidget() = 0;

	//!设置用户数据
	virtual void setUserData(QString strUid, QString strToken, QString strCompId,bool bSetThread = true) = 0;

	//!消息弹出程序已读、点击等上报
	virtual void reportMsgInfo(QString strUid, QString strMsgId, QString strCompId) = 0;

	//!消息对话框是否显示
	virtual bool msgCenterShow() = 0;

	//!减少未读条数
	virtual void reduceUnreadNum()	=	0;
signals:
	void changeUnreadMsgNum(int,bool);
	void checkTokenFailed(int);
	void sigReduceUnreadNum(int);
	void sigSendMessageRespone(QString);
private:

};
#endif // ZCLOUDMSGCENTER_H
