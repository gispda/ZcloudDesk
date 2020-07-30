#include "AppCenterComponent.h"
#include <QScrollBar>
#include <QApplication>
#include "ZhicloudApp.h"
#include "ZcloudCommon.h"
#include "AppCenterTools.h"
#include "RightClassAppWidget.h"
#include "DownloadFile/DownLoadManager.h"
#include "qt_windows.h"
#include <QFileInfo>
#include <QDir>
#include <QPainterPath>
#include "ZcloudBigData.h"


extern UserInfoStruct app_userInfo;

//#define   SCROLLBARSTYESHEET  "QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"

AppCenterComponent::AppCenterComponent(QObject *parent)
	: QObject(parent)
{
}

AppCenterComponent::~AppCenterComponent()
{
}




///////////////////////////////////////////////////////////////////////////

SliderWidget::SliderWidget(QWidget *parent)
	:QWidget(parent)
{
	listApp.clear();
	//QPushButton *button = new QPushButton("aaaaaaaa", this);
	//button->resize(682, 226);
}
SliderWidget::~SliderWidget()
{

}




void SliderWidget::addApp(AppCenterTools *appCenterTools)
{
	listApp.push_back(appCenterTools);
	appCenterTools->setParent(this);
	//QStringList strList = appCenterTools->getDesktopAppInfo().m_strListAppVipList;
	//if (strList.size() > 0 && strList.at(0) != 0)
	//{
	//	QLabel *vipLable = new QLabel(this);
	//	vipLable->setPixmap(QPixmap(":/new/imageFile/appCenterImage/VipClass.png"));
	//	appCenterTools->vipLabel = vipLable;
	//	vipLable->setAttribute(Qt::WA_TranslucentBackground);
	//}
	resetInterface();
}

void SliderWidget::resetInterface()
{
	for (int i = 0; i < listApp.length(); ++i)
	{
		listApp[i]->move(i % 3 * listApp[i]->width(), i / 3  * (listApp[i]->height() + 20));
		listApp[i]->show();
	
	}
}

void SliderWidget::clearButton()
{
	foreach(AppCenterTools *appCenterTools, listApp)
	{
		if (appCenterTools)
		{
			appCenterTools->disconnect();
			appCenterTools->deleteLater();
			appCenterTools = NULL;
		}
		
	}
	listApp.clear();
}


/////////////////////////////////////////////////////////////////////////
PhotoWidget::PhotoWidget(QWidget *parent)
	:QWidget(parent)
	, m_rightButton(new QPushButton(this))
	, m_leftButton(new QPushButton(this))
{

	this->resize(960, 200);//0,72
	totalWidget = new QWidget(this);
	totalWidget->setFocusPolicy(Qt::NoFocus);
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, [this]()
	{
		if (wideget_move)
		{
			int newIndex = current_index + 1;
			setPhoto(newIndex);
		}
	});


	m_rightButton->setGeometry(910, 80, 40, 40);
	m_leftButton->setGeometry(10, 80, 40, 40);
	m_leftButton->setStyleSheet("QPushButton{border-image: url(:/new/imageFile/AppCenterPng/left_nor.png);background: transparent;}\
							  							   	QPushButton:hover{border-image: url(:/new/imageFile/AppCenterPng/left_hov.png);}\
																							QPushButton:pressed{border-image: url(:/new/imageFile/AppCenterPng/left_hov.png);};");
	m_rightButton->setStyleSheet("QPushButton{border-image: url(:/new/imageFile/AppCenterPng/right_nor.png);background: transparent;}\
							   							   QPushButton:hover{border-image: url(:/new/imageFile/AppCenterPng/right_hov.png);}\
														   							   QPushButton:pressed{border-image: url(:/new/imageFile/AppCenterPng/right_hov.png);};");
	m_rightButton->setFocusPolicy(Qt::NoFocus);
	m_leftButton->setFocusPolicy(Qt::NoFocus);
	m_rightButton->raise();
	m_leftButton->raise();
	connect(m_rightButton, SIGNAL(clicked()), this, SLOT(rightPhotoSlot()));
	connect(m_leftButton, SIGNAL(clicked()), this, SLOT(leftPhotoSlot()));
}

PhotoWidget::~PhotoWidget()
{

}

bool PhotoWidget::eventFilter(QObject *target, QEvent *e)
{
	if (e->type() == QEvent::MouseButtonRelease)
	{
		for (int i = 0; i < labelListPhoto.size(); i++)
		{
			QLabel *label = labelListPhoto.at(i);
			if (label == target)
			{
				if (current_index != i)
				{
					if (wideget_move)
					{
						setPhoto(i);
					}
				}
				else
				{
					if (sliderInfoList.size() >= i)
					{
						SliderInfo sliderInfo = sliderInfoList.at(i);
						ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "AFP002", sliderInfo.m_strSliderTarget);
						if (sliderInfo.m_bSliderIsApp)
						{
							emit openAppParticularsSig(sliderInfo.m_strSliderTarget);
						}
						else
						{
							if (sliderInfo.m_bAppIsDefaultWeb)
							{
								QDesktopServices::openUrl(QUrl::fromUserInput(sliderInfo.m_strSliderTarget));
							}
							else
							{
								QStringList paramsList;
								paramsList << "" << sliderInfo.m_strSliderId << "" << sliderInfo.m_strSliderTarget << "";
								QProcess::startDetached(QApplication::applicationDirPath() + "/ZBrowser.exe", paramsList);
							}
						}
					}
				}
				break;
			}
		}
	}
	return QWidget::eventFilter(target, e);
}

