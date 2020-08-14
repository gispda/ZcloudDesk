#pragma once

#include <QWidget>
#include "ui_EntInfoWidget.h"
#include "ZcloudCommonWidget.h"
#include "EntInfoDataDefine.h"
#include "EntDataBase.h"

class EntInfoWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	EntInfoWidget(UserInfoStruct* _userinfo, EntCenterInfo* _pentinfo, QWidget *parent = Q_NULLPTR);
	~EntInfoWidget();

private slots:
	void onEntEditBtnClick();
	void onInvoiceEditBtnClick();
	void onUpdateinvoiceSucessed();
	void onUpdateEntSucessed();

protected:
	bool eventFilter(QObject *target, QEvent *e);
private:
	bool showEntInfo();

	//!获取企业资料
	bool winHttpGetEntInfo(QString strUid,QString strToken,QString& strRet);



	EntCenterInfo* m_pentinfo;

	UserInfoStruct* m_userinfo;
	stEntInfo		m_stEntInfo;
	stInvoiceInfo	m_stInvoiceInfo;
	QString			m_strUid;
	QString			m_strToken;
	Ui::EntInfoWidget ui;
};
