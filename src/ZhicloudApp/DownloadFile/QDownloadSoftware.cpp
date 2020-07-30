//下载开票软件
#include "ZcloudCommon.h"
#include "QDownloadSoftware.h"
#include <QSettings>
#include <QApplication>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QPainter>
#include <QMouseEvent>
#include <qmath.h>
#include <QProcess>
#include <QDesktopWidget>

#include "DownLoadThread.h"
extern QString g_strAppName;

QDownloadSoftware::QDownloadSoftware(int nDownloadType, QString url, QWidget *parent)
	: AppCommDialog( parent)
	, m_pDownloadThread(NULL)
	, m_bytesReceived(0)
	, m_downloadErrorFlag(true)
	, m_nDownloadType(nDownloadType)
	, m_url(url)
{
	this->resize(666, 346);

	setWindowTitle(g_strAppName);

	downMiniPushButton = new QPushButton(m_widget);
	downClosePushButton = new QPushButton(m_widget);
	pushButton = new QPushButton(QString::fromLocal8Bit("点击继续下载"), m_widget);
	connect(downClosePushButton,SIGNAL(clicked()), this,SLOT(downClose()));
	connect(downMiniPushButton, SIGNAL(clicked()), this, SLOT(showMinimized()));
	connect(pushButton, SIGNAL(clicked()), this, SLOT(resetPushButton()));
	progressBar = new QProgressBar(m_widget);
	progressLabel = new QLabel("0%",m_widget);
	speedLabel = new QLabel(m_widget);
	progressBar->setTextVisible(false);
	progressLabel->setAlignment(Qt::AlignRight);
	speedLabel->setAlignment(Qt::AlignLeft);

	downMiniPushButton->setGeometry(595, 5, 25, 25);
	downClosePushButton->setGeometry(620, 5, 25, 25);
	pushButton->setGeometry(525, 257, 74, 15);
	speedLabel->setGeometry(51, 300, 400, 15);
	progressBar->setGeometry(50, 281, 550, 10);
	progressLabel->setGeometry(570, 300, 30, 15);

	downMiniPushButton->setStyleSheet("QPushButton{border-image: url(:/new/imageFile/zxh_nor.png);}\
									  QPushButton:hover{border-image: url(:/new/imageFile/zxh_sel.png);}\
									  									  QPushButton:pressed{border-image: url(:/new/imageFile/zxh_sel.png);};"
																		  );
	downClosePushButton->setStyleSheet("QPushButton{border-image: url(:/new/imageFile/gb_nor.png);}\
									   QPushButton:hover{border-image: url(:/new/imageFile/gb_sel.png);}\
									   QPushButton:pressed{border-image: url(:/new/imageFile/gb_sel.png);};");
	pushButton->setStyleSheet("QPushButton{	color: rgb(50, 154, 238);border:none;font: 12px;}\
								QPushButton:hover{	text-decoration: underline;	color: rgb(50, 154, 238);border:none;font: 12px;}\
								QPushButton:pressed{text-decoration: underline;	color: rgb(50, 154, 238);border:none;font: 12px;};");
	speedLabel->setStyleSheet("	color: rgb(128, 128, 128);font-size: 12px;");
	progressLabel->setStyleSheet("	color: rgb(128, 128, 128);font-size: 12px;");

	pushButton->hide();
	progressBar->setStyleSheet("QProgressBar{border-radius:5px;text-align:center;background-color:rgb(242, 242, 242);}"
		"QProgressBar::chunk{border-radius:5px;background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1)) ;}");
	if (0 == m_nDownloadType || 2 == m_nDownloadType)
	{
		m_widget->setStyleSheet(QString::fromLocal8Bit("QWidget#AppCommDialogDialog{border-image: url( :/new/imageFile/downloadSoft.png);border-radius:8px;}"));
	
		strCodeList.clear();
		QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
		QStringList groupsList = settings->childGroups();
		foreach(QString group, groupsList)
		{
			settings->beginGroup(group);
			QString strCode = settings->value("code", QVariant()).toString();			//！企业税号
			strCode = strCode.replace(" ", "");
			QString strMachine = settings->value("machine", QVariant()).toString();		//！主机号分机号
			settings->endGroup();
			if (!strCode.isEmpty() && !strMachine.isEmpty())
			{
				strCodeList << strCode;			//！企业税号
			}
		}
		delete settings;
	}
	else if (1 == m_nDownloadType)
	{
		m_widget->setStyleSheet(QString::fromLocal8Bit("QWidget#AppCommDialogDialog{border-image: url( :/new/imageFile/downloadNuonuo.png);border-radius:8px;}"));
	}
	else
	{
		m_widget->setStyleSheet(QString::fromLocal8Bit("QWidget#AppCommDialogDialog{border-image: url( :/new/imageFile/topAppDownloadBg.png);border-radius:8px;}"));
	}
	startDownload();
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
}

