#pragma once
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QObjectUserData>
#include <QMap>

#define   SCROLLBARSTYESHEET  "QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"



#ifndef   _APPSTATUS_   
#define   _APPSTATUS_   
enum APPSTATUS{
	E_INSTALL,			//安装
	E_INSTALLING,		//安装中
	E_INSTALLDEFEAT,	//安装失败

	E_UNINSTALL,		//卸载
	E_UNINSTALLING,		//卸载中
	E_UNINSTALLDEFEAT,	//卸载失败

	E_OPEN,				//打开

	E_UPDATE,			//升级
	E_UPDATEING,		//升级中
	E_UPDATEDEFEAT		//升级失败
};

enum APPDOWNLOADETYPE
{
	mapp_DOWNLOADING,	//下载中
	mapp_ERROR,			//下载错误
	mapp_TIMEOUTERROR,	//下载超时

	mapp_FINISH,		//下载完成
	mapp_INSTALLFINLSH,	//安装完成
	mapp_INSTALLERROR,	//安装错误
	mapp_PAUSE,			//暂停下载
	mapp_CLOSE			//已关闭的（未下载）
};




enum APPCLASSPAGEFLAG
{
	CLASSALL,				//所有分类
	CLASSDESK,				//桌面管理类别
	CLASSCENTER,			//应用中心类别
	CLASSHOME,				//首页类别
	CLASSRECOMMEND,			//首页推荐应用
	CLASSHOT				//热门应用类别
};



//轮播图信息
class SliderInfo
{
public:
	QString m_strSliderId;		//轮播图id
	QString m_strSliderImgUrl;	//图片下载地址
	bool m_bSliderIsApp;		//是否时 应用
	QString m_strSliderTarget;	//应用id  或者链接
	QString m_strSliderImgPath; //图片本地地址

	bool m_bAppIsDefaultWeb = false; //bs是否是默认浏览器打开
	int sort = 0;

};


//右侧分类信息
class AppClassInfo
{
public:
	QString m_strClassId;
	QString m_strClassName;
	APPCLASSPAGEFLAG m_pageFlag;   //0:类别(自动添加全部分类) 1:桌面管理 2:财税必备 3:为您推荐 4：热门应用
	int m_sort;
	QString m_strReserved1;
	QString m_strReserved2;
};

#define DOWNLOAD_FILE_SUFFIX	"_tmp"
//class UserInfo
//{
//public:
//	QString  m_strUserId;			//用户id
//	QString  m_strToken;			//用户 token
//	QString  m_strTaxNumber;		//税号
//
//	QString  m_strMachine;			//分机号
//	QString  m_strHzsId;			//合作商Id
//	QString  m_strUserName;			//用户名
//	QString	 m_strComName;			//公司名字
//
//	QStringList m_strListAppVipList;		//vip等级链表
//	QStringList m_strListAppVipNameList;//vip等级名字链表
//	QStringList m_strListTimeList;
//	bool		 m_nIsHxMember = false;		//!是否为航信会员 0非 1是
//	int		hxMemberTime = 0;				//会员到期时间
//	bool   isHideNR = false;		//是否隐藏开票软件和重装开票
//	QString m_strMobile;			//手机号
//};

class AppDataInfo
{
public:
	bool bAuth;		//0用户不能隐藏  1用户可以隐藏
	bool bState;		//1默认显示 0：默认不显示
	bool bSMethod;		//传参方式  0：get   1:post    (B/S)
	int m_iUpMethod;		//应用更新模式 0-静默/1-强制提示/2-提示/3-暗示[B/S]

	QString m_strAppId;					//应用id
	QString mStrAppCateId;				//分类Id
	QString m_strAppName;				//应用名字
	QString m_strAppAlias;				//应用别名
	QString m_strAppIconPath;			//应用本地图标路径
	QString m_strAppIconDownUrl;		//应用图标下载地址

	QString m_strAppDownloadUrl;		//应用下载地址 bs的访问地址

	QString m_strAppExecName;			//应用的执行名字
	QString m_strAppExecPathUrl;		//应用的执行路径(cs本地路径 )
	QString m_strAppUninstallPath;		//应用的卸载路径
	QString m_strAppParams;				//免登录参数(如果未空 则无免登录)
	int m_intAppSort = 0;					//应用的顺序
	
	bool m_bAppType;					//应用类型 cs/bs true-B/s false-C/s
	bool m_bAppIsDefaultWeb;			//是否默认浏览器打开
	QString m_strAppFree;				//应用的价格  应用是否收费 0-免费 1-收费
	QStringList m_strListAppVipList;	//vip等级链表
	
	QStringList m_strListAppVipNameList;//vip等级名字链表
	QStringList m_vipEndTimeList;			//会员到期时间链表
	int m_intAppSize = 0;				//软件大小 kb
	int m_iAppDownloadNumber = 0;			//应用下载次数
	QDateTime m_dtAppCreatTimer;		//应用创建时间
	QString m_strAppUpdateSpecification;//更新说明

	QString m_strAppOnLineVerson;		//线上版本
	QString m_strAppCurrentVerson;		//当前版本
	int m_intAppIsForceUpdate;			//是否强制更新 0不强制， 1 提示 2 强制
	bool m_bAppIsInstall = false;		//应用是否安装
	QString m_strAppDesc;				//应用简介

	int m_update_time;			//更新时间
	QString m_enPaidTime = "";			//到期时间
	QString m_enExperienceTime = "";			//试用结束时间
	QString m_experienceTime = "";			//试用时间
	int  m_isBindingPhone = 0;				//是否需要绑定手机号才能用
	QString m_strReserved1;		
	QString m_strReserved2;
	APPDOWNLOADETYPE  m_statusAppButton = mapp_INSTALLFINLSH;
};

class AppUserCustomData :public QObjectUserData
{
public:
	QString strCateId = "";
	QString strName;
	int nCurPage = 1;
	int nTotalPage = 1;

	bool isHavePrePage()
	{
		if (nCurPage <= 1)
		{
			return false;
		}
		return true;
	}
	bool isHaveNextPage()
	{
		if (nCurPage >= nTotalPage)
		{
			return false;
		}
		return true;
	}
	void reset()
	{
		nCurPage = 1;
		nTotalPage = 1;
	}
};

#define MARGIN_WITH 8
#endif  //_APPSTATUS_





