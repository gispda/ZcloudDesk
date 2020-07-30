#include "AppCenterUUWidget.h"
#include <QScrollBar>
#include <QAbstractScrollArea>
#include <QDesktopWidget>
#include "AppCenterWidget.h"
#include "AppDatabase/AppCenterDatabase.h"
#include "dlgwait.h"
#include "AppCommFun.h"
#include "ZcloudBigData.h"

AppCenterUUWidget::AppCenterUUWidget(QWidget *parent)
	: QWidget(parent)
	, m_noUpdateLabel(new QLabel(this))
	, m_UUScrollArea(new QScrollArea(this))
	, m_UUWidget(new QWidget(this))
	, m_UUButtonGroup(new QButtonGroup(this))
{
	this->resize(1000, 528);
	m_UUButtonGroup->setExclusive(true);
	QLabel *label = new QLabel(this);
	label->setGeometry(20, 50, 960, 1);
	label->setStyleSheet("QLabel{background-color: rgb(235, 235, 235);}");

	m_noUpdateLabel->setStyleSheet("QLabel{border-image: url(:/new/imageFile/AppCenterPng/img_wyy.png);}");
	m_noUpdateLabel->setGeometry(280, 130, 440, 260);
	m_noUpdateLabel->raise();

	m_UUScrollArea->verticalScrollBar()->setStyleSheet(SCROLLBARSTYESHEET);
	m_UUScrollArea->setStyleSheet("QScrollArea{border:none;outline: none;background-color: rgb(253, 253, 253);}");
	m_UUScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_UUScrollArea->verticalScrollBar()->setMaximum(100);
	m_UUScrollArea->setGeometry(0, 51, 995, 473);

	m_UUWidget->setStyleSheet("QWidget{background-color: rgb(253, 253, 253);}");
	m_UUScrollArea->setWidget(m_UUWidget);
	connect(m_UUScrollArea->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(onNextPageBtnClick(int)));

	m_noUpdateLabel->hide();
	//initUU();
}

AppCenterUUWidget::~AppCenterUUWidget()
{
}

void AppCenterUUWidget::initUU()
{




	QList<AppClassInfo> uuClassInfoList;
	if (!AppCenterDatabase::instance()->findAppClassList(uuClassInfoList, CLASSDESK))
	{
		return;
	}

	//清空卸载列表分类
	QList<QAbstractButton*> oldUuButtonList =  m_UUButtonGroup->buttons();
	for each (QAbstractButton * uuButton in oldUuButtonList)
	{
		m_UUButtonGroup->removeButton(uuButton);
		if (uuButton)
		{
			uuButton->disconnect();
			uuButton->deleteLater();
			uuButton = NULL;
		}
	}

	AppClassInfo allClassInfo;
	allClassInfo.m_strClassName = QString::fromLocal8Bit("全部");
	allClassInfo.m_pageFlag = CLASSDESK;
	uuClassInfoList.insert(0, allClassInfo);
	int nindex = 0;
	int buttonNumber = 0;
	foreach(AppClassInfo rightClassInfo, uuClassInfoList)
	{
		AtegoryButton *button = new AtegoryButton(1, this);
		button->setText(rightClassInfo.m_strClassName);
		button->setGeometry(20 + buttonNumber * 70, 20, 66, 30);

		AppUserCustomData*	pCustomData = new AppUserCustomData;
		pCustomData->strCateId = rightClassInfo.m_strClassId;
		button->setUserData(0, (QObjectUserData*)pCustomData);

		m_UUButtonGroup->addButton(button, buttonNumber++);
		connect(button, SIGNAL(clicked()), this, SLOT(UUButtonSlot()));
		button->show();
	}

	if (m_UUButtonGroup->buttons().size() > 0)
	{
		m_UUButtonGroup->button(0)->setCheckable(true);
		m_UUButtonGroup->button(0)->setChecked(true);
		m_UUButtonGroup->button(0)->click();
	}

}


void AppCenterUUWidget::UUButtonSlot()
{
	static QMutex ategoryMutex;
	if (!ategoryMutex.tryLock()) return;
	DlgWait 	dlgWait("", this);
	//dlgWait.setGeometry(this->pos().x(), this->pos().y(), this->width(), this->height());
	QDesktopWidget* desktop = QApplication::desktop();
	dlgWait.move((desktop->width() - dlgWait.width()) / 2, (desktop->height() - dlgWait.height()) / 2);
	QPushButton *button = qobject_cast<QPushButton *>(sender());

	if (button)
	{
		QObjectUserData*	pData = button->userData(0);
		if (pData == NULL)
		{
			ategoryMutex.unlock();
			return;
		}
		AppUserCustomData*	pCustomData = (AppUserCustomData*)pData;
		if (pCustomData == NULL)
		{
			ategoryMutex.unlock();
			return;
		}

		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "AUN003", pCustomData->strCateId);
		pCustomData->reset();
		pCustomData->nCurPage = 1;
		AppAnalyAppInfo(pCustomData);
	}

	
	ategoryMutex.unlock();
}

