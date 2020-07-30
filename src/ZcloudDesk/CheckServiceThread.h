#pragma once
#include <QThread>
#include <string>
using namespace std;
class CheckServiceThread : public QThread
{
	Q_OBJECT

public:
	CheckServiceThread(QString strUid,QString strToken,QString strHzsId,QObject *parent=0);
	~CheckServiceThread();

	void stopImmediately();

protected:
	void run();

private:
	//!˰���ϱ�
	void submitTaxs();

	//!��������ֹͣ����
	void OperService(bool bStart);

	//!�ϴ��ļ�����ţ
	void uploadFileToQiniu(QString strLocalFile);

	//!�ϴ����������Ϣ
	void submitDeskApp();

	bool		m_bBreak;
	QMutex		m_mutex;
	QString		m_strUid;
	QString     m_strToken;
	QString     m_strHzsId;
};
