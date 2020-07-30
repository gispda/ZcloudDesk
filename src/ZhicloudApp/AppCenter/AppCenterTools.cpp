//应用中心的 应用按钮
#include "AppCenterTools.h"
#include "ui_AppCenterWidget.h"
#include "AppCommFun.h"
#include "ZcloudCommon.h"
#include "AppDatabase/AppCenterDatabase.h"
#include "ZhicloudApp.h"
#include "RightClassAppWidget.h"
#include <QTextEdit>
#include <QDir>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include "DownloadFile/DownLoadManager.h"
#include "ZcloudBigData.h"

extern UserInfoStruct app_userInfo;

AppCenterTools::AppCenterTools(AppDataInfo  info, QWidget *parent)
	: QPushButton(parent)
	, m_desktopAppInfo(info)
	, m_photoLabel(new QLabel(this))
	, m_nameLabel(new QLabel(this))
	, m_particulars(new QLabel(this))
	, statusButton(new AppCenterItemPushButton(this))
{

	this->resize(236, 60);
	connect(statusButton, SIGNAL(clicked()), this, SLOT(onRecommended()));
	connect(statusButton, SIGNAL(clicked()), this, SLOT(clickedStautusButton()));
	statusButton->setGeometry(55, 30, 60, 24);

	m_photoLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	m_photoLabel->setGeometry(0, 5, 50, 50);
	QString pixmapPath = m_desktopAppInfo.m_strAppIconPath;
	QFileInfo fileInfo(pixmapPath);
	if (pixmapPath.isEmpty() || !fileInfo.exists())
		pixmapPath = ":/new/imageFile/photoError.png";
	QFile file(pixmapPath);
	file.open(QIODevice::ReadOnly);
	QPixmap iconpixmap;
	iconpixmap.loadFromData(file.readAll());
	m_photoLabel->setPixmap(iconpixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));



	m_nameLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	QString strliasName = m_desktopAppInfo.m_strAppAlias;
	if (strliasName.isEmpty())
		strliasName = m_desktopAppInfo.m_strAppName;
	
	m_nameLabel->setText(AppCommFun::getElidedText(strliasName,10));
	m_nameLabel->setGeometry(55, 5, 160, 25);
	m_nameLabel->setStyleSheet(QString::fromLocal8Bit("font: 14px \"微软雅黑\";color: rgb(51, 51, 51);"));



	//QLabel *appSizeLabel = new QLabel(this);
	//appSizeLabel->setAlignment(Qt::AlignHCenter);
	//appSizeLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	//appSizeLabel->setGeometry(8, 105, 130, 20);
	//appSizeLabel->setStyleSheet(QString::fromLocal8Bit("font: \"微软雅黑\" 13px;color: rgb(102,102,102);"));
	//QString strAppSize = m_desktopAppInfo.m_intAppSize;
	//
	//if (m_desktopAppInfo.m_bAppType && !m_desktopAppInfo.m_strAppDownloadUrl.isEmpty())//cs  应用
	//{
	//	if (strAppSize.isEmpty() )
	//	{
	//		strAppSize = "--";
	//	}
	//	else
	//		strAppSize.append("M");
	//}else
	//	strAppSize = "--";
	//appSizeLabel->setText(strAppSize);
	//

	m_particulars->setStyleSheet(QString::fromLocal8Bit("background:transparent;border-width:0;border-style:outset;color: rgb(102, 102, 102);font: 13px \"微软雅黑\";"));
	m_particulars->setGeometry(55, 30, 160, 25);
	QString strDesc = m_desktopAppInfo.m_strAppDesc;
	strDesc = strDesc.split(QRegExp("[\r\n]"), QString::SkipEmptyParts).join("");
	m_particulars->setText(AppCommFun::getElidedText(strDesc, 11));
	connectThread();
}



