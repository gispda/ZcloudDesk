#include "ZcloudCommon.h"
#include "MessageTipDlg.h"
#include "SrvInterface.h"
#include "DownLoadIcon.h"
#include "AES/qaeswrap.h"
#include <QHostInfo>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>
#include <shlobj.h>
#include <QEventLoop>
#include <QTimer>
#include <QNetworkInterface>
#include <QProcess>
#pragma   comment(lib,   "shell32.lib")
#pragma   comment(lib,   "version.lib")
#define NTDLL_RTL_GET_VERSION

int ZcloudComFun::openMessageTipDlg(EN_BTN_TYPE enBtnType, QString strTitle, QString strMsg, QWidget *parent /*= 0*/)
{
	MessageTipDlg	dlg(enBtnType, strTitle, strMsg, parent);
	
	return dlg.exec();
}

int ZcloudComFun::openUploadTipDlg(QWidget *parent /*= 0*/)
{
	UpdateTipDlg  dlg(parent);
	return dlg.exec();
}

int ZcloudComFun::openMessageTipDlg_2(EN_BTN_TYPE enBtnType, QString strTitle, QString strMsg, QString buttonStr_1, QString buttonStr_2, QWidget *parent /*= 0*/)
{
	MessageTipDlg	dlg(enBtnType, strTitle, strMsg,buttonStr_1, buttonStr_2, parent);
	return dlg.exec();
}

int ZcloudComFun::openMessageTipDlg_3(EN_BTN_TYPE enBtnType, QString strTitle, QString strImageUrl, QString buttonStr_1, QString buttonStr_2, QWidget *parent /*= 0*/)
{
	MessageTipDlg	dlg(enBtnType, strTitle, "", buttonStr_1, buttonStr_2, parent);
	dlg.
	return dlg.exec();
}


int SSO(QString jsonStr)
{
	QByteArray byte_array = jsonStr.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError || !parse_doucment.isObject())
	{
		return 1;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("code").toInt();
	return status;
	
}



bool ZcloudComFun::httpPost(QString strUrl, QString strPost, int nTimeout, QString& strRet, bool isCheckToken /*= false*/,int _type)
{
	(-1 == strUrl.indexOf("?")) ? strUrl.append("?") : strUrl.append("&");
	strUrl.append("mac=").append(getHostMacAddress()).append("&version=")
		.append(getFileVertion(QApplication::applicationFilePath())).append("&system=").append(getOsVer());
	SrvInterface	sInter;
	bool httpS = sInter.httpPost(strUrl, strPost, nTimeout, strRet,_type);
	//������߳� ���� ��UI���� ������� ���мӴ��ֶ�
	if (isCheckToken)
	{
		if (httpS && strUrl.contains("token") && !strRet.isEmpty())
		{
			int status = SSO(strRet);
			if (-1 == status)
			{
				//token ����
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ĵ�¼�ѹ��ڣ������µ�¼��"));

				ZcloudComFun::writeRegReboot(ZcloudComFun::EN_NOREBOOT);
				QProcess p;
				QString c = "taskkill /im ZcloudDesk.exe /f";
				p.execute(c);
				p.close();
			}
			else if (-2 == status)
			{
				//�����ط���¼ �����¼
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�����˺����������ط���¼�������������˲�\r\n������ע���˺Ű�ȫ��"));

				ZcloudComFun::writeRegReboot(ZcloudComFun::EN_NOREBOOT);
				QProcess p;
				QString c = "taskkill /im ZcloudDesk.exe /f";
				p.execute(c);
				p.close();
			}
		}
	}
	return httpS;
}

bool ZcloudComFun::httpPostFile(QString strUrl, QByteArray strPost, int nTimeout, QString& strRet, bool isCheckToken /*= false*/, int _type /*= 0*/)
{
	(-1 == strUrl.indexOf("?")) ? strUrl.append("?") : strUrl.append("&");
	strUrl.append("mac=").append(getHostMacAddress()).append("&version=")
		.append(getFileVertion(QApplication::applicationFilePath())).append("&system=").append(getOsVer());
	SrvInterface	sInter;
	bool httpS = sInter.httpPost(strUrl, strPost, nTimeout, strRet, _type);
	//������߳� ���� ��UI���� ������� ���мӴ��ֶ�
	if (isCheckToken)
	{
		if (httpS && strUrl.contains("token") && !strRet.isEmpty())
		{
			int status = SSO(strRet);
			if (-1 == status)
			{
				//token ����
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ĵ�¼�ѹ��ڣ������µ�¼��"));

				ZcloudComFun::writeRegReboot(ZcloudComFun::EN_NOREBOOT);
				QProcess p;
				QString c = "taskkill /im ZcloudDesk.exe /f";
				p.execute(c);
				p.close();
			}
			else if (-2 == status)
			{
				//�����ط���¼ �����¼
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�����˺����������ط���¼�������������˲�\r\n������ע���˺Ű�ȫ��"));

				ZcloudComFun::writeRegReboot(ZcloudComFun::EN_NOREBOOT);
				QProcess p;
				QString c = "taskkill /im ZcloudDesk.exe /f";
				p.execute(c);
				p.close();
			}
		}
	}
	return httpS;
}


