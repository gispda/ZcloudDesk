#pragma once

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QReadWriteLock>
#include "ZhicloudAppDataDefine.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>


class AppCenterDatabase : public QObject
{
	Q_OBJECT

public:
	static AppCenterDatabase *instance()
	{
		if (!m_appCenterDatabase)
		{
			m_appCenterDatabase = new AppCenterDatabase();
		}
		return m_appCenterDatabase;
	};

	//����
	/*//////////////////////////////////////////////////////////////////

	* Function��insertClass

	* Description�� �������

	* Input����

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-08-21 11:37:00

	//////////////////////////////////////////////////////////////////*/
	bool insertClass(AppClassInfo appClassInfo);


	/*//////////////////////////////////////////////////////////////////

	* Function��removeClassAppInfo

	* Description�� ɾ��һ������Ĺ�ϵ��

	* Input����

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2019-03-3 18:37:00

	//////////////////////////////////////////////////////////////////*/
	bool removeClassAppInfo(QString strClassId);

	/*//////////////////////////////////////////////////////////////////

	* Function��removeClassAppInfo_Class

	* Description�� ɾ����Ӧ�ù�ϵ��

	* Input��ɾ����Ӧ��id

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2019-03-05 16:03:00

	//////////////////////////////////////////////////////////////////*/
	bool removeClassAppInfo_Class(QString appId);

	/*//////////////////////////////////////////////////////////////////

	* Function��removeClass

	* Description��ɾ��һ������

	* Input������id

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-08-21 11:37:00

	//////////////////////////////////////////////////////////////////*/
	bool removeClass(QString classId);

	/*//////////////////////////////////////////////////////////////////

	* Function��findAppClassList

	* Description�� ��ѯ���з���

	* Input����

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-03 10:03:00

	//////////////////////////////////////////////////////////////////*/
	bool findAppClassList(QList<AppClassInfo> &appClassInfoList, APPCLASSPAGEFLAG = CLASSALL);


	//Ӧ�� 
	/*//////////////////////////////////////////////////////////////////

	* Function��alterApp

	* Description�� �޸�Ӧ�� replace �����޸� �������

	* Input���޸ĵ�Ӧ

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-03 10:04:00

	//////////////////////////////////////////////////////////////////*/
	bool alterApp(AppDataInfo appDataInfo);



	/*//////////////////////////////////////////////////////////////////

	* Function��updateApp

	* Description�� �޸�Ӧ�� �������� 

	* Input���޸ĵ�Ӧ������ 

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-14 12:49:00

	//////////////////////////////////////////////////////////////////*/
	bool updateApp(AppDataInfo appDataInfo, bool isAppear = false);

	/*//////////////////////////////////////////////////////////////////

	* Function��appearApp

	* Description�� �ϱ������� Ӧ�õİ�װ״̬  1��װӦ�� 2ж��Ӧ�� 3��ʼ����

	* Input�� isInstall ״̬   appId Ӧ��id

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-27 18:37:00

	//////////////////////////////////////////////////////////////////*/
	bool appearApp(QString appId, int isInstall);

	/*//////////////////////////////////////////////////////////////////

	* Function��updateAppPaidTime

	* Description�� ���ĸ���Ӧ�õĵ���ʱ��

	* Input��Ӧ��Id ����ʱ�� isPaid��true����Ӧ�õ���ʱ�� false:����Ӧ�õ���ʱ��

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-10-21 19:21:00

	//////////////////////////////////////////////////////////////////*/
	bool updateAppPaidTime(QString appId, int paidTime, bool isPaid = true);


	/*//////////////////////////////////////////////////////////////////

	* Function��alterClassAppInfo

	* Description�� �޸Ĺ�ϵ��

	* Input���޸ĵ�Ӧ��id���޸ĵķ���id

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-03 13:13:00

	//////////////////////////////////////////////////////////////////*/
	bool alterClassAppInfo(QString appId, QString classId, int sort);




