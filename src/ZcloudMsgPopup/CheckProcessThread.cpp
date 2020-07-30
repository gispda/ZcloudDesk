#include "CheckProcessThread.h"
#include <qt_windows.h>
#include <TlHelp32.h> 
#include <QApplication>
#ifdef VERSION_FOR_GZ
const std::wstring g_strAppName = L"爱服务";
#else
const std::wstring g_strAppName = L"云财税";
#endif
CheckProcessThread::CheckProcessThread(QObject *parent)
	: QThread(parent)
{
}

CheckProcessThread::~CheckProcessThread()
{
}
void CheckProcessThread::run()
{
	while (true)
	{
		// 检测监控桌面
		if ((!seachProcesses(L"ZcloudDesk.exe", true)) && (!seachProcesses(g_strAppName, false)))
		{
			QApplication::exit(0);
		}
		sleep(1);
	}
}

bool CheckProcessThread::seachProcesses(wstring findedName, bool bMatchAll)
{
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);

	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	BOOL bResult = Process32First(hProcessSnap, &pe32);

	while (bResult)
	{
		wstring name = wstring(pe32.szExeFile);
		if (bMatchAll)
		{
			if (name == findedName)
			{
				CloseHandle(hProcessSnap);
				return true;
			}
		}
		else
		{
			wstring::size_type pos = name.find(findedName);
			if (pos != std::string::npos)
			{
				CloseHandle(hProcessSnap);
				return true;
			}
		}
		bResult = Process32Next(hProcessSnap, &pe32);
	}
	CloseHandle(hProcessSnap);
	return false;
}