AppCenterTools::AppCenterTools(AppDataInfo  info, int number, QWidget *parent)
	: QPushButton(parent)
	, m_desktopAppInfo(info)
	, m_particulars( new QLabel(this))
	, m_numberLabel(new QLabel(this))
	, m_photoLabel(new QLabel(this))
	, m_nameLabel(new QLabel(this))
	, statusButton(new AppCenterItemPushButton(this))
{
	m_isHotApp = 1;
	this->resize(228, 30);
	m_photoLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	
	m_nameLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	m_nameLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	connect(statusButton, SIGNAL(clicked()), this, SLOT(clickedStautusButton()));

	QString pixmapPath = m_desktopAppInfo.m_strAppIconPath;
	QFileInfo fileInfo(pixmapPath);
	if (pixmapPath.isEmpty() || !fileInfo.exists())
		pixmapPath = ":/new/imageFile/photoError.png";
	QFile file(pixmapPath);
	file.open(QIODevice::ReadOnly);
	QPixmap iconpixmap;
	iconpixmap.loadFromData(file.readAll());
	
	




	m_photoLabel->resize(30, 30);//29,1
	m_photoLabel->setPixmap(iconpixmap.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	statusButton->setMaximumSize(60, 24);
	statusButton->setMinimumSize(60, 24);

	QString strliasName = m_desktopAppInfo.m_strAppAlias;
	if (strliasName.isEmpty())
		strliasName = m_desktopAppInfo.m_strAppName;
	hotAppName_1 = 	AppCommFun::getElidedText(strliasName, 10);

	hotAppName_2 = AppCommFun::getElidedText(strliasName, 6);

	m_nameLabel->setText(hotAppName_1);
	m_nameLabel->setStyleSheet(QString::fromLocal8Bit("font: 14px \"微软雅黑\";color: rgb(51, 51, 51);"));
	
	m_particulars->setStyleSheet(QString::fromLocal8Bit("font: 14px \"微软雅黑\";color: rgb(255, 255, 255);background-color: rgb(252, 98, 120);"));
	m_particulars->setMaximumSize(20, 20);
	m_particulars->setMinimumSize(20, 20);
	m_particulars->setAlignment(Qt::AlignHCenter);
	m_particulars->setText(QString::number(number));
	m_numberLabel = new QLabel(this);
	m_numberLabel->setAlignment(Qt::AlignHCenter);
	m_numberLabel->setMaximumSize(20, 20);
	m_numberLabel->setMinimumSize(20, 20);
	m_numberLabel->setText(QString::number(number));
	QString styStr = QString::fromLocal8Bit("font: 14px \"微软雅黑\";background:transparent;");
	if (number == 1)
	{
		styStr.append(QString::fromLocal8Bit("color: rgb(252, 98, 120);"));
	}
	else if (number == 2)
	{
		styStr.append(QString::fromLocal8Bit("color:#F68B34;"));
	}
	else if (number == 3)
	{
		styStr.append(QString::fromLocal8Bit("color:#89C73B;"));
	}
	else
	{
		styStr.append(QString::fromLocal8Bit("color:#666666;"));
	}
	m_numberLabel->setStyleSheet(styStr);

	QHBoxLayout *HLayout = new QHBoxLayout(this);
	HLayout->setMargin(0);
	HLayout->addWidget(m_numberLabel);
	HLayout->addWidget(m_particulars);//背景为红色的 数字按钮
	HLayout->addWidget(m_photoLabel);
	HLayout->addWidget(m_nameLabel);
	HLayout->addStretch();
	HLayout->addWidget(statusButton);

	m_particulars->hide();
	m_photoLabel->hide();
	connectThread();
	//QDesktopWidget *deskWgt = QApplication::desktop();
	//connect(deskWgt, SIGNAL(resized(int)), this, SLOT(resizeFont()));
	//resizeFont();
}

QString appSizeDataString(int size)
{
	QString unit;
	if (size < 1024) {
		unit = QString("kB");
	}
	else {
		size /= 1024;
		unit = QString("MB");
	}
	return QString(QLatin1String("%1 %2")).arg(size).arg(unit);
}

AppCenterTools::AppCenterTools(QWidget *parent, AppDataInfo  info, bool ategory_manager)
	: QPushButton(parent)
	, m_desktopAppInfo(info)
	, m_photoLabel(new QLabel(this))
	, m_particulars(new QLabel(this))
	, statusButton(new AppCenterItemPushButton(this))
{
	m_isHotApp = ategory_manager ?  2 : 3;
	this->resize(998, 91);
	connect(statusButton, SIGNAL(clicked()), this, SLOT(clickedStautusButton()));
	connect(statusButton, SIGNAL(actionUninstallSignal()), this, SLOT(updateUninstall()));
	statusButton->setGeometry(830, 25, 120, 40);

	m_photoLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	m_photoLabel->setGeometry(20, 20, 50, 50);
	QString pixmapPath = m_desktopAppInfo.m_strAppIconPath;
	QFileInfo fileInfo(pixmapPath);
	if (pixmapPath.isEmpty() || !fileInfo.exists())
		pixmapPath = ":/new/imageFile/photoError.png";
	QFile file(pixmapPath);
	file.open(QIODevice::ReadOnly);
	QPixmap iconpixmap;
	iconpixmap.loadFromData(file.readAll());
	m_photoLabel->setPixmap(iconpixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));


	//////////////////////////////////////////////////////////
	QFrame *frame = new QFrame(this);
	m_nameLabel = new QLabel(frame);
	frame->setGeometry(80, 20, 460, 25);
	m_nameLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	m_nameLabel->setScaledContents(true);
	QHBoxLayout *hlayout = new QHBoxLayout;//创建一个水平布局管理器
	hlayout->setMargin(0);
	hlayout->setSpacing(5);
	frame->setLayout(hlayout);
	hlayout->addWidget(m_nameLabel);
	QString strliasName = m_desktopAppInfo.m_strAppAlias;
	if (strliasName.isEmpty())
		strliasName = m_desktopAppInfo.m_strAppName;

	m_nameLabel->setText(AppCommFun::getElidedText(strliasName, 30));
	m_nameLabel->setStyleSheet(QString::fromLocal8Bit("font: 14px \"微软雅黑\";font-weight:bold;color: rgb(51, 51, 51);"));
	//资费
	if (m_desktopAppInfo.m_strAppFree.toFloat() == 0)
	{
		//freeStr = QString::fromLocal8Bit("免费");
		//freePhotStr = ":/new/imageFile/AppCenterPng/NullM.png";
	}
	else
	{
		QString freeStr;
		QString freePhotStr;
		freeStr = QString::fromLocal8Bit("收费");
		freePhotStr = ":/new/imageFile/AppCenterPng/changeM.png";

		//资费
		QToolButton *freeToolButton = new QToolButton;
		freeToolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
		freeToolButton->setAutoRaise(true);
		freeToolButton->setIcon(QIcon(QPixmap(freePhotStr).scaled(22, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
		hlayout->addWidget(freeToolButton);
		freeToolButton->setText(freeStr);
		freeToolButton->setStyleSheet(QString::fromLocal8Bit("color: #666666; font: 14px \"微软雅黑\";background: transparent;border:none"));
	}
	//会员

	QStringList strList = m_desktopAppInfo.m_strListAppVipList;
	if (strList.size() > 0 && strList.at(0) != "0")
	{
		QToolButton *vipToolButton = new QToolButton;
		vipToolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
		vipToolButton->setAutoRaise(true);
		vipToolButton->setIcon(QIcon(QPixmap(":/new/imageFile/AppCenterPng/vipManagement").scaled(22, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
		hlayout->addWidget(vipToolButton);
		vipToolButton->setText(QString::fromLocal8Bit("会员尊享"));
		vipToolButton->setStyleSheet(QString::fromLocal8Bit("color: #666666; font: 14px \"微软雅黑\";background: transparent;border:none"));
	}
	hlayout->addStretch();
///////////////////////////////////////////////////
	
	if (!m_desktopAppInfo.m_bAppType && !m_desktopAppInfo.m_strAppDownloadUrl.isEmpty())//cs  应用
	{
		QLabel *appSizeLabel = new QLabel(this);
		appSizeLabel->setAlignment(Qt::AlignHCenter);
		appSizeLabel->setAttribute(Qt::WA_TranslucentBackground, true);
		appSizeLabel->setGeometry(680, 35, 50, 20);
		appSizeLabel->setStyleSheet(QString::fromLocal8Bit("font: 14px \"微软雅黑\";color: rgb(51,51,51);"));
		QString strAppSize;
		int intAppSize = m_desktopAppInfo.m_intAppSize;
		if (intAppSize <= 0)
		{
			strAppSize = "--";
		}
		else
			strAppSize.append(appSizeDataString(intAppSize));
		appSizeLabel->setText(strAppSize);
	}
	
	

	m_particulars->setStyleSheet(QString::fromLocal8Bit("background:transparent;border-width:0;border-style:outset;color: rgb(102, 102, 102);font: 13px \"微软雅黑\";"));
	m_particulars->setGeometry(80, 45, 500, 25);
	QString strDesc = m_desktopAppInfo.m_strAppDesc;
	strDesc = strDesc.split(QRegExp("[\r\n]"), QString::SkipEmptyParts).join("");
	m_particulars->setText(AppCommFun::getElidedText(strDesc, 35));
	QLabel *label = new QLabel(this);
	label->setStyleSheet("background-color: rgb(235, 235, 235);");
	label->setGeometry(20, 90, 960, 1);
	connectThread();
}


void AppCenterTools::connectThread()
{
	
	AppCenterWidget *appCenterPr = RightClassAppWidget::GetInstance()->getAppCenterWidget();
	if (appCenterPr)
	{
		connect(this, SIGNAL(addDownloadItemSignal(AppDownLoadItem *)), appCenterPr, SLOT(addDownloadItem(AppDownLoadItem *)));
		connect(this, SIGNAL(clicked()), appCenterPr, SLOT(openAppParticularsSlot()));
	}

	if(m_isHotApp == 0 || m_isHotApp == 1) statusButton->hide();
	this->setObjectName("AppCenterTools");
	this->setStyleSheet("QPushButton#AppCenterTools{background: transparent;}");
	if (m_desktopAppInfo.m_bAppIsInstall)
	{
		if (m_isHotApp == 3)
		{
			statusChanged(E_UNINSTALL,true);
		}
		else
		{
			statusChanged(E_OPEN, true);
		}
	}
	else
	{
		statusChanged(E_INSTALL, true);
	}


}


void AppCenterTools::unstallFlish(AppDataInfo , bool flag)
{
	if (flag)
	{
		statusChanged(E_INSTALL);
	}
	else
		statusChanged(E_OPEN);
}

AppCenterTools::~AppCenterTools()
{

}

//窗口的进入事件(enterEvent)
void AppCenterTools::enterEvent(QEvent *event)
{
	if (0 == m_isHotApp)
	{
		m_particulars->hide();
		statusButton->show();
	} else if (1 == m_isHotApp)
	{
		m_numberLabel->hide();
		m_nameLabel->setText(hotAppName_2);
		m_photoLabel->show();
		m_particulars->show();
		statusButton->show();
	}
	else if (2 == m_isHotApp)
	{
		
	}
	
	return QWidget::enterEvent(event);
}

//窗口的离开事件（leaveEvent）
void AppCenterTools::leaveEvent(QEvent *event)
{
	
	if (0 == m_isHotApp)
	{
		statusButton->hide();
		m_particulars->show();
	} else if (1 == m_isHotApp)
	{
		statusButton->hide();
		m_particulars->hide();
		m_photoLabel->hide();
		m_nameLabel->setText(hotAppName_1);
		m_numberLabel->show();
	}
	else if (2 == m_isHotApp)
	{
		
	}
	return QWidget::enterEvent(event);
}
//void AppCenterTools::paintEvent(QPaintEvent* event)
//{
//
//	return QPushButton::paintEvent(event);
//}

//如果有卸载或者安装中修改按钮状体
bool AppCenterTools::uuChangedStatus(APPSTATUS appstatus)
{
	//更新
	DownLoadManager*	pDownloadManager = RightClassAppWidget::getDownLoadManager();
	AppDownLoadThread *downloadThread = pDownloadManager->isRightManager(m_desktopAppInfo.m_strAppName, m_desktopAppInfo.m_strAppId);
	if (downloadThread != NULL)
	{
		disconnect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), this, SLOT(onDownloadStatusChanged(APPDOWNLOADETYPE)));
		connect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), this, SLOT(onDownloadStatusChanged(APPDOWNLOADETYPE)));
		//0 热门应用的button  1 推荐应用的button   2应用类别的button   3 是应用管理
		//安装中
		//		1.安装，打开，卸载，升级

		if (downloadThread->isRunning())
		{
			if (m_isHotApp == 0 || m_isHotApp == 1 || m_isHotApp == 2)
			{
				switch (appstatus)
				{
				case E_INSTALL:
				{
					statusChanged(E_INSTALLING);
					return true;
				}
				case E_INSTALLING:
					break;
				case E_INSTALLDEFEAT:
					break;
				case E_UNINSTALL:
					break;
				case E_UNINSTALLING:
					break;
				case E_UNINSTALLDEFEAT:
					break;
				case E_OPEN:
				{
					statusChanged(E_UPDATEING);
					return true;
				}
				case E_UPDATE:
					break;
				case E_UPDATEING:
					break;
				case E_UPDATEDEFEAT:
					break;
				default:
					break;
				}
			}
			else if (m_isHotApp == 3)
			{
				switch (appstatus)
				{
				case E_INSTALL:
					break;
				case E_INSTALLING:
					break;
				case E_INSTALLDEFEAT:
					break;
				case E_UNINSTALL:
				{
					statusChanged(E_UNINSTALL);
					statusButton->setEnabled(false);
					return true;
				}
				case E_UNINSTALLING:
					break;
				case E_UNINSTALLDEFEAT:
					break;
				case E_OPEN:
					break;
				case E_UPDATE:
				{
					statusChanged(E_UPDATEING);
					return true;
				}
				case E_UPDATEING:
					break;
				case E_UPDATEDEFEAT:
					break;
				default:
					break;
				}
			}
		}
		else
		{
			//qDebug() << "aaaaaaaa";
		}
	}
	UnInstallThread *unInstallThread = pDownloadManager->isRightUninstallManager(m_desktopAppInfo.m_strAppId);
	if (unInstallThread != NULL)
	{
		connect(unInstallThread, SIGNAL(uninstallationCompleteSiganl(AppDataInfo, bool)), this,
			SLOT(unInstallSucceed(AppDataInfo, bool)));
		if (unInstallThread->isRunning())
		{
			//0 热门应用的button  1 推荐应用的button   2应用类别的button   3 是应用管理
			//卸载中
			//		1.打开，卸载，升级

			if (m_isHotApp == 0 || m_isHotApp == 1 || m_isHotApp == 2)
			{
				switch (appstatus)
				{
				case E_INSTALL:
					break;
				case E_INSTALLING:
					break;
				case E_INSTALLDEFEAT:
					break;
				case E_UNINSTALL:
					break;
				case E_UNINSTALLING:
					break;
				case E_UNINSTALLDEFEAT:
					break;
				case E_OPEN:
				{
					statusChanged(E_UNINSTALLING);
					return true;
				}
				case E_UPDATE:
					break;
				case E_UPDATEING:
					break;
				case E_UPDATEDEFEAT:
					break;
				default:
					break;
				}
			}
			else if (m_isHotApp == 3)
			{

				switch (appstatus)
				{
				case E_INSTALL:
					break;
				case E_INSTALLING:
					break;
				case E_INSTALLDEFEAT:
					break;
				case E_UPDATE:
				case E_UNINSTALL:
				{
					statusChanged(E_UNINSTALLING);
					return true;
				}
				case E_UNINSTALLING:
					break;
				case E_UNINSTALLDEFEAT:
					break;
				case E_OPEN:
					break;
				case E_UPDATEING:
					break;
				case E_UPDATEDEFEAT:
					break;
				default:
					break;
				}
			}
		}
	}
	return false;
}



//按钮状态
void AppCenterTools::statusChanged(APPSTATUS flag, bool isAdd)
{
	if (isAdd)
	{
		if (uuChangedStatus(flag))
			return;
	}


	m_APPSTATUSFlag = flag;
	statusButton->hideToolButton();
	QString fontSize = "14";
	QString rSize = "2";
	if (2 == m_isHotApp ||  3 == m_isHotApp)
	{
		fontSize = "18";
		rSize = "4";
	}
	switch (m_APPSTATUSFlag)
	{
	case  E_INSTALL:
	{
		m_desktopAppInfo.m_bAppIsInstall = false;
		statusButton->setText(QString::fromLocal8Bit("安装"));
		statusButton->setStyleSheet(QString::fromLocal8Bit(
			"QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));\
			border-radius:%1px;font: %2px \"微软雅黑\";color:rgba(255, 255, 255, 1);}\
			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\
			border-radius:%3px;font: %4px \"微软雅黑\";color:rgba(255, 255, 255, 1);}\
												").arg(rSize).arg(fontSize).arg(rSize).arg(fontSize));
		statusButton->setEnabled(true);
		
		break;
	}
	case  E_INSTALLDEFEAT:
		break;
	case  E_INSTALLING:
	{
		statusButton->setText(QString::fromLocal8Bit("安装中"));
		statusButton->setEnabled(false);
		statusButton->setStyleSheet(QString::fromLocal8Bit(
			"QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(128, 209, 254, 1), stop:1 rgba(143, 197, 246, 1));\
			border-radius:%1px;font: %2px \"微软雅黑\";color:rgba(255, 255, 255, 1);}\
			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\
			border-radius:%3px;font: %4px \"微软雅黑\";color:rgba(255, 255, 255, 1);}\
															").arg(rSize).arg(fontSize).arg(rSize).arg(fontSize));
		break;
	}
	case  E_OPEN:
	{
		m_desktopAppInfo.m_bAppIsInstall = true;
		statusButton->setText(QString::fromLocal8Bit("打开"));
		statusButton->setStyleSheet(QString::fromLocal8Bit(
			"QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 1), stop:1 rgba(244, 244, 244, 1));\
			 border: 1px solid #DEDEDE;border-radius:%1px;font: %2px \"微软雅黑\";color: #333333;}\
			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 1), stop:1 rgba(251, 251, 251, 1));\
			border: 1px solid #DEDEDE;border-radius:%3px;font: %4px \"微软雅黑\";color: #333333;}\
															").arg(rSize).arg(fontSize).arg(rSize).arg(fontSize));
		statusButton->setEnabled(true);
		break;
	}
	case  E_UNINSTALL:
	{
		m_desktopAppInfo.m_bAppIsInstall = true;
		statusButton->setText(QString::fromLocal8Bit("卸载"));
		statusButton->setStyleSheet(QString::fromLocal8Bit(
			"QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 1), stop:1 rgba(244, 244, 244, 1));\
						 border: 1px solid #DEDEDE;border-radius:%1px;font: %2px \"微软雅黑\";color: #333333;}\
						 			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 1), stop:1 rgba(251, 251, 251, 1));\
												border: 1px solid #DEDEDE;border-radius:%3px;font: %4px \"微软雅黑\";color: #333333;}\
																											").arg(rSize).arg(fontSize).arg(rSize).arg(fontSize));
		statusButton->setEnabled(true);
		break;
	}
	case  E_UNINSTALLDEFEAT:
		break;
	case  E_UNINSTALLING:
		statusButton->setStyleSheet(QString::fromLocal8Bit("QPushButton{ background-color: rgb(253, 253, 253);border-style:none;\
					font: %1px \"微软雅黑\";color:rgba(51, 51, 51, 1);}").arg(fontSize));
		statusButton->setEnabled(false);
		statusButton->setText(QString::fromLocal8Bit("卸载中"));
		if (0 == m_isHotApp)
		{
			statusButton->setStyleSheet(QString::fromLocal8Bit(
				"QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(128, 209, 254, 1), stop:1 rgba(143, 197, 246, 1));\
							border-radius:%1px;font: %2px \"微软雅黑\";color:rgba(255, 255, 255, 1);}\
										QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\
													border-radius:%3px;font: %4px \"微软雅黑\";color:rgba(255, 255, 255, 1);}\
																												").arg(rSize).arg(fontSize).arg(rSize).arg(fontSize));
		}


		break;
	case  E_UPDATE:
		isUpdate = true;
		statusButton->setEnabled(true);
		statusButton->setStyleSheet(QString::fromLocal8Bit("QPushButton{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(82, 219, 176, 1), stop:1 rgba(53, 190, 127, 1));border-radius:4px;font: 18px \"微软雅黑\";color:rgba(255, 255, 255, 1);}QPushButton:hover,pressed{  background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(100, 223, 184, 1), stop:1 rgba(74, 197, 141, 1));border-radius:4px; font: 18px \"微软雅黑\";color:rgba(255, 255, 255, 1);}"));

		statusButton->setText(QString::fromLocal8Bit("升级"));
		statusButton->showToolBtutton();
		break;
	case  E_UPDATEDEFEAT:
		break;
	case  E_UPDATEING:
	{
		isUpdate = true;
		statusButton->setEnabled(false);
		statusButton->setText(QString::fromLocal8Bit("升级中"));
		statusButton->setStyleSheet(QString::fromLocal8Bit("QPushButton{ background-color: rgb(253, 253, 253);border-style:none;\
														   					font: %1px \"微软雅黑\";color:rgba(51, 51, 51, 1);}").arg(fontSize));
		if (0 == m_isHotApp)
		{
			statusButton->setStyleSheet(QString::fromLocal8Bit(
				"QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(128, 209, 254, 1), stop:1 rgba(143, 197, 246, 1));\
							border-radius:%1px;font: %2px \"微软雅黑\";color:rgba(255, 255, 255, 1);}\
										QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\
													border-radius:%3px;font: %4px \"微软雅黑\";color:rgba(255, 255, 255, 1);}\
																												").arg(rSize).arg(fontSize).arg(rSize).arg(fontSize));
		}
		break;
	}
	default:
		break;

	}
	emit toolsStatusChanged(m_APPSTATUSFlag);

}


void AppCenterTools::updateUninstall()
{
	if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("确定要卸载 %1 吗？").arg(m_desktopAppInfo.m_strAppAlias.isEmpty() ? m_desktopAppInfo.m_strAppName : m_desktopAppInfo.m_strAppAlias)) == QDialog::Accepted)
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "AUN004" ,m_desktopAppInfo.m_strAppId + "-" + m_desktopAppInfo.m_strAppOnLineVerson);
		statusChanged(E_UNINSTALLING);
		uninstallApp();
	}
}

