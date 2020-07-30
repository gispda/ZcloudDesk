#pragma once
#ifdef ZCLOUDCOMMON_LIB
# define ZCLOUDCODELABEL_EXPORT Q_DECL_EXPORT
#else
# define ZCLOUDCODELABEL_EXPORT Q_DECL_IMPORT
#endif
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QTime>

class ZCLOUDCODELABEL_EXPORT VerificationCodeLabel : public QLabel
{
	Q_OBJECT

public:
	VerificationCodeLabel(QWidget *parent = 0);
	~VerificationCodeLabel();

	QString getVerificationCode();
protected:
	//!重写绘制事件,以此来生成验证码
	void paintEvent(QPaintEvent *event);
	//void mousePressEvent(QMouseEvent *ev);
private:
	void produceCode();
	//!生成验证码
	void produceVerificationCode();
	//!产生随机的字符
	QChar produceRandomLetter();
	//!产生随机的颜色
	void produceRandomColor();

	QChar *verificationCode;
	QColor *colorArray;

	//!产生字符的数量
	const int letter_number = 4;

	//!噪点的数量
	int noice_point_number;
};
