#pragma once
#include <QWidget>
#include "ui_TopToolWidget.h"
#include "qevent.h"
#include "CommWidget.h"
#include "Database.h"
#include <QMutex>
#include "AppCommWidget.h"
class TopToolWidget :public AppCommWidget
{
	Q_OBJECT

public:
	TopToolWidget(TopToolInfo* pInfo,QWidget *parent = Q_NULLPTR);
	~TopToolWidget();
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:
	void onAppBtnClick();

private:

	void setVerScrollBarStyle();

	//!Ω‚Œˆ”¶”√
	void analysisAppArray();

	QMap<QToolButton*, QString>	m_mpAppBtn;
	TopToolInfo* m_pInfo;
	Ui::TopToolWidget ui;
	QMutex	m_mutex;
	QPoint dPos;
};
