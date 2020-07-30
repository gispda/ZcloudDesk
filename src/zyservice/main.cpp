#include <windows.h>
#include <TlHelp32.h> 
#include <vector>
#include <shlwapi.h>
#include <WtsApi32.h>
#include <UserEnv.h>
#include <thread>
#include <wincred.h>
#include "msgLog.h"
#include "DataManage.h"
#include "srvInterface.h"

#pragma comment(lib, "Wtsapi32.lib")
#pragma comment(lib, "Userenv.lib")
#pragma comment(lib, "shlwapi.lib") 
TCHAR                               ServiceName[] = L"ZyService";
SERVICE_STATUS                      ServiceStatus;
SERVICE_STATUS_HANDLE               hStatus;

#ifdef VERSION_FOR_GZ
const wstring setupPro	= L"爱服务";
#else
const wstring setupPro = L"云财税";
#endif

const wstring moniPro	= L"ZcloudDesk.exe";
wstring g_strServerAddr;

//!检索进程是否存在
bool seachProcesses(wstring findedName, bool bMatchAll)
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

//!检测安装包完整性(各文件是否存在)
bool checkPageIntact()
{
	vector<wstring> vDependAll = {
		L"audio\\qtaudio_windows.dll", \
		L"bearer\\qgenericbearer.dll", \
		L"bearer\\qnativewifibearer.dll", \
		L"designer\\qaxwidget.dll", \
		L"designer\\qdeclarativeview.dll", \
		L"designer\\qquickwidget.dll", \
		L"designer\\qwebview.dll", \
		L"generic\\qtuiotouchplugin.dll", \
		L"geoservices\\qtgeoservices_mapbox.dll", \
		L"geoservices\\qtgeoservices_nokia.dll", \
		L"geoservices\\qtgeoservices_osm.dll", \
		L"iconengines\\qsvgicon.dll", \
		L"imageformats\\qdds.dll", \
		L"imageformats\\qgif.dll", \
		L"imageformats\\qicns.dll", \
		L"imageformats\\qico.dll", \
		L"imageformats\\qjp2.dll", \
		L"imageformats\\qjpeg.dll", \
		L"imageformats\\qmng.dll", \
		L"imageformats\\qsvg.dll", \
		L"imageformats\\qtga.dll", \
		L"imageformats\\qtiff.dll", \
		L"imageformats\\qwbmp.dll", \
		L"imageformats\\qwebp.dll", \
		L"mediaservice\\dsengine.dll", \
		L"mediaservice\\qtmedia_audioengine.dll", \
		L"mediaservice\\wmfengine.dll", \
		L"platforms\\qminimal.dll", \
		L"platforms\\qoffscreen.dll", \
		L"platforms\\qwindows.dll", \
		L"playlistformats\\qtmultimedia_m3u.dll", \
		L"position\\qtposition_positionpoll.dll", \
		L"printsupport\\windowsprintersupport.dll", \
		L"qml1tooling\\qmldbg_inspector.dll", \
		L"qml1tooling\\qmldbg_tcp_qtdeclarative.dll", \
		L"qmltooling\\qmldbg_qtquick2.dll", \
		L"qmltooling\\qmldbg_tcp.dll", \
		L"qtwebengine\\ffmpegsumo.dll", \
		L"sensorgestures\\qtsensorgestures_plugin.dll", \
		L"sensorgestures\\qtsensorgestures_shakeplugin.dll", \
		L"sensors\\qtsensors_generic.dll", \
		L"sqldrivers\\qsqlite.dll", \
		L"sqldrivers\\qsqlmysql.dll", \
		L"sqldrivers\\qsqlodbc.dll", \
		L"sqldrivers\\qsqlpsql.dll", \
		L"api-ms-win-core-console-l1-1-0.dll", \
		L"api-ms-win-core-datetime-l1-1-0.dll", \
		L"api-ms-win-core-debug-l1-1-0.dll", \
		L"api-ms-win-core-errorhandling-l1-1-0.dll", \
		L"api-ms-win-core-file-l1-1-0.dll", \
		L"api-ms-win-core-file-l1-2-0.dll", \
		L"api-ms-win-core-file-l2-1-0.dll", \
		L"api-ms-win-core-handle-l1-1-0.dll", \
		L"api-ms-win-core-heap-l1-1-0.dll", \
		L"api-ms-win-core-interlocked-l1-1-0.dll", \
		L"api-ms-win-core-libraryloader-l1-1-0.dll", \
		L"api-ms-win-core-localization-l1-2-0.dll", \
		L"api-ms-win-core-memory-l1-1-0.dll", \
		L"api-ms-win-core-namedpipe-l1-1-0.dll", \
		L"api-ms-win-core-processenvironment-l1-1-0.dll", \
		L"api-ms-win-core-processthreads-l1-1-0.dll", \
		L"api-ms-win-core-processthreads-l1-1-1.dll", \
		L"api-ms-win-core-profile-l1-1-0.dll", \
		L"api-ms-win-core-rtlsupport-l1-1-0.dll", \
		L"api-ms-win-core-string-l1-1-0.dll", \
		L"api-ms-win-core-synch-l1-1-0.dll", \
		L"api-ms-win-core-synch-l1-2-0.dll", \
		L"api-ms-win-core-sysinfo-l1-1-0.dll", \
		L"api-ms-win-core-timezone-l1-1-0.dll", \
		L"api-ms-win-core-util-l1-1-0.dll", \
		L"api-ms-win-crt-conio-l1-1-0.dll", \
		L"api-ms-win-crt-convert-l1-1-0.dll", \
		L"api-ms-win-crt-environment-l1-1-0.dll", \
		L"api-ms-win-crt-filesystem-l1-1-0.dll", \
		L"api-ms-win-crt-heap-l1-1-0.dll", \
		L"api-ms-win-crt-locale-l1-1-0.dll", \
		L"api-ms-win-crt-math-l1-1-0.dll", \
		L"api-ms-win-crt-multibyte-l1-1-0.dll", \
		L"api-ms-win-crt-private-l1-1-0.dll", \
		L"api-ms-win-crt-process-l1-1-0.dll", \
		L"api-ms-win-crt-runtime-l1-1-0.dll", \
		L"api-ms-win-crt-stdio-l1-1-0.dll", \
		L"api-ms-win-crt-string-l1-1-0.dll", \
		L"api-ms-win-crt-time-l1-1-0.dll", \
		L"api-ms-win-crt-utility-l1-1-0.dll", \
		L"ucrtbase.dll", \
		L"ssleay32.dll", \
		L"Qt5Xml.dll", \
		L"Qt5Widgets.dll", \
		L"Qt5WebKitWidgets.dll", \
		L"Qt5WebKit.dll", \
		L"Qt5WebChannel.dll", \
		L"Qt5Sql.dll", \
		L"Qt5Sensors.dll", \
		L"Qt5Quick.dll", \
		L"Qt5Qml.dll", \
		L"Qt5PrintSupport.dll", \
		L"Qt5Positioning.dll", \
		L"Qt5OpenGL.dll", \
		L"Qt5Network.dll", \
		L"Qt5MultimediaWidgets.dll", \
		L"Qt5Multimedia.dll", \
		L"Qt5Gui.dll", \
		L"Qt5Core.dll", \
		L"msvcr120.dll", \
		L"msvcp120.dll", \
		L"mfc120.dll", \
		L"libeay32.dll", \
		L"icuuc54.dll", \
		L"icuin54.dll", \
		L"icudt54.dll", \
		L"ZcloudEntCenter.dll", \
		L"ZcloudMsgCenter.dll", \
		L"ZhicloudApp.dll", \
		L"ZcloudCommon.dll", \
		L"ZcloudBigData.dll", \
		L"ZcloudDesk.exe"
	};

	vector<wstring>::iterator   iter = vDependAll.begin();
	wstring strCurAppPath = msgLog::getCurPath();
	for (; iter != vDependAll.end(); iter++)
	{
		wstring strFilePath = strCurAppPath + (*iter);
		if (!PathFileExists(strFilePath.c_str()))
		{
			TCHAR showMsg1[1024] = { 0 };
			wsprintf(showMsg1, L"%s%s%s%s", setupPro,L"启动失败，缺少必要的组件(", (*iter).c_str(), L")，前往官网下载最新安装包。");

			DWORD resp = 0;
			msgLog::WriteMsgToLog(showMsg1);
			WTSSendMessage(
				WTS_CURRENT_SERVER_HANDLE,
				WTSGetActiveConsoleSessionId(),
				L"提示", 5,
				showMsg1, 600,
				0, 0, &resp, true);

			return false;
		}
	}
	return true;
}

