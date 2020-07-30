#pragma once
#include <QThread>
#include <string>
using namespace std;
class CheckProcessThread : public QThread
{
	Q_OBJECT

public:
	CheckProcessThread(QObject *parent=0);
	~CheckProcessThread();

protected:
	void run();

private:
	bool seachProcesses(wstring findedName, bool bMatchAll);
};
