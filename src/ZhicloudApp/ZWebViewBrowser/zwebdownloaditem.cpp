#include "zwebdownloaditem.h"
#include "zwebviewbrowser.h"
#include <QDebug>
#include <QMessageBox>
ZWebDownloadItem::ZWebDownloadItem(QNetworkReply *download, QWidget *parent) :
    QWidget(parent)
  , m_bytesReceived(0)
  , m_bytesCurrentReceived(0)
  , m_totalByte(0)
  , m_networkManager(ZWebViewBrowser::networkAccessManager())
  , m_downloadStatus(DOWNLOADING)
  , m_isSupportBreakPoint(false)
  , m_fileName("")
  , m_download(download)
  , m_downloadThread(NULL)
{
    setupUi(this);
	progressBar->setValue(0);
    //QPalette p = downloadInfoLabel->palette();
    //p.setColor(QPalette::Text, Qt::darkGray);
    //downloadInfoLabel->setPalette(p);
	progressBar->setTextVisible(false);
    connect(openDirButton, SIGNAL(clicked()), this, SLOT(onOpenDirBtn()));
    connect(tryAgainButton, SIGNAL(clicked()), this, SLOT(tryAgain()));
    tryAgainButton->setToolTip(QString::fromLocal8Bit("重新下载"));
    continuePushButton->setToolTip(QString::fromLocal8Bit("继续"));
    suspendButton->setToolTip(QString::fromLocal8Bit("暂停"));
    stopButton->setToolTip(QString::fromLocal8Bit("取消"));
    openButton->setToolTip(QString::fromLocal8Bit("打开文件"));
    openDirButton->setToolTip(QString::fromLocal8Bit("打开目录"));
    setButton();
	downloadInfoLabel->clear();
	progressBar->setValue(0);
	progressBar->show();
    init();
    this->setMinimumSize(55,55);
}

ZWebDownloadItem::~ZWebDownloadItem()
{

}

void ZWebDownloadItem::onClose()
{
    if(m_downloadStatus != STOP)
    {
        QString text = QString::fromLocal8Bit("该下载正在下载或在被暂停，你确定要取消下载吗？");
        QMessageBox::StandardButton button = QMessageBox::question(this, QString(), text,
                                                                   QMessageBox::Ok | QMessageBox::Cancel,
                                                                   QMessageBox::Ok);
        if (button == QMessageBox::Ok) {
			emit statusChanged();
            on_stopButton_clicked();
            this->close();
        }
    }else
    {
        emit  statusChanged();
        on_stopButton_clicked();
        this->close();
    }
}

void ZWebDownloadItem::setButton()
{
    setUpdatesEnabled(false);
    switch (m_downloadStatus) {
    case DOWNLOADING:
        tryAgainButton->setEnabled(false);
        tryAgainButton->hide();

        continuePushButton->setEnabled(false);
        continuePushButton->hide();

        suspendButton->setEnabled(true);
        suspendButton->show();

        openButton->setEnabled(false);
        openButton->hide();

		progressBar->setEnabled(true);
		progressBar->show();

        //        openDirButton->setEnabled(false);
        //        openDirButton->hide();

        stopButton->setEnabled(true);
        stopButton->show();
        break;
    case STOP:
        tryAgainButton->setEnabled(true);
        tryAgainButton->show();

        continuePushButton->setEnabled(false);
        continuePushButton->hide();

        suspendButton->setEnabled(false);
        suspendButton->hide();

        openButton->setEnabled(false);
        openButton->hide();

		progressBar->setEnabled(false);
		progressBar->hide();

        //openDirButton->setEnabled(false);
        //openDirButton->hide();

        stopButton->setEnabled(false);
        stopButton->hide();
        break;
    case SUSPEND:
        tryAgainButton->setEnabled(true);
        tryAgainButton->show();

        continuePushButton->setEnabled(true);
        continuePushButton->show();

        suspendButton->setEnabled(false);
        suspendButton->hide();

        openButton->setEnabled(false);
        openButton->hide();

		progressBar->setEnabled(true);
		progressBar->show();

        //openDirButton->setEnabled(false);
        //openDirButton->hide();

        stopButton->setEnabled(true);
        stopButton->show();
        break;
    default:
        break;
    }
    setUpdatesEnabled(true);
    updateInfoLabel();
    emit statusChanged();
}

