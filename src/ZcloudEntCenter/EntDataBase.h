#pragma once

#include <QObject>
#include <QReadWriteLock>
#include <QSqlDatabase>
#include <QDateTime>
#include "Database.h"
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
	int     _nProvinceid;      ///企业注册地省份id
	int     _nCityid;          ////企业注册地市id
	int     _nAreaid;          ////企业注册地区id
	QString _strAddress;        ///地址
	int     _nOfficeProvinceid;      ///企业办公地省份id
	int     _nOfficeCityid;          ////企业办公地市id
	int     _nOfficeAreaid;          ////企业办公地区id
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
