#include "EditEntInfoWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include "ZcloudBigData.h"

EditEntInfoWidget::EditEntInfoWidget(QString strUid, QString strToken, stEntInfo entInfo, QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_stEntInfo(entInfo)
	, m_strUid(strUid)
	, m_strToken(strToken)
{
	ui.setupUi(getContentWidget());
	resize(454, 382);
	setWindowTitle(QString::fromLocal8Bit("编辑企业资料"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("editEntInfo");
	setAttribute(Qt::WA_ShowModal, true);

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});

	////!所属行业
	//showTradeData();
	//connect(ui.comboBoxTrade, SIGNAL(currentIndexChanged(int)), this, SLOT(onTradeIndexChanged(int)));
	//ui.comboBoxTrade->lineEdit()->setReadOnly(true);
	//if (m_stEntInfo._strTradeName.isEmpty())
	//{
	//	ui.comboBoxTrade->setCurrentText("");
	//	ui.comboBoxTrade->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("请选择所属行业"));
	//}
	//else
	//{
	//	ui.comboBoxTrade->setCurrentText(m_stEntInfo._strTradeName);
	//}

	showAreaData(ui.comboBoxPro, 0);
	showAreaData(ui.comboBoxProOffice, 0);

	connect(ui.comboBoxPro, SIGNAL(currentIndexChanged(int)), this, SLOT(onProIndexChanged(int)));
	connect(ui.comboBoxCity, SIGNAL(currentIndexChanged(int)), this, SLOT(onCityIndexChanged(int)));
	connect(ui.comboBoxArea, SIGNAL(currentIndexChanged(int)), this, SLOT(onAreaIndexChanged(int)));

	//!省
	ui.comboBoxPro->lineEdit()->setReadOnly(true);
	ui.comboBoxProOffice->lineEdit()->setReadOnly(true);
	if (m_stEntInfo._strPro.isEmpty())
	{
		ui.comboBoxPro->setCurrentText("");
		ui.comboBoxPro->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("省"));
	}
	else
	{
		ui.comboBoxPro->setCurrentText(m_stEntInfo._strPro);
	}
	

	//!市
	ui.comboBoxCity->lineEdit()->setReadOnly(true);
	ui.comboBoxCityOffice->lineEdit()->setReadOnly(true);
	if (m_stEntInfo._strCity.isEmpty())
	{
		ui.comboBoxCity->setCurrentText("");
		ui.comboBoxCity->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("市"));
	}
	else
	{
		ui.comboBoxCity->setCurrentText(m_stEntInfo._strCity);
	}

	//!区
	ui.comboBoxArea->lineEdit()->setReadOnly(true);
	ui.comboBoxAreaOffice->lineEdit()->setReadOnly(true);
	if (m_stEntInfo._strArea.isEmpty())
	{
		ui.comboBoxArea->setCurrentText("");
		ui.comboBoxArea->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("区"));
	}
	else
	{
		ui.comboBoxArea->setCurrentText(m_stEntInfo._strArea);
	}

	ui.labelAreaError->hide();
	ui.labelAddressError->hide();
	ui.labelAreaOfficeError->hide();
	ui.labelAddressOfficeError->hide();
	ui.labelLegalPeasonError->hide();
	ui.labelPhoneError->hide();

	ui.lineEditLegalPeason->setText(m_stEntInfo._strOfficeName);
	ui.lineEditPhone->setText(m_stEntInfo._strOfficeMobile);
	connect(ui.lineEditLegalPeason, &QLineEdit::editingFinished, this, &EditEntInfoWidget::onLegalPeasonEditingFinished);
	connect(ui.lineEditPhone, &QLineEdit::editingFinished, this, &EditEntInfoWidget::onPhoneEditingFinished);
	connect(ui.okButton, &QPushButton::clicked, this, &EditEntInfoWidget::onEditOkBtnClick);
	connect(ui.cancelButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD004");
		close();
	});
}


void EditEntInfoWidget::onRadioBtnAddressRegClick(){
	ui.widgetAddressOffice->hide();
	adjustSize();
}
void EditEntInfoWidget::onRadioBtnAddressNewClick(){
	ui.widgetAddressOffice->show();
	adjustSize();
}


EditEntInfoWidget::~EditEntInfoWidget()
{
}

