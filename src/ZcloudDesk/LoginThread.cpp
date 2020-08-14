#include "LoginThread.h"
#include <QApplication>
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QNetworkInterface>
#include <QSettings>
#include <QJsonArray>
#include "HttpInterface.h"
#include "ZcloudBigData.h"
#include "ZcloudCommon.h"
extern QString zhicloudStrToken;
extern QString zhicloudStrUserId;

LoginThread::LoginThread(QObject *parent)
	:QThread(parent)
{

}

LoginThread::~LoginThread()
{

}


void LoginThread::setValue(WayEnum wayEnum, QString id, QString pw, QString codeType)
{
	m_wayEnum = wayEnum;
	m_Id = id;
	m_PW = pw;
	m_codeType = codeType;
	
}

QString LoginThread::checkLogoExist(QString strUrl)
{
	return ZcloudComFun::downloadPic(strUrl, QApplication::applicationDirPath().append("/CacheImage/logoImage"));
}

void LoginThread::run()
{
	HttpInterface	sInter;
	if (zhicloudStrToken.isEmpty())
	{
		//������¼
		switch (m_wayEnum)
		{
		case LoginThread::LoginPwWay:
		{
			int rtCode = httpLogin(0, m_Id, m_PW, m_userInfoStruct);
			emit loginSignals(rtCode, m_userInfoStruct);
			break;
		}
		case LoginThread::LoginPaWay:
		{
			int rtCode = httpLogin(-2, m_Id, m_PW, m_userInfoStruct);
			emit loginSignals(rtCode, m_userInfoStruct);
			break;
		}
		case LoginThread::AuthWay:
			emit getFilishSignals(getCode(m_Id, m_codeType));
			break;
		case LoginThread::VerifyPaWay:
			emit getFilishSignals(checkCode(m_Id, m_codeType, m_PW));
			break;
		case LoginThread::ResetPwWay:
			emit getFilishSignals(changedPassword(m_Id, m_PW, m_codeType));
			break;
		case LoginThread::VerifyWay:
			emit getFilishSignals(userRegister(m_Id, m_PW, m_codeType));
			break;
		case LoginThread::BindingPhoneWay:
		{
			int rtCode = httpLogin(3, m_Id, m_PW, m_userInfoStruct, m_codeType);
			emit loginSignals(rtCode, m_userInfoStruct);
			break;
		}
		case BindingEin:
		{
			//emit getFilishSignals(bindingTaxNumber(m_Id, m_PW));
			break;
		}
		case SetUserNameWay:
		{
			int rtCode = httpLogin(4, m_userInfoStruct.m_strToken, m_Id, m_userInfoStruct);
			emit getFilishSignals(rtCode);
		
		}
			break;
		default:
			break;
		}
	}
	else
	{
		//��˰��ʱ
		switch (m_wayEnum)
		{
		case LoginThread::LoginPwWay:
			break;
		case LoginThread::AuthWay:
			emit getFilishSignals(getCode(m_Id, m_codeType));
			break;
		case LoginThread::VerifyPaWay:
			emit getFilishSignals(checkCode(m_Id, m_codeType, m_PW));
			break;
		case LoginThread::ResetPwWay:
			break;
		case LoginThread::VerifyWay:
			break;
		case LoginThread::BindingPhoneWay:
		{
			//˰�Ű�΢�ź�
			int rtCode = bindingTaxNumber(m_Id, m_PW, m_codeType, m_userInfoStruct);
			if (rtCode == 0) m_userInfoStruct.m_strMobile = m_Id;
			emit loginSignals(rtCode, m_userInfoStruct);
			break;
		}
		case LoginThread::LoginPaWay:
		case LoginThread::BindingEin:
		{
			//�ֻ�����֤��� 
			//ֱ�� �ֻ��ż�˰�Ű� m_PWΪ��
			int rtCode = bindingTaxNumber(m_Id, m_PW, m_userInfoStruct);
			if (rtCode == 0) m_userInfoStruct.m_strMobile = m_Id;
			emit loginSignals(rtCode, m_userInfoStruct);
			//emit getFilishSignals();
			break;
		}
		default:
			break;
		}
	}
}

