#ifndef MSGCENTERWIDGET_H
#define MSGCENTERWIDGET_H

#include <QWidget>
#include <QWebView>
#include <QPaintEvent>
#include "qevent.h"
#include "ui_MsgCenterWidget.h"
#include <QStyledItemDelegate>
#include "MsgInfoDenfine.h"

class NoFocusFrameDelegate : public QStyledItemDelegate
{
	Q_OBJECT
public:
	explicit NoFocusFrameDelegate(QWidget *parent = 0);

	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class MsgCenterWidget : public QWidget
{
	Q_OBJECT

public:
	MsgCenterWidget(QWidget *parent = 0);
	~MsgCenterWidget();

	//!全部消息
	void setAllMsg();

	//!已读消息
	void setReadMsg();

	//!未读消息
	void setUnreadMsg();

	//!显示窗口
	void showWindow();

	//!设置未读条数
	void setUnreadMsgCount(int nUnread);

	//!打开指定消息
	void openAssignMsg(QString strMsgid);

	//!减少未读条数
	void reduceUnreadNum();

signals:
	void sigReduceUnreadNum(int nNum);
	void sigSendMessageRespone(QString);
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent * event);
	bool eventFilter(QObject *target, QEvent *e);
private slots:
	void onMaxBtn();
	void onClickItem(stMsgInfo* pMsgInfo,bool bRead);
	void onLinkClicked(const QUrl& url);
	void onCbxIndexChanged(int index);
	void onSliderChanged(int value);
	void onDeleteItem(QString strId);
	void onMsgBtnClick();
	void onReduceUnreadNum();
	void onCommitStatue();
	void onMsgFormClose();
	void onScrollRequested(int, int, const QRect &);
private:
	//!设置最大化/最小化风格
	void setStyle(bool bIsMax);

	//!显示list列表
	void showListItem(const vtrMsgInfo&	msgInfos);

	//!显示消息数据
	void showMsgList(int nType);

	//!删除所有列表
	void delListWidget();

	//!默认显示指定行的消息详情
	void showDetail(int nRow);

	//!解析按钮
	void analysisBtnArray(const stMsgInfo* pMsgInfo);

	//!释放消息按钮资源
	void releaseBtnInfo();

	//!创建对话框
	void createMsgWidget();

	//!显示图片消息
	void showPicMsg(QString strPicPath);

	//!显示普通消息
	void showNorMsg(const QString& strMsgTitle, const int& nSendTime, const QString& strMsgContent);

	//!发送消息相应
	void sendMessageRespone(int nResType, QString strUid, QString strToken, QString strCompId,QString strMsgId, QString strBtnId, int nBtnType, QString strBtnTarget, bool bRead,bool bFromPopUp=false);

private:
	int					m_nUnreadCount = 0;
	bool				m_bIsMax	= false;
	QMutex				m_mutex;
	int					m_nType		= 0;
	Ui::MsgShadowWidget ui;
	std::map<QPushButton*, stMsgBtnInfo*>	m_mpBtnInfos;
	QPoint				dPos;
	QDateTime			m_dtLast;
	stMsgInfo*			m_pNowMsgInfo = NULL;
	QWidget*			m_pNoMsgWidget  = NULL;

	QWidget*			m_pPicMsgWidget = NULL;
	QLabel*				m_pLabelImage = NULL;
	QMovie*				m_pMovieImage = NULL;

	QWidget*			m_pNorMsgWidget = NULL;
	QLabel*				m_pMsgTitle = NULL;
	QLabel*				m_pMsgTime	= NULL;
	QLabel*				m_pSapce = NULL;
	QWebView*			m_pMsgWebView = NULL;

	bool				m_bUpdateScroll = false;
};

#endif // MSGCENTERWIDGET_H
