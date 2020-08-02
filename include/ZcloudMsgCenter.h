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
	//����ʵ������
	static ZcloudMsgCenter * createNew();

	//!���ٶ���
	virtual void destroy()			=	0; 

	//!��ʼ��Ϣ�߳�
	virtual void startMsgThread(QString strUid, QString strToken, QString strCompId) = 0;


	//!����Ϣ����
	virtual void openMsgCenter(int nUnread)	=	0;

	//!ˢ����Ϣ����
	virtual void refreshMsgCenter(int nUnread) = 0;

	//!����鿴�����ָ����Ϣ
	virtual void openAssignMsgCenter(int nUnread,QString strMsgId) =0;

	//!ֹͣ��Ϣ��ѯ�߳�
	virtual void stopMsgThread()	=	0;

	//!�ر�������Ϣ����
	virtual void closeAllMsgWidget() = 0;

	//!�����û�����
	virtual void setUserData(QString strUid, QString strToken, QString strCompId,bool bSetThread = true) = 0;

	//!��Ϣ���������Ѷ���������ϱ�
	virtual void reportMsgInfo(QString strUid, QString strMsgId, QString strCompId) = 0;

	//!��Ϣ�Ի����Ƿ���ʾ
	virtual bool msgCenterShow() = 0;

	//!����δ������
	virtual void reduceUnreadNum()	=	0;
signals:
	void changeUnreadMsgNum(int,bool);
	void checkTokenFailed(int);
	void sigReduceUnreadNum(int);
	void sigSendMessageRespone(QString);
private:

};
#endif // ZCLOUDMSGCENTER_H
