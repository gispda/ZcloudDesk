#include "ZBrowser.h"
#include <QtWidgets/QApplication>
#include <QTranslator>
#include <QFileInfo>
#include <QSettings>
void applyNetProxy()
{
	QString strIniPath = QApplication::applicationDirPath();
	QSettings settings(strIniPath + "/net", QSettings::IniFormat);
	int nType = settings.value("proxy/type").toInt();
	QString strHost = settings.value("proxy/host").toString();
	int nPort = settings.value("proxy/port").toInt();
	QString strUser = settings.value("proxy/user").toString();
	QString strPwd = settings.value("proxy/pwd").toString();

	QNetworkProxy proxy;
	proxy.setType((QNetworkProxy::ProxyType)nType);
	proxy.setHostName(strHost);
	proxy.setPort(nPort);
	proxy.setUser(strUser);
	proxy.setPassword(strPwd);
	QNetworkProxy::setApplicationProxy(proxy);
}
//日志
void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	// "zcd-0x00000080:"  80可以用
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
		text = QString("QtCriticalMsg:zcd-0x0000007C ");
		break;
	case QtFatalMsg:
		text = QString("QtFatalMsg:  zcd-0x0000007D ");
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
	QFile file(QApplication::applicationDirPath() + "/ZcloudDeskLog.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream text_stream(&file);
	text_stream << message << "\r\n";
	file.flush();
	file.close();

	/*if (msg.contains("zcd-0x"))
	{
	QString bigDataDebugStr = " zcloudDeskErrorMsg:" + msg;
	bigDataDebugStr.replace("\"", "");
	if (bigDataDebugStr.size() > 1900) bigDataDebugStr = bigDataDebugStr.mid(0, 1900);
	BigDataInterface::GetInstance()->socketPost(QString("%1,%2,%3,%4").arg("M20").arg("").arg("").arg(bigDataDebugStr));
	}*/
}

int main(int argc, char *argv[])
{
#ifdef _DEBUG
#else
	qInstallMessageHandler(outputMessage);
#endif
	QApplication a(argc, argv);
	// 传入参数 分类id  应用id  标题  url  icon路径
	QString strClassId, strAppId, strTitel, strUrl, strIcon;
	 if (argc == 2)
	{
		strUrl = argv[1];
	 }else if (argc < 6)
	 {
		 strUrl = "https://www.zhicloud.com";
		 strTitel = QString::fromLocal8Bit("致云科技");
	 }
	 else
	{
		strClassId = argv[1];
		strAppId = argv[2];
		strTitel = QString::fromLocal8Bit(argv[3]);
		strUrl = argv[4];
		strIcon = argv[5];
	}
	
	//！浏览器中文支持
	QTranslator translator;
	translator.load(":/qt_zh_CN.qm");
	a.installTranslator(&translator);

	if (strIcon.isEmpty() ||  !QFileInfo::exists(strIcon))
		strIcon = ":/zc64.ico";
	//!图标名称
	QIcon icon(strIcon);
	a.setWindowIcon(icon);
	if (strTitel.isEmpty())
	{
		strTitel = QString::fromLocal8Bit("浏览器");
	}
	QApplication::setApplicationDisplayName(strTitel);

	applyNetProxy();

	ZBrowser w(strClassId, strAppId, strUrl, strTitel);
	w.show();
	return a.exec();
}