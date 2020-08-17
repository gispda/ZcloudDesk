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
	//��⿪Ʊ���
	QString softUrl;
	//������ID 8888
	QString softVersion = this->m_stUserInfo->m_strHzsId;
	//�������汾
	bool rst = ZcloudComFun::getSoftwareData(softUrl, softVersion);
	QString strVerSion = "";
	//bool need_install = true;
	if (ZcloudDesk::readRegInfo(strVerSion, m_stUserInfo->m_strTaxNumber))
	{
		if (!strVerSion.isEmpty() && strVerSion != softVersion){

			emit sendDownAndUpdate(softUrl);

			//������GUI�̲߳�������
			////���û�ȷ���Ƿ�װ��Ʊ���
			//if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��⵽�µĿ�Ʊ������Ƿ���£�")) == QDialog::Accepted)
			//{
			//	//��װ��Ʊ���
			//	if (ZhicloudApp::openDownloadSoftware(0, softUrl) == QDialog::Accepted)
			//	{
			//		//��װ�ɹ��������
			//		//a.appDisConnect();
			//		QProcess::startDetached(qApp->applicationFilePath(), QStringList());
			//		//return 0;
			//	}
			//}
		}

	}
	isrunning = false;
}




