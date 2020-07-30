#ifndef PIPESERVERTHREAD_H
#define PIPESERVERTHREAD_H

#include <QThread>
#include <QEventLoop>
#include <QLocalServer>
#include <QLocalSocket>

class PipeServerThread : public QThread
{
	Q_OBJECT

public:
	PipeServerThread(QObject *parent=0);
	~PipeServerThread();

	void stopThread();

signals:
	//!������Ϣ��������ܵ���Ϣ //!nType 1��ť��� 2�鿴���� 3ͼƬ��Ϣ��� 4����
	void sigReciveMsgPopUp(QString);
protected:
	void run();

private slots:
	void onNewConnection();
	void onReadyRead();
	void onRemoveClients();
private:
	QEventLoop*		m_pEventLoop = NULL;
	QLocalServer*	m_pLocalServer = NULL;
	//QVector<QLocalSocket*>	m_vtrLocalSocket;
};

#endif // PIPESERVERTHREAD_H