bool ZcloudComFun::winHttpSSO(QString strToken, QString strUserId)
{
	QString strUrl = QString("/ucenter/general/ping");
	QString strPost = QString("token=%1").arg(strToken);
	QString strRet;
	bool httpR = ZcloudComFun::httpPost(strUrl, strPost, 2000, strRet,true,1);
	if (httpR && !strRet.isEmpty())
	{
		int status = SSO(strRet);
		if (-1 == status || -2 == status)
		{
			//token ����
			//�����ط���¼ �����¼
			return false;
		}
	}
	return true;
}


QString ZcloudComFun::downloadIconFromUrl(QString strUrl, QString strDirPath, QString strAppId)
{
	QString strReturn;
	DownLoadIcon * cloudDownload = new DownLoadIcon();
	cloudDownload->setValue(strDirPath, strUrl, strAppId);
	cloudDownload->run();
	if (cloudDownload->errorFlag)
	{
		strReturn = cloudDownload->filePath;
		strReturn.replace("\\", "/");
	}
	else
	{
		if (!strAppId.isEmpty())
		{
			//����ʧ��  �����һ�����سɹ� �߻���
			if (QFileInfo::exists(QString(strDirPath + "\\%1.png").arg(strAppId)))
			{
				cloudDownload->deleteLater();
				cloudDownload = NULL;
				return QString(strDirPath + "\\%1.png").arg(strAppId);
			}
			else
			{
				//����ϴ�����ʧ�� �߱���
				//	QString iconPathBack = QString(QApplication::applicationDirPath() + "\\CacheImageBack" + "\\%1.png").arg(id);
				//	if (QFileInfo::exists(iconPathBack))
				//	{
				//		QString iconCopyPath = QString(iconPath + "\\%1.png").arg(id);
				//		if (QFile::copy(iconPathBack, iconCopyPath))
				//		{
				//			cloudDownload->deleteLater();
				//			cloudDownload = NULL;
				//			return iconCopyPath;
				//		}
				//	}
			}
		}
		QString filename = QFileInfo(strUrl).fileName();
		if (!filename.isEmpty())
		{
			QString oldFileNamePath = strDirPath + "/" + filename;
			QFile oldFile(oldFileNamePath);
			if (oldFile.exists())
			{
				strReturn = oldFileNamePath;
				strReturn.replace("\\", "/");
				cloudDownload->deleteLater();
				cloudDownload = NULL;
				return strReturn;
			}
		}
		strReturn.clear();
	}
	cloudDownload->deleteLater();
	cloudDownload = NULL;
	return strReturn;
}

bool ZcloudComFun::isNetActive()
{
	QString strRet;
	QString strUrl = QString("/ucenter/general/ping");

	
	return httpPost(strUrl, "", 15000, strRet);
}

//��ȡ��Ʊ�����
bool ZcloudComFun::readsoft(QString &verSion, QString taxNumber)
{
	HKEY RootKey;            // ����
	LPCTSTR lpSubKey;        // �Ӽ�����
	HKEY hkResult;            // ��Ҫ�򿪼��ľ��
	HKEY hkRKey;
	LONG lReturn;            // ��¼��ȡע����Ƿ�ɹ�
	QString strBuffer;
	QString strMidReg;
	DWORD index = 0;

	wchar_t szKeyName[255] = { 0 };        // ע���������
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
					QString strSoftName = QString::fromUtf16((const ushort*)szBuffer);
					if (strSoftName.contains(QString::fromLocal8Bit("��Ʊ���"), Qt::CaseSensitive))
					{
						//���˵� ���� ��Ʊ���
						if (!strSoftName.contains(QString::fromLocal8Bit("��ֵ˰��Ʊ˰�ؿ�Ʊ���"), Qt::CaseSensitive))
						{
							QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
							QStringList groupsList = settings->childGroups();
							foreach(QString group, groupsList)
							{
								settings->beginGroup(group);
								QString strCode = settings->value("code", QVariant()).toString();			//����ҵ˰��
								strCode = strCode.replace(" ", "");
								QString machine = settings->value("machine", QVariant()).toString();
								
								settings->endGroup();
								if (taxNumber.isEmpty())
									break;
								else
								{
									if (strCode == taxNumber)//���˰����ͬ
									{
										verSion = settings->value("Version", QVariant()).toString();		//���汾
										verSion.replace("V", "");
										verSion.replace("v", "");
										verSion.replace(" ", "");
										break;
									}
									continue;
								}
							}
							delete settings;
							return true;;
						}
					}
				}
				dwKeyLen = 255;
				memset(szKeyName, 0, 255);
			}
		}
		RegCloseKey(hkResult);
	}
	return false;
		
}

