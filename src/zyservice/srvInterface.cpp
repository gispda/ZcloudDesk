#include "srvInterface.h"
#include <codecvt>
#include <locale.h>
#include <iphlpapi.h>
#include "msgLog.h"
#include "CJson.h"
#pragma comment(lib,   "Version.lib") 
#pragma comment(lib,   "Iphlpapi.lib")

extern wstring g_strServerAddr;
static size_t write_string_data(void *input, size_t uSize, size_t uCount, void *avg)
{
	size_t uLen = uSize*uCount;
	string *pStr = (string *)(avg);
	pStr->append((char *)(input), uLen);

	// 只有返回uSize*uCount才会返回成功
	return uLen;
}

srvInterface::srvInterface()
{
	curl_global_init(CURL_GLOBAL_ALL);
	getNetProxy();
}


srvInterface::~srvInterface()
{
	if (m_pCurl != NULL)
	{
		curl_easy_cleanup(m_pCurl);
		m_pCurl = NULL;
	}
	curl_global_cleanup();
}

bool srvInterface::https_post(const wstring& strUrl, const wstring& strPost, string& szRet)
{
	msgLog::WriteMsgToLog(strUrl.c_str());
	msgLog::WriteMsgToLog(strPost.c_str());
	string strTemp = "";
	CURLcode ret;
	curl_global_init(CURL_GLOBAL_ALL);
	if (m_pCurl == NULL)
		m_pCurl = curl_easy_init();

	curl_slist *http_headers = NULL;
	http_headers = curl_slist_append(http_headers, "Content-Type:application/x-www-form-urlencoded; charset=UTF-8"); 
	if (m_pCurl)
	{
		curl_easy_setopt(m_pCurl, CURLOPT_HTTPHEADER, http_headers);
		curl_easy_setopt(m_pCurl, CURLOPT_URL, wstring_to_utf8(strUrl).c_str());
		curl_easy_setopt(m_pCurl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(m_pCurl, CURLOPT_SSL_VERIFYHOST, 0L);
		//打开调试信息
		//curl_easy_setopt(m_pCurl, CURLOPT_VERBOSE, 1L);//调试信息打开	
		//设置要post的数据 
		string strPostData = wstring_to_utf8(strPost);
		if (!strPostData.empty())
		{
			curl_easy_setopt(m_pCurl, CURLOPT_POST, true);
			curl_easy_setopt(m_pCurl, CURLOPT_POSTFIELDS, strPostData.c_str());
		}
		if (m_bHaveProxy)	
		{
			if(m_nType == 1)
			{
				curl_easy_setopt(m_pCurl, CURLOPT_PROXYTYPE, CURLPROXY_SOCKS5);
			}
			else if (m_nType == 3)
			{
				curl_easy_setopt(m_pCurl, CURLOPT_PROXYTYPE, CURLPROXY_HTTP);
			}
			//!设置代理host
			string strHostData = wstring_to_utf8(m_strHost);
			if (!strHostData.empty())
			{
				curl_easy_setopt(m_pCurl, CURLOPT_PROXY, strHostData.c_str());
			}

			//!设置代理port
			string strPortData = wstring_to_utf8(m_strPort);
			if (!strPortData.empty())
			{
				curl_easy_setopt(m_pCurl, CURLOPT_PROXYPORT, strPortData.c_str());
			}
			//!设置代理身份验证
			string strUserData = wstring_to_utf8(m_strUserInfo);
			if (!strUserData.empty())
			{
				curl_easy_setopt(m_pCurl, CURLOPT_PROXYUSERPWD, strUserData.c_str());
			}
			curl_easy_setopt(m_pCurl, CURLOPT_HTTPPROXYTUNNEL, 1L);
		}
		
		//设置连接超时	
		curl_easy_setopt(m_pCurl, CURLOPT_CONNECTTIMEOUT, 5000);
		//设置数据接收回调函数 
		curl_easy_setopt(m_pCurl, CURLOPT_WRITEFUNCTION, write_string_data);
		curl_easy_setopt(m_pCurl, CURLOPT_WRITEDATA, &strTemp);

		try
		{
			ret = curl_easy_perform(m_pCurl);
			if (ret == CURLE_OK)
			{
				msgLog::WriteMsgToLog(L"ok");
				curl_easy_cleanup(m_pCurl);
				m_pCurl = NULL;
				szRet = strTemp;
				return true;
			}
			else
			{
				curl_easy_cleanup(m_pCurl);
				m_pCurl = NULL;
				szRet = "";
			}
		}
		catch (...)
		{
			curl_easy_cleanup(m_pCurl);
			m_pCurl = NULL;
			szRet = strTemp;
		}
	}
	return false;
}

wstring srvInterface::utf8_to_wstring(const string& str)
{
	wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.from_bytes(str);	
}

string srvInterface::wstring_to_utf8(const wstring& str)
{
	wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.to_bytes(str);
}
bool srvInterface::WinHttpAppOperate(wstring strUid, wstring strToken, wstring strComId, wstring strHzsId, std::wstring strAppId, int nAppType)
{
	wstring strUrl	=	g_strServerAddr + L"/app/app-operate?";
	strUrl = strUrl + L"mac=" + GetMacByCmd() + L"&version=" + GetCurVer() + L"&system=" + GetOsVer();
	wstring strPost = L"user_id=" + strUid + L"&company_id=" + strComId + L"&hzs_id=" + strHzsId + L"&app_id=" + strAppId + L"&type=" + to_wstring(nAppType);

	string	strRet;
	bool bSucessed	=	 https_post(strUrl, strPost, strRet);
	if (bSucessed)
	{
		return CheckRCode(strRet);
	}
	return bSucessed;
}

wstring srvInterface::GetOsVer()
{
	//!目前只做了windows版本
	OSVERSIONINFOEXW ovi = { sizeof ovi };

#ifdef NTDLL_RTL_GET_VERSION
	GetVersionEx2((LPOSVERSIONINFOW)&ovi);
	//printf("使用NTDLL->RtlGetVersion获取的信息：\n");
#else
	GetVersionExW((LPOSVERSIONINFOW)&ovi);
	//printf("使用KERNEL32->GetVersionExW获取的信息：\n");
#endif

	wstring osname;

	//        printf("dwMajorVersion: %08x %d\n", ovi.dwMajorVersion, ovi.dwMajorVersion);
	//        printf("dwMinorVersion: %08x %d\n", ovi.dwMinorVersion, ovi.dwMinorVersion);
	//        printf("dwBuildNumber: %08x %d\n", ovi.dwBuildNumber, ovi.dwBuildNumber);
	//        printf("dwPlatformID: %08x %d\n", ovi.dwPlatformId, ovi.dwPlatformId);
	//        printf("szCSDVersion: %s\n", (char*)QString::fromWCharArray(ovi.szCSDVersion).toStdString().c_str());
	//        printf("wServicePackMajor: %04x %d\n", ovi.wServicePackMajor, ovi.wServicePackMajor);
	//        printf("wServicePackMinor: %04x %d\n", ovi.wServicePackMinor, ovi.wServicePackMinor);
	//        printf("wSuitMask: %04x %d\n", ovi.wSuiteMask, ovi.wSuiteMask);
	//        printf("wProductType: %02x %d\n", ovi.wProductType, ovi.wProductType);
	//        printf("wReserved: %02x %d\n", ovi.wReserved, ovi.wReserved);

	switch (ovi.dwMajorVersion)//判断主版本号
	{
	case 4:
		switch (ovi.dwMinorVersion)//判断次版本号
		{
		case 0:
			if (ovi.dwPlatformId == VER_PLATFORM_WIN32_NT)
				osname = L"Microsoft Windows NT 4.0"; //1996年7月发布
			else if (ovi.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
				osname = L"Microsoft Windows 95";
			break;
		case 10:
			osname = L"Microsoft Windows 98";
			break;
		case 90:
			osname = L"Microsoft Windows Me";
			break;
		}
		break;
	case 5:
		switch (ovi.dwMinorVersion)	//再比较dwMinorVersion的值
		{
		case 0:
			osname = L"Microsoft Windows 2000";//1999年12月发布
			break;
		case 1:
			osname = L"Microsoft Windows XP";//2001年8月发布
			break;
		case 2:
			if (ovi.wProductType == VER_NT_WORKSTATION)
			{
				osname = L"Microsoft Windows XP Professional x64 Edition";
			}
			else if (GetSystemMetrics(SM_SERVERR2) == 0)
				osname = L"Microsoft Windows Server 2003";//2003年3月发布
			else if (GetSystemMetrics(SM_SERVERR2) != 0)
				osname = L"Microsoft Windows Server 2003 R2";
			break;
		}
		break;
	case 6:
		switch (ovi.dwMinorVersion)
		{
		case 0:
			if (ovi.wProductType == VER_NT_WORKSTATION)
				osname = L"Microsoft Windows Vista";
			else
				osname = L"Microsoft Windows Server 2008";//服务器版本
			break;
		case 1:
			if (ovi.wProductType == VER_NT_WORKSTATION)
				osname = L"Microsoft Windows 7";
			else
				osname = L"Microsoft Windows Server 2008 R2";
			break;
		}
		break;
	case 10:
		osname = L"Microsoft Windows 10";
		break;
	}
	osname += L" ";
	return osname;
}

BOOL srvInterface::GetVersionEx2(LPOSVERSIONINFOW lpVersionInformation)
{
	HMODULE hNtDll = GetModuleHandleW(L"NTDLL"); // 获取ntdll.dll的句柄
	typedef NTSTATUS(NTAPI*tRtlGetVersion)(PRTL_OSVERSIONINFOW povi); // RtlGetVersion的原型
	tRtlGetVersion pRtlGetVersion = NULL;
	if (hNtDll)
	{
		pRtlGetVersion = (tRtlGetVersion)GetProcAddress(hNtDll, "RtlGetVersion"); // 获取RtlGetVersion地址
	}
	if (pRtlGetVersion)
	{
		return pRtlGetVersion((PRTL_OSVERSIONINFOW)lpVersionInformation) >= 0; // 调用RtlGetVersion
	}
	return FALSE;
}

std::wstring srvInterface::GetCurVer()
{
	wstring   strVersion;
	wstring		szFileName  = msgLog::getCurPath() + L"ZcloudDesk.exe";
	// 读文件信息  
	DWORD   dwVerHnd = 0;
	DWORD   dwVerInfoSize = ::GetFileVersionInfoSize(szFileName.c_str(), &dwVerHnd);
	if (dwVerInfoSize)
	{

		HANDLE     hMem;
		LPVOID     lpvMem;
		unsigned   int   uInfoSize = 0;
		VS_FIXEDFILEINFO   *   pFileInfo;

		hMem = ::GlobalAlloc(GMEM_MOVEABLE, dwVerInfoSize);
		lpvMem = ::GlobalLock(hMem);
		::GetFileVersionInfo(szFileName.c_str(), dwVerHnd, dwVerInfoSize, lpvMem);
		::VerQueryValue(lpvMem, (LPTSTR)("\\"), (void**)&pFileInfo, &uInfoSize);

		WORD   nVer[4];
		nVer[0] = HIWORD(pFileInfo->dwProductVersionMS);
		nVer[1] = LOWORD(pFileInfo->dwProductVersionMS);
		nVer[2] = HIWORD(pFileInfo->dwProductVersionLS);
		nVer[3] = LOWORD(pFileInfo->dwProductVersionLS);
		wchar_t szVer[32] = { 0 };
		wsprintf(szVer, L"%d.%d.%d", nVer[0], nVer[1], nVer[2]);
		strVersion = szVer;

		::GlobalUnlock(hMem);
		::GlobalFree(hMem);
	}
	return   strVersion;
}

wstring srvInterface::GetMacByCmd()
{
	wstring strReturn;
	ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
	PIP_ADAPTER_INFO pAdapterInfo = (IP_ADAPTER_INFO*)malloc(sizeof(IP_ADAPTER_INFO));
	if (pAdapterInfo == NULL)
		return false;
	// Make an initial call to GetAdaptersInfo to get the necessary size into the ulOutBufLen variable
	if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW)
	{
		free(pAdapterInfo);
		pAdapterInfo = (IP_ADAPTER_INFO *)malloc(ulOutBufLen);
		if (pAdapterInfo == NULL)
			return false;
	}

	if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == NO_ERROR)
	{
		for (PIP_ADAPTER_INFO pAdapter = pAdapterInfo; pAdapter != NULL; pAdapter = pAdapter->Next)
		{

			if (pAdapter->Type != MIB_IF_TYPE_ETHERNET)
				continue;

			if (pAdapter->AddressLength != 6)
				continue;
			wchar_t acMAC[32] = {0};
			wsprintf(acMAC,  L"%02X:%02X:%02X:%02X:%02X:%02X",
				int(pAdapter->Address[0]),
				int(pAdapter->Address[1]),
				int(pAdapter->Address[2]),
				int(pAdapter->Address[3]),
				int(pAdapter->Address[4]),
				int(pAdapter->Address[5]));
			strReturn = acMAC;
			break;
		}
	}

	free(pAdapterInfo);
	return strReturn;
}
bool srvInterface::WinHttpMessageResponse(wstring strUid, wstring strToken, wstring strComId, wstring strHzsId,wstring strMsgId, int strResType, wstring strBtnId)
{
	wstring strUrl = g_strServerAddr + L"/push/message-response?";
	strUrl = strUrl + L"mac=" + GetMacByCmd() + L"&version=" + GetCurVer() + L"&system=" + GetOsVer();

	wstring strPost = L"user_id=" + strUid + L"&company_id=" + strComId + L"&hzs_id=" + strHzsId + L"&message_id=" + strMsgId + L"&response_type=" + to_wstring(strResType) + L"&btn_id=" + strBtnId;

	string	strRet;
	bool bSucessed = https_post(strUrl, strPost, strRet);
	if (bSucessed)
	{
		return CheckRCode(strRet);
	}
	return bSucessed;
}
bool srvInterface::CheckRCode(const string & strRet)
{
	CJson cj;
	int iRc = cj.parse(strRet);
	if (iRc != 0)
	{
		return false;
	}

	std::string sCode;
	std::string sMsg;

	iRc = cj.getVal(".status", sCode);
	if (iRc != 0)
	{
		return false;
	}
	return true;
}

