#include "VerificationCodeLabel.h"

VerificationCodeLabel::VerificationCodeLabel(QWidget *parent)
	: QLabel(parent)
{
	qsrand(QTime::currentTime().second() * 1000 + QTime::currentTime().msec());
	colorArray = new QColor[letter_number];
	verificationCode = new QChar[letter_number];
	noice_point_number = this->width() * 4;
}

VerificationCodeLabel::~VerificationCodeLabel()
{
}

void VerificationCodeLabel::paintEvent(QPaintEvent *event)
{
	produceCode();
	return;
}

//void VerificationCodeLabel::mousePressEvent(QMouseEvent *ev)
//{
//	repaint();
//}

void VerificationCodeLabel::produceVerificationCode()
{
	for (int i = 0; i < letter_number; ++i)
	{
		verificationCode[i] = produceRandomLetter();
	}	
}

QChar VerificationCodeLabel::produceRandomLetter()
{
	QChar c;
	int flag = qrand() % letter_number;
	switch (flag)
	{
		case 0:
			c = '0' + qrand() % 10;
			break;
		case 1:
			c = 'A' + qrand() % 26;
			break;
		case 2:
			c = 'a' + qrand() % 26;
			break;
		default:
			c = '0' + qrand() % 10;
			break;
	}
	return c;
}

void VerificationCodeLabel::produceRandomColor()
{
	for (int i = 0; i < letter_number; ++i)
	{
		colorArray[i] = QColor(qrand() % 255, qrand() % 255, qrand() % 255);
	}	
}

void VerificationCodeLabel::produceCode()
{
	QPainter painter(this);
	QPoint p;
	//!产生4个不同的字符
	produceVerificationCode();
	//!产生4个不同的颜色
	produceRandomColor();
	//!绘制验证码
	for (int i = 0; i < letter_number; ++i)
	{
		p.setX(i*(this->width() / letter_number) + this->width() / 16);
		p.setY(this->height() / 1.5);
		painter.setPen(colorArray[i]);
		painter.drawText(p, QString(verificationCode[i]));
	}
	//!绘制噪点
	for (int j = 0; j < noice_point_number; ++j)
	{
		p.setX(qrand() % this->width());
		p.setY(qrand() % this->height());
		painter.setPen(colorArray[j % 4]);
		painter.drawPoint(p);
	}
}

QString VerificationCodeLabel::getVerificationCode()
{
	QString strReturn;
	strReturn.append(verificationCode, letter_number);
	return strReturn;
}
