#include "MsgRightWidget.h"
#include <QtWidgets/QApplication>
#include "MsgCenteredWidget.h"
#include "ServiceFeeWidget.h"
#include "MsgRightWidget.h"
#include "MsgDataBase.h"
#include "PicMsgWidget.h"
#include "CheckProcessThread.h"
#include "ActivityWidget.h"

//!��ʾ��ͨ��Ϣ���͵���
void DisplayNorMsg(const stMsgInfo& msgInfo)
{
	switch (msgInfo._nPosition)
	{
	case 1:
	{
		MsgRightWidget*  w = new MsgRightWidget(msgInfo);
		w->setAttribute(Qt::WA_QuitOnClose, true);
		w->showWindow();
		break;
	}
	case 2:
	{
		MsgCenteredWidget* w = new MsgCenteredWidget(msgInfo);
		w->setAttribute(Qt::WA_QuitOnClose, true);
		w->show();
		break;
	}
	default:
		break;
	}
}

//!��ʾ����ѵ����������͵���
void DisplayFeeMsg(const stMsgInfo& msgInfo)
{
	switch (msgInfo._nPosition)
	{
	case 1:
	{
		MsgRightWidget*  w = new MsgRightWidget(msgInfo);
		w->setAttribute(Qt::WA_QuitOnClose, true);
		w->showWindow();
		break;
	}
	case 2:
	{
		ServiceFeeWidget*  w = new ServiceFeeWidget(msgInfo);
		w->setAttribute(Qt::WA_QuitOnClose, true);
		w->show();
		break;
	}
	default:
		break;
	}
}

//!��ʾ��Ϣ��𴰿�
void DisplayMsgType(const stMsgInfo& msgInfo)
{
	switch (msgInfo._nMsgType)
	{
	case 1:
	{
		DisplayNorMsg(msgInfo);
		break;
	}
	case 2:
	{
		PicMsgWidget* w = new PicMsgWidget(msgInfo);
		w->setAttribute(Qt::WA_QuitOnClose, true);
		w->show();
		break;
	}
	case 3:
	{
		MsgRightWidget*  w = new MsgRightWidget(msgInfo);
		w->setAttribute(Qt::WA_QuitOnClose, true);
		w->showWindow();
		break;
	}
	case 4:
	{
		DisplayFeeMsg(msgInfo);
		break;
	}
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	if (argc != 7)
	{
		return 0;
	}
	QString strUid		= argv[1];
	QString strToken	= argv[2];
	QString strCompId	= argv[3];
	QString strMsg		= argv[4];
	QString strPicPath	= QString::fromLocal8Bit(argv[5]);
	QString	strType		= argv[6];
	a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
	QApplication::setApplicationDisplayName(QString::fromLocal8Bit("��Ϣ"));
	if (strType	==	"1")		//!��Ϣ
	{
		stMsgInfo	msgInfo;
		MsgDataBase::GetInstance()->queryMsgInfo(strUid, strToken, strCompId, strMsg, msgInfo);
		MsgDataBase::GetInstance()->DestoryInstance();
		DisplayMsgType(msgInfo);
	}
	else if (strType == "2")	//!�
	{
		ActivityWidget*	pWidget = new ActivityWidget(strUid, strToken, strCompId, strMsg, strPicPath);
		pWidget->setAttribute(Qt::WA_QuitOnClose, true);
		pWidget->show();
	}
	CheckProcessThread*	pThread = new CheckProcessThread;
	pThread->start();

	return a.exec();
}
