#ifndef ZCLOUDENTCENTERIMPL_H
#define ZCLOUDENTCENTERIMPL_H
#include <QObject>
#include "ZcloudEntCenter.h"
#include "EntCenterWidget.h"
#include "VipInfoWidget.h"
#include "InfoCenterWidget.h"
class ZcloudEntCenterImpl : public ZcloudEntCenter
{
	Q_OBJECT

public:
	ZcloudEntCenterImpl();
	~ZcloudEntCenterImpl();


	virtual void setUserInfo(UserInfoStruct _userInfo);

	//!�����û�����
	void setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId, QString strUserName) ;

	//!���ٶ���
	virtual void destroy();
	//!�½���ҵ
	virtual void createEntCenter(QString strUid, QString strToken);
	//!�򿪹����б�
	virtual void openWorkers(QString strUid, QString strToken);

	//!����ҵ����
	virtual void openEntCenter(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId, QString strUserName);

	void getInfoCenterWidget()
	{
		if (NULL == m_pInfoCenterWidget)
		{
			m_pInfoCenterWidget = new InfoCenterWidget(&m_userInfo);

			connect(m_pInfoCenterWidget, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));
			//connect(this, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));
		}
	}

	//! ��ҵ�����Ƿ���ʾ
	virtual bool isEntCenterShow();

	//�����ֻ���
	virtual void setMobile(QString mobile);
	virtual void setToken(QString strToken);

	//!�򿪻�Ա����
	virtual void openVipInfoCenter(QString strUid, QString strToken, bool bJoinEnt, bool bHasMember);

	//!�򿪷�������Ѵ���
	virtual void openServiceFeeCenter(QString strUrl);

	//!�ر�������ҵ�Ի���
	virtual void closeAllEntWidget();

	//!ǩ���ɹ��޸��Ʊ�����
	virtual void modifyCoinCount(int nCount);
public:
signals :

	void sigSwitchAcc(int, bool, QString, QString);
public
slots:
	void onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd);

private:
	EntCenterWidget*		m_pEntCenterWidget = NULL;
	InfoCenterWidget*		m_pInfoCenterWidget = NULL;
	VipInfoWidget*			m_pVipInfoWidget = NULL;

	UserInfoStruct m_userInfo;
	QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;
	bool	m_isNetActive = true;
};
#endif // ZCLOUDENTCENTERIMPL_H
