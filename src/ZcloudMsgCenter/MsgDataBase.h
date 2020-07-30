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

	//!��ѯ��Ϣ���ݣ�nType 0Ϊȫ�� 1Ϊ�Ѷ� 2Ϊδ����
	bool queryMsgInfo(vtrMsgInfo& msgInfos,int nPage = 0, int nType = 0);

	//!ɾ����Ϣ
	bool deleteMsg(QString strId);

	//!δ��-���Ѷ�
	bool changeMsgState(QString strId);

	//!������Ϣ
	bool insertMsgInfo(const vtrMsgInfo& msgInfos);

	//!���õ�ǰ��¼�û���Ϣ
	void setUserData(QString strUid, QString strToken,QString strCompId);

	//!����ʱ��ѯ��ǰ�û�δ����Ϣ����
	int  countUnreadMsg();

	//!��Ϣ�Ѷ�-��δ��
	bool changeMsgState(QString strId,QString strUid,QString strCompId);
private:
	//!�ж����ݿ���Ƿ����
	bool isTableExist(QString strTableName);

	//�����ݿ�
	bool openMsgDatabase();

	//!������ݿⲻ�����򴴽�
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
