#include "InfoCenterWidget.h"
#include <QClipboard>
#include "SwitchAccWidget.h"
#include "EntComWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileInfo>
#include <QDialog>
#include "ZcloudBigData.h"
#include "VipInfoWidget.h"
#include "DefaultVipWidget.h"
#include "JoinEntWidget.h"
#include "EntInfoWidget.h"
#include "FinanMemberWidget.h"
#include "AccSettingWidget.h"

InfoCenterWidget::InfoCenterWidget(UserInfoStruct* _userInfo, QWidget *parent /*= 0*/) :QWidget( parent)
{
	ui.setupUi(this);
	m_userInfo = _userInfo;
	m_bIsloadDb = false;

	QString strRet;
	//获取企业信息
	if (!getEntInfo(&m_stEntInfo, m_userInfo->m_strTaxNumber, m_userInfo->m_strToken, strRet))
	{
		//!失败 从数据库读出
		EntDataBase::GetInstance()->queryEntCenterInfo(m_strUid, m_stEntInfo);
	}
	else
	{
		EntDataBase::GetInstance()->insertEntCenterInfo(m_stEntInfo);
	}


	setWindowFlags(Qt::FramelessWindowHint );
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");

	ui.labelUserCenter->hide();

	connect(ui.pushButtonEntCenter, SIGNAL(clicked()), this, SLOT(showEntCenter()));
	connect(ui.pushButtonUserCenter, SIGNAL(clicked()), this, SLOT(showUserCenter()));

	m_pEntCenter = new EntCenterNewWidget(&m_stEntInfo, m_userInfo, ui.widgetCenter);
	m_pUserCenter = new UserCenterWidget(&m_stEntInfo, _userInfo, ui.widgetCenter);
	m_pEntCenter->setGeometry(0, -1, 1002, 620);
	m_pUserCenter->setGeometry(0, -1, 1002, 620);



	connect(m_pEntCenter, SIGNAL(sigNeedLogin()), this, SLOT(needLogin()));
	connect(m_pUserCenter, SIGNAL(sigNeedLogin()), this, SLOT(needLogin()));

	m_pUserCenter->hide();

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});
	
	connect(m_pEntCenter, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));


}
void InfoCenterWidget::needLogin(){
	emit sigNeedLogin();
}

void InfoCenterWidget::showEntCenter(){

	ui.pushButtonEntCenter->setStyleSheet("color:#1E8BED;");
	ui.pushButtonUserCenter->setStyleSheet("color:#000000;");
	m_pEntCenter->show();
	m_pUserCenter->hide();
	ui.labelEntCenter->show();
	ui.labelUserCenter->hide();
}
void InfoCenterWidget::showUserCenter(){

	ui.pushButtonEntCenter->setStyleSheet("color:#000000;");
	ui.pushButtonUserCenter->setStyleSheet("color:#1E8BED;");
	m_pEntCenter->hide();
	m_pUserCenter->show();
	ui.labelEntCenter->hide();
	ui.labelUserCenter->show();
}

void InfoCenterWidget::setUserInfo(UserInfoStruct* _userInfo){
	m_userInfo = _userInfo;
	m_bIsloadDb = false;

	QString strRet;
	//获取企业信息
	if (!getEntInfo(&m_stEntInfo, m_userInfo->m_strTaxNumber, m_userInfo->m_strToken, strRet))
	{
		//!失败 从数据库读出
		EntDataBase::GetInstance()->queryEntCenterInfo(m_strUid, m_stEntInfo);
	}
	else
	{
		EntDataBase::GetInstance()->insertEntCenterInfo(m_stEntInfo);
	}
	m_pEntCenter->init(&m_stEntInfo);
	m_pUserCenter->init(&m_stEntInfo, _userInfo);

}
void InfoCenterWidget::setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId, QString strUserName)
{
	m_strUid = strUid;
	m_strToken = strToken;
	m_strTrueName = strTrueName;
	m_strJob = strJob;
	m_isLoginByTax = isLoginByTax;
	m_strMobile = strMobile;
	m_strCompId = strCompId;
	m_strUserName = strUserName;
}