//!获取活动sessionid
DWORD GetActiveSessionID()
{
	DWORD dwSessionId = 0;
	PWTS_SESSION_INFO pSessionInfo = NULL;
	DWORD dwCount = 0;

	WTSEnumerateSessions(WTS_CURRENT_SERVER_HANDLE, 0, 1, &pSessionInfo, &dwCount);

	for (DWORD i = 0; i < dwCount; i++)
	{
		WTS_SESSION_INFO si = pSessionInfo[i];
		if (WTSActive == si.State)
		{
			dwSessionId = si.SessionId;
			break;
		}
	}
	WTSFreeMemory(pSessionInfo);
	return dwSessionId;
}

//!启动同步程序
void startSynchronizeProcess(const wstring& strSynchronizePath)
{
	DWORD dwProcesses = 0;
	BOOL bResult = FALSE;

	DWORD dwSid = GetActiveSessionID();

	DWORD dwRet = 0;
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	HANDLE hProcess = NULL, hPToken = NULL, hUserTokenDup = NULL;
	if (!WTSQueryUserToken(dwSid, &hPToken))
	{

		PROCESSENTRY32 procEntry;
		DWORD dwPid = 0;
		HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hSnap == INVALID_HANDLE_VALUE)
		{
			return;
		}

		procEntry.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				wstring strName = procEntry.szExeFile;
				if (strName == L"explorer.exe")
				{
					DWORD exeSessionId = 0;
					if (ProcessIdToSessionId(procEntry.th32ProcessID, &exeSessionId) && exeSessionId == dwSid)
					{
						dwPid = procEntry.th32ProcessID;
						break;
					}
				}

			} while (Process32Next(hSnap, &procEntry));
		}
		CloseHandle(hSnap);

		// explorer进程不存在  
		if (dwPid == 0)
		{
			return;
		}

		hProcess = ::OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, dwPid);
		if (hProcess == NULL)
		{
			return;
		}

		if (!::OpenProcessToken(hProcess, TOKEN_ALL_ACCESS_P, &hPToken))
		{
			CloseHandle(hProcess);
			return;
		}
	}

	if (hPToken == NULL)
		return;

	TOKEN_LINKED_TOKEN admin;
	bResult = GetTokenInformation(hPToken, (TOKEN_INFORMATION_CLASS)19, &admin, sizeof(TOKEN_LINKED_TOKEN), &dwRet);

	if (!bResult) // vista 以前版本不支持TokenLinkedToken  
	{

		TOKEN_PRIVILEGES tp;
		LUID luid;
		if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid))
		{
			tp.PrivilegeCount = 1;
			tp.Privileges[0].Luid = luid;
			tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		}
		DuplicateTokenEx(hPToken, MAXIMUM_ALLOWED, NULL, SecurityIdentification, TokenPrimary, &hUserTokenDup);
	}
	else
	{
		hUserTokenDup = admin.LinkedToken;

	}

	LPVOID pEnv = NULL;
	DWORD dwCreationFlags = CREATE_PRESERVE_CODE_AUTHZ_LEVEL;

	if (CreateEnvironmentBlock(&pEnv, hUserTokenDup, TRUE))
	{
		dwCreationFlags |= CREATE_UNICODE_ENVIRONMENT;
	}
	else
	{
		pEnv = NULL;
	}

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOWNORMAL;
	ZeroMemory(&pi, sizeof(pi));

	msgLog::WriteMsgToLog(strSynchronizePath.c_str());

	bResult = CreateProcessAsUser(
		hUserTokenDup,                     // client's access token  
		NULL,					// file to execute  
		const_cast<LPWSTR>(strSynchronizePath.c_str()),	// command line  
		NULL,					// pointer to process SECURITY_ATTRIBUTES  
		NULL,               // pointer to thread SECURITY_ATTRIBUTES  
		FALSE,              // handles are not inheritable  
		dwCreationFlags,     // creation flags  
		pEnv,               // pointer to new environment block  
		NULL,               // name of current directory  
		&si,               // pointer to STARTUPINFO structure  
		&pi                // receives information about new process  
		);

	if (pi.hProcess)
	{
		if (WAIT_OBJECT_0 == WaitForSingleObject(pi.hProcess, 180000))
		{
			DWORD dwResult = 0;
			if (GetExitCodeProcess(pi.hProcess, &dwResult))
			{
				//n32ExitResult = dwResult;
			}
			else
			{
				//n32ExitResult = -1;
			}

			CloseHandle(pi.hThread);
			CloseHandle(pi.hProcess);
		}
		else
		{
			CloseHandle(pi.hThread);
			CloseHandle(pi.hProcess);
			//n32ExitResult = -1;
		}
	}
	if (hUserTokenDup != NULL)
		CloseHandle(hUserTokenDup);
	if (hProcess != NULL)
		CloseHandle(hProcess);
	if (hPToken != NULL)
		CloseHandle(hPToken);
	if (pEnv != NULL)
		DestroyEnvironmentBlock(pEnv);
}

