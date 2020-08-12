#include "AppCenterDatabase.h"
#include <QDebug>
#include <QApplication>
#include <QFileInfo>
#include "ZhicloudAppDataDefine.h"
#include "Database.h"
#include "ZcloudCommon.h"


#define enumtoStr(val) Setstr(#val)
//"zcd-0x00000056 ����
AppCenterDatabase *AppCenterDatabase::m_appCenterDatabase = NULL;
extern UserInfoStruct app_userInfo;

AppCenterDatabase::AppCenterDatabase(QObject *parent)
	: QObject(parent)
{
	openAppCenterDatabase();
}

AppCenterDatabase::~AppCenterDatabase()
{
}

bool AppCenterDatabase::creatAppCenterDb()
{
	QSqlError lastError;
	QString	 creatStr;
	QSqlQuery query(m_appCenterSqlDatabase);
	creatStr = QString::fromLocal8Bit(
		"CREATE TABLE[Class]("
		"[userId] TEXT NOT NULL,"
		"[classId] TEXT NOT NULL,"
		"[className] TEXT NOT NULL,"
		"[pageFlag] INT NOT NULL,"   //0:�Ҳ����(�Զ����ȫ������) 1:������� 2:��˰�ر� 3:Ϊ���Ƽ� 4������Ӧ��
		"[sort] INT,"
		"[reserved1] TEXT,"
		"[reserved2] TEXT,"
		"PRIMARY KEY ([userId], [classId],[reserved1]));"
		);
	if (!query.exec(creatStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x00000002:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}


	//�ֲ�ͼ
	creatStr = QString::fromLocal8Bit(
		"CREATE TABLE[Slider]("
		"[userId] TEXT NOT NULL,"
		"[sliderId] TEXT NOT NULL,"
		"[sliderImgUrl] TEXT NOT NULL,"
		"[sliderType] INT NOT NULL,"
		"[sliderTarget] TEXT,"
		"[sliderImgPath] TEXT,"
		"[sliderDefaultWeb] BOOL,"
		"[sort] INT,"
		"[compId] TEXT,"
		"PRIMARY KEY ([userId], [sliderId],[compId]));"
		);
	if (!query.exec(creatStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x00000003:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}


	//Ӧ�ñ�
	creatStr = QString::fromLocal8Bit(
		"CREATE TABLE[App]("
		"[userId] TEXT NOT NULL,"			//�û�Id

		"[appId] TEXT NOT NULL,"			//Ӧ��id
		"[appName] TEXT NOT NULL,"			//Ӧ������
		"[appAlias] TEXT,"					//Ӧ�ñ���
		"[appIconPath] TEXT,"				//Ӧ�ñ���ͼ��·��
		"[appIconDownUrl] TEXT,"			//Ӧ��ͼ�����ص�ַ

		"[appDownloadUrl] TEXT,"			//Ӧ�����ص�ַ bs�ķ��ʵ�ַ
		"[appExecName] TEXT,"				//Ӧ�õ�ִ������
		"[appExecPathUrl] TEXT,"			//Ӧ�õ�ִ��·��(cs����·��)
		"[appUninstallPath] TEXT,"			//Ӧ�õ�ж��·��
		"[appParams]  TEXT,"				//���¼����(���δ�� �������¼)

		"[appSort] INT,"					//Ӧ�õ�˳��
		"[appType] BOOL,"					//Ӧ������ cs/bs
		"[appIsDefaultWeb] BOOL,"			//�Ƿ�Ĭ���������
		"[appFree] TEXT,"					//Ӧ�õļ۸�
		"[appVipList] TEXT,"				//vip�ȼ�����

		"[appVipNameList] TEXT,"			//vip�ȼ�����
		"[appVipEndTimeList] TEXT,"
		"[appSize] INT,"					//�����С
		"[appDownloadNumber] INT,"			//Ӧ�����ش���
		"[appCreatTimer] DATETIME,"			//Ӧ�ô���ʱ��
		"[appUpdateSpecification] TEXT,"	//����˵��

		"[appOnLineVerson] TEXT,"			//���ϰ汾
		"[appCurrentVerson] TEXT,"			//��ǰ�汾
		"[appIsForceUpdate] INT,"			//�Ƿ�ǿ�Ƹ���
		"[appIsInstall] BOOL,"				//Ӧ���Ƿ�װ
		"[appDesc] TEXT,"					//Ӧ�ü��

		"[appUpdateTime] INT,"			//����ʱ��
		"[appPaidTime] TEXT,"				//Ӧ�õĵ���ʱ��
		"[enExperienceTime] TEXT,"			//���ý���ʱ��
		"[experienceTime] TEXT,"			//����ʱ��
		"[bindingPhone] BOOL,"				//�Ƿ���Ҫ���ֻ���
		"[reserved1] TEXT,"
		"[reserved2] TEXT,"
		"Primary Key([userId], [appId],[reserved1] )"
		");"
		);
	if (!query.exec(creatStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x00000004:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}
	//Ӧ�ú����Ĺ�ϵ��
	creatStr = QString::fromLocal8Bit("CREATE TABLE[ClassAppInfo]("
		"[userId] TEXT NOT NULL,"
		"[appId] TEXT NOT NULL,"
		"[classId] TEXT NOT NULL,"
		"[sort] INT,"
		"[compId] TEXT,"
		"Primary Key([userId], [appId], [classId],[compId])"
		");");
	if (!query.exec(creatStr))
	{
		lastError = query.lastError();
		qDebug() << "zcd-0x00000005:" << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}

	//�����������Ӧ��
	creatStr = QString::fromLocal8Bit("CREATE TABLE[Sue]("
		"[userId] TEXT NOT NULL,"
		"[appId] TEXT NOT NULL,"
		"[compId] TEXT,"
		"Primary Key([userId], [appId], [compId])"
		");");
	if (!query.exec(creatStr))
	{
		lastError = query.lastError();
		qDebug()  << lastError << lastError.driverText().toStdString().c_str();
		return false;
	}



	return true;
}
bool AppCenterDatabase::openAppCenterDatabase()
{

	QString databasePath = QApplication::applicationDirPath() + "/zhicloudApp.db";

	m_appCenterSqlDatabase = 
	 QSqlDatabase::addDatabase("ZCWXSQL", "zhicloudAppDatabase");
	m_appCenterSqlDatabase.setDatabaseName(databasePath);
	m_appCenterSqlDatabase.setPassword("ZhiCloudAppPwd");
	QFileInfo dataFileInfo(databasePath);
	if (dataFileInfo.exists())
	{
		if (!m_appCenterSqlDatabase.open())
		{
			qDebug() << "zcd-0x00000006:" << "open db failed";
		}
	}
	else
	{
		if (!m_appCenterSqlDatabase.open())
		{
			qDebug() << "zcd-0x00000007:" << "open db failed";
			return false;
		}
		if (!creatAppCenterDb())
			qDebug() << "zcd-0x00000008:" << "create db file failed";
	}
	return true;
}

//����
/*//////////////////////////////////////////////////////////////////

* Function��insertClass

* Description�� �������

* Input����

* Output���Ƿ�ɹ�

* Others:

* ���ߣ�Tohn

* ���ڣ�2018-08-21 11:37:00

//////////////////////////////////////////////////////////////////*/
bool AppCenterDatabase::insertClass(AppClassInfo appClassInfo)
{
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	sqlQuery.prepare("replace into Class values(?, ?, ?, ?, ?, ?, ?);");
	sqlQuery.bindValue(0, app_userInfo.m_strUserId);
	sqlQuery.bindValue(1, appClassInfo.m_strClassId);
	sqlQuery.bindValue(2, appClassInfo.m_strClassName);
	sqlQuery.bindValue(3, (int)appClassInfo.m_pageFlag);
	sqlQuery.bindValue(4, appClassInfo.m_sort);
	sqlQuery.bindValue(5, app_userInfo.m_strCompanyId);
	sqlQuery.bindValue(6, appClassInfo.m_strReserved2);
	if (!sqlQuery.exec())
	{
		qDebug() << "zcd-0x00000009:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	return true;
}


bool AppCenterDatabase::removeClassAppInfo(QString strClassId)
{
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);

	if (sqlQuery.isActive()) sqlQuery.finish();
	QString exestr;

	if (app_userInfo.m_strCompanyId == "")
	exestr = QString("delete from ClassAppInfo where userId = '%1' AND classId = '%2';").arg(app_userInfo.m_strUserId).arg(strClassId);
	else
	exestr = QString("delete from ClassAppInfo where userId = '%1' AND classId = '%2' AND compId = '%3';").arg(app_userInfo.m_strUserId).arg(strClassId).arg(app_userInfo.m_strCompanyId);
	if (!sqlQuery.exec(exestr))
	{
		qDebug() << "zcd-0x00000051:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	return true;
}

bool AppCenterDatabase::removeClassAppInfo_Class(QString strAppId)
{
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);

	if (sqlQuery.isActive()) sqlQuery.finish();


	QString exestr;
	if (app_userInfo.m_strCompanyId == "")
	exestr = QString("delete from ClassAppInfo where userId = '%1' AND appId = '%2';").arg(app_userInfo.m_strUserId).arg(strAppId);
	else
	exestr = QString("delete from ClassAppInfo where userId = '%1' AND appId = '%2' AND compId = '%3';").arg(app_userInfo.m_strUserId).arg(strAppId).arg(app_userInfo.m_strCompanyId);
	if (!sqlQuery.exec(exestr))
	{
		qDebug() << "zcd-0x00000052:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	return true;
}


bool AppCenterDatabase::removeClass(QString classId)
{
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);

	if (sqlQuery.isActive()) sqlQuery.finish();

	QString exestr;
	if (app_userInfo.m_strCompanyId == "")
		exestr = QString("delete from Class where userId = '%1' AND  classId = '%2';").arg(app_userInfo.m_strUserId).arg(classId);
	else
		exestr = QString("delete from Class where userId = '%1' AND  classId = '%2' AND reserved1 = '%3';").arg(app_userInfo.m_strUserId).arg(classId).arg(app_userInfo.m_strCompanyId);


	sqlQuery.prepare(exestr);
	if (!sqlQuery.exec())
	{
		qDebug() << "zcd-0x0000000A:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	if (app_userInfo.m_strCompanyId == "")
		exestr = QString("delete from ClassAppInfo where userId = '%1' AND classId = '%2';").arg(app_userInfo.m_strUserId).arg(classId);
	else
		exestr = QString("delete from ClassAppInfo where userId = '%1' AND classId = '%2' AND compId = '%3';").arg(app_userInfo.m_strUserId).arg(classId).arg(app_userInfo.m_strCompanyId);



	if (!sqlQuery.exec(exestr))
	{
		qDebug() << "zcd-0x0000000B:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	return true;


}

/*//////////////////////////////////////////////////////////////////

* Function��findAppClassList

* Description�� ��ѯ���з���

* Input����

* Output���Ƿ�ɹ�

* Others:

* ���ߣ�Tohn

* ���ڣ�2018-09-03 10:03:00

//////////////////////////////////////////////////////////////////*/
bool AppCenterDatabase::findAppClassList(QList<AppClassInfo> &appClassInfoList, APPCLASSPAGEFLAG classFlag)
{
	QReadLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	QString sqlStr;
	if (classFlag == CLASSALL)
	{ 
		if (app_userInfo.m_strCompanyId=="")
			sqlStr = QString::fromLocal8Bit("select *from Class where userId = '%1';").arg(app_userInfo.m_strUserId);
		else
		sqlStr = QString::fromLocal8Bit("select *from Class where userId = '%1' AND reserved1 = '%2';").arg(app_userInfo.m_strUserId).arg(app_userInfo.m_strCompanyId);
	}		
	else
	{
		if (app_userInfo.m_strCompanyId == "")
		sqlStr = QString::fromLocal8Bit("select *from Class where userId = '%1' AND pageFlag = %2 order by sort desc;").arg(app_userInfo.m_strUserId).arg(classFlag);
		else
		sqlStr = QString::fromLocal8Bit("select *from Class where userId = '%1' AND pageFlag = %2 AND reserved1  = '%3' order by sort desc;").arg(app_userInfo.m_strUserId).arg(classFlag).arg(app_userInfo.m_strCompanyId);
	}
	
	if (!sqlQuery.exec(sqlStr))
	{
		qDebug() << "zcd-0x0000000C:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	while (sqlQuery.next())
	{
		AppClassInfo appClassInfo;
		appClassInfo.m_strClassId = sqlQuery.value(1).toString();
		appClassInfo.m_strClassName = sqlQuery.value(2).toString();
		appClassInfo.m_pageFlag = (APPCLASSPAGEFLAG)sqlQuery.value(3).toInt();
		appClassInfo.m_sort = sqlQuery.value(4).toInt();
		appClassInfo.m_strReserved1 = sqlQuery.value(5).toString();
		appClassInfo.m_strReserved2 = sqlQuery.value(6).toString();
		appClassInfoList << appClassInfo;
	}
	return true;
}


/*//////////////////////////////////////////////////////////////////

* Function��alterClassAppInfo

* Description�� �޸Ĺ�ϵ��

* Input���޸ĵ�Ӧ��id���޸ĵķ���id

* Output���Ƿ�ɹ�

* Others:

* ���ߣ�Tohn

* ���ڣ�2018-09-03 13:13:00

//////////////////////////////////////////////////////////////////*/
bool AppCenterDatabase::alterClassAppInfo(QString appId, QString classId, int sort)
{
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	//if (sqlQuery.isActive()) sqlQuery.finish();
	sqlQuery.prepare(QString("replace into ClassAppInfo values(?, ?, ?, ?, ?);"));
	sqlQuery.bindValue(0, app_userInfo.m_strUserId);
	sqlQuery.bindValue(1, appId);
	sqlQuery.bindValue(2, classId);
	sqlQuery.bindValue(3, sort);
	sqlQuery.bindValue(4, app_userInfo.m_strCompanyId);
	if (!sqlQuery.exec())
	{
		qDebug() << "zcd-0x0000000D:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	return true;
}


bool AppCenterDatabase::findClassAppInfo(QString strClassId, QStringList &appIdList)
{
	QReadLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	QString execStr;
	
	
	
	
	
	if (app_userInfo.m_strCompanyId == "")
	{
		execStr = QString("select *from ClassAppInfo where userId = ? AND classId = ?;");
		sqlQuery.prepare(execStr);
		sqlQuery.bindValue(0, app_userInfo.m_strUserId);
		sqlQuery.bindValue(1, strClassId);

	}
	else
	{
		execStr = QString("select *from ClassAppInfo where userId = ? AND classId = ? AND compId = ?;");
		sqlQuery.prepare(execStr);
		sqlQuery.bindValue(0, app_userInfo.m_strUserId);
		sqlQuery.bindValue(1, strClassId);
		sqlQuery.bindValue(2, app_userInfo.m_strCompanyId);
	}




	if (!sqlQuery.exec(execStr))
	{
		qDebug() << "zcd-0x00000053:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	while (sqlQuery.next())
	{
		QString appId  = sqlQuery.value(1).toString();
		if (!appId.isEmpty())
		{
			appIdList << appId;
		}
	}
	return true;

}


//Ӧ�� 
/*//////////////////////////////////////////////////////////////////

* Function��alterApp

* Description�� �޸�Ӧ�� replace �����޸� �������

* Input���޸ĵ�Ӧ������

* Output���Ƿ�ɹ�

* Others:

* ���ߣ�Tohn

* ���ڣ�2018-09-03 10:04:00

//////////////////////////////////////////////////////////////////*/
bool AppCenterDatabase::alterApp(AppDataInfo appDataInfo)
{
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	QString strSql;
	if (app_userInfo.m_strCompanyId == "")
	strSql = QString("select * from App where  userId = '%1' AND appId = '%2';").arg(app_userInfo.m_strUserId).arg(appDataInfo.m_strAppId);
	else
	strSql= QString("select * from App where  userId = '%1' AND appId = '%2' AND reserved1 = '%3';").arg(app_userInfo.m_strUserId).arg(appDataInfo.m_strAppId).arg(app_userInfo.m_strCompanyId);
	if (!sqlQuery.exec(strSql))
	{
		qDebug() << "zcd-0x00000054:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		sqlQuery.finish();
		return false;
	}

	if (sqlQuery.next())
	{
		sqlQuery.finish();
		sqlQuery.prepare("update App set  appName=?, appAlias=?,appIconPath=?, appIconDownUrl=?,"
			"appDownloadUrl=?, appExecName=?, appParams=?, appSort=?, appType=?, appIsDefaultWeb=?,"
			"appFree=? ,appVipList=? , appVipNameList=?, appVipEndTimeList = ?, appSize=?, appDownloadNumber=?,"
			"appCreatTimer=?, appUpdateSpecification=?, appOnLineVerson=?,appIsForceUpdate=?, appDesc=?,"
			"appUpdateTime=?, experienceTime=?, enExperienceTime=?, appPaidTime = ?, bindingPhone=?, reserved2=? where userId = ? AND appId = ? AND reserved1 = ?;");
	}
	else
	{
		sqlQuery.finish();
		sqlQuery.prepare("replace into App( appName, appAlias,appIconPath, appIconDownUrl,"
			"appDownloadUrl, appExecName, appParams, appSort, appType, appIsDefaultWeb,"
			"appFree ,appVipList , appVipNameList, appVipEndTimeList, appSize, appDownloadNumber,"
			" appCreatTimer, appUpdateSpecification, appOnLineVerson,appIsForceUpdate, appDesc,"
			"appUpdateTime, experienceTime, enExperienceTime, appPaidTime, bindingPhone, reserved2,  userId, appId, reserved1)"
			"values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);"); // 28 ��
	}

	sqlQuery.bindValue(0, appDataInfo.m_strAppName);
	sqlQuery.bindValue(1, appDataInfo.m_strAppAlias);
	sqlQuery.bindValue(2, appDataInfo.m_strAppIconPath);
	sqlQuery.bindValue(3, appDataInfo.m_strAppIconDownUrl);

	sqlQuery.bindValue(4, appDataInfo.m_strAppDownloadUrl);
	sqlQuery.bindValue(5, appDataInfo.m_strAppExecName);
	sqlQuery.bindValue(6, appDataInfo.m_strAppParams);
	sqlQuery.bindValue(7, appDataInfo.m_intAppSort);
	sqlQuery.bindValue(8, appDataInfo.m_bAppType);

	sqlQuery.bindValue(9, appDataInfo.m_bAppIsDefaultWeb);
	sqlQuery.bindValue(10, appDataInfo.m_strAppFree);
	sqlQuery.bindValue(11, appDataInfo.m_strListAppVipList.join("#"));
	sqlQuery.bindValue(12, appDataInfo.m_strListAppVipNameList.join("#"));
	sqlQuery.bindValue(13, appDataInfo.m_vipEndTimeList.join("#"));
	sqlQuery.bindValue(14, appDataInfo.m_intAppSize);

	sqlQuery.bindValue(15, appDataInfo.m_iAppDownloadNumber);
	sqlQuery.bindValue(16, appDataInfo.m_dtAppCreatTimer);
	sqlQuery.bindValue(17, appDataInfo.m_strAppUpdateSpecification);
	sqlQuery.bindValue(18, appDataInfo.m_strAppOnLineVerson);
	sqlQuery.bindValue(19, appDataInfo.m_intAppIsForceUpdate);

	sqlQuery.bindValue(20, appDataInfo.m_strAppDesc);
	sqlQuery.bindValue(21, appDataInfo.m_update_time);
	sqlQuery.bindValue(22, appDataInfo.m_experienceTime);
	sqlQuery.bindValue(23, appDataInfo.m_enExperienceTime);
	sqlQuery.bindValue(24, appDataInfo.m_enPaidTime);
	sqlQuery.bindValue(25, appDataInfo.m_isBindingPhone);
	sqlQuery.bindValue(26, appDataInfo.m_strReserved2);


	sqlQuery.bindValue(27, app_userInfo.m_strUserId);

	sqlQuery.bindValue(28, appDataInfo.m_strAppId);
	sqlQuery.bindValue(29, app_userInfo.m_strCompanyId);
	if (!sqlQuery.exec())
	{
		qDebug() << "zcd-0x0000000E:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	return true;
}

/*//////////////////////////////////////////////////////////////////

* Function��updateApp

* Description�� �޸�Ӧ�� ��������

* Input���޸ĵ�Ӧ������

* Output���Ƿ�ɹ�

* Others:

* ���ߣ�Tohn

* ���ڣ�2018-09-03 10:04:00

//////////////////////////////////////////////////////////////////*/
bool AppCenterDatabase::updateApp(AppDataInfo appDataInfo, bool isAppear, bool updateState)
{
	if (appDataInfo.m_strAppName == QString::fromLocal8Bit("��������ϵͳ - ��Ѱ�")){
		QString a;
	}
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	//sqlQuery.prepare("UPDATE  App SET appIconPath = ?,appExecPathUrl = ?, appUninstallPath = ?,appCurrentVerson = ?, appIsInstall = ? WHERE userId = ? AND appId = ? AND reserved1 = ?;");

	if (updateState){
	//�������ظ���״̬
	sqlQuery.prepare("UPDATE  App SET appIconPath = ?,appExecPathUrl = ?, appUninstallPath = ?,appCurrentVerson = ?, appIsInstall = ? , name = ? WHERE userId = ? AND appId = ? AND reserved1 = ? ;");
	
	sqlQuery.bindValue(0, appDataInfo.m_strAppIconPath);
	sqlQuery.bindValue(1, appDataInfo.m_strAppExecPathUrl);
	sqlQuery.bindValue(2, appDataInfo.m_strAppUninstallPath);
	sqlQuery.bindValue(3, appDataInfo.m_strAppCurrentVerson);
	sqlQuery.bindValue(4, appDataInfo.m_bAppIsInstall);

	//���ظ���״̬  enumtoCharArr(FLASH)
	QString statusApp;
	
		if (appDataInfo.m_statusAppButton == mapp_DOWNLOADING){
			statusApp = "mapp_DOWNLOADING";
		}if (appDataInfo.m_statusAppButton == mapp_ERROR){
			statusApp = "mapp_ERROR";
		}if (appDataInfo.m_statusAppButton == mapp_TIMEOUTERROR){
			statusApp = "mapp_TIMEOUTERROR";
		}if (appDataInfo.m_statusAppButton == mapp_FINISH){
			statusApp = "mapp_FINISH";
		}if (appDataInfo.m_statusAppButton == mapp_INSTALLFINLSH){
			statusApp = "mapp_INSTALLFINLSH";
		}if (appDataInfo.m_statusAppButton == mapp_INSTALLERROR){
			statusApp = "mapp_INSTALLERROR";
		}if (appDataInfo.m_statusAppButton == mapp_PAUSE){
			statusApp = "mapp_PAUSE";
		}if (appDataInfo.m_statusAppButton == mapp_CLOSE){
			statusApp = "mapp_CLOSE";
		}
	

		sqlQuery.bindValue(5, statusApp);

	sqlQuery.bindValue(6, app_userInfo.m_strUserId);
	sqlQuery.bindValue(7, appDataInfo.m_strAppId);
	sqlQuery.bindValue(8, app_userInfo.m_strCompanyId);

	}
else{
	sqlQuery.prepare("UPDATE  App SET appIconPath = ?,appExecPathUrl = ?, appUninstallPath = ?,appCurrentVerson = ?, appIsInstall = ? WHERE userId = ? AND appId = ? AND reserved1 = ? ;");
	sqlQuery.bindValue(0, appDataInfo.m_strAppIconPath);
	sqlQuery.bindValue(1, appDataInfo.m_strAppExecPathUrl);
	sqlQuery.bindValue(2, appDataInfo.m_strAppUninstallPath);
	sqlQuery.bindValue(3, appDataInfo.m_strAppCurrentVerson);
	sqlQuery.bindValue(4, appDataInfo.m_bAppIsInstall);
	sqlQuery.bindValue(5, app_userInfo.m_strUserId);
	sqlQuery.bindValue(6, appDataInfo.m_strAppId);
	sqlQuery.bindValue(7, app_userInfo.m_strCompanyId);
}




	if (!sqlQuery.exec())
	{
		qDebug() << "zcd-0x0000000F:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	if (isAppear)
		appearApp(appDataInfo.m_strAppId, appDataInfo.m_bAppIsInstall ? 1 : 2);
	return true;
}

bool AppCenterDatabase::appearApp(QString appId, int isInstall)
{
	//�����������ݿⲻ�ü���
	return ServerDatabase::GetInstance()->insertAppOper(app_userInfo.m_strUserId, app_userInfo.m_strToken, appId, app_userInfo.m_strCompanyId, app_userInfo.m_strHzsId, isInstall);
}



/*//////////////////////////////////////////////////////////////////

* Function��updateAppPaidTime

* Description�� ���ĸ���Ӧ�õĵ���ʱ��

* Input��Ӧ��Id ����ʱ��

* Output���Ƿ�ɹ�

* Others:

* ���ߣ�Tohn

* ���ڣ�2018-10-21 19:21:00

//////////////////////////////////////////////////////////////////*/
bool AppCenterDatabase::updateAppPaidTime(QString appId, int paidTime, bool isPaid)
{
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	if (isPaid)
		sqlQuery.prepare("UPDATE  App SET appPaidTime = ? WHERE userId = ? AND appId = ? AND reserved1 = ?;");
	else
		sqlQuery.prepare("UPDATE  App SET enExperienceTime = ? WHERE userId = ? AND appId = ? AND reserved1 = ?;");
	sqlQuery.bindValue(0, QString::number(paidTime));
	sqlQuery.bindValue(1, app_userInfo.m_strUserId);
	sqlQuery.bindValue(2, appId);
	sqlQuery.bindValue(3, app_userInfo.m_strCompanyId);

	if (!sqlQuery.exec())
	{
		m_appCenterSqlDatabase.commit();
		if (isPaid)
			qDebug() << "zcd-0x00000010:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		else
			qDebug() << "zcd-0x00000011:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	m_appCenterSqlDatabase.commit();
	return true;
}

/*//////////////////////////////////////////////////////////////////

* Function��removeApp

* Description��  ɾ��һ��Ӧ��  �����¼�Ӧ��  ����ǰ��ȡ�����ĺ�Ƚ϶���� Ӧ��

* Input����Ҫɾ����Ӧ��id

* Output���Ƿ�ɹ�

* Others:

* ���ߣ�Tohn

* ���ڣ�2018-09-03 10:05:00

//////////////////////////////////////////////////////////////////*/
bool AppCenterDatabase::removeApp(QString appId)
{
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	QString exestr;

	if (app_userInfo.m_strCompanyId == "")
	exestr = QString("delete from App where userId = '%1' AND appID = '%2';").arg(app_userInfo.m_strUserId).arg(appId);
	else
	exestr = QString("delete from App where userId = '%1' AND appID = '%2' AND reserved1 = '%3';").arg(app_userInfo.m_strUserId).arg(appId).arg(app_userInfo.m_strCompanyId);
	if (!sqlQuery.exec(exestr))
	{
		qDebug() << "zcd-0x00000012:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}

	if (app_userInfo.m_strCompanyId == "")
		exestr = QString("delete from ClassAppInfo where userId = '%1' AND appId = '%2';").arg(app_userInfo.m_strUserId).arg(appId);
	else
		exestr = QString("delete from ClassAppInfo where userId = '%1' AND appId = '%2' AND compId = '%3';").arg(app_userInfo.m_strUserId).arg(appId).arg(app_userInfo.m_strCompanyId);



	if (!sqlQuery.exec(exestr))
	{
		qDebug() << "zcd-0x00000013:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	return true;
}

bool AppCenterDatabase::updateAppInstallStatus(QString appId, bool status)
{
	//������ ������
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();

	sqlQuery.prepare("update App set appIsInstall = ? where userId = ? AND appId = ? AND reserved1 = ?;");
	sqlQuery.bindValue(0, status);
	sqlQuery.bindValue(1, app_userInfo.m_strUserId);
	sqlQuery.bindValue(2, appId);
	sqlQuery.bindValue(3, app_userInfo.m_strCompanyId);
	if (!sqlQuery.exec())
	{
		qDebug() << "zcd-0x00000055:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	return true;
}



/*//////////////////////////////////////////////////////////////////

* Function��findClassAppList

* Description��  ��ѯһ�������Ӧ��

* Input��Ӧ����������

* Output���Ƿ�ɹ�

* Others:

* ���ߣ�Tohn

* ���ڣ�2018-09-03 11:37:00

//////////////////////////////////////////////////////////////////*/
bool AppCenterDatabase::findClassAppList(QList<AppDataInfo > &appDataInfoList, QString classId, int cutPage, QString findStr, bool isInstall)
{
	QReadLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	QString execStr;
	if (classId.isEmpty())
	{
		
		if (app_userInfo.m_strCompanyId=="")
		execStr = QString("select *from App where userId = '%1'").arg(app_userInfo.m_strUserId);
		else
		execStr = QString("select *from App where userId = '%1' AND reserved1 = '%2' ").arg(app_userInfo.m_strUserId).arg(app_userInfo.m_strCompanyId);
		if (isInstall)  execStr.append("AND appIsInstall = 1 ");
		if (!findStr.isEmpty())
		{
			execStr.append(QString("AND (appName GLOB '*%1*' OR appAlias  GLOB '*%2*') ").arg(findStr).arg(findStr));
		}
		execStr.append(" order by appSort asc,appId desc");
	}
	else
	{
		if (app_userInfo.m_strCompanyId == "")
			execStr = QString("select * from  App as a inner join ClassAppInfo as i on i.appId = a.appId AND a.userId = i.userId where a.userId = '%1' AND i.classId = '%2'").arg(app_userInfo.m_strUserId).arg(classId);
		else
			execStr = QString("select * from  App as a inner join ClassAppInfo as i on i.appId = a.appId AND i.compId = a.reserved1 AND a.userId = i.userId where a.userId = '%1' AND i.classId = '%2' AND i.compId = '%3' ").arg(app_userInfo.m_strUserId).arg(classId).arg(app_userInfo.m_strCompanyId);


		//select * from goods as g inner join goods_classes as gc on g.sid = gc.goodsID where 


		if (isInstall)  execStr.append("AND a.appIsInstall = 1 ");
		execStr.append(" order by i.sort asc,a.appId desc");
	}
	
	if (cutPage)
		execStr.append(QString(" LIMIT  %1 * 10,10").arg(cutPage - 1));
	execStr.append(";");
	if (!sqlQuery.exec(execStr))
	{
		qDebug() << "zcd-0x00000002:" << sqlQuery.lastError() <<  QString::fromLocal8Bit("��ѯһ������Ӧ��ʧ��").toStdString().c_str();
		return false;
	}
	while (sqlQuery.next())
	{
		for (int i = 0; i < 34; i++){
			QVariant v=sqlQuery.value(i);
			qDebug() << v;
		}

		AppDataInfo appDataInfo;
		appDataInfo.mStrAppCateId = classId;
		appDataInfo.m_strAppId = sqlQuery.value(1).toString();					//Ӧ��id
		appDataInfo.m_strAppName = sqlQuery.value(2).toString();				//Ӧ������
		appDataInfo.m_strAppAlias = sqlQuery.value(3).toString();				//Ӧ�ñ���
		appDataInfo.m_strAppIconPath = sqlQuery.value(4).toString();			//Ӧ�ñ���ͼ��·��
		appDataInfo.m_strAppIconDownUrl = sqlQuery.value(5).toString();			//Ӧ��ͼ�����ص�ַ

		appDataInfo.m_strAppDownloadUrl = sqlQuery.value(6).toString();
		appDataInfo.m_strAppExecName = sqlQuery.value(7).toString();			//Ӧ�õ�ִ������
		appDataInfo.m_strAppExecPathUrl = sqlQuery.value(8).toString();			//Ӧ�õ�ִ��·��(cs����·�� bs�ķ��ʵ�ַ)
		appDataInfo.m_strAppUninstallPath = sqlQuery.value(9).toString();		//Ӧ�õ�ж��·��
		appDataInfo.m_strAppParams = sqlQuery.value(10).toString();				//ִ�в���

		appDataInfo.m_intAppSort = sqlQuery.value(11).toInt();					//Ӧ�õ�˳��
		appDataInfo.m_bAppType = sqlQuery.value(12).toBool();					//Ӧ������ cs/bs
		appDataInfo.m_bAppIsDefaultWeb = sqlQuery.value(13).toBool();			//�Ƿ�Ĭ���������
		appDataInfo.m_strAppFree = sqlQuery.value(14).toString();					//Ӧ�õļ۸�
		appDataInfo.m_strListAppVipList = sqlQuery.value(15).toString().split("#");		//vip�ȼ�����
		if (appDataInfo.m_strListAppVipList.size() == 1)
		{
			//�п���  Ϊ��  ��Ϊ  split �������ַ��� ����1
			if (appDataInfo.m_strListAppVipList.at(0).isEmpty())
				appDataInfo.m_strListAppVipList.clear();
		}
		appDataInfo.m_strListAppVipNameList = sqlQuery.value(16).toString().split("#");//vip�ȼ���������
		appDataInfo.m_vipEndTimeList = sqlQuery.value(17).toString().split("#");		//vip�ȼ�����
		if (appDataInfo.m_vipEndTimeList.size() == 1)
		{
			//�п���  Ϊ��  ��Ϊ  split �������ַ��� ����1
			if (appDataInfo.m_vipEndTimeList.at(0).isEmpty())
				appDataInfo.m_vipEndTimeList.clear();
		}


		appDataInfo.m_intAppSize = sqlQuery.value(18).toInt();				//�����С
		appDataInfo.m_iAppDownloadNumber = sqlQuery.value(19).toInt();			//Ӧ�����ش���
		appDataInfo.m_dtAppCreatTimer = sqlQuery.value(20).toDateTime();		//Ӧ�ô���ʱ��
		appDataInfo.m_strAppUpdateSpecification = sqlQuery.value(21).toString();//����˵��

		appDataInfo.m_strAppOnLineVerson = sqlQuery.value(22).toString();		//���ϰ汾
		appDataInfo.m_strAppCurrentVerson = sqlQuery.value(23).toString();		//��ǰ�汾
		appDataInfo.m_intAppIsForceUpdate = sqlQuery.value(24).toInt();			//�Ƿ�ǿ�Ƹ���
		appDataInfo.m_bAppIsInstall = sqlQuery.value(25).toBool();				//Ӧ���Ƿ�װ
		appDataInfo.m_strAppDesc = sqlQuery.value(26).toString();				//Ӧ�ü��

		appDataInfo.m_update_time = sqlQuery.value(27).toInt();


		appDataInfo.m_enPaidTime = sqlQuery.value(28).toString();
		if (!appDataInfo.m_enPaidTime.isEmpty())
		{
			appDataInfo.m_enPaidTime = appDataInfo.m_enPaidTime;//appPaidTime
			bool ok;
			appDataInfo.m_enPaidTime.toInt(&ok);
			if (!ok) appDataInfo.m_enPaidTime = "-1";
		}
		else
		{
			appDataInfo.m_enPaidTime = "-1";
		}
		appDataInfo.m_enExperienceTime = sqlQuery.value(29).toString();
		if (!appDataInfo.m_enExperienceTime.isEmpty())
		{
			appDataInfo.m_enExperienceTime = appDataInfo.m_enExperienceTime;//m_enExperienceTime
			bool ok;
			appDataInfo.m_enExperienceTime.toInt(&ok);
			if (!ok) appDataInfo.m_enExperienceTime = "-1";
		}
		else
		{
			appDataInfo.m_enExperienceTime = "-1";
		}
		appDataInfo.m_experienceTime = sqlQuery.value(30).toString();
		if (!appDataInfo.m_experienceTime.isEmpty())
		{
			appDataInfo.m_experienceTime = appDataInfo.m_experienceTime;//m_experienceTime
			bool ok;
			appDataInfo.m_experienceTime.toInt(&ok);
			if (!ok) appDataInfo.m_experienceTime = "-1";
		}
		else
		{
			appDataInfo.m_experienceTime = "-1";
		}
		
		appDataInfo.m_isBindingPhone = sqlQuery.value(31).toBool();
		appDataInfo.m_strReserved1 = sqlQuery.value(32).toString();		
		appDataInfo.m_strReserved2 = sqlQuery.value(33).toString();

		QString stausApp = sqlQuery.value(34).toString();

		if (appDataInfo.m_strAppName == QString::fromLocal8Bit("��������ϵͳ - ��Ѱ�")){
			QString a;
		}

		if (!stausApp.isEmpty()){
			if (stausApp == "mapp_DOWNLOADING"){
				appDataInfo.m_statusAppButton = mapp_DOWNLOADING;
			}if (stausApp == "mapp_ERROR"){
				appDataInfo.m_statusAppButton = mapp_ERROR;
			}if (stausApp == "mapp_TIMEOUTERROR"){
				appDataInfo.m_statusAppButton = mapp_TIMEOUTERROR;
			}if (stausApp == "mapp_FINISH"){
				appDataInfo.m_statusAppButton = mapp_FINISH;
			}if (stausApp == "mapp_INSTALLFINLSH"){
				appDataInfo.m_statusAppButton = mapp_INSTALLFINLSH;
			}if (stausApp == "mapp_INSTALLERROR"){
				appDataInfo.m_statusAppButton = mapp_INSTALLERROR;
			}if (stausApp == "mapp_PAUSE"){
				appDataInfo.m_statusAppButton = mapp_PAUSE;
			}if (stausApp == "mapp_CLOSE"){
				appDataInfo.m_statusAppButton = mapp_CLOSE;
			}
		}
		else{
			appDataInfo.m_statusAppButton = mapp_INSTALLFINLSH;
			}
		
		if (app_userInfo.isHideNR)
		{
			if (appDataInfo.m_strAppName == QString::fromLocal8Bit("��Ʊ���") || appDataInfo.m_strAppName == QString::fromLocal8Bit("��װ��Ʊ"))
				continue;
		}
		appDataInfoList << appDataInfo;

	}
	return true;
}


bool AppCenterDatabase::findApp(AppDataInfo &appDataInfo)
{
	QReadLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	QString execStr;

	if (app_userInfo.m_strCompanyId == "")
		QString("select * from  App  where userId = '%1' AND appId = '%2';").arg(app_userInfo.m_strUserId).arg(appDataInfo.m_strAppId);
	else
		QString("select * from  App  where userId = '%1' AND appId = '%2' AND reserved1 = '%3';").arg(app_userInfo.m_strUserId).arg(appDataInfo.m_strAppId).arg(app_userInfo.m_strCompanyId);

	
	if (!sqlQuery.exec(execStr))
	{
		qDebug() << "zcd-0x00000014:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	if (sqlQuery.next())
	{
		appDataInfo.m_strAppId = sqlQuery.value(1).toString();					//Ӧ��id
		appDataInfo.m_strAppName = sqlQuery.value(2).toString();				//Ӧ������
		appDataInfo.m_strAppAlias = sqlQuery.value(3).toString();				//Ӧ�ñ���
		appDataInfo.m_strAppIconPath = sqlQuery.value(4).toString();			//Ӧ�ñ���ͼ��·��
		appDataInfo.m_strAppIconDownUrl = sqlQuery.value(5).toString();			//Ӧ��ͼ�����ص�ַ

		appDataInfo.m_strAppDownloadUrl = sqlQuery.value(6).toString();
		appDataInfo.m_strAppExecName = sqlQuery.value(7).toString();			//Ӧ�õ�ִ������
		appDataInfo.m_strAppExecPathUrl = sqlQuery.value(8).toString();			//Ӧ�õ�ִ��·��(cs����·�� bs�ķ��ʵ�ַ)
		appDataInfo.m_strAppUninstallPath = sqlQuery.value(9).toString();		//Ӧ�õ�ж��·��
		appDataInfo.m_strAppParams = sqlQuery.value(10).toString();				//ִ�в���

		appDataInfo.m_intAppSort = sqlQuery.value(11).toInt();					//Ӧ�õ�˳��
		appDataInfo.m_bAppType = sqlQuery.value(12).toBool();					//Ӧ������ cs/bs
		appDataInfo.m_bAppIsDefaultWeb = sqlQuery.value(13).toBool();			//�Ƿ�Ĭ���������
		appDataInfo.m_strAppFree = sqlQuery.value(14).toString();//Ӧ�õļ۸�
		appDataInfo.m_strListAppVipList = sqlQuery.value(15).toString().split("#");	//vip�ȼ�����
		if (appDataInfo.m_strListAppVipList.size() == 1)
		{
			//�п���  Ϊ��  ��Ϊ  split �������ַ��� ����1
			if (appDataInfo.m_strListAppVipList.at(0).isEmpty())
				appDataInfo.m_strListAppVipList.clear();
		}

		appDataInfo.m_strListAppVipNameList = sqlQuery.value(16).toString().split("#");//vip�ȼ���������
		appDataInfo.m_vipEndTimeList = sqlQuery.value(17).toString().split("#");		//vip�ȼ�����
		if (appDataInfo.m_vipEndTimeList.size() == 1)
		{
			//�п���  Ϊ��  ��Ϊ  split �������ַ��� ����1
			if (appDataInfo.m_vipEndTimeList.at(0).isEmpty())
				appDataInfo.m_vipEndTimeList.clear();
		}


		appDataInfo.m_intAppSize = sqlQuery.value(18).toInt();				//�����С
		appDataInfo.m_iAppDownloadNumber = sqlQuery.value(19).toInt();			//Ӧ�����ش���
		appDataInfo.m_dtAppCreatTimer = sqlQuery.value(20).toDateTime();		//Ӧ�ô���ʱ��
		appDataInfo.m_strAppUpdateSpecification = sqlQuery.value(21).toString();//����˵��

		appDataInfo.m_strAppOnLineVerson = sqlQuery.value(22).toString();		//���ϰ汾
		appDataInfo.m_strAppCurrentVerson = sqlQuery.value(23).toString();		//��ǰ�汾
		appDataInfo.m_intAppIsForceUpdate = sqlQuery.value(24).toInt();			//�Ƿ�ǿ�Ƹ���
		appDataInfo.m_bAppIsInstall = sqlQuery.value(25).toBool();				//Ӧ���Ƿ�װ
		appDataInfo.m_strAppDesc = sqlQuery.value(26).toString();				//Ӧ�ü��

		appDataInfo.m_update_time = sqlQuery.value(27).toInt();


		appDataInfo.m_enPaidTime = sqlQuery.value(28).toString();
		if (!appDataInfo.m_enPaidTime.isEmpty())
		{
			appDataInfo.m_enPaidTime = appDataInfo.m_enPaidTime;//appPaidTime
			bool ok;
			appDataInfo.m_enPaidTime.toInt(&ok);
			if (!ok) appDataInfo.m_enPaidTime = "-1";
		}
		else
		{
			appDataInfo.m_enPaidTime = "-1";
		}
		appDataInfo.m_enExperienceTime = sqlQuery.value(29).toString();
		if (!appDataInfo.m_enExperienceTime.isEmpty())
		{
			appDataInfo.m_enExperienceTime = appDataInfo.m_enExperienceTime;//m_enExperienceTime
			bool ok;
			appDataInfo.m_enExperienceTime.toInt(&ok);
			if (!ok) appDataInfo.m_enExperienceTime = "-1";
		}
		else
		{
			appDataInfo.m_enExperienceTime = "-1";
		}
		appDataInfo.m_experienceTime = sqlQuery.value(30).toString();
		if (!appDataInfo.m_experienceTime.isEmpty())
		{
			appDataInfo.m_experienceTime = appDataInfo.m_experienceTime;//m_experienceTime
			bool ok;
			appDataInfo.m_experienceTime.toInt(&ok);
			if (!ok) appDataInfo.m_experienceTime = "-1";
		}
		else
		{
			appDataInfo.m_experienceTime = "-1";
		}

		appDataInfo.m_isBindingPhone = sqlQuery.value(31).toBool();
		appDataInfo.m_strReserved1 = sqlQuery.value(32).toString();
		appDataInfo.m_strReserved2 = sqlQuery.value(33).toString();
		return true;
	}
	return false;

}

bool AppCenterDatabase::insertSider(QList<SliderInfo > sliderInfoList)
{

	//����ǰ��ɾ��
	//����

	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	QString strSQL = QString("delete from Slider where userId = '%1' AND compId = '%2';").arg(app_userInfo.m_strUserId).arg(app_userInfo.m_strCompanyId);
	if (!sqlQuery.exec(strSQL))
	{
		qDebug() << "zcd-0x00000015:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	for each (SliderInfo sliderInfo in sliderInfoList)
	{
		sqlQuery.prepare(QString("replace into Slider values(?, ?, ?, ?, ?, ?, ?, ?, ?);"));
		sqlQuery.bindValue(0, app_userInfo.m_strUserId);
		sqlQuery.bindValue(1, sliderInfo.m_strSliderId);
		sqlQuery.bindValue(2, sliderInfo.m_strSliderImgUrl);
		sqlQuery.bindValue(3, sliderInfo.m_bSliderIsApp);
		sqlQuery.bindValue(4, sliderInfo.m_strSliderTarget);
		sqlQuery.bindValue(5, sliderInfo.m_strSliderImgPath);
		sqlQuery.bindValue(6, sliderInfo.m_bAppIsDefaultWeb);
		sqlQuery.bindValue(7, sliderInfo.sort);
		sqlQuery.bindValue(8, app_userInfo.m_strCompanyId);
		if (!sqlQuery.exec())
		{
			qDebug() << "zcd-0x00000056:" << "zcd-0x0000001E:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
			return false;
		}
	}
	return true;

}

bool AppCenterDatabase::findSider(QList<SliderInfo > &sliderInfoList)
{
	//��ѯ�ֲ�ͼ
	QReadLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	QString	execStr;
	if (app_userInfo.m_strCompanyId == "")
	execStr = QString("select *from Slider where userId = '%1'order by sort desc;").arg(app_userInfo.m_strUserId);
	else
	execStr= QString("select *from Slider where userId = '%1' AND compId = '%2' order by sort desc;").arg(app_userInfo.m_strUserId).arg(app_userInfo.m_strCompanyId);

	if (!sqlQuery.exec(execStr))
	{
		qDebug() << "zcd-0x0000001F:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	while (sqlQuery.next())
	{
		SliderInfo sliderInfo;
		sliderInfo.m_strSliderId = sqlQuery.value(1).toString();
		sliderInfo.m_strSliderImgUrl = sqlQuery.value(2).toString();
		sliderInfo.m_bSliderIsApp = sqlQuery.value(3).toBool();
		sliderInfo.m_strSliderTarget = sqlQuery.value(4).toString();
		sliderInfo.m_strSliderImgPath = sqlQuery.value(5).toString();
		sliderInfo.m_bAppIsDefaultWeb = sqlQuery.value(5).toBool();
		sliderInfo.sort = sqlQuery.value(6).toInt();

		sliderInfoList << sliderInfo;
	}
	return true;
}

//�޸�Ӧ��ͼ��
bool AppCenterDatabase::updateIconPath(QString strIcon, QString appId)
{
	QSqlError lastError;
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	sqlQuery.prepare("update App set appIconPath = ? where userId = ? AND appId = ? AND reserved1 = ?;");
	sqlQuery.bindValue(0, strIcon);
	sqlQuery.bindValue(1, app_userInfo.m_strUserId);
	sqlQuery.bindValue(2, appId);
	sqlQuery.bindValue(3, app_userInfo.m_strCompanyId);

	if (!sqlQuery.exec())
	{
		lastError = sqlQuery.lastError();
		qDebug() << "zcd-0x0000003A:" << "updateIconPath App" << lastError << lastError.driverText().toStdString().c_str();
		m_appCenterSqlDatabase.commit();
		return false;
	}
	return true;
}

bool AppCenterDatabase::removeOneSue(QString strAppId)
{
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	QString exeStr;
	if (app_userInfo.m_strCompanyId == "")
		exeStr = QString("delete from Sue where userId = '%1' AND appId = '%2';").arg(app_userInfo.m_strUserId).arg(strAppId);
	else
		exeStr = QString("delete from Sue where userId = '%1' AND appId = '%2' AND compId = '%3';").arg(app_userInfo.m_strUserId).arg(strAppId).arg(app_userInfo.m_strCompanyId);


	if (!sqlQuery.exec(exeStr))
	{
		qDebug() << "zcd-0x00000016:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	return true;

}

bool AppCenterDatabase::removeAppAllClassAll(QString strUserId)
{
	QSqlError lastError;
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	//App
	QString exeStr;
	if (app_userInfo.m_strCompanyId == "")
	{
		exeStr = QString("delete from  App  where userId = ?;");
		sqlQuery.prepare(exeStr);
		sqlQuery.bindValue(0, strUserId);
	}
	else
	{
		exeStr = QString("delete from  App  where userId = ? AND reserved1 = ?;");
		sqlQuery.prepare(exeStr);
		sqlQuery.bindValue(0, strUserId);
		sqlQuery.bindValue(1, app_userInfo.m_strCompanyId);

	}
	
	
	if (!sqlQuery.exec(exeStr))
	{
		lastError = sqlQuery.lastError();
		qDebug() << "zcd-0x0000003B:" << "zcd-0x00000021:" << "removeAppAllClassAll App" << lastError << lastError.driverText().toStdString().c_str();
		m_appCenterSqlDatabase.commit();
		return false;
	}
	m_appCenterSqlDatabase.commit();
	//Class


	if (app_userInfo.m_strCompanyId == "")
	{
		exeStr = QString("delete from Class where userId = ?;");
		sqlQuery.prepare(exeStr);
		sqlQuery.bindValue(0, strUserId);
	}
	else
	{
		exeStr = QString("delete from Class where userId = ? AND reserved1 = ?;");
		sqlQuery.prepare(exeStr);
		sqlQuery.bindValue(0, strUserId);
		sqlQuery.bindValue(1, app_userInfo.m_strCompanyId);

	}


	if (!sqlQuery.exec())
	{
		lastError = sqlQuery.lastError();
		qDebug() << "zcd-0x0000003C:" << "removeAppAllClassAll Class" << lastError << lastError.driverText().toStdString().c_str();
		m_appCenterSqlDatabase.commit();
		return false;
	}
	m_appCenterSqlDatabase.commit();
	//ClassAppInfo


	if (app_userInfo.m_strCompanyId == "")
	{
		exeStr = QString("delete from ClassAppInfo  where userId = ?;");
		sqlQuery.prepare(exeStr);
		sqlQuery.bindValue(0, strUserId);
	}
	else
	{
		exeStr = QString("delete from ClassAppInfo  where userId = ? AND compId = ? ; ");
		sqlQuery.prepare(exeStr);
		sqlQuery.bindValue(0, strUserId);
		sqlQuery.bindValue(1, app_userInfo.m_strCompanyId);

	}


	if (!sqlQuery.exec())
	{
		lastError = sqlQuery.lastError();
		qDebug() << "zcd-0x0000003D:" << "removeAppAllClassAll ClassAppInfo" << lastError << lastError.driverText().toStdString().c_str();
		m_appCenterSqlDatabase.commit();
		return false;
	}
	m_appCenterSqlDatabase.commit();
	return true;
}

bool AppCenterDatabase::changeAppCenterUserId(QString strOldUserId, QString strNewUserId)
{
	QSqlError lastError;
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);


	QString execStr;


	if (app_userInfo.m_strCompanyId == "")
	{
		execStr = QString("update App set userId= ? where userId = ?;");
		sqlQuery.prepare(execStr);
		sqlQuery.bindValue(0, strNewUserId);
		sqlQuery.bindValue(1, strOldUserId);

	}
	else
	{
		execStr = QString("update App set userId= ? where userId = ? AND reserved1 = ?; ");
		sqlQuery.prepare(execStr);
		sqlQuery.bindValue(0, strNewUserId);
		sqlQuery.bindValue(1, strOldUserId);
		sqlQuery.bindValue(2, app_userInfo.m_strCompanyId);
	}

	//App


	if (!sqlQuery.exec(execStr))
	{
		lastError = sqlQuery.lastError();
		qDebug() << "zcd-0x0000003E:" << "changeAppCenterUserId App" << lastError << lastError.driverText().toStdString().c_str();
		m_appCenterSqlDatabase.commit();
		//return false;
	}
	m_appCenterSqlDatabase.commit();


	if (app_userInfo.m_strCompanyId == "")
	{
		execStr = QString("update Class set userId= ? where userId = ?;");
		sqlQuery.prepare(execStr);
		sqlQuery.bindValue(0, strNewUserId);
		sqlQuery.bindValue(1, strOldUserId);

	}
	else
	{
		execStr = QString("update Class set userId= ? where userId = ? AND reserved1 = ?; ");
		sqlQuery.prepare(execStr);
		sqlQuery.bindValue(0, strNewUserId);
		sqlQuery.bindValue(1, strOldUserId);
		sqlQuery.bindValue(2, app_userInfo.m_strCompanyId);
	}



	//Class
	

	if (!sqlQuery.exec(execStr))
	{
		lastError = sqlQuery.lastError();
		qDebug() << "zcd-0x0000003F:" << "changeAppCenterUserId Class" << lastError << lastError.driverText().toStdString().c_str();
		m_appCenterSqlDatabase.commit();
		//return false;
	}
	m_appCenterSqlDatabase.commit();

	if (app_userInfo.m_strCompanyId == "")
	{
		execStr = QString("update ClassAppInfo set userId= ? where userId = ?;");
		sqlQuery.prepare(execStr);
		sqlQuery.bindValue(0, strNewUserId);
		sqlQuery.bindValue(1, strOldUserId);

	}
	else
	{
		execStr = QString("update ClassAppInfo set userId= ? where userId = ? AND reserved1 = ?; ");
		sqlQuery.prepare(execStr);
		sqlQuery.bindValue(0, strNewUserId);
		sqlQuery.bindValue(1, strOldUserId);
		sqlQuery.bindValue(2, app_userInfo.m_strCompanyId);
	}

	//ClassAppInfo
	

	if (!sqlQuery.exec(execStr))
	{
		lastError = sqlQuery.lastError();
		qDebug() << "zcd-0x00000040:" << "changeAppCenterUserId ClassAppInfo" << lastError << lastError.driverText().toStdString().c_str();
		m_appCenterSqlDatabase.commit();
		//return false;
	}
	m_appCenterSqlDatabase.commit();
	//Slider

	if (app_userInfo.m_strCompanyId == "")
	{
		execStr = QString("update Slider set userId= ? where userId = ?;");
		sqlQuery.prepare(execStr);
		sqlQuery.bindValue(0, strNewUserId);
		sqlQuery.bindValue(1, strOldUserId);

	}
	else
	{
		execStr = QString("update Slider set userId= ? where userId = ? AND reserved1 = ?; ");
		sqlQuery.prepare(execStr);
		sqlQuery.bindValue(0, strNewUserId);
		sqlQuery.bindValue(1, strOldUserId);
		sqlQuery.bindValue(2, app_userInfo.m_strCompanyId);
	}

	

	if (!sqlQuery.exec())
	{
		lastError = sqlQuery.lastError();
		qDebug() << "zcd-0x00000041:" << "changeAppCenterUserId Slider" << lastError << lastError.driverText().toStdString().c_str();
		m_appCenterSqlDatabase.commit();
		//return false;
	}
	m_appCenterSqlDatabase.commit();
	//Sue

	
	if (app_userInfo.m_strCompanyId == "")
	{
		execStr = QString("update Sue set userId=? where userId = ?;");
		sqlQuery.prepare(execStr);
		sqlQuery.bindValue(0, strNewUserId);
		sqlQuery.bindValue(1, strOldUserId);

	}
	else
	{
		execStr = QString("update Sue set userId = ? where userId = ? AND compId = ? ; ");
		sqlQuery.prepare(execStr);
		sqlQuery.bindValue(0, strNewUserId);
		sqlQuery.bindValue(1, strOldUserId);
		sqlQuery.bindValue(2, app_userInfo.m_strCompanyId);
	}
	if (!sqlQuery.exec(execStr))
	{
		lastError = sqlQuery.lastError();
		qDebug() << "zcd-0x00000042:" << "changeAppCenterUserId Sue" << lastError << lastError.driverText().toStdString().c_str();
		m_appCenterSqlDatabase.commit();
		return false;
	}
	m_appCenterSqlDatabase.commit();
	return true;
}

bool AppCenterDatabase::insertSue(QStringList issueStringList)
{
	QWriteLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
    

	QString execStr;
	if (app_userInfo.m_strCompanyId == "")
	{
		execStr = QString("delete from Sue where userId = '%1';").arg(app_userInfo.m_strUserId);
	}
	else
	{
		execStr = QString("delete from Sue where userId = '%1' AND compId = '%2';").arg(app_userInfo.m_strUserId).arg(app_userInfo.m_strCompanyId);
	}


	if (!sqlQuery.exec(execStr))
	{
		qDebug() << "zcd-0x00000016:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	if (sqlQuery.isActive()) sqlQuery.finish();
	for each (QString appId in issueStringList)
	{
		sqlQuery.prepare(QString("insert into Sue values(?, ?, ?);"));
		sqlQuery.bindValue(0, app_userInfo.m_strUserId);
		sqlQuery.bindValue(1, appId);
		sqlQuery.bindValue(2, app_userInfo.m_strCompanyId);
		if (!sqlQuery.exec())
		{
			qDebug() << "zcd-0x00000020:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
			return false;
		}
	}
	return true;
}

bool AppCenterDatabase::readSue(QStringList &issueStringList)
{
	QReadLocker locker(&m_readWriteLock);
	QSqlQuery sqlQuery(m_appCenterSqlDatabase);
	if (sqlQuery.isActive()) sqlQuery.finish();
	QString	execStr;
	
	

	if (app_userInfo.m_strCompanyId == "")
	{
		execStr = QString("select *from Sue where userId = '%1';").arg(app_userInfo.m_strUserId);		
	}
	else
	{
		execStr = QString("select *from Sue where userId = '%1' AND compId = '%2';").arg(app_userInfo.m_strUserId).arg(app_userInfo.m_strCompanyId);
	}

	if (!sqlQuery.exec(execStr))
	{
		qDebug() << "zcd-0x00000017:" << sqlQuery.lastError() << sqlQuery.lastError().driverText().toStdString().c_str();
		return false;
	}
	while (sqlQuery.next())
	{
		issueStringList << sqlQuery.value(1).toString();
	}
	return true;
}


////����
//QString AppCenterDatabase::freeAESStr(QString aesStr, QString appId)
//{
//	return aesStr;
//	QByteArray data = aesStr.toLocal8Bit();
//	data = QByteArray::fromHex(data);
//	if (ZcloudComFun::aesZhicloud(data, appId, false))
//	{
//		aesStr = QString::fromLocal8Bit(data);
//		if (aesStr.contains(appId))
//		{
//			aesStr.replace(appId, "");
//			aesStr.replace(app_userInfo.m_strUserId, "");
//			return aesStr;
//		}
//	}
//	qDebug() << "zcd-0x00000018:" << "freeAESStr  error = " << aesStr << "  appId = " << appId;
//	return "-1";
//}
//
////����
//QString   AppCenterDatabase::freeStrAEs(QString aesStr, QString appId)
//{
//	return aesStr;
//	aesStr += appId;
//	aesStr += app_userInfo.m_strUserId;
//	QByteArray data = aesStr.toLocal8Bit();
//	if (ZcloudComFun::aesZhicloud(data, appId, true))
//	{
//		QByteArray bye = data.toHex();
//		return QString::fromLocal8Bit(bye);
//	}
//	return "-1";
//}