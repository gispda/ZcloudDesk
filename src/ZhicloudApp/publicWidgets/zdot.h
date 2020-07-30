#ifndef ZDOT_H
#define ZDOT_H

#include <QLabel>
#include <QWidget>
#include <QPainter>

class ZDot : public QLabel
{
public:
    ZDot(int radius = 0, bool zflag = false, QWidget *parent = 0);
    void gradientArc(QPainter *painter, int radius, int startAngle, int angleLength, int arcHeight, QRgb color);
     int number;
	 bool have;//是否显示数字的标志位
protected:

    void paintEvent(QPaintEvent *event);
private:
      int iRadius;

};

#endif // ZDOT_H