//!启动云财税主程序
void startMainProcess(wstring  strCallParam)
{
	DWORD dwProcesses = 0;
	BOOL bResult = FALSE;

	DWORD dwSid = GetActiveSessionID();

	DWORD dwRet = 0;
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	HANDLE hProcess = NULL, hPToken = NULL, hUserTokenDup = NULL;
	if (!WTSQueryUserToken(dwSid, &hPToken))
	{

		PROCESSENTRY32 procEntry;
		DWORD dwPid = 0;
		HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hSnap == INVALID_HANDLE_VALUE)
		{
			return;
		}

		procEntry.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				wstring strName = procEntry.szExeFile;
				if (strName == L"explorer.exe")
				{
					DWORD exeSessionId = 0;
					if (ProcessIdToSessionId(procEntry.th32ProcessID, &exeSessionId) && exeSessionId == dwSid)
					{
						dwPid = procEntry.th32ProcessID;
						break;
					}
				}

			} while (Process32Next(hSnap, &procEntry));
		}
		CloseHandle(hSnap);

		// explorer进程不存在  
		if (dwPid == 0)
		{
			return;
		}

		hProcess = ::OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, dwPid);
		if (hProcess == NULL)
		{
			return;
		}

		if (!::OpenProcessToken(hProcess, TOKEN_ALL_ACCESS_P, &hPToken))
		{
			CloseHandle(hProcess);
			return;
		}
	}

	if (hPToken == NULL)
		return;

	TOKEN_LINKED_TOKEN admin;
	bResult = GetTokenInformation(hPToken, (TOKEN_INFORMATION_CLASS)19, &admin, sizeof(TOKEN_LINKED_TOKEN), &dwRet);

	if (!bResult) // vista 以前版本不支持TokenLinkedToken  
	{

		TOKEN_PRIVILEGES tp;
		LUID luid;
		if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid))
		{
			tp.PrivilegeCount = 1;
			tp.Privileges[0].Luid = luid;
			tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		}
		DuplicateTokenEx(hPToken, MAXIMUM_ALLOWED, NULL, SecurityIdentification, TokenPrimary, &hUserTokenDup);
	}
	else
	{
		hUserTokenDup = admin.LinkedToken;

	}

	LPVOID pEnv = NULL;
	DWORD dwCreationFlags = CREATE_PRESERVE_CODE_AUTHZ_LEVEL;

	if (CreateEnvironmentBlock(&pEnv, hUserTokenDup, TRUE))
	{
		dwCreationFlags |= CREATE_UNICODE_ENVIRONMENT;
	}
	else
	{
		pEnv = NULL;
	}

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOWNORMAL;
	ZeroMemory(&pi, sizeof(pi));

	wstring strFilePath = msgLog::getCurPath() + moniPro + L" " + strCallParam;
	msgLog::WriteMsgToLog(strFilePath.c_str());

	bResult = CreateProcessAsUser(
		hUserTokenDup,                     // client's access token  
		NULL,					// file to execute  
		const_cast<LPWSTR>(strFilePath.c_str()),					// command line  
		NULL,					// pointer to process SECURITY_ATTRIBUTES  
		NULL,               // pointer to thread SECURITY_ATTRIBUTES  
		FALSE,              // handles are not inheritable  
		dwCreationFlags,     // creation flags  
		pEnv,               // pointer to new environment block  
		NULL,               // name of current directory  
		&si,               // pointer to STARTUPINFO structure  
		&pi                // receives information about new process  
		);

	if (pi.hProcess)
	{
		if (WAIT_OBJECT_0 == WaitForSingleObject(pi.hProcess, 180000))
		{
			DWORD dwResult = 0;
			if (GetExitCodeProcess(pi.hProcess, &dwResult))
			{
				//n32ExitResult = dwResult;
			}
			else
			{
				//n32ExitResult = -1;
			}

			CloseHandle(pi.hThread);
			CloseHandle(pi.hProcess);
		}
		else
		{
			CloseHandle(pi.hThread);
			CloseHandle(pi.hProcess);
			//n32ExitResult = -1;
		}
	}
	if (hUserTokenDup != NULL)
		CloseHandle(hUserTokenDup);
	if (hProcess != NULL)
		CloseHandle(hProcess);
	if (hPToken != NULL)
		CloseHandle(hPToken);
	if (pEnv != NULL)
		DestroyEnvironmentBlock(pEnv);
}

