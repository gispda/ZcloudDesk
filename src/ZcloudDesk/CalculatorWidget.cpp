#include "CalculatorWidget.h"
#include <QDesktopWidget>
#include <QApplication>
CalculatorWidget::CalculatorWidget(QString strName,QString strUrl, QWidget *parent)
	: AppCommWidget("", true, parent)
{
	ui.setupUi(m_widget);
	resize(1156, 776);
	setObjectName("CalculatorWidget");
	setWindowTitle(strName);
	ui.label->setText(strName);
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
	m_pWebView->setGeometry(0, 50, 1140, 710);

	m_pWebView->load(QUrl::fromUserInput(strUrl));

	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
}

CalculatorWidget::~CalculatorWidget()
{
}

void CalculatorWidget::mousePressEvent(QMouseEvent *event)
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

void CalculatorWidget::mouseMoveEvent(QMouseEvent *event)
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
