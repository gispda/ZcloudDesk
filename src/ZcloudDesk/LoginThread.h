#pragma once

#include <QThread>
#include "ZcloudCommon.h"
#include "Database.h"

class LoginThread : public QThread
{
	Q_OBJECT
public:

	enum WayEnum{
		LoginPwWay,		//账号密码登录
		LoginPaWay,		//手机验证码登录
		AuthWay,		//获取验证码
		VerifyPaWay,	//检测验证码
		ResetPwWay,		//重置密码确认
		VerifyWay,		//注册
		BindingPhoneWay,//微信绑定手机号
		BindingEin		//税号绑定手机号
	};

	LoginThread(QObject *parent = NULL);
	~LoginThread();
	void setValue(WayEnum wayEnum, QString id, QString pw, QString codeType = "");
	WayEnum getWayEnum(){ return m_wayEnum; }
	//登录 
	static int httpLogin(int bytaxFlag, QString strTaxNo_ID, QString strMachine_PW, UserInfoStruct &userInfoStruct, QString strSkid = "");
	//!检测用户头像是否存在 存在返回路径 不存在下载之后返回路径
	static QString checkLogoExist(QString strUrl);
private:
	//获取验证码
	int getCode(QString phoneNumber, QString codeType);
	//检测验证码
	int checkCode(QString phoneNumber, QString codeType, QString codeNumber);

	//用户注册
	int userRegister(QString phoneNumber, QString passWord, QString codeNumber);

	//修改密码
	int changedPassword(QString phoneNber, QString passWord, QString codeNumber);

	//手机号和税号绑定   bingdingWay = true:微信绑定   false:手机绑定
	int bindingTaxNumber(QString strMobile, QString strCaptcha, UserInfoStruct &);
	int bindingTaxNumber(QString strMobile, QString strCaptcha, QString strSkid, UserInfoStruct &);
	
	//税号 token userid 写注册表·
	static void writeRegdit(UserInfoStruct);
	//解析登录数据
	static int analySucessJson(QString strRet, UserInfoStruct &userInfoStruct);
	//验证返回成功与否
	int analyCodeSucess(QString strRet);
	//解析json 是否为未注册用户（用户手机号快捷登录）
	static bool analySucessJsonSign(QString strRet,QString &strSign);

	WayEnum m_wayEnum = LoginPwWay;
	QString m_Id;
	QString m_PW;
	QString m_codeType = "";
	//用于手机快捷登录时 未注册时 保存sign（sign 用户设置密码时用 注册接口）
	QString m_strSign = "";

	UserInfoStruct m_userInfoStruct;
signals:
	void loginSignals(int status, UserInfoStruct);
	void getFilishSignals(int status);
protected:
	void run();
};
