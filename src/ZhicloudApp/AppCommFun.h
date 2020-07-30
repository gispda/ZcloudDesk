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
	QString m_strSoftName;          // �����
	QString m_strSoftVersion;       // ����汾��
	QString m_strInstallLocation;   // �����װĿ¼
	QString m_strPublisher;         // �����������
	QString m_strMainProPath;       // ��������������·��
	QString m_strUninstallPth;      // ж��exe��������·��
}SOFT_INFO;

enum ReturnStatusEnum
{
	MemoryRUNNING,	//��������    д  gracefulRun
	MemoryEXIT,		//�˳� ����   д  gracefulExit
	MemoryNOPASS,		//		     д loginNopass		
	MemoryUPDATE		//�˳� ������  д gracefulUpdate
};


class AppCommFun : public QObject
{
	Q_OBJECT

public:
	AppCommFun(QObject *parent);
	~AppCommFun();

	//���� ͼƬ
	static QString downloadIcon(QString url, QString id = "");
	//��������������µ�
	//��ѯ����Ƿ����   ���ڲ�ѯ�汾�Ƿ������£����·���true ��  ���뱾���Ƿ����    isHudgeHave �Ƿ��ж��������
	static bool isHaveNewVerson(AppDataInfo &pData, bool &isNew, bool isHudgeHave = true);
	static bool isSoftInstall(AppDataInfo* pAppInfo);
	//�汾ƥ��
	static bool CompareVersion(QString nowVerson, QString newVerson);
	static bool queryDeskTop(QString strAppName, QString& strInstallLoc);
	//!��ݷ�ʽ�ļ��Ƿ���ڣ�������ȫ·��
	static bool isLinkFileExsit(QString strExeLinkName, QString& strLinkFilePath);

	static QString getFileVertion(QString fullName);
	//��ȡ�Ѱ�װ��Ӧ��
	static void GetSoftInfo(QVector<SOFT_INFO> &softInfoList);
	//д�����ڴ� 
	static void sharedMemory(ReturnStatusEnum);
	//��ȡϵͳ
	static QString GetOs();
	static QString GetOsVer();
	 //!�õ����ص�ǰʱ��(t_)��ʱ�������ֵ(p_)
	static	QString  GetCurTimeFormLoc();
	//��ȡ������ϵͳʱ��
	static QDateTime getSystemTime();

	//��ȡ���� ����������ʡ�Ժ�
	static QString getElidedText(QString elidedStr, int fonSize);
private:
	static QFileInfoList GetFileList(QString path);
	static bool isLinkNameExsit(QString strDirName, QString strExeLinkName, QString& strLinkFilePath);
	//static vector<string> split_string(string &szInput, string &szToken);
	

};

//***************************************//
//���� �ȴ� c/s  Ӧ���˳����߳� 
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