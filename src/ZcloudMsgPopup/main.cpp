#include "MsgRightWidget.h"
#include <QtWidgets/QApplication>
#include "MsgCenteredWidget.h"
#include "ServiceFeeWidget.h"
#include "MsgRightWidget.h"
#include "MsgDataBase.h"
#include "PicMsgWidget.h"
#include "CheckProcessThread.h"
#include "ActivityWidget.h"

//!显示普通消息类型弹窗
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

//!显示服务费到期提醒类型弹窗
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

//!显示消息类别窗口
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
	QApplication::setApplicationDisplayName(QString::fromLocal8Bit("消息"));
	if (strType	==	"1")		//!消息
	{
		stMsgInfo	msgInfo;
		MsgDataBase::GetInstance()->queryMsgInfo(strUid, strToken, strCompId, strMsg, msgInfo);
		MsgDataBase::GetInstance()->DestoryInstance();
		DisplayMsgType(msgInfo);
	}
	else if (strType == "2")	//!活动
	{
		ActivityWidget*	pWidget = new ActivityWidget(strUid, strToken, strCompId, strMsg, strPicPath);
		pWidget->setAttribute(Qt::WA_QuitOnClose, true);
		pWidget->show();
	}
	CheckProcessThread*	pThread = new CheckProcessThread;
	pThread->start();

	return a.exec();
}