bool EditEntInfoWidget::winHttpGetTradeList(QString& strRet)
{
	QString strUrl = QString("/param/trade-list");
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

bool EditEntInfoWidget::showTradeData()
{
	QString strRet;
	if (!winHttpGetTradeList(strRet))
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

	QJsonValue list = obj.take("data");
	if (!list.isArray())
	{
		return false;
	}
	//QJsonArray listArray = list.toArray();
	//int nSize = listArray.size();
	//for (int nIndex = 0; nIndex < nSize; ++nIndex)
	//{
	//	QJsonObject dataList = listArray.at(nIndex).toObject();
	//	int nId = dataList.take("value").toInt();
	//	QString strName = dataList.take("name").toString();
	//	ui.comboBoxTrade->addItem(strName);
	//	ui.comboBoxTrade->setItemData(nIndex, nId);
	//}
	return true;
}

bool EditEntInfoWidget::winHttpGetAreaList(int code, QString& strRet)
{
	QString strUrl = QString("/param/get-region-by-code?code=%1").arg(code);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

void EditEntInfoWidget::onProIndexChanged(int index)
{
	if (index	==	-1)
	{
		return;
	}
	ui.comboBoxCity->clear();
	ui.comboBoxArea->clear();
	int nCode = ui.comboBoxPro->itemData(index).toInt();
	m_stEntInfo._nProId = nCode;
	m_stEntInfo._strPro = ui.comboBoxPro->currentText();
	showAreaData(ui.comboBoxCity, nCode);
	if (m_stEntInfo._nProId == -999)
	{
		ui.labelAreaError->show();
	}
	else
	{
		ui.labelAreaError->hide();
	}
}

void EditEntInfoWidget::onCityIndexChanged(int index)
{
	if (index == -1)
	{
		return;
	}
	ui.comboBoxArea->clear();
	int nCode = ui.comboBoxCity->itemData(index).toInt();
	m_stEntInfo._nCityId = nCode;
	m_stEntInfo._strCity = ui.comboBoxCity->currentText();
	showAreaData(ui.comboBoxArea, nCode);
	if (m_stEntInfo._nCityId == -999)
	{
		ui.labelAreaError->show();
	}
	else
	{
		ui.labelAreaError->hide();
	}
}


void EditEntInfoWidget::onTradeIndexChanged(int index)
{
	/*int nCode = ui.comboBoxTrade->itemData(index).toInt();
	m_stEntInfo._nTradeId = nCode;
	m_stEntInfo._strTradeName = ui.comboBoxTrade->currentText();*/
}

void EditEntInfoWidget::onLegalPeasonEditingFinished()
{
	QRegExp	reg(".{2,20}");
	QString strText = ui.lineEditLegalPeason->text();
	if (strText.isEmpty())
	{
		m_bLegalPeason = true;
		ui.labelLegalPeasonError->hide();
		return;
	}
	if (!reg.exactMatch(strText))
	{
		m_bLegalPeason = false;
		ui.labelLegalPeasonError->show();
	}
	else
	{
		m_bLegalPeason = true;
		ui.labelLegalPeasonError->hide();
	}
}

void EditEntInfoWidget::onPhoneEditingFinished()
{
	QRegExp reg("^1\\d{10}$");
	QString strText = ui.lineEditPhone->text();
	if (strText.isEmpty())
	{
		m_bPhone = true;
		ui.labelPhoneError->hide();
		return;
	}
	if (!reg.exactMatch(strText))
	{
		m_bPhone = false;
		ui.labelPhoneError->show();
	}
	else
	{
		m_bPhone = true;
		ui.labelPhoneError->hide();
	}
}

bool EditEntInfoWidget::showAreaData(QComboBox* pComBoBox, int nCode)
{
	pComBoBox->insertItem(0,QString::fromLocal8Bit("不限"));
	pComBoBox->setItemData(0,-999);
	QString strRet;
	if (!winHttpGetAreaList(nCode, strRet))
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
	QJsonValue list = obj.take("data");
	if (!list.isArray())
	{
		return false;
	}

	QJsonArray listArray = list.toArray();
	int nSize = listArray.size();
	for (int nIndex = 0; nIndex < nSize; ++nIndex)
	{
		QJsonObject dataList = listArray.at(nIndex).toObject();
		int nId = dataList.take("id").toInt();
		QString strName = dataList.take("region_name").toString();
		pComBoBox->insertItem(nIndex + 1, strName);
		pComBoBox->setItemData(nIndex+1, nId);
	}
	return true;
}

void EditEntInfoWidget::onAreaIndexChanged(int index)
{
	int nCode = ui.comboBoxArea->itemData(index).toInt();
	m_stEntInfo._nAreaId = nCode;
	if (m_stEntInfo._nAreaId == -999)
	{
		ui.labelAreaError->show();
	}
	else
	{
		ui.labelAreaError->hide();
	}
	m_stEntInfo._strArea = ui.comboBoxArea->currentText();
}

void EditEntInfoWidget::onEditOkBtnClick()
{
	if (!m_bLegalPeason)
	{
		ui.labelLegalPeasonError->show();
	}
	if (!m_bPhone)
	{
		ui.labelPhoneError->show();
	}
	if (!m_bLegalPeason || !m_bPhone)
	{
		return;
	}
	if (m_stEntInfo._nProId == -999 || m_stEntInfo._nCityId == -999 || m_stEntInfo._nAreaId == -999)
	{
		ui.labelAreaError->show();
		return;
	}
	QString strRet;
	//根据新接口修改上传内容
	if (!winHttpUpdateCompanyInfo(m_strUid, m_strToken, m_stEntInfo._nTradeId, m_stEntInfo._nProId, m_stEntInfo._nCityId, m_stEntInfo._nAreaId, ui.lineEditLegalPeason->text(), ui.lineEditPhone->text(), strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n更新企业资料失败，请稍后再试！"));
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
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD003");
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n更新企业资料成功！"));
		emit sigUpdateSucessed();
	}
	else
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M10", "OP000", "BBD002", QString("%1").arg(status));
		if (10014 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n财务负责人姓名不正确！"));
		}
		else if (10004 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n手机号不正确！"));
		}
		else
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n更新企业资料失败，请稍后再试！"));
		}
	}
}

bool EditEntInfoWidget::winHttpUpdateCompanyInfo(QString strUid, QString strToken, int nTradeId, int nProId, int nCityId, int nAreaId, QString strOfficer, QString strPhone, QString& strRet)
{
	QString strUrl = QString("/v2/company/update-company-info?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("action_type=company&trade_id=%1&province_id=%2&city_id=%3&area_id=%4&financial_officer=%5&financial_phone=%6").arg(nTradeId).arg(nProId).arg(nCityId).arg(nAreaId).arg(strOfficer).arg(strPhone);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}
