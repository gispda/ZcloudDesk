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

EntCenterMainWidget::EntCenterMainWidget(EntCenterInfo* pEntInfo, UserInfoStruct* userinfo, QWidget *parent)
	: AppCommWidget("", true, parent)
{
	ui.setupUi(this);

	m_pInfo = pEntInfo;
	m_userinfo = userinfo;
	connect(ui.ServiceFeeButton, &QPushButton::clicked, this, &EntCenterMainWidget::onServiceFeeBtnClick);

	bool m_isNetActive = ZcloudComFun::isNetActive();
	if (!m_isNetActive)
	{
		ui.ServiceFeeButton->setEnabled(false);
	}
	else
	{
		ui.ServiceFeeButton->setEnabled(true);
	}
}

void EntCenterMainWidget::init(EntCenterInfo*	info, UserInfoStruct* userinfo)
{
	m_pInfo = info;
	this->m_userinfo = userinfo;

	QString m_bHasMember = m_pInfo->_bHasMember;
	QString strCompName =m_pInfo->_strCompName;
	QString strTaxNo =m_pInfo->_strTaxNo;
	bool m_bJoinEnt;
	if (strCompName.isEmpty())
	{
		if (1 == m_userinfo->m_bLoginByTax)
		{
			strCompName = QString::fromLocal8Bit("暂未查询到您的企业");
		}
		else
		{
			QString strUserName = m_userinfo->m_strUsername;
			if (strUserName.isEmpty() || strUserName.contains("wechat_") || strUserName.contains("nick_") || strUserName.contains("user_"))
			{
				if (m_userinfo->m_strMobile.isEmpty())
				{
					strCompName = QString::fromLocal8Bit("——");
				}
				else
				{
					strCompName = m_userinfo->m_strMobile;
				}
			}
			else
			{
				strCompName = strUserName;
			}
			m_bJoinEnt = false;
		}
	}



	//绑定经理
	if (m_pInfo->_nisbinds)
	{
		//显示头像
		//m_pInfo->_oservice.m_avatarurl
		ui.widgetUserInfo_2->show();
		ui.widgetNotBinding_2->hide();
		ui.labelName_2->setText(m_pInfo->_oservice.m_strTruename);
		ui.labelPhone_2->setText(m_pInfo->_oservice.m_strPhone);
		ui.labelWeChat_2->setText(m_pInfo->_oservice.m_wechat);
		ui.labelName_5->setText(m_pInfo->_oservice.m_qq);

	}
	else
	{
		//显示二维码
		ui.widgetUserInfo_2->hide();
		ui.widgetNotBinding_2->show();
	}

	

	if (m_pInfo->_nisjoin)
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
			ui.ServiceFeeButton->hide();
		}
		else
		{
			ui.labelExpired_2->setStyleSheet("border-image:url(:/EntCenterWidget/image/notExpired.png);");
			ui.labelNoServerFee_2->hide();
			ui.progressBar->show();

			ui.labelFeeTime->show();
			ui.labelFeeTime_4->show();
			ui.labelDays->show();
			ui.ServiceFeeButton->show();

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
	bool m_isNetActive = ZcloudComFun::isNetActiveByToken(m_userinfo->m_strToken);
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




QString EntCenterMainWidget::checkLogoExist(QString strUrl)
{
	return ZcloudComFun::downloadPic(strUrl, QApplication::applicationDirPath().append("/CacheImage/logoImage"));
}

void EntCenterMainWidget::onServiceFeeBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC004");
	if (ZcloudComFun::winHttpSSO(m_pInfo->_strToken, m_pInfo->_strUid))
	{
		if (!this->findChild <EntComWidget*>("ServiceFee"))
		{
			QString strEntInfoUrl = ZcloudComFun::getWvUrl(m_pInfo->_strUid, m_pInfo->_strToken, "wv/service-charge-payment/index");
			EntComWidget*	pWidget = new EntComWidget(QString::fromLocal8Bit("服务费续费"), strEntInfoUrl, false, this);
			pWidget->setObjectName("ServiceFee");
			pWidget->setAttribute(Qt::WA_DeleteOnClose);
			pWidget->show();
		}
	}
}



