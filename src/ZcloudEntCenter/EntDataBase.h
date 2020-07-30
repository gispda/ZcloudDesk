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
	QString _strCompId;		//!��˾���
	QString _strCompName;	//!��˾����
	QString _strTaxNo;		//!˰��
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
