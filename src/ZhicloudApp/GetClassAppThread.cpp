#include "GetClassAppThread.h"
#include "AppDatabase/AppCenterDatabase.h"
#include "AppCommFun.h"
#include "AppHttpInterface.h"
#include <QDebug>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QApplication>
#include "ZcloudCommon.h"
#include "RightClassAppWidget.h"
#include "Database.h"

extern UserInfoStruct app_userInfo;

GetClassAppThread::GetClassAppThread(QObject *parent)
	:QThread(parent)
{
}


GetClassAppThread::~GetClassAppThread()
{
}


void GetClassAppThread::run()
{
	//获取右侧分类 获取右侧应用
	//获取应用中心分类 获取应用中心应用
	//获取专题分类 获取专题应用

}


