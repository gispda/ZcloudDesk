#pragma once

#include <QWidget>
#include "ui_ModifyPwdWidget.h"
#include "ZcloudCommonWidget.h"

class ModifyPwdWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	ModifyPwdWidget(QString strUid,QString strToken,QWidget *parent = Q_NULLPTR);
	~ModifyPwdWidget();
signals:
	void sigResetPwdSucessed(int, bool);
	void sigForgetPwd();
protected:
	bool eventFilter(QObject *target, QEvent *e);

private slots:
	void onModifyOkBtnClick();
	void onOldPwdEditBtnClick();
	void onNewPwdEditBtnClick();
	void onComfirmPwdEditBtnClick();
private:
	//!ÐÞ¸ÄÃÜÂë
	bool winHttpResetPwd(QString strUid, QString strToken, QString strOldPwd, QString strNewPwd, QString strComfirmPwd, QString& strRet);

	QString m_strUid;
	QString	m_strToken;
	bool	m_bOldPwd		= false;
	bool	m_bNewPwd		= false;
	bool	m_bComfirmPwd	= false;
	Ui::ModifyPwdWidget ui;
};
