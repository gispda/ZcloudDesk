#include "WebTabWidget.h"
#include <QClipboard>

TabBar::TabBar(QWidget *parent)
	:QTabBar(parent)
{
	this->setTabsClosable(true);
	this->setStyleSheet(QString::fromLocal8Bit("QTabBar{background:rgba(235,235,235,1); left: 60px;}\
						QTabBar::tab:first{border-image: url(:/Image/tabBar_home1.png);width:0px;height:40px;margin: 0px; }\
						QTabBar::tab:selected:first{border-image: url(:/Image/tabBar_home2.png);margin: 0px; }\
						QTabBar::tab:!first{margin: 1px;background-color: #DEDEDE; font: 14px \"微软雅黑\";color: #666666;}\
						QTabBar::tab:selected:!first{color: #FFFFFF; background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));}\
						QTabBar::tab:only-one { width:0px;height:40px;border-image: url(:/Image/tabBar_home2.png); margin: 0;}\
						QTabBar::close-button {image:null;}\
						QTabBar::close-button:hover {  image:url(:/Image/tabBar_close_nor.png)}\
						QTabBar::close-button:selected {image: url(:/Image/tabBar_close_nor1.png)}\
						QTabBar::close-button:selected:hover {  image: url(:/Image/tabBar_close_hov.png)}"));
	setSelectionBehaviorOnRemove(QTabBar::SelectPreviousTab);
	setMovable(false);
}


QSize TabBar::tabSizeHint(int index) const
{
	if (index == 0)
		return QSize(0, 40);
	int size = this->width();
	if (size < 1120) size = 1120;
	size =  (size - 60) / (count() - 1);
	if (size < 100) size = 100;
	if (size > 200) size = 200;
	return QSize(size , 40);
}

TabBar::~TabBar()
{

}


WebTabWidget::WebTabWidget(QWidget *parent)
	: QTabWidget(parent)
	, m_mainButton(new QPushButton(this))
	, m_tabBar(new TabBar(this))
{
	setTabBar(m_tabBar);
	m_mainButton->setGeometry(0, 0, 60, 40);
	m_mainButton->setStyleSheet("QPushButton{border-image: url(:/Image/tabBar_home2.png);margin: 0px; }");
	connect(m_mainButton, &QPushButton::clicked, this, &WebTabWidget::choosMainTab);
	connect(m_tabBar, &QTabBar::tabCloseRequested, this, &WebTabWidget::closeTab);
	connect(this, &QTabWidget::currentChanged, this, &WebTabWidget::handleCurrentChanged);
	//setDocumentMode(true);
	newTab();
}

WebTabWidget::~WebTabWidget()
{
}
void WebTabWidget::choosMainTab()
{
	if (m_tabBar->currentIndex() != 0)
	{
		setCurrentIndex(0);
	}
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

		bool hasFocus = view->hasFocus();
		view->triggerPageAction(QWebPage::WebAction(QWebPage::Stop));
		removeTab(index);
		if (hasFocus && count() > 0)
			currentWebView()->setFocus();
		if (count() == 0)
			newTab();
		//view->page()->triggerAction(QWebPage::RequestClose);
		//connect(view->page(), &QWebPage::windowCloseRequested, this, &QWidget::close);

		disconnect(view);
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
		if (index != -1 && index != 0)
		{
			QString streElide = title;

			QFontMetrics fontMetrics(QFont("font: 14px;color: #666666;"));
			int width = fontMetrics.width(streElide);  //计算字符串宽度
			if (width >= 350)  //当字符串宽度大于最大宽度时进行转换
			{
				streElide = fontMetrics.elidedText(streElide, Qt::ElideRight, 350);  //右部显示省略号
			}
			setTabText(index, streElide);
		}
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

	connect(webView, SIGNAL(downloadRequestSignal(QNetworkReply *)), this, SIGNAL(download(QNetworkReply *)));
}

void WebTabWidget::setUrl(const QUrl &url)
{
	if (ZWebView *view = currentWebView()) {
		view->loadUrl(url);
		view->setFocus();
	}
}

void WebTabWidget::clostTabAll()
{
	for (int i = count(); i > 0; i--)
		closeTab(i);
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

	if (index == 0)
	{
		m_mainButton->setStyleSheet("QPushButton{border-image: url(:/Image/tabBar_home2.png);width:60px;height:40px;margin: 0px; }");
	}
	else if (index > 0)
	{
		m_mainButton->setStyleSheet("QPushButton{border-image: url(:/Image/tabBar_home1.png);width:60px;height:40px;margin: 0px; }");
	}


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