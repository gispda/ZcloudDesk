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
#include "ModifyUserInfoWidget.h"
#include "BindMobileWidget.h"
#include "BindEmailWidget.h"
#include "ModifyPwdWidget.h"
#include "SetPwdWidget.h"
#include "ZcloudBigData.h"

UserCenterAccWidget::UserCenterAccWidget(EntCenterInfo*	entinfo, UserInfoStruct* info, QWidget *parent)
	: m_userInfo(info), QWidget( parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");


	ui.labelInfoEdit->installEventFilter(this);
	ui.labelPhone2->installEventFilter(this);
	ui.labelPwd2->installEventFilter(this);
	ui.labelEmail2->installEventFilter(this);
	ui.labelAddr2->installEventFilter(this);

	ui.widgetAddr->hide();
	ui.widgetEmail->hide();
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
	if (target == ui.labelInfoEdit)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAS001");
			ModifyUserInfoWidget*	pWidget = new ModifyUserInfoWidget(m_userInfo->m_strTruename, m_userInfo->m_strJob, m_userInfo->m_strMobile, m_userInfo->m_strUserId, this);
			connect(pWidget, &ModifyUserInfoWidget::sigModifySucessed, this, &UserCenterAccWidget::onModifyUserInfoSucessed);
			pWidget->show();
		}
	}
	else if (target == ui.labelPhone2)
	{
		if (e->type() == QEvent::MouseButtonRelease)
		{
			
			QString strOperId = m_userInfo->m_strMobile.isEmpty() ? "BAS004" : "BAS008";
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", strOperId);
			BindMobileWidget*	pWidget = new BindMobileWidget(m_userInfo->m_strMobile, m_userInfo->m_strUserId, m_userInfo->m_strToken, false, this);
			connect(pWidget, &BindMobileWidget::sigBindMobileSucessed, this, &UserCenterAccWidget::onBindMobileSucessed);
			pWidget->show();
		}
	}
	else if (target == ui.labelPwd2)
	{
		if (e->type() == QEvent::MouseButtonRelease)
		{
			QString strText = ui.labelPwd2->text();
			if (strText == QString::fromLocal8Bit("����"))
			{
				ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAS012");
				SetPwdWidget*	pWidget = new SetPwdWidget(m_userInfo->m_strUserId, m_userInfo->m_strToken, this);
				connect(pWidget, &SetPwdWidget::sigSetPwdSucessed, this, &UserCenterAccWidget::onSetPwdSucessed);
				pWidget->show();
			}
			/*else if (strText == QString::fromLocal8Bit("�޸�"))
			{
				ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAS014");
				ModifyPwdWidget*	pWidget = new ModifyPwdWidget(m_strUid, m_strToken, this);
				connect(pWidget, &ModifyPwdWidget::sigResetPwdSucessed, this, &AccSettingWidget::onResetPwdSucessed);
				connect(pWidget, &ModifyPwdWidget::sigForgetPwd, this, &AccSettingWidget::onForgetPwd);
				pWidget->show();
			}*/
		}
	}
	/*else if (target == ui.labelEmail2)
	{
		if (e->type() == QEvent::MouseButtonRelease)
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAS016");
			BindEmailWidget*	pWidget = new BindEmailWidget(m_strUid, m_strToken, this);
			connect(pWidget, &BindEmailWidget::sigBindEmailSucessed, this, &AccSettingWidget::onBindEmailSucessed);
			pWidget->show();
		}
	}
	else if (target == ui.labelAddr2)
	{
		if (e->type() == QEvent::MouseButtonRelease)
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAS020");
			AcceptAddressWidget*	pWidget = new AcceptAddressWidget(m_strUid, m_strToken, m_addrInfo, this);
			connect(pWidget, &AcceptAddressWidget::sigUpdateAddrSucessed, this, &AccSettingWidget::onUpdateAddrSucessed);
			pWidget->show();
		}
	}*/
	//return QWidget::eventFilter(target, e);
	return NULL;
}

