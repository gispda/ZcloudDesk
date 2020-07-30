//!下载开票软件和远程服务
#ifndef DOWLOADFILE_H
#define DOWLOADFILE_H

#include <QDialog>
#include <QTime>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include "DownLoadThread.h"
#include "publicWidgets/AppCommDialog.h"

class  QDownloadSoftware : public AppCommDialog
{
	Q_OBJECT

public:
	//  开票软件  下载     1是运程服务   2重装开票 3是顶栏应用    main中(false)的下载 还是  重装开票（true） 
	QDownloadSoftware(int nDownloadType, QString url,  QWidget *parent = 0);
	~QDownloadSoftware();
signals:
	void sigInstallFinlished(QString, bool);
	void switchEinSignal(QString, QString);
private slots:
	
void downClose();

	void onDownloadProcess(qint64 bytesReceived, qint64 bytesTotal);
	void resetPushButton();

	void downloadFinish(int, QString filePath);
	void downloadError(QString);

	void installFilish(bool installFlag);
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	virtual void closeEvent(QCloseEvent *event);
private:
	void updateInfoLabel();
	QString dataString(int size) const;
	void startDownload();

private:
	// 0 开票软件  下载     1是运程服务   2重装开票
	int     m_nDownloadType;
	QString m_url;
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;
	DownLoadThread * m_pDownloadThread;
	qint64	m_bytesReceived;
	QTime m_downloadTime;
	QStringList strCodeList;
	volatile bool m_downloadErrorFlag;//下载出错的 标志位 让界面 不触发  下载进度的槽函数


	QPushButton *downMiniPushButton = NULL;
	QPushButton *downClosePushButton = NULL;
	QPushButton *pushButton = NULL;
	//QLabel *downloadInfoLabel = NULL;
	QLabel *speedLabel = NULL;
	QProgressBar *progressBar = NULL;
	QLabel *progressLabel = NULL;

};

#endif // DOWLOADFILE_H
