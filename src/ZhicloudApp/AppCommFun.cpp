#include "ZcloudCommon.h"
#include "AppCommFun.h"
#include <QApplication>
#include <QFileInfo>
#include <QNetworkInterface>
#include <time.h>
#include <QDir>
#include "AppHttpInterface.h"
#include <QSettings>
#include <windows.h>
#include <shlobj.h>
#include <atlstr.h>
#include <tlhelp32.h>// for CreateToolhelp32Snapshot
#include <Psapi.h>   // for GetModuleFileNameEx
#include "RightClassAppWidget.h"
#include "ZcloudBigData.h"
#include "Database.h"

#pragma   comment(lib,   "shell32.lib")
#pragma   comment(lib,   "version.lib")
#pragma	  comment(lib,   "advapi32.lib")

extern UserInfoStruct app_userInfo;
AppCommFun::AppCommFun(QObject *parent)
	: QObject(parent)
{
}

AppCommFun::~AppCommFun()
{
}



QString AppCommFun::downloadIcon(QString url, QString id)
{
	QString iconPath = QApplication::applicationDirPath() +  "/CacheImage/appImage";
	return ZcloudComFun::downloadIconFromUrl(url, iconPath, id);
}


// 软件存在且是最新的
//查询软件是否存在   存在查询版本是否是最新（最新返回true ）           传入本地是否存在
bool AppCommFun::isHaveNewVerson(AppDataInfo &pData, bool &isNew, bool isHudgeHave)
{

	//先查询 再 修改开票软件版本信息
	//判定 查询是否存在
	if (isHudgeHave)
	{
		//查询应用是否存在
		if (!isSoftInstall(&pData))
		{
			isNew = false;
			return false;
		}
	}

	//读取当前登陆的税号 的开票软件版本
	if (pData.m_strAppName == QString::fromLocal8Bit("开票软件") || pData.m_strAppAlias == QString::fromLocal8Bit("开票软件"))
	{

		//读取线上最新版本的 开票软件版本
		//pData.m_strAppOnLineVerson.clear();
		ZcloudComFun::getSoftwareData(pData.m_strAppDownloadUrl, pData.m_strAppOnLineVerson);
		
		QString	strConfigPath = app_userInfo.m_strTaxNumber;			//！企业税号
		QString strConfigMachine = app_userInfo.m_strMachine;
		QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
		QStringList groupsList = settings->childGroups();
		foreach(QString group, groupsList)
		{
			settings->beginGroup(group);
			QString strCode = settings->value("code", QVariant()).toString();			//！企业税号
			strCode = strCode.replace(" ", "");
			QString machine = settings->value("machine", QVariant()).toString();
			if (strCode == strConfigPath && strConfigMachine == machine)//如果税号相同
			{
				pData.m_strAppCurrentVerson = settings->value("Version", QVariant()).toString();		//！版本
				pData.m_strAppCurrentVerson.replace("V", "");
				pData.m_strAppCurrentVerson.replace("v", "");
				pData.m_strAppCurrentVerson.replace(" ", "");
				break;
			}
			settings->endGroup();
		}
		delete settings;
	}

	pData.m_strAppCurrentVerson.trimmed();
	pData.m_strAppCurrentVerson.trimmed();
	if (pData.m_strAppCurrentVerson.isEmpty() || pData.m_strAppCurrentVerson.isEmpty())
	{
		isNew = true;
		return true;
	}
	isNew =  CompareVersion(pData.m_strAppCurrentVerson, pData.m_strAppOnLineVerson);
	return true;
}




