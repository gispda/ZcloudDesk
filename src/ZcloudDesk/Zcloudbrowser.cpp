#include "Zcloudbrowser.h"
#include <QDesktopWidget>
#include <QApplication>
Zcloudbrowser::Zcloudbrowser(QString strName, QString strUrl, QWidget *parent)
	: AppCommWidget("", true, parent)
{
	ui.setupUi(m_widget);
	//resize(1156, 776);
	setObjectName("Zcloudbrowser");
	setWindowTitle(strName);
	//ui.label->setText(strName);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setAttribute(Qt::WA_DeleteOnClose);
	setStyleSheet("outline: none");

	//connect(ui.closeButton, &QPushButton::clicked, [this]()
	//{
	//	close();
	//});
	//m_pWebView = new WebView(ui.FilletWidget);
	m_pWebView = new QWebEngineView();
	m_pWebView->setContextMenuPolicy(Qt::NoContextMenu);
	//m_pWebView->setGeometry(0, 50, 1140, 710);
	m_pWebView->setUrl(QUrl(strUrl));

	//m_pWebView->load(QUrl::fromUserInput(strUrl));
	m_pWebView->show();
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
}

Zcloudbrowser::~Zcloudbrowser()
{
}

void Zcloudbrowser::mousePressEvent(QMouseEvent *event)
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

void Zcloudbrowser::mouseMoveEvent(QMouseEvent *event)
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
