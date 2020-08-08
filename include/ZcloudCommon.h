#ifndef ZCLOUDCOMMON_H
#define ZCLOUDCOMMON_H

#include <QString>
#include <QWidget>
#include <QLabel>
namespace ZcloudComFun
{
	enum EN_BTN_TYPE
	{
		EN_CLOSE = 0,		//!只一个关闭按钮
		EN_OKCANCEL = 1,	//!确认取消按钮
		ZEN_UPDATE = 2,		//!升级、不升级按钮
		EN_BINDING = 3,		//绑定税号
		EN_TIP = 4,			//失败的提示
	};



	extern "C" __declspec(dllexport) void LoadAvatar(const std::string &strAvatarUrl, QLabel* lable);

	//!提示框
	extern "C" __declspec(dllexport) int openMessageTipDlg(EN_BTN_TYPE enBtnType, QString strTitle, QString strMsg, QWidget *parent = 0);

	//!提示框
	extern "C" __declspec(dllexport) int openMessageTipDlg_2(EN_BTN_TYPE enBtnType, QString strTitle, QString strMsg, QString buttonStr_1, QString tuttonStr_2, QWidget *parent = 0);

	//!http调用
	extern "C" __declspec(dllexport) bool httpPost(QString strUrl, QString strPost, int nTimeout, QString& strRet, bool isCheckToken = false,int _type = 0);
	//判定token
	extern "C" __declspec(dllexport) bool winHttpSSO(QString strToken, QString strUserId);

	//!从url下载图片
	 __declspec(dllexport) QString downloadIconFromUrl(QString strUrl, QString strDirPath, QString strAppId = "");

	//!下载3次图片
	 __declspec(dllexport) QString downloadPic(QString strUrl, QString strDirPath);

	 //!检测联网
	 extern "C" __declspec(dllexport) bool isNetActive();
	 
	 //读取开票软件是否存在  
	 extern "C" __declspec(dllexport)  bool readsoft(QString &verSion, QString taxNumber = "");
	 extern "C" __declspec(dllexport)  bool qtReadsoft(QString &verSion, QString taxNumber = "");

	 //获取开票软件信息
	 extern "C" __declspec(dllexport) bool getSoftwareData(QString &url, QString &verson_hszId, QString tax_number = "");

	 //获取公网Ip
	 __declspec(dllexport) QString GetNetIP(QString &province, QString &city);

	 //!获取云财税版本号
	 __declspec(dllexport) QString getFileVertion(QString fullName);

	//isOnAesUncrypt = false 解密   反之加密
	 extern "C" __declspec(dllexport) bool aesZhicloud(QByteArray &ytestr, QString strKey, bool isOnAesUncrypt);

	 //!获取本地mac地址
	 __declspec(dllexport) QString getHostMacAddress();

	 //!获取本机操作系统版本
	 __declspec(dllexport) QString getOsVer();
	 __declspec(dllexport) QString getOsVerQt();

	 //!获取api接口主域名
	 __declspec(dllexport) QString getHostName();

	 //!获取wv页面Url(参数eg:uid,token,“wv/wallpaper/index")
	 __declspec(dllexport) QString getWvUrl(QString strUid, QString strtoken, QString strFun);

	 //!获取顶栏工具链接
	 __declspec(dllexport) QString getTopToolUrl(QString strUid, QString strtoken, QString strFun);

	 //!服务启动客户端机制 
	 enum EN_REBOOT_TYPE
	 {
		 EN_NOREBOOT		= 0,	//!不重启（登陆关闭、更新关闭）
		 EN_REBOOT_PARAMS	= 1,	//!参数重启（只启动心跳的模式）
	 };
	 extern "C" __declspec(dllexport) void writeRegReboot(EN_REBOOT_TYPE enType);

	 //开票软件已存在读取开票软件
	 bool readSoftV(QString &verSion, QString tax_number);

	 //获取税号
	 __declspec(dllexport) QString getTaxnumber();

	 bool getPublicIp(QString& ip);

	 __declspec(dllexport) void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);
};
#endif // ZCLOUDCOMMON_H


