#include "NamePipeClinet.h"
#include <QDataStream>
#include <QApplication>

NamePipeClinet::NamePipeClinet(QObject *parent)
	: QObject(parent)
{
	m_pLocalSocket = new QLocalSocket();
	connect(m_pLocalSocket, SIGNAL(connected()), this, SLOT(onConnected()));
	connect(m_pLocalSocket, SIGNAL(disconnected()), this, SLOT(onDisConnected()));
	connect(m_pLocalSocket, SIGNAL(error(QLocalSocket::LocalSocketError)), this, SLOT(onSocketError(QLocalSocket::LocalSocketError)));
}

NamePipeClinet::~NamePipeClinet()
{
	if (NULL != m_pLocalSocket)
	{
		m_pLocalSocket->disconnectFromServer();
		delete m_pLocalSocket;
		m_pLocalSocket = NULL;
	}
}

void NamePipeClinet::onConnected()
{
	qDebug() << "connected sucess";
}

void NamePipeClinet::onDisConnected()
{
	qDebug() << "connected failed";
	QApplication::exit(0);
}

void NamePipeClinet::onSocketError(QLocalSocket::LocalSocketError error) 
{
	qWarning() << error;
}

bool NamePipeClinet::connectToServer(const QString &strServerName)
{
	m_pLocalSocket->connectToServer(strServerName);
	if (!m_pLocalSocket->waitForConnected(1000))
	{
		qDebug() << "waitForConnected return false";
		return false;
	}
	return true;
}

void NamePipeClinet::sendMessage(int nResType, QString strUid, QString strToken, QString strCompId, QString strMsgId, QString strBtnId, int nBtnType, QString strBtnTarget, bool bRead, bool bFromPopUp)
{
	QStringList strTextList;
	strTextList << QString::number(nResType) << strUid << strToken << strCompId << strMsgId << strBtnId << QString::number(nBtnType) << strBtnTarget << QString::number(bRead) << QString::number(bFromPopUp);
	QString strText	=	strTextList.join("+");

	QDataStream tempWriteDataStream(m_pLocalSocket);
	tempWriteDataStream << strText;

	m_pLocalSocket->waitForBytesWritten();
	m_pLocalSocket->flush();	
}
