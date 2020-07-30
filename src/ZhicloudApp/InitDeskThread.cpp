#include "InitDeskThread.h"
#include "AppDatabase/AppCenterDatabase.h"
#include "AppCommFun.h"
#include "AppHttpInterface.h"
#include <QDebug>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QApplication>
#include <QSettings>
#include "ZcloudCommon.h"
#include "RightClassAppWidget.h"
#include "Database.h"

extern UserInfoStruct app_userInfo;

//初始化 桌面线程
InitDeskThread::InitDeskThread(QObject *parent)
	: QThread(parent)
{
}

InitDeskThread::~InitDeskThread()
{

}

void InitDeskThread::run()
{
	QString strIniPath = QApplication::applicationDirPath();
	QSettings settings(strIniPath + "/config.ini", QSettings::IniFormat);
	int timeUp = 100;
	if (settings.contains("conf/appUpdateInterval")) 
		timeUp = settings.value("conf/appUpdateInterval").toInt();


	int last_update_time = 0;
	m_emitFlag = false;
	while (isRunningFlag)
	{
		if (!isUpdateApp(last_update_time) && m_emitFlag)
		{
			if (!m_emitFlag)
			{
				m_emitFlag = true;
				emit initDeskSuccess(true);
				is_flush_succeed = true;
			}
			//qsrand(10);
			//timeUp = qrand() % 100;
			for (int i = 0; i < timeUp && isRunningFlag; i++)
			{
				sleep(6);
			}
			//如果没刷新成功is_flush_succeed 被设置为false; 
			if (!is_flush_succeed)
			{
				emit initDeskSuccess(true);
				is_flush_succeed = true;
			}
			updateIconPath();
			continue;
		}
		qDebug() << "start getClass---------------------------;";
	
		oldAppIdUpTimeMap.clear();
		newAppIdUpTimeMap.clear();
		//储存 存在的 分类id
		oldCateIdList.clear();
		newCateIdList.clear();
		//发布到桌面的应用
		issueStringList.clear();
		//桌面已安装应用
		deskAppStringList.clear();

		getDateTime();
		getOldAppData();
		if (!isRunningFlag) return;
		//获取右侧应用
		if (!getAllClass())
		{
			emit initDeskSuccess(false);
			m_emitFlag = true;
			//如果接口出现错误， 下次还要重新更新
			if (last_update_time) last_update_time--;
			continue;
		}

		//获取轮播图
		if (!isRunningFlag) return;
		if (!getSlideshow())
		{
			emit initDeskSuccess(false);
			m_emitFlag = true;
			if (last_update_time) last_update_time--;
			continue;
		}

		if (!isRunningFlag) return;
		if (!upAppData())
		{
			emit initDeskSuccess(false);
			m_emitFlag = true;
			if (last_update_time) last_update_time--;
			continue;
		}

		//更新了到期时间刷新右侧避免右侧刷新不及时得问题
		//V2.1.30.180828
		//V2.1.30.180625

		//是否要重新更新  桌面信息
		bool isUpdateDeskTOp = false;
		//删除多余的分类
		foreach(QString cateId, oldCateIdList)
		{
			if (!newCateIdList.contains(cateId))
			{
				//删除了分类
				AppCenterDatabase::instance()->removeClass(cateId);
				isUpdateDeskTOp = true;
			}
		}


		//删除多余的应用
		QMapIterator<QString, int> item(oldAppIdUpTimeMap);
		while (item.hasNext()) {
			item.next();
			QString appId = item.key();
			if (!newAppIdUpTimeMap.contains(appId))
			{
				//删除了应用
				AppCenterDatabase::instance()->removeApp(appId);
				//如果 sue有数据也需要删除
				QStringList oldIssueStringList;
				if (AppCenterDatabase::instance()->readSue(oldIssueStringList))
				{
					if (oldIssueStringList.contains(appId))
					{
						AppCenterDatabase::instance()->removeOneSue(appId);
					}
				}
				isUpdateDeskTOp = true;
			}
		}


		//if (isUpdateDeskTOp || (oldCateIdList.size() < newCateIdList.size()) || (oldAppIdUpTimeMap.size() < newAppIdUpTimeMap.size()))
		//{
		//	emit initDeskSuccess(true);
		//	emitFlag = true;
		//}
		//存储发布到桌面的 应用
		//issueStringList
		QStringList oldIssueStringList;
		if (AppCenterDatabase::instance()->readSue(oldIssueStringList))
		{
			for each (QString appId in oldIssueStringList)
			{
				//如果是发布到桌面，用户没有点击过，后台取消掉发布到桌面 客户端也需要对应的删除
				if (!issueStringList.contains(appId))
				{
					//待处理,删除发布到桌面的应用，修改对应的应用的安装状态，
					AppCenterDatabase::instance()->removeOneSue(appId);
					AppCenterDatabase::instance()->updateAppInstallStatus(appId, false);
				}
			}
		}
		if (!AppCenterDatabase::instance()->insertSue(issueStringList))
		{

		}
		//if (!emitFlag)
		//{
		//	emit initDeskSuccess(true);
		//}
		emit initDeskSuccess(true);
		m_emitFlag = true;
		updateIconPath();
	}
}