int LoginThread::getCode(QString phoneNumber, QString codeType)
{
	HttpInterface	sInter;
	QString			strRet;
	if (!sInter.winHttpSendCode(phoneNumber, codeType, strRet))
		return -1;
	return analyCodeSucess(strRet);
}

int LoginThread::checkCode(QString phoneNumber, QString codeType, QString codeNumber)
{
	HttpInterface	sInter;
	QString			strRet;
	if (!sInter.winHttpCheckCode(phoneNumber, codeType, codeNumber, strRet))
		return -1;
	return analyCodeSucess(strRet);
}

//�û�ע��
int LoginThread::userRegister(QString phoneNumber, QString passWord, QString codeNumber)
{
	HttpInterface	sInter;
	QString			strRet;
	if (!sInter.winHttpRegister(phoneNumber, passWord, codeNumber, m_userInfoStruct.m_strSign, strRet))
		return -1;
	return analyCodeSucess(strRet);
}

//�޸�����
int LoginThread::changedPassword(QString phoneNumber, QString passWord, QString codeNumber)
{
	HttpInterface	sInter;
	QString			strRet;
	if (!sInter.winHttpChangePassword(phoneNumber, passWord, codeNumber, strRet))
		return -1;
	return analyCodeSucess(strRet);
}

int LoginThread::analyCodeSucess(QString strRet)
{
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return -1;
	}
	if (!parse_doucment.isObject())
	{
		return -1;
	}
	QJsonObject obj = parse_doucment.object();
	int code = obj.take("code").toInt();
	return code;
}

int LoginThread::clsanalyCodeSucess(QString strRet)
{
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return -1;
	}
	if (!parse_doucment.isObject())
	{
		return -1;
	}
	QJsonObject obj = parse_doucment.object();
	int code = obj.take("code").toInt();
	return code;
}

int LoginThread::httpLogin(int bytaxFlag, QString strTaxNo_ID, QString strMachine_PW, UserInfoStruct &userInfoStruct, QString strSkid)
{
	HttpInterface	sInter;
	QString			strRet;
	if (bytaxFlag == 1)
	{
		//˰�ŵ�¼ʧЧ �޸ĳ��л���ǰ������ҵ
		if (!sInter.winHttpLogin(strTaxNo_ID, userInfoStruct.m_strToken, strRet))
			return -1;
		userInfoStruct.m_bLoginByTax = 1;
	}
	else if (bytaxFlag == 0)
	{
		//�˺������¼
		if (!sInter.winHttpLogin(true, strTaxNo_ID, strMachine_PW, strRet))
			return -1;
		userInfoStruct.m_strPwd = strMachine_PW;
		userInfoStruct.m_bLoginByTax = 0;
	}
	else if (bytaxFlag == -2)
	{
		//��֤���¼
		if (!sInter.winHttpLogin(false, strTaxNo_ID, strMachine_PW, strRet))
			return -1;
		//���code��Ϊ30035 δע��
		QString strSign;
		if (analySucessJsonSign(strRet, strSign))
		{
			userInfoStruct.m_strSign = strSign;
			return 30025;
		}
		userInfoStruct.m_bLoginByTax = -1;
	}
	else if (bytaxFlag == 3)
	{
		//�󶨵�¼
		if (!sInter.winHttpBindingPhone(strTaxNo_ID, strMachine_PW, strSkid, strRet))
			return -1;
		userInfoStruct.m_bLoginByTax = -1;
	}
	else if (bytaxFlag == -1){
		//token��¼
		if (!sInter.winHttpTokenLogin(strTaxNo_ID, strMachine_PW, strRet))
			return -1;
		userInfoStruct.m_bLoginByTax = -1;
	}
	else if (bytaxFlag == 4){
		//�����û�����
		if (!sInter.winHttpSetUsername(strTaxNo_ID, strMachine_PW, strRet))
			return -1;
		userInfoStruct.m_bLoginByTax = -1;


		return clsanalyCodeSucess(strRet);
	}
	else
	{
		return -1;

	}
	int code = analySucessJson(strRet, userInfoStruct);
	//userInfoStruct.m_strCompanyId = "13JZBY";
	//userInfoStruct.m_strCompanyName = QString::fromLocal8Bit("�������л��������޹�˾");
	//userInfoStruct.m_strTaxNumber = "91620924MA74U5801R";
	//userInfoStruct.m_strUsername = "17707456666";
	//userInfoStruct.m_strPwd = "666666";
	//userInfoStruct.m_strTruename = QString::fromLocal8Bit("�ܽ���");
	//userInfoStruct.m_strUserId = "11NECP";
	//userInfoStruct.m_strJob = QString::fromLocal8Bit("����");
	//userInfoStruct.m_strProvinceId = "620000";
	//userInfoStruct.m_strCityId = "620900";
	//userInfoStruct.m_strAreaId = "620924";
	//userInfoStruct.m_strHzsId = "10026";

	if (code == 0)
	{
		LoginSetingStruct loginSetingStruct;
		loginSetingStruct.autoLogin = true;
		loginSetingStruct.firstLogin = false;
		loginSetingStruct.loginByTax = userInfoStruct.m_bLoginByTax;
		if (bytaxFlag == 1)
		{
			loginSetingStruct.taxNo = strTaxNo_ID;
			loginSetingStruct.machine = strMachine_PW;
			loginSetingStruct.userName = userInfoStruct.m_strUsername;
			loginSetingStruct.pwd = userInfoStruct.m_strPwd;
		}
		else  if (bytaxFlag == 0)
		{
			loginSetingStruct.userName = strTaxNo_ID;
			loginSetingStruct.pwd = strMachine_PW;
		}
		else if (bytaxFlag == -2 || bytaxFlag == 3 || bytaxFlag == -1)
		{
			loginSetingStruct.userName = userInfoStruct.m_strMobile;
		}
		loginSetingStruct.uid = userInfoStruct.m_strUserId;
		loginSetingStruct.token = userInfoStruct.m_strToken;
		if (zhicloudStrToken.isEmpty())
		{
			Database::GetInstance()->setLoginSet(loginSetingStruct);
			writeRegdit(userInfoStruct);
		}
	}
	if (code == 0)
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "SLG005", ZcloudComFun::getOsVerQt() + "-" + strTaxNo_ID + "-" + (bytaxFlag == -2 ? strMachine_PW + "-" : "") + QString::number(bytaxFlag == -1 ? 5 : (bytaxFlag + 3)));
	}
	return code;
}

