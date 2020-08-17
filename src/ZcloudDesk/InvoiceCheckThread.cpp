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
	checkedClient = true;

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
		if (!strVerSion.isEmpty() && strVerSion != softVersion){
			checkedInvoice = true;

		}
	}
	checkedInvoice = true;
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




