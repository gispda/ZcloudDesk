
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
//!�Ӵ��������ļ���ȡ�������
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
//��־
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

	//�����������֧��
	QTranslator translator;
	translator.load(":/ZcloudDesk/qt_zh_CN.qm");
	a.installTranslator(&translator);

	QTranslator translatorTE;
	translatorTE.load(":/ZcloudDesk/widgets.qm");
	a.installTranslator(&translatorTE);

	//!ͼ������
#ifdef VERSION_FOR_GZ
	QIcon icon(":/ZcloudDesk/image/zc64Gz.ico");
	g_strAppName	=	QString::fromLocal8Bit("������");
#else
	QIcon icon(":/ZcloudDesk/image/zc64.ico");
	g_strAppName = QString::fromLocal8Bit("�Ʋ�˰");
#endif
	a.setWindowIcon(icon);
	QApplication::setApplicationDisplayName(g_strAppName);
	if (a.isRunning())
	{
		return 0;
	}
	a.setQuitOnLastWindowClosed(false);

	//!�����������
	applyNetProxy();

	//!���ݿ��ʼ��
	Database::GetInstance();
	ServerDatabase::GetInstance();

	//!��������
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
	//!����
	updater();
	



	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//LoginDialog loginDialog;
	//DlgWait 	dlgWait(QString::fromLocal8Bit("��¼��..."));
	//QString strTip;
	//int logingInt;
	//if (loginDialog.isUserNameLogin())//��˰�ŵ�¼
	//	logingInt = 3;
	//else
	//	logingInt = loginDialog.checkLogin(strTip);
	//dlgWait.stop();
	//if (logingInt == 2 || logingInt == 0 || logingInt == 3)
	//{
	//	if (logingInt == 2)
	//	{
	//		/*
	//		//���û�ȷ���Ƿ�װ��Ʊ���
	//		if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ʾ"), strTip) == QDialog::Accepted)
	//		{
	//			//��װ��Ʊ���
	//			QString softUrl;
	//			QString softVersion;
	//			if (ZcloudComFun::getSoftwareData(softUrl, softVersion))
	//			{
	//				if (ZhicloudApp::openDownloadSoftware(0, softUrl) == QDialog::Accepted)
	//				{
	//					//��װ�ɹ��������
	//					a.appDisConnect();
	//					QProcess::startDetached(qApp->applicationFilePath(), QStringList());
	//					return 0;
	//				}
	//			}
	//			else
	//				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��ȡ��Ʊ���ʧ�ܣ����Ժ����ԣ�"));
	//		}*/
	//	}
	//	else if (logingInt == 0)
	//	{
	//		//��¼ʧ����ʾ
	//		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), strTip);
	//	}
	//	//�˺ŵ�¼��
	//	//ɨ�� ����ʾ��װ��Ʊ���
	//	loginDialog.initWeChartWidget(logingInt);
	//	if (loginDialog.exec() != QDialog::Accepted)
	//	{
	//		return 0;
	//	}
	//}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////�����˰�ŵ�¼��¼�ɹ� ��⿪Ʊ����汾
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
	//						//���û�ȷ���Ƿ�װ��Ʊ���
	//						if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��⵽�µĿ�Ʊ������Ƿ���£�")) == QDialog::Accepted)
	//						{
	//							//��װ��Ʊ���
	//							if (ZhicloudApp::openDownloadSoftware(0, softUrl) == QDialog::Accepted)
	//							{
	//								//��װ�ɹ��������
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
	//��½�ɹ�
	//UserInfoStruct userInfo = loginDialog.getUserInfoStruct();
	//ZcloudDesk w(userInfo);
	//LoginDialog loginDialog;


	UserInfoStruct userInfo;

	
	int code = LoginThread::visitorLogin(userInfo);

	//HttpTest ht;
	//ht.access();

	if (code != 0)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("�ο͵�½"), QString::fromLocal8Bit("�οͻ�ȡ��ʱȨ���쳣"));
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
