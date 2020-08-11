#ifndef EntCenterMemberWidget_H
#define EntCenterMemberWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_EntCenterMemberWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"

class EntCenterMemberWidget : public AppCommWidget
{
	Q_OBJECT

public:
	EntCenterMemberWidget(QWidget *parent = 0);
	~EntCenterMemberWidget();
	void init(EntCenterInfo*	info);

	//!�����û�����
	void setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId,QString strUserName);
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
	void onModifyMember(QString strTrueName, QString strJob, QString strUserId);

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
	bool winHttpHandOver(QString strUid, QString strToken, QString strUserId, QString& strRet);

	//!�Ƴ���Ա
	bool winHttpRemoveMember(QString strUid, QString strToken, QString strUserId, QString& strRet);


	QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;
	bool	m_isNetActive	= true;

	Ui::EntCenterMemberWidget ui;
	
	bool	m_bJoinEnt = true;
	bool	m_bHasMember = true;
	//QWidget* m_pUserDefult = NULL;
	EntCenterInfo*	m_pInfo;
};

#endif // EntCenterMemberWidget_H
