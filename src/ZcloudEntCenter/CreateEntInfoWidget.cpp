#include "CreateEntInfoWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include "ZcloudBigData.h"
#include <QGraphicsDropShadowEffect>
#include "EntAppealDlg.h"

CreateEntInfoWidget::CreateEntInfoWidget(UserInfoStruct* _userinfo,QString strUid, QString strToken, QWidget *parent)
	:m_userinfo(_userinfo), m_strUid(strUid), m_strToken(strToken), QWidget(parent)
{
	ui.setupUi(this);



	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("��������ҵ"));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setAttribute(Qt::WA_ShowModal, true);
	setStyleSheet("outline: none");

	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);			//��Ӱģ����
	//������Ӱ����
	shadow->setOffset(0, 0);
	//������Ӱ��ɫ
	shadow->setColor(QColor("#666666"));
	//������ӰԲ��
	shadow->setBlurRadius(8);
	//��Ƕ��QWidget������Ӱ
	this->setGraphicsEffect(shadow);

	ui.widget_4->resize(540,390);
	this->resize(542, 392);
	//this->setGeometry(rect.x(), rect.y(), 540, 420);
	ui.widgetAddressOffice->hide();

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});

	
	initProData();
	//showAreaData(ui.comboBoxPro, 0);
	//showAreaData(ui.comboBoxProOffice, 0);

	

	//!ʡ
	ui.comboBoxPro->lineEdit()->setReadOnly(true);
	ui.comboBoxProOffice->lineEdit()->setReadOnly(true);
	//!��
	ui.comboBoxCity->lineEdit()->setReadOnly(true);
	ui.comboBoxCityOffice->lineEdit()->setReadOnly(true);
	//!��
	ui.comboBoxArea->lineEdit()->setReadOnly(true);
	ui.comboBoxAreaOffice->lineEdit()->setReadOnly(true);

	ui.radioButtonAddressReg->setChecked(true);

	//ui.comboBoxProOffice->lineEdit()->setEnabled(false);
	//ui.comboBoxCityOffice->lineEdit()->setEnabled(false);
	//ui.comboBoxAreaOffice->lineEdit()->setEnabled(false);
	//

	//ui.comboBoxProOffice->setDisabled(true);
	//ui.comboBoxCityOffice->setDisabled(true);
	//ui.comboBoxAreaOffice->setDisabled(true);
	//ui.lineEditAddressOffice->setDisabled(true);

	ui.labelCompNameErr->hide();
	ui.labelCompCodeErr->hide();
	ui.labelAreaError->hide();
	ui.labelAddressError->hide();
	ui.labelAreaOfficeError->hide();
	ui.labelAddressOfficeError->hide();
	ui.labelLegalPeasonError->hide();
	ui.labelPhoneError->hide();

	connect(ui.comboBoxPro, SIGNAL(currentIndexChanged(int)), this, SLOT(onProIndexChanged(int)));
	connect(ui.comboBoxCity, SIGNAL(currentIndexChanged(int)), this, SLOT(onCityIndexChanged(int)));
	connect(ui.comboBoxArea, SIGNAL(currentIndexChanged(int)), this, SLOT(onAreaIndexChanged(int)));
	connect(ui.comboBoxProOffice, SIGNAL(currentIndexChanged(int)), this, SLOT(onProOfficeIndexChanged(int)));
	connect(ui.comboBoxCityOffice, SIGNAL(currentIndexChanged(int)), this, SLOT(onCityOfficeIndexChanged(int)));
	connect(ui.comboBoxAreaOffice, SIGNAL(currentIndexChanged(int)), this, SLOT(onAreaOfficeIndexChanged(int)));


	connect(ui.radioButtonAddressReg, SIGNAL(clicked()), this, SLOT(onRadioBtnAddressRegClick()));
	connect(ui.radioButtonAddressNew, SIGNAL(clicked()), this, SLOT(onRadioBtnAddressNewClick()));


	connect(ui.lineEditCompanyName, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onCheckEntName);
	connect(ui.lineEditSocietyCode, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onCheckEntCode);

	connect(ui.lineEditAddress, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onCheckAddress);
	connect(ui.lineEditAddressOffice, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onCheckAddressOffice);

	connect(ui.lineEditLegalPeasonName, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onCheckLegalPeason);
	connect(ui.lineEditPhone, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onCheckPhone);
	connect(ui.buttonOK, &QPushButton::clicked, this, &CreateEntInfoWidget::onOkBtnClick);
	connect(ui.buttonCancel, &QPushButton::clicked, this, &CreateEntInfoWidget::close);

}

