#include "UserCenterMainWidget.h"
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

UserCenterMainWidget::UserCenterMainWidget(UserInfoStruct* info,QWidget *parent)
	: m_userInfo(info),AppCommWidget("", true, parent)
{
	ui.setupUi(m_widget);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");


	connect(ui.SignInButton, &QPushButton::clicked, this, &UserCenterMainWidget::onSignInBtnClick);
	connect(ui.CompeteDataButton, &QPushButton::clicked, this, &UserCenterMainWidget::onCompeteDataBtnClick);



	m_pUserDefult = new QWidget(ui.EntRightWidget);
	m_pUserDefult->setGeometry(20, 140, 711, 181);
	m_pUserDefult->setStyleSheet("border-image:url(:/UserCenterMainWidget/image/userVipDefualt.png);");
	m_pUserDefult->setAttribute(Qt::WA_DeleteOnClose);
	m_pUserDefult->hide();

	ui.CompeteDataWidget->hide();
	ui.SignInWidget->hide();
}

UserCenterMainWidget::~UserCenterMainWidget()
{

}
void UserCenterMainWidget::setElideText(int nPixSize, QLabel* pLabel, const QString& strText)
{
	QFont font("Microsoft YaHei");
	font.setPixelSize(nPixSize);
	pLabel->setFont(font);
	QFontMetrics fontMetrics(pLabel->font());
	int fontSize = fontMetrics.width(strText);//��ȡ֮ǰ���õ��ַ��������ش�С
	QString strElideText;
	if (fontSize > pLabel->width())
	{
		strElideText = fontMetrics.elidedText(strText, Qt::ElideRight, pLabel->width());//����һ������ʡ�Ժŵ��ַ���
	}
	else
	{
		strElideText = strText;
	}
	pLabel->setText(strElideText);
	pLabel->adjustSize();
}

bool UserCenterMainWidget::eventFilter(QObject *target, QEvent *e)
{
	//if (target == ui.copyTaxButton)
	//{
	//	if (e->type() == QEvent::Enter) //
	//	{
	//		QString strText = ui.labelCopy->text();
	//		if (QString::fromLocal8Bit("����")!=	strText)
	//		{
	//			ui.labelCopy->setText(QString::fromLocal8Bit("����"));
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

void UserCenterMainWidget::init(EntCenterInfo*	info11)
{
	QString strRet;
	

	//!��������
	//if (!info->_bIsManualFulled)
	//{
	//	
	//	
	//	//if (m_isNetActive)
	//	//{
	//	//	ui.CompeteDataButton->setEnabled(true);
	//	//}
	//	//else
	//	//{
	//	//	ui.CompeteDataButton->setEnabled(false);
	//	//}
	//	ui.CompeteDataButton->setText(QString::fromLocal8Bit("ȥ���"));
	//}
	//else
	//{
	//	ui.CompeteDataButton->setEnabled(false);
	//	ui.CompeteDataButton->setText(QString::fromLocal8Bit("�����"));
	//}


	
	QString strCompName = m_userInfo->m_strCompanyName;
	QString strTaxNo = m_userInfo->m_strTaxNumber;
	QString m_strTrueName = m_userInfo->m_strTruename;
	QString strUserName = m_userInfo->m_strUsername;
	QString m_strMobile = m_userInfo->m_strMobile;
	QString m_strJob = m_userInfo->m_strJob;

	
	bool m_bJoinEnt = false;
	
	if (strCompName.isEmpty())
	{
			if (1 == m_userInfo->m_bLoginByTax)
		{
			strCompName = QString::fromLocal8Bit("��δ��ѯ��������ҵ");
		}
		else
		{
			if (strUserName.isEmpty() || strUserName.contains("wechat_") || strUserName.contains("nick_") || strUserName.contains("user_"))
			{
				if (m_strMobile.isEmpty())
				{
					strCompName = QString::fromLocal8Bit("����");
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
	



	//!������ְ��
	if (m_strTrueName.isEmpty())
	{
		ui.labelFirstName->setText("");
		ui.labelFirstName->setStyleSheet("background:rgba(222,222,222,1);border-radius:15px;");
		ui.labelUserName->setText(QString::fromLocal8Bit("����"));
	}
	else
	{
		ui.labelFirstName->setStyleSheet("background:rgba(95,217,153,1);border-radius:15px;font:14px \"΢���ź�\";color:#FDFDFD;");
		ui.labelFirstName->setText(m_strTrueName.left(1));
		ui.labelUserName->setText(m_strTrueName);
		ui.labelUserName->adjustSize();
	}

	if (m_bJoinEnt)
	{
		if (m_strJob.isEmpty())
		{
			ui.labelUserJob->setText(QString::fromLocal8Bit("����"));
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

	
	/*QDateTime timeNow = m_userInfo->m_timeChargeExpire;
	uint	aa = timeNow.toTime_t();
	QDate	  dateNow = timeNow.date();

	QDateTime	timeLastSign = QDateTime::fromTime_t(info->_nLastSignTime);
	QDate	  dateLastSign = timeLastSign.date();

	if (dateLastSign < dateNow || 0 == info->_nLastSignTime)
	{
		ui.SignInButton->setEnabled(true);
		ui.SignInButton->setText(QString::fromLocal8Bit("ȥ���"));
	}
	else
	{
		ui.SignInButton->setEnabled(false);
		ui.SignInButton->setText(QString::fromLocal8Bit("�����"));
	}*/

}





QString UserCenterMainWidget::checkLogoExist(QString strUrl)
{
	return ZcloudComFun::downloadPic(strUrl, QApplication::applicationDirPath().append("/CacheImage/logoImage"));
}


void UserCenterMainWidget::onSignInBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC017");
	emit openSignInWidget(this);
}



void UserCenterMainWidget::onCompeteDataBtnClick()
{
	//ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC019");

	//if (ZcloudComFun::winHttpSSO(m_strToken, m_strUid))
	//{
	//	if (!this->findChild <AccSettingWidget*>("accSetting"))
	//	{
	//		AccSettingWidget*	pWidget = new AccSettingWidget(m_strUid, m_strToken, QString::fromLocal8Bit("��������"), this);
	//		connect(pWidget, &AccSettingWidget::sigChangeCoin, this, &UserCenterMainWidget::onChangeCoin);
	//		//connect(pWidget, &AccSettingWidget::sigEditUserInfoSucessed, this, &UserCenterMainWidget::onEditUserInfoSucessed);
	//		connect(pWidget, &AccSettingWidget::sigBindMobileSucessed, this, &UserCenterMainWidget::sigSignBindingSucceeded);
	//		pWidget->show();
	//	}
	//}
}
void UserCenterMainWidget::onChangeCoin(int nCoin)
{
	ui.CompeteDataButton->setEnabled(false);
	ui.CompeteDataButton->setText(QString::fromLocal8Bit("�����"));
}



