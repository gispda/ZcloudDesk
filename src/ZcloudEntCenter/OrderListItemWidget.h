#pragma once

#include <QWidget>
#include "ui_OrderListItemWidget.h"

class OrderListItemWidget : public QWidget
{
	Q_OBJECT

public:
	OrderListItemWidget(QString strOrderCode, QString strOrderName, QString strOrderState, QString strCreateTime, QString strAction2, QWidget *parent = Q_NULLPTR);
	~OrderListItemWidget();

signals:
	//!œÍ«È
	void sigDetial(QString);
	//£°∆¿º€
	void sigEvaluate(QString);

private slots:
void test(QString);

private:

	Ui::OrderListItemWidget ui;
	//QMenu	*m_pMenu;
	//QAction *m_pActionRemoveOrderList;
	//QAction *m_pActionModifyOrderList;
	//QAction *m_pActionHandOver;
	//QString m_strUid;
	//QString m_strTrueName;
	//QString	m_strJob;

	QString m_strOrderCode;
	QString m_strOrderName;
	QString m_strOrderState;
	QString m_strCreateTime;
	QString m_strAction2;
};
