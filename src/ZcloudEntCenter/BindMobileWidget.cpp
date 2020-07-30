#include "BindMobileWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include "ZcloudBigData.h"


BindMobileWidget::BindMobileWidget(QString& strMobile, QString strUid, QString strToken, bool bResetPwd, QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
	, m_strMobile(strMobile)
	, m_bResetPwd(bResetPwd)
{
	ui.setupUi(getContentWidget());
	resize(454, 254);
	setWindowTitle(QString::fromLocal8Bit("�ֻ���"));
	setAttribute(Qt::WA_DeleteOnClose);
	setAttribute(Qt::WA_ShowModal, true);
	setObjectName("bindMobile");

	ui.label_11->hide();
	ui.label_9->hide();

	if (!strMobile.isEmpty())
	{
		ui.labelTitle->setText(QString::fromLocal8Bit("��֤ԭ�ֻ�"));
		ui.labelPhone->setFixedHeight(40);
		ui.labelPhone->move(ui.lineEditMobile->pos());
		ui.lineEditMobile->hide();
		QString strText = strMobile.mid(0, 3) + "****" + strMobile.mid(7, 4);
		ui.labelPhone->setText(strText);
		ui.labelPhone->show();
		m_bValidation = true;
		ui.okButton->setText(QString::fromLocal8Bit("��һ��"));
	}
	else
	{
		m_bValidation = false;
		ui.labelTitle->setText(QString::fromLocal8Bit("�ֻ���"));
		ui.labelPhone->hide();
	}

	connect(ui.lineEditMobile, &QLineEdit::editingFinished, this, &BindMobileWidget::onMobileEditingFinished);
	connect(ui.lineEditMobileCode, &QLineEdit::editingFinished, this, &BindMobileWidget::onMobileCodeEditingFinished);
	connect(ui.sendCodeButton, &QPushButton::clicked, this, &BindMobileWidget::onSendCodeBtnClick);
	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});

	connect(ui.okButton, &QPushButton::clicked, this, &BindMobileWidget::onBindMobileOkBtnClick);
	connect(ui.cancelButton, &QPushButton::clicked, [this](){
		close();
	});
	connect(&timer, &QTimer::timeout, [this]{
		if (m_nCountDown > 0)
		{
			ui.sendCodeButton->setEnabled(false);
			ui.sendCodeButton->setText(QString::fromLocal8Bit("%1���ط�").arg(m_nCountDown--));
		}
		else
		{
			timer.stop();
			ui.sendCodeButton->setEnabled(true);
			m_nCountDown = 60;
			ui.sendCodeButton->setText(QString::fromLocal8Bit("������֤��"));
		}
	});
}

BindMobileWidget::~BindMobileWidget()
{
}

void BindMobileWidget::onBindMobileOkBtnClick()
{
	QString strMobile;
	if (!m_bValidation)
	{
		if (!m_bMobile)
		{
			ui.label_11->show();
			return;
		}
		strMobile = ui.lineEditMobile->text();
	}
	else
	{
		strMobile = m_strMobile;
	}
	if (!m_bMobileCode)
	{
		ui.label_9->show();
		return;
	}
	if (timer.isActive())
	{
		timer.stop();
		ui.sendCodeButton->setEnabled(true);
		m_nCountDown = 60;
		ui.sendCodeButton->setText(QString::fromLocal8Bit("������֤��"));
	}
	if (QString::fromLocal8Bit("��һ��")	==	ui.okButton->text())
	{
		QString strRet, strCheckType;
		if (!m_bResetPwd)
		{
			strCheckType = "reset_mobile";
		}
		else
		{
			strCheckType = "forgot_password"; 
		}
		
		if (!winHttpCheckCode(strMobile, ui.lineEditMobileCode->text(), strCheckType, strRet))
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��֤ԭ�ֻ���ʧ�ܣ����Ժ����ԣ�"));
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
		int status = obj.take("status").toInt();
		if (0 == status)
		{ 
			if (!m_bResetPwd)
			{
				ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "BAS011");
				m_bValidation = false;
				ui.labelPhone->hide();
				ui.lineEditMobile->clear();
				ui.lineEditMobile->show();
				ui.okButton->setText(QString::fromLocal8Bit("ȷ��"));
				ui.lineEditMobileCode->clear();
				ui.labelTitle->setText(QString::fromLocal8Bit("�����ֻ���"));
			}
			else
			{
				emit sigCheckForgetPwdSucessed();
			}
		}
		else
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "BAS010", QString("%1").arg(status));
			if (20019 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n�ֻ��Ų���Ϊ�գ�"));
			}
			else if (10004 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n�ֻ��Ų���ȷ��"));
			}
			else if (20021 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��֤�벻��Ϊ�գ�"));
			}
			else if (30017 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��֤�����Ͳ���ȷ��"));
			}
			else if (30020 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��֤����ڣ�"));
			}
			else if (30021 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��֤�����"));
			}
			else if (30032 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n�ֻ����Ѵ��ڣ�"));
			}
			else
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��֤ԭ�ֻ���ʧ�ܣ����Ժ����ԣ�"));
			}
		}
	}
	else if (QString::fromLocal8Bit("ȷ��") == ui.okButton->text())
	{
		QString strRet;
		if (!winHttpBindMobile(m_strUid, m_strToken, ui.lineEditMobile->text(), ui.lineEditMobileCode->text(), "bind_mobile",strRet))
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n���ֻ���ʧ�ܣ����Ժ����ԣ�"));
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
		int status = obj.take("status").toInt();
		QJsonObject data = obj.take("data").toObject();
		if (0 == status)
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "BAS007");
			m_strMobile = ui.lineEditMobile->text();
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("�����ɹ�"), QString::fromLocal8Bit("\r\n���ֻ��ųɹ���"));
			emit sigBindMobileSucessed(data.take("coin").toInt(), (1 == data.take("perfect").toInt()) ? true : false);
		}
		else
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "BAS006", QString("%1").arg(status));
			if (20019 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n�ֻ��Ų���Ϊ�գ�"));
			}
			else if (10004 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n�ֻ��Ų���ȷ��"));
			}
			else if (20021 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��֤�벻��Ϊ�գ�"));
			}
			else if (30017 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��֤�����Ͳ���ȷ��"));
			}
			else if (30020 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��֤����ڣ�"));
			}
			else if (30021 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��֤�����"));
			}
			else if (30032 == status)
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n�ֻ����Ѵ��ڣ�"));
			}
			else
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n���ֻ���ʧ�ܣ����Ժ����ԣ�"));
			}
		}
	}
}

