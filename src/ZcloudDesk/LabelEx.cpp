#include "LabelEx.h"
#include <QPainter>
#include <QDebug>
LabelEx::LabelEx(QWidget *parent)
	: QLabel(parent)
{
}

LabelEx::~LabelEx()
{
}
void LabelEx::setPic(QString strAvtarPath, bool bVip)
{
	m_strAvtarPath = strAvtarPath;
	m_bVip = bVip;
}

void LabelEx::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QRect	rectLabel = this->geometry();
	
	QPixmap bgPixmap;
	bgPixmap.load(":/ZcloudDesk/image/bg_transparent.png");
	//isHower ? bgPixmap.load(":/ZcloudDesk/image/bg_transparent_hover.png") : bgPixmap.load(":/ZcloudDesk/image/bg_transparent.png");
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	QPainterPath bgpath;
	bgpath.addRect(0, 0, rectLabel.width(), rectLabel.height());
	painter.setClipPath(bgpath);
	painter.drawPixmap(0, 0, rectLabel.width(), rectLabel.height() , bgPixmap);


	QPixmap pixmapa;
	pixmapa.load(m_strAvtarPath);
	
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	QPainterPath path;
	path.addEllipse(0, 0, rectLabel.width() - 2, rectLabel.height() - 2);
	painter.setClipPath(path);
	painter.drawPixmap(0, 0, rectLabel.width() - 2, rectLabel.height() - 2, pixmapa);

	QPixmap pixmapa1;
	if (m_bVip)
	{
		pixmapa1.load(":/ZcloudDesk/image/dl_icon_vip.png");
	}
	else
	{
		pixmapa1.load(":/ZcloudDesk/image/dl_icon_vip_wjr.png");
	}
	QPainterPath path1;
	path1.addRect(0, -1, rectLabel.width() , rectLabel.height());
	painter.setClipPath(path1);
	painter.drawPixmap(0, -1, rectLabel.width(), rectLabel.height() , pixmapa1);
	return QLabel::paintEvent(event);
}


//获得焦点
void LabelEx::enterEvent(QEvent *)
{
	isHower = true;
	update();
}

//失去焦点
void LabelEx::leaveEvent(QEvent *)
{
	isHower = false;
	update();
}