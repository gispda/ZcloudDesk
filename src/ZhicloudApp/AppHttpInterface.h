#pragma once

#include <QObject>

class AppHttpInterface : public QObject
{
	Q_OBJECT

public:
	AppHttpInterface(QObject *parent = NULL);
	~AppHttpInterface();

	/************************************************************************/
	/*函数名称：	WinHttpGetAppStoreRotationPic
	/*函数功能：	获取应用中心轮播图
	/*函数参数：
	/*函数返回：	true请求响应成功，否则失败
	/************************************************************************/
	bool WinHttpGetAppStoreRotationPic(QString strUid, QString strToken, QString& strRet);
	

	/************************************************************************/
	/*函数名称：	WinHttpGetAllClassInfo
	/*函数功能：	获取所有的分类
	/*函数参数：	strUid		uid					in
	strToken	token				in
	strRet		接口返回Json字符串		out
	/*函数返回：	true请求响应成功，否则失败
	/************************************************************************/
	bool WinHttpGetAllClassInfo(QString strUid, QString strToken, QString& strRet);

	/************************************************************************/
	/*函数名称：	WinHttpGetAppStatus
	/*函数功能：	获取线上分类和应用得状态
	/*函数参数：	strUid		uid					in
	strToken	token				in
	strRet		接口返回Json字符串		out
	/*函数返回：	true请求响应成功，否则失败
	/************************************************************************/
	bool WinHttpGetAppStatus(QString strUid, QString strToken, int last_update_time, QString& strRet);
	
	
	/************************************************************************/
	/*函数名称：	WinHttpGetSystemIPForApp
	/*函数功能：	获取开票软件 最新版本
	/*函数参数：
	/*函数返回：	true请求响应成功，否则失败
	/************************************************************************/
	bool WinHttpGetSystemIPForApp(QString strHzsId, QString& strRet);


	
	/************************************************************************/
	/*函数名称：	WinHttpGetVipInfoByTaxCode
	/*函数功能：	根据税号获取VIP信息
	/*函数参数：
	/*函数返回：	true请求响应成功，否则失败
	/************************************************************************/
	bool WinHttpGetVipInfoByTaxCode(QString strTaxNo, QString& strRet);


	
	/************************************************************************/
	/*函数名称：	WinHttpGetSystemTime
	/*函数功能：	获取服务器时间
	/*函数参数：
	/*函数返回：	true请求响应成功，否则失败
	/************************************************************************/
	bool WinHttpGetSystemTime(QString& strRet);

	

	/************************************************************************/
	/*函数名称：	WinHttpGetAppInfoList
	/*函数功能：	获取应用详情
	/*函数参数：	strUid		uid			应用idlist用逗号隔开		in
	strToken	token				
	strRet		接口返回Json字符串		out
	/*函数返回：	true请求响应成功，否则失败
	/************************************************************************/
	bool WinHttpGetAppInfoList(QString strUid, QString strToken, QString applistId, QString& strRet);



	/************************************************************************/
	/*函数名称：	WinHttpGetApplistByCateId
	/*函数功能：	根据分类id查询全部所属应用（安装 未安装）
	/*函数参数：	strUid		uid						in
	strToken	token					in
	strHzsId	合作商ID					in
	strCateId	分类Id					in
	nPage		页码						in
	strRet		接口返回Json字符串			out
	/*函数返回：	true请求响应成功，否则失败
	/************************************************************************/
	bool WinHttpGetApplistByCateId(QString strUid, QString strToken, QString strHzsId, QString strCateId, int nPage, QString& strRet);

	

private:
	//QString				m_strOtherInfo;

	//!httpPost请求     url             post数据    超时检查    返回数据
	//bool  httpPost(QString url, QString post, int iTime, QString& strRet);
};
