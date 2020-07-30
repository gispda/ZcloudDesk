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
	//!接受消息弹出程序管道信息 //!nType 1按钮点击 2查看更多 3图片消息点击 4活动点击
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
