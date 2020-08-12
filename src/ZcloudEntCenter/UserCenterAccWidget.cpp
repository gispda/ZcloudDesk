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

UserCenterAccWidget::UserCenterAccWidget(QWidget *parent)
	: AppCommWidget("", true, parent)
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

bool UserCenterAccWidget::eventFilter(QObject *target, QEvent *e)
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

void UserCenterAccWidget::init(EntCenterInfo*	info)
{
	QString strRet;

	m_bHasMember = info->_bHasMember;
	QString strCompName = info->_strCompName;
	QString strTaxNo = info->_strTaxNo;
	if (strCompName.isEmpty())
	{
		if (1	==	m_isLoginByTax)
		{
			strCompName = QString::fromLocal8Bit("��δ��ѯ��������ҵ");
		}
		else
		{
			QString strUserName = m_strUserName;
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

	



}

void UserCenterAccWidget::setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId,QString strUserName)
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

void UserCenterAccWidget::setMobile(QString strMobile)
{
	m_strMobile = strMobile;
}

void UserCenterAccWidget::setToken(QString strToken)
{
	m_strToken = strToken;
}


QString UserCenterAccWidget::checkLogoExist(QString strUrl)
{
	return ZcloudComFun::downloadPic(strUrl, QApplication::applicationDirPath().append("/CacheImage/logoImage"));
}



void UserCenterAccWidget::onEntInfoBtnClick()
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



