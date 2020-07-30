#pragma once

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QThread>
#include <QComboBox>
#include <QNetworkProxy>
#include "LoginWidgets.h"




class LoginDialog : public QDialog
{
	Q_OBJECT

public:
	LoginDialog(bool bShowMinBtn = true, QWidget *parent = NULL);
	~LoginDialog();
	void initWeChartWidget(int logingInt = 0);
	void initBindingEinWidget();
	UserInfoStruct getUserInfoStruct()
	{
		return loginWidget->m_userInfoStruct;
	};

	QString getPhoneNumber()
	{
		return loginWidget->m_userInfoStruct.m_strMobile;
	}

	//判断是账号非自动登录
	bool isUserNameLogin()
	{
		return loginWidget->isUserNameLogin();
	};
	
	int checkLogin(QString &tipStr)
	{
		return  loginWidget->checkLogin(tipStr);
	};

protected:
	void paintEvent(QPaintEvent*	event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent *event);

private:
	void initSetWidget();
	void initLoginDialog(bool bShowMinBtn = true);
private:
	QPixmap	m_bg;
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;

	
	LoginWidget *loginWidget = NULL;
	LoginSetWidget *setWidget = NULL;
	LoginWeChartWidget *weChartWidget = NULL;
	BindingEinWidget *bindingEinWidget = NULL;
	QPushButton *setButton = NULL;
	QLabel *lodingLabel = NULL;
	QMovie *movie = NULL;
	
private slots:
	void onSetButtonClicked();
	void onCancelButtonClicked();
	void loadgingStartSlot();
	void loadgingFilish();

	void isAccept();
	void wxLoginSoucceedSlog(UserInfoStruct userInfoStruct);
	void installSoftwareSlot();
private:
	//默认在账密窗口
	int widgetFlag = 0;
};