int LoginThread::bindingTaxNumber(QString strMobile, QString strCaptcha, UserInfoStruct &userInfo)
{
	HttpInterface	sInter;
	QString			strRet;
	if (zhicloudStrToken.isEmpty())
		return -1;
	//�ֻ���
	if (!sInter.winHttpTaxPhoneBind(strMobile, strCaptcha, zhicloudStrToken, zhicloudStrUserId, strRet))
		return -1;
	LoginSetingStruct  loginSetingStruct;
	userInfo.m_bLoginByTax = -1;
	if (Database::GetInstance()->findLoginSet(loginSetingStruct) && loginSetingStruct.loginByTax != 0)
	{
		userInfo.m_bLoginByTax = loginSetingStruct.loginByTax;
	}
	return LoginThread::analySucessJson(strRet, userInfo);
}

int LoginThread::bindingTaxNumber(QString strMobile, QString strCaptcha, QString strSkid, UserInfoStruct &userInfo)
{
	HttpInterface	sInter;
	QString			strRet;
	if (zhicloudStrToken.isEmpty())
		return -1;
	//΢�Ű��ֻ��Ű�
	if (!sInter.winHttpBindingPhone(strMobile, strCaptcha, strSkid, zhicloudStrToken,zhicloudStrUserId, strRet))
		return -1;
	LoginSetingStruct  loginSetingStruct;
	userInfo.m_bLoginByTax = -1;
	if (Database::GetInstance()->findLoginSet(loginSetingStruct) && loginSetingStruct.loginByTax != 0)
	{
		userInfo.m_bLoginByTax = loginSetingStruct.loginByTax;
	}
	return  LoginThread::analySucessJson(strRet, userInfo);
	/*
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return -1;
	}
	if (!parse_doucment.isObject())
	{
		return -1;
	}
	QJsonObject obj = parse_doucment.object();
	int code = obj.take("status").toInt();
	if (0 == code)
	{
		QJsonObject data = obj.take("data").toObject();
		userInfo.m_strUserId = data.take("user_id").toString();			//user_id
		userInfo.m_strToken = data.take("token").toString();		//token
	}
	*/
	//return analyCodeSucess(strRet);
}

