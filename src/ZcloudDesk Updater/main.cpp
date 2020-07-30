#include "ZcloudDeskUpdater.h"
#include <QtWidgets/QApplication>
#include <QSettings>
#include <QNetworkProxy>
#include "CheckProcessThread.h"

#ifdef VERSION_FOR_GZ
QString  g_strAppName= QString::fromLocal8Bit("爱服务");
#else
QString g_strAppName = QString::fromLocal8Bit("云财税");
#endif

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
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	if (argc != 4)
	{
		return 0;
	}
	QString strDownloadUrl	= argv[1];
	QString strMd5			= argv[2];
	QString strShowWindow	= argv[3];

	//QString strDownloadUrl = "http://download.zhicloud.com/app/pkg/guizhou/Package5.0.3-love.zip";
	//QString strMd5 = "E68656427DB02D2C8390D4F79A1BF020";
	//QString strShowWindow = "0";
	bool bShowWindow = strShowWindow.toInt();

	QApplication::setApplicationDisplayName(QString::fromLocal8Bit("%1更新程序").arg(g_strAppName));

	applyNetProxy();

	ZcloudDeskUpdater w(strDownloadUrl, strMd5, bShowWindow);
	if (bShowWindow)
	{
		w.show();
	}

	CheckProcessThread*	pThread = new CheckProcessThread;
	pThread->start();

	return a.exec();
}