	/*//////////////////////////////////////////////////////////////////

	* Function��findClassAppInfo

	* Description�� ��ѯ��ϵ��

	* Input������Id

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2019-03-04 18:14:00

	//////////////////////////////////////////////////////////////////*/
	bool findClassAppInfo(QString strClassId, QStringList &appIdList);



	/*//////////////////////////////////////////////////////////////////

	* Function��removeApp

	* Description��  ɾ��һ��Ӧ��  �����¼�Ӧ��  ����ǰ��ȡ�����ĺ�Ƚ϶���� Ӧ��

	* Input����Ҫɾ����Ӧ��id

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-03 10:05:00

	//////////////////////////////////////////////////////////////////*/
	bool removeApp(QString appId);

	/*//////////////////////////////////////////////////////////////////

	* Function��updateAppInstallStatus

	* Description��  ����Ӧ�õİ�װ״̬

	* Input����Ҫ���ĵ�Ӧ��id�� ��װ����ж��

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2019-02-25 23:05:00

	//////////////////////////////////////////////////////////////////*/
	bool updateAppInstallStatus(QString appId, bool status);



	/*//////////////////////////////////////////////////////////////////

	* Function��findClassAppList

	* Description��  ��ѯһ�������һ���� ���classId Ϊ�����ѯ���е�Ӧ��

	* Input��Ӧ����������  isInstall:true ��ѯ�Ѱ�װ�ģ��������ʹ�ã� false:���ù�

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-03 11:37:00

	//////////////////////////////////////////////////////////////////*/
	bool findClassAppList(QList<AppDataInfo > &appDataInfoList, QString classId = "", int cutPage = 0, QString findStr = "", bool isInstall = false);


	/*//////////////////////////////////////////////////////////////////

	* Function��findApp

	* Description�� ��ѯһ��Ӧ��

	* Input��Ӧ������  appInfo.id ΪҪ��ѯ��id

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-17 10:54:00

	//////////////////////////////////////////////////////////////////*/
	bool findApp(AppDataInfo &appInfo);

	/*//////////////////////////////////////////////////////////////////

	* Function��insertSider

	* Description��  �����ֲ�ͼ

	* Input��

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-13 19:27:00

	//////////////////////////////////////////////////////////////////*/
	bool insertSider(QList<SliderInfo > sliderInfoList);

	/*//////////////////////////////////////////////////////////////////

	* Function��findSider

	* Description��  ��ѯ�ֲ�ͼ

	* Input��

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-14 10:26:00

	//////////////////////////////////////////////////////////////////*/
	bool findSider(QList<SliderInfo > &sliderInfoList);


	/*//////////////////////////////////////////////////////////////////

	* Function��insertSue

	* Description��  �洢�����������Ӧ��

	* Input��

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-27 15:27:00

	//////////////////////////////////////////////////////////////////*/
	bool insertSue(QStringList issueStringList);

	bool removeOneSue(QString strAppId);

	/*//////////////////////////////////////////////////////////////////

	* Function��readSue

	* Description��  ��ȡδ�ϱ������������Ӧ��

	* Input��

	* Output���Ƿ�ɹ�

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-27 16:04:00

	//////////////////////////////////////////////////////////////////*/
	bool readSue(QStringList &issueStringList);


	//�޸��û�Id
	bool changeAppCenterUserId(QString strOldUserId, QString strNewUserId);

	//ɾ������Ӧ�úͷ���
	bool removeAppAllClassAll(QString strUserId);

	//�޸�Ӧ��ͼ��
	bool updateIconPath(QString strIcon, QString appId);

private:
	explicit AppCenterDatabase(QObject *parent = NULL);
	~AppCenterDatabase();
	//�������ݿ�	
	bool creatAppCenterDb();
	//�����ݿ�
	bool openAppCenterDatabase();

	bool removeAppClass(int);

	//QString freeAESStr(QString byte, QString appId);
	//QString freeStrAEs(QString aesStr, QString appId);

private:
	static AppCenterDatabase * m_appCenterDatabase;
	QReadWriteLock m_readWriteLock;
	QSqlDatabase m_appCenterSqlDatabase;
};
