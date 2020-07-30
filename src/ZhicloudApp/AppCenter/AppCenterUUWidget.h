#pragma once

#include <QWidget>
#include <QLabel>
#include <QButtonGroup>
#include <QScrollArea>
#include <QPushButton>
#include "ZhicloudAppDataDefine.h"
#include "AppCenterTools.h"
class AppCenterUUWidget : public QWidget
{
	Q_OBJECT

public:
	AppCenterUUWidget(QWidget *parent);
	~AppCenterUUWidget();
	void initUU();

	void changedToolButtonStatus(QString appId, APPSTATUS partFlag);
private:
	QLabel *m_noUpdateLabel = NULL;
	QButtonGroup *m_UUButtonGroup = NULL;
	QWidget *m_UUWidget = NULL;
	QScrollArea * m_UUScrollArea = NULL;
	QList<AppCenterTools *> m_UUButtonList;

private:
	
	bool AppAnalyAppInfo(AppUserCustomData*pUserData, bool isClear = true);
	void clearAppCenterToolsList();
	
	private slots:
	void onNextPageBtnClick(int value);
	void UUButtonSlot();
};