void AppCenterTools::clickedStautusButton()
{
	switch (m_APPSTATUSFlag)
	{
	case  E_INSTALL:
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M01", "OP001", "AAC009",m_desktopAppInfo.m_strAppId + "-" + m_desktopAppInfo.m_strAppOnLineVerson);
		downloadApp();	
		break;
	}
	case  E_INSTALLDEFEAT:
		break;
	case  E_INSTALLING:
	{
		break;
	}
	case  E_OPEN:
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M01", "OP001", "AAC012", m_desktopAppInfo.m_strAppId + "-" + m_desktopAppInfo.m_strAppOnLineVerson);
		RightClassAppWidget *ptr = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance());
		if (ptr)
			ptr->openApp(m_desktopAppInfo, "AAC012");
		break;
	}
	case  E_UNINSTALL:
	{
		updateUninstall();
		
		break;
	}
	case  E_UNINSTALLDEFEAT:
		break;
	case  E_UNINSTALLING:
		break;
	case  E_UPDATE:
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "AUP003", m_desktopAppInfo.m_strAppId + "-" + m_desktopAppInfo.m_strAppCurrentVerson +"-" + m_desktopAppInfo.m_strAppOnLineVerson);
		downloadApp();
		break;
	case  E_UPDATEDEFEAT:
		break;
	case  E_UPDATEING:
		break;
	default:
		break;

	}
}