void ZWebDownloadItem::setIcon(QIcon icon)
{
    fileIcon->setPixmap(icon.pixmap(48, 48));
}

void ZWebDownloadItem::setFileNameLabel(QString text)
{
    fileNameLabel->setText(text);
}


void ZWebDownloadItem::init(bool isSupportBreakPoint)
{
	m_isSupportBreakPoint = isSupportBreakPoint;
    if(!isSupportBreakPoint)
    {
        if (!m_download)
            return;
        m_url = m_download->url();
        getFileName();
       // m_download->close();
        m_download->deleteLater();
        m_download = NULL;
	}

    QNetworkRequest request;
    request.setUrl(m_url);

	QString strRange = QString("bytes=%1-").arg(m_bytesCurrentReceived);
	request.setRawHeader("Range", strRange.toLatin1());

	m_downloadThread = new ZWebDownloadThread(this);
	m_downloadThread->setValue(request,m_fileName);
	connect(m_downloadThread, SIGNAL(threadReadProgress(qint64, qint64)),
		this, SLOT(downloadProgress(qint64, qint64)));
	connect(m_downloadThread, SIGNAL(finished_signal()),
		this, SLOT(finished()));
	connect(m_downloadThread, SIGNAL(error_signal(QNetworkReply::NetworkError)),
		this, SLOT(error(QNetworkReply::NetworkError)));

	connect(m_downloadThread, SIGNAL(errotTxetSignal(int,QString)),
		this, SLOT(errotTxetSlot(int, QString)));

	m_downloadThread->start();
	progressBar->show();
    // start timer for the download estimation
    m_downloadTime.start();
    m_downloadStatus = DOWNLOADING;
    setButton();
}

void ZWebDownloadItem::getFileName(bool promptForFileName)
{
	QSettings settings;
	settings.beginGroup(QLatin1String("downloadmanager"));
    //QString defaultLocation = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
	QString defaultLocation = QApplication::applicationDirPath() + "/downloadApp";
	QDir dir(defaultLocation);
	if (!dir.exists())
		dir.mkdir(defaultLocation);

    QString downloadDirectory = settings.value(QLatin1String("downloadDirectory"), defaultLocation).toString();
    if (!downloadDirectory.isEmpty())
        downloadDirectory += QLatin1Char('/');

    QString defaultFileName = saveFileName(downloadDirectory);
    QString fileName = defaultFileName;
    if (promptForFileName) {
        fileName = QFileDialog::getSaveFileName(this, tr("Save File"), defaultFileName);
        if (fileName.isEmpty()) {
            //m_download->close();
            fileNameLabel->setText(tr("Download canceled: %1").arg(QFileInfo(defaultFileName).fileName()));
            return;
        }
    }
	m_fileName = fileName;
    m_output.setFileName(fileName);
    fileNameLabel->setText(QFileInfo(m_output.fileName()).fileName());
    //if (promptForFileName)
    //    downloadReadyRead();
}

QString ZWebDownloadItem::saveFileName(const QString &directory) const
{
    // Move this function into QNetworkReply to also get file name sent from the server
    QString path = m_url.path();
    QFileInfo info(path);
    QString baseName = info.completeBaseName();
    QString endName = info.suffix();

    if (baseName.isEmpty()) {
        baseName = QLatin1String("unnamed_download");
		qDebug() << "zcd-0x00000073:" << "DownloadManager:: downloading unknown file:" << m_url;
    }
    QString name = directory + baseName + QLatin1Char('.') + endName;
    if (QFile::exists(name)) {
        // already exists, don't overwrite
        int i = 1;
        do {
            name = directory + baseName + QLatin1Char('-') + QString::number(i++) + QLatin1Char('.') + endName;
        } while (QFile::exists(name));
    }
    return name;
}

