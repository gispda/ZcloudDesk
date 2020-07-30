#ifndef ENTCENTERWIDGET_H
#define ENTCENTERWIDGET_H

#include <QWidget>
#include "qevent.h"
#include "ui_EntCenterWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"

class EntCenterWidget : public AppCommWidget
{
	Q_OBJECT

public:
	EntCenterWidget(QWidget *parent = 0);
	~EntCenterWidget();

	//!�����û�����
	void setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId,QString strUserName);

	//!��ʾ����
	void showWindow();

	//�����ֻ���
	void setMobile(QString mobile);
	void setToken(QString strToken);

	void modifyCoinCount(int nCount);
signals:
	//!�л��˺�
	void sigSwitchAcc(int, bool, QString, QString);

	//�����Ա�ɹ�
	void sendVipListSignals(QStringList, QStringList, QStringList);

	//�޸��û�����ְ��
	void trueNameJobChange(QString, QString);

	//���ֻ���
	void bingdingPhoneSignal();

	//!���ֻ��ųɹ�
	void sigSignBindingSucceeded( const QString &strMobile);

	//!��ǩ������
	void openSignInWidget(QWidget*);

protected:
	bool eventFilter(QObject *target, QEvent *e);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:
	//!����˰��
	void onCopyBtnClick();
	//!�˺��л�
	void onSwitchBtnClick();
	//!�����Ա
	void onMemberBtnClick();
	//!�˺�����
	void onAccSetBtnClick();
	//!ǩ��
	void onSignInBtnClick();
	//!��ҵ����
	void onEntInfoBtnClick();
	//!������Ϣ
	void onTransInfoBtnClick();
	//!��ҵ��Ա
	void onEntVipBtnClick();
	//!���������
	void onServiceFeeBtnClick();
	//!��������
	void onCompeteDataBtnClick();
	
	//!���������޸��Ʊ�
	void onChangeCoin(int nCoin);

	//�޸����ϳɹ�
	void onEditUserInfoSucessed(const QString& strName, const QString& strJob);

	//!�����Ա�ɹ�
	void changeVipSucessed(QStringList nameList, QStringList gradeList, QStringList vipTimerList);

private:
	//!�������ֳ�����...������ʾ
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);

	//!��ѯ��ҵ��Ϣ
	bool winHttpGetCompanyInfo(QString strUid,QString strToken,QString& strRet);

	//!��ʼ���û���Ϣ 
	void init();

	//!������ҵ��Ϣ
	bool analysisJson(const QString& strJson, EntCenterInfo& info);

	//!����û�ͷ���Ƿ���� ���ڷ���·�� ����������֮�󷵻�·��
	QString checkLogoExist(QString strUrl);

	//!������Ա
	bool   analysisVip(QByteArray byteJsonArray);

	//!��ʾͷ��VIP��ʶ
	void showAvatar(QString strAvatarPath, bool bVip);

	QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;
	bool	m_isNetActive	= true;
	Ui::EntCenterWidget ui;
	QPoint dPos;
	bool	m_bJoinEnt = true;
	bool	m_bHasMember = true;
	QWidget* m_pUserDefult = NULL;
};

#endif // ENTCENTERWIDGET_H
