#pragma once

#include <QObject>
#include <QDialog>
#include "ZhicloudAppDataDefine.h"
#include <QPushButton>
class AppParticularsDialog : public QDialog
{
	friend class AppCenterWidget;
	Q_OBJECT
public:
	AppParticularsDialog(AppDataInfo pData, APPSTATUS APPSTATUSFlag, QWidget *parent = nullptr);
private:
	~AppParticularsDialog();
	
	void downloadApp();
private slots:
	void statusChanged(APPSTATUS flag);
	void clostClickeSlot();
public slots:
	void onDownloadStatusChanged(APPDOWNLOADETYPE type);
private:
	AppDataInfo m_desktopAppInfo;
	QPushButton *button;
public:
	APPSTATUS m_APPSTATUSFlag = E_OPEN;

private slots:
	void clickedStautusButton();
};