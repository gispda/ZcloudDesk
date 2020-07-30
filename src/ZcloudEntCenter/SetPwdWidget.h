#pragma once

#include <QWidget>
#include "ui_SetPwdWidget.h"
#include "ZcloudCommonWidget.h"

class SetPwdWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	SetPwdWidget(QString strUid, QString strToken,QWidget *parent = Q_NULLPTR);
	~SetPwdWidget();
signals:
	void sigSetPwdSucessed(int, bool);
private slots:
	void onSetOkBtnClick();
	void onNewPwdEditBtnClick();
	void onComfirmPwdEditBtnClick();
private:
	//!…Ë÷√–¬√‹¬Î
	bool winHttpSetPwd(QString strUid, QString strToken, QString strNewPwd, QString strComfirmPwd, QString& strRet);

	QString m_strUid;
	QString	m_strToken;
	bool	m_bNewPwd = false;
	bool	m_bComfirmPwd = false;
	Ui::SetPwdWidget ui;
};