//bool InfoCenterWidget::winHttpGetEntInfo(QString strTaxno, QString strToken, QString& strRet)
//{
//	QString strUrl = QString("/ucenter/company/info");
//	QString strPost;
//
//	//strPost = QString("tax=%1").arg(strTaxno);
//	strPost = QString("tax=%1&token=%2").arg(strTaxno).arg(strToken);
//	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);
//}

bool InfoCenterWidget::winHttpGetCompanyInfo( QString strTaxno, QString strToken, QString& strRet)
{
	QString strUrl = QString("/ucenter/company/info");
	QString strPost;

	if (!strTaxno.isEmpty())
	{
		strPost = QString("tax=%1&token=%2").arg(strTaxno).arg(strToken);
		return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);
	}
	return false;
}



InfoCenterWidget::~InfoCenterWidget()
{
	if (m_pEntCenter != NULL){
		//m_pEntCenter->deleteLater();
		m_pEntCenter = NULL;
	}
	if (m_pUserCenter != NULL){
		//m_pUserCenter->deleteLater();
		m_pUserCenter = NULL;
	}



}
void InfoCenterWidget::mousePressEvent(QMouseEvent *event)
{
	if (!isMaximized())
	{
		if (event->button() == Qt::LeftButton)
		{
			dPos = event->globalPos() - pos();
			event->accept();
		}
	}
}

void InfoCenterWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (!isMaximized())
	{
		if (event->buttons()&Qt::LeftButton)
		{
			move(event->globalPos() - dPos);
			event->accept();
		}
	}
}


bool InfoCenterWidget::getEntInfo(EntCenterInfo* info, QString strTaxno, QString strToken, QString& strRet){

	//获取企业信息
	if (winHttpGetCompanyInfo(strTaxno, strToken, strRet))
	{
		if (analysisJson(strRet, strToken, info))
		{
			return true;
		}
	}
	return false;
}

