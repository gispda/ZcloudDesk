#ifndef MSGRIGHTWIDGET_H
#define MSGRIGHTWIDGET_H

#include <QWidget>
#include <QLocalSocket>
#include <QTimer>
#include "qevent.h"
#include "ui_MsgRightWidget.h"
#include "NamePipeClinet.h"
#include "MsgDataBase.h"

class MsgRightWidget : public QWidget
{
	Q_OBJECT

public:
	MsgRightWidget(stMsgInfo msgInfo,QWidget *parent = 0);
	~MsgRightWidget();

	//!��ʾ����
	void showWindow();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:
	void onCloseBtnClick();
	void onMoreBtnClick();

	//���رմ���
	void closeWindow();
	void widgetShow();
	void widgetClose();
private:
	//!��ʼ������
	void init();

	//!������ť
	void analysisBtnArray(QByteArray byteJsonArray);

	//!����label��ʾ������...��β
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);

	//!��������
	QRect	m_deskRect;
	QTimer* m_showTimer = NULL;
	QTimer* m_closeTimer = NULL;
	int		m_nCurHeight = 0;
	bool    m_bAutoClose = true;
	Ui::MsgRightWidget ui;
	QPoint dPos;

	//!��������
	NamePipeClinet*	m_pClient = NULL;
	stMsgInfo m_msgInfo;
	std::map<QPushButton*, stMsgBtnInfo*>	m_mpBtnInfos;	
};

#endif // MSGRIGHTWIDGET_H
