#ifndef EntCenterMainWidget_H
#define EntCenterMainWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_EntCenterMainWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"

class EntCenterMainWidget : public AppCommWidget
{
	Q_OBJECT

public:
	EntCenterMainWidget(EntCenterInfo* pEntInfo, UserInfoStruct* m_userinfo, QWidget *parent = 0);
	~EntCenterMainWidget();

	
	//!初始化用户信息 
	void init(EntCenterInfo*	info, UserInfoStruct* userinfo);
	
signals:
	

	//绑定手机号
	void bingdingPhoneSignal();

	//!绑定手机号成功
	void sigSignBindingSucceeded( const QString &strMobile);


protected:
	bool eventFilter(QObject *target, QEvent *e);


private slots:


//!服务费续费
void onServiceFeeBtnClick();
	
	


private:




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
	Ui::EntCenterMainWidget ui;
	
	//bool	m_bJoinEnt = true;
	//bool	m_bHasMember = true;
	//QWidget* m_pUserDefult = NULL;

	UserInfoStruct* m_userinfo;
	EntCenterInfo*	m_pInfo;

};

#endif // EntCenterMainWidget_H