void PhotoWidget::keyPressEvent(QKeyEvent *event)
{
	if (wideget_move) {
		switch (event->key()) {
		case Qt::Key_Left:
		case Qt::Key_Up:
		{
			//if (current_index > 1) {
			leftPhotoSlot();
			//	}
			break;
		}
		case Qt::Key_Right:
		case Qt::Key_Down:
		{
			//	if (current_index < labelListPhoto.size() - 2) {
			rightPhotoSlot();
			//	}
			break;
		}
		default:
			break;
		}
	}
}



void PhotoWidget::enterEvent(QEvent * e)
{
	if (labelListPhoto.size() > 3)
	{
		m_rightButton->show();
		m_leftButton->show();
	}
	else
	{
		m_rightButton->hide();
		m_leftButton->hide();
	}
	QWidget::enterEvent(e);
}

void PhotoWidget::leaveEvent(QEvent * e)
{

	m_rightButton->hide();
	m_leftButton->hide();
	QWidget::leaveEvent(e);
}
void PhotoWidget::leftPhotoSlot()
{
	if (wideget_move)
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "AFP007");
		int newIndex = current_index - 1;
		setPhoto(newIndex);
	}
}

void PhotoWidget::rightPhotoSlot()
{
	if (wideget_move)
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "AFP008");
		int newIndex = current_index + 1;
		setPhoto(newIndex);
	}
}



void PhotoWidget::setPhoto(int newLabelIndex)
{
	setLabelMove(false);
	if (newLabelIndex < labelListPhoto.size())
	{
		int oleLabelIndex = current_index;
		current_index = newLabelIndex;
		moveCurrentPage(oleLabelIndex < current_index);
		emit chooseLabelSignal(current_index - 1);
	}
	setLabelMove(true);
}

