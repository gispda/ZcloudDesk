#include "UserCenterWidget.h"
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

UserCenterWidget::UserCenterWidget(UserInfoStruct* _userInfo,QWidget *parent)
	:QWidget(parent), m_userInfo(_userInfo)
{
	ui.setupUi(this);
	mp_UserCenterMain = new UserCenterMainWidget(_userInfo,ui.RightWidget);

	mp_UserCenterAcc = new UserCenterAccWidget(_userInfo, ui.RightWidget);
	mp_UserCenterAcc->hide();


	connect(ui.pushButtonAcc, SIGNAL(clicked()), this, SLOT(onShowAcc()));


	/*connect(ui.copyTaxButton, SIGNAL(clicked()), this, SLOT(onCopyBtnClick()));
	connect(ui.switchButton, SIGNAL(clicked()), this, SLOT(onSwitchBtnClick()));
	connect(ui.memberButton, SIGNAL(clicked()), this, SLOT(onMemberBtnClick()));
	connect(ui.accSetButton, SIGNAL(clicked()), this, SLOT(onAccSetBtnClick()));
	connect(ui.SignInButton, &QPushButton::clicked, this, &UserCenterWidget ::onSignInBtnClick);
	connect(ui.entInfoButton, &QPushButton::clicked, this, &UserCenterWidget ::onEntInfoBtnClick);
	connect(ui.transInfoButton, &QPushButton::clicked, this, &UserCenterWidget ::onTransInfoBtnClick);
	connect(ui.EntVipButton, &QPushButton::clicked, this, &UserCenterWidget ::onEntVipBtnClick);
	connect(ui.ServiceFeeButton, &QPushButton::clicked, this, &UserCenterWidget ::onServiceFeeBtnClick);
	connect(ui.CompeteDataButton, &QPushButton::clicked, this, &UserCenterWidget ::onCompeteDataBtnClick);
	connect(ui.minButton, &QPushButton::clicked, [this]()
	{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC014");
	showMinimized();
	});
	connect(ui.closeButton, &QPushButton::clicked, [this]()
	{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC015");
	hide();
	});
	ui.labelAddComp->hide();
	ui.labelAddComp->installEventFilter(this);

	ui.labelCopy->hide();
	ui.copyTaxButton->installEventFilter(this);

	m_pUserDefult = new QWidget(ui.EntRightWidget);
	m_pUserDefult->setGeometry(20, 140, 711, 181);
	m_pUserDefult->setStyleSheet("border-image:url(:/UserCenterWidget /image/userVipDefualt.png);");
	m_pUserDefult->setAttribute(Qt::WA_DeleteOnClose);
	m_pUserDefult->hide();*/
	
}
void UserCenterWidget::init(EntCenterInfo*	info){
	m_bHasMember = info->_bHasMember;
	mp_UserCenterMain->init(info);
	mp_UserCenterAcc->init(info);
}

UserCenterWidget ::~UserCenterWidget(){
	if (mp_UserCenterMain != NULL){
		mp_UserCenterMain->deleteLater();
		mp_UserCenterMain = NULL;
	}
	if (mp_UserCenterAcc != NULL){
		mp_UserCenterAcc->deleteLater();
		mp_UserCenterAcc = NULL;
	}
}

void UserCenterWidget::onShowAcc(){
	mp_UserCenterMain->hide();
	mp_UserCenterAcc->show();
}

void UserCenterWidget::onShowMain(){
	mp_UserCenterMain->show();
	mp_UserCenterAcc->hide();
}




bool UserCenterWidget ::eventFilter(QObject *target, QEvent *e)
{
	//if (target == ui.copyTaxButton)
	//{
	//	if (e->type() == QEvent::Enter) //
	//	{
	//		QString strText = ui.labelCopy->text();
	//		if (QString::fromLocal8Bit("¸´ÖÆ")!=	strText)
	//		{
	//			ui.labelCopy->setText(QString::fromLocal8Bit("¸´ÖÆ"));
	//		}
	//		ui.labelCopy->show();
	//	}
	//	else if (e->type() == QEvent::Leave)
	//	{
	//		ui.labelCopy->hide();
	//	}
	//}
	//else if (target == ui.labelAddComp)
	//{
	//	if (e->type() == QEvent::MouseButtonRelease) //
	//	{
	//		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC003");
	//		if (ZcloudComFun::winHttpSSO(m_strToken, m_strUid))
	//		{
	//			if (!this->findChild <JoinEntWidget*>("addEntEnter"))
	//			{
	//				JoinEntWidget*	pJoinEntWidget = new JoinEntWidget(m_strUid,m_strToken,this);
	//				pJoinEntWidget->show();
	//			}
	//		}
	//	}
	//}
	return QWidget::eventFilter(target, e);
}

void UserCenterWidget::modifyCoinCount(int nCount)
{
	ui.labelScore->setText(QString("%1").arg(nCount));
}


void UserCenterWidget::onChangeCoin(int nCoin)
{
	ui.labelScore->setText(QString("%1").arg(nCoin));
}




bool UserCenterWidget::winHttpGetCompanyInfo(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/company/get-company-info?user_id=%1&token=%2").arg(strUid).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}


//bool UserCenterWidget::analysisJson(const QString& strJson, EntCenterInfo& info)
//{
//	QByteArray byte_array = strJson.toUtf8();
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
//	int status = obj.take("status").toInt();
//
//	if (status != 0)
//	{
//		return false;
//	}
//
//	QJsonObject data = obj.take("data").toObject();
//	info._strUid = m_strUid;
//	info._strToken = m_strToken;
//	info._strCompId = data.take("company_id").toString();
//	info._strCompName = data.take("company_name").toString();
//	info._strTaxNo = data.take("tax_number").toString();
//	info._strLogo = data.take("logo").toString();
//	info._strLogoPath = checkLogoExist(info._strLogo);
//	info._bIsHxMember = data.take("is_hx_member").toInt();
//	info._nChargeExpire = data.take("charge_expire").toInt();
//	info._nEndDays = data.take("end_days").toInt();
//	info._bIsManualFulled = data.take("perfect_user_info").toInt();
//	info._nLastSignTime = data.take("last_sign_time").toInt();
//	info._nCoin = data.take("zc_coin").toInt();
//	info._nCoupon = data.take("coupon_num").toInt();
//	info._strCompanyInfoUrl = data.take("company_info_url").toString();
//	info._strTradeInfoUrl = data.take("trade_info_url").toString();
//	info._strFinancialMemberUrl = data.take("financial_member_url").toString();
//	info._strAccountSettingUrl = data.take("account_setting_url").toString();
//	info._strRenewUrl = data.take("renew_url").toString();
//	info._strMemberInfoUrl = data.take("member_info_url").toString();
//	info._strSignUrl = data.take("sign_url").toString();
//	info._strCreateCompanyUrl = data.take("create_company_url").toString();
//	info._dtServerTime = QDateTime::fromTime_t(data.take("server_time").toInt());
//	info._bHasMember = data.take("has_member").toInt();
//	QJsonValue jsonValue = data.take("member_list");
//	if (jsonValue.isArray())
//	{
//		QJsonArray BtnArray = jsonValue.toArray();
//		QJsonDocument document;
//		document.setArray(BtnArray);
//		QByteArray byte_array = document.toJson(QJsonDocument::Compact);
//		info._memberList = byte_array;
//	}
//	return true;
//}

QString UserCenterWidget::checkLogoExist(QString strUrl)
{
	return ZcloudComFun::downloadPic(strUrl, QApplication::applicationDirPath().append("/CacheImage/logoImage"));
}