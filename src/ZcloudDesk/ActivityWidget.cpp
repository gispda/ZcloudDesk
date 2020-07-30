#include "ActivityWidget.h"
#include <QDesktopWidget>
#include "ZcloudCommon.h"
#include <QDesktopServices>
#include "JsInterface.h"
#include <QWebFrame>
ActivityWidget::ActivityWidget(QString strUrl, QWidget *parent)
	:AppCommWidget("", true, parent)
	, m_strUrl(strUrl)
{
	ui.setupUi(m_widget);
	resize(756, 766);
	setObjectName("ActivityWidget");
	setWindowTitle(QString::fromLocal8Bit("»î¶¯"));
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setAttribute(Qt::WA_DeleteOnClose);
	setStyleSheet("outline: none");
	
	connect(ui.closeButton, &QPushButton::clicked, [this]()
	{
		close();
	});

	m_pWebView = new WebView(ui.FilletWidget);
	m_pWebView->setContextMenuPolicy(Qt::NoContextMenu);
	m_pWebView->setGeometry(0, 50, 740, 690);
	m_pWebView->load(QUrl::fromUserInput(strUrl));
	connect(m_pWebView, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished(bool)));
	connect(m_pWebView, SIGNAL(linkClicked(const QUrl &)), this, SLOT(onLinkClicked(const QUrl&)));
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
}

ActivityWidget::~ActivityWidget()
{
}

void ActivityWidget::mousePressEvent(QMouseEvent *event)
{
	if (!isMaximized())
	{
		if (event->button() == Qt::LeftButton)
		{
			dPos = event->globalPos() - pos();
			event->accept();
		}
	}
}

void ActivityWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (!isMaximized())
	{
		if (event->buttons()&Qt::LeftButton)
		{
			move(event->globalPos() - dPos);
			event->accept();
		}
	}
}

void ActivityWidget::onLinkClicked(const QUrl& url)
{
	QDesktopServices::openUrl(url);
}

void ActivityWidget::onLoadFinished(bool)
{
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("JsInterface", (QObject*)JsInterface::GetInstance());
}
