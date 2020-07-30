#pragma once
#include <QWidget>
#include "ui_AuditMemberWidget.h"
#include "ZcloudCommonWidget.h"

class AuditOperWidget :public QWidget
{
	Q_OBJECT
public:
	AuditOperWidget(QString	strAuditId,QWidget *parent = Q_NULLPTR);
	~AuditOperWidget();
signals:
	void sigAuditOper(QString, int);
protected:
	bool eventFilter(QObject *target, QEvent *e);
private:
	QLabel*	m_pPass;
	QLabel*	m_pRefuse;
	QString	m_strAuditId;

};
class AuditMemberWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	AuditMemberWidget(QString strUid,QString strToken,QWidget *parent = Q_NULLPTR);
	~AuditMemberWidget();

signals:
	void sigRefreshFinanMember();

private slots:
	void onAuditOper(QString strAuditId, int state);
	
private:
	bool getAuditList(QString strUid, QString strToken);

	//!获取审核列表
	bool winHttpGetAuditList(QString strUid, QString strToken, QString& strRet);

	//!审核财务成员
	bool winHttpDoAudit(QString strUid, QString strToken, QString strAuditId, int state, QString& strRet);

	QString m_strUid;
	QString m_strToken;
	Ui::AuditMemberWidget ui;
};