bool ZcloudComFun::qtReadsoft(QString &verSion, QString taxNumber)
{
	QString lpSubKey = "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall";
	QSettings lpSettings(lpSubKey, QSettings::NativeFormat);
	QStringList lpGroupsList = lpSettings.childGroups();
	for (int i = lpGroupsList.size(); i > 0; )
	{
		QString strSoftName = lpGroupsList.at(--i);
		if (strSoftName.isEmpty())
			continue;
		if (strSoftName.contains(QString::fromLocal8Bit("��Ʊ���"), Qt::CaseSensitive) && !strSoftName.contains(QString::fromLocal8Bit("��ֵ˰��Ʊ˰�ؿ�Ʊ���"), Qt::CaseSensitive))//���˵� ���� ��Ʊ���
		{
			if (readSoftV(verSion, taxNumber))
				return true;
		}
		//��ѯ���� ע���
		QSettings lp2Settings(lpSubKey + "\\" + strSoftName, QSettings::NativeFormat);
		QStringList lp2GroupsList = lp2Settings.childGroups();
		foreach(QString group, lp2GroupsList)
		{
			if (group.isEmpty())
				continue;
			if (group.contains(QString::fromLocal8Bit("��Ʊ���"), Qt::CaseSensitive) && !group.contains(QString::fromLocal8Bit("��ֵ˰��Ʊ˰�ؿ�Ʊ���"), Qt::CaseSensitive))//���˵� ���� ��Ʊ���
			{
				if (readSoftV(verSion, taxNumber))
					return true;
			}
		}
	}
	return false;
}

QStringList ZcloudComFun::getTaxnumberList()
{
	QSettings settings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
	QStringList groupsList = settings.childGroups();
	
	QString strCode;
	QStringList strTaxnols;
	foreach(QString group, groupsList)
	{
		settings.beginGroup(group);
		strCode = settings.value("code", QVariant()).toString();			//����ҵ˰��
	    

		strTaxnols.append(strCode);

		settings.endGroup();
	}
	return strTaxnols;

}


QString ZcloudComFun::getFirstTaxnumbers()
{

	QString strtaxls = "";
	QStringList strLocalTaxnoLs = ZcloudComFun::getTaxnumberList();
	int nsize = strLocalTaxnoLs.count();

	if (nsize > 0)
	{

		return strLocalTaxnoLs.at(0);
	}
	else
		return "";
}

QString ZcloudComFun::getTaxnumbers()
{

	QString strtaxls="";
	QStringList strLocalTaxnoLs = ZcloudComFun::getTaxnumberList();
	int nsize = strLocalTaxnoLs.count();
	
	for (int index = 0; index < nsize; index++)
	{

		strtaxls.append(strLocalTaxnoLs.at(index));
		if (index < (nsize - 1))
		{
			strLocalTaxnoLs.append(",");
		}
	}

	return strtaxls;

}

bool ZcloudComFun::readSoftV(QString &verSion, QString tax_number)
{
	QSettings settings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
	QStringList groupsList = settings.childGroups();
	int validCode = groupsList.size();
	foreach(QString group, groupsList)
	{
		settings.beginGroup(group);
		QString strCode = settings.value("code", QVariant()).toString();			//����ҵ˰��
		strCode = strCode.replace(" ", "");
		QString machine = settings.value("machine", QVariant()).toString();
		settings.endGroup();
		if (strCode.isEmpty())
		{
			validCode--;
			continue;
		}
		if (tax_number.isEmpty())
		{
			verSion = settings.value("Version", QVariant()).toString();		//���汾
			verSion.replace("V", "");
			verSion.replace("v", "");
			verSion.replace(" ", "");
			return true;
		}
		else
		{
			if (strCode == tax_number)//���˰����ͬ
			{
				verSion = settings.value("Version", QVariant()).toString();		//���汾
				verSion.replace("V", "");
				verSion.replace("v", "");
				verSion.replace(" ", "");
				return true;
			}
			continue;
		}
	}
	if (validCode > 0)
		return true;
	return false;
}