bool AppCommFun::isSoftInstall(AppDataInfo* pAppInfo)
{
	QString strSoftName = pAppInfo->m_strAppName;
	//!注册表应用信息
	QVector<SOFT_INFO> m_vtrSoftInfoList;
	m_vtrSoftInfoList.clear();
	GetSoftInfo(m_vtrSoftInfoList);

	QVector<SOFT_INFO>::iterator itr = m_vtrSoftInfoList.begin();
	for (; itr != m_vtrSoftInfoList.end(); ++itr)
	{
		SOFT_INFO& softInfo(*itr);
		if (softInfo.m_strSoftName.contains(strSoftName, Qt::CaseSensitive) || (!pAppInfo->m_strAppAlias.isEmpty() && softInfo.m_strSoftName.contains(pAppInfo->m_strAppAlias, Qt::CaseSensitive)))
		{
			//过滤掉 百旺 开票软件
			if (softInfo.m_strSoftName.contains(QString::fromLocal8Bit("增值税发票税控开票软件"), Qt::CaseSensitive) && pAppInfo->m_strAppName == QString::fromLocal8Bit("开票软件"))
			{
				continue;
			}

			QString verson = softInfo.m_strSoftVersion;
			verson.replace("v", "");
			verson.replace("V", "");
			verson.replace(" ", "");
			pAppInfo->m_strAppCurrentVerson = verson;
			pAppInfo->m_strAppUninstallPath = softInfo.m_strUninstallPth;
			QString	strInstallLocation = softInfo.m_strInstallLocation;
			QString	strExeFullPath;
			if (strInstallLocation != "")
			{
				strInstallLocation.replace("\\", "/");
				QString	strTemp = strInstallLocation.right(1);
				if (strTemp == "/")
				{
					strInstallLocation = strInstallLocation.mid(0, strInstallLocation.length() - 1);
				}
				strExeFullPath = strInstallLocation + "/" + pAppInfo->m_strAppExecName;
			}
			else
			{
				strInstallLocation = softInfo.m_strUninstallPth;
				if (strInstallLocation == "")
				{
					break;
				}
				strInstallLocation.replace("\"", "");
				strInstallLocation.replace("\\", "/");

				int nIndex = strInstallLocation.indexOf(".exe");
				if (-1 == nIndex)
				{
					nIndex = strInstallLocation.indexOf(".EXE");
					if (-1 == nIndex)
					{
						break;
					}
				}
				strInstallLocation = strInstallLocation.mid(0, nIndex);
				nIndex = strInstallLocation.lastIndexOf("/");
				strInstallLocation = strInstallLocation.mid(0, nIndex);
				strExeFullPath = strInstallLocation + "/" + pAppInfo->m_strAppExecName;
			}

			QFileInfo	info(strExeFullPath);
			if (info.isFile())
			{
				pAppInfo->m_strAppExecPathUrl = strExeFullPath;
				return true;
			}
		}
	}

	QString	strInstall;
	if (queryDeskTop(strSoftName, strInstall))
	{
		if (strInstall.contains(QString::fromLocal8Bit("增值税发票税控开票软件"), Qt::CaseSensitive) && pAppInfo->m_strAppName == QString::fromLocal8Bit("开票软件"))
		{
			return false;
		}
		pAppInfo->m_strAppExecPathUrl = strInstall;
		return true;
	}
	return false;
}



bool AppCommFun::CompareVersion(QString oldVerson, QString newVerson)
{
	QStringList oldVerList = oldVerson.split(".");
	QStringList newVerList = newVerson.split(".");
	for (size_t i = 0; i < (oldVerList.size() > newVerList.size() ? newVerList.size() : oldVerList.size()); i++)
	{
		if (oldVerList.at(i).toInt() != newVerList.at(i).toInt())
		{
			if (oldVerList.at(i).toInt() < newVerList.at(i).toInt())
				return false;
			return true;
		}
	}
	return true;
}


bool AppCommFun::queryDeskTop(QString strAppName, QString& strInstallLoc)
{
	QString	strFullPath;
	if (isLinkFileExsit(strAppName, strFullPath))
	{
		QFileInfo	info(strFullPath);
		if (info.isFile())
		{
			bool isLinkFile = info.isSymLink();
			if (isLinkFile)
			{
				strInstallLoc = info.symLinkTarget();
				if (strInstallLoc.isEmpty())
				{
					strInstallLoc = strFullPath;
				}
				return true;
			}
		}
	}
	return false;
}


