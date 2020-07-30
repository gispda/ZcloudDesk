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
	//!��Ӳ����Ա
	void onAddMember();

	//!��Ӳ����Ա�ɹ�
	void onAddMemberSucess();

	//!���ͨ����ˢ���б�
	void onFreshFinanMember();

	//!�Ƴ���Ա
	void onRemoveMember(QString strUserId);

	//!�༭��Ա
	void onModifyMember(QString strTrueName, QString strJob,QString strUserId);

	//!�༭���ϳɹ�
	void onModifyMemberSucess(QString strTrueName, QString strJob, QString strCurUserId);

	//!�ƽ�����ԱȨ��
	void onHandOver(QString strUserId);
private:
	//!��ʾ�����Ա��Ϣ
	bool showMemberInfo();

private:
	//!��ȡ�����Ա
	bool winHttpGetMemberInfo(QString strUid, QString strToken, QString& strRet);

	//!�ƽ�����ԱȨ��
	bool winHttpHandOver(QString strUid, QString strToken, QString strUserId,QString& strRet);

	//!�Ƴ���Ա
	bool winHttpRemoveMember(QString strUid, QString strToken, QString strUserId, QString& strRet);

	Ui::FinanMemberWidget ui;
	QString m_strUid;
	QString	m_strToken;
};
