#include "zappmenubutton.h"

//按钮右上角可显示红点
ZAppMenuButton::ZAppMenuButton(QWidget *parent)
	:QPushButton(parent)
{
	lable = new ZDot(4, false, this);
	lable->setGeometry(49, 3, 4, 4);
	setNumberF(1, false);
}

ZAppMenuButton::ZAppMenuButton(QString strCateId, QWidget *parent)
	:QPushButton(parent)
	, m_strCateId(strCateId)
{
	lable = new ZDot(4, false, this);
	lable->setGeometry(49, 3, 4, 4);
	setNumberF(1, false);
}

ZAppMenuButton::ZAppMenuButton(int radius, QString str, QWidget *parent,bool zFlag)
    : QPushButton(parent)
    ,iRadius(radius)
{
    lable = new ZDot(iRadius,zFlag,this);
	if(!zFlag){
		lable->setGeometry(49, 3, iRadius, iRadius);
		setNumberF(1,false);
	}
	else{
		lable->setGeometry(44, 0, iRadius, iRadius);
		setNumberF(100,true);
	}
    this->setText(str);
}

//have 为true显示数字  否则不显示数字
void ZAppMenuButton::setNumberF(int number, bool have)
{
    lable->number = number;
	lable->have = have;
}

void ZAppMenuButton::setNumber(int number)
{
	lable->number = number;
	if (number == 0)
		lable->hide();
	else
		lable->show();
}
QString ZAppMenuButton::userData()
{
	return m_strCateId;
}
