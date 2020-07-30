#pragma once

#include <QDialog>
#include "ui_AddMemberWidget.h"
#include "ZcloudCommonWidget.h"

class AddMemberWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	AddMemberWidget(QString strUid, QString strToken, QWidget *parent = Q_NULLPTR);
	~AddMemberWidget();
signals:
	void sigAddMember();
private slots :
	void onAddOkBtnClick();
	void onNameEditingFinished();
	void onAccEditingFinished();
	void onPwdEditingFinished();
	void onJobEditingFinished();
private:

	//!ÃÌº”≥…‘±
	bool winHttpAddMember(QString strUid, QString strToken, QString strTrueName, QString strAcc, QString strPwd, QString strJob, QString& strRet);

	Ui::AddMemberWidget ui;
	QString		m_strUid;
	QString		m_strToken;
	bool m_bName	=	false;
	bool m_bAcc		=	false;
	bool m_bPwd		=	false;
	bool m_bJob		=	true;
};