void PhotoWidget::addPhoto(SliderInfo sliderInfo)
{
	sliderInfoList << sliderInfo;
	QLabel *label = new QLabel(QString::fromLocal8Bit("label"),totalWidget);
	label->resize(960,200);
	label->setAlignment(Qt::AlignHCenter);
	label->installEventFilter(this);

	QFile file(sliderInfo.m_strSliderImgPath);
	file.open(QIODevice::ReadOnly);
	QPixmap pixmap;
	pixmap.loadFromData(file.readAll());
	file.close();


	QPixmap temp = pixmap.scaled(960, 200, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	//QPixmap temp(pixmap.size());
	//temp.fill(Qt::transparent);
	//QPainter p1(&temp);
	//p1.setCompositionMode(QPainter::CompositionMode_Source);
	//p1.drawPixmap(0, 0, pixmap);
	//p1.setCompositionMode(QPainter::CompositionMode_DestinationIn);
	//p1.fillRect(temp.rect(), QColor(255, 255, 255, 60));
	//p1.end();
	//pixmap = temp;

	label->setPixmap(temp);
	labelListPhoto.append(label);
	label->show();
	resetInterface();
}

void PhotoWidget::addFlish()
{
	if (sliderInfoList.size() > 0 )
	{
		sliderInfoList.insert(0, sliderInfoList.last());
		sliderInfoList.append(sliderInfoList.at(1));


		//前边添加 倒数第一张 
		QLabel *label = new QLabel(totalWidget);
		label->setAlignment(Qt::AlignHCenter);
		label->installEventFilter(this);
		label->resize(960, 200);
		label->setPixmap(QPixmap(sliderInfoList.at(0).m_strSliderImgPath ).scaled(960, 200, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
		labelListPhoto.insert(0, label);

		//后边添加 第一张
		QLabel *labelFilst = new QLabel(totalWidget);
		labelFilst->setAlignment(Qt::AlignHCenter);
		labelFilst->resize(960, 200);
		labelFilst->installEventFilter(this);
		labelFilst->setPixmap(QPixmap(sliderInfoList.last().m_strSliderImgPath).scaled(960, 200, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
		labelListPhoto.append(labelFilst);

		resetInterface();
		if (labelListPhoto.size() <= 1)
		{
			m_rightButton->hide();
			m_leftButton->hide();
		}
	}
	if (sliderInfoList.size() > 3)
		timer->start(8000);
}

void PhotoWidget::resetInterface()
{
	totalWidget->setGeometry(0, 0, labelListPhoto.size() * 960, this->height());
	
	for (int i = 0; i < labelListPhoto.size(); ++i)
	{
		labelListPhoto[i]->move(i * 960, 0);
		labelListPhoto[i]->show();
	}
	totalWidget->show();
}

void PhotoWidget::setLabelMove(bool enable)
{
	wideget_move = enable;
}

void PhotoWidget::moveCurrentPage(bool direction)
{
	
	int current_pos_x = totalWidget->x();    //label position
	int dest_pos_x = - 960 * current_index ;
	if (direction) {
		while (current_pos_x > dest_pos_x) {
			totalWidget->move( current_pos_x - 240, 0);
			current_pos_x = totalWidget->x();
			qApp->processEvents(QEventLoop::AllEvents);
		}
	}
	else {
		while (current_pos_x < dest_pos_x) {
			totalWidget->move(current_pos_x + 240, 0);
			current_pos_x = totalWidget->x();
			qApp->processEvents(QEventLoop::AllEvents);
		}
	}
	

	//第一张 前一张
	if (current_index == 0)
	{

		current_index = labelListPhoto.size() - 2;
		
	}
	//最后一张得后一张
	else if (current_index == (labelListPhoto.size() - 1))
	{
		current_index = 1;
	}
	totalWidget->move(- 960 * current_index, 0);
	totalWidget->show();
}

void PhotoWidget::clearLabel()
{
	while (!wideget_move)
		::Sleep(1);
	setLabelMove(false);
	timer->stop();
	sliderInfoList.clear();
	foreach(QLabel *label, labelListPhoto)
	{
		label->deleteLater();
	}
	labelListPhoto.clear();
	current_index = 1;
	setLabelMove(true);
}



//下载 列表widget
AppDownLoadAppWidget::AppDownLoadAppWidget(QWidget *parent /*= 0*/)
	:AppCommWidget("", false, parent)
{
	this->resize(416, 516);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	m_widget->setStyleSheet(QString::fromLocal8Bit("QWidget#AppCommWidgetWidget{background-color: rgb(252, 252, 252);border-top-left-radius:8px;border-top-right-radius:8px;}"));

	m_doanloadSizeLabel = new QLabel(QString::fromLocal8Bit("下载管理(0)"), m_widget);
	m_doanloadSizeLabel->setGeometry(20, 12, 100, 30);
	m_doanloadSizeLabel->setStyleSheet(QString::fromLocal8Bit("font: 14px \"微软雅黑\";color:rgb(51, 51, 51);background: transparent;"));
	QPushButton * closeButton = new QPushButton(m_widget);
	closeButton->setAttribute(Qt::WA_TranslucentBackground, true);
	closeButton->setStyleSheet(QString::fromLocal8Bit(
		"QPushButton{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_nor.png);}\
				QPushButton:hover{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_hov.png);}\
						QPushButton:pressed{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_hov.png);};\
																"));
	closeButton->setGeometry(358, 12, 32, 28);
	connect(closeButton, &QPushButton::clicked, [this]()
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "ADL007");
		this->hide();
	});


	QScrollArea *downloadScrollArea = new QScrollArea(m_widget);
	downloadScrollArea->setObjectName("downloadScrollArea");
	downloadListWidget = new QWidget;
	downloadListWidget->setObjectName("downloadListWidget");
	downloadListWidget->setStyleSheet("QWidget#downloadListWidget{background-color: rgb(255, 255, 255);border-style:none ;border-bottom-left-radius:8px;border-bottom-right-radius:8px;}");
	downloadScrollArea->setFocusPolicy(Qt::NoFocus);
	downloadListWidget->setFocusPolicy(Qt::NoFocus);
	downloadScrollArea->setStyleSheet("QScrollArea#downloadScrollArea{background-color: rgb(255, 255, 255);border-style:none ;border-bottom-left-radius:8px;border-bottom-right-radius:8px;}");
	downloadScrollArea->verticalScrollBar()->setStyleSheet(SCROLLBARSTYESHEET);
	downloadScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	downloadScrollArea->setGeometry(0, 50, 400, 450);
	downloadScrollArea->setWidget(downloadListWidget);

	noDownloadLabel = new QLabel(m_widget);//border-image:
	noDownloadLabel->setStyleSheet("border-image: url(:/new/imageFile/AppCenterPng/img_xz_wxz.png);");
	noDownloadLabel->setGeometry(123, 130, 170, 149);
	noDownloadLabel->raise();
	DownLoadManager *downLoadManager = RightClassAppWidget::getDownLoadManager();
	if (downLoadManager)
	{
		int downloadCount = downLoadManager->m_pDownloadThreads.size();
		for (int i = 0; i < downloadCount; i ++)
		{
			AppDownLoadThread *downloadThread = downLoadManager->m_pDownloadThreads.at(i);
			AppDownLoadItem *appDownLoadItem = new AppDownLoadItem( downloadThread);
			appDownLoadItem->onStatusChanged(downloadThread->downloadedSuccessfully());
			appDownLoadItem->onDownloadProcess(downloadThread->m_bytesReceived + downloadThread->m_bytesCurrentReceived, downloadThread->m_bytesTotal + downloadThread->m_bytesCurrentReceived);
			
			addDownload(appDownLoadItem);
		}
	}
}

AppDownLoadAppWidget::~AppDownLoadAppWidget()
{
	if (downloadListWidget)
	{
		downloadListWidget->deleteLater();
		downloadListWidget = NULL;
	}
}


void AppDownLoadAppWidget::showEvent(QShowEvent *e)
{
	this->setAttribute(Qt::WA_Mapped);
	QWidget::showEvent(e);
}

void AppDownLoadAppWidget::showWindow()
{
	this->show();
	for each (AppDownLoadItem *appDownLoadItem in listAppDownLoadItem)
	{
		appDownLoadItem->updateInfoLabel();
	}
}

void AppDownLoadAppWidget::focusOutEvent(QFocusEvent * e)
{
	this->hide();
	return QWidget::focusOutEvent(e);
}

void AppDownLoadAppWidget::addDownload(AppDownLoadItem *appDownLoadItem)
{
	if (appDownLoadItem)
	{
		
		appDownLoadItem->setParent(downloadListWidget);
		listAppDownLoadItem.insert(0,appDownLoadItem);
		//倒序
		//int j = 0;
		//for (int i = listAppDownLoadItem.size() - 1; i >= 0; i--)
		//	listAppDownLoadItem.at(i)->move(0, j++ * appDownLoadItem->height());
		connect(appDownLoadItem, SIGNAL(sigEndDownLoad()), this, SLOT(removeItem()), Qt::DirectConnection);
		connect(appDownLoadItem, &AppDownLoadItem::itemCownloadChange, [this]()
		{
			int downloadIngSize = 0;
			for each (AppDownLoadItem *appDownLoadItem in listAppDownLoadItem)
			{
				if (appDownLoadItem->getDownloadType() == mapp_DOWNLOADING)
				{
					downloadIngSize++;
				}
			}
			m_doanloadSizeLabel->setText(QString::fromLocal8Bit("下载管理(%1)").arg(downloadIngSize));
		});
		resetInterface();
	}
}

void AppDownLoadAppWidget::resetInterface()
{
	int widgetH = 0;
	int downLoadItemH = 80;
	if (listAppDownLoadItem.size() * downLoadItemH > 450)
	{
		widgetH = listAppDownLoadItem.size() * downLoadItemH;
	}
	else
		widgetH = 450;
	downloadListWidget->setMinimumHeight(widgetH);
	downloadListWidget->resize(400, widgetH);

	int i = 0;
	for each (AppDownLoadItem *appDownLoadItem in listAppDownLoadItem)
	{
		appDownLoadItem->move(1, i * downLoadItemH);
		appDownLoadItem->show();
		i++;
	}
	listAppDownLoadItem.size() ? noDownloadLabel->hide() : noDownloadLabel->show();
}

void AppDownLoadAppWidget::removeItem()
{
	AppDownLoadItem *appDownLoadItem = qobject_cast<AppDownLoadItem *>(sender());
	if (appDownLoadItem)
	{
		removeItemAt = listAppDownLoadItem.indexOf(appDownLoadItem);
		removeItemY = appDownLoadItem->y();
		
		listAppDownLoadItem.removeOne(appDownLoadItem);
		appDownLoadItem->hide();
		appDownLoadItem->deleteLater();
		appDownLoadItem = NULL;


		if ((removeItemAt + 1) < listAppDownLoadItem.size())
		{
			if (!m_closeTimer)
				m_closeTimer = new QTimer();
			connect(m_closeTimer, SIGNAL(timeout()), this, SLOT(removeItemMoveItem()));
			m_closeTimer->start(5);
		}
		else
		{
			if (m_closeTimer)
				m_closeTimer->stop();
			resetInterface();
		}
		//if (listAppDownLoadItem.size() == 0)
		//{
		//	if (!noDownloadLabel)
		//	{
		//		noDownloadLabel = new QLabel(this);//border-image:
		//		noDownloadLabel->setStyleSheet("border-image: url(:/new/imageFile/AppCenterPng/img_xz_wxz.png);");
		//		noDownloadLabel->setGeometry(123, 130, 170, 149);
		//		noDownloadLabel->raise();
		//		noDownloadLabel->show();
		//	}
		//}
	}
}

void AppDownLoadAppWidget::removeItemMoveItem()
{

	if (listAppDownLoadItem.at(removeItemAt)->y() > removeItemY)
	{
		for (int i = removeItemAt; i < listAppDownLoadItem.size(); i++)
		{
			AppDownLoadItem *appDownLoadItem = listAppDownLoadItem.at(i);
			appDownLoadItem->move(appDownLoadItem->x(), appDownLoadItem->y() - 1);
		}
		QApplication::processEvents();
	}
	else
	{
		m_closeTimer->stop();
		resetInterface();
	}
}


//下载 对话框 item
AppDownLoadItem::AppDownLoadItem( AppDownLoadThread *downloadThread , QWidget *parent)
	:QProgressBar(parent)
	, m_deskInfo(downloadThread->m_pData)
	, downloadPercentageLabel(new QLabel(this))
{
	//setMinimumSize(398, 80);
	//setMaximumSize(398, 80);
	this->resize(398, 80);
	this->setStyleSheet(
		"QProgressBar{background:transparent;border:0px;}"
		"QProgressBar::chunk{background:#DEF1FF;}");//border:1px solid black;
	this->setGeometry(0, 0, 400, 80);
	this->setTextVisible(false);
	this->setMaximum(100);
	this->setValue(0);

	QLabel *label = new QLabel(this);
	label->setStyleSheet("QLabel{background-color:rgba(222, 222, 222, 1);}");
	label->setGeometry(0, 79, 400, 1);


	QLabel *photoLabel = new QLabel(this);
	photoLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	photoLabel->setGeometry(19, 15, 50, 50);

	QString pixmapPath = m_deskInfo.m_strAppIconPath;
	QFileInfo fileInfo(pixmapPath);
	if (pixmapPath.isEmpty() || !fileInfo.exists())
		pixmapPath = ":/new/imageFile/photoError.png";
	QFile *file = new QFile(pixmapPath);
	file->open(QIODevice::ReadOnly);
	QPixmap iconpixmap;
	iconpixmap.loadFromData(file->readAll());

	photoLabel->setPixmap(iconpixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));

	SqueezeLabel *nameLabel = new SqueezeLabel(this);

	nameLabel->setText(m_deskInfo.m_strAppAlias.isEmpty() ? m_deskInfo.m_strAppName : m_deskInfo.m_strAppAlias);
	nameLabel->setStyleSheet(QString::fromLocal8Bit("background: transparent;color:#333333;font: 14px \"微软雅黑\";font-weight:bold;"));
	//nameLabel->setAlignment(Qt::AlignHCenter);
	nameLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	nameLabel->setGeometry(80, 15, 130, 22);

	continueDownloadButton = new QPushButton(this);
	reBeginDownloadButton = new QPushButton(this);
	endDownloadButton = new QPushButton(this);
	pauseDownloadButton = new QPushButton(this);

	continueDownloadButton->setFocusPolicy(Qt::NoFocus);
	reBeginDownloadButton->setFocusPolicy(Qt::NoFocus);
	endDownloadButton->setFocusPolicy(Qt::NoFocus);
	pauseDownloadButton->setFocusPolicy(Qt::NoFocus);
	endDownloadButton->raise();
	continueDownloadButton->setToolTip(QString::fromLocal8Bit("继续"));
	reBeginDownloadButton->setToolTip(QString::fromLocal8Bit("重新下载"));
	endDownloadButton->setToolTip(QString::fromLocal8Bit("关闭"));
	pauseDownloadButton->setToolTip(QString::fromLocal8Bit("暂停"));

	//progressBar = new QProgressBar(this);
	//progressBar->setStyleSheet(
	//	"QProgressBar {border-radius: 4px;background:#dddddd ;text-align: center;color:rgb(255,255,255);}"
	//	"QProgressBar::chunk {border-radius:4px;background:#2299fe;}");//border:1px solid black;
	//progressBar->setTextVisible(false);
	//progressBar->setMaximum(100);
	//progressBar->setValue(0);
	//progressBar->setGeometry(66, 36, 140, 4);

	downloadInfoLabel = new SqueezeLabel(this);
	downloadInfoLabel->setGeometry(80, 41, 240, 20);
	downloadInfoLabel->setStyleSheet("background: transparent;color:#666666;font: 14px \"微软雅黑\";");

	downloadPercentageLabel->setStyleSheet("background: transparent;color:#333333;font: 14px \"微软雅黑\";");
	downloadPercentageLabel->setGeometry(250, 30, 75, 20);

	continueDownloadButton->resize(24, 24);
	reBeginDownloadButton->resize(24, 24);
	endDownloadButton->resize(24, 24);
	pauseDownloadButton->resize(24, 24);

	continueDownloadButton->move(319, 28);
	reBeginDownloadButton->move(319, 28);
	pauseDownloadButton->move(319, 28);

	endDownloadButton->move(346, 28);
	continueDownloadButton->setStyleSheet("QToolTip{background:rgba(255,255,255,1);border:1px solid rgba(153, 153, 153, 1);}"
		"QPushButton{border-image: url(:/new/imageFile/AppCenterPng/down_start.png);}"
		"QPushButton:hover,pressed{border-image: url(:/new/imageFile/AppCenterPng/down_start_sel.png);}"
		
		);
	reBeginDownloadButton->setStyleSheet("QToolTip{background:rgba(255,255,255,1);border:1px solid rgba(153, 153, 153, 1);}"
		"QPushButton{border-image: url(:/new/imageFile/AppCenterPng/down_restart.png);}"
		"QPushButton:hover,pressed{border-image: url(:/new/imageFile/AppCenterPng/down_restart_sel.png);}"
		);
	endDownloadButton->setStyleSheet("QToolTip{background:rgba(255,255,255,1);border:1px solid rgba(153, 153, 153, 1);}"
		"QPushButton{border-image: url(:/new/imageFile/AppCenterPng/down_close_nor.png);}"
		"QPushButton:hover,pressed{border-image: url(:/new/imageFile/AppCenterPng/down_close _sel.png);}"
		
		);
	pauseDownloadButton->setStyleSheet("QToolTip{background:rgba(255,255,255,1);border:1px solid rgba(153, 153, 153, 1);}"
		"QPushButton{border-image: url(:/new/imageFile/AppCenterPng/down_suspend_nor.png);}"
		"QPushButton:hover,pressed{border-image: url(:/new/imageFile/AppCenterPng/down_suspend_sel.png);}"
		);

	connect(continueDownloadButton, SIGNAL(clicked()), this, SLOT(onDownLoadContinue()));
	connect(reBeginDownloadButton, SIGNAL(clicked()), this, SLOT(onDownLoadReBegin()));
	connect(endDownloadButton, SIGNAL(clicked()), this, SLOT(onDownLoadEnd()));
	connect(pauseDownloadButton, SIGNAL(clicked()), this, SLOT(onDownLoadPause()));

	continueDownloadButton->hide();
	reBeginDownloadButton->hide();
	pauseDownloadButton->show();

	// start timer for the download estimation
	m_downloadTime.start();

	connect(downloadThread, SIGNAL(signalDownloadProcess(qint64, qint64)), this, SLOT(onDownloadProcess(qint64, qint64)));
	connect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), this, SLOT(onStatusChanged(APPDOWNLOADETYPE)));

	//item直接操作线程
	connect(this, SIGNAL(sigEndDownLoad()), downloadThread, SLOT(closeDownload()), Qt::QueuedConnection);//停止下载
	connect(this, SIGNAL(sigPauseDownLoad()), downloadThread, SLOT(stopDownload()), Qt::QueuedConnection);//暂停下载
	connect(this, SIGNAL(sigContinueDownLoad()), downloadThread, SLOT(continueDownload()), Qt::QueuedConnection);//继续
	connect(this, SIGNAL(sigReBeginDownload()), downloadThread, SLOT(reDownload()), Qt::QueuedConnection);//重新下载			



}

