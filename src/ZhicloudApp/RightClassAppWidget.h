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
	int enumStatus = -1; //-1 ��������   0 �˳�  1����
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
	//Ӧ���Ƿ�����
	bool m_appsWidgetIsHid = false;
	int		m_appShowWidth;//��Ҫ��ʾ�Ŀ��
	int    m_lefitWidth = 0; //��߿յĿ��
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
	int		m_nCurWidth; //��ǰ��ʾ�Ŀ��

	int btnRow; //����
	int btnLine;//����
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
	

	//��Ӧ��
	bool openApp(QString  appId);
	//�˳��߳� ���˳�ʱ ������߳�
	void zhicoludExitThread(int flag = 0);
	//�����Զ�����
	bool setAutoDownload(AppDataInfo pData);
	static DownLoadManager * getDownLoadManager();
	//��ʼ��ʼ��
	void startInit();
	//!��Ӧ�����ĶԻ���
	void openAppCenterDlg(bool isShow = true);
	void setArrowLable();


	//���� ���ط�ʽ
	void setWidgetHind(bool hindClass, bool isHind);

	//��ǰʱ���
	int m_currentTime = 0;
signals:
	void changeTaxSignals(QString strTaxNo, QString strMachine);
	//���ֻ���
	void bindingPhoneSignals();
	//�����Ա�ɹ�
	void buyVipListSignals(QStringList, QStringList, QStringList);
	//�򿪻�Ա����
	//void openMemberCenter(QStringList);
	//����Ӧ��
	//void buyAppSignal(QString appId);
public slots:
	//��Ӧ��
	bool openApp(AppDataInfo pData, QString  Operand_id = "");
	void flushButton(QString classId = "", bool flushFlag = true);
	void installUnnstallSucessed(AppDataInfo pData);
private:
	RightClassAppWidget(QWidget *parent = NULL);
	~RightClassAppWidget();


	//�����߳�
	void exitThread();

	//���  �Ƿ���Ҫ�����߳�
	void clearClassButton(bool isCloaseAppCenter = false);
	
	void getScreenInfo();
	
	//������ж�ص�
	bool findClassAppRUninstall(QList<DragButton *> &appButtonList, QString classId);
	//��Ӧ�ô���
	void RightClassAppWidget::openAppError(AppDataInfo pData, QString  Operand_id );
	//Զ�̷��� invoice = 0 ,other = 1 , vip = 2
	void remoteServiceV(AppDataInfo pData, int ivo);
	//��ʾ�����ط���
	void hideFunc();
	void showFunc();
	//����Ӧ�� �͹���Ӧ��
	int buyApp(QString appId, bool isBuyApp);
	//�ж��Ƿ����
	bool determineAvailability(AppDataInfo pData, QString  Operand_id);

	AppCenterWidget *getAppCenterWidget()
	{
		return m_appCenterWidget;
	}

	//�ж������Ƿ���Ҫ����
	bool isPayApp(AppDataInfo pData);

	//�ж�Ӧ���Ƿ���Ҫ��Ա
	bool isMemberApp(AppDataInfo pData);

	//�ж������Ƿ��� ��isTryOut=true ���п��� isAastDurΪtrue
	bool isAastDueApp(AppDataInfo pData);

private slots:
	//��ʾ�����ط���
	void drawShow();
	void drawHide();
	void clickBtnOp(bool);
	//��ʼ���Ҳ�Ӧ��
	void initClass();
	void initClass(bool bremote);
	//���Ӧ��
	void clickbtn();
	//���Ĳ���
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
	//������
	bool m_haveHid = false;
	bool m_showActive = false; //���� ��ʾ ��־λ ��ֹ��ν�����ʾ
	bool m_hideActive = false;//���� ���� ��־λ ��ֹ��ν�������
	QTimer *m_classTimer = NULL;

	int m_classShowWidth = 0;//��ǰ�Ѿ���ʾ�� ���
	QStringList m_issueStringList; //δ�ϱ���Ӧ��

	//���ڹ������� �� ж���߳�
	static DownLoadManager *m_DownLoadManager;
	static RightClassAppWidget * m_RightAppsWidget;
	QVector<ZAppMenuButton*> classBtnVector;
	ZAppMenuButton*	 m_tButton = NULL;
	//QMutex rightMutex;
	QMutex mutexCLicke;
	volatile bool rightMFLag = false;
	QWidget *m_classWidget = NULL;
	RightAppsWidget *m_appWidgt;

	//!��ʼ��Ӧ���߳�
	InitDeskThread *m_initDeskThread = NULL;
	//FindAppPath*	m_findAppPath = NULL;

	QLabel *arrowLable = NULL;
	//Ӧ������
	AppCenterWidget *m_appCenterWidget = NULL;
	//!��ǰ�ֱ��ʿ��ÿ��
	int		m_nAvailableWidth = 0;;
	//!��ǰ�ֱ��ʿ��ø߶�
	int		m_nAvailableHeight = 0;
	//!��߱�
	float   m_AspectRatios = 0.0f;
	//!�ֱ��ʱ仯���ȱ�
	float	m_nWidthScan = 0.0f;
	//!�ֱ��ʱ仯��߶ȱ�
	float	m_nHeightScan = 0.0f;

	//�仯ǰ�߶�
	int		m_nHeight;

	//�仯ǰ���
	int		m_nWidth;
	
	QPixmap m_pixmap;
	//�ı�ֱ��ʺ�� ��Ȳ�ֵ
	int nWnumBer = 0;

};
