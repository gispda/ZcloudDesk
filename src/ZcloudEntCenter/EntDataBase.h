#pragma once

#include <QObject>
#include <QReadWriteLock>
#include <QSqlDatabase>
#include <QDateTime>
#include "Database.h"
#include "EntDataBase.h"
#include "EntInfoDataDefine.h" 
class EntCenterInfo
{
public:
	QString _strId;   
	QString _strToken;
	QString _strCompId;		//!公司编号

	QString _strCompName;	//!公司名称
	QString _strTaxNo;		//!税号
	/////-------------------------新增加
	QString _strHzsid;           ///合作商id
	QString _strEmail;          ///企业邮箱
	int _nCompanytype;     /////企业类型
	int  _nTradeid;        /////

	LocAddress m_registerAddress;  //企业注册地址
	LocAddress m_officeAddress;   //企业办公地址

	int     _nProvinceid;      ///企业注册地省份id
	int     _nCityid;          ////企业注册地市id
	int     _nAreaid;          ////企业注册地区id
	QString     _strProvince;      ///企业注册地省份id
	QString     _strCity;          ////企业注册地市id
	QString     _strArea;          ////企业注册地区id

	QString _strAddress;        ///地址
	int     _nOfficeProvinceid;      ///企业办公地省份id
	int     _nOfficeCityid;          ////企业办公地市id
	int     _nOfficeAreaid;          ////企业办公地区id
	QString     _strOfficeProvince;      ///企业注册地省份id
	QString     _strOfficeCity;          ////企业注册地市id
	QString     _strOfficeArea;          ////企业注册地区id

	QString _strOfficeaddress;


	int _nisjoin;     ///用户有无绑定企业信息

	int _nisbinds;     //用户有无绑定客户经理
	int _nhasadmin;    ///企业有无管理员

	QString _strUid;  
	QString _strUsername;
	QString _strTruename;
	int _nrole_type;   //身份id
	QString _strJob;//用户在这个企业的身份，管理员，财务等

	QString _strRegisterFulladdress;
	QString _strOfficeFulladdress;

	QString _strlegalboss;   ///法人
	QString _strlegalbossmobile;   //法人电话
	QString  _strBankname;    ///开户行
	QString  _strBankaccount; //开户行账号
	QString  _strTelNumber;		//企业固定电话


	UserService _oservice;    ///客户经理

	////-----------------------------
	QString _strLogo;		//!头像图标
	QString _strLogoPath;	//!头像图标本地地址
	bool	_bIsHxMember		= false;		//!是否是航信会员
	int		_nChargeExpire		= 0;			//!服务费到期时间
	int		_nEndDays			= 0;			//!航信服务费剩余天数
	bool    _bIsManualFulled	= true;			//!是否已经手动完善资料
	bool	_bHasMember			= true;			//!当前合作商是否上架会员功能
	QByteArray	_memberList		= QByteArray();	//!会员列表
	int		_nLastSignTime		= 0;			//!最后一次签到时间	
	int		_nCoin				= 0;			//!云币
	int		_nCoupon			= 0;			//!优惠券
	QString _strCompanyInfoUrl;		//!企业资料url
	QString _strTradeInfoUrl;		//!交易信息url
	QString _strFinancialMemberUrl;	//!财务成员url
	QString _strAccountSettingUrl;	//!账号设置url
	QString _strRenewUrl;			//!服务费续费url
	QString _strMemberInfoUrl;		//!会员详情url
	QString _strSignUrl;			//!签到Url
	QString _strCreateCompanyUrl;	//!创建公司url
	QDateTime	_dtServerTime = QDateTime::currentDateTime();		//!服务器当前时间

	int	nAdmin = 0;

	int disk_type;   ////税控盘类型 1黑盘，2白盘
	QString strDisk_type;///税控盘类型文本

	QString strUse_address;///是否直接使用企业注册地址，1：使用，2：使用新地址

	QString strLicenseUrl;////营业执照的url

	////本地注册表中读出的税号，用于后台比对的。
	QStringList _strLocalTaxnoLs;

