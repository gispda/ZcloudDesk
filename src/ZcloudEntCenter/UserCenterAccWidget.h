#ifndef UserCenterAccWidget_H
#define UserCenterAccWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_UserCenterAccWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"

class UserCenterAccWidget : public AppCommWidget
{
	Q_OBJECT

public:
	UserCenterAccWidget(EntCenterInfo*	entinfo, UserInfoStruct* info, QWidget *parent = 0);
	~UserCenterAccWidget();
	void onSetPwdSucessed(int nCoin, bool bPerfect);
	void onBindMobileSucessed(int nCoin, bool bPerfect);
	void onModifyUserInfoSucessed(int nCoin, bool bPerfect);

	
	void init(EntCenterInfo*	entinfo, UserInfoStruct* info);

	void modifyCoinCount(int nCount);
signals:
	void sigChangeCoin(int);
	void sigEditUserInfoSucessed(const QString&, const QString&);
	void sigBindMobileSucessed(const QString&);

	//绑定手机号
	void bingdingPhoneSignal();

	//!绑定手机号成功
	void sigSignBindingSucceeded( const QString &strMobile);

	//!打开签到中心
	void openSignInWidget(QWidget*);

protected:
	bool eventFilter(QObject *target, QEvent *e);


private slots:


	//!企业资料
	void onEntInfoBtnClick();
	
	


private:
	//!设置文字超出以...结束显示
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);




	//!检测用户头像是否存在 存在返回路径 不存在下载之后返回路径
	QString checkLogoExist(QString strUrl);


	//QString m_strUserName;
	//QString m_strUid;
	//QString m_strToken;
	//QString m_strTrueName;
	//QString m_strJob;
	//QString m_strMobile;
	//int		m_isLoginByTax;
	//QString m_strCompId;
	//bool	m_isNetActive	= true;
	//QPoint dPos;
	//bool	m_bJoinEnt = true;
	//bool	m_bHasMember = true;
	////QWidget* m_pUserDefult = NULL;

	Ui::UserCenterAccWidget ui;
	UserInfoStruct* m_userInfo;
};

#endif // UserCenterAccWidget_H
