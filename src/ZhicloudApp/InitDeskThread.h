#pragma once

#include <QThread>
#include <QMap>
#include <QDateTime>
#include "AppDatabase/AppCenterDatabase.h"

class InitDeskThread : public QThread
{
	Q_OBJECT

public:
	InitDeskThread(QObject *parent);
	~InitDeskThread();
	bool isRunningFlag = true;
	bool m_emitFlag = false;
	volatile bool is_flush_succeed = true;//是否刷新成功 如果没有刷新成功等待下一次循环再发送信号刷新
protected:
	void run();
signals:
	void initDeskSuccess(bool isSuccess);
	void flashButton();
private:
	//储存 存在的 应用id
	QMap<QString ,int> oldAppIdUpTimeMap;
	QMap<QString, int>  newAppIdUpTimeMap;
	//储存 存在的 分类id
	QStringList oldCateIdList;
	QStringList newCateIdList;
	//发布到桌面的应用
	QStringList issueStringList;
	//桌面已安装应用
	QStringList deskAppStringList;

	//获取所有的应用和分类id
	void getOldAppData();
	//解析 分类json 
	bool analysisJson(const QJsonValue, APPCLASSPAGEFLAG);
	//获取所有的分类
	bool getAllClass();
	//判定是否需要更新，如需要更新获取应用详情
	bool upAppData();

	//获取应用是否更新
	bool isUpdateApp(int &last_update_time);

	//获取服务器时间
	void getDateTime();

	//初始化应用中心
	//bool initDatabase(QString cateId, int pageId = 1);
	

	//获取图片
	void updateIconPath();

	//单点登录
	void httpCodeError(int code);


	
	//获取轮播图
	bool getSlideshow();


};
