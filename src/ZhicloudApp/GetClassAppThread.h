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
	//���� ���ڵ� Ӧ��id
	QMap<QString, int> oldAppIdUpTimeMap;
	QMap<QString, int>  newAppIdUpTimeMap;
	//���� ���ڵ� ����id
	QMap<QString, QString> oldCateIdNameMap;
	QMap<QString, QString>  newCateIdNameMap;
	//�����������Ӧ��
	QStringList issueStringList;
	//�����Ѱ�װӦ��
	QStringList deskAppStringList;
};

