#pragma once

#include "zwebview.h"
#include <QtWidgets/QTabBar>

#include <QtWidgets/QShortcut>
#include <QMenu>
#include <QDrag>
#include <QMimeData>
#include <QTabWidget>
#include <QPushButton>

class TabBar : public QTabBar
{
	Q_OBJECT
public:
	TabBar(QWidget *parent);
	~TabBar();
signals:
private:
protected:
	QSize tabSizeHint(int index) const;
	
};



class WebTabWidget : public QTabWidget
{
	Q_OBJECT
private:
	TabBar *m_tabBar;
signals :
	// tab widget signals
	void loadPage(const QString &url);
	void tabsChanged();
	void lastTabClosed();

	// current tab signals
	void setCurrentTitle(const QString &url);
	void showStatusBarMessage(const QString &message);
	void linkHovered(const QString &link);

	void geometryChangeRequested(const QRect &geometry);
	void menuBarVisibilityChangeRequested(bool visible);
	void statusBarVisibilityChangeRequested(bool visible);
	void toolBarVisibilityChangeRequested(bool visible);
	void printRequested(QWebFrame *frame);
	void download(QNetworkReply *);


public:
	WebTabWidget(QWidget *parent = nullptr);
	~WebTabWidget();

	void triggerWebPageAction(QWebPage::WebAction action);
public slots:
	ZWebView *newTab(bool makeCurrent = true);
	void setUrl(const QUrl & url);
protected:
	void mouseDoubleClickEvent(QMouseEvent *event);
	void contextMenuEvent(QContextMenuEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
private:


	ZWebView * webView(int index) const;
	ZWebView * currentWebView() const;
	public slots:
	void closeTab(int index);
	void clostTabAll();

signals:
	void loadProgress(int progress);
	void webActionEnabledChanged(QWebPage::WebAction action, bool enabled);
	//void downloadRequestSignal(QWebDownloadItem*);
	void tabWidgetClose();
	void titleChanged(const QString &title);
private:
	void setupView(ZWebView * webView);


	QPushButton *m_mainButton;
private slots:
	void handleCurrentChanged(int index);
	void choosMainTab();
	
};