void AppDownLoadItem::onDownLoadReBegin()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M01", "OP001", "ADL003",m_deskInfo.m_strAppId);
	continueDownloadButton->hide();
	reBeginDownloadButton->hide();
	pauseDownloadButton->show();

	emit sigReBeginDownload();
}

void AppDownLoadItem::onDownLoadPause()
{
	//tipsLabel->setText(QStringLiteral("暂停下载..."));

	ZcloudBigDataInterface::GetInstance()->produceData("M01", "OP001", "ADL001",m_deskInfo.m_strAppId);
	reBeginDownloadButton->hide();
	pauseDownloadButton->hide();
	continueDownloadButton->show();
	emit sigPauseDownLoad();
}

void AppDownLoadItem::onDownLoadContinue()
{
	//tipsLabel->setText(QStringLiteral("正在下载..."));
	ZcloudBigDataInterface::GetInstance()->produceData("M01", "OP001", "ADL002",m_deskInfo.m_strAppId);
	continueDownloadButton->hide();
	reBeginDownloadButton->hide();
	pauseDownloadButton->show();
	emit sigContinueDownLoad();
}

//删除下载
void AppDownLoadItem::onDownLoadEnd()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M01", "OP001", "ADL004",m_deskInfo.m_strAppId);
	continueDownloadButton->hide();
	reBeginDownloadButton->hide();
	endDownloadButton->hide();
	pauseDownloadButton->hide();
	pauseDownloadButton->move(217, 28);
	emit sigEndDownLoad();
}


