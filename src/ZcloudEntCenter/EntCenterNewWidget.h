#ifndef EntCenterNewWidget_H
#define EntCenterNewWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_EntCenterNewWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"
#include "EntCenterMemberWidget.h"
#include "EntCenterInfoWidget.h"
#include "EntCenterMainWidget.h"
#include "Database.h"
#include "SwitchAccWidget.h"

class EntCenterNewWidget : public QWidget
{
	Q_OBJECT

public:
	EntCenterNewWidget(UserInfoStruct _userInfo,QWidget *parent = 0);
	~EntCenterNewWidget();

	void init(EntCenterInfo*	info);
	//!…Ë÷√”√ªß ˝æ›
	void setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId, QString strUserName);

protected:
	void showUserCompanyInfoTitle();
	void clearUserCompanyInfoTitle();
signals:
	//!«–ªª’À∫≈
	void sigSwitchAcc(int, bool, QString, QString);

protected:
	bool eventFilter(QObject *target, QEvent *e);


	private slots:
	void onShowInfo();
	void onShowMember();
	void onShowMain();
	//!∏¥÷∆À∞∫≈
	void onCopyBtnClick();
	//!’À∫≈«–ªª
	void onSwitchBtnClick();


	void onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd);
private:

	UserInfoStruct m_userInfo;
	QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;
	bool	m_isNetActive	= true;

	QString m_strLocalTaxno;
	Ui::EntCenterNewWidget ui;

	bool	m_bJoinEnt = true;
	bool	m_bHasMember = true;
	QWidget* m_pUserDefult = NULL;
	EntCenterMemberWidget* mp_EntCenterMember;
	EntCenterInfoWidget* mp_EntCenterInfo;
	EntCenterMainWidget* mp_EntCenterMain;

	SwitchAccWidget*	pWidget;
};

#endif // EntCenterNewWidget_H
