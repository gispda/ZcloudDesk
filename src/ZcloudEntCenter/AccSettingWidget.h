#pragma once
#include <QWidget>
#include "ui_AccSettingWidget.h"
#include "ZcloudCommonWidget.h"
#include <QJsonObject>
#include "AcceptAddressWidget.h"

class AccSettingWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	AccSettingWidget(QString strUid,QString strToken,QString strTitle,QWidget *parent = Q_NULLPTR);
	~AccSettingWidget();
signals:
	void sigChangeCoin(int);
	void sigEditUserInfoSucessed(const QString&, const QString&);
	void sigBindMobileSucessed(const QString&);
protected:
	bool eventFilter(QObject *target, QEvent *e);

private slots:
	void onModifyUserInfoSucessed(int nCoin, bool bPerfect);
	void onBindMobileSucessed(int nCoin, bool bPerfect);
	void onBindEmailSucessed(QString strEmail, int nCoin, bool bPerfect);
	void onUpdateAddrSucessed(int nCoin, bool bPerfect, AddressInfo  addrInfo);
	void onResetPwdSucessed(int nCoin, bool bPerfect);
	void onSetPwdSucessed(int nCoin, bool bPerfect);
	void onForgetPwd();
	void onCheckForgetPwdSucessed();
private:
	bool showAccSettingInfo();
private:
	//!获取账号设置数据
	bool winHttpGetAccountSetting(QString strUid, QString strToken, QString& strRet);

	QString	m_strUid;
	QString	m_strToken;
	QString	m_strTrueName;
	QString	m_strJob;
	QString	m_strMobile;
	AddressInfo m_addrInfo;
	Ui::AccSettingWidget ui;
};
