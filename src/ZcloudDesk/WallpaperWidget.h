#ifndef WALLPAPERWIDGET_H
#define WALLPAPERWIDGET_H

#include <QWidget>
#include "ui_WallpaperWidget.h"
#include "qevent.h"
#include "AppCommWidget.h"
#include "WebView.h"

class WallpaperWidget : public AppCommWidget
{
	Q_OBJECT

public:
	WallpaperWidget(QString strUrl,QWidget *parent = 0);
	~WallpaperWidget();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private slots:
	void onLoadFinished(bool);
	void onDownloadLink(const QString&);
private:
	void  setWallPaper(QString strPicPath);

	WebView*	m_pWebView = NULL;
	Ui::WallpaperWidget ui;
	QPoint dPos;
};

#endif // WALLPAPERWIDGET_H