bool InitDeskThread::isUpdateApp(int &last_update_time)
{
	AppHttpInterface	severface;
	QString	strResult = "";
	if (!severface.WinHttpGetAppStatus(app_userInfo.m_strUserId, app_userInfo.m_strToken, last_update_time, strResult))
	{
		qDebug() << "zcd-0x00000080:" << "WinHttpGetAppStatus Error";
		return false;
	}
	QByteArray byte_array = strResult.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		qDebug() << "zcd-0x0000007E:" << "json error:" << strResult;
		return   false;
	}

	if (!parse_doucment.isObject())
	{
		qDebug() << "zcd-0x0000007F:" << "json error:" << strResult;
		return false;;
	}

	QJsonObject obj = parse_doucment.object();
	int code = obj.take("status").toInt();
	if (code != 0)
	{
		qDebug() << "zcd-0x00000081:" << "code error:" << QString::number(code);
		httpCodeError(code);
		return false;
	}
	QJsonValue data = obj.take("data");
	if (!data.isObject())
		return false;
	QJsonObject isUpdateObject = data.toObject();
	last_update_time = isUpdateObject.take("last_update_time").toInt();
	return isUpdateObject.take("update_status").toInt();
}

void InitDeskThread::getDateTime()
{
	AppHttpInterface	severface;
	int currentTime = 0;
	QString	strResult = "";
	if (severface.WinHttpGetSystemTime(strResult))
	{


		QByteArray byte_array = strResult.toUtf8();
		QJsonParseError json_error;
		QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
		if (json_error.error == QJsonParseError::NoError && parse_doucment.isObject())
		{
			QJsonObject obj = parse_doucment.object();
			int code = obj.take("status").toInt();
			if (code == 0)
			{
				QJsonValue data = obj.take("data");
				if (data.isObject())
				{
					QJsonObject timeJson = data.toObject();
					currentTime = timeJson.take("time").toInt();

				}
			}
		}
	}
	if (currentTime == 0)
	{
		currentTime = QDateTime::currentDateTime().toTime_t();
	}
	RightClassAppWidget *ptr = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance());
	if (ptr)
		ptr->m_currentTime = currentTime;

	//{"status":0, "data" : {"time":1538981107}}
}


void InitDeskThread::getOldAppData()
{
	QList<AppDataInfo> oldAppDataInfoList;
	QList<AppClassInfo> oldAppClassInfoList;
	AppCenterDatabase::instance()->findClassAppList(oldAppDataInfoList);
	AppCenterDatabase::instance()->findAppClassList(oldAppClassInfoList);

	oldAppIdUpTimeMap.clear();
	oldCateIdList.clear();
	newAppIdUpTimeMap.clear();
	newCateIdList.clear();
	for each (AppDataInfo var in oldAppDataInfoList)
	{
		oldAppIdUpTimeMap.insert(var.m_strAppId, var.m_update_time);
	}
	for each (AppClassInfo var in oldAppClassInfoList)
	{
		oldCateIdList << var.m_strClassId;
	}
}


