#include "EntCenterInfoWidget.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QFileInfo>
#include <QPainter>
#include "ZcloudCommon.h"
#include "EditEntInfoWidget.h"
#include "EditInvoiceInfoWidget.h"
#include "ZcloudBigData.h"

EntCenterInfoWidget::EntCenterInfoWidget(EntCenterInfo*	info, UserInfoStruct* userInfo, QWidget *parent)
	:QWidget( parent)
{
	ui.setupUi(this);
	m_userInfo = userInfo;
	m_pInfo = info;
	ui.entEditWidget->installEventFilter(this);
	ui.invoiceEditWidget->installEventFilter(this);

	ui.labelTaxCode->setText(m_pInfo->_strTaxNo);
	ui.labelCompany->setText(m_pInfo->_strCompName);
	//m_userinfo->m_logoUrl

}

EntCenterInfoWidget::~EntCenterInfoWidget()
{

}

void EntCenterInfoWidget::init(EntCenterInfo* info){
	m_pInfo = info;


	
	ui.labelArea->setText(m_pInfo->_strAddress);
	ui.labelName->setText(m_pInfo->_strlegalboss);
	ui.labelMobile->setText(m_pInfo->_strlegalbossmobile);

	ui.labelAcc->setText(m_pInfo->_strBankaccount);
	ui.labelBank->setText(m_pInfo->_strBankname);
	ui.labelAddr->setText(m_pInfo->_strOfficeaddress);

	////管理员权限 显示编辑
	//ui.entEditWidget->hide();
	//ui.invoiceEditWidget->hide();
	//if (m_pInfo->_nrole_type == 1)
	//{
	//	ui.entEditWidget->show();
	//	ui.invoiceEditWidget->show();
	//}

}




void EntCenterInfoWidget::onEntEditBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD001");
	EditEntInfoWidget*	pWidget = new EditEntInfoWidget(this->m_userInfo, m_pInfo, true, this);
	connect(pWidget, &EditEntInfoWidget::sigUpdateSucessed, this, &EntCenterInfoWidget::onUpdateEntSucessed);
	pWidget->show();
}

void EntCenterInfoWidget::onInvoiceEditBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD005");
	
	/*ui.labelAcc->setText(m_pInfo->_strBankaccount);
	ui.labelBank->setText(m_pInfo->_strBankname);
	ui.labelAddr->setText(m_pInfo->_strOfficeaddress);*/

	stInvoiceInfo m_stInvoiceInfo ;
	m_stInvoiceInfo._strAddr = m_pInfo->_strOfficeaddress;
	m_stInvoiceInfo._strBankAccount = m_pInfo->_strBankaccount;
	m_stInvoiceInfo._strBankName = m_pInfo->_strBankname;
	EditInvoiceInfoWidget*	pWidget = new EditInvoiceInfoWidget(m_pInfo->_strId, m_pInfo->_strToken, m_stInvoiceInfo, this);
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

void EntCenterInfoWidget::onUpdateinvoiceSucessed()
{
	EditInvoiceInfoWidget*	pWidget = qobject_cast<EditInvoiceInfoWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
	init(m_pInfo);
}

void EntCenterInfoWidget::onUpdateEntSucessed()
{
	EditEntInfoWidget*	pWidget = qobject_cast<EditEntInfoWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
	init(m_pInfo);
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

