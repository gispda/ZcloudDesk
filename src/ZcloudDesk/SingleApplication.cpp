#include "SingleApplication.h"  
#include <QtNetwork/QLocalSocket>  
#include <QtNetwork/QLocalServer>  
#include <QFileInfo>  
#include <QTimer>

SingleApplication::SingleApplication(int &argc, char **argv)  
    : QApplication(argc, argv)  
	, bRunning(false)
	, bZyServerRuning(false)
    , localServer(NULL)  
    , mainWindow(NULL) 
{  
    // 取应用程序名作为LocalServer的名字  
    serverName = QFileInfo(QCoreApplication::applicationFilePath()).fileName();  
	if (argc == 2)
	{
		//如果是 服务启动主程序，则只启动 心跳
		QString zyServer = argv[1];
		if (zyServer == "1")
		{
			bZyServerRuning = true;
		}
	}
	initLocalConnection();  
}  
  
  
////////////////////////////////////////////////////////////////////////////////  
// 说明：  
// 检查是否已經有一个实例在运行, true - 有实例运行， false - 没有实例运行  
////////////////////////////////////////////////////////////////////////////////  
bool SingleApplication::isRunning()  
{  
    return bRunning;  
}  

////////////////////////////////////////////////////////////////////////////////  
// 说明：  
// 通过socket通讯实现程序单实例运行，监听到新的连接时触发该函数  
////////////////////////////////////////////////////////////////////////////////  
void SingleApplication::newLocalConnection()  
{  
    QLocalSocket *socket = localServer->nextPendingConnection();  
    if (!socket)  
        return;  
    socket->waitForReadyRead(1000);  
    QTextStream stream(socket);  
	QString     readMsg;
	// 读出数据
	readMsg = stream.readAll();
	if (readMsg != "1")
	{
		//如果之前是 服务启动的  则退出
		if (bZyServerRuning)
		{
			delete socket;
			this->exit(773);
			return;
		}

	}
    delete socket;  
	//如果是服务启动的  mainWindow == NULL
    if (mainWindow != NULL)  
    {  
		if (!mainWindow->isVisible())
		{
			QTimer::singleShot(3000, this, SLOT(showZCloudDesk()));

			//!登录动画待新的完成再放开
			//DlgWait dlgWait(QString::fromLocal8Bit("<html><head/><body><p><span style=\" color:#ffffff; \">   登录中...</span></p></body></html>"));
		}	
    }  
}  
  
void SingleApplication::showZCloudDesk()
{
	//激活窗口  
	mainWindow->raise();
	mainWindow->activateWindow();
	mainWindow->setWindowState((mainWindow->windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
	mainWindow->show();
}

SingleApplication * SingleApplication::instance()
{
	return (static_cast<SingleApplication *>(QCoreApplication::instance()));
}

////////////////////////////////////////////////////////////////////////////////  
// 说明：  
// 通过socket通讯实现程序单实例运行，  
// 初始化本地连接，如果连接不上server，则创建，否则退出  
////////////////////////////////////////////////////////////////////////////////  
void SingleApplication::initLocalConnection()  
{  
    bRunning = false;  
    QLocalSocket socket;  
    socket.connectToServer(serverName);  
    if(socket.waitForConnected(500))  
    {  
        bRunning = true;
        // 其他处理，如：将启动参数发送到服务端  
        QTextStream stream(&socket); 
        QStringList args = QCoreApplication::arguments();  
        if (args.count() > 1)  
            stream << args.at(1);  
        else  
            stream << QString();  
        stream.flush();  
        socket.waitForBytesWritten();  
  
        return;  
    }  
  
    //连接不上服务器，就创建一个  
    newLocalServer();  
}  
  
////////////////////////////////////////////////////////////////////////////////  
// 说明：  
// 创建LocalServer  
////////////////////////////////////////////////////////////////////////////////  
void SingleApplication::newLocalServer()  
{  
    localServer = new QLocalServer(this);  
    connect(localServer, SIGNAL(newConnection()), this, SLOT(newLocalConnection()));
    if(!localServer->listen(serverName))  
    {  
        // 此时监听失败，可能是程序崩溃时,残留进程服务导致的,移除之  
        if(localServer->serverError() == QAbstractSocket::AddressInUseError)  
        {  
            QLocalServer::removeServer(serverName); // <-- 重点  
            localServer->listen(serverName); // 再次监听  
        }  
    }  
}  

////////////////////////////////////////////////////////////////////////////////  
// 说明：  
// 断开链接 用于切换税号 重启 
////////////////////////////////////////////////////////////////////////////////  
void SingleApplication::appDisConnect()
{
	bRunning = false;
	if (localServer)
	{
		localServer->close();
		QLocalServer::removeServer(serverName);
	}
}
