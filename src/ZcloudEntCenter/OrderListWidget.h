#pragma once

#include <QWidget>
#include "ui_OrderListWidget.h"
#include "ZcloudCommonWidget.h"

class OrderListWidget : public QWidget
{
	Q_OBJECT

public:
	OrderListWidget(QString strUid, QString strToken,QWidget *parent = Q_NULLPTR);
	~OrderListWidget();

signals:
	void sigEditMemberSucessed(const QString&, const QString&);


protected:
	bool eventFilter(QObject *target, QEvent *e);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:
	void orderDetial(QString);
	void orderComment(QString);
	
private:
	//!显示工单
	bool showOrderList();
	void onFreshOrderList();

private:
	//!获取工单
	bool winHttpGetOrderList(QString strUid, QString strToken, QString& strRet);


	Ui::OrderListWidget ui;
	QString m_strUid;
	QString	m_strToken;
	QPoint dPos;
};
