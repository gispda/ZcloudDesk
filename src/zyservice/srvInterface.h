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

	//！获取 Windows 版本
	wstring GetOsVer();


	//!获取客户端当前版本号
	wstring GetCurVer();

	BOOL GetVersionEx2(LPOSVERSIONINFOW lpVersionInformation);

	//!获取mac地址
	wstring GetMacByCmd();

	//!获取网络代理信息
	void getNetProxy();

	CURL*		m_pCurl	=	NULL;

	bool		m_bHaveProxy	=	false;
	int			m_nType = 0;
	wstring		m_strPort;
	wstring     m_strHost;
	wstring		m_strUserInfo;
};