bool AppCommFun::isLinkFileExsit(QString strExeLinkName, QString& strLinkFilePath)
{
	//!首先查询用户桌面,判断快捷方式是否存在
	TCHAR   szPath[MAX_PATH] = { 0 };
	SHGetSpecialFolderPath(NULL, szPath, CSIDL_DESKTOPDIRECTORY, false);
	QString strPath = QString::fromStdWString(szPath);
	if (isLinkNameExsit(strPath, strExeLinkName, strLinkFilePath))
	{
		return true;
	}

	//!再判断公用桌面,判断快捷方式是否存在
	SHGetSpecialFolderPath(NULL, szPath, CSIDL_COMMON_DESKTOPDIRECTORY, false);
	strPath = QString::fromStdWString(szPath);
	if (isLinkNameExsit(strPath, strExeLinkName, strLinkFilePath))
	{
		return true;
	}

	//!判断用户开始菜单
	SHGetSpecialFolderPath(NULL, szPath, CSIDL_STARTMENU, false);
	strPath = QString::fromStdWString(szPath);
	if (isLinkNameExsit(strPath, strExeLinkName, strLinkFilePath))
	{
		return true;
	}

	//!判断公用开始菜单
	SHGetSpecialFolderPath(NULL, szPath, CSIDL_COMMON_STARTMENU, false);
	strPath = QString::fromStdWString(szPath);
	if (isLinkNameExsit(strPath, strExeLinkName, strLinkFilePath))
	{
		return true;
	}
	return false;
}

//获取当前安装的 所有程序
void AppCommFun::GetSoftInfo(QVector<SOFT_INFO> &softInfoList)
{
	//    // 保存系统补丁信息
	//    QVector<SOFT_INFO> m_SystemPatchesArr;
	//    // 保存已安装常用软件安装信息
	//    QVector<SOFT_INFO> m_SoftInfoArr;
	SOFT_INFO SoftInfo;
	HKEY RootKey;            // 主键
	LPCTSTR lpSubKey;        // 子键名称
	HKEY hkResult;            // 将要打开键的句柄
	HKEY hkRKey;
	LONG lReturn;            // 记录读取注册表是否成功
	QString strBuffer;
	QString strMidReg;
	DWORD index = 0;

	wchar_t szKeyName[255] = { 0 };        // 注册表项名称
	wchar_t szBuffer[1024] = { 0 };

	DWORD dwKeyLen = 255;
	DWORD dwNameLen = 255;
	DWORD dwType = REG_BINARY | REG_DWORD | REG_EXPAND_SZ | REG_MULTI_SZ | REG_NONE | REG_SZ;
	RootKey = HKEY_LOCAL_MACHINE;

	lpSubKey = reinterpret_cast<LPCTSTR>(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall");
	lReturn = RegOpenKeyEx(RootKey, lpSubKey, 0, KEY_ALL_ACCESS, &hkResult);

	if (lReturn == ERROR_SUCCESS)
	{
		while (ERROR_NO_MORE_ITEMS != RegEnumKeyEx(hkResult, index, szKeyName, &dwKeyLen, 0, NULL, NULL, NULL))
		{
			index++;
			strBuffer = QString::fromUtf16((const ushort*)szKeyName);
			if (!strBuffer.isEmpty())
			{
				strMidReg = QString::fromUtf16((const ushort*)lpSubKey) + QString("\\") + strBuffer;
				if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, (LPCWSTR)strMidReg.utf16(), 0, KEY_ALL_ACCESS, &hkRKey) == ERROR_SUCCESS)
				{
					RegQueryValueEx(hkRKey, L"DisplayName", 0, &dwType, (LPBYTE)szBuffer, &dwNameLen);
					SoftInfo.m_strSoftName = QString::fromUtf16((const ushort*)szBuffer);

					dwNameLen = 1024;
					memset(szBuffer, 0, 1024);
					RegQueryValueEx(hkRKey, L"DisplayVersion", 0, &dwType, (LPBYTE)szBuffer, &dwNameLen);
					SoftInfo.m_strSoftVersion = QString::fromUtf16((const ushort*)szBuffer);

					dwNameLen = 1024;
					memset(szBuffer, 0, 1024);

					RegQueryValueEx(hkRKey, L"InstallLocation", 0, &dwType, (LPBYTE)szBuffer, &dwNameLen);
					SoftInfo.m_strInstallLocation = QString::fromUtf16((const ushort*)szBuffer);

					dwNameLen = 1024;
					memset(szBuffer, 0, 1024);

					RegQueryValueEx(hkRKey, L"Publisher", 0, &dwType, (LPBYTE)szBuffer, &dwNameLen);
					SoftInfo.m_strPublisher = QString::fromUtf16((const ushort*)szBuffer);

					dwNameLen = 1024;
					RegQueryValueEx(hkRKey, L"InstallLocation", 0, &dwType, (LPBYTE)szBuffer, &dwNameLen);

					SoftInfo.m_strMainProPath = QString::fromUtf16((const ushort*)szBuffer);
					dwNameLen = 1024;

					memset(szBuffer, 0, 1024);
					RegQueryValueEx(hkRKey, L"UninstallString", 0, &dwType, (LPBYTE)szBuffer, &dwNameLen);

					SoftInfo.m_strUninstallPth = QString::fromUtf16((const ushort*)szBuffer);
					dwNameLen = 1024;

					memset(szBuffer, 0, 1024);
					if (!SoftInfo.m_strSoftName.isEmpty())
					{
						if (strBuffer.at(0) == 'K' && strBuffer.at(1) == 'B')
						{
							//m_SystemPatchesArr.push_back(SoftInfo);
						}
						else
						{
							//m_SoftInfoArr.push_back(SoftInfo);
							softInfoList.push_back(SoftInfo);
						}
					}
				}
				dwKeyLen = 255;
				memset(szKeyName, 0, 255);
			}
		}
		RegCloseKey(hkResult);
		// qDebug("open register success");
	}
	else
	{
		qDebug("open register failed");
	}
}

