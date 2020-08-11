#ifndef UserCenterMainWidget_H
#define UserCenterMainWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_UserCenterMainWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"

class UserCenterMainWidget : public AppCommWidget
{
	Q_OBJECT

public:
	UserCenterMainWidget(QWidget *parent = 0);
	~UserCenterMainWidget();

	void init(EntCenterInfo*	info);
	//!设置用户数据
	void setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId,QString strUserName);
	void modifyCoinCount(int nCount);
signals:
	//!打开签到中心
	void openSignInWidget(QWidget*);
	//!绑定手机号成功
	void sigSignBindingSucceeded(const QString &strMobile);
protected:
	bool eventFilter(QObject *target, QEvent *e);


private slots:
	//!签到
	void onSignInBtnClick();	
	//!完善资料修改云币
	void onChangeCoin(int nCoin);

	////修改资料成功
	//void onEditUserInfoSucessed(const QString& strName, const QString& strJob);

	//!完善资料
	void onCompeteDataBtnClick();

private:
	//!设置文字超出以...结束显示
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);


	//!初始化用户信息 
	void init();


	//!检测用户头像是否存在 存在返回路径 不存在下载之后返回路径
	QString checkLogoExist(QString strUrl);


	QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;
	bool	m_isNetActive	= true;
	Ui::UserCenterMainWidget ui;
	QPoint dPos;
	bool	m_bJoinEnt = true;
	bool	m_bHasMember = true;
	QWidget* m_pUserDefult = NULL;

};

#endif // UserCenterMainWidget_H
