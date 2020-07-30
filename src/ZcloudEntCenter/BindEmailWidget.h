#pragma once

#include <QWidget>
#include "ui_BindEmailWidget.h"
#include "ZcloudCommonWidget.h"
#include <QTimer>
class BindEmailWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	BindEmailWidget(QString strUid,QString strToken,QWidget *parent = Q_NULLPTR);
	~BindEmailWidget();
signals:
	void sigBindEmailSucessed(QString, int, bool);
private slots:
	void onEmailEditingFinished();
	void onEmailCodeEditingFinished();
	void onSendCodeBtnClick();
	void onBindEmailOkBtnClick();
private:
	//!获取邮箱验证码
	bool winHttpSendEmail(QString strUid, QString strToken, QString strEmail, QString& strRet);

	//!绑定邮箱
	bool winHttpBindEmail(QString strUid, QString strToken, QString strEmail, QString strCode, QString& strRet);

	Ui::BindEmailWidget ui;
	QString	m_strUid;
	QString	m_strToken;
	QTimer  timer;
	int		m_nCountDown = 60;
	bool	m_bEmailCode = false;
	bool	m_bEmail = false;
};
