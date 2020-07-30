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
	//!搜索按钮点击
	void onSearchBtnClick();

	//!加入企业
	void onJoinEnt(QString strComId);

	//!取消加入企业审核
	void onCancelReview(QString strComId);
private:
	//!搜索企业
	bool winHttpSearchCompany(QString strUid, QString strToken, QString strKeyWord, QString& strRet);
	
	//!加入企业
	bool winHttpJoinEnt(QString strUid, QString strToken, QString strComId, QString& strRet);

	//!取消加入企业
	bool winHttpCancelJoinEnt(QString strUid, QString strToken, QString strComId, QString& strRet);
	Ui::JoinEntWidget ui;
	QString			m_strUid;
	QString			m_strToken;
};
