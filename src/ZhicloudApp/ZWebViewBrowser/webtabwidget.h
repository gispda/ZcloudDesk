#ifndef WEBTABWIDGET_H
#define WEBTABWIDGET_H
#include "ZWebViewBrowser/zwebview.h"
#include <QtWidgets/QTabBar>

#include <QtWidgets/QShortcut>
#include <QMenu>
#include <QDrag>
#include <QMimeData>
/*
    Tab bar with a few more features such as a context menu and shortcuts
 */
class TabBar : public QTabBar
{
    Q_OBJECT

signals:
    void newTab();
    void cloneTab(int index);
    void closeTab(int index);
    void closeOtherTabs(int index);
    void reloadTab(int index);
    void reloadAllTabs();
    void tabMoveRequested(int fromIndex, int toIndex);

public:
    TabBar(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

private slots:
    void selectTabAction();
    void cloneTab();
    void closeTab();
    void closeOtherTabs();
    void reloadTab();
    void contextMenuRequested(const QPoint &position);

private:
    QList<QShortcut*> m_tabShortcuts;
    friend class TabWidget;

    QPoint m_dragStartPos;
    int m_dragCurrentIndex;
};

#include <QtWebKitWidgets\QWebPage>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE
class WebView;
/*!
    A proxy object that connects a single browser action
    to one child webpage action at a time.

    Example usage: used to keep the main window stop action in sync with
    the current tabs webview's stop action.
 */
class WebActionMapper : public QObject
{
    Q_OBJECT

public:
    WebActionMapper(QAction *root, QWebPage::WebAction webAction, QObject *parent);
    QWebPage::WebAction webAction() const;
    void addChild(QAction *action);
    void updateCurrent(QWebPage *currentParent);

private slots:
    void rootTriggered();
    void childChanged();
    void rootDestroyed();
    void currentDestroyed();

private:
    QWebPage *m_currentParent;
    QAction *m_root;
    QWebPage::WebAction m_webAction;
};


#include <QtCore/QUrl>
#include <QtWidgets/QTabWidget>
QT_BEGIN_NAMESPACE
class QCompleter;
class QLineEdit;
class QMenu;
class QStackedWidget;
QT_END_NAMESPACE
/*!
    TabWidget that contains WebViews and a stack widget of associated line edits.

    Connects up the current tab's signals to this class's signal and uses WebActionMapper
    to proxy the actions.
 */
class WebTabWidget : public QTabWidget
{
	Q_OBJECT
signals:
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
	ZWebView *m_thisWebView;//±£´æ×î³õµÄweb

    void triggerWebPageAction(QWebPage::WebAction action);
public slots:
    ZWebView *newTab(bool makeCurrent  = true);
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
//    //void downloadRequestSignal(QWebDownloadItem*);
    void tabWidgetClose();
    void titleChanged(const QString &title);
private:
    void setupView(ZWebView * webView);

	
    
private slots:
    void handleCurrentChanged(int index);

};



#endif // !WEBTABWIDGET_H
