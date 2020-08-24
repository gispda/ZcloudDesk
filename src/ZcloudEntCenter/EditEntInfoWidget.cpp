#include "EditEntInfoWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include "ZcloudBigData.h"
#include <QGraphicsDropShadowEffect>
#include <QDebug>

EditEntInfoWidget::EditEntInfoWidget(UserInfoStruct* _userinfo, EntCenterInfo* _pentinfo, bool beditdb, QWidget *parent)
	: QDialog(parent)
{
	m_strUid = _userinfo->m_strUserId;
	m_strToken = _userinfo->m_strToken;

	m_userinfo = _userinfo;

	m_pentinfo = _pentinfo;

	m_beditdb = beditdb;
	m_pFinishentinfo = NULL;
	ui.setupUi(this);
	//resize(565, 545);
	setWindowTitle(QString::fromLocal8Bit("编辑企业资料"));
	//setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("editEntInfo");
	setAttribute(Qt::WA_ShowModal, true);
	//QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);			//阴影模糊度
	////设置阴影距离
	//shadow->setOffset(0, 0);
	////设置阴影颜色
	//shadow->setColor(QColor("#666666"));
	////设置阴影圆角
	//shadow->setBlurRadius(8);
	////给嵌套QWidget设置阴影
	//this->setGraphicsEffect(shadow);



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


	connect(ui.radioButtonAddressReg, SIGNAL(clicked()), this, SLOT(onRadioBtnAddressRegClick()));
	connect(ui.radioButtonAddressNew, SIGNAL(clicked()), this, SLOT(onRadioBtnAddressNewClick()));

	if (m_pentinfo->_strAddress == m_pentinfo->_strOfficeaddress){
		ui.widgetAddressOffice->hide();

		ui.widget_2->resize(540, 380);
		this->resize(540, 382);
	}
	else{
		ui.widgetAddressOffice->show();

		ui.widget_2->resize(540, 510);
		this->resize(540, 512);
	}


	showAreaData(ui.comboBoxPro, 0);
	showAreaData(ui.comboBoxProOffice, 0);

	connect(ui.comboBoxPro, SIGNAL(currentIndexChanged(int)), this, SLOT(onProIndexChanged(int)));
	connect(ui.comboBoxCity, SIGNAL(currentIndexChanged(int)), this, SLOT(onCityIndexChanged(int)));
	connect(ui.comboBoxArea, SIGNAL(currentIndexChanged(int)), this, SLOT(onAreaIndexChanged(int)));


	connect(ui.comboBoxProOffice, SIGNAL(currentIndexChanged(int)), this, SLOT(onOfficeProIndexChanged(int)));
	connect(ui.comboBoxCityOffice, SIGNAL(currentIndexChanged(int)), this, SLOT(onOfficeCityIndexChanged(int)));
	connect(ui.comboBoxAreaOffice, SIGNAL(currentIndexChanged(int)), this, SLOT(onOfficeAreaIndexChanged(int)));


	//!省
	ui.comboBoxPro->lineEdit()->setReadOnly(true);
	ui.comboBoxProOffice->lineEdit()->setReadOnly(true);
	if (!m_areamap.contains(m_pentinfo->_nProvinceid)){
		 ui.comboBoxPro->setCurrentText("");
		ui.comboBoxPro->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("省"));
	}
	else
	{
		QString _strProvince = this->m_areamap.find(m_pentinfo->_nProvinceid).value();
		ui.comboBoxPro->setCurrentText(_strProvince);
		showAreaData(ui.comboBoxCity, m_pentinfo->_nProvinceid);
	}
    
	if (!m_areamap.contains(m_pentinfo->_nOfficeProvinceid))
	{
		ui.comboBoxProOffice->setCurrentText("");
		ui.comboBoxProOffice->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("省"));
	}
	else
	{
		QString _strProvince = this->m_areamap.find(m_pentinfo->_nOfficeProvinceid).value();
		ui.comboBoxProOffice->setCurrentText(_strProvince);
		showAreaData(ui.comboBoxCityOffice, m_pentinfo->_nOfficeProvinceid);
	}


	//!市
	ui.comboBoxCity->lineEdit()->setReadOnly(true);
	ui.comboBoxCityOffice->lineEdit()->setReadOnly(true);

	if (!m_areamap.contains(m_pentinfo->_nCityid))
	{
		ui.comboBoxCity->setCurrentText("");
		ui.comboBoxCity->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("市"));
	}
	else
	{
		QString _strCity = this->m_areamap.find(m_pentinfo->_nCityid).value();
		ui.comboBoxCity->setCurrentText(_strCity);

		showAreaData(ui.comboBoxArea, m_pentinfo->_nCityid);
	}

	if (!m_areamap.contains(m_pentinfo->_nOfficeCityid))
	{
		ui.comboBoxCityOffice->setCurrentText("");
		ui.comboBoxCityOffice->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("市"));
	}
	else
	{
		QString _strCity = this->m_areamap.find(m_pentinfo->_nOfficeCityid).value();
		ui.comboBoxCityOffice->setCurrentText(_strCity);
		showAreaData(ui.comboBoxAreaOffice, m_pentinfo->_nOfficeCityid);
	}


	//!区
	ui.comboBoxArea->lineEdit()->setReadOnly(true);
	ui.comboBoxAreaOffice->lineEdit()->setReadOnly(true);
	if (!m_areamap.contains(m_pentinfo->_nAreaid))
	{
		ui.comboBoxArea->setCurrentText("");
		ui.comboBoxArea->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("区"));
	}
	else
	{
		QString _strArea = this->m_areamap.find(m_pentinfo->_nAreaid).value();
		ui.comboBoxArea->setCurrentText(_strArea);
	}

	if (!m_areamap.contains(m_pentinfo->_nOfficeAreaid))
	{
		ui.comboBoxAreaOffice->setCurrentText("");
		ui.comboBoxAreaOffice->lineEdit()->setPlaceholderText(QString::fromLocal8Bit("区"));
	}
	else
	{
		QString _strArea = this->m_areamap.find(m_pentinfo->_nOfficeAreaid).value();
		ui.comboBoxAreaOffice->setCurrentText(_strArea);
	}
	ui.lineEditAddress->setText(m_pentinfo->_strAddress);
	ui.lineEditOfficeOffice->setText(m_pentinfo->_strOfficeaddress);

	ui.labelAreaError->hide();
	ui.labelAddressError->hide();
	ui.labelAreaOfficeError->hide();
	ui.labelAddressOfficeError->hide();
	ui.labelLegalPeasonError->hide();
	ui.labelPhoneError->hide();

	ui.lineEditLegalPeason->setText(m_pentinfo->_strlegalboss);
	ui.lineEditPhone->setText(m_pentinfo->_strlegalbossmobile);
	connect(ui.lineEditLegalPeason, &QLineEdit::editingFinished, this, &EditEntInfoWidget::onLegalPeasonEditingFinished);
	connect(ui.lineEditPhone, &QLineEdit::editingFinished, this, &EditEntInfoWidget::onPhoneEditingFinished);
	connect(ui.okButton, &QPushButton::clicked, this, &EditEntInfoWidget::onEditOkBtnClick);

	connect(ui.nextbutton, &QPushButton::clicked, this, &EditEntInfoWidget::onNextBtnClick);
	connect(ui.cancelButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD004");
		close();
	});


	ChangeShow();

}

