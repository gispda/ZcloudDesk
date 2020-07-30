#include "msgLog.h"
#include <windows.h>
#include <string.h>
msgLog::msgLog()
{
}

msgLog::~msgLog()
{
}

void msgLog::WriteMsgToLog(wstring strMsg)
{
	wstring strLogPath = msgLog::getCurPath() + L"Msg.log";
	writeMutex.lock();
	FILE *file = nullptr;
	int err = _wfopen_s(&file,strLogPath.c_str(), L"a+");
	if (!file || strMsg.empty())
	{
		writeMutex.unlock();
		return;
	}

	fwprintf(file, L"%s\n", strMsg.c_str());

	fflush(file);
	fclose(file);
	writeMutex.unlock();
}

wstring msgLog::getCurPath()
{
#ifdef _DEBUG
	TCHAR szFilePath[MAX_PATH] = { 0 };
	GetModuleFileNameW(NULL, szFilePath, MAX_PATH);
	(wcsrchr(szFilePath, L'\\'))[1] = 0; // 删除文件名，只获得路径字串
	return szFilePath;
#else
	wstring strRegeditVer;
	HKEY RootKey;            // 主键
	TCHAR  lpSubKey[MAX_PATH] = { L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{A9D22CBD-1E78-4813-8773-007907D30803}_is1" };
	HKEY hkResult;            // 将要打开键的句柄
	LONG lReturn;
	TCHAR szBuffer[1024] = { 0 };

	DWORD dwType = REG_BINARY | REG_DWORD | REG_EXPAND_SZ | REG_MULTI_SZ | REG_NONE | REG_SZ;
	RootKey = HKEY_LOCAL_MACHINE;
	lReturn = RegOpenKeyEx(RootKey, lpSubKey, 0, KEY_ALL_ACCESS, &hkResult);
	if (lReturn == ERROR_SUCCESS)
	{
		DWORD dwNameLen = 255;
		RegQueryValueEx(hkResult, TEXT("InstallLocation"), 0, &dwType, (LPBYTE)szBuffer, &dwNameLen);
		return szBuffer;
	}
	return L"";
#endif	
}

wstring msgLog::getKeyWord()
{
	wstring strReturn;
	HKEY RootKey;            // 主键
	TCHAR  lpSubKey[MAX_PATH] = { TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{A9D22CBD-1E78-4813-8773-007907D30803}_is1") };//子键名称   

	HKEY hkResult;            // 将要打开键的句柄
	LONG lReturn;
	TCHAR szBuffer[1024] = { 0 };
	DWORD dwNameLen = 255;

	DWORD dwType = REG_BINARY | REG_DWORD | REG_EXPAND_SZ | REG_MULTI_SZ | REG_NONE | REG_SZ;
	RootKey = HKEY_LOCAL_MACHINE;
	lReturn = RegOpenKeyEx(RootKey, lpSubKey, 0, KEY_READ, &hkResult); 
	if (lReturn == ERROR_SUCCESS)
	{
		RegQueryValueEx(hkResult, TEXT("keyServer"), 0, &dwType, (LPBYTE)szBuffer, &dwNameLen);
		return szBuffer;
	}
	else
	{
		::Sleep(500);
		lReturn = RegOpenKeyEx(RootKey, lpSubKey, 0, KEY_READ, &hkResult);
		if (lReturn == ERROR_SUCCESS)
		{
			RegQueryValueEx(hkResult, TEXT("keyServer"), 0, &dwType, (LPBYTE)szBuffer, &dwNameLen);
			return szBuffer;
		}
	}
	return L"";
}