void LoginThread::writeRegdit(UserInfoStruct userInfoStruct)
{
	QString strVer = ZcloudComFun::getFileVertion(QApplication::applicationFilePath());
	QString strRegPath = QString("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\ZcloudDesk\\%1").arg(userInfoStruct.m_strUserId);
	QSettings *settings = new QSettings(strRegPath, QSettings::NativeFormat);
	settings->setValue("uid", userInfoStruct.m_strUserId);
	settings->setValue("cid", userInfoStruct.m_strCompanyId);
	settings->setValue("ver", strVer);
	if (!userInfoStruct.m_strTaxNumber.isEmpty())
		settings->setValue("taxno", userInfoStruct.m_strTaxNumber);
	delete settings;
	settings = NULL;
}

int LoginThread::analySucessJson(QString strRet, UserInfoStruct &userInfoStruct)
{
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return -1;
	}
	if (!parse_doucment.isObject())
	{
		return -1;
	}
	QJsonObject obj = parse_doucment.object();
	int code = obj.take("code").toInt();
	if (code == 0)
	{
		QJsonObject data = obj.take("data").toObject();
		//userInfoStruct.m_strCompanyId = data.take("company_id").toString();			//��˾ҵ����
		//userInfoStruct.m_strCompanyName = data.take("company_name").toString();		//��˾����
		//userInfoStruct.m_strTaxNumber = data.take("tax_number").toString();			//˰��
		userInfoStruct.m_strUsername = data.take("user_name").toString();			//��¼�˺�
		userInfoStruct.m_strTruename = data.take("true_name").toString();			//��ʵ����
		//userInfoStruct.m_strJob = data.take("job").toString();			//��ʵ����
		userInfoStruct.m_strUserId = data.take("user_id").toString();			//�û����
		userInfoStruct.m_strMobile = data.take("mobile").toString();
		userInfoStruct.m_sex = data.take("sex").toString();
		userInfoStruct.m_iisbindc = data.take("is_bind_c").toInt();    /// //���ް���ҵ��1���ٰ�һ���� 0δ���κ���ҵ
		userInfoStruct.m_iisbinds = data.take("is_bind_s").toInt();    /// //���ް󶨿ͷ����� 1���Ѱ� 0��δ��

		QJsonObject  objValue = data.take("company").toObject();
		

		userInfoStruct.m_strCompanyId = objValue.take("company_id").toString();		//��˾ҵ����
		userInfoStruct.m_strCompanyName = objValue.take("company_name").toString();		//��˾����
		userInfoStruct.m_strTaxNumber = objValue.take("tax").toString();			//˰��

		userInfoStruct.m_strProvinceId = QString::number(objValue.take("province_id").toInt());		//ʡId
		userInfoStruct.m_strCityId = QString::number(objValue.take("city_id").toInt());			//��Id
		userInfoStruct.m_strAreaId = QString::number(objValue.take("area_id").toInt());			//��Id
		userInfoStruct.m_strHzsId = QString::number(objValue.take("hzs_id").toInt());				//������Id

		if (userInfoStruct.m_iisbinds == 1)
		{
			objValue = data.take("service").toObject();
			userInfoStruct.userservice.m_nProvinceId = objValue.take("province_id").toInt();		//ʡId
			userInfoStruct.userservice.m_nCityId = objValue.take("city_id").toInt();			//��Id
			userInfoStruct.userservice.m_nAreaId = objValue.take("area_id").toInt();			//��Id
			userInfoStruct.userservice.m_strHzsId = QString::number(objValue.take("hzs_id").toInt());				//������Id
			userInfoStruct.userservice.m_businessid = objValue.take("business_id").toString();  
			userInfoStruct.userservice.m_strUsername = objValue.take("username").toString();
			userInfoStruct.userservice.m_strPhone = objValue.take("phone").toString();
			userInfoStruct.userservice.m_strTruename = objValue.take("truename").toString();
			userInfoStruct.userservice.m_sex = objValue.take("sex").toString();
			userInfoStruct.userservice.m_strAddress = objValue.take("address").toString();

			userInfoStruct.userservice.m_wechat = objValue.take("weixin").toString();
			userInfoStruct.userservice.m_qq = objValue.take("qq").toString();
			userInfoStruct.userservice.m_nickname = objValue.take("nickname").toString();
			userInfoStruct.userservice.m_avatarurl = objValue.take("avatarurl").toString();


		}

		userInfoStruct.m_logoUrl = data.take("logo").toString();							//LOGO���ӵ�ַ
		userInfoStruct.m_logoPath = checkLogoExist(userInfoStruct.m_logoUrl);
		userInfoStruct.m_strToken = data.take("token").toString();				//token 
		userInfoStruct.m_timeChargeExpire = QDateTime::fromTime_t(data.take("charge_expire").toInt());	//����ѵ���ʱ��
		userInfoStruct.m_isHxNumber = (data.take("is_hx_member").toInt() == 0 ? false : true);
		userInfoStruct.m_bHideAppClass = data.take("hide_desktop_apps").toBool();

		userInfoStruct.m_bHasMember = data.take("has_member").toInt();
		QJsonValue memberValue = data.take("member_list");
		if (memberValue.isArray())
		{
			QJsonArray memberArray = memberValue.toArray();
			for (int j = 0; j < memberArray.size(); j++)
			{
				QJsonObject memberData = memberArray.at(j).toObject();
				QString memberLevel = memberData.take("member_grade_id").toString();
				QString membername = memberData.take("member_name").toString();
				QString memberEndTime = QString::number( memberData.take("member_end_time").toInt());
				userInfoStruct.m_strListAppVipList.append(memberLevel);
				userInfoStruct.m_strListAppVipNameList.append(membername);
				userInfoStruct.m_vipDateTimeList.append(memberEndTime);
			}
		}
		Database::GetInstance()->setUserData(userInfoStruct);
		if (!Database::GetInstance()->isUserConfigExist(userInfoStruct.m_strUserId))
		{
			Database::GetInstance()->replaceUserConfig(userInfoStruct.m_strUserId);
		}
	}
	return code;
}


