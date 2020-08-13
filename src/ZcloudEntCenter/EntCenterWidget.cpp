#include "EntCenterWidget.h"
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

EntCenterWidget::EntCenterWidget(QWidget *parent)
	:AppCommWidget("", true, parent)
{
	ui.setupUi(m_widget);
	resize(1002, 620);
	setWindowTitle(QString::fromLocal8Bit("企业中心"));
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");

	connect(ui.copyTaxButton, SIGNAL(clicked()), this, SLOT(onCopyBtnClick()));
	connect(ui.switchButton, SIGNAL(clicked()), this, SLOT(onSwitchBtnClick()));
	connect(ui.memberButton, SIGNAL(clicked()), this, SLOT(onMemberBtnClick()));
	connect(ui.accSetButton, SIGNAL(clicked()), this, SLOT(onAccSetBtnClick()));
	connect(ui.SignInButton, &QPushButton::clicked, this, &EntCenterWidget::onSignInBtnClick);
	connect(ui.entInfoButton, &QPushButton::clicked, this, &EntCenterWidget::onEntInfoBtnClick);
	connect(ui.transInfoButton, &QPushButton::clicked, this, &EntCenterWidget::onTransInfoBtnClick); 
	connect(ui.EntVipButton, &QPushButton::clicked, this, &EntCenterWidget::onEntVipBtnClick);
	connect(ui.ServiceFeeButton, &QPushButton::clicked, this, &EntCenterWidget::onServiceFeeBtnClick);
	connect(ui.CompeteDataButton, &QPushButton::clicked, this, &EntCenterWidget::onCompeteDataBtnClick);
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
	m_pUserDefult->setStyleSheet("border-image:url(:/EntCenterWidget/image/userVipDefualt.png);");
	m_pUserDefult->setAttribute(Qt::WA_DeleteOnClose);
	m_pUserDefult->hide();
}

EntCenterWidget::~EntCenterWidget()
{

}
void EntCenterWidget::mousePressEvent(QMouseEvent *event)
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

void EntCenterWidget::mouseMoveEvent(QMouseEvent *event)
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

void EntCenterWidget::setElideText(int nPixSize, QLabel* pLabel, const QString& strText)
{
	QFont font("Microsoft YaHei");
	font.setPixelSize(nPixSize);
	pLabel->setFont(font);
	QFontMetrics fontMetrics(pLabel->font());
	int fontSize = fontMetrics.width(strText);//获取之前设置的字符串的像素大小
	QString strElideText;
	if (fontSize > pLabel->width())
	{
		strElideText = fontMetrics.elidedText(strText, Qt::ElideRight, pLabel->width());//返回一个带有省略号的字符串
	}
	else
	{
		strElideText = strText;
	}
	pLabel->setText(strElideText);
	pLabel->adjustSize();
}

bool EntCenterWidget::eventFilter(QObject *target, QEvent *e)
{
	if (target == ui.copyTaxButton)
	{
		if (e->type() == QEvent::Enter) //
		{
			QString strText = ui.labelCopy->text();
			if (QString::fromLocal8Bit("复制")!=	strText)
			{
				ui.labelCopy->setText(QString::fromLocal8Bit("复制"));
			}
			ui.labelCopy->show();
		}
		else if (e->type() == QEvent::Leave)
		{
			ui.labelCopy->hide();
		}
	}
	else if (target == ui.labelAddComp)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC003");
			if (ZcloudComFun::winHttpSSO(m_strToken, m_strUid))
			{
				if (!this->findChild <JoinEntWidget*>("addEntEnter"))
				{
					JoinEntWidget*	pJoinEntWidget = new JoinEntWidget(m_strUid,m_strToken,this);
					pJoinEntWidget->show();
				}
			}
		}
	}
	return QWidget::eventFilter(target, e);
}

void EntCenterWidget::onCopyBtnClick()
{
	ui.copyTaxButton->setEnabled(false);
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC002");
	QString strTaxNo = ui.labelTaxNo->text();
	QClipboard *clipboard = QApplication::clipboard();   //获取系统剪贴板指针  
	if (NULL == clipboard)
	{
		ui.labelCopy->setText(QString::fromLocal8Bit("复制失败"));
		ui.copyTaxButton->setEnabled(true);
		return;
	}
	QString originalText = clipboard->text();         //获取剪贴板上文本信息  
	clipboard->setText(strTaxNo);
	ui.labelCopy->setText(QString::fromLocal8Bit("已复制"));
	ui.copyTaxButton->setEnabled(true);	
}

