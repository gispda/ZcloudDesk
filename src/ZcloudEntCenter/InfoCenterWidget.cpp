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

InfoCenterWidget::InfoCenterWidget(QWidget *parent)
	:QWidget( parent)
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
	

	m_pEntCenter = new EntCenterNewWidget(ui.widgetCenter);


	m_pUserCenter = new UserCenterWidget(ui.widgetCenter);
	m_pUserCenter->hide();
	

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

bool InfoCenterWidget::winHttpGetCompanyInfo(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/company/get-company-info?user_id=%1&token=%2").arg(strUid).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

void InfoCenterWidget::init(){
	EntCenterInfo	info;
	QString strRet;
	EntCenterInfo* m_pInfo = &info;
	if (!winHttpGetCompanyInfo(m_strUid, m_strToken, strRet))
	{
		//!失败 从数据库读出
		EntDataBase::GetInstance()->queryEntCenterInfo(m_strUid,info);
	}
	else
	{
		//!接口解析并replace数据库
		if (analysisJson(strRet, info))
		{
			EntDataBase::GetInstance()->insertEntCenterInfo(info);
		}
		else
		{
			EntDataBase::GetInstance()->queryEntCenterInfo(m_strUid, info);
		}	
	}	
	m_pEntCenter->init(&info);
	m_pUserCenter->init(&info);
	
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
	int status = obj.take("status").toInt();

	if (status != 0)
	{
		return false;
	}

	QJsonObject data = obj.take("data").toObject();
	info._strUid = m_strUid;
	info._strToken = m_strToken;
	info._strCompId = data.take("company_id").toString();
	info._strCompName = data.take("company_name").toString();
	info._strTaxNo = data.take("tax_number").toString();
	info._strLogo = data.take("logo").toString();
	info._strLogoPath = checkLogoExist(info._strLogo);
	info._bIsHxMember = data.take("is_hx_member").toInt();
	info._nChargeExpire = data.take("charge_expire").toInt();
	info._nEndDays = data.take("end_days").toInt();
	info._bIsManualFulled = data.take("perfect_user_info").toInt();
	info._nLastSignTime = data.take("last_sign_time").toInt();
	info._nCoin = data.take("zc_coin").toInt();
	info._nCoupon = data.take("coupon_num").toInt();
	info._strCompanyInfoUrl = data.take("company_info_url").toString();
	info._strTradeInfoUrl = data.take("trade_info_url").toString();
	info._strFinancialMemberUrl = data.take("financial_member_url").toString();
	info._strAccountSettingUrl = data.take("account_setting_url").toString();
	info._strRenewUrl = data.take("renew_url").toString();
	info._strMemberInfoUrl = data.take("member_info_url").toString();
	info._strSignUrl = data.take("sign_url").toString();
	info._strCreateCompanyUrl = data.take("create_company_url").toString();
	info._dtServerTime = QDateTime::fromTime_t(data.take("server_time").toInt());
	info._bHasMember = data.take("has_member").toInt();
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