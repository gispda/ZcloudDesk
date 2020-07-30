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
	QString strId;			//!消息Id
	QString strUid;			//!uid
	QString strToken;		//!token
	QString strTitle;		//!标题（全部）
	QString strContent;		//!内容（全部）
	QString strAlias;		//!消息类型（政企通：zhiCloudCloudPushZqtNotice	系统消息:zhiCloudPushNotice）
	QString strCreateTime;	//!创建时间
	QString _strTitle;		//!标题（截取）
	QString _strContent;	//!内容（截取）
	QString strPopUp;
	QString strLink;		//!系统消息链接
	QString strIsRead;		//!是否已读(未读：0	已读:1)
	QByteArray strBtnInfo;		//!按钮信息
	QString strImagePath;	//!图片
	QString strAppId;		//!应用id
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
//!消息数据集合
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

	//! 打开以前版本消息数据库
	bool openOldDataBase();

	//！打开新版本消息数据库没有并创建消息表
	bool openCurDataBase();

	//!查询以前版本历史消息
	bool queryMsgInfo(vtrMsgInfo& msgInfos);

	bool insertHistoryMsgInfo(const vtrMsgInfo& msgInfos);
private:
	explicit Database(QObject *parent = 0);

	//!创建当前数据库
	bool CreateDb(QString strPath);

	//!判断当前版本数据库表是否存在 
	bool isCurTableExist(QString strTableName);

	//!判断以前版本数据库表是否存在
	bool isOldTableExist(QString strTableName);

private:
	QSqlDatabase		m_DataBase;
	QSqlDatabase		m_MsgDataBase;
	static Database*	m_pDbInstance;
};
#endif