void AppDownLoadItem::onDownloadProcess(qint64 bytesReceived, qint64 bytesTotal)
{
	if (bytesTotal <= 0) {
		this->setMaximum(100);
		this->setValue(0);
	}
	else {
		this->setMaximum(bytesTotal);
		this->setValue(bytesReceived);
	}
	updateInfoLabel();
}


void AppDownLoadItem::updateInfoLabel()
{
	qint64 bytesTotal = this->maximum();
	qint64 bytesReceived = this->value();
	// update info label
	double speed = bytesReceived * 1000.0 / m_downloadTime.elapsed();
	double timeRemaining = ((double)(bytesTotal - bytesReceived)) / speed;
	QString timeRemainingString = QString::fromLocal8Bit("秒");
	if (timeRemaining > 60) {
		timeRemaining = timeRemaining / 60;
		timeRemainingString = QString::fromLocal8Bit("分钟");
	}
	timeRemaining = floor(timeRemaining);

	// When downloading the eta should never be 0
	if (timeRemaining == 0)
		timeRemaining = 1;

	QString info;

	//QString remaining;
	//if (bytesTotal != 0)
	//	remaining = QString::fromLocal8Bit("- 剩余 %4 %5 ")
	//	.arg(timeRemaining)
	//	.arg(timeRemainingString);
	//info = QString::fromLocal8Bit("%1/%2 (%3/秒) %4 %5")
	//	.arg(dataString(bytesReceived))
	//	.arg(bytesTotal == 0 ? tr("?") : dataString(bytesTotal))
	//	.arg(dataString((int)speed))
	//	.arg(remaining)
	//	.arg(progressBar->text());
	info = QString::fromLocal8Bit("%1/%2  ")
		.arg(dataString(bytesReceived))
		.arg(bytesTotal == 0 ? tr("?") : dataString(bytesTotal));

	QString percentageStr;
	switch (m_downloadStatus)
	{
	case mapp_DOWNLOADING:
		//info.append(QString::fromLocal8Bit("	下载中"));
		info.append(dataString((int)speed)).append("/s");
		percentageStr = this->text();
		break;
	case mapp_ERROR:
		percentageStr = QString::fromLocal8Bit("下载错误");
		break;
	case mapp_FINISH:
		percentageStr = QString::fromLocal8Bit("安装中");
		break;
	case mapp_INSTALLFINLSH:
	{
		percentageStr = QString::fromLocal8Bit("安装完成");
		downloadInfoLabel->hide();
		break;
	}
	case mapp_INSTALLERROR:

		percentageStr = QString::fromLocal8Bit("安装错误");
		break;
	case mapp_PAUSE:
		percentageStr = QString::fromLocal8Bit("暂停中");
		break;
	case mapp_TIMEOUTERROR:
		percentageStr = QString::fromLocal8Bit("网络错误");
		break;
	case mapp_CLOSE:
		this->setValue(0);
		percentageStr = QString::fromLocal8Bit("已关闭");
		break;
	default:
		break;
	}
	downloadPercentageLabel->setText(percentageStr);
	downloadInfoLabel->setText(info);
	update();
}

