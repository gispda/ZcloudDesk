#ifndef ZCLOUDCOMMON_H
#define ZCLOUDCOMMON_H

#include <QString>
#include <QWidget>
#include <QLabel>
namespace ZcloudComFun
{
	enum EN_BTN_TYPE
	{
		EN_CLOSE = 0,		//!ֻһ���رհ�ť
		EN_OKCANCEL = 1,	//!ȷ��ȡ����ť
		ZEN_UPDATE = 2,		//!��������������ť
		EN_BINDING = 3,		//��˰��
		EN_TIP = 4,			//ʧ�ܵ���ʾ
	};



	extern "C" __declspec(dllexport) void LoadAvatar(const std::string &strAvatarUrl, QLabel* lable);

	//!��ʾ��
	extern "C" __declspec(dllexport) int openMessageTipDlg(EN_BTN_TYPE enBtnType, QString strTitle, QString strMsg, QWidget *parent = 0);

	//!��ʾ��
	extern "C" __declspec(dllexport) int openMessageTipDlg_2(EN_BTN_TYPE enBtnType, QString strTitle, QString strMsg, QString buttonStr_1, QString tuttonStr_2, QWidget *parent = 0);

	//!http����
	extern "C" __declspec(dllexport) bool httpPost(QString strUrl, QString strPost, int nTimeout, QString& strRet, bool isCheckToken = false,int _type = 0);
	//�ж�token
	extern "C" __declspec(dllexport) bool winHttpSSO(QString strToken, QString strUserId);

	//!��url����ͼƬ
	 __declspec(dllexport) QString downloadIconFromUrl(QString strUrl, QString strDirPath, QString strAppId = "");

	//!����3��ͼƬ
	 __declspec(dllexport) QString downloadPic(QString strUrl, QString strDirPath);

	 //!�������
	 extern "C" __declspec(dllexport) bool isNetActive();
	 
	 //��ȡ��Ʊ����Ƿ����  
	 extern "C" __declspec(dllexport)  bool readsoft(QString &verSion, QString taxNumber = "");
	 extern "C" __declspec(dllexport)  bool qtReadsoft(QString &verSion, QString taxNumber = "");

	 //��ȡ��Ʊ�����Ϣ
	 extern "C" __declspec(dllexport) bool getSoftwareData(QString &url, QString &verson_hszId, QString tax_number = "");

	 //��ȡ����Ip
	 __declspec(dllexport) QString GetNetIP(QString &province, QString &city);

	 //!��ȡ�Ʋ�˰�汾��
	 __declspec(dllexport) QString getFileVertion(QString fullName);

	//isOnAesUncrypt = false ����   ��֮����
	 extern "C" __declspec(dllexport) bool aesZhicloud(QByteArray &ytestr, QString strKey, bool isOnAesUncrypt);

	 //!��ȡ����mac��ַ
	 __declspec(dllexport) QString getHostMacAddress();

	 //!��ȡ��������ϵͳ�汾
	 __declspec(dllexport) QString getOsVer();
	 __declspec(dllexport) QString getOsVerQt();

	 //!��ȡapi�ӿ�������
	 __declspec(dllexport) QString getHostName();

	 //!��ȡwvҳ��Url(����eg:uid,token,��wv/wallpaper/index")
	 __declspec(dllexport) QString getWvUrl(QString strUid, QString strtoken, QString strFun);

	 //!��ȡ������������
	 __declspec(dllexport) QString getTopToolUrl(QString strUid, QString strtoken, QString strFun);

	 //!���������ͻ��˻��� 
	 enum EN_REBOOT_TYPE
	 {
		 EN_NOREBOOT		= 0,	//!����������½�رա����¹رգ�
		 EN_REBOOT_PARAMS	= 1,	//!����������ֻ����������ģʽ��
	 };
	 extern "C" __declspec(dllexport) void writeRegReboot(EN_REBOOT_TYPE enType);

	 //��Ʊ����Ѵ��ڶ�ȡ��Ʊ���
	 bool readSoftV(QString &verSion, QString tax_number);

	 //��ȡ˰��
	 __declspec(dllexport) QString getTaxnumber();

	 bool getPublicIp(QString& ip);

	 __declspec(dllexport) void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);
};
#endif // ZCLOUDCOMMON_H


