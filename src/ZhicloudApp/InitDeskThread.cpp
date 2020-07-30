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

//��ʼ�� �����߳�
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
			//���ûˢ�³ɹ�is_flush_succeed ������Ϊfalse; 
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
		//���� ���ڵ� ����id
		oldCateIdList.clear();
		newCateIdList.clear();
		//�����������Ӧ��
		issueStringList.clear();
		//�����Ѱ�װӦ��
		deskAppStringList.clear();

		getDateTime();
		getOldAppData();
		if (!isRunningFlag) return;
		//��ȡ�Ҳ�Ӧ��
		if (!getAllClass())
		{
			emit initDeskSuccess(false);
			m_emitFlag = true;
			//����ӿڳ��ִ��� �´λ�Ҫ���¸���
			if (last_update_time) last_update_time--;
			continue;
		}

		//��ȡ�ֲ�ͼ
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

		//�����˵���ʱ��ˢ���Ҳ�����Ҳ�ˢ�²���ʱ������
		//V2.1.30.180828
		//V2.1.30.180625

		//�Ƿ�Ҫ���¸���  ������Ϣ
		bool isUpdateDeskTOp = false;
		//ɾ������ķ���
		foreach(QString cateId, oldCateIdList)
		{
			if (!newCateIdList.contains(cateId))
			{
				//ɾ���˷���
				AppCenterDatabase::instance()->removeClass(cateId);
				isUpdateDeskTOp = true;
			}
		}


		//ɾ�������Ӧ��
		QMapIterator<QString, int> item(oldAppIdUpTimeMap);
		while (item.hasNext()) {
			item.next();
			QString appId = item.key();
			if (!newAppIdUpTimeMap.contains(appId))
			{
				//ɾ����Ӧ��
				AppCenterDatabase::instance()->removeApp(appId);
				//��� sue������Ҳ��Ҫɾ��
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
		//�洢����������� Ӧ��
		//issueStringList
		QStringList oldIssueStringList;
		if (AppCenterDatabase::instance()->readSue(oldIssueStringList))
		{
			for each (QString appId in oldIssueStringList)
			{
				//����Ƿ��������棬�û�û�е��������̨ȡ�������������� �ͻ���Ҳ��Ҫ��Ӧ��ɾ��
				if (!issueStringList.contains(appId))
				{
					//������,ɾ�������������Ӧ�ã��޸Ķ�Ӧ��Ӧ�õİ�װ״̬��
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

	//"user_apps �û�Ӧ��
	//"store_apps Ӧ������
	//"topic_apps ר��Ӧ�� 
	// "special_apps_hot ����Ӧ��
	//"special_apps_recommend �Ƽ�Ӧ��
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

		appDataInfo.m_enPaidTime = QString::number(appJsonObject.take("paid_expireTime").toInt());		//����ʱ��
		appDataInfo.m_enExperienceTime = QString::number(appJsonObject.take("try_expireTime").toInt());		//���ý���ʱ��

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
			//ɾ����Ӧ�õĹ�ϵ��  go to removeclassAppInfo_class
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
					//�����ϵ��
					if (!AppCenterDatabase::instance()->alterClassAppInfo(appDataInfo.m_strAppId, cateId, sort))
					{
						return false;
					}
				}
			}
		}

		//����һ��Ӧ��
		if (!AppCenterDatabase::instance()->alterApp(appDataInfo))
		{
			return false;
		}


		//����Ƿ��������� ���߱��ز���������������Ӧ�� �� �޸�Ӧ�õİ�װ״̬ Ϊ�Ѱ�װ
		if (issueStringList.contains(appDataInfo.m_strAppId) || (addAppList.contains(appDataInfo.m_strAppId) && deskAppStringList.contains(appDataInfo.m_strAppId)))
		{
			appDataInfo.m_bAppIsInstall = true;
			if (!appDataInfo.m_bAppType && !appDataInfo.m_strAppDownloadUrl.isEmpty())//cs  Ӧ��
			{
				// csӦ�ò�ѯ·��
				bool isNew = false;
				AppCommFun::isHaveNewVerson(appDataInfo, isNew);
			}
			if (issueStringList.contains(appDataInfo.m_strAppId))
			{
				//����Ƿ��������� ���ϱ������� �û������ ���ϱ�
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

		//����һ������
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

			//�Ѱ�װ��Ӧ��
			if (CLASSDESK == flag)
			{
				//����������
				if (!appJsonObject.take("state").toInt())
				{
					//ĳ��Ӧ�� ɾ����������ĳ������ ����ĳ����ϵ���ᱻɾ�� ����  ����go to removeclassAppInfo�� ���³�ʼ����ϵ��
					if (!issueStringList.contains(appId))
						issueStringList.append(appId);
				}
				else
				{
					//���ڱ��ز����� �޸İ�װ״̬Ϊ �Ѱ�װ
					deskAppStringList.append(appId);
				}
			}
			if (appId.isEmpty())
			{
				qDebug() << "zcd-0x0000002E:" << "appId = NULL!!";
				continue;
			}
			//����һ����ϵ�� ����û��app_sort�ֶ�  ����ȥ�� ��Ӧ������������
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
	//�ֲ�ͼ
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
		//token ���� ���µ�¼
	}
	else if (code == -2)
	{
		//�����¼ �����û�
	}
	else
	{

	}
}


//ͼƬ����  ����-����-����     updateIconPath�߳�ͳһ���� ���£���ֹ ��ռ���������ݿ��� ���濨����
void InitDeskThread::updateIconPath()
{
	//����ͼƬ
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





