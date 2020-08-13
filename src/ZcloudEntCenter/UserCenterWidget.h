#ifndef UserCenterWidget_H
#define UserCenterWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_UserCenterWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"
#include "UserCenterMainWidget.h"
#include "UserCenterAccWidget.h"
#include "Database.h"


class UserCenterWidget : public QWidget
{
	Q_OBJECT

public:
	UserCenterWidget(EntCenterInfo*	entinfo,UserInfoStruct* _userInfo, QWidget *parent = 0);
	~UserCenterWidget();
	void init(EntCenterInfo*	entinfo,UserInfoStruct* info);

	void modifyCoinCount(int nCount);
signals:
	////!切换账号
	//void sigSwitchAcc(int, bool, QString, QString);

	////购买会员成功
	//void sendVipListSignals(QStringList, QStringList, QStringList);

	////修改用户名和职务
	//void trueNameJobChange(QString, QString);

	////绑定手机号
	//void bingdingPhoneSignal();

	////!绑定手机号成功
	//void sigSignBindingSucceeded( const QString &strMobile);

	////!打开签到中心
	//void openSignInWidget(QWidget*);

protected:
	bool eventFilter(QObject *target, QEvent *e);


private slots:
//!完善资料修改云币
void onChangeCoin(int nCoin);

void onShowAcc();

void onShowMain();


//	//!复制税号
//	void onCopyBtnClick();
//	//!账号切换
//	void onSwitchBtnClick();
//	//!财务成员
//	void onMemberBtnClick();
//	//!账号设置
//	void onAccSetBtnClick();
//	//!签到
//	void onSignInBtnClick();
//	//!企业资料
//	void onEntInfoBtnClick();
//	//!交易信息
//	void onTransInfoBtnClick();
//	//!企业会员
//	void onEntVipBtnClick();
//	//!服务费续费
//	void onServiceFeeBtnClick();
//	//!完善资料
//	void onCompeteDataBtnClick();
//	


//
//	//修改资料成功
//	void onEditUserInfoSucessed(const QString& strName, const QString& strJob);
//
//	//!购买会员成功
//	void changeVipSucessed(QStringList nameList, QStringList gradeList, QStringList vipTimerList);
//
private:
	//!查询企业信息
	bool winHttpGetCompanyInfo(QString strUid, QString strToken, QString& strRet);
	//!解析企业信息
	//bool analysisJson(const QString& strJson, EntCenterInfo& info);
	//!检测用户头像是否存在 存在返回路径 不存在下载之后返回路径
	QString checkLogoExist(QString strUrl);
//	//!设置文字超出以...结束显示
//	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);
//
//	//!查询企业信息
//	bool winHttpGetCompanyInfo(QString strUid,QString strToken,QString& strRet);
//
//
//	//!解析企业信息
//	bool analysisJson(const QString& strJson, EntCenterInfo& info);
//
//	//!检测用户头像是否存在 存在返回路径 不存在下载之后返回路径
//	QString checkLogoExist(QString strUrl);
//
//	//!解析会员
//	bool   analysisVip(QByteArray byteJsonArray);
//
//	//!显示头像及VIP标识
//	void showAvatar(QString strAvatarPath, bool bVip);
	/*QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;*/
	bool	m_isNetActive	= true;
	Ui::UserCenterWidget ui;

	//bool	m_bJoinEnt = true;
	//bool	m_bHasMember = true;
	QWidget* m_pUserDefult = NULL;
	//首页
	UserCenterMainWidget* mp_UserCenterMain = NULL;
	//账户信息
	UserCenterAccWidget* mp_UserCenterAcc = NULL;

	EntCenterInfo*	m_pEntinfo;
	UserInfoStruct* m_userInfo;
};

#endif // UserCenterWidget_H
