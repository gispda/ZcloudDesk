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

const int g_rightWidgetWidth = 70;	//分类按钮的高度
const int g_fontSize = 30;	//应用字体高度
const int g_appRow = 6;	//一列应用的个数
const int g_nRightWidth = 30;	//右边  widget的宽度
const int g_nullWidth = 20;  //分类和 应用的间距
int SHOW_WIDGET_WIDTH = 2;//隐藏预留宽度
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

//应用框
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

//失去焦点
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
	this->m_appShowWidth = lineCont * rightWidgetWidth;//需要显示的宽度
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
	//初始化 桌面线程，  如果需要初始化 重新读取网络 应用信息 直接  start
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

//窗口的进入事件(enterEvent)
void RightClassAppWidget::enterEvent(QEvent *event)
{
	if (m_haveHid)
	{
		showFunc();
	}

	return QWidget::enterEvent(event);
}

//窗口的离开事件（leaveEvent）
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
		//如果是显示的 才隐藏
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
		//如果是隐藏的才显示
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
	//如果应用中心不为空重新初始化
	if (NULL != m_appCenterWidget)
	{
		//切换税号时用
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

	//初始化 下载列表
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
			"QPushButton{text-align:center center;color:rgb(255,255,255);border-radius:2px;font:15px\'微软雅黑\'75;"
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
	//保存现在的宽度和高度
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
			//如果是隐藏的 第一次 就不显·示
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
	//结束线程
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

//清空
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
		//关闭应用中心 结束线程
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
			"QPushButton{text-align:center center;color:rgb(255,255,255);border-radius:2px;font:15px\'微软雅黑\'75;"
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
			"QPushButton{text-align:center center;color:rgb(255,255,255);border-radius:2px;font:15px\'微软雅黑\'75;"
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
	//查询数据库失败 也要显示widget
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
	//查询该分类的所有应用
	QList<AppDataInfo> appReadList;
	if (!AppCenterDatabase::instance()->findClassAppList(appReadList, classId))
	{
		qDebug() << "zcd-0x00000039:" << "findClassAppList Error";
		return false;
	}

	//读取下载列表
	DownLoadManager*	pDownloadManager = RightClassAppWidget::getDownLoadManager();


	if (app_userInfo.m_strCompanyId != "")
	{
	
	 for each (AppDataInfo pData in appReadList)
	 {

		AppDownLoadThread *downloadThread = pDownloadManager->isRightManager(pData.m_strAppName, pData.m_strAppId);
		if (downloadThread != NULL)
		{
			//更新
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
				//如果当前版本为空  未处理
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
					//如果当前版本为空  未处理
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
				if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("该应用未安装,是否安装?")) == QDialog::Accepted)
				{
					setAutoDownload(pData);
					return true;
				}
			}
		}
	}
	return false;
}

//查询会员或者付费是否满足 (需要会员 && 不满足会员) || （需要购买 && 会员已到期)

//判定用用是否需要购买
bool RightClassAppWidget::isPayApp(AppDataInfo pData)
{
	if (pData.m_enPaidTime.isEmpty() || pData.m_enPaidTime == "0" || (pData.m_enPaidTime.toInt() < m_currentTime))
	{
		return true;
	}
	return false;
}

//判定应用是否需要会员
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

//判定试用是否到期 当isTryOut=true 才有可能 isAastDur为true
bool RightClassAppWidget::isAastDueApp(AppDataInfo pData)
{
	//判断是否到期
	if (pData.m_enExperienceTime.toInt() < m_currentTime)
	{
		return true;
	}
	return false;
}

bool RightClassAppWidget::determineAvailability(AppDataInfo pData, QString  Operand_id)
{
	//发布到桌面 用户点击后 再上报 已安装
	if (m_issueStringList.contains(pData.m_strAppId))
	{
		m_issueStringList.removeOne(pData.m_strAppId);
		if (AppCenterDatabase::instance()->removeOneSue(pData.m_strAppId))
		{
			//上报已安装
			AppCenterDatabase::instance()->appearApp(pData.m_strAppId, 1);
		}
	}
	QStringList strList = pData.m_strListAppVipList;
	//if (strList.contains("-1") || pData.m_strAppFree.contains("-1") || pData.m_enExperienceTime.contains("-1") || pData.m_experienceTime.contains("-1"))
	//{
	//	if (Operand_id != "_top_app")
	//		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("打开失败，请稍后再试！"));
	//	return false;
	//}
	//
	//有试用
	bool isTryOut = (!pData.m_experienceTime.isEmpty() && pData.m_experienceTime != "0");	
	//有试用 且未开始试用
	if (isTryOut && (pData.m_enExperienceTime.isEmpty() || pData.m_enExperienceTime == "0"))
	{
		//顶栏的不在这提示 因为需要操作数据库
		if (Operand_id != "_top_app")
		{
			//开始试用  修改试用到期时间
			int experienceTime = m_currentTime + pData.m_experienceTime.toInt() * 24 * 60 * 60;
			pData.m_enExperienceTime = QString::number(experienceTime);
			if (AppCenterDatabase::instance()->updateAppPaidTime(pData.m_strAppId, experienceTime, false))
			{
				//刷新右侧应用
				if (m_tButton)
					emit m_tButton->clicked(true);
				if (m_appCenterWidget)
					m_appCenterWidget->flushAppCenter();
				AppCenterDatabase::instance()->appearApp(pData.m_strAppId, 3);
			}
			else
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("试用失败，请稍后再试！"));
				return false;
			}
		}else
			return false;
	}
	//需注册
	bool isBinding = pData.m_isBindingPhone;
	//需购买
	bool isPay = (pData.m_strAppFree.toFloat() != 0);// isPayApp(pData);
	bool isPayTimeOut = false;
	if (isPay) isPayTimeOut = isPayApp(pData);
	//需会员
	bool isMember = (pData.m_strListAppVipList.size() > 0);// isMemberApp(pData);
	bool isMemberTimeOut = false;
	if (isMember) isMemberTimeOut = isMemberApp(pData);
	//试用已过期  当isTryOut=true 才有可能 isAastDur为true
	bool isAastDue = false;
	if (isTryOut)	isAastDue = isAastDueApp(pData);

	if (isBinding && (isAastDue || !isTryOut))
	{
		//提醒绑定手机号
		if (app_userInfo.m_strMobile.isEmpty())
		{
			//if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"),
			//	QString::fromLocal8Bit("绑定手机号后,您将享受%1更多功能").arg(g_strAppName))
			//	== QDialog::Accepted)
			//{
				emit bindingPhoneSignals();
			//}
			return false;
		}
	}
	if ((isAastDue || !isTryOut) && isMember && !isPay)
	{
		//会员过期或者第一次使用
		if (isMemberTimeOut)
		{
			//提醒购买会员
			int retrunExec = buyApp(pData.m_strAppId, false);
			//再次判断会员等级 有可能购买成功但会员等级不够
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
		//应用过期 或第一次使用 需要购买
		if (isPayTimeOut)
		{
			//提醒购买应用
			if (/*ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"),
				QString::fromLocal8Bit("该应用非免费,请购买！是否打开商城?"))
				!= QDialog::Accepted ||*/ !buyApp(pData.m_strAppId, true))
			{
				return false;
			}
		}
	}
	if ((isAastDue || !isTryOut) && isMember && isPay)
	{
		//两个同时 过期或者没购买过
		if (isMemberTimeOut && isPayTimeOut)
		{
			//提醒购买会员或者应用
			int dRt = ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_BINDING, QString::fromLocal8Bit("该应用为收费应用"), QString::fromLocal8Bit("购买会员可以免费使用"),
				QString::fromLocal8Bit("购买会员"), QString::fromLocal8Bit("购买应用"));
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

		if (pData.m_strAppName == QString::fromLocal8Bit("税控服务费续费"))//我要发票  和 自助缴费  合二为一
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

			if (pData.m_strAppName == QString::fromLocal8Bit("发票查验平台"))
			{
				//if (CommSetInfo::GetInstance().bNextCloudGh)
				//{
				//	if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("为了确保纳税人发票信息的数据安全，\r\n请安装国家税务总局税务数字证书！")) == QDialog::Accepted)
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
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("功能即将上线，敬请期待！"));
			mutexCLicke.unlock();
			return true;
		}
	}
	else
	{
		//打开特殊的CS应用
		if (pData.m_strAppName == QString::fromLocal8Bit("重装开票"))
		{
			//！正式服下载地址
			pData.m_strAppOnLineVerson.clear();
			QString version = app_userInfo.m_strHzsId;
			pData.m_strAppDownloadUrl.clear();//避免后台 配置了地址
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
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("获取开票软件失败，请稍后再试！"));
				mutexCLicke.unlock();
				return false;
			}
			mutexCLicke.unlock();
			return true;
		}
		else if (pData.m_strAppName == QString::fromLocal8Bit("银联支付"))
		{
			QString	strArgs = " TaxNo:" + app_userInfo.m_strTaxNumber + " EntName:" + app_userInfo.m_strCompanyName;
			QString filePath = "SoftWare\\AisinoUnionPay\\AisinoUnionPay.exe ";
			CsOpenReturnThread *csOpenReturnThread = new CsOpenReturnThread(filePath, pData.mStrAppCateId, pData.m_strAppId, pData.m_strAppCurrentVerson, this);
			csOpenReturnThread->setParams(QStringList() << QString("TaxNo:" + app_userInfo.m_strTaxNumber) << QString("EntName:" + app_userInfo.m_strCompanyName));
			csOpenReturnThread->start();

			mutexCLicke.unlock();
			return true;
		}
		else if (pData.m_strAppName == QString::fromLocal8Bit("打印机定位"))
		{
			//!打印机定位
			QString filePath = "SoftWare\\PrintConfigEdit\\PrintConfigEdit.exe";
			CsOpenReturnThread *csOpenReturnThread = new CsOpenReturnThread(filePath, pData.mStrAppCateId, pData.m_strAppId, pData.m_strAppCurrentVerson, this);
			csOpenReturnThread->setParams(QStringList() << QString("print") << app_userInfo.m_strTaxNumber);
			csOpenReturnThread->start();
			mutexCLicke.unlock();
			return true;

		}
		else if (pData.m_strAppName == QString::fromLocal8Bit("诺诺商城"))
		{
			//！诺诺商城
			QString filePath = "SoftWare\\PrintConfigEdit\\PrintConfigEdit.exe";
			CsOpenReturnThread *csOpenReturnThread = new CsOpenReturnThread(filePath, pData.mStrAppCateId, pData.m_strAppId, pData.m_strAppCurrentVerson, this);
			csOpenReturnThread->setParams(QStringList() << QString("nuonuo") << app_userInfo.m_strTaxNumber);
			csOpenReturnThread->start();
			mutexCLicke.unlock();
			return true;
		}
		else if (pData.m_strAppName == QString::fromLocal8Bit("人民币大写转换工具"))
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
				//更新应用 安装路径
				AppCenterDatabase::instance()->updateApp(pData);
				vPath = pData.m_strAppExecPathUrl;
				vPath.replace("\\", "/");
			}
			bool bShow = true;//是否显示vip按钮
			if (pData.m_strAppAlias == QString::fromLocal8Bit("客服远程"))
			{
				bShow = false;
			}
			else if (pData.m_strAppAlias == QString::fromLocal8Bit("会员远程"))	//!新疆会员专区
			{
				//直接点击 vipButton
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
				//打开对应的  远程服务
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
		//如果下载地址为空 且不是特殊应用 的cs(后台配置错误)
		if (vPath.isEmpty() && pData.m_strAppDownloadUrl.isEmpty())
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("打开应用失败，请稍后再试！"));
			mutexCLicke.unlock();
			return false;
		}

		//打开cs 应用
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
				//更新应用 安装路径
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
			//有参数快捷方式有可能打不开  待处理  待测试
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
	if ("TSA002" == Operand_id)//右侧应用打开失败
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M11", "OP001", "TSA003", pData.m_strAppId + "-" + pData.mStrAppCateId);
	}
	else if ("AAC012" == Operand_id)//应用中心打开应用失败
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M11", "OP001", "AAC014", pData.m_strAppId);
	}
	if (Operand_id != "_top_app")
	{
		//非顶栏应用
		if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("该应用未安装，\r\n是否立即安装此应用服务？")) == QDialog::Accepted)
		{
			openAppCenterDlg();
			if (m_appCenterWidget)
			{
				pData.m_bAppIsInstall = false;
				AppCenterDatabase::instance()->updateApp(pData);
				//刷新界面
				flushButton();
				openAppCenterDlg();
				m_appCenterWidget->setAutoDownload(pData);
			}
		}
	}
}

void RightClassAppWidget::openAppCenterDlg(bool isShow)
{
	//必须 判定 为空 否则 使用中途 处出现一下提示 ，  
	if (NULL == m_appCenterWidget && !m_initDeskThread->m_emitFlag)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("正在初始化应用中心，请稍后再试！"));
		return;
	}
	if (NULL == m_appCenterWidget)
	{
		DlgWait 	dlgWait;
		//由于应用中心初始化时间比较长 防止在初始化时多次点击
		static bool openCenterFlag = false;
		if (openCenterFlag)
			return;
		qApp->processEvents(QEventLoop::AllEvents);
		openCenterFlag = true;
		m_appCenterWidget = new AppCenterWidget();
		//需再次调用，否则 应用中心m_appCenterWidget 为空
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
	DlgWait *dlgWait = new DlgWait(QString::fromLocal8Bit("请稍等.."), this);
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

//远程服务 invoice  other vip
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
			//网络超时 和 非vip
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("您还不是会员，\r\n请联系当地航天信息服务站进行\r\n会员缴费，享受会员服务"));
			return;
		}
		else 
		{
			if (m_currentTime <= app_userInfo.m_timeChargeExpire.toTime_t())
			{
				//!未超时
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
				//!会员过期
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("您的会员已到期，\r\n请联系当地航天信息服务站进行续费"));
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
				//购买会员成功
				QStringList strListAppVipNameList = buyAppDialog.m_strListAppVipNameList;//vip等级名字链表
				QStringList strListAppVipList = buyAppDialog.m_strListAppVipList;		//vip等级链表
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
					//购买应用成功 刷新右侧 和应用中心
					flushButton();
					if (m_appCenterWidget)
					{
						m_appCenterWidget->flushAppCenter();
					}
				}
				else
				{
					//直接打开应用 用户点击了暂不购买， 在应用内去购买
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

















