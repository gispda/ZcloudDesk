#include <QtCore/QCoreApplication>
#include <QSharedMemory>
#include "DownloadAssist.h"
#include <QDateTime>
#include <QApplication>
#include <QDir>
#include <QTextStream>

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	static QMutex mutex;
	QMutexLocker locker(&mutex);

	QString text;
	switch (type)
	{
	case QtDebugMsg:
		text = QString("Debug:   ");
		break;
	case QtWarningMsg:
		text = QString("QtWarningMsg:   ");
		return;
	case QtCriticalMsg:
		text = QString("QtCriticalMsg:  ");
		break;
	case QtFatalMsg:
		text = QString("QtFatalMsg:  ");
		break;
	case QtInfoMsg:
		text = QString("QtInfoMsg:   ");
		return;
	default:
		return;
	}

	QString h = "============================================================================\r\n";
	QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
	QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
	QString message = QString("%1           %2 %3 \r\n %4 %5").arg(h).arg(current_date_time).arg(context_info).arg(text).arg(msg);

	QString strlogsDir = QApplication::applicationDirPath() + "/logs";
	QDir dir;
	if (!dir.exists(strlogsDir))
	{
		dir.mkpath(strlogsDir);
	}

	QString strlogFile = strlogsDir + QString("/%1.txt").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
	QFile file(strlogFile);
	file.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream text_stream(&file);
	text_stream << message << "\r\n";
	file.flush();
	file.close();
}
int main(int argc, char *argv[])
{
#ifdef _DEBUG
#else
	qInstallMessageHandler(outputMessage);
#endif
	QCoreApplication a(argc, argv);

	//!共享内存方式实现程序单实例运行
	QSharedMemory shared("ZcloudDeskAssist");
	if (shared.attach())
	{
		return 0;
	}
	shared.create(1);

	DownloadAssist w;
	return a.exec();
}
