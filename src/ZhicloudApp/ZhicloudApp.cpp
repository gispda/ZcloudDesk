#include "DownloadFile/QDownloadSoftware.h"
 #include "ZhicloudApp.h"
#include "AppDatabase/AppCenterDatabase.h"
#include <QDebug>
#include "RightClassAppWidget.h"
#include "ZhicloudAppDataDefine.h"
#include <QObject>
#include "dlgwait.h"
#include "AppCommFun.h"

UserInfoStruct app_userInfo;
#ifdef VERSION_FOR_GZ
QString  g_strAppName = QString::fromLocal8Bit("爱服务");
#else
QString  g_strAppName = QString::fromLocal8Bit("云财税");
#endif

ZhicloudApp::ZhicloudApp( QObject *parent)
	:QObject(parent)
{
	RightClassAppWidget * rightClassAppWidget = RightClassAppWidget::GetInstance();
	//connect(rightClassAppWidget, SIGNAL(openMemberCenter(QStringList)), this, SIGNAL(openMemberCenter(QStringList)));
	//connect(rightClassAppWidget, SIGNAL(buyAppSignal(QString)), this, SIGNAL(buyAppSignal(QString)));
	rightClassAppWidget->show();
}

void ZhicloudApp::setUserInfo(UserInfoStruct userInfo,
//void ZhicloudApp::setUserInfo(QString userId, QString token, QString taxNumber, QString  strMachine, QString  strHzsId, 
//	QString strUserName, QString strComName, QStringList memberList, QStringList memberNameList, bool isHxMember, 
//	QString strMobile,
	QWidget *parent)
{
	app_userInfo = userInfo;
	//app_userInfo.m_strUserId = userId;
	//app_userInfo.m_strToken = token;
	//app_userInfo.m_strTaxNumber = taxNumber;
	//app_userInfo.m_strMachine = strMachine;			//分机号
	//app_userInfo.m_strHzsId = strHzsId;			//合作商Id

	//app_userInfo.m_strUserName = strUserName;			//用户名
	//app_userInfo.m_strComName = strComName;			//公司名字
	//app_userInfo.m_strListAppVipList = memberList;				//会员等级
	//app_userInfo.m_strListAppVipNameList = memberNameList;		//会员名字
	//app_userInfo.m_nIsHxMember = isHxMember;					//!是否为航信会员 0非 1是
	//app_userInfo.m_strMobile = strMobile;
	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance(parent);
	if (rightClassAppWidget)
	{
		rightClassAppWidget->disconnect(this);
		connect(rightClassAppWidget, SIGNAL(changeTaxSignals(QString, QString)), this, SIGNAL(changeTaxSignals(QString, QString)));
		connect(rightClassAppWidget, &RightClassAppWidget::bindingPhoneSignals, this, &ZhicloudApp::bindingPhoneSignals);
		connect(rightClassAppWidget, SIGNAL(buyVipListSignals(QStringList, QStringList, QStringList)), this, SIGNAL(buyVipListSignals(QStringList, QStringList, QStringList)));
		rightClassAppWidget->startInit();
	}
}

void ZhicloudApp::changeToken(QString token)
{
	app_userInfo.m_strToken = token;
}

void ZhicloudApp::openAppCenterDlg()
{
	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance();
	if (rightClassAppWidget)
	{
		rightClassAppWidget->openAppCenterDlg();
	}
}

bool ZhicloudApp::openZhicloudApp(QString appId)
{
	AppDataInfo pData;
	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance();
	if (rightClassAppWidget)
	{
		return rightClassAppWidget->openApp(appId);
	}
	return false;
}


bool ZhicloudApp::openZhicloudApp(AppDataInfo pInfo, QString type)
{
	AppDataInfo pData;
	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance();
	if (rightClassAppWidget)
	{
		return rightClassAppWidget->openApp(pInfo, type);
	}
	return false;
}

bool ZhicloudApp::getVer(AppDataInfo &pData, bool &isNew, bool isHudgeHave)
{
	return AppCommFun::isHaveNewVerson(pData, isNew, isHudgeHave);
}

void ZhicloudApp::setClassIsHind(bool hindClass, bool isHind)
{
	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance();
	if (rightClassAppWidget)
	{
		rightClassAppWidget->setWidgetHind(hindClass,isHind);
	}
}


void ZhicloudApp::setIsHideNR(bool isHideNR)
{
	app_userInfo.isHideNR = isHideNR;
	//刷新界面
	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance();
	if (rightClassAppWidget)
	{
		rightClassAppWidget->flushButton();
	}
}

ZhicloudApp::~ZhicloudApp()
{
	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance();
	if (rightClassAppWidget)
	{
		rightClassAppWidget->deleteLater();
		rightClassAppWidget = NULL;
	}
}


int ZhicloudApp::openDownloadSoftware(int nDownloadType, QString url,QWidget *parent)
{
	QDownloadSoftware downloadSoftware(nDownloadType, url,parent);
	return downloadSoftware.exec();
}


bool ZhicloudApp::getAppData(QString appId, QString &appName, QString &appIconPath)
{
	AppDataInfo pData;
	pData.m_strAppId = appId;
	if (AppCenterDatabase::instance()->findApp(pData))
	{
		appName = pData.m_strAppAlias.isEmpty() ? pData.m_strAppName : pData.m_strAppAlias;
		appIconPath = pData.m_strAppIconPath;
		return true;
	}
	return false;
}

void ZhicloudApp::closeAppCenter()
{
	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance();
	if (rightClassAppWidget)
	{
		rightClassAppWidget->clearClassButton();
		QProcess p;
		QString c = "taskkill /im ZBrowser.exe /f";
		p.execute(c);
		p.close();
	}
}

void ZhicloudApp::exitAppCenterThread()
{
	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance();
	if (rightClassAppWidget)
	{
		rightClassAppWidget->exitThread();
	}
}

void ZhicloudApp::setMobile(QString strMobile)
{
	app_userInfo.m_strMobile = strMobile;
	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance();
	if (rightClassAppWidget)
	{
		rightClassAppWidget->flushButton();
	}
}

void ZhicloudApp::setToken(QString strToken)
{
	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance();
	if (rightClassAppWidget)
	{
		app_userInfo.m_strToken = strToken;
	}
}

QRect ZhicloudApp::getRightRect()
{

	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance();
	if (rightClassAppWidget)
	{
		return rightClassAppWidget->geometry();
	}
	return QRect();
}


void ZhicloudApp::setVipList(QStringList memberNameList, QStringList memberList, QStringList vipTimeList)
{
	app_userInfo.m_strListAppVipList = memberList;				//会员等级
	app_userInfo.m_strListAppVipNameList = memberNameList;		//会员名字
	app_userInfo.m_vipDateTimeList = vipTimeList;
	RightClassAppWidget *	rightClassAppWidget = RightClassAppWidget::GetInstance();
	if (rightClassAppWidget)
	{
		rightClassAppWidget->flushButton();
	}
}

bool ZhicloudApp::changeAppUserId(QString strOldUserId, QString strNewUserId)
{
	return AppCenterDatabase::instance()->changeAppCenterUserId(strOldUserId, strNewUserId);
}

bool ZhicloudApp::removeAppClassAll(QString strUserId)
{
	return AppCenterDatabase::instance()->removeAppAllClassAll(strUserId);

}

