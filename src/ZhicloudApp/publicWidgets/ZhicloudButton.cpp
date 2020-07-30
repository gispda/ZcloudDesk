#include "ZhicloudButton.h"
#include <QPainter>
#include <QLinearGradient>
#include <QPainterPath>

ZhicloudButton::ZhicloudButton(QString str_startColor, QString str_stopColor, QWidget *parent)
	: QPushButton(parent)
	, mstr_startColor(str_startColor)
	, mstr_stopColor(str_stopColor)
{
	//("border:none;position: absolute;");
	//this->setFlat(true);
	qlineargradient(spread:pad, x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0 rgba(0, 0, 0, 255), stop : 0.33 rgba(0, 0, 0, 255), stop : 0.34 rgba(255, 30, 30, 255), stop : 0.66 rgba(255, 0, 0, 255), stop : 0.67 rgba(255, 255, 0, 255), stop : 1 rgba(255, 255, 0, 255))

}

ZhicloudButton::~ZhicloudButton()
{

}


void ZhicloudButton::paintEvent(QPaintEvent* event)
{
	return QWidget::paintEvent(event);
	QPainter painter(this);
	QLinearGradient linearGradient(0, 0, this->width(), 0); //确定一条直线
	linearGradient.setColorAt(0, QColor(mstr_startColor));
	linearGradient.setColorAt(1, QColor(mstr_stopColor));
	painter.setBrush(linearGradient);

	painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
	QPainterPath painterPath;
	painterPath.addRoundedRect(this->rect(), m_radius, m_radius);
	painter.drawPath(painterPath);

	

	//painter.drawRect(this->rect());//绘制矩形，线性渐变线正好在矩形的水平中心线上
	painter.setRenderHint(QPainter::TextAntialiasing);
	painter.setPen(QColor(mstr_fonColor));
	QFont font("Microsoft YaHei");

	font.setPixelSize(m_fontSize);
	painter.setFont(font);
	painter.drawText(this->rect(), Qt::AlignVCenter | Qt::AlignHCenter, mstr_text);

	return QWidget::paintEvent(event);
}
