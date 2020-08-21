#ifndef UserCenterMainWidget_H
#define UserCenterMainWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_UserCenterMainWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"
#include "Database.h"

class UserCenterMainWidget : public QWidget
{
	Q_OBJECT

public:
	UserCenterMainWidget(EntCenterInfo*	entinfo, UserInfoStruct* m_userInfo, QWidget *parent = 0);
	~UserCenterMainWidget();

	void init(EntCenterInfo*	entinfo, UserInfoStruct*	info);
	//!�����û�����
	void modifyCoinCount(int nCount);
signals:

	void sigNeedLogin();
	//!��ǩ������
	void openSignInWidget(QWidget*);
	//!���ֻ��ųɹ�
	void sigSignBindingSucceeded(const QString &strMobile);
protected:
	bool eventFilter(QObject *target, QEvent *e);


private slots:

	//!ǩ��
	void onSignInBtnClick();	
	//!���������޸��Ʊ�
	void onChangeCoin(int nCoin);

	////�޸����ϳɹ�
	//void onEditUserInfoSucessed(const QString& strName, const QString& strJob);

	//!��������
	void onCompeteDataBtnClick();

private:
	//!�������ֳ�����...������ʾ
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);


	//!��ʼ���û���Ϣ 
	void init();


	//!����û�ͷ���Ƿ���� ���ڷ���·�� ����������֮�󷵻�·��
	QString checkLogoExist(QString strUrl);

	UserInfoStruct* m_userInfo;

	/*QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;
	bool	m_isNetActive	= true;*/
	Ui::UserCenterMainWidget ui;
	QPoint dPos;
	//bool	m_bJoinEnt = true;
	//bool	m_bHasMember = true;
	QWidget* m_pUserDefult = NULL;

};

#endif // UserCenterMainWidget_H
