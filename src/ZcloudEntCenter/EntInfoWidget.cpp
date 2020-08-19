#include "EntInfoWidget.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QFileInfo>
#include <QPainter>
#include "ZcloudCommon.h"
#include "EditEntInfoWidget.h"
#include "EditInvoiceInfoWidget.h"
#include "ZcloudBigData.h"

EntInfoWidget::EntInfoWidget(UserInfoStruct* _userinfo, EntCenterInfo* _pentinfo, QWidget *parent)
	:ZcloudCommonWidget(parent)
{
	ui.setupUi(getContentWidget());
	resize(800, 500);
	setWindowTitle(QString::fromLocal8Bit("企业资料"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("entInfo");
	m_userinfo = _userinfo;
	m_pentinfo = _pentinfo;
	connect(ui.closeButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD009");
		close();
	});

	ui.entEditWidget->installEventFilter(this);
	ui.invoiceEditWidget->installEventFilter(this);

	if (!showEntInfo())
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n打开企业资料失败，请稍后再试！"));
		close();
	}
}

EntInfoWidget::~EntInfoWidget()
{
}

void EntInfoWidget::onEntEditBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD001");
	EditEntInfoWidget*	pWidget = new EditEntInfoWidget(m_userinfo, m_pentinfo, this);
	connect(pWidget, &EditEntInfoWidget::sigUpdateSucessed, this, &EntInfoWidget::onUpdateEntSucessed);
	pWidget->show();
}

void EntInfoWidget::onInvoiceEditBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD005");
	EditInvoiceInfoWidget*	pWidget = new EditInvoiceInfoWidget(m_pentinfo,m_strUid, m_strToken, m_stInvoiceInfo, this);
	connect(pWidget, &EditInvoiceInfoWidget::sigUpdateSucessed, this, &EntInfoWidget::onUpdateinvoiceSucessed);
	pWidget->show();
}

