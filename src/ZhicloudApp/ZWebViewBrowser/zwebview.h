#ifndef ZWEBVIEW_H
#define ZWEBVIEW_H
#include <QtWebKitWidgets/QWebView>
#include <QtWebKitWidgets/QWebPage>
#include <QtWebKitWidgets/QWebFrame>
#include <QMouseEvent>
#include <QApplication>
#include <QWidget>
#include <QDebug>
QT_BEGIN_NAMESPACE
class QAuthenticator;
class QMouseEvent;
class QNetworkProxy;
class QNetworkReply;
class QSslError;
QT_END_NAMESPACE

class ZWebPage : public QWebPage {
    Q_OBJECT
signals:
    void loadingUrl(const QUrl &url);

    void downloadReply(QNetworkReply *reply);
public:
    ZWebPage(QObject *parent = 0);
    ~ZWebPage();


private slots:
    void handleUnsupportedContent(QNetworkReply *reply);

private:
    friend class ZWebView;

    // set the webview mousepressedevent
    Qt::KeyboardModifiers m_keyboardModifiers;
    Qt::MouseButtons m_pressedButtons;
    bool m_openInNewTab;
    QUrl m_loadingUrl;
};


class ZWebView : public QWebView {
    Q_OBJECT
signals:
    void webActionEnabledChanged(QWebPage::WebAction webAction, bool enabled);
    void downloadRequestSignal(QNetworkReply *);
public:
    ZWebView(QWidget *parent = 0);

    void loadUrl(const QUrl &url);
    QString lastStatusBarText() const;
    QUrl url() const;
    inline int progress() const { return m_progress; }
    bool isWebActionEnabled(QWebPage::WebAction webAction) const;
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);
    void wheelEvent(QWheelEvent *event);
    QWebView *createWindow(QWebPage::WebWindowType type);
private slots:
    void setStatusBarText(const QString &string);
    void setProgress(int progress);
    void loadFinished();
    void downloadRequested(QNetworkReply *request);
    void openLinkInNewTab();
	void openLinkSlot(QUrl);
private:
    QString m_statusBarText;
    QUrl m_initialUrl;
    int m_progress;
    ZWebPage *m_page;
    void setPage(ZWebPage *page);
    void createWebActionTrigger(QWebPage *page, QWebPage::WebAction webAction);
};


#endif // ZWEBVIEW_H
