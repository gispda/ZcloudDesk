#include "ZcloudCommon.h"
#include "AppCenterWidget.h"
#include <QPainter>
#include <QGridLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QDesktopWidget>
#include <QMutexLocker> 
#include "ZhicloudApp.h"
#include "dlgwait.h"
#include "AppCommFun.h"
#include <QDebug>
#include "AppDatabase/AppCenterDatabase.h"
#include "RightClassAppWidget.h"
#include "DownloadFile/DownLoadManager.h"
#include "ZcloudBigData.h"



extern UserInfoStruct app_userInfo;

#define  STYSTEM5	"QPushButton{border-style:none ;font: 14px \"΢���ź�\";color: rgb(102, 102, 102);} QPushButton:hover{color: rgb(34, 153, 254);}QPushButton:pressed{color: rgb(34, 153, 254);};"


AppCenterWidget::AppCenterWidget(QWidget *parent)
	: QWidget(parent)
	, pButtonGroup(new QButtonGroup(this))
	, appDownLoadAppWidget(new AppDownLoadAppWidget(this))
{
	ui.setupUi(this);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowFlags(Qt::FramelessWindowHint);// | Qt::WindowStaysOnTopHint );
	//setStyleSheet("outline: none;");

	pButtonGroup->setExclusive(true);
	pButtonGroup->addButton(ui.mainPushButton,0);
	pButtonGroup->addButton(ui.categoryPushButton,1);
	pButtonGroup->addButton(ui.managerPushButton,2);
	setWindowModality(Qt::NonModal);
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	setWindowTitle(QString::fromLocal8Bit("Ӧ������"));
	ui.seekLineEdit->setTextMargins(30, 0, 0, 0);
	
	connect(ui.seekLineEdit, SIGNAL(returnPressed()), this, SLOT(onFindBtnClick()));
	connect(ui.homeWidget->m_photoWidget, SIGNAL(openAppParticularsSig(QString)), this, SLOT(openAppParticularsSlot(QString)));
	
	
	homePageTimer = new QTimer(this);
	connect(homePageTimer, &QTimer::timeout, [this]()
	{
		RightClassAppWidget *zhicloudDesk = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance());
		if (zhicloudDesk)
		{
			//������  �Ƿ���Ҫ��һ��ʱ�� ȥ��ȥ�ֲ�ͼ
			//zhicloudDesk->initDeskThread->isFirst = false;
			//zhicloudDesk->initDeskThread->start();
		}
	});
	homePageTimer->start(60 * 1000 * 10);
	connect(ui.miniButton, SIGNAL(clicked()), this, SLOT(showMinimized()));
	connect(ui.closeButton, &QPushButton::clicked, [this]()
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "AAC008");
		this->hide();
	});
}

AppCenterWidget::~AppCenterWidget()
{

}



void AppCenterWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->globalPos().y() < (this->pos().y() + 88))
	{
		this->windowPos = this->pos();            // ��ò�����ǰλ��
		this->mousePos = event->globalPos();     // ������λ��
		this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
	}
	return QWidget::mousePressEvent(event);
}

void AppCenterWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (event->globalPos().y() < (this->pos().y() + 88))
	{
		this->move(event->globalPos() - this->dPos);
	}
	return QWidget::mouseMoveEvent(event);
}

void AppCenterWidget::on_mainPushButton_clicked(bool checked)
{
	if ( !mutex.tryLock()) return;
	mutex.unlock();
	QMutexLocker mutexLocker(&mutex);
	ui.seekLineEdit->clear();
	setLabelNotApp();
	
	ui.homeWidget->initHomeWidget();
	if (!checked) ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "AAC001");
}

//����
void AppCenterWidget::on_categoryPushButton_clicked(bool checked)
{
	if ( !mutex.tryLock()) return;
	mutex.unlock();
	QMutexLocker mutexLocker(&mutex);
	ui.seekLineEdit->clear();
	setLabelNotApp();
	ui.categoryWidget->initCategory();
	if (!checked) ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "AAC002");
}



void AppCenterWidget::on_managerPushButton_clicked(bool checked)
{
	if (!mutex.tryLock()) return;
	mutex.unlock();
	QMutexLocker mutexLocker(&mutex);

	ui.seekLineEdit->clear();
	setLabelNotApp();
	ui.appManagerWidget->initUU();
	if (!checked) ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "AAC004");
}


void AppCenterWidget::setLabelNotApp(bool isShowLabel)
{
	if (appParticularsDialog)
	{
		appParticularsDialog->deleteLater();
		appParticularsDialog = NULL;
	}
	this->setEnabled(false);
	ui.categoryWidget->hide();
	ui.appManagerWidget->hide();
	ui.homeWidget->hide();

	int chooseWidget = pButtonGroup->checkedId();
	//��ҳ
	if (chooseWidget == 0)
	{
		//ui.homeWidget->initHomeWidget();
		ui.homeWidget->show();
	}
	//����
	else if (chooseWidget == 1)
	{
		//ui.categoryWidget->initCategory();
		ui.categoryWidget->move(MARGIN_WITH, 80 + MARGIN_WITH);
		ui.categoryWidget->show();

	}
	//�������
	else if (chooseWidget == 2)
	{
		//ui.appManagerWidget->initUU();
		ui.appManagerWidget->move(MARGIN_WITH, 80 + MARGIN_WITH);
		ui.appManagerWidget->show();
	}
	this->setEnabled(true);
}


