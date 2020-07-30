#pragma once

#include <QWidget>
#include <QMenu>
#include "ui_EditEntInfoWidget.h"
#include "ZcloudCommonWidget.h"
#include "EntInfoDataDefine.h"

class EditEntInfoWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	EditEntInfoWidget(QString strUid,QString strToken,stEntInfo entInfo,QWidget *parent = Q_NULLPTR);
	~EditEntInfoWidget();

signals:
	void sigUpdateSucessed();
private slots:
	void onProIndexChanged(int index);
	void onCityIndexChanged(int index);
	void onAreaIndexChanged(int index);
	void onTradeIndexChanged(int index);
	void onOfficeEditingFinished();
	void onPhoneEditingFinished();
	void onEditOkBtnClick();
private:
	bool showTradeData();

	bool showXzAreaData(QComboBox* pComBoBox,int nCode);

	//!获取行业
	bool winHttpGetTradeList(QString& strRet);
	//!获取省市区
	bool winHttpGetAreaList(int code,QString& strRet);

	//!更新企业资料
	bool winHttpUpdateCompanyInfo(QString strUid,QString strToken,int nTradeId,int nProId,int nCityId,int nAreaId,QString strOfficer,QString strPhone,QString& strRet);

	Ui::EditEntInfoWidget ui;
	stEntInfo m_stEntInfo;
	QString	m_strUid;
	QString	m_strToken;
	bool	m_bOffice	= true;
	bool	m_bPhone	= true;
};
