#include "zdot.h"

ZDot::ZDot( int radius, bool zflag, QWidget *parent)
    : QLabel(parent)
    ,iRadius(radius)
{
    this->setMinimumSize(iRadius * 2, iRadius * 2);
    this->setMaximumSize(iRadius * 2, iRadius * 2);
	have = zflag;
    number = 0;
}

void ZDot::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int arcHeight = 10;

    painter.translate(width() >> 1, height() >> 1);

    /**
       * 参数二：半径
       * 参数三：开始的角度
       * 参数四：指扫取的角度-顺时针（360度 / 8 = 45度）
       * 参数五：圆环的高度
       * 参数六：填充色
      **/


	if (number > 0)
		gradientArc(&painter, iRadius, 0, 360, arcHeight, qRgb(250, 0, 0));
}

void ZDot::gradientArc(QPainter *painter, int radius, int startAngle, int angleLength, int arcHeight, QRgb color)
{
    // 渐变色
    QRadialGradient gradient;//(0, 0, radius);
    //gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1.0, color);
    painter->setBrush(gradient);

    // << 1（左移1位）相当于radius*2 即：150*2=300
    //QRectF(-150, -150, 300, 300)
    QRectF rect( - radius, - radius , radius << 1 , radius << 1);
    QPainterPath path;
    path.arcTo(rect, startAngle, angleLength);
    painter->setPen(Qt::NoPen);
    painter->drawPath(path);

	if (have)
	{
	
		QLinearGradient myGradient;
		QPen myPen;
		myPen.setColor(QColor(255, 255, 255));
		QFont myFont;//( "Microsoft YaHei" , 7 ,  QFont::Thin) ;
		myFont.setFamily("Yu Gothic Light");
		
		QPainterPath myPath;
		QPointF baseline;
		if(number <= 99)
		{
			if(number <=9 )
			{
				if (number == 1)
				{
					myFont.setPointSize(10);
					baseline.setX(radius - 4);
					baseline.setY(radius + 5);
				}
				else
				{
					myFont.setPointSize(9);
					baseline.setX(radius - 3);
					baseline.setY(radius + 5);
				}

			}else
			{
				myFont.setPointSize(8);
				baseline.setX(radius - 6);
				baseline.setY(radius + 5);
			}
			myPath.addText(baseline, myFont, QString::number(number));
		}
		else
		{
			myFont.setPointSize(7);
			baseline.setX(radius - 7);
			baseline.setY(radius + 4);
			myPath.addText(baseline, myFont, QString::fromLocal8Bit("99+"));
		}
		QPainter painter1(this);
		painter1.setRenderHint(QPainter::Antialiasing, true);
		painter1.setRenderHint(QPainter::SmoothPixmapTransform);
		painter1.setBrush(myGradient);
		painter1.setPen(myPen);
		painter1.drawPath(myPath);
		this->show();
	}

}