void ZWebDownloadItem::tryAgain()
{
    if (!tryAgainButton->isEnabled())
        return;

	progressBar->setValue(0);
    m_bytesCurrentReceived = 0;

    init(true);
    emit statusChanged();
}

void ZWebDownloadItem::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
	//继续下载
	if (m_totalByte != 0)
	{
		if (m_totalByte != (bytesTotal + m_bytesCurrentReceived))
		{
			on_stopButton_clicked();
			downloadInfoLabel->setText(QString::fromLocal8Bit("错误: 文件校验失败"));
			QString text = QString::fromLocal8Bit("该下载不支持断点续传，你需要重新下载吗？");
			QMessageBox::StandardButton button = QMessageBox::question(this, QString(), text,
				QMessageBox::Ok | QMessageBox::Cancel,
				QMessageBox::Ok);
			if (button == QMessageBox::Ok) {	
				init(true);
			}
			return;
		}
	}
	if (!m_isSupportBreakPoint)//只有第一次记录 大小
		m_totalByte = bytesTotal;

	m_bytesReceived = bytesReceived;
    if (bytesTotal == -1) {
		progressBar->setValue(0);
		progressBar->setMaximum(0);
    } else {
		progressBar->setValue(bytesReceived + m_bytesCurrentReceived);
		progressBar->setMaximum(bytesTotal + m_bytesCurrentReceived);
    }

    updateInfoLabel();
    update();
}


void ZWebDownloadItem::metaDataChanged()
{
	qDebug() << "zcd-0x00000074:" << "DownloadItem::metaDataChanged: not handled.";
}

void ZWebDownloadItem::updateInfoLabel()
{
	qint64 bytesTotal = progressBar->maximum();
	qint64 bytesReceived = m_bytesReceived + m_bytesCurrentReceived;
    // update info label
	double speed = bytesReceived * 1000.0 / m_downloadTime.elapsed();
	double timeRemaining = ((double)(bytesTotal - bytesReceived)) / speed;
    QString timeRemainingString = QString::fromLocal8Bit("秒");
    if (timeRemaining > 60) {
        timeRemaining = timeRemaining / 60;
        timeRemainingString = QString::fromLocal8Bit("分钟");
    }
    timeRemaining = floor(timeRemaining);

    // When downloading the eta should never be 0
    if (timeRemaining == 0)
        timeRemaining = 1;

    QString info;
    if (!downloadedSuccessfully()) {
        QString remaining;
        if (bytesTotal != 0)
            remaining = QString::fromLocal8Bit("- 剩余 %4 %5 ")
                    .arg(timeRemaining)
                    .arg(timeRemainingString);
        info = QString::fromLocal8Bit("%1 共 %2 (%3/秒) %4 %5")
			.arg(dataString(bytesReceived))
                .arg(bytesTotal == 0 ? tr("?") : dataString(bytesTotal))
                .arg(dataString((int)speed))
                .arg(remaining)
				.arg(progressBar->text());
    } else {
		if (bytesReceived != bytesTotal) {

			info = QString::fromLocal8Bit("%1 共 %2 - 停止")
				.arg(dataString(bytesReceived))
				.arg(dataString(bytesTotal));

        } else
			info = dataString(bytesReceived);
    }
	switch (m_downloadStatus)
	{
	case STOP:
		info.append(QString::fromLocal8Bit("  停止..."));
		break;
	case SUSPEND:
		info.append(QString::fromLocal8Bit("  暂停..."));
		break;
	case DOWNLOADING:
		info.append(QString::fromLocal8Bit("  下载中..."));
		break;
	case FILISH:
		info.append(QString::fromLocal8Bit("  下载完成..."));
	default:
		break;
	}
    downloadInfoLabel->setText(info);
}

