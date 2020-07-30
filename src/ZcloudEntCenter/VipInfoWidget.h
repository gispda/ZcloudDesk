#pragma once

#include <QWidget>
#include "ui_VipInfoWidget.h"
#include "qevent.h"
#include "WebView.h"
#include <QPushButton>

class VipInfoWidget : public QWidget
{
	Q_OBJECT

public:
	VipInfoWidget(QString strUid,QString strToken,QString strUrl,QWidget *parent = Q_NULLPTR);
	~VipInfoWidget();

	void showWindow(QString strUrl);
signals:
	void sendVipListSignals(QStringList vipNameList, QStringList vipIdList, QStringList vipTimeList);
	void bingdingPhoneSignal();
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:
	void onLoadFinished(bool);
	//提示绑定手机号
	void vipWidgetBingdingPhone();
	void onGetVipList(const QString& strJson);
	void getNewUserIdToken(const QString, const QString);
private:
	Ui::VipInfoWidget ui;
	QPoint dPos;
	WebView*		m_pWebView = NULL;
	QPushButton*	m_pCloseBtn = NULL;
	QString			m_strUrl;
};
