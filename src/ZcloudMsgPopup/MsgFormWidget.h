#pragma once

#include <QWidget>
#include "ui_MsgFormWidget.h"
#include "qevent.h"
#include <QNetworkReply>
#include <QSslError>
class MsgFormWidget : public QWidget
{
	Q_OBJECT

public:
	MsgFormWidget(QString strUrl,QWidget *parent = Q_NULLPTR);
	~MsgFormWidget();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
signals:
	void sigCommitStatue();
	void sigMsgFormClose();
public slots:
	void commitStatue(bool);
private slots:
	void handleSslErrors(QNetworkReply*, const QList<QSslError> &);
	void onLoadFinished(bool);
private:
	Ui::MsgFormWidget ui;
	QPoint dPos;
};
