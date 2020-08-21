#ifndef SwitchAccNewWidget_H
#define SwitchAccNewWidget_H

#include <QWidget>
#include "ui_SwitchAccNewWidget.h"
#include "qevent.h"
#include "Database.h"
#include "ZcloudCommon.h"
#include "EntDataBase.h"

class SwitchAccNewWidget : public QWidget
{
	Q_OBJECT

public:
	SwitchAccNewWidget(UserInfoStruct* m_userInfo, EntCenterInfo* m_pEntInfo, QWidget *parent = 0);
	~SwitchAccNewWidget();

	//!�ͻ���������
	void CustomerManagerinvite();
	//!��ҵ����Ա����
	void EnterpriseManagerinvite();

signals:
	void sigSwitchAcc(int, bool, QString, QString);
	void sigJoinEnt(QString m_strTaxNum);
private slots:
void onTextChanged(const QString& strText);
void onSwitchAcc(int nLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd);
void onJoinEnt(QString m_strTaxNum);
protected:
	bool eventFilter(QObject *target, QEvent *e);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	//!��ȡ��ǰ�û�����������ҵ
	bool winHttpGetCompanyList(QString strTaxno, QString strToken, QString& strRet);

	//!��ȡ��ǰ�û�����������ҵ
	void getCompanyList();

	//!��ʾ�б�
	void showListWidget(QString strText);

	//!��ȡ�л��˺��б�
	void getSwitchInfo();

	//!ע���˰���������ݿ���д���(��ʾ������¼���������ݿ���������Ϣ)
	bool isTaxExistRegedit(QString strTaxNo);

	//!�ӿڻ�ȡ�������������ݿ���д���(��ʾ������¼���������ݿ���������Ϣ)
	bool isTaxExistInterface(QString strUid, QString strCompId);

	void openCreateEntDlg();

	////!��ǰ��¼�˺�uid
	//QString m_strUid;
	//QString	m_strToken;
	////!��ǰ��¼��˾id
	//QString	m_strCompId;
	//QString	m_strUserName;
	//QString	m_strMobile;


	Ui::SwitchAccNewWidget ui;
	QPoint dPos;

	UserInfoStruct* m_userInfo;
	EntCenterInfo* m_pEntInfo;
	vtrSwitchAccInfos m_vtrAccInfos;

};

#endif // SwitchAccNewWidget_H
