#pragma once

#include <QWidget>
#include "ui_TwobarCodeWidget.h"
#include "ZcloudCommonWidget.h"

class TwobarCodeWidget : public QWidget
{
	Q_OBJECT

public:
	TwobarCodeWidget(QString code, QString str, QWidget *parent = Q_NULLPTR);
	~TwobarCodeWidget();

signals:
	//!œÍ«È
	void sigDetial(QString);
	//£°∆¿º€
	void sigEvaluate(QString, QString, QString);

protected:

	void setGrade(int);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	QPixmap TwobarCodeWidget::generateQRcode(QString tempstr);
private:

	Ui::TwobarCodeWidget ui;


	QString m_code;
	QString m_str;

	QPoint dPos;
};
