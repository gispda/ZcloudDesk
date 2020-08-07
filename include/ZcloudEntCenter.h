#ifndef ZCLOUDENTCENTER_H
#define ZCLOUDENTCENTER_H
#include <QObject>
#include <QtCore/qglobal.h>
#ifdef ZCLOUDENTCENTER_LIB
# define ZCLOUDENTCENTER_EXPORT Q_DECL_EXPORT
#else
# define ZCLOUDENTCENTER_EXPORT Q_DECL_IMPORT
#endif

class ZCLOUDENTCENTER_EXPORT ZcloudEntCenter:public QObject
{
	Q_OBJECT
public:
	//创建实例对象
	static ZcloudEntCenter * createNew();

	//!销毁对象
	virtual void destroy() = 0;
	//!新建企业
	virtual void createEntCenter(QString strUid, QString strToken) = 0;

	//!打开工单列表
	virtual void openWorkers(QString strUid, QString strToken) = 0;
	//!打开企业中心
	virtual void openEntCenter(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId,QString strUserName) = 0;

	//! 企业中心是否显示
	virtual bool isEntCenterShow()	=	0;

	//!打开会员中心
	virtual void openVipInfoCenter(QString strUid, QString strToken, bool bJoinEnt, bool bHasMember) = 0;

	//!打开服务费续费窗口
	virtual void openServiceFeeCenter(QString strUrl) = 0;
	//!关闭所有企业对话框
	virtual void closeAllEntWidget() = 0;

	//!签到成功修改云币数据
	virtual void modifyCoinCount(int nCount)	=	0;

	//设置用户信息
	virtual void setMobile(QString strMobile) = 0;
	virtual void setToken(QString strToken) = 0;

signals:
	void sigSwitchAcc(int, bool, QString, QString);
	void sendVipListSignals(QStringList, QStringList, QStringList);
	//修改用户资料
	void trueNameJobChange(QString trueName ,QString strJob);
	void bingdingPhoneSignal();

	//绑定手机号成功
	void sigSignBindingSucceeded(const QString &strMobile);
	//!打开签到中心
	void openSignInWidget(QWidget*);
};

#endif // ZCLOUDENTCENTER_H
