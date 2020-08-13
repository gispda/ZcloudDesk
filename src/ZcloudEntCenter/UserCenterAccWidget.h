#ifndef UserCenterAccWidget_H
#define UserCenterAccWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_UserCenterAccWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"

class UserCenterAccWidget : public AppCommWidget
{
	Q_OBJECT

public:
	UserCenterAccWidget(EntCenterInfo*	entinfo, UserInfoStruct* info, QWidget *parent = 0);
	~UserCenterAccWidget();
	void onSetPwdSucessed(int nCoin, bool bPerfect);
	void onBindMobileSucessed(int nCoin, bool bPerfect);
	void onModifyUserInfoSucessed(int nCoin, bool bPerfect);

	
	void init(EntCenterInfo*	entinfo, UserInfoStruct* info);

	void modifyCoinCount(int nCount);
signals:
	void sigChangeCoin(int);
	void sigEditUserInfoSucessed(const QString&, const QString&);
	void sigBindMobileSucessed(const QString&);

	//���ֻ���
	void bingdingPhoneSignal();

	//!���ֻ��ųɹ�
	void sigSignBindingSucceeded( const QString &strMobile);

	//!��ǩ������
	void openSignInWidget(QWidget*);

protected:
	bool eventFilter(QObject *target, QEvent *e);


private slots:


	//!��ҵ����
	void onEntInfoBtnClick();
	
	


private:
	//!�������ֳ�����...������ʾ
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);




	//!����û�ͷ���Ƿ���� ���ڷ���·�� ����������֮�󷵻�·��
	QString checkLogoExist(QString strUrl);


	//QString m_strUserName;
	//QString m_strUid;
	//QString m_strToken;
	//QString m_strTrueName;
	//QString m_strJob;
	//QString m_strMobile;
	//int		m_isLoginByTax;
	//QString m_strCompId;
	//bool	m_isNetActive	= true;
	//QPoint dPos;
	//bool	m_bJoinEnt = true;
	//bool	m_bHasMember = true;
	////QWidget* m_pUserDefult = NULL;

	Ui::UserCenterAccWidget ui;
	UserInfoStruct* m_userInfo;
};

#endif // UserCenterAccWidget_H
