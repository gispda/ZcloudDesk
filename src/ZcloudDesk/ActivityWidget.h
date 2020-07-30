#ifndef ACTIVITYWIDGET_H
#define ACTIVITYWIDGET_H

#include <QWidget>
#include "ui_ActivityWidget.h"
#include "qevent.h"
#include "CommWidget.h"
#include "WebView.h"
#include "AppCommWidget.h"
class ActivityWidget : public AppCommWidget
{
	Q_OBJECT

public:
	ActivityWidget(QString strUrl,QWidget *parent = 0);
	~ActivityWidget();
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private slots:
	void onLinkClicked(const QUrl&);
	void onLoadFinished(bool);
private:
	Ui::ActivityWidget ui;
	WebView*	m_pWebView = NULL;
	QPoint dPos;
	QString    m_strUrl;
};

#endif // ACTIVITYWIDGET_H