bool ZcloudComFun::getSoftwareData(QString &url, QString &verson_hszId, QString tax_number)
{
	QString	strRet;
	QString strUrl = QString("");
	if (!verson_hszId.isEmpty())
	{
		strUrl.append("/general/get-invoice-software?hzs_id=" + verson_hszId);
	}
	else
	{
		QString province;
		QString city;
		if (!GetNetIP(province, city).isEmpty() && !city.isEmpty() && !province.isEmpty())
		{
			strUrl.append("/general/get-invoice-software?province=" + province + "&city=" + city);
			if (!tax_number.isEmpty())
			{
				strUrl.append("&tax_number=" + tax_number);
			}
		}
		else
		{
			if (!tax_number.isEmpty())
			{
				strUrl.append("/general/get-invoice-software?tax_number=" + tax_number);
			}
			else
			{
				return false;
			}
		}
	}
	if (ZcloudComFun::httpPost(strUrl, "", 5000, strRet))
	{
		QJsonParseError jsonError;
		QJsonDocument jsonDocument = QJsonDocument::fromJson(strRet.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			QJsonObject obj = jsonDocument.object();
			int code = obj.take("status").toInt();
			QString message = obj.take("message").toString();
			if (code == 0)
			{
				QJsonValue data = obj.take("data");
				if (data.isObject())
				{
					QJsonObject dataObj = data.toObject();
					url = dataObj.take("download_url").toString();
					verson_hszId = dataObj.take("version_number").toString();//"2.1.30.180227";
					if (!url.isEmpty() && !verson_hszId.isEmpty())
					{
						return true;
						//url = "http://download.zhicloud.com/app/pkg/invoice.exe";
					}
				}
				//else
				//{
				//	url = "http://download.zhicloud.com/app/pkg/invoice.exe";
				//	return true;
				//}
			}
		}
	}
	return false;
}

//��ȡ��������IP��ַ
QString ZcloudComFun::GetNetIP(QString &province, QString &city) {
	QString strRet;
	QString strUrl = QString("/general/get-server-time");
	if (!httpPost(strUrl, "", 5000, strRet))
	{
		return "";
	} 
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(strRet.toUtf8(), &json_error);
	if (json_error.error == QJsonParseError::NoError && parse_doucment.isObject())
	{
		QJsonObject obj = parse_doucment.object();
		int code = obj.take("status").toInt();
		if (code == 0)
		{
			QJsonObject data = obj.take("data").toObject();
			QString netIp = data.take("client_ip").toString();
			QNetworkAccessManager *manager = new QNetworkAccessManager();
			QNetworkReply *reply = manager->get(QNetworkRequest(QUrl("http://api.map.baidu.com/location/ip?ak=aaiHrfToeg63rSDdoPg8SgXE&ip=" + netIp)));
			QByteArray responseData;
			QEventLoop eventLoop;
			QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
			eventLoop.exec();
			responseData = reply->readAll();

			QJsonParseError json_error;
			QJsonDocument parse_doucment = QJsonDocument::fromJson(responseData, &json_error);
			if (json_error.error == QJsonParseError::NoError && parse_doucment.isObject())
			{
				QJsonObject obj = parse_doucment.object();
				int code = obj.take("status").toInt();
				if (code == 0)
				{
					QJsonObject address_detail = obj.take("content").toObject().take("address_detail").toObject();
					province = address_detail.take("province").toString();
					city = address_detail.take("city").toString();
					if (!province.isEmpty() && !city.isEmpty())
					{
						return netIp;
					}
				}
			}
		}
	}
	return "";
}

