#ifndef ZCLOUDENTCENTER_H
#define ZCLOUDENTCENTER_H
#include <QObject>
#include <QtCore/qglobal.h>
#ifdef ZCLOUDENTCENTER_LIB
# define ZCLOUDENTCENTER_EXPORT Q_DECL_EXPORT
#else
# define ZCLOUDENTCENTER_EXPORT Q_DECL_IMPORT
#endif

class ZCLOUDENTCENTER_EXPORT ZcloudEntCenter:public QObject
{
	Q_OBJECT
public:
	//����ʵ������
	static ZcloudEntCenter * createNew();

	//!���ٶ���
	virtual void destroy() = 0;
	//!�½���ҵ
	virtual void createEntCenter(QString strUid, QString strToken) = 0;

	//!�򿪹����б�
	virtual void openWorkers(QString strUid, QString strToken) = 0;
	//!����ҵ����
	virtual void openEntCenter(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId,QString strUserName) = 0;

	//! ��ҵ�����Ƿ���ʾ
	virtual bool isEntCenterShow()	=	0;

	//!�򿪻�Ա����
	virtual void openVipInfoCenter(QString strUid, QString strToken, bool bJoinEnt, bool bHasMember) = 0;

	//!�򿪷�������Ѵ���
	virtual void openServiceFeeCenter(QString strUrl) = 0;
	//!�ر�������ҵ�Ի���
	virtual void closeAllEntWidget() = 0;

	//!ǩ���ɹ��޸��Ʊ�����
	virtual void modifyCoinCount(int nCount)	=	0;

	//�����û���Ϣ
	virtual void setMobile(QString strMobile) = 0;
	virtual void setToken(QString strToken) = 0;

signals:
	void sigSwitchAcc(int, bool, QString, QString);
	void sendVipListSignals(QStringList, QStringList, QStringList);
	//�޸��û�����
	void trueNameJobChange(QString trueName ,QString strJob);
	void bingdingPhoneSignal();

	//���ֻ��ųɹ�
	void sigSignBindingSucceeded(const QString &strMobile);
	//!��ǩ������
	void openSignInWidget(QWidget*);
};

#endif // ZCLOUDENTCENTER_H
