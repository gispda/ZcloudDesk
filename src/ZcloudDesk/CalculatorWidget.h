#pragma once

#include <QWidget>
#include "ui_CalculatorWidget.h"
#include "CommWidget.h"
#include "WebView.h"
#include "AppCommWidget.h"
class CalculatorWidget : public AppCommWidget
{
	Q_OBJECT

public:
	CalculatorWidget(QString strName,QString strUrl,QWidget *parent = Q_NULLPTR);
	~CalculatorWidget();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	Ui::CalculatorWidget ui;
	WebView*	m_pWebView = NULL;
	QPoint		dPos;
};
