#pragma once

#include <QWidget>
#include "ui_BindMobileWidget.h"
#include "ZcloudCommonWidget.h"
#include <QTimer>

class BindMobileWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	
	BindMobileWidget(QString& strMobile, QString strUid, QString strToken, bool bResetPwd ,QWidget *parent = Q_NULLPTR);
	~BindMobileWidget();

signals:
	void sigBindMobileSucessed(int, bool);
	void sigCheckForgetPwdSucessed();
private slots:
	//!手机绑定
	void onBindMobileOkBtnClick();
	void onMobileEditingFinished();
	void onSendCodeBtnClick();
	void onMobileCodeEditingFinished();
private:
	//!发送手机验证码
	bool winHttpSendCode(QString strMobile,QString strCodeType, QString& strRet);

	//!验证手机验证码
	bool winHttpCheckCode(QString strMobile, QString strCode, QString strCodeType, QString& strRet);

	//!绑定手机号
	bool winHttpBindMobile(QString strUid, QString strToken, QString strMobile, QString strMobileCode,QString strCodeType, QString& strRet);

	QTimer  timer;
	int		m_nCountDown = 60;
	QString	m_strUid;
	QString	m_strToken;
	QString& m_strMobile;
	Ui::BindMobileWidget  ui;
	bool	m_bMobile		= false;
	bool	m_bMobileCode	= false;
	bool	m_bValidation	= false;
	bool	m_bResetPwd		= false;
};
