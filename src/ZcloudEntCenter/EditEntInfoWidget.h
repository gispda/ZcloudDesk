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
	void onLegalPeasonEditingFinished();
	void onPhoneEditingFinished();
	void onEditOkBtnClick();
	void onRadioBtnAddressRegClick();
	void onRadioBtnAddressNewClick();
private:
	bool showTradeData();

	bool showAreaData(QComboBox* pComBoBox,int nCode);

	//!��ȡ��ҵ
	bool winHttpGetTradeList(QString& strRet);
	//!��ȡʡ����
	bool winHttpGetAreaList(int code,QString& strRet);

	//!������ҵ����
	bool winHttpUpdateCompanyInfo(QString strUid,QString strToken,QString& strRet);

	Ui::EditEntInfoWidget ui;
	stEntInfo m_stEntInfo;
	QString	m_strUid;
	QString	m_strToken;
	bool	m_bLegalPeason = true;
	bool	m_bPhone	= true;
};