void BindMobileWidget::onMobileEditingFinished()
{
	QRegExp reg("^1\\d{10}$");
	QString strText = ui.lineEditMobile->text();
	if (strText.isEmpty())
	{
		m_bMobile = false;
		ui.label_11->show();
	}
	if (!reg.exactMatch(strText))
	{
		m_bMobile = false;
		ui.label_11->show();
	}
	else
	{
		m_bMobile = true;
		ui.label_11->hide();
	}
}

void BindMobileWidget::onSendCodeBtnClick()
{
	QString strMobile,strCodeType;
	if (!m_bValidation)
	{
		if (!m_bMobile)
		{
			ui.label_11->show();
			return;
		}
		strMobile = ui.lineEditMobile->text();
		strCodeType = "bind_mobile";
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAS005");
	}
	else
	{
		strMobile = m_strMobile;
		if (!m_bResetPwd)
		{
			strCodeType = "reset_mobile";
		}
		else
		{
			strCodeType = "forgot_password";
		}
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAS009");
	}
	QString strRet;
	if (!winHttpSendCode(strMobile, strCodeType,strRet))
	{
		ui.label_9->setText(QString::fromLocal8Bit("������֤��ʧ�ܣ����Ժ�����"));
		ui.label_9->show();
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
	int status = obj.take("status").toInt();
	if (0 == status)
	{
		timer.start(1000);
	}
	else if (20019 == status)
	{
		ui.label_9->setText(QString::fromLocal8Bit("�ֻ��Ų���Ϊ��"));
		ui.label_9->show();
	}
	else if (10004 == status)
	{
		ui.label_9->setText(QString::fromLocal8Bit("�ֻ��Ų���ȷ"));
		ui.label_9->show();
	}
	else if (30017 == status)
	{
		ui.label_9->setText(QString::fromLocal8Bit("��֤�����Ͳ���ȷ"));
		ui.label_9->show();
	}
	else if (30048 == status)
	{
		ui.label_9->setText(QString::fromLocal8Bit("���ֻ��Ų�����"));
		ui.label_9->show();
	}
	else if (30018 == status)
	{
		ui.label_9->setText(QString::fromLocal8Bit("��֤�뷢��̫Ƶ�������Ժ�����"));
		ui.label_9->show();
	}
}

bool BindMobileWidget::winHttpSendCode(QString strMobile, QString strCodeType, QString& strRet)
{
	QString strUrl = QString("/general/send-captcha");
	QString strPost = QString("mobile=%1&type=%2").arg(strMobile).arg(strCodeType);
	return ZcloudComFun::httpPost(strUrl, strPost, 10000, strRet);
}

void BindMobileWidget::onMobileCodeEditingFinished()
{
	QRegExp reg("\\d{6}$");
	QString strText = ui.lineEditMobileCode->text();
	if (strText.isEmpty())
	{
		m_bMobileCode = false;
		ui.label_9->show();
	}
	if (!reg.exactMatch(strText))
	{
		m_bMobileCode = false;
		ui.label_9->show();
	}
	else
	{
		m_bMobileCode = true;
		ui.label_9->hide();
	}
}

bool BindMobileWidget::winHttpBindMobile(QString strUid, QString strToken, QString strMobile, QString strMobileCode, QString strCodeType, QString& strRet)
{
	QString strUrl = QString("/v2/user/update-mobile?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("mobile=%1&check_code=%2&type=%3").arg(strMobile).arg(strMobileCode).arg(strCodeType);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

bool BindMobileWidget::winHttpCheckCode(QString strMobile,QString strCode, QString strCodeType, QString& strRet)
{
	QString strUrl = QString("/general/check-captcha");
	QString strPost = QString("mobile=%1&type=%2&check_code=%3").arg(strMobile).arg(strCodeType).arg(strCode);
	return ZcloudComFun::httpPost(strUrl, strPost, 10000, strRet);
}
