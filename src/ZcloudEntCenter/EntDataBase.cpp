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
			//qDebug() << "zcd-0x10000014:create zhicloudEnt database failed!";
			return false;
		}
	}
	else
	{
		//qDebug() << "zcd-0x10000015:open zhicloudEnt database failed!";
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


		   /* "CREATE TABLE [entCenterInfo]("
			"[Id] TEXT PRIMARY KEY NOT NULL UNIQUE,"
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
			"[hasMember] BOOL, "
			"[hzs_id]  TEXT,"
			"[email]  TEXT,"
			"[company_type]  INTEGER,"
			"[trade_id]  INTEGER, "
			"[province_id]  INTEGER,"
			"[city_id]  INTEGER,"
			"[area_id]  INTEGER,"
			"[address]  TEXT,"
			"[legal_person_phone]  TEXT,"
			"[legal_person_name}  TEXT,"
			"[bank_name]  TEXT,"
			"[bank_account]  TEXT,"
			"[office_province_id]  INTEGER,"
			"[office_city_id]  INTEGER,"
			"[office_area_id]  INTEGER,"
			"[office_address]  TEXT,"
			"[is_join]  INTEGER,"
			"[is_bind_s]  INTEGER,"
			"[has_admin]  INTEGER,"
			"[reg_full_address]  TEXT,"
			"[office_full_address]  TEXT,"
			"[ser_business_id]  TEXT,"
			"[ser_hzs_id]  TEXT,"
			"[ser_username]  TEXT,"
			"[ser_phone]  TEXT,"
			"[ser_truename]  TEXT,"
			"[ser_sex]  INTEGER,"
			"[ser_province_id]  INTEGER,"
			"[ser_city_id]  INTEGER,"
			"[ser_area_id]  INTEGER,"
			"[ser_address]  TEXT,"
			"[ser_weixin]  TEXT,"
			"[ser_qq]  TEXT,"
			"[ser_nickname]  TEXT,"
			"[ser_avatarurl]  TEXT,"
			"[usr_user_id]  INTEGER,"
			"[usr_user_name]  TEXT,"
			"[usr_true_name]  TEXT,"
			"[usr_job]  TEXT,"
			"[usr_roletype]  INTEGER);"*/
	
		creatStr = QString(
		//"ALTER TABLE [entCenterInfo] RENAME TO [_entCenterInfo_old_20200811]; "
		"CREATE TABLE [entCenterInfo]("
		"[Id] TEXT PRIMARY KEY NOT NULL UNIQUE,"
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
		"[lastSignTime] INT,"
		"[coin] INT,"
		"[coupon] INT,"
		"[hasMember] BOOL, "
		"[hzs_id]  TEXT,"
		"[email]  TEXT,"
		"[company_type]  INT,"
		"[trade_id]  INT, "
		"[province_id]  INT,"
		"[city_id]  INT,"
		"[area_id]  INT,"
		"[address]  TEXT,"
		"[entbossphone]  TEXT,"
		"[entboss}  TEXT,"
		"[entbankname]  TEXT,"
		"[bankaccount]  TEXT,"
		"[oprovinceid]  INT,"
		"[ocityid]  INT,"
		"[oareaid]  INT,"
		"[oaddress]  TEXT,"
		"[is_join]  INT,"
		"[is_binds]  INT,"
		"[has_admin]  INT,"
		"[regfaddress]  TEXT,"
		"[officefaddress]  TEXT,"
		"[serbusiness_id]  TEXT,"
		"[serhzs_id]  TEXT,"
		"[serusername]  TEXT,"
		"[serphone]  TEXT,"
		"[sertruename]  TEXT,"
		"[sersex]  INT,"
		"[serprovince_id]  INT,"
		"[ser_city_id]  INT,"
		"[ser_area_id]  INT,"
		"[ser_address]  TEXT,"
		"[ser_weixin]  TEXT,"
		"[ser_qq]  TEXT,"
		"[ser_nickname]  TEXT,"
		"[ser_avatarurl]  TEXT,"
		"[usr_user_id]  TEXT,"
		"[usr_user_name]  TEXT,"
		"[usr_true_name]  TEXT,"
		"[usr_job]  TEXT,"
		"[usr_roletype]  INT);"
		     /*"CREATE TABLE [entCenterInfo]("
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
			"[hasMember] BOOL); "*/
			);
		if (!query.exec(creatStr))
		{
			lastError = query.lastError();
			//qDebug() << "zcd-0x10000016:create entCenterInfo table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
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

	//query.prepare("replace into entCenterInfo (Id,token,compId,compName,taxNo,logo,logoPath,isHxMember,chargeExpire,endDays,manualFulled,memberList,lastSignTime,coin,coupon,companyInfoUrl,tradeInfoUrl,financialMemberUrl,accountSettingUrl,renewUrl,memberInfoUrl,signUrl,createCompanyUrl,hasMember,hzs_id,email,company_type,trade_id,province_id,city_id,area_id,address,legal_person_phone,legal_person_name,bank_name,bank_account,office_province_id,office_city_id,office_area_id,office_address,is_join,is_bind_s,has_admin,reg_full_address,office_full_address,ser_business_id,ser_hzs_id,ser_username,ser_phone,ser_truename,ser_sex,ser_province_id,ser_city_id,ser_area_id,ser_address,ser_weixin,ser_qq,ser_nickname,ser_avatarurl,usr_user_id,usr_user_name,usr_true_name,usr_job,usr_roletype) values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");
	//query.prepare("insert or replace into entCenterInfo (Id, token) values(?, ?);");
	query.prepare("insert or replace into entCenterInfo (Id,token,compId,compName,taxNo,logo,logoPath,isHxMember,chargeExpire,endDays,coin,coupon,hasMember,hzs_id,email,company_type,trade_id,province_id,city_id,area_id,address,entbossphone,entboss) values(?, ?, ?, ?, ?, ?,?, ?, ?, ?, ?, ?,?, ?, ?, ?, ?, ?,?, ?, ?, ?, ?);");
	
	query.bindValue(0, entInfo._strId);	
	query.bindValue(1, entInfo._strToken);
	query.bindValue(2, entInfo._strCompId);
	query.bindValue(3, entInfo._strCompName);
	query.bindValue(4, entInfo._strTaxNo);
	query.bindValue(5, entInfo._strLogo);
	query.bindValue(6, entInfo._strLogoPath);
	query.bindValue(7, entInfo._bIsHxMember);
	query.bindValue(8, entInfo._nChargeExpire);
	query.bindValue(9, entInfo._nEndDays);
	query.bindValue(10, entInfo._nCoin);
	query.bindValue(11, entInfo._nCoupon);
	query.bindValue(12, entInfo._bHasMember);
	query.bindValue(13, entInfo._strHzsid);
	query.bindValue(14, entInfo._strEmail);
	query.bindValue(15, entInfo._nCompanytype);
	query.bindValue(16, entInfo._nTradeid);
	query.bindValue(17, entInfo._nProvinceid);	
	query.bindValue(18, entInfo._nCityid);
	query.bindValue(19, entInfo._nAreaid);
	query.bindValue(20, entInfo._strAddress);
	query.bindValue(21, entInfo._strlegalbossmobile);
	query.bindValue(22, entInfo._strlegalboss);

//	query.bindValue(22, entInfo._strBankname);
	//query.bindValue(24, entInfo._strBankaccount);
	//query.bindValue(25, entInfo._nOfficeProvinceid);
	//query.bindValue(37, entInfo._nOfficeCityid);
	//query.bindValue(38, entInfo._nOfficeAreaid);
	//query.bindValue(39, entInfo._strOfficeaddress);
	//query.bindValue(40, entInfo._nisjoin);
	//query.bindValue(41, entInfo._nisbinds);
	//query.bindValue(42, entInfo._nhasadmin);
	//query.bindValue(43, entInfo._strRegisterFulladdress);
	//query.bindValue(44, entInfo._strOfficeFulladdress);
	//query.bindValue(45, entInfo._oservice.m_businessid);
	//query.bindValue(46, entInfo._oservice.m_strHzsId);
	//query.bindValue(47, entInfo._oservice.m_strUsername);
	//query.bindValue(48, entInfo._oservice.m_strPhone);
	//query.bindValue(49, entInfo._oservice.m_strTruename);
	//query.bindValue(50, entInfo._oservice.m_sex);
	//query.bindValue(51, entInfo._oservice.m_nProvinceId);
	//query.bindValue(52, entInfo._oservice.m_nCityId);
	//query.bindValue(53, entInfo._oservice.m_nAreaId);
	//query.bindValue(54, entInfo._oservice.m_strAddress);
	//query.bindValue(55, entInfo._oservice.m_wechat);
	//query.bindValue(56, entInfo._oservice.m_qq);
	//query.bindValue(57, entInfo._oservice.m_nickname);
	//query.bindValue(58, entInfo._oservice.m_avatarurl);
	//query.bindValue(59, entInfo._strUid);
	//query.bindValue(60, entInfo._strUsername);
	//query.bindValue(61, entInfo._strTruename);
	//query.bindValue(62, entInfo._strJob);
	//query.bindValue(63, entInfo._nrole_type);


	if (!query.exec())
	{
		lastError = query.lastError();
	
		//qDebug() << "zcd-0x10000017:replace entCenterInfo table failed! \r\n error : " << lastError << lastError.driverText().toStdString().c_str();
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
		//qDebug() << "zcd-0x10000018:select entCenterInfo table failed! \r\n sql:" << strSql << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
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
			entInfo._strHzsid = query.value(24).toString();
			entInfo._strEmail = query.value(25).toString();
			entInfo._nCompanytype = query.value(26).toInt();
			entInfo._nTradeid = query.value(27).toInt();
			entInfo._nProvinceid = query.value(28).toInt();
			entInfo._nCityid = query.value(29).toInt();
			entInfo._nAreaid = query.value(30).toInt();
			entInfo._strAddress = query.value(31).toString();
			entInfo._strlegalbossmobile = query.value(32).toString();
			entInfo._strlegalboss = query.value(33).toString();
			entInfo._strBankname = query.value(34).toString();
			entInfo._strBankaccount = query.value(35).toString();

			entInfo._nOfficeProvinceid = query.value(36).toInt();
			entInfo._nOfficeCityid = query.value(37).toInt();
			entInfo._nOfficeAreaid = query.value(38).toInt();
			entInfo._strOfficeaddress = query.value(39).toString();

			entInfo._nisjoin = query.value(40).toInt();
			entInfo._nisbinds = query.value(41).toInt();
			entInfo._nhasadmin = query.value(42).toInt();
			entInfo._strRegisterFulladdress = query.value(43).toString();
			entInfo._strOfficeFulladdress = query.value(44).toString();


			entInfo._oservice.m_businessid = query.value(45).toString();
			entInfo._oservice.m_strHzsId = query.value(46).toString();
			entInfo._oservice.m_strUsername = query.value(47).toString();
			entInfo._oservice.m_strPhone = query.value(48).toString();
			entInfo._oservice.m_strTruename = query.value(49).toString();
			entInfo._oservice.m_sex = query.value(50).toString();
			entInfo._oservice.m_nProvinceId = query.value(51).toInt();
			entInfo._oservice.m_nCityId = query.value(52).toInt();
			entInfo._oservice.m_nAreaId = query.value(53).toInt();
			entInfo._oservice.m_strAddress = query.value(54).toString();
			entInfo._oservice.m_wechat = query.value(55).toString();
			entInfo._oservice.m_qq = query.value(56).toString();
			entInfo._oservice.m_nickname = query.value(57).toString();
			entInfo._oservice.m_avatarurl = query.value(58).toString();
			entInfo._strUid = query.value(59).toString();
			entInfo._strUsername = query.value(60).toString();
			entInfo._strTruename = query.value(61).toString();
			entInfo._strJob = query.value(62).toString();
			entInfo._nrole_type = query.value(63).toInt();
		}
		query.finish();
	}
	return true;
}
