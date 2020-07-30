#include "AppCenterHomeWidget.h"
#define  STYSTEM4	"QPushButton{background:rgba(255, 255, 255, 1);border-radius:5px; }QPushButton:hover{ background:rgba(26,143,240,1);border-radius:5px }QPushButton:pressed{ background:rgba(26,143,240,1);border-radius:5px}; "
#include "AppDatabase/AppCenterDatabase.h"
#include "AppCenterTools.h"
#include "AppCommFun.h"
#include "AppCenterWidget.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>

AppCenterHomeWidget::AppCenterHomeWidget(QWidget *parent)
	: QWidget(parent)
	, m_nameButtonGroup(new QButtonGroup(this))
	, m_sliderWidget(new SliderWidget(this))
	, m_photoWidget(new PhotoWidget(this))
{
	ui.setupUi(this);
	m_nameButtonGroup->setExclusive(true);
	this->setMinimumSize(800,444);
	
	m_sliderWidget->setGeometry(22, 284, 690, 226);

	//m_sliderWidget->setStyleSheet("background-color: rgb(0, 255, 0);");
	m_sliderWidget->show();
	QLabel *label = new QLabel(QString::fromLocal8Bit("热门应用"),this);
	label->setGeometry(755, 229, 92, 35);
	label->setStyleSheet(QString::fromLocal8Bit("font: 16px \"微软雅黑\";color: rgb(102, 102, 102);background: transparent;"));

	m_photoWidget->setGeometry(20, 18, 960, 200);
	connect(m_photoWidget, SIGNAL(chooseLabelSignal(int)), this, SLOT(set_circleButton(int)));
	
}

AppCenterHomeWidget::~AppCenterHomeWidget()
{
}


//点击 小圆点  
void AppCenterHomeWidget::clickedButtonSLot(bool)
{
	QPushButton *chooseButton = qobject_cast<QPushButton *>(sender());
	if (chooseButton)
	{
		int number = chooseButton->objectName().toInt();
		m_photoWidget->setPhoto(number + 1);
		set_circleButton(number);
	}
}
//设置 小圆点 的样式
void AppCenterHomeWidget::set_circleButton(int circleNumber)
{
	foreach(QPushButton *button, listButton)
		button->setStyleSheet(STYSTEM4);
	if (circleNumber < listButton.size())
		listButton.at(circleNumber)->setStyleSheet("QPushButton{background:rgba(26,143,240,1);border-radius:5px}");
}

void AppCenterHomeWidget::clearHomeWidget()
{
	m_photoWidget->clearLabel();
	for each (QPushButton * var in listButton)
		var->deleteLater();
	listButton.clear();

	for each (QAbstractButton *var in m_nameButtonGroup->buttons())
	{
		m_nameButtonGroup->removeButton(var);
		var->deleteLater();
		var = NULL;
	}
	
	QMapIterator<QPushButton *, QString> i(nameButtonMap);
	while (i.hasNext()) {
		QPushButton *button = i.next().key();
		if (button) {
			button->deleteLater();
			button = NULL;
		}
	}
	nameButtonMap.clear();

	for each (AppCenterTools *var in hotAppToolsList)
	{
		var->deleteLater();
		var = NULL;
	}
	hotAppToolsList.clear();
}



void AppCenterHomeWidget::initHomeWidget()
{
	clearHomeWidget();

	//热门应用
	QList<AppDataInfo> hotAppDataInfoList;
	if (AppCenterDatabase::instance()->findClassAppList(hotAppDataInfoList, "2"))
	{
		int hotSize = 0;
		for (int i = 0; i < hotAppDataInfoList.size(); i++)
		{
			AppDataInfo appDataInfo = hotAppDataInfoList.at(i);
			AppCenterTools *hotAppTools = new AppCenterTools(appDataInfo, ++hotSize, this);
			hotAppToolsList.append(hotAppTools);
			hotAppTools->move(752, 275 + (hotSize - 1) * 30);
			hotAppTools->show();

			if (hotSize > 7) break;
		}
	}




	///////////////////////////////////////////////////////////////////
	//首页分类
	AppClassInfo recommendClass;
	recommendClass.m_strClassName = QString::fromLocal8Bit("为您推荐");
	recommendClass.m_strClassId = "1";
	recommendClass.m_pageFlag = CLASSRECOMMEND;
	QList<AppClassInfo> homeClassInfoList;

	homeClassInfoList.clear();
	if (AppCenterDatabase::instance()->findAppClassList(homeClassInfoList, CLASSHOME))
	{
		homeClassInfoList.insert(0, recommendClass);
					
		for (int nIndex = 0; nIndex < homeClassInfoList.size(); nIndex++)
		{
			AppClassInfo appClassInfo = homeClassInfoList.at(nIndex);

			QString lbtId = appClassInfo.m_strClassId;
			QString lbtName = appClassInfo.m_strClassName;
			//QString lbtSort = appClassInfo.m_intSort;
			//QString cretTime = appClassInfo.t

			AtegoryButton *nameButton = new AtegoryButton(2, this);
			nameButtonMap.insert(nameButton, lbtId);
			m_nameButtonGroup->addButton(nameButton, nIndex);
			
			nameButton->setText(lbtName);
			nameButton->setGeometry(20 + nIndex * 96 + 2, 225, 92, 38);
			nameButton->show();

			connect(nameButton, SIGNAL(clicked()), this, SLOT(clickedNameButtonSlot()));
		}
	}

	////////////////////////////////////////////////////////////////////////

	

	QList<SliderInfo > sliderInfoList;
	if (!AppCenterDatabase::instance()->findSider(sliderInfoList) )
		return;

	int cX = (1000 - (sliderInfoList.size() * 16 - 20)) / 2;

	for (int j = 0; j < sliderInfoList.size(); j++)
	{
		QPushButton *button = new QPushButton(this);
		listButton.append(button);
		button->setGeometry(cX + j * 16, 198, 10, 10);
		button->setStyleSheet(STYSTEM4);
		button->setObjectName(QString::number(j));
		button->setFocusPolicy(Qt::NoFocus);
		button->raise();
		button->show();
		connect(button, SIGNAL(clicked(bool)), this, SLOT(clickedButtonSLot(bool)));
		m_photoWidget->addPhoto(sliderInfoList.at(j));
	}

	m_photoWidget->addFlish();
	m_photoWidget->show();
	
	if (listButton.size() > 0)
		emit listButton.at(0)->clicked(true);
	if (m_nameButtonGroup->buttons().size() > 0)
	{
		m_nameButtonGroup->button(0)->click();
	}
}