void srvInterface::getNetProxy()
{
	wstring strIniFile = msgLog::getCurPath() + L"net";

	int nType = 0;
	::GetPrivateProfileIntW(L"proxy", L"type", nType,strIniFile.c_str());
	if (nType == 1 || nType	==	3)
	{
		m_bHaveProxy = true;
		m_nType = nType;
	}
	//!设置代理
	WCHAR szHost[MAX_PATH] = { 0 };
	::GetPrivateProfileStringW(L"proxy", L"host", L"", szHost, MAX_PATH, strIniFile.c_str());
	m_strHost = szHost;

	WCHAR szPort[MAX_PATH] = { 0 };
	::GetPrivateProfileStringW(L"proxy", L"port", L"", szPort, MAX_PATH, strIniFile.c_str());
	m_strPort = szPort;

	WCHAR szUser[MAX_PATH] = { 0 };
	::GetPrivateProfileStringW(L"proxy", L"user", L"", szUser, MAX_PATH, strIniFile.c_str());
	wstring strUser = szUser;
	if (strUser.empty())
	{
		return;
	}

	WCHAR szPwd[MAX_PATH] = { 0 };
	::GetPrivateProfileStringW(L"proxy", L"pwd", L"", szPwd, MAX_PATH, strIniFile.c_str());
	wstring strPwd = szPwd;
	if (strPwd.empty())
	{
		return;
	}
	m_strUserInfo = strUser + L":" + strPwd;	
}