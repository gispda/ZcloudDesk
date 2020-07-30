#pragma once

#include "AppCenterHomeWidget.h"
#include "ui_AppCenterWidget.h"
#include "AppCommWidget.h"
#include "AppCenterTools.h"
#include "AppParticularsDialog.h"
#include <QButtonGroup>


class AppCenterWidget : public QWidget
{
	friend class RightClassAppWidget;
	Q_OBJECT
public:
	AppCenterWidget(QWidget *parent = Q_NULLPTR);
	~AppCenterWidget();
	void clickedMainHomeButton()
	{
		ui.mainPushButton->click();
	};
	void flushAppCenter();
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	QPixmap	m_bg;
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;
private:
	QButtonGroup *pButtonGroup = NULL;
public:
	//推送付费应用
	void pushPayInstall(const QString& strJson);
	//自动下载   isInstall = false 打开详情
	void setAutoDownload(AppDataInfo pData);
	//关闭详情修改按钮状态
	void changeButtonStatus(QString appId);
private:
	//下载页面
	AppDownLoadAppWidget * appDownLoadAppWidget = NULL;

	//!当前分类序号 0开始
	int	m_nCurretIndex = 0;
	//防止 连续点击
	QMutex mutex;

	//应用中心首页 获取轮播图和专题应用  十分钟 获取一次
	QTimer *homePageTimer = NULL;

	//应用详情
	AppParticularsDialog *appParticularsDialog = NULL;
private:
	Ui::AppCenterWidget ui;

	//设置ui 界面上 的label  显示无应用(并设置当前属于 哪个界面)
	void setLabelNotApp( bool isShowLabel = true );
	void closeCenterWidget();

private slots:
	//主页
	void on_mainPushButton_clicked(bool checked = false);
	//类别
	void on_categoryPushButton_clicked(bool checked = false);

	//云桌面管理
	void on_managerPushButton_clicked(bool checked = false);
	
	//下载列表
	void on_downloadButton_clicked();

	//打开应用详情
	void openAppParticularsSlot();
	//图片中的应用
	void openAppParticularsSlot(QString appId);

	//搜索
	void onFindBtnClick();
public slots:
	//添加 下载
	void addDownloadItem(AppDownLoadItem *);
signals:
	//操作完成 n取值0 安装  1添加 2移除  3卸载
	void installFilish(int n, AppDataInfo*	pData);
	//刷新界面 有新的下载
	void newFlushClass(QString cateId);
};