bool InitDeskThread::getAllClass()
{
	QString	strResult;
	AppHttpInterface	severface;
	if (!severface.WinHttpGetAllClassInfo(app_userInfo.m_strUserId, app_userInfo.m_strToken, strResult))
	{
		qDebug() << "zcd-0x00000024:" << "can not get local desktop app";
		return false;
	}

	QByteArray byte_array = strResult.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		qDebug() << "zcd-0x0000002A:" << "json error:" << strResult;
		return   false;
	}

	if (!parse_doucment.isObject())
	{
		qDebug() << "zcd-0x0000002B:" << "json error:" << strResult;
		return false;;
	}

	QJsonObject obj = parse_doucment.object();
	int code = obj.take("status").toInt();
	if (code != 0)
	{
		qDebug() << "zcd-0x0000002C:" << "code error:" << QString::number(code);
		httpCodeError(code);
		return false;
	}
	QJsonValue data = obj.take("data");
	if (!data.isObject())
		return false;

	//"user_apps 用户应用
	//"store_apps 应用中心
	//"topic_apps 专题应用 
	// "special_apps_hot 热门应用
	//"special_apps_recommend 推荐应用
	QJsonObject allClassObject = data.toObject();
	QJsonValue user_apps_value = allClassObject.take("user_apps");
	QJsonValue store_apps_value = allClassObject.take("store_apps");
	QJsonValue topic_apps_value = allClassObject.take("topic_apps");
	QJsonValue special_apps_hot_value = allClassObject.take("special_apps_hot");
	QJsonValue special_apps_recommend_value = allClassObject.take("special_apps_recommend");

	if (analysisJson(user_apps_value, CLASSDESK) && analysisJson(store_apps_value, CLASSCENTER) && analysisJson(topic_apps_value, CLASSHOME) &&
		analysisJson(special_apps_hot_value, CLASSHOT) && analysisJson(special_apps_recommend_value, CLASSRECOMMEND))
	{
		return true;
	}
	return false;
}



