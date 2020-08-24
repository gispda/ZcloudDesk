#include "MsgFormWidget.h"
#include <QGraphicsDropShadowEffect>
#include "JsInterface.h"
#include <QWebFrame>
#include "ZcloudBigData.h"
MsgFormWidget::MsgFormWidget(QString strUrl,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setAttribute(Qt::WA_DeleteOnClose);
	setAttribute(Qt::WA_ShowModal, true);
	setStyleSheet("outline: none");

	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
	//shadow->setBlurRadius(0.8);				//阴影模糊度
	//设置阴影距离
	shadow->setOffset(0, 0);
	//设置阴影颜色
	shadow->setColor(QColor("#666666"));
	//设置阴影圆角
	shadow->setBlurRadius(8);
	//给嵌套QWidget设置阴影
	this->setGraphicsEffect(shadow);

	m_pWebView = new WebView(ui.FormFilletWidget);
	connect(m_pWebView, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished(bool)));
	m_pWebView->setContextMenuPolicy(Qt::NoContextMenu);
	m_pWebView->setGeometry(9, 29, 371, 401);
	m_pWebView->load(QUrl::fromUserInput(strUrl));

	connect(ui.closeButton, &QPushButton::clicked, [this]()
	{
		emit sigMsgFormClose();
		close();
	});
}

MsgFormWidget::~MsgFormWidget()
{
	if (NULL != m_pWebView)
	{
		m_pWebView->stop();
		m_pWebView->close();
		//m_pWebView->deleteLater();
		m_pWebView = NULL;
	}
}

void MsgFormWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		dPos = event->globalPos() - pos();
		event->accept();
	}
}

void MsgFormWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - dPos);
		event->accept();
	}
}

void MsgFormWidget::onLoadFinished(bool)
{
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("JsInterface", (QObject*)JsInterface::GetInstance());
	connect(JsInterface::GetInstance(), SIGNAL(sigCommitStatue(bool)), this, SLOT(onCommitStatue(bool)));
}

void MsgFormWidget::onCommitStatue(bool bSucess)
{
	if (bSucess)
	{
		emit sigCommitStatue();
	}	
}
