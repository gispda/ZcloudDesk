#ifndef DATABASE_H
#define DATABASE_H
#include <QObject>
#include <vector>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QReadWriteLock>
class stMsgInfo
{
public:
	stMsgInfo()
	{
		clear();
	}
	QString strId;			//!��ϢId
	QString strUid;			//!uid
	QString strToken;		//!token
	QString strTitle;		//!���⣨ȫ����
	QString strContent;		//!���ݣ�ȫ����
	QString strAlias;		//!��Ϣ���ͣ�����ͨ��zhiCloudCloudPushZqtNotice	ϵͳ��Ϣ:zhiCloudPushNotice��
	QString strCreateTime;	//!����ʱ��
	QString _strTitle;		//!���⣨��ȡ��
	QString _strContent;	//!���ݣ���ȡ��
	QString strPopUp;
	QString strLink;		//!ϵͳ��Ϣ����
	QString strIsRead;		//!�Ƿ��Ѷ�(δ����0	�Ѷ�:1)
	QByteArray strBtnInfo;		//!��ť��Ϣ
	QString strImagePath;	//!ͼƬ
	QString strAppId;		//!Ӧ��id
	void clear()
	{
		strId = "";
		strUid = "";
		strToken = "";
		strTitle = "";
		strContent = "";
		strAlias = "";
		strCreateTime = "";
		_strTitle = "";
		_strContent = "";
		strLink = "";
		strPopUp = "";
		strIsRead = "0";
		strImagePath = "";
		strAppId = "";
		strBtnInfo = QByteArray();
	}
};
//!��Ϣ���ݼ���
class  vtrMsgInfo :public std::vector<stMsgInfo*>
{
public:
	~vtrMsgInfo()
	{
		clearData();
	}
	void clearData()
	{
		if (0 != this->size())
		{
			iterator itr = this->begin();
			for (; itr != this->end(); ++itr)
			{
				stMsgInfo* pMsgInfo = (*itr);
				if (NULL != pMsgInfo)
				{
					delete pMsgInfo;
					pMsgInfo = NULL;
				}
			}
			this->clear();
		}
	}
};
class Database:public QObject
{
	Q_OBJECT
public:

	~Database();
	
	static Database *GetInstance();
	static void DestoryInstance();

	//! ����ǰ�汾��Ϣ���ݿ�
	bool openOldDataBase();

	//�����°汾��Ϣ���ݿ�û�в�������Ϣ��
	bool openCurDataBase();

	//!��ѯ��ǰ�汾��ʷ��Ϣ
	bool queryMsgInfo(vtrMsgInfo& msgInfos);

	bool insertHistoryMsgInfo(const vtrMsgInfo& msgInfos);
private:
	explicit Database(QObject *parent = 0);

	//!������ǰ���ݿ�
	bool CreateDb(QString strPath);

	//!�жϵ�ǰ�汾���ݿ���Ƿ���� 
	bool isCurTableExist(QString strTableName);

	//!�ж���ǰ�汾���ݿ���Ƿ����
	bool isOldTableExist(QString strTableName);

private:
	QSqlDatabase		m_DataBase;
	QSqlDatabase		m_MsgDataBase;
	static Database*	m_pDbInstance;
};
#endif