void EntCenterWidget::onSwitchBtnClick()
{
	SwitchAccWidget*	pWidget = new SwitchAccWidget(m_strUid,m_strToken,m_strUserName,m_strCompId,this);
	connect(pWidget, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SIGNAL(sigSwitchAcc(int, bool, QString, QString)));
	pWidget->setAttribute(Qt::WA_DeleteOnClose);
	pWidget->show();
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC010");
}

void EntCenterWidget::onMemberBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC005");
	if (ZcloudComFun::winHttpSSO(m_strToken, m_strUid))
	{
		if (!this->findChild <FinanMemberWidget*>("financialMember"))
		{
			FinanMemberWidget*	pWidget = new FinanMemberWidget(m_strUid, m_strToken, this);
			connect(pWidget, &FinanMemberWidget::sigEditMemberSucessed, this, &EntCenterWidget::onEditUserInfoSucessed);
			pWidget->show();
		}
	}
}

void EntCenterWidget::onAccSetBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC009");
	if (ZcloudComFun::winHttpSSO(m_strToken, m_strUid))
	{
		if (!this->findChild <AccSettingWidget*>("accSetting"))
		{
			AccSettingWidget*	pWidget = new AccSettingWidget(m_strUid,m_strToken,QString::fromLocal8Bit("账号设置"),this);
			connect(pWidget, &AccSettingWidget::sigChangeCoin, this, &EntCenterWidget::onChangeCoin);
			connect(pWidget, &AccSettingWidget::sigEditUserInfoSucessed, this, &EntCenterWidget::onEditUserInfoSucessed);
			connect(pWidget, &AccSettingWidget::sigBindMobileSucessed, this, &EntCenterWidget::sigSignBindingSucceeded);
			pWidget->show();
		}
	}
}

bool EntCenterWidget::winHttpGetCompanyInfo(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/company/get-company-info?user_id=%1&token=%2").arg(strUid).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

bool EntCenterWidget::analysisVip(QByteArray byteJsonArray)
{
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byteJsonArray, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray btnArray = parse_doucment.array();
			if (0 < btnArray.size())
			{
				ui.labelExpired_2->setStyleSheet("border-image:url(:/EntCenterWidget/image/notExpired.png);");
				QString strVip	=	QString::fromLocal8Bit("您已开通企业会员，拥有");
				for (int nIndex = 0; nIndex < btnArray.size(); ++nIndex)
				{
					QJsonObject child = btnArray.at(nIndex).toObject();
					strVip += child.take("member_name").toString();
					strVip += QString::fromLocal8Bit("、");
				}
				if (btnArray.size()>0)
				{
					strVip = strVip.left(strVip.length() - 1);
				}
				strVip += QString::fromLocal8Bit("等特权");
				setElideText(14, ui.label_7, strVip);
				return true;
			}
		}
	}
	ui.labelExpired_2->setStyleSheet("border-image:url(:/EntCenterWidget/image/expired.png);");	
	return false;
}