QDownloadSoftware::~QDownloadSoftware()
{
	if (m_pDownloadThread)
	{
		disconnect(m_pDownloadThread);
		m_pDownloadThread->deleteLater();
		m_pDownloadThread = NULL;
	}
}


void QDownloadSoftware::mousePressEvent(QMouseEvent *event)
{
	this->windowPos = this->pos();           // 获得部件当前位置
	this->mousePos = event->globalPos();     // 获得鼠标位置
	this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void QDownloadSoftware::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->globalPos() - this->dPos);
}
//重新下载
void QDownloadSoftware::resetPushButton()
{
	speedLabel->setText(QString::fromLocal8Bit("正在下载,请稍等... "));
	startDownload();
}

void QDownloadSoftware::startDownload()
{
	pushButton->hide();
	m_downloadErrorFlag = true;

	
	if (m_pDownloadThread == NULL)
	{
		m_pDownloadThread = new DownLoadThread(this);
		m_pDownloadThread->setDownInto(true);
		connect(m_pDownloadThread, SIGNAL(signalDownloadProcess(qint64, qint64)), this, SLOT(onDownloadProcess(qint64, qint64)));
		connect(m_pDownloadThread, SIGNAL(signalReplyFinished(int,QString)), this, SLOT(downloadFinish(int,QString)));
		connect(m_pDownloadThread, SIGNAL(signalDownloadError(QString)), this, SLOT(downloadError(QString)));
		connect(m_pDownloadThread, SIGNAL(installFinished(bool)), this, SLOT(installFilish(bool)));
	}


	//m_pDownloadThread->reset();
	m_pDownloadThread->downloadFile(m_url, QApplication::applicationDirPath());
	m_downloadTime.start();	
}


void QDownloadSoftware::installFilish(bool installFlag)
{
	downClosePushButton->setEnabled(true);
	if (0 == m_nDownloadType || 2 == m_nDownloadType)
	{
		QString strVerSion = "";
		if (ZcloudComFun::readsoft(strVerSion))
		{
			QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
			QStringList groupsList = settings->childGroups();
			foreach(QString group, groupsList)
			{
				settings->beginGroup(group);
				QString newCode = settings->value("code", QVariant()).toString();			//！企业税号
				newCode = newCode.replace(" ", "");
				QString strMachine = settings->value("machine", QVariant()).toString();		//！主机号分机号
				QString strOrgCode = settings->value("orgcode", QVariant()).toString();		//！地区代码
				settings->endGroup();
				if (newCode.isEmpty()/* || strMachine.isEmpty()*/)
				{
					continue;
				}
				if (!strCodeList.contains(newCode))
				{
					//检测到新税号
					if (0 == m_nDownloadType)//登录之前 安装开票软件
					{
						delete settings;
						this->accept();
						return;
					}
					else //登录之后 安装开票软件
					{
						if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("检测到新税号：%1\r\n是否切换并重新登录？").arg(newCode)) == QDialog::Accepted)
						{
							emit sigInstallFinlished(newCode, true);
							emit switchEinSignal(newCode, strMachine);
						}
						delete settings;
						this->accept();
						return;
					}
					break;
				}
			}
		}

		if (2 == m_nDownloadType)
		{
			//如果是重装 安装失败直接关闭窗口
			downClose();
			return;
		}

		downloadError(QString::fromLocal8Bit("安装失败！"));
		return;
	}
	else if (1 == m_nDownloadType)
	{
		//下载远程服务
		this->accept();
	}
	else
	{
		//下载顶栏应用
		this->accept();
	}
}

