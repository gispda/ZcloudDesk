#include "zwebview.h"
#include <QAction>
#include <QNetworkReply>
#include <QFile>
#include <QBuffer>
#include <QStyle>
#include <QClipboard>
#include <QMenu>
#include <QtUiTools/QUiLoader>
#include "zwebviewbrowser.h"

ZWebPage::ZWebPage(QObject *parent)
    : QWebPage(parent)
    , m_keyboardModifiers(Qt::NoModifier)
    , m_pressedButtons(Qt::NoButton)
    , m_openInNewTab(false)
{
    setNetworkAccessManager(ZWebViewBrowser::networkAccessManager());
    connect(this, SIGNAL(unsupportedContent(QNetworkReply*)),
            this, SLOT(handleUnsupportedContent(QNetworkReply*)));
    setForwardUnsupportedContent(true);

}

ZWebPage::~ZWebPage()
{
	
}



void ZWebPage::handleUnsupportedContent(QNetworkReply *reply)
{
    QString errorString = reply->errorString();
    if (m_loadingUrl != reply->url()) {
        // sub resource of this page
        qWarning() << "Resource" << reply->url().toEncoded() << "has unknown Content-Type, will be ignored.";
        //reply->deleteLater();
        emit downloadReply(reply);
        return;
    }

    if (reply->error() == QNetworkReply::NoError && !reply->header(QNetworkRequest::ContentTypeHeader).isValid()) {
        errorString = "Unknown Content-Type";
    }

    QFile file(QLatin1String(":/notfound.html"));
    bool isOpened = file.open(QIODevice::ReadOnly);
    Q_ASSERT(isOpened);
    Q_UNUSED(isOpened)

    QString title = tr("Error loading page: %1").arg(reply->url().toString());
    QString html = QString(QLatin1String(file.readAll()))
                        .arg(title)
                        .arg(errorString)
                        .arg(reply->url().toString());

    QBuffer imageBuffer;
    imageBuffer.open(QBuffer::ReadWrite);
    QIcon icon = view()->style()->standardIcon(QStyle::SP_MessageBoxWarning, 0, view());
    QPixmap pixmap = icon.pixmap(QSize(32,32));
    if (pixmap.save(&imageBuffer, "PNG")) {
        html.replace(QLatin1String("IMAGE_BINARY_DATA_HERE"),
                     QString(QLatin1String(imageBuffer.buffer().toBase64())));
    }

    QList<QWebFrame*> frames;
    frames.append(mainFrame());
    while (!frames.isEmpty()) {
        QWebFrame *frame = frames.takeFirst();
        if (frame->url() == reply->url()) {
            frame->setHtml(html, reply->url());
            return;
        }
        QList<QWebFrame *> children = frame->childFrames();
        foreach(QWebFrame *frame, children)
            frames.append(frame);
    }
    if (m_loadingUrl == reply->url()) {
        mainFrame()->setHtml(html, reply->url());
    }
}



ZWebView::ZWebView(QWidget* parent)
    : QWebView(parent)
    ,m_page(new ZWebPage(this))
{
    setPage(m_page);
    connect(page(), SIGNAL(statusBarMessage(QString)),
            SLOT(setStatusBarText(QString)));
    connect(this, SIGNAL(loadProgress(int)),
            this, SLOT(setProgress(int)));
    connect(this, SIGNAL(loadFinished(bool)),
            this, SLOT(loadFinished()));
    connect(page(), SIGNAL(loadingUrl(QUrl)),
            this, SIGNAL(urlChanged(QUrl)));
	connect(page(), SIGNAL(loadingUrl(QUrl)),
		this, SIGNAL(urlChanged(QUrl)));
    //connect(page(), SIGNAL(downloadRequested(QNetworkRequest)),
    //        this, SLOT(downloadRequested(QNetworkRequest)));
    //connect(page(), SIGNAL(unsupportedContent(QNetworkRequest)),
    //        this, SLOT(downloadRequested(QNetworkRequest)));
    connect(m_page, SIGNAL(downloadReply(QNetworkReply *)),
            this, SLOT(downloadRequested(QNetworkReply *)));
	setContextMenuPolicy(Qt::NoContextMenu);
    //page()->setForwardUnsupportedContent(true);
	QNetworkAccessManager* pNetworkManager = m_page->networkAccessManager();
	pNetworkManager = new QNetworkAccessManager;
	QNetworkProxyQuery proxyQuery(QUrl::fromUserInput("https://www.baidu.com"));
	QList<QNetworkProxy> proxyList = QNetworkProxyFactory::systemProxyForQuery(proxyQuery);
	if (proxyList.count() > 0)
	{
		pNetworkManager->setProxy(proxyList.at(0));
	}
	m_page->setNetworkAccessManager(pNetworkManager);
	//将webview设置成使用flash插件,否则无法加载flash,NPSWF32.dll文件放在plugins文件夹中
	//QWebSettings *settings = QWebSettings::globalSettings();
	//settings->setAttribute(QWebSettings::PluginsEnabled, true);//
	//settings->setAttribute(QWebSettings::JavascriptEnabled, true);//JavaScript
	//settings->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);//
	//settings->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
	//将webview中的页面上的插连接全部激活
	//this->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
	//connect(this, SIGNAL(linkClicked(QUrl)), this, SLOT(openLinkSlot(QUrl)));
	//将页面的显示的的横向滚动条禁止
	//this->page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
	
}

