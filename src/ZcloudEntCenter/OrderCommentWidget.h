#pragma once

#include <QWidget>
#include "ui_OrderCommentWidget.h"
#include "ZcloudCommonWidget.h"

class OrderCommentWidget : public QWidget
{
	Q_OBJECT

public:
	OrderCommentWidget(QString strOrderCode, QWidget *parent = Q_NULLPTR);
	~OrderCommentWidget();

signals:
	//!œÍ«È
	void sigDetial(QString);
	//£°∆¿º€
	void sigEvaluate(QString, QString, QString);
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private:

	Ui::OrderCommentWidget ui;
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
	QPoint dPos;
};
