#include <QtCore/QCoreApplication>
#include <QFile>
#include "Database.h"

void synchronizeDB()
{
	//����ǰ�汾��zhicloud.db�ļ���ʧ�ܻ�����Ϣ���ı�����
	if (!Database::GetInstance()->openOldDataBase())
	{
		return ;
	}

	//!�򿪵�ǰ�汾zhicloudMsg.dbʧ��
	if (!Database::GetInstance()->openCurDataBase())
	{
		return ;
	}

	vtrMsgInfo msgInfos;
	//!��ѯ��ʷ��Ϣʧ��
	if (!Database::GetInstance()->queryMsgInfo(msgInfos))
	{
		return ;
	}

	//!��������Ϣ�б�
	Database::GetInstance()->insertHistoryMsgInfo(msgInfos);
}
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QString dbPath = QCoreApplication::applicationDirPath() + "/zhicloud.db";
	QFile file(dbPath);
	//!��ǰ�汾��zhicloud.db�ļ�������
	if (!file.exists())
	{
		return 0;
	}

	synchronizeDB();

	Database::DestoryInstance();
	QFile::remove(dbPath);

	QString serDbPath = QCoreApplication::applicationDirPath() + "/zhicloudServer.db";
	QFile fileSer(serDbPath);
	//!��ǰ�汾��zhicloud.db�ļ�������
	if (!fileSer.exists())
	{
		return 0;
	}
	QFile::remove(serDbPath);

	QString resDbPath = QCoreApplication::applicationDirPath() + "/ResourcesDatabase.db";
	QFile fileRes(resDbPath);
	//!��ǰ�汾��zhicloud.db�ļ�������
	if (!fileRes.exists())
	{
		return 0;
	}
	QFile::remove(resDbPath);
	return 0;
}
