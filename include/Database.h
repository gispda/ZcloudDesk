#ifndef DATABASE_H
#define DATABASE_H

#ifdef ZCLOUDCOMMON_LIB
# define ZCLOUDCOMMON_EXPORT Q_DECL_EXPORT
#else
# define ZCLOUDCOMMON_EXPORT Q_DECL_IMPORT
#endif
#include <QObject>
#include <QReadWriteLock>
#include <QSqlDatabase>
#include <QDateTime>
#include <QMap>
#include <QVector>
#include "ZhicloudAppDataDefine.h"


//!顶栏工具信息
class TopToolInfo
{
public:
	QString _strUid;
	QString	_strToken;
	//int		_nId = 0;		//!id
	//QString _strTopAppId;	//!顶栏工具id
	//QString _strIcon;		//!图片网络地址
	//QString _strIconPath;	//!图片本地地址
	//QString _strTopAppName;	//!顶栏工具名称
	//QString _strAliasName;	//!顶栏工具别名
	//int		_nAppType;		//!顶栏工具类型（应用类型 1-B/s 2-C/s 3-自定义）
	//QString _strUrl;		//!下载地址 打开链接 wv链接

	QString _strToolId;							//!顶栏工具Id
	QString _strToolName;						//!顶栏工具名称
	QString _strIcon;							//!顶栏工具图标下载地址
	QString _strIconPath;						//!顶栏工具图标本地地址
	QString _strUrl;							//!wv页面链接
	int		_nCreateTime = 0;					//!创建时间
	int		_nUpdateTime = 0;					//!更新时间
	QByteArray  _arryToolList = QByteArray();	//!应用列表
	int		_nSort = 0;							//!排序
	bool	_bIsShow = true;					//!是否显示在顶栏
	bool	_bAuth = false;						//!用户是否有权限进程显隐操作（true的工具将在设置里面展示）
};
//typedef QVector<TopToolInfo*>	vtrTopToolInfos;
typedef QVector<AppDataInfo*>	vtrAppDataInfos; 

struct LoginSetingStruct
{
	bool firstLogin = true;	//第一次登录
	bool autoLogin = true;		//自动登录
	int loginByTax =1;	//税号登录 -2:手机验证码登录 -1:微信登录  0：账号登录  1:税号登录
	bool forcedSwitch = false;	//是否选择税控盘登录
	QString uid;		//用户id
	QString taxNo;		//登录的税号
	QString machine;	//分机号
	QString userName;	//用户名
	QString pwd;		//密码
	QString token;		//token
	bool nextCloudGh = false;	//是否安装插件
	bool bShowGuide = false;	//是否新手引导

};


/////企业开户行信息数据结构
typedef struct CompanyBankInfo
{
	QString m_strTaxno;     ///企业税号
	QString m_strAddress;   ///地址
	QString m_strBankaccount;//企业开户行账号
	QString m_strBankname;  //企业开户行
	QString m_strTelno;     //企业固定电话

};





///客户经理的数据结构
struct UserService
{
	QString m_businessid;  //业务id
	QString m_strUsername;  //用户名
	QString m_strPhone;    //电话
	QString m_strTruename;  //姓名
	QString m_sex;   ///性别 0，1
	int m_nProvinceId;		//省Id
	int m_nCityId;			//市Id
	int m_nAreaId;			//区Id
	QString m_strHzsId;				//合作商Id
	QString m_strAddress;           //地址
	QString m_wechat;              //微信
	QString m_qq;                  //qq
	QString m_nickname;           //昵称
	QString m_avatarurl;          //头像
};

struct UserInfoStruct
{
	QString m_strCompanyId;			//公司业务编号
	QString m_strCompanyName;		//公司名称
	QString m_strTaxNumber;			//税号
	QString m_strProvinceId;		//省Id
	QString m_strCityId;			//市Id
	QString m_strAreaId;			//区Id
	QString m_strHzsId;				//合作商Id

	UserService userservice;        //关联的客户经理信息

	QString m_strMachine;
	QString m_strUsername;			//登录账号
	QString m_strPwd;				//登录密码
	QString m_strTruename;			//真实名字
	QString m_strUserId;			//用户编号
	QString m_sex;                      //性别 0 ,1 
	QString m_strToken;				//token 
	int m_iisbindc;                //有无绑定企业，1至少绑定一个， 0未绑定任何企业
	int m_iisbinds;                ///有无绑定客服经理 1：已绑定 0：未绑定




	QString m_strJob;				//职务
	QString m_logoUrl;				//LOGO链接地址
	QString m_logoPath;				//LOGO链接地址

	QDateTime m_timeChargeExpire;	//服务费到期时间
	bool m_isHxNumber;				//是否是航信会员
	bool m_bHideAppClass;			//!是否隐藏右侧分类（应用和按钮一起）
	bool m_bHasMember;				//!合作商是否上架会员功能
	QStringList m_strListAppVipList;		//vip等级链表
	QStringList m_strListAppVipNameList;//vip等级名字链表
	QStringList m_vipDateTimeList;			//vip 到期时间链表
	int  m_bLoginByTax;			//!是否是税号登录   -8:游客登陆 -2:手机验证码登录 -1:微信登录  0：账号登录  1:税号登录   目前没有税号登陆说法，只是切换当前企业
	QString m_strMobile;			//手机号
	bool isHideNR = false;		//是否隐藏开票软件和重装开票


	QString m_strSign = "";		//用于手机验证码登录为注册 保存sign
};

struct StLnkNameExeName
{
	QString strLnkName;	//lnk名字
	QString strExeName;	//exe名字
	bool isUp;			//是否上报
};


