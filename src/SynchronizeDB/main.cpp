#include <QtCore/QCoreApplication>
#include <QFile>
#include "Database.h"

void synchronizeDB()
{
	//！以前版本的zhicloud.db文件打开失败或者消息中心表不存在
	if (!Database::GetInstance()->openOldDataBase())
	{
		return ;
	}

	//!打开当前版本zhicloudMsg.db失败
	if (!Database::GetInstance()->openCurDataBase())
	{
		return ;
	}

	vtrMsgInfo msgInfos;
	//!查询历史消息失败
	if (!Database::GetInstance()->queryMsgInfo(msgInfos))
	{
		return ;
	}

	//!插入新消息列表
	Database::GetInstance()->insertHistoryMsgInfo(msgInfos);
}
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QString dbPath = QCoreApplication::applicationDirPath() + "/zhicloud.db";
	QFile file(dbPath);
	//!以前版本的zhicloud.db文件不存在
	if (!file.exists())
	{
		return 0;
	}

	synchronizeDB();

	Database::DestoryInstance();
	QFile::remove(dbPath);

	QString serDbPath = QCoreApplication::applicationDirPath() + "/zhicloudServer.db";
	QFile fileSer(serDbPath);
	//!以前版本的zhicloud.db文件不存在
	if (!fileSer.exists())
	{
		return 0;
	}
	QFile::remove(serDbPath);

	QString resDbPath = QCoreApplication::applicationDirPath() + "/ResourcesDatabase.db";
	QFile fileRes(resDbPath);
	//!以前版本的zhicloud.db文件不存在
	if (!fileRes.exists())
	{
		return 0;
	}
	QFile::remove(resDbPath);
	return 0;
}
