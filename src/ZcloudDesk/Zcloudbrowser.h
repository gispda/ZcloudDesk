#pragma once

#include <QWidget>
#include "ui_Zcloudbrowser.h"
#include "CommWidget.h"
#include "WebView.h"
#include "AppCommWidget.h"

#include <QtWebEngineWidgets>
#include "QWebEngineView"

class Zcloudbrowser: public AppCommWidget
{
	Q_OBJECT

public:
	Zcloudbrowser(QString strName, QString strUrl, QWidget *parent = Q_NULLPTR);
	~Zcloudbrowser();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	Ui::Zcloudbrower ui;
	//WebView*	m_pWebView = NULL;
	QWebEngineView* m_pWebView = NULL;

	QPoint		dPos;
};
