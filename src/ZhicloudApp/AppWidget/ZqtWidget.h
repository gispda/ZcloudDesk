#ifndef ZQTWIDGET_H
#define ZQTWIDGET_H

#include <QWidget>
#include "ui_ZqtWidget.h"
#include "AppWidgets/AppCommWidget.h"
#include <QtWebKitWidgets/QWebView>

class ZqtWidget : public AppCommWidget
{
	Q_OBJECT

public:
	ZqtWidget(QString strId,QString strTitle, QString strComName, QString strUrl, QWidget *parent = 0);
	~ZqtWidget();
	
private slots:
	void onLinkClick(const QUrl&);
	void unsupportedContent(QNetworkReply*);

private:
	QWebView*	m_pWebView;
	QString m_strAppid;
	Ui::ZqtWidget ui;
	
};

#endif // ZQTWIDGET_H
