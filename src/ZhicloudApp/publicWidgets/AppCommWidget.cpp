#include "AppCommWidget.h"
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QPushButton>
#include <QList>
#include <QVBoxLayout>
#include "ZhicloudAppDataDefine.h"
#include <QLabel>
//#include <qdrawutil.h>

AppCommWidget::AppCommWidget(QString imageFile,bool moveFlag, QWidget *parent)
	: QWidget(parent)
	, m_widget(new QWidget())
	, m_moveFlag(moveFlag)
{
	//	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	//	setWindowModality(Qt::);
	//	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);

	//���ô���͸��WindowModal
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	//�����ޱ߿�
	this->setWindowFlags(Qt::FramelessWindowHint);
	if (!imageFile.isEmpty())
	{
		m_bg.load(imageFile);
		m_bgLoad = true;
	}
	m_widget->setObjectName("AppCommWidgetWidget");

	QGridLayout *pLayout = new QGridLayout(this);
	pLayout->addWidget(m_widget);
	pLayout->setMargin(8);
	pLayout->setSpacing(0);
	//QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
	////shadow->setBlurRadius(0.8);				//��Ӱģ����
	////������Ӱ����
	//shadow->setOffset(0, 0);
	////������Ӱ��ɫ
	//shadow->setColor(QColor("#666666"));
	////������ӰԲ��
	//shadow->setBlurRadius(8);
	////��Ƕ��QWidget������Ӱ
	//this->setGraphicsEffect(shadow);
}

AppCommWidget::~AppCommWidget()
{
}


void AppCommWidget::paintEvent(QPaintEvent* event)
{
	if (m_bgLoad)
	{
		QPainter painter(m_widget);
		painter.setRenderHint(QPainter::Antialiasing, true);
		painter.drawPixmap(m_widget->rect(), m_bg);
	}
	if (m_bShowShadow)
	{
		drawShadow();
	}
	
	return QWidget::paintEvent(event);
}



void AppCommWidget::drawShadow()
{
	QPainter painter(this);
	QList<QPixmap> pixmaps;
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/leftTopLabel.png").scaled(2 * MARGIN_WITH,2 * MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/topLabel.png").scaled(this->width() - 4 * MARGIN_WITH,  MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/rightTopLabel.png").scaled(2 * MARGIN_WITH, 2 * MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/leftLabel.png").scaled( MARGIN_WITH,this->height() - 4 * MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/rightLabel.png").scaled(MARGIN_WITH, this->height() - 4 * MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/leftBottomLabel.png").scaled(2 * MARGIN_WITH, 2 * MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/bottomLabel.png").scaled(this->width() - 4 * MARGIN_WITH, MARGIN_WITH));
	pixmaps.append(QPixmap(":/new/imageFile/AppCenterPng/rightBottonLabel.png").scaled(2 * MARGIN_WITH, 2 * MARGIN_WITH));


	painter.drawPixmap(0, 0, MARGIN_WITH * 2, MARGIN_WITH * 2, pixmaps[0]);
	painter.drawPixmap(MARGIN_WITH * 2, 0, this->width() - 4 * MARGIN_WITH, MARGIN_WITH, pixmaps[1]);
	painter.drawPixmap(this->width() - 2* MARGIN_WITH, 0, 2 * MARGIN_WITH,2 * MARGIN_WITH, pixmaps[2]);

	painter.drawPixmap(0, 2 * MARGIN_WITH, MARGIN_WITH, this->height() - 4 * MARGIN_WITH, pixmaps[3]);
	painter.drawPixmap(this->width() - MARGIN_WITH, 2 * MARGIN_WITH, MARGIN_WITH,this->height() - 4 * MARGIN_WITH, pixmaps[4]);

	painter.drawPixmap(0, this->height() - 2 * MARGIN_WITH, 2 * MARGIN_WITH,  2 * MARGIN_WITH, pixmaps[5]);
	painter.drawPixmap(2 * MARGIN_WITH, this->height() - MARGIN_WITH, this->width() - 4 * MARGIN_WITH, MARGIN_WITH, pixmaps[6]);
	painter.drawPixmap(this->width() - 2 * MARGIN_WITH, this->height() - 2 * MARGIN_WITH, 2 * MARGIN_WITH, 2 *MARGIN_WITH, pixmaps[7]);
}




void AppCommWidget::mousePressEvent(QMouseEvent *event)
{
	if (m_moveFlag)
	{
		this->windowPos = this->pos();            // ��ò�����ǰλ��
		this->mousePos = event->globalPos();     // ������λ��
		this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
	}
	return QWidget::mousePressEvent(event);
}

void AppCommWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (m_moveFlag)
		this->move(event->globalPos() - this->dPos);
	return QWidget::mouseMoveEvent(event);
}

void AppCommWidget::showShadow(bool bShow)
{
	m_bShowShadow = bShow;
}



AppCommButton::AppCommButton(QPushButton *button, QWidget *parent)
	: QFrame(parent)
{
	//���ô���͸��
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	//�����ޱ߿�
	this->setWindowFlags(Qt::FramelessWindowHint);

	// �����ӰQWidget
	QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(button);
	shadowEffect->setColor(Qt::lightGray);
	shadowEffect->setBlurRadius(8); // ��Ӱ�Ĵ�С
	shadowEffect->setOffset(0, 0);
	button->setGraphicsEffect(shadowEffect);

	// ��ӵ�������
	QGridLayout *lo = new QGridLayout();
	lo->addWidget(button, 0, 0);
	lo->setContentsMargins(0, 0, 0, 8); 
	setLayout(lo);
}

AppCommButton::~AppCommButton()
{
}