QFileInfoList AppCommFun::GetFileList(QString path)
{
	QDir dir(path);
	QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden);
	QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

	for (int i = 0; i != folder_list.size(); i++)
	{
		QString name = folder_list.at(i).absoluteFilePath();
		QFileInfoList child_file_list = GetFileList(name);
		file_list.append(child_file_list);
	}

	return file_list;
}


bool AppCommFun::isLinkNameExsit(QString strDirName, QString strExeLinkName, QString& strLinkFilePath)
{
	QFileInfoList fileInfoList = GetFileList(strDirName);
	QFileInfoList::iterator itr = fileInfoList.begin();
	for (; itr != fileInfoList.end(); ++itr)
	{
		QFileInfo	fileInfo = (*itr);
		if (fileInfo.completeBaseName().contains(strExeLinkName, Qt::CaseSensitive) && fileInfo.suffix() == "lnk")
		{
			strLinkFilePath = fileInfo.filePath();
			return true;
		}
	}
	return false;
}

QString AppCommFun::getFileVertion(QString fullName)
{
	DWORD dwLen = 0;
	char* lpData = NULL;
	BOOL bSuccess = FALSE;
	QString fileInfomation = "";
	//获得文件基础信息
	//--------------------------------------------------------
	dwLen = GetFileVersionInfoSize(fullName.toStdWString().c_str(), 0);
	if (0 == dwLen)
	{
		qDebug() << "zcd-0x00000021:" << "Get file verstion error!";
		return "";
	}
	lpData = new char[dwLen + 1];

	bSuccess = GetFileVersionInfo(fullName.toStdWString().c_str(), 0, dwLen, lpData);
	if (!bSuccess)
	{
		qDebug() << "zcd-0x00000022:" << "Get file verstion error!";
		delete lpData;
		return"";
	}

	LPVOID lpBuffer = NULL;
	UINT uLen = 0;

	//获得语言和代码页(language and code page)
	//---------------------------------------------------
	bSuccess = VerQueryValue(lpData,
		(TEXT("\\VarFileInfo\\Translation")),
		&lpBuffer,
		&uLen);
	QString strTranslation, str1, str2;
	unsigned short int *p = (unsigned short int *)lpBuffer;
	str1.setNum(*p, 16);
	str1 = "000" + str1;
	strTranslation += str1.mid(str1.size() - 4, 4);
	str2.setNum(*(++p), 16);
	str2 = "000" + str2;
	strTranslation += str2.mid(str2.size() - 4, 4);
	//获得文件版本信息
	//-----------------------------------------------------
	QString code = "\\StringFileInfo\\" + strTranslation + "\\FileVersion";
	bSuccess = VerQueryValue(lpData,
		(code.toStdWString().c_str()),
		&lpBuffer,
		&uLen);
	if (!bSuccess)
	{
		qDebug() << "zcd-0x00000023:" << "Get file verstion error!";
		delete lpData;
		return"";
	}
	fileInfomation += QString::fromUtf16((const unsigned short int *)lpBuffer);
	delete[] lpData;//此处不需要释放
	return fileInfomation;
}

