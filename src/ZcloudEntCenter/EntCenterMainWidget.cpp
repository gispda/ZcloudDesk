#include "EntCenterMainWidget.h"
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

EntCenterMainWidget::EntCenterMainWidget(UserInfoStruct _userinfo,QWidget *parent)
	: AppCommWidget("", true, parent)
{
	ui.setupUi(this);

	m_userinfo = _userinfo;
	connect(ui.ServiceFeeButton, &QPushButton::clicked, this, &EntCenterMainWidget::onServiceFeeBtnClick);

	m_isNetActive = ZcloudComFun::isNetActive();
	if (!m_isNetActive)
	{
		ui.ServiceFeeButton->setEnabled(false);
	}
	else
	{
		ui.ServiceFeeButton->setEnabled(true);
	}
}

void EntCenterMainWidget::init(EntCenterInfo*	info)
{
	m_pInfo = info;

	m_bHasMember = m_pInfo->_bHasMember;
	QString strCompName =m_pInfo->_strCompName;
	QString strTaxNo =m_pInfo->_strTaxNo;
	if (strCompName.isEmpty())
	{
		if (1 == m_isLoginByTax)
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
			m_bJoinEnt = false;
		}
	}



	//!姓名与职务
	if (m_strTrueName.isEmpty())
	{
		//ui.labelFirstName->setText("");
		//ui.labelFirstName->setStyleSheet("background:rgba(222,222,222,1);border-radius:15px;");
		//ui.labelUserName->setText(QString::fromLocal8Bit("——"));
	}
	else
	{
		//ui.labelFirstName->setStyleSheet("background:rgba(95,217,153,1);border-radius:15px;font:14px \"微软雅黑\";color:#FDFDFD;");
		//ui.labelFirstName->setText(m_strTrueName.left(1));
		//ui.labelUserName->setText(m_strTrueName);
		//ui.labelUserName->adjustSize();
	}

	

	if (m_bJoinEnt)
	{
		//!服务费
		if (m_pInfo->_strCompName.isEmpty() || 0 == m_pInfo->_nChargeExpire)
		{
			ui.labelExpired_2->setStyleSheet("border-image:url(:/EntCenterWidget/image/expired.png);");
			ui.labelNoServerFee_2->show();
			ui.progressBar->hide();
			ui.label_7->hide();
			ui.label_8->hide();
			ui.labelFeeTime->hide();
			ui.labelFeeTime_4->hide();
			ui.labelDays->hide();
		}
		else
		{
			ui.labelExpired_2->setStyleSheet("border-image:url(:/EntCenterWidget/image/notExpired.png);");
			ui.labelNoServerFee_2->hide();
			ui.progressBar->show();

			ui.labelFeeTime->show();
			ui.labelFeeTime_4->show();
			ui.labelDays->show();

			if (m_pInfo->_nEndDays >= 0)
			{
				QString strDays = QString::fromLocal8Bit("剩余 <font style='font-size:16px;font-family:\"微软雅黑\";font-weight:400;color:#1F8BED;'>%1</font> 天").arg(m_pInfo->_nEndDays);
				ui.labelDays->setText(strDays);
				ui.labelDays->adjustSize();

				int nProcess =m_pInfo->_nEndDays;
				ui.progressBar->setValue(nProcess);

				QDateTime time = QDateTime::fromTime_t(m_pInfo->_nChargeExpire);
				QString strTime = time.toString("yyyy-MM-dd hh:mm:ss");
				ui.labelFeeTime->setText(strTime);

				if (0 ==m_pInfo->_nEndDays)
				{
					ui.progressBar->setStyleSheet("QProgressBar{border:0px;border-radius:5px;background-color:#ebebeb;}"
						"QProgressBar::chunk{border:0px;border-radius:5px;background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #fd7081, stop:1 #f43b5e);}"
						"QProgressBar{border:0px;border-radius:5px;text-align:center;}");
				}
			}
		}

		////!会员
		//bool bVip = analysisVip(info._memberList);
		////!头像
		//showAvatar(info._strLogoPath, bVip);

		//m_pUserDefult->hide();
	}
	else
	{
		ui.ServiceFeeWidget->hide();

	}

	//!按钮状态
	m_isNetActive = ZcloudComFun::isNetActive();
	if (!m_isNetActive)
	{
		ui.ServiceFeeButton->setEnabled(false); 
	}
	else
	{
		ui.ServiceFeeButton->setEnabled(true); 
	}

	
}

EntCenterMainWidget::~EntCenterMainWidget()
{

}
bool EntCenterMainWidget::eventFilter(QObject *target, QEvent *e)
{
	//if (target == ui.copyTaxButton)
	//{
	//	if (e->type() == QEvent::Enter) //
	//	{
	//		QString strText = ui.labelCopy->text();
	//		if (QString::fromLocal8Bit("复制")!=	strText)
	//		{
	//			ui.labelCopy->setText(QString::fromLocal8Bit("复制"));
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


void EntCenterMainWidget::setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId,QString strUserName)
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



QString EntCenterMainWidget::checkLogoExist(QString strUrl)
{
	return ZcloudComFun::downloadPic(strUrl, QApplication::applicationDirPath().append("/CacheImage/logoImage"));
}

void EntCenterMainWidget::onServiceFeeBtnClick()
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



