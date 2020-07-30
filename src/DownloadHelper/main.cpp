#include "DownloadHelper.h"
#include <QSharedMemory>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	//!共享内存方式实现程序单实例运行
	QSharedMemory shared("DownloadHelper");
	if (shared.attach()) return 0;
	shared.create(1);

	DownloadHelper w;
	return a.exec();
}
