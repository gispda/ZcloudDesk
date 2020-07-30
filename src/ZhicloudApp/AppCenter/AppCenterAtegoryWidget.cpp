#include "AppCenterAtegoryWidget.h"
#include <QScrollArea>
#include <QScrollBar>
#include <QAbstractScrollArea>
#include <QPushButton>
#include <QDesktopWidget>
#include "AppCenterWidget.h"
#include "AppDatabase/AppCenterDatabase.h"
#include "dlgwait.h"
#include "ZcloudBigData.h"


AppCenterAtegoryWidget::AppCenterAtegoryWidget(QWidget *parent)
	: QWidget(parent)
	, ategoryButtonGroup(new QButtonGroup(this))
	, m_categoryScrollArea(new QScrollArea(this))
	, m_appWidget(new QWidget())
	, m_noAppLabel(new QLabel(this))
	, m_findStr("")
{
	this->resize(1000, 528);
	//this->setStyleSheet("border-radius: 8px;}");
	m_noAppLabel->setStyleSheet("border-image: url(:/new/imageFile/AppCenterPng/img_wyy.png);");
	m_noAppLabel->setGeometry(280, 130 + MARGIN_WITH, 440, 260);
	m_noAppLabel->raise();

	ategoryButtonGroup->setExclusive(true);
	m_categoryScrollArea->setWidget(m_appWidget);
	m_categoryScrollArea->setStyleSheet("QScrollArea{border:none;outline: none;background-color: rgb(253, 253, 253);}");
	m_appWidget->setStyleSheet("QWidget{background-color: rgb(253, 253, 253);}");
	m_categoryScrollArea->verticalScrollBar()->setStyleSheet(SCROLLBARSTYESHEET);
	m_categoryScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_categoryScrollArea->verticalScrollBar()->setMaximum(100);
	m_categoryScrollArea->setGeometry(0,69,995,455);
	connect(m_categoryScrollArea->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(onNextPageBtnClick(int)));	
	//m_appWidget->setStyleSheet("background-color: rgb(255, 70, 119);");
	//initCategory();

}

AppCenterAtegoryWidget::~AppCenterAtegoryWidget()
{

}


void AppCenterAtegoryWidget::initCategory()
{
	m_findStr.clear();
	QList<AppClassInfo> classInfoList;
	if (AppCenterDatabase::instance()->findAppClassList(classInfoList, CLASSCENTER))
	{

		AppClassInfo allClassInfo;
		allClassInfo.m_strClassName = QString::fromLocal8Bit("全部");
		allClassInfo.m_pageFlag = CLASSCENTER;
		classInfoList.insert(0, allClassInfo);

		int statX = (1000 - classInfoList.size() * 124 - 20) / 2;
		for (int i = 0; i < classInfoList.size(); i++)
		{
			AppClassInfo ifi = classInfoList.at(i);
			QString strName = ifi.m_strClassName;
			QString strCateId = ifi.m_strClassId;

			AtegoryButton *pOpBtn = new AtegoryButton(0, this);
			if (i == 0) pOpBtn->setChecked(true);
			connect(pOpBtn, SIGNAL(clicked(bool)), this, SLOT(ategoryButtonSlot(bool)));
			ategoryButtonGroup->addButton(pOpBtn,i);
			pOpBtn->setText(strName);
			pOpBtn->setGeometry(statX , 20, 140, 36);
			pOpBtn->show();
			statX += 124;

			AppUserCustomData*	pCustomData = new AppUserCustomData;
			pCustomData->strCateId = strCateId;
			pCustomData->strName = strName;
			pOpBtn->setUserData(0, (QObjectUserData*)pCustomData);
		}
	}
	if (ategoryButtonGroup->buttons().size() > 0)
	{
		AtegoryButton *button = qobject_cast<AtegoryButton *> (ategoryButtonGroup->checkedButton());
		if (button)
		{
			emit button->clicked(true);
		}
	}
}



void AppCenterAtegoryWidget::ategoryButtonSlot(bool checked)
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

		if (!checked) ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "ACL003", pCustomData->strCateId);
		pCustomData->reset();
		pCustomData->nCurPage = 1;
		AppAnalyAppInfo(pCustomData);
	}
	ategoryMutex.unlock();
}



