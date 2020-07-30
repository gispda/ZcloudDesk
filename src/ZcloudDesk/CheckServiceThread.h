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
	//!税号上报
	void submitTaxs();

	//!启动或者停止服务
	void OperService(bool bStart);

	//!上传文件到七牛
	void uploadFileToQiniu(QString strLocalFile);

	//!上传桌面软件信息
	void submitDeskApp();

	bool		m_bBreak;
	QMutex		m_mutex;
	QString		m_strUid;
	QString     m_strToken;
	QString     m_strHzsId;
};
