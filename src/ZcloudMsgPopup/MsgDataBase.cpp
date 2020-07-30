#include "MsgDataBase.h"
#include <QSqlQuery>
#include <QApplication>
#include <QSqlError>
#include <qDebug>
MsgDataBase *MsgDataBase::m_pDbInstance = NULL;
MsgDataBase::MsgDataBase(QObject *parent)
	: QObject(parent)
{
	openMsgDatabase();
}

MsgDataBase::~MsgDataBase()
{
	if (m_DataBase.isValid())
	{
		m_DataBase.close();
	}
}

MsgDataBase * MsgDataBase::GetInstance()
{
	if (m_pDbInstance == NULL)
	{
		m_pDbInstance = new MsgDataBase();
	}
	return m_pDbInstance;
}

void MsgDataBase::DestoryInstance()
{
	if (m_pDbInstance != NULL)
	{
		delete m_pDbInstance;
		m_pDbInstance = NULL;
	}
}

bool MsgDataBase::isTableExist(QString strTableName)
{
	QSqlQuery query(m_DataBase);
	QString strSql = QString("select name from sqlite_master where type='table' and name='%1';").arg(strTableName);
	if (!query.exec(strSql))
	{
		return false;
	}
	return query.first();
}

bool MsgDataBase::openMsgDatabase()
{
	QString dbPath = QApplication::applicationDirPath() + "/zhicloudMsgInfo.db";
	m_DataBase = QSqlDatabase::addDatabase("ZCWXSQL", "zcMsgDatabase");
	m_DataBase.setPassword("ZhiCloudMsgPwd");
	m_DataBase.setDatabaseName(dbPath);
	if (m_DataBase.open())
	{
		if (!CreateDB(dbPath))
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

bool MsgDataBase::queryMsgInfo(QString strUid,QString strToken, QString strComId, QString strMsgId, stMsgInfo& msgInfo)
{
	QSqlError lastError;
	QString strSql = QString("select * from msgCenterInfo where userId='%1' and comId='%2' and msgId='%3'").arg(strUid).arg(strComId).arg(strMsgId);
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		return false;
	}
	else
	{
		while (query.next())
		{
			msgInfo._strUid = query.value(0).toString();
			msgInfo._strToken = strToken;
			msgInfo._nMsgType = query.value(2).toInt();
			msgInfo._strMsgId = query.value(3).toString();
			msgInfo._strCompId = query.value(4).toString();
			msgInfo._strFeedBackId = query.value(5).toString();
			msgInfo._strMsgTitle = query.value(6).toString();
			msgInfo._strMsgContent = query.value(7).toString();
			msgInfo._strAbstruct = query.value(8).toString();
			msgInfo._nPosition = query.value(9).toInt();
			msgInfo._nSendTime = query.value(10).toInt();
			msgInfo._nValidStartTime = query.value(11).toInt();
			msgInfo._nValidEndTime = query.value(12).toInt();
			msgInfo._nTargetType = query.value(13).toInt();
			msgInfo._strTarget = query.value(14).toString();
			msgInfo._arryBtnList = query.value(15).toByteArray();
			msgInfo._bIsRead = query.value(16).toBool();
			msgInfo._bIsOld = query.value(17).toBool();
		}
		query.finish();
	}
	return true;
}
bool MsgDataBase::CreateDB(QString strPath)
{
	//!建立消息中心表
	if (!isTableExist("msgCenterInfo"))
	{
		return false;
	}
	return true;
}