void EntCenterWidget::init()
{
	QString strRet;
	EntCenterInfo	info;
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

	m_bHasMember = info._bHasMember;
	QString strCompName =	info._strCompName;
	QString strTaxNo	=	info._strTaxNo;
	if (strCompName.isEmpty())
	{
		if (1	==	m_isLoginByTax)
		{
			strCompName = QString::fromLocal8Bit("暂未查询到您的企业");
		}
		else
		{
			QString strUserName = m_strUserName;
			if (strUserName.isEmpty() || strUserName.contains("wechat_") || strUserName.contains("nick_") || strUserName.contains("user_"))
			{
				if (m_strMobile.isEmpty())
				{
					strCompName = QString::fromLocal8Bit("——");
				}
				else
				{
					strCompName = m_strMobile;
				}
			}
			else
			{
				strCompName = strUserName;
			}

			ui.labelTaxNo->hide();
			ui.copyTaxButton->hide();
			ui.labelAddComp->show();
			m_bJoinEnt = false;
		}
	}
	//!公司名称
	//setElideText(14, ui.labelComName, strCompName);
	ui.labelComName->setText(strCompName);
	ui.labelComName->setWordWrap(true);

	//！税号
	ui.labelTaxNo->setText(strTaxNo);

	//!云币与优惠券
	ui.labelScore->clear();
	ui.labelScore->setText(QString("%1").arg(info._nCoin));
	ui.labelCoupon->clear();
	ui.labelCoupon->setText(QString("%1").arg(info._nCoupon));

	//!姓名与职务
	if (m_strTrueName.isEmpty())
	{
		ui.labelFirstName->setText("");
		ui.labelFirstName->setStyleSheet("background:rgba(222,222,222,1);border-radius:15px;");
		ui.labelUserName->setText(QString::fromLocal8Bit("——"));
	}
	else
	{
		ui.labelFirstName->setStyleSheet("background:rgba(95,217,153,1);border-radius:15px;font:14px \"微软雅黑\";color:#FDFDFD;");
		ui.labelFirstName->setText(m_strTrueName.left(1));
		ui.labelUserName->setText(m_strTrueName);
		ui.labelUserName->adjustSize();
	}

	if (m_bJoinEnt)
	{
		if (m_strJob.isEmpty())
		{
			ui.labelUserJob->setText(QString::fromLocal8Bit("——"));
		}
		else
		{
			ui.labelUserJob->setText(m_strJob);
			ui.labelUserJob->adjustSize();
		}
	}
	else
	{
		ui.labelUserJob->hide();
	}
	
	if (m_bJoinEnt)
	{
		//!服务费
		if (info._strCompName.isEmpty() || 0 == info._nChargeExpire)
		{
			ui.labelExpired->setStyleSheet("border-image:url(:/EntCenterWidget/image/expired.png);");
			ui.labelNoServerFee->show();
			ui.progressBar->hide();
			ui.label_4->hide();
			ui.label_5->hide();
			ui.labelFeeTime->hide();
			ui.labelFeeTime_2->hide();
			ui.labelDays->hide();
		}
		else
		{
			ui.labelExpired->setStyleSheet("border-image:url(:/EntCenterWidget/image/notExpired.png);");
			ui.labelNoServerFee->hide();
			ui.progressBar->show();
			ui.label_4->show();
			ui.label_5->show();
			ui.labelFeeTime->show();
			ui.labelFeeTime_2->show();
			ui.labelDays->show();

			if (info._nEndDays >= 0)
			{
				QString strDays = QString::fromLocal8Bit("剩余 <font style='font-size:16px;font-family:\"微软雅黑\";font-weight:400;color:#1F8BED;'>%1</font> 天").arg(info._nEndDays);
				ui.labelDays->setText(strDays);
				ui.labelDays->adjustSize();

				int nProcess = info._nEndDays;
				ui.progressBar->setValue(nProcess);

				QDateTime time = QDateTime::fromTime_t(info._nChargeExpire);
				QString strTime = time.toString("yyyy-MM-dd hh:mm:ss");
				ui.labelFeeTime->setText(strTime);

				if (0 == info._nEndDays)
				{
					ui.progressBar->setStyleSheet("QProgressBar{border:0px;border-radius:5px;background-color:#ebebeb;}"
						"QProgressBar::chunk{border:0px;border-radius:5px;background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #fd7081, stop:1 #f43b5e);}"
						"QProgressBar{border:0px;border-radius:5px;text-align:center;}");
				}
			}
		}

		//!会员
		bool bVip = analysisVip(info._memberList);
		//!头像
		showAvatar(info._strLogoPath, bVip);

		m_pUserDefult->hide();
	}
	else
	{
		//!头像
		showAvatar(info._strLogoPath, false);
		ui.label->setText(QString::fromLocal8Bit("个人服务"));
		ui.ServiceFeeWidget->hide();
		ui.EntVipWidget->hide();
		m_pUserDefult->show();
	}

	//!按钮状态
	m_isNetActive = ZcloudComFun::isNetActive();
	if (!m_isNetActive)
	{
		ui.ServiceFeeButton->setEnabled(false);
		ui.EntVipButton->setEnabled(false);
	}
	else
	{
		ui.ServiceFeeButton->setEnabled(true);
		ui.EntVipButton->setEnabled(true);
	}

	//!完善资料
	if (!info._bIsManualFulled)
	{
		if (m_isNetActive)
		{
			ui.CompeteDataButton->setEnabled(true);
		}
		else
		{
			ui.CompeteDataButton->setEnabled(false);
		}
		ui.CompeteDataButton->setText(QString::fromLocal8Bit("去完成"));
	}
	else
	{
		ui.CompeteDataButton->setEnabled(false);
		ui.CompeteDataButton->setText(QString::fromLocal8Bit("已完成"));
	}

	QDateTime timeNow = info._dtServerTime;
	uint	aa = timeNow.toTime_t();
	QDate	  dateNow = timeNow.date();

	QDateTime	timeLastSign = QDateTime::fromTime_t(info._nLastSignTime);
	QDate	  dateLastSign = timeLastSign.date();

	if (dateLastSign < dateNow || 0 == info._nLastSignTime)
	{
		ui.SignInButton->setEnabled(true);
		ui.SignInButton->setText(QString::fromLocal8Bit("去完成"));
	}
	else
	{
		ui.SignInButton->setEnabled(false);
		ui.SignInButton->setText(QString::fromLocal8Bit("已完成"));
	}

	if (!m_bJoinEnt)
	{
		ui.labelMember->hide();
		ui.labelAccSet->hide();
		ui.entInfoButton->hide();
		ui.memberButton->hide();
		ui.transInfoButton->move(80,360);
		ui.accSetButton->move(80,403);
	}
}