void EditEntInfoWidget::onNextBtnClick()
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
	if (m_pentinfo->_nProvinceid == -999 || m_pentinfo->_nCityid == -999 || m_pentinfo->_nAreaid == -999)
	{
		ui.labelAreaError->show();
		return;
	}

		if (m_pFinishentinfo == NULL)
			m_pFinishentinfo = new EntCenterInfo();
		*m_pFinishentinfo = *m_pentinfo;
		accept();
	   close();
}
void EditEntInfoWidget::onRadioBtnAddressRegClick(){
	ui.widgetAddressOffice->hide();

	ui.widget_2->resize(540, 380);
	this->resize(540, 380);

}
void EditEntInfoWidget::onRadioBtnAddressNewClick(){
	ui.widgetAddressOffice->show();
	ui.widget_2->resize(540, 510);
	this->resize(540, 510);
}


EditEntInfoWidget::~EditEntInfoWidget()
{
	if (m_pFinishentinfo = NULL)
		delete m_pFinishentinfo;
	m_pFinishentinfo = NULL;

	 m_areamap.clear();
	 m_codemap.clear();
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
	m_pentinfo->_nProvinceid = nCode;
	m_pentinfo->_strProvince= ui.comboBoxPro->currentText();
	showAreaData(ui.comboBoxCity, nCode);
	if (m_pentinfo->_nProvinceid == -999)
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
	m_pentinfo->_nCityid = nCode;
	m_pentinfo->_strCity = ui.comboBoxCity->currentText();
	showAreaData(ui.comboBoxArea, nCode);
	if (m_pentinfo->_nCityid == -999)
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
	if (pComBoBox != NULL){
		pComBoBox->insertItem(0, QString::fromLocal8Bit("不限"));
		pComBoBox->setItemData(0, -999);
	}
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

		if (pComBoBox != NULL){
			pComBoBox->insertItem(nIndex + 1, strName);
			pComBoBox->setItemData(nIndex + 1, nId);
		}
		m_areamap.insert(nId, strName);
		m_codemap.insert(strName, nId);

	}
	return true;
}

