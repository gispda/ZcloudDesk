#include "MsgFormWidget.h"
#include <QGraphicsDropShadowEffect>
#include <QWebFrame>
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

	ui.webView->setContextMenuPolicy(Qt::NoContextMenu);

	connect(ui.webView->page()->networkAccessManager(),
		SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> &)),
		this,
		SLOT(handleSslErrors(QNetworkReply*, const QList<QSslError> &)));

	ui.webView->load(QUrl::fromUserInput(strUrl));
	connect(ui.webView, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished(bool)));
	connect(ui.closeButton, &QPushButton::clicked, [this]()
	{
		emit sigMsgFormClose();
		close();
	});
}

MsgFormWidget::~MsgFormWidget()
{
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

void MsgFormWidget::handleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors)
{
	//foreach(QSslError e, errors)
	//{
	//	qDebug() << "ssl error: " << e;
	//}
	reply->ignoreSslErrors();
}
void MsgFormWidget::onLoadFinished(bool)
{
	ui.webView->page()->mainFrame()->addToJavaScriptWindowObject("JsInterface", this);
}

void MsgFormWidget::commitStatue(bool bSucess)
{
	if (bSucess)
	{
		emit sigCommitStatue();
	}
}