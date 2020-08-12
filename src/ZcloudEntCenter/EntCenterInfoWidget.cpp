#include "EntCenterInfoWidget.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QFileInfo>
#include <QPainter>
#include "ZcloudCommon.h"
#include "EditEntInfoWidget.h"
#include "EditInvoiceInfoWidget.h"
#include "ZcloudBigData.h"

EntCenterInfoWidget::EntCenterInfoWidget(UserInfoStruct _userInfo, QWidget *parent)
	:AppCommWidget("", true, parent)
{
	ui.setupUi(m_widget);

	m_userinfo = _userInfo;
	ui.entEditWidget->installEventFilter(this);
	ui.invoiceEditWidget->installEventFilter(this);

}

EntCenterInfoWidget::~EntCenterInfoWidget()
{

}

void EntCenterInfoWidget::init(EntCenterInfo*	info){
	m_stEntInfo._strCompId = info->_strCompId;
	m_stEntInfo._strCompName = info->_strCompName;
	m_stEntInfo._nTradeId = info->_nTradeid;
	m_stEntInfo._strLogoPath = info->_strLogoPath;
	m_stEntInfo._strOfficeMobile = info->_strlegalbossmobile;
	m_stEntInfo._strOfficeName = info->_strlegalboss;
	m_stEntInfo._strTaxNo = info->_strTaxNo;
	m_stEntInfo.m_registerAddress._nProId = info->_nProvinceid;
	m_stEntInfo.m_registerAddress._nCityId = info->_nCityid;
	m_stEntInfo.m_registerAddress._nAreaId = info->_nAreaid;
	m_stEntInfo.m_registerAddress._address = info->_strRegisterFulladdress;

	m_stEntInfo.m_officeAddress._nProId = info->_nOfficeProvinceid;
	m_stEntInfo.m_officeAddress._nCityId = info->_nOfficeCityid;
	m_stEntInfo.m_officeAddress._nAreaId = info->_nOfficeAreaid;
	m_stEntInfo.m_officeAddress._address = info->_strOfficeFulladdress;

}


void EntCenterInfoWidget::onEntEditBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD001");
	EditEntInfoWidget*	pWidget = new EditEntInfoWidget(m_userinfo.m_strUserId, m_userinfo.m_strToken, m_stEntInfo, this);
	connect(pWidget, &EditEntInfoWidget::sigUpdateSucessed, this, &EntCenterInfoWidget::onUpdateEntSucessed);
	pWidget->show();
}

void EntCenterInfoWidget::onInvoiceEditBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD005");
	EditInvoiceInfoWidget*	pWidget = new EditInvoiceInfoWidget(m_userinfo.m_strUserId, m_userinfo.m_strToken, m_stInvoiceInfo, this);
	connect(pWidget, &EditInvoiceInfoWidget::sigUpdateSucessed, this, &EntCenterInfoWidget::onUpdateinvoiceSucessed);
	pWidget->show();
}

bool EntCenterInfoWidget::winHttpGetEntInfo(QString strTaxno, QString strToken, QString& strRet)
{
	QString strUrl = QString("/ucenter/company/info");
	QString strPost;

	strPost = QString("tax=%1").arg(strTaxno);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet,false,1);
}

