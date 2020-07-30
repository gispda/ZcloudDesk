#ifndef ENTCENTERWIDGET_H
#define ENTCENTERWIDGET_H

#include <QWidget>
#include "qevent.h"
#include "ui_EntCenterWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"

class EntCenterWidget : public AppCommWidget
{
	Q_OBJECT

public:
	EntCenterWidget(QWidget *parent = 0);
	~EntCenterWidget();

	//!设置用户数据
	void setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId,QString strUserName);

	//!显示窗口
	void showWindow();

	//设置手机号
	void setMobile(QString mobile);
	void setToken(QString strToken);

	void modifyCoinCount(int nCount);
signals:
	//!切换账号
	void sigSwitchAcc(int, bool, QString, QString);

	//购买会员成功
	void sendVipListSignals(QStringList, QStringList, QStringList);

	//修改用户名和职务
	void trueNameJobChange(QString, QString);

	//绑定手机号
	void bingdingPhoneSignal();

	//!绑定手机号成功
	void sigSignBindingSucceeded( const QString &strMobile);

	//!打开签到中心
	void openSignInWidget(QWidget*);

protected:
	bool eventFilter(QObject *target, QEvent *e);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:
	//!复制税号
	void onCopyBtnClick();
	//!账号切换
	void onSwitchBtnClick();
	//!财务成员
	void onMemberBtnClick();
	//!账号设置
	void onAccSetBtnClick();
	//!签到
	void onSignInBtnClick();
	//!企业资料
	void onEntInfoBtnClick();
	//!交易信息
	void onTransInfoBtnClick();
	//!企业会员
	void onEntVipBtnClick();
	//!服务费续费
	void onServiceFeeBtnClick();
	//!完善资料
	void onCompeteDataBtnClick();
	
	//!完善资料修改云币
	void onChangeCoin(int nCoin);

	//修改资料成功
	void onEditUserInfoSucessed(const QString& strName, const QString& strJob);

	//!购买会员成功
	void changeVipSucessed(QStringList nameList, QStringList gradeList, QStringList vipTimerList);

private:
	//!设置文字超出以...结束显示
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);

	//!查询企业信息
	bool winHttpGetCompanyInfo(QString strUid,QString strToken,QString& strRet);

	//!初始化用户信息 
	void init();

	//!解析企业信息
	bool analysisJson(const QString& strJson, EntCenterInfo& info);

	//!检测用户头像是否存在 存在返回路径 不存在下载之后返回路径
	QString checkLogoExist(QString strUrl);

	//!解析会员
	bool   analysisVip(QByteArray byteJsonArray);

	//!显示头像及VIP标识
	void showAvatar(QString strAvatarPath, bool bVip);

	QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;
	bool	m_isNetActive	= true;
	Ui::EntCenterWidget ui;
	QPoint dPos;
	bool	m_bJoinEnt = true;
	bool	m_bHasMember = true;
	QWidget* m_pUserDefult = NULL;
};

#endif // ENTCENTERWIDGET_H
