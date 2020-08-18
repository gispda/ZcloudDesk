#include "InvoiceCheckThread.h"
#include <QDataStream>
#include "ZcloudCommon.h"
#include "ZcloudDesk.h"
#include "HttpInterface.h"

InvoiceCheckThread::InvoiceCheckThread(UserInfoStruct*	stUserInfo,QObject *parent)
	: QThread(parent), m_stUserInfo(stUserInfo)
{
}

InvoiceCheckThread::~InvoiceCheckThread()
{
	m_stUserInfo = NULL;
}

void InvoiceCheckThread::run()
{
	isrunning = true;
	sleep(10);
	//检查客户端版本
	bool checkedClient = false;
	bool checkedInvoice = false;
	QString strDownloadUrl, strMd5;
	CheckUpdater updater;
	checkedClient = updater.checkUpdater(m_stUserInfo->m_strUserId, m_stUserInfo->m_strToken);
	//checkedClient = true;

	//检测开票软件版本
	QString softUrl;
	//获得软件ID 8888
	QString softVersion = this->m_stUserInfo->m_strHzsId;
	//获得软件版本
	bool rst = ZcloudComFun::getSoftwareData(softUrl, softVersion);
	QString strVerSion = "";
	//bool need_install = true;
	if (ZcloudDesk::readRegInfo(strVerSion, m_stUserInfo->m_strTaxNumber))
	{
		
		int ret = CompareVersion(strVerSion, softVersion);
		if (ret < 0)
		{
			checkedInvoice = true;
		}

	}
	//checkedInvoice = true;
	QString url;
	CheckUpdater* updateObj=NULL;
	if (checkedClient){
		updateObj=&updater;
	}
	if (!checkedInvoice){
		softUrl = "";
	}
	emit sendDownAndUpdate(softUrl, updateObj);

	isrunning = false;
}





int InvoiceCheckThread::CompareVersion(QString nowVerson, QString newVerson)
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


vector<string> InvoiceCheckThread::split_string(string &szInput, string &szToken)
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