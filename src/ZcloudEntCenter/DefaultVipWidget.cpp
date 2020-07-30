#include "DefaultVipWidget.h"
#include <QGraphicsDropShadowEffect>
DefaultVipWidget::DefaultVipWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");
	setAttribute(Qt::WA_DeleteOnClose,true);
	setAttribute(Qt::WA_ShowModal, true);
	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
	//设置阴影距离
	shadow->setOffset(0, 0);
	//设置阴影颜色
	shadow->setColor(QColor("#666666"));
	//设置阴影圆角
	shadow->setBlurRadius(8);
	//给嵌套QWidget设置阴影
	this->setGraphicsEffect(shadow);
}

DefaultVipWidget::~DefaultVipWidget()
{
}
