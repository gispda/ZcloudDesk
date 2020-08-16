#include "CreateEntInfoWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include "ZcloudBigData.h"

CreateEntInfoWidget::CreateEntInfoWidget(QString strUid, QString strToken, QWidget *parent)
	: m_strUid(strUid), m_strToken(strToken), QDialog(parent)
{
	ui.setupUi(this);


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

	

	showAreaData(ui.comboBoxPro, 0);
	showAreaData(ui.comboBoxProOffice, 0);

	

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

	ui.labelCompanyNotFound->hide();
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

	connect(ui.lineEditAddress, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onAddressEditingFinished);
	connect(ui.lineEditAddressOffice, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onAddressOfficeEditingFinished);
	connect(ui.lineEditLegalPeasonName, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onLegalPeasonEditingFinished);
	connect(ui.lineEditPhone, &QLineEdit::editingFinished, this, &CreateEntInfoWidget::onPhoneEditingFinished);
	connect(ui.buttonOK, &QPushButton::clicked, this, &CreateEntInfoWidget::onEditOkBtnClick);
}

CreateEntInfoWidget::~CreateEntInfoWidget()
{
}

void CreateEntInfoWidget::onSearchkBtnClick(){
	//����Э���̨��ѯ��˾��Ϣ

}



void CreateEntInfoWidget::onOkBtnClick()
{
	
	QString strRet;
	//�����½ӿ��޸��ϴ�����
	//if (!winHttpUpdateCompanyInfo(m_strUid, m_strToken, m_stEntInfo._nTradeId, m_stEntInfo._nProId, m_stEntInfo._nCityId, m_stEntInfo._nAreaId, ui.lineEditLegalPeason->text(), ui.lineEditPhone->text(), strRet))
	//{
	//	ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n������ҵ����ʧ�ܣ����Ժ����ԣ�"));
	//	return;
	//}
	
}


