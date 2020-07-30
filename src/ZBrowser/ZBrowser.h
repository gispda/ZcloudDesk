#pragma once

//#include <QtWidgets/QWidget>
//#include "ui_ZBrowser.h"
//
//class ZBrowser : public QWidget
//{
//	Q_OBJECT
//
//public:
//	ZBrowser(QWidget *parent = Q_NULLPTR);
//
//private:
//	Ui::ZBrowserClass ui;
//};



#include <QWidget>
#include <QNetworkProxy>
#include <QNetworkDiskCache>
#include "ui_ZBrowser.h"
#include "networkaccessmanager.h"

class ZBrowser : public QWidget
{
	Q_OBJECT

public:
	ZBrowser(QString strClassId, QString strAppId, QString url, QString titel, QWidget *parent = Q_NULLPTR);
	~ZBrowser();
	static  NetworkAccessManager *networkAccessManager();
private:
	Ui::ZBrowserClass ui;

	private slots:
	void flushWeb();
	void stopFlushWeb();
	void on_backPushButton_clicked();
	void on_forwardPushButton_clicked();
	void on_maxPushButton_clicked();
	void on_miniPushButton_clicked();
	void on_closePushButton_clicked();

	void handleWebViewLoadProgress(int progress);
	void handleWebActionEnabledChanged(QWebPage::WebAction action, bool enabled);
	void downloadRequested(QNetworkReply *);
private:
	static NetworkAccessManager *s_networkAccessManager;
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;
	QString m_strClassId;
	QString m_strAppId;
protected:
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
};

