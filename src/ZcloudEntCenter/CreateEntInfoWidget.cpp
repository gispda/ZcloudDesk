#include "CreateEntInfoWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include "ZcloudBigData.h"

CreateEntInfoWidget::CreateEntInfoWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	resize(454, 382);
	setWindowTitle(QString::fromLocal8Bit("��������ҵ"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("createtEntInfo");
	setAttribute(Qt::WA_ShowModal, true);


	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, false);
	setWindowModality(Qt::WindowModal);
	setStyleSheet("outline: none");


	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});

	//!������ҵ
	showTradeData();
	/*connect(ui.comboBoxTrade, SIGNAL(currentIndexChanged(int)), this, SLOT(onTradeIndexChanged(int)));
	ui.comboBoxTrade->lineEdit()->setReadOnly(true);
	if (m_stEntInfo._strTradeName.isEmpty())
	{
		ui.comboBoxTrade->setCurrentText("");
		ui.comboBoxTrade->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("��ѡ��������ҵ"));
	}
	else
	{
		ui.comboBoxTrade->setCurrentText(m_stEntInfo._strTradeName);
	}*/
	
	showXzAreaData(ui.comboBoxPro,0);

	connect(ui.comboBoxPro, SIGNAL(currentIndexChanged(int)), this, SLOT(onProIndexChanged(int)));
	connect(ui.comboBoxCity, SIGNAL(currentIndexChanged(int)), this, SLOT(onCityIndexChanged(int)));
	connect(ui.comboBoxArea, SIGNAL(currentIndexChanged(int)), this, SLOT(onAreaIndexChanged(int)));

	//!ʡ
	ui.comboBoxPro->lineEdit()->setReadOnly(true);
	if (m_stEntInfo._strPro.isEmpty())
	{
		ui.comboBoxPro->setCurrentText("");
		ui.comboBoxPro->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("ʡ"));
	}
	else
	{
		ui.comboBoxPro->setCurrentText(m_stEntInfo._strPro);
	}

	//!��
	ui.comboBoxCity->lineEdit()->setReadOnly(true);
	if (m_stEntInfo._strCity.isEmpty())
	{
		ui.comboBoxCity->setCurrentText("");
		ui.comboBoxCity->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("��"));
	}
	else
	{
		ui.comboBoxCity->setCurrentText(m_stEntInfo._strCity);
	}

	//!��
	ui.comboBoxArea->lineEdit()->setReadOnly(true);
	if (m_stEntInfo._strArea.isEmpty())
	{
		ui.comboBoxArea->setCurrentText("");
		ui.comboBoxArea->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("��"));
	}
	else
	{
		ui.comboBoxArea->setCurrentText(m_stEntInfo._strArea);
	}

	ui.labelCompanyNotFound->hide();
	ui.labelAreaError->hide();
	ui.labelAddressError->hide();
	ui.labelLegalPeasonError->hide();
	ui.labelPhoneError->hide();

	connect(ui.lineEditAddress, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onAddressEditingFinished);
	connect(ui.lineEditLegalPeasonName, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onLegalPeasonEditingFinished);
	connect(ui.lineEditPhone, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onPhoneEditingFinished);

}

CreateEntInfoWidget::~CreateEntInfoWidget()
{
}

void CreateEntInfoWidget::onSearchkBtnClick(){
}

bool CreateEntInfoWidget::winHttpGetTradeList(QString& strRet)
{
	QString strUrl = QString("/param/trade-list");
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

bool CreateEntInfoWidget::showTradeData()
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
	QJsonArray listArray = list.toArray();
	int nSize = listArray.size();
	for (int nIndex = 0; nIndex < nSize; ++nIndex)
	{
		QJsonObject dataList = listArray.at(nIndex).toObject();
		int nId = dataList.take("value").toInt();
		QString strName = dataList.take("name").toString();
	/*	ui.comboBoxTrade->addItem(strName);
		ui.comboBoxTrade->setItemData(nIndex, nId);*/
	}
	return true;
}

bool CreateEntInfoWidget::winHttpGetAreaList(int code, QString& strRet)
{
	QString strUrl = QString("/param/get-region-by-code?code=%1").arg(code);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

void CreateEntInfoWidget::onProIndexChanged(int index)
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
	showXzAreaData(ui.comboBoxCity, nCode);
	if (m_stEntInfo._nProId == -999)
	{
		ui.labelAreaError->show();
	}
	else
	{
		ui.labelAreaError->hide();
	}
}

