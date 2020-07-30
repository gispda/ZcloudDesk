#include "AccSettingWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include "ModifyUserInfoWidget.h"
#include "BindMobileWidget.h"
#include "BindEmailWidget.h"
#include "ModifyPwdWidget.h"
#include "SetPwdWidget.h"
#include "ZcloudBigData.h"

AccSettingWidget::AccSettingWidget(QString strUid, QString strToken, QString strTitle,QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
{
	ui.setupUi(getContentWidget());
	resize(800, 500);
	setWindowTitle(QString::fromLocal8Bit("�˺�����"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("accSetting");
	setAttribute(Qt::WA_ShowModal, true);
	ui.labelTitle->setText(strTitle);

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAS024");
		close();
	});

	if (!showAccSettingInfo())
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n���˺�����ʧ�ܣ����Ժ����ԣ�"));
		close();
	}
	ui.labelInfoEdit->installEventFilter(this);
	ui.labelPhone2->installEventFilter(this);
	ui.labelPwd2->installEventFilter(this);
	ui.labelEmail2->installEventFilter(this);
	ui.labelAddr2->installEventFilter(this);
}

AccSettingWidget::~AccSettingWidget()
{
}

bool AccSettingWidget::winHttpGetAccountSetting(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/v2/user/account-setting?user_id=%1&token=%2").arg(strUid).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

bool AccSettingWidget::showAccSettingInfo()
{
	QString strRet;
	if (!winHttpGetAccountSetting(m_strUid, m_strToken, strRet))
	{
		return false;
	}
	QByteArray byte_array = strRet.toUtf8();
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
	if (0 != status)
	{
		return false;
	}

	QJsonObject data	=	obj.take("data").toObject();
	QString strUserName =	data.take("username").toString();
	if (strUserName.isEmpty() || strUserName.contains("wechat_") || strUserName.contains("nick_") || strUserName.contains("user_"))
	{
		strUserName = QString::fromLocal8Bit("����");
	}
	ui.labelUserName->setText(strUserName);
	ui.labelUserName->adjustSize();

	m_strTrueName = data.take("truename").toString();
	QString strTrueName = m_strTrueName;
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

	m_strJob = data.take("job").toString();
	QString strJob = m_strJob;
	if (strJob.isEmpty())
	{
		strJob = QString::fromLocal8Bit("����");
	}
	ZcloudComFun::setElideText(14, ui.labelJob, strJob);

	//!�ֻ�����
	m_strMobile =  data.take("mobile").toString();
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
	int nSetPwd	= data.take("is_set_password").toInt();
	if (1 != nSetPwd)
	{
		ui.labelPwd->setText(QString::fromLocal8Bit("��¼�Ʋ�˰ʱ��Ҫ���������"));
		ui.labelPwdIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/unsetted.png);");
		ui.labelPwd1->setText(QString::fromLocal8Bit("δ����"));
		ui.labelPwd1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#FF9930;border-bottom:0px;}"));
		ui.labelPwd2->setText(QString::fromLocal8Bit("����"));
	}
	else
	{
		ui.labelPwd->setText(QString::fromLocal8Bit("���������˵�¼����"));
		ui.labelPwdIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/setted.png);");
		ui.labelPwd1->setText(QString::fromLocal8Bit("������"));
		ui.labelPwd1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#47C382;border-bottom:0px;}"));
		ui.labelPwd2->setText(QString::fromLocal8Bit("�޸�"));
	}

	//!����
	QString strEmail = data.take("email").toString();
	if (strEmail.isEmpty())
	{
		ui.labelEmail->setText(QString::fromLocal8Bit("�󶨺�ɽ��յ��ӷ�Ʊ"));
		ui.labelEmailIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/unsetted.png);");
		ui.labelEmail1->setText(QString::fromLocal8Bit("δ��"));
		ui.labelEmail1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#FF9930;border-bottom:0px;}"));
		ui.labelEmail2->setText(QString::fromLocal8Bit("��"));
	}
	else
	{
		QString strText = QString::fromLocal8Bit("<font color=#666666>���Ѱ�������</font><font color=#47C382>%1****%2</font>")
			.arg(strEmail.mid(0, 3)).arg(strEmail.mid(7, strEmail.length()-7));
		ui.labelEmail->setText(strText);
		ui.labelEmail->adjustSize();
		ui.labelEmailIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/setted.png);");
		ui.labelEmail1->setText(QString::fromLocal8Bit("�Ѱ�"));
		ui.labelEmail1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#47C382;border-bottom:0px;}"));
		ui.labelEmail2->setText(QString::fromLocal8Bit("�޸�"));
	}

	//!�ջ���ַ
	QJsonObject objAddr = data.take("recv_address").toObject();
	if (objAddr.isEmpty())
	{
		ui.labelAddr->setText(QString::fromLocal8Bit("Ϊ�������յ����Ʒ������д��ʵ���ջ���Ϣ"));
		ui.labelAddrIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/unsetted.png);");
		ui.labelAddr1->setText(QString::fromLocal8Bit("δ����"));
		ui.labelAddr1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#FF9930;border-bottom:0px;}"));
		ui.labelAddr2->setText(QString::fromLocal8Bit("����"));
	}
	else
	{
		ui.labelAddr->setText(QString::fromLocal8Bit("�����������ջ���ַ"));
		ui.labelAddrIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/setted.png);");
		ui.labelAddr1->setText(QString::fromLocal8Bit("������"));
		ui.labelAddr1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#47C382;border-bottom:0px;}"));
		ui.labelAddr2->setText(QString::fromLocal8Bit("�޸�"));


		m_addrInfo._strTureName = objAddr.take("true_name").toString();
		m_addrInfo._strMobile	= objAddr.take("phone").toString();
		m_addrInfo._nProId		= objAddr.take("province_id").toString().toInt();
		m_addrInfo._nCityId		= objAddr.take("city_id").toString().toInt();
		m_addrInfo._nAreaId		= objAddr.take("area_id").toString().toInt();
		m_addrInfo._strAddr		= objAddr.take("address").toString();
	}
	return true;
}