void UserCenterAccWidget::init(EntCenterInfo*	info111,  UserInfoStruct* info)
{
	QString strRet;

	QString m_bHasMember = m_userInfo->m_bHasMember;
	QString strCompName = m_userInfo->m_strCompanyName;
	QString strTaxNo = m_userInfo->m_strTaxNumber;
	if (strCompName.isEmpty())
	{
		if (1 == m_userInfo->m_bLoginByTax)
		{
			strCompName = QString::fromLocal8Bit("��δ��ѯ��������ҵ");
		}
		else
		{
			QString strUserName = m_userInfo->m_strUsername;
			if (strUserName.isEmpty() || strUserName.contains("wechat_") || strUserName.contains("nick_") || strUserName.contains("user_"))
			{
				if (m_userInfo->m_strMobile.isEmpty())
				{
					strCompName = QString::fromLocal8Bit("����");
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
	


	
	//!������ְ��
	if (m_userInfo->m_strTruename.isEmpty())
	{
		ui.labelFirstName->setText("");
		ui.labelFirstName->setStyleSheet("background:rgba(222,222,222,1);border-radius:15px;");
		ui.labelUserName->setText(QString::fromLocal8Bit("����"));
	}
	else
	{
		QString  name = m_userInfo->m_strTruename;
		ui.labelFirstName->setStyleSheet("background:rgba(95,217,153,1);border-radius:15px;font:14px \"΢���ź�\";color:#FDFDFD;");
		ui.labelFirstName->setText(name.left(1));
		ui.labelUserName->setText(name);
		ui.labelUserName->adjustSize();
	}
	ui.labelJob->setText(this->m_userInfo->m_strJob);


	//!�ֻ�����
	QString m_strMobile = m_userInfo->m_strMobile;
	if (m_strMobile.isEmpty())
	{
		ui.labelPhone->setText(QString::fromLocal8Bit("���ֻ��ſ��԰������һ�����"));
		ui.labelPhoneIcon->setStyleSheet("border-image:url(:/EntCenterWidget/image/unsetted.png);");
		ui.labelPhone1->setText(QString::fromLocal8Bit("δ��"));
		ui.labelPhone1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#FF9930;border-bottom:0px;}"));
		ui.labelPhone2->setText(QString::fromLocal8Bit("��"));
	}
	else
	{
		if (m_strMobile.size() == 11)
		{
			QString strText = QString::fromLocal8Bit("<font color=#666666>���Ѱ����ֻ�</font><font color=#47C382>%1****%2</font><font color=#666666>���������һص�¼���롿</font>")
				.arg(m_strMobile.mid(0, 3)).arg(m_strMobile.mid(7, 4));
			ui.labelPhone->setText(strText);
			ui.labelPhone->adjustSize();
			ui.labelPhoneIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/setted.png);");
			ui.labelPhone1->setText(QString::fromLocal8Bit("�Ѱ�"));
			ui.labelPhone1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#47C382;border-bottom:0px;}"));
			ui.labelPhone2->setText(QString::fromLocal8Bit("�޸�"));
		}
	}

	//!��¼����
	//int nSetPwd = data.take("is_set_password").toInt();
	//if (1 != nSetPwd)
	//{
		ui.labelPwd->setText(QString::fromLocal8Bit("��¼�Ʋ�˰ʱ��Ҫ���������"));
		ui.labelPwdIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/unsetted.png);");
		ui.labelPwd1->setText(QString::fromLocal8Bit("δ����"));
		ui.labelPwd1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#FF9930;border-bottom:0px;}"));
		ui.labelPwd2->setText(QString::fromLocal8Bit("����"));
	//}
	//else
	//{
	//	ui.labelPwd->setText(QString::fromLocal8Bit("���������˵�¼����"));
	//	ui.labelPwdIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/setted.png);");
	//	ui.labelPwd1->setText(QString::fromLocal8Bit("������"));
	//	ui.labelPwd1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#47C382;border-bottom:0px;}"));
	//	ui.labelPwd2->setText(QString::fromLocal8Bit("�޸�"));
	//}

	////!����
	//QString strEmail = data.take("email").toString();
	//if (strEmail.isEmpty())
	//{
	//	ui.labelEmail->setText(QString::fromLocal8Bit("�󶨺�ɽ��յ��ӷ�Ʊ"));
	//	ui.labelEmailIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/unsetted.png);");
	//	ui.labelEmail1->setText(QString::fromLocal8Bit("δ��"));
	//	ui.labelEmail1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#FF9930;border-bottom:0px;}"));
	//	ui.labelEmail2->setText(QString::fromLocal8Bit("��"));
	//}
	//else
	//{
	//	QString strText = QString::fromLocal8Bit("<font color=#666666>���Ѱ�������</font><font color=#47C382>%1****%2</font>")
	//		.arg(strEmail.mid(0, 3)).arg(strEmail.mid(7, strEmail.length() - 7));
	//	ui.labelEmail->setText(strText);
	//	ui.labelEmail->adjustSize();
	//	ui.labelEmailIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/setted.png);");
	//	ui.labelEmail1->setText(QString::fromLocal8Bit("�Ѱ�"));
	//	ui.labelEmail1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#47C382;border-bottom:0px;}"));
	//	ui.labelEmail2->setText(QString::fromLocal8Bit("�޸�"));
	//}

	////!�ջ���ַ
	//QJsonObject objAddr = data.take("recv_address").toObject();
	//if (objAddr.isEmpty())
	//{
	//	ui.labelAddr->setText(QString::fromLocal8Bit("Ϊ�������յ����Ʒ������д��ʵ���ջ���Ϣ"));
	//	ui.labelAddrIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/unsetted.png);");
	//	ui.labelAddr1->setText(QString::fromLocal8Bit("δ����"));
	//	ui.labelAddr1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#FF9930;border-bottom:0px;}"));
	//	ui.labelAddr2->setText(QString::fromLocal8Bit("����"));
	//}
	//else
	//{
	//	ui.labelAddr->setText(QString::fromLocal8Bit("�����������ջ���ַ"));
	//	ui.labelAddrIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/setted.png);");
	//	ui.labelAddr1->setText(QString::fromLocal8Bit("������"));
	//	ui.labelAddr1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#47C382;border-bottom:0px;}"));
	//	ui.labelAddr2->setText(QString::fromLocal8Bit("�޸�"));


	//	m_addrInfo._strTureName = objAddr.take("true_name").toString();
	//	m_addrInfo._strMobile = objAddr.take("phone").toString();
	//	m_addrInfo._nProId = objAddr.take("province_id").toString().toInt();
	//	m_addrInfo._nCityId = objAddr.take("city_id").toString().toInt();
	//	m_addrInfo._nAreaId = objAddr.take("area_id").toString().toInt();
	//	m_addrInfo._strAddr = objAddr.take("address").toString();
	//}
	//


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
			EntInfoWidget*	pEntInfoWidget = new EntInfoWidget(m_userInfo,m_pentinfo, this);
			pEntInfoWidget->show();
		}
	}	
}