QString AppDownLoadItem::dataString(int size) const
{
	QString unit;
	if (size < 1024) {
		unit = tr("bytes");
	}
	else if (size < 1024 * 1024) {
		size /= 1024;
		unit = tr("kB");
	}
	else {
		size /= 1024 * 1024;
		unit = tr("MB");
	}
	return QString(QLatin1String("%1 %2")).arg(size).arg(unit);
}


//修改状态
void AppDownLoadItem::onStatusChanged(APPDOWNLOADETYPE type)
{
	m_downloadStatus = type;
	continueDownloadButton->hide();
	reBeginDownloadButton->hide();
	pauseDownloadButton->hide();
	switch (type)
	{
	case mapp_DOWNLOADING:
		pauseDownloadButton->show();
		//QString::fromLocal8Bit("下载中"));
		break;
	case mapp_ERROR:
		reBeginDownloadButton->show();
		//QString::fromLocal8Bit("下载错误"));
		break;
	case mapp_FINISH:
		endDownloadButton->hide();
		//QString::fromLocal8Bit("安装中"));
		break;
	case mapp_INSTALLFINLSH:
		endDownloadButton->show();
		//(QString::fromLocal8Bit("安装完成"));
		break;
	case mapp_INSTALLERROR:
		reBeginDownloadButton->show();
		endDownloadButton->show();
		//QString::fromLocal8Bit("安装错误"));
		break;
	case mapp_PAUSE:
	case mapp_TIMEOUTERROR:
		continueDownloadButton->show();
		//QString::fromLocal8Bit("暂停中"));
		break;
	case mapp_CLOSE:
		endDownloadButton->hide();
		break;
	default:
		break;
	}
	updateInfoLabel();
	emit itemCownloadChange();
}

