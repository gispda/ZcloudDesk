#pragma once
#ifdef ZCLOUDCOMMON_LIB
# define ZCLOUDCOMMONWIDGET_EXPORT Q_DECL_EXPORT
#else
# define ZCLOUDCOMMONWIDGET_EXPORT Q_DECL_IMPORT
#endif
#include <QWidget>
#include "qevent.h"
#include <QDialog>

class ZCLOUDCOMMONWIDGET_EXPORT ZcloudCommonWidget : public QWidget
{
	Q_OBJECT

public:
	ZcloudCommonWidget(QWidget *parent = NULL);
	~ZcloudCommonWidget();

	//!�����Ƿ���ʾ��Ӱ
	void setShadowEnable(bool bShow);

	//!�����Ƿ���϶�
	void setMoveEnable(bool bEnable);

	//!��ȡ����widgetָ�룬��UI��
	QWidget*	getContentWidget();
protected:
	void paintEvent(QPaintEvent*	event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	//!���Ʊ߿���Ӱ
	void	drawShadow();

	QWidget*	m_pContentWidget	= NULL;
	bool		m_bShadowEnable		=	true;
	bool		m_bMoveEnable		=	true;
	QPixmap		m_bg;
	QPoint		windowPos;
	QPoint		mousePos;
	QPoint		dPos;
};
