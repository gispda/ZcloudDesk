#pragma once

#include <QWidget>
#include <QThread>
#include "ZhicloudAppDataDefine.h"
#include "publicWidgets/zappmenubutton.h"
#include "AppCommWidget.h"
#include "publicWidgets\drawbutton.h"
#include "AppCenter\AppCenterWidget.h"
#include "InitDeskThread.h"

class DownLoadManager;
class ReturnThread : public QThread
{
	Q_OBJECT

public:
	ReturnThread(QObject *parent = NULL);
	~ReturnThread();
	int enumStatus = -1; //-1 启动心跳   0 退出  1重启
private:
	void run();

signals:
	void threadReturn(int);

};

class RightAppsWidget : public QWidget
{
	Q_OBJECT

public:
	RightAppsWidget(QWidget *parent = NULL);
	~RightAppsWidget();
	//应用是否隐藏
	bool m_appsWidgetIsHid = false;
	int		m_appShowWidth;//需要显示的宽度
	int    m_lefitWidth = 0; //左边空的宽度
	void addAppButton(DragButton* btn);
	void setRowLine(int rowCont, int lineCont, int rightWidgetWidth, int fontSize);
	void clearAppsButton();
	void showAppsWidget();
	void hideAppsWidget();
	bool timerIsAction()
	{
		return m_appsTimer->isActive();
	};
	void stopAppsTimer()
	{
		if (m_appsTimer) m_appsTimer->stop();
	};

	void resetInterface();

private:
	QTimer *m_appsTimer = NULL;
	QVector<DragButton*> BtnVector;
	int		m_nCurWidth; //当前显示的宽度

	int btnRow; //行数
	int btnLine;//列数
	int buttonWidth;
	int fontSize;
protected:
	void focusOutEvent(QFocusEvent * e);
private:

private slots:
	
	void drawShowAppsSlot();
	void drawHideAppsSlot();

};


class RightClassAppWidget : public QWidget
{
	Q_OBJECT
	friend class RightAppsWidget;
	friend class AppParticularsDialog;
	friend class AppCenterTools;
	friend class ReturnThread;
	friend class ZhicloudApp;
	friend class AppCenterTools;
public:
	static RightClassAppWidget *GetInstance(QWidget *parent = NULL);
	

	//打开应用
	bool openApp(QString  appId);
	//退出线程 在退出时 需结束线程
	void zhicoludExitThread(int flag = 0);
	//设置自动下载
	bool setAutoDownload(AppDataInfo pData);
	static DownLoadManager * getDownLoadManager();
	//开始初始化
	void startInit();
	//!打开应用中心对话框
	void openAppCenterDlg(bool isShow = true);
	void setArrowLable();


	//设置 隐藏方式
	void setWidgetHind(bool hindClass, bool isHind);

	//当前时间戳
	int m_currentTime = 0;
signals:
	void changeTaxSignals(QString strTaxNo, QString strMachine);
	//绑定手机号
	void bindingPhoneSignals();
	//购买会员成功
	void buyVipListSignals(QStringList, QStringList, QStringList);
	//打开会员中心
	//void openMemberCenter(QStringList);
	//购买应用
	//void buyAppSignal(QString appId);
public slots:
	//打开应用
	bool openApp(AppDataInfo pData, QString  Operand_id = "");
	void flushButton(QString classId = "", bool flushFlag = true);
	void installUnnstallSucessed(AppDataInfo pData);
private:
	RightClassAppWidget(QWidget *parent = NULL);
	~RightClassAppWidget();


	//结束线程
	void exitThread();

	//清空  是否需要结束线程
	void clearClassButton(bool isCloaseAppCenter = false);
	
	void getScreenInfo();
	
	//查找已卸载得
	bool findClassAppRUninstall(QList<DragButton *> &appButtonList, QString classId);
	//打开应用错误
	void RightClassAppWidget::openAppError(AppDataInfo pData, QString  Operand_id );
	//远程服务 invoice = 0 ,other = 1 , vip = 2
	void remoteServiceV(AppDataInfo pData, int ivo);
	//显示和隐藏分类
	void hideFunc();
	void showFunc();
	//购买应用 和购买应用
	int buyApp(QString appId, bool isBuyApp);
	//判定是否可用
	bool determineAvailability(AppDataInfo pData, QString  Operand_id);

	AppCenterWidget *getAppCenterWidget()
	{
		return m_appCenterWidget;
	}

	//判定用用是否需要购买
	bool isPayApp(AppDataInfo pData);

	//判定应用是否需要会员
	bool isMemberApp(AppDataInfo pData);

	//判定试用是否到期 当isTryOut=true 才有可能 isAastDur为true
	bool isAastDueApp(AppDataInfo pData);

private slots:
	//显示和隐藏分类
	void drawShow();
	void drawHide();
	void clickBtnOp(bool);
	//初始化右侧应用
	void initClass();
	void initClass(bool bremote);
	//点击应用
	void clickbtn();
	//更改布局
	void resetInterface();
protected:
	void paintEvent(QPaintEvent * event);
	void enterEvent(QEvent *event);
	void leaveEvent(QEvent *event);
	bool eventFilter(QObject *obj, QEvent *event);
	void keyPressEvent(QKeyEvent * e);
	void closeEvent(QCloseEvent *event);
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private:
	//否隐藏
	bool m_haveHid = false;
	bool m_showActive = false; //正在 显示 标志位 防止多次进入显示
	bool m_hideActive = false;//正在 隐藏 标志位 防止多次进入隐藏
	QTimer *m_classTimer = NULL;

	int m_classShowWidth = 0;//当前已经显示的 宽度
	QStringList m_issueStringList; //未上报的应用

	//用于管理下载 和 卸载线程
	static DownLoadManager *m_DownLoadManager;
	static RightClassAppWidget * m_RightAppsWidget;
	QVector<ZAppMenuButton*> classBtnVector;
	ZAppMenuButton*	 m_tButton = NULL;
	//QMutex rightMutex;
	QMutex mutexCLicke;
	volatile bool rightMFLag = false;
	QWidget *m_classWidget = NULL;
	RightAppsWidget *m_appWidgt;

	//!初始化应用线程
	InitDeskThread *m_initDeskThread = NULL;
	//FindAppPath*	m_findAppPath = NULL;

	QLabel *arrowLable = NULL;
	//应用中心
	AppCenterWidget *m_appCenterWidget = NULL;
	//!当前分辨率可用宽度
	int		m_nAvailableWidth = 0;;
	//!当前分辨率可用高度
	int		m_nAvailableHeight = 0;
	//!宽高比
	float   m_AspectRatios = 0.0f;
	//!分辨率变化后宽度比
	float	m_nWidthScan = 0.0f;
	//!分辨率变化后高度比
	float	m_nHeightScan = 0.0f;

	//变化前高度
	int		m_nHeight;

	//变化前宽度
	int		m_nWidth;
	
	QPixmap m_pixmap;
	//改变分辨率后的 宽度差值
	int nWnumBer = 0;

};
