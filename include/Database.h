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


//!����������Ϣ
class TopToolInfo
{
public:
	QString _strUid;
	QString	_strToken;
	//int		_nId = 0;		//!id
	//QString _strTopAppId;	//!��������id
	//QString _strIcon;		//!ͼƬ�����ַ
	//QString _strIconPath;	//!ͼƬ���ص�ַ
	//QString _strTopAppName;	//!������������
	//QString _strAliasName;	//!�������߱���
	//int		_nAppType;		//!�����������ͣ�Ӧ������ 1-B/s 2-C/s 3-�Զ��壩
	//QString _strUrl;		//!���ص�ַ ������ wv����

	QString _strToolId;							//!��������Id
	QString _strToolName;						//!������������
	QString _strIcon;							//!��������ͼ�����ص�ַ
	QString _strIconPath;						//!��������ͼ�걾�ص�ַ
	QString _strUrl;							//!wvҳ������
	int		_nCreateTime = 0;					//!����ʱ��
	int		_nUpdateTime = 0;					//!����ʱ��
	QByteArray  _arryToolList = QByteArray();	//!Ӧ���б�
	int		_nSort = 0;							//!����
	bool	_bIsShow = true;					//!�Ƿ���ʾ�ڶ���
	bool	_bAuth = false;						//!�û��Ƿ���Ȩ�޽�������������true�Ĺ��߽�����������չʾ��
};
//typedef QVector<TopToolInfo*>	vtrTopToolInfos;
typedef QVector<AppDataInfo*>	vtrAppDataInfos; 

struct LoginSetingStruct
{
	bool firstLogin = true;	//��һ�ε�¼
	bool autoLogin = true;		//�Զ���¼
	int loginByTax =1;	//˰�ŵ�¼ -2:�ֻ���֤���¼ -1:΢�ŵ�¼  0���˺ŵ�¼  1:˰�ŵ�¼
	bool forcedSwitch = false;	//�Ƿ�ѡ��˰���̵�¼
	QString uid;		//�û�id
	QString taxNo;		//��¼��˰��
	QString machine;	//�ֻ���
	QString userName;	//�û���
	QString pwd;		//����
	QString token;		//token
	bool nextCloudGh = false;	//�Ƿ�װ���
	bool bShowGuide = false;	//�Ƿ���������

};


/////��ҵ��������Ϣ���ݽṹ
typedef struct CompanyBankInfo
{
	QString m_strTaxno;     ///��ҵ˰��
	QString m_strAddress;   ///��ַ
	QString m_strBankaccount;//��ҵ�������˺�
	QString m_strBankname;  //��ҵ������
	QString m_strTelno;     //��ҵ�̶��绰

};





///�ͻ���������ݽṹ
struct UserService
{
	QString m_businessid;  //ҵ��id
	QString m_strUsername;  //�û���
	QString m_strPhone;    //�绰
	QString m_strTruename;  //����
	QString m_sex;   ///�Ա� 0��1
	int m_nProvinceId;		//ʡId
	int m_nCityId;			//��Id
	int m_nAreaId;			//��Id
	QString m_strHzsId;				//������Id
	QString m_strAddress;           //��ַ
	QString m_wechat;              //΢��
	QString m_qq;                  //qq
	QString m_nickname;           //�ǳ�
	QString m_avatarurl;          //ͷ��
};

struct UserInfoStruct
{
	QString m_strCompanyId;			//��˾ҵ����
	QString m_strCompanyName;		//��˾����
	QString m_strTaxNumber;			//˰��
	QString m_strProvinceId;		//ʡId
	QString m_strCityId;			//��Id
	QString m_strAreaId;			//��Id
	QString m_strHzsId;				//������Id

	UserService userservice;        //�����Ŀͻ�������Ϣ

	QString m_strMachine;
	QString m_strUsername;			//��¼�˺�
	QString m_strPwd;				//��¼����
	QString m_strTruename;			//��ʵ����
	QString m_strUserId;			//�û����
	QString m_sex;                      //�Ա� 0 ,1 
	QString m_strToken;				//token 
	int m_iisbindc;                //���ް���ҵ��1���ٰ�һ���� 0δ���κ���ҵ
	int m_iisbinds;                ///���ް󶨿ͷ����� 1���Ѱ� 0��δ��




	QString m_strJob;				//ְ��
	QString m_logoUrl;				//LOGO���ӵ�ַ
	QString m_logoPath;				//LOGO���ӵ�ַ

	QDateTime m_timeChargeExpire;	//����ѵ���ʱ��
	bool m_isHxNumber;				//�Ƿ��Ǻ��Ż�Ա
	bool m_bHideAppClass;			//!�Ƿ������Ҳ���ࣨӦ�úͰ�ťһ��
	bool m_bHasMember;				//!�������Ƿ��ϼܻ�Ա����
	QStringList m_strListAppVipList;		//vip�ȼ�����
	QStringList m_strListAppVipNameList;//vip�ȼ���������
	QStringList m_vipDateTimeList;			//vip ����ʱ������
	int  m_bLoginByTax;			//!�Ƿ���˰�ŵ�¼   -8:�ο͵�½ -2:�ֻ���֤���¼ -1:΢�ŵ�¼  0���˺ŵ�¼  1:˰�ŵ�¼   Ŀǰû��˰�ŵ�½˵����ֻ���л���ǰ��ҵ
	QString m_strMobile;			//�ֻ���
	bool isHideNR = false;		//�Ƿ����ؿ�Ʊ�������װ��Ʊ


	QString m_strSign = "";		//�����ֻ���֤���¼Ϊע�� ����sign
};