//!数据库任务线程
void cThreadTaskList()
{
	DataManage *  dm = DataManage::getInstance();
	dm->querySinglelTask();
}

//!循环进程任务线程
void cThreadTaskProcess()
{
	while (true)
	{
		::Sleep(1000 * 3 * 60);
	
		// 检测监控桌面
		if ((!seachProcesses(moniPro,true)) && (!seachProcesses(setupPro, false)))
		{
			wstring strKeyWord = msgLog::getKeyWord();
			if (strKeyWord == L"1") // 退出  需要重启
			{
				msgLog::WriteMsgToLog(L"ready to CreateZyProcess 1.....");
				startMainProcess(L"1");
			}
		}
		msgLog::WriteMsgToLog(L"next while loop");
	}
}

void getHttpUrl()
{
	wstring strIniPath = msgLog::getCurPath() + L"config.ini";
	WCHAR szHostName[MAX_PATH] = { 0 };
	::GetPrivateProfileStringW(L"api", L"hostName", L"https://api.zhicloud.com", szHostName, MAX_PATH, strIniPath.c_str());
	g_strServerAddr = szHostName;
}
//!业务逻辑开始
void beginService()
{
	//!获取api服务器地址
	getHttpUrl();

	msgLog::WriteMsgToLog(g_strServerAddr.c_str());
	msgLog::WriteMsgToLog(L"###zyservice Service runing###");

	//！确认当前会话是否进入桌面
	while (true)
	{
		if (!seachProcesses(L"explorer.exe", true))
		{
			::Sleep(1000 * 3);
		}
		else
		{
			break;
		}
	}
	msgLog::WriteMsgToLog(L"explorer find sucessed");

	//!检测安装包完整性
	if (!checkPageIntact())
	{
		return;
	}
	msgLog::WriteMsgToLog(L"checkPageIntact sucessed");

	//!启动客户端
	if (!seachProcesses(moniPro, "full"))
	{
		// 启动
		startMainProcess(L"0");
		msgLog::WriteMsgToLog(L"startMainProcess 0");
		::Sleep(1000 * 5);
	}	
	msgLog::WriteMsgToLog(L"startMainProcess sucessed");

	std::thread   threadTaskList(cThreadTaskList);

	std::thread   threadTaskProcess(cThreadTaskProcess);

	threadTaskList.join();
	threadTaskProcess.join();
}