void EditEntInfoWidget::onAreaIndexChanged(int index)
{
	int nCode = ui.comboBoxArea->itemData(index).toInt();
	m_pentinfo->_nAreaid = nCode;
	if (m_pentinfo->_nAreaid == -999)
	{
		ui.labelAreaError->show();
	}
	else
	{
		ui.labelAreaError->hide();
	}
	m_pentinfo->_strArea = ui.comboBoxArea->currentText();
}

void EditEntInfoWidget::onEditOkBtnClick()
{
	QString strArea = ui.comboBoxArea->currentText();
	if (strArea.isEmpty() || strArea == QString::fromLocal8Bit("不限"))
	{
		ui.labelAreaError->show();
		return ;
	}

	if (ui.lineEditAddress->text().isEmpty())
	{
		ui.labelAddressError->show();
		return;
	}
	if (ui.radioButtonAddressNew->isChecked()){
		QString strArea = ui.comboBoxAreaOffice->currentText();
		if (strArea.isEmpty() || strArea == QString::fromLocal8Bit("不限"))
		{
			ui.labelAreaOfficeError->show();
			return;
		}

		if (ui.lineEditOfficeOffice->text().isEmpty())
		{
			ui.labelAddressOfficeError->show();
			return;
		}
	}

	if (ui.lineEditLegalPeason->text().isEmpty())
	{
		ui.labelLegalPeasonError->show();
		return;
	}
	if (ui.lineEditPhone->text().isEmpty())
	{
		ui.labelPhoneError->show();
		return;
	}



	QString strRet;
	//根据新接口修改上传内容
	if (!winHttpUpdateCompanyInfo(m_strUid, m_strToken, strRet))
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
	int statecode = obj.take("code").toInt();
	if (0 == statecode)
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD003");

		{

			m_pentinfo->_strAddress = ui.lineEditAddress->text();


			{
				int index = ui.comboBoxPro->currentIndex();
				int nCode = ui.comboBoxPro->itemData(index).toInt();
				m_pentinfo->_nProvinceid = nCode;

				index = ui.comboBoxCity->currentIndex();
				nCode = ui.comboBoxCity->itemData(index).toInt();
				m_pentinfo->_nCityid = nCode;

				index = ui.comboBoxArea->currentIndex();
				nCode = ui.comboBoxArea->itemData(index).toInt();
				m_pentinfo->_nAreaid = nCode;
			}

			if (ui.radioButtonAddressNew->isChecked()){
				int index = ui.comboBoxProOffice->currentIndex();
				int nCode = ui.comboBoxProOffice->itemData(index).toInt();
				m_pentinfo->_nOfficeProvinceid = nCode;

				index = ui.comboBoxCityOffice->currentIndex();
				nCode = ui.comboBoxCityOffice->itemData(index).toInt();
				m_pentinfo->_nOfficeCityid = nCode;

				index = ui.comboBoxAreaOffice->currentIndex();
				nCode = ui.comboBoxAreaOffice->itemData(index).toInt();
				m_pentinfo->_nOfficeAreaid = nCode;
				m_pentinfo->_strOfficeaddress = ui.lineEditOfficeOffice->text();
			}
			else{
				m_pentinfo->_nOfficeProvinceid = m_pentinfo->_nProvinceid;
				m_pentinfo->_nOfficeCityid = m_pentinfo->_nCityid;
				m_pentinfo->_nOfficeAreaid = m_pentinfo->_nOfficeCityid;

				m_pentinfo->_strOfficeaddress = m_pentinfo->_strAddress;
			}


			m_pentinfo->_strlegalboss = ui.lineEditLegalPeason->text();
			m_pentinfo->_strlegalbossmobile = ui.lineEditPhone->text();
		}


		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n更新企业资料成功！"));


		if (m_pFinishentinfo == NULL)
			m_pFinishentinfo = new EntCenterInfo();
		*m_pFinishentinfo = *m_pentinfo;
		emit sigUpdateSucessed();
	}
	else
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M10", "OP000", "BBD002", QString("%1").arg(statecode));
		/*if (10014 == statecode)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n财务负责人姓名不正确！"));
		}
		else if (10004 == statecode)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n手机号不正确！"));
		}
		else
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n更新企业资料失败，请稍后再试！"));
		}*/


		QString strMsg;


		switch (statecode)
		{
		case 20001:
			strMsg = QString::fromLocal8Bit("企业名称不能为空");
			break;
		case 20002:
			strMsg = QString::fromLocal8Bit("企业名称长度输入不正确（4-50）");
			break;
		case 20003:
			strMsg = QString::fromLocal8Bit("税号不能为空");
			break;
		case 20004:
			strMsg = QString::fromLocal8Bit("税号输入不正确");
			break;
		case 20005:
			strMsg = QString::fromLocal8Bit("税号长度输入不正确（至少15个字符）");
			break;
		case 20006:
			strMsg = QString::fromLocal8Bit("所属区域省份不能为空");
			break;
		case 20007:
			strMsg = QString::fromLocal8Bit("所属区域省份输入不正确，纯数字");
			break;
		case 20008:
			strMsg = QString::fromLocal8Bit("所属区域城市不能为空");
			break;
		case 20009:
			strMsg = QString::fromLocal8Bit("所属区域城市输入不正确，纯数字");
			break;
		case 20010:
			strMsg = QString::fromLocal8Bit("所属区域地区不能为空");
			break;
		case 20011:
			strMsg = QString::fromLocal8Bit("所属区域地区输入不正确 ，纯数字");
			break;
		case 20012:
			strMsg = QString::fromLocal8Bit("企业地址不能为空");
			break;
		case 20013:
			strMsg = QString::fromLocal8Bit("企业地址输入不正确（5-50个字符）");
			break;
		case 20014:
			strMsg = QString::fromLocal8Bit("企业法人不能为空");
			break;
		case 20015:
			strMsg = QString::fromLocal8Bit("企业法人输入不正确");
			break;
		case 20016:
			strMsg = QString::fromLocal8Bit("企业法人电话不能为空");
			break;
		case 20017:
			strMsg = QString::fromLocal8Bit("企业法人电话输入类型不正确");
			break;
		case 20018:
			strMsg = QString::fromLocal8Bit("企业法人电话输入长度不正确（11位数字）");
			break;
		case 20019:
			strMsg = QString::fromLocal8Bit("所属区域不正确");
			break;
		case 20034:
			strMsg = QString::fromLocal8Bit("系统不存在此企业信息，请确认你的操作");
			break;
		case 20035:
			strMsg = QString::fromLocal8Bit("企业信息操作失败");
			break;
		case 20038:
			strMsg = QString::fromLocal8Bit("当前企业已经绑定过管理员了");
			break;
		case 20040:
			strMsg = QString::fromLocal8Bit("税控盘类型不能为空");
			break;
		case 20041:
			strMsg = QString::fromLocal8Bit("税控盘类型不正确");
			break;
		case 20042:
			strMsg = QString::fromLocal8Bit("系统已存在此名称的企业信息");
			break;
		case 20043:
			strMsg = QString::fromLocal8Bit("所属办公区域省份不能为空");
			break;
		case 20044:
			strMsg = QString::fromLocal8Bit("所属办公区域省份输入不正确");
			break;
		case 20045:
			strMsg = QString::fromLocal8Bit("所属办公区域城市不能为空");
			break;
		case 20046:
			strMsg = QString::fromLocal8Bit("所属办公区域城市输入不正确");
			break;
		case 20047:
			strMsg = QString::fromLocal8Bit("所属办公区域地区不能为空");
			break;
		case 20048:
			strMsg = QString::fromLocal8Bit("所属办公区域地区输入不正确");
			break;
		case 20049:
			strMsg = QString::fromLocal8Bit("企业办公地址不能为空");
			break;
		case 20050:
			strMsg = QString::fromLocal8Bit("企业办公地址输入不正确");
			break;
		case 20051:
			strMsg = QString::fromLocal8Bit("所属办公区域不正确");
			break;
			break;
		case 20052:
			strMsg = QString::fromLocal8Bit("请上传您的营业执照");
			break;
		default:
			strMsg = obj.value("msg").toString();
			break;
		}


		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), strMsg);


		this->close();
	}
}

bool EditEntInfoWidget::winHttpUpdateCompanyInfo(QString strUid, QString strToken, QString& strRet)
{
	int nCodePro = -999;
	int nCodeCity = -999;
	int nCodeArea = -999;
	int nCodeProOffice = -999;
	int nCodeCityOffice = -999;
	int nCodeAreaOffice = -999;
	if (m_codemap.contains(ui.comboBoxPro->currentText())){
		nCodePro = this->m_codemap.find(ui.comboBoxPro->currentText()).value();
	}
	if (m_codemap.contains(ui.comboBoxCity->currentText())){
		nCodeCity = this->m_codemap.find(ui.comboBoxCity->currentText()).value();
	}
	if (m_codemap.contains(ui.comboBoxArea->currentText())){
		nCodeArea = this->m_codemap.find(ui.comboBoxArea->currentText()).value();
	}

	if (ui.radioButtonAddressNew->isChecked()){
		if (m_codemap.contains(ui.comboBoxProOffice->currentText())){
			nCodeProOffice = this->m_codemap.find(ui.comboBoxProOffice->currentText()).value();
		}
		if (m_codemap.contains(ui.comboBoxCityOffice->currentText())){
			nCodeCityOffice = this->m_codemap.find(ui.comboBoxCityOffice->currentText()).value();
		}
		if (m_codemap.contains(ui.comboBoxAreaOffice->currentText())){
			nCodeAreaOffice = this->m_codemap.find(ui.comboBoxAreaOffice->currentText()).value();
		}
	}
	else{
		nCodeProOffice = nCodePro;
		nCodeCityOffice = nCodeCity;
		nCodeAreaOffice = nCodeArea;
	}


	QString strUrl = QString("/ucenter/company/update-info");
	QString strPost = QString("token=%1&company_name=%2&tax=%3&province_id=%4&city_id=%5&area_id=%6&address=%7&legal_person_phone=%8&legal_person_name=%9&office_province_id=%10&office_city_id=%11&office_area_id=%12&office_address=%13&disk_type=1")
		.arg(strToken).arg(m_pentinfo->_strCompName).arg(m_pentinfo->_strTaxNo).arg(nCodePro)
		.arg(nCodeCity).arg(nCodeArea).arg(m_pentinfo->_strAddress)
		.arg(m_pentinfo->_strlegalbossmobile).arg(m_pentinfo->_strlegalboss).arg(nCodeProOffice)
		.arg(nCodeCityOffice).arg(nCodeAreaOffice).arg(m_pentinfo->_strOfficeaddress);
	//qDebug() << strPost;

	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);
}
///返回完善的企业信息资料
EntCenterInfo* EditEntInfoWidget::getFinishEnterInfo()
{
	return m_pFinishentinfo;
}

