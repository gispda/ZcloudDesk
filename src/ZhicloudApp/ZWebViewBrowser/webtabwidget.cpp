#include "webtabwidget.h"
#include <QClipboard>
#include <QMessageBox>

TabBar::TabBar(QWidget *parent)
    : QTabBar(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    setAcceptDrops(true);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(contextMenuRequested(QPoint)));

    QString ctrl = QLatin1String("Ctrl+%1");
    for (int i = 1; i <= 10; ++i) {
        int key = i;
        if (key == 10)
            key = 0;
        QShortcut *shortCut = new QShortcut(ctrl.arg(key), this);
        m_tabShortcuts.append(shortCut);
        connect(shortCut, SIGNAL(activated()), this, SLOT(selectTabAction()));
    }
    setTabsClosable(true);
    connect(this, SIGNAL(tabCloseRequested(int)),
            this, SIGNAL(closeTab(int)));
    setSelectionBehaviorOnRemove(QTabBar::SelectPreviousTab);
    setMovable(true);
}

void TabBar::selectTabAction()
{
    if (QShortcut *shortCut = qobject_cast<QShortcut*>(sender())) {
        int index = m_tabShortcuts.indexOf(shortCut);
        if (index == 0)
            index = 10;
        setCurrentIndex(index);
    }
}

void TabBar::contextMenuRequested(const QPoint &position)
{
    QMenu menu;
    menu.addAction(tr("New &Tab"), this, SIGNAL(newTab()), QKeySequence::AddTab);
    int index = tabAt(position);
    if (-1 != index) {
        QAction *action = menu.addAction(tr("Clone Tab"),
                this, SLOT(cloneTab()));
        action->setData(index);

        menu.addSeparator();

        action = menu.addAction(tr("&Close Tab"),
                this, SLOT(closeTab()), QKeySequence::Close);
        action->setData(index);

        action = menu.addAction(tr("Close &Other Tabs"),
                this, SLOT(closeOtherTabs()));
        action->setData(index);

        menu.addSeparator();

        action = menu.addAction(tr("Reload Tab"),
                this, SLOT(reloadTab()), QKeySequence::Refresh);
        action->setData(index);
    } else {
        menu.addSeparator();
    }
    menu.addAction(tr("Reload All Tabs"), this, SIGNAL(reloadAllTabs()));
    menu.exec(QCursor::pos());
}

void TabBar::cloneTab()
{
    if (QAction *action = qobject_cast<QAction*>(sender())) {
        int index = action->data().toInt();
        emit cloneTab(index);
    }
}

void TabBar::closeTab()
{
    if (QAction *action = qobject_cast<QAction*>(sender())) {
        int index = action->data().toInt();
        emit closeTab(index);
    }
}

void TabBar::closeOtherTabs()
{
    if (QAction *action = qobject_cast<QAction*>(sender())) {
        int index = action->data().toInt();
        emit closeOtherTabs(index);
    }
}

void TabBar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        m_dragStartPos = event->pos();
    QTabBar::mousePressEvent(event);
}

void TabBar::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton) {
        int diffX = event->pos().x() - m_dragStartPos.x();
        int diffY = event->pos().y() - m_dragStartPos.y();
        if ((event->pos() - m_dragStartPos).manhattanLength() > QApplication::startDragDistance()
            && diffX < 3 && diffX > -3
            && diffY < -10) {
            QDrag *drag = new QDrag(this);
            QMimeData *mimeData = new QMimeData;
            QList<QUrl> urls;
            int index = tabAt(event->pos());
            QUrl url = tabData(index).toUrl();
            urls.append(url);
            mimeData->setUrls(urls);
            mimeData->setText(tabText(index));
            mimeData->setData(QLatin1String("action"), "tab-reordering");
            drag->setMimeData(mimeData);
            drag->exec();
        }
    }
    QTabBar::mouseMoveEvent(event);
}

//// When index is -1 index chooses the current tab
//void TabWidget::reloadTab(int index)
//{
//    if (index < 0)
//        index = currentIndex();
//    if (index < 0 || index >= count())
//        return;

//    QWidget *widget = this->widget(index);
//    if (WebView *tab = qobject_cast<WebView*>(widget))
//        tab->reload();
//}

