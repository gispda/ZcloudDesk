#ifndef ZWEBDOWNLOADITEM_H
#define ZWEBDOWNLOADITEM_H

#include <QWidget>
#include <QFileInfo>
#include <QDir>
#include <QProgressBar>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QScopedPointer>
#include <QTime>
#include <QSettings>
#include <QStandardPaths>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include "ZWebViewBrowser/zwebdownloadthread.h"
#include "ui_zwebdownloaditem.h"
enum DownloadStatus
{
    STOP,           //停止
    SUSPEND,        //暂停
    DOWNLOADING,    //下载中
	FILISH			//下载完成
};

class ZWebDownloadItem : public QWidget, public Ui_ZWebDownloadItem
{
    Q_OBJECT

public:
    explicit ZWebDownloadItem(QNetworkReply *download, QWidget *parent = 0);
    ~ZWebDownloadItem();

signals:
    void statusChanged();

public:
    void setButton();
    void setIcon(QIcon);
    void setFileNameLabel(QString text);
    bool downloading() const;
    bool downloadedSuccessfully() const;

    void init(bool isSupportBreakPoint = false);
    void getFileName(bool promptForFileName = false);

    QString getdownloadInfoLabelText();
    bool stopIsEnabled();
private slots:
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void finished();

    void on_stopButton_clicked();
    void onOpenDirBtn();
    void on_openButton_clicked();

	void errotTxetSlot(int, QString);
    void error(QNetworkReply::NetworkError);
    void tryAgain();
    void metaDataChanged();
    void on_suspendButton_clicked();
    void on_continuePushButton_clicked();
    void onClose();
private:
    friend class ZWebDowloadManager;
    void updateInfoLabel();
    QString dataString(int size) const;
	void removeFiles();
    QUrl m_url;
    QFile m_output;
	QString m_fileName;
    qint64 m_bytesReceived;				//当前下载的
    qint64 m_bytesCurrentReceived;		//断点 续传之前的字节
	qint64 m_totalByte;					//文件总大小
    QTime m_downloadTime;
    DownloadStatus m_downloadStatus;

	ZWebDownloadThread *m_downloadThread;

	bool m_isSupportBreakPoint;
    QNetworkReply * m_download;
    QNetworkAccessManager* m_networkManager;
    QString saveFileName(const QString &directory) const;
};

#endif // ZWEBDOWNLOADITEM_H