	EntCenterInfo()
	{
		_strId= "";
		_strToken ="";
		_strCompId="";		//!公司编号

		_strCompName="";	//!公司名称
		_strTaxNo = "";		//!税号
		/////-------------------------新增加
		_strHzsid = "";           ///合作商id
		_strEmail = "";          ///企业邮箱
		_nCompanytype=0;     /////企业类型
		_nTradeid=0;        /////
		_nProvinceid=-999;      ///企业注册地省份id
		_nCityid = -999;          ////企业注册地市id
		_nAreaid = -999;          ////企业注册地区id
		_strAddress = "";        ///地址
		_nOfficeProvinceid = -999;      ///企业办公地省份id
		_nOfficeCityid = -999;          ////企业办公地市id
		_nOfficeAreaid = -999;          ////企业办公地区id
		_strOfficeaddress = "";

		_nisjoin = 0;     ///用户有无绑定企业信息

		_nisbinds = 0;     //用户有无绑定客户经理
		_nhasadmin = 0;    ///企业有无管理员

		_strUid = "";
		_strUsername = "";
		_strTruename = "";
		_nrole_type = -1;   //身份id
		_strJob = "";//用户在这个企业的身份，管理员，财务等

		_strRegisterFulladdress = "";
		_strOfficeFulladdress = "";

		_strlegalboss = "";   ///法人
		_strlegalbossmobile = "";   //法人电话
		_strBankname = "";    ///开户行
		_strBankaccount = ""; //开户行账号


		_oservice.m_businessid = "";    ///客户经理
		_oservice.m_nAreaId = -999;    ///客户经理
		_oservice.m_avatarurl = "";    ///客户经理
		_oservice.m_nCityId = -999;    ///客户经理
		_oservice.m_nickname = "";    ///客户经理
		_oservice.m_nProvinceId = -999;    ///客户经理
		_oservice.m_qq = "";    ///客户经理
		_oservice.m_wechat = "";    ///客户经理
		_oservice.m_sex = "";    ///客户经理
		_oservice.m_strAddress = "";    ///客户经理
		_oservice.m_strHzsId = "";    ///客户经理
		_oservice.m_strPhone = "";    ///客户经理
		_oservice.m_strTruename = "";    ///客户经理
		_oservice.m_strUsername = "";    ///客户经理
		
		////-----------------------------
		_strLogo = "";		//!头像图标
		_strLogoPath = "";	//!头像图标本地地址
		_bIsHxMember = false;		//!是否是航信会员
		_nChargeExpire = 0;			//!服务费到期时间
		_nEndDays = 0;			//!航信服务费剩余天数
		_bIsManualFulled = true;			//!是否已经手动完善资料
		_bHasMember = true;			//!当前合作商是否上架会员功能
		_memberList = QByteArray();	//!会员列表
		_nLastSignTime = 0;			//!最后一次签到时间	
		_nCoin = 0;			//!云币
		_nCoupon = 0;			//!优惠券
		_strCompanyInfoUrl = "";		//!企业资料url
		_strTradeInfoUrl = "";		//!交易信息url
		_strFinancialMemberUrl = "";	//!财务成员url
		_strAccountSettingUrl = "";	//!账号设置url
		_strRenewUrl = "";			//!服务费续费url
		_strMemberInfoUrl = "";		//!会员详情url
		_strSignUrl = "";			//!签到Url
		_strCreateCompanyUrl = "";	//!创建公司url
		_dtServerTime = QDateTime::currentDateTime();		//!服务器当前时间

		nAdmin = 0;

		disk_type = -1;
		strDisk_type = "";

		strLicenseUrl = "";

		strUse_address = "";
		_strLocalTaxnoLs.clear();
	
	}


