#pragma once

#include <QObject>

class AppHttpInterface : public QObject
{
	Q_OBJECT

public:
	AppHttpInterface(QObject *parent = NULL);
	~AppHttpInterface();

	/************************************************************************/
	/*�������ƣ�	WinHttpGetAppStoreRotationPic
	/*�������ܣ�	��ȡӦ�������ֲ�ͼ
	/*����������
	/*�������أ�	true������Ӧ�ɹ�������ʧ��
	/************************************************************************/
	bool WinHttpGetAppStoreRotationPic(QString strUid, QString strToken, QString& strRet);
	

	/************************************************************************/
	/*�������ƣ�	WinHttpGetAllClassInfo
	/*�������ܣ�	��ȡ���еķ���
	/*����������	strUid		uid					in
	strToken	token				in
	strRet		�ӿڷ���Json�ַ���		out
	/*�������أ�	true������Ӧ�ɹ�������ʧ��
	/************************************************************************/
	bool WinHttpGetAllClassInfo(QString strUid, QString strToken, QString& strRet);

	/************************************************************************/
	/*�������ƣ�	WinHttpGetAppStatus
	/*�������ܣ�	��ȡ���Ϸ����Ӧ�õ�״̬
	/*����������	strUid		uid					in
	strToken	token				in
	strRet		�ӿڷ���Json�ַ���		out
	/*�������أ�	true������Ӧ�ɹ�������ʧ��
	/************************************************************************/
	bool WinHttpGetAppStatus(QString strUid, QString strToken, int last_update_time, QString& strRet);
	
	
	/************************************************************************/
	/*�������ƣ�	WinHttpGetSystemIPForApp
	/*�������ܣ�	��ȡ��Ʊ��� ���°汾
	/*����������
	/*�������أ�	true������Ӧ�ɹ�������ʧ��
	/************************************************************************/
	bool WinHttpGetSystemIPForApp(QString strHzsId, QString& strRet);


	
	/************************************************************************/
	/*�������ƣ�	WinHttpGetVipInfoByTaxCode
	/*�������ܣ�	����˰�Ż�ȡVIP��Ϣ
	/*����������
	/*�������أ�	true������Ӧ�ɹ�������ʧ��
	/************************************************************************/
	bool WinHttpGetVipInfoByTaxCode(QString strTaxNo, QString& strRet);


	
	/************************************************************************/
	/*�������ƣ�	WinHttpGetSystemTime
	/*�������ܣ�	��ȡ������ʱ��
	/*����������
	/*�������أ�	true������Ӧ�ɹ�������ʧ��
	/************************************************************************/
	bool WinHttpGetSystemTime(QString& strRet);

	

	/************************************************************************/
	/*�������ƣ�	WinHttpGetAppInfoList
	/*�������ܣ�	��ȡӦ������
	/*����������	strUid		uid			Ӧ��idlist�ö��Ÿ���		in
	strToken	token				
	strRet		�ӿڷ���Json�ַ���		out
	/*�������أ�	true������Ӧ�ɹ�������ʧ��
	/************************************************************************/
	bool WinHttpGetAppInfoList(QString strUid, QString strToken, QString applistId, QString& strRet);



	/************************************************************************/
	/*�������ƣ�	WinHttpGetApplistByCateId
	/*�������ܣ�	���ݷ���id��ѯȫ������Ӧ�ã���װ δ��װ��
	/*����������	strUid		uid						in
	strToken	token					in
	strHzsId	������ID					in
	strCateId	����Id					in
	nPage		ҳ��						in
	strRet		�ӿڷ���Json�ַ���			out
	/*�������أ�	true������Ӧ�ɹ�������ʧ��
	/************************************************************************/
	bool WinHttpGetApplistByCateId(QString strUid, QString strToken, QString strHzsId, QString strCateId, int nPage, QString& strRet);

	

private:
	//QString				m_strOtherInfo;

	//!httpPost����     url             post����    ��ʱ���    ��������
	//bool  httpPost(QString url, QString post, int iTime, QString& strRet);
};
