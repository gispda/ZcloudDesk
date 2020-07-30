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

	//!设置是否显示阴影
	void setShadowEnable(bool bShow);

	//!设置是否可拖动
	void setMoveEnable(bool bEnable);

	//!获取内容widget指针，与UI绑定
	QWidget*	getContentWidget();
protected:
	void paintEvent(QPaintEvent*	event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	//!绘制边框阴影
	void	drawShadow();

	QWidget*	m_pContentWidget	= NULL;
	bool		m_bShadowEnable		=	true;
	bool		m_bMoveEnable		=	true;
	QPixmap		m_bg;
	QPoint		windowPos;
	QPoint		mousePos;
	QPoint		dPos;
};