CreateEntInfoWidget::~CreateEntInfoWidget()
{
}

void CreateEntInfoWidget::onSearchkBtnClick(){
	//����Э���̨��ѯ��˾��Ϣ

}



void CreateEntInfoWidget::onOkBtnClick()
{

	if (!this->onCheckEntName()){
		ui.labelCompNameErr->show();
		return;
	}
	if (!this->onCheckEntCode()){
		ui.labelCompCodeErr->show();
		return;
	}
	if (!this->onCheckArea()){
		ui.labelAddressError->show();
		return;
	}
	if (!this->onCheckAddress()){
		ui.labelAddressError->show();
		return;
	}
	if (!this->onCheckAreaOffice()){
		ui.labelAddressOfficeError->show();
		return;
	}

	if (!this->onCheckAddressOffice()){
		ui.labelAddressOfficeError->show();
		return;
	}
	if (!this->onCheckLegalPeason()){
		ui.labelLegalPeasonError->show();
		return;
	}
	if (!this->onCheckPhone()){
		ui.labelPhoneError->show();
		return;
	}

	submitCompany();


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


void CreateEntInfoWidget::onRadioBtnAddressRegClick(){

	QRect rect = this->geometry();
	ui.widgetAddressOffice->hide();
	ui.widget_4->resize(540, 390);
	this->resize(542, 402);
	//adjustSize();
}
void CreateEntInfoWidget::onRadioBtnAddressNewClick(){
	QRect rect = this->geometry();
	//this->setGeometry(rect.x(), rect.y(), 540, 480);

	ui.widgetAddressOffice->show();
	ui.widget_4->resize(540, 480);
	this->resize(542, 482);

	//adjustSize();
}


bool CreateEntInfoWidget::winHttpGetAreaList(int code, QString& strRet)
{
	QString strUrl = QString("/param/get-region-by-code?code=%1").arg(code);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

void CreateEntInfoWidget::onProIndexChanged(int index)
{
	if (index == -1)
	{
		return;
	}
	ui.comboBoxCity->clear();
	ui.comboBoxArea->clear();
	int nCode = ui.comboBoxPro->itemData(index).toInt();
	showAreaData(ui.comboBoxCity, nCode);

}

void CreateEntInfoWidget::onProOfficeIndexChanged(int index)
{
	if (index == -1)
	{
		return;
	}
	ui.comboBoxCityOffice->clear();
	ui.comboBoxAreaOffice->clear();
	int nCode = ui.comboBoxProOffice->itemData(index).toInt();

	showAreaData(ui.comboBoxCityOffice, nCode);

}

void CreateEntInfoWidget::onCityIndexChanged(int index)
{
	if (index == -1)
	{
		return;
	}
	ui.comboBoxArea->clear();
	int nCode = ui.comboBoxCity->itemData(index).toInt();
	showAreaData(ui.comboBoxArea, nCode);

}


void CreateEntInfoWidget::onCityOfficeIndexChanged(int index)
{
	if (index == -1)
	{
		return;
	}
	ui.comboBoxAreaOffice->clear();
	int nCode = ui.comboBoxCityOffice->itemData(index).toInt();
	showAreaData(ui.comboBoxAreaOffice, nCode);
}





bool CreateEntInfoWidget::onCheckLegalPeason()
{
	QRegExp	reg(".{2,15}");
	QString strText = ui.lineEditLegalPeasonName->text().trimmed();
	if (strText.isEmpty())
	{
		ui.labelLegalPeasonError->hide();
		return false;
	}
	if (!reg.exactMatch(strText))
	{
		ui.labelLegalPeasonError->show();
		return false;
	}
	else
	{
		ui.labelLegalPeasonError->hide();
		return true;
	}
}

bool CreateEntInfoWidget::onCheckArea()
{

	QString strArea = ui.comboBoxArea->currentText();
	if (strArea.isEmpty() || strArea == QString::fromLocal8Bit("����"))
	{
		ui.labelAreaError->show();
		return false;
	}
	else
	{
		ui.labelAreaError->hide();
		return true;
	}
}

bool CreateEntInfoWidget::onCheckAreaOffice()
{
	if (!ui.radioButtonAddressNew->isChecked()){
		ui.labelAreaOfficeError->hide();
		return true;
	}
	QString strArea = ui.comboBoxAreaOffice->currentText();
	if (strArea.isEmpty() || strArea==QString::fromLocal8Bit("����"))
	{
		ui.labelAreaOfficeError->show();
		return false;
	}
	else
	{
		ui.labelAreaOfficeError->hide();
		return true;
	}
}


bool CreateEntInfoWidget::onCheckAddressOffice()
{
	if (!ui.radioButtonAddressNew->isChecked()){
		ui.labelAddressOfficeError->hide();
		return true;
	}
	QRegExp	reg(".{5,100}");
	QString strText = ui.lineEditAddressOffice->text().trimmed();
	if (strText.isEmpty())
	{
		ui.labelAddressOfficeError->hide();
		return false;
	}
	if (!reg.exactMatch(strText))
	{
		ui.labelAddressOfficeError->show();
		return false;
	}
	else
	{
		ui.labelAddressOfficeError->hide();
		return true;
	}
}


bool CreateEntInfoWidget::onCheckAddress()
{
	QRegExp	reg(".{5,100}");
	QString strText = ui.lineEditAddress->text().trimmed();
	if (strText.isEmpty())
	{
		ui.labelAddressError->hide();
		return false;
	}
	if (!reg.exactMatch(strText))
	{
		ui.labelAddressError->show();
		return false;
	}
	else
	{
		ui.labelAddressError->hide();
		return true;
	}
}
bool CreateEntInfoWidget::onCheckEntName(){
	QRegExp reg(".{2,50}");
	QString strText = ui.lineEditCompanyName->text().trimmed();
	if (strText.isEmpty())
	{
		ui.labelCompNameErr->hide();
		return false;
	}
	if (!reg.exactMatch(strText))
	{
		ui.labelCompNameErr->show();
		return false;
	}
	else
	{
		ui.labelCompNameErr->hide();
		return true;
	}
}
bool CreateEntInfoWidget::onCheckEntCode(){

	QRegExp reg("^[A-Za-z0-9]{18}$");
	QString strText = ui.lineEditSocietyCode->text().trimmed();
	if (strText.isEmpty())
	{
		ui.labelCompCodeErr->hide();
		return false;
	}
	if (!reg.exactMatch(strText))
	{
		ui.labelCompCodeErr->show();
		return false;
	}
	else
	{
		strText = strText.toUpper();
		ui.lineEditSocietyCode->setText(strText);
		ui.labelCompCodeErr->hide();
		return true;
	}
}

bool CreateEntInfoWidget::onCheckPhone()
{
	QRegExp reg("^(13|14|15|17|18)\\d{9}$");
	QString strText = ui.lineEditPhone->text().trimmed();
	if (strText.isEmpty())
	{
		ui.labelPhoneError->hide();
		return false;
	}
	if (!reg.exactMatch(strText))
	{
		ui.labelPhoneError->show();
		return false;
	}
	else
	{		
		ui.labelPhoneError->hide(); 
		return true;
	}
}


bool CreateEntInfoWidget::initProData()
{
	ui.comboBoxPro->insertItem(0, QString::fromLocal8Bit("����"));
	ui.comboBoxPro->setItemData(0, -999);
	ui.comboBoxProOffice->insertItem(0, QString::fromLocal8Bit("����"));
	ui.comboBoxProOffice->setItemData(0, -999);
	QString strRet;
	if (!winHttpGetAreaList(0, strRet))
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
		ui.comboBoxPro->insertItem(nIndex + 1, strName);
		ui.comboBoxPro->setItemData(nIndex + 1, nId);
		ui.comboBoxProOffice->insertItem(nIndex + 1, strName);
		ui.comboBoxProOffice->setItemData(nIndex + 1, nId);

	}
	return true;
}

bool CreateEntInfoWidget::showAreaData(QComboBox* pComBoBox, int nCode)
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
	//int nCode = ui.comboBoxArea->itemData(index).toInt();
	//

	//if (m_stEntInfo.m_registerAddress._nAreaId == -999)
	//{
	//	ui.labelAreaError->show();
	//}
	//else
	//{
	//	ui.labelAreaError->hide();
	//}
	//m_stEntInfo.m_registerAddress._strArea = ui.comboBoxArea->currentText();
}