void UserCenterAccWidget::onBindMobileSucessed(int nCoin, bool bPerfect)
{
	if (m_userInfo->m_strMobile.isEmpty())
	{
		ui.labelPhone->setText(QString::fromLocal8Bit("���ֻ��ſ��԰������һ�����"));
		ui.labelPhoneIcon->setStyleSheet("border-image:url(:/EntCenterWidget/image/unsetted.png);");
		ui.labelPhone1->setText(QString::fromLocal8Bit("δ��"));
		ui.labelPhone1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#FF9930;border-bottom:0px;}"));
		ui.labelPhone2->setText(QString::fromLocal8Bit("��"));
	}
	else
	{
		if (m_userInfo->m_strMobile.size() == 11)
		{
			QString strText = QString::fromLocal8Bit("<font color=#666666>���Ѱ����ֻ�</font><font color=#47C382>%1****%2</font><font color=#666666>���������һص�¼���롿</font>")
				.arg(m_userInfo->m_strMobile.mid(0, 3)).arg(m_userInfo->m_strMobile.mid(7, 4));
			ui.labelPhone->setText(strText);
			ui.labelPhone->adjustSize();
			ui.labelPhoneIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/setted.png);");
			ui.labelPhone1->setText(QString::fromLocal8Bit("�Ѱ�"));
			ui.labelPhone1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#47C382;border-bottom:0px;}"));
			ui.labelPhone2->setText(QString::fromLocal8Bit("�޸�"));
		}
	}

	if (bPerfect)
	{
		emit sigChangeCoin(nCoin);
	}
	BindMobileWidget*	pWidget = qobject_cast<BindMobileWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
	emit sigBindMobileSucessed(m_userInfo->m_strMobile);
}



void UserCenterAccWidget::onModifyUserInfoSucessed(int nCoin, bool bPerfect)
{
	QString strTrueName = this->m_userInfo->m_strTruename;
	if (strTrueName.isEmpty())
	{
		ui.labelFirstName->setText("");
		ui.labelTrueName->setText(QString::fromLocal8Bit("����"));
	}
	else
	{
		ui.labelFirstName->setText(strTrueName.left(1));
		ZcloudComFun::setElideText(14, ui.labelTrueName, strTrueName);
	}
	QString strJob = this->m_userInfo->m_strJob;
	if (strJob.isEmpty())
	{
		strJob = QString::fromLocal8Bit("����");
	}
	ZcloudComFun::setElideText(14, ui.labelJob, strJob);

	if (bPerfect)
	{
		emit sigChangeCoin(nCoin);
	}
	ModifyUserInfoWidget*	pWidget = qobject_cast<ModifyUserInfoWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
	emit sigEditUserInfoSucessed(this->m_userInfo->m_strTruename, this->m_userInfo->m_strJob);
}


void UserCenterAccWidget::onSetPwdSucessed(int nCoin, bool bPerfect)
{
	ui.labelPwd->setText(QString::fromLocal8Bit("���������˵�¼����"));
	ui.labelPwdIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/setted.png);");
	ui.labelPwd1->setText(QString::fromLocal8Bit("������"));
	ui.labelPwd1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#47C382;border-bottom:0px;}"));
	ui.labelPwd2->setText(QString::fromLocal8Bit("�޸�"));
	if (bPerfect)
	{
		emit sigChangeCoin(nCoin);
	}
	SetPwdWidget*	pWidget = qobject_cast<SetPwdWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
}