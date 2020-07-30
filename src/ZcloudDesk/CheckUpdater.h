#pragma once

#include <QObject>
#include <vector>
#include <string>
using namespace std;
class CheckUpdater : public QObject
{
	Q_OBJECT

public:
	CheckUpdater(QObject *parent = 0);
	~CheckUpdater();

	bool checkUpdater(QString strUid, QString strToken);

	void startUpdaterProcess(bool bSlience);
private:
	bool CheckUpdaterVer(QString strVerNum);

	int CompareVersion(QString nowVerson, QString newVerson);

	vector<string> split_string(string &szInput, string &szToken);

	QString m_strDownloadUrl;
	QString m_strMd5;
};