AtegoryButton::AtegoryButton(int flag, QWidget *parent)
	: QPushButton(parent)
{
	this->setFlat(true);
	
	this->setFocusPolicy(Qt::NoFocus);
	this->setCheckable(true);
	//设置窗体透明
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	//设置无边框
	this->setWindowFlags(Qt::FramelessWindowHint);
	if (flag == 0)
	{
		this->setStyleSheet(QString::fromLocal8Bit("QPushButton{border-image: url(:/new/imageFile/AppCenterPng/AtegoryNormol.png);color: rgb(51, 51, 51);font: 16px \"微软雅黑\";}\
												   	QPushButton:hover{border-image: url(:/new/imageFile/AppCenterPng/AtegoryNormol.png);color: rgb(31, 139, 237);font: 16px \"微软雅黑\";}\
														QPushButton:checked {border-image: url(:/new/imageFile/AppCenterPng/AtegoryClicked.png);color: rgb(255, 255, 255);font: 16px \"微软雅黑\";};\
															"));
	}
	else if (flag == 1)
	{
		this->setStyleSheet(QString::fromLocal8Bit("QPushButton{background-color: transparent;color: rgb(102, 102, 102);font: 13px \"微软雅黑\";}\
												    	QPushButton:hover{background-color: transparent;color: rgb(31, 139, 237);font: 13px \"微软雅黑\";}\
														QPushButton:checked {border-image: url(:/new/imageFile/border.png);color: rgb(31, 139, 237);font: 13px \"微软雅黑\";};\
														"));
	}
	else if (flag == 2)
	{
		this->setStyleSheet(QString::fromLocal8Bit("QPushButton{background: transparent;font: 16px \"微软雅黑\";color: rgb(102, 102, 102);}\
												   	 QPushButton:hover{background: transparent;font: 16px \"微软雅黑\";color: rgb(31, 139, 237);}\
													 QPushButton:checked {border-image: url(:/new/imageFile/border.png);color: rgb(31, 139, 237);font: 16px \"微软雅黑\";};\
														 "));
	}
}