void QDownloadSoftware::onDownloadProcess(qint64 bytesReceived, qint64 bytesTotal)
{
	if (!m_downloadErrorFlag)
		return;
	m_bytesReceived = bytesReceived;
	if (bytesTotal == 0) return;
	if (bytesTotal == -1) {
		progressBar->setValue(0);
		progressBar->setMaximum(0);
	}
	else {
		progressBar->setRange(0, bytesTotal);
		progressBar->setValue(bytesReceived);
	}	
	progressLabel->setText(progressBar->text());
	updateInfoLabel();
	update();
	QCoreApplication::processEvents();//避免界面冻结
}


void QDownloadSoftware::updateInfoLabel()
{
	qint64 bytesTotal = progressBar->maximum();

	// update info label
	double speed = m_bytesReceived * 1000.0 / m_downloadTime.elapsed();
	double timeRemaining = ((double)(bytesTotal - m_bytesReceived)) / speed;
	QString timeRemainingString = QString::fromLocal8Bit("秒");// tr("seconds");
	if (timeRemaining > 60) {
		timeRemaining = timeRemaining / 60;
		timeRemainingString = QString::fromLocal8Bit("分钟");// tr("minutes");
	}
	timeRemaining = floor(timeRemaining);

	// When downloading the eta should never be 0
	if (timeRemaining == 0)
		timeRemaining = 1;


	QString remaining;
	if (bytesTotal != 0)
		remaining = QString::fromLocal8Bit("还剩 %4 %5")
		.arg(timeRemaining)
		.arg(timeRemainingString);

	if (!m_downloadErrorFlag)
		return;
	speedLabel->setText(QString("%1/%2( %3/s ) %4").arg(dataString(m_bytesReceived)).arg(bytesTotal == 0 ? tr("?") : dataString(bytesTotal)).arg(dataString((int)speed)).arg(remaining));
}

QString QDownloadSoftware::dataString(int size) const
{
	QString unit;
	if (size < 1024) {
		unit = tr("bytes");
	}
	else if (size < 1024 * 1024) {
		size /= 1024;
		unit = tr("kB");
	}
	else {
		size /= 1024 * 1024;
		unit = tr("MB");
	}
	return QString(QLatin1String("%1 %2")).arg(size).arg(unit);
}


void QDownloadSoftware::downloadFinish(int ,QString filePath)
{
	downClosePushButton->setEnabled(false);
	speedLabel->setText(QString::fromLocal8Bit("安装中..."));
}

void QDownloadSoftware::closeEvent(QCloseEvent *event)
{
	event->ignore(); // 忽略关闭事件
}


void QDownloadSoftware::downloadError( QString erroStr)
{
	this->show();
	m_downloadErrorFlag = false;
	if (m_pDownloadThread)
	{
		disconnect(m_pDownloadThread);
		m_pDownloadThread->deleteLater();
		m_pDownloadThread = NULL;
	}
	speedLabel->setText(erroStr);
	pushButton->show();
}

void  QDownloadSoftware::downClose()
{
	downClosePushButton->setEnabled(false);
	if (m_pDownloadThread)
	{
		m_pDownloadThread->closeDownload(true);
		m_pDownloadThread->deleteLater();
		m_pDownloadThread = NULL;
	}

	if (2 == m_nDownloadType)
	{
		emit sigInstallFinlished("", false);
	}
	this->reject();
}




