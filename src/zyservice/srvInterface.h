#pragma once
#include <string>
#include "curl/curl.h"
using namespace std;

#ifndef NTDLL_RTL_GET_VERSION
#define NTDLL_RTL_GET_VERSION
#endif
class srvInterface
{
public:
	srvInterface();
	~srvInterface();

	bool WinHttpAppOperate(wstring strUid, wstring strToken, wstring strComId, wstring strHzsId, std::wstring strAppId, int nAppType);
	bool WinHttpMessageResponse(wstring strUid, wstring strToken, wstring strComId, wstring strHzsId,wstring strMsgId, int strResType, wstring strBtnId);

protected:
	bool	https_post(const wstring& strUrl, const wstring& strPost, string& szRet);
	wstring utf8_to_wstring(const string& str);
	string	wstring_to_utf8(const wstring& str);
	bool CheckRCode(const string & strRet);

	//����ȡ Windows �汾
	wstring GetOsVer();


	//!��ȡ�ͻ��˵�ǰ�汾��
	wstring GetCurVer();

	BOOL GetVersionEx2(LPOSVERSIONINFOW lpVersionInformation);

	//!��ȡmac��ַ
	wstring GetMacByCmd();

	//!��ȡ���������Ϣ
	void getNetProxy();

	CURL*		m_pCurl	=	NULL;

	bool		m_bHaveProxy	=	false;
	int			m_nType = 0;
	wstring		m_strPort;
	wstring     m_strHost;
	wstring		m_strUserInfo;
};