void AppCenterTools::downloadApp()
{
	
	RightClassAppWidget *ptr = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance()); // 下载完成只链接一次
	if (!ptr) return;

	if (m_isHotApp == 3)
		statusChanged(E_UPDATEING);
	else
		statusChanged(E_INSTALLING);

	QString catid = m_desktopAppInfo.mStrAppCateId;
	QString appId = m_desktopAppInfo.m_strAppId;
	
	if (!m_desktopAppInfo.m_bAppType && !m_desktopAppInfo.m_strAppDownloadUrl.isEmpty())//cs  应用
	{
		DownLoadManager*	pDownloadManager = RightClassAppWidget::getDownLoadManager();
		AppDownLoadThread *downloadThread;
		//cs 应用下载 防止多次 添加下载 线程
		if (startDownloadAppSlotFLag)
		{
			int numberFlag = 0;
			while (!(downloadThread = pDownloadManager->isRightManager(m_desktopAppInfo.m_strAppName, m_desktopAppInfo.m_strAppId)) || numberFlag ++ < 10)
			{
				Sleep(100);
			}
		}
		else
			downloadThread = pDownloadManager->isRightManager(m_desktopAppInfo.m_strAppName, m_desktopAppInfo.m_strAppId);
		if (downloadThread == NULL)
		{
			downloadThread = new AppDownLoadThread(m_desktopAppInfo);
			AppDownLoadItem *appDownLoadItem = new AppDownLoadItem( downloadThread);
			//appDownLoadAppWidget.addDownload(appDownLoadItem);
			
			disconnect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), this, SLOT(onDownloadStatusChanged(APPDOWNLOADETYPE)));
			connect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), this, SLOT(onDownloadStatusChanged(APPDOWNLOADETYPE)));

		
			// 从url 中获取文件名，但不是都有效;
			QFileInfo fileInfo(QUrl::fromUserInput(m_desktopAppInfo.m_strAppDownloadUrl).path());
			QString appFileName = fileInfo.fileName();
			QString fileName = QApplication::applicationDirPath().append("/downloadApp/");
			QDir fileD(fileName);
			if (!fileD.exists())
				fileD.mkpath(fileName);
			fileName = fileName + appFileName + DOWNLOAD_FILE_SUFFIX;
			pDownloadManager->beginDownload(downloadThread, m_desktopAppInfo, fileName, 0, 0);
			downloadThread->start();

			Q_EMIT addDownloadItemSignal(appDownLoadItem);
		}
		else
		{
			disconnect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), this, SLOT(onDownloadStatusChanged(APPDOWNLOADETYPE)));
			connect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), this, SLOT(onDownloadStatusChanged(APPDOWNLOADETYPE)));
			if (!downloadThread->isRunning())
			{
				if (downloadThread->m_APPDOWNLOADETYPE != mapp_PAUSE)
				{
					downloadThread->reset();
					downloadThread->start();
				}else 
					downloadThread->continueDownload();
				
			}
			
		}
		
	}
	else // 网页 bs
	{
		m_desktopAppInfo.m_bAppIsInstall = true;
		AppCenterDatabase::instance()->updateApp(m_desktopAppInfo, true);
		RightClassAppWidget *ptr = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance());  //"parentWidget" very important. 获得父部件指针，同时需要类型强转.
		if (ptr)
		{
			ptr->flushButton(m_desktopAppInfo.mStrAppCateId, false);
		}
		//bs没有升级
		statusChanged(E_OPEN);
		
	}
	emit startDownloadAppSignal(appId);
}

