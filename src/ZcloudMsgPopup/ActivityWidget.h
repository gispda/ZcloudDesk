#pragma once

#include <QWidget>
#include "ui_ActivityWidget.h"
#include "NamePipeClinet.h"

class ActivityWidget : public QWidget
{
	Q_OBJECT

public:
	ActivityWidget(QString strUid,QString strToken,QString strCompId,QString strAvId,QString strTitle,QWidget *parent = Q_NULLPTR);
	~ActivityWidget();
private slots:
	void onActivittyBtnClick();
private:
	Ui::ActivityWidget ui;
	QString m_strUid;
	QString m_strToken;
	QString m_strCompId;	
	QString m_strAvId;
	//! ˝æ›…Ë÷√
	NamePipeClinet*	m_pClient = NULL;
};
