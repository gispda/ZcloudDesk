#pragma once

#include <QDialog>
#include <QMouseEvent>
#include <QWidget>

class AppCommDialog : public QDialog
{
	Q_OBJECT

public:
	AppCommDialog(QWidget *parent);
	~AppCommDialog();
	QWidget *m_widget = NULL;
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent*	event);

private:
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;
	void drawShadow();

};
