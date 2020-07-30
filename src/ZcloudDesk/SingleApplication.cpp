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
    // ȡӦ�ó�������ΪLocalServer������  
    serverName = QFileInfo(QCoreApplication::applicationFilePath()).fileName();  
	if (argc == 2)
	{
		//����� ����������������ֻ���� ����
		QString zyServer = argv[1];
		if (zyServer == "1")
		{
			bZyServerRuning = true;
		}
	}
	initLocalConnection();  
}  
  
  
////////////////////////////////////////////////////////////////////////////////  
// ˵����  
// ����Ƿ��ѽ���һ��ʵ��������, true - ��ʵ�����У� false - û��ʵ������  
////////////////////////////////////////////////////////////////////////////////  
bool SingleApplication::isRunning()  
{  
    return bRunning;  
}  

////////////////////////////////////////////////////////////////////////////////  
// ˵����  
// ͨ��socketͨѶʵ�ֳ���ʵ�����У��������µ�����ʱ�����ú���  
////////////////////////////////////////////////////////////////////////////////  
void SingleApplication::newLocalConnection()  
{  
    QLocalSocket *socket = localServer->nextPendingConnection();  
    if (!socket)  
        return;  
    socket->waitForReadyRead(1000);  
    QTextStream stream(socket);  
	QString     readMsg;
	// ��������
	readMsg = stream.readAll();
	if (readMsg != "1")
	{
		//���֮ǰ�� ����������  ���˳�
		if (bZyServerRuning)
		{
			delete socket;
			this->exit(773);
			return;
		}

	}
    delete socket;  
	//����Ƿ���������  mainWindow == NULL
    if (mainWindow != NULL)  
    {  
		if (!mainWindow->isVisible())
		{
			QTimer::singleShot(3000, this, SLOT(showZCloudDesk()));

			//!��¼�������µ�����ٷſ�
			//DlgWait dlgWait(QString::fromLocal8Bit("<html><head/><body><p><span style=\" color:#ffffff; \">   ��¼��...</span></p></body></html>"));
		}	
    }  
}  
  
void SingleApplication::showZCloudDesk()
{
	//�����  
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
// ˵����  
// ͨ��socketͨѶʵ�ֳ���ʵ�����У�  
// ��ʼ���������ӣ�������Ӳ���server���򴴽��������˳�  
////////////////////////////////////////////////////////////////////////////////  
void SingleApplication::initLocalConnection()  
{  
    bRunning = false;  
    QLocalSocket socket;  
    socket.connectToServer(serverName);  
    if(socket.waitForConnected(500))  
    {  
        bRunning = true;
        // ���������磺�������������͵������  
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
  
    //���Ӳ��Ϸ��������ʹ���һ��  
    newLocalServer();  
}  
  
////////////////////////////////////////////////////////////////////////////////  
// ˵����  
// ����LocalServer  
////////////////////////////////////////////////////////////////////////////////  
void SingleApplication::newLocalServer()  
{  
    localServer = new QLocalServer(this);  
    connect(localServer, SIGNAL(newConnection()), this, SLOT(newLocalConnection()));
    if(!localServer->listen(serverName))  
    {  
        // ��ʱ����ʧ�ܣ������ǳ������ʱ,�������̷����µ�,�Ƴ�֮  
        if(localServer->serverError() == QAbstractSocket::AddressInUseError)  
        {  
            QLocalServer::removeServer(serverName); // <-- �ص�  
            localServer->listen(serverName); // �ٴμ���  
        }  
    }  
}  

////////////////////////////////////////////////////////////////////////////////  
// ˵����  
// �Ͽ����� �����л�˰�� ���� 
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