QString ZcloudComFun::getFileVertion(QString fullName)
{
	DWORD dwLen = 0;
	char* lpData = NULL;
	BOOL bSuccess = FALSE;
	QString fileInfomation = "";
	//����ļ�������Ϣ
	//--------------------------------------------------------
	dwLen = GetFileVersionInfoSize(fullName.toStdWString().c_str(), 0);
	if (0 == dwLen)
	{
		qDebug() << "zcd-0x0000003E:" << "Get file verstion error!";
		return "";
	}
	lpData = new char[dwLen + 1];

	bSuccess = GetFileVersionInfo(fullName.toStdWString().c_str(), 0, dwLen, lpData);
	if (!bSuccess)
	{
		qDebug() << "zcd-0x0000003F:" << "Get file verstion error!";
		delete lpData;
		return"";
	}

	LPVOID lpBuffer = NULL;
	UINT uLen = 0;

	//������Ժʹ���ҳ(language and code page)
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
	//����ļ��汾��Ϣ
	//-----------------------------------------------------
	QString code = "\\StringFileInfo\\" + strTranslation + "\\FileVersion";
	bSuccess = VerQueryValue(lpData,
		(code.toStdWString().c_str()),
		&lpBuffer,
		&uLen);
	if (!bSuccess)
	{
		qDebug() << "zcd-0x00000040:" << "Get file verstion error!";
		delete lpData;
		return"";
	}
	fileInfomation += QString::fromUtf16((const unsigned short int *)lpBuffer);
	delete[] lpData;//�˴�����Ҫ�ͷ�
	return fileInfomation;
}



//isOnAesUncrypt = false ����   ��֮����
bool ZcloudComFun::aesZhicloud(QByteArray &data, QString strKey, bool isOnAesUncrypt)
{
	QString keyStr = "tohn" + strKey;
	QByteArray mdata;
	QAesWrap aes(keyStr.toLocal8Bit(), "zhicloud.com", QAesWrap::AES_256);
	if (isOnAesUncrypt)
	{
		if (aes.encrypt(data, mdata, QAesWrap::AES_CTR))
		{
			data = mdata;
			return true;
		}
	}
	else
	{
		if (aes.decrypt(data, mdata, QAesWrap::AES_CTR))
		{
			data = mdata;
			return true;

		}
	}
	return false;
}

QString ZcloudComFun::getHostMacAddress()
{
	//�������ᱨ ����Invalid parameter passed to C runtime function.
	QString strMacAddr = "";
	for each (QNetworkInterface net in QNetworkInterface::allInterfaces()) // ��ȡ��������ӿ��б�  
	{
		// ���������ӿڱ�������������в��Ҳ��ǻػ���ַ�������������Ҫ�ҵ�Mac��ַ  
		if (net.flags().testFlag(QNetworkInterface::IsUp) && net.flags().testFlag(QNetworkInterface::IsRunning) && !net.flags().testFlag(QNetworkInterface::IsLoopBack))
		{
			strMacAddr = net.hardwareAddress();
			break;
		}
	}
	return strMacAddr;
}

BOOL GetVersionEx2(LPOSVERSIONINFOW lpVersionInformation)
{
	HMODULE hNtDll = GetModuleHandleW(L"NTDLL"); // ��ȡntdll.dll�ľ��
	typedef NTSTATUS(NTAPI*tRtlGetVersion)(PRTL_OSVERSIONINFOW povi); // RtlGetVersion��ԭ��
	tRtlGetVersion pRtlGetVersion = NULL;
	if (hNtDll)
	{
		pRtlGetVersion = (tRtlGetVersion)GetProcAddress(hNtDll, "RtlGetVersion"); // ��ȡRtlGetVersion��ַ
	}
	if (pRtlGetVersion)
	{
		return pRtlGetVersion((PRTL_OSVERSIONINFOW)lpVersionInformation) >= 0; // ����RtlGetVersion
	}
	return FALSE;
}


