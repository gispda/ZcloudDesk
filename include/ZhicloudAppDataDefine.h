#pragma once
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QObjectUserData>
#include <QMap>

#define   SCROLLBARSTYESHEET  "QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"



#ifndef   _APPSTATUS_   
#define   _APPSTATUS_   
enum APPSTATUS{
	E_INSTALL,			//��װ
	E_INSTALLING,		//��װ��
	E_INSTALLDEFEAT,	//��װʧ��

	E_UNINSTALL,		//ж��
	E_UNINSTALLING,		//ж����
	E_UNINSTALLDEFEAT,	//ж��ʧ��

	E_OPEN,				//��

	E_UPDATE,			//����
	E_UPDATEING,		//������
	E_UPDATEDEFEAT		//����ʧ��
};

enum APPDOWNLOADETYPE
{
	mapp_DOWNLOADING,	//������
	mapp_ERROR,			//���ش���
	mapp_TIMEOUTERROR,	//���س�ʱ

	mapp_FINISH,		//�������
	mapp_INSTALLFINLSH,	//��װ���
	mapp_INSTALLERROR,	//��װ����
	mapp_PAUSE,			//��ͣ����
	mapp_CLOSE			//�ѹرյģ�δ���أ�
};




enum APPCLASSPAGEFLAG
{
	CLASSALL,				//���з���
	CLASSDESK,				//����������
	CLASSCENTER,			//Ӧ���������
	CLASSHOME,				//��ҳ���
	CLASSRECOMMEND,			//��ҳ�Ƽ�Ӧ��
	CLASSHOT				//����Ӧ�����
};



//�ֲ�ͼ��Ϣ
class SliderInfo
{
public:
	QString m_strSliderId;		//�ֲ�ͼid
	QString m_strSliderImgUrl;	//ͼƬ���ص�ַ
	bool m_bSliderIsApp;		//�Ƿ�ʱ Ӧ��
	QString m_strSliderTarget;	//Ӧ��id  ��������
	QString m_strSliderImgPath; //ͼƬ���ص�ַ

	bool m_bAppIsDefaultWeb = false; //bs�Ƿ���Ĭ���������
	int sort = 0;

};


//�Ҳ������Ϣ
class AppClassInfo
{
public:
	QString m_strClassId;
	QString m_strClassName;
	APPCLASSPAGEFLAG m_pageFlag;   //0:���(�Զ����ȫ������) 1:������� 2:��˰�ر� 3:Ϊ���Ƽ� 4������Ӧ��
	int m_sort;
	QString m_strReserved1;
	QString m_strReserved2;
};

#define DOWNLOAD_FILE_SUFFIX	"_tmp"
//class UserInfo
//{
//public:
//	QString  m_strUserId;			//�û�id
//	QString  m_strToken;			//�û� token
//	QString  m_strTaxNumber;		//˰��
//
//	QString  m_strMachine;			//�ֻ���
//	QString  m_strHzsId;			//������Id
//	QString  m_strUserName;			//�û���
//	QString	 m_strComName;			//��˾����
//
//	QStringList m_strListAppVipList;		//vip�ȼ�����
//	QStringList m_strListAppVipNameList;//vip�ȼ���������
//	QStringList m_strListTimeList;
//	bool		 m_nIsHxMember = false;		//!�Ƿ�Ϊ���Ż�Ա 0�� 1��
//	int		hxMemberTime = 0;				//��Ա����ʱ��
//	bool   isHideNR = false;		//�Ƿ����ؿ�Ʊ�������װ��Ʊ
//	QString m_strMobile;			//�ֻ���
//};

class AppDataInfo
{
public:
	bool bAuth;		//0�û���������  1�û���������
	bool bState;		//1Ĭ����ʾ 0��Ĭ�ϲ���ʾ
	bool bSMethod;		//���η�ʽ  0��get   1:post    (B/S)
	int m_iUpMethod;		//Ӧ�ø���ģʽ 0-��Ĭ/1-ǿ����ʾ/2-��ʾ/3-��ʾ[B/S]

	QString m_strAppId;					//Ӧ��id
	QString mStrAppCateId;				//����Id
	QString m_strAppName;				//Ӧ������
	QString m_strAppAlias;				//Ӧ�ñ���
	QString m_strAppIconPath;			//Ӧ�ñ���ͼ��·��
	QString m_strAppIconDownUrl;		//Ӧ��ͼ�����ص�ַ

	QString m_strAppDownloadUrl;		//Ӧ�����ص�ַ bs�ķ��ʵ�ַ

	QString m_strAppExecName;			//Ӧ�õ�ִ������
	QString m_strAppExecPathUrl;		//Ӧ�õ�ִ��·��(cs����·�� )
	QString m_strAppUninstallPath;		//Ӧ�õ�ж��·��
	QString m_strAppParams;				//���¼����(���δ�� �������¼)
	int m_intAppSort = 0;					//Ӧ�õ�˳��
	
	bool m_bAppType;					//Ӧ������ cs/bs true-B/s false-C/s
	bool m_bAppIsDefaultWeb;			//�Ƿ�Ĭ���������
	QString m_strAppFree;				//Ӧ�õļ۸�  Ӧ���Ƿ��շ� 0-��� 1-�շ�
	QStringList m_strListAppVipList;	//vip�ȼ�����
	
	QStringList m_strListAppVipNameList;//vip�ȼ���������
	QStringList m_vipEndTimeList;			//��Ա����ʱ������
	int m_intAppSize = 0;				//�����С kb
	int m_iAppDownloadNumber = 0;			//Ӧ�����ش���
	QDateTime m_dtAppCreatTimer;		//Ӧ�ô���ʱ��
	QString m_strAppUpdateSpecification;//����˵��

	QString m_strAppOnLineVerson;		//���ϰ汾
	QString m_strAppCurrentVerson;		//��ǰ�汾
	int m_intAppIsForceUpdate;			//�Ƿ�ǿ�Ƹ��� 0��ǿ�ƣ� 1 ��ʾ 2 ǿ��
	bool m_bAppIsInstall = false;		//Ӧ���Ƿ�װ
	QString m_strAppDesc;				//Ӧ�ü��

	int m_update_time;			//����ʱ��
	QString m_enPaidTime = "";			//����ʱ��
	QString m_enExperienceTime = "";			//���ý���ʱ��
	QString m_experienceTime = "";			//����ʱ��
	int  m_isBindingPhone = 0;				//�Ƿ���Ҫ���ֻ��Ų�����
	QString m_strReserved1;		
	QString m_strReserved2;
	APPDOWNLOADETYPE  m_statusAppButton = mapp_INSTALLFINLSH;
};

class AppUserCustomData :public QObjectUserData
{
public:
	QString strCateId = "";
	QString strName;
	int nCurPage = 1;
	int nTotalPage = 1;

	bool isHavePrePage()
	{
		if (nCurPage <= 1)
		{
			return false;
		}
		return true;
	}
	bool isHaveNextPage()
	{
		if (nCurPage >= nTotalPage)
		{
			return false;
		}
		return true;
	}
	void reset()
	{
		nCurPage = 1;
		nTotalPage = 1;
	}
};

#define MARGIN_WITH 8
#endif  //_APPSTATUS_





