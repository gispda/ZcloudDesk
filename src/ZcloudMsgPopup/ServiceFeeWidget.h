#ifndef SERVICEFEEWIDGET_H
#define SERVICEFEEWIDGET_H

#include <QWidget>
#include "ui_ServiceFeeWidget.h"
#include "qevent.h"
#include "MsgDataBase.h"
#include <QPushButton>
#include <map>
#include <QDateTime>
#include "NamePipeClinet.h"
class ServiceFeeWidget : public QWidget
{
	Q_OBJECT

public:
	ServiceFeeWidget(stMsgInfo msgInfo,QWidget *parent = 0);
	~ServiceFeeWidget();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:
	void onMsgBtnClick();
private:

	//!��ʼ������
	void init();

	//!������ť
	void analysisBtnArray(QByteArray byteJsonArray);

	//!����label��ʾ������...��β
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);

	std::map<QPushButton*, stMsgBtnInfo*>	m_mpBtnInfos;
	Ui::ServiceFeeWidget ui;
	stMsgInfo m_msgInfo;
	QDateTime		m_dtLast;
	NamePipeClinet*	m_pClient;
	QPoint dPos;
};

#endif // SERVICEFEEWIDGET_H
