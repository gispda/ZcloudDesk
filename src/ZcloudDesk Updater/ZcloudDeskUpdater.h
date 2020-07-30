#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ZcloudDeskUpdater.h"
#include "qevent.h"

class ZcloudDeskUpdater : public QMainWindow
{
	Q_OBJECT

public:
	ZcloudDeskUpdater(QString strUrl,QString strMd5,bool bShowWindow,QWidget *parent = Q_NULLPTR);

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:
	void onTimerOut();
	void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
private:
	//!��ʼ����
	bool startWork();

	//!����
	bool download(QString strDownloadUrl, QString strMd5, QString& strFileName);

	//!���سɹ�����
	bool downloadSucessed(QString strFileName);

	QPoint dPos;
	Ui::ZcloudDeskUpdaterWidget ui;
	QString m_strDownloadUrl;
	QString m_strMd5;
	bool	m_bShowWindow = false;
	QTimer*	m_pTimer = NULL;
};
