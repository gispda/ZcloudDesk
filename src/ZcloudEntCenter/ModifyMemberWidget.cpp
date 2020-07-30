#include "ModifyMemberWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include "ZcloudBigData.h"

ModifyMemberWidget::ModifyMemberWidget(QString strTrueName, QString strJob, QString strUid, QString strToken, QString strUserId, QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
	, m_strUserId(strUserId)
{
	ui.setupUi(getContentWidget());
	resize(454, 254);
	setWindowTitle(QString::fromLocal8Bit("�༭��Ա"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("modifyMember");
	setAttribute(Qt::WA_ShowModal, true);

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BRM005");
		close();
	});

	connect(ui.okButton, &QPushButton::clicked, this, &ModifyMemberWidget::onModifyOkBtnClick);
	connect(ui.cancelButton, &QPushButton::clicked, [this](){
		close();
	});
	ui.label_6->hide();
	ui.label_9->hide();

	m_bName = strTrueName.isEmpty() ? false : true;
	ui.lineEditName->setText(strTrueName);
	ui.lineEditJob->setText(strJob);

	connect(ui.lineEditName, &QLineEdit::editingFinished, this, &ModifyMemberWidget::onNameEditingFinished);
	connect(ui.lineEditJob, &QLineEdit::editingFinished, this, &ModifyMemberWidget::onJobEditingFinished);
}

ModifyMemberWidget::~ModifyMemberWidget()
{
}

void ModifyMemberWidget::onModifyOkBtnClick()
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
	if (!winHttpModifyMemberInfo(m_strUid,m_strToken,ui.lineEditName->text(),ui.lineEditJob->text(),m_strUserId,strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n���²����Աʧ�ܣ����Ժ����ԣ�"));
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
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "BRM003", m_strUserId);
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("�����ɹ�"), QString::fromLocal8Bit("\r\n���²����Ա��Ϣ�ɹ���"));
		emit sigModifyMember(ui.lineEditName->text(), ui.lineEditJob->text(), m_strUserId);
	}
	else
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "BRM002", QString("%1-%2").arg(m_strUserId).arg(status));
		if (30069 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n�Բ�����û�в���Ȩ�ޣ�"));
		}
		else if (10014 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n������д����ȷ��"));
		}
		else if (10015 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\nְ����д����ȷ��"));
		}
		else
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n���²����Աʧ�ܣ����Ժ����ԣ�"));
		}
	}	
}

void ModifyMemberWidget::onNameEditingFinished()
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

void ModifyMemberWidget::onJobEditingFinished()
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
bool ModifyMemberWidget::winHttpModifyMemberInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, QString strUserId,QString& strRet)
{
	QString strUrl = QString("/v2/company/set-member-info?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("action_type=update&true_name=%1&job=%2&u_id=%3").arg(strTrueName).arg(strJob).arg(strUserId);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}
