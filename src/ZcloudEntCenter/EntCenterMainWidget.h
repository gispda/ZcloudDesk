#ifndef EntCenterMainWidget_H
#define EntCenterMainWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_EntCenterMainWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"

class EntCenterMainWidget : public AppCommWidget
{
	Q_OBJECT

public:
	EntCenterMainWidget(EntCenterInfo* pEntInfo, UserInfoStruct* m_userinfo, QWidget *parent = 0);
	~EntCenterMainWidget();

	
	//!��ʼ���û���Ϣ 
	void init(EntCenterInfo*	info, UserInfoStruct* userinfo);
	
signals:
	

	//���ֻ���
	void bingdingPhoneSignal();

	//!���ֻ��ųɹ�
	void sigSignBindingSucceeded( const QString &strMobile);


protected:
	bool eventFilter(QObject *target, QEvent *e);


private slots:


//!���������
void onServiceFeeBtnClick();
	
	


private:




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
	Ui::EntCenterMainWidget ui;
	
	//bool	m_bJoinEnt = true;
	//bool	m_bHasMember = true;
	//QWidget* m_pUserDefult = NULL;

	UserInfoStruct* m_userinfo;
	EntCenterInfo*	m_pInfo;

};

#endif // EntCenterMainWidget_H
