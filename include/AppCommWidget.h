#pragma once

#ifdef ZHICLOUDAPP_LIB
# define ZHICLOUDAPP_EXPORT Q_DECL_EXPORT
#else
# define ZHICLOUDAPP_EXPORT Q_DECL_IMPORT
#endif

#include <QWidget>
#include <QDialog>
#include <QMouseEvent>
#include <QPushButton>
#include <QFrame>

class ZHICLOUDAPP_EXPORT AppCommWidget : public QWidget
{
	Q_OBJECT

public:
	AppCommWidget(QString imageFile, bool moveFlag,  QWidget *parent);
	~AppCommWidget();

	QWidget *m_widget = NULL;
	void showShadow(bool bShow);
protected:
	void paintEvent(QPaintEvent*	event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	QPixmap	m_bg;
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;
	void drawShadow();

private:
	bool m_bgLoad = false;
	bool m_moveFlag = true;
	bool m_bShowShadow = true;
};


class AppCommButton : public QFrame
{
	Q_OBJECT

public:
	AppCommButton(QPushButton *button,QWidget *parent = 0);
	~AppCommButton();


};

