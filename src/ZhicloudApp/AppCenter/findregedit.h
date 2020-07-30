#ifndef FINDREGEDIT_H
#define FINDREGEDIT_H

#include <QThread>
#include "ZhicloudAppDataDefine.h"
#include <qt_windows.h>

class FindRegedit : public QThread
{
	Q_OBJECT

public:
	FindRegedit(QObject *parent, AppDataInfo*	pData, int model);
	~FindRegedit();
	void findPath(bool &isHave);
private:
	QString m_fileName;
	AppDataInfo*	m_pData;
	int m_model;//0-安装查询 1-卸载查询
signals:
	void installationCompleteSiganl(QString, AppDataInfo*);
	void uninstallationCompleteSiganl(AppDataInfo*);
protected:
	void run();
	
};


class UnInstallThread : public QThread
{
	Q_OBJECT

public:
	UnInstallThread(AppDataInfo	pData, QObject *parent = NULL);
	~UnInstallThread();
	bool isHaveUninstall(QString appId);
private:
	AppDataInfo	m_pData;
	HWND GetProcessID(LPCWSTR procName);//procName 被调用进程名称
	void findTemporary(QString fileMd5);
	QString getFileMd5(QString fileNamePath);
signals:
	void uninstallationCompleteSiganl(AppDataInfo, bool);
	void removeUninstallThread();
protected:
	void run();

};


//查找 cs应用的执行 路径
class FindAppPath : public QThread
{
	Q_OBJECT

public:
	FindAppPath(QObject *parent = NULL);
	~FindAppPath();
	bool m_runReturn = false;
	//void setUserId(QString strUserId)
	//{
	//	this->m_userId = strUserId;
	//};
protected:
	void run();
private:
	QString m_userId;
signals:
	void filishFindAppPathSignal();

};


#endif // FINDREGEDIT_H
