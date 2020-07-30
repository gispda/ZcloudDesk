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

	//!ȫ����Ϣ
	void setAllMsg();

	//!�Ѷ���Ϣ
	void setReadMsg();

	//!δ����Ϣ
	void setUnreadMsg();

	//!��ʾ����
	void showWindow();

	//!����δ������
	void setUnreadMsgCount(int nUnread);

	//!��ָ����Ϣ
	void openAssignMsg(QString strMsgid);

	//!����δ������
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
	//!�������/��С�����
	void setStyle(bool bIsMax);

	//!��ʾlist�б�
	void showListItem(const vtrMsgInfo&	msgInfos);

	//!��ʾ��Ϣ����
	void showMsgList(int nType);

	//!ɾ�������б�
	void delListWidget();

	//!Ĭ����ʾָ���е���Ϣ����
	void showDetail(int nRow);

	//!������ť
	void analysisBtnArray(const stMsgInfo* pMsgInfo);

	//!�ͷ���Ϣ��ť��Դ
	void releaseBtnInfo();

	//!�����Ի���
	void createMsgWidget();

	//!��ʾͼƬ��Ϣ
	void showPicMsg(QString strPicPath);

	//!��ʾ��ͨ��Ϣ
	void showNorMsg(const QString& strMsgTitle, const int& nSendTime, const QString& strMsgContent);

	//!������Ϣ��Ӧ
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
