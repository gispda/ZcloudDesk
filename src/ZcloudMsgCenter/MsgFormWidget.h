#pragma once

#include <QWidget>
#include "ui_MsgFormWidget.h"
#include "qevent.h"
#include "WebView.h"
class MsgFormWidget : public QWidget
{
	Q_OBJECT

public:
	MsgFormWidget(QString strUrl,QWidget *parent = Q_NULLPTR);
	~MsgFormWidget();
signals:
	void sigCommitStatue();
	void sigMsgFormClose();
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:
	void onLoadFinished(bool);
	void onCommitStatue(bool);
private:
	Ui::MsgFormWidget ui;
	WebView*	m_pWebView = NULL;
	QPoint dPos;
};
