#include "VerDesWidget.h"
#include <QGraphicsDropShadowEffect>
VerDesWidget::VerDesWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");
	setAttribute(Qt::WA_ShowModal, true);
	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
	//������Ӱ����
	shadow->setOffset(0, 0);
	//������Ӱ��ɫ
	shadow->setColor(QColor("#666666"));
	//������ӰԲ��
	shadow->setBlurRadius(8);
	//��Ƕ��QWidget������Ӱ
	this->setGraphicsEffect(shadow);

	QPalette pl = ui.textEdit->palette();
	pl.setBrush(QPalette::Base, QBrush(QColor(255, 0, 0, 0)));
	ui.textEdit->setPalette(pl);

	connect(ui.closeButton, &QPushButton::clicked, [this]()
	{
		close();
	});
}

VerDesWidget::~VerDesWidget()
{
}

void VerDesWidget::mousePressEvent(QMouseEvent *event)
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

void VerDesWidget::mouseMoveEvent(QMouseEvent *event)
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
