#include "InvoiceCheckThread.h"
#include <QDataStream>
#include "ZcloudCommon.h"
#include "ZcloudDesk.h"

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
	//检测开票软件
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

			emit sendDownAndUpdate(softUrl);

			//必须在GUI线程操作界面
			////让用户确认是否安装开票软件
			//if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("检测到新的开票软件，是否更新？")) == QDialog::Accepted)
			//{
			//	//安装开票软件
			//	if (ZhicloudApp::openDownloadSoftware(0, softUrl) == QDialog::Accepted)
			//	{
			//		//安装成功重启软件
			//		//a.appDisConnect();
			//		QProcess::startDetached(qApp->applicationFilePath(), QStringList());
			//		//return 0;
			//	}
			//}
		}

	}
	isrunning = false;
}




