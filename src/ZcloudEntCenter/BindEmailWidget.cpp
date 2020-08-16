#include "BindEmailWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include "ZcloudBigData.h"

BindEmailWidget::BindEmailWidget(QString strUid, QString strToken, QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
{
	ui.setupUi(this);
	resize(454, 254);
	setWindowTitle(QString::fromLocal8Bit("邮箱绑定"));
	setAttribute(Qt::WA_DeleteOnClose);
	setAttribute(Qt::WA_ShowModal, true);
	setObjectName("bindEmial");

	ui.label_6->hide();
	ui.label_9->hide();

	connect(ui.lineEditEmail, &QLineEdit::editingFinished, this, &BindEmailWidget::onEmailEditingFinished);
	connect(ui.lineEditEmailCode, &QLineEdit::editingFinished, this, &BindEmailWidget::onEmailCodeEditingFinished);

	connect(ui.sendCodeButton, &QPushButton::clicked, this, &BindEmailWidget::onSendCodeBtnClick);
	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});

	connect(ui.okButton, &QPushButton::clicked, this, &BindEmailWidget::onBindEmailOkBtnClick);
	connect(ui.cancelButton, &QPushButton::clicked, [this](){
		close();
	});
	connect(&timer, &QTimer::timeout, [this]{
		if (m_nCountDown > 0)
		{
			ui.sendCodeButton->setEnabled(false);
			ui.sendCodeButton->setText(QString::fromLocal8Bit("%1后重发").arg(m_nCountDown--));
		}
		else
		{
			timer.stop();
			ui.sendCodeButton->setEnabled(true);
			m_nCountDown = 60;
			ui.sendCodeButton->setText(QString::fromLocal8Bit("发送验证码"));
		}
	});
}

BindEmailWidget::~BindEmailWidget()
{
}

void BindEmailWidget::onEmailEditingFinished()
{
	QRegExp reg("^([0-9A-Za-z\\-_\\.]+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)$");
	QString strText = ui.lineEditEmail->text();
	if (strText.isEmpty())
	{
		m_bEmail = false;
		ui.label_6->show();
	}
	if (!reg.exactMatch(strText))
	{
		m_bEmail = false;
		ui.label_6->show();
	}
	else
	{
		m_bEmail = true;
		ui.label_6->hide();
	}
}

void BindEmailWidget::onEmailCodeEditingFinished()
{
	QRegExp reg("\\d{6}$");
	QString strText = ui.lineEditEmailCode->text();
	if (strText.isEmpty())
	{
		m_bEmailCode = false;
		ui.label_9->show();
	}
	if (!reg.exactMatch(strText))
	{
		m_bEmailCode = false;
		ui.label_9->show();
	}
	else
	{
		m_bEmailCode = true;
		ui.label_9->hide();
	}
}

void BindEmailWidget::onBindEmailOkBtnClick()
{
	if (!m_bEmail)
	{
		ui.label_6->show();
		
	}
	if (!m_bEmailCode)
	{
		ui.label_9->show();
		
	}

	if (!m_bEmail || !m_bEmailCode)
	{
		return;
	}
	if (timer.isActive())
	{
		timer.stop();
		ui.sendCodeButton->setEnabled(true);
		m_nCountDown = 60;
		ui.sendCodeButton->setText(QString::fromLocal8Bit("发送验证码"));
	}
	QString strRet;
	if (!winHttpBindEmail(m_strUid, m_strToken, ui.lineEditEmail->text(), ui.lineEditEmailCode->text(), strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n绑定邮箱失败，请稍后再试！"));
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
	int status	= obj.take("status").toInt();
	QJsonObject data = obj.take("data").toObject();
	if (0 == status)
	{
		QString strEmail = ui.lineEditEmail->text();
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "BAS017", strEmail);
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n绑定邮箱成功！"));
		emit sigBindEmailSucessed(strEmail, data.take("coin").toInt(), (1 == data.take("perfect").toInt()) ? true : false);
	}
	else if (10016 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n邮箱不能为空！"));
	}
	else if (20021 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n验证码不能为空！"));
	}
	else if (30017 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n验证码类型不正确！"));
	}
	else if (30020 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n验证码过期！"));
	}
	else if (30021 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n验证码错误！"));
	}
	else
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n绑定邮箱失败，请稍后再试！"));
	}
}

void BindEmailWidget::onSendCodeBtnClick()
{
	if (!m_bEmail)
	{
		ui.label_6->show();
		return;
	}
	QString strRet;
	if (!winHttpSendEmail(m_strUid,m_strToken, ui.lineEditEmail->text(), strRet))
	{
		ui.label_6->setText(QString::fromLocal8Bit("发送验证码失败，请稍后再试"));
		ui.label_6->show();
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
	else if (20030 == status)
	{
		ui.label_6->setText(QString::fromLocal8Bit("邮箱不能为空"));
		ui.label_6->show();
	}
	else if (10016 == status)
	{
		ui.label_6->setText(QString::fromLocal8Bit("邮箱不正确"));
		ui.label_6->show();
	}
	else if (30017 == status)
	{
		ui.label_6->setText(QString::fromLocal8Bit("验证码类型不正确"));
		ui.label_6->show();
	}
	else if (30018 == status)
	{
		ui.label_6->setText(QString::fromLocal8Bit("验证码发送太频繁，请稍后再试"));
		ui.label_6->show();
	}
}

bool BindEmailWidget::winHttpSendEmail(QString strUid, QString strToken, QString strEmail, QString& strRet)
{
	QString strUrl = QString("/general/send-mail?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("mail=%1&type=bind_email").arg(strEmail);
	return ZcloudComFun::httpPost(strUrl, strPost, 10000, strRet);
}

bool BindEmailWidget::winHttpBindEmail(QString strUid, QString strToken, QString strEmail, QString strCode, QString& strRet)
{
	QString strUrl = QString("/v2/user/update-email?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("email=%1&type=bind_email&check_code=%2").arg(strEmail).arg(strCode);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}
