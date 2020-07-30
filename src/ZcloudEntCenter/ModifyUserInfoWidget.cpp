#include "ModifyUserInfoWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include "ZcloudBigData.h"

ModifyUserInfoWidget::ModifyUserInfoWidget(QString& strTrueName, QString& strJob, QString strUid, QString strToken,QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
	, m_strTrueName(strTrueName)
	, m_strJob(strJob)
{
	ui.setupUi(getContentWidget());
	resize(454, 254);
	setWindowTitle(QString::fromLocal8Bit("编辑用户"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("modifyUserInfo");
	setAttribute(Qt::WA_ShowModal, true);

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});

	connect(ui.okButton, &QPushButton::clicked, this, &ModifyUserInfoWidget::onModifyOkBtnClick);
	connect(ui.cancelButton, &QPushButton::clicked, [this](){
		close();
	});
	ui.label_6->hide();
	ui.label_9->hide();

	ui.lineEditName->setText(strTrueName);
	ui.lineEditJob->setText(strJob);

	connect(ui.lineEditName, &QLineEdit::editingFinished, this, &ModifyUserInfoWidget::onNameEditingFinished);
	connect(ui.lineEditJob, &QLineEdit::editingFinished, this, &ModifyUserInfoWidget::onJobEditingFinished);
}

ModifyUserInfoWidget::~ModifyUserInfoWidget()
{
}

void ModifyUserInfoWidget::onModifyOkBtnClick()
{
	if (!m_bName)
	{
		ui.label_6->show();
	}
	if (!m_bJob)
	{
		ui.label_9->show();
	}
	if (!m_bName || !m_bJob)
	{
		return;
	}
	QString strRet;
	if (!winHttpEditUser(m_strUid, m_strToken, ui.lineEditName->text(), ui.lineEditJob->text(),strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n更新用户信息失败，请稍后再试！"));
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
		m_strTrueName	=	ui.lineEditName->text();
		m_strJob		=	ui.lineEditJob->text();
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAS003");
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n更新用户信息成功！"));
		emit sigModifySucessed(data.take("coin").toInt(), (1 == data.take("perfect").toInt()) ? true : false);
	}
	else
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "BAS002", QString("%1").arg(status));
		if (10014 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n姓名填写不正确！"));
		}
		else if (10015 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n职务填写不正确！"));
		}
		else
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n更新用户信息失败，请稍后再试！"));
		}
	}	
}

void ModifyUserInfoWidget::onNameEditingFinished()
{
	QRegExp	reg(".{2,20}");
	QString strText = ui.lineEditName->text();
	if (!reg.exactMatch(strText))
	{
		m_bName = false;
		ui.label_6->show();
	}
	else
	{
		m_bName = true;
		ui.label_6->hide();
	}
}

void ModifyUserInfoWidget::onJobEditingFinished()
{
	QRegExp	reg(".{0,10}");
	QString strText = ui.lineEditJob->text();
	if (strText.isEmpty())
	{
		m_bJob = true;
		ui.label_9->hide();
		return;
	}
	if (!reg.exactMatch(strText))
	{
		m_bJob = false;
		ui.label_9->show();
	}
	else
	{
		m_bJob = true;
		ui.label_9->hide();
	}
}

bool ModifyUserInfoWidget::winHttpEditUser(QString strUid, QString strToken, QString strTrueName, QString strJob, QString& strRet)
{
	QString strUrl = QString("/v2/user/edit-user?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("truename=%1&job=%2").arg(strTrueName).arg(strJob);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}
