#include "AddMemberWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include "ZcloudBigData.h"

AddMemberWidget::AddMemberWidget(QString strUid,QString strToken,QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
{
	ui.setupUi(getContentWidget());
	resize(454, 366);
	setWindowTitle(QString::fromLocal8Bit("添加成员"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("addMember");
	setAttribute(Qt::WA_ShowModal, true);

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAC006");
		close();
	});

	connect(ui.okButton, &QPushButton::clicked, this, &AddMemberWidget::onAddOkBtnClick);
	connect(ui.cancelButton, &QPushButton::clicked, [this](){
		close();
	});
	ui.label_7->hide();
	ui.label_8->hide();


	ui.label_6->hide();
	ui.labelJobErr->hide();
	ui.labelPhoneErr->hide();

	connect(ui.lineEditName, &QLineEdit::editingFinished, this, &AddMemberWidget::onNameEditingFinished);
	connect(ui.lineEditAcc, &QLineEdit::editingFinished, this, &AddMemberWidget::onAccEditingFinished);
	connect(ui.lineEditPwd, &QLineEdit::editingFinished, this, &AddMemberWidget::onPwdEditingFinished);
	//connect(ui.lineEditJob, &QLineEdit::editingFinished, this, &AddMemberWidget::onJobEditingFinished);
	connect(ui.lineEditPhone, &QLineEdit::editingFinished, this, &AddMemberWidget::onPhoneEditingFinished);
}

AddMemberWidget::~AddMemberWidget()
{
}

void AddMemberWidget::onAddOkBtnClick()
{
	if (!onNameEditingFinished()||ui.lineEditName->text().isEmpty())
	{
		ui.label_6->show();
		return;
	}

	if (!onPhoneEditingFinished()||ui.lineEditPhone->text().isEmpty())
	{
		ui.labelPhoneErr->show();
		return;
	}


	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAC003");
	QString strRet;
	if (!winHttpAddMember(m_strUid, m_strToken, ui.lineEditName->text(), ui.lineEditPhone->text(),  ui.lineEditJob->text(),strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n新增财务成员失败，请稍后再试！"));
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
	if (0 == status)
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "BAC004");
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n新增财务成员成功！"));
		emit sigAddMember();
	}
	else
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M10", "OP000", "BAC005", QString("%1").arg(status));
		if (30069 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n对不起，您没有操作权限！"));
		}
		else if (10014 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n姓名填写不正确！"));
		}
		else if (10007 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n账号填写不正确！"));
		}
		else if (10008 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n密码填写不正确！"));
		}
		else if (30025 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n对不起，账号已存在！"));
		}
		else if (30005 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n对不起，创建用户失败！"));
		}
		else if (10015 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n职务填写不正确！"));
		}
		else
		{

			QString msg = obj.value("msg").toString();
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), msg);
		}
	}		
}

bool AddMemberWidget::winHttpAddMember(QString strUid, QString strToken, QString username, QString strAcc, QString strJob, QString& strRet)
{
	//QString strUrl = QString("/v2/company/set-member-info?user_id=%1&token=%2").arg(strUid).arg(strToken);
	//QString strPost = QString("action_type=add&true_name=%1&account=%2&password=%3&job=%4").arg(strTrueName).arg(strAcc).arg(strPwd).arg(strJob);
	//return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);

	QString strUrl = QString("/ucenter/user/bind-member");
	QString strPost = QString("token=%1&username=%2&account=%3&job=%4").arg(strToken).arg(username).arg(strAcc).arg(strJob);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet,false,1);
}

bool AddMemberWidget::onNameEditingFinished()
{
	QRegExp	reg(".{2,20}");
	QString strText = ui.lineEditName->text();
	if (strText.isEmpty())
	{
		m_bName = true;
		ui.label_6->hide();
		return false;
	}
	if (!reg.exactMatch(strText))
	{
		m_bName = false;
		ui.label_6->show();
		return false;
	}
	else
	{
		m_bName = true;
		ui.label_6->hide();
		return true;
	}
}

void AddMemberWidget::onAccEditingFinished()
{
	QRegExp	reg("^[a-zA-Z][a-zA-Z0-9_]{5,19}$");
	QString strText = ui.lineEditAcc->text();
	if (!reg.exactMatch(strText))
	{
		m_bAcc = false;
		ui.label_7->show();
		ZcloudBigDataInterface::GetInstance()->produceData("M10", "OP000", "BAC001");
	}
	else
	{
		m_bAcc = true;
		ui.label_7->hide();
	}
}

void AddMemberWidget::onPwdEditingFinished()
{
	QRegExp	reg(".{8,20}");
	QString strText = ui.lineEditPwd->text();
	if (!reg.exactMatch(strText))
	{
		m_bPwd = false;
		ui.label_8->show();
		ZcloudBigDataInterface::GetInstance()->produceData("M10", "OP000", "BAC002");
	}
	else
	{
		m_bPwd = true;
		ui.label_8->hide();
	}
}

bool AddMemberWidget::onPhoneEditingFinished(){
	QRegExp reg("^(13|14|15|17|18)\\d{9}$");
	QString strText = ui.lineEditPhone->text();
	if (strText.isEmpty())
	{
		ui.labelPhoneErr->hide();
		return false;
	}
	if (!reg.exactMatch(strText))
	{
		ui.labelPhoneErr->show();
		return false;
	}
	else
	{
		ui.labelPhoneErr->hide();
		return true;
	}
}


