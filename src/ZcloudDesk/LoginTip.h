#ifndef LOGINTIP_H
#define LOGINTIP_H

#include <QWidget>
#include "ui_LoginTip.h"
#include "qevent.h"
#include "CommWidget.h"
#include "WebView.h"
#include "AppCommWidget.h"
class LoginTip : public QDialog
{
	Q_OBJECT

public:
	LoginTip(QWidget *parent = 0);
	~LoginTip();
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private slots:
	void onLinkClicked(const QUrl&);
	void onLoadFinished(bool);
private:
	Ui::ZcloudLoginTip ui;
	WebView*	m_pWebView = NULL;
	QPoint dPos;
	QString    m_strUrl;
};

#endif // LOGINTIP_H
