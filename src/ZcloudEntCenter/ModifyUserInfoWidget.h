#pragma once

#include <QWidget>
#include "ui_ModifyUserInfoWidget.h"
#include "ZcloudCommonWidget.h"

class ModifyUserInfoWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	ModifyUserInfoWidget(QString& strTrueName, QString& strJob, QString strUid, QString strToken,QWidget *parent = Q_NULLPTR);
	~ModifyUserInfoWidget();
signals:
	void sigModifySucessed(int,bool);
private slots:
	void onModifyOkBtnClick();
	void onNameEditingFinished();
	void onJobEditingFinished();
private:

	//!更新用户姓名与职务
	bool winHttpEditUser(QString strUid, QString strToken, QString strTrueName, QString strJob, QString& strRet);

	QString&		m_strTrueName;
	QString&		m_strJob;
	QString			m_strUid;
	QString			m_strToken;
	bool			m_bName = false;
	bool			m_bJob = true;
	Ui::ModifyUserInfoWidget ui;
};