void AppCenterUUWidget::clearAppCenterToolsList()
{
	for (int i = m_UUButtonList.size() - 1; i >= 0; i--)
	{
		AppCenterTools *tool = m_UUButtonList.at(i);
		if (tool)
		{
			tool->disconnect();
			tool->deleteLater();
			tool = NULL;
		}
	}
	m_UUButtonList.clear();
}


bool AppCenterUUWidget::AppAnalyAppInfo(AppUserCustomData * pUserData,  bool isClear)
{
	if (isClear)
		clearAppCenterToolsList();
	if (pUserData->nCurPage <= 0)
		pUserData->nCurPage = 1;
	QList<AppDataInfo > deskAppInfoList;
	if (!AppCenterDatabase::instance()->findClassAppList(deskAppInfoList, pUserData->strCateId, pUserData->nCurPage, "", true))
	{
		qDebug() << "zcd-0x00000001: AppCenterUUWidget,findClassAppList Error";
		return false;
	}

	//m_UUButtonList.size() ? m_noUpdateLabel->hide() : m_noUpdateLabel->show();

	if (deskAppInfoList.size() <= 0) {
		pUserData->nCurPage--;
		return false;
	}


	QList<AppDataInfo > updateAppList;
	QList<AppDataInfo > uninstallAppList;
	foreach(AppDataInfo pData, deskAppInfoList)
	{
		//cs应用
		if (!pData.m_bAppType && !pData.m_strAppDownloadUrl.isEmpty() && !pData.m_strAppCurrentVerson.isEmpty())
		{
			//如果当前版本为空  未处理
			bool isNewVerson = false;
			AppCommFun::isHaveNewVerson(pData, isNewVerson, false);
			isNewVerson ? uninstallAppList.append(pData) : updateAppList.append(pData);
		}
		else
			uninstallAppList.append(pData);
	}
	int index = uninstallAppList.size() + updateAppList.size();
	//clearAppCenterToolsList();

	int widgetH = (pUserData->nCurPage - 1) * 910 + index * 91;
	if (widgetH < 473) widgetH = 473;
	m_UUWidget->setMinimumSize(995, widgetH);
	m_UUWidget->resize(995, widgetH);

	foreach(AppDataInfo  pAppInfo, updateAppList)
	{
		int toolsY = m_UUButtonList.size() * 91;
		AppCenterTools *appCenterTools = new AppCenterTools(m_UUWidget, pAppInfo, false);

		m_UUButtonList.append(appCenterTools);

		appCenterTools->move(0, toolsY);
		appCenterTools->statusChanged(E_UPDATE, true);
		appCenterTools->show();

	}

	foreach(AppDataInfo  pAppInfo, uninstallAppList)
	{
		int toolsY = m_UUButtonList.size() * 91;
		AppCenterTools *appCenterTools = new AppCenterTools(m_UUWidget, pAppInfo, false);
		
		m_UUButtonList.append(appCenterTools);

		appCenterTools->move(0, toolsY);
		appCenterTools->show();

	}



	m_UUButtonList.size() ? m_noUpdateLabel->hide() : m_noUpdateLabel->show();
	return true;
}


void AppCenterUUWidget::onNextPageBtnClick(int value)
{
	if (value != m_UUScrollArea->verticalScrollBar()->maximum()) return;
	DlgWait 	dlgWait("", this);
	dlgWait.setGeometry(this->pos().x(), this->pos().y(), this->width(), this->height());

	QPushButton*	pCurBtn = qobject_cast<QPushButton *>(m_UUButtonGroup->checkedButton());
	if (pCurBtn == NULL)
	{
		return;
	}
	QObjectUserData*	pData = pCurBtn->userData(0);
	if (pData == NULL)
	{
		return;
	}
	AppUserCustomData*	pCustomData = (AppUserCustomData*)pData;
	if (pCustomData == NULL)
	{
		return;
	}
	
	pCustomData->nCurPage = pCustomData->nCurPage + 1;
	AppAnalyAppInfo(pCustomData, false);
}


void AppCenterUUWidget::changedToolButtonStatus(QString appId, APPSTATUS partFlag)
{
	for each (AppCenterTools * appCenterTools in m_UUButtonList)
	{
		if (appCenterTools)
		{
			if (appCenterTools->getDesktopAppInfo().m_strAppId == appId)
			{
				//修改按钮状态
				appCenterTools->statusChanged(partFlag, true);
			}
		}
	}
}