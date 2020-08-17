#ifndef ZCLOUDDESK_H
#define ZCLOUDDESK_H
#include <QtWidgets/QMainWindow>
#include <qsystemtrayicon.h>
#include "ZcloudEntCenter.h"
#include "ui_ZcloudDesk.h"
#include "ZcloudBigData.h"
#include "ZcloudMsgCenter.h"
#include "PipeServerThread.h"
#include "ZhicloudApp.h"
#include "Database.h"
#include "zappmenubutton.h"
#include "CheckServiceThread.h"
#include "LoginTip.h"
#include <QWidget>
#include <QtGui>

class ZcloudDesk : public QMainWindow
{
	Q_OBJECT

public:

	ZcloudDesk(UserInfoStruct userInfoStruct, QWidget *parent = 0);
	~ZcloudDesk();

	//打开应用
	void openApp(QString strAppid);

	//!顶栏应用
	void openApp(AppDataInfo* pInfo, QString type = "_top_app");

	//!获取顶栏工具应用信息（名字、图标）
	bool getAppData(QString appId, QString &appName, QString &appIconPath);

	//获取位置
	QRect getWidgetRect(int i);

	QString loadJsbTax();
	ZcloudEntCenter* getEntCenter();
public:

	//读取注册表软件安装信息
	static bool readRegInfo(QString &verSion, QString taxNumber);

protected:
	bool eventFilter(QObject *target, QEvent *e);
	void keyPressEvent(QKeyEvent * e);
	void closeEvent(QCloseEvent *event);
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);

	bool showLoginTip();
signals:
	void startInitSignal(int);
	void applyLogin();
	private slots:


	void startDownAndUpdate(QString softUrl);
	///登陆的实际操作函数入口
	void doLogin();
	void openCreateEntDlg();
	void openWorkers();
	//隐藏按钮
	void hideWindow();
	//显示按钮
	void showWindow();
	//托盘操作函数
	void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

	//!签到修改云币数量
	void onModifyCoinCount(int nCount);

	//!插入金税宝检测提示切换税号  flag用于 隐藏 开票软件和重装开票
	void onSwitchTip(bool flag = true);

	//!打开签到中心
	void openSignInWidegt(QWidget* pParentWidget);

	//注册插拔事件
	void registerDevice();

	//!签到广告点击
	void  onAdvertisingClick(int nType, QString strTarget);

	//!接收消息弹窗信息
	void onReciveMsgPopUp(QString);

	//!开始初始化
	void startInitSlot(int flag);

	//!检测token过期
	void onCheckTokenFailed(int status);

	//结束线程
	void exitThread(int flag = 0);

	//显示等待框
	void showDlgWait(bool isShow, bool bBind = false);

	void onlyExitThread(UserInfoStruct& userInfo, QString strOldUserId, QString strNewUserId, QString strNewToken);

	//!启动初始化工作
	void startInitWork();

	//!登录成功后关闭所有对话框
	void closeAllWindows(int flag);

	//!resize所有窗口
	void resizeAllWidget();

	//!接收消息，改变未读消息条数
	void onChangeUnreadMsgNum(int nNum, bool bAdd);

	//!顶栏工具按钮点击
	void onTopToolClick();




	//!刷新消息红点提示未读条数
	void onReduceUnreadNum(int);

	//!打开应用中心
	void openAppCenterWidget();

	//!打开消息中心
	void openMsgCenterWidget();

	//!打开设置中心
	void openSettingCenterWidget();

	//!切换账号(是否税号登录 是否是直接打开登录页面 税号/登录名称 密码)
	void onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd);

	//!设置中心顶栏状态改变
	void onTopCheckChanged(bool bShow);

	//!设置中心右侧状态改变
	void onRightCheckChanged(bool bShow);

	//!设置中心工具状态改变
	void onToolCheckChanged(QString strToolId, bool bShow);

	//!退出
	void onLogout();

	//!重装开票切换税号
	void onChangeTax(QString strTaxNo, QString strMachine);

	//绑定手机号
	void bingdingPhoneSlot();

	//绑定成功
	void slotBindingSucceeded(UserInfoStruct& userInfo, const QString &strUserId, const QString &strMobile, const QString &strToken);

	//修改手机号
	void slotChangeMobile(const QString &strMobile);

	//新手引导
	void noviceSlot(bool flag = false);

	//购买会员成功
	void  buyMembershipSlot(QStringList vipNameList, QStringList vipIdList, QStringList vipTimeList);

private:
	//!客户经理邀请
	void CustomerManagerinvite();
	//!企业管理员邀请
	void EnterpriseManagerinvite();

	//!打开服务费续费窗口 
	void openServiceFee(QString strUrl);

	//!刷新消息未读提示
	void refreshMsgToolTip();

	//!结束释放资源
	void release();

	//!打开企业中心
	void openEntCenterWidget();




	void createEnterCenterMgr();

	QString queryTaxInfo();

	void InitEntCenter();




	//!打开壁纸
	void openWallpaperWidget(QString strUrl);

	//!打开活动中心
	void openActivityCenterWidget(QString strUrl);

	//!截图
	void openScreenShot();

	//!锁屏
	void lockScreen();

	//!搜索
	void openSearch();

	//!打开财税计算器
	void openTaxCalculatorWidget(QString strUrl);

	//!打开办税日历
	void openFiscalCalendarWidget(QString strUrl);

	//!打开会员中心
	void openVipCenterWidget();

	//!获取屏幕分辨率信息
	void getScreenInfo();

	//!获取顶栏工具
	void getTopTool();

	//!解析顶栏工具json
	void analysisTopTool(const QString& strJson, vtrAppDataInfos& topToolInfos);

	//!显示顶栏工具
	void showTopTool(const vtrAppDataInfos& topToolInfos);

	//!显示公司名字以及头像
	void showCompInfo();

	//!清除顶栏工具内存
	void clearTopTool();

	//!设置文字超出以...结束显示
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);



	LoginTip*               m_pLoginTip = NULL;
	ZhicloudApp *			m_zhicloudApp = NULL;
	ZcloudMsgCenter*		m_pMsgCenter = NULL;
	ZcloudEntCenter*		m_pEntCenter = NULL;
	ZcloudBigDataInterface*	m_pBigDataInterface = NULL;
	PipeServerThread*		m_pPipeServerThread = NULL;
	CheckServiceThread*		m_pCheckServiceThread = NULL;

	QSystemTrayIcon *system_tray = NULL;

	bool switchAcc = false;

	//!当前分辨率可用宽度
	int						m_nAvailableWidth = 0;
	//!当前分辨率可用高度
	int						m_nAvailableHeight = 0;

	//!登录信息结构体
	UserInfoStruct			m_stUserInfo;

	Ui::ZcloudDesk			ui;

	//!消息未读条数
	int						m_nUnreadCount = 0;

	std::map<QPushButton*, AppDataInfo*>	m_mpTopToolBtnInfos;

	bool					m_bNeedUpdate = false;
	bool isIgnalClose = true;//是否忽略 close 标志位

	//!需要切换的税号
	QString				m_strSwitchTax = "";

	bool				m_bCheckToken = true;
};

#endif // ZCLOUDDESK_H