void CreateEntInfoWidget::onCityIndexChanged(int index)
{
	if (index == -1)
	{
		return;
	}
	ui.comboBoxArea->clear();
	int nCode = ui.comboBoxCity->itemData(index).toInt();
	m_stEntInfo._nCityId = nCode;
	m_stEntInfo._strCity = ui.comboBoxCity->currentText();
	showXzAreaData(ui.comboBoxArea, nCode);
	if (m_stEntInfo._nCityId == -999)
	{
		ui.labelAreaError->show();
	}
	else
	{
		ui.labelAreaError->hide();
	}
}



void CreateEntInfoWidget::onLegalPeasonEditingFinished()
{
	QRegExp	reg(".{2,15}");
	QString strText = ui.lineEditLegalPeasonName->text();
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

void CreateEntInfoWidget::onAddressEditingFinished()
{
	QRegExp	reg(".{5,100}");
	QString strText = ui.lineEditAddress->text();
	if (strText.isEmpty())
	{
		m_bAddress = true;
		ui.labelAddressError->hide();
		return;
	}
	if (!reg.exactMatch(strText))
	{
		m_bAddress = false;
		ui.labelAddressError->show();
	}
	else
	{
		m_bAddress = true;
		ui.labelAddressError->hide();
	}
}

void CreateEntInfoWidget::onPhoneEditingFinished()
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

bool CreateEntInfoWidget::showXzAreaData(QComboBox* pComBoBox, int nCode)
{
	pComBoBox->insertItem(0,QString::fromLocal8Bit("����"));
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

void CreateEntInfoWidget::onAreaIndexChanged(int index)
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

void CreateEntInfoWidget::onEditOkBtnClick()
{
	if (ui.lineEditCompanyName->text().isEmpty()){
		ui.labelCompanyNotFound->show();
		return;
	}
	if (ui.lineEditSocietyCode->text().isEmpty()){
		ui.labelCompanyNotFound->show();
		return;
	}

	if (!m_bAddress)
	{
		ui.labelAddressError->show();
	}	
	if (!m_bLegalPeason)
	{
		ui.labelLegalPeasonError->show();
	}
	if (!m_bPhone)
	{
		ui.labelPhoneError->show();
	}
	if (!m_bAddress || !m_bPhone || !m_bLegalPeason)
	{
		return;
	}

	if (m_stEntInfo._nProId == -999 || m_stEntInfo._nCityId == -999 || m_stEntInfo._nAreaId == -999)
	{
		ui.labelAreaError->show();
		return;
	}
	QString strRet;
	//if (!winHttpCreateCompanyInfo(m_strUid, m_strToken, m_stEntInfo._nTradeId, m_stEntInfo._nProId, m_stEntInfo._nCityId, m_stEntInfo._nAreaId, ui.lineEditOffice->text(), ui.lineEditPhone->text(), strRet))
	//{
	//	ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n������ҵ����ʧ�ܣ����Ժ����ԣ�"));
	//	return;
	//}
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
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("�����ɹ�"), QString::fromLocal8Bit("\r\n������ҵ���ϳɹ���"));
		emit sigUpdateSucessed();
	}
	else
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M10", "OP000", "BBD002", QString("%1").arg(status));
		if (10014 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n����������������ȷ��"));
		}
		else if (10004 == status)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n�ֻ��Ų���ȷ��"));
		}
		else
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n������ҵ����ʧ�ܣ����Ժ����ԣ�"));
		}
	}
}

bool CreateEntInfoWidget::winHttpCreateCompanyInfo(QString strUid, QString strToken, int nTradeId, int nProId, int nCityId, int nAreaId, QString strOfficer, QString strPhone, QString& strRet)
{
	QString strUrl = QString("/v2/company/update-company-info?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("action_type=company&trade_id=%1&province_id=%2&city_id=%3&area_id=%4&financial_officer=%5&financial_phone=%6").arg(nTradeId).arg(nProId).arg(nCityId).arg(nAreaId).arg(strOfficer).arg(strPhone);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}


void CreateEntInfoWidget::mousePressEvent(QMouseEvent *event)
{
	if (!isMaximized())
	{
		if (event->button() == Qt::LeftButton)
		{
			dPos = event->globalPos() - pos();
			event->accept();
		}
	}
}

void CreateEntInfoWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (!isMaximized())
	{
		if (event->buttons()&Qt::LeftButton)
		{
			move(event->globalPos() - dPos);
			event->accept();
		}
	}
}