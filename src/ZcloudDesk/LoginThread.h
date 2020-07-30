#pragma once

#include <QThread>
#include "ZcloudCommon.h"
#include "Database.h"

class LoginThread : public QThread
{
	Q_OBJECT
public:

	enum WayEnum{
		LoginPwWay,		//�˺������¼
		LoginPaWay,		//�ֻ���֤���¼
		AuthWay,		//��ȡ��֤��
		VerifyPaWay,	//�����֤��
		ResetPwWay,		//��������ȷ��
		VerifyWay,		//ע��
		BindingPhoneWay,//΢�Ű��ֻ���
		BindingEin		//˰�Ű��ֻ���
	};

	LoginThread(QObject *parent = NULL);
	~LoginThread();
	void setValue(WayEnum wayEnum, QString id, QString pw, QString codeType = "");
	WayEnum getWayEnum(){ return m_wayEnum; }
	//��¼ 
	static int httpLogin(int bytaxFlag, QString strTaxNo_ID, QString strMachine_PW, UserInfoStruct &userInfoStruct, QString strSkid = "");
	//!����û�ͷ���Ƿ���� ���ڷ���·�� ����������֮�󷵻�·��
	static QString checkLogoExist(QString strUrl);
private:
	//��ȡ��֤��
	int getCode(QString phoneNumber, QString codeType);
	//�����֤��
	int checkCode(QString phoneNumber, QString codeType, QString codeNumber);

	//�û�ע��
	int userRegister(QString phoneNumber, QString passWord, QString codeNumber);

	//�޸�����
	int changedPassword(QString phoneNber, QString passWord, QString codeNumber);

	//�ֻ��ź�˰�Ű�   bingdingWay = true:΢�Ű�   false:�ֻ���
	int bindingTaxNumber(QString strMobile, QString strCaptcha, UserInfoStruct &);
	int bindingTaxNumber(QString strMobile, QString strCaptcha, QString strSkid, UserInfoStruct &);
	
	//˰�� token userid дע���
	static void writeRegdit(UserInfoStruct);
	//������¼����
	static int analySucessJson(QString strRet, UserInfoStruct &userInfoStruct);
	//��֤���سɹ����
	int analyCodeSucess(QString strRet);
	//����json �Ƿ�Ϊδע���û����û��ֻ��ſ�ݵ�¼��
	static bool analySucessJsonSign(QString strRet,QString &strSign);

	WayEnum m_wayEnum = LoginPwWay;
	QString m_Id;
	QString m_PW;
	QString m_codeType = "";
	//�����ֻ���ݵ�¼ʱ δע��ʱ ����sign��sign �û���������ʱ�� ע��ӿڣ�
	QString m_strSign = "";

	UserInfoStruct m_userInfoStruct;
signals:
	void loginSignals(int status, UserInfoStruct);
	void getFilishSignals(int status);
protected:
	void run();
};