QString AppCommFun::GetOs()
{
#ifdef Q_OS_MAC
	return QString("mac");
#endif

#ifdef Q_OS_LINUX
	return QString("Linux");
#endif

#ifdef Q_OS_WIN32
	return QString("windows");
#endif	
}

QString AppCommFun::GetOsVer()
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

	QString osname;

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
				osname = QObject::tr("Microsoft Windows NT 4.0"); //1996年7月发布
			else if (ovi.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
				osname = QObject::tr("Microsoft Windows 95");
			break;
		case 10:
			osname = QObject::tr("Microsoft Windows 98");
			break;
		case 90:
			osname = QObject::tr("Microsoft Windows Me");
			break;
		}
		break;
	case 5:
		switch (ovi.dwMinorVersion)	//再比较dwMinorVersion的值
		{
		case 0:
			osname = QObject::tr("Microsoft Windows 2000");//1999年12月发布
			break;
		case 1:
			osname = QObject::tr("Microsoft Windows XP");//2001年8月发布
			break;
		case 2:
			if (ovi.wProductType == VER_NT_WORKSTATION)
			{
				osname = QObject::tr("Microsoft Windows XP Professional x64 Edition");
			}
			else if (GetSystemMetrics(SM_SERVERR2) == 0)
				osname = QObject::tr("Microsoft Windows Server 2003");//2003年3月发布
			else if (GetSystemMetrics(SM_SERVERR2) != 0)
				osname = QObject::tr("Microsoft Windows Server 2003 R2");
			break;
		}
		break;
	case 6:
		switch (ovi.dwMinorVersion)
		{
		case 0:
			if (ovi.wProductType == VER_NT_WORKSTATION)
				osname = QObject::tr("Microsoft Windows Vista");
			else
				osname = QObject::tr("Microsoft Windows Server 2008");//服务器版本
			break;
		case 1:
			if (ovi.wProductType == VER_NT_WORKSTATION)
				osname = QObject::tr("Microsoft Windows 7");
			else
				osname = QObject::tr("Microsoft Windows Server 2008 R2");
			break;
		}
		break;
	case 10:
		osname = QObject::tr("Microsoft Windows 10");
		break;
	}
	osname += QString(" ");
	osname += QString::fromWCharArray(ovi.szCSDVersion);

	return osname;
}

QString AppCommFun::GetCurTimeFormLoc()
{
	QString strReturn;
	time_t now_time;
	now_time = time(NULL);

	uint	value = (now_time % 10000) * 3 + 2345;
	strReturn = QString("t_=%1&p_=%2").arg(now_time).arg(value);
	return strReturn;
}