void TabBar::reloadTab()
{
    if (QAction *action = qobject_cast<QAction*>(sender())) {
        int index = action->data().toInt();
        emit reloadTab(index);
    }
}





WebActionMapper::WebActionMapper(QAction *root, QWebPage::WebAction webAction, QObject *parent)
    : QObject(parent)
    , m_currentParent(0)
    , m_root(root)
    , m_webAction(webAction)
{
    if (!m_root)
        return;
    connect(m_root, SIGNAL(triggered()), this, SLOT(rootTriggered()));
    connect(root, SIGNAL(destroyed(QObject*)), this, SLOT(rootDestroyed()));
    root->setEnabled(false);
}

void WebActionMapper::rootDestroyed()
{
    m_root = 0;
}

void WebActionMapper::currentDestroyed()
{
    updateCurrent(0);
}

void WebActionMapper::addChild(QAction *action)
{
    if (!action)
        return;
    connect(action, SIGNAL(changed()), this, SLOT(childChanged()));
}

QWebPage::WebAction WebActionMapper::webAction() const
{
    return m_webAction;
}

void WebActionMapper::rootTriggered()
{
    if (m_currentParent) {
        QAction *gotoAction = m_currentParent->action(m_webAction);
        gotoAction->trigger();
    }
}

void WebActionMapper::childChanged()
{
    if (QAction *source = qobject_cast<QAction*>(sender())) {
        if (m_root
            && m_currentParent
            && source->parent() == m_currentParent) {
            m_root->setChecked(source->isChecked());
            m_root->setEnabled(source->isEnabled());
        }
    }
}

void WebActionMapper::updateCurrent(QWebPage *currentParent)
{
    if (m_currentParent)
        disconnect(m_currentParent, SIGNAL(destroyed(QObject*)),
                   this, SLOT(currentDestroyed()));

    m_currentParent = currentParent;
    if (!m_root)
        return;
    if (!m_currentParent) {
        m_root->setEnabled(false);
        m_root->setChecked(false);
        return;
    }
    QAction *source = m_currentParent->action(m_webAction);
    m_root->setChecked(source->isChecked());
    m_root->setEnabled(source->isEnabled());
    connect(m_currentParent, SIGNAL(destroyed(QObject*)),
            this, SLOT(currentDestroyed()));
}

















WebTabWidget::WebTabWidget(QWidget *parent)
	: QTabWidget(parent)
    , m_thisWebView(nullptr)
{
    QTabBar *tabBar = this->tabBar();
    tabBar->setTabsClosable(true);
    tabBar->setSelectionBehaviorOnRemove(QTabBar::SelectPreviousTab);
    tabBar->setMovable(true);
    tabBar->setContextMenuPolicy(Qt::CustomContextMenu);
	
    connect(tabBar, &QTabBar::tabCloseRequested, this, &WebTabWidget::closeTab);
    connect(this, &QTabWidget::currentChanged, this, &WebTabWidget::handleCurrentChanged);
    setDocumentMode(true);
    newTab();
}

WebTabWidget::~WebTabWidget()
{
}

void WebTabWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (!childAt(event->pos())
            // Remove the line below when QTabWidget does not have a one pixel frame
            && event->pos().y() < (tabBar()->y() + tabBar()->height())) {
        newTab();
        return;
    }
    QTabWidget::mouseDoubleClickEvent(event);
}

void WebTabWidget::contextMenuEvent(QContextMenuEvent *event)
{
    if (!childAt(event->pos())) {
        //this->tabBar()->contextMenuRequested(event->pos());
        return;
    }
    QTabWidget::contextMenuEvent(event);
}

void WebTabWidget::mouseReleaseEvent(QMouseEvent *event)
{
#ifndef QT_NO_CLIPBOARD
    if (event->button() == Qt::MidButton && !childAt(event->pos())
            // Remove the line below when QTabWidget does not have a one pixel frame
            && event->pos().y() < (tabBar()->y() + tabBar()->height())) {
        QUrl url(QApplication::clipboard()->text(QClipboard::Selection));
        if (!url.isEmpty() && url.isValid() && !url.scheme().isEmpty()) {
            ZWebView *webView = newTab();
            webView->setUrl(url);
        }
    }
#endif
}

