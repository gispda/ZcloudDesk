#include "HttpInterface.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>

HttpInterface::HttpInterface(QObject *parent)
	: QObject(parent)
{

}

HttpInterface::~HttpInterface()
{

}

bool HttpInterface::winHttpLogin(QString strTaxNo, QString strUserId, QString& strRet)
{
	if (strTaxNo.isEmpty())
	{
		qDebug("zcd-0x10000004:login by tax,tax is empty!");
		return false;
	}
	QString strUrl = QString("/user/login");
	QString strPost = QString("tax_number=%1").arg(strTaxNo);
	if (!strUserId.isEmpty())
	{
		strPost.append("&user_id=").append(strUserId);
	}
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}


bool HttpInterface::winHttpTokneLogin(QString strModel, QString strToken, QString& strRet)
{
	if (strModel.isEmpty() || strToken.isEmpty())
	{
		qDebug(":winHttpTokneLogin by tax,tax is empty!");
		return false;
	}
	QString strUrl = QString("/user/login");
	QString strPost = QString("account=%1&last_token=%2").arg(strModel).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

bool HttpInterface::winHttpLogin(bool accountPhone, QString strAccount, QString strPwd, QString& strRet)
{
	if (strAccount.isEmpty() || strPwd.isEmpty())
	{
		qDebug("zcd-0x10000005:login by account,account or password is empty!");
		return false;
	}
	QString strUrl = QString("/ucenter/user/login");
	QString strPost = accountPhone ? QString("account=%1&password=%2").arg(strAccount).arg(strPwd) : QString("account=%1&captcha=%2").arg(strAccount).arg(strPwd);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet,false,1);
}

bool HttpInterface::winHttpLogin(QString strTaxNo, QString& strRet)
{

	QString strUrl = QString("/ucenter/user/get-key");
	QString strPost;

	if (strTaxNo != "")
		strPost = QString("tax=%1").arg(strTaxNo);
	else
		strPost = "";
	//if (!strUserId.isEmpty())
	//{
	//	strPost.append("&user_id=").append(strUserId);
	//}
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet,false,1);
}

bool HttpInterface::winHttpGetTopToolInfo(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/general/get-top-app-list?user_id=%1&token=%2").arg(strUid).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

bool HttpInterface::winHttpSendFeedback(QString strUid, QString strToken, QString strType, QString strContent, QString strContactway, QString& strRet)
{
	QString strUrl = QString("/user/send-feedback?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("type_id=%1&content=%2&contact_way=%3").arg(strType).arg(strContent).arg(strContactway);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

bool HttpInterface::winHttpGetYcsSoftware(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/general/get-ycs-software?user_id=%1&token=%2&os_version=%3").arg(strUid).arg(strToken).arg(ZcloudComFun::getOsVerQt());
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

bool HttpInterface::winHttpTaxResponse(QString strUid, QString strToken, QString strTaxs, QString& strRet)
{
	QString strUrl = QString("/general/tax-response?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("tax_number=%1").arg(strTaxs);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

//发送验证码
bool  HttpInterface::winHttpSendCode(QString phoneNumber, QString codeType, QString & strRet)
{
	QString strUrl = QString("/common/sms/send");
	//验证码类型(register注册,login登录,bind_mobile绑定手机,reset_mobile重置手机号,forgot_password忘记密码)
	QString strPost = QString("type=%1&mobile=%2").arg(codeType).arg(phoneNumber);
	return ZcloudComFun::httpPost(strUrl, strPost, 10000, strRet,false,1);
}

//检测验证码
bool  HttpInterface::winHttpCheckCode(QString phoneNumber, QString codeType, QString code, QString &strRet)
{
	QString strUrl = QString("/general/check-captcha");
	QString strPost = QString("mobile=%1&type=%2&check_code=%3").arg(phoneNumber).arg(codeType).arg(code);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}


//用户注册
bool  HttpInterface::winHttpRegister(QString phoneNumber, QString password, QString captcha, QString strSign, QString &strRet)
{
	QString strUrl = QString("/user/register");
	QString strPost = QString("mobile=%1&password=%2&captcha=%3").arg(phoneNumber).arg(password).arg(captcha);
	if (!strSign.isEmpty())
	{
		strPost.append("&sign=");
		strPost.append(strSign);
	}
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

//绑定手机
bool  HttpInterface::winHttpBindingPhone(QString phoneNumber, QString captcha, QString skid, QString &strRet)
{
	QString strUrl = QString("/wv/wechat/ajax-bind");
	QString strPost = QString("mobile=%1&code=%2&pkid=").arg(phoneNumber).arg(captcha) + skid;
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}
//token登录
bool  HttpInterface::winHttpTokenLogin(QString phoneNumber, QString strToken, QString &strRet)
{
	QString strUrl = QString("/user/login");
	QString strPost = QString("account=%1&last_token=%2").arg(phoneNumber).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}
//绑定 税号手机
bool  HttpInterface::winHttpBindingPhone(QString phoneNumber, QString captcha, QString skid, QString strToken, QString strUserId, QString &strRet)
{
	if (strToken.isEmpty()) return false;
	QString strUrl = QString("/wv/wechat/ajax-bind?token=%1&user_id=%2").arg(strToken).arg(strUserId);
	QString strPost = QString("mobile=%1&code=%2&pkid=%3").arg(phoneNumber).arg(captcha).arg(skid);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}


//修改密码
bool HttpInterface::winHttpChangePassword(QString  phoneNumber, QString password, QString codeNumber, QString &strRet)
{
	QString strUrl = QString("/user/edit-self");
	QString strPost = QString("mobile=%1&password=%2&captcha=%3").arg(phoneNumber).arg(password).arg(codeNumber);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

//获取二维码
bool HttpInterface::winHttpGetQRCode(QString strToken,QString userId, QString &strRet)
{
	QString strUrl = QString("/wv/wechat/get-qr-code");
	if (!strToken.isEmpty())
		strUrl.append(QString("?token=%1&user_id=%2").arg(strToken).arg(userId));
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

//检查二维码扫描状态
bool HttpInterface::winHttpCheckScanStatus(QString strPkid, QString strToken, QString strUserId, QString &strRet)
{	
	QString strUrl = QString("/wv/wechat/ajax-check-scan-status");
	if (!strToken.isEmpty())
		strUrl.append(QString("?token=%1&user_id=%2").arg(strToken).arg(strUserId));
	QString strPost = QString("pkid=%1").arg(strPkid);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

//绑定用户
bool HttpInterface::winHttpAjaxBind(QString strPkid, QString strToken, QString &strRet)
{
	QString strUrl = QString("/wv/wechat/ajax-bind?pkid=%1").arg(strPkid);
	if (!strToken.isEmpty())
		strUrl.append("&token=" + strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}


//税号绑定手机号
bool HttpInterface::winHttpTaxPhoneBind(QString strMobile, QString captcha, QString strToken, QString strUserId, QString &strRet)
{
	QString strUrl = QString("/user/bind-mobile?token=%1&user_id=%2").arg(strToken).arg(strUserId);
	QString strPost = QString("mobile=%1").arg(strMobile);
	if (!captcha.isEmpty())
	{
		strPost.append("&captcha=" + captcha);
	}
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

bool HttpInterface::winHttpGetSystemTime(QString &strRet)
{
	QString strUrl = QString("/general/get-server-time");
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

bool HttpInterface::winHttpSetUsername(QString strToken, QString m_strUsername, QString &strRet)
{
	QString strUrl = QString("/ucenter/user/update-name");
	QString strPost = QString("token=%1&username=%2").arg(strToken).arg(m_strUsername);

	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet,false,1);
}