bool EntCenterInfoWidget::showEntInfo()
{
	QString strRet;
	if (!winHttpGetEntInfo(m_stEntInfo._strTaxNo, m_userinfo.m_strToken, strRet))
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
	int status = obj.take("code").toInt();
	if (0 != status)
	{
		return false;
	}

	QJsonObject data = obj.take("data").toObject();

	m_stEntInfo._strCompId = data.take("company_id").toString();

	//!��˾����
	m_stEntInfo._strCompName = data.take("company_name").toString();
	QString	strCompName = m_stEntInfo._strCompName;
	if (strCompName.isEmpty())
	{
		strCompName = QString::fromLocal8Bit("��δ��ѯ��������ҵ");
	}
	ui.labelCompany->setText(strCompName);
	ui.labelCompany->adjustSize();

	//!˰��
	m_stEntInfo._strTaxNo = data.take("tax_number").toString();
	ui.labelTaxCode->setText(m_stEntInfo._strTaxNo);

	//!ͷ��
	//m_stEntInfo._strLogoPath = ZcloudComFun::downloadPic(data.take("logo").toString(), QApplication::applicationDirPath().append("/CacheImage/logoImage"));
	//QString strLogoPath = m_stEntInfo._strLogoPath;
	//QFileInfo fileInfo(strLogoPath);
	//if (!fileInfo.isFile())
	//{
	//	strLogoPath = ":/EntCenterWidget/image/img_tx_d.png";
	//}
	//QPixmap pixmapa;
	//pixmapa.load(strLogoPath);
	//QRect	rectLabel = ui.labelAvatar->geometry();
	//QPixmap pixmap(rectLabel.width(), rectLabel.height());
	//pixmap.fill(Qt::transparent);
	//QPainter painter(&pixmap);
	//painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	//QPainterPath path;
	//path.addEllipse(0, 0, rectLabel.width(), rectLabel.height());
	//painter.setClipPath(path);
	//painter.drawPixmap(0, 0, rectLabel.width(), rectLabel.height(), pixmapa);
	//ui.labelAvatar->setPixmap(pixmap);

	////!��ҵ
	//m_stEntInfo._nTradeId = data.take("trade_id").toInt();
	//m_stEntInfo._strTradeName = data.take("trade_name").toString();
	//QString strTradeName = m_stEntInfo._strTradeName;
	//if (strTradeName.isEmpty())
	//{
	//	strTradeName = QString::fromLocal8Bit("����");
	//}
	//ui.labelIndustry->setText(strTradeName);
	//ui.labelIndustry->adjustSize();

	//!��������
	m_stEntInfo.m_registerAddress._nProId = data.take("province_id").toInt();
	m_stEntInfo.m_registerAddress._nCityId = data.take("city_id").toInt();
	m_stEntInfo.m_registerAddress._nAreaId = data.take("area_id").toInt();
	m_stEntInfo.m_registerAddress._strPro = data.take("province_name").toString();
	QString strPro = m_stEntInfo.m_registerAddress._strPro;
	m_stEntInfo.m_registerAddress._strCity = data.take("city_name").toString();
	QString strCity = m_stEntInfo.m_registerAddress._strCity;
	m_stEntInfo.m_registerAddress._strArea = data.take("area_name").toString();
	QString strArea = m_stEntInfo.m_registerAddress._strArea;
	QString strText;
	if (strPro.isEmpty())
	{
		strText = QString::fromLocal8Bit("����");
	}
	else
	{
		if (strCity.isEmpty())
		{
			strText = strPro;
		}
		else
		{
			if (strArea.isEmpty())
			{
				strText = strPro + "-" + strCity;
			}
			else
			{
				strText = strPro + "-" + strCity + "-" + strArea;
			}
		}
	}
	ui.labelArea->setText(strText);
	ui.labelArea->adjustSize();

	//!��˰������
	m_stEntInfo._strOfficeName = data.take("legal_person_name").toString();
	QString strOfficerName = m_stEntInfo._strOfficeName;
	if (strOfficerName.isEmpty())
	{
		strOfficerName = QString::fromLocal8Bit("����");
	}
	ZcloudComFun::setElideText(14, ui.labelName, strOfficerName);

	//!�������ֻ���
	m_stEntInfo._strOfficeMobile = data.take("legal_person_phone").toString();
	QString strPhone = m_stEntInfo._strOfficeMobile;
	if (strPhone.isEmpty())
	{
		strPhone = QString::fromLocal8Bit("����");
	}
	ZcloudComFun::setElideText(14, ui.labelMobile, strPhone);

	//!�����˺�
	m_stInvoiceInfo._strBankAccount = data.take("bank_account").toString();
	QString strBankAccount = m_stInvoiceInfo._strBankAccount;
	if (strBankAccount.isEmpty())
	{
		strBankAccount = QString::fromLocal8Bit("����");
	}
	ZcloudComFun::setElideText(14, ui.labelAcc, strBankAccount);

	//!��������
	m_stInvoiceInfo._strBankName = data.take("bank_name").toString();
	QString strBankName = m_stInvoiceInfo._strBankName;
	if (strBankName.isEmpty())
	{
		strBankName = QString::fromLocal8Bit("����");
	}
	ZcloudComFun::setElideText(14, ui.labelBank, strBankName);

	//!�����绰
	m_stInvoiceInfo._strTelNo = data.take("tel_number").toString();
	QString strTelNo = m_stInvoiceInfo._strTelNo;
	if (strTelNo.isEmpty())
	{
		strTelNo = QString::fromLocal8Bit("����");
	}
	ui.labelPhone->setText(strTelNo);
	ui.labelPhone->adjustSize();

	//!��ַ
	m_stInvoiceInfo._strAddr = data.take("address").toString();
	QString strAddr = m_stInvoiceInfo._strAddr;
	if (strAddr.isEmpty())
	{
		strAddr = QString::fromLocal8Bit("����");
	}
	ui.labelAddr->setText(strAddr);
	ui.labelAddr->adjustSize();


	QJsonObject userdata = data.take("user").toObject();

	int	nAdmin = userdata.take("role_type").toInt();

	if (nAdmin != 1)
	{
		ui.entEditWidget->hide();
		ui.invoiceEditWidget->hide();
	}
	return true;
}

void EntCenterInfoWidget::onUpdateinvoiceSucessed()
{
	EditInvoiceInfoWidget*	pWidget = qobject_cast<EditInvoiceInfoWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
	showEntInfo();
}

void EntCenterInfoWidget::onUpdateEntSucessed()
{
	EditEntInfoWidget*	pWidget = qobject_cast<EditEntInfoWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
	showEntInfo();
}

bool EntCenterInfoWidget::eventFilter(QObject *target, QEvent *e)
{
	if (target == ui.entEditWidget)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			onEntEditBtnClick();
		}
	}
	else if (target == ui.invoiceEditWidget)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			onInvoiceEditBtnClick();
		}
	}
	return QWidget::eventFilter(target, e);
}
