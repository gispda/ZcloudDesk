#ifndef SwitchAccNewWidget_H
#define SwitchAccNewWidget_H

#include <QWidget>
#include "ui_SwitchAccNewWidget.h"
#include "qevent.h"
#include "Database.h"
#include "ZcloudCommon.h"
#include "EntDataBase.h"

class SwitchAccNewWidget : public QWidget
{
	Q_OBJECT

public:
	SwitchAccNewWidget(UserInfoStruct* m_userInfo, EntCenterInfo* m_pEntInfo, QWidget *parent = 0);
	~SwitchAccNewWidget();

	//!客户经理邀请
	void CustomerManagerinvite();
	//!企业管理员邀请
	void EnterpriseManagerinvite();

signals:
	void sigSwitchAcc(int, bool, QString, QString);
	void sigJoinEnt(QString m_strTaxNum);
private slots:
void onTextChanged(const QString& strText);
void onSwitchAcc(int nLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd);
void onJoinEnt(QString m_strTaxNum);
protected:
	bool eventFilter(QObject *target, QEvent *e);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	//!获取当前用户所属所有企业
	bool winHttpGetCompanyList(QString strTaxno, QString strToken, QString& strRet);

	//!获取当前用户所属所有企业
	void getCompanyList();

	//!显示列表
	void showListWidget(QString strText);

	//!获取切换账号列表
	void getSwitchInfo();

	//!注册表税号已在数据库表中存在(表示曾经登录过，在数据库留下了信息)
	bool isTaxExistRegedit(QString strTaxNo);

	//!接口获取的数据已在数据库表中存在(表示曾经登录过，在数据库留下了信息)
	bool isTaxExistInterface(QString strUid, QString strCompId);

	void openCreateEntDlg();

	////!当前登录账号uid
	//QString m_strUid;
	//QString	m_strToken;
	////!当前登录公司id
	//QString	m_strCompId;
	//QString	m_strUserName;
	//QString	m_strMobile;


	Ui::SwitchAccNewWidget ui;
	QPoint dPos;

	UserInfoStruct* m_userInfo;
	EntCenterInfo* m_pEntInfo;
	vtrSwitchAccInfos m_vtrAccInfos;

};

#endif // SwitchAccNewWidget_H
