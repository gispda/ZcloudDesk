#include "DownloadHelper.h"
#include <QSharedMemory>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	//!�����ڴ淽ʽʵ�ֳ���ʵ������
	QSharedMemory shared("DownloadHelper");
	if (shared.attach()) return 0;
	shared.create(1);

	DownloadHelper w;
	return a.exec();
}
