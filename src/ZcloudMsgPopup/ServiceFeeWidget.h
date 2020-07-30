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

	//!初始化界面
	void init();

	//!解析按钮
	void analysisBtnArray(QByteArray byteJsonArray);

	//!设置label显示不完以...结尾
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);

	std::map<QPushButton*, stMsgBtnInfo*>	m_mpBtnInfos;
	Ui::ServiceFeeWidget ui;
	stMsgInfo m_msgInfo;
	QDateTime		m_dtLast;
	NamePipeClinet*	m_pClient;
	QPoint dPos;
};

#endif // SERVICEFEEWIDGET_H
