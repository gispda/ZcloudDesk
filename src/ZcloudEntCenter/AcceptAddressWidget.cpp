#include "AcceptAddressWidget.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include "ZcloudCommon.h"
#include "ZcloudBigData.h"

AcceptAddressWidget::AcceptAddressWidget(QString strUid, QString strToken, AddressInfo addrInfo, QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
	, m_addrInfo(addrInfo)
{
	ui.setupUi(getContentWidget());
	resize(515, 423);
	setWindowTitle(QString::fromLocal8Bit("收货地址"));
	setAttribute(Qt::WA_DeleteOnClose);
	setAttribute(Qt::WA_ShowModal, true);
	setObjectName("acceptAddress");

	ui.label_6->hide();
	ui.label_7->hide();
	ui.label_8->hide();
	ui.label_9->hide();

	initAddr();

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});

	connect(ui.lineEditName, &QLineEdit::editingFinished, this, &AcceptAddressWidget::onNameEditBtnClick);
	connect(ui.lineEditMobile, &QLineEdit::editingFinished, this, &AcceptAddressWidget::onMobileEditBtnClick);
	connect(ui.textEditAddr, &QTextEdit::textChanged, this, &AcceptAddressWidget::onAddrEditBtnClick);

	connect(ui.comboBoxPro, SIGNAL(currentIndexChanged(int)), this, SLOT(onProIndexChanged(int)));
	connect(ui.comboBoxCity, SIGNAL(currentIndexChanged(int)), this, SLOT(onCityIndexChanged(int)));
	connect(ui.comboBoxArea, SIGNAL(currentIndexChanged(int)), this, SLOT(onAreaIndexChanged(int)));

	connect(ui.okButton, &QPushButton::clicked, this, &AcceptAddressWidget::onAddressOkBtnClick);
	connect(ui.cancelButton, &QPushButton::clicked, [this](){
		close();
	});
}

AcceptAddressWidget::~AcceptAddressWidget()
{
}

void AcceptAddressWidget::onAddressOkBtnClick()
{
	if (!m_bName)
	{
		ui.label_6->show();
	}
	if (!m_bMobile)
	{
		ui.label_7->show();
	}
	if (!m_bAddr)
	{
		ui.label_9->show();
	}
	if (!m_bName || !m_bMobile || !m_bAddr)
	{
		return;
	}
	if (m_addrInfo._nProId == -999 || m_addrInfo._nCityId == -999 || m_addrInfo._nAreaId == -999)
	{
		ui.label_8->show();
		return;
	}
	QString strRet;
	m_addrInfo._strTureName = ui.lineEditName->text();
	m_addrInfo._strMobile	= ui.lineEditMobile->text();
	m_addrInfo._strAddr		= ui.textEditAddr->toPlainText();
	if (!winHttpUpdateAddress(m_strUid, m_strToken, ui.lineEditName->text(), ui.lineEditMobile->text(), ui.textEditAddr->toPlainText(),strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n更新收货地址失败，请稍后再试！"));
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
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "BAS021");
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n更新收货地址成功！"));
		emit sigUpdateAddrSucessed(data.take("coin").toInt(), (1 == data.take("perfect").toInt()) ? true : false,m_addrInfo);
	}
	else if (10046 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n收件人格式不正确！"));
	}
	else if (10047 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n联系电话格式不正确！"));
	}
	else if (100481 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n收件人地址格式不正确！"));
	}
	else if (10048 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n收件人所在区域不正确！"));
	}
	else
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n更新收货地址失败，请稍后再试！"));
	}
}

void AcceptAddressWidget::onNameEditBtnClick()
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

void AcceptAddressWidget::onMobileEditBtnClick()
{
	QRegExp reg("^1\\d{10}$");
	QString strText = ui.lineEditMobile->text();
	if (!reg.exactMatch(strText))
	{
		m_bMobile = false;
		ui.label_7->show();
	}
	else
	{
		m_bMobile = true;
		ui.label_7->hide();
	}
}

void AcceptAddressWidget::onAddrEditBtnClick()
{
	QRegExp	reg(".{0,200}");
	QString strText = ui.textEditAddr->toPlainText();
	if (!reg.exactMatch(strText))
	{
		m_bAddr = false;
		ui.label_9->show();
	}
	else
	{
		m_bAddr = true;
		ui.label_9->hide();
	}
}

