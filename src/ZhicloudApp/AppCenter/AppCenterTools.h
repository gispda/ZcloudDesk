#pragma once

#include "AppCenterComponent.h"
#include "ZhicloudAppDataDefine.h"

class AppCenterTools : public QPushButton
{
	Q_OBJECT
	friend class AppCenterWidget;
	friend class AppCenterHomeWidget;
public:
	//图片   ，名字， 简介
	//应用类别
	AppCenterTools(QWidget *parent, AppDataInfo  info, bool ategory_manager = true);
	//首页推荐应用
	AppCenterTools(AppDataInfo  info, QWidget *parent = 0);
	//首页热门应用
	AppCenterTools(AppDataInfo  info, int number, QWidget *parent = 0);
public:
	~AppCenterTools();
	//QLabel *vipLabel = NULL;
	AppDataInfo getDesktopAppInfo()
	{
		return m_desktopAppInfo;
	}
public:
	//按钮状态改变
	void statusChanged(APPSTATUS flag, bool isAdd = false);
	//当前按钮状态
	APPSTATUS m_APPSTATUSFlag;
protected:
	virtual void	enterEvent(QEvent *event);
	virtual void	leaveEvent(QEvent *event);
	//virtual void	paintEvent(QPaintEvent* event);
private:
	AppCenterItemPushButton *statusButton;
	AppDataInfo  m_desktopAppInfo;
	//QPixmap m_bg;
	bool startDownloadAppSlotFLag = false;
private slots:
	//有升级时点击卸载
	void updateUninstall();
	//点击状态按钮
	void clickedStautusButton();
	void onRecommended();
	void unstallFlish(AppDataInfo, bool flag);
	//解决 首页  同一个应用 显示多次
	void startDownloadAppSlot(QString appId);
	//卸载完成
	void unInstallSucceed(AppDataInfo, bool flag);
signals:
	//添加 下载 到下载列表 信号
	void  addDownloadItemSignal(AppDownLoadItem *);
	void toolsStatusChanged(APPSTATUS);
	void startDownloadAppSignal(QString appId);
public slots:
	//下载 状态该表
	void onDownloadStatusChanged(APPDOWNLOADETYPE type);

private:
	//卸载应用
	void uninstallApp();
	void downloadApp();
	//初始化 线程
	void connectThread();

	//如果有卸载或者安装中修改按钮状体
	bool uuChangedStatus(APPSTATUS);


	void getScreenInfo();
	//0 热门应用的button  1 推荐应用的button   2应用类别的button   3 是应用管理
	int m_isHotApp = 0;


	QLabel * m_particulars = NULL;
	QLabel * m_numberLabel = NULL;
	QLabel * m_photoLabel = NULL;
	QLabel * m_nameLabel = NULL;
	QString hotAppName_1;
	QString hotAppName_2;


	bool isUpdate = false;
};