	EntCenterInfo operator = (const EntCenterInfo that)
	{
		this->_strId = that._strId;
		this->_strToken = that._strToken;
		this->_strCompId = that._strCompId;		//!公司编号

		this->_strCompName = that._strCompName;	//!公司名称
		this->_strTaxNo = that._strTaxNo;		//!税号
		/////-------------------------新增加
		this->_strHzsid = that._strHzsid;           ///合作商id
		this->_strEmail = that._strEmail;          ///企业邮箱
		this->_nCompanytype = that._nCompanytype;     /////企业类型
		this->_nTradeid = that._nTradeid;        /////
		this->_nProvinceid = that._nProvinceid;      ///企业注册地省份id
		this->_nCityid = that._nCityid;          ////企业注册地市id
		this->_nAreaid = that._nAreaid;          ////企业注册地区id
		this->_strAddress = that._strAddress;        ///地址
		this->_nOfficeProvinceid = that._nOfficeProvinceid;      ///企业办公地省份id
		this->_nOfficeCityid = that._nOfficeCityid;          ////企业办公地市id
		this->_nOfficeAreaid = that._nOfficeAreaid;          ////企业办公地区id
		this->_strOfficeaddress = that._strOfficeaddress;

		this->_nisjoin = that._nisjoin;     ///用户有无绑定企业信息

		this->_nisbinds = that._nisbinds;     //用户有无绑定客户经理
		this->_nhasadmin = that._nhasadmin;    ///企业有无管理员

		this->_strUid = that._strUid;
		this->_strUsername = that._strUsername;
		this->_strTruename = that._strTruename;
		this->_nrole_type = that._nrole_type;   //身份id
		this->_strJob = that._strJob;//用户在这个企业的身份，管理员，财务等

		this->_strRegisterFulladdress = that._strRegisterFulladdress;
		this->_strOfficeFulladdress = that._strOfficeFulladdress;

		this->_strlegalboss = that._strlegalboss;   ///法人
		this->_strlegalbossmobile = that._strlegalbossmobile;   //法人电话
		this->_strBankname = that._strBankname;    ///开户行
		this->_strBankaccount = that._strBankaccount; //开户行账号


		this->_oservice.m_businessid = that._oservice.m_businessid;    ///客户经理
		this->_oservice.m_nAreaId = that._oservice.m_nAreaId;    ///客户经理
		this->_oservice.m_avatarurl = that._oservice.m_avatarurl;    ///客户经理
		this->_oservice.m_nCityId = that._oservice.m_nCityId;    ///客户经理
		this->_oservice.m_nickname = that._oservice.m_nickname;    ///客户经理
		this->_oservice.m_nProvinceId = that._oservice.m_nProvinceId;    ///客户经理
		this->_oservice.m_qq = that._oservice.m_qq;    ///客户经理
		this->_oservice.m_wechat = that._oservice.m_wechat;    ///客户经理
		this->_oservice.m_sex = that._oservice.m_sex;    ///客户经理
		this->_oservice.m_strAddress = that._oservice.m_strAddress;    ///客户经理
		this->_oservice.m_strHzsId = that._oservice.m_strHzsId;    ///客户经理
		this->_oservice.m_strPhone = that._oservice.m_strPhone;    ///客户经理
		this->_oservice.m_strTruename = that._oservice.m_strTruename;    ///客户经理
		this->_oservice.m_strUsername = that._oservice.m_strUsername;    ///客户经理

		////-----------------------------
		this->_strLogo = that._strLogo;		//!头像图标
		this->_strLogoPath = that._strLogoPath;	//!头像图标本地地址
		this->_bIsHxMember = that._bIsHxMember;		//!是否是航信会员
		this->_nChargeExpire = that._nChargeExpire;			//!服务费到期时间
		this->_nEndDays = that._nEndDays;			//!航信服务费剩余天数
		this->_bIsManualFulled = that._bIsManualFulled;			//!是否已经手动完善资料
		this->_bHasMember = that._bHasMember;			//!当前合作商是否上架会员功能
		this->_memberList = that._memberList;	//!会员列表
		this->_nLastSignTime = that._nLastSignTime;			//!最后一次签到时间	
		this->_nCoin = that._nCoin;			//!云币
		this->_nCoupon = that._nCoupon;			//!优惠券
		this->_strCompanyInfoUrl = that._strCompanyInfoUrl;		//!企业资料url
		this->_strTradeInfoUrl = that._strTradeInfoUrl;		//!交易信息url
		this->_strFinancialMemberUrl = that._strFinancialMemberUrl;	//!财务成员url
		this->_strAccountSettingUrl = that._strAccountSettingUrl;	//!账号设置url
		this->_strRenewUrl = that._strRenewUrl;			//!服务费续费url
		this->_strMemberInfoUrl = that._strMemberInfoUrl;		//!会员详情url
		this->_strSignUrl = that._strSignUrl;			//!签到Url
		this->_strCreateCompanyUrl = that._strCreateCompanyUrl;	//!创建公司url
		this->_dtServerTime = that._dtServerTime;		//!服务器当前时间

		this->nAdmin = that.nAdmin;

		this->disk_type = that.disk_type;
		this->strDisk_type = that.strDisk_type;

		this->strLicenseUrl = that.strLicenseUrl;

		this->strUse_address = that.strUse_address;
		this->_strLocalTaxnoLs = that._strLocalTaxnoLs;

		return *this;
	}


};
class EntDataBase : public QObject
{
	Q_OBJECT

public:
	~EntDataBase();

	static EntDataBase *GetInstance();
	static void DestoryInstance();

	//!插入企业信息
	bool insertEntCenterInfo(const EntCenterInfo& entInfo);

	//!查询企业信息
	bool queryEntCenterInfo(QString strUid,EntCenterInfo& entInfo);

private:
	//!判断数据库表是否存在
	bool isTableExist(QString strTableName);

	//打开数据库
	bool openEntDatabase();

	//!如果数据库不存在则创建
	bool CreateDB(QString strPath);

	explicit EntDataBase(QObject *parent = 0);

	QReadWriteLock		m_ReadWriteLock;
	QSqlDatabase		m_DataBase;
	static EntDataBase*	m_pDbInstance;
};