void CreateEntInfoWidget::onAreaOfficeIndexChanged(int index)
{
	//int nCode = ui.comboBoxAreaOffice->itemData(index).toInt();
	//m_stEntInfo.m_officeAddress._nAreaId = nCode;
	//if (m_stEntInfo.m_officeAddress._nAreaId == -999)
	//{
	//	ui.labelAreaOfficeError->show();
	//}
	//else
	//{
	//	ui.labelAreaOfficeError->hide();
	//}
	//m_stEntInfo.m_officeAddress._strArea = ui.comboBoxAreaOffice->currentText();
}


bool CreateEntInfoWidget::winHttpCreateCompanyInfo(QString strUid, QString strToken, stEntInfo* m_stEntInfo, QString& strRet)
{
	QString strUrl = QString("/ucenter/company/update");
	QString strPost = QString("token=%1&company_name=%2&tax=%3&province_id=%4&city_id=%5&area_id=%6&address=%7&legal_person_phone=%8&legal_person_name=%9&office_province_id=%10&office_city_id=%11&office_area_id=%12&office_address=%13")
		             .arg(strToken).arg(m_stEntInfo->_strCompName).arg(m_stEntInfo->_strTaxNo).arg(m_stEntInfo->m_registerAddress._nProId)
					 .arg(m_stEntInfo->m_registerAddress._nCityId).arg(m_stEntInfo->m_registerAddress._nAreaId).arg(m_stEntInfo->m_registerAddress._address)
					 .arg(m_stEntInfo->_strOfficeMobile).arg(m_stEntInfo->_strOfficeName).arg(m_stEntInfo->m_officeAddress._nProId)
					 .arg(m_stEntInfo->m_officeAddress._nCityId).arg(m_stEntInfo->m_officeAddress._nAreaId).arg(m_stEntInfo->m_officeAddress._address);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet,false,1);
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

