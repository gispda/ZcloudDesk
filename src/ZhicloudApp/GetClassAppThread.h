#pragma once
#include <QThread>
#include <QMap>
class GetClassAppThread :
	public QThread
{
public:
	GetClassAppThread(QObject *parent);
	~GetClassAppThread();
private:
	void run();
	//储存 存在的 应用id
	QMap<QString, int> oldAppIdUpTimeMap;
	QMap<QString, int>  newAppIdUpTimeMap;
	//储存 存在的 分类id
	QMap<QString, QString> oldCateIdNameMap;
	QMap<QString, QString>  newCateIdNameMap;
	//发布到桌面的应用
	QStringList issueStringList;
	//桌面已安装应用
	QStringList deskAppStringList;
};

