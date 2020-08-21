#ifndef UserCenterWidget_H
#define UserCenterWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_UserCenterWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"
#include "UserCenterMainWidget.h"
#include "UserCenterAccWidget.h"
#include "Database.h"


class UserCenterWidget : public QWidget
{
	Q_OBJECT

public:
	UserCenterWidget(EntCenterInfo*	entinfo,UserInfoStruct* _userInfo, QWidget *parent = 0);
	~UserCenterWidget();
	void init(EntCenterInfo*	entinfo,UserInfoStruct* info);

	void modifyCoinCount(int nCount);
signals:
	void sigNeedLogin();
	

protected:
	bool eventFilter(QObject *target, QEvent *e);


private slots:
	void needLogin();
//!���������޸��Ʊ�
void onChangeCoin(int nCoin);

void onShowAcc();

void onShowMain();


//	//!����˰��
//	void onCopyBtnClick();
//	//!�˺��л�
//	void onSwitchBtnClick();
//	//!�����Ա
//	void onMemberBtnClick();
//	//!�˺�����
//	void onAccSetBtnClick();
//	//!ǩ��
//	void onSignInBtnClick();
//	//!��ҵ����
//	void onEntInfoBtnClick();
//	//!������Ϣ
//	void onTransInfoBtnClick();
//	//!��ҵ��Ա
//	void onEntVipBtnClick();
//	//!���������
//	void onServiceFeeBtnClick();
//	//!��������
//	void onCompeteDataBtnClick();
//	


//
//	//�޸����ϳɹ�
//	void onEditUserInfoSucessed(const QString& strName, const QString& strJob);
//
//	//!�����Ա�ɹ�
//	void changeVipSucessed(QStringList nameList, QStringList gradeList, QStringList vipTimerList);
//
private:
	//!��ѯ��ҵ��Ϣ
	bool winHttpGetCompanyInfo(QString strUid, QString strToken, QString& strRet);
	//!������ҵ��Ϣ
	//bool analysisJson(const QString& strJson, EntCenterInfo& info);
	//!����û�ͷ���Ƿ���� ���ڷ���·�� ����������֮�󷵻�·��
	QString checkLogoExist(QString strUrl);
//	//!�������ֳ�����...������ʾ
//	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);
//
//	//!��ѯ��ҵ��Ϣ
//	bool winHttpGetCompanyInfo(QString strUid,QString strToken,QString& strRet);
//
//
//	//!������ҵ��Ϣ
//	bool analysisJson(const QString& strJson, EntCenterInfo& info);
//
//	//!����û�ͷ���Ƿ���� ���ڷ���·�� ����������֮�󷵻�·��
//	QString checkLogoExist(QString strUrl);
//
//	//!������Ա
//	bool   analysisVip(QByteArray byteJsonArray);
//
//	//!��ʾͷ��VIP��ʶ
//	void showAvatar(QString strAvatarPath, bool bVip);
	/*QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;*/


	////�Ƿ�Ӻ�̨��������
	bool m_bIsloadDb;

	bool	m_isNetActive	= true;
	Ui::UserCenterWidget ui;

	//bool	m_bJoinEnt = true;
	//bool	m_bHasMember = true;
	QWidget* m_pUserDefult = NULL;
	//��ҳ
	UserCenterMainWidget* mp_UserCenterMain = NULL;
	//�˻���Ϣ
	UserCenterAccWidget* mp_UserCenterAcc = NULL;

	EntCenterInfo*	m_pEntinfo;
	UserInfoStruct* m_userInfo;
};

#endif // UserCenterWidget_H