QString  ZcloudComFun::getOsVerQt()
{
	QSysInfo::WinVersion ver = QSysInfo::windowsVersion();
	QString ovVer = "";
	switch (ver)
	{
	case QSysInfo::WV_None:
		ovVer = QString("WV_None");
		break;
	case QSysInfo::WV_32s:
		ovVer = QString("WV_32s");
		break;
	case QSysInfo::WV_95:
		ovVer = QString("WV_95");
		break;
	case QSysInfo::WV_98:
		ovVer = QString("WV_98");
		break;
	case QSysInfo::WV_Me:
		ovVer = QString("WV_Me");
		break;
	case QSysInfo::WV_DOS_based:
		ovVer = QString("WV_DOS_based");
		break;
	case QSysInfo::WV_NT:
		ovVer = QString("WV_NT");
		break;
	case QSysInfo::WV_2000:
		ovVer = QString("WV_2000");
		break;
	case QSysInfo::WV_XP:
		ovVer = QString("WV_XP");
		break;
	case QSysInfo::WV_2003:
		ovVer = QString("WV_2003");
		break;
	case QSysInfo::WV_VISTA:
		ovVer = QString("WV_VISTA");
		break;
	case QSysInfo::WV_WINDOWS7:
		ovVer = QString("WV_WINDOWS7");
		break;
	case QSysInfo::WV_WINDOWS8:
		ovVer = QString("WV_WINDOWS8");
		break;
	case QSysInfo::WV_WINDOWS8_1:
		ovVer = QString("WV_WINDOWS8_1");
		break;
	case QSysInfo::WV_WINDOWS10:
		ovVer = QString("WV_WINDOWS10");
		break;
	case QSysInfo::WV_NT_based:
		ovVer = QString("WV_NT_based");
		break;
		//case QSysInfo::WV_4_0:
		//	break;
		//case QSysInfo::WV_5_0:
		//	break;
		//case QSysInfo::WV_5_1:
		//	break;
		//case QSysInfo::WV_5_2:
		//	break;
		//case QSysInfo::WV_6_0:
		//	break;
		//case QSysInfo::WV_6_1:
		//	break;
		//case QSysInfo::WV_6_2:
		//	break;
		//case QSysInfo::WV_6_3:
		//	break;
		//case QSysInfo::WV_10_0:
		//	break;
	case QSysInfo::WV_CE:
		ovVer = QString("WV_CE");
		break;
	case QSysInfo::WV_CENET:
		ovVer = QString("WV_CENET");
		break;
	case QSysInfo::WV_CE_5:
		ovVer = QString("WV_CE_5");
		break;
	case QSysInfo::WV_CE_6:
		ovVer = QString("WV_CE_6");
		break;
	case QSysInfo::WV_CE_based:
		ovVer = QString("WV_CE_based");
		break;
	default:
		ovVer = QString("WV_other");
		break;
	}
	return ovVer;
}


