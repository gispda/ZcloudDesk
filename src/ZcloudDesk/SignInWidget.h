#pragma once

#include <QDialog>
#include "ui_SignInWidget.h"
#include "ZcloudCommonWidget.h"
class SignInTipWidget :public QDialog
{
	Q_OBJECT
public:
	SignInTipWidget(int nBaseReward, int nExtraReward, int nSignDay,QWidget *parent = Q_NULLPTR);
	~SignInTipWidget();

private:
	QWidget*m_pWidget = NULL;
	QLabel*	m_pLabel1 = NULL;
	QLabel*	m_pLabel2 = NULL;
	QLabel*	m_pLabel3 = NULL;
	QLabel*	m_pLabel4 = NULL;
	QPushButton*	m_pOkBtn = NULL;
};
class SignInWidget : public ZcloudCommonWidget
{
	Q_OBJECT

public:
	SignInWidget(QString strUid,QString strToken,QWidget *parent = Q_NULLPTR);
	~SignInWidget();
signals:
	void showAdvertPic(QString);
	void sigAdvertisingClick(int ,QString);
	void modifyCoinCount(int);
protected:
	bool eventFilter(QObject *target, QEvent *e);
private slots:
	void signInBtnClick();
	void loadAdvertPic(QString strPicPath);
	void onShowAdvertPic(QString strPicPath);
private:
	//!��ʾ����
	bool showDetails();

	//!ǩ������
	bool winHttpSignInDetails(QString strUid, QString strToken, QString& strRet);

	//!ǩ�����������
	bool winHttpAdvertClickCount(QString strUid, QString strToken, QString strAdvertId);

	//!ǩ��
	bool winHttpDoSign(QString strUid, QString strToken, QString& strRet);

	QString		m_strUid;
	QString		m_strToken;
	int			m_nTargetType;
	int			m_nCoinCount;
	QString		m_strTarget;
	QString		m_strAdvertId;
	bool		m_bClickAdvert = false;
	Ui::SignInWidget ui;
};
