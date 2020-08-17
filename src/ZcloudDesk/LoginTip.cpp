#include "LoginTip.h"
#include <QDesktopWidget>
#include "ZcloudCommon.h"
#include <QDesktopServices>
#include "JsInterface.h"
#include <QWebFrame>
LoginTip::LoginTip(QWidget *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	resize(370, 386);
	setObjectName("ZcloudLoginTip");
	setWindowTitle(QString::fromLocal8Bit("»î¶¯"));
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground, false);
	//setAttribute(Qt::WA_DeleteOnClose);
	setStyleSheet("outline: none");
	
	connect(ui.closeButton, &QPushButton::clicked, [this]()
	{
		close();
	});

	m_pWebView = new WebView();
	m_pWebView->setContextMenuPolicy(Qt::NoContextMenu);
	m_pWebView->setGeometry(0, 50, 740, 690);
//	m_pWebView->load(QUrl::fromUserInput(strUrl));
	connect(m_pWebView, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished(bool)));
	connect(m_pWebView, SIGNAL(linkClicked(const QUrl &)), this, SLOT(onLinkClicked(const QUrl&)));


	connect(ui.okButton, SIGNAL(clicked()), this, SLOT(accept()));
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
}

LoginTip::~LoginTip()
{
}

void LoginTip::mousePressEvent(QMouseEvent *event)
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

void LoginTip::mouseMoveEvent(QMouseEvent *event)
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

void LoginTip::onLinkClicked(const QUrl& url)
{
	QDesktopServices::openUrl(url);
}

void LoginTip::onLoadFinished(bool)
{
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("JsInterface", (QObject*)JsInterface::GetInstance());
}
