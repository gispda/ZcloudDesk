
#include <QtWidgets/QApplication>
#include <QNetworkProxyQuery>
#include <QFileInfo>
#include <QSettings>
#include <QDateTime>
#include <QTranslator>
#include <QProcess>
#include "ZcloudDesk.h"
#include "SingleApplication.h"
#include "LoginDialog.h"
#include "Database.h"
#include "dlgwait.h"
#include "QauZIP/JlCompress.h"
#include "ZcloudBigData.h"
#include "HttpTest.h"

QString g_strAppName;
//!从代理配置文件获取网络代理
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
void updater()
{
	QString strUpdaterFile = QApplication::applicationDirPath() + "/Updater";
	if (!QFile::exists(strUpdaterFile))
	{
		//qDebug("zcd-0x10000001: config file named \"Updater\" not exist!");
		return;
	}
	QSettings settings(strUpdaterFile, QSettings::IniFormat);
	bool bUpdater	= settings.value("updater/update").toBool();

	if (bUpdater)
	{
		QString strFileName = settings.value("updater/path").toString();
		if (!QFile::exists(strFileName))
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M10", "OP001", "TAU004");
			QFile::remove(strUpdaterFile);
			return;
		}
		if (strFileName.right(4) == ".exe")
		{
			QFile::remove(strUpdaterFile);
			ZcloudComFun::writeRegReboot(ZcloudComFun::EN_NOREBOOT);
			strFileName = "\"" + strFileName + "\"";
			QProcess::startDetached(strFileName, QStringList());
		}
	}	
}
int main(int argc, char *argv[])
{
#ifdef _DEBUG
#else
	qInstallMessageHandler(outputMessage);
#endif
	qRegisterMetaType<UserInfoStruct>("UserInfoStruct");
	SingleApplication a(argc, argv);

	//！浏览器中文支持
	QTranslator translator;
	translator.load(":/ZcloudDesk/qt_zh_CN.qm");
	a.installTranslator(&translator);

	QTranslator translatorTE;
	translatorTE.load(":/ZcloudDesk/widgets.qm");
	a.installTranslator(&translatorTE);

	//!图标名称
#ifdef VERSION_FOR_GZ
	QIcon icon(":/ZcloudDesk/image/zc64Gz.ico");
	g_strAppName	=	QString::fromLocal8Bit("爱服务");
#else
	QIcon icon(":/ZcloudDesk/image/zc64.ico");
	g_strAppName = QString::fromLocal8Bit("云财税");
#endif
	a.setWindowIcon(icon);
	QApplication::setApplicationDisplayName(g_strAppName);
	if (a.isRunning())
	{
		return 0;
	}
	a.setQuitOnLastWindowClosed(false);

	//!设置网络代理
	applyNetProxy();

	//!数据库初始化
	Database::GetInstance();
	ServerDatabase::GetInstance();

	//!启动心跳
	QString zyServer = argv[1];
	//qDebug() << "argv is:" << zyServer;
	if (zyServer == "1")
	{
		UserInfoStruct	info;
		Database::GetInstance()->getUserInfoByPreUser(info);

		if (info.m_strUserId.isEmpty())
		{
			return 0;
		}
		ZcloudBigDataInterface::GetInstance()->initData(info.m_strUserId,info.m_strCompanyId,info.m_strHzsId,info.m_strProvinceId,info.m_strCityId,info.m_strAreaId,"0");
		int ret = a.exec();
		if (ret == 773) {
			a.appDisConnect();
			QProcess::startDetached(qApp->applicationFilePath(), QStringList());
			return 0;
		}
		else if (ret == 1)
		{
			QProcess::startDetached(qApp->applicationFilePath(), QStringList() << "1");
			return 0;
		}
		return ret;
	}
	//!更新
	updater();
	



	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//LoginDialog loginDialog;
	//DlgWait 	dlgWait(QString::fromLocal8Bit("登录中..."));
	//QString strTip;
	//int logingInt;
	//if (loginDialog.isUserNameLogin())//非税号登录
	//	logingInt = 3;
	//else
	//	logingInt = loginDialog.checkLogin(strTip);
	//dlgWait.stop();
	//if (logingInt == 2 || logingInt == 0 || logingInt == 3)
	//{
	//	if (logingInt == 2)
	//	{
	//		/*
	//		//让用户确认是否安装开票软件
	//		if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"), strTip) == QDialog::Accepted)
	//		{
	//			//安装开票软件
	//			QString softUrl;
	//			QString softVersion;
	//			if (ZcloudComFun::getSoftwareData(softUrl, softVersion))
	//			{
	//				if (ZhicloudApp::openDownloadSoftware(0, softUrl) == QDialog::Accepted)
	//				{
	//					//安装成功重启软件
	//					a.appDisConnect();
	//					QProcess::startDetached(qApp->applicationFilePath(), QStringList());
	//					return 0;
	//				}
	//			}
	//			else
	//				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("获取开票软件失败，请稍后再试！"));
	//		}*/
	//	}
	//	else if (logingInt == 0)
	//	{
	//		//登录失败提示
	//		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), strTip);
	//	}
	//	//账号登录框
	//	//扫码 下提示安装开票软件
	//	loginDialog.initWeChartWidget(logingInt);
	//	if (loginDialog.exec() != QDialog::Accepted)
	//	{
	//		return 0;
	//	}
	//}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////如果是税号登录登录成功 检测开票软件版本
	//if (loginDialog.getUserInfoStruct().m_bLoginByTax == 1)
	//{
	//	QString softUrl;
	//	QString softVersion = loginDialog.getUserInfoStruct().m_strHzsId;
	//	if (ZcloudComFun::getSoftwareData(softUrl, softVersion))
	//	{
	//		QString strVerSion = "";
	//		if (ZcloudComFun::readsoft(strVerSion, loginDialog.getUserInfoStruct().m_strTaxNumber) && !strVerSion.isEmpty())
	//		{
	//			QStringList oldVerList = strVerSion.split(".");
	//			QStringList newVerList = softVersion.split(".");
	//			for (size_t i = 0; i < (oldVerList.size() > newVerList.size() ? newVerList.size() : oldVerList.size()); i++)
	//			{
	//				if (oldVerList.at(i).toInt() != newVerList.at(i).toInt())
	//				{
	//					if (oldVerList.at(i).toInt() < newVerList.at(i).toInt())
	//					{
	//						//让用户确认是否安装开票软件
	//						if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("检测到新的开票软件，是否更新？")) == QDialog::Accepted)
	//						{
	//							//安装开票软件
	//							if (ZhicloudApp::openDownloadSoftware(0, softUrl) == QDialog::Accepted)
	//							{
	//								//安装成功重启软件
	//								a.appDisConnect();
	//								QProcess::startDetached(qApp->applicationFilePath(), QStringList());
	//								return 0;
	//							}
	//						}
	//						break;
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//登陆成功
	//UserInfoStruct userInfo = loginDialog.getUserInfoStruct();
	//ZcloudDesk w(userInfo);
	//LoginDialog loginDialog;


	UserInfoStruct userInfo;

	
	int code = LoginThread::visitorLogin(userInfo);

	//HttpTest ht;
	//ht.access();

	if (code != 0)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("游客登陆"), QString::fromLocal8Bit("游客获取临时权限异常"));
	}


	ZcloudDesk w(userInfo);
	w.show();
	a.mainWindow = &w;
	int ret = a.exec();
	if (ret == 773) {
		a.appDisConnect();
		QProcess::startDetached(qApp->applicationFilePath(), QStringList());
		return 0;
	}
	else if (ret == 1)
	{
		QProcess::startDetached(qApp->applicationFilePath(), QStringList() << "1");
		return 0;
	}
	return ret;
}
