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
	m_DataBase = QSqlDatabase::addDatabase("ZCWXSQL", "zhicloudMsgDatabase");
	m_DataBase.setPassword("ZhiCloudMsgPwd");
	m_DataBase.setDatabaseName(dbPath);
	if (m_DataBase.open())
	{
		if (!CreateDB(dbPath))
		{
			qDebug("zcd-0x10000006:create zhicloudMsgInfo database failed!");
			return false;
		}
	}
	else
	{
		qDebug("zcd-0x10000007:open zhicloudMsgInfo database failed!");
		return false;
	}
	return true;
}

bool MsgDataBase::CreateDB(QString strPath)
{
	QSqlError lastError;
	QString	 creatStr;
	QSqlQuery query(m_DataBase);

	//!建立消息中心表
	if (!isTableExist("msgCenterInfo"))
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
			qDebug() << "zcd-0x10000008:create msgCenterInfo table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
			return false;
		}
	}
	return true;
}

bool MsgDataBase::queryMsgInfo(vtrMsgInfo& msgInfos,int nPage /*= 0*/, int nType /*= 0*/)
{
	QSqlError lastError;
	QString strSql = QString("select * from msgCenterInfo where userId='%1' and comId='%2'").arg(m_strUid).arg(m_strCompId);
	if (1 == nType)	//已读
	{
		strSql += " and isRead='1'";
	}
	else if (2 == nType)	//!未读
	{
		strSql += " and isRead='0'";
	}
	strSql += QString(" order by sendTime DESC limit 20 offset %1;").arg(nPage);
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000009:select msgCenterInfo table failed! \r\n sql:" << strSql <<"\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	else
	{
		while (query.next())
		{
			stMsgInfo*	pMsgInfo = new stMsgInfo;
			pMsgInfo->_strUid = query.value(0).toString();
			pMsgInfo->_strToken = m_strToken;
			pMsgInfo->_nMsgType = query.value(2).toInt();
			pMsgInfo->_strMsgId = query.value(3).toString();
			pMsgInfo->_strComId = query.value(4).toString();
			pMsgInfo->_strFeedBackId = query.value(5).toString();
			pMsgInfo->_strMsgTitle = query.value(6).toString();
			pMsgInfo->_strMsgContent = query.value(7).toString();
			pMsgInfo->_strAbstruct = query.value(8).toString();
			pMsgInfo->_nPosition = query.value(9).toInt();
			pMsgInfo->_nSendTime = query.value(10).toInt();
			pMsgInfo->_nValidStartTime = query.value(11).toInt();
			pMsgInfo->_nValidEndTime = query.value(12).toInt();
			pMsgInfo->_nTargetType = query.value(13).toInt();
			pMsgInfo->_strTarget = query.value(14).toString();
			pMsgInfo->_arryBtnList = query.value(15).toByteArray();
			pMsgInfo->_bIsRead = query.value(16).toBool();
			pMsgInfo->_bIsOld = query.value(17).toBool();
			msgInfos.push_back(pMsgInfo);
		}
		query.finish();
	}
	return true;
}

bool MsgDataBase::deleteMsg(QString strId)
{
	QSqlError lastError;
	QString strSql = QString("delete from msgCenterInfo where userId='%1' and comId='%2' and msgId='%3';").arg(m_strUid).arg(m_strCompId).arg(strId);

	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000010:delete msgCenterInfo table failed! \r\n sql:" << strSql << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	return true;
}

bool MsgDataBase::changeMsgState(QString strId)
{
	QSqlError lastError;
	QString strSql = QString("update  msgCenterInfo set isRead='1' where userId='%1' and comId='%2' and msgId='%3';").arg(m_strUid).arg(m_strCompId).arg(strId);
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000011:msg update table failed! \r\n sql:" << strSql << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	return true;
}

bool MsgDataBase::changeMsgState(QString strId, QString strUid,QString strCompId)
{
	QSqlError lastError;
	QString strSql = QString("update  msgCenterInfo set isRead='1' where userId='%1' and comId='%2' and msgId='%3';").arg(strUid).arg(strCompId).arg(strId);
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000053:msg update table failed! \r\n sql:" << strSql << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	return true;
}

void MsgDataBase::setUserData(QString strUid, QString strToken, QString strCompId)
{
	m_strUid	= strUid;
	m_strToken	= strToken;
	m_strCompId = strCompId;
}

bool MsgDataBase::insertMsgInfo(const vtrMsgInfo& msgInfos)
{
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	m_DataBase.transaction();

	vtrMsgInfo::const_iterator	itr = msgInfos.begin();
	for (; itr != msgInfos.end(); ++itr)
	{
		stMsgInfo*	pInfo = (*itr);
		query.prepare("replace into msgCenterInfo values( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");
		query.bindValue(0, pInfo->_strUid);
		query.bindValue(1, pInfo->_strToken);
		query.bindValue(2, pInfo->_nMsgType);
		query.bindValue(3, pInfo->_strMsgId);
		query.bindValue(4, pInfo->_strComId);
		query.bindValue(5, pInfo->_strFeedBackId);
		query.bindValue(6, pInfo->_strMsgTitle);
		query.bindValue(7, pInfo->_strMsgContent);
		query.bindValue(8, pInfo->_strAbstruct);
		query.bindValue(9, pInfo->_nPosition);
		query.bindValue(10, pInfo->_nSendTime);
		query.bindValue(11, pInfo->_nValidStartTime);
		query.bindValue(12, pInfo->_nValidEndTime);
		query.bindValue(13, pInfo->_nTargetType);
		query.bindValue(14, pInfo->_strTarget);
		query.bindValue(15, pInfo->_arryBtnList);
		query.bindValue(16, pInfo->_bIsRead);
		query.bindValue(17, pInfo->_bIsOld);

		if (!query.exec())
		{
			continue;
		}
	}
	m_DataBase.commit();
	return true;
}

int MsgDataBase::countUnreadMsg()
{
	QSqlError lastError;
	QString strSql = QString("select count(msgId) from msgCenterInfo where userId='%1' and comId='%2' and isRead='0';").arg(m_strUid).arg(m_strCompId);

	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000053:count unread msgCenterInfo table failed! \r\n sql:" << strSql << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		return 0;
	}
	if (!query.first())
		return 0;
	return query.value(0).toInt();
}
