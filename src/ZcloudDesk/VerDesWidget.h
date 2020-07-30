#pragma once

#include <QDialog>
#include "ui_VerDesWidget.h"
#include "qevent.h"
class VerDesWidget : public QDialog
{
	Q_OBJECT

public:
	VerDesWidget(QWidget *parent = Q_NULLPTR);
	~VerDesWidget();
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	Ui::VerDesWidget ui;
	QPoint dPos;
};
