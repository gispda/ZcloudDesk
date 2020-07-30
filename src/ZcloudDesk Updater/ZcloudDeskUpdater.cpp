#include "ZcloudDeskUpdater.h"
#include <QGraphicsDropShadowEffect>
#include <QNetworkProxyQuery>
#include <QFileInfo>
#include <QDir>
#include <QTimer>
#include <QMessageBox>
#include <QProcess>
#include "QauZIP/JlCompress.h"
#include "MessageTipDlg.h"
#include <QSettings>
#include <QWaitCondition>
#include "HttpDownload.h"

#define DOWNLOAD_FILE_SUFFIX	"_tmp_download"
extern QString g_strAppName;
ZcloudDeskUpdater::ZcloudDeskUpdater(QString strUrl, QString strMd5, bool bShowWindow,QWidget *parent)
	: QMainWindow(parent)
	, m_strDownloadUrl(strUrl)
	, m_strMd5(strMd5)
	, m_bShowWindow(bShowWindow)
	, m_pTimer(new QTimer(this))
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowSystemMenuHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowTitle(QString::fromLocal8Bit("%1更新程序").arg(g_strAppName));
	setStyleSheet("outline: none");

	ui.label_2->setText(QString::fromLocal8Bit("检测到%1新版本").arg(g_strAppName));

	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
	//设置阴影距离
	shadow->setOffset(0, 0);
	//设置阴影颜色
	shadow->setColor(QColor("#666666"));
	//设置阴影圆角
	shadow->setBlurRadius(8);
	//给嵌套QWidget设置阴影
	this->setGraphicsEffect(shadow);

	connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimerOut()));
	m_pTimer->start(1000);
}

void ZcloudDeskUpdater::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		dPos = event->globalPos() - pos();
		event->accept();
	}
}

void ZcloudDeskUpdater::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - dPos);
		event->accept();
	}
}
void ZcloudDeskUpdater::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
	if (0 == bytesTotal)
	{
		return;
	}
	if (bytesReceived == bytesTotal)
	{
		ui.labelPercent->setText("100%");
	}
	else
	{
		qint64 fPercent = bytesReceived*100 / bytesTotal;
		QString strPercent = QString::fromLocal8Bit("%1%").arg(fPercent);
		ui.labelPercent->setText(strPercent);
	}
	ui.progressBar->setMaximum(bytesTotal);
	ui.progressBar->setValue(bytesReceived);
	ui.progressBar->repaint();
}

bool ZcloudDeskUpdater::downloadSucessed(QString strDownloadFileName)
{
	if (!QFile::exists(strDownloadFileName))
	{
		return false;
	}
	QString strUpdaterFileName;
	if (strDownloadFileName.right(4) == ".exe")
	{
		strUpdaterFileName = strDownloadFileName;
	}
	else if (strDownloadFileName.right(4) == ".zip")
	{
		QString uzipPath = QCoreApplication::applicationDirPath();
		uzipPath.replace("\\", "/");
		QStringList strFileList = JlCompress::getFileList(strDownloadFileName);
		int nCount = strFileList.count();
		for (int i = 0; i < nCount; i++)
		{
			QString strFile = strFileList.at(i);
			if (strFile == "ZcloudDesk.exe")
			{
				continue;
			}
			strUpdaterFileName = JlCompress::extractFile(strDownloadFileName, strFile, uzipPath + "/" + strFile);
		}
		QFile::remove(strDownloadFileName);
	}
	if (m_bShowWindow)
	{
		MessageTipDlg	dlg(MessageTipDlg::EN_OKCANCEL, QString::fromLocal8Bit("下载完成"), QString::fromLocal8Bit("下载成功，是否立即更新？"), this);
		if (QDialog::Accepted == dlg.exec())
		{
			strUpdaterFileName = "\"" + strUpdaterFileName + "\"";
			QProcess::startDetached(strUpdaterFileName, QStringList());
			return true;
		}
	}
	QString strIniFile = QApplication::applicationDirPath().append("/Updater");
	QSettings *configIniWrite = new QSettings(strIniFile, QSettings::IniFormat);
	configIniWrite->setValue("/updater/update", true);
	configIniWrite->setValue("/updater/path", strUpdaterFileName);
	delete configIniWrite;
	return true;
}

void ZcloudDeskUpdater::onTimerOut()
{
	if (!startWork())
	{
		if (!m_bShowWindow)
		{
			m_pTimer->start(1000 * 60 * 60*2);
		}
		else
		{
			MessageTipDlg	dlg(MessageTipDlg::EN_CLOSE, QString::fromLocal8Bit("更新失败"), QString::fromLocal8Bit("更新失败，请稍后再试!"), this);
			dlg.exec();
			m_pTimer->stop();
			qApp->quit();
		}
		
	}
	else
	{
		m_pTimer->stop();
		qApp->quit();
	}
}

bool ZcloudDeskUpdater::startWork()
{
	//!十分钟随机
	if (!m_bShowWindow)
	{
		qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
		unsigned long test = qrand() % 1000 * 60 * 3;
		QMutex mutex;
		QWaitCondition sleep;
		mutex.lock();
		sleep.wait(&mutex, test);
		mutex.unlock();
	}
	
	//！下载并校验md5
	QString strFileName;
	if (!download(m_strDownloadUrl, m_strMd5, strFileName))
	{
		return false;
	}
	if (!downloadSucessed(strFileName))
	{
		return false;
	}
	return true;

}
bool ZcloudDeskUpdater::download(QString strDownloadUrl, QString strMd5, QString& strFileName)
{
	HttpDownload*	pHttpDownload = new HttpDownload(QApplication::applicationDirPath() + "/", strDownloadUrl, strMd5, true, this);
	if (m_bShowWindow)
	{
		connect(pHttpDownload, SIGNAL(sigDownloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
	}
	
	bool bSucessed	= pHttpDownload->startDownload(strDownloadUrl);
	strFileName		= pHttpDownload->getFileName();

	QFileInfo file(strFileName);
	return (bSucessed	&&	file.isFile());
}