bool InitDeskThread::upAppData()
{
	QStringList updateAppidList;
	QStringList addAppList;
	QMapIterator<QString, int> i(newAppIdUpTimeMap);
	while (i.hasNext()) {
		i.next();
		QString appId = i.key();
		int dateTime = i.value();
		if (oldAppIdUpTimeMap.contains(appId))
		{
			if (oldAppIdUpTimeMap.value(appId) < dateTime)
			{
				updateAppidList.append(appId);
			}
		}
		else{
			addAppList.append(appId);
		}
	}

	if (updateAppidList.size() == 0 && addAppList.size() == 0) {
		//emit initDeskSuccess(true);
		return true;
	}
	QString	strResult;
	AppHttpInterface	severface;
	if (!severface.WinHttpGetAppInfoList(app_userInfo.m_strUserId, app_userInfo.m_strToken, (updateAppidList + addAppList).join(","), strResult))
	{
		qDebug() << "zcd-0x00000026:" << "can not get local desktop app";
		return false;
	}


	QByteArray byte_array = strResult.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		qDebug() << "zcd-0x00000027:" << "json error:" << strResult;
		return   false;
	}

	if (!parse_doucment.isObject())
	{
		qDebug() << "zcd-0x00000028:" << "json error:" << strResult;
		return false;;
	}

	QJsonObject obj = parse_doucment.object();
	int code = obj.take("status").toInt();
	if (code != 0)
	{
		qDebug() << "zcd-0x00000029:" << "code error:" << QString::number(code);
		httpCodeError(code);
		return false;
	}
	QJsonValue data = obj.take("data");
	if (!data.isArray())
		return false;

	QJsonArray jsonDataArray = data.toArray();
	int nSize = jsonDataArray.size();

	for (int nIndex = 0; nIndex < nSize; ++nIndex)
	{
		AppDataInfo appDataInfo;
		QJsonObject appJsonObject = jsonDataArray.at(nIndex).toObject();
		appDataInfo.m_strAppId = appJsonObject.take("app_id").toString();
		appDataInfo.m_strAppIconDownUrl = appJsonObject.take("icon").toString();

		//QString downloadIconName = "";
		//if (!appDataInfo.m_strAppIconDownUrl.isEmpty())
		//{
		//	QFileInfo info(QUrl::fromUserInput(appDataInfo.m_strAppIconDownUrl).path());
		//	downloadIconName = info.baseName();
		//}

		appDataInfo.m_strAppIconPath = AppCommFun::downloadIcon(appDataInfo.m_strAppIconDownUrl, appDataInfo.m_strAppId);
		//ZcloudComFun::downloadIconFromUrl(appDataInfo.m_strAppIconDownUrl, QApplication::applicationDirPath() + "\\CacheImage\\appImage");
		if (appDataInfo.m_strAppIconPath.isEmpty())
			appDataInfo.m_strAppIconPath = ":/new/imageFile/photoError.png";
		appDataInfo.m_strAppName = appJsonObject.take("app_name").toString();

		appDataInfo.m_strAppAlias = appJsonObject.take("alias_name").toString();
		appDataInfo.m_bAppType = (appJsonObject.take("app_type").toInt() == 1 ? true : false);
		appDataInfo.m_strAppDownloadUrl = appJsonObject.take("url").toString();
		appDataInfo.m_strAppOnLineVerson = appJsonObject.take("version").toString();
		appDataInfo.m_intAppSize = appJsonObject.take("size").toInt();

		appDataInfo.m_strAppDesc = appJsonObject.take("introduce").toString();
		appDataInfo.m_strAppUpdateSpecification = appJsonObject.take("update_introduce").toString();
		//appDataInfo.m_strAppFree = (appJsonObject.take("charging_state").toInt() ? appJsonObject.take("free").toDouble() : 0
		appDataInfo.m_strAppFree = QString::number(appJsonObject.take("charging_state").toInt());

		appDataInfo.m_strAppParams = (appJsonObject.take("allow_send_third_party").toInt() ? appJsonObject.take("send_third_party_params").toString() : "");
		appDataInfo.m_bAppIsDefaultWeb = appJsonObject.take("is_default_browser").toInt();

		appDataInfo.m_strAppExecName = appJsonObject.take("execution_path").toString();
		appDataInfo.m_intAppIsForceUpdate = appJsonObject.take("update_method").toInt();
		appDataInfo.m_intAppSort = appJsonObject.take("sort").toInt();

		appDataInfo.m_update_time = appJsonObject.take("update_time").toInt();
		appDataInfo.m_dtAppCreatTimer = QDateTime::fromTime_t(appJsonObject.take("create_time").toInt());
		appDataInfo.m_experienceTime = appJsonObject.take("tryout_times").toString();
		if (appDataInfo.m_experienceTime.isEmpty()) appDataInfo.m_experienceTime = "0";
		appDataInfo.m_isBindingPhone = appJsonObject.take("trigger_register").toInt();

		appDataInfo.m_enPaidTime = QString::number(appJsonObject.take("paid_expireTime").toInt());		//到期时间
		appDataInfo.m_enExperienceTime = QString::number(appJsonObject.take("try_expireTime").toInt());		//试用结束时间

		QJsonValue memberValue = appJsonObject.take("member_grade_list");
		if (memberValue.isArray())
		{
			QJsonArray memberArray = memberValue.toArray();
			for (int i = 0; i < memberArray.size(); i++)
			{
				QJsonObject memberObj = memberArray.at(i).toObject();
				QString vipId = memberObj.take("member_grade_id").toString();
				QString vipName = memberObj.take("member_name").toString();
				QString vipEndTime = memberObj.take("member_end_time").toString();
				if (!vipId.isEmpty())
				{
					appDataInfo.m_strListAppVipList.append(vipId);
					appDataInfo.m_strListAppVipNameList.append(vipName);
					appDataInfo.m_vipEndTimeList.append(vipEndTime);
				}
			}
		}


		QJsonValue desktopCateValue = appJsonObject.take("category_list");
		if (desktopCateValue.isArray())
		{
			//删除该应用的关系表  go to removeclassAppInfo_class
			AppCenterDatabase::instance()->removeClassAppInfo_Class(appDataInfo.m_strAppId);
			QJsonArray desktopCateArray = desktopCateValue.toArray();
			for (int i = 0; i < desktopCateArray.size(); i++)
			{
				QJsonObject desktopCateObj = desktopCateArray.at(i).toObject();
				QString cateId = desktopCateObj.take("category_id").toString();
				QString cateName = desktopCateObj.take("category_name").toString();
				int sort = desktopCateObj.take("app_sort").toInt();
				if (!cateId.isEmpty())
				{
					//插入关系表
					if (!AppCenterDatabase::instance()->alterClassAppInfo(appDataInfo.m_strAppId, cateId, sort))
					{
						return false;
					}
				}
			}
		}

		//插入一个应用
		if (!AppCenterDatabase::instance()->alterApp(appDataInfo))
		{
			return false;
		}


		//如果是发布到桌面 或者本地不存在且属于桌面应用 就 修改应用的安装状态 为已安装
		if (issueStringList.contains(appDataInfo.m_strAppId) || (addAppList.contains(appDataInfo.m_strAppId) && deskAppStringList.contains(appDataInfo.m_strAppId)))
		{
			appDataInfo.m_bAppIsInstall = true;
			if (!appDataInfo.m_bAppType && !appDataInfo.m_strAppDownloadUrl.isEmpty())//cs  应用
			{
				// cs应用查询路径
				bool isNew = false;
				AppCommFun::isHaveNewVerson(appDataInfo, isNew);
			}
			if (issueStringList.contains(appDataInfo.m_strAppId))
			{
				//如果是发布到桌面 不上报服务器 用户点击了 才上报
			}
			if (!AppCenterDatabase::instance()->updateApp(appDataInfo))
			{
				return false;
			}
		}
	}
	return true;
}



