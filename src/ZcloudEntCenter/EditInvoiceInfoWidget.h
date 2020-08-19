#pragma once

#include <QWidget>
#include "ui_EditInvoiceInfoWidget.h"
#include "ZcloudCommonWidget.h"
#include "EntInfoDataDefine.h"
#include "ZcloudClient.h"
#include "EntDataBase.h"

class EditInvoiceInfoWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	EditInvoiceInfoWidget(EntCenterInfo* info,QString strUid, QString strToken, stInvoiceInfo invoiceInfo, QWidget *parent = Q_NULLPTR);
	~EditInvoiceInfoWidget();
signals:
	void sigUpdateSucessed();
private slots:
	void onAccEditBtnClick();
	void onBankEditBtnClick();
	void onTelNoEditBtnClick();
	void onAddrEditBtnClick();
	void onEditOkBtnClick();
private:
	void showInvoiceData();

	//!更新企业资料开票信息
	bool winHttpUpdateCompanyInfo(QString strUid, QString strToken, QString strAcc, QString strBank, QString strTel, QString strAddr, QString& strRet);

	Ui::EditInvoiceInfoWidget ui;
	stInvoiceInfo m_stInvoiceInfo;
	QString		m_strUid;
	QString		m_strToken;

	EntCenterInfo* m_info;

	bool m_bAcc		= true;
	bool m_bBank	= true;
	bool m_bTelNo	= true;
	bool m_bAddr	= true;

};