bool LoginThread::analySucessJsonSign(QString strRet,QString &strSign)
{

	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return false;
	}
	if (!parse_doucment.isObject())
	{
		return false;
	}
	QJsonObject obj = parse_doucment.object();
	int code = obj.take("code").toInt();
	if (code == 30025)
	{
		QJsonObject data = obj.take("data").toObject();
		strSign = data.take("sign").toString();			//��˾ҵ����
		return true;
	}
	return false;
}

int LoginThread::visitorLogin(UserInfoStruct &userInfoStruct)
{

	QString strtax = ZcloudComFun::getTaxnumber();

	HttpInterface	sInter;
	QString			strRet;
	
		//�ο͵�½ȡ��ʱtoken
	if (!sInter.winHttpLogin(strtax, strRet))
	{

		
		return -1;
	}

	
	return analySucessTempJson(strRet, userInfoStruct);;
}

int LoginThread::analySucessTempJson(QString strRet, UserInfoStruct &userInfoStruct)
{
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return -1;
	}
	if (!parse_doucment.isObject())
	{
		return -1;
	}
	QJsonObject obj = parse_doucment.object();
	int code = obj.take("code").toInt();
	if (code == 0)
	{
		QJsonObject data = obj.take("data").toObject();
		userInfoStruct.m_strCompanyId = data.take("company_id").toString();			//��˾ҵ����
		userInfoStruct.m_strCompanyName = data.take("company_name").toString();		//��˾����
		userInfoStruct.m_strTaxNumber = data.take("tax_number").toString();			//˰��

	
		userInfoStruct.m_strUserId = data.take("user_id").toString();			//�û����

		userInfoStruct.m_strProvinceId = QString::number(data.take("province_id").toInt());		//ʡId
		userInfoStruct.m_strCityId = QString::number(data.take("city_id").toInt());			//��Id
		userInfoStruct.m_strAreaId = QString::number(data.take("area_id").toInt());			//��Id
		userInfoStruct.m_strHzsId = QString::number(data.take("hzs_id").toInt());				//������Id
		userInfoStruct.m_strToken = data.take("token").toString();				//token 

		userInfoStruct.m_bLoginByTax = -8;
	}
	return code;
}
