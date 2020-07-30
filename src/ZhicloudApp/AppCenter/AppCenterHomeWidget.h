#pragma once

#include <QWidget>
#include "ui_AppCenterHomeWidget.h"
#include "AppCenterComponent.h"

class AppCenterHomeWidget : public QWidget
{
	Q_OBJECT
	friend class AppCenterWidget;
public:
	AppCenterHomeWidget(QWidget *parent = Q_NULLPTR);
	~AppCenterHomeWidget();
	void initHomeWidget();
	bool openHomeError(AppDataInfo pData);
	void changedToolButtonStatus(QString appId, APPSTATUS partFlag);
private:
	Ui::AppCenterHomeWidget ui;
	void clearHomeWidget();
	//void connectHomeApp(AppCenterTools *appCenterTools,QString appId);
private:
	//��ҳ
	PhotoWidget *m_photoWidget = NULL;
	QMap<QPushButton *, QString> nameButtonMap;
	QButtonGroup *m_nameButtonGroup = NULL;
	SliderWidget *m_sliderWidget = NULL;
	//��ҳСԲ�� ��ť 
	QList<QPushButton * > listButton;
	QList<AppCenterTools *> hotAppToolsList;
private slots:
	void clickedButtonSLot(bool);
	void set_circleButton(int circleNumber);
	//���һ���Ƽ����
	void clickedNameButtonSlot();
};
