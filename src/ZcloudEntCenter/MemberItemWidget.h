#pragma once

#include <QWidget>
#include "ui_MemberItemWidget.h"

class MemberItemWidget : public QWidget
{
	Q_OBJECT

public:
	MemberItemWidget(int nAdmin,int nIndex,QString strUid, QString strUserName, QString strTrueName, QString strJob, QString strMobile, int nRoleType,QWidget *parent = Q_NULLPTR);
	~MemberItemWidget();
signals:
	//!移除成员
	void sigRemoveMember(QString);
	//！编辑资料
	void sigModifyMember(QString, QString, QString);
	//！移交管理员权限
	void sigHandOver(QString);
private:
	Ui::MemberItemWidget ui;
	QMenu	*m_pMenu;
	QAction *m_pActionRemoveMember;
	QAction *m_pActionModifyMember;
	QAction *m_pActionHandOver;
	QString m_strUid;
	QString m_strTrueName;
	QString	m_strJob;
	
};
