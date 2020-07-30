#pragma once

#include <QWidget>
#include "ui_ModifyMemberWidget.h"
#include "ZcloudCommonWidget.h"

class ModifyMemberWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	ModifyMemberWidget(QString strTrueName,QString strJob,QString strUid,QString strToken,QString strUserId,QWidget *parent = Q_NULLPTR);
	~ModifyMemberWidget();

signals:
	void sigModifyMember(QString,QString,QString);
private slots :
	void onModifyOkBtnClick();
	void onNameEditingFinished();
	void onJobEditingFinished();
private:
	//!更新财务成员信息
	bool winHttpModifyMemberInfo(QString strUid, QString strToken, QString strTrueName, QString strJob,QString strUserId, QString& strRet);

	Ui::ModifyMemberWidget ui;
	QString m_strUid;
	QString m_strToken;
	QString m_strUserId;
	bool m_bName = false;
	bool m_bJob = true;
};
