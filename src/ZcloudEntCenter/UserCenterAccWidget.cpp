#include "UserCenterAccWidget.h"
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

UserCenterAccWidget::UserCenterAccWidget(UserInfoStruct* info,QWidget *parent)
	: m_userInfo(info), AppCommWidget("", true, parent)
{
	ui.setupUi(m_widget);

	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");


}

UserCenterAccWidget::~UserCenterAccWidget()
{

}
void UserCenterAccWidget::setElideText(int nPixSize, QLabel* pLabel, const QString& strText)
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

bool UserCenterAccWidget::eventFilter(QObject *target, QEvent *e)
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

void UserCenterAccWidget::init(EntCenterInfo*	info111)
{
	QString strRet;

	QString m_bHasMember = m_userInfo->m_bHasMember;
	QString strCompName = m_userInfo->m_strCompanyName;
	QString strTaxNo = m_userInfo->m_strTaxNumber;
	if (strCompName.isEmpty())
	{
		if (1 == m_userInfo->m_bLoginByTax)
		{
			strCompName = QString::fromLocal8Bit("暂未查询到您的企业");
		}
		else
		{
			QString strUserName = m_userInfo->m_strUsername;
			if (strUserName.isEmpty() || strUserName.contains("wechat_") || strUserName.contains("nick_") || strUserName.contains("user_"))
			{
				if (m_userInfo->m_strMobile.isEmpty())
				{
					strCompName = QString::fromLocal8Bit("——");
				}
				else
				{
					strCompName = m_userInfo->m_strMobile;
				}
			}
			else
			{
				strCompName = strUserName;
			}

			//m_bJoinEnt = false;
		}
	}
	


	
	//!姓名与职务
	if (m_userInfo->m_strTruename.isEmpty())
	{
		ui.labelFirstName->setText("");
		ui.labelFirstName->setStyleSheet("background:rgba(222,222,222,1);border-radius:15px;");
		ui.labelUserName->setText(QString::fromLocal8Bit("——"));
	}
	else
	{
		QString  name = m_userInfo->m_strTruename;
		ui.labelFirstName->setStyleSheet("background:rgba(95,217,153,1);border-radius:15px;font:14px \"微软雅黑\";color:#FDFDFD;");
		ui.labelFirstName->setText(name.left(1));
		ui.labelUserName->setText(name);
		ui.labelUserName->adjustSize();
	}

	



}




QString UserCenterAccWidget::checkLogoExist(QString strUrl)
{
	return ZcloudComFun::downloadPic(strUrl, QApplication::applicationDirPath().append("/CacheImage/logoImage"));
}



void UserCenterAccWidget::onEntInfoBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC008");
	if (ZcloudComFun::winHttpSSO(m_userInfo->m_strToken, m_userInfo->m_strUserId))
	{
		if (!this->findChild <EntInfoWidget*>("entInfo"))
		{
			EntInfoWidget*	pEntInfoWidget = new EntInfoWidget(m_userInfo->m_strUserId, m_userInfo->m_strToken, this);
			pEntInfoWidget->show();
		}
	}	
}




