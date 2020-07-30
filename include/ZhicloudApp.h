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

	* Function��setUserInfo

	* Description�� �����û�����

	* Input��	strUserId;				id
				strToken;				token
				strTaxNumber;			˰��
				strMachine;				�ֻ���
				strHzsId;				������id
				strUserName:			�û�����
				strComName:				��˾����
				memberList;				��Ա�ȼ�����
				memberList:				��Ա��������
				isHxMember;				�Ƿ�Ϊ���Ż�Ա false�� true��

	* Output����

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-08-21 18:23:00

	//////////////////////////////////////////////////////////////////*/
	void setUserInfo(UserInfoStruct,
	//void setUserInfo(QString userId, QString token, QString taxNumber, QString  strMachine, QString  strHzsId, 
	//	QString strUserName, QString strComName, QStringList memberList, QStringList memberNameList, bool isHxMember, 
	//	QString strMobile,
		QWidget *paren = NULL);



	/*//////////////////////////////////////////////////////////////////

	* Function��setClassIsHind

	* Description�� ���÷������Զ�����

	* Input��hindClass:  
						true:���ط�����Ӧ�ÿ� 
						false:ֻ����Ӧ�ÿ�
			isHind:  
						true������  
						false����ʾ

	* Output����

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-08-21 18:23:00

	//////////////////////////////////////////////////////////////////*/
	void setClassIsHind(bool hindClass, bool isHind);



	/*//////////////////////////////////////////////////////////////////

	* Function��openZhicloudApp

	* Description�� ��Ӧ��  ����� ��������

	* Input��Ӧ����Ϣ�ṹ��

	* Output�������Ƿ��������

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-08-21 18:23:00

	//////////////////////////////////////////////////////////////////*/
	bool openZhicloudApp(QString appId);
	bool openZhicloudApp(AppDataInfo pInfo, QString type);


	bool getVer(AppDataInfo &pData, bool &isNew, bool isHudgeHave = true);


	/*//////////////////////////////////////////////////////////////////

	* Function��openAppCenterDlg

	* Description�� ��Ӧ������  ��Ӧ���������ڳ�ʼ��ʱ���ʧ��

	* Input����

	* Output����

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-08-21 18:23:00

	//////////////////////////////////////////////////////////////////*/
	void openAppCenterDlg();


	/*//////////////////////////////////////////////////////////////////

	* Function��setIsHideNR

	* Description�� �����Ƿ����ؿ�Ʊ�������װ��Ʊ

	* Input���Ƿ�����

	* Output����

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-20 18:23:00

	//////////////////////////////////////////////////////////////////*/
	void setIsHideNR(bool isHideNR);

	/*//////////////////////////////////////////////////////////////////

	* Function��openDownloadSoftware

	* Description�� ��װ��Ʊ��� ��main�е���

	* Input��

	* Output

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-27 10:13:00

	//////////////////////////////////////////////////////////////////*/
	static int openDownloadSoftware(int nDownloadType, QString url, QWidget *parent = nullptr);

	
	/*//////////////////////////////////////////////////////////////////

	* Function��getAppData

	* Description����ȡӦ�� ���ֺ� ͼ��

	* Input�� Ӧ��id    

	* Output: �Ƿ����

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-28 12:35:00

	//////////////////////////////////////////////////////////////////*/
	bool getAppData(QString appId, QString &appName, QString &appIconPath);

	/*//////////////////////////////////////////////////////////////////

	* Function��closeAppCenter

	* Description���ر�Ӧ������

	* Input�� ��

	* Output: ��

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-28 12:35:00

	//////////////////////////////////////////////////////////////////*/
	void closeAppCenter();

	//�����߳�
	void exitAppCenterThread();


	/*//////////////////////////////////////////////////////////////////

	* Function��changeToken

	* Description���޸�token  ���� token����

	* Input�� token

	* Output: ��

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-10-08 12:30:00

	//////////////////////////////////////////////////////////////////*/
	void changeToken(QString token);


	/*//////////////////////////////////////////////////////////////////

	* Function��setMobile

	* Description�� �����ֻ���

	* Input�� strMobile �ֻ���

	* Output: ��

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-12-26 11:32:00

	//////////////////////////////////////////////////////////////////*/
	void setMobile(QString strMobile);

	void setToken(QString strToken);

	QRect getRightRect();


	//����vip
	void setVipList(QStringList, QStringList,QStringList);

	//�޸��û�Id
	bool changeAppUserId(QString strOldUserId, QString strNewUserId);

	//ɾ������Ӧ��
	bool removeAppClassAll(QString strUserId);
signals:
	/*//////////////////////////////////////////////////////////////////

	* Function��changeTaxSignals

	* Description�� ���ؿ�Ʊ�����鵽�µĿ�Ʊ�����Ҫ�л�˰��

	* Input��strTaxNo��˰��  strMachine���ֻ���

	* Output����

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-08-21 18:23:00

	//////////////////////////////////////////////////////////////////*/
	void changeTaxSignals(QString strTaxNo, QString strMachine);
	
	/*//////////////////////////////////////////////////////////////////

	* Function��openMemberCenter

	* Description�� �򿪻�Ա���� ���ѻ�Ա 

	* Input��QStringList: ��Ӧ�� ����Ҫ�� ��Ա�ȼ�����

	* Output����

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-29 17:27:00

	//////////////////////////////////////////////////////////////////*/
	//void openMemberCenter(QStringList);

	/*//////////////////////////////////////////////////////////////////

	* Function��buyAppSignal

	* Description������Ӧ�� 

	* Input��appId:��Ҫ�����Ӧ��id

	* Output����

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-09-29 17:28:00

	//////////////////////////////////////////////////////////////////*/
	//void buyAppSignal(QString appId);



	/*//////////////////////////////////////////////////////////////////

	* Function��bindingPhoneSignals

	* Description�����ֻ���

	* Input�� ��

	* Output����

	* Others:

	* ���ߣ�Tohn

	* ���ڣ�2018-12-26 11:19:00

	//////////////////////////////////////////////////////////////////*/
	void bindingPhoneSignals();

	void buyVipListSignals(QStringList, QStringList, QStringList);

private:
};




#endif // ZHICLOUDAPP_H
