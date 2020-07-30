#include "ModifyPwdWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include "ZcloudBigData.h"

ModifyPwdWidget::ModifyPwdWidget(QString strUid, QString strToken,QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
{
	ui.setupUi(getContentWidget());
	resize(454, 323);
	setWindowTitle(QString::fromLocal8Bit("修改密码"));
	setAttribute(Qt::WA_DeleteOnClose);
	setAttribute(Qt::WA_ShowModal, true);
	setObjectName("modifyPwd");

	ui.label_8->hide();
	ui.label_9->hide();
	ui.label_10->hide();

	ui.labelForgetPwd->installEventFilter(this);
	connect(ui.lineEditOldPwd, &QLineEdit::editingFinished, this, &ModifyPwdWidget::onOldPwdEditBtnClick);
	connect(ui.lineEditNewPwd, &QLineEdit::editingFinished, this, &ModifyPwdWidget::onNewPwdEditBtnClick);
	connect(ui.lineEditComfirmPwd, &QLineEdit::editingFinished, this, &ModifyPwdWidget::onComfirmPwdEditBtnClick);

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});
	connect(ui.okButton, &QPushButton::clicked, this, &ModifyPwdWidget::onModifyOkBtnClick);
	connect(ui.cancelButton, &QPushButton::clicked, [this](){
		close();
	});
}

ModifyPwdWidget::~ModifyPwdWidget()
{
}

void ModifyPwdWidget::onModifyOkBtnClick()
{
	if (!m_bOldPwd)
	{
		ui.label_8->show();
	}
	if (!m_bNewPwd)
	{
		ui.label_9->show();
	}
	if (!m_bComfirmPwd)
	{
		ui.label_10->show();
	}
	if (!m_bOldPwd || !m_bNewPwd || !m_bComfirmPwd)
	{
		return;
	}
	if (ui.lineEditNewPwd->text() != ui.lineEditComfirmPwd->text())
	{
		ui.label_10->setText(QString::fromLocal8Bit("两次输入的密码不一致"));
		ui.label_10->show();
		return;
	}
	QString strRet;
	if (!winHttpResetPwd(m_strUid, m_strToken, ui.lineEditOldPwd->text(), ui.lineEditNewPwd->text(), ui.lineEditComfirmPwd->text(), strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n修改密码失败，请稍后再试！"));
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
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "BAS015");
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n修改密码成功！"));
		emit sigResetPwdSucessed(data.take("coin").toInt(), (1 == data.take("perfect").toInt()) ? true : false);
	}
	else if (10008 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n密码格式不正确！"));
	}
	else if (30022 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n两次密码不一致！"));
	}
	else if (30023 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n旧密码不正确！"));
	}
	else if (30024 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n手机验证超时！"));
	}
	else
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n修改密码失败，请稍后再试！"));
	}
}

void ModifyPwdWidget::onOldPwdEditBtnClick()
{
	QRegExp	reg(".{8,20}");
	QString strText = ui.lineEditOldPwd->text();
	if (!reg.exactMatch(strText))
	{
		m_bOldPwd = false;
		ui.label_8->show();
	}
	else
	{
		m_bOldPwd = true;
		ui.label_8->hide();
	}
}

void ModifyPwdWidget::onNewPwdEditBtnClick()
{
	QRegExp	reg(".{8,20}");
	QString strText = ui.lineEditNewPwd->text();
	if (!reg.exactMatch(strText))
	{
		m_bNewPwd = false;
		ui.label_9->show();
	}
	else
	{
		m_bNewPwd = true;
		ui.label_9->hide();
	}
}

void ModifyPwdWidget::onComfirmPwdEditBtnClick()
{
	QRegExp	reg(".{8,20}");
	QString strText = ui.lineEditComfirmPwd->text();
	if (!reg.exactMatch(strText))
	{
		m_bComfirmPwd = false;
		ui.label_10->show();
	}
	else
	{
		m_bComfirmPwd = true;
		ui.label_10->hide();
	}
}

bool ModifyPwdWidget::winHttpResetPwd(QString strUid, QString strToken, QString strOldPwd, QString strNewPwd, QString strComfirmPwd, QString& strRet)
{
	QString strUrl = QString("/v2/user/reset-password?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("old_password=%1&new_password=%2&confirm_password=%3&type=modify")
		.arg(strOldPwd).arg(strNewPwd).arg(strComfirmPwd);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

bool ModifyPwdWidget::eventFilter(QObject *target, QEvent *e)
{
	if (target == ui.labelForgetPwd)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			emit sigForgetPwd();
		}
	}
	return QWidget::eventFilter(target, e);
}