bool InfoCenterWidget::analysisJson(const QString& strJson, QString token, EntCenterInfo* info)
{

	//qDebug() << strJson;
	QByteArray byte_array = strJson.toUtf8();
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
	int status = obj.take("code").toInt();

	if (status != 0)
	{
		return false;
	}

	QJsonObject data = obj.take("data").toObject();

	//qDebug() << QString(QJsonDocument(data).toJson());
	//if (data.contains("u_rule_type")){
	//	/*QJsonValue rule_int = data.take("u_rule_type");
	//	QString rule = data.take("u_rule_type").toString();*/
	//	int intrule = data.take("u_rule_type").toInt();
	//	int b=10;
	//}

	//qDebug() << obj.take("data").toString();


	info->_strId = data.value("id").toString();
	info->_strToken = token;
	info->_strCompId = data.value("company_id").toString();
	info->_strCompName = data.value("company_name").toString();
	info->_strTaxNo = data.value("tax_number").toString();
	info->_strLogo = data.value("logo").toString();
	info->_strLogoPath = checkLogoExist(info->_strLogo);
	info->_bIsHxMember = data.value("is_hx_member").toInt();  ///没有了 航信会员
	info->_nChargeExpire = data.value("charge_expire").toInt();
	info->_nEndDays = data.value("end_days").toInt();
	info->_bIsManualFulled = data.value("perfect_user_info").toInt(); ///没有了
	info->_nLastSignTime = data.value("last_sign_time").toInt();  //没有了
	info->_nCoin = data.value("zc_coin").toInt();      //没有了
	info->_nCoupon = data.value("coupon_num").toInt();   //没有了
	info->_strCompanyInfoUrl = data.value("company_info_url").toString();  //没有了
	info->_strTradeInfoUrl = data.value("trade_info_url").toString();   ///没有额
	info->_strFinancialMemberUrl = data.value("financial_member_url").toString();  //没有
	info->_strAccountSettingUrl = data.value("account_setting_url").toString(); //没有
	info->_strRenewUrl = data.value("renew_url").toString();  //没有
	info->_strMemberInfoUrl = data.value("member_info_url").toString();   ///没有
	info->_strSignUrl = data.value("sign_url").toString();  //没有
	info->_strCreateCompanyUrl = data.value("create_company_url").toString();   ///没有
	info->_dtServerTime = QDateTime::fromTime_t(data.value("server_time").toInt()); //没有
	info->_bHasMember = data.value("has_member").toInt();  //没有


	////-------------------------------新增----------------------------
	info->_strHzsid = data.value("hzs_id").toString();  //
	info->_strEmail = data.value("email").toString();  //
	info->_nCompanytype = data.value("company_type").toInt();  //
	info->_nTradeid = data.value("trade_id").toInt();  //
	info->_nProvinceid = data.value("province_id").toString().toInt();  //
	info->_nCityid = data.value("city_id").toString().toInt();  //
	info->_nAreaid = data.value("area_id").toString().toInt();  //
	info->_nOfficeProvinceid = data.value("office_province_id").toString().toInt();  //
	info->_nOfficeCityid = data.value("office_city_id").toString().toInt();  //
	info->_nOfficeAreaid = data.value("office_area_id").toString().toInt();  //
	info->_strOfficeaddress = data.value("office_address").toString();  //
	info->_strAddress = data.value("address").toString();  //
	info->_strRegisterFulladdress = data.value("reg_full_address").toString();  //
	info->_strOfficeFulladdress = data.value("office_full_address").toString();  //

	info->_nisjoin = data.value("is_join").toInt();  //
	//QJsonValue t = data.value("is_bind_s");
	info->_nisbinds = data.value("is_bind_s").toInt();  //
	info->_nhasadmin = data.value("has_admin").toInt();  //

	info->_strlegalboss = data.value("legal_person_name").toString();  //
	info->_strlegalbossmobile = data.value("legal_person_phone").toString();  //
	info->_strBankname = data.value("bank_name").toString();  //
	info->_strBankaccount = data.value("bank_account").toString();  //
	info->_strTelNumber = data.value("tel_number").toString();




	//QJsonObject  objValue;



	if (info->_nisbinds == 1)
	{
		QJsonObject objValue = data.value("service").toObject();

		//qDebug() << QString(QJsonDocument(objValue).toJson());



		info->_oservice.m_nProvinceId = objValue.value("province_id").toString().toInt();		//省Id
		info->_oservice.m_nCityId = objValue.value("city_id").toString().toInt();			//市Id
		info->_oservice.m_nAreaId = objValue.value("area_id").toString().toInt();			//区Id
		info->_oservice.m_strHzsId = QString::number(objValue.value("hzs_id").toInt());				//合作商Id
		info->_oservice.m_businessid = objValue.value("business_id").toString();
		info->_oservice.m_strUsername = objValue.value("username").toString();
		info->_oservice.m_strPhone = objValue.value("phone").toString();
		info->_oservice.m_strTruename = objValue.value("truename").toString();
		info->_oservice.m_sex = objValue.value("sex").toString();
		info->_oservice.m_strAddress = objValue.value("address").toString();

		info->_oservice.m_wechat = objValue.value("weixin").toString();
		info->_oservice.m_qq = objValue.value("qq").toString();
		info->_oservice.m_nickname = objValue.value("nickname").toString();
		info->_oservice.m_avatarurl = objValue.value("avatarurl").toString();


		QJsonValue phone = objValue.value("phone");
		QJsonValue username = objValue.value("username");
		QJsonValue weixin = objValue.value("weixin");
		QJsonValue avatar = objValue.value("avatarurl");

		//qDebug() << QString(QJsonDocument(avatar.toObject()).toJson());
		//qDebug() << avatar.toString();

		//info->_oservice.m_strPhone = phone.toString();
		//info->_oservice.m_wechat = weixin.toString();
		//info->_oservice.m_strUsername = username.toString();
		//info->_oservice.m_avatarurl = avatar.toString();;

		/*info->_oservice.m_businessid = data.take("srv_business_id").toString();
		info->_oservice.m_strHzsId = data.take("srv_hzs_id").toString();
		info->_oservice.m_strUsername = data.take("srv_username").toString();
		info->_oservice.m_strPhone = data.take("srv_phone").toString();
		info->_oservice.m_strTruename = data.take("srv_truename").toString();
		info->_oservice.m_sex = data.take("srv_sex").toString();
		info->_oservice.m_nProvinceId = data.take("srv_province_id").toString().toInt();
		info->_oservice.m_nCityId = data.take("srv_city_id").toString().toInt();
		info->_oservice.m_nAreaId = data.take("srv_area_id").toString().toInt();
		info->_oservice.m_strAddress = data.take("srv_address").toString();

		info->_oservice.m_wechat = data.take("srv_weixin").toString();
		info->_oservice.m_qq = data.take("srv_qq").toString();
		info->_oservice.m_nickname = data.take("srv_nickname").toString();
		info->_oservice.m_avatarurl = data.take("srv_avatarurl").toString();*/

	}
	{
		QJsonObject objValue = data.value("user").toObject();


		//必须在这里取值 才能获取正确内容
		info->_nrole_type = objValue.value("role_type").toString().toInt();  //


		info->_strUid = objValue.value("user_id").toString();  //
		info->_strUsername = objValue.value("user_name").toString();  //
		info->_strTruename = objValue.value("true_name").toString();  //
		info->_strJob = objValue.value("job").toString();  //
	}
	

	info->nAdmin = info->_nrole_type;

	////-------------------------------------------------------------------

	QJsonValue jsonValue = data.take("member_list");
	if (jsonValue.isArray())
	{
		QJsonArray BtnArray = jsonValue.toArray();
		QJsonDocument document;
		document.setArray(BtnArray);
		QByteArray byte_array = document.toJson(QJsonDocument::Compact);
		info->_memberList = byte_array;
	}
	return true;
}