void AppCenterHomeWidget::clickedNameButtonSlot()
{
	QPushButton * button = qobject_cast<QPushButton*>(sender());

	if (button)
	{
		m_sliderWidget->clearButton();

		QList<AppDataInfo > appDataInfoList;
		if (!AppCenterDatabase::instance()->findClassAppList(appDataInfoList, nameButtonMap[button]))
		{
			return;
		}

		for (int i = 0; i < appDataInfoList.size(); i++)
		{
			//多余九个舍弃
			if (i > 9) return;
			AppDataInfo appInfo = appDataInfoList.at(i);
			QString appid = appInfo.m_strAppId;
			AppCenterTools *appCenterTools = new AppCenterTools(appInfo);
			//lbtQppIdList.contains(appid) ? connectHomeApp(appCenterTools, appid) : lbtQppIdList.append(appid);
			
			m_sliderWidget->addApp(appCenterTools);
		}
	}
}

bool AppCenterHomeWidget::openHomeError(AppDataInfo pData)
{
	//打开错误 重新安装
		foreach(AppCenterTools *appCenterTools, m_sliderWidget->listApp)
		{
			if (appCenterTools)
			{
				if (appCenterTools->m_desktopAppInfo.m_strAppId == pData.m_strAppId)
				{
					appCenterTools->m_APPSTATUSFlag = E_INSTALL;
					appCenterTools->m_desktopAppInfo.m_bAppIsInstall = false;
				}
			}
		}
	
	//必须 两次循环 因为 里边的信号与槽  有联系
	
		foreach(AppCenterTools *appCenterTools, m_sliderWidget->listApp)
		{
			if (appCenterTools)
			{
				if (appCenterTools->m_desktopAppInfo.m_strAppId == pData.m_strAppId)
				{
					appCenterTools->clickedStautusButton();
					return true;
				}
			}
		}
	
	return false;
}

//void AppCenterHomeWidget::connectHomeApp(AppCenterTools *appCenterTools,QString appId)
//{
//		foreach(AppCenterTools *oldTools, m_sliderWidget->listApp)
//		{
//			if (oldTools->getDesktopAppInfo().m_strAppId == appId)
//			{
//				connect(oldTools, SIGNAL(startDownloadAppSignal(QString)), appCenterTools, SLOT(startDownloadAppSlot(QString)));
//				connect(appCenterTools, SIGNAL(startDownloadAppSignal(QString)), oldTools, SLOT(startDownloadAppSlot(QString)));
//			}
//		}
//	
//		for each (AppCenterTools * var in hotAppToolsList)
//		{
//			if (var)
//			{
//				if (var->m_desktopAppInfo.m_strAppId == appId)
//				{
//					connect(var, SIGNAL(startDownloadAppSignal(QString)), appCenterTools, SLOT(startDownloadAppSlot(QString)));
//					connect(appCenterTools, SIGNAL(startDownloadAppSignal(QString)), var, SLOT(startDownloadAppSlot(QString)));
//				}
//			}
//		}
//}

void AppCenterHomeWidget::changedToolButtonStatus(QString appId, APPSTATUS partFlag)
{

	foreach(AppCenterTools *appCenterTools, m_sliderWidget->listApp)
	{
		if (appCenterTools)
		{
			if (appCenterTools->m_desktopAppInfo.m_strAppId == appId)
			{
				//修改按钮状态
				appCenterTools->statusChanged(partFlag, true);
			}
		}
	}

	for each (AppCenterTools * var in hotAppToolsList)
	{
		if (var)
		{
			if (var->m_desktopAppInfo.m_strAppId == appId)
			{
				//修改按钮状态
				var->statusChanged(partFlag, true);
			}
		}
	}

}