void EntCenterWidget::setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId,QString strUserName)
{
	m_strUid		= strUid;
	m_strToken		= strToken;
	m_strTrueName	= strTrueName;
	m_strJob		= strJob;
	m_isLoginByTax	= isLoginByTax;
	m_strMobile		= strMobile;
	m_strCompId		= strCompId;
	m_strUserName = strUserName;
}

void EntCenterWidget::setMobile(QString strMobile)
{
	m_strMobile = strMobile;
}

void EntCenterWidget::setToken(QString strToken)
{
	m_strToken = strToken;
}

void EntCenterWidget::showWindow()
{
	init();
	showNormal();
}

bool EntCenterWidget::analysisJson(const QString& strJson, EntCenterInfo& info)
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

QString EntCenterWidget::checkLogoExist(QString strUrl)
{
	return ZcloudComFun::downloadPic(strUrl, QApplication::applicationDirPath().append("/CacheImage/logoImage"));
}

void EntCenterWidget::showAvatar(QString strAvatarPath,bool bVip)
{
	QFileInfo fileInfo(strAvatarPath);
	if (!fileInfo.isFile())
	{
		strAvatarPath = ":/EntCenterWidget/image/img_tx_d.png";
	}
	QPixmap pixmapa;
	pixmapa.load(strAvatarPath);
	QRect	rectLabel = ui.labelAvatar->geometry();
	QPixmap pixmap(rectLabel.width(), rectLabel.height());
	pixmap.fill(Qt::transparent);
	QPainter painter(&pixmap);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	QPainterPath path;
	path.addEllipse(0, 0, rectLabel.width(), rectLabel.height());
	painter.setClipPath(path);
	painter.drawPixmap(0, 0, rectLabel.width(), rectLabel.height(), pixmapa);
	ui.labelAvatar->setPixmap(pixmap);

	if (!bVip)
	{
		ui.labelVip->setStyleSheet("border-image: url(:/EntCenterWidget/image/qyzx_icon_vip_wjr.png);");
	}
	else
	{
		ui.labelVip->setStyleSheet("border-image: url(:/EntCenterWidget/image/qyzx_icon_vip.png);");
	}
	ui.labelVip->raise();
}

void EntCenterWidget::onSignInBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC017");
	emit openSignInWidget(this);
}

void EntCenterWidget::onEntInfoBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC008");
	if (ZcloudComFun::winHttpSSO(m_strToken, m_strUid))
	{
		if (!this->findChild <EntInfoWidget*>("entInfo"))
		{
			EntInfoWidget*	pEntInfoWidget = new EntInfoWidget(m_strUid, m_strToken, this);
			pEntInfoWidget->show();
		}
	}	
}

void EntCenterWidget::onTransInfoBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC016");
	if (ZcloudComFun::winHttpSSO(m_strToken, m_strUid))
	{
		if (!this->findChild <EntComWidget*>("transInf"))
		{
			QString strTransInfoUrl = ZcloudComFun::getWvUrl(m_strUid, m_strToken, "wv/trade/trade-info");
			EntComWidget*	pWidget = new EntComWidget(QString::fromLocal8Bit("交易信息"), strTransInfoUrl, true, this);
			pWidget->setObjectName("transInf");
			connect(pWidget, SIGNAL(sendVipListSignals(QStringList, QStringList, QStringList)), this, SLOT(changeVipSucessed(QStringList, QStringList, QStringList)));
			pWidget->setAttribute(Qt::WA_DeleteOnClose);
			pWidget->show();
		}
	}	
}

