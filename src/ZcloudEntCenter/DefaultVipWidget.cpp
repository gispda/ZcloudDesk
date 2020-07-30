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
	//������Ӱ����
	shadow->setOffset(0, 0);
	//������Ӱ��ɫ
	shadow->setColor(QColor("#666666"));
	//������ӰԲ��
	shadow->setBlurRadius(8);
	//��Ƕ��QWidget������Ӱ
	this->setGraphicsEffect(shadow);
}

DefaultVipWidget::~DefaultVipWidget()
{
}
