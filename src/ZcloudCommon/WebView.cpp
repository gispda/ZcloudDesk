#include "WebView.h"
#include <QNetworkReply>
#include "ZcloudCommon.h"
#include <QHostInfo>
#include <QJsonParseError>
#include <QJsonObject>
#include <QProcess>
#include <QNetworkRequest>
#include <QNetworkProxyFactory>
WebView::WebView(QWidget *parent)
	: QWebView(parent)
{
	this->setContextMenuPolicy(Qt::NoContextMenu);
	this->page()->networkAccessManager()->proxyFactory()->setUseSystemConfiguration(true);
	//this->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
	connect(page()->networkAccessManager(),
		SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> &)),
		this,
		SLOT(handleSslErrors(QNetworkReply*, const QList<QSslError> &)));
}

WebView::~WebView()
{
}

void WebView::handleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors)
{
	qDebug() << "zcd-0x0000003C:" << "handleSslErrors: ";
	foreach(QSslError e, errors)
	{
		qDebug() << "zcd-0x0000003D:" << "ssl error: " << e;
	}

	reply->ignoreSslErrors();
}