QString ZcloudComFun::getOsVer()
{
	//!Ŀǰֻ����windows�汾
	OSVERSIONINFOEXW ovi = { sizeof ovi };

#ifdef NTDLL_RTL_GET_VERSION
	GetVersionEx2((LPOSVERSIONINFOW)&ovi);
	//printf("ʹ��NTDLL->RtlGetVersion��ȡ����Ϣ��\n");
#else
	GetVersionExW((LPOSVERSIONINFOW)&ovi);
	//printf("ʹ��KERNEL32->GetVersionExW��ȡ����Ϣ��\n");
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

	switch (ovi.dwMajorVersion)//�ж����汾��
	{
	case 4:
		switch (ovi.dwMinorVersion)//�жϴΰ汾��
		{
		case 0:
			if (ovi.dwPlatformId == VER_PLATFORM_WIN32_NT)
				osname = QObject::tr("Microsoft Windows NT 4.0"); //1996��7�·���
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
		switch (ovi.dwMinorVersion)	//�ٱȽ�dwMinorVersion��ֵ
		{
		case 0:
			osname = QObject::tr("Microsoft Windows 2000");//1999��12�·���
			break;
		case 1:
			osname = QObject::tr("Microsoft Windows XP");//2001��8�·���
			break;
		case 2:
			if (ovi.wProductType == VER_NT_WORKSTATION)
			{
				osname = QObject::tr("Microsoft Windows XP Professional x64 Edition");
			}
			else if (GetSystemMetrics(SM_SERVERR2) == 0)
				osname = QObject::tr("Microsoft Windows Server 2003");//2003��3�·���
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
				osname = QObject::tr("Microsoft Windows Server 2008");//�������汾
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
QString ZcloudComFun::getHostName()
{
	SrvInterface	sInter;
	return sInter.getHostName();
}

QString ZcloudComFun::getWvUrl(QString strUid, QString strtoken, QString strFun)
{

	if (strFun.contains("?"))
	{
		return QString("%1/%2&user_id=%3&token=%4&mac=%5&version=%6&system=%7").arg(getHostName()).arg(strFun).arg(strUid).arg(strtoken)
			.arg(getHostMacAddress()).arg(getFileVertion(QApplication::applicationFilePath())).arg(getOsVer());
	}
	return QString("%1/%2?user_id=%3&token=%4&mac=%5&version=%6&system=%7").arg(getHostName()).arg(strFun).arg(strUid).arg(strtoken)
		.arg(getHostMacAddress()).arg(getFileVertion(QApplication::applicationFilePath())).arg(getOsVer());
}

void ZcloudComFun::writeRegReboot(EN_REBOOT_TYPE enType)
{
	QString key = "zhicloudsharedmemory";
	QString qtstrComData;

	switch (enType)
	{
	case EN_NOREBOOT:
		qtstrComData = "0";
		break;
	case EN_REBOOT_PARAMS:
		qtstrComData = "1";
		break;
	}

	QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{A9D22CBD-1E78-4813-8773-007907D30803}_is1", QSettings::NativeFormat);
	settings->setValue("keyServer", qtstrComData);
	delete settings;
}

QString ZcloudComFun::getTopToolUrl(QString strUid, QString strtoken, QString strFun)
{
	if (strFun.contains("?"))
	{
		return QString("%1&user_id=%2&token=%3&mac=%4&version=%5&system=%6").arg(strFun).arg(strUid).arg(strtoken)
			.arg(getHostMacAddress()).arg(getFileVertion(QApplication::applicationFilePath())).arg(getOsVer());
	}
	return QString("%1?user_id=%2&token=%3&mac=%4&version=%5&system=%6").arg(strFun).arg(strUid).arg(strtoken)
		.arg(getHostMacAddress()).arg(getFileVertion(QApplication::applicationFilePath())).arg(getOsVer());
}

QString ZcloudComFun::downloadPic(QString strUrl, QString strDirPath)
{
	if (strUrl.isEmpty())
	{
		return "";
	}

	QDir dir(strDirPath);
	if (!dir.exists())
	{
		dir.mkpath(strDirPath);
	}

	//!������ص��ļ��Ѿ����ڣ���ֱ�ӷ��� �����������3��
	int nPos = strUrl.lastIndexOf("/");
	QString strFileName = strUrl.mid(nPos + 1);
	QString strFilePath = strDirPath + "/" + strFileName;
	QFileInfo info(strFilePath);
	if (info.isFile())
	{
		return strFilePath;
	}

	strFilePath = "";
	int i = 0;
	while (i++ < 3)
	{
		strFilePath = ZcloudComFun::downloadIconFromUrl(strUrl, strDirPath);
		QFileInfo fileInfo(strFilePath);
		if (fileInfo.isFile())
		{
			break;
		}
	}
	QFileInfo fileInfo(strFilePath);
	if (!fileInfo.isFile())
	{
		return "";
	}
	return strFilePath;
}

void ZcloudComFun::setElideText(int nPixSize, QLabel* pLabel, const QString& strText)
{
	QFont font("Microsoft YaHei");
	font.setPixelSize(nPixSize);
	pLabel->setFont(font);
	QFontMetrics fontMetrics(pLabel->font());
	int fontSize = fontMetrics.width(strText);//��ȡ֮ǰ���õ��ַ��������ش�С
	QString strElideText;
	if (fontSize > pLabel->width())
	{
		strElideText = fontMetrics.elidedText(strText, Qt::ElideRight, pLabel->width());//����һ������ʡ�Ժŵ��ַ���
	}
	else
	{
		strElideText = strText;
	}
	strElideText = strElideText.simplified();
	pLabel->setText(strElideText);
}

void ZcloudComFun::LoadAvatar(const std::string &strAvatarUrl, QLabel* lable)
{
	QUrl url(QString().fromStdString(strAvatarUrl));
	QNetworkAccessManager manager;
	QEventLoop loop;

	QNetworkReply *reply = manager.get(QNetworkRequest(url));
	QObject::connect(reply, &QNetworkReply::finished, &loop, [&reply, &lable, &loop](){
		if (reply->error() == QNetworkReply::NoError)
		{
			QByteArray jpegData = reply->readAll();
			QPixmap pixmap;
			pixmap.loadFromData(jpegData);
			if (!pixmap.isNull())
			{
				lable->clear();
				lable->setPixmap(pixmap);
				lable->setScaledContents(true);
			}
		}
		loop.quit();
	});

	loop.exec();
}

bool ZcloudComFun::isNetActiveByToken(QString strToken)
{
	QString strRet;
	QString strUrl = QString("/ucenter/general/ping");
	QString strPost = QString("token=%1").arg(strToken);

	return httpPost(strUrl, strToken, 15000, strRet,false,1);
}

QString ZcloudComFun::getRegditValue(QString key)
{
	QString strVer = ZcloudComFun::getFileVertion(QApplication::applicationFilePath());
	QString strRegPath = QString("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\ZcloudDesk\\NewsTip"));
	QSettings *settings = new QSettings(strRegPath, QSettings::NativeFormat);


	QString strvalue = settings->value(key);
	delete settings;
	settings = NULL;
	return strvalue;
}


void ZcloudComFun::writeRegdit(QString key, QString strvalue)
{
	QString strVer = ZcloudComFun::getFileVertion(QApplication::applicationFilePath());
	QString strRegPath = QString("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\ZcloudDesk\\NewsTip"));
	QSettings *settings = new QSettings(strRegPath, QSettings::NativeFormat);
	settings->setValue(key, strvalue);

	delete settings;
	settings = NULL;
}

////��ѯ�Ƿ������ҵ��Ҳ��������ע���˰�Ų�ѯ��̨��˾�Ƿ�ƥ��
bool ZcloudComFun::winHttpQueryCompanyInfoLocalTax(QString strTaxno, QString strToken, dbEntInfo& info)
{

	QString strUrl = QString("/ucenter/user/company-list");
	QString strPost;
	QString strRet;

	if (strTaxno.isEmpty())
		strPost = QString("token=%1").arg(strToken);
	else
		strPost = QString("tax=%1&token=%2").arg(strTaxno).arg(strToken);

	bool bret;
	bret = ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);




	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return false;
	}
	if (!parse_doucment.isObject())
	{
		return false;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("code").toInt();
	if (0 != status)
	{
		//switch (status)
		//{
		//case 20012:
		//	strMsg = QString::fromLocal8Bit("��ҵ��ַ����Ϊ��");
		//	break;
		//case 20013:
		//	strMsg = QString::fromLocal8Bit("��ҵ��ַ���벻��ȷ");
		//	break;
		//case 20027:
		//	strMsg = QString::fromLocal8Bit("�����ʺŲ���Ϊ��");
		//	break;
		//case 20028:
		//	strMsg = QString::fromLocal8Bit("�����ʺ��������Ͳ���ȷ");
		//	break;
		//case 20029:
		//	strMsg = QString::fromLocal8Bit("�����ʺ����볤�Ȳ���ȷ");
		//	break;
		//case 20030:
		//	strMsg = QString::fromLocal8Bit("�������в���Ϊ��");
		//	break;
		//case 20031:
		//	strMsg = QString::fromLocal8Bit("���������������Ͳ���ȷ");
		//	break;
		//case 20032:
		//	strMsg = QString::fromLocal8Bit("�绰����Ϊ��");
		//	break;
		//case 20033:
		//	strMsg = QString::fromLocal8Bit("�绰���Ȳ���ȷ");
		//	break;
		//default:
		//	break;
		//}


		info.strCompany = QString::fromLocal8Bit("��δ��ѯ��������ҵ");
		info.bloadDb = false;
		return false;
	}

	QJsonValue list = obj.take("data").toArray();


	if (!list.isArray())
	{
		return false;
	}
	QJsonArray listArray = list.toArray();
	int nSize = listArray.size();

	QString _strtaxno;
	int has_admin;
	QString roletype;
	for (int nIndex = 0; nIndex < nSize; ++nIndex)
	{
		QJsonObject dataList = listArray.at(nIndex).toObject();

		info.nIsjoin = dataList.take("is_join").toInt();
		roletype = dataList.take("role_type").toString();
		info.nroletype = roletype.toInt();
		info.strRoletype = info.nroletype == 1 ? QString::fromLocal8Bit("����Ա") : QString::fromLocal8Bit("����������Ա");
		info.strCompany = dataList.take("company_name").toString();
		_strtaxno = dataList.take("tax_number").toString();
		info.strTaxno = _strtaxno;
		info.strcompanyid = dataList.take("company_id").toString();
		info.nIsbind = dataList.take("is_bind_s").toInt();
		has_admin = dataList.take("has_admin").toInt();
		info.niscurrent = dataList.take("is_current").toInt();
		info.isbindEnt = has_admin == 1 ? true : false;
		info.bloadDb = true;
		////���˰���а���һ����ֱ�ӷ���
		if (strTaxno.contains(_strtaxno) && strTaxno.isEmpty() == false)
		{
			return true;
		}
	}
	info.nIsjoin = 0;
	info.nroletype = -1;
	info.nIsbind = 0;
	info.bloadDb = false;
	info.strCompany = QString::fromLocal8Bit("��δ��ѯ��������ҵ");
	return false;
}


//QString ZcloudComFun::getTaxnumber()
//{
//	QString strTaxno;
//	//!��ѯע����ȡ˰����Ϣ
//	QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
//	QStringList groupsList = settings->childGroups();
//	foreach(QString group, groupsList)
//	{
//		settings->beginGroup(group);
//		QString strCode = settings->value("code", QVariant()).toString();			//����ҵ˰��
//		strCode = strCode.replace(" ", "");
//		settings->endGroup();
//		if (!strCode.isEmpty())
//		{
//			if (!isTaxExistRegedit(strCode))
//			{
//				
//				strTaxno = strCode;
//				
//				
//			}
//		}
//	}
//	delete settings;
//	return strTaxno;
//}