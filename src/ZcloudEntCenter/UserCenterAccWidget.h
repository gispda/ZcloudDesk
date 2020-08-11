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
	UserCenterAccWidget(QWidget *parent = 0);
	~UserCenterAccWidget();

	//!�����û�����
	void setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId,QString strUserName);

	void init(EntCenterInfo*	info);

	//�����ֻ���
	void setMobile(QString mobile);
	void setToken(QString strToken);

	void modifyCoinCount(int nCount);
signals:
	

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


	QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;
	bool	m_isNetActive	= true;
	Ui::UserCenterAccWidget ui;
	QPoint dPos;
	bool	m_bJoinEnt = true;
	bool	m_bHasMember = true;
	//QWidget* m_pUserDefult = NULL;

};

#endif // UserCenterAccWidget_H
