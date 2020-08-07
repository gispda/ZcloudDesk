#pragma once

#include <QObject>
#include <QReadWriteLock>
#include <QSqlDatabase>
#include <QDateTime>
class WorkerInfo
{
public:

	QString strWorkerid;
	QString strAcceptid;
	QString strCompanyid;
	QString strUid;

	int iLevel;
	QString strWorkertitle;
	int iState;
	bool bIsread;
	QString strStatedesc;
	QString strLeveldesc;

	
	QDateTime	_dtCreateTime;

	WorkerInfo operator=(const WorkerInfo& _info)
	{
		this->bIsread = _info.bIsread;
		this->iLevel = _info.iLevel;
		this->iState = _info.iState;
		this->strAcceptid = _info.strAcceptid;
		this->strCompanyid = _info.strCompanyid;
		this->strLeveldesc = _info.strLeveldesc;
		this->strStatedesc = _info.strStatedesc;
		this->strUid = _info.strUid;
		this->strWorkerid = _info.strWorkerid;
		this->strWorkertitle = _info.strWorkertitle;
		this->_dtCreateTime = _info._dtCreateTime;
		return *this;
	}
};

class WorkerStarInfo
{
public:
	int iStarlevel;
	QString strStarname;
	int iStarscore;
	QStringList strStarlabel;

public:

};
//class WorkerDataBase : public QObject
//{
//	Q_OBJECT
//
//public:
//	~WorkerDataBase();
//
//	static WorkerDataBase *GetInstance();
//	static void DestoryInstance();
//
//	//!������ҵ��Ϣ
//	bool insertWorkerInfo(const WorkerInfo& workerInfo);
//
//	//!��ѯ��ҵ��Ϣ
//	bool queryWorkInfo(QString strUid, WorkerInfo& workerInfo);
//
//private:
//	//!�ж����ݿ���Ƿ����
//	bool isTableExist(QString strTableName);
//
//	//�����ݿ�
//	bool openWorkerDatabase();
//
//	//!������ݿⲻ�����򴴽�
//	bool CreateDB(QString strPath);
//
//	explicit WorkerDataBase(QObject *parent = 0);
//
//	QReadWriteLock		m_ReadWriteLock;
//	QSqlDatabase		m_DataBase;
//	static WorkerDataBase*	m_pDbInstance;
//};
