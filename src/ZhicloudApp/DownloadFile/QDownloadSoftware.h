//!���ؿ�Ʊ�����Զ�̷���
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
	//  ��Ʊ���  ����     1���˳̷���   2��װ��Ʊ 3�Ƕ���Ӧ��    main��(false)������ ����  ��װ��Ʊ��true�� 
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
	// 0 ��Ʊ���  ����     1���˳̷���   2��װ��Ʊ
	int     m_nDownloadType;
	QString m_url;
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;
	DownLoadThread * m_pDownloadThread;
	qint64	m_bytesReceived;
	QTime m_downloadTime;
	QStringList strCodeList;
	volatile bool m_downloadErrorFlag;//���س���� ��־λ �ý��� ������  ���ؽ��ȵĲۺ���


	QPushButton *downMiniPushButton = NULL;
	QPushButton *downClosePushButton = NULL;
	QPushButton *pushButton = NULL;
	//QLabel *downloadInfoLabel = NULL;
	QLabel *speedLabel = NULL;
	QProgressBar *progressBar = NULL;
	QLabel *progressLabel = NULL;

};

#endif // DOWLOADFILE_H