QString InfoCenterWidget::checkLogoExist(QString strUrl)
{
	return ZcloudComFun::downloadPic(strUrl, QApplication::applicationDirPath().append("/CacheImage/logoImage"));
}

void InfoCenterWidget::onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd)
{
	emit sigSwitchAcc(bLoginByTax, bOther, strTaxNo_userName, strPwd);
}




//bool InfoCenterWidget::loadEntInfo(EntCenterInfo* info)
//{
//	QString strRet;
//	info->_strLocalTaxnoLs = ZcloudComFun::getTaxnumberList();
//	QString strlocaltax="";
//	if (info->_strLocalTaxnoLs.count()>0)
//	strlocaltax = info->_strLocalTaxnoLs.at(0);
//	//strlocaltax = "210624197305200017";
//	QString strtax = m_userInfo->m_strTaxNumber.isEmpty() != true ? m_userInfo->m_strTaxNumber : strlocaltax;
//
//	if (strtax.isEmpty())
//	{
//		m_bIsloadDb = false;
//		return false;
//	}
//	if (!winHttpGetEntInfo(strtax, m_userInfo->m_strToken, strRet))
//	{
//		return false;
//	}
//
//	QByteArray byte_array = strRet.toUtf8();
//	QJsonParseError json_error;
//	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
//	if (json_error.error != QJsonParseError::NoError)
//	{
//		return false;
//	}
//	if (!parse_doucment.isObject())
//	{
//		return false;
//	}
//	QJsonObject obj = parse_doucment.object();
//	int status = obj.take("code").toInt();
//	if (0 != status)
//	{
//		return false;
//	}
//	m_bIsloadDb = true;
//
//	QJsonObject data = obj.take("data").toObject();
//
//	info->_strCompId = data.take("company_id").toString();
//
//	//!公司名称
//	info->_strCompName = data.take("company_name").toString();
//	QString	strCompName = info->_strCompName;
//	if (strCompName.isEmpty())
//	{
//		strCompName = QString::fromLocal8Bit("暂未查询到您的企业");
//	}
//
//
//	//!税号
//	info->_strTaxNo = data.take("tax_number").toString();
//
//
//	//!行政区域
//	
//	info->_nProvinceid = data.take("province_id").toString().toInt();
//	info->_nCityid = data.take("city_id").toString().toInt();
//	info->_nAreaid = data.take("area_id").toString().toInt();
//	//m_stEntinfo->m_registerAddress._strPro = data.take("province_name").toString();
//	m_stEntinfo->_strAddress = data.take("address").toString();
//
//	m_stEntinfo->_nOfficeProvinceid = data.take("office_province_id").toString().toInt();
//	m_stEntinfo->_nOfficeCityid = data.take("office_city_id").toString().toInt();
//	m_stEntinfo->_nOfficeAreaid = data.take("office_area_id").toString().toInt();
//	m_stEntinfo->_strOfficeaddress = data.take("office_address").toString();
//
//
//
//
//	//!财税负责人
//	m_stEntInfo._strlegalboss = data.take("legal_person_name").toString();
//	QString strOfficerName = m_stEntInfo._strlegalboss;
//	if (strOfficerName.isEmpty())
//	{
//		strOfficerName = QString::fromLocal8Bit("——");
//	}
//
//	//!负责人手机号
//	m_stEntInfo._strlegalbossmobile = data.take("legal_person_phone").toString();
//	QString strPhone = m_stEntInfo._strlegalbossmobile;
//	if (strPhone.isEmpty())
//	{
//		strPhone = QString::fromLocal8Bit("——");
//	}
//
//	//!开户账号
//	m_stEntInfo._strBankaccount = data.take("bank_account").toString();
//	QString strBankAccount = m_stEntInfo._strBankaccount;
//	if (strBankAccount.isEmpty())
//	{
//		strBankAccount = QString::fromLocal8Bit("——");
//	}
//
//	//!开户银行
//	m_stEntInfo._strBankname = data.take("bank_name").toString();
//	QString strBankName = m_stEntInfo._strBankname;
//	if (strBankName.isEmpty())
//	{
//		strBankName = QString::fromLocal8Bit("——");
//	}
//
//
//	QJsonObject userdata = data.take("user").toObject();
//
//	
//	m_stEntInfo._strUid = userdata.take("user_id").toString();
//	m_stEntInfo._strUsername = userdata.take("user_name").toString();
//	m_stEntInfo._strTruename = userdata.take("true_name").toString();
//	m_stEntInfo.nAdmin = userdata.take("role_type").toInt();
//	m_stEntInfo._nrole_type = userdata.take("rule_type").toString().toInt();
//	m_stEntInfo._strJob = userdata.take("job").toString();
//
//
//	m_stEntInfo._oservice.m_businessid = data.take("srv_business_id").toString();
//	m_stEntInfo._oservice.m_strHzsId = data.take("srv_hzs_id").toString();
//	m_stEntInfo._oservice.m_strUsername = data.take("srv_username").toString();
//	m_stEntInfo._oservice.m_strPhone = data.take("srv_phone").toString();
//	m_stEntInfo._oservice.m_strTruename = data.take("srv_truename").toString();
//	m_stEntInfo._oservice.m_sex = data.take("srv_sex").toString();
//	m_stEntInfo._oservice.m_nProvinceId = data.take("srv_province_id").toString().toInt();
//	m_stEntInfo._oservice.m_nCityId = data.take("srv_city_id").toString().toInt();
//	m_stEntInfo._oservice.m_nAreaId = data.take("srv_area_id").toString().toInt();
//	m_stEntInfo._oservice.m_strAddress = data.take("srv_address").toString();
//
//	m_stEntInfo._oservice.m_wechat = data.take("srv_weixin").toString();
//	m_stEntInfo._oservice.m_qq = data.take("srv_qq").toString();
//	m_stEntInfo._oservice.m_nickname = data.take("srv_nickname").toString();
//	m_stEntInfo._oservice.m_avatarurl = data.take("srv_avatarurl").toString();
//
//
//	return true;
//}