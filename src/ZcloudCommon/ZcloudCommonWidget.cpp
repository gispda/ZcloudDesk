#include "ZcloudCommonWidget.h"
#include <QPainter>
#include <QGridLayout>
#define MARGIN_SPACE 8
ZcloudCommonWidget::ZcloudCommonWidget(QWidget *parent)
	: QWidget(parent)
	, m_pContentWidget(new QWidget(this))
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none"); 

	QGridLayout *pLayout = new QGridLayout(this);
	pLayout->addWidget(m_pContentWidget);
	pLayout->setMargin(8);
	pLayout->setSpacing(0);
}

ZcloudCommonWidget::~ZcloudCommonWidget()
{
}

void ZcloudCommonWidget::setShadowEnable(bool bEnable)
{
	m_bShadowEnable = bEnable;
}

void ZcloudCommonWidget::setMoveEnable(bool bEnable)
{
	m_bMoveEnable = bEnable;
}

void ZcloudCommonWidget::drawShadow()
{
	QPainter painter(this);
	QList<QPixmap> pixmaps;
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/leftTopLabel.png").scaled(2 * MARGIN_SPACE, 2 * MARGIN_SPACE));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/topLabel.png").scaled(this->width() - 4 * MARGIN_SPACE, MARGIN_SPACE));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/rightTopLabel.png").scaled(2 * MARGIN_SPACE, 2 * MARGIN_SPACE));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/leftLabel.png").scaled(MARGIN_SPACE, this->height() - 4 * MARGIN_SPACE));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/rightLabel.png").scaled(MARGIN_SPACE, this->height() - 4 * MARGIN_SPACE));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/leftBottomLabel.png").scaled(2 * MARGIN_SPACE, 2 * MARGIN_SPACE));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/bottomLabel.png").scaled(this->width() - 4 * MARGIN_SPACE, MARGIN_SPACE));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/rightBottonLabel.png").scaled(2 * MARGIN_SPACE, 2 * MARGIN_SPACE));


	painter.drawPixmap(0, 0, MARGIN_SPACE * 2, MARGIN_SPACE * 2, pixmaps[0]);
	painter.drawPixmap(MARGIN_SPACE * 2, 0, this->width() - 4 * MARGIN_SPACE, MARGIN_SPACE, pixmaps[1]);
	painter.drawPixmap(this->width() - 2 * MARGIN_SPACE, 0, 2 * MARGIN_SPACE, 2 * MARGIN_SPACE, pixmaps[2]);

	painter.drawPixmap(0, 2 * MARGIN_SPACE, MARGIN_SPACE, this->height() - 4 * MARGIN_SPACE, pixmaps[3]);
	painter.drawPixmap(this->width() - MARGIN_SPACE, 2 * MARGIN_SPACE, MARGIN_SPACE, this->height() - 4 * MARGIN_SPACE, pixmaps[4]);

	painter.drawPixmap(0, this->height() - 2 * MARGIN_SPACE, 2 * MARGIN_SPACE, 2 * MARGIN_SPACE, pixmaps[5]);
	painter.drawPixmap(2 * MARGIN_SPACE, this->height() - MARGIN_SPACE, this->width() - 4 * MARGIN_SPACE, MARGIN_SPACE, pixmaps[6]);
	painter.drawPixmap(this->width() - 2 * MARGIN_SPACE, this->height() - 2 * MARGIN_SPACE, 2 * MARGIN_SPACE, 2 * MARGIN_SPACE, pixmaps[7]);
}

void ZcloudCommonWidget::mousePressEvent(QMouseEvent *event)
{
	if (m_bMoveEnable)
	{
		this->windowPos = this->pos();            // 获得部件当前位置
		this->mousePos = event->globalPos();     // 获得鼠标位置
		this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
	}
	return QWidget::mousePressEvent(event);
}

void ZcloudCommonWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bMoveEnable)
	{
		this->move(event->globalPos() - this->dPos);
	}
	return QWidget::mouseMoveEvent(event);
}

void ZcloudCommonWidget::paintEvent(QPaintEvent* event)
{
	if (m_bShadowEnable)
	{
		drawShadow();
	}
	return QWidget::paintEvent(event);
}

QWidget* ZcloudCommonWidget::getContentWidget()
{
	return m_pContentWidget;
}