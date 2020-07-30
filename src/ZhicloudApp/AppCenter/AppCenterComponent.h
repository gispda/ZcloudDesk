#pragma once

#include <QObject>
#include <QPushButton>
#include <QFocusEvent>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QPainter>
#include <QEventLoop>
#include <QTimer>
#include <QDesktopServices>
#include <QString>
#include <QDebug>
#include <QTime>
#include <QMenu>
#include <QAction>
#include <QToolButton>
#include <QWidget>
#include "ZhicloudAppDataDefine.h"
#include "publicWidgets/squeezelabel.h"
#include "AppCommWidget.h"

class AppDownLoadThread;

class AppCenterComponent : public QObject
{
	Q_OBJECT

public:
	AppCenterComponent(QObject *parent);
	~AppCenterComponent();
};



class AppCenterTools;
class AppDownLoadItem;


//并排五个应用
class SliderWidget : public QWidget
{
	friend class AppCenterWidget;
	friend class AppCenterHomeWidget;
	Q_OBJECT
public:
	SliderWidget(QWidget *parent);
	~SliderWidget();
	void clearButton();
private:
	QVector<AppCenterTools*> listApp;
	void resetInterface();
public:
	//添加一个应用
	void addApp(AppCenterTools *);
};

class PhotoWidget : public QWidget
{
	Q_OBJECT
public:
	PhotoWidget(QWidget *parent);
	~PhotoWidget();
	void clearLabel();
	void addPhoto(SliderInfo);
	void setPhoto(int newLabel);
	void addFlish();
protected:
	void keyPressEvent(QKeyEvent *event);
	bool eventFilter(QObject *target, QEvent *e);
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);

private:
	void moveCurrentPage(bool direction);
	//开始移动标志位
	void setLabelMove(bool enable);
	void resetInterface();
signals:
	void chooseLabelSignal(int);
	void openAppParticularsSig(QString);
private slots:
	void rightPhotoSlot();
	void leftPhotoSlot();
private:
	QWidget *totalWidget;
	QTimer *timer;
	QPushButton *m_rightButton = NULL;
	QPushButton *m_leftButton = NULL;
	bool wideget_move = true;
	int current_index = 1;
	QList<SliderInfo> sliderInfoList;
	QList<QLabel* > labelListPhoto;
	

};



class AppDownLoadAppWidget : public AppCommWidget
{
	Q_OBJECT
public:
	AppDownLoadAppWidget(QWidget *parent = 0);
	void addDownload(AppDownLoadItem *);
	void showWindow();
private:
	~AppDownLoadAppWidget();
	void resetInterface();

	QLabel *noDownloadLabel;
	QWidget *downloadListWidget = NULL;
	QList<AppDownLoadItem *> listAppDownLoadItem;
	int removeItemAt = 0;
	int removeItemY = 0;
	QTimer *m_closeTimer = NULL;
	QLabel *m_doanloadSizeLabel = NULL;
protected:
	void focusOutEvent(QFocusEvent * e);
	void showEvent(QShowEvent *e);
private slots:
	void removeItem();
	void removeItemMoveItem();
};

class AppDownLoadItem : public QProgressBar
{
	Q_OBJECT
public:
	AppDownLoadItem(AppDownLoadThread *downloadThread , QWidget* parent = 0);
	AppDataInfo m_deskInfo;
	APPDOWNLOADETYPE getDownloadType()
	{
		return this->m_downloadStatus;
	};
	void updateInfoLabel();
private:
	QPushButton *continueDownloadButton;
	QPushButton *reBeginDownloadButton;
	QPushButton *endDownloadButton;
	QPushButton *pauseDownloadButton;
	//QProgressBar *m_progressBar;
	SqueezeLabel *downloadInfoLabel;
	QLabel *downloadPercentageLabel = NULL;
	QTime m_downloadTime;
	APPDOWNLOADETYPE m_downloadStatus;
private slots:
	//重新下载
	void onDownLoadReBegin();
	//暂停下载
	void onDownLoadPause();
	//继续
	void onDownLoadContinue();
	//删除下载
	void onDownLoadEnd();

public slots:
	void onStatusChanged(APPDOWNLOADETYPE type);
	//更新进度
	void onDownloadProcess(qint64, qint64);
signals:
	void sigReBeginDownload();
	void sigContinueDownLoad();
	void sigPauseDownLoad();
	void sigEndDownLoad();
	//item的状态改变 
	void itemCownloadChange();
private:
	
	QString dataString(int size) const;
};



class AtegoryButton : public QPushButton
{
	Q_OBJECT
public:
	AtegoryButton(int flag, QWidget *parent);
	~AtegoryButton();

private:

protected:
	//virtual void	paintEvent(QPaintEvent* event);
};



class AppCenterItemPushButton : public QPushButton
{
	Q_OBJECT
public:
	AppCenterItemPushButton(QWidget *parent = NULL);
public:
	void showToolBtutton()
	{
		menuToolButton->setGeometry(99, 13, 14, 14);
		menuToolButton->setStyleSheet("QToolButton{border-radius:7px;border-image: url(:/new/imageFile/AppCenterPng/toolMenu.png);}");
		connect(menuToolButton, SIGNAL(clicked()), this, SLOT(showMenu()));
		menuToolButton->show();
	};
	void hideToolButton()
	{
		if (menuToolButton)
			menuToolButton->hide();
	};
private:
	QMenu *m_menu;
	QAction *m_actionUpdate;
	QAction *m_actionUninstall;
	QToolButton *menuToolButton;
signals:
	void actionUninstallSignal();
protected slots:
	void showMenu();
};

