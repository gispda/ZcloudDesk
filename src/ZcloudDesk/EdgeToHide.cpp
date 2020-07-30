#include "edgetohide.h"
#include <QApplication>

int SHOW_EDGE_WIDTH = 2;

EdgeToHide::EdgeToHide(QWidget *parent) :
    QWidget(parent)
	, m_isHaveHide(false)
{
	setWindowFlags(Qt::FramelessWindowHint );
	setAttribute(Qt::WA_TranslucentBackground, true);
    setStyleSheet("outline: none");

	m_bg.load(":/ZcloudDesk/image/bg_transparent_pre.png");
}

EdgeToHide::~EdgeToHide()
{
    
}


//���ڵĽ����¼�(enterEvent)
void EdgeToHide::enterEvent(QEvent *event)
{
    switch (m_eEdgeStatus)
    {
    case EG_TOP:
        setGeometry(pos().x(), -SHOW_EDGE_WIDTH, width(), height());
        break;
    case EG_LEFT:
        setGeometry(-SHOW_EDGE_WIDTH, y(), width(), height());
        break;
    case EG_RIGHT:
        setGeometry(QApplication::desktop()->width() - width() + SHOW_EDGE_WIDTH, y(), width(), height());
        break;
    }
    return QWidget::enterEvent(event);
}

//���ڵ��뿪�¼���leaveEvent��
void EdgeToHide::leaveEvent(QEvent *event)
{
	leaveStatusChanged();
    return QWidget::leaveEvent(event);
}

void EdgeToHide::leaveStatusChanged()
{
	if (m_isHaveHide)
	{
		if (y() <= 2)
		{
			m_eEdgeStatus = EG_TOP;
		}
		else if (QApplication::desktop()->width() <= (this->x() + width()))
		{
			m_eEdgeStatus = EG_RIGHT;
		}
		else if (this->x() <= 0)
		{
			m_eEdgeStatus = EG_LEFT;
		}
		else
		{
			m_eEdgeStatus = EG_NORMAL;
		}

		switch (m_eEdgeStatus)
		{
		case EG_TOP:
			setGeometry(pos().x(), -height() + SHOW_EDGE_WIDTH + 2, width(), height());
			break;
		case EG_LEFT:
			setGeometry(-width() + SHOW_EDGE_WIDTH, pos().y(), width(), height());
			break;
		case EG_RIGHT:
			setGeometry(QApplication::desktop()->width() - SHOW_EDGE_WIDTH, pos().y(), width(), height());
			break;
		}
	}
	else
	{
		m_eEdgeStatus = EG_NORMAL;
		setGeometry(pos().x(), 0, width(), height());
	}
}

//����ͷŵ����¼�(mouseReleaseEvent)
//void EdgeToHide::mouseReleaseEvent(QMouseEvent*event)
//{
//  
//    QWidget::mouseReleaseEvent(event);
//}

void EdgeToHide::paintEvent(QPaintEvent* event)
{
	QPainter painter;
	painter.begin(this);
	painter.drawPixmap(rect(), m_bg);
	painter.end();
	return QWidget::paintEvent(event);
}

//void EdgeToHide::mouseMoveEvent(QMouseEvent *event)
//{
//	this->move(event->globalPos() - this->dPos);
//}
//
//void EdgeToHide::mousePressEvent(QMouseEvent *event)
//{
//	this->windowPos = this->pos();            // ��ò�����ǰλ��
//	this->mousePos = event->globalPos();     // ������λ��
//	this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
//}
