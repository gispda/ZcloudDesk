#pragma once
#ifdef ZCLOUDCOMMON_LIB
# define JSINTERFACE_EXPORT Q_DECL_EXPORT
#else
# define JSINTERFACE_EXPORT Q_DECL_IMPORT
#endif

#include <QObject>

class JSINTERFACE_EXPORT JsInterface : public QObject
{
	Q_OBJECT

public:
	static JsInterface *GetInstance();
	static void DestoryInstance();
	void changeUserIdtoken(const QString strUserId, const QString strToken);
public slots:
	//!�˺����óɹ���ˢ�����ơ�ְ��������(ƽ̨���ṩ�� ���ʱ�����¼ ��һ����token��¼)
	void accountSetSucessed(const QString& strName, const QString& strJob);

	//!��Ա�����Ȩ���б�
	void getVipList(const QString& strJson);

	//���ֻ���
	void slotBindingPhone();

	//!ǩ���ɹ�
	void signInSucessed(bool bSucessed,int );

	//!��ȡ��ֽ��������
	void wallpaperDownload(const QString& strDownloadLink);

	//�޸���ҵ���� �����
	void enterpriseDataSucessed(bool,int);

	//!��֧��Э��
	void slotOpenDefaultWeb(const QString&);

	//!���ֻ��ųɹ�
	void slotBindingSucceeded( const QString &strMobile);

	//!�ύ���ɹ�
	void commitStatue(bool);

	
signals:
	//�޸ĸ�����
	void sigAccountSetSucessed(const QString& strName, const QString& strJob);
	//�����Ա
	void sigGetVipList(const QString& strJson);
	//���ֻ���
	void signalBindingPhone();
	//ǩ��
	void sigSignInSucessed(bool bSucessed,int);
	//�޸ı�ֽ
	void sigWallpaperDownloadLink(const QString& strDwownloadLink);
	//�޸������������
	void sigSignCompeteSucessed(bool,int);

	//!���ֻ��ųɹ�
	void sigSignBindingSucceeded( const QString &strMobile);

	//!�ύ���ɹ�
	void sigCommitStatue(bool);

	//token�� ����userId���
	void changeUserIdtokenSignal(const QString, const QString);
private:
	JsInterface(QObject *parent = 0);
	static JsInterface *m_Instance;
};