void AppCenterTools::startDownloadAppSlot(QString appId)
{
	if (m_desktopAppInfo.m_strAppId == appId && m_APPSTATUSFlag == E_INSTALL)
	{
		startDownloadAppSlotFLag = true;
		clickedStautusButton();
		startDownloadAppSlotFLag = false;
	}
			
}


//修改状态 下载状态
void AppCenterTools::onDownloadStatusChanged(APPDOWNLOADETYPE type)
{
	switch (type)
	{
	case mapp_DOWNLOADING://下载中
	case mapp_FINISH:		//安装中
	{
		if (m_desktopAppInfo.m_bAppIsInstall)
			statusChanged(E_UPDATEING);
		else
			statusChanged(E_INSTALLING);
		break;
	}
	case mapp_PAUSE:	//暂停中
	case mapp_TIMEOUTERROR:
	case mapp_ERROR:
	case mapp_INSTALLERROR://安装错误
	case mapp_CLOSE:
	{
		if (m_desktopAppInfo.m_bAppIsInstall)
		{
			if (type == mapp_TIMEOUTERROR || type == mapp_ERROR || type == mapp_INSTALLERROR)
			{
				ZcloudBigDataInterface::GetInstance()->produceData("M11", "OP000", "AUP005", m_desktopAppInfo.m_strAppId + "-" + QString::number(type));
			}
			if (isUpdate && m_isHotApp == 3)
			{
				//已安装
				statusChanged(E_UPDATE);
			}
			else
			{
				//已安装 安装失败
				if (m_isHotApp == 3)
				{
					statusChanged(E_UNINSTALL);
				}
				else
				{
					statusChanged(E_OPEN);
				}
			}
		}
		else
		{
			//安装失败
			if (type == mapp_TIMEOUTERROR || type == mapp_ERROR || type == mapp_INSTALLERROR)
			{
				//安装错误
				ZcloudBigDataInterface::GetInstance()->produceData("M11", "OP001", "AAC011", m_desktopAppInfo.m_strAppId + "-" + QString::number(type));
			}
			statusChanged(E_INSTALL);
		}
		break;
	}
	case mapp_INSTALLFINLSH://安装完成
	{
		if (m_isHotApp == 3)
		{
			//显示升级成功
			m_APPSTATUSFlag = E_OPEN;
			statusButton->setText(QString::fromLocal8Bit("升级成功"));
			ZcloudBigDataInterface::GetInstance()->produceData("M01", "OP000", "AUP004", m_desktopAppInfo.m_strAppId);
		}
		else
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M01", "OP001", "AAC010",m_desktopAppInfo.m_strAppId);
			statusChanged(E_OPEN);
		}
		AppCenterDatabase::instance()->findApp(m_desktopAppInfo);
		break;
	}
	
	default:
		break;
	}
}



