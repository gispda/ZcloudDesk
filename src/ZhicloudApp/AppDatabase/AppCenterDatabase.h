#pragma once

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QReadWriteLock>
#include "ZhicloudAppDataDefine.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>


class AppCenterDatabase : public QObject
{
	Q_OBJECT

public:
	static AppCenterDatabase *instance()
	{
		if (!m_appCenterDatabase)
		{
			m_appCenterDatabase = new AppCenterDatabase();
		}
		return m_appCenterDatabase;
	};

	//分类
	/*//////////////////////////////////////////////////////////////////

	* Function：insertClass

	* Description： 插入分类

	* Input：无

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-08-21 11:37:00

	//////////////////////////////////////////////////////////////////*/
	bool insertClass(AppClassInfo appClassInfo);


	/*//////////////////////////////////////////////////////////////////

	* Function：removeClassAppInfo

	* Description： 删除一个分类的关系表

	* Input：无

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2019-03-3 18:37:00

	//////////////////////////////////////////////////////////////////*/
	bool removeClassAppInfo(QString strClassId);

	/*//////////////////////////////////////////////////////////////////

	* Function：removeClassAppInfo_Class

	* Description： 删除该应用关系表

	* Input：删除的应用id

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2019-03-05 16:03:00

	//////////////////////////////////////////////////////////////////*/
	bool removeClassAppInfo_Class(QString appId);

	/*//////////////////////////////////////////////////////////////////

	* Function：removeClass

	* Description：删除一个分类

	* Input：分类id

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-08-21 11:37:00

	//////////////////////////////////////////////////////////////////*/
	bool removeClass(QString classId);

	/*//////////////////////////////////////////////////////////////////

	* Function：findAppClassList

	* Description： 查询所有分类

	* Input：无

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-09-03 10:03:00

	//////////////////////////////////////////////////////////////////*/
	bool findAppClassList(QList<AppClassInfo> &appClassInfoList, APPCLASSPAGEFLAG = CLASSALL);


	//应用 
	/*//////////////////////////////////////////////////////////////////

	* Function：alterApp

	* Description： 修改应用 replace 有则修改 无则添加

	* Input：修改的应

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-09-03 10:04:00

	//////////////////////////////////////////////////////////////////*/
	bool alterApp(AppDataInfo appDataInfo);



	/*//////////////////////////////////////////////////////////////////

	* Function：updateApp

	* Description： 修改应用 本地数据 

	* Input：修改的应用数据 

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-09-14 12:49:00

	//////////////////////////////////////////////////////////////////*/
	bool updateApp(AppDataInfo appDataInfo, bool isAppear = false);

	/*//////////////////////////////////////////////////////////////////

	* Function：appearApp

	* Description： 上报服务器 应用的安装状态  1安装应用 2卸载应用 3开始试用

	* Input： isInstall 状态   appId 应用id

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-09-27 18:37:00

	//////////////////////////////////////////////////////////////////*/
	bool appearApp(QString appId, int isInstall);

	/*//////////////////////////////////////////////////////////////////

	* Function：updateAppPaidTime

	* Description： 更改付费应用的到期时间

	* Input：应用Id 到期时间 isPaid：true付费应用到期时间 false:试用应用到期时间

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-10-21 19:21:00

	//////////////////////////////////////////////////////////////////*/
	bool updateAppPaidTime(QString appId, int paidTime, bool isPaid = true);


	/*//////////////////////////////////////////////////////////////////

	* Function：alterClassAppInfo

	* Description： 修改关系表

	* Input：修改的应用id，修改的分类id

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-09-03 13:13:00

	//////////////////////////////////////////////////////////////////*/
	bool alterClassAppInfo(QString appId, QString classId, int sort);




	/*//////////////////////////////////////////////////////////////////

	* Function：findClassAppInfo

	* Description： 查询关系表

	* Input：分类Id

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2019-03-04 18:14:00

	//////////////////////////////////////////////////////////////////*/
	bool findClassAppInfo(QString strClassId, QStringList &appIdList);



	/*//////////////////////////////////////////////////////////////////

	* Function：removeApp

	* Description：  删除一个应用  用于下架应用  更改前读取，更改后比较多余的 应用

	* Input：需要删除的应用id

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-09-03 10:05:00

	//////////////////////////////////////////////////////////////////*/
	bool removeApp(QString appId);

	/*//////////////////////////////////////////////////////////////////

	* Function：updateAppInstallStatus

	* Description：  更改应用的安装状态

	* Input：需要更改的应用id， 安装还是卸载

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2019-02-25 23:05:00

	//////////////////////////////////////////////////////////////////*/
	bool updateAppInstallStatus(QString appId, bool status);



	/*//////////////////////////////////////////////////////////////////

	* Function：findClassAppList

	* Description：  查询一个分类的一个用 如果classId 为空则查询所有的应用

	* Input：应用详情链表  isInstall:true 查询已安装的（桌面管理使用） false:不用管

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-09-03 11:37:00

	//////////////////////////////////////////////////////////////////*/
	bool findClassAppList(QList<AppDataInfo > &appDataInfoList, QString classId = "", int cutPage = 0, QString findStr = "", bool isInstall = false);


	/*//////////////////////////////////////////////////////////////////

	* Function：findApp

	* Description： 查询一个应用

	* Input：应用详情  appInfo.id 为要查询的id

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-09-17 10:54:00

	//////////////////////////////////////////////////////////////////*/
	bool findApp(AppDataInfo &appInfo);

	/*//////////////////////////////////////////////////////////////////

	* Function：insertSider

	* Description：  插入轮播图

	* Input：

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-09-13 19:27:00

	//////////////////////////////////////////////////////////////////*/
	bool insertSider(QList<SliderInfo > sliderInfoList);

	/*//////////////////////////////////////////////////////////////////

	* Function：findSider

	* Description：  查询轮播图

	* Input：

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-09-14 10:26:00

	//////////////////////////////////////////////////////////////////*/
	bool findSider(QList<SliderInfo > &sliderInfoList);


	/*//////////////////////////////////////////////////////////////////

	* Function：insertSue

	* Description：  存储发布到桌面的应用

	* Input：

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-09-27 15:27:00

	//////////////////////////////////////////////////////////////////*/
	bool insertSue(QStringList issueStringList);

	bool removeOneSue(QString strAppId);

	/*//////////////////////////////////////////////////////////////////

	* Function：readSue

	* Description：  读取未上报发布到桌面的应用

	* Input：

	* Output：是否成功

	* Others:

	* 作者：Tohn

	* 日期：2018-09-27 16:04:00

	//////////////////////////////////////////////////////////////////*/
	bool readSue(QStringList &issueStringList);


	//修改用户Id
	bool changeAppCenterUserId(QString strOldUserId, QString strNewUserId);

	//删除所有应用和分类
	bool removeAppAllClassAll(QString strUserId);

	//修改应用图标
	bool updateIconPath(QString strIcon, QString appId);

private:
	explicit AppCenterDatabase(QObject *parent = NULL);
	~AppCenterDatabase();
	//创建数据库	
	bool creatAppCenterDb();
	//打开数据库
	bool openAppCenterDatabase();

	bool removeAppClass(int);

	//QString freeAESStr(QString byte, QString appId);
	//QString freeStrAEs(QString aesStr, QString appId);

private:
	static AppCenterDatabase * m_appCenterDatabase;
	QReadWriteLock m_readWriteLock;
	QSqlDatabase m_appCenterSqlDatabase;
};
