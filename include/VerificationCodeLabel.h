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
	//!��д�����¼�,�Դ���������֤��
	void paintEvent(QPaintEvent *event);
	//void mousePressEvent(QMouseEvent *ev);
private:
	void produceCode();
	//!������֤��
	void produceVerificationCode();
	//!����������ַ�
	QChar produceRandomLetter();
	//!�����������ɫ
	void produceRandomColor();

	QChar *verificationCode;
	QColor *colorArray;

	//!�����ַ�������
	const int letter_number = 4;

	//!��������
	int noice_point_number;
};
