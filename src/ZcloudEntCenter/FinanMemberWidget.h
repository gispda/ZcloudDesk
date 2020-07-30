#pragma once

#include <QWidget>
#include "ui_FinanMemberWidget.h"
#include "ZcloudCommonWidget.h"

class FinanMemberWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	FinanMemberWidget(QString strUid, QString strToken,QWidget *parent = Q_NULLPTR);
	~FinanMemberWidget();

signals:
	void sigEditMemberSucessed(const QString&, const QString&);
protected:
	bool eventFilter(QObject *target, QEvent *e);
private slots:
	//!添加财务成员
	void onAddMember();

	//!添加财务成员成功
	void onAddMemberSucess();

	//!审核通过后刷新列表
	void onFreshFinanMember();

	//!移除成员
	void onRemoveMember(QString strUserId);

	//!编辑成员
	void onModifyMember(QString strTrueName, QString strJob,QString strUserId);

	//!编辑资料成功
	void onModifyMemberSucess(QString strTrueName, QString strJob, QString strCurUserId);

	//!移交管理员权限
	void onHandOver(QString strUserId);
private:
	//!显示财务成员信息
	bool showMemberInfo();

private:
	//!获取财务成员
	bool winHttpGetMemberInfo(QString strUid, QString strToken, QString& strRet);

	//!移交管理员权限
	bool winHttpHandOver(QString strUid, QString strToken, QString strUserId,QString& strRet);

	//!移除成员
	bool winHttpRemoveMember(QString strUid, QString strToken, QString strUserId, QString& strRet);

	Ui::FinanMemberWidget ui;
	QString m_strUid;
	QString	m_strToken;
};