void WebTabWidget::closeTab(int index)
{
    if (index < 0)
        index = currentIndex();
    if (index < 0 || index >= count())
        return;

    if (ZWebView *view = webView(index)) {
        if (m_thisWebView == view)
            return;

        bool hasFocus = view->hasFocus();
        removeTab(index);
        if (hasFocus && count() > 0)
            currentWebView()->setFocus();
        if (count() == 0)
            newTab();
        //view->page()->triggerAction(QWebPage::RequestClose);
        //connect(view->page(), &QWebPage::windowCloseRequested, this, &QWidget::close);

		disconnect(view);
		view->close();
		view->deleteLater();
        removeTab(index);
        emit tabsChanged();
    }
}

ZWebView *WebTabWidget::newTab(bool makeCurrent)
{
    ZWebView *webView = new ZWebView;
    setupView(webView);
    addTab(webView, QString::fromLocal8Bit("(新标签页)"));
    if (makeCurrent)
        setCurrentWidget(webView);
    return webView;
}

void WebTabWidget::setupView(ZWebView *webView)
{
   // QWebPage *webPage = webView->page();
    connect(webView, &QWebView::titleChanged, [this, webView](const QString &title) {
        int index = indexOf(webView);
        if (index != -1)
            setTabText(index, title);
        if (currentIndex() == index)
            emit titleChanged(title);
    });
    connect(webView, &QWebView::loadProgress, [this, webView](int progress) {
        if (currentIndex() == indexOf(webView))
            emit loadProgress(progress);
    });

	//刷新前jing 后退按鈕
    connect(webView, &ZWebView::webActionEnabledChanged, [this, webView](QWebPage::WebAction action, bool enabled) {
        //if (currentIndex() == indexOf(webView))
            emit webActionEnabledChanged(action, enabled);
    });

    connect(webView, SIGNAL(downloadRequestSignal(QNetworkReply *)),this,SIGNAL(download(QNetworkReply *)));
}

void WebTabWidget::setUrl(const QUrl &url)
{

    if (ZWebView *view = currentWebView()) {
        if (m_thisWebView == nullptr)
            m_thisWebView = view;
        view->loadUrl(url);
        view->setFocus();
    }
}

void WebTabWidget::clostTabAll()
{
    for (int i = count(); i > 0 ; i --)
        closeTab(i);
    if (NULL == m_thisWebView)
    {
        Q_EMIT tabWidgetClose();
        return;
    }
	disconnect(m_thisWebView);
	m_thisWebView->close();
	m_thisWebView->deleteLater();
    removeTab(currentIndex());
    Q_EMIT tabWidgetClose();
//    connect(m_thisWebView->page(), &QWebPage::windowCloseRequested, [this]()
//    {
//        m_thisWebView->deleteLater();
//        qDebug() << "-333-----------";
//        Q_EMIT tabWidgetClose();
//    });
//    m_thisWebView->page()->mainFrame()->evaluateJavaScript("window.close()");
}

ZWebView *WebTabWidget::currentWebView() const
{
    return webView(currentIndex());
}

ZWebView *WebTabWidget::webView(int index) const
{
    return qobject_cast<ZWebView*>(widget(index));
}


void WebTabWidget::handleCurrentChanged(int index)
{
    if (index != -1) {
        ZWebView *view = webView(index);
        if (!view->url().isEmpty())
            view->setFocus();
        emit loadProgress(view->progress());

        emit webActionEnabledChanged(QWebPage::Back, view->isWebActionEnabled(QWebPage::Back));
        emit webActionEnabledChanged(QWebPage::Forward, view->isWebActionEnabled(QWebPage::Forward));
        emit webActionEnabledChanged(QWebPage::Stop, view->isWebActionEnabled(QWebPage::Stop));
        emit webActionEnabledChanged(QWebPage::Reload, view->isWebActionEnabled(QWebPage::Reload));
    }
    else {
        emit loadProgress(0);
        emit webActionEnabledChanged(QWebPage::Back, false);
        emit webActionEnabledChanged(QWebPage::Forward, false);
        emit webActionEnabledChanged(QWebPage::Stop, false);
        emit webActionEnabledChanged(QWebPage::Reload, true);
    }
}

//设置 前进后退
void WebTabWidget::triggerWebPageAction(QWebPage::WebAction action)
{
    if (ZWebView *webView = currentWebView()) {
        webView->triggerPageAction(action);
        webView->setFocus();
    }
}
