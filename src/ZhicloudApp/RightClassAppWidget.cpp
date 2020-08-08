#include "ZcloudCommon.h"
#include "RightClassAppWidget.h"
#include "AppDatabase\AppCenterDatabase.h"
#include "AppCenter/findregedit.h"
#include "DownloadFile\DownLoadManager.h"
#include "AppCommFun.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QFileInfo>
#include <QTimer>
#include <QDateTime>
#include "ZhicloudApp.h"
#include "dlgwait.h"
#include "AppWidget/QPayInvoiceDialog.h"
#include "AppWidget/QRemoteServiceDlg.h"
#include <QMetaType>
#include "DownloadFile/QDownloadSoftware.h"
#include "AppDatabase/AppCenterDatabase.h"
#include "AppHttpInterface.h"
#include "ZcloudBigData.h"
#include "BuyAppDialog.h"

const int g_rightWidgetWidth = 70;	//���ఴť�ĸ߶�
const int g_fontSize = 30;	//Ӧ������߶�
const int g_appRow = 6;	//һ��Ӧ�õĸ���
const int g_nRightWidth = 30;	//�ұ�  widget�Ŀ��
const int g_nullWidth = 20;  //����� Ӧ�õļ��
int SHOW_WIDGET_WIDTH = 2;//����Ԥ�����
extern QString g_strAppName;
extern UserInfoStruct app_userInfo;
RightClassAppWidget *RightClassAppWidget::m_RightAppsWidget = NULL;
DownLoadManager *RightClassAppWidget::m_DownLoadManager = NULL;


ReturnThread::ReturnThread(QObject *parent)
	: QThread(parent)
{

}

ReturnThread::~ReturnThread()
{

}

void ReturnThread::run()
{
	sleep(2);
	RightClassAppWidget *zhicloudDesk = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance());
	if (zhicloudDesk)
	{
		if (zhicloudDesk->m_initDeskThread->isRunning())
		{
			zhicloudDesk->m_initDeskThread->isRunningFlag = false;
			zhicloudDesk->m_initDeskThread->wait(-1);
		}

	}
	emit threadReturn(enumStatus);
	usleep(300);
}

//Ӧ�ÿ�
RightAppsWidget::RightAppsWidget(QWidget *parent)
	:QWidget(parent)
	, m_appsTimer(new QTimer(this))
{
	setAttribute(Qt::WA_TranslucentBackground, true);
	//setStyleSheet("outline: none");


}

RightAppsWidget::~RightAppsWidget()
{


}

//ʧȥ����
void RightAppsWidget::focusOutEvent(QFocusEvent * e)
{
	if (m_appsWidgetIsHid)
		hideAppsWidget();
	QWidget::focusOutEvent(e);
}


void RightAppsWidget::setRowLine(int rowCont, int lineCont, int rightWidgetWidth, int fontSize)
{
	this->btnRow = rowCont;
	this->btnLine = lineCont;
	this->buttonWidth = rightWidgetWidth;
	this->fontSize = fontSize;
	this->m_appShowWidth = lineCont * rightWidgetWidth;//��Ҫ��ʾ�Ŀ��
}

void RightAppsWidget::clearAppsButton()
{
	if (m_appsTimer->isActive())
	{
		m_appsTimer->disconnect();
		m_appsTimer->stop();
	}
	for (int i = 0; i < BtnVector.length(); ++i)
	{
		DragButton *dragButton = BtnVector[i];
		if (dragButton)
		{
			dragButton->hide();
			dragButton->disconnect();
			dragButton->setContextMenuPolicy(Qt::NoContextMenu);
			delete dragButton;
			dragButton = NULL;
		}
	}
	BtnVector.clear();
	update();
}



void RightAppsWidget::showAppsWidget()
{
	//if (m_appsTimer->isActive()) return false;
	m_nCurWidth = 0;
	m_appsTimer->disconnect();
	if (m_appsTimer->isActive()) m_appsTimer->stop();
	connect(m_appsTimer, SIGNAL(timeout()), this, SLOT(drawShowAppsSlot()));
	RightClassAppWidget *prR = qobject_cast<RightClassAppWidget *> (parentWidget());
	this->setGeometry(m_appShowWidth - m_nCurWidth + m_lefitWidth, 0, m_nCurWidth, this->height());
	if (prR)
	{
		prR->arrowLable->setPixmap(QPixmap(":/new/imageFile/arrowLeft.png"));
		prR->setArrowLable();
	}
	m_appsTimer->start(10);
}
void RightAppsWidget::drawShowAppsSlot()
{
	m_nCurWidth += 5;
	RightClassAppWidget *prR = qobject_cast<RightClassAppWidget *> (parentWidget());
	if (m_nCurWidth >= m_appShowWidth)
	{
		m_nCurWidth = m_appShowWidth;
		this->setFocus();
		if (prR)	{
			prR->setArrowLable();
		}
		m_appsTimer->disconnect();
		m_appsTimer->stop();
	}
	this->setGeometry(m_appShowWidth - m_nCurWidth + m_lefitWidth, 0, m_nCurWidth, this->height());
	update();
}



void RightAppsWidget::hideAppsWidget()
{
	m_nCurWidth = m_appShowWidth;
	m_appsTimer->disconnect();
	if (m_appsTimer->isActive()) m_appsTimer->stop();
	connect(m_appsTimer, SIGNAL(timeout()), this, SLOT(drawHideAppsSlot()));
	m_appsTimer->start(10);
	RightClassAppWidget *prR = qobject_cast<RightClassAppWidget *> (parentWidget());
	if (prR) 	{
		prR->arrowLable->setPixmap(QPixmap(":/new/imageFile/arrow.png"));
		prR->arrowLable->move(0, prR->arrowLable->y());
		prR->arrowLable->show();
	}
}

void RightAppsWidget::drawHideAppsSlot()
{
	RightClassAppWidget *prR = qobject_cast<RightClassAppWidget *> (parentWidget());
	m_nCurWidth -= 5;
	if (m_nCurWidth <= 0)
	{
		m_nCurWidth = 0;
		m_appsTimer->disconnect();
		m_appsTimer->stop();
		if (prR) 	prR->arrowLable->hide();
	}
	int appWidgtX = m_appShowWidth - m_nCurWidth + g_nullWidth + m_lefitWidth;
	this->setGeometry(appWidgtX, 0, m_nCurWidth, this->height());
	if (prR) prR->arrowLable->move(appWidgtX - 15, prR->arrowLable->y());
	show();
	qApp->processEvents(QEventLoop::AllEvents);
}

void RightAppsWidget::addAppButton(DragButton* btn)
{
	btn->setParent(this);
	BtnVector.push_back(btn);
	btn->show();
	resetInterface();
}