bool AcceptAddressWidget::showXzAreaData(QComboBox* pComBoBox, int nCode, int nCurId)
{
	pComBoBox->insertItem(0, QString::fromLocal8Bit("不限"));
	pComBoBox->setItemData(0, -999);
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
		pComBoBox->setItemData(nIndex + 1, nId);
		if (nCurId == nId)
		{
			pComBoBox->setCurrentIndex(nIndex + 1);
		}
	}
	return true;
}

bool AcceptAddressWidget::winHttpGetAreaList(int code, QString& strRet)
{
	QString strUrl = QString("/param/get-region-by-code?code=%1").arg(code);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

void AcceptAddressWidget::onProIndexChanged(int index)
{
	if (index == -1)
	{
		return;
	}
	ui.comboBoxCity->clear();
	ui.comboBoxArea->clear();
	m_addrInfo._nProId = ui.comboBoxPro->itemData(index).toInt();
	showXzAreaData(ui.comboBoxCity, m_addrInfo._nProId, m_addrInfo._nCityId);
	if (m_addrInfo._nProId == -999)
	{
		ui.label_8->show();
	}
	else
	{
		ui.label_8->hide();
	}
}

void AcceptAddressWidget::onCityIndexChanged(int index)
{
	if (index == -1)
	{
		return;
	}
	ui.comboBoxArea->clear();
	m_addrInfo._nCityId = ui.comboBoxCity->itemData(index).toInt();
	showXzAreaData(ui.comboBoxArea, m_addrInfo._nCityId, m_addrInfo._nAreaId);
	if (m_addrInfo._nCityId == -999)
	{
		ui.label_8->show();
	}
	else
	{
		ui.label_8->hide();
	}
}

void AcceptAddressWidget::onAreaIndexChanged(int index)
{
	m_addrInfo._nAreaId = ui.comboBoxArea->itemData(index).toInt();
	if (m_addrInfo._nAreaId == -999)
	{
		ui.label_8->show();
	}
	else
	{
		ui.label_8->hide();
	}
}

bool AcceptAddressWidget::winHttpUpdateAddress(QString strUid, QString strToken, QString strName, QString strMobile, QString strAddr, QString& strRet)
{
	QString strUrl = QString("/v2/user/update-address?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("true_name=%1&phone=%2&address=%3&region[province_id]=%4&region[city_id]=%5&region[area_id]=%6")
		.arg(strName).arg(strMobile).arg(strAddr).arg(m_addrInfo._nProId).arg(m_addrInfo._nCityId).arg(m_addrInfo._nAreaId);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

void AcceptAddressWidget::initAddr()
{
	m_bName = m_addrInfo._strTureName.isEmpty() ? false : true;
	ui.lineEditName->setText(m_addrInfo._strTureName);

	m_bMobile = m_addrInfo._strMobile.isEmpty() ? false : true;
	ui.lineEditMobile->setText(m_addrInfo._strMobile);

	if (0 == m_addrInfo._nProId)
	{
		ui.comboBoxPro->lineEdit()->setReadOnly(true);
		ui.comboBoxPro->setCurrentText("");
		ui.comboBoxPro->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("省"));
	}
	showXzAreaData(ui.comboBoxPro, 0, m_addrInfo._nProId);
	
	if (0 == m_addrInfo._nCityId)
	{
		ui.comboBoxCity->lineEdit()->setReadOnly(true);
		ui.comboBoxCity->setCurrentText("");
		ui.comboBoxCity->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("市"));
	}
	showXzAreaData(ui.comboBoxCity, m_addrInfo._nProId, m_addrInfo._nCityId);
	
	if (0 == m_addrInfo._nAreaId)
	{
		ui.comboBoxArea->lineEdit()->setReadOnly(true);
		ui.comboBoxArea->setCurrentText("");
		ui.comboBoxArea->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("区"));
	}
	showXzAreaData(ui.comboBoxArea, m_addrInfo._nCityId, m_addrInfo._nAreaId);
	
	m_bAddr = m_addrInfo._strAddr.isEmpty() ? false : true;
	ui.textEditAddr->setPlainText(m_addrInfo._strAddr);
}
