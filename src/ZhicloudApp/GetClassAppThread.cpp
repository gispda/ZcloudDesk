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
	//��ȡ�Ҳ���� ��ȡ�Ҳ�Ӧ��
	//��ȡӦ�����ķ��� ��ȡӦ������Ӧ��
	//��ȡר����� ��ȡר��Ӧ��

}