void WINAPI svcHandler(DWORD fdwControl)
{
	switch (fdwControl)
	{
	case SERVICE_CONTROL_STOP:
	{
		msgLog::WriteMsgToLog(L"zyservice stop...");

		ServiceStatus.dwCurrentState = SERVICE_STOPPED;
		ServiceStatus.dwWin32ExitCode = 0;
		SetServiceStatus(hStatus, &ServiceStatus);
	}
	break;
	case SERVICE_CONTROL_SHUTDOWN:
	{
		msgLog::WriteMsgToLog(L"zyservice shutdown...");

		ServiceStatus.dwCurrentState = SERVICE_STOPPED;
		ServiceStatus.dwWin32ExitCode = 0;
		SetServiceStatus(hStatus, &ServiceStatus);
	}
	break;
	default:
		break;
	}
}

void WINAPI ServiceMain(DWORD argc, LPTSTR* argv)
{
	ServiceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS | SERVICE_INTERACTIVE_PROCESS;
	ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
	ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_STOP;
	ServiceStatus.dwWin32ExitCode = NO_ERROR;
	ServiceStatus.dwServiceSpecificExitCode = NO_ERROR;
	ServiceStatus.dwCheckPoint = 0;
	ServiceStatus.dwWaitHint = 0;

	hStatus = RegisterServiceCtrlHandler(ServiceName, svcHandler);
	if (!hStatus)
	{
		DWORD dwError = GetLastError();
		return;
	}

	msgLog::WriteMsgToLog(L"zyservice startup...");

	ServiceStatus.dwCurrentState = SERVICE_RUNNING;
	SetServiceStatus(hStatus, &ServiceStatus);

	beginService();
}

//!单例运行
bool singleRun()
{
	HANDLE h = ::CreateEvent(NULL, FALSE, TRUE, L"zyservice");
	auto err = GetLastError();
	if (err == ERROR_ALREADY_EXISTS)
	{
		return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	//!设置中文环境
	setlocale(LC_ALL, "chs");

	if (!singleRun())
	{
		return 0;
	}
	//beginService();
	//return 0;
	SERVICE_TABLE_ENTRY ServiceTable[] =
	{
		{ ServiceName, ServiceMain },
		{ NULL, NULL },
	};

	return StartServiceCtrlDispatcher(ServiceTable);
}