QString ZWebDownloadItem::dataString(int size) const
{
    QString unit;
    if (size < 1024) {
        unit = tr("bytes");
    } else if (size < 1024*1024) {
        size /= 1024;
        unit = tr("kB");
    } else {
        size /= 1024*1024;
        unit = tr("MB");
    }
    return QString(QLatin1String("%1 %2")).arg(size).arg(unit);
}

bool ZWebDownloadItem::downloading() const
{
    return (this->isVisible());
}


bool ZWebDownloadItem::downloadedSuccessfully() const
{
    return (stopButton->isHidden() && tryAgainButton->isHidden());
}

void ZWebDownloadItem::finished()
{
	progressBar->setValue(0);
	progressBar->hide();
    openDirButton->setEnabled(true);
    openDirButton->show();
    openButton->setEnabled(true);
    openButton->show();
    stopButton->setEnabled(false);
    stopButton->hide();
    suspendButton->setEnabled(false);
    suspendButton->hide();
    m_output.close();
	m_downloadStatus = FILISH;
    updateInfoLabel();
    emit statusChanged();
}

void ZWebDownloadItem::error(QNetworkReply::NetworkError erroNet)
{
   // qDebug() << "DownloadItem::error" << m_download->errorString() << m_url;
    m_downloadStatus = STOP;
    setButton();
   // downloadInfoLabel->setText(tr("Network Error: %1").arg(m_download->errorString()));
}

//停止
void ZWebDownloadItem::on_stopButton_clicked()
{
	if (m_downloadStatus == DOWNLOADING)
		on_suspendButton_clicked();
	removeFiles();
    m_bytesCurrentReceived = 0;
	//m_downloadThread->removeFile();
    m_downloadStatus = STOP;
    setButton();
}

//暂停
void ZWebDownloadItem::on_suspendButton_clicked()
{
	if (m_downloadThread != NULL)
    {
		m_downloadThread->suspendDownload();
		disconnect(m_downloadThread, SIGNAL(finished_signal()), this, SLOT(finished()));
		disconnect(m_downloadThread, SIGNAL(error_signal(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
		disconnect(m_downloadThread, SIGNAL(threadReadProgress(qint64, qint64)),
			this, SLOT(downloadProgress(qint64, qint64)));
		m_downloadThread->deleteLater();
		m_downloadThread = NULL;
    }
    m_downloadStatus = SUSPEND;
    setButton();
	m_bytesCurrentReceived += m_bytesReceived;
}

//下载继续
void ZWebDownloadItem::on_continuePushButton_clicked()
{
    init(true);
}

void ZWebDownloadItem::onOpenDirBtn()
{
    QFileInfo fileInfo(m_output);
    QString	strDirPath = fileInfo.absoluteDir().absolutePath();
    QDesktopServices::openUrl(strDirPath);
}

void ZWebDownloadItem::on_openButton_clicked()
{
    QFileInfo info(m_output);
    QUrl url = QUrl::fromLocalFile(info.absolutePath() + "/" + info.fileName());
    QDesktopServices::openUrl(url);
}

QString ZWebDownloadItem::getdownloadInfoLabelText()
{
    return downloadInfoLabel->text();
}

bool ZWebDownloadItem::stopIsEnabled()
{
    return stopButton->isEnabled();
}

void ZWebDownloadItem::errotTxetSlot(int number, QString text)
{
	if (number == 0)
	{
		downloadInfoLabel->setText(text);
	}
	on_stopButton_clicked();
	emit statusChanged();
}


// 删除文件;
void ZWebDownloadItem::removeFiles()
{
	QFileInfo fileInfo(m_output);
	if (fileInfo.exists())
	{
		QFile::remove(fileInfo.filePath() + "/" + fileInfo.fileName());
	}
}