void AppCenterWidget::on_downloadButton_clicked()
{
	if( !mutex.tryLock()) return;
	mutex.unlock();
	QMutexLocker mutexLocker(&mutex);
	
	if (!appDownLoadAppWidget->isVisible())
	{
		appDownLoadAppWidget->move(this->x() + 718, this->y() + 69);
		appDownLoadAppWidget->showWindow();
		appDownLoadAppWidget->setFocus();
	}
	else
		appDownLoadAppWidget->hide();
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "AAC006");


}
void AppCenterWidget::addDownloadItem(AppDownLoadItem *dItem)
{
	if (!appDownLoadAppWidget)
	{
		on_downloadButton_clicked();
	}
	if (dItem)
	{
		appDownLoadAppWidget->addDownload(dItem);
		appDownLoadAppWidget->move(this->x() + 718, this->y() + 69);
		appDownLoadAppWidget->showWindow();
		appDownLoadAppWidget->setFocus();

		//֪ͨ����ˢ��������
		emit newFlushClass(dItem->m_deskInfo.mStrAppCateId);
	}
}

void AppCenterWidget::pushPayInstall(const QString& strJson)
{

}

void AppCenterWidget::setAutoDownload(AppDataInfo pData)
{
	//��Ӧ������ ��װ
	if (appParticularsDialog)
	{
		appParticularsDialog->deleteLater();
		appParticularsDialog = NULL;
	}
	APPSTATUS partFlag = pData.m_bAppIsInstall ? E_OPEN :  E_INSTALL;
	int checkedId = pButtonGroup->checkedId();
	if (checkedId == 0)
	{
		ui.homeWidget->changedToolButtonStatus(pData.m_strAppId, partFlag);
	}
	else if (checkedId == 1)
	{
		ui.categoryWidget->changedToolButtonStatus(pData.m_strAppId, partFlag);
	}
	else if (checkedId == 2)
	{
		ui.appManagerWidget->changedToolButtonStatus(pData.m_strAppId, partFlag);
	}

	appParticularsDialog = new AppParticularsDialog(pData, partFlag, this);
	appParticularsDialog->clickedStautusButton();
	appParticularsDialog->show();

}

void AppCenterWidget::changeButtonStatus(QString appId)
{
	if (appParticularsDialog)
	{
		APPSTATUS partFlag = appParticularsDialog->m_APPSTATUSFlag;
		int checkedId = pButtonGroup->checkedId();
		if (checkedId == 0)
		{
			ui.homeWidget->changedToolButtonStatus(appId, partFlag);

		}
		else if (checkedId == 1)
		{
			ui.categoryWidget->changedToolButtonStatus(appId, partFlag);
		}
		else if (checkedId == 2)
		{
			ui.appManagerWidget->changedToolButtonStatus(appId, partFlag);
		}
		appParticularsDialog->deleteLater();
		appParticularsDialog = NULL;
	}
}

void AppCenterWidget::openAppParticularsSlot()
{
	AppCenterTools *appCenterTools = qobject_cast<AppCenterTools *>(sender());
	if (appCenterTools)
	{
		//��ֹ�������
		if (appParticularsDialog) return;
		appParticularsDialog = new AppParticularsDialog(appCenterTools->m_desktopAppInfo, appCenterTools->m_APPSTATUSFlag, this);
		connect(appCenterTools, SIGNAL(toolsStatusChanged(APPSTATUS)), appParticularsDialog, SLOT(statusChanged(APPSTATUS)));
		appParticularsDialog->show();
		//if (appParticularsDialog)
		//{
		//	if (appParticularsDialog->m_APPSTATUSFlag == E_INSTALLING || appParticularsDialog->m_APPSTATUSFlag == E_UPDATEING)
		//	{
		//		//����ڰ�װ�д��� ��ǰ�����ϵİ�ť״̬ �� �ۺ���
		//		if (appCenterTools) appCenterTools->downloadApp();
		//	}
		//	else
		//	{
		//		if (appCenterTools) appCenterTools->statusChanged(appParticularsDialog->m_APPSTATUSFlag);
		//	}
		//	appParticularsDialog->deleteLater();
		//	appParticularsDialog = NULL;
		//}
	}
}

//ͼƬ����
void AppCenterWidget::openAppParticularsSlot(QString appId)
{
	AppDataInfo deskData;
	deskData.m_strAppId = appId;//1062
	if (AppCenterDatabase::instance()->findApp(deskData))
	{
		RightClassAppWidget *ptr = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance());
		if (ptr)
			ptr->openApp(deskData);
	}
}

void AppCenterWidget::onFindBtnClick()
{
	QString findStr = ui.seekLineEdit->text();
	if (!ui.categoryPushButton->isChecked())
	{
		ui.categoryPushButton->click();
		ui.seekLineEdit->setText(findStr);
	}
	findStr.replace("/","//");
	findStr.replace("'","''");
	findStr.replace("]","/]");
	findStr.replace("[","/[");
	findStr.replace("%","/%");
	findStr.replace("&","/&");
	findStr.replace("_","/_");
	findStr.replace("(","/(");
	findStr.replace(")","/)");
	ui.categoryWidget->clickedAllButton(findStr);
}


void AppCenterWidget::closeCenterWidget()
{
	DownLoadManager*	pDownloadManager = RightClassAppWidget::getDownLoadManager();
	if (pDownloadManager)
	{
		pDownloadManager->deleteUUThread();
	}
}

void AppCenterWidget::flushAppCenter()
{
	emit pButtonGroup->checkedButton()->clicked();
}