bool InitDeskThread::analysisJson(const QJsonValue jsonValue, APPCLASSPAGEFLAG flag)
{
	QJsonArray jsonDataArray = jsonValue.toArray();
	int nSize = jsonDataArray.size();

	for (int nIndex = 0; nIndex < nSize; ++nIndex)
	{
		QJsonObject valueO = jsonDataArray.at(nIndex).toObject();
		AppClassInfo	pClassInfo;
		pClassInfo.m_strClassId = valueO.take("category_id").toString();
		pClassInfo.m_pageFlag = flag;
		pClassInfo.m_strClassName = valueO.take("category_name").toString();
		pClassInfo.m_sort = valueO.take("sort").toInt();
		QJsonArray child = valueO.take("app_list").toArray();
		if (pClassInfo.m_strClassId.isEmpty())
		{
			qDebug() << "zcd-0x0000002D:" << "classId = NULL";
			continue;
		}

		//插入一个分类
		if (!AppCenterDatabase::instance()->insertClass(pClassInfo))
		{
			return false;
		}

		for (int i = 0; i < child.size(); i++)
		{
			QJsonObject appJsonObject = child.at(i).toObject();

			QString appId = appJsonObject.take("app_id").toString();
			int timeT = appJsonObject.take("update_time").toInt();
			int sort = appJsonObject.take("app_sort").toInt();
			if (appId.isEmpty())	{
				continue;
			}
			newAppIdUpTimeMap.insert(appId, timeT);

			//已安装的应用
			if (CLASSDESK == flag)
			{
				//发布到桌面
				if (!appJsonObject.take("state").toInt())
				{
					//某个应用 删除发布到都某个分类 存在某个关系表不会被删除 问题  会在go to removeclassAppInfo这 重新初始化关系表
					if (!issueStringList.contains(appId))
						issueStringList.append(appId);
				}
				else
				{
					//用于本地不存在 修改安装状态为 已安装
					deskAppStringList.append(appId);
				}
			}
			if (appId.isEmpty())
			{
				qDebug() << "zcd-0x0000002E:" << "appId = NULL!!";
				continue;
			}
			//插入一个关系表 由于没有app_sort字段  所以去掉 在应用详情中增加
			if (!AppCenterDatabase::instance()->alterClassAppInfo(appId, pClassInfo.m_strClassId, sort))
			{
				return false;
			}

			if (!newAppIdUpTimeMap.contains(appId))
				newAppIdUpTimeMap.insert(appId, timeT);
		}

		if (!newCateIdList.contains(pClassInfo.m_strClassId))
			newCateIdList.append(pClassInfo.m_strClassId);
	}
	return true;
}


bool InitDeskThread::getSlideshow()
{
	//轮播图
	AppHttpInterface	severface;
	QString	strResult = "";
	if (!severface.WinHttpGetAppStoreRotationPic(app_userInfo.m_strUserId, app_userInfo.m_strToken, strResult))
	{
		return false;
	}
	QByteArray byte_array = strResult.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError || !parse_doucment.isObject())
	{
		qDebug() << "zcd-0x00000030:" << " get Store Rotation json error:" << strResult;
		return false;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("status").toInt();
	if (status != 0)
	{
		httpCodeError(status);
		return false;
	}
	QJsonArray data = obj.take("data").toArray();
	int photoSize = data.size();
	QList<SliderInfo> sliderInfoList;
	for (int j = 0; j < photoSize; j++)
	{
		SliderInfo sliderInfo;
		QJsonObject json = data.at(j).toObject();
		sliderInfo.m_strSliderId = json.take("slider_id").toString();
		sliderInfo.m_strSliderImgUrl = json.take("img_url").toString();
		sliderInfo.m_bSliderIsApp = json.take("type").toInt() == 1 ? false : true;
		sliderInfo.m_strSliderTarget = json.take("target").toString();
		sliderInfo.m_bAppIsDefaultWeb = json.take("is_default_browser").toInt();
		sliderInfo.sort = json.take("sort").toInt();
		sliderInfo.m_strSliderImgPath = AppCommFun::downloadIcon(sliderInfo.m_strSliderImgUrl);
		sliderInfoList << sliderInfo;
	}
	if (sliderInfoList.size() == 0) return true;
	if (!AppCenterDatabase::instance()->insertSider(sliderInfoList))
	{
		return false;
	}
	return true;
}