void EntCenterWidget::onEntVipBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC018");
	//查询成功
	if (!m_bJoinEnt)
	{
		if (ZcloudComFun::winHttpSSO(m_strToken, m_strUid))
		{
			if (!this->findChild <JoinEntWidget*>("addEntEnter"))
			{
				JoinEntWidget*	pJoinEntWidget = new JoinEntWidget(m_strUid, m_strToken, this);
				pJoinEntWidget->show();
			}
		}
		return;
	}

	if (!m_bHasMember)
	{
		DefaultVipWidget*	pDefaultVipWidget = new DefaultVipWidget(this);
		pDefaultVipWidget->show();
		return;
	}

	if (ZcloudComFun::winHttpSSO(m_strToken, m_strUid))
	{
		if (!this->findChild <EntComWidget*>("entVip"))
		{
			QString strUrl = ZcloudComFun::getWvUrl(m_strUid, m_strToken, "wv/member/index");
			VipInfoWidget*	pWidget = new VipInfoWidget(m_strUid, m_strToken, strUrl, this);
			pWidget->setObjectName("entVip");
			connect(pWidget, SIGNAL(sendVipListSignals(QStringList, QStringList, QStringList)), this, SLOT(changeVipSucessed(QStringList, QStringList, QStringList)));
			connect(pWidget, SIGNAL(bingdingPhoneSignal()), this, SIGNAL(bingdingPhoneSignal()));
			pWidget->setAttribute(Qt::WA_DeleteOnClose);
			pWidget->show();
		}
	}
}

void EntCenterWidget::onServiceFeeBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC004");
	if (ZcloudComFun::winHttpSSO(m_strToken, m_strUid))
	{
		if (!this->findChild <EntComWidget*>("ServiceFee"))
		{
			QString strEntInfoUrl = ZcloudComFun::getWvUrl(m_strUid, m_strToken, "wv/service-charge-payment/index");
			EntComWidget*	pWidget = new EntComWidget(QString::fromLocal8Bit("服务费续费"), strEntInfoUrl, false, this);
			pWidget->setObjectName("ServiceFee");
			pWidget->setAttribute(Qt::WA_DeleteOnClose);
			pWidget->show();
		}
	}	
}

void EntCenterWidget::onCompeteDataBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC019");
	if (ZcloudComFun::winHttpSSO(m_strToken, m_strUid))
	{
		if (!this->findChild <AccSettingWidget*>("accSetting"))
		{
			AccSettingWidget*	pWidget = new AccSettingWidget(m_strUid, m_strToken, QString::fromLocal8Bit("完善资料"), this);
			connect(pWidget, &AccSettingWidget::sigChangeCoin, this, &EntCenterWidget::onChangeCoin);
			connect(pWidget, &AccSettingWidget::sigEditUserInfoSucessed, this, &EntCenterWidget::onEditUserInfoSucessed);
			connect(pWidget, &AccSettingWidget::sigBindMobileSucessed, this, &EntCenterWidget::sigSignBindingSucceeded);
			pWidget->show();
		}
	}
}

void EntCenterWidget::onEditUserInfoSucessed(const QString& strName, const QString& strJob)
{
	m_strTrueName = strName;
	m_strJob = strJob;
	if (!strName.isEmpty())
	{
		emit trueNameJobChange(strName, strJob);
	}

	if (m_strTrueName.isEmpty())
	{
		ui.labelFirstName->setStyleSheet("background:rgba(222,222,222,1);border-radius:15px;");
		ui.labelUserName->setText(QString::fromLocal8Bit("——"));
	}
	else
	{
		ui.labelFirstName->setStyleSheet("background:rgba(95,217,153,1);border-radius:15px;font:14px \"微软雅黑\";color:#FDFDFD;");
		ui.labelFirstName->setText(m_strTrueName.left(1));
		ui.labelUserName->setText(m_strTrueName);
		ui.labelUserName->adjustSize();
	}

	if (m_strJob.isEmpty())
	{
		ui.labelUserJob->setText(QString::fromLocal8Bit("——"));
	}
	else
	{
		ui.labelUserJob->setText(m_strJob);
		ui.labelUserJob->adjustSize();
	}
}

void EntCenterWidget::changeVipSucessed(QStringList nameList, QStringList gradeList, QStringList vipTimerList)
{
	emit sendVipListSignals(nameList, gradeList, vipTimerList);
}

void EntCenterWidget::modifyCoinCount(int nCount)
{
	ui.SignInButton->setEnabled(false);
	ui.SignInButton->setText(QString::fromLocal8Bit("已完成"));
	ui.labelScore->setText(QString("%1").arg(nCount));
}

void EntCenterWidget::onChangeCoin(int nCoin)
{
	ui.CompeteDataButton->setEnabled(false);
	ui.CompeteDataButton->setText(QString::fromLocal8Bit("已完成"));
	ui.labelScore->setText(QString("%1").arg(nCoin));
}

