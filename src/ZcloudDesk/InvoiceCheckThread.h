#ifndef InvoiceCheckTHREAD_H
#define InvoiceCheckTHREAD_H

#include <QThread>
#include <QEventLoop>
#include <QLocalServer>
#include <QLocalSocket>
#include "Database.h"

#include "CheckUpdater.h"
class InvoiceCheckThread : public QThread
{
	Q_OBJECT

public:
	InvoiceCheckThread(UserInfoStruct*	m_stUserInfo,QObject *parent = 0);
	~InvoiceCheckThread();
	bool isrunning;

	int CompareVersion(QString nowVerson, QString newVerson);

	vector<string> split_string(string &szInput, string &szToken);

signals:
	void sendDownAndUpdate(QString url, CheckUpdater* obj);
	
protected:
	void run();

private:
	//QEventLoop*		m_pEventLoop = NULL;
	//QLocalServer*	m_pLocalServer = NULL;
	//QVector<QLocalSocket*>	m_vtrLocalSocket;

	UserInfoStruct*			m_stUserInfo;
};

#endif // InvoiceCheckTHREAD_H
