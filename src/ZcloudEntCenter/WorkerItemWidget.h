#pragma once

#include <QWidget>
#include "ui_WorkerItemWidget.h"
#include "WorkerDataBase.h"

class WorkerItemWidget : public QWidget
{
	Q_OBJECT

public:
	WorkerItemWidget(WorkerInfo _info, QString strAction2, QWidget *parent = Q_NULLPTR);
	~WorkerItemWidget();

signals:
	//!œÍ«È
	void sigDetial(QString strworkerid);
	//£°∆¿º€
	void sigEvaluate(WorkerInfo _sinfo);

private slots:
void test(QString);

private:

	Ui::WorkerItemWidget ui;
	//QMenu	*m_pMenu;
	//QAction *m_pActionRemoveOrderList;
	//QAction *m_pActionModifyOrderList;
	//QAction *m_pActionHandOver;
	//QString m_strUid;
	//QString m_strTrueName;
	//QString	m_strJob;

	WorkerInfo m_info;


	QString m_strOrderCode;
	QString m_strOrderName;
	QString m_strOrderState;
	QString m_strCreateTime;
	QString m_strAction2;
};
