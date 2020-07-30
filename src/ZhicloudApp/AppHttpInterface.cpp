#include "AppHttpInterface.h"
#include "ZCloudCommon.h"
#include "AppCommFun.h"
#include <QApplication>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkProxyQuery>
#include <QNetworkReply>
#include <qt_windows.h>


AppHttpInterface::AppHttpInterface(QObject *parent)
	: QObject(parent)
{
	//m_strOtherInfo = QString("&i_=%1&d_=%2&dv_=%3&v_=V%4").arg(AppCommFun::getHostMacAddress()).arg(AppCommFun::GetOs()).arg(AppCommFun::GetOsVer()).arg(AppCommFun::getFileVertion(QApplication::applicationFilePath()));

}

AppHttpInterface::~AppHttpInterface()
{
}


bool AppHttpInterface::WinHttpGetSystemIPForApp(QString strHzsId, QString& strRet)
{
	QString strUrl = strHzsId.trimmed().isEmpty() ?
		QString("%1").arg("/YCSUserUninstallService/getSystemIPForApp/json?")
		: QString("%1&hzs_id=%2").arg("/YCSUserUninstallService/getSystemHzsForApp/json?").arg(strHzsId);

	return ZcloudComFun::httpPost(strUrl, "", 10000, strRet);
}


bool AppHttpInterface::WinHttpGetAppStoreRotationPic(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("%1&token=%2&user_id=%3").arg("/app/get-slider-list?")
		.arg(strToken).arg(strUid);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}


bool AppHttpInterface::WinHttpGetAllClassInfo(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("%1&token=%2&user_id=%3").arg("/app/get-app-store?")
		.arg(strToken).arg(strUid);
	return ZcloudComFun::httpPost(strUrl, "", 10000, strRet);
}

//bool WinHttpGetAppStatus(QString strUid, QString strToken, QString& strRet);

bool AppHttpInterface::WinHttpGetAppStatus(QString strUid, QString strToken, int last_update_time, QString& strRet)
{
	QString strUrl = QString("%1&token=%2&user_id=%3&last_update_time=%4").arg("/app/app-update-status?")
		.arg(strToken).arg(strUid).arg(last_update_time);
	return ZcloudComFun::httpPost(strUrl, "", 10000, strRet);
}

bool AppHttpInterface::WinHttpGetAppInfoList(QString strUid, QString strToken, QString applistId, QString& strRet)
{
	QString strUrl = QString("%1&token=%2&user_id=%3&app_id=%4").arg("/app/get-app-detail?")
		.arg(strToken).arg(strUid).arg(applistId);
	return ZcloudComFun::httpPost(strUrl, "", 10000, strRet);
}

bool AppHttpInterface::WinHttpGetSystemTime(QString& strRet)
{
	QString strUrl = QString("%1").arg("/general/get-server-time?");
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

















bool AppHttpInterface::WinHttpGetVipInfoByTaxCode(QString strTaxNo, QString& strRet)
{
	QString strUrl = QString("https://pay.xjhtxx.cn/xjhtxx_shop/Order/GetVipInfoByTaxCode?taxcode=%1").arg(strTaxNo);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}


bool AppHttpInterface::WinHttpGetApplistByCateId(QString strUid, QString strToken, QString strHzsId, QString strCateId, int nPage, QString& strRet)
{
	QString strUrl = QString("%1&uid=%2&token=%3&hzs_id=%4&cate_id=%5&p=%6").arg("/YCSAppStoreService/getAppMapInAppStore/json?")
		.arg(strUid).arg(strToken).arg(strHzsId).arg(strCateId).arg(nPage);
	return ZcloudComFun::httpPost(strUrl, "", 10000, strRet);
}


