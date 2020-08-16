#pragma once

#include <QWidget>
#include <QMenu>
#include "ui_EditEntInfoWidget.h"
#include "ZcloudCommonWidget.h"
#include "EntInfoDataDefine.h"
#include "EntDataBase.h"

class EditEntInfoWidget : public QDialog
{
	Q_OBJECT

public:
	EditEntInfoWidget(UserInfoStruct* _userinfo, EntCenterInfo* _pentinfo, QWidget *parent = Q_NULLPTR);
	~EditEntInfoWidget();



	EntCenterInfo* getFinishEnterInfo();
signals:
	void sigUpdateSucessed();
private slots:
	void onProIndexChanged(int index);
	void onCityIndexChanged(int index);
	void onAreaIndexChanged(int index);

	void onOfficeProIndexChanged(int index);
	void onOfficeCityIndexChanged(int index);
	void onOfficeAreaIndexChanged(int index);


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


	////�Ƿ�Ӻ�̨��������
	bool m_bIsloadDb;

	EntCenterInfo* m_pentinfo;
	EntCenterInfo* m_pFinishentinfo;
	UserInfoStruct* m_userinfo;

	//stEntInfo m_stEntInfo;
	QString	m_strUid;
	QString	m_strToken;
	bool	m_bLegalPeason = true;
	bool	m_bPhone	= true;
};