//!切换税号信息
struct stSwitchAccInfo
{
	QString strUid;
	QString strLogoPath;
	QString strTaxNo;
	QString strUserName;
	QString strCompName;
	int    bLoginByTax	=	1; //!是否是税号登录(没有税号登陆说法，只是切换当前企业)  -2 手机验证码 -1:微信登录  0：账号登录  1 : 税号登录没有税号登陆说法，只是切换当前企业
	QString strPwd;
	QString strToken;
	QString strMobliePhone;
	QString strCompId;
	int nIsjoin = 0;
};
typedef QVector<stSwitchAccInfo*>	vtrSwitchAccInfos;


class ZCLOUDCOMMON_EXPORT Database : public QObject
{
	Q_OBJECT

public:

	~Database();
	static Database *GetInstance();
	static void DestoryInstance();

	//!插入顶栏工具信息
	bool insertTopToolInfo(const AppDataInfo*, QString userId);

	//更新顶栏应用
	bool updateTopApp(AppDataInfo appDataInfo, QString userId);

	//!查询顶栏工具信息  isAuth = true  !查询用户可操作的顶栏工具（用于设置中心）
	bool queryTopToolInfo(QString strUid, vtrAppDataInfos& topToolInfos, bool isAuth = false);

	//删除顶栏应用
	bool removeTopToolInfo(QString strUid, QString strTopId);

	//修改顶栏试用到期时间 isPaid：true付费应用到期时间 false:试用应用到期时间
	bool updateTopAppPaidTime(QString appId,QString strUid, int paidTime, bool isPaid = true);

	bool queryUpdateToolInfo(QString strUid, QString strToolId, int& nUpdateTime, QString& strImagePath, bool& bShow);

	//!修改顶栏工具显隐状态
	bool updateToolInfo(QString strUid, QString strToolId, bool bShow);

	//读取登录设置  读取配置的第几个  返回的数据
	bool findLoginSet(LoginSetingStruct &loginSetingStuct);
	//设置登录数据
	bool setLoginSet(LoginSetingStruct loginSetingStuct);

	//设置某个字段
	bool setLoginSet(QString prepareStr);

	//!设置云财税更新信息
	bool setUpdaterInfo(bool bNeedUpdate,QString strFilePath);

	//!读取云财税更新信息
	bool queryUpdaterInfo(bool bNeedUpdate, QString strFilePath);

	//设置用户信息
	bool setUserData(UserInfoStruct userInfoStruct);

	//读取用户信息
	bool readUserData(UserInfoStruct &userInfoStruct,QString strUserId);

	//!判断指定用户的配置信息是否存在
	bool isUserConfigExist(QString strUid);

	//!查询用户配置信息
	bool queryUserConfig(QString strUid,bool& bShowTop,bool& bShowRight);

	//!插入用户配置信息
	bool replaceUserConfig(QString strUid, bool bShowTop = true, bool bShowRight = true);

	//!修改用户配置信息
	bool updateUserConfig(QString strUid, bool bShow, int nType);

	//!读取账号切换信息
	bool querySwitchInfo(vtrSwitchAccInfos& switchInfos);

	//!插入税号
	bool insertTaxInfo(const QStringList& taxInfoList);

	//!查询税号是否存在
	bool findTaxIsExist(QString strTax);

	//!查询已查询到的 lnkExe
	bool findLnkExeName(QList<StLnkNameExeName > &lnkExeList);
	//插入 lnkExe
	bool replaceLnkExeName(const StLnkNameExeName  &stLnkExe);

	//!查询已登录的且有手机号的用户
	bool queryPhoneNumber(QStringList &);

	//!查询上次登录用户的userInfo信息
	bool getUserInfoByPreUser(UserInfoStruct& info);

	//添加该用户的手机号
	bool addPhoneNumber(QString strMobile,QString strUserId);

	//更改用户Id
	bool changeSetUsrId(QString strOldUserId, QString strNewUserId, QString strCompId);
	
	//更改企业中心userId
	bool changeEndUsrId(QString strOldUserId, QString strNewUserId);
	//更改消息中心
	bool changeMsgUsrId(QString strOldUserId, QString strNewUserId);
private:

	bool createDB(QString strPath);

	bool openDatabase();

	//!判断数据库表是否存在
	bool isTableExist(QString strTableName);


	//QString freeAESStr(QString byte, QString userId);
	//QString freeStrAEs(QString aesStr, QString userId);

	explicit Database(QObject *parent = 0);

	QReadWriteLock		m_ReadWriteLock;
	QSqlDatabase		m_DataBase;
	static Database*	m_pDbInstance;
};

class ZCLOUDCOMMON_EXPORT ServerDatabase :public QObject
{
	Q_OBJECT
public:
	~ServerDatabase();
	static ServerDatabase *GetInstance();

	//!应用安装与卸载插入service库
	bool insertAppOper(QString strUid, QString strToken, QString strAppId, QString strCompId, QString strHzsId, int nType);

	//读取未上报的 应用
	bool readAppOper(const QString strUid, QStringList &appIdList, const  int nType);

	//!消息反馈插入service库
	bool insertMsgOper(QString strUid, QString strToken, QString strComId, QString strHzsId, QString strMsgId, int nResType, QString strBtnId);

	//更改用户Id
	bool changeServerUsrId(QString strOldUserId, QString strNewUserId);
private:
	explicit ServerDatabase(QObject *parent = 0);

	//!如果数据库不存在则创建
	bool CreateDBS(QString strPath);

	bool openServerDatabase();

	
	
private:
	//!判断数据库表是否存在
	bool isTableExist(QString strTableName);

	QReadWriteLock  m_SReadWriteLock;
	QSqlDatabase	m_SDataBase;
	static ServerDatabase* m_pSDbInstance;
};

#endif // DATABASE_H