bool AccSettingWidget::eventFilter(QObject *target, QEvent *e)
{
	if (target == ui.labelInfoEdit)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAS001");
			ModifyUserInfoWidget*	pWidget = new ModifyUserInfoWidget(m_strTrueName,m_strJob,m_strUid,m_strToken,this);
			connect(pWidget, &ModifyUserInfoWidget::sigModifySucessed, this, &AccSettingWidget::onModifyUserInfoSucessed);
			pWidget->show();
		}
	}
	else if (target == ui.labelPhone2)
	{
		if (e->type() == QEvent::MouseButtonRelease)
		{
			QString strOperId = m_strMobile.isEmpty() ? "BAS004" : "BAS008";
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", strOperId);
			BindMobileWidget*	pWidget = new BindMobileWidget(m_strMobile, m_strUid, m_strToken,false, this);
			connect(pWidget, &BindMobileWidget::sigBindMobileSucessed, this, &AccSettingWidget::onBindMobileSucessed);
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
				SetPwdWidget*	pWidget = new SetPwdWidget(m_strUid, m_strToken, this);
				connect(pWidget, &SetPwdWidget::sigSetPwdSucessed, this, &AccSettingWidget::onSetPwdSucessed);
				pWidget->show();
			}
			else if (strText == QString::fromLocal8Bit("�޸�"))
			{
				ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAS014");
				ModifyPwdWidget*	pWidget = new ModifyPwdWidget(m_strUid, m_strToken, this);
				connect(pWidget, &ModifyPwdWidget::sigResetPwdSucessed, this, &AccSettingWidget::onResetPwdSucessed);
				connect(pWidget, &ModifyPwdWidget::sigForgetPwd, this, &AccSettingWidget::onForgetPwd);
				pWidget->show();
			}	
		}
	}
	else if (target == ui.labelEmail2)
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
	}
	return QWidget::eventFilter(target, e);
}

void AccSettingWidget::onModifyUserInfoSucessed(int nCoin, bool bPerfect)
{
	QString strTrueName = m_strTrueName;
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
	QString strJob = m_strJob;
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
	emit sigEditUserInfoSucessed(m_strTrueName, m_strJob);
}

void AccSettingWidget::onBindMobileSucessed(int nCoin, bool bPerfect)
{
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

	if (bPerfect)
	{
		emit sigChangeCoin(nCoin);
	}
	BindMobileWidget*	pWidget = qobject_cast<BindMobileWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
	emit sigBindMobileSucessed(m_strMobile);
}

void AccSettingWidget::onBindEmailSucessed(QString strEmail, int nCoin, bool bPerfect)
{
	if (strEmail.isEmpty())
	{
		ui.labelEmail->setText(QString::fromLocal8Bit("�󶨺�ɽ��յ��ӷ�Ʊ"));
		ui.labelEmailIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/unsetted.png);");
		ui.labelEmail1->setText(QString::fromLocal8Bit("δ��"));
		ui.labelEmail1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#FF9930;border-bottom:0px;}"));
		ui.labelEmail2->setText(QString::fromLocal8Bit("��"));
	}
	else
	{
		QString strText = QString::fromLocal8Bit("<font color=#666666>���Ѱ�������</font><font color=#47C382>%1****%2</font>")
			.arg(strEmail.mid(0, 3)).arg(strEmail.mid(7, strEmail.length() - 7));
		ui.labelEmail->setText(strText);
		ui.labelEmail->adjustSize();
		ui.labelEmailIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/setted.png);");
		ui.labelEmail1->setText(QString::fromLocal8Bit("�Ѱ�"));
		ui.labelEmail1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#47C382;border-bottom:0px;}"));
		ui.labelEmail2->setText(QString::fromLocal8Bit("�޸�"));
	}
	if (bPerfect)
	{
		emit sigChangeCoin(nCoin);
	}
	BindEmailWidget*	pWidget = qobject_cast<BindEmailWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
}

void AccSettingWidget::onUpdateAddrSucessed(int nCoin, bool bPerfect, AddressInfo  addrInfo)
{
	ui.labelAddr->setText(QString::fromLocal8Bit("�����������ջ���ַ"));
	ui.labelAddrIcon->setStyleSheet("border-image: url(:/EntCenterWidget/image/setted.png);");
	ui.labelAddr1->setText(QString::fromLocal8Bit("������"));
	ui.labelAddr1->setStyleSheet(QString::fromLocal8Bit("QLabel{font:14px \"΢���ź�\";color:#47C382;border-bottom:0px;}"));
	ui.labelAddr2->setText(QString::fromLocal8Bit("�޸�"));
	if (bPerfect)
	{
		emit sigChangeCoin(nCoin);
	}
	m_addrInfo = addrInfo;
	AcceptAddressWidget*	pWidget = qobject_cast<AcceptAddressWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
}

void AccSettingWidget::onResetPwdSucessed(int nCoin, bool bPerfect)
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
	ModifyPwdWidget*	pWidget = qobject_cast<ModifyPwdWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
}

void AccSettingWidget::onSetPwdSucessed(int nCoin, bool bPerfect)
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

void AccSettingWidget::onForgetPwd()
{
	ModifyPwdWidget*	pWidget = qobject_cast<ModifyPwdWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}

	if (m_strMobile.isEmpty())
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�ֻ��Ų�����,���Ȱ��ֻ�\r\n�ٽ��������һأ�"));
	}
	else
	{
		BindMobileWidget*	pWidget = new BindMobileWidget(m_strMobile, m_strUid, m_strToken, true, this);
		connect(pWidget, &BindMobileWidget::sigCheckForgetPwdSucessed, this, &AccSettingWidget::onCheckForgetPwdSucessed);
		pWidget->show();
	}
}

void AccSettingWidget::onCheckForgetPwdSucessed()
{
	BindMobileWidget*	pWidget = qobject_cast<BindMobileWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
	SetPwdWidget*	pPwdWidget = new SetPwdWidget(m_strUid, m_strToken, this);
	connect(pPwdWidget, &SetPwdWidget::sigSetPwdSucessed, this, &AccSettingWidget::onSetPwdSucessed);
	pPwdWidget->show();
}
