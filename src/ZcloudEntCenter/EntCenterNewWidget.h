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
	void showUserCompanyInfoTitle();
	void clearUserCompanyInfoTitle();

	///δ������ҵ��������ʾ
	void showUnaddCompanyInfoTitle(QString _strcompany, QString _strtaxno, QString _strUser, QString _straddcompany);

	///δ��ѯ����ҵ��������ʾ
	void showUnqueryCompanyInfoTitle();

	///������ҵ��������ʾ
	void showaddCompanyInfoTitle(QString _strcompany, QString _strtaxno, QString _strUser, QString _straroletype);

	

signals:
	//!�л��˺�
	void sigSwitchAcc(int, bool, QString, QString);

protected:
	bool eventFilter(QObject *target, QEvent *e);


	private slots:
	void onShowInfo();

	void JoinEntMoreStep();

	bool JoinStep2FinishEntinfo();

	bool DoapplyJoinEnt();

	void onShowMember();
	void onShowMain();
	//!����˰��
	void onCopyBtnClick();
	//!�˺��л�
	void onSwitchBtnClick();


	void onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd);

private:
	bool winHttpJoinEnt(QString strToken, QString strComId, QString& strRet);
	bool winHttpAppealJoinEnt(QString strToken, QString& strRet, QString& strMsg, int& stateCode);
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

	ZcloudComFun::dbEntInfo m_info;
	

	QString m_strLocalTaxno;
	Ui::EntCenterNewWidget ui;

	//bool	m_bJoinEnt = true;
	//bool	m_bHasMember = true;
	//QWidget* m_pUserDefult = NULL;

	////�Ƿ�Ӻ�̨��������
	bool m_bIsloadDb;


	EditEntInfoWidget* m_pEditEntinfo;
	JoinEntWidget*	m_pJoinEntWidget;
	EntCenterMemberWidget* mp_EntCenterMember;
	EntCenterInfoWidget* mp_EntCenterInfo;
	EntCenterMainWidget* mp_EntCenterMain;

	//SwitchAccWidget*	pWidget;

	SwitchAccNewWidget* pSwitchWidget;

	UserInfoStruct* m_userInfo;
	EntCenterInfo* m_pEntInfo;

	EntCenterInfo* m_pFinishEntInfo;
};

#endif // EntCenterNewWidget_H
