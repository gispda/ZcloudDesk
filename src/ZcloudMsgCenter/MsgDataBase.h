#ifndef MSGDATABASE_H
#define MSGDATABASE_H

#include <QObject>
#include <QReadWriteLock>
#include <QSqlDatabase>
#include "MsgInfoDenfine.h"
class MsgDataBase : public QObject
{
	Q_OBJECT

public:
	
	~MsgDataBase();

	static MsgDataBase *GetInstance();
	static void DestoryInstance();

	//!查询消息数据（nType 0为全部 1为已读 2为未读）
	bool queryMsgInfo(vtrMsgInfo& msgInfos,int nPage = 0, int nType = 0);

	//!删除消息
	bool deleteMsg(QString strId);

	//!未读-》已读
	bool changeMsgState(QString strId);

	//!插入消息
	bool insertMsgInfo(const vtrMsgInfo& msgInfos);

	//!设置当前登录用户信息
	void setUserData(QString strUid, QString strToken,QString strCompId);

	//!启动时查询当前用户未读消息条数
	int  countUnreadMsg();

	//!消息已读-》未读
	bool changeMsgState(QString strId,QString strUid,QString strCompId);
private:
	//!判断数据库表是否存在
	bool isTableExist(QString strTableName);

	//打开数据库
	bool openMsgDatabase();

	//!如果数据库不存在则创建
	bool CreateDB(QString strPath);

	explicit MsgDataBase(QObject *parent = 0);

	QString				m_strUid;
	QString				m_strToken;
	QString				m_strCompId;
	QReadWriteLock		m_ReadWriteLock;
	QSqlDatabase		m_DataBase;
	static MsgDataBase*	m_pDbInstance;
};

#endif // MSGDATABASE_H