//写共享内存 
void AppCommFun::sharedMemory(ReturnStatusEnum enumStatus)
{
	QString key = "zhicloudsharedmemory";
	QString qtstrComData;

	switch (enumStatus)
	{
	case MemoryRUNNING:
		//正在运行
		qtstrComData = "gracefulRun";
		break;
	case MemoryEXIT:
		//退出  需要重启
		qtstrComData = "gracefulExit";
		break;
	case MemoryNOPASS:
		//退出（再 loging  main中已退出）  不重启
		qtstrComData = "loginNopass";
		break;
	case MemoryUPDATE:
		//退出  不重启 
		qtstrComData = "gracefulUpdate";
		break;
	default:
		return;
	}


	QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{A9D22CBD-1E78-4813-8773-007907D30803}_is1", QSettings::NativeFormat);
	settings->setValue("keyServer", qtstrComData);
	delete settings;




	//string strComData = qtstrComData.toStdString();        // 共享内存中的数据
	//LPVOID writeBuffer;                                    // 共享内存指针

	//// 首先试图打开一个命名的内存映射文件对象  
	//HANDLE hMap = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, 0, key.toStdWString().c_str());

	////加锁   （目前没有跟  龙哥  沟通  暂时 不用）
	////HANDLE hMutex = CreateMutex(NULL, FALSE, key.toStdWString().c_str());
	//if (NULL == hMap)
	//{    

	//	// 打开失败，创建之
	//	hMap = ::CreateFileMapping(INVALID_HANDLE_VALUE,
	//		NULL,
	//		PAGE_READWRITE,
	//		0,
	//		strComData.length() + 1,
	//		key.toStdWString().c_str());
	//}
	//// 映射对象的一个视图，得到指向共享内存的指针，设置里面的数据
	//writeBuffer = ::MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	//if (writeBuffer)
	//{
	//	strcpy((char*)writeBuffer, strComData.c_str());
	//	::UnmapViewOfFile(writeBuffer);
	//}
	//需要退出得
	if (MemoryEXIT == enumStatus || MemoryUPDATE == enumStatus)
	{
		//退出需要等待线程完成
		RightClassAppWidget *zhicloudDesk = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance());
		if (zhicloudDesk)
		{
			MemoryEXIT == enumStatus ? zhicloudDesk->zhicoludExitThread(773) : zhicloudDesk->zhicoludExitThread();
		}
		else
		{
			//登录之前 为空
			MemoryEXIT == enumStatus ? qApp->exit(773) : qApp->exit();
		}



		//QProcess *appProcess = new QProcess(NULL);
		//appProcess->start(qApp->applicationFilePath());
		//QProcess::startDetached();
	}
}


QDateTime AppCommFun::getSystemTime()
{
	AppHttpInterface sInter;
	QString strRet;
	if (sInter.WinHttpGetSystemTime(strRet))
	{
		QByteArray byte_array = strRet.toLocal8Bit();
		QJsonParseError json_error;
		QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
		if (json_error.error != QJsonParseError::NoError)
			return QDateTime::currentDateTime();

		if (!parse_doucment.isObject())
			return QDateTime::currentDateTime();

		QJsonObject obj = parse_doucment.object();
		int code = obj.take("code").toInt();
		QString message = obj.take("message").toString();
		if (code == 200 && message == "ok")
		{
			QString strCurrentTime = obj.take("data").toString();
			return QDateTime::fromString(strCurrentTime, "yyyy-MM-dd hh:mm:ss");
		}
	}
	return QDateTime::currentDateTime();
}



QString AppCommFun::getElidedText(QString elidedStr, int fonSize)
{
	int strSize = elidedStr.size();
	QString ddd = "";
	while (elidedStr.toLocal8Bit().length() > (fonSize * 2))
	{
		ddd = "...";
		elidedStr = elidedStr.left(strSize--);
	}
	if (!ddd.isEmpty()) elidedStr = elidedStr.left(strSize--);
	return elidedStr + ddd;
}

// CS应用的等待结束
CsOpenReturnThread::CsOpenReturnThread(QString filePath, QString classId, QString appId, QString appVersion, QObject *parent)
: QThread(parent)
, m_filePath(filePath)
, m_classId(classId)
, m_appId(appId)
, m_appVersion(appVersion)
, m_process(NULL)
{

}

void CsOpenReturnThread::setWorkPath(QString workPath)
{
	if (m_process == NULL)
		m_process = new QProcess();
	m_process->setWorkingDirectory(workPath);
}



CsOpenReturnThread::~CsOpenReturnThread()
{
	delete m_process;
}

void CsOpenReturnThread::run()
{
	if (m_process == NULL)
		m_process = new QProcess(this);
	if (m_strParamList.size() == 0)
	{
		m_process->setProgram(m_filePath);
		m_process->start();
		//m_process->startDetached(m_filePath);
		m_process->waitForStarted();
	}
	else
	{
		m_process->start(m_filePath, m_strParamList);
		//m_process->startDetached(m_filePath, m_strParamList);
	}



	if (m_process->waitForFinished(-1))
	{
		//上报大数据 待处理
	}
	ZcloudBigDataInterface::GetInstance()->produceData("M01", "OP001", "AAC013", m_appId + (m_appVersion.isEmpty() ? "" : ("," + m_appVersion)));
}

void CsOpenReturnThread::setParams(QStringList strParamList)
{
	m_strParamList = strParamList;
}


