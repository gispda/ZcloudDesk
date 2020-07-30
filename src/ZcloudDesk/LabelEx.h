#pragma once

#include <QLabel>

class LabelEx : public QLabel
{
	Q_OBJECT

public:
	LabelEx(QWidget *parent);
	~LabelEx();
	void setPic(QString strAvtarPath, bool bVip);
protected:
	void paintEvent(QPaintEvent *event);
	//获得焦点
	void enterEvent(QEvent *);
	//失去焦点
	void leaveEvent(QEvent *);
private:
	QString m_strAvtarPath;
	bool	m_bVip;
	bool isHower = false;
};