bool EntInfoWidget::winHttpGetEntInfo(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/v2/company/get-company-info?user_id=%1&token=%2").arg(strUid).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

bool EntInfoWidget::showEntInfo()
{
	QString strRet;
	if (!winHttpGetEntInfo(m_userinfo->m_strUserId, m_userinfo->m_strToken, strRet))
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
	
	QJsonObject data = obj.take("data").toObject();

	m_stEntInfo._strCompId		= data.take("company_id").toString();

	//!公司名称
	m_stEntInfo._strCompName	= data.take("company_name").toString();
	QString	strCompName = m_stEntInfo._strCompName;
	if (strCompName.isEmpty())
	{
		strCompName = QString::fromLocal8Bit("暂未查询到您的企业");
	}
	ui.labelCompName->setText(strCompName);
	ui.labelCompName->adjustSize();

	//!税号
	m_stEntInfo._strTaxNo = data.take("tax_number").toString();
	ui.labelTaxNo->setText(m_stEntInfo._strTaxNo);

	//!头像
	m_stEntInfo._strLogoPath = ZcloudComFun::downloadPic(data.take("logo").toString(), QApplication::applicationDirPath().append("/CacheImage/logoImage"));
	QString strLogoPath = m_stEntInfo._strLogoPath;
	QFileInfo fileInfo(strLogoPath);
	if (!fileInfo.isFile())
	{
		strLogoPath = ":/EntCenterWidget/image/img_tx_d.png";
	}
	QPixmap pixmapa;
	pixmapa.load(strLogoPath);
	QRect	rectLabel = ui.labelAvatar->geometry();
	QPixmap pixmap(rectLabel.width(), rectLabel.height());
	pixmap.fill(Qt::transparent);
	QPainter painter(&pixmap);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	QPainterPath path;
	path.addEllipse(0, 0, rectLabel.width(), rectLabel.height());
	painter.setClipPath(path);
	painter.drawPixmap(0, 0, rectLabel.width(), rectLabel.height(), pixmapa);
	ui.labelAvatar->setPixmap(pixmap);

	//!行业
	m_stEntInfo._nTradeId = data.take("trade_id").toInt();
	m_stEntInfo._strTradeName = data.take("trade_name").toString();
	QString strTradeName = m_stEntInfo._strTradeName;
	if (strTradeName.isEmpty())
	{
		strTradeName = QString::fromLocal8Bit("——");
	}
	ui.labelIndustry->setText(strTradeName);
	ui.labelIndustry->adjustSize();

	//!行政区域
	m_stEntInfo.m_registerAddress._nProId		= data.take("province_id").toInt();
	m_stEntInfo.m_registerAddress._nCityId	= data.take("city_id").toInt();
	m_stEntInfo.m_registerAddress._nAreaId	= data.take("area_id").toInt();
	m_stEntInfo.m_registerAddress._strPro		= data.take("province_name").toString();
	QString strPro			= m_stEntInfo.m_registerAddress._strPro;
	m_stEntInfo.m_registerAddress._strCity	= data.take("city_name").toString();
	QString strCity			= m_stEntInfo.m_registerAddress._strCity;
	m_stEntInfo.m_registerAddress._strArea	= data.take("area_name").toString();
	QString strArea			= m_stEntInfo.m_registerAddress._strArea;
	QString strText;
	if (strPro.isEmpty())
	{
		strText = QString::fromLocal8Bit("——");
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

	//!财税负责人
	m_stEntInfo._strOfficeName  = data.take("financial_officer").toString();
	QString strOfficerName = m_stEntInfo._strOfficeName;
	if (strOfficerName.isEmpty())
	{
		strOfficerName = QString::fromLocal8Bit("——");
	}
	ZcloudComFun::setElideText(14, ui.labelName, strOfficerName);

	//!负责人手机号
	m_stEntInfo._strOfficeMobile = data.take("financial_phone").toString();
	QString strPhone = m_stEntInfo._strOfficeMobile;
	if (strPhone.isEmpty())
	{
		strPhone = QString::fromLocal8Bit("——");
	}
	ZcloudComFun::setElideText(14, ui.labelMobile, strPhone);

	//!开户账号
	m_stInvoiceInfo._strBankAccount = data.take("bank_account").toString();
	QString strBankAccount = m_stInvoiceInfo._strBankAccount;
	if (strBankAccount.isEmpty())
	{
		strBankAccount = QString::fromLocal8Bit("——");
	}
	ZcloudComFun::setElideText(14, ui.labelAcc, strBankAccount);

	//!开户银行
	m_stInvoiceInfo._strBankName = data.take("bank_name").toString();
	QString strBankName = m_stInvoiceInfo._strBankName;
	if (strBankName.isEmpty())
	{
		strBankName = QString::fromLocal8Bit("——");
	}
	ZcloudComFun::setElideText(14, ui.labelBank, strBankName);

	//!开户电话
	m_stInvoiceInfo._strTelNo = data.take("tel_number").toString();
	QString strTelNo = m_stInvoiceInfo._strTelNo;
	if (strTelNo.isEmpty())
	{
		strTelNo = QString::fromLocal8Bit("——");
	}
	ui.labelPhone->setText(strTelNo);
	ui.labelPhone->adjustSize();

	//!地址
	m_stInvoiceInfo._strAddr = data.take("address").toString();
	QString strAddr = m_stInvoiceInfo._strAddr;
	if (strAddr.isEmpty())
	{
		strAddr = QString::fromLocal8Bit("——");
	}
	ui.labelAddr->setText(strAddr);
	ui.labelAddr->adjustSize();

	int	nAdmin = data.take("is_admin").toInt();

	if (nAdmin != 1)
	{
		ui.entEditWidget->hide();
		ui.invoiceEditWidget->hide();
	}
	return true;
}

void EntInfoWidget::onUpdateinvoiceSucessed()
{
	EditInvoiceInfoWidget*	pWidget = qobject_cast<EditInvoiceInfoWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
	showEntInfo();
}

void EntInfoWidget::onUpdateEntSucessed()
{
	EditEntInfoWidget*	pWidget = qobject_cast<EditEntInfoWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
	showEntInfo();
}

bool EntInfoWidget::eventFilter(QObject *target, QEvent *e)
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
