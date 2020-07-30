#pragma once
#include <QLabel>

class AvatarLabel : public QLabel
{
	Q_OBJECT

public:
	AvatarLabel(QWidget *parent);
	~AvatarLabel();
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
