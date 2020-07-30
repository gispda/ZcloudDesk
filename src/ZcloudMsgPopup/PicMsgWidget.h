#pragma once
#include <QWidget>
#include "ui_PicMsgWidget.h"
#include "MsgDataBase.h"
#include "qevent.h"
#include <QLabel>
#include <QMovie>
#include <QPushButton>
#include <QDateTime>
#include "NamePipeClinet.h"
class PicMsgWidget : public QWidget
{
	Q_OBJECT

public:
	PicMsgWidget(stMsgInfo msgInfo,QWidget *parent = Q_NULLPTR);
	~PicMsgWidget();
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	bool eventFilter(QObject *target, QEvent *e);
private slots:
	void onCloseBtnClick();
	void onMsgBtnClick();
	void onCommitStatue();
	void onMsgFormClose();
private:
	//!初始化数据
	void init();

	//!解析按钮
	void analysisBtnArray(QByteArray byteJsonArray);

	QLabel*				m_pLabelImage	= NULL;
	stMsgInfo			m_msgInfo;
	NamePipeClinet*		m_pClient = NULL;
	QDateTime			m_dtLast;
	std::map<QPushButton*, stMsgBtnInfo*>	m_mpBtnInfos;
	Ui::PicMsgWidget	ui;
	QPoint dPos;
};
