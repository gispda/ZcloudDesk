#ifndef HTTPINTERFACE_H
#define HTTPINTERFACE_H

#include <QObject>

class HttpInterface : public QObject
{
	Q_OBJECT

public:
	HttpInterface(QObject *parent=0);
	~HttpInterface();

	//!税号登录
	bool winHttpLogin(QString strTaxNo,QString strUserId, QString& strRet);

	//手机号加Token登录
	bool winHttpTokneLogin(QString strModel, QString strToken, QString& strRet);

	//!账号密码登录(true) 手机登录false
	bool winHttpLogin(bool accountPhone, QString strAccount,QString strPwd, QString& strRet);

	//!获取顶栏工具
	bool winHttpGetTopToolInfo(QString strUid,QString strToken,QString& strRet);

	//!意见反馈(uid token 意见反馈分类编号 内容 联系方式 返回结果)
	bool winHttpSendFeedback(QString strUid, QString strToken, QString strType, QString strContent, QString strContactway, QString& strRet);

	//!多税号上报
	bool winHttpTaxResponse(QString strUid, QString strToken, QString strTaxs, QString& strRet);

	//!云财税版本更新
	bool winHttpGetYcsSoftware(QString strUid, QString strToken, QString& strRet);

	//发送验证码
	bool winHttpSendCode(QString phoneNumber,QString codeType, QString & strRet);
	
	//检测验证码
	bool winHttpCheckCode(QString phoneNumber, QString codeType,  QString code, QString &strRet);

	//用户注册
	bool winHttpRegister(QString phoneNumber, QString password, QString captcha,QString strSign, QString &strRet);
	
	//绑定手机
	bool  winHttpBindingPhone(QString phoneNumber, QString captcha, QString skid, QString strToken, QString strUserId, QString &strRet);
	bool  winHttpBindingPhone(QString phoneNumber, QString captcha, QString skid, QString &strRet);

	//token登录
	bool  winHttpTokenLogin(QString phoneNumber, QString strToken,QString &strRet);

	//修改密码
	bool winHttpChangePassword(QString  phoneNumber, QString password, QString codeNumber, QString &strRet);

	//获取微信二维码
	bool winHttpGetQRCode(QString strToken,QString strUserId, QString &strRet);
	
	//检查二维码扫描状态
	bool winHttpCheckScanStatus(QString strPkid, QString strToken,QString strUserId, QString &strRet);
	
	//微信绑定用户
	bool winHttpAjaxBind(QString strPkid, QString strToken, QString &strRet);

	//税号绑定手机号
	bool winHttpTaxPhoneBind(QString strMobile, QString captcha, QString strToken, QString strUserId, QString &strRet);

	//!获取服务器系统时间
	bool winHttpGetSystemTime(QString &strRet);

private:
	
};

#endif // HTTPINTERFACE_H