void ZWebView::openLinkSlot(QUrl url)
{
	//qDebug() << url.toString();

}

void ZWebView::loadUrl(const QUrl &url)
{
    m_initialUrl = url;
	QString str = url.toString();
    this->load(url);
}

void ZWebView::setPage(ZWebPage *page)
{
    createWebActionTrigger(page, QWebPage::Forward);
    createWebActionTrigger(page, QWebPage::Back);
    createWebActionTrigger(page, QWebPage::Reload);
    createWebActionTrigger(page, QWebPage::Stop);
    QWebView::setPage(page);
}

void ZWebView::createWebActionTrigger(QWebPage *page, QWebPage::WebAction webAction)
{
    QAction *action = page->action(webAction);
    connect(action, &QAction::changed, [this, action, webAction] {
        emit webActionEnabledChanged(webAction, action->isEnabled());
    });
}



void ZWebView::mousePressEvent(QMouseEvent *event)
{
    m_page->m_pressedButtons = event->buttons();
    m_page->m_keyboardModifiers = event->modifiers();
    QWebView::mousePressEvent(event);
}

void ZWebView::mouseReleaseEvent(QMouseEvent *event)
{
    QWebView::mouseReleaseEvent(event);
#ifndef QT_NO_CLIPBOARD
    if (!event->isAccepted() && (m_page->m_pressedButtons & Qt::MidButton)) {
        QUrl url(QApplication::clipboard()->text(QClipboard::Selection));
        if (!url.isEmpty() && url.isValid() && !url.scheme().isEmpty()) {
            setUrl(url);
        }
    }
#endif
}

void ZWebView::contextMenuEvent(QContextMenuEvent *event)
{
    QWebHitTestResult r = page()->mainFrame()->hitTestContent(event->pos());
    if (!r.linkUrl().isEmpty()) {
        QMenu menu(this);
        menu.addAction(pageAction(QWebPage::OpenLinkInNewWindow));
        menu.addAction(tr("Open in New Tab"), this, SLOT(openLinkInNewTab()));
        menu.addSeparator();
        menu.addAction(pageAction(QWebPage::DownloadLinkToDisk));
        // Add link to bookmarks...
        menu.addSeparator();
        menu.addAction(pageAction(QWebPage::CopyLinkToClipboard));
        if (page()->settings()->testAttribute(QWebSettings::DeveloperExtrasEnabled))
            menu.addAction(pageAction(QWebPage::InspectElement));
        menu.exec(mapToGlobal(event->pos()));
        return;
    }
    QWebView::contextMenuEvent(event);
}

void ZWebView::wheelEvent(QWheelEvent *event)
{
    if (QApplication::keyboardModifiers() & Qt::ControlModifier) {
        int numDegrees = event->delta() / 8;
        int numSteps = numDegrees / 15;
        setTextSizeMultiplier(textSizeMultiplier() + numSteps * 0.1);
        event->accept();
        return;
    }
    QWebView::wheelEvent(event);
}

QWebView *ZWebView::createWindow(QWebPage::WebWindowType type)
{
	switch (type) {
	case QWebPage::WebBrowserWindow: {
		QWidget *mainWindow = qobject_cast<QWidget*>(parentWidget());
		if (mainWindow)
		{
			WebTabWidget * webTabWidget = qobject_cast<WebTabWidget*>( mainWindow->parentWidget());
			if (webTabWidget)
			 return webTabWidget->newTab();
		}
	}
	case QWebPage::WebModalDialog: {
	}
    }
    return this;
}


void ZWebView::setStatusBarText(const QString &string)
{
    m_statusBarText = string;
}

void ZWebView::setProgress(int progress)
{
    m_progress = progress;
}

void ZWebView::loadFinished()
{
    if (100 != m_progress) {
        qWarning() << "Received finished signal while progress is still:" << progress()
                   << "Url:" << url();
    }
    m_progress = 0;
}

//有下载的数据
void ZWebView::downloadRequested(QNetworkReply *request)
{
    if(request->url().isEmpty())
    {
        request->deleteLater();
        return;
    }
    emit downloadRequestSignal(request);

    //BrowserApplication::downloadManager()->download(request);
}

void ZWebView::openLinkInNewTab()
{
    m_page->m_openInNewTab = true;
    pageAction(QWebPage::OpenLinkInNewWindow)->trigger();
}

QUrl ZWebView::url() const
{
    QUrl url = QWebView::url();
    if (!url.isEmpty())
        return url;

    return m_initialUrl;
}
QString ZWebView::lastStatusBarText() const
{
    return m_statusBarText;
}

bool ZWebView::isWebActionEnabled(QWebPage::WebAction webAction) const
{
    return page()->action(webAction)->isEnabled();
}
