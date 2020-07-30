#pragma once
#ifndef APPCOMMFUN_H
#define APPCOMMFUN_H
#include <QObject>
#include "ZhicloudAppDataDefine.h"
#include <QFileInfoList>
#include <QThread>
#include <QProcess>

typedef struct _SoftInfo
{
	QString m_strSoftName;          // 软件名
	QString m_strSoftVersion;       // 软件版本号
	QString m_strInstallLocation;   // 软件安装目录
	QString m_strPublisher;         // 软件发布厂商
	QString m_strMainProPath;       // 主程序所在完整路径
	QString m_strUninstallPth;      // 卸载exe所在完整路径
}SOFT_INFO;

enum ReturnStatusEnum
{
	MemoryRUNNING,	//正在运行    写  gracefulRun
	MemoryEXIT,		//退出 重启   写  gracefulExit
	MemoryNOPASS,		//		     写 loginNopass		
	MemoryUPDATE		//退出 不重启  写 gracefulUpdate
};


class AppCommFun : public QObject
{
	Q_OBJECT

public:
	AppCommFun(QObject *parent);
	~AppCommFun();

	//下载 图片
	static QString downloadIcon(QString url, QString id = "");
	//软件存在且是最新的
	//查询软件是否存在   存在查询版本是否是最新（最新返回true ）  传入本地是否存在    isHudgeHave 是否判定软件存在
	static bool isHaveNewVerson(AppDataInfo &pData, bool &isNew, bool isHudgeHave = true);
	static bool isSoftInstall(AppDataInfo* pAppInfo);
	//版本匹配
	static bool CompareVersion(QString nowVerson, QString newVerson);
	static bool queryDeskTop(QString strAppName, QString& strInstallLoc);
	//!快捷方式文件是否存在，并返回全路径
	static bool isLinkFileExsit(QString strExeLinkName, QString& strLinkFilePath);

	static QString getFileVertion(QString fullName);
	//获取已安装的应用
	static void GetSoftInfo(QVector<SOFT_INFO> &softInfoList);
	//写共享内存 
	static void sharedMemory(ReturnStatusEnum);
	//获取系统
	static QString GetOs();
	static QString GetOsVer();
	 //!得到本地当前时间(t_)和时间相关数值(p_)
	static	QString  GetCurTimeFormLoc();
	//获取服务器系统时间
	static QDateTime getSystemTime();

	//获取字体 超出部分用省略号
	static QString getElidedText(QString elidedStr, int fonSize);
private:
	static QFileInfoList GetFileList(QString path);
	static bool isLinkNameExsit(QString strDirName, QString strExeLinkName, QString& strLinkFilePath);
	//static vector<string> split_string(string &szInput, string &szToken);
	

};

//***************************************//
//用于 等待 c/s  应用退出的线程 
//***************************************//
class CsOpenReturnThread : public QThread
{
public:
	CsOpenReturnThread(QString filePath, QString classId, QString appId, QString appVersion, QObject *parent = 0);
	~CsOpenReturnThread();
	void setWorkPath(QString wordPath);
	void setParams(QStringList strParamList);
protected:
	void run();
private:
	QString m_filePath;
	QString m_classId;
	QString m_appId;
	QString m_appVersion;
	QStringList	m_strParamList;
	bool m_isHaveParameter;


private:
	QProcess *m_process;
};

#endif // APPCOMMFUN_H