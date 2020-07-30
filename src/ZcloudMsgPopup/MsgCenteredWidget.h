#ifndef MSGCENTEREDWIDGET_H
#define MSGCENTEREDWIDGET_H

#include <QWidget>
#include "ui_MsgCenteredWidget.h"
#include "qevent.h"
#include "MsgDataBase.h"
#include <QWebView>
#include <QPushButton>
#include <map>
#include "NamePipeClinet.h"
class MsgCenteredWidget : public QWidget
{
	Q_OBJECT

public:
	MsgCenteredWidget(stMsgInfo msgInfo,QWidget *parent = 0);
	~MsgCenteredWidget();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent * event);
private slots:
	void onLinkClicked(const QUrl& url);
	void onMsgBtnClick();
	void onCommitStatue();
	void onMsgFormClose();
	void onScrollRequested(int, int, const QRect &);
private:
	//!初始化界面
	void init();

	//!解析按钮
	void analysisBtnArray(QByteArray byteJsonArray);

	//!数据设置
	NamePipeClinet*	m_pClient = NULL;

	std::map<QPushButton*, stMsgBtnInfo*>	m_mpBtnInfos;
	QWebView*				m_pWebView;
	Ui::MsgCenteredWidget	ui;
	QDateTime				m_dtLast;
	stMsgInfo				m_msgInfo;
	QPoint					dPos;
	bool					m_bUpdate = false;
};

#endif // MSGCENTEREDWIDGET_H
