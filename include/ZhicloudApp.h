#ifndef ZHICLOUDAPP_H
#define ZHICLOUDAPP_H

#include <QtCore/qglobal.h>

#include <QWidget>
#include <QObject>
#include <QRect>
#include "ZhicloudAppDataDefine.h"
#include "Database.h"

#ifdef ZHICLOUDAPP_LIB
# define ZHICLOUDAPP_EXPORT Q_DECL_EXPORT
#else
# define ZHICLOUDAPP_EXPORT Q_DECL_IMPORT
#endif



class RightClassAppWidget;
class ZHICLOUDAPP_EXPORT ZhicloudApp : public QObject
{
	Q_OBJECT
public:
	ZhicloudApp( QObject *parent = 0);
	~ZhicloudApp();


	/*//////////////////////////////////////////////////////////////////

	* Function：setUserInfo

	* Description： 设置用户信心

	* Input：	strUserId;				id
				strToken;				token
				strTaxNumber;			税号
				strMachine;				分机号
				strHzsId;				合作商id
				strUserName:			用户名字
				strComName:				公司名字
				memberList;				会员等级链表
				memberList:				会员名字链表
				isHxMember;				是否为航信会员 false非 true是

	* Output：无

	* Others:

	* 作者：Tohn

	* 日期：2018-08-21 18:23:00

	//////////////////////////////////////////////////////////////////*/
	void setUserInfo(UserInfoStruct,
	//void setUserInfo(QString userId, QString token, QString taxNumber, QString  strMachine, QString  strHzsId, 
	//	QString strUserName, QString strComName, QStringList memberList, QStringList memberNameList, bool isHxMember, 
	//	QString strMobile,
		QWidget *paren = NULL);



	/*//////////////////////////////////////////////////////////////////

	* Function：setClassIsHind

	* Description： 设置分类框的自动隐藏

	* Input：hindClass:  
						true:隐藏分类框和应用框 
						false:只隐藏应用框；
			isHind:  
						true：隐藏  
						false：显示

	* Output：无

	* Others:

	* 作者：Tohn

	* 日期：2018-08-21 18:23:00

	//////////////////////////////////////////////////////////////////*/
	void setClassIsHind(bool hindClass, bool isHind);



	/*//////////////////////////////////////////////////////////////////

	* Function：openZhicloudApp

	* Description： 打开应用  有则打开 无则下载

	* Input：应用信息结构体

	* Output：返回是否可以下载

	* Others:

	* 作者：Tohn

	* 日期：2018-08-21 18:23:00

	//////////////////////////////////////////////////////////////////*/
	bool openZhicloudApp(QString appId);
	bool openZhicloudApp(AppDataInfo pInfo, QString type);


	bool getVer(AppDataInfo &pData, bool &isNew, bool isHudgeHave = true);


	/*//////////////////////////////////////////////////////////////////

	* Function：openAppCenterDlg

	* Description： 打开应用中心  当应用中心正在初始化时会打开失败

	* Input：无

	* Output：无

	* Others:

	* 作者：Tohn

	* 日期：2018-08-21 18:23:00

	//////////////////////////////////////////////////////////////////*/
	void openAppCenterDlg();


	/*//////////////////////////////////////////////////////////////////

	* Function：setIsHideNR

	* Description： 设置是否隐藏开票软件和重装开票

	* Input：是否隐藏

	* Output：无

	* Others:

	* 作者：Tohn

	* 日期：2018-09-20 18:23:00

	//////////////////////////////////////////////////////////////////*/
	void setIsHideNR(bool isHideNR);

	/*//////////////////////////////////////////////////////////////////

	* Function：openDownloadSoftware

	* Description： 安装开票软件 在main中调用

	* Input：

	* Output

	* Others:

	* 作者：Tohn

	* 日期：2018-09-27 10:13:00

	//////////////////////////////////////////////////////////////////*/
	static int openDownloadSoftware(int nDownloadType, QString url, QWidget *parent = nullptr);

	
	/*//////////////////////////////////////////////////////////////////

	* Function：getAppData

	* Description：获取应用 名字和 图标

	* Input： 应用id    

	* Output: 是否存在

	* Others:

	* 作者：Tohn

	* 日期：2018-09-28 12:35:00

	//////////////////////////////////////////////////////////////////*/
	bool getAppData(QString appId, QString &appName, QString &appIconPath);

	/*//////////////////////////////////////////////////////////////////

	* Function：closeAppCenter

	* Description：关闭应用中心

	* Input： 无

	* Output: 无

	* Others:

	* 作者：Tohn

	* 日期：2018-09-28 12:35:00

	//////////////////////////////////////////////////////////////////*/
	void closeAppCenter();

	//结束线程
	void exitAppCenterThread();


	/*//////////////////////////////////////////////////////////////////

	* Function：changeToken

	* Description：修改token  用于 token过期

	* Input： token

	* Output: 无

	* Others:

	* 作者：Tohn

	* 日期：2018-10-08 12:30:00

	//////////////////////////////////////////////////////////////////*/
	void changeToken(QString token);


	/*//////////////////////////////////////////////////////////////////

	* Function：setMobile

	* Description： 设置手机号

	* Input： strMobile 手机号

	* Output: 无

	* Others:

	* 作者：Tohn

	* 日期：2018-12-26 11:32:00

	//////////////////////////////////////////////////////////////////*/
	void setMobile(QString strMobile);

	void setToken(QString strToken);

	QRect getRightRect();


	//设置vip
	void setVipList(QStringList, QStringList,QStringList);

	//修改用户Id
	bool changeAppUserId(QString strOldUserId, QString strNewUserId);

	//删除所有应用
	bool removeAppClassAll(QString strUserId);
signals:
	/*//////////////////////////////////////////////////////////////////

	* Function：changeTaxSignals

	* Description： 下载开票软件检查到新的开票软件需要切换税号

	* Input：strTaxNo：税号  strMachine：分机号

	* Output：无

	* Others:

	* 作者：Tohn

	* 日期：2018-08-21 18:23:00

	//////////////////////////////////////////////////////////////////*/
	void changeTaxSignals(QString strTaxNo, QString strMachine);
	
	/*//////////////////////////////////////////////////////////////////

	* Function：openMemberCenter

	* Description： 打开会员中心 续费会员 

	* Input：QStringList: 该应用 所需要的 会员等级链表

	* Output：无

	* Others:

	* 作者：Tohn

	* 日期：2018-09-29 17:27:00

	//////////////////////////////////////////////////////////////////*/
	//void openMemberCenter(QStringList);

	/*//////////////////////////////////////////////////////////////////

	* Function：buyAppSignal

	* Description：购买应用 

	* Input：appId:需要购买的应用id

	* Output：无

	* Others:

	* 作者：Tohn

	* 日期：2018-09-29 17:28:00

	//////////////////////////////////////////////////////////////////*/
	//void buyAppSignal(QString appId);



	/*//////////////////////////////////////////////////////////////////

	* Function：bindingPhoneSignals

	* Description：绑定手机号

	* Input： 无

	* Output：无

	* Others:

	* 作者：Tohn

	* 日期：2018-12-26 11:19:00

	//////////////////////////////////////////////////////////////////*/
	void bindingPhoneSignals();

	void buyVipListSignals(QStringList, QStringList, QStringList);

private:
};




#endif // ZHICLOUDAPP_H
