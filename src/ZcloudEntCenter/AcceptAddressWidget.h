#pragma once

#include <QWidget>
#include "ui_AcceptAddressWidget.h"
#include "ZcloudCommonWidget.h"

class AddressInfo
{
public:
	QString _strTureName;
	QString _strMobile;
	int		_nProId		= 0;
	int		_nCityId	= 0;
	int		_nAreaId	= 0;
	QString _strAddr;
};
class AcceptAddressWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	AcceptAddressWidget(QString strUid, QString strToken, AddressInfo addrInfo, QWidget *parent = Q_NULLPTR);
	~AcceptAddressWidget();
signals:
	void sigUpdateAddrSucessed(int, bool, AddressInfo);
private slots:
	void onAddressOkBtnClick();
	void onNameEditBtnClick();
	void onMobileEditBtnClick();
	void onAddrEditBtnClick();
	void onProIndexChanged(int index);
	void onCityIndexChanged(int index);
	void onAreaIndexChanged(int index);
private:
	bool showXzAreaData(QComboBox* pComBoBox, int nCode ,int nCurId);
	//!��ȡʡ����
	bool winHttpGetAreaList(int code, QString& strRet);

	//!�ύ�ջ���ַ
	bool winHttpUpdateAddress(QString strUid, QString strToken, QString strName, QString strMobile, QString strAddr, QString& strRet);

	//!��ʼ���ջ���ַ
	void initAddr();

	QString m_strUid;
	QString m_strToken;
	AddressInfo m_addrInfo;
	bool	m_bName		= false;
	bool	m_bMobile	= false;
	bool	m_bAddr		= false;
	Ui::AcceptAddressWidget ui;
};
