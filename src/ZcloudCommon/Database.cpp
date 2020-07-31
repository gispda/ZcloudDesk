#include "Database.h"
#include <QApplication>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "ZcloudCommon.h"

Database *Database::m_pDbInstance = NULL;
ServerDatabase *ServerDatabase::m_pSDbInstance = NULL;
Database::Database(QObject *parent)
	: QObject(parent)
{
	openDatabase();
}

Database::~Database()
{
	if (m_DataBase.isValid())
	{
		m_DataBase.close();
	}
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

bool Database::openDatabase()
{
	QString dbPath = QApplication::applicationDirPath() + "/zhicloudUser.db";

	m_DataBase = QSqlDatabase::addDatabase("ZCWXSQL", "zhicloudDatabase");
	//m_DataBase = QSqlDatabase::addDatabase("QSQLITE", "zhicloudDatabase");
	m_DataBase.setPassword("ZhiCloudUserPwd");
	m_DataBase.setDatabaseName(dbPath);
	QString name = m_DataBase.userName();
	bool open = m_DataBase.open();
	if (open)
	{
		if (!createDB(dbPath))
		{
			qDebug() << "zcd-0x10000019: create zhicloudUser database failed!";
			return false;
		}
	}
	else
	{
		qDebug() << "zcd-0x10000020: open zhicloudUser database failed!";
		return false;
	}
	return true;
}

bool Database::createDB(QString strPath)
{
	QSqlError lastError;
	QString	 creatStr;
	QSqlQuery query(m_DataBase);

	//!建立登录设置表
	if (!isTableExist("loginSet"))
	{
		creatStr = QString("CREATE TABLE [loginSet]("
			"[id] INT PRIMARY KEY UNIQUE,"
			"[firstLogin] BOOL NOT NULL DEFAULT 1,"
			"[autoLogin] BOOL NOT NULL DEFAULT 0,"
			"[loginByTax] INT NOT NULL DEFAULT 1,"
			"[forcedSwitch] BOOL NOT NULL DEFAULT 0,"
			"[uid] TEXT,"
			"[taxNo] TEXT,"
			"[machine] TEXT,"
			"[userName] TEXT,"
			"[pwd] TEXT,"
			"[token] TEXT,"
			"[nextCloudGh] BOOL DEFAULT 1,"
			"[needUpdate] BOOL DEFAULT 0,"
			"[updateFilePath] TEXT,"
			"[showGuide] BOOL  DEFAULT 1"
			");"
			);
		if (!query.exec(creatStr))
		{
			lastError = query.lastError();
			qDebug() << "zcd-0x10000021:create loginSet table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
			return false;
		}
	}

	//!建立设置中心表
	if (!isTableExist("settingInfo"))
	{
		creatStr = QString("CREATE TABLE [settingInfo]("
			"[uid] TEXT PRIMARY KEY UNIQUE,"
			"[showTop] BOOL DEFAULT 1,"
			"[showRight] BOOL DEFAULT 1"
			");"
			);
		if (!query.exec(creatStr))
		{
			lastError = query.lastError();
			qDebug() << "zcd-0x10000022:create settingInfo table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
			return false;
		}
	}

	//!建立登录信息表
	if (!isTableExist("userLoginInfo"))
	{
		creatStr = QString("CREATE TABLE[userLoginInfo]("
			"[uid] TEXT NOT NULL,"
			"[token] TEXT,"
			"[compId] TEXT,"
			"[compName] TEXT,"
			"[taxNo] TEXT,"
			"[userName] TEXT,"
			"[pwd] TEXT,"
			"[trueName] TEXT,"
			"[job] TEXT,"
			"[logo] TEXT,"
			"[logoPath] TEXT,"
			"[provinceId] TEXT,"
			"[cityId] TEXT,"
			"[areaId] TEXT,"
			"[hzsId] TEXT,"
			"[isHxMember] BOOL,"
			"[isLoginByTax] INT,"
			"[timeChargeExpire] DATETIME,"
			"[isHideAppClass] BOOL,"
			"[appVipList] TEXT,"
			"[appVipNameList] TEXT,"
			"[appVipTimeList] TEXT,"
			"[userMobile] TEXT,"
			"[hasMember] BOOL,"
			"Primary Key([uid],[compId])"
			");"
			);
		if (!query.exec(creatStr))
		{
			lastError = query.lastError();
			qDebug() << "zcd-0x10000023:create userLoginInfo table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
			return false;
		}
	}

	//桌面快捷方式表
	if (!isTableExist("LnkExe"))
	{
		creatStr = QString("CREATE TABLE[LnkExe]("
			"[knkName] TEXT,"
			"[exename] TEXT,"
			"[isUp] BOOL,"
			"Primary Key([knkName], [exename])"
			"); "
			);
		if (!query.exec(creatStr))
		{
			lastError = query.lastError();
			qDebug() << "create LnkExe table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
			return false;
		}
	}

	//!建立顶栏工具表
	if (!isTableExist("topToolInfo"))
	{
		creatStr = QString::fromLocal8Bit(
			"CREATE TABLE[topToolInfo]("
			"[userId] TEXT NOT NULL,"			//用户Id

			"[appId] TEXT NOT NULL,"			//应用id
			"[appName] TEXT NOT NULL,"			//应用名字
			"[appAlias] TEXT,"					//应用别名
			"[appIconPath] TEXT,"				//应用本地图标路径
			"[appIconDownUrl] TEXT,"			//应用图标下载地址

			"[appDownloadUrl] TEXT,"			//应用下载地址 bs的访问地址
			"[appExecName] TEXT,"				//应用的执行名字
			"[appExecPathUrl] TEXT,"			//应用的执行路径(cs本地路径)
			"[appUninstallPath] TEXT,"			//应用的卸载路径
			"[appParams]  TEXT,"				//免登录参数(如果未空 则无免登录)

			"[appSort] INT,"					//应用的顺序
			"[appType] BOOL,"					//应用类型 cs/bs
			"[appIsDefaultWeb] BOOL,"			//是否默认浏览器打开
			"[appFree] TEXT,"					//应用的价格
			"[appVipList] TEXT,"				//vip等级链表

			"[appVipNameList] TEXT,"			//vip等级名字
			"[appVipEndTimeList] TEXT,"
			"[appSize] INT,"					//软件大小
			"[appDownloadNumber] INT,"			//应用下载次数
			"[appCreatTimer] DATETIME,"			//应用创建时间
			"[appUpdateSpecification] TEXT,"	//更新说明

			"[appOnLineVerson] TEXT,"			//线上版本
			"[appCurrentVerson] TEXT,"			//当前版本
			"[appIsForceUpdate] INT,"			//是否强制更新
			"[appIsInstall] BOOL,"				//应用是否安装
			"[appDesc] TEXT,"					//应用简介

			"[appUpdateTime] INT,"			//更新时间
			"[appPaidTime] TEXT,"				//应用的到期时间
			"[enExperienceTime] TEXT,"			//试用结束时间
			"[experienceTime] TEXT,"			//试用时间
			"[bindingPhone] BOOL,"				//是否需要绑定手机号

			"[auth] BOOL,"		//0用户不能隐藏  1用户可以隐藏
			"[state] BOOL,"		//1默认显示 0：默认不显示
			"[bsMethod] BOOL,"		//传参方式  0：get   1:post    (B/S)
			"[upMethod] INT,"		//应用更新模式 0-静默/1-强制提示/2-提示/3-暗示[B/S]
			"[reserved1] TEXT,"
			"[reserved2] TEXT,"
			"Primary Key([userId], [appId])"
			");"
			);
		if (!query.exec(creatStr))
		{
			lastError = query.lastError();
			qDebug() << "zcd-0x10000024:create topToolInfo table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
			return false;
		}
	}

	if (!isTableExist("taxInfo"))
	{
		creatStr = QString("CREATE TABLE[taxInfo]("
			"[tax] TEXT PRIMARY KEY NOT NULL UNIQUE,"
			"[machine] TEXT); ");
		if (!query.exec(creatStr))
		{
			lastError = query.lastError();
			qDebug() << "zcd-0x10000025:create taxInfo table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
			return false;
		}
	}
	return true;
}

bool Database::isTableExist(QString strTableName)
{
	QSqlQuery query(m_DataBase);
	QString strSql = QString("select name from sqlite_master where type='table' and name='%1';").arg(strTableName);
	if (!query.exec(strSql))
	{
		return false;
	}
	return query.first();
}


bool Database::updateTopApp(AppDataInfo appDataInfo, QString userId)
{
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery sqlQuery(m_DataBase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	sqlQuery.prepare("UPDATE  topToolInfo SET appIconPath = ?,appExecPathUrl = ?, appUninstallPath = ?,appCurrentVerson = ?, appIsInstall = ? WHERE userId = ? AND appId = ?;");
	sqlQuery.bindValue(0, appDataInfo.m_strAppIconPath);
	sqlQuery.bindValue(1, appDataInfo.m_strAppExecPathUrl);
	sqlQuery.bindValue(2, appDataInfo.m_strAppUninstallPath);
	sqlQuery.bindValue(3, appDataInfo.m_strAppCurrentVerson);
	sqlQuery.bindValue(4, appDataInfo.m_bAppIsInstall);
	sqlQuery.bindValue(5, userId);
	sqlQuery.bindValue(6, appDataInfo.m_strAppId);
	if (!sqlQuery.exec())
	{
		qDebug() << "zcd-0x00000043:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	return true;

}

bool Database::insertTopToolInfo(const AppDataInfo* appDataInfo, QString userId)
{
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery sqlQuery(m_DataBase);
	m_DataBase.transaction();

	//vtrAppDataInfos::const_iterator	itr = topToolInfos.begin();
	//for (; itr != topToolInfos.end(); ++itr)
	//{
	//	AppDataInfo*	appDataInfo = (*itr);
		QString strSql = QString("select * from topToolInfo where  userId = '%1' AND appId = '%2';").arg(userId).arg(appDataInfo->m_strAppId);
		if (!sqlQuery.exec(strSql))
		{
			qDebug() << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
			sqlQuery.finish();
			return false;
		}


		

		if (sqlQuery.next())
		{
			sqlQuery.finish();
			sqlQuery.prepare("update topToolInfo set  appName=?, appAlias=?,appIconPath=?, appIconDownUrl=?,"
				"appDownloadUrl=?, appExecName=?, appParams=?, appSort=?, appType=?, appIsDefaultWeb=?,"
				"appFree=? ,appVipList=? , appVipNameList=?, appVipEndTimeList = ?,appSize=?, appDownloadNumber=?,"
				"appCreatTimer=?, appUpdateSpecification=?, appOnLineVerson=?,appIsForceUpdate=?, appDesc=?,"
				"appUpdateTime=?, experienceTime=?, bindingPhone=?,"
				"auth = ?, state = ?, bsMethod = ?, upMethod = ?,"
				"reserved1=?,reserved2=? where userId = ? AND appId = ?;");
		}
		else
		{
			sqlQuery.finish();
			sqlQuery.prepare("replace into topToolInfo( appName, appAlias,appIconPath, appIconDownUrl,"
				"appDownloadUrl, appExecName, appParams, appSort, appType, appIsDefaultWeb,"
				"appFree ,appVipList , appVipNameList, appVipEndTimeList, appSize, appDownloadNumber,"
				" appCreatTimer, appUpdateSpecification, appOnLineVerson,appIsForceUpdate, appDesc,"
				"appUpdateTime, experienceTime, bindingPhone,"
				"auth, state, bsMethod, upMethod,"
				" reserved1,reserved2,  userId, appId)"
				"values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);"); // 28 个
		}

		sqlQuery.bindValue(0, appDataInfo->m_strAppName);
		sqlQuery.bindValue(1, appDataInfo->m_strAppAlias);
		sqlQuery.bindValue(2, appDataInfo->m_strAppIconPath);
		sqlQuery.bindValue(3, appDataInfo->m_strAppIconDownUrl);

		sqlQuery.bindValue(4, appDataInfo->m_strAppDownloadUrl);
		sqlQuery.bindValue(5, appDataInfo->m_strAppExecName);
		sqlQuery.bindValue(6, appDataInfo->m_strAppParams);
		sqlQuery.bindValue(7, appDataInfo->m_intAppSort);
		sqlQuery.bindValue(8, appDataInfo->m_bAppType);

		sqlQuery.bindValue(9, appDataInfo->m_bAppIsDefaultWeb);
		sqlQuery.bindValue(10, appDataInfo->m_strAppFree);
		sqlQuery.bindValue(11, appDataInfo->m_strListAppVipList.join("#"));
		sqlQuery.bindValue(12, appDataInfo->m_strListAppVipNameList.join("#"));
		sqlQuery.bindValue(13, appDataInfo->m_vipEndTimeList.join("#"));
		sqlQuery.bindValue(14, appDataInfo->m_intAppSize);

		sqlQuery.bindValue(15, appDataInfo->m_iAppDownloadNumber);
		sqlQuery.bindValue(16, appDataInfo->m_dtAppCreatTimer);
		sqlQuery.bindValue(17, appDataInfo->m_strAppUpdateSpecification);
		sqlQuery.bindValue(18, appDataInfo->m_strAppOnLineVerson);
		sqlQuery.bindValue(19, appDataInfo->m_intAppIsForceUpdate);

		sqlQuery.bindValue(20, appDataInfo->m_strAppDesc);
		sqlQuery.bindValue(21, appDataInfo->m_update_time);
		sqlQuery.bindValue(22, appDataInfo->m_experienceTime);
		sqlQuery.bindValue(23, appDataInfo->m_isBindingPhone);
		

		sqlQuery.bindValue(24, appDataInfo->bAuth);
		sqlQuery.bindValue(25, appDataInfo->bState);
		sqlQuery.bindValue(26, appDataInfo->bSMethod);
		sqlQuery.bindValue(27, appDataInfo->m_iUpMethod);


		sqlQuery.bindValue(28, appDataInfo->m_strReserved1);
		sqlQuery.bindValue(29, appDataInfo->m_strReserved2);
	

		sqlQuery.bindValue(30, userId);
		sqlQuery.bindValue(31, appDataInfo->m_strAppId);

		if (!sqlQuery.exec())
		{
			qDebug() << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
			sqlQuery.finish();
			//continue;
		}
	//}
	m_DataBase.commit();
	return true;
}

bool Database::removeTopToolInfo(QString strUid, QString strTopId)
{
	QSqlError lastError;
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery sqlQuery(m_DataBase);
	QString strSql = QString("delete from topToolInfo where  userId = ? AND appId = ? ; ");
	sqlQuery.prepare(strSql);
	sqlQuery.bindValue(0, strUid);
	sqlQuery.bindValue(1, strTopId);
	if (!sqlQuery.exec())
	{
		lastError = sqlQuery.lastError();
		qDebug() << "zcd-0x00000044:" << strSql << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		sqlQuery.finish();
		return false;
	}
	return true;
}

bool Database::updateTopAppPaidTime(QString appId, QString strUid, int paidTime, bool isPaid)
{
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery sqlQuery(m_DataBase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	if (isPaid)
		sqlQuery.prepare("UPDATE  topToolInfo SET appPaidTime = ? WHERE userId = ? AND appId = ?;");
	else
		sqlQuery.prepare("UPDATE  topToolInfo SET enExperienceTime = ? WHERE userId = ? AND appId = ?;");
	sqlQuery.bindValue(0, QString::number(paidTime));
	sqlQuery.bindValue(1, strUid);
	sqlQuery.bindValue(2, appId);

	if (!sqlQuery.exec())
	{
		if (isPaid)
			qDebug() << "zcd-0x00000045:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		else
			qDebug() << "zcd-0x00000046:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	return true;
}

bool Database::queryTopToolInfo(QString strUid, vtrAppDataInfos& topToolInfos , bool isAuth)
{

	QSqlError lastError;
	QString strSql = isAuth ? QString("select * from topToolInfo where userId='%1' and auth='1' order by appSort asc;").arg(strUid) : QString("select * from topToolInfo where userId='%1'order by appSort asc;").arg(strUid) ;
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery sqlQuery(m_DataBase);
	if (!sqlQuery.exec(strSql))
	{
		lastError = sqlQuery.lastError();
		qDebug() << (isAuth ?  "zcd-0x10000033:select topToolInfo table failed! \r\n sql:" : "zcd-0x10000026:select topToolInfo table failed! \r\n sql:") << strSql << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		sqlQuery.finish();
		return false;
	}
	else
	{
		while (sqlQuery.next())
		{
			AppDataInfo*	appDataInfo = new AppDataInfo;
			appDataInfo->m_strAppId = sqlQuery.value(1).toString();					//应用id
			appDataInfo->m_strAppName = sqlQuery.value(2).toString();				//应用名字
			appDataInfo->m_strAppAlias = sqlQuery.value(3).toString();				//应用别名
			appDataInfo->m_strAppIconPath = sqlQuery.value(4).toString();			//应用本地图标路径
			appDataInfo->m_strAppIconDownUrl = sqlQuery.value(5).toString();			//应用图标下载地址

			appDataInfo->m_strAppDownloadUrl = sqlQuery.value(6).toString();
			appDataInfo->m_strAppExecName = sqlQuery.value(7).toString();			//应用的执行名字
			appDataInfo->m_strAppExecPathUrl = sqlQuery.value(8).toString();			//应用的执行路径(cs本地路径 bs的访问地址)
			appDataInfo->m_strAppUninstallPath = sqlQuery.value(9).toString();		//应用的卸载路径
			appDataInfo->m_strAppParams = sqlQuery.value(10).toString();				//执行参数

			appDataInfo->m_intAppSort = sqlQuery.value(11).toInt();					//应用的顺序
			appDataInfo->m_bAppType = sqlQuery.value(12).toBool();					//应用类型 cs/bs
			appDataInfo->m_bAppIsDefaultWeb = sqlQuery.value(13).toBool();			//是否默认浏览器打开
			appDataInfo->m_strAppFree = sqlQuery.value(14).toString();					//应用的价格
			appDataInfo->m_strListAppVipList = sqlQuery.value(15).toString().split("#");		//vip等级链表
			if (appDataInfo->m_strListAppVipList.size() == 1)
			{
				//有可能  为空  因为  split 解析空字符串 返回1
				if (appDataInfo->m_strListAppVipList.at(0).isEmpty())
					appDataInfo->m_strListAppVipList.clear();
			}
			appDataInfo->m_strListAppVipNameList = sqlQuery.value(16).toString().split("#");//vip等级名字链表
			appDataInfo->m_vipEndTimeList = sqlQuery.value(17).toString().split("#");		//到期时间
			if (appDataInfo->m_vipEndTimeList.size() == 1)
			{
				//有可能  为空  因为  split 解析空字符串 返回1
				if (appDataInfo->m_vipEndTimeList.at(0).isEmpty())
					appDataInfo->m_vipEndTimeList.clear();
			}


			appDataInfo->m_intAppSize = sqlQuery.value(18).toInt();				//软件大小
			appDataInfo->m_iAppDownloadNumber = sqlQuery.value(19).toInt();			//应用下载次数
			appDataInfo->m_dtAppCreatTimer = sqlQuery.value(20).toDateTime();		//应用创建时间
			appDataInfo->m_strAppUpdateSpecification = sqlQuery.value(21).toString();//更新说明

			appDataInfo->m_strAppOnLineVerson = sqlQuery.value(22).toString();		//线上版本
			appDataInfo->m_strAppCurrentVerson = sqlQuery.value(23).toString();		//当前版本
			appDataInfo->m_intAppIsForceUpdate = sqlQuery.value(24).toInt();			//是否强制更新
			appDataInfo->m_bAppIsInstall = sqlQuery.value(25).toBool();				//应用是否安装
			appDataInfo->m_strAppDesc = sqlQuery.value(26).toString();				//应用简介

			appDataInfo->m_update_time = sqlQuery.value(27).toInt();


			appDataInfo->m_enPaidTime = sqlQuery.value(28).toString();
			
			appDataInfo->m_enExperienceTime = sqlQuery.value(29).toString();
			
			appDataInfo->m_experienceTime = sqlQuery.value(30).toString();
			
			appDataInfo->m_isBindingPhone = sqlQuery.value(31).toBool();
			appDataInfo->bAuth = sqlQuery.value(32).toBool();
			appDataInfo->bState = sqlQuery.value(33).toBool();
			appDataInfo->bSMethod = sqlQuery.value(34).toBool();
			appDataInfo->m_iUpMethod = sqlQuery.value(35).toInt();

			appDataInfo->m_strReserved1 = sqlQuery.value(36).toString();
			appDataInfo->m_strReserved2 = sqlQuery.value(37).toString();


			//待处理 顶栏隐藏开票软件
				//if (appDataInfo->m_strAppName == QString::fromLocal8Bit("开票软件") || appDataInfo->m_strAppName == QString::fromLocal8Bit("重装开票"))
			topToolInfos.push_back(appDataInfo);
		}	
	}
	sqlQuery.finish();
	return true;
}



bool Database::findLoginSet(LoginSetingStruct &loginSetingStruct)
{
	QSqlError lastError;
	QString strSql = QString("select * from loginSet;");
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000027:select loginSet table failed! \r\n sql:" << strSql << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		query.finish();
		return false;
	}
	else
	{
		if(query.next())
		{
			loginSetingStruct.firstLogin = query.value(1).toBool();
			loginSetingStruct.autoLogin = query.value(2).toBool();
			loginSetingStruct.loginByTax = query.value(3).toInt();
			loginSetingStruct.forcedSwitch = query.value(4).toBool();
			loginSetingStruct.uid = query.value(5).toString();
			loginSetingStruct.taxNo = query.value(6).toString();
			loginSetingStruct.machine = query.value(7).toString();
			loginSetingStruct.userName = query.value(8).toString();
			loginSetingStruct.pwd = query.value(9).toString();
			loginSetingStruct.token = query.value(10).toString();
			loginSetingStruct.bShowGuide = query.value(14).toBool();
		}
	}
	query.finish();
	return true;
}

bool Database::setLoginSet(LoginSetingStruct loginSetingStuct)
{
	QSqlError lastError;
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	//update topToolInfo 
	// replace 是先删除再插入， 不能用户替换表中的部分字段
	QString strSql = QString("select * from loginSet where id = 1;");
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000054:select loginSet  key = 1 table failed! \r\n sql:" << strSql << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		query.finish();
		return false;
	}

	if (query.next())
	{
		query.finish();
		query.prepare("update loginSet set  firstLogin = ? , autoLogin = ? , loginByTax = ? , uid = ? , taxNo = ? , machine = ? , userName = ? , pwd = ? , token = ? where id = ?;");
	}
	else
	{
		query.finish();
		query.prepare("replace into loginSet( firstLogin, autoLogin, loginByTax, uid, taxNo, machine, userName, pwd, token, id)  values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");
	}

	query.bindValue(0, loginSetingStuct.firstLogin);
	query.bindValue(1, loginSetingStuct.autoLogin);
	query.bindValue(2, loginSetingStuct.loginByTax);
	query.bindValue(3, loginSetingStuct.uid);
	query.bindValue(4, loginSetingStuct.taxNo);
	query.bindValue(5, loginSetingStuct.machine);
	query.bindValue(6, loginSetingStuct.userName);
	query.bindValue(7, loginSetingStuct.pwd);
	query.bindValue(8, loginSetingStuct.token);
	query.bindValue(9, 1);
	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000028:replace loginSet table failed! \r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		m_DataBase.commit();
		return false;
	}
	m_DataBase.commit();
	return true;
}

bool Database::setLoginSet(QString prepareStr)
{
	QSqlError lastError;
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (!query.exec(prepareStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000053:setLoginSet failed! \r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		m_DataBase.commit();
		return false;
	}
	m_DataBase.commit();
	return true;
}


bool Database::queryUpdateToolInfo(QString strUid, QString strToolId,int& nUpdateTime, QString& strImagePath,bool& bShow)
{
	QSqlError lastError;
	QString strSql = QString("select appIconPath,appUpdateTime,state from topToolInfo where userId='%1' and appId='%2';").arg(strUid).arg(strToolId);
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000029:select topToolInfo table failed! \r\n sql:" << strSql<<"\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		query.finish();
		return false;
	}
	else
	{
		if(query.next())
		{
			nUpdateTime = query.value(1).toInt();
			strImagePath = query.value(0).toString();
			bShow = query.value(2).toBool();
			query.finish();
			return true;
		}	
	}
	query.finish();
	return false;
}




//设置用户信息
bool Database::setUserData(UserInfoStruct userInfoStruct)
{
	QSqlError lastError;
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (!userInfoStruct.m_strCompanyId.isEmpty())
	{
		QString strSql = QString("delete from userLoginInfo where uid='%1' and compId='';").arg(userInfoStruct.m_strUserId);
		if (!query.exec(strSql))
		{
			return false;
		}
	}
	query.prepare("replace into userLoginInfo values( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");
	query.bindValue(0, userInfoStruct.m_strUserId);
	query.bindValue(1, userInfoStruct.m_strToken);
	query.bindValue(2, userInfoStruct.m_strCompanyId);
	query.bindValue(3, userInfoStruct.m_strCompanyName);
	query.bindValue(4, userInfoStruct.m_strTaxNumber);
	query.bindValue(5, userInfoStruct.m_strUsername);
	query.bindValue(6, userInfoStruct.m_strPwd);
	query.bindValue(7, userInfoStruct.m_strTruename);
	query.bindValue(8, userInfoStruct.m_strJob);
	query.bindValue(9, userInfoStruct.m_logoUrl);
	query.bindValue(10, userInfoStruct.m_logoPath);
	query.bindValue(11, userInfoStruct.m_strProvinceId);
	query.bindValue(12, userInfoStruct.m_strCityId);
	query.bindValue(13, userInfoStruct.m_strAreaId);
	query.bindValue(14, userInfoStruct.m_strHzsId);
	query.bindValue(15, userInfoStruct.m_isHxNumber);
	query.bindValue(16, userInfoStruct.m_bLoginByTax);
	query.bindValue(17, userInfoStruct.m_timeChargeExpire);
	query.bindValue(18, userInfoStruct.m_bHideAppClass);
	query.bindValue(19, userInfoStruct.m_strListAppVipList.join("#"));
	query.bindValue(20, userInfoStruct.m_strListAppVipNameList.join("#"));
	query.bindValue(21, userInfoStruct.m_vipDateTimeList.join("#"));
	query.bindValue(22, userInfoStruct.m_strMobile);
	query.bindValue(23, userInfoStruct.m_bHasMember);

	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000030:replace userLoginInfo table failed! \r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		m_DataBase.commit();
		return false;
	}
	m_DataBase.commit();
	return true;
}


//读取用户信息
bool Database::readUserData(UserInfoStruct &userInfoStruct,  QString strUserId)
{
	QSqlError lastError;
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	QString sqlStr = QString("select *from userLoginInfo where uid = '%1';").arg(strUserId);
	if (!query.exec(sqlStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000031:select userLoginInfo table failed! \r\n sql:" << sqlStr<<"\r\n error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}

	if (query.first())
	{
		userInfoStruct.m_strUserId = query.value(0).toString();
		userInfoStruct.m_strToken = query.value(1).toString();
		userInfoStruct.m_strCompanyId = query.value(2).toString();
		userInfoStruct.m_strCompanyName = query.value(3).toString();
		userInfoStruct.m_strTaxNumber = query.value(4).toString();
		userInfoStruct.m_strUsername = query.value(5).toString();
		userInfoStruct.m_strPwd = query.value(6).toString();
		userInfoStruct.m_strTruename = query.value(7).toString();
		userInfoStruct.m_strJob = query.value(8).toString();
		userInfoStruct.m_logoUrl = query.value(9).toString();
		userInfoStruct.m_logoPath = query.value(10).toString();
		userInfoStruct.m_strProvinceId = query.value(11).toString();
		userInfoStruct.m_strCityId = query.value(12).toString();
		userInfoStruct.m_strAreaId = query.value(13).toString();
		userInfoStruct.m_strHzsId = query.value(14).toString();
		userInfoStruct.m_isHxNumber = query.value(15).toBool();
		userInfoStruct.m_bLoginByTax = query.value(16).toInt();
		userInfoStruct.m_timeChargeExpire = query.value(17).toDateTime();
		userInfoStruct.m_bHideAppClass = query.value(18).toBool();
		userInfoStruct.m_strListAppVipList = query.value(19).toString().split("#");
		userInfoStruct.m_strListAppVipNameList = query.value(20).toString().split("#");
		userInfoStruct.m_vipDateTimeList = query.value(21).toString().split("#");
		userInfoStruct.m_strMobile = query.value(22).toString();
		userInfoStruct.m_bHasMember = query.value(23).toBool();
		return true;
	}
	return false;
}

bool Database::querySwitchInfo(vtrSwitchAccInfos& switchInfos)
{
	QSqlError lastError;
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	QString sqlStr = "select uid,compName,taxNo,userName,logoPath,isLoginByTax,pwd,token,userMobile,compId from userLoginInfo;";
	if (!query.exec(sqlStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000032:select userLoginInfo table failed! \r\n sql:" << sqlStr << "\r\n error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}

	while (query.next())
	{
		stSwitchAccInfo*	pSwitchInfo = new stSwitchAccInfo;
		pSwitchInfo->strUid			= query.value(0).toString();
		pSwitchInfo->strCompName	= query.value(1).toString();
		pSwitchInfo->strTaxNo		= query.value(2).toString();
		pSwitchInfo->strUserName	= query.value(3).toString();
		pSwitchInfo->strLogoPath	= query.value(4).toString();
		pSwitchInfo->bLoginByTax	= query.value(5).toInt();
		pSwitchInfo->strPwd			= query.value(6).toString();
		pSwitchInfo->strToken		= query.value(7).toString();
		pSwitchInfo->strMobliePhone = query.value(8).toString();
		pSwitchInfo->strCompId		= query.value(9).toString();
		switchInfos.push_back(pSwitchInfo);
	}
	return true;
}


bool Database::queryPhoneNumber(QStringList& listPhoneNumber)
{
	QSqlError lastError;
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	QString sqlStr = "select userMobile from userLoginInfo;";
	if (!query.exec(sqlStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000053:select PhoneNumber failed! \r\n sql:" << sqlStr << "\r\n error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}

	while (query.next())
	{
		QString phoneNumber = query.value(0).toString();
		if (!phoneNumber.isEmpty() && phoneNumber.size() == 11)
		{
			listPhoneNumber.append(phoneNumber);
		}
	}
	//listPhoneNumber.append("18201886681");
	return true;
}

bool Database::queryUserConfig(QString strUid, bool& bShowTop, bool& bShowRight)
{
	QSqlError lastError;
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	QString sqlStr = QString("select showTop,showRight from settingInfo where uid='%1';").arg(strUid);
	if (!query.exec(sqlStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000034:select settingInfo table failed! \r\n sql:" << sqlStr << "\r\n error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	if (query.first())
	{
		bShowTop	= query.value(0).toBool();
		bShowRight	= query.value(1).toBool();
	}
	return true;
}

bool Database::isUserConfigExist(QString strUid)
{
	QSqlError lastError;
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	QString strSql = QString("select * from settingInfo where uid='%1';").arg(strUid);
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000035:select settingInfo table failed! \r\n sql:" << strSql << "\r\n error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	return query.first();
}

bool Database::replaceUserConfig(QString strUid, bool bShowTop /*= true*/, bool bShowRight /*= true*/)
{
	QSqlError lastError;
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	query.prepare("replace into settingInfo values(?, ?, ?);");
	query.bindValue(0, strUid);
	query.bindValue(1, bShowTop);
	query.bindValue(2, bShowRight);
	
	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000036:replace settingInfo table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	return true;
}

bool Database::updateToolInfo(QString strUid, QString strToolId, bool bShow)
{
	QSqlError lastError;
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	query.prepare("update topToolInfo set state=? where userId=? and appId=?;");
	query.bindValue(0, bShow);
	query.bindValue(1, strUid);
	query.bindValue(2, strToolId);

	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000037:update topToolInfo table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
		m_DataBase.commit();
		return false;
	}
	return true;
}

bool Database::updateUserConfig(QString strUid, bool bShow, int nType)
{
	QSqlError lastError;
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (0 == nType)
	{
		query.prepare("update settingInfo set showTop=? where uid=?;");
	}
	else if (1 == nType)
	{
		query.prepare("update settingInfo set showRight=? where uid=?;");
	}
	
	query.bindValue(0, bShow);
	query.bindValue(1, strUid);
	
	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000038:update settingInfo table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	return true;
}





bool Database::insertTaxInfo(const QStringList& taxInfoList)
{
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	m_DataBase.transaction();

	QStringList::const_iterator	itr = taxInfoList.begin();
	for (; itr != taxInfoList.end(); ++itr)
	{
		QString strTax = (*itr);
		query.prepare("replace into taxInfo values(?,?);");
		query.bindValue(0, strTax);
		query.bindValue(1, "");
		if (!query.exec())
		{
			continue;
		}
	}
	m_DataBase.commit();
	return false;
}

bool Database::findTaxIsExist(QString strTax)
{
	QSqlError lastError;
	QSqlQuery query(m_DataBase);
	QString execStr = QString("select * from taxInfo where tax='%1';").arg(strTax);
	if (!query.exec(execStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000039:select taxInfo table failed! \r\n  sql:" << execStr<< "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	return query.first();
}

bool Database::findLnkExeName(QList<StLnkNameExeName > &lnkExeList)
{
	QSqlError lastError;
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	QString sqlStr = "select * from LnkExe;";
	if (!query.exec(sqlStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x00000047:" << "findLnkExeNameMapError" << sqlStr << "error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}

	while (query.next())
	{
		StLnkNameExeName stLnkNameExeName;
		stLnkNameExeName.strLnkName = query.value(0).toString();
		stLnkNameExeName.strExeName = query.value(1).toString();
		stLnkNameExeName.isUp = query.value(2).toBool();
		lnkExeList << stLnkNameExeName;
	}
	return true;
}


bool Database::replaceLnkExeName(const StLnkNameExeName  &stLnkExe)
{
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	m_DataBase.transaction();
	QSqlError lastError;
	query.prepare("replace into LnkExe values(?,?,?);");
	query.bindValue(0, stLnkExe.strLnkName);
	query.bindValue(1, stLnkExe.strExeName);
	query.bindValue(2, stLnkExe.isUp);
	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x00000048:" << "insertLnkExeName" << "error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	m_DataBase.commit();
	return true;
}

ServerDatabase::~ServerDatabase()
{
	if (m_SDataBase.isValid())
	{
		m_SDataBase.close();
	}
}

ServerDatabase * ServerDatabase::GetInstance()
{
	if (m_pSDbInstance == NULL)
	{
		m_pSDbInstance = new ServerDatabase();
	}
	return m_pSDbInstance;
}

bool ServerDatabase::CreateDBS(QString strPath)
{
	QSqlError lastError;
	QSqlQuery query(m_SDataBase);
	if (!isTableExist("tasklist"))
	{
		QString creatStr = QString("CREATE TABLE [tasklist]("
			"[autoid]       INTEGER   PRIMARY KEY AUTOINCREMENT NOT NULL,"
			"[taskCate]     TEXT      NOT NULL,"
			"[userId]       TEXT      NOT NULL,"
			"[userToken]    TEXT,"
			"[appId]        TEXT,"
			"[appType]      INT,"
			"[msgId]        TEXT,"
			"[companyId]    TEXT,"
			"[hzsId]        TEXT,"
			"[responseType] INT,"
			"[btnId]		TEXT,"
			"[timeline] TIMESTAMP not null default (datetime('now','localtime'))"
			");");
		if (!query.exec(creatStr))
		{
			lastError = query.lastError();
			qDebug() << "zcd-0x10000040:create tasklist table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
			return false;
		}
	}
	return true;
}

bool ServerDatabase::isTableExist(QString strTableName)
{
	QSqlQuery query(m_SDataBase);
	QString strSql = QString("select name from sqlite_master where type='table' and name='%1';").arg(strTableName);
	if (!query.exec(strSql))
	{
		return false;
	}
	return query.first();
}

ServerDatabase::ServerDatabase(QObject *parent /*= 0*/)
	: QObject(parent)
{
	openServerDatabase();
}

bool ServerDatabase::openServerDatabase()
{
	QString dbPath = QApplication::applicationDirPath() + "/zhicloudServices.db";
	m_SDataBase = QSqlDatabase::addDatabase("QSQLITE", "zhicloudSDatabase");
	m_SDataBase.setDatabaseName(dbPath);
	if (m_SDataBase.open())
	{
		if (!CreateDBS(dbPath))
		{
			qDebug() << "zcd-0x10000041:create zhicloudService database failed!";
			return false;
		}
	}
	else
	{
		qDebug() << "zcd-0x10000042:open zhicloudService database failed!";
		return false;
	}
	return true;
}

bool ServerDatabase::insertAppOper(QString strUid, QString strToken, QString strAppId,QString strCompId, QString strHzsId, int nType)
{
	QSqlError lastError;
	QWriteLocker locker(&m_SReadWriteLock);
	QSqlQuery query(m_SDataBase);
	QString sqlStr = "insert into tasklist (taskCate,userId,userToken,appId,appType,companyId,hzsId) values(?, ?, ?, ?, ?, ?, ?);";
	query.prepare(sqlStr);
	query.bindValue(0, "app_oper");
	query.bindValue(1, strUid);
	query.bindValue(2, strToken);
	query.bindValue(3, strAppId);
	query.bindValue(4, nType);
	query.bindValue(5, strCompId);
	query.bindValue(6, strHzsId);
	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000043:insert app oper tasklist table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	return true;
}

bool ServerDatabase::readAppOper(const QString strUid, QStringList &appIdList, const  int nType)
{
	QSqlError lastError;
	QReadLocker locker(&m_SReadWriteLock);
	QSqlQuery query(m_SDataBase);
	QString sqlStr = QString("select *from tasklist where userId = ? AND  taskCate = ? AND appType = ?;");
	query.prepare(sqlStr);
	query.bindValue(0, strUid);
	query.bindValue(1, "app_oper");
	query.bindValue(2, nType);
	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000043:insert app oper tasklist table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	while (query.next())
	{
		QString appId = query.value(2).toString();
		if (!appId.isEmpty())
			appIdList << appId;
	}
	return true;
}


bool ServerDatabase::insertMsgOper(QString strUid, QString strToken,QString strComId,QString strHzsId, QString strMsgId, int nResType, QString strBtnId)
{
	QSqlError lastError;
	QWriteLocker locker(&m_SReadWriteLock);
	QSqlQuery query(m_SDataBase);
	QString sqlStr = "insert into tasklist (taskCate,userId,userToken,companyId,hzsId,msgId,responseType,btnId) values(?, ?, ?, ?, ?, ?, ?, ?);";
	query.prepare(sqlStr);
	query.bindValue(0, "msg_oper");
	query.bindValue(1, strUid);
	query.bindValue(2, strToken);
	query.bindValue(3, strComId);
	query.bindValue(4, strHzsId);
	query.bindValue(5, strMsgId);
	query.bindValue(6, nResType);
	query.bindValue(7, strBtnId);
	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000044:insert msg oper tasklist table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	return true;
}


////解密
//QString Database::freeAESStr(QString aesStr, QString userId)
//{
//	return aesStr;
//	QByteArray data = aesStr.toLocal8Bit();
//	data = QByteArray::fromHex(data);
//	if (ZcloudComFun::aesZhicloud(data, userId, false))
//	{
//		aesStr = QString::fromLocal8Bit(data);
//		if (aesStr.contains(userId))
//		{
//			aesStr.replace(userId, "");
//			return aesStr;
//		}
//	}
//	qDebug() << "zcd-0x10000045:" << "freeAESStr  error = " << aesStr << "  userId = " << userId;
//	return "-1";
//}
//
////加密
//QString   Database::freeStrAEs(QString aesStr, QString userId)
//{
//	return aesStr;
//	aesStr += userId;
//	QByteArray data = aesStr.toLocal8Bit();
//	if (ZcloudComFun::aesZhicloud(data, userId, true))
//	{
//		QByteArray bye = data.toHex();
//		return QString::fromLocal8Bit(bye);
//	}
//	return "-1";
//}

bool Database::setUpdaterInfo(bool bNeedUpdate, QString strFilePath)
{
	QSqlError lastError;
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	query.prepare("update loginSet set needUpdate=?,updateFilePath=? where id='1';");
	query.bindValue(0, bNeedUpdate);
	query.bindValue(1, strFilePath);
	
	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000046:update loginSet table failed! \r\n error:" << lastError << lastError.driverText().toStdString().c_str();
		m_DataBase.commit();
		return false;
	}
	m_DataBase.commit();
	return true;
}

bool Database::queryUpdaterInfo(bool bNeedUpdate, QString strFilePath)
{
	QSqlError lastError;
	QString strSql = QString("select needUpdate,updateFilePath from loginSet where id='1';");
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	if (!query.exec(strSql))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x10000047:update loginSet table failed! \r\n sql:" << strSql<<"\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		query.finish();
		return false;
	}
	else
	{
		if (query.next())
		{
			bNeedUpdate = query.value(0).toBool();
			strFilePath = query.value(1).toString();
		}
	}
	query.finish();
	return true;
}


bool Database::addPhoneNumber(QString strMobile, QString strUserId)
{
	QSqlError lastError;
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);
	//userLoginInfo
	query.prepare("update userLoginInfo set userMobile =? where uid = ?;");
	query.bindValue(0, strMobile);
	query.bindValue(1, strUserId );

	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x00000056 " << "addPhoneNumber" << lastError << lastError.driverText().toStdString().c_str();
		m_DataBase.commit();
		return false;
	}
	m_DataBase.commit();
	return true;
}

//更改设置用户Id
bool Database::changeSetUsrId(QString strOldUserId, QString strNewUserId, QString strCompId)
{
	QSqlError lastError;
	QWriteLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);

	//loginSet
	query.prepare("update loginSet set uid=? where id='1' AND uid = ?;");
	query.bindValue(0, strNewUserId);
	query.bindValue(1, strOldUserId);

	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x00000049:" << "changeUsrId loginSet" << lastError << lastError.driverText().toStdString().c_str();
		m_DataBase.commit();
		return false;
	}
	m_DataBase.commit();

	//settingInfo
	QString execStr = QString("delete from settingInfo where uid='%1';").arg(strNewUserId);
	if (!query.exec(execStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x00000056:bind phone delete settingInfo table failed! \r\n  sql:" << execStr << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	m_DataBase.commit();

	query.prepare("update settingInfo set uid=? where uid = ?;");
	query.bindValue(0, strNewUserId);
	query.bindValue(1, strOldUserId);

	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x0000004A:" << "changeUsrId settingInfo" << lastError << lastError.driverText().toStdString().c_str();
		m_DataBase.commit();
		return false;
	}
	m_DataBase.commit();

	//topToolInfo
	execStr = QString("delete from topToolInfo where userId='%1';").arg(strNewUserId);
	if (!query.exec(execStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x00000057:bind phone delete topToolInfo table failed! \r\n  sql:" << execStr << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	m_DataBase.commit();

	query.prepare("update topToolInfo set userId=? where userId = ?;");
	query.bindValue(0, strNewUserId);
	query.bindValue(1, strOldUserId);

	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x0000004B:" << "changeUsrId topToolInfo" << lastError << lastError.driverText().toStdString().c_str();
		m_DataBase.commit();
		return false;
	}
	m_DataBase.commit();

	//删除已存在的
	query.prepare("delete from userLoginInfo where  uid = ? and compId= ?;");
	query.bindValue(0, strOldUserId);
	query.bindValue(1, strCompId);
	if (!query.exec())
	{
		qDebug() << "zcd-0x00000058:bind phone delete userLoginInfo table failed! \r\n  sql:" << execStr << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		m_DataBase.commit();
		return false;
	}
	m_DataBase.commit();

	execStr = QString("delete from userLoginInfo where uid='%1' and compId='';").arg(strNewUserId);
	if (!query.exec(execStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x00000060:bind phone delete userLoginInfo table failed! \r\n  sql:" << execStr << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	m_DataBase.commit();
	return true;
}

//更改企业中心userId
bool Database::changeEndUsrId(QString strOldUserId, QString strNewUserId)
{
	QString dbPath = QApplication::applicationDirPath() + "/zhicloudEnt.db";
	QSqlDatabase endDataBase = QSqlDatabase::addDatabase("ZCWXSQL", "entDatabase");
	endDataBase.setPassword("ZhiCloudEntPwd");
	endDataBase.setDatabaseName(dbPath);
	if (endDataBase.open())
	{
		QSqlError lastError;
		QSqlQuery query(endDataBase);

		QString execStr = QString("delete from entCenterInfo where userId='%1';").arg(strNewUserId);
		if (!query.exec(execStr))
		{
			lastError = query.lastError();
			qDebug() << "zcd-0x00000059:bind phone delete entCenterInfo table failed! \r\n  sql:" << execStr << "\r\n error : " << lastError << lastError.driverText().toStdString().c_str();
			return false;
		}
		endDataBase.commit();

		query.prepare("update entCenterInfo set userId= ? where userId = ?;");
		query.bindValue(0, strNewUserId);
		query.bindValue(1, strOldUserId);

		if (!query.exec())
		{
			lastError = query.lastError();
			qDebug() << "zcd-0x0000004D:" << "changeUsrId userLoginInfo" << lastError << lastError.driverText().toStdString().c_str();
			endDataBase.commit();
			endDataBase.close();
			return false;
		}
	}
	else
	{
		qDebug() << "zcd-0x10000015:open zhicloudEnt database failed!";
		return false;
	}
	endDataBase.commit();
	endDataBase.close();
	return true;
}

//更改消息中心UserId
bool Database::changeMsgUsrId(QString strOldUserId, QString strNewUserId)
{
	QString dbPath = QApplication::applicationDirPath() + "/zhicloudMsgInfo.db";
	QSqlDatabase msgDataBase = QSqlDatabase::addDatabase("ZCWXSQL", "msgDatabase");
	msgDataBase.setPassword("ZhiCloudMsgPwd");
	msgDataBase.setDatabaseName(dbPath);
	if (msgDataBase.open())
	{
		QSqlError lastError;
		QSqlQuery query(msgDataBase);
		query.prepare("update msgCenterInfo set userId=? where userId = ?;");
		query.bindValue(0, strNewUserId);
		query.bindValue(1, strOldUserId);

		if (!query.exec())
		{
			lastError = query.lastError();
			qDebug() << "zcd-0x0000004F:" << "changeMsgUsrId msgCenterInfo" << lastError << lastError.driverText().toStdString().c_str();
			msgDataBase.commit();
			msgDataBase.close();
			return false;
		}
	}
	else
	{
		qDebug() << "zcd-0x10000015:open zhicloudMsgInfo database failed!";
		return false;
	}
	msgDataBase.close();
	return true;
}

bool Database::getUserInfoByPreUser(UserInfoStruct& info)
{
	QReadLocker locker(&m_ReadWriteLock);
	QSqlQuery query(m_DataBase);

	QString strSql = "select uid,compId,hzsId,provinceId,cityId,areaId from userLoginInfo where uid=(select uid from loginSet where id='1');";
	if (!query.exec(strSql))
	{
		qDebug() << "zcd-0x10000053:" << query.lastError() << query.lastError().driverText().toStdString().c_str();
		return false;
	}
	else
	{
		query.first();
		info.m_strUserId		= query.value(0).toString();
		info.m_strCompanyId		= query.value(1).toString();
		info.m_strHzsId			= query.value(2).toString();
		info.m_strProvinceId	= query.value(3).toString();
		info.m_strCityId		= query.value(4).toString();
		info.m_strAreaId		= query.value(5).toString();
	}
	return true;
}

//更改用户Id
bool ServerDatabase::changeServerUsrId(QString strOldUserId, QString strNewUserId)
{
	QSqlError lastError;
	QWriteLocker locker(&m_SReadWriteLock);
	QSqlQuery query(m_SDataBase);
	query.prepare("update tasklist set userId= ? where userId = ?;");
	query.bindValue(0, strNewUserId);
	query.bindValue(1, strOldUserId);
	if (!query.exec())
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x00000050:" << "changeServerUsrId error:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	return true;
}