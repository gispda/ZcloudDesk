#include "AvatarLabel.h"
#include <QPainter>
AvatarLabel::AvatarLabel(QWidget *parent)
	: QLabel(parent)
{
}

AvatarLabel::~AvatarLabel()
{
}
void AvatarLabel::setPic(QString strAvtarPath, bool bVip)
{
	m_strAvtarPath = strAvtarPath;
	m_bVip = bVip;
}

void AvatarLabel::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QRect	rectLabel = this->geometry();
	
	QPixmap bgPixmap;
	isHower ? bgPixmap.load(":/new/imageFile/bg_transparent_hover.png") : bgPixmap.load(":/new/imageFile/bg_transparent.png");
	//QPixmap pixmap(rectLabel.width(), rectLabel.height());
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	QPainterPath bgpath;
	bgpath.addRect(0, 0, rectLabel.width() - 2, rectLabel.height() - 2);
	painter.setClipPath(bgpath);
	painter.drawPixmap(0, 0, rectLabel.width() - 2, rectLabel.height() - 2, bgPixmap);


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
		pixmapa1.load(":/new/imageFile/dl_icon_vip.png");
	}
	else
	{
		pixmapa1.load(":/new/imageFile/dl_icon_vip_wjr.png");
	}
	QPainterPath path1;
	path1.addRect(0, -1, rectLabel.width() , rectLabel.height());
	painter.setClipPath(path1);
	painter.drawPixmap(0, -1, rectLabel.width(), rectLabel.height() , pixmapa1);
	return QLabel::paintEvent(event);
}


//获得焦点
void AvatarLabel::enterEvent(QEvent *)
{
	isHower = true;
	update();
}

//失去焦点
void AvatarLabel::leaveEvent(QEvent *)
{
	isHower = false;
	update();
}