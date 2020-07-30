#pragma once
#ifdef ZCLOUDCOMMON_LIB
# define JSINTERFACE_EXPORT Q_DECL_EXPORT
#else
# define JSINTERFACE_EXPORT Q_DECL_IMPORT
#endif

#include <QObject>

class JSINTERFACE_EXPORT JsInterface : public QObject
{
	Q_OBJECT

public:
	static JsInterface *GetInstance();
	static void DestoryInstance();
	void changeUserIdtoken(const QString strUserId, const QString strToken);
public slots:
	//!账号设置成功，刷新名称、职务、新密码(平台不提供， 如果时密码登录 下一次用token登录)
	void accountSetSucessed(const QString& strName, const QString& strJob);

	//!会员购买后权益列表
	void getVipList(const QString& strJson);

	//绑定手机号
	void slotBindingPhone();

	//!签到成功
	void signInSucessed(bool bSucessed,int );

	//!获取壁纸下载链接
	void wallpaperDownload(const QString& strDownloadLink);

	//修改企业资料 已完成
	void enterpriseDataSucessed(bool,int);

	//!打开支付协议
	void slotOpenDefaultWeb(const QString&);

	//!绑定手机号成功
	void slotBindingSucceeded( const QString &strMobile);

	//!提交表单成功
	void commitStatue(bool);

	
signals:
	//修改该资料
	void sigAccountSetSucessed(const QString& strName, const QString& strJob);
	//购买会员
	void sigGetVipList(const QString& strJson);
	//绑定手机号
	void signalBindingPhone();
	//签到
	void sigSignInSucessed(bool bSucessed,int);
	//修改壁纸
	void sigWallpaperDownloadLink(const QString& strDwownloadLink);
	//修改资料完成任务
	void sigSignCompeteSucessed(bool,int);

	//!绑定手机号成功
	void sigSignBindingSucceeded( const QString &strMobile);

	//!提交表单成功
	void sigCommitStatue(bool);

	//token、 或者userId变更
	void changeUserIdtokenSignal(const QString, const QString);
private:
	JsInterface(QObject *parent = 0);
	static JsInterface *m_Instance;
};
