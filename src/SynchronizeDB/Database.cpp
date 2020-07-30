#include "Database.h"
#include <QCoreApplication>
#include <QVariant>
#include <QDateTime>
Database *Database::m_pDbInstance = NULL;

Database::Database(QObject *parent)
	:QObject(parent)
{

}

Database * Database::GetInstance()
{
	if (m_pDbInstance == NULL)
	{
		m_pDbInstance = new Database();
	}
	return m_pDbInstance;
}

void Database::DestoryInstance()
{
	if (m_pDbInstance != NULL)
	{
		delete m_pDbInstance;
		m_pDbInstance = NULL;
	}
}

Database::~Database()
{
	if (m_DataBase.isValid())
	{
		m_DataBase.close();
	}
	if (m_MsgDataBase.isValid())
	{
		m_MsgDataBase.close();
	}
}

bool Database::openOldDataBase()
{
	QString dbPath = QCoreApplication::applicationDirPath() + "/zhicloud.db";
	m_DataBase = QSqlDatabase::addDatabase("QSQLITE", "zhicloudDatabase");
	m_DataBase.setDatabaseName(dbPath);
	if (m_DataBase.open())
	{
		return isOldTableExist("msgCenterInfo");
	}
	return false;
}

bool Database::isOldTableExist(QString strTableName)
{
	QSqlQuery query(m_DataBase);
	QString strSql = QString("select name from sqlite_master where type='table' and name='%1';").arg(strTableName);
	if (!query.exec(strSql))
	{
		return false;
	}
	return query.first();
}

bool Database::isCurTableExist(QString strTableName)
{
	QSqlQuery query(m_MsgDataBase);
	QString strSql = QString("select name from sqlite_master where type='table' and name='%1';").arg(strTableName);
	if (!query.exec(strSql))
	{
		return false;
	}
	return query.first();
}

bool Database::openCurDataBase()
{
	QString dbPath = QCoreApplication::applicationDirPath() + "/zhicloudMsgInfo.db";
	m_MsgDataBase = QSqlDatabase::addDatabase("ZCWXSQL", "zhicloudMsgDatabase");
	m_MsgDataBase.setPassword("ZhiCloudMsgPwd");
	m_MsgDataBase.setDatabaseName(dbPath);
	if (m_MsgDataBase.open())
	{
		if (!CreateDb(dbPath))
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool Database::CreateDb(QString strPath)
{
	QSqlError lastError;
	QString	 creatStr;
	QSqlQuery query(m_MsgDataBase);

	//!建立消息中心表
	if (!isCurTableExist("msgCenterInfo"))
	{
		creatStr = QString("CREATE TABLE [msgCenterInfo]("
			"[userId] TEXT NOT NULL,"
			"[token] TEXT NOT NULL,"
			"[msgType] INT NOT NULL,"
			"[msgId] TEXT,"
			"[comId] TEXT,"
			"[feedBackId] TEXT,"
			"[title] TEXT,"
			"[content] TEXT,"
			"[abstruct] TEXT,"
			"[position] INT,"
			"[sendTime] INT,"
			"[validStartTime] INT,"
			"[validEndTime] INT,"
			"[targetType] INT,"
			"[target] TEXT,"
			"[btnInfo] QByteArray,"
			"[isRead] BOOL NOT NULL,"
			"[isOld] BOOL NOT NULL,"
			"Primary Key(userId,msgId,comId));"
			);
		if (!query.exec(creatStr))
		{
			lastError = query.lastError();
			return false;
		}
	}
	return true;
}

bool Database::queryMsgInfo(vtrMsgInfo& msgInfos)
{
	QSqlError lastError;
	QString strSql = "select * from msgCenterInfo";
	QSqlQuery query(m_DataBase);
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		QString str = lastError.driverText();
		return false;
	}
	else
	{
		while (query.next())
		{
			stMsgInfo*	pMsgInfo = new stMsgInfo;
			pMsgInfo->strId = query.value(0).toString();
			pMsgInfo->strUid = query.value(1).toString();
			pMsgInfo->strToken = query.value(2).toString();
			pMsgInfo->strTitle = query.value(3).toString();
			pMsgInfo->strCreateTime = query.value(4).toString();
			pMsgInfo->strContent = query.value(5).toString();
			pMsgInfo->strAlias = query.value(6).toString();
			pMsgInfo->_strTitle = query.value(7).toString();
			pMsgInfo->_strContent = query.value(8).toString();
			pMsgInfo->strLink = query.value(9).toString();
			pMsgInfo->strIsRead = query.value(10).toString();
			pMsgInfo->strBtnInfo = query.value(11).toByteArray();
			pMsgInfo->strImagePath = query.value(12).toString();
			pMsgInfo->strAppId = query.value(13).toString();
			pMsgInfo->strPopUp = query.value(14).toString();
			msgInfos.push_back(pMsgInfo);
		}
		query.finish();
	}
	return true;
}

bool Database::insertHistoryMsgInfo(const vtrMsgInfo& msgInfos)
{
	QSqlQuery query(m_MsgDataBase);
	m_MsgDataBase.transaction();
	vtrMsgInfo::const_iterator	itr = msgInfos.begin();
	for (; itr != msgInfos.end();	++itr)
	{
		stMsgInfo*	pMsgInfo = (*itr);
		query.prepare("replace into msgCenterInfo values( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");
		query.bindValue(0, pMsgInfo->strUid);
		query.bindValue(1, pMsgInfo->strToken);

		if (pMsgInfo->strAlias	==	"zhiCloudImgNotice")
		{
			query.bindValue(2, 2);
			query.bindValue(6, pMsgInfo->strImagePath);
		}
		else if (pMsgInfo->strAlias == "zhiCloudOtherNotice" || pMsgInfo->strAlias == "zhiCloudPushNotice")
		{
			query.bindValue(2, 1);
			query.bindValue(6, pMsgInfo->strContent);
		}
		query.bindValue(3, pMsgInfo->strId);
		query.bindValue(4, "");
		query.bindValue(5, pMsgInfo->strTitle);
		query.bindValue(7, pMsgInfo->_strContent);
		query.bindValue(8, (pMsgInfo->strPopUp).toInt());

		QDateTime	time	= QDateTime::fromString(pMsgInfo->strCreateTime, "yyyy-MM-dd hh:mm:ss");
		int nSendTime = time.toTime_t();
		query.bindValue(9, nSendTime);
		query.bindValue(10, 0);
		query.bindValue(11, 0);
		
		if (!pMsgInfo->strLink.isEmpty())
		{
			query.bindValue(12, 1);
			query.bindValue(13, pMsgInfo->strLink);
		}
		if (!pMsgInfo->strAppId.isEmpty())
		{
			query.bindValue(12, 2);
			query.bindValue(13, pMsgInfo->strAppId);
		}
		query.bindValue(14, pMsgInfo->strBtnInfo);
		query.bindValue(15, (pMsgInfo->strIsRead).toInt());
		query.bindValue(16,true);
		if (!query.exec())
		{
			continue;
		}
	}
	m_MsgDataBase.commit();
	return true;	
}


