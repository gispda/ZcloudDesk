#ifndef EDGETOHIDE_H
#define EDGETOHIDE_H

#include <QWidget>
#include <QEvent>
#include <QDesktopWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>

enum EdgeStatus
{
    EG_TOP,
    EG_LEFT,
    EG_RIGHT,
    EG_NORMAL
};

class EdgeToHide : public QWidget
{
    Q_OBJECT

public:
    explicit EdgeToHide(QWidget *parent = 0);
    ~EdgeToHide();
	void leaveStatusChanged();
	void setHaveHide(bool isHide)
	{
		m_isHaveHide = isHide;
		leaveStatusChanged();
	};
protected:
    void leaveEvent(QEvent *event);
    void enterEvent(QEvent *event);
    //void mouseReleaseEvent(QMouseEvent*event);
	void paintEvent(QPaintEvent* event);

	//void mouseMoveEvent(QMouseEvent*event);
	//void mousePressEvent(QMouseEvent*event);

private:
	bool m_isHaveHide;
    EdgeStatus m_eEdgeStatus;
	QPixmap m_bg;
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;
};

#endif // EDGETOHIDE_H
