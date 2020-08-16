#include "EditInvoiceInfoWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include "ZcloudBigData.h"

EditInvoiceInfoWidget::EditInvoiceInfoWidget(QString strUid, QString strToken, stInvoiceInfo invoiceInfo, QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_stInvoiceInfo(invoiceInfo)
	, m_strUid(strUid)
	, m_strToken(strToken)
{
	ui.setupUi(getContentWidget());
	resize(454, 423);
	setWindowTitle(QString::fromLocal8Bit("编辑开票信息"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("editInvoiceInfo");
	setAttribute(Qt::WA_ShowModal, true);

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});

	connect(ui.lineEditAcc, &QLineEdit::editingFinished, this, &EditInvoiceInfoWidget::onAccEditBtnClick);
	connect(ui.lineEditBank, &QLineEdit::editingFinished, this, &EditInvoiceInfoWidget::onBankEditBtnClick);
	connect(ui.lineEditTelNo, &QLineEdit::editingFinished, this, &EditInvoiceInfoWidget::onTelNoEditBtnClick);
	connect(ui.textEditAddr, &QTextEdit::textChanged, this, &EditInvoiceInfoWidget::onAddrEditBtnClick);
	connect(ui.okButton, &QPushButton::clicked, this, &EditInvoiceInfoWidget::onEditOkBtnClick);
	connect(ui.cancelButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD008");
		close();
	});
	ui.label_6->hide();
	ui.label_7->hide();
	ui.label_8->hide();
	ui.label_9->hide();
	showInvoiceData();
}

EditInvoiceInfoWidget::~EditInvoiceInfoWidget()
{
}

void EditInvoiceInfoWidget::showInvoiceData()
{
	ui.lineEditAcc->setText(m_stInvoiceInfo._strBankAccount);
	ui.lineEditBank->setText(m_stInvoiceInfo._strBankName);
	ui.lineEditTelNo->setText(m_stInvoiceInfo._strTelNo);
	ui.textEditAddr->setText(m_stInvoiceInfo._strAddr);
}

void EditInvoiceInfoWidget::onAccEditBtnClick()
{
	QRegExp reg("\\d{16,19}");
	QString strText = ui.lineEditAcc->text();
	if (strText.isEmpty())
	{
		m_bAcc = true;
		ui.label_6->hide();
		return;
	}
	if (!reg.exactMatch(strText))
	{
		m_bAcc = false;
		ui.label_6->show();
	}
	else
	{
		m_bAcc = true;
		ui.label_6->hide();
	}
}

void EditInvoiceInfoWidget::onBankEditBtnClick()
{
	QRegExp	reg(".{0,50}");
	QString strText = ui.lineEditBank->text();
	if (strText.isEmpty())
	{
		m_bBank = true;
		ui.label_7->hide();
		return;
	}
	if (!reg.exactMatch(strText))
	{
		m_bBank = false;
		ui.label_7->show();
	}
	else
	{
		m_bBank = true;
		ui.label_7->hide();
	}
}

void EditInvoiceInfoWidget::onTelNoEditBtnClick()
{
	QRegExp reg("[0-9]{3,4}-[0-9]{7,8}");
	QString strText = ui.lineEditTelNo->text();
	if (strText.isEmpty())
	{
		m_bTelNo = true;
		ui.label_9->hide();
		return;
	}
	if (!reg.exactMatch(strText))
	{
		m_bTelNo = false;
		ui.label_9->show();
	}
	else
	{
		m_bTelNo = true;
		ui.label_9->hide();
	}
}

void EditInvoiceInfoWidget::onAddrEditBtnClick()
{
	QRegExp	reg(".{0,200}");
	QString strText = ui.textEditAddr->toPlainText();
	if (strText.isEmpty())
	{
		m_bAddr = true;
		ui.label_8->hide();
		return;
	}
	if (!reg.exactMatch(strText))
	{
		m_bAddr = false;
		ui.label_8->show();
	}
	else
	{
		m_bAddr = true;
		ui.label_8->hide();
	}
}

void EditInvoiceInfoWidget::onEditOkBtnClick()
{
	if (!m_bAcc)
	{
		ui.label_6->show();
	}
	if (!m_bBank)
	{
		ui.label_7->show();
	}
	if (!m_bTelNo)
	{
		ui.label_9->show();
	}
	if (!m_bAddr)
	{
		ui.label_8->show();
	}

	if (!m_bAcc || !m_bBank || !m_bTelNo || !m_bAddr)
	{
		return;
	}
	QString strRet;
	if (!winHttpUpdateCompanyInfo(m_strUid, m_strToken, ui.lineEditAcc->text(), ui.lineEditBank->text(), ui.lineEditTelNo->text(), ui.textEditAddr->toPlainText(), strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n更新开票信息失败，请稍后再试！"));
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
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "BBD007");
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n更新开票信息成功！"));
		
		emit sigUpdateSucessed();
	}
	else
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M10", "OP000", "BBD006", QString("%1").arg(status));
		if (10027 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n开户账号不正确！"));
		}
		else if (10028 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n开户银行不正确！"));
		}
		else
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n更新开票信息失败，请稍后再试！"));
		}
	}
}

bool EditInvoiceInfoWidget::winHttpUpdateCompanyInfo(QString strUid, QString strToken, QString strAcc, QString strBank, QString strTel, QString strAddr, QString& strRet)
{
	QString strUrl = QString("/v2/company/update-company-info?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("action_type=invoice&bank_account=%1&bank_name=%2&tel_number=%3&address=%4").arg(strAcc).arg(strBank).arg(strTel).arg(strAddr);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}
