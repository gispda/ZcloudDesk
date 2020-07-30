#pragma once

#include <QPushButton>
#include <QWidget>
class ZhicloudButton : public QPushButton
{
	Q_OBJECT

public:
	ZhicloudButton(QString str_startColor, QString str_stopColor, QWidget *parent = NULL);
	~ZhicloudButton();
	//这种字体       文字   字体大小   圆角大小
	void setText(QString str_text,QString fontColor = "", int fontSize = 0, int i_radius = 0)
	{
		mstr_text = str_text;
		if (i_radius) m_radius = i_radius;
		if (!fontColor.isEmpty()) mstr_fonColor = fontColor;
		if (m_fontSize) m_fontSize = fontSize;
	};
	void setStartStopColor(QString startColor, QString stopColor)
	{
		mstr_startColor = startColor;
		mstr_stopColor = stopColor;
	};
protected:

	void paintEvent(QPaintEvent* event);
private:
	QString mstr_startColor;
	QString mstr_stopColor;
	QString mstr_text;
	QString mstr_fonColor;
	int m_fontSize = 12;
	int m_radius = 0;
};
