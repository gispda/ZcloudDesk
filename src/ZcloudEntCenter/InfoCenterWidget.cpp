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

InfoCenterWidget::InfoCenterWidget(UserInfoStruct _userInfo, QWidget *parent /*= 0*/) :QWidget( parent)
{
	ui.setupUi(this);
	//resize(1002, 620);
	//setWindowTitle(QString::fromLocal8Bit("企业中心"));

	setWindowFlags(Qt::FramelessWindowHint );
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");

	ui.labelUserCenter->hide();

	connect(ui.pushButtonEntCenter, SIGNAL(clicked()), this, SLOT(showEntCenter()));
	connect(ui.pushButtonUserCenter, SIGNAL(clicked()), this, SLOT(showUserCenter()));
	
	m_userInfo = _userInfo;

	m_pEntCenter = new EntCenterNewWidget(_userInfo,ui.widgetCenter);


	m_pUserCenter = new UserCenterWidget(_userInfo,ui.widgetCenter);
	m_pUserCenter->hide();

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});
	
	connect(m_pEntCenter, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));
	//connect(this, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));
	//m_pUserDefult = new QWidget(ui.EntRightWidget);
	//m_pUserDefult->setGeometry(20, 140, 711, 181);
	//m_pUserDefult->setStyleSheet("border-image:url(:/InfoCenterWidget/image/userVipDefualt.png);");
	//m_pUserDefult->setAttribute(Qt::WA_DeleteOnClose);
	//m_pUserDefult->hide();
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

bool InfoCenterWidget::winHttpGetCompanyInfo(QString strTaxno, QString strToken, QString& strRet)
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