void EditEntInfoWidget::onOfficeAreaIndexChanged(int index)
{
	int nCode = ui.comboBoxAreaOffice->itemData(index).toInt();
	m_pentinfo->_nOfficeAreaid = nCode;
	if (m_pentinfo->_nOfficeAreaid == -999)
	{
		ui.labelAreaError->show();
	}
	else
	{
		ui.labelAreaError->hide();
	}
	m_pentinfo->_strOfficeArea = ui.comboBoxArea->currentText();
}

void EditEntInfoWidget::onOfficeCityIndexChanged(int index)
{
	if (index == -1)
	{
		return;
	}
	ui.comboBoxAreaOffice->clear();
	int nCode = ui.comboBoxCityOffice->itemData(index).toInt();
	m_pentinfo->_nOfficeCityid = nCode;
	m_pentinfo->_strOfficeCity = ui.comboBoxCity->currentText();
	showAreaData(ui.comboBoxAreaOffice, nCode);
	if (m_pentinfo->_nOfficeCityid == -999)
	{
		ui.labelAreaError->show();
	}
	else
	{
		ui.labelAreaError->hide();
	}
}

void EditEntInfoWidget::onOfficeProIndexChanged(int index)
{
	if (index == -1)
	{
		return;
	}
	ui.comboBoxCityOffice->clear();
	ui.comboBoxAreaOffice->clear();
	int nCode = ui.comboBoxProOffice->itemData(index).toInt();
	m_pentinfo->_nOfficeProvinceid = nCode;
	m_pentinfo->_strOfficeProvince = ui.comboBoxProOffice->currentText();
	showAreaData(ui.comboBoxCityOffice, nCode);
	if (m_pentinfo->_nOfficeProvinceid == -999)
	{
		ui.labelAreaError->show();
	}
	else
	{
		ui.labelAreaError->hide();
	}
}

void EditEntInfoWidget::ChangeShow(bool beditdb)
{

	m_beditdb = beditdb;
	if (m_beditdb)
	{
		ui.okButton->show();
		ui.nextbutton->hide();
	}
	else
	{
		ui.okButton->hide();
		ui.nextbutton->show();
	   
	}
}
