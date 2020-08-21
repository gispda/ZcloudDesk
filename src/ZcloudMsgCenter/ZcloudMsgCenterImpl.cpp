#include "ZcloudMsgCenterImpl.h"
#include "MsgDataBase.h"
#include <QProcess>
#include <QStringList>
ZcloudMsgCenterImpl::ZcloudMsgCenterImpl()
{
}

ZcloudMsgCenterImpl::~ZcloudMsgCenterImpl()
{
	stopMsgThread();
	closeAllMsgWidget();
	MsgDataBase::DestoryInstance();
}

ZcloudMsgCenter * ZcloudMsgCenter::createNew()
{
	return new ZcloudMsgCenterImpl();
}

void ZcloudMsgCenterImpl::destroy()
{
	delete this;
}

void ZcloudMsgCenterImpl::openMsgCenter(int nUnread)
{
	if (NULL == m_pMsgCenterWidget)
	{
		m_pMsgCenterWidget = new MsgCenterWidget;	
		connect(m_pMsgCenterWidget, SIGNAL(sigReduceUnreadNum(int)), this, SIGNAL(sigReduceUnreadNum(int)));
		connect(m_pMsgCenterWidget, SIGNAL(sigSendMessageRespone(QString)), this, SIGNAL(sigSendMessageRespone(QString)));
	}
	m_pMsgCenterWidget->setUnreadMsgCount(nUnread);
	m_pMsgCenterWidget->setAllMsg();
	m_pMsgCenterWidget->showWindow();
}

void ZcloudMsgCenterImpl::stopPopupProcess()
{
	QProcess p;
	QString c = "taskkill /im ZcloudMsgPopup.exe /f";
	p.execute(c);
	p.close();
}

void ZcloudMsgCenterImpl::reviceMsgInfo(QStringList strParamList, int nCount)
{
	emit changeUnreadMsgNum(MsgDataBase::GetInstance()->countUnreadMsg(), false);
	strParamList.append("1");
	QString strPopupPath = QApplication::applicationDirPath().append("/ZcloudMsgPopup.exe");
	if (!QFile::exists(strPopupPath))
	{
		//qDebug() << "zcd-0x10000012:msg \"ZcloudMsgPopup.exe\" not exist!";
		return;
	}
	strPopupPath = "\"" + strPopupPath + "\"";
	QProcess::startDetached(strPopupPath, strParamList);
}

void ZcloudMsgCenterImpl::closeAllMsgWidget()
{
	if (NULL != m_pMsgCenterWidget)
	{
		m_pMsgCenterWidget->deleteLater();
		m_pMsgCenterWidget = NULL;
	}
	stopPopupProcess();
}

void ZcloudMsgCenterImpl::setUserData(QString strUid, QString strToken, QString strCompId, bool bSetThread)
{
	MsgDataBase::GetInstance()->setUserData(strUid, strToken,strCompId);

	int nCount = MsgDataBase::GetInstance()->countUnreadMsg();
	emit changeUnreadMsgNum(nCount,false);

	/*if (!bSetThread)
	{
		m_pZcloudMsgThread->setUserData(strUid, strToken);
	}*/
}

void ZcloudMsgCenterImpl::startMsgThread(QString strUid, QString strToken, QString strCompId)
{
	if (NULL == m_pZcloudMsgThread)
	{
		m_pZcloudMsgThread = new ZcloudMsgThread(this);
		connect(m_pZcloudMsgThread, SIGNAL(sendMsgInfo(QStringList, int)), this, SLOT(reviceMsgInfo(QStringList, int)));
		connect(m_pZcloudMsgThread, SIGNAL(sendActivityInfo(QStringList)), this, SLOT(reviceActivityInfo(QStringList)));
		connect(m_pZcloudMsgThread, SIGNAL(checkTokenFailed(int)), this, SIGNAL(checkTokenFailed(int)));
	}
	m_pZcloudMsgThread->setUserData(strUid, strToken,strCompId);
	m_pZcloudMsgThread->start();
}

void ZcloudMsgCenterImpl::reviceActivityInfo(QStringList strParamList)
{
	//!结束上一个活动提示
	if (NULL != m_processActivity)
	{
		if (m_processActivity->state() == QProcess::Starting || m_processActivity->state() == QProcess::Running)
		{
			m_processActivity->close();
		}
		m_processActivity->deleteLater();
		m_processActivity = NULL;
	}
	
	if (NULL == m_processActivity)
	{
		//!开启新的活动提示
		strParamList.append("2");
		QString strPopupPath = QApplication::applicationDirPath().append("/ZcloudMsgPopup.exe");
		if (!QFile::exists(strPopupPath))
		{
			//qDebug() << "zcd-0x10000013:activity \"ZcloudMsgPopup.exe\" not exist!";
			return;
		}
		strPopupPath = "\"" + strPopupPath + "\"";
		m_processActivity = new QProcess(this);
		m_processActivity->start(strPopupPath, strParamList);
		m_processActivity->waitForStarted();
	}	
}

void ZcloudMsgCenterImpl::stopMsgThread()
{
	if (NULL != m_pZcloudMsgThread)
	{
		if (m_pZcloudMsgThread->isRunning())
		{
			m_pZcloudMsgThread->stopImmediately();
			m_pZcloudMsgThread->wait();
			m_pZcloudMsgThread->deleteLater();
			m_pZcloudMsgThread = NULL;
		}
	}
}

void ZcloudMsgCenterImpl::reportMsgInfo(QString strUid, QString strMsgId, QString strCompId)
{
	MsgDataBase::GetInstance()->changeMsgState(strMsgId, strUid, strCompId);
}

bool ZcloudMsgCenterImpl::msgCenterShow()
{
	if (NULL == m_pMsgCenterWidget)
	{
		return false;
	}
	return m_pMsgCenterWidget->isVisible();
}

void ZcloudMsgCenterImpl::refreshMsgCenter(int nUnread)
{
	m_pMsgCenterWidget->setUnreadMsgCount(nUnread);
	m_pMsgCenterWidget->setAllMsg();
}

void ZcloudMsgCenterImpl::openAssignMsgCenter(int nUnread, QString strMsgId)
{
	if (!msgCenterShow())
	{
		openMsgCenter(nUnread);
	}
	m_pMsgCenterWidget->openAssignMsg(strMsgId);
}

void ZcloudMsgCenterImpl::reduceUnreadNum()
{
	if (msgCenterShow())
	{
		m_pMsgCenterWidget->reduceUnreadNum();
	}
}
