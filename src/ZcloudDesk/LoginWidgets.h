#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QTimer>
#include <QNetworkProxy>
#include <QLabel>
#include <QMovie>
#include <QPushButton>
#include <QFuture>
#include <QComboBox>
#include "LoginThread.h"


class LoginLineEdit : public QLineEdit
{
	Q_OBJECT
public:
	LoginLineEdit(QWidget *parent, QString placeholder = "");
	void errorStyle();
protected:
	virtual void mousePressEvent(QMouseEvent *event);
signals :
	void focusInSignal();
	void focusOutSignal();
private:
	bool m_isError = false;

};



/*/////////////////////////////////////////////
��������
////////////////////////////////////////////*/
class LoginSetWidget : public QWidget
{
	Q_OBJECT

public:
	LoginSetWidget(QWidget *parent);
	~LoginSetWidget();
signals:
	void cancelButtonSignals();
	void lodingStartSiganl();
	void lodingFilishSiganl();
private slots:
	//ȷ�����ô���
	void checkclicked();
	//���Դ���
	bool testClicke();
	void setTypeCurentIndexChanged(int);
private:
	//��ȡ���õ� QNetworkProxy
	QNetworkProxy getNetworkProxy();
protected:
	bool eventFilter(QObject *target, QEvent *e);
private:
	LoginLineEdit *setAddrLineEdit = NULL;
	LoginLineEdit *setPortLineEdit = NULL;
	LoginLineEdit *setAccountLineEdit = NULL;
	LoginLineEdit *setPasswordLineEdit = NULL;
	LoginLineEdit *setRegionLineEdit = NULL;

	QLabel *testSetLael = NULL;
	QLabel *tipSetLael = NULL;
	//��ǰѡ��Ĵ���
	int m_typeCurentIndex = 0;
};

/*/////////////////////////////////////////////
�˺������¼
////////////////////////////////////////////*/
class LoginWidget : public QWidget
{
	Q_OBJECT
	friend class LoginDialog;
public:
	LoginWidget( QWidget *parent);
	~LoginWidget();
	UserInfoStruct m_userInfoStruct;
	//�ж����˺ŷ��Զ���¼
	bool isUserNameLogin()
	{
		return (!m_loginSetingStruct.loginByTax && !m_loginSetingStruct.autoLogin);
	};
	void setShowDownloadSoftware(int);
signals:
	void lodingStartSiganl();
	void lodingFilishSiganl();
	void logingSucceed();
	void qrChartLoginSingal();
	void installSoftwareSignal();
private slots:
	void onLoginButtonClicked();
	//������¼��ʽ����¼    0  ʧ��  1 �ɹ�  2 ��Ҫ��װ��Ʊ���
	int checkLogin(QString &tipStr);

protected:
	bool eventFilter(QObject *target, QEvent *e);
private:
	//�޸ĵ�¼��ʽ
	void changeLoginMethod(int statusFlag, bool isClear = true);
private slots:
	void loginFinish(int stataus, UserInfoStruct userInfoStruct);
	void getFinish(int status);

private:
	QLabel *statusLoginLabel = NULL;
	QLabel *statusLoginLabel_2 = NULL;
	LoginLineEdit *accountLineEdit = NULL;
	LoginLineEdit *passwordLineEdit = NULL;
	LoginLineEdit *passwordLineEdit_2 = NULL;
	LoginLineEdit *verificationCodeLineEdit = NULL;

	QLabel *m_hintLabel_1 = NULL;
	QLabel *m_hintLabel_2 = NULL;
	QLabel *m_hintLabel_3 = NULL;

	QLabel *tipLabel = NULL;
	QPushButton *loginButton = NULL;
	QLabel * forgetPasswordLabel = NULL;
	QLabel * verificationCodeLabel = NULL;
	QTimer *timer = NULL;
	int timerInt = 60;

	QLabel *registerLael = NULL;
	QLabel *weChartLoginLabel = NULL;

	LoginThread *m_loginThread = NULL;
	LoginSetingStruct m_loginSetingStruct;

	//��ȡ˰��
	void getTaxInfo(QString &taxNo, QString &staMachine);
	//��ȡ����
	bool loginNotNet(QString &tipSt);

	QPushButton *installSoftwareButton = NULL;


	QString m_strId = "";
	QString m_strPw = "";
};


/*/////////////////////////////////////////////
΢�ŵ�¼
////////////////////////////////////////////*/
class LoginWeChartWidget : public QWidget
{
	Q_OBJECT
		friend class LoginWidget;
public:
	LoginWeChartWidget(int logingIn,QWidget *parent);
	~LoginWeChartWidget();
	void getQRCode();
	void closeLoginWeChartWidget()
	{
		while (future.isRunning())
		{
			this->isLodingPhoto = false;
			this->isGetStatus = false;
			::_sleep(250);
			continue;
		}
	};
signals:
	//0���л���¼��ʽ��1����¼��loding��ʼ 2����¼ʧ��lodingֹͣ
	void changeLoginWaySiganl(int );
	void weChartLoginSucceed(UserInfoStruct);
	void showWCWidgetSignals(int);
	//��װ��Ʊ���
	void installSoftwareSignal();
protected:
	bool eventFilter(QObject *target, QEvent *e);
private:
	void initBindingWidget();
	void getNetworkPic();
	//��ȡ�û�ɨ��״̬
	void getStatus();
	void analysisUserData(QJsonObject jsonObject, UserInfoStruct &userInfoStruct);
	//��ȡ�����ϵ�ͷͼƬ
	QPixmap getNetworkPic(QString strUrl);
	
private slots:
	void showWCWidget(int i);
	void bindingFlishSlot(int status, UserInfoStruct userInfoStruct);
private:
	QFuture<void> future;
	volatile bool isLodingPhoto = false;
	volatile bool isGetStatus = false;
	volatile bool isGetCode = false;
	QLabel *QRCodeLabel = NULL;
	QLabel *phoneLoginLabel = NULL;
	QString strPkid;
	QWidget *bindingPhoneWidget = NULL;
	QWidget *getQRCodeWidget = NULL;
	QMovie *qrCMovie = NULL;
	QTimer *bindingTimer = NULL;
	int bindingTimerInt = 60;
	LoginThread *m_bindingThread = NULL;

	QLabel *bindingLabel = NULL;
	QLabel *bindingLabel_2 = NULL;
	QLabel *wCharPhotoLabel = NULL;
	QLabel *m_bindingHintLabel = NULL;
	QLabel *m_bindingHintLabel_2 = NULL;
	LoginLineEdit *accountLineEdit = NULL;
	LoginLineEdit *verificationCodeLineEdit = NULL;
	QLabel *verificationCodeLabel = NULL;
	QPushButton *bindingButton = NULL;
};



class BindingEinWidget : public QWidget
{
	Q_OBJECT
public:
	BindingEinWidget(QStringList phoneNumberList, QWidget *parent = 0);
	~BindingEinWidget();

signals:
	//0���л���¼��ʽ��1:����loding��ʼ 2����ʧ��lodingֹͣ
	void changeLoginWaySiganl(int);
	//�󶨳ɹ�
	void bindingEinSoucces(UserInfoStruct userInfo);
private slots:
	void putInButtonSlot();
	void getFilishSlot(int status, UserInfoStruct);
protected:
	bool eventFilter(QObject *target, QEvent *e);
private:
	QPushButton *putInButton = NULL;
	QComboBox *numberComboBox = NULL;
	LoginThread *m_bindingThread = NULL;
	QLabel *m_changeBindingWayLabel = NULL;
	QStringList m_listPhoneNumberList;
	QLabel *m_tipLabel = NULL;

};

