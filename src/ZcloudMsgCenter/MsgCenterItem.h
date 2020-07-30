#ifndef MSGCENTERITEM_H
#define MSGCENTERITEM_H

#include <QWidget>
#include <QListWidgetItem>
#include "ui_MsgCenterItem.h"
#include "MsgInfoDenfine.h"
#include <QLabel>
class MsgCenterItem : public QWidget
{
	Q_OBJECT

public:
	MsgCenterItem(stMsgInfo* pMsgInfo, QListWidgetItem* pListWidgetItem,QWidget *parent = 0);
	~MsgCenterItem();

	QListWidgetItem* getListItem();
	QString		getMsgId();
	void clickItem();
signals:
	void sigClickItem(stMsgInfo* pMsgInfo,bool bRead);
	void sigDeleteItem(QString strId);
	void sigReduceUnreadNum();
protected:
	bool eventFilter(QObject *target, QEvent *e);
private slots:
	void onDeleteBtnClick();
private:
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);

	void setIcon();

	stMsgInfo*	m_pMsgInfo = NULL;
	QListWidgetItem* m_pListWidgetItem = NULL;
	Ui::MsgCenterItem ui;
};

#endif // MSGCENTERITEM_H