void InfoCenterWidget::init(){
	//EntCenterInfo	info;
	QString strRet;



	
	if (!winHttpGetCompanyInfo(m_userInfo.m_strTaxNumber,m_userInfo.m_strToken,strRet))
	{
		//!失败 从数据库读出
		EntDataBase::GetInstance()->queryEntCenterInfo(m_strUid,m_pInfo);
	}
	else
	{
		//!接口解析并replace数据库
		if (analysisJson(strRet, m_pInfo))
		{
			/*m_pInfo._strBankname = QString("234242342");
			m_pInfo._strlegalboss = QString("234242342");*/
			EntDataBase::GetInstance()->insertEntCenterInfo(m_pInfo);
		}
		else
		{
			EntDataBase::GetInstance()->queryEntCenterInfo(m_strUid, m_pInfo);
		}	
	}	
	m_pEntCenter->init(&m_pInfo);
	m_pUserCenter->init(&m_pInfo);
	
}
InfoCenterWidget::~InfoCenterWidget()
{
	if (m_pEntCenter != NULL){
		m_pEntCenter->deleteLater();
		m_pEntCenter = NULL;
	}
	if (m_pUserCenter != NULL){
		m_pUserCenter->deleteLater();
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


bool InfoCenterWidget::analysisJson(const QString& strJson, EntCenterInfo& info)
{
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
	

	info._strId = data.take("id").toString();
	info._strToken = m_userInfo.m_strToken;
	info._strCompId = data.take("company_id").toString();
	info._strCompName = data.take("company_name").toString();
	info._strTaxNo = data.take("tax_number").toString();
	info._strLogo = data.take("logo").toString();
	info._strLogoPath = checkLogoExist(info._strLogo);
	info._bIsHxMember = data.take("is_hx_member").toInt();  ///没有了 航信会员
	info._nChargeExpire = data.take("charge_expire").toInt();  
	info._nEndDays = data.take("end_days").toInt();
	info._bIsManualFulled = data.take("perfect_user_info").toInt(); ///没有了
	info._nLastSignTime = data.take("last_sign_time").toInt();  //没有了
	info._nCoin = data.take("zc_coin").toInt();      //没有了
	info._nCoupon = data.take("coupon_num").toInt();   //没有了
	info._strCompanyInfoUrl = data.take("company_info_url").toString();  //没有了
	info._strTradeInfoUrl = data.take("trade_info_url").toString();   ///没有额
	info._strFinancialMemberUrl = data.take("financial_member_url").toString();  //没有
	info._strAccountSettingUrl = data.take("account_setting_url").toString(); //没有
	info._strRenewUrl = data.take("renew_url").toString();  //没有
	info._strMemberInfoUrl = data.take("member_info_url").toString();   ///没有
	info._strSignUrl = data.take("sign_url").toString();  //没有
	info._strCreateCompanyUrl = data.take("create_company_url").toString();   ///没有
	info._dtServerTime = QDateTime::fromTime_t(data.take("server_time").toInt()); //没有
	info._bHasMember = data.take("has_member").toInt();  //没有


	////-------------------------------新增----------------------------
	info._strHzsid = data.take("hzs_id").toString();  //
	info._strEmail = data.take("email").toString();  //
	info._nCompanytype = data.take("company_type").toInt();  //
	info._nTradeid = data.take("trade_id").toInt();  //
	info._nProvinceid = data.take("province_id").toInt();  //
	info._nCityid = data.take("city_id").toInt();  //
	info._nAreaid = data.take("area_id").toInt();  //
	info._nOfficeProvinceid = data.take("office_province_id").toInt();  //
	info._nOfficeCityid = data.take("office_city_id").toInt();  //
	info._nOfficeAreaid = data.take("office_area_id").toInt();  //
	info._strOfficeaddress = data.take("office_address").toString();  //
	info._strAddress = data.take("address").toString();  //
	info._strRegisterFulladdress = data.take("reg_full_address").toString();  //
	info._strOfficeFulladdress = data.take("office_full_address").toString();  //

	info._nisjoin = data.take("is_join").toInt();  //
	info._nisbinds = data.take("is_bind_s").toInt();  //
	info._nhasadmin = data.take("has_admin").toInt();  //

	info._strlegalboss = data.take("legal_person_name").toString();  //
	info._strlegalbossmobile = data.take("legal_person_phone").toString();  //
	info._strBankname = data.take("bank_name").toString();  //
	info._strBankaccount = data.take("bank_account").toString();  //
	QJsonObject  objValue;
	if (info._nisbinds == 1)
	{
			objValue = data.take("service").toObject();
			info._oservice.m_nProvinceId = objValue.take("province_id").toInt();		//省Id
			info._oservice.m_nCityId = objValue.take("city_id").toInt();			//市Id
			info._oservice.m_nAreaId = objValue.take("area_id").toInt();			//区Id
			info._oservice.m_strHzsId = QString::number(objValue.take("hzs_id").toInt());				//合作商Id
			info._oservice.m_businessid = objValue.take("business_id").toString();
			info._oservice.m_strUsername = objValue.take("username").toString();
			info._oservice.m_strPhone = objValue.take("phone").toString();
			info._oservice.m_strTruename = objValue.take("truename").toString();
			info._oservice.m_sex = objValue.take("sex").toString();
			info._oservice.m_strAddress = objValue.take("address").toString();

			info._oservice.m_wechat = objValue.take("weixin").toString();
			info._oservice.m_qq = objValue.take("qq").toString();
			info._oservice.m_nickname = objValue.take("nickname").toString();
			info._oservice.m_avatarurl = objValue.take("avatarurl").toString();		

	}
	objValue = data.take("user").toObject();

	info._strUid = objValue.take("user_id").toString();  //
	info._strUsername = objValue.take("user_name").toString();  //
	info._strTruename = objValue.take("true_name").toString();  //
	info._strJob = objValue.take("job").toString();  //
	info._nrole_type = objValue.take("role_type").toInt();  //

	////-------------------------------------------------------------------

	QJsonValue jsonValue = data.take("member_list");
	if (jsonValue.isArray())
	{
		QJsonArray BtnArray = jsonValue.toArray();
		QJsonDocument document;
		document.setArray(BtnArray);
		QByteArray byte_array = document.toJson(QJsonDocument::Compact);
		info._memberList = byte_array;
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