void RightAppsWidget::resetInterface()
{
	int widgetH = (buttonWidth + fontSize) * btnRow;

	for (int i = 0; i < BtnVector.length(); ++i)
	{
		for (int i = 0; i < BtnVector.length(); ++i)
		{
			BtnVector[i]->setGeometry(m_appShowWidth - (i / btnRow + 1)* (m_appShowWidth / btnLine), i % btnRow * (widgetH / btnRow),
				m_appShowWidth / btnLine, widgetH / btnRow);
		}
	}
	update();
	//qApp->processEvents(QEventLoop::AllEvents);
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RightClassAppWidget::RightClassAppWidget(QWidget *parent)
	: QWidget(parent)
	, m_initDeskThread(new InitDeskThread(this))
	//, m_findAppPath(new FindAppPath(this))
	, m_appWidgt(new RightAppsWidget(this))
	, m_classWidget(new QWidget(this))
	, arrowLable(new QLabel(this))
	, m_classTimer(new QTimer(this))
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowSystemMenuHint);// | Qt::WindowStaysOnTopHint );
	getScreenInfo();
	m_pixmap.load(":/new/imageFile/LeftBackImag.png");
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	this->setGeometry(m_nAvailableWidth - 120, 70, 120, m_nAvailableHeight - 70);
	m_classWidget->setFocusPolicy(Qt::NoFocus);
	m_classWidget->raise();
	arrowLable->hide();
	//��ʼ�� �����̣߳�  �����Ҫ��ʼ�� ���¶�ȡ���� Ӧ����Ϣ ֱ��  start
	connect(m_initDeskThread, SIGNAL(initDeskSuccess(bool)), this, SLOT(initClass()));//, Qt::QueuedConnection);
	connect(m_initDeskThread, SIGNAL(flashButton()), this, SLOT(flushButton()));
	//connect(m_findAppPath, SIGNAL(filishFindAppPathSignal()), this, SLOT(flushButton()));
	connect(QApplication::desktop(), &QDesktopWidget::workAreaResized, [this](int)
	{
		this->move(QApplication::desktop()->availableGeometry().width() - this->width(), 70);
	});
	//initClass();

	QTimer *timer = new QTimer(this);
	connect(timer, &QTimer::timeout, [this]()
	{
		m_currentTime += 5;
	});
	timer->start(5000);
}

RightClassAppWidget::~RightClassAppWidget()
{
	m_classWidget->deleteLater();
	arrowLable->deleteLater();
	if (m_appCenterWidget){
		m_appCenterWidget->deleteLater();
		m_appCenterWidget = NULL;
	}
	if (m_initDeskThread)
	{
		m_initDeskThread->deleteLater();
		m_initDeskThread = NULL;
	}
	//if (m_findAppPath)
	//{
	//	m_findAppPath->deleteLater();
	//	m_findAppPath = NULL;
	//}
}


void RightClassAppWidget::closeEvent(QCloseEvent *event)
{
	//event->ignore();
	return;
}

bool RightClassAppWidget::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
	if (eventType == "windows_generic_MSG" || eventType == "windows_dispatcher_MSG")
	{
		MSG *msg = (MSG *)message;
		if ((msg->message == WM_QUERYENDSESSION) && (msg->lParam != ENDSESSION_LOGOFF))
		{
			//isIgnalClose = false;
			//onLogout();
		}
		else if (msg->message == WM_KEYDOWN || msg->message == WM_SYSKEYDOWN)
		{
			if ((VK_F4 == msg->wParam) && (::GetKeyState(VK_MENU) & 0xF000))
			{
				return TRUE;
			}
		}
	}
	return QWidget::nativeEvent(eventType, message, result);
}


void RightClassAppWidget::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.drawPixmap(this->rect(), m_pixmap);
	//m_appWidgt->update();
	//m_classWidget->update();
	return QWidget::paintEvent(event);
}
bool RightClassAppWidget::eventFilter(QObject *obj, QEvent *event)
{
	//return true;
	return QWidget::eventFilter(obj, event);
}

void RightClassAppWidget::keyPressEvent(QKeyEvent * e)
{
	if (e->key() == Qt::Key_F4 && (e->modifiers() == Qt::AltModifier))
	{
		e->ignore();
		return;
	}
	return QWidget::keyPressEvent(e);
}

//���ڵĽ����¼�(enterEvent)
void RightClassAppWidget::enterEvent(QEvent *event)
{
	if (m_haveHid)
	{
		showFunc();
	}

	return QWidget::enterEvent(event);
}

//���ڵ��뿪�¼���leaveEvent��
void RightClassAppWidget::leaveEvent(QEvent *event)
{
	if (m_haveHid)
	{
		hideFunc();

	}
	return QWidget::leaveEvent(event);
}


void RightClassAppWidget::hideFunc()
{
	if (!m_hideActive)
	{
		bool bIsActive = m_classTimer->isActive();
		if (bIsActive)
		{
			m_classTimer->stop();
			//m_showActive = false;
			//m_hideActive = false;
		}
		//�������ʾ�� ������
		if (m_classShowWidth > SHOW_WIDGET_WIDTH || bIsActive)
		{
			m_hideActive = true;
			m_classShowWidth = this->width();
			m_classTimer->disconnect();
			connect(m_classTimer, SIGNAL(timeout()), this, SLOT(drawHide()));
			m_classTimer->start(10);
		}
	}
}
void RightClassAppWidget::showFunc()
{
	if (!m_showActive)
	{
		bool bIsActive = m_classTimer->isActive();
		if (bIsActive)
		{
			m_classTimer->stop();
			//m_showActive = false;
			//m_hideActive = false;
		}
		//��������صĲ���ʾ
		if (m_classShowWidth <= SHOW_WIDGET_WIDTH || bIsActive){
			m_showActive = true;
			m_classShowWidth = SHOW_WIDGET_WIDTH;
			m_classTimer->disconnect();
			connect(m_classTimer, SIGNAL(timeout()), this, SLOT(drawShow()));
			m_classTimer->start(10);
		}
	}
}

void RightClassAppWidget::drawShow()
{
	m_classShowWidth += 5;
	if (m_classShowWidth >= this->width())
	{
		m_showActive = false;
		m_hideActive = false;
		m_classTimer->stop();
		m_classShowWidth = this->width();
		move(QApplication::desktop()->availableGeometry().width() - m_classShowWidth, 70);
		show();
		update();
		//this->setFocus();

		//if (m_tButton)
		//	emit m_tButton->clicked(true);
		return;
	}
	move(QApplication::desktop()->availableGeometry().width() - m_classShowWidth, 70);
	update();
}

void RightClassAppWidget::drawHide()
{

	m_classShowWidth -= 5;
	if (m_classShowWidth <= SHOW_WIDGET_WIDTH)
	{
		m_showActive = false;
		m_hideActive = false;
		m_classTimer->stop();
		m_classShowWidth = SHOW_WIDGET_WIDTH;
	}
	move(QApplication::desktop()->availableGeometry().width() - m_classShowWidth, 70);
	update();
}



RightClassAppWidget * RightClassAppWidget::GetInstance(QWidget *parent)
{
	if (m_RightAppsWidget == NULL)
	{
		qRegisterMetaType<APPDOWNLOADETYPE>("APPDOWNLOADETYPE");
		qRegisterMetaType<AppDataInfo>("AppDataInfo");
		m_RightAppsWidget = new RightClassAppWidget(parent);
	}
	return m_RightAppsWidget;
}

DownLoadManager * RightClassAppWidget::getDownLoadManager()
{
	if (m_DownLoadManager == NULL)
	{
		m_DownLoadManager = new DownLoadManager();
	}
	return m_DownLoadManager;
}

bool RightClassAppWidget::setAutoDownload(AppDataInfo pData)
{
	if (!m_appCenterWidget)
	{
		openAppCenterDlg();
	}
	if (m_appCenterWidget)
	{
		m_appCenterWidget->setAutoDownload(pData);
		return true;
	}
	return false;
}

void RightClassAppWidget::startInit()
{
	//���Ӧ�����Ĳ�Ϊ�����³�ʼ��
	if (NULL != m_appCenterWidget)
	{
		//�л�˰��ʱ��
		m_appCenterWidget->closeCenterWidget();
		m_appCenterWidget->close();
		m_appCenterWidget->deleteLater();
		m_appCenterWidget = NULL;
	}
	exitThread();
	clearClassButton();
	m_appWidgt->clearAppsButton();
	if (m_initDeskThread)
	{
		m_initDeskThread->isRunningFlag = true;
		m_initDeskThread->start();
	}

}

void RightClassAppWidget::initClass()
{
	if (rightMFLag)
	{
		if (m_initDeskThread)
		{
			m_initDeskThread->is_flush_succeed = false;
		}
		return;
	}
	rightMFLag = true;
	m_issueStringList.clear();
	AppCenterDatabase::instance()->readSue(m_issueStringList);

	//��ʼ�� �����б�
	RightClassAppWidget::getDownLoadManager();

	clearClassButton();
	QList<AppClassInfo> appClassInfoList;
	if (!AppCenterDatabase::instance()->findAppClassList(appClassInfoList, CLASSDESK)) return;
	int nindex = 0;
	int buttonNumber = 0;
	foreach(AppClassInfo rightClassInfo, appClassInfoList)
	{
		QString strName = rightClassInfo.m_strClassName;
		ZAppMenuButton*	 pOpBtn = new ZAppMenuButton(rightClassInfo.m_strClassId, m_classWidget);
		pOpBtn->setFocusPolicy(Qt::NoFocus);
		classBtnVector.push_back(pOpBtn);
		pOpBtn->pIndex = nindex;
		pOpBtn->installEventFilter(this);
		connect(pOpBtn, SIGNAL(clicked(bool)), this, SLOT(clickBtnOp(bool)));

		int iLine = strName.length() / 6;
		switch (iLine)
		{
		case 0:
			break;
		default:
			strName = strName.left(5);
			pOpBtn->setToolTip(strName);
			break;
		}

		QString	strClassName = "\n";
		for (int i = 0; i < strName.length(); i++)
		{
			strClassName += strName[i];
			strClassName += "\n";
		}

		pOpBtn->setText(strClassName);
		pOpBtn->setStyleSheet(QString::fromLocal8Bit(
			"QPushButton{text-align:center center;color:rgb(255,255,255);border-radius:2px;font:15px\'΢���ź�\'75;"
			"border-image:url(:/new/imageFile/classInfo.png); }"
			"QPushButton:hover,pressed{border-image:url(:/new/imageFile/classInfo_hover.png);}"
			));
		if (nindex == 0)
		{
			m_tButton = pOpBtn;
		}
		pOpBtn->setGeometry(0, (100 + 10) * nindex, g_nRightWidth, 100);
		pOpBtn->show();
		nindex++;
	}

	//if (m_findAppPath)
	//{
	//	m_findAppPath->setUserId(app_userInfo.m_strUserId);
	//	m_findAppPath->start();
	//}
	this->show();
	rightMFLag = false;
	if (m_tButton) 
		emit m_tButton->clicked(true);
}

void RightClassAppWidget::initClass(bool bremote)
{
	rightMFLag = bremote;
	initClass();
}

void RightClassAppWidget::getScreenInfo()
{
	QDesktopWidget *deskWgt = QApplication::desktop();
	QRect availableRect = deskWgt->availableGeometry();
	m_nAvailableWidth = availableRect.width();
	m_nAvailableHeight = availableRect.height();

	m_AspectRatios = m_nAvailableWidth / (float)m_nAvailableHeight;
	m_nWidthScan = m_nAvailableWidth / (float)m_nWidth;
	m_nHeightScan = m_nAvailableHeight / (float)m_nHeight;
	//�������ڵĿ�Ⱥ͸߶�
	nWnumBer = m_nAvailableWidth - m_nWidth;
	m_nWidth = m_nAvailableWidth;
	m_nHeight = m_nAvailableHeight;
}

void RightClassAppWidget::resetInterface()
{
	static bool  fistFlag = true;
	QRect availableRect = QApplication::desktop()->availableGeometry();
	if (m_classWidget && m_appWidgt)
	{
		int x = availableRect.width() - m_appWidgt->m_appShowWidth - g_nRightWidth - g_nullWidth;
		int y = 70;
		int w = m_appWidgt->m_appShowWidth + g_nRightWidth + g_nullWidth;
		int h = QApplication::desktop()->availableGeometry().height() - y;
		int thisW = this->width();
		if (x < this->x())
		{
			thisW = w;
			int thisH = h - 270;
			if (thisH < 600) 
				thisH = 600;
			this->setGeometry(x, y, w, thisH);
		}
		m_appWidgt->m_lefitWidth = thisW - m_appWidgt->width() - g_nRightWidth - g_nullWidth;
		m_classWidget->setGeometry(thisW - g_nRightWidth, 0, g_nRightWidth, availableRect.height());
		m_classShowWidth = this->width();
		if (fistFlag)
		{
			setArrowLable();
			this->show();
			this->repaint();
			m_appWidgt->show();
			m_classWidget->show();
			qApp->processEvents(QEventLoop::AllEvents);
			//qApp->processEvents();
		}
		if (fistFlag && m_appWidgt->m_appsWidgetIsHid)
		{
			//��������ص� ��һ�� �Ͳ��ԡ�ʾ
		}
		else
		{
			m_appWidgt->showAppsWidget();
		}
	}
	update();
	if (fistFlag) fistFlag = false;
}

void RightClassAppWidget::exitThread()
{
	//�����߳�
	//QMutexLocker boollocker(&mutexCLicke);
	if (m_initDeskThread)
	{
		if (m_initDeskThread->isRunning())
		{
			m_initDeskThread->isRunningFlag = false;
			m_initDeskThread->quit();
			m_initDeskThread->wait(20 * 1000);
			if (m_initDeskThread->isRunning())
			{
				int i;
				qDebug() << "aaaaaaaa";
			}
		}
	}

	//if (m_findAppPath && m_findAppPath->isRunning())
	//{
	//	m_findAppPath->m_runReturn = true;
	//	m_findAppPath->wait(-1);
	//}
}

//���
void RightClassAppWidget::clearClassButton(bool isCloaseAppCenter)
{
	if (m_appWidgt)
	{
		m_appWidgt->clearAppsButton();
	}

	for (int i = 0; i < classBtnVector.length(); ++i)
	{
		ZAppMenuButton *zAppMenuButton = classBtnVector[i];
		if (zAppMenuButton)
		{
			zAppMenuButton->disconnect();
			zAppMenuButton->setContextMenuPolicy(Qt::NoContextMenu);
			zAppMenuButton->deleteLater();
			zAppMenuButton = NULL;
		}
	}
	m_tButton = NULL;
	classBtnVector.clear();
	if (m_appCenterWidget && isCloaseAppCenter)
	{
		//�ر�Ӧ������ �����߳�
		m_appCenterWidget->setContextMenuPolicy(Qt::NoContextMenu);
		m_appCenterWidget->closeCenterWidget();
		m_appCenterWidget->deleteLater();
		m_appCenterWidget = NULL;
	}
}

void RightClassAppWidget::clickBtnOp(bool checked)
{
	if (rightMFLag) return;
	rightMFLag = true;
	//if (m_appWidgt->timerIsAction())
	//	return;
	//QMutexLocker mutexLocker(&rightMutex);

	ZAppMenuButton*	btnop = qobject_cast<ZAppMenuButton*>(sender());
	if (NULL == btnop)
	{
		rightMFLag = false;
		return;
	}
	if (!checked) ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSA001", btnop->userData());
	bool  isSameButton = true;
	if (m_tButton)
	{
		m_tButton->setStyleSheet(QString::fromLocal8Bit(
			"QPushButton{text-align:center center;color:rgb(255,255,255);border-radius:2px;font:15px\'΢���ź�\'75;"
			"border-image:url(:/new/imageFile/classInfo.png); }"
			"QPushButton:hover{border-image:url(:/new/imageFile/classInfo_hover.png);}"
			"QPushButton:pressed{border-image:url(:/new/imageFile/classInfo_hover.png);};"
			));
		if (m_tButton != btnop)
		{
			m_tButton = btnop;
			isSameButton = false;
		}
		m_tButton->setStyleSheet(QString::fromLocal8Bit(
			"QPushButton{text-align:center center;color:rgb(255,255,255);border-radius:2px;font:15px\'΢���ź�\'75;"
			"border-image:url(:/new/imageFile/classInfo_hover.png); }"
			));
	}
	m_appWidgt->clearAppsButton();
	QList<DragButton *> appButtonList;

	if (findClassAppRUninstall(appButtonList, btnop->userData()))
	{
		int nSize = appButtonList.size();
		int appCounCont = (nSize - 1) / g_appRow + 1;
		m_appWidgt->setRowLine(g_appRow, appCounCont, g_rightWidgetWidth, g_fontSize);
		m_appWidgt->resize(m_appWidgt->m_appShowWidth, this->height());
	}
	else
	{
		m_appWidgt->setRowLine(g_appRow, 1, g_rightWidgetWidth, g_fontSize);
		m_appWidgt->resize(m_appWidgt->m_appShowWidth, this->height());
		qDebug() << "zcd-0x00000038:" << "findClassAppList Error";
	}
	//��ѯ���ݿ�ʧ�� ҲҪ��ʾwidget
	foreach(DragButton *btn, appButtonList)
	{
		m_appWidgt->addAppButton(btn);
	}
	//m_appWidgt->resetInterface();
	resetInterface();
	rightMFLag = false;
}

void RightClassAppWidget::setArrowLable()
{
	if (m_classWidget && arrowLable && m_tButton)
	{
		arrowLable->move(m_classWidget->x() - 10, m_tButton->y() + 40);
		arrowLable->show();
		arrowLable->raise();
		//this->repaint();
	}
}

bool RightClassAppWidget::findClassAppRUninstall(QList<DragButton *> &appButtonList, QString classId)
{
	//��ѯ�÷��������Ӧ��
	QList<AppDataInfo> appReadList;
	if (!AppCenterDatabase::instance()->findClassAppList(appReadList, classId))
	{
		qDebug() << "zcd-0x00000039:" << "findClassAppList Error";
		return false;
	}

	//��ȡ�����б�
	DownLoadManager*	pDownloadManager = RightClassAppWidget::getDownLoadManager();


	if (app_userInfo.m_strCompanyId != "")
	{
	
	 for each (AppDataInfo pData in appReadList)
	 {

		AppDownLoadThread *downloadThread = pDownloadManager->isRightManager(pData.m_strAppName, pData.m_strAppId);
		if (downloadThread != NULL)
		{
			//����
			pData.m_statusAppButton = downloadThread->getType();
		}
		if (pData.m_bAppIsInstall || (downloadThread != NULL && downloadThread->getType() != mapp_CLOSE))
		{
			DragButton *btn = new DragButton;
			btn->setFocusPolicy(Qt::NoFocus);
			btn->settUserData(pData);
			btn->setContextMenuPolicy(Qt::CustomContextMenu);
			QString strName;
			if (pData.m_strAppAlias.isEmpty())
			{
				strName = pData.m_strAppName;
			}
			else
			{
				strName = pData.m_strAppAlias;
			}
			btn->setToolTip(strName);
			if (strName.length() > 8)
			{
				strName = strName.left(7) + "...";
			}

			btn->setText(strName);
			btn->statusAppButton = pData.m_statusAppButton;

			QString icon = pData.m_strAppIconPath;
			QFileInfo fileInfo(icon);

			if (icon.isEmpty() || !fileInfo.exists())
			{
				icon = ":/new/imageFile/photoError.png";
			}
			btn->setPixmap(icon);

			btn->setStyleSheet("QToolButton{border-radius: 1px;color:rgb(255,255,255);}");
			connect(btn, SIGNAL(dragDoubleClicked()), this, SLOT(clickbtn()));
			connect(btn, SIGNAL(closeDownload(QString)), this, SLOT(flushButton(QString)));
			if (downloadThread != NULL && downloadThread->getType() != mapp_CLOSE)
			{
				connect(downloadThread, SIGNAL(signalDownloadProcess(qint64, qint64)), btn, SLOT(upDownloadProcess(qint64, qint64)));
				connect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), btn, SLOT(upStatusChanged(APPDOWNLOADETYPE)));
			}

			if (!pData.m_bAppType && !pData.m_strAppDownloadUrl.isEmpty() && !pData.m_strAppCurrentVerson.isEmpty())
			{
				//�����ǰ�汾Ϊ��  δ����
				bool isNewVerson = false;
				AppCommFun::isHaveNewVerson(pData, isNewVerson, false);
				if (!isNewVerson)
				{
					btn->m_isUpdate = true;
				}
			}

			appButtonList.append(btn);
		}
	 }
    }
	else
	{
		for each (AppDataInfo pData in appReadList)
		{
						


				DragButton *btn = new DragButton;
				btn->setFocusPolicy(Qt::NoFocus);
				btn->settUserData(pData);
				btn->setContextMenuPolicy(Qt::CustomContextMenu);
				QString strName;
				if (pData.m_strAppAlias.isEmpty())
				{
					strName = pData.m_strAppName;
				}
				else
				{
					strName = pData.m_strAppAlias;
				}
				btn->setToolTip(strName);
				if (strName.length() > 8)
				{
					strName = strName.left(7) + "...";
				}

				btn->setText(strName);
				btn->statusAppButton = pData.m_statusAppButton;

				QString icon = pData.m_strAppIconPath;
				QFileInfo fileInfo(icon);

				if (icon.isEmpty() || !fileInfo.exists())
				{
					icon = ":/new/imageFile/photoError.png";
				}
				btn->setPixmap(icon);

				btn->setStyleSheet("QToolButton{border-radius: 1px;color:rgb(255,255,255);}");
				connect(btn, SIGNAL(dragDoubleClicked()), this, SLOT(clickbtn()));
				connect(btn, SIGNAL(closeDownload(QString)), this, SLOT(flushButton(QString)));
				//if (downloadThread != NULL && downloadThread->getType() != mapp_CLOSE)
				//{
				//	connect(downloadThread, SIGNAL(signalDownloadProcess(qint64, qint64)), btn, SLOT(upDownloadProcess(qint64, qint64)));
				//	connect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), btn, SLOT(upStatusChanged(APPDOWNLOADETYPE)));
				//}

				if (!pData.m_bAppType && !pData.m_strAppDownloadUrl.isEmpty() && !pData.m_strAppCurrentVerson.isEmpty())
				{
					//�����ǰ�汾Ϊ��  δ����
					bool isNewVerson = false;
					AppCommFun::isHaveNewVerson(pData, isNewVerson, false);
					if (!isNewVerson)
					{
						btn->m_isUpdate = true;
					}
				
			
			   }
				appButtonList.append(btn);
		}


	}
	return true;
}

void RightClassAppWidget::clickbtn()
{
	QObject* aa = sender();
	if (aa == NULL)
	{
		return;
	}
	DragButton* bb = (DragButton*)aa;

	if (bb == NULL)
	{
		return;
	}
	AppDataInfo	pData = bb->userData();

	ZcloudBigDataInterface::GetInstance()->produceData("M01", "OP001", "TSA002",pData.m_strAppId + "-" + pData.mStrAppCateId);
	if (!pData.m_bAppIsInstall)
	{

		switch (bb->statusAppButton)
		{
		case mapp_DOWNLOADING:
		{
			DownLoadManager*	pDownloadManager = RightClassAppWidget::getDownLoadManager();
			AppDownLoadThread *downloadThread = pDownloadManager->isRightManager(pData.m_strAppName, pData.m_strAppId);
			if (downloadThread != NULL && downloadThread->getType() != mapp_PAUSE)
			{
				downloadThread->stopDownload();
				bb->statusAppButton = mapp_PAUSE;
			}
			break;
		}

		case mapp_FINISH:
			break;
		case mapp_INSTALLFINLSH:
			openApp(pData, "TSA002");
			break;
		case mapp_INSTALLERROR:
		case mapp_ERROR:
		{
			DownLoadManager*	pDownloadManager = RightClassAppWidget::getDownLoadManager();
			AppDownLoadThread *downloadThread = pDownloadManager->isRightManager(pData.m_strAppName, pData.m_strAppId);
			if (downloadThread != NULL && downloadThread->getType() != mapp_DOWNLOADING)
			{
				downloadThread->reDownload();
				bb->statusAppButton = mapp_DOWNLOADING;
			}
			break;
		}
		case mapp_TIMEOUTERROR:
		case mapp_PAUSE:
		{
			DownLoadManager*	pDownloadManager = RightClassAppWidget::getDownLoadManager();
			AppDownLoadThread *downloadThread = pDownloadManager->isRightManager(pData.m_strAppName, pData.m_strAppId);
			if (downloadThread != NULL && downloadThread->getType() != mapp_DOWNLOADING)
			{
				downloadThread->continueDownload();
				bb->statusAppButton = mapp_DOWNLOADING;
			}
			break;
		}
		case mapp_CLOSE:
			break;
		default:
			break;
		}
	}
	else if (pData.m_bAppIsInstall)
	{
		switch (bb->statusAppButton)
		{
		case mapp_DOWNLOADING:
		{
			DownLoadManager*	pDownloadManager = RightClassAppWidget::getDownLoadManager();
			AppDownLoadThread *downloadThread = pDownloadManager->isRightManager(pData.m_strAppName, pData.m_strAppId);
			if (downloadThread != NULL && downloadThread->getType() != mapp_PAUSE)
			{
				downloadThread->stopDownload();
				bb->statusAppButton = mapp_PAUSE;
			}
			break;
		}
		case mapp_FINISH:
			break;
		default:
		{
			openApp(pData, "TSA002");
			break;
		}
		}
	}
}

void RightClassAppWidget::installUnnstallSucessed(AppDataInfo pData)
{
	this->flushButton(pData.mStrAppCateId, false);
}

void RightClassAppWidget::flushButton(QString classId, bool flushFlag)
{
	if (m_tButton)
	{
		if (classId == m_tButton->userData() || flushFlag || classId.isEmpty())
		{
			emit m_tButton->clicked(true);
		}
	}
}

bool RightClassAppWidget::openApp(QString  appId)
{
	if (!appId.isEmpty())
	{
		AppDataInfo pData;
		pData.m_strAppId = appId;
		if (AppCenterDatabase::instance()->findApp(pData))
		{
			if (pData.m_bAppIsInstall)
			{
				openApp(pData);
				return true;
			}
			else{
				if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��Ӧ��δ��װ,�Ƿ�װ?")) == QDialog::Accepted)
				{
					setAutoDownload(pData);
					return true;
				}
			}
		}
	}
	return false;
}

//��ѯ��Ա���߸����Ƿ����� (��Ҫ��Ա && �������Ա) || ����Ҫ���� && ��Ա�ѵ���)

//�ж������Ƿ���Ҫ����
bool RightClassAppWidget::isPayApp(AppDataInfo pData)
{
	if (pData.m_enPaidTime.isEmpty() || pData.m_enPaidTime == "0" || (pData.m_enPaidTime.toInt() < m_currentTime))
	{
		return true;
	}
	return false;
}

//�ж�Ӧ���Ƿ���Ҫ��Ա
bool RightClassAppWidget::isMemberApp(AppDataInfo pData)
{
	QStringList strList = pData.m_strListAppVipList;
	bool needVip = false;
	for (int i = 0; i < strList.size() ; i++)
	{
		QString vipC = strList.at(i);
		if (app_userInfo.m_strListAppVipList.contains(vipC))
		{
			int count = app_userInfo.m_strListAppVipList.indexOf(vipC);
			if (count != -1)
			{
				QString endTime = app_userInfo.m_vipDateTimeList.at(count);
				if (endTime.toInt() > m_currentTime)
				{
					needVip = true;
					break;
				}
			}
		}
	}
	if (!needVip && strList.size() > 0)
	{
		return true;
	}

	return false;
}

//�ж������Ƿ��� ��isTryOut=true ���п��� isAastDurΪtrue
bool RightClassAppWidget::isAastDueApp(AppDataInfo pData)
{
	//�ж��Ƿ���
	if (pData.m_enExperienceTime.toInt() < m_currentTime)
	{
		return true;
	}
	return false;
}

bool RightClassAppWidget::determineAvailability(AppDataInfo pData, QString  Operand_id)
{
	//���������� �û������ ���ϱ� �Ѱ�װ
	if (m_issueStringList.contains(pData.m_strAppId))
	{
		m_issueStringList.removeOne(pData.m_strAppId);
		if (AppCenterDatabase::instance()->removeOneSue(pData.m_strAppId))
		{
			//�ϱ��Ѱ�װ
			AppCenterDatabase::instance()->appearApp(pData.m_strAppId, 1);
		}
	}
	QStringList strList = pData.m_strListAppVipList;
	//if (strList.contains("-1") || pData.m_strAppFree.contains("-1") || pData.m_enExperienceTime.contains("-1") || pData.m_experienceTime.contains("-1"))
	//{
	//	if (Operand_id != "_top_app")
	//		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��ʧ�ܣ����Ժ����ԣ�"));
	//	return false;
	//}
	//
	//������
	bool isTryOut = (!pData.m_experienceTime.isEmpty() && pData.m_experienceTime != "0");	
	//������ ��δ��ʼ����
	if (isTryOut && (pData.m_enExperienceTime.isEmpty() || pData.m_enExperienceTime == "0"))
	{
		//�����Ĳ�������ʾ ��Ϊ��Ҫ�������ݿ�
		if (Operand_id != "_top_app")
		{
			//��ʼ����  �޸����õ���ʱ��
			int experienceTime = m_currentTime + pData.m_experienceTime.toInt() * 24 * 60 * 60;
			pData.m_enExperienceTime = QString::number(experienceTime);
			if (AppCenterDatabase::instance()->updateAppPaidTime(pData.m_strAppId, experienceTime, false))
			{
				//ˢ���Ҳ�Ӧ��
				if (m_tButton)
					emit m_tButton->clicked(true);
				if (m_appCenterWidget)
					m_appCenterWidget->flushAppCenter();
				AppCenterDatabase::instance()->appearApp(pData.m_strAppId, 3);
			}
			else
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����ʧ�ܣ����Ժ����ԣ�"));
				return false;
			}
		}else
			return false;
	}
	//��ע��
	bool isBinding = pData.m_isBindingPhone;
	//�蹺��
	bool isPay = (pData.m_strAppFree.toFloat() != 0);// isPayApp(pData);
	bool isPayTimeOut = false;
	if (isPay) isPayTimeOut = isPayApp(pData);
	//���Ա
	bool isMember = (pData.m_strListAppVipList.size() > 0);// isMemberApp(pData);
	bool isMemberTimeOut = false;
	if (isMember) isMemberTimeOut = isMemberApp(pData);
	//�����ѹ���  ��isTryOut=true ���п��� isAastDurΪtrue
	bool isAastDue = false;
	if (isTryOut)	isAastDue = isAastDueApp(pData);

	if (isBinding && (isAastDue || !isTryOut))
	{
		//���Ѱ��ֻ���
		if (app_userInfo.m_strMobile.isEmpty())
		{
			//if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ʾ"),
			//	QString::fromLocal8Bit("���ֻ��ź�,��������%1���๦��").arg(g_strAppName))
			//	== QDialog::Accepted)
			//{
				emit bindingPhoneSignals();
			//}
			return false;
		}
	}
	if ((isAastDue || !isTryOut) && isMember && !isPay)
	{
		//��Ա���ڻ��ߵ�һ��ʹ��
		if (isMemberTimeOut)
		{
			//���ѹ����Ա
			int retrunExec = buyApp(pData.m_strAppId, false);
			//�ٴ��жϻ�Ա�ȼ� �п��ܹ���ɹ�����Ա�ȼ�����
			if (QDialog::Accepted == retrunExec)
			{
				if (isMemberApp(pData))
				{
					return false;
				}
			}
			if (3 != retrunExec && QDialog::Accepted != retrunExec)
			{
				return false;
			}
		}
	}
	if ((isAastDue || !isTryOut) && !isMember && isPay)
	{
		//Ӧ�ù��� ���һ��ʹ�� ��Ҫ����
		if (isPayTimeOut)
		{
			//���ѹ���Ӧ��
			if (/*ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ʾ"),
				QString::fromLocal8Bit("��Ӧ�÷����,�빺���Ƿ���̳�?"))
				!= QDialog::Accepted ||*/ !buyApp(pData.m_strAppId, true))
			{
				return false;
			}
		}
	}
	if ((isAastDue || !isTryOut) && isMember && isPay)
	{
		//����ͬʱ ���ڻ���û�����
		if (isMemberTimeOut && isPayTimeOut)
		{
			//���ѹ����Ա����Ӧ��
			int dRt = ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_BINDING, QString::fromLocal8Bit("��Ӧ��Ϊ�շ�Ӧ��"), QString::fromLocal8Bit("�����Ա�������ʹ��"),
				QString::fromLocal8Bit("�����Ա"), QString::fromLocal8Bit("����Ӧ��"));
			if (dRt == QDialog::Accepted)
			{
				if (!buyApp(pData.m_strAppId, false))
					return false;
			}
			else if (dRt == 3)
			{
				if (!buyApp(pData.m_strAppId, true))
					return false;
			}
			else
				return false;
		}
	}
	return true;
}


bool RightClassAppWidget::openApp(AppDataInfo pData, QString  Operand_id)
{
	if (!mutexCLicke.tryLock())
		return false;
	if (!determineAvailability(pData, Operand_id))
	{
		mutexCLicke.unlock();
		return false;
	}


	if ("TSA002" != Operand_id && m_appCenterWidget)
	{
	}
	else
	{

	}
	
	QString	vPath;
	if (pData.m_bAppType)
	{

		if (pData.m_strAppName == QString::fromLocal8Bit("˰�ط��������"))//��Ҫ��Ʊ  �� �����ɷ�  �϶�Ϊһ
		{
			PayInvoiceDialog payInvoiceDialog(app_userInfo.m_strTaxNumber, pData, this);
			payInvoiceDialog.exec();
			mutexCLicke.unlock();
			return true;
		}

		if (!pData.m_strAppParams.isEmpty())
		{
			vPath = pData.m_strAppDownloadUrl;
			vPath += pData.m_strAppParams;
			vPath.replace("amp;", "");
			vPath.replace("{taxcode}", app_userInfo.m_strTaxNumber);
			vPath.replace("{uid}", app_userInfo.m_strUserId);
			vPath.replace("{token}", app_userInfo.m_strToken);
			vPath.replace("{machine}", app_userInfo.m_strMachine);
		}
		else
		{
			vPath = pData.m_strAppDownloadUrl;
			vPath.replace("amp;", "");
			vPath.replace("{taxcode}", app_userInfo.m_strTaxNumber);
			vPath.replace("{uid}", app_userInfo.m_strUserId);
			vPath.replace("{token}", app_userInfo.m_strToken);
			vPath.replace("{machine}", app_userInfo.m_strMachine);
		}

		if (vPath != "")
		{
			QString strSoftName = pData.m_strAppName;

			if (pData.m_strAppName == QString::fromLocal8Bit("��Ʊ����ƽ̨"))
			{
				//if (CommSetInfo::GetInstance().bNextCloudGh)
				//{
				//	if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("Ϊ��ȷ����˰�˷�Ʊ��Ϣ�����ݰ�ȫ��\r\n�밲װ����˰���ܾ�˰������֤�飡")) == QDialog::Accepted)
				//	{
				//		QString filePath = "SoftWare\\cloudGh.exe";
				//		CsOpenReturnThread *csOpenReturnThread = new CsOpenReturnThread(filePath, pData.mStrAppCateId, pData.m_strAppId, pData.m_strAppCurrentVerson,   this);
				//		csOpenReturnThread->start();
				//		CommSetInfo::GetInstance()->setNextCloudGh();
				//	}
				//  mutexCLicke.unlock();
				//	return;
				//}
			}
			if (!pData.m_bAppIsDefaultWeb)
			{
				QStringList paramsList;
				paramsList << "" << pData.m_strAppId << pData.m_strAppName <<vPath << pData.m_strAppIconPath;
				CsOpenReturnThread *csOpenReturnThread = new CsOpenReturnThread(QApplication::applicationDirPath() + "/ZBrowser.exe ", pData.mStrAppCateId, pData.m_strAppId, pData.m_strAppCurrentVerson, this);
				csOpenReturnThread->setParams(paramsList);
				csOpenReturnThread->start();
				mutexCLicke.unlock();
				return true;
			}
			else
			{
				QDesktopServices::openUrl(QUrl::fromUserInput(vPath));
				mutexCLicke.unlock();
				return true;
			}
		}
		else
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ܼ������ߣ������ڴ���"));
			mutexCLicke.unlock();
			return true;
		}
	}
	else
	{
		//�������CSӦ��
		if (pData.m_strAppName == QString::fromLocal8Bit("��װ��Ʊ"))
		{
			//����ʽ�����ص�ַ
			pData.m_strAppOnLineVerson.clear();
			QString version = app_userInfo.m_strHzsId;
			pData.m_strAppDownloadUrl.clear();//�����̨ �����˵�ַ
			ZcloudComFun::getSoftwareData(pData.m_strAppDownloadUrl, version);
			if (!pData.m_strAppDownloadUrl.isEmpty())
			{
				QDownloadSoftware* pDownloadFile = new QDownloadSoftware(2, pData.m_strAppDownloadUrl, this);
				pDownloadFile->setModal(false);
				connect(pDownloadFile, SIGNAL(switchEinSignal(QString, QString)), this, SIGNAL(changeTaxSignals(QString, QString)));
				pDownloadFile->show();
			}
			else
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��ȡ��Ʊ���ʧ�ܣ����Ժ����ԣ�"));
				mutexCLicke.unlock();
				return false;
			}
			mutexCLicke.unlock();
			return true;
		}
		else if (pData.m_strAppName == QString::fromLocal8Bit("����֧��"))
		{
			QString	strArgs = " TaxNo:" + app_userInfo.m_strTaxNumber + " EntName:" + app_userInfo.m_strCompanyName;
			QString filePath = "SoftWare\\AisinoUnionPay\\AisinoUnionPay.exe ";
			CsOpenReturnThread *csOpenReturnThread = new CsOpenReturnThread(filePath, pData.mStrAppCateId, pData.m_strAppId, pData.m_strAppCurrentVerson, this);
			csOpenReturnThread->setParams(QStringList() << QString("TaxNo:" + app_userInfo.m_strTaxNumber) << QString("EntName:" + app_userInfo.m_strCompanyName));
			csOpenReturnThread->start();

			mutexCLicke.unlock();
			return true;
		}
		else if (pData.m_strAppName == QString::fromLocal8Bit("��ӡ����λ"))
		{
			//!��ӡ����λ
			QString filePath = "SoftWare\\PrintConfigEdit\\PrintConfigEdit.exe";
			CsOpenReturnThread *csOpenReturnThread = new CsOpenReturnThread(filePath, pData.mStrAppCateId, pData.m_strAppId, pData.m_strAppCurrentVerson, this);
			csOpenReturnThread->setParams(QStringList() << QString("print") << app_userInfo.m_strTaxNumber);
			csOpenReturnThread->start();
			mutexCLicke.unlock();
			return true;

		}
		else if (pData.m_strAppName == QString::fromLocal8Bit("ŵŵ�̳�"))
		{
			//��ŵŵ�̳�
			QString filePath = "SoftWare\\PrintConfigEdit\\PrintConfigEdit.exe";
			CsOpenReturnThread *csOpenReturnThread = new CsOpenReturnThread(filePath, pData.mStrAppCateId, pData.m_strAppId, pData.m_strAppCurrentVerson, this);
			csOpenReturnThread->setParams(QStringList() << QString("nuonuo") << app_userInfo.m_strTaxNumber);
			csOpenReturnThread->start();
			mutexCLicke.unlock();
			return true;
		}
		else if (pData.m_strAppName == QString::fromLocal8Bit("����Ҵ�дת������"))
		{
			QString filePath = "SoftWare\\RMBCapitalConversion.exe";
			CsOpenReturnThread *csOpenReturnThread = new CsOpenReturnThread(filePath, pData.mStrAppCateId, pData.m_strAppId, pData.m_strAppCurrentVerson, this);
			csOpenReturnThread->start();
			mutexCLicke.unlock();
			return true;
		}
		else if (pData.m_strAppName == QString::fromLocal8Bit("Web1800Client"))
		{
			QFileInfo fileInfo(pData.m_strAppExecPathUrl);
			if (pData.m_strAppExecPathUrl == "" || !fileInfo.exists())
			{
				if (!AppCommFun::isSoftInstall(&pData))
				{
					openAppError(pData, Operand_id);
					mutexCLicke.unlock();
					return false;
				}
				//����Ӧ�� ��װ·��
				AppCenterDatabase::instance()->updateApp(pData);
				vPath = pData.m_strAppExecPathUrl;
				vPath.replace("\\", "/");
			}
			bool bShow = true;//�Ƿ���ʾvip��ť
			if (pData.m_strAppAlias == QString::fromLocal8Bit("�ͷ�Զ��"))
			{
				bShow = false;
			}
			else if (pData.m_strAppAlias == QString::fromLocal8Bit("��ԱԶ��"))	//!�½���Աר��
			{
				//ֱ�ӵ�� vipButton
				remoteServiceV(pData, 2);
				mutexCLicke.unlock();
				return true;
			}
			else 
			{
				bShow = true;
			}
			QRemoteServiceDlg paa( pData.m_strAppParams, bShow);
			if (paa.exec() == QDialog::Accepted)
			{
				//�򿪶�Ӧ��  Զ�̷���
				remoteServiceV(pData, paa.IVO);
			}
			mutexCLicke.unlock();
			return true;
		}
		else
		{
			vPath = pData.m_strAppExecPathUrl;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//������ص�ַΪ�� �Ҳ�������Ӧ�� ��cs(��̨���ô���)
		if (vPath.isEmpty() && pData.m_strAppDownloadUrl.isEmpty())
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��Ӧ��ʧ�ܣ����Ժ����ԣ�"));
			mutexCLicke.unlock();
			return false;
		}

		//��cs Ӧ��
		vPath.replace("\\", "/");
		QFileInfo fileInfo(vPath);
		if (vPath == "" || !fileInfo.exists())
		{
			if (Operand_id != "_top_app")
			{
				if (!AppCommFun::isSoftInstall(&pData))
				{
					openAppError(pData, Operand_id);
					mutexCLicke.unlock();
					return false;
				}
				//����Ӧ�� ��װ·��
				AppCenterDatabase::instance()->updateApp(pData);
				vPath = pData.m_strAppExecPathUrl;
				vPath.replace("\\", "/");
			}
			else
			{
				mutexCLicke.unlock();
				return false;
			}
		}

		QString strAppParams = "";
		if (!pData.m_strAppParams.isEmpty())
		{
			strAppParams = pData.m_strAppParams;
			strAppParams.replace("amp;", "");
			strAppParams.replace("{taxcode}", app_userInfo.m_strTaxNumber);
			strAppParams.replace("{uid}", app_userInfo.m_strUserId);
			strAppParams.replace("{token}", app_userInfo.m_strToken);
			strAppParams.replace("{machine}", app_userInfo.m_strMachine);
		}
		int nIndex = vPath.indexOf(".lnk");
		if (-1 == nIndex)
		{
			int nIndex = vPath.lastIndexOf("/");
			QString	strWorkPath = vPath.mid(0, nIndex);
			CsOpenReturnThread *csOpenReturnThread = new CsOpenReturnThread(vPath, pData.mStrAppCateId, pData.m_strAppId, pData.m_strAppCurrentVerson, this);
			csOpenReturnThread->setWorkPath(strWorkPath);
			if (!strAppParams.isEmpty())csOpenReturnThread->setParams(QStringList() << strAppParams);
			csOpenReturnThread->start();
			mutexCLicke.unlock();
			return true;
		}
		else
		{
			//�в�����ݷ�ʽ�п��ܴ򲻿�  ������  ������
			if (!strAppParams.isEmpty()) vPath.append(" " + strAppParams);
			QByteArray	ba = vPath.toLocal8Bit();
			HINSTANCE	hs = ShellExecuteA(NULL, "open", ba.data(), NULL, NULL, SW_SHOWNORMAL);
			if ((long)hs <= 32)
			{
				openAppError(pData, Operand_id);
				mutexCLicke.unlock();
				return false;
			}
		}
	}
	mutexCLicke.unlock();
	return false;
}

void RightClassAppWidget::openAppError(AppDataInfo pData, QString  Operand_id)
{
	if ("TSA002" == Operand_id)//�Ҳ�Ӧ�ô�ʧ��
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M11", "OP001", "TSA003", pData.m_strAppId + "-" + pData.mStrAppCateId);
	}
	else if ("AAC012" == Operand_id)//Ӧ�����Ĵ�Ӧ��ʧ��
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M11", "OP001", "AAC014", pData.m_strAppId);
	}
	if (Operand_id != "_top_app")
	{
		//�Ƕ���Ӧ��
		if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��Ӧ��δ��װ��\r\n�Ƿ�������װ��Ӧ�÷���")) == QDialog::Accepted)
		{
			openAppCenterDlg();
			if (m_appCenterWidget)
			{
				pData.m_bAppIsInstall = false;
				AppCenterDatabase::instance()->updateApp(pData);
				//ˢ�½���
				flushButton();
				openAppCenterDlg();
				m_appCenterWidget->setAutoDownload(pData);
			}
		}
	}
}

void RightClassAppWidget::openAppCenterDlg(bool isShow)
{
	//���� �ж� Ϊ�� ���� ʹ����; ������һ����ʾ ��  
	if (NULL == m_appCenterWidget && !m_initDeskThread->m_emitFlag)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ڳ�ʼ��Ӧ�����ģ����Ժ����ԣ�"));
		return;
	}
	if (NULL == m_appCenterWidget)
	{
		DlgWait 	dlgWait;
		//����Ӧ�����ĳ�ʼ��ʱ��Ƚϳ� ��ֹ�ڳ�ʼ��ʱ��ε��
		static bool openCenterFlag = false;
		if (openCenterFlag)
			return;
		qApp->processEvents(QEventLoop::AllEvents);
		openCenterFlag = true;
		m_appCenterWidget = new AppCenterWidget();
		//���ٴε��ã����� Ӧ������m_appCenterWidget Ϊ��
		m_appCenterWidget->clickedMainHomeButton();
		connect(m_appCenterWidget, SIGNAL(newFlushClass(QString)), this, SLOT(flushButton(QString)), Qt::QueuedConnection);

		if (isShow)
		{
			m_appCenterWidget->setWindowModality(Qt::WindowModal);
			m_appCenterWidget->showNormal();
			m_appCenterWidget->activateWindow();
		}
		else
		{
			m_appCenterWidget->hide();
		}
		openCenterFlag = false;
	}
	else
	{
		if (isShow)
		{
			m_appCenterWidget->showNormal();
			m_appCenterWidget->activateWindow();
		}
		else
		{
			m_appCenterWidget->hide();
		}
	}
}

void RightClassAppWidget::zhicoludExitThread(int flag)
{
	DlgWait *dlgWait = new DlgWait(QString::fromLocal8Bit("���Ե�.."), this);
	dlgWait->show();
	qApp->processEvents(QEventLoop::AllEvents);
	ReturnThread *exitThread = new ReturnThread(this);
	exitThread->enumStatus = flag;
	exitThread->start();
	connect(exitThread, &ReturnThread::threadReturn, [this](int flag)
	{
		qApp->exit(flag);
	});
	qApp->processEvents(QEventLoop::AllEvents);
}

void RightClassAppWidget::setWidgetHind(bool hindClass, bool isHind)
{
	if (hindClass)
	{
		m_appWidgt->m_appsWidgetIsHid = false;
		m_haveHid = isHind;
		m_haveHid ? this->hideFunc() : this->showFunc();
	}
	else
	{
		m_haveHid = false;
		m_appWidgt->m_appsWidgetIsHid = isHind;
		m_appWidgt->m_appsWidgetIsHid ? m_appWidgt->hideAppsWidget() : m_appWidgt->showAppsWidget();
	}
}

//Զ�̷��� invoice  other vip
void RightClassAppWidget::remoteServiceV(AppDataInfo pData, int iov)
{
	QString strGpId;
	switch (iov)
	{
	case 0:
	{
		if ("10026" == app_userInfo.m_strHzsId)
		{
			strGpId = "3361";
		}
		else if ("10014" == app_userInfo.m_strHzsId)
		{
			strGpId = "3362";
		}
		else
		{
			strGpId = "6";
		}

		break;
	}
	case 1:
	{
		if ("10026" == app_userInfo.m_strHzsId)
		{
			strGpId = "3361";
		}
		else if ("10014" == app_userInfo.m_strHzsId)
		{
			strGpId = "3364";
		}
		else
		{
			strGpId = "2";
		}
		break;
	}
	case 2:
	{
		int nVipState = 0;
		if ("10014" == app_userInfo.m_strHzsId)
		{
			nVipState = app_userInfo.m_isHxNumber;
		}
		else
		{
			nVipState = QRemoteServiceDlg::checkVipState(app_userInfo.m_strTaxNumber);
		}

		if (!nVipState)
		{
			//���糬ʱ �� ��vip
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������ǻ�Ա��\r\n����ϵ���غ�����Ϣ����վ����\r\n��Ա�ɷѣ����ܻ�Ա����"));
			return;
		}
		else 
		{
			if (m_currentTime <= app_userInfo.m_timeChargeExpire.toTime_t())
			{
				//!δ��ʱ
				if ("10026" == app_userInfo.m_strHzsId)
				{
					strGpId = "3364";
				}
				else if ("10014" == app_userInfo.m_strHzsId)
				{
					strGpId = pData.m_strAppParams;
				}
				else
				{
					strGpId = "16";
				}
			}
			else
			{
				//!��Ա����
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���Ļ�Ա�ѵ��ڣ�\r\n����ϵ���غ�����Ϣ����վ��������"));
				return;
			}
		}
		break;
	}
	default:
		return;
	}
	QString filePath = "Type=2,UserId=" + app_userInfo.m_strUserId + ",UserName=" + app_userInfo.m_strUsername + ",ProductName=web1800,ProductModel=3.1,SerialNo=3.1.59,GPID=" + strGpId + ",taxnumber=" + app_userInfo.m_strTaxNumber + ",CompanyName=" + app_userInfo.m_strCompanyName;
	CsOpenReturnThread *csOpenReturnThread = new CsOpenReturnThread(pData.m_strAppExecPathUrl, pData.mStrAppCateId, pData.m_strAppId, pData.m_strAppCurrentVerson, this);
	csOpenReturnThread->setParams(QStringList() << filePath);
	csOpenReturnThread->start();
}

int RightClassAppWidget::buyApp(QString appId, bool isBuyApp)
{
	//UserInfo app_userInfo;
	QString strToken = app_userInfo.m_strToken;
	QString strUid = app_userInfo.m_strUserId;
	if (ZcloudComFun::winHttpSSO(strToken, strUid))
	{
		QString strWallpaperUrl = ZcloudComFun::getWvUrl(strUid, strToken, (isBuyApp ? "wv/trade/buy-app?app_id=" : "wv/member/app-list?app_id=") + appId);
		BuyAppDialog  buyAppDialog(appId, strUid, strToken, isBuyApp, strWallpaperUrl, this);
		int returnExec = buyAppDialog.exec();
		if (returnExec == QDialog::Accepted)
		{
			if (!isBuyApp)
			{
				//�����Ա�ɹ�
				QStringList strListAppVipNameList = buyAppDialog.m_strListAppVipNameList;//vip�ȼ���������
				QStringList strListAppVipList = buyAppDialog.m_strListAppVipList;		//vip�ȼ�����
				QStringList strEndTimeList = buyAppDialog.m_strEndTimeList;
				app_userInfo.m_strListAppVipNameList = strListAppVipNameList;
				app_userInfo.m_strListAppVipList = strListAppVipList;
				app_userInfo.m_vipDateTimeList = strEndTimeList;
				emit buyVipListSignals(strListAppVipNameList, strListAppVipList, strEndTimeList);
			}
			else
			{
				if (!buyAppDialog.isOpen)
				{
					//����Ӧ�óɹ� ˢ���Ҳ� ��Ӧ������
					flushButton();
					if (m_appCenterWidget)
					{
						m_appCenterWidget->flushAppCenter();
					}
				}
				else
				{
					//ֱ�Ӵ�Ӧ�� �û�������ݲ����� ��Ӧ����ȥ����
				}
			}
			return QDialog::Accepted;
		}
		else if (3 == returnExec)
		{
			return 3;
		}
		else if (2 == returnExec)
		{
			emit bindingPhoneSignals();
		}
	}
	return QDialog::Rejected;
}

















