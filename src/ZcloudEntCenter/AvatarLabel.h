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
	//��ý���
	void enterEvent(QEvent *);
	//ʧȥ����
	void leaveEvent(QEvent *);
private:
	QString m_strAvtarPath;
	bool	m_bVip;
	bool isHower = false;
};
