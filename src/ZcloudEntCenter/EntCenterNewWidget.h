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
#include "JoinEntWidget.h"
#include "ZcloudCommon.h"
#include "EditEntInfoWidget.h"
#include "SwitchAccNewWidget.h"



class EntCenterNewWidget : public QWidget
{
	Q_OBJECT

public:
	EntCenterNewWidget(EntCenterInfo* pEntInfo, UserInfoStruct* userInfo, QWidget *parent = 0);
	~EntCenterNewWidget();

	void init(EntCenterInfo*	info);


protected:
	void showUserCompanyInfoTitle(EntCenterInfo*	info);
	void clearUserCompanyInfoTitle();

	///未加入企业的左面显示
	void showUnaddCompanyInfoTitle(QString _strcompany, QString _strtaxno, QString _strUser, QString _straddcompany);

	///未查询到企业的左面显示
	void showUnqueryCompanyInfoTitle();

	///加入企业的左面显示
	void showaddCompanyInfoTitle(QString _strcompany, QString _strtaxno, QString _strUser, QString _straroletype);

	

signals:
	//!切换账号
	void sigSwitchAcc(int, bool, QString, QString);

protected:
	bool eventFilter(QObject *target, QEvent *e);


	private slots:

	bool onJoinEnt(QString strCompanyid);

	void onShowInfo();

	void JoinEntMoreStep(EntCenterInfo* m_pEntInfo);

	void DoJoinEntMoreStep(EntCenterInfo* m_pEntInfo,bool isbinding);

	void DoAppealEnt(EntCenterInfo* m_pEntInfo);

	bool JoinStep2AppealGetEntInfo(EntCenterInfo* m_pEntInfo_old, EntCenterInfo* m_pFinishEntInfo);

	bool JoinStep2FinishEntinfo(EntCenterInfo* m_pEntInfo, EntCenterInfo* m_pFinishEntInfo);

	bool DoapplyJoinEnt(QString strCompanyid,int& stcode);

	////判断是否加入企业
	bool decideJoinEnt();
	void onShowMember();
	void onShowMain();
	//!复制税号
	void onCopyBtnClick();
	//!账号切换
	void onSwitchBtnClick();
	//!账号切换
	void SwitchBtnClick(EntCenterInfo*	info);


	void onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd);

private:
	bool winHttpJoinEnt(QString strToken, QString strComId, QString& strRet);
	bool winHttpAppealJoinEnt(EntCenterInfo* m_pFinishEntInfo, QString strToken, QString& strRet, QString& strMsg, int& stateCode);
private:


	/*QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;

	QString m_strCompany;
	QString m_strCompId;
	bool	m_isNetActive	= true;

	bool m_bjoin;*/

	

	QString m_strLocalTaxno;
	Ui::EntCenterNewWidget ui;

	//bool	m_bJoinEnt = true;
	//bool	m_bHasMember = true;
	//QWidget* m_pUserDefult = NULL;

	////是否从后台拉回数据
	bool m_bIsloadDb;


	EditEntInfoWidget* m_pEditEntinfo;
	JoinEntWidget*	m_pJoinEntWidget;
	EntCenterMemberWidget* mp_EntCenterMember;
	EntCenterInfoWidget* mp_EntCenterInfo;
	EntCenterMainWidget* mp_EntCenterMain;

	//SwitchAccWidget*	pWidget;

	SwitchAccNewWidget* pSwitchWidget;

	UserInfoStruct* m_userInfo;

	ZcloudComFun::dbEntInfo m_info;
	EntCenterInfo* m_pEnt;
	//EntCenterInfo* m_pEntInfo;

	//EntCenterInfo* m_pFinishEntInfo;
};

#endif // EntCenterNewWidget_H