void CreateEntInfoWidget::submitCompany()
{
	stEntInfo* m_stEntInfo = new stEntInfo();

	m_stEntInfo->_strCompName = ui.lineEditCompanyName->text();
	m_stEntInfo->_strTaxNo = ui.lineEditSocietyCode->text();

	m_stEntInfo->m_registerAddress._address = ui.lineEditAddress->text();
	
	//ʡ
	int index = ui.comboBoxPro->currentIndex();
	int nCode = ui.comboBoxPro->itemData(index).toInt();
	m_stEntInfo->m_registerAddress._nProId = nCode;
	//��
	index = ui.comboBoxCity->currentIndex();
	nCode = ui.comboBoxCity->itemData(index).toInt();
	m_stEntInfo->m_registerAddress._nCityId = nCode;
	//��
	index = ui.comboBoxArea->currentIndex();
	nCode = ui.comboBoxArea->itemData(index).toInt();
	m_stEntInfo->m_registerAddress._nAreaId = nCode;


	if (ui.radioButtonAddressNew->isChecked()){
		m_stEntInfo->m_officeAddress._address = ui.lineEditAddressOffice->text();
		//ʡ
		index = ui.comboBoxProOffice->currentIndex();
		 nCode = ui.comboBoxProOffice->itemData(index).toInt();
		m_stEntInfo->m_officeAddress._nProId = nCode;
		//��
		index = ui.comboBoxCityOffice->currentIndex();
		 nCode = ui.comboBoxCityOffice->itemData(index).toInt();
		m_stEntInfo->m_officeAddress._nCityId = nCode;
		//��
		index = ui.comboBoxAreaOffice->currentIndex();
		nCode = ui.comboBoxAreaOffice->itemData(index).toInt();
		m_stEntInfo->m_officeAddress._nAreaId = nCode;
		//use_address
		
	}
	else{
		m_stEntInfo->m_officeAddress._address = m_stEntInfo->m_registerAddress._address;
		m_stEntInfo->m_officeAddress._nProId = m_stEntInfo->m_registerAddress._nProId;
		m_stEntInfo->m_officeAddress._nCityId = m_stEntInfo->m_registerAddress._nCityId;
		m_stEntInfo->m_officeAddress._nAreaId = m_stEntInfo->m_registerAddress._nAreaId;
	}
	


	m_stEntInfo->_strOfficeMobile = ui.lineEditPhone->text();
	m_stEntInfo->_strOfficeName = ui.lineEditLegalPeasonName->text();
	
	QString strRet;
	if (!winHttpCreateCompanyInfo(m_strUid, m_strToken, m_stEntInfo,strRet))
	{	delete m_stEntInfo;
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
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("�����ɹ�"), QString::fromLocal8Bit("\r\n������ҵ���ϳɹ���"));


			//if (m_pFinishentinfo == NULL)
			//	m_pFinishentinfo = new EntCenterInfo();
			//*m_pFinishentinfo = *m_pentinfo;
			emit sigUpdateSucessed();
			//this->close();
		}
		else

		{
			ZcloudBigDataInterface::GetInstance()->produceData("M10", "OP000", "BBD002", QString("%1").arg(statecode));


			QString strMsg;

			
			switch (statecode)
			{
			case 20001:
				strMsg = QString::fromLocal8Bit("��ҵ���Ʋ���Ϊ��");
				break;
			case 20002:
				strMsg = QString::fromLocal8Bit("��ҵ���Ƴ������벻��ȷ��4-50��");
				break;
			case 20003:
				strMsg = QString::fromLocal8Bit("˰�Ų���Ϊ��");
				break;
			case 20004:
				strMsg = QString::fromLocal8Bit("˰�����벻��ȷ");
				break;
			case 20005:
				strMsg = QString::fromLocal8Bit("˰�ų������벻��ȷ������15���ַ���");
				break;
			case 20006:
				strMsg = QString::fromLocal8Bit("��������ʡ�ݲ���Ϊ��");
				break;
			case 20007:
				strMsg = QString::fromLocal8Bit("��������ʡ�����벻��ȷ��������");
				break;
			case 20008:
				strMsg = QString::fromLocal8Bit("����������в���Ϊ��");
				break;
			case 20009:
				strMsg = QString::fromLocal8Bit("��������������벻��ȷ��������");
				break;
			case 20010:
				strMsg = QString::fromLocal8Bit("���������������Ϊ��");
				break;
			case 20011:
				strMsg = QString::fromLocal8Bit("��������������벻��ȷ ��������");
				break;
			case 20012:
				strMsg = QString::fromLocal8Bit("��ҵ��ַ����Ϊ��");
				break;
			case 20013:
				strMsg = QString::fromLocal8Bit("��ҵ��ַ���벻��ȷ��5-50���ַ���");
				break;
			case 20014:
				strMsg = QString::fromLocal8Bit("��ҵ���˲���Ϊ��");
				break;
			case 20015:
				strMsg = QString::fromLocal8Bit("��ҵ�������벻��ȷ");
				break;
			case 20016:
				strMsg = QString::fromLocal8Bit("��ҵ���˵绰����Ϊ��");
				break;
			case 20017:
				strMsg = QString::fromLocal8Bit("��ҵ���˵绰�������Ͳ���ȷ");
				break;
			case 20018:
				strMsg = QString::fromLocal8Bit("��ҵ���˵绰���볤�Ȳ���ȷ��11λ���֣�");
				break;
			case 20019:
				strMsg = QString::fromLocal8Bit("����������ȷ");
				break;
			case 20034:
				strMsg = QString::fromLocal8Bit("ϵͳ�����ڴ���ҵ��Ϣ����ȷ����Ĳ���");
				break;
			case 20035:
				strMsg = QString::fromLocal8Bit("��ҵ��Ϣ����ʧ��");
				break;
			case 20038:
				strMsg = QString::fromLocal8Bit("��ǰ��ҵ�Ѿ��󶨹�����Ա��");
			case 20040:
				strMsg = QString::fromLocal8Bit("˰�������Ͳ���Ϊ��");
				break;
			case 20041:
				strMsg = QString::fromLocal8Bit("˰�������Ͳ���ȷ");
				break;
			case 20042:
				strMsg = QString::fromLocal8Bit("ϵͳ�Ѵ��ڴ����Ƶ���ҵ��Ϣ");
				break;
			case 20043:
				strMsg = QString::fromLocal8Bit("�����칫����ʡ�ݲ���Ϊ��");
				break;
			case 20044:
				strMsg = QString::fromLocal8Bit("�����칫����ʡ�����벻��ȷ");
				break;
			case 20045:
				strMsg = QString::fromLocal8Bit("�����칫������в���Ϊ��");
				break;
			case 20046:
				strMsg = QString::fromLocal8Bit("�����칫����������벻��ȷ");
				break;
			case 20047:
				strMsg = QString::fromLocal8Bit("�����칫�����������Ϊ��");
				break;
			case 20048:
				strMsg = QString::fromLocal8Bit("�����칫����������벻��ȷ");
				break;
			case 20049:
				strMsg = QString::fromLocal8Bit("��ҵ�칫��ַ����Ϊ��");
				break;
			case 20050:
				strMsg = QString::fromLocal8Bit("��ҵ�칫��ַ���벻��ȷ");
				break;
			case 20051:
				strMsg = QString::fromLocal8Bit("�����칫������ȷ");
				break;
				break;
			case 20052:
				strMsg = QString::fromLocal8Bit("���ϴ�����Ӫҵִ��");
				break;
			default:
				strMsg = QString::fromLocal8Bit("�����쳣");
				break;
			}

			if (20042 == statecode || 20038 == statecode){
				//��������
				int result = ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_BINDING, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("����ҵ�Ѱ󶨹���Ա����������ϵ��ҵ����Ա����\r\n��ӵ���ҵ��Ա����������Ϊ����ҵ����Ա"), QString::fromLocal8Bit("����"), QString::fromLocal8Bit("ȡ��"));
				if (result == 1){
					//�ϴ�ͼƬ
					
					EntAppealDlg* dlg = new EntAppealDlg(m_stEntInfo, this->m_userinfo, this);
					int rst=dlg->exec();


					
				}
			}
			else{


				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), strMsg);
			}
		}

		delete m_stEntInfo;

}

void CreateEntInfoWidget::clear()
{
	

}
