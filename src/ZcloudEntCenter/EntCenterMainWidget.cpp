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
#include "WorkersWidget.h"

EntCenterMainWidget::EntCenterMainWidget(EntCenterInfo* pEntInfo, UserInfoStruct* userinfo, QWidget *parent)
	: QWidget( parent)
{
	ui.setupUi(this);

	m_pInfo = pEntInfo;
	m_userinfo = userinfo;
	connect(ui.ServiceFeeButton, &QPushButton::clicked, this, &EntCenterMainWidget::onServiceFeeBtnClick);



	//ui.labelJoin2->installEventFilter(this);

	ui.labelworkers->installEventFilter(this);
	bool m_isNetActive = ZcloudComFun::isNetActive();
	if (!m_isNetActive)
	{
		ui.ServiceFeeButton->setEnabled(false);
	}
	else
	{
		ui.ServiceFeeButton->setEnabled(true);
	}
	init(pEntInfo, userinfo);
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

		ZcloudComFun::LoadAvatar(m_pInfo->_oservice.m_avatarurl.toStdString(), ui.labelPic_3);

		ui.ServiceBaseWidget->show();
		ui.widgetNotBinding->hide();
		ui.labelName_2->setText(m_pInfo->_oservice.m_strTruename);
		ui.labelPhone_2->setText(m_pInfo->_oservice.m_strPhone);
		ui.labelWeChat_2->setText(m_pInfo->_oservice.m_wechat);
		ui.labelName_5->setText(m_pInfo->_oservice.m_qq);

	}
	else
	{
		//显示二维码
		getCodeImg();
		ui.ServiceBaseWidget->hide();
		ui.widgetNotBinding->show();
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


	if (target == ui.labelworkers)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{

			if (m_userinfo->m_bLoginByTax != -8)
			{			
			WorkersWidget* pEntComWidget = new WorkersWidget(m_userinfo->m_strUserId, m_userinfo->m_strToken);
			pEntComWidget->setAttribute(Qt::WA_DeleteOnClose);
			pEntComWidget->show();
		    }
		}
	}
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



void EntCenterMainWidget::getCodeImg()
{
	QString strRet;
	if (!winHttpGetTwoCodeInfo(m_pInfo->_strCompId, m_pInfo->_strToken, strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n更新企业资料失败，请稍后再试！"));
		return;
	}




	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return;
	}
	if (!parse_doucment.isObject())
	{
		return;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("code").toInt();
	if (0 != status)
	{
		return;
	}

	QJsonObject data = obj.take("data").toObject();


	QString m_tburl = data.take("qrimg").toString();


	ZcloudComFun::LoadAvatar(m_tburl.toStdString(), ui.labelTwoBarCode);

}

bool EntCenterMainWidget::winHttpGetTwoCodeInfo(QString strCompanyid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/ucenter/qr/min-qrcode");
	QString strPost = QString("token=%1&company_id=%2")
		.arg(strToken).arg(strCompanyid);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);
}
