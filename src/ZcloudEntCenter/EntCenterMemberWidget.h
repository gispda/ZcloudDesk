#ifndef EntCenterMemberWidget_H
#define EntCenterMemberWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_EntCenterMemberWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"
#include "Database.h"

class EntCenterMemberWidget : public QWidget
{
	Q_OBJECT

public:
	EntCenterMemberWidget(EntCenterInfo* pEntInfo, UserInfoStruct* userInfo, QWidget *parent = 0);

	void LoadEntInfo();

	~EntCenterMemberWidget();
	void init(EntCenterInfo*	info);

signals:
	void sigNeedLogin();
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
	void onModifyMember(QString strTrueName, QString strJob, QString strUserId);

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
	bool winHttpHandOver(QString strUid, QString strToken, QString strUserId, QString& strRet);

	//!移除成员
	bool winHttpRemoveMember(QString strUid, QString strToken, QString strUserId, QString& strRet);



	UserInfoStruct* m_userInfo;
	/*QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;
	bool	m_isNetActive	= true;*/

	Ui::EntCenterMemberWidget ui;
	
	/*bool	m_bJoinEnt = true;
	bool	m_bHasMember = true;*/
	//QWidget* m_pUserDefult = NULL;
	EntCenterInfo*	m_pInfo;


	////是否从后台拉回数据
	bool m_bIsloadDb;

};

#endif // EntCenterMemberWidget_H
