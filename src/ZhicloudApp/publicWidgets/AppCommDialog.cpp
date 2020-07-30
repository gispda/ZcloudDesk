#include "AppCommDialog.h"
#include <QPainter>
#include <QGridLayout>
#include "ZhicloudAppDataDefine.h"

AppCommDialog::AppCommDialog(QWidget *parent)
	: QDialog(parent)
	, m_widget(new QWidget())
{
	setWindowModality(Qt::WindowModal);
	//setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);

	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);


	m_widget->setObjectName("AppCommDialogDialog");
	m_widget->setStyleSheet("QWidget#AppCommDialogDialog{border-radius:4px;}");

	QGridLayout *pLayout = new QGridLayout(this);
	pLayout->addWidget(m_widget);
	pLayout->setMargin(8);
	pLayout->setSpacing(0);
}

AppCommDialog::~AppCommDialog()
{
}


void AppCommDialog::mousePressEvent(QMouseEvent *event)
{
	this->windowPos = this->pos();            // 获得部件当前位置
	this->mousePos = event->globalPos();     // 获得鼠标位置
	this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void AppCommDialog::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->globalPos() - this->dPos);
}

void AppCommDialog::paintEvent(QPaintEvent* event)
{
	/*QPainter painter(m_widget);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.drawPixmap(m_widget->rect(), m_bg);*/
	drawShadow();
	return QWidget::paintEvent(event);
}



void AppCommDialog::drawShadow()
{
	QPainter painter(this);
	QList<QPixmap> pixmaps;
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/leftTopLabel.png").scaled(2 * MARGIN_WITH, 2 * MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/topLabel.png").scaled(this->width() - 4 * MARGIN_WITH, MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/rightTopLabel.png").scaled(2 * MARGIN_WITH, 2 * MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/leftLabel.png").scaled(MARGIN_WITH, this->height() - 4 * MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/rightLabel.png").scaled(MARGIN_WITH, this->height() - 4 * MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/leftBottomLabel.png").scaled(2 * MARGIN_WITH, 2 * MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/bottomLabel.png").scaled(this->width() - 4 * MARGIN_WITH, MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/rightBottonLabel.png").scaled(2 * MARGIN_WITH, 2 * MARGIN_WITH));


	painter.drawPixmap(0, 0, MARGIN_WITH * 2, MARGIN_WITH * 2, pixmaps[0]);
	painter.drawPixmap(MARGIN_WITH * 2, 0, this->width() - 4 * MARGIN_WITH, MARGIN_WITH, pixmaps[1]);
	painter.drawPixmap(this->width() - 2 * MARGIN_WITH, 0, 2 * MARGIN_WITH, 2 * MARGIN_WITH, pixmaps[2]);

	painter.drawPixmap(0, 2 * MARGIN_WITH, MARGIN_WITH, this->height() - 4 * MARGIN_WITH, pixmaps[3]);
	painter.drawPixmap(this->width() - MARGIN_WITH, 2 * MARGIN_WITH, MARGIN_WITH, this->height() - 4 * MARGIN_WITH, pixmaps[4]);

	painter.drawPixmap(0, this->height() - 2 * MARGIN_WITH, 2 * MARGIN_WITH, 2 * MARGIN_WITH, pixmaps[5]);
	painter.drawPixmap(2 * MARGIN_WITH, this->height() - MARGIN_WITH, this->width() - 4 * MARGIN_WITH, MARGIN_WITH, pixmaps[6]);
	painter.drawPixmap(this->width() - 2 * MARGIN_WITH, this->height() - 2 * MARGIN_WITH, 2 * MARGIN_WITH, 2 * MARGIN_WITH, pixmaps[7]);
}
