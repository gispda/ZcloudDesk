#ifndef ZCLOUDENTCENTERIMPL_H
#define ZCLOUDENTCENTERIMPL_H
#include <QObject>
#include "ZcloudEntCenter.h"
#include "EntCenterWidget.h"
#include "VipInfoWidget.h"
#include "InfoCenterWidget.h"
class ZcloudEntCenterImpl : public ZcloudEntCenter
{
	Q_OBJECT

public:
	ZcloudEntCenterImpl();
	~ZcloudEntCenterImpl();


	virtual void setUserInfo(UserInfoStruct _userInfo);

	//!设置用户数据
	void setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId, QString strUserName) ;

	//!销毁对象
	virtual void destroy();
	//!新建企业
	virtual void createEntCenter(QString strUid, QString strToken);
	//!打开工单列表
	virtual void openWorkers(QString strUid, QString strToken);

	//!打开企业中心
	virtual void openEntCenter(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId, QString strUserName);

	void getInfoCenterWidget()
	{
		if (NULL == m_pInfoCenterWidget)
		{
			m_pInfoCenterWidget = new InfoCenterWidget(&m_userInfo);

			connect(m_pInfoCenterWidget, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));
			//connect(this, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));
		}
	}

	//! 企业中心是否显示
	virtual bool isEntCenterShow();

	//设置手机号
	virtual void setMobile(QString mobile);
	virtual void setToken(QString strToken);

	//!打开会员中心
	virtual void openVipInfoCenter(QString strUid, QString strToken, bool bJoinEnt, bool bHasMember);

	//!打开服务费续费窗口
	virtual void openServiceFeeCenter(QString strUrl);

	//!关闭所有企业对话框
	virtual void closeAllEntWidget();

	//!签到成功修改云币数据
	virtual void modifyCoinCount(int nCount);
public:
signals :

	void sigSwitchAcc(int, bool, QString, QString);
public
slots:
	void onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd);

private:
	EntCenterWidget*		m_pEntCenterWidget = NULL;
	InfoCenterWidget*		m_pInfoCenterWidget = NULL;
	VipInfoWidget*			m_pVipInfoWidget = NULL;

	UserInfoStruct m_userInfo;
	QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;
	bool	m_isNetActive = true;
};
#endif // ZCLOUDENTCENTERIMPL_H
