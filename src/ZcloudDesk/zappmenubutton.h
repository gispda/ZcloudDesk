#ifndef ZAPPMENUBUTTON_H
#define ZAPPMENUBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QPushButton>
#include <QEvent>
#include <QLayout>
#include "zdot.h"

class ZAppMenuButton : public QPushButton
{
	Q_OBJECT
public:
	ZAppMenuButton(QWidget *parent = 0);
	ZAppMenuButton(QString strCateId,QWidget *parent = 0);
    ZAppMenuButton(int radius = 0,QString str = "", QWidget *parent = 0,bool zFlag = false);
public:
    void setNumberF(int number, bool have);
	void setNumber(int number);
	QString userData();
	int pIndex = 0;
private:
      int iRadius;
      ZDot *lable;
	  QString m_strCateId;

};
#endif // ZAPPMENUBUTTON_H
