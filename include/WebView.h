#pragma once
#ifdef ZCLOUDCOMMON_LIB
# define WEBVIEW_EXPORT Q_DECL_EXPORT
#else
# define WEBVIEW_EXPORT Q_DECL_IMPORT
#endif

#include <QtWebKitWidgets/QWebView>

#include "qevent.h"

class WEBVIEW_EXPORT WebView : public QWebView
{
	Q_OBJECT


public:
	WebView(QWidget *parent = Q_NULLPTR);
	~WebView();

private slots:
	void handleSslErrors(QNetworkReply*, const QList<QSslError> &);
};
