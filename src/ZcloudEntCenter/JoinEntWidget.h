#pragma once

#include <QWidget>
#include "ui_JoinEntWidget.h"
#include "ZcloudCommonWidget.h"

class JoinEntWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	JoinEntWidget(QString strUid,QString strToken,QWidget *parent = Q_NULLPTR);
	~JoinEntWidget();

private slots:
	//!������ť���
	void onSearchBtnClick();

	//!������ҵ
	void onJoinEnt(QString strComId);

	//!ȡ��������ҵ���
	void onCancelReview(QString strComId);
private:
	//!������ҵ
	bool winHttpSearchCompany(QString strUid, QString strToken, QString strKeyWord, QString& strRet);
	
	//!������ҵ
	bool winHttpJoinEnt(QString strUid, QString strToken, QString strComId, QString& strRet);

	//!ȡ��������ҵ
	bool winHttpCancelJoinEnt(QString strUid, QString strToken, QString strComId, QString& strRet);
	Ui::JoinEntWidget ui;
	QString			m_strUid;
	QString			m_strToken;
};
