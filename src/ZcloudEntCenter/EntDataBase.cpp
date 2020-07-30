#include "EntDataBase.h"
#include <QSqlQuery>
#include <QApplication>
#include <QSqlError>
#include <QDebug>
EntDataBase *EntDataBase::m_pDbInstance = NULL;
EntDataBase::EntDataBase(QObject *parent)
	: QObject(parent)
{
	openEntDatabase();
}

EntDataBase::~EntDataBase()
{
	if (m_DataBase.isValid())
	{
		m_DataBase.close();
	}
}

EntDataBase * EntDataBase::GetInstance()
{
	if (m_pDbInstance == NULL)
	{
		m_pDbInstance = new EntDataBase();
	}
	return m_pDbInstance;
}

void EntDataBase::DestoryInstance()
{
	if (m_pDbInstance != NULL)
	{
		delete m_pDbInstance;
		m_pDbInstance = NULL;
	}
}
bool EntDataBase::isTableExist(QString strTableName)
{
	QSqlQuery query(m_DataBase);
	QString strSql = QString("select name from sqlite_master where type='table' and name='%1';").arg(strTableName);
	if (!query.exec(strSql))
	{
		return false;
	}
	return query.first();
}

bool EntDataBase::openEntDatabase()
{
	QString dbPath = QApplication::applicationDirPath() + "/zhicloudEnt.db";
	m_DataBase = QSqlDatabase::addDatabase("ZCWXSQL", "zhicloudEntDatabase");
	m_DataBase.setPassword("ZhiCloudEntPwd");
	m_DataBase.setDatabaseName(dbPath);
	if (m_DataBase.open())
	{
		if (!CreateDB(dbPath))
		{
			qDebug() << "zcd-0x10000014:create zhicloudEnt database failed!";
			return false;
		}
	}
	else
	{
		qDebug() << "zcd-0x10000015:open zhicloudEnt database failed!";
		return false;
	}
	return true;
}

bool EntDataBase::CreateDB(QString strPath)
{
	QSqlError lastError;
	QString	 creatStr;
	QSqlQuery query(m_DataBase);

	//!建立消息中心表
	if (!isTableExist("entCenterInfo"))
	{
		creatStr = QString("CREATE TABLE [entCenterInfo]("
			"[userId] TEXT PRIMARY KEY NOT NULL UNIQUE,"
			"[token] TEXT,"
			"[compId] TEXT,"
			"[compName] TEXT,"
			"[taxNo] TEXT,"
			"[logo] TEXT,"
			"[logoPath] TEXT,"
			"[isHxMember] BOOL,"
			"[chargeExpire] INT,"
			"[endDays] INT,"
			"[manualFulled] BOOL,"
			"[memberList] QByteArray,"
			"[lastSignTime] INT,"
			"[coin] INT,"
			"[coupon] INT,"
			"[companyInfoUrl] TEXT,"
			"[tradeInfoUrl] TEXT,"
			"[financialMemberUrl] TEXT,"
			"[accountSettingUrl] TEXT,"
			"[renewUrl] TEXT,"
			"[memberInfoUrl] TEXT,"
			"[signUrl] TEXT,"
			"[createCompanyUrl] TEXT,"
			"[hasMember] BOOL); "
			);
		if (!query.exec(creatStr))
		{
			lastError = query.lastError();
			qDebug() << "zcd-0x10000016:create entCenterInfo table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
			return false;
		}
	}
	return true;
}

bool EntDataBase::insertEntCenterInfo(const EntCenterInfo& entInfo)
{
	QSqlError lastError;
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	query.prepare("replace into entCenterInfo values( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");
	query.bindValue(0, entInfo._strUid);
	query.bindValue(1, entInfo._strToken);
	query.bindValue(2, entInfo._strCompId);
	query.bindValue(3, entInfo._strCompName);
	query.bindValue(4, entInfo._strTaxNo);
	query.bindValue(5, entInfo._strLogo);
	query.bindValue(6, entInfo._strLogoPath);
	query.bindValue(7, entInfo._bIsHxMember);
	query.bindValue(8, entInfo._nChargeExpire);
	query.bindValue(9, entInfo._nEndDays);
	query.bindValue(10, entInfo._bIsManualFulled);
	query.bindValue(11, entInfo._memberList);
	query.bindValue(12, entInfo._nLastSignTime);
	query.bindValue(13, entInfo._nCoin);
	query.bindValue(14, entInfo._nCoupon);
	query.bindValue(15, entInfo._strCompanyInfoUrl);
	query.bindValue(16, entInfo._strTradeInfoUrl);
	query.bindValue(17, entInfo._strFinancialMemberUrl);
	query.bindValue(18, entInfo._strAccountSettingUrl);
	query.bindValue(19, entInfo._strRenewUrl);
	query.bindValue(20, entInfo._strMemberInfoUrl);
	query.bindValue(21, entInfo._strSignUrl);
	query.bindValue(22, entInfo._strCreateCompanyUrl);
	query.bindValue(23, entInfo._bHasMember);
	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000017:replace entCenterInfo table failed! \r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	return true;
}

bool EntDataBase::queryEntCenterInfo(QString strUid,EntCenterInfo& entInfo)
{
	QSqlError lastError;
	QString strSql = QString("select * from entCenterInfo where userId='%1';").arg(strUid);
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000018:select entCenterInfo table failed! \r\n sql:" << strSql << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	else
	{
		while (query.next())
		{
			entInfo._strUid				= query.value(0).toString();
			entInfo._strToken			= query.value(1).toString();
			entInfo._strCompId			= query.value(2).toString();
			entInfo._strCompName		= query.value(3).toString();
			entInfo._strTaxNo			= query.value(4).toString();
			entInfo._strLogo			= query.value(5).toString();
			entInfo._strLogoPath		= query.value(6).toString();
			entInfo._bIsHxMember		= query.value(7).toBool();
			entInfo._nChargeExpire		= query.value(8).toInt();
			entInfo._nEndDays			= query.value(9).toInt();
			entInfo._bIsManualFulled	= query.value(10).toBool();
			entInfo._memberList			= query.value(11).toByteArray();
			entInfo._nLastSignTime		= query.value(12).toInt();
			entInfo._nCoin				= query.value(13).toInt();
			entInfo._nCoupon			= query.value(14).toInt();
			entInfo._strCompanyInfoUrl	= query.value(15).toString();
			entInfo._strTradeInfoUrl	= query.value(16).toString();
			entInfo._strFinancialMemberUrl	= query.value(17).toString();
			entInfo._strAccountSettingUrl	= query.value(18).toString();
			entInfo._strRenewUrl			= query.value(19).toString();
			entInfo._strMemberInfoUrl		= query.value(20).toString();
			entInfo._strSignUrl				= query.value(21).toString();
			entInfo._strCreateCompanyUrl	= query.value(22).toString();
			entInfo._bHasMember				= query.value(23).toBool();
		}
		query.finish();
	}
	return true;
}