void CreateEntInfoWidget::onRadioBtnAddressRegClick(){
	ui.widgetAddressOffice->hide();
	adjustSize();
}
void CreateEntInfoWidget::onRadioBtnAddressNewClick(){
	 ui.widgetAddressOffice->show();
	adjustSize();
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
	m_stEntInfo.m_registerAddress._nProId = nCode;
	m_stEntInfo.m_registerAddress._strPro = ui.comboBoxPro->currentText();
	showAreaData(ui.comboBoxCity, nCode);
	if (m_stEntInfo.m_registerAddress._nProId == -999)
	{
		ui.labelAreaError->show();
	}
	else
	{
		ui.labelAreaError->hide();
	}
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
	m_stEntInfo.m_officeAddress._nProId = nCode;
	m_stEntInfo.m_officeAddress._strPro = ui.comboBoxProOffice->currentText();
	showAreaData(ui.comboBoxCityOffice, nCode);
	if (m_stEntInfo.m_officeAddress._nProId == -999)
	{
		ui.labelAreaOfficeError->show();
	}
	else
	{
		ui.labelAreaOfficeError->hide();
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
	m_stEntInfo.m_registerAddress._nCityId = nCode;
	m_stEntInfo.m_registerAddress._strCity = ui.comboBoxCity->currentText();
	showAreaData(ui.comboBoxArea, nCode);
	if (m_stEntInfo.m_registerAddress._nCityId == -999)
	{
		ui.labelAreaError->show();
	}
	else
	{
		ui.labelAreaError->hide();
	}
}


void CreateEntInfoWidget::onCityOfficeIndexChanged(int index)
{
	if (index == -1)
	{
		return;
	}
	ui.comboBoxAreaOffice->clear();
	int nCode = ui.comboBoxCityOffice->itemData(index).toInt();
	m_stEntInfo.m_officeAddress._nCityId = nCode;
	m_stEntInfo.m_officeAddress._strCity = ui.comboBoxCityOffice->currentText();
	showAreaData(ui.comboBoxAreaOffice, nCode);
	if (m_stEntInfo.m_officeAddress._nCityId == -999)
	{
		ui.labelAreaOfficeError->show();
	}
	else
	{
		ui.labelAreaOfficeError->hide();
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


void CreateEntInfoWidget::onAddressOfficeEditingFinished()
{
	QRegExp	reg(".{5,100}");
	QString strText = ui.lineEditAddressOffice->text();
	if (strText.isEmpty())
	{
		m_bAddress = true;
		ui.labelAddressOfficeError->hide();
		return;
	}
	if (!reg.exactMatch(strText))
	{
		m_bAddress = false;
		ui.labelAddressOfficeError->show();
	}
	else
	{
		m_bAddress = true;
		ui.labelAddressOfficeError->hide();
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
	int nCode = ui.comboBoxArea->itemData(index).toInt();
	
	m_stEntInfo.m_registerAddress._nAreaId = nCode;

	if (m_stEntInfo.m_registerAddress._nAreaId == -999)
	{
		ui.labelAreaError->show();
	}
	else
	{
		ui.labelAreaError->hide();
	}
	m_stEntInfo.m_registerAddress._strArea = ui.comboBoxArea->currentText();
}


void CreateEntInfoWidget::onAreaOfficeIndexChanged(int index)
{
	int nCode = ui.comboBoxAreaOffice->itemData(index).toInt();
	m_stEntInfo.m_officeAddress._nAreaId = nCode;
	if (m_stEntInfo.m_officeAddress._nAreaId == -999)
	{
		ui.labelAreaOfficeError->show();
	}
	else
	{
		ui.labelAreaOfficeError->hide();
	}
	m_stEntInfo.m_officeAddress._strArea = ui.comboBoxAreaOffice->currentText();
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

	if (m_stEntInfo.m_registerAddress._nProId == -999 || m_stEntInfo.m_registerAddress._nCityId == -999 || m_stEntInfo.m_registerAddress._nAreaId == -999)
	{
		ui.labelAreaError->show();
		return;
	}

	if (m_stEntInfo.m_officeAddress._nProId == -999 || m_stEntInfo.m_officeAddress._nCityId == -999 || m_stEntInfo.m_officeAddress._nAreaId == -999)
	{
		ui.labelAreaOfficeError->show();
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

bool CreateEntInfoWidget::winHttpCreateCompanyInfo(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/ucenter/company/update");
	QString strPost = QString("token=%1&company_name=%2&tax=%3&province_id=%4&city_id=%5&area_id=%6&address=%7&legal_person_phone=%8&legal_person_name=%9&office_province_id=%10&office_city_id=%11&office_area_id=%12&office_address=%13")
		             .arg(strToken).arg(m_stEntInfo._strCompName).arg(m_stEntInfo._strTaxNo).arg(m_stEntInfo.m_registerAddress._nProId)
					 .arg(m_stEntInfo.m_registerAddress._nCityId).arg(m_stEntInfo.m_registerAddress._nAreaId).arg(m_stEntInfo.m_registerAddress._address)
					 .arg(m_stEntInfo._strOfficeMobile).arg(m_stEntInfo._strOfficeName).arg(m_stEntInfo.m_officeAddress._nProId)
					 .arg(m_stEntInfo.m_officeAddress._nCityId).arg(m_stEntInfo.m_officeAddress._nAreaId).arg(m_stEntInfo.m_officeAddress._address);
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
	m_stEntInfo.m_officeAddress._address = ui.lineEditAddressOffice->text();
	//m_stEntInfo.m_officeAddress._nAreaId = ui.comboBoxArea;


	m_stEntInfo.m_registerAddress._address = ui.lineEditAddress->text();
	m_stEntInfo._strCompName = ui.lineEditCompanyName->text();

	m_stEntInfo._strOfficeMobile = ui.lineEditPhone->text();
	m_stEntInfo._strOfficeName = ui.lineEditLegalPeasonName->text();
	m_stEntInfo._strTaxNo = ui.lineEditSocietyCode->text();
	
	QString strRet;
	if (!winHttpCreateCompanyInfo(m_strUid, m_strToken, strRet))
	{
		



	
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


			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), strMsg);

		}


}

void CreateEntInfoWidget::clear()
{
	m_stEntInfo.m_officeAddress._address = "";
	m_stEntInfo.m_officeAddress._nAreaId = 0;
	m_stEntInfo.m_officeAddress._nCityId = 0;
	m_stEntInfo.m_officeAddress._nProId = 0;
	m_stEntInfo.m_officeAddress._strArea = "";
	m_stEntInfo.m_officeAddress._strCity = "";
	m_stEntInfo.m_officeAddress._strPro = "";

	m_stEntInfo.m_registerAddress._address = "";
	m_stEntInfo.m_registerAddress._nAreaId = 0;
	m_stEntInfo.m_registerAddress._nCityId = 0;
	m_stEntInfo.m_registerAddress._nProId = 0;
	m_stEntInfo.m_registerAddress._strArea = "";
	m_stEntInfo.m_registerAddress._strCity = "";
	m_stEntInfo.m_registerAddress._strPro = "";

	m_stEntInfo._nTradeId = 0;
	m_stEntInfo._strCompId = "";
	m_stEntInfo._strCompName = "";
	m_stEntInfo._strLogoPath = "";
	m_stEntInfo._strOfficeMobile = "";
	m_stEntInfo._strOfficeName = "";
	m_stEntInfo._strTaxNo = "";
	m_stEntInfo._strTradeName = "";

}