AtegoryButton::~AtegoryButton()
{

}


//void AtegoryButton::paintEvent(QPaintEvent* event)
//{
//	//140 * 36
//	//QPainter painter(this);
//	//painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
//
//	//QPainterPath painterPath;
//	//painterPath.moveTo(20, 2);
//	//painterPath.lineTo(0, 34);
//	//painterPath.quadTo(2, 34, 2, 36);
//	//painterPath.lineTo(118, 36);
//	//painterPath.quadTo(118, 34, 120, 34);
//	//painterPath.lineTo(140, 2);
//	//painterPath.quadTo(118, 2, 138, 0);
//	//painterPath.lineTo(22, 0);
//	//painterPath.quadTo(22, 2, 20, 2);
//
//	//QLinearGradient linearGradient;
//	//linearGradient.setColorAt(0, QColor("#02A4FD"));
//	//linearGradient.setColorAt(1.0, QColor("#1F8BED"));
//
//	//painter.setBrush(linearGradient);
//	//painter.drawPath(painterPath);
//
//	return QPushButton::paintEvent(event);
//}
//



AppCenterItemPushButton::AppCenterItemPushButton(QWidget *parent)
	:QPushButton(parent)
	, menuToolButton(new QToolButton(this))
{
	//this->setStyleSheet("QPushButton{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(82, 219, 176, 1), stop:1 rgba(53, 190, 127, 1));border-radius:4px;font: 18px \"微软雅黑\";color:rgba(255, 255, 255, 1);}\
	//					QPushButton:hover,pressed{  background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(100, 223, 184, 1), stop:1 rgba(74, 197, 141, 1));border-radius:4px; font: 18px \"微软雅黑\";color:rgba(255, 255, 255, 1);}");
	QToolButton *menuToolButton = new QToolButton(this);
	menuToolButton->setGeometry(99, 13, 14, 14);
	menuToolButton->setAttribute(Qt::WA_TranslucentBackground, true);
	menuToolButton->setStyleSheet("QToolButton{border-radius:7px;border-image: url(:/new/imageFile/AppCenterPng/toolMenu.png);}");
	menuToolButton->hide();

	m_menu = new QMenu(this);
	m_actionUpdate = new QAction(this);
	m_actionUninstall = new QAction(this);

	m_actionUpdate->setText(QString::fromLocal8Bit("升级"));
	m_actionUninstall->setText(QString::fromLocal8Bit("卸载"));

	m_menu->addAction(m_actionUninstall);
	m_menu->addAction(m_actionUpdate);
	m_menu->resize(74, 48);
	m_menu->setMaximumSize(74, 48);
	m_menu->setMinimumSize(74, 48);
	m_menu->setAttribute(Qt::WA_TranslucentBackground);
	m_menu->setStyleSheet(QString::fromLocal8Bit("QMenu {background-color:rgba(255, 255, 255, 1);"//整个背景
		"border: 1px solid rgb(222, 222, 222);"//整个菜单边缘
		"font-size:12px 'Microsoft Yahei';text-align:center;color: rgb(51, 51, 51);}"
		"QMenu::item {;"//字体颜色
		"background-color: rgb(255, 255, 255);}"
		//"margin:0px 0px;"//设置菜单项的外边距
		//"padding:0px 0px 0px 0px;}"//设置菜单项文字上下和左右的内边距，效果就是菜单中的条目左右上下有了间隔
		"QMenu::item:pressed {background-color:rgb(242,242,242);"//选中的样式
		"font-size: 12px 'Microsoft Yahei'; color: rgb(51, 51, 51);}"//字体颜色
		"QMenu::item:selected {"//菜单项按下效果
		"font-size: 12px 'Microsoft Yahei'; color: rgb(51, 51, 51);"//字体颜色
		"background-color: rgb(242, 242, 242);}"));

	connect(m_actionUpdate, SIGNAL(triggered()), this, SIGNAL(clicked()));
	connect(m_actionUninstall, SIGNAL(triggered()), this, SIGNAL(actionUninstallSignal()));
	connect(menuToolButton, SIGNAL(clicked()), this, SLOT(showMenu()));

}

void AppCenterItemPushButton::showMenu()
{
	//m_menu->exec(mapToGlobal(QPoint(this->parentWidget()->pos().x() + 90, this->parentWidget()->pos().y() - 55)));
	QPoint point = mapToGlobal(QPoint(this->x(), this->y()));
	m_menu->exec(QPoint(point.x() - 740, point.y() + 10));

}



