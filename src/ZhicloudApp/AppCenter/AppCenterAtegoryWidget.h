#pragma once

#include <QButtonGroup>
#include <QWidget>
#include <QLAbel>
#include "ZhicloudAppDataDefine.h"
#include "AppCenterTools.h"


class AppCenterAtegoryWidget : public QWidget
{
	Q_OBJECT

public:
	AppCenterAtegoryWidget(QWidget *parent);
	~AppCenterAtegoryWidget();
	void initCategory();
	void changedToolButtonStatus(QString appId, APPSTATUS partFlag);
	void clickedAllButton(QString findStr);
private:

	bool AppAnalyAppInfo(AppUserCustomData*pUserData, bool isClear  = true);
private slots:
	//点击 一个分类
	void ategoryButtonSlot(bool checked);
	void onNextPageBtnClick(int value);
	void clearAppCenterToolsList();
	void clearClassButton();
private:
	QButtonGroup *ategoryButtonGroup = NULL;
	QWidget *m_appWidget = NULL;
	QScrollArea * m_categoryScrollArea = NULL;
	QList<AppCenterTools *> m_ategoryButtonList;
	QLabel *m_noAppLabel = NULL;
	QString m_findStr;
};
