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

	//!显示窗口
	void showWindow();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:
	void onCloseBtnClick();
	void onMoreBtnClick();

	//！关闭窗口
	void closeWindow();
	void widgetShow();
	void widgetClose();
private:
	//!初始化界面
	void init();

	//!解析按钮
	void analysisBtnArray(QByteArray byteJsonArray);

	//!设置label显示不完以...结尾
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);

	//!窗口设置
	QRect	m_deskRect;
	QTimer* m_showTimer = NULL;
	QTimer* m_closeTimer = NULL;
	int		m_nCurHeight = 0;
	bool    m_bAutoClose = true;
	Ui::MsgRightWidget ui;
	QPoint dPos;

	//!数据设置
	NamePipeClinet*	m_pClient = NULL;
	stMsgInfo m_msgInfo;
	std::map<QPushButton*, stMsgBtnInfo*>	m_mpBtnInfos;	
};

#endif // MSGRIGHTWIDGET_H