void AppCenterAtegoryWidget::onNextPageBtnClick(int value)
{
	if (value != m_categoryScrollArea->verticalScrollBar()->maximum()) return;
	DlgWait 	dlgWait("", this);
	dlgWait.setGeometry(this->pos().x(), this->pos().y(), this->width(), this->height());

	int classButtonSize = ategoryButtonGroup->buttons().size();
	if (!classButtonSize) return;
	QPushButton*	pCurBtn = qobject_cast<QPushButton *>(ategoryButtonGroup->checkedButton());
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


void AppCenterAtegoryWidget::clearAppCenterToolsList()
{
	for (int i = m_ategoryButtonList.size() - 1; i >= 0; i--)
	{
		AppCenterTools *tool = m_ategoryButtonList.at(i);
		if (tool)
		{
			tool->disconnect();
			tool->deleteLater();
			tool = NULL;
		}
	}
	m_ategoryButtonList.clear();
	if (ategoryButtonGroup->checkedId() != 0)
	{
		m_findStr.clear();
	}
}

void AppCenterAtegoryWidget::clearClassButton()
{
	QList<QAbstractButton*> buttons = ategoryButtonGroup->buttons();
	for (int i = buttons.size() - 1; i >= 0; i--)
	{
		QAbstractButton *button = buttons.at(i);
		button->disconnect();
		ategoryButtonGroup->removeButton(button);
		button->deleteLater();
		button = NULL;
	}
}

bool AppCenterAtegoryWidget::AppAnalyAppInfo(AppUserCustomData*pUserData, bool isClear)
{
	if (isClear)
		clearAppCenterToolsList();
	if (pUserData->nCurPage <= 0)
		pUserData->nCurPage = 1;
	QList<AppDataInfo > deskAppInfoList;
	//点击分类
	int widgetH = 0;
	if (!AppCenterDatabase::instance()->findClassAppList(deskAppInfoList, pUserData->strCateId, pUserData->nCurPage, m_findStr))
		return false;

	!deskAppInfoList.size() && !m_ategoryButtonList.size() ? m_noAppLabel->show() : m_noAppLabel->hide();
	if (deskAppInfoList.size() <= 0) {
		pUserData->nCurPage--;
		if (!m_findStr.isEmpty())
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP003", "ACL002", m_findStr);
		return false;
	}
	widgetH = (pUserData->nCurPage - 1) * 910 + deskAppInfoList.size() * 91;
	if (widgetH < 455) widgetH = 455;
	m_appWidget->setMinimumSize(1000, widgetH);
	m_appWidget->resize(1000, widgetH);

	deskAppInfoList.size() ? m_noAppLabel->hide() : m_noAppLabel->show() ;

	QString findAppIdStrList = "";
	foreach(AppDataInfo  pAppInfo, deskAppInfoList)
	{
		findAppIdStrList += ("," + pAppInfo.m_strAppId);
		AppCenterTools *appCenterTools = new AppCenterTools(m_appWidget, pAppInfo);
		
		int toolsY =  m_ategoryButtonList.size() * 91;
		appCenterTools->move(0, toolsY);
		appCenterTools->show();

		//if (pAppInfo.m_strListAppVipList.size() > 0 && pAppInfo.m_strListAppVipList.at(0) != 0)
		//{
		//	QLabel *vipLable = new QLabel(m_appWidget);
		//	appCenterTools->vipLabel = vipLable;
		//	vipLable->setAttribute(Qt::WA_TranslucentBackground);
		//	vipLable->setGeometry(0 - 11, toolsY - 12, 74, 75);
		//	vipLable->setPixmap(QPixmap(":/new/imageFile/appCenterImage/VipClass.png"));
		//	vipLable->show();
		//}
		m_ategoryButtonList.append(appCenterTools);
	}
	if (!m_findStr.isEmpty())
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP003", "ACL002", m_findStr + findAppIdStrList);
	return true;
}

void AppCenterAtegoryWidget::changedToolButtonStatus(QString appId, APPSTATUS partFlag)
{
	for each (AppCenterTools * appCenterTools in m_ategoryButtonList)
	{
		if (appCenterTools)
		{
			if (appCenterTools->getDesktopAppInfo().m_strAppId == appId)
			{
				appCenterTools->statusChanged(partFlag, true);
			}
		}
	}
}
void AppCenterAtegoryWidget::clickedAllButton(QString findStr)
{
	m_findStr = findStr.trimmed();
	if (ategoryButtonGroup->buttons().size() > 0)
	{
		if (ategoryButtonGroup->checkedId() != 0)
		{
			ategoryButtonGroup->checkedButton()->setChecked(false);
			ategoryButtonGroup->button(0)->setChecked(true);
		}
		QPushButton *button = qobject_cast<QPushButton *>(ategoryButtonGroup->button(0));
		if (button)
			button->clicked(true);
	}
}
