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
	QString _strCompId;		//!��˾���

	QString _strCompName;	//!��˾����
	QString _strTaxNo;		//!˰��
	/////-------------------------������
	QString _strHzsid;           ///������id
	QString _strEmail;          ///��ҵ����
	int _nCompanytype;     /////��ҵ����
	int  _nTradeid;        /////

	LocAddress m_registerAddress;  //��ҵע���ַ
	LocAddress m_officeAddress;   //��ҵ�칫��ַ

	int     _nProvinceid;      ///��ҵע���ʡ��id
	int     _nCityid;          ////��ҵע�����id
	int     _nAreaid;          ////��ҵע�����id
	QString     _strProvince;      ///��ҵע���ʡ��id
	QString     _strCity;          ////��ҵע�����id
	QString     _strArea;          ////��ҵע�����id

	QString _strAddress;        ///��ַ
	int     _nOfficeProvinceid;      ///��ҵ�칫��ʡ��id
	int     _nOfficeCityid;          ////��ҵ�칫����id
	int     _nOfficeAreaid;          ////��ҵ�칫����id
	QString     _strOfficeProvince;      ///��ҵע���ʡ��id
	QString     _strOfficeCity;          ////��ҵע�����id
	QString     _strOfficeArea;          ////��ҵע�����id

	QString _strOfficeaddress;


	int _nisjoin;     ///�û����ް���ҵ��Ϣ

	int _nisbinds;     //�û����ް󶨿ͻ�����
	int _nhasadmin;    ///��ҵ���޹���Ա

	QString _strUid;  
	QString _strUsername;
	QString _strTruename;
	int _nrole_type;   //���id
	QString _strJob;//�û��������ҵ����ݣ�����Ա�������

	QString _strRegisterFulladdress;
	QString _strOfficeFulladdress;

	QString _strlegalboss;   ///����
	QString _strlegalbossmobile;   //���˵绰
	QString  _strBankname;    ///������
	QString  _strBankaccount; //�������˺�


	UserService _oservice;    ///�ͻ�����

	////-----------------------------
	QString _strLogo;		//!ͷ��ͼ��
	QString _strLogoPath;	//!ͷ��ͼ�걾�ص�ַ
	bool	_bIsHxMember		= false;		//!�Ƿ��Ǻ��Ż�Ա
	int		_nChargeExpire		= 0;			//!����ѵ���ʱ��
	int		_nEndDays			= 0;			//!���ŷ����ʣ������
	bool    _bIsManualFulled	= true;			//!�Ƿ��Ѿ��ֶ���������
	bool	_bHasMember			= true;			//!��ǰ�������Ƿ��ϼܻ�Ա����
	QByteArray	_memberList		= QByteArray();	//!��Ա�б�
	int		_nLastSignTime		= 0;			//!���һ��ǩ��ʱ��	
	int		_nCoin				= 0;			//!�Ʊ�
	int		_nCoupon			= 0;			//!�Ż�ȯ
	QString _strCompanyInfoUrl;		//!��ҵ����url
	QString _strTradeInfoUrl;		//!������Ϣurl
	QString _strFinancialMemberUrl;	//!�����Աurl
	QString _strAccountSettingUrl;	//!�˺�����url
	QString _strRenewUrl;			//!���������url
	QString _strMemberInfoUrl;		//!��Ա����url
	QString _strSignUrl;			//!ǩ��Url
	QString _strCreateCompanyUrl;	//!������˾url
	QDateTime	_dtServerTime = QDateTime::currentDateTime();		//!��������ǰʱ��

	int	nAdmin = 0;

	int disk_type;   ////˰�������� 1���̣�2����
	QString strDisk_type;///˰���������ı�

	QString strUse_address;///�Ƿ�ֱ��ʹ����ҵע���ַ��1��ʹ�ã�2��ʹ���µ�ַ

	QString strLicenseUrl;////Ӫҵִ�յ�url

	////����ע����ж�����˰�ţ����ں�̨�ȶԵġ�
	QStringList _strLocalTaxnoLs;

	EntCenterInfo()
	{
		_strId= "";
		_strToken ="";
		_strCompId="";		//!��˾���

		_strCompName="";	//!��˾����
		_strTaxNo = "";		//!˰��
		/////-------------------------������
		_strHzsid = "";           ///������id
		_strEmail = "";          ///��ҵ����
		_nCompanytype=0;     /////��ҵ����
		_nTradeid=0;        /////
		_nProvinceid=-999;      ///��ҵע���ʡ��id
		_nCityid = -999;          ////��ҵע�����id
		_nAreaid = -999;          ////��ҵע�����id
		_strAddress = "";        ///��ַ
		_nOfficeProvinceid = -999;      ///��ҵ�칫��ʡ��id
		_nOfficeCityid = -999;          ////��ҵ�칫����id
		_nOfficeAreaid = -999;          ////��ҵ�칫����id
		_strOfficeaddress = "";

		_nisjoin = 0;     ///�û����ް���ҵ��Ϣ

		_nisbinds = 0;     //�û����ް󶨿ͻ�����
		_nhasadmin = 0;    ///��ҵ���޹���Ա

		_strUid = "";
		_strUsername = "";
		_strTruename = "";
		_nrole_type;   //���id
		_strJob = "";//�û��������ҵ����ݣ�����Ա�������

		_strRegisterFulladdress = "";
		_strOfficeFulladdress = "";

		_strlegalboss = "";   ///����
		_strlegalbossmobile = "";   //���˵绰
		_strBankname = "";    ///������
		_strBankaccount = ""; //�������˺�


		_oservice.m_businessid = "";    ///�ͻ�����
		_oservice.m_nAreaId = -999;    ///�ͻ�����
		_oservice.m_avatarurl = "";    ///�ͻ�����
		_oservice.m_nCityId = -999;    ///�ͻ�����
		_oservice.m_nickname = "";    ///�ͻ�����
		_oservice.m_nProvinceId = -999;    ///�ͻ�����
		_oservice.m_qq = "";    ///�ͻ�����
		_oservice.m_wechat = "";    ///�ͻ�����
		_oservice.m_sex = "";    ///�ͻ�����
		_oservice.m_strAddress = "";    ///�ͻ�����
		_oservice.m_strHzsId = "";    ///�ͻ�����
		_oservice.m_strPhone = "";    ///�ͻ�����
		_oservice.m_strTruename = "";    ///�ͻ�����
		_oservice.m_strUsername = "";    ///�ͻ�����
		
		////-----------------------------
		_strLogo = "";		//!ͷ��ͼ��
		_strLogoPath = "";	//!ͷ��ͼ�걾�ص�ַ
		_bIsHxMember = false;		//!�Ƿ��Ǻ��Ż�Ա
		_nChargeExpire = 0;			//!����ѵ���ʱ��
		_nEndDays = 0;			//!���ŷ����ʣ������
		_bIsManualFulled = true;			//!�Ƿ��Ѿ��ֶ���������
		_bHasMember = true;			//!��ǰ�������Ƿ��ϼܻ�Ա����
		_memberList = QByteArray();	//!��Ա�б�
		_nLastSignTime = 0;			//!���һ��ǩ��ʱ��	
		_nCoin = 0;			//!�Ʊ�
		_nCoupon = 0;			//!�Ż�ȯ
		_strCompanyInfoUrl = "";		//!��ҵ����url
		_strTradeInfoUrl = "";		//!������Ϣurl
		_strFinancialMemberUrl = "";	//!�����Աurl
		_strAccountSettingUrl = "";	//!�˺�����url
		_strRenewUrl = "";			//!���������url
		_strMemberInfoUrl = "";		//!��Ա����url
		_strSignUrl = "";			//!ǩ��Url
		_strCreateCompanyUrl = "";	//!������˾url
		_dtServerTime = QDateTime::currentDateTime();		//!��������ǰʱ��

		nAdmin = 0;

		disk_type = -1;
		strDisk_type = "";

		strLicenseUrl = "";

		strUse_address = "";
		_strLocalTaxnoLs.clear();
	
	}


};
class EntDataBase : public QObject
{
	Q_OBJECT

public:
	~EntDataBase();

	static EntDataBase *GetInstance();
	static void DestoryInstance();

	//!������ҵ��Ϣ
	bool insertEntCenterInfo(const EntCenterInfo& entInfo);

	//!��ѯ��ҵ��Ϣ
	bool queryEntCenterInfo(QString strUid,EntCenterInfo& entInfo);

private:
	//!�ж����ݿ���Ƿ����
	bool isTableExist(QString strTableName);

	//�����ݿ�
	bool openEntDatabase();

	//!������ݿⲻ�����򴴽�
	bool CreateDB(QString strPath);

	explicit EntDataBase(QObject *parent = 0);

	QReadWriteLock		m_ReadWriteLock;
	QSqlDatabase		m_DataBase;
	static EntDataBase*	m_pDbInstance;
};