void InitDeskThread::httpCodeError(int code)
{
	if (code == -1)
	{
		//token 过期 重新登录
	}
	else if (code == -2)
	{
		//单点登录 提醒用户
	}
	else
	{

	}
}


//图片下载  缓存-备份-错误     updateIconPath线程统一下载 更新（防止 抢占网络慢数据库让 界面卡死）
void InitDeskThread::updateIconPath()
{
	//下载图片
	bool isUpdateIcon = false;
	QList<AppDataInfo > updateAppList;
	if (AppCenterDatabase::instance()->findClassAppList(updateAppList))
	{
		foreach(AppDataInfo pData, updateAppList)
		{
			QString iconDoanloadUrl = pData.m_strAppIconDownUrl;
			QString iconStr = pData.m_strAppIconPath;
			QFileInfo fileInfo(iconStr);
			if (iconStr.contains("photoError") || iconStr.isEmpty() || !fileInfo.exists())
			{
				QString downIconStr = AppCommFun::downloadIcon(iconDoanloadUrl, pData.m_strAppId);
				if (!downIconStr.isEmpty()/* && downIconStr != iconStr*/)
				{
					if (!AppCenterDatabase::instance()->updateIconPath(downIconStr, pData.m_strAppId))
					{
						if (isUpdateIcon)
						{
							emit flashButton();
						}
						return;
					}
					isUpdateIcon = true;
				}
			}
		}
	}
	if (isUpdateIcon)
	{
		emit flashButton();
	}
}























//
////force_update  vision_name
//bool InitDeskThread::initDatabase(QString	cateId, int pageId)
//{
//	if (!isRunningFlag) return true;
//	AppHttpInterface	severface;
//	QString	strJson;
//	if (!severface.WinHttpGetApplistByCateId(app_userInfo.m_strUserId, app_userInfo.m_strToken, app_userInfo.m_strHzsId, cateId, pageId, strJson))
//	{
//		qDebug() << "zcd-0x00000033:" << "initDatabase error";
//		return  false;
//	}
//
//	QByteArray byte_array = strJson.toLatin1();
//	QJsonParseError json_error;
//	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
//	if (json_error.error != QJsonParseError::NoError)
//	{
//		qDebug() << "zcd-0x00000034:" << "initDatabase json error:" << strJson;
//		return false;
//	}
//
//	if (!parse_doucment.isObject())
//	{
//		qDebug() << "zcd-0x00000035:" << "init Database json error:" << strJson;
//		return false;
//	}
//
//	QJsonObject obj = parse_doucment.object();
//
//	int code = obj.take("code").toInt();
//	QString message = obj.take("message").toString();
//	if (code != 200 || message != "ok")
//	{
//		qDebug() << "zcd-0x00000036:" << "init Database code error:" << QString::number(code);
//		return false;
//	}
//	QJsonObject data = obj.take("data").toObject();
//	QString strInstallNum = data.take("installNum").toString();
//	QString strTotalNum = data.take("totalNum").toString();
//	QString strCurPageNum = data.take("p").toString();
//	QString strCountPageNum = data.take("pt").toString();
//
//	int curPage = strCurPageNum.toInt();
//	int totolCate = strCountPageNum.toInt();
//
//	QJsonValue jsonValue = data.take("app");
//	if (!jsonValue.isArray())
//	{
//		qDebug() << "zcd-0x00000037:" << "init Database json error:" << strJson;
//		return false;
//	}
//
//	QJsonArray app = jsonValue.toArray();
//
//	if (AppCenterDatabase::instance()->insertClassApp(app, newAppIdUpTimeMap))
//	{
//		if (curPage < totolCate)
//		{
//			if (!initDatabase(cateId, curPage + 1))
//				return false;
//		}
//	}
//	return true;
//}





