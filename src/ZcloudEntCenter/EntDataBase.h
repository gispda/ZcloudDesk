#pragma once

#include <QObject>
#include <QReadWriteLock>
#include <QSqlDatabase>
#include <QDateTime>
class EntCenterInfo
{
public:
	QString _strUid;
	QString _strToken;
	QString _strCompId;		//!公司编号
	QString _strCompName;	//!公司名称
	QString _strTaxNo;		//!税号
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
