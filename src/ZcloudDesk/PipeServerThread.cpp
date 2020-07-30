#include "PipeServerThread.h"
#include <QDataStream>
PipeServerThread::PipeServerThread(QObject *parent)
	: QThread(parent)
{
}

PipeServerThread::~PipeServerThread()
{
	if (NULL	!=	m_pEventLoop)
	{
		m_pEventLoop->deleteLater();
		m_pEventLoop = NULL;
	}

	if (NULL != m_pLocalServer)
	{
		m_pLocalServer->deleteLater();
		m_pLocalServer = NULL;
	}

	/*for (QVector<QLocalSocket*>::iterator i = m_vtrLocalSocket.begin(); i != m_vtrLocalSocket.end();i++)
	{
		QLocalSocket*	pLocalSocket = *i;
		if (NULL != pLocalSocket)
		{
			pLocalSocket->deleteLater();
			pLocalSocket = NULL;
		}
	}
	m_vtrLocalSocket.clear();*/
}

void PipeServerThread::run()
{
	m_pEventLoop = new QEventLoop;
	m_pLocalServer = new QLocalServer;
	connect(m_pLocalServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()), Qt::DirectConnection);
	bool bOk = false;
	do 
	{
		QLocalServer::removeServer("ZcloudMsgNamePipe");
		bOk = m_pLocalServer->listen("ZcloudMsgNamePipe");
	} while (!bOk);
	m_pEventLoop->exec();
}

void PipeServerThread::onNewConnection()
{
	QLocalSocket* pLocalSocket = m_pLocalServer->nextPendingConnection();
	connect(pLocalSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead())/*, Qt::DirectConnection*/);
	connect(pLocalSocket, SIGNAL(disconnected()), pLocalSocket, SLOT(deleteLater()/*onRemoveClients()*/));
	//m_vtrLocalSocket.push_back(pLocalSocket);
}

void PipeServerThread::onReadyRead()
{
	/*for (QVector<QLocalSocket*>::iterator i = m_vtrLocalSocket.begin(); i != m_vtrLocalSocket.end();i++)
	{
	QLocalSocket*	pLocalSocket = *i;
	if (pLocalSocket)
	{
	QDataStream tempReadDataStream(pLocalSocket);
	QString strText;
	tempReadDataStream >> strText;

	if (!strText.isEmpty())
	{
	emit sigReciveMsgPopUp(strText);
	}
	}
	}*/
	QLocalSocket*	pLocalSocket = static_cast<QLocalSocket*>(sender());
	if (pLocalSocket)
	{
		QDataStream tempReadDataStream(pLocalSocket);
		QString strText;
		tempReadDataStream >> strText;

		if (!strText.isEmpty())
		{
			emit sigReciveMsgPopUp(strText);
		}
	}
	
}

void PipeServerThread::stopThread()
{
	m_pEventLoop->quit();
}

void PipeServerThread::onRemoveClients()
{
	/*for (QVector<QLocalSocket*>::iterator i = m_vtrLocalSocket.begin(); i != m_vtrLocalSocket.end();)
	{
		QLocalSocket*	pLocalSocket = *i;
		if (pLocalSocket->state() != QLocalSocket::ConnectedState) 
		{
			i = m_vtrLocalSocket.erase(i);
			pLocalSocket->deleteLater();
			pLocalSocket = NULL;
		}
		else 
		{
			i++;
		}
	}*/
}
