#ifndef HTTPINTERFACE_H
#define HTTPINTERFACE_H

#include <QObject>

class HttpInterface : public QObject
{
	Q_OBJECT

public:
	HttpInterface(QObject *parent=0);
	~HttpInterface();

	//!˰�ŵ�¼
	bool winHttpLogin(QString strTaxNo,QString strUserId, QString& strRet);

	//�ֻ��ż�Token��¼
	bool winHttpTokneLogin(QString strModel, QString strToken, QString& strRet);

	//!�˺������¼(true) �ֻ���¼false
	bool winHttpLogin(bool accountPhone, QString strAccount,QString strPwd, QString& strRet);

	//!��ȡ��������
	bool winHttpGetTopToolInfo(QString strUid,QString strToken,QString& strRet);

	//!�������(uid token ������������� ���� ��ϵ��ʽ ���ؽ��)
	bool winHttpSendFeedback(QString strUid, QString strToken, QString strType, QString strContent, QString strContactway, QString& strRet);

	//!��˰���ϱ�
	bool winHttpTaxResponse(QString strUid, QString strToken, QString strTaxs, QString& strRet);

	//!�Ʋ�˰�汾����
	bool winHttpGetYcsSoftware(QString strUid, QString strToken, QString& strRet);

	//������֤��
	bool winHttpSendCode(QString phoneNumber,QString codeType, QString & strRet);
	
	//�����֤��
	bool winHttpCheckCode(QString phoneNumber, QString codeType,  QString code, QString &strRet);

	//�û�ע��
	bool winHttpRegister(QString phoneNumber, QString password, QString captcha,QString strSign, QString &strRet);
	
	//���ֻ�
	bool  winHttpBindingPhone(QString phoneNumber, QString captcha, QString skid, QString strToken, QString strUserId, QString &strRet);
	bool  winHttpBindingPhone(QString phoneNumber, QString captcha, QString skid, QString &strRet);

	//token��¼
	bool  winHttpTokenLogin(QString phoneNumber, QString strToken,QString &strRet);

	//�޸�����
	bool winHttpChangePassword(QString  phoneNumber, QString password, QString codeNumber, QString &strRet);

	//��ȡ΢�Ŷ�ά��
	bool winHttpGetQRCode(QString strToken,QString strUserId, QString &strRet);
	
	//����ά��ɨ��״̬
	bool winHttpCheckScanStatus(QString strPkid, QString strToken,QString strUserId, QString &strRet);
	
	//΢�Ű��û�
	bool winHttpAjaxBind(QString strPkid, QString strToken, QString &strRet);

	//˰�Ű��ֻ���
	bool winHttpTaxPhoneBind(QString strMobile, QString captcha, QString strToken, QString strUserId, QString &strRet);

	//!��ȡ������ϵͳʱ��
	bool winHttpGetSystemTime(QString &strRet);

private:
	
};

#endif // HTTPINTERFACE_H
