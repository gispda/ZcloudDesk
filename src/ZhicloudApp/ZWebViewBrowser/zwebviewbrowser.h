#ifndef ZWEBVIEWBROWSER_H
#define ZWEBVIEWBROWSER_H

#include <QWidget>
#include <QProgressBar>
#include <QNetworkProxy>
#include <QNetworkDiskCache>
#include "webtabwidget.h"
#include "zwebdowloadmanager.h"
#include "networkaccessmanager.h"
#include <QThread>
namespace Ui {
class ZWebViewBrowser;
}

class ZWebViewBrowser : public QWidget
{
    Q_OBJECT

public:
	explicit ZWebViewBrowser(QString classId, QString appId,bool bShow=true, QWidget *parent = 0);
    ~ZWebViewBrowser();


	static  NetworkAccessManager *networkAccessManager();
    void load(QString url, QString name = "");
    WebTabWidget *tabWidget();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
private slots:
    void on_flushPushButton_clicked();
    void on_backPushButton_clicked();
    void on_forwardPushButton_clicked();
    void on_maxPushButton_clicked();
    void on_miniPushButton_clicked();
    void onClose();
    void handleWebViewLoadProgress(int progress);
    void handleWebActionEnabledChanged(QWebPage::WebAction action, bool enabled);
    void downloadRequested(QNetworkReply *);
private:
    Ui::ZWebViewBrowser *ui;
    WebTabWidget *m_tabWidget;
    QProgressBar *m_progressBar;
    ZWebDowloadManager *m_webDowloadManager;
    static NetworkAccessManager *s_networkAccessManager;
private:
    QString m_titleName;
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
    QPixmap m_bg;

	QString m_classId;
	QString m_appId;

};

#endif // ZWEBVIEWBROWSER_H
