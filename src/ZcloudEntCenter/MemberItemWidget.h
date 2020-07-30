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
	//!�Ƴ���Ա
	void sigRemoveMember(QString);
	//���༭����
	void sigModifyMember(QString, QString, QString);
	//���ƽ�����ԱȨ��
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
