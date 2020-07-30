#include "CheckUpdater.h"
#include "HttpInterface.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QApplication>
#include <QFile>
#include <QProcess>
#include <QStringList>
#include "ZcloudCommon.h"
#include <qt_windows.h>


CheckUpdater::CheckUpdater(QObject *parent)
	: QObject(parent)
{
}

CheckUpdater::~CheckUpdater()
{
}

bool CheckUpdater::checkUpdater(QString strUid, QString strToken)
{
	HttpInterface sInter;
	QString    strRet;
	if (sInter.winHttpGetYcsSoftware(strUid, strToken, strRet))
	{
		QByteArray byte_array = strRet.toUtf8();
		QJsonParseError json_error;
		QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
		if (json_error.error != QJsonParseError::NoError)
			return false;

		if (!parse_doucment.isObject())
			return false;

		QJsonObject obj = parse_doucment.object();

		int code = obj.take("status").toInt();
		if (code != 0)
			return false;

		QJsonObject  data		= obj.take("data").toObject();
		QString strVerNum		= data.take("version_number").toString();
		m_strDownloadUrl		= data.take("download_url").toString();
		QString strTitle		= data.take("version_title").toString();
		QString strDesc			= data.take("version_desc").toString();
		m_strMd5				= data.take("md5").toString();

		//!检查版本更新
		return CheckUpdaterVer(strVerNum);
	}
	return false;
}

bool CheckUpdater::CheckUpdaterVer(QString strVerNum)
{
	QString mainverResult = ZcloudComFun::getFileVertion(QApplication::applicationFilePath());
	if (mainverResult.isEmpty()) return true;

	int ret = CompareVersion(mainverResult, strVerNum);
	if (ret < 0)
	{
		return true;
	}
	return false;
}

int CheckUpdater::CompareVersion(QString nowVerson, QString newVerson)
{
	std::string szLoc = nowVerson.toLatin1().data();
	std::string szSvr = newVerson.toLocal8Bit().data();
	//!旧版本号
	std::vector<std::string> locVerFields = split_string(szLoc, std::string("."));
	std::vector<std::string> srvVerFields = split_string(szSvr, std::string("."));

	int loc_size = locVerFields.size();
	int srv_size = srvVerFields.size();

	int pSize = loc_size >= srv_size ? srv_size : loc_size;

	int retval = 0;
	int i = 0;
	for (; i < pSize; i++)
	{
		int istrcmp = 0;
		int nLocVer = atoi(locVerFields[i].c_str());
		int nSrvVer = atoi(srvVerFields[i].c_str());
		if (nLocVer == nSrvVer)
		{
			istrcmp = 0;
		}
		else if (nLocVer < nSrvVer)
		{
			istrcmp = -1;
		}
		else
		{
			istrcmp = 1;
		}
		if (istrcmp == 0)
		{
			if (i == pSize - 1)//最后一个  
			{
				retval = 0;
				break;
				//return 0;  
			}
		}
		else if (istrcmp == 1)
		{
			retval = 1;
			break;
			//return 1;  
		}
		else if (istrcmp < 0)
		{
			retval = -1;
			break;
			//return -1;  
		}
	}
	return retval;
}

vector<string> CheckUpdater::split_string(string &szInput, string &szToken)
{
	vector<string> result;
	int pos = 0;
	int begin = 0;
	const int size = szToken.size();
	while (true)
	{
		pos = szInput.find(szToken, begin);
		if (pos == string::npos)
		{
			result.push_back(szInput.substr(begin));
			break;
		}
		result.push_back(szInput.substr(begin, pos - begin));
		begin = pos + size;
	}
	return result;
}

void CheckUpdater::startUpdaterProcess(bool bSlience)
{
	QProcess p;
	QString c = "taskkill /im ZcloudDesk Updater.exe /f";
	p.execute(c);
	p.close();
	::Sleep(500);

	QStringList strParamList;
	strParamList<<m_strDownloadUrl<<m_strMd5<<(bSlience ? "0" : "1");
	QString strPopupPath = QApplication::applicationDirPath().append("/ZcloudDesk Updater.exe");
	if (!QFile::exists(strPopupPath))
	{
		qDebug("zcd-0x10000003:\"ZcloudDesk Updater.exe\" not exist!");
		return;
	}
	strPopupPath = "\"" + strPopupPath + "\"";
	QProcess::startDetached(strPopupPath, strParamList);
}
