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

	//��Ӧ��
	void openApp(QString strAppid);

	//!����Ӧ��
	void openApp(AppDataInfo* pInfo, QString type = "_top_app");

	//!��ȡ��������Ӧ����Ϣ�����֡�ͼ�꣩
	bool getAppData(QString appId, QString &appName, QString &appIconPath);

	//��ȡλ��
	QRect getWidgetRect(int i);

	QString loadJsbTax();
	ZcloudEntCenter* getEntCenter();
public:

	//��ȡע��������װ��Ϣ
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
	///��½��ʵ�ʲ����������
	void doLogin();
	void openCreateEntDlg();
	void openWorkers();
	//���ذ�ť
	void hideWindow();
	//��ʾ��ť
	void showWindow();
	//���̲�������
	void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

	//!ǩ���޸��Ʊ�����
	void onModifyCoinCount(int nCount);

	//!�����˰�������ʾ�л�˰��  flag���� ���� ��Ʊ�������װ��Ʊ
	void onSwitchTip(bool flag = true);

	//!��ǩ������
	void openSignInWidegt(QWidget* pParentWidget);

	//ע�����¼�
	void registerDevice();

	//!ǩ�������
	void  onAdvertisingClick(int nType, QString strTarget);

	//!������Ϣ������Ϣ
	void onReciveMsgPopUp(QString);

	//!��ʼ��ʼ��
	void startInitSlot(int flag);

	//!���token����
	void onCheckTokenFailed(int status);

	//�����߳�
	void exitThread(int flag = 0);

	//��ʾ�ȴ���
	void showDlgWait(bool isShow, bool bBind = false);

	void onlyExitThread(UserInfoStruct& userInfo, QString strOldUserId, QString strNewUserId, QString strNewToken);

	//!������ʼ������
	void startInitWork();

	//!��¼�ɹ���ر����жԻ���
	void closeAllWindows(int flag);

	//!resize���д���
	void resizeAllWidget();

	//!������Ϣ���ı�δ����Ϣ����
	void onChangeUnreadMsgNum(int nNum, bool bAdd);

	//!�������߰�ť���
	void onTopToolClick();




	//!ˢ����Ϣ�����ʾδ������
	void onReduceUnreadNum(int);

	//!��Ӧ������
	void openAppCenterWidget();

	//!����Ϣ����
	void openMsgCenterWidget();

	//!����������
	void openSettingCenterWidget();

	//!�л��˺�(�Ƿ�˰�ŵ�¼ �Ƿ���ֱ�Ӵ򿪵�¼ҳ�� ˰��/��¼���� ����)
	void onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd);

	//!�������Ķ���״̬�ı�
	void onTopCheckChanged(bool bShow);

	//!���������Ҳ�״̬�ı�
	void onRightCheckChanged(bool bShow);

	//!�������Ĺ���״̬�ı�
	void onToolCheckChanged(QString strToolId, bool bShow);

	//!�˳�
	void onLogout();

	//!��װ��Ʊ�л�˰��
	void onChangeTax(QString strTaxNo, QString strMachine);

	//���ֻ���
	void bingdingPhoneSlot();

	//�󶨳ɹ�
	void slotBindingSucceeded(UserInfoStruct& userInfo, const QString &strUserId, const QString &strMobile, const QString &strToken);

	//�޸��ֻ���
	void slotChangeMobile(const QString &strMobile);

	//��������
	void noviceSlot(bool flag = false);

	//�����Ա�ɹ�
	void  buyMembershipSlot(QStringList vipNameList, QStringList vipIdList, QStringList vipTimeList);

private:
	//!�ͻ���������
	void CustomerManagerinvite();
	//!��ҵ����Ա����
	void EnterpriseManagerinvite();

	//!�򿪷�������Ѵ��� 
	void openServiceFee(QString strUrl);

	//!ˢ����Ϣδ����ʾ
	void refreshMsgToolTip();

	//!�����ͷ���Դ
	void release();

	//!����ҵ����
	void openEntCenterWidget();




	void createEnterCenterMgr();

	QString queryTaxInfo();

	void InitEntCenter();




	//!�򿪱�ֽ
	void openWallpaperWidget(QString strUrl);

	//!�򿪻����
	void openActivityCenterWidget(QString strUrl);

	//!��ͼ
	void openScreenShot();

	//!����
	void lockScreen();

	//!����
	void openSearch();

	//!�򿪲�˰������
	void openTaxCalculatorWidget(QString strUrl);

	//!�򿪰�˰����
	void openFiscalCalendarWidget(QString strUrl);

	//!�򿪻�Ա����
	void openVipCenterWidget();

	//!��ȡ��Ļ�ֱ�����Ϣ
	void getScreenInfo();

	//!��ȡ��������
	void getTopTool();

	//!������������json
	void analysisTopTool(const QString& strJson, vtrAppDataInfos& topToolInfos);

	//!��ʾ��������
	void showTopTool(const vtrAppDataInfos& topToolInfos);

	//!��ʾ��˾�����Լ�ͷ��
	void showCompInfo();

	//!������������ڴ�
	void clearTopTool();

	//!�������ֳ�����...������ʾ
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

	//!��ǰ�ֱ��ʿ��ÿ��
	int						m_nAvailableWidth = 0;
	//!��ǰ�ֱ��ʿ��ø߶�
	int						m_nAvailableHeight = 0;

	//!��¼��Ϣ�ṹ��
	UserInfoStruct			m_stUserInfo;

	Ui::ZcloudDesk			ui;

	//!��Ϣδ������
	int						m_nUnreadCount = 0;

	std::map<QPushButton*, AppDataInfo*>	m_mpTopToolBtnInfos;

	bool					m_bNeedUpdate = false;
	bool isIgnalClose = true;//�Ƿ���� close ��־λ

	//!��Ҫ�л���˰��
	QString				m_strSwitchTax = "";

	bool				m_bCheckToken = true;
};

#endif // ZCLOUDDESK_H