void AppCenterTools::uninstallApp()
{
	RightClassAppWidget *ptr = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance());
	if (ptr)
	{
		if (!m_desktopAppInfo.m_bAppType && !m_desktopAppInfo.m_strAppDownloadUrl.isEmpty())//cs  应用
		{
			UnInstallThread *unInstallThread = new UnInstallThread(m_desktopAppInfo, NULL);
			connect(unInstallThread, SIGNAL(uninstallationCompleteSiganl(AppDataInfo, bool)), ptr,
				SLOT(installUnnstallSucessed(AppDataInfo)));
			connect(unInstallThread, SIGNAL(uninstallationCompleteSiganl(AppDataInfo, bool)), this,
				SLOT(unInstallSucceed(AppDataInfo, bool)));
			DownLoadManager *downLoadManger = RightClassAppWidget::getDownLoadManager();
			downLoadManger->beginUninstall(unInstallThread);
			unInstallThread->start();
		}
		else
		{
			//卸载地址为空 或者 bs 应用
			unInstallSucceed(m_desktopAppInfo, true);
			m_desktopAppInfo.m_bAppIsInstall = false;
			AppCenterDatabase::instance()->updateApp(m_desktopAppInfo, true);
			ptr->flushButton(m_desktopAppInfo.mStrAppCateId, false);
		}
	}
}

void AppCenterTools::unInstallSucceed(AppDataInfo, bool flag)
{
	if (flag)
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M01", "OP000", "AUN005", m_desktopAppInfo.m_strAppId);
		//卸载成功变为安装
		//应用管理界面变为卸载成功  其他界面变为安装状态
		if (m_isHotApp == 3)
		{
			statusButton->setText(QString::fromLocal8Bit("卸载完成"));
			this->setEnabled(false);
		}
		else
		{
			statusChanged(E_INSTALL);
		}
	}
	else
	{
		//卸载失败
		//应用管理界面变为卸载  其他界面变为打开状态
		ZcloudBigDataInterface::GetInstance()->produceData("M01", "OP000", "AUN006", m_desktopAppInfo.m_strAppId);
		if (m_isHotApp == 3)
		{
			if (isUpdate)
			{
				statusChanged(E_UPDATE);
			}else
				statusChanged(E_UNINSTALL);
		}
		else
		{
			statusChanged(E_OPEN);
		}
		
	}
}

void AppCenterTools::onRecommended()
{
     ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "AFP004", m_desktopAppInfo.m_strAppId);
}


