struct StLnkNameExeName
{
	QString strLnkName;	//lnk����
	QString strExeName;	//exe����
	bool isUp;			//�Ƿ��ϱ�
};


//!�л�˰����Ϣ
struct stSwitchAccInfo
{
	QString strUid;
	QString strLogoPath;
	QString strTaxNo;
	QString strUserName;
	QString strCompName;
	int    bLoginByTax	=	1; //!�Ƿ���˰�ŵ�¼(û��˰�ŵ�½˵����ֻ���л���ǰ��ҵ)  -2 �ֻ���֤�� -1:΢�ŵ�¼  0���˺ŵ�¼  1 : ˰�ŵ�¼û��˰�ŵ�½˵����ֻ���л���ǰ��ҵ
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

	//!���붥��������Ϣ
	bool insertTopToolInfo(const AppDataInfo*, QString userId);

	//���¶���Ӧ��
	bool updateTopApp(AppDataInfo appDataInfo, QString userId);

	//!��ѯ����������Ϣ  isAuth = true  !��ѯ�û��ɲ����Ķ������ߣ������������ģ�
	bool queryTopToolInfo(QString strUid, vtrAppDataInfos& topToolInfos, bool isAuth = false);

	//ɾ������Ӧ��
	bool removeTopToolInfo(QString strUid, QString strTopId);

	//�޸Ķ������õ���ʱ�� isPaid��true����Ӧ�õ���ʱ�� false:����Ӧ�õ���ʱ��
	bool updateTopAppPaidTime(QString appId,QString strUid, int paidTime, bool isPaid = true);

	bool queryUpdateToolInfo(QString strUid, QString strToolId, int& nUpdateTime, QString& strImagePath, bool& bShow);

	//!�޸Ķ�����������״̬
	bool updateToolInfo(QString strUid, QString strToolId, bool bShow);

	//��ȡ��¼����  ��ȡ���õĵڼ���  ���ص�����
	bool findLoginSet(LoginSetingStruct &loginSetingStuct);
	//���õ�¼����
	bool setLoginSet(LoginSetingStruct loginSetingStuct);

	//����ĳ���ֶ�
	bool setLoginSet(QString prepareStr);

	//!�����Ʋ�˰������Ϣ
	bool setUpdaterInfo(bool bNeedUpdate,QString strFilePath);

	//!��ȡ�Ʋ�˰������Ϣ
	bool queryUpdaterInfo(bool bNeedUpdate, QString strFilePath);

	//�����û���Ϣ
	bool setUserData(UserInfoStruct userInfoStruct);

	//��ȡ�û���Ϣ
	bool readUserData(UserInfoStruct &userInfoStruct,QString strUserId);

	//!�ж�ָ���û���������Ϣ�Ƿ����
	bool isUserConfigExist(QString strUid);

	//!��ѯ�û�������Ϣ
	bool queryUserConfig(QString strUid,bool& bShowTop,bool& bShowRight);

	//!�����û�������Ϣ
	bool replaceUserConfig(QString strUid, bool bShowTop = true, bool bShowRight = true);

	//!�޸��û�������Ϣ
	bool updateUserConfig(QString strUid, bool bShow, int nType);

	//!��ȡ�˺��л���Ϣ
	bool querySwitchInfo(vtrSwitchAccInfos& switchInfos);

	//!����˰��
	bool insertTaxInfo(const QStringList& taxInfoList);

	//!��ѯ˰���Ƿ����
	bool findTaxIsExist(QString strTax);

	//!��ѯ�Ѳ�ѯ���� lnkExe
	bool findLnkExeName(QList<StLnkNameExeName > &lnkExeList);
	//���� lnkExe
	bool replaceLnkExeName(const StLnkNameExeName  &stLnkExe);

	//!��ѯ�ѵ�¼�������ֻ��ŵ��û�
	bool queryPhoneNumber(QStringList &);

	//!��ѯ�ϴε�¼�û���userInfo��Ϣ
	bool getUserInfoByPreUser(UserInfoStruct& info);

	//��Ӹ��û����ֻ���
	bool addPhoneNumber(QString strMobile,QString strUserId);

	//�����û�Id
	bool changeSetUsrId(QString strOldUserId, QString strNewUserId, QString strCompId);
	
	//������ҵ����userId
	bool changeEndUsrId(QString strOldUserId, QString strNewUserId);
	//������Ϣ����
	bool changeMsgUsrId(QString strOldUserId, QString strNewUserId);
private:

	bool createDB(QString strPath);

	bool openDatabase();

	//!�ж����ݿ���Ƿ����
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

	//!Ӧ�ð�װ��ж�ز���service��
	bool insertAppOper(QString strUid, QString strToken, QString strAppId, QString strCompId, QString strHzsId, int nType);

	//��ȡδ�ϱ��� Ӧ��
	bool readAppOper(const QString strUid, QStringList &appIdList, const  int nType);

	//!��Ϣ��������service��
	bool insertMsgOper(QString strUid, QString strToken, QString strComId, QString strHzsId, QString strMsgId, int nResType, QString strBtnId);

	//�����û�Id
	bool changeServerUsrId(QString strOldUserId, QString strNewUserId);
private:
	explicit ServerDatabase(QObject *parent = 0);

	//!������ݿⲻ�����򴴽�
	bool CreateDBS(QString strPath);

	bool openServerDatabase();

	
	
private:
	//!�ж����ݿ���Ƿ����
	bool isTableExist(QString strTableName);

	QReadWriteLock  m_SReadWriteLock;
	QSqlDatabase	m_SDataBase;
	static ServerDatabase* m_pSDbInstance;
};

#endif // DATABASE_H
