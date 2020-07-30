#include "LoginWidgets.h"
#include <QComboBox>
#include <QStyledItemDelegate>
#include <QNetworkReply>
#include <QSettings>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QDesktopServices>
#include <QLibrary>
#include <QJsonParseError>
#include <QJsonObject>
#include <QtConcurrent/QtConcurrentRun>
#include <QPainter>
#include <QJsonArray>
#include "HttpInterface.h"
#include "ZcloudCommon.h"
#include "ZcloudBigData.h"



extern QString zhicloudStrToken;
extern QString zhicloudStrUserId;
extern QString g_strAppName;
LoginLineEdit::LoginLineEdit(QWidget *parent, QString placeholder)
	:QLineEdit(parent)
{
	//setAlignment(Qt::AlignBottom);
	//setStyleSheet(QString::fromLocal8Bit("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';}"
	//	"QLineEdit:laceholder{color:rgba(51,51,51,1);}"
	//	"QLineEdit:focus{border-style:outset;border-radius:4px;border:1px solid rgb(222,222,222);color:rgba(51,51,51,1); background-color:rgb(255, 255, 255);border-left:4px solid rgb(23,146,241);}"
	//	"QLineEdit:disabled{background-color: rgb(247,248, 250);};"
	//	));
	//
	setStyleSheet(QString::fromLocal8Bit("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';}"
		"QLineEdit:laceholder{color:rgba(51,51,51,1);}"
		"QLineEdit:focus{border:1px solid rgba(30,140,238,1);}"
		"QLineEdit:disabled{background-color: rgb(247,248, 250);};"
		));
	//!设置文字与左边框间距
	setTextMargins(4, 0, 0, 0);
	//!设置提示内容
	if (!placeholder.isEmpty())
		setPlaceholderText(placeholder);
	setMaxLength(20);
}

void LoginLineEdit::errorStyle()
{
	//border:1px solid rgba(241,0,32,1);
	setStyleSheet(QString::fromLocal8Bit("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(241,0,32);font:14px 'Microsoft Yahei';}"
		"QLineEdit:laceholder{color:rgba(51,51,51,1);}"
		//"QLineEdit:focus{border-style:outset;border-radius:4px;border:1px solid rgb(222,222,222);color:rgba(51,51,51,1); background-color:rgb(255, 255, 255);border-left:4px solid rgb(23,146,241);}"
		"QLineEdit:focus{border:1px solid rgba(30,140,238,1);}"
		"QLineEdit:disabled{background-color: rgb(247,248, 250);};"
		));
	m_isError = true;
}

void LoginLineEdit::mousePressEvent(QMouseEvent *event)
{
	if (m_isError)
	{
		setStyleSheet(QString::fromLocal8Bit("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';}"
			"QLineEdit:laceholder{color:rgba(51,51,51,1);}"
			//"QLineEdit:focus{border-style:outset;border-radius:4px;border:1px solid rgb(222,222,222);color:rgba(51,51,51,1); background-color:rgb(255, 255, 255);border-left:4px solid rgb(23,146,241);}"
		"QLineEdit:focus{border:1px solid rgba(30,140,238,1);}"
			"QLineEdit:disabled{background-color: rgb(247,248, 250);};"
			));
		m_isError = false;
	}
	return QLineEdit::mousePressEvent(event);
}

class LoginComboBox : public QComboBox
{
public:
	LoginComboBox(QWidget *parent = NULL);

private:
protected:
};


LoginComboBox::LoginComboBox(QWidget *parent)
	: QComboBox(parent)
{

	//用于下拉框item的样式美化
	QStyledItemDelegate* itemDelegate = new QStyledItemDelegate();

	this->setItemDelegate(itemDelegate);

	this->setStyleSheet("QComboBox QAbstractItemView {border-radius: 4px; color:rgba(153, 153, 153, 1);"
		"outline: 0px; font: 14px 'Microsoft Yahei';border:1px solid rgba(222, 222, 222, 1); }"
		"QComboBox QAbstractItemView::item{ height: 40px; border-style:none;}"
		"QComboBox QAbstractItemView::item:selected{color:rgba(153, 153, 153, 1); background-color: rgb(245, 246, 247); "
		"border:4px;}"// border-style:none none  none solid; border-color: rgba(23, 146, 241, 1); }"
		"QComboBox{ border-radius: 4px; color:rgba(153, 153, 153, 1); border:1px solid rgba(222, 222, 222, 1);"
		" background-color: rgb(255, 255, 255); font: 14px 'Microsoft Yahei'; }"
		//"QComboBox:focus{ border-style:outset; border-radius: 4px; border:1px solid rgba(222, 222, 222, 1); color:rgba(153, 153, 153, 1); "
		//"background-color: rgb(255, 255, 255); border-left:4px solid rgba(23, 146, 241, 1); }"
		"QComboBox:focus{border:1px solid rgba(30,140,238,1);}"
		"QComboBox::drop-down {subcontrol-origin: padding; subcontrol-position: top right; width: 32px;"
		" border-top-right-radius:4px;	"
		" border-bottom-right-radius: 4px;}"
		"QComboBox:down-arrow{image: url(:/ZcloudDesk/image/comboBoxDownArrow.png);}"
		);


}



//////////////////////////////////////////////////////////////////////////////////////////////
LoginWidget::LoginWidget(QWidget *parent)
	: QWidget(parent)
	, m_loginThread(new LoginThread(this))
	, timer(new QTimer(this))
{
	statusLoginLabel = new QLabel(this);
	statusLoginLabel->setStyleSheet("QLabel{font: 24px 'Microsoft YaHei';font-weight:bold;color: rgb(51, 51, 51);}");
	statusLoginLabel->setGeometry(48, 30, 200, 30);
	statusLoginLabel_2 = new QLabel(this);
	statusLoginLabel_2->installEventFilter(this);
	statusLoginLabel_2->setCursor(Qt::PointingHandCursor);

	//QLabel *accountLabel = new QLabel(QString::fromLocal8Bit("账号"), loginWidget);
	//QLabel *passwordLabel = new QLabel(QString::fromLocal8Bit("密码"), loginWidget);
	//accountLabel->setStyleSheet("QLabel{font: 14px 'Microsoft YaHei';font-weight:400;color: rgb(102, 102, 102);}");
	//passwordLabel->setStyleSheet("QLabel{font: 14px 'Microsoft YaHei';font-weight:400;color: rgb(102, 102, 102);}");
	//accountLabel->setGeometry(48, 105, 30, 15);
	//passwordLabel->setGeometry(48, 200, 30, 15);
	accountLineEdit = new LoginLineEdit(this);
	verificationCodeLineEdit = new LoginLineEdit(this, QString::fromLocal8Bit("请输入验证码"));
	passwordLineEdit = new LoginLineEdit(this, QString::fromLocal8Bit("请输入8～20位登录密码"));
	passwordLineEdit->setEchoMode(QLineEdit::Password);


	m_hintLabel_1 = new QLabel(this);
	m_hintLabel_1->setAlignment(Qt::AlignLeft);
	m_hintLabel_1->setGeometry(48, 142, 300, 20);
	m_hintLabel_1->setStyleSheet("font: 14px 'Microsoft YaHei';color: rgb(241, 0, 32);");
	m_hintLabel_1->hide();
	m_hintLabel_1->setText(QString::fromLocal8Bit("账号"));

	m_hintLabel_2 = new QLabel(this);
	m_hintLabel_2->setAlignment(Qt::AlignLeft);
	m_hintLabel_2->setGeometry(48, 217, 300, 20);
	m_hintLabel_2->setStyleSheet("font: 14px 'Microsoft YaHei';color: rgb(241, 0, 32);");
	m_hintLabel_2->hide();
	m_hintLabel_2->setText(QString::fromLocal8Bit("验证码"));


	m_hintLabel_3 = new QLabel(this);
	m_hintLabel_3->setAlignment(Qt::AlignLeft);
	m_hintLabel_3->setGeometry(48, 292, 300, 20);
	m_hintLabel_3->setStyleSheet("font: 14px 'Microsoft YaHei';color: rgb(241, 0, 32);");
	m_hintLabel_3->hide();
	m_hintLabel_3->setText(QString::fromLocal8Bit("错误"));







	verificationCodeLabel = new QLabel(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font-size:14px 'Microsoft YaHei';font-weight:800; color:#dedede;\">|</span>"
		"<span style=\" font-size:14px;\"/><span style=\" font-size:14px; color:#1e8cee;\"> 获取验证码</span></p></body></html>"), this);
	verificationCodeLabel->installEventFilter(this);
	verificationCodeLabel->setCursor(Qt::PointingHandCursor);
	verificationCodeLabel->setGeometry(275, 177, 130, 20);
	verificationCodeLabel->raise();

	tipLabel = new QLabel(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font-size:14px 'Microsoft YaHei'; color:#999999;\">注册代表您已同意</span>"
		"<span style=\" font-size:14px 'Microsoft YaHei'; font-weight:600; color:#666666;\">《%1用户使用协议》</span></p></body></html>").arg(g_strAppName), this);
	tipLabel->installEventFilter(this);
	tipLabel->setCursor(Qt::PointingHandCursor);
	tipLabel->setAlignment(Qt::AlignLeft);
	tipLabel->setGeometry(48, 380, 300, 20);
	tipLabel->hide();

	QRegExp phoneNumberExp("^1\\d{10}$");
	QValidator *validator = new QRegExpValidator(phoneNumberExp, accountLineEdit);
	accountLineEdit->setValidator(validator);

	registerLael = new QLabel(QString::fromLocal8Bit("<html><head/><body><p><span style=' font-size:12px 'Microsoft YaHei';'>账号注册</span></p></body></html>"), this);
	registerLael->setCursor(Qt::PointingHandCursor);
	registerLael->setStyleSheet("color: rgb(30, 140, 238);text-decoration: underline;font: 12px 'Microsoft YaHei';");
	registerLael->installEventFilter(this);
	registerLael->setGeometry(178, 305, 60, 15);

	forgetPasswordLabel = new QLabel(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font: 14px 'Microsoft YaHei';color:#666666;\">忘记密码？</span></p></body></html>"), this);
	forgetPasswordLabel->setGeometry(295, 230, 70, 20);
	forgetPasswordLabel->setCursor(Qt::PointingHandCursor);
	forgetPasswordLabel->installEventFilter(this);
	forgetPasswordLabel->hide();
	loginButton = new QPushButton(this);
	loginButton->setStyleSheet("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));"
		"border-radius:4px;font: 20px 'Microsoft YaHei';font-weight:400;color:rgba(255, 255, 255, 1);}"
		"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));"
		"border-radius:4px;font: 20px 'Microsoft YaHei';font-weight:400;color:rgba(255, 255, 255, 1);};");
	loginButton->setShortcut(QKeySequence::InsertParagraphSeparator);


	connect(loginButton, &QPushButton::clicked, this, &LoginWidget::onLoginButtonClicked);


	connect(timer, &QTimer::timeout, [this]{
		if (timerInt > 0)
		{
			verificationCodeLabel->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font-size:14px 'Microsoft YaHei';font-weight:800; color:#dedede;\">|</span>"
				"<span style=\" font-size:14px;\"/><span style=\" font-size:14px 'Microsoft YaHei'; color:#999999;\"> %1s后重发</span></p></body></html>").arg(timerInt--));
		}
		else
		{
			timer->stop();
			timerInt = 60;
			verificationCodeLabel->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font-size:14px;font-weight:800; color:#dedede;\">|</span>"
				"<span style=\" font-size:14px 'Microsoft YaHei';\"/><span style=\" font-size:14px 'Microsoft YaHei'; color:#1e8cee;\"> 获取验证码</span></p></body></html>"));
		}
	});

	connect(m_loginThread, &LoginThread::loginSignals, this, &LoginWidget::loginFinish);
	connect(m_loginThread, &LoginThread::getFilishSignals, this, &LoginWidget::getFinish);

	weChartLoginLabel = new QLabel(this);
	weChartLoginLabel->setGeometry(306, 364, 92, 84);
	weChartLoginLabel->installEventFilter(this);
	weChartLoginLabel->setCursor(Qt::PointingHandCursor);
	weChartLoginLabel->setPixmap(QPixmap(":/ZcloudDesk/image/weChartLogin.png"));
#ifdef WCLOGINHIDE
	weChartLoginLabel->hide();
#endif // WCLOGINHIDE

	Database::GetInstance()->findLoginSet(m_loginSetingStruct);
	changeLoginMethod(1);

}
void LoginWidget::setShowDownloadSoftware(int logingIn)
{
	if (logingIn == 2)
	{
		//提示安装开票软件
		if (!installSoftwareButton)
		{
			installSoftwareButton = new QPushButton(this);
			installSoftwareButton->setGeometry(140, 380, 120, 36);
			installSoftwareButton->setText(QString::fromLocal8Bit("安装开票软件"));
			installSoftwareButton->setStyleSheet(QString::fromLocal8Bit("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 1), stop:1 rgba(244, 244, 244, 1));\
																																																																										 border: 1px solid #DEDEDE;border-radius:4px;font: 14px \"微软雅黑\";color: #333333;}\
																																																																										 																																																								 																																							 																						 						 			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 1), stop:1 rgba(251, 251, 251, 1));\
																																																																																																																																																																																																																																																																																																																																																																																																																																																							border: 1px solid #DEDEDE;border-radius:4px;font: 14px \"微软雅黑\";color: #333333;}"));
			connect(installSoftwareButton, SIGNAL(clicked()), this, SIGNAL(installSoftwareSignal()));
		}
		installSoftwareButton->show();
	}
	else if (installSoftwareButton)
	{
		installSoftwareButton->hide();
	}
}

bool LoginWidget::eventFilter(QObject *target, QEvent *e)
{
	if (e->type() == QEvent::MouseButtonRelease)
	{
		if (target == registerLael)
		{
			//QDesktopServices::openUrl(QUrl::fromUserInput("https://user.zhicloud.com/"));
			//注册
			changeLoginMethod(3);
			statusLoginLabel->text() != QString::fromLocal8Bit("手机快捷登录") ?
				ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG008")
				: ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG004");

		}
		else if (target == statusLoginLabel_2)
		{
			//修改登录方式
			statusLoginLabel->text() != QString::fromLocal8Bit("手机快捷登录") ?
				ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG039")
				: ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG021");
			changeLoginMethod(statusLoginLabel->text() != QString::fromLocal8Bit("手机快捷登录") ? 1 : 2);
		}
		else if (target == forgetPasswordLabel)
		{
			//忘记密码
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG012");
			changeLoginMethod(4);
		}
		else if (target == verificationCodeLabel)
		{
			//获取验证码
			if (accountLineEdit->text().size() != 11)
			{
				//手机号不符合规定
				accountLineEdit->errorStyle();
				m_hintLabel_1->setText(QString::fromLocal8Bit("请输入正确的手机号"));
				m_hintLabel_1->show();
			}
			else
			{
				if (!timer->isActive())
				{
					QString strCodeType;
					if (statusLoginLabel->text() == QString::fromLocal8Bit("手机快捷登录"))//手机登录
					{
						ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG033", accountLineEdit->text());
						if (zhicloudStrToken.isEmpty())
							strCodeType = "login";
						else
							strCodeType = "bind_mobile";
					}
					else if (loginButton->text() == QString::fromLocal8Bit("下一步"))//找回密码  获取验证码
					{
						ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG015", accountLineEdit->text());
						strCodeType = "forgot_password";
					}
					else if (loginButton->text() == QString::fromLocal8Bit("立即注册")) //注册获取验证码
					{
						ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG026", accountLineEdit->text());
						strCodeType = "register";
					}
					else
						strCodeType = "";
					if (!strCodeType.isEmpty())
					{
						verificationCodeLineEdit->clear();
						m_hintLabel_1->hide();
						m_hintLabel_2->hide();
						m_hintLabel_3->hide();
						verificationCodeLabel->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font:14px 'Microsoft YaHei';font-weight:800; color:#dedede;\">|</span>"
							"<span style=\" font:14px 'Microsoft YaHei';\"/><span style=\" font:14px 'Microsoft YaHei'; color:#999999;\"> 60s后重发</span></p></body></html>"));
						//获取验证码
						timer->start(1000); // 每隔1s 
						m_loginThread->setValue(LoginThread::AuthWay, accountLineEdit->text(), "", strCodeType);
						m_loginThread->start();
					}
				}
			}
		}
		else if (target == tipLabel)
		{
#ifdef VERSION_FOR_GZ
			QDesktopServices::openUrl(QUrl::fromUserInput("https://www.zhicloud.com/UserAgreement/index.html"));
#else
			QDesktopServices::openUrl(QUrl::fromUserInput("https://www.zhicloud.com/UserAgreement/all.html"));
#endif		
		}
		else if (target == weChartLoginLabel)
		{
			//二维码登录
			emit qrChartLoginSingal();
		}
	}
	return QWidget::eventFilter(target, e);
}


void LoginWidget::changeLoginMethod(int statusFlag, bool isClear)
{
	if (isClear)
	{
		accountLineEdit->clear();
		passwordLineEdit->clear();
		verificationCodeLineEdit->clear();
	}
	m_hintLabel_1->hide();
	m_hintLabel_2->hide();
	m_hintLabel_3->hide();
	weChartLoginLabel->hide();
	if (installSoftwareButton) installSoftwareButton->hide();
	timer->stop();
	timerInt = 60;
	if (passwordLineEdit_2) passwordLineEdit_2->hide();
	//如果定时器在运行则需要重新设置内容
	verificationCodeLabel->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font:14px 'Microsoft YaHei';font-weight:800; color:#dedede;\">|</span>"
		"<span style=\" font:14px 'Microsoft YaHei';\"/><span style=\" font:14px 'Microsoft YaHei'; color:#1e8cee;\"> 获取验证码</span></p></body></html>"));
	
	switch (statusFlag)
	{
	case 1:
	{
		//手机验证码登录
		statusLoginLabel->setText(QString::fromLocal8Bit("手机快捷登录"));
		statusLoginLabel_2->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font:14px 'Microsoft YaHei';  font-weight:600;color:#666666;\">账号登录</span>"
			"<span style=\" font:14px 'Microsoft YaHei'; font-weight:600; color:#1f8bed;\">&gt;</span></p></body></html>"));
		accountLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入手机号"));
		accountLineEdit->setEchoMode(QLineEdit::Normal);
		verificationCodeLineEdit->setGeometry(48, 164, 320, 50);
		verificationCodeLineEdit->show();
		passwordLineEdit->hide();

		loginButton->setGeometry(48, 240, 320, 50);
		registerLael->setGeometry(178, 305, 60, 15);
		registerLael->show();
		verificationCodeLabel->show();
		verificationCodeLabel->raise();


		statusLoginLabel_2->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
		statusLoginLabel_2->setGeometry(265, 30, 100, 30);
		accountLineEdit->setGeometry(48, 91, 320, 50);
		loginButton->setText(QString::fromLocal8Bit("登录"));
		forgetPasswordLabel->hide();
		tipLabel->hide();

		QRegExp phoneNumberExp("^1\\d{10}$");
		QValidator *validator = new QRegExpValidator(phoneNumberExp, accountLineEdit);
		accountLineEdit->setValidator(validator);
#ifdef WCLOGINHIDE
		weChartLoginLabel->hide();
		if (installSoftwareButton) installSoftwareButton->show();
#else
		weChartLoginLabel->show();
		if (installSoftwareButton) installSoftwareButton->hide();
#endif // WCLOGINHIDE

		break;
	}
	case 2:
	{
		//账号密码登录
		statusLoginLabel->setText(QString::fromLocal8Bit("账号登录"));
		statusLoginLabel_2->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font:14px 'Microsoft YaHei';  font-weight:600;color:#666666;\">手机快捷登录</span>"
			"<span style=\" font:14px 'Microsoft YaHei'; font-weight:600; color:#1f8bed;\">&gt;</span></p></body></html>"));
		accountLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入手机号/账号"));
		verificationCodeLineEdit->hide();
		verificationCodeLabel->hide();
		tipLabel->hide();
		passwordLineEdit->setGeometry(48, 164, 320, 50);
		passwordLineEdit->show();
		accountLineEdit->show();
		loginButton->setGeometry(48, 265, 320, 50);
		registerLael->setGeometry(178, 332, 60, 15);
		registerLael->show();
		forgetPasswordLabel->show();

		QRegExp regx("^[0-9a-zA-Z_]{1,}$");
		QValidator *validator = new QRegExpValidator(regx, accountLineEdit);
		accountLineEdit->setValidator(validator);
#ifdef WCLOGINHIDE
		weChartLoginLabel->hide();
		if (installSoftwareButton) installSoftwareButton->show();
#else
		weChartLoginLabel->show();
		if (installSoftwareButton) installSoftwareButton->hide();
#endif // WCLOGINHIDE
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG009");
		break;
	}
	case 3:
	{
		//注册
		statusLoginLabel->setText(QString::fromLocal8Bit("注册%1账号").arg(g_strAppName));
		statusLoginLabel_2->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font:14px 'Microsoft YaHei'; font-weight:600; color:#1f8bed;\">&lt;"
			"</span><span style=\" font:14px 'Microsoft YaHei';  font-weight:600;color:#666666;\">已有%1账号</span></p></body></html>").arg(g_strAppName));
		statusLoginLabel_2->setGeometry(48, 410, 113, 35);
		accountLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入手机号"));
		passwordLineEdit->setGeometry(48, 239, 320, 50);
		verificationCodeLineEdit->show();
		passwordLineEdit->show();
		tipLabel->show();
		loginButton->setText(QString::fromLocal8Bit("立即注册"));
		loginButton->setGeometry(48, 315, 320, 50);
		registerLael->hide();
		forgetPasswordLabel->hide();
		verificationCodeLabel->show();
		verificationCodeLabel->raise();
		//QRegExp phoneNumberExp("^((13[0-9])|(14[5,7])|(15[0-3,5-9])|(17[0,3,5-8])|(18[0-9])|166|198|199|(147))\\d{8}$");
		QRegExp phoneNumberExp("^1\\d{10}$");
		QValidator *validator = new QRegExpValidator(phoneNumberExp, accountLineEdit);
		accountLineEdit->setValidator(validator);

		break;
	}
	case 4:
	{
		//重置密码1
		statusLoginLabel->setText(QString::fromLocal8Bit("找回密码"));
		statusLoginLabel_2->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font:14px 'Microsoft YaHei'; font-weight:600; color:#1f8bed;\">&lt;"
			"</span><span style=\" font:14px 'Microsoft YaHei';  font-weight:600;color:#666666;\">已有%1账号</span></p></body></html>").arg(g_strAppName));
		statusLoginLabel_2->setGeometry(48, 410, 113, 35);
		accountLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入手机号"));

		passwordLineEdit->hide();
		verificationCodeLineEdit->show();
		loginButton->setText(QString::fromLocal8Bit("下一步"));
		loginButton->setGeometry(48, 237, 320, 50);
		registerLael->setGeometry(178, 305, 60, 15);
		forgetPasswordLabel->hide();
		tipLabel->hide();
		registerLael->hide();
		verificationCodeLabel->show();
		verificationCodeLabel->raise();

		//QRegExp phoneNumberExp("^((13[0-9])|(14[5,7])|(15[0-3,5-9])|(17[0,3,5-8])|(18[0-9])|166|198|199|(147))\\d{8}$");
		QRegExp phoneNumberExp("^1\\d{10}$");
		QValidator *validator = new QRegExpValidator(phoneNumberExp, accountLineEdit);
		accountLineEdit->setValidator(validator);
		break;
	}
	case 5:
	{
		//重置密码2
		verificationCodeLabel->hide();
		verificationCodeLineEdit->hide();
		accountLineEdit->hide();
		if (!passwordLineEdit_2)
			passwordLineEdit_2 = new LoginLineEdit(this, QString::fromLocal8Bit("请输入8～20位登录密码"));

		passwordLineEdit->setGeometry(48, 91, 320, 50);
		passwordLineEdit_2->setGeometry(48, 164, 320, 50);
		passwordLineEdit_2->setValidator(0);
		passwordLineEdit_2->setPlaceholderText(QString::fromLocal8Bit("请确认新密码"));
		passwordLineEdit_2->setEchoMode(QLineEdit::Password);
		loginButton->setText(QString::fromLocal8Bit("确定"));
		passwordLineEdit->show();
		passwordLineEdit_2->show();
		break;
	}case 6:
	{
		//设置密码
		//statusLoginLabel_2->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font:14px 'Microsoft YaHei'; font-weight:600; color:#1f8bed;\">&lt;"
		//	"</span><span style=\" font:14px 'Microsoft YaHei';  font-weight:600;color:#666666;\">已有%1账号</span></p></body></html>").arg(g_strAppName));
		//statusLoginLabel_2->setGeometry(48, 410, 113, 35);
		statusLoginLabel->setText(QString::fromLocal8Bit("设置密码"));
		verificationCodeLabel->hide();
		verificationCodeLineEdit->hide();
		accountLineEdit->hide();
		registerLael->hide();
		statusLoginLabel_2->hide();

		passwordLineEdit->setGeometry(48, 91, 320, 50);
		loginButton->setText(QString::fromLocal8Bit("确定"));
		loginButton->setGeometry(48, 164, 320, 50);
		passwordLineEdit->show();
	}
	default:
		break;
	}

	if (!zhicloudStrToken.isEmpty())
	{
		//没有账号密码登录
		statusLoginLabel_2->hide();
		//没有注册
		registerLael->hide();
		//没有忘记密码
		forgetPasswordLabel->hide();
	}

}

void LoginWidget::onLoginButtonClicked()
{
	if (m_loginThread->isRunning())
	{
		//获取验证码 线程正在运行
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("正在获取验证码，请稍后！"));
		return;
	}

	m_hintLabel_1->hide();
	m_hintLabel_2->hide();
	m_hintLabel_3->hide();
	QString accountStr = accountLineEdit->text();
	QString verificationCodeStr = verificationCodeLineEdit->text();
	QString passwordStr = passwordLineEdit->text();
	if (loginButton->text() == QString::fromLocal8Bit("登录"))
	{
		if (statusLoginLabel->text() != QString::fromLocal8Bit("手机快捷登录"))
		{
			//账号密码登录
			if (accountStr.isEmpty())
			{
				accountLineEdit->errorStyle();
				m_hintLabel_1->setText(QString::fromLocal8Bit("账号不能为空"));
				m_hintLabel_1->show();
				return;
			}
			else if (passwordStr.isEmpty())
			{
				passwordLineEdit->errorStyle();
				m_hintLabel_2->setText(QString::fromLocal8Bit("密码不能为空"));
				m_hintLabel_2->show();
				return;
			}

			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG035", accountStr);
			emit lodingStartSiganl();

			m_loginThread->setValue(LoginThread::LoginPwWay, accountStr, passwordStr);
			m_loginThread->start();
		}
		else
		{
			//手机验证码登录
			if (accountStr.isEmpty())
			{
				accountLineEdit->errorStyle();
				m_hintLabel_1->setText(QString::fromLocal8Bit("手机号不能为空"));
				m_hintLabel_1->show();
				return;
			}
			else if (accountStr.size() < 11)
			{
				accountLineEdit->errorStyle();
				m_hintLabel_1->setText(QString::fromLocal8Bit("手机号格式错误，请重新输入"));
				m_hintLabel_1->show();
				return;
			}
			else if (verificationCodeStr.isEmpty())
			{
				verificationCodeLineEdit->errorStyle();
				m_hintLabel_2->setText(QString::fromLocal8Bit("验证码不能为空"));
				m_hintLabel_2->show();
				return;
			}

			emit lodingStartSiganl();
			m_loginThread->setValue(LoginThread::LoginPaWay, accountStr, verificationCodeStr);
			m_loginThread->start();
		}
	}
	else if (loginButton->text() == QString::fromLocal8Bit("下一步"))
	{
		//重置密码下一步
		if (accountStr.isEmpty())
		{
			accountLineEdit->errorStyle();
			m_hintLabel_1->setText(QString::fromLocal8Bit("手机号不能为空"));
			m_hintLabel_1->show();
			return;
		}
		else if (accountStr.size() < 11)
		{
			accountLineEdit->errorStyle();
			m_hintLabel_1->setText(QString::fromLocal8Bit("手机号格式错误，请重新输入"));
			m_hintLabel_1->show();
			return;
		}
		else if (verificationCodeStr.isEmpty())
		{
			verificationCodeLineEdit->errorStyle();
			m_hintLabel_2->setText(QString::fromLocal8Bit("验证码不能为空"));
			m_hintLabel_2->show();
			return;
		}
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG017", accountStr + "-" + verificationCodeStr);
		emit lodingStartSiganl();
		m_loginThread->setValue(LoginThread::VerifyPaWay, accountStr, verificationCodeStr, "forgot_password");
		m_loginThread->start();


	}
	else if (loginButton->text() == QString::fromLocal8Bit("确定"))
	{
		if (statusLoginLabel->text() == QString::fromLocal8Bit("设置密码"))
		{
			if (passwordStr.isEmpty())
			{
				passwordLineEdit->errorStyle();
				m_hintLabel_1->setText(QString::fromLocal8Bit("密码不能为空"));
				m_hintLabel_1->show();
				return;
			}
			else if (passwordStr.size() < 8)
			{
				passwordLineEdit->errorStyle();
				m_hintLabel_1->setText(QString::fromLocal8Bit("请输入8～20位登录密码"));
				m_hintLabel_1->show();
				return;
			}
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG037", accountStr);
			emit lodingStartSiganl();
			m_loginThread->setValue(LoginThread::VerifyWay, accountStr, passwordStr, verificationCodeStr);
			m_loginThread->start();
		}
		else
		{
			QString pass_1 = passwordLineEdit->text();
			QString pass_2 = passwordLineEdit_2->text();

			if (pass_1.isEmpty())
			{
				passwordLineEdit->errorStyle();
				m_hintLabel_1->setText(QString::fromLocal8Bit("密码不能为空"));
				m_hintLabel_1->show();
				return;
			}
			if (pass_1.size() < 8 || pass_1.size() > 20)
			{
				passwordLineEdit->errorStyle();
				m_hintLabel_1->setText(QString::fromLocal8Bit("请输入8～20位登录密码"));
				m_hintLabel_1->show();
				return;
			}

			if (pass_1 != pass_2)
			{
				passwordLineEdit_2->errorStyle();
				m_hintLabel_2->setText(QString::fromLocal8Bit("两次输入密码不匹配"));
				m_hintLabel_2->show();
				return;
			}
			//重置密码确定
			emit lodingStartSiganl();
			m_loginThread->setValue(LoginThread::ResetPwWay, accountStr, passwordStr, verificationCodeStr);
			m_loginThread->start();
		}
	}
	else if (loginButton->text() == QString::fromLocal8Bit("立即注册"))
	{
		if (accountStr.isEmpty())
		{
			accountLineEdit->errorStyle();
			m_hintLabel_1->setText(QString::fromLocal8Bit("手机号不能为空"));
			m_hintLabel_1->show();
			return;
		}
		else if (accountStr.size() < 11)
		{
			accountLineEdit->errorStyle();
			m_hintLabel_1->setText(QString::fromLocal8Bit("手机号格式错误，请重新输入"));
			m_hintLabel_1->show();
			return;
		}

		if (verificationCodeStr.isEmpty())
		{
			verificationCodeLineEdit->errorStyle();
			m_hintLabel_2->setText(QString::fromLocal8Bit("验证码不能为空"));
			m_hintLabel_2->show();
			return;
		}

		if (passwordStr.isEmpty())
		{
			passwordLineEdit->errorStyle();
			m_hintLabel_3->setText(QString::fromLocal8Bit("密码不能为空"));
			m_hintLabel_3->show();
			return;
		}
		else if (passwordStr.size() < 8)
		{
			passwordLineEdit->errorStyle();
			m_hintLabel_3->setText(QString::fromLocal8Bit("请输入8～20位登录密码"));
			m_hintLabel_3->show();
			return;
		}
		emit lodingStartSiganl();
		m_loginThread->setValue(LoginThread::VerifyWay, accountStr, passwordStr, verificationCodeStr);
		m_loginThread->start();
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG028", accountStr);
	}
	m_hintLabel_1->hide();
	m_hintLabel_2->hide();
	m_hintLabel_3->hide();
}


void LoginWidget::getFinish(int status)
{
	LoginThread::WayEnum wayEnum = m_loginThread->getWayEnum();

	if (status == 0)
	{
		switch (wayEnum)
		{
		case LoginThread::LoginPwWay:		//账号密码登录
			break;
		case LoginThread::AuthWay:		//获取验证码
			break;
		case LoginThread::VerifyPaWay:	//检测验证码
		{
			//重置密码下一步
			changeLoginMethod(5, false);
			emit lodingFilishSiganl();
			break;
		}
		case LoginThread::ResetPwWay:		//重置密码确认
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG020",accountLineEdit->text() + "-0" );
		case LoginThread::VerifyWay:		//注册
			m_loginThread->setValue(LoginThread::LoginPwWay, accountLineEdit->text(), passwordLineEdit->text());
			m_loginThread->start();
			break;
		case LoginThread::LoginPaWay:		//手机验证码登录
		case LoginThread::BindingEin:
		{
			if (!zhicloudStrToken.isEmpty())
			{
				//手机验证码绑定税号成功
				//手机号绑定税号成功
				m_userInfoStruct.m_strMobile =  accountLineEdit->text();
				emit logingSucceed();
			}
			break;
		}
		default:
			break;
		}
	}
	else
	{
		//错误提示
		switch (wayEnum)
		{
		case LoginThread::LoginPwWay:		//账号密码登录
			break;
		case LoginThread::AuthWay:		//获取验证码
		{
			QString errorStr = QString::fromLocal8Bit("获取验证码失败，请重新获取");// QString::fromLocal8Bit("验证码过期，请重新获取");
			if (loginButton->text() == QString::fromLocal8Bit("立即注册")) 
				ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "SLG027", accountLineEdit->text() + "-" + QString::number(status));
			else
			{
				ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "SLG034", accountLineEdit->text() + "-" + QString::number(status));
			}
			timer->stop();
			timerInt = 60;
			verificationCodeLabel->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font:14px 'Microsoft YaHei';"
				"font-weight:800; color:#dedede;\">|</span><span style=\" font:14px 'Microsoft YaHei';\"/>"
				"<span style=\" font:14px 'Microsoft YaHei'; color:#1e8cee;\"> 获取验证码</span></p></body></html>"));
			if (30032 == status)
			{
				errorStr = QString::fromLocal8Bit("手机号已注册，请直接登录");
			}
			else if (30048 == status)
			{
				errorStr = QString::fromLocal8Bit("手机号未注册，请先注册");
			}
			else if (30018 == status)
			{
				errorStr = QString::fromLocal8Bit("请过段时间后再发送验证码!");
			}
			else if (10004 == status)
			{
				errorStr = QString::fromLocal8Bit("手机号格式不正确，请重新输入!");
			}
			else{
				errorStr.append(QString::fromLocal8Bit("！错误码：%1").arg(status));
			}
			accountLineEdit->errorStyle();
			m_hintLabel_2->setText(errorStr);
			m_hintLabel_2->show();
			break;
		}
		case LoginThread::VerifyPaWay:	//检测验证码
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "SLG016", accountLineEdit->text());
			changeLoginMethod(4, false);
			verificationCodeLineEdit->errorStyle();
			m_hintLabel_2->setText(QString::fromLocal8Bit("验证码过期，请重新获取"));
			m_hintLabel_2->show();
			emit lodingFilishSiganl();
			break;
		}
		case LoginThread::ResetPwWay:		//重置密码确认
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG020", accountLineEdit->text() + "-1" + "-" + QString::number(status));
			accountLineEdit->errorStyle();
			m_hintLabel_2->setText(QString::fromLocal8Bit("重置密码失败,错误码%1").arg(status));
			emit lodingFilishSiganl();
			break;
		}
		case LoginThread::VerifyWay:		//注册
		{
			int a = 0;
			QString strError;
			switch (status)
			{
			case 30021:
				strError = QString::fromLocal8Bit("验证码错误，请重新获取");
				verificationCodeLineEdit->errorStyle();
				m_hintLabel_2->setText(strError);
				m_hintLabel_2->show();
				break;
			case 30020:
				strError = QString::fromLocal8Bit("验证码过期，请重新获取");
				verificationCodeLineEdit->errorStyle();
				m_hintLabel_2->setText(strError);
				m_hintLabel_2->show();
				break;
			case 30018:
				strError = QString::fromLocal8Bit("请过段时间后再发送验证码");
				verificationCodeLineEdit->errorStyle();
				m_hintLabel_2->setText(strError);
				m_hintLabel_2->show();
				break;
			case 30032:
				strError = QString::fromLocal8Bit("该用户已存在");
				accountLineEdit->errorStyle();
				m_hintLabel_1->setText(strError);
				m_hintLabel_1->show();
				break;
			case 10004:
				strError = QString::fromLocal8Bit("手机号格式不正确"); 
				accountLineEdit->errorStyle();
				m_hintLabel_1->setText(strError);
				m_hintLabel_1->show();
				break;
			case 10008:
				strError = QString::fromLocal8Bit("密码格式不正确");
				passwordLineEdit->errorStyle();
				m_hintLabel_2->setText(strError);
				m_hintLabel_2->show();
				break;
			case 30033:
				strError = QString::fromLocal8Bit("注册失败");
				m_hintLabel_2->setText(strError);
				m_hintLabel_2->show();
				break;
			default:
				strError = QString::fromLocal8Bit("发生了错误，请重新输入！错误码:%1").arg(status);
				m_hintLabel_2->setText(strError);
				m_hintLabel_2->show();
				break;
			}
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG027", QString::number(status));
			
			emit lodingFilishSiganl();
			break;
		}
		case LoginThread::LoginPaWay:		//手机验证码登录
		case LoginThread::BindingEin:
		{
			if (!zhicloudStrToken.isEmpty())
			{
				//手机验证码绑定税号失败
				//手机号绑定税号失败
				QString errorStr = QString::fromLocal8Bit("验证码错误，请重新输入!错误码：%1").arg(status);
				if (status == 30021)
				{
					errorStr = QString::fromLocal8Bit("验证码错误，请重新输入");
				}
				else if (status == 30020)
				{
					errorStr = QString::fromLocal8Bit("验证码已过期，请重新获取");
				}
				else if (30071 == status)// 手机号已绑定企业
				{
					errorStr = QString::fromLocal8Bit("手机号已绑定该企业");
				}
				else if (status == 30032)
				{
					errorStr = QString::fromLocal8Bit("手机号已存在");
				}
				else{
					errorStr.append(QString::fromLocal8Bit("！错误码：%1").arg(status));
				}
				emit lodingFilishSiganl();
				verificationCodeLineEdit->errorStyle();
				m_hintLabel_2->setText(errorStr);
				m_hintLabel_2->show();
			}
			
			break;
		}
		default:
			break;
		}
	}
}

void LoginWidget::loginFinish(int status, UserInfoStruct userInfoStruct)
{
	LoginThread::WayEnum wayEnum = m_loginThread->getWayEnum();
	if (status == 0)
	{
		switch (wayEnum)
		{
		case LoginThread::LoginPaWay:		//手机验证码登录
		case LoginThread::BindingEin:
		{
			if (!zhicloudStrToken.isEmpty())
			{
				//手机验证码绑定税号成功
				//手机号绑定税号成功
				m_userInfoStruct = userInfoStruct;
				emit logingSucceed();
			}
			else
			{
				//登录成功
				m_userInfoStruct = userInfoStruct;
				emit logingSucceed();
			}
			return;
		}
		}
	}
	



	QString loginButtonText = loginButton->text();
	if (loginButtonText == QString::fromLocal8Bit("登录"))
	{
		if (statusLoginLabel->text() != QString::fromLocal8Bit("手机快捷登录"))
		{
			if (status == 0)
			{
				m_userInfoStruct = userInfoStruct;
				emit logingSucceed();
			}
			else
			{
				QString errorStr = QString::fromLocal8Bit("账号或密码错误，请重新输入!错误码:") + QString::number(status);
				if (status == 30014)
				{
					errorStr = QString::fromLocal8Bit("该账号未绑定公司");
				}
				else if (status == 30001)
				{
					errorStr = QString::fromLocal8Bit("账号密码错误,请重新输入");
				}
				emit lodingFilishSiganl();
				passwordLineEdit->errorStyle();
				m_hintLabel_2->setText(errorStr);
				m_hintLabel_2->show();
			}
		}
		else
		{
			//30014用户未绑定公司
			//验证码登录
			if (status == 0)
			{
				m_userInfoStruct = userInfoStruct;
				emit logingSucceed();
			}
			else if (status == 30025)
			{
				//跳到设置密码界面
				changeLoginMethod(6,false);
				emit lodingFilishSiganl();
			}
			else
			{
				QString errorStr = QString::fromLocal8Bit("验证码错误，请重新输入!错误码：%1").arg(status);
				if (status == 30014)
				{
					errorStr = QString::fromLocal8Bit("该账号未绑定公司");
				}
				else if (status == 30021)
				{
					errorStr = QString::fromLocal8Bit("验证码错误，请重新输入");
				}
				else if (status == 30020)
				{
					errorStr = QString::fromLocal8Bit("验证码过期，请重新获取");
				}
				else if (30071 == status)// 手机号已绑定企业
				{
					errorStr = QString::fromLocal8Bit("手机号已绑定该企业");
				}
				else if (status == 30032)
				{
					errorStr = QString::fromLocal8Bit("手机号已存在");
				}
				emit lodingFilishSiganl();
				verificationCodeLineEdit->errorStyle();
				m_hintLabel_2->setText(errorStr);
				m_hintLabel_2->show();
			}
		}
	}
	else if (loginButtonText == QString::fromLocal8Bit("确定") || loginButtonText == QString::fromLocal8Bit("立即注册"))
	{
		//重置密码成功 注册成功 登录完成
		if (status == 0)
		{
			if (loginButtonText == QString::fromLocal8Bit("立即注册"))
			{
				ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000",  "SLG029" , accountLineEdit->text() );
			}
			m_userInfoStruct = userInfoStruct;
			emit logingSucceed();
		}
		else
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", loginButtonText == QString::fromLocal8Bit("立即注册") ? "SLG030"  : "SLG006",
				accountLineEdit->text() + "-" + QString::number(status));
			QString errorStr = QString::fromLocal8Bit("账号或密码错误，请重新输入");
			if (status == 30014)
			{
				errorStr = QString::fromLocal8Bit("该账号未绑定公司");
			}
			changeLoginMethod(2, false);
			emit lodingFilishSiganl();
			accountLineEdit->errorStyle();
			m_hintLabel_2->setText(errorStr);
			m_hintLabel_2->show();
		}
	}
}


//////////////////////////////////////////////////////////////////华丽的分割线/////////////////////////////////////////////////////////////////
int LoginWidget::checkLogin(QString &tipSt)
{
	QString strTaxNo_ID, strMachine_PW;
	//1.检测网络无网络
	if (!ZcloudComFun::isNetActive())
	{
		//是否是第一次登录
		if (!m_loginSetingStruct.firstLogin &&  !m_loginSetingStruct.uid.isEmpty())
		{
			//	否：走缓存
			return loginNotNet(tipSt);
		}
		//	是：提示用户
		tipSt = QString::fromLocal8Bit("对不起，网络连接失败，\r\n请检查您的网络或本机防火墙设置！");
		return 0;
	}
	else
	{
		//第一次登录
		if (m_loginSetingStruct.firstLogin)
		{
			//检测开票软件
			QString strVerSion = "";
			if (!ZcloudComFun::qtReadsoft(strVerSion))
			{
				tipSt = QString::fromLocal8Bit("尚未安装开票软件，\r\n请下载安装或者重新登录！");
				return 2;
			}
			else
			{
				//!获取税号登录
				getTaxInfo(strTaxNo_ID, strMachine_PW);
				m_loginSetingStruct.loginByTax = 1;
			}
		}
		else
		{
			//	检测税号登录与账号登录
			if (m_loginSetingStruct.loginByTax == 1)	//!税号登录
			{
				//!获取税号登录
				strTaxNo_ID = m_loginSetingStruct.taxNo;
				strMachine_PW = m_loginSetingStruct.uid;
				if (strTaxNo_ID.isEmpty())
				{
					getTaxInfo(strTaxNo_ID, strMachine_PW);
				}
			}
			else if (m_loginSetingStruct.loginByTax == 0)
			{
				//!账号登录
				strTaxNo_ID = m_loginSetingStruct.userName;
				strMachine_PW = m_loginSetingStruct.pwd;
			}
			else if (m_loginSetingStruct.loginByTax == -1 || m_loginSetingStruct.loginByTax == -2)
			{
				//手机验证码登录 和微信登录
				strTaxNo_ID = m_loginSetingStruct.userName;
				strMachine_PW = m_loginSetingStruct.token;
			}
		}
	}

	if (strTaxNo_ID.isEmpty())
	{
		//不能为空 登录异常
		tipSt = QString::fromLocal8Bit("登录异常，\r\n请重新登录！");
		return 0;
	}

	int reLogin = LoginThread::httpLogin(m_loginSetingStruct.loginByTax, strTaxNo_ID, strMachine_PW, m_userInfoStruct);
	if(reLogin != 0)
	{
		//if (!m_loginSetingStruct.firstLogin)
		//{
		//	//非第一次登录失败走缓存
		//	return loginNotNet(tipSt);
		//}
		tipSt = QString::fromLocal8Bit("登录失败，\r\n请重新登录！");
		if (30070 == reLogin)
		{
			tipSt = QString::fromLocal8Bit("登录失败，该账号已过期，\r\n请重新登录!");
		}
		return 0;
	}

	return 1;
}


void LoginWidget::getTaxInfo(QString &strTaxNo, QString &strMachine)
{
	//金税宝登录 待处理 
	typedef char* (_stdcall *pfnGetJsbMsg)();
	QLibrary lib("GetJsbMsg2.dll");
	if (lib.load())
	{
		pfnGetJsbMsg getJsbMsg = (pfnGetJsbMsg)lib.resolve("GetJsbMsg_TaxCode");
		if (NULL != getJsbMsg)
		{
			strTaxNo = getJsbMsg();
			strTaxNo = strTaxNo.replace("$", "");
			strMachine = "0";
		}
	}

	if (strTaxNo.isEmpty())
	{
		QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
		QStringList groupsList = settings->childGroups();
		for (int i = groupsList.size() - 1; i >= 0; i--)
		{
			QString group = groupsList[i];
			settings->beginGroup(group);
			strTaxNo = settings->value("code", QVariant()).toString();			//！企业税号
			strTaxNo = strTaxNo.replace(" ", "");
			strMachine = settings->value("machine", QVariant()).toString();		//！主机号分机号
			settings->endGroup();
			if (!strTaxNo.isEmpty() && !strMachine.isEmpty())
			{
				break;
			}
		}
		delete settings;
	}
	strMachine.clear();
}

//缓存
bool LoginWidget::loginNotNet(QString &tipSt)
{
	bool loginNotNetBool = Database::GetInstance()->readUserData(m_userInfoStruct,  m_loginSetingStruct.uid);
	if (loginNotNetBool && !m_userInfoStruct.m_strToken.isEmpty())
		return true;
	else
	{
		tipSt = QString::fromLocal8Bit("登录异常2！\r\n请用账号密码登录！");
	}
	return false;
}




LoginWidget::~LoginWidget()
{
}


LoginSetWidget::LoginSetWidget(QWidget *parent)
	: QWidget(parent)
{
	QLabel *setLabel = new QLabel(QString::fromLocal8Bit("代理设置"), this);
	setLabel->setStyleSheet("QLabel{font: 16px 'Microsoft YaHei';font-weight:bold;color: rgb(51, 51, 51);}");
	setLabel->setGeometry(35, 10, 100, 30);

	QLabel *setTypeLabel = new QLabel(QString::fromLocal8Bit("类型:"), this);
	QLabel *setAddrLabel = new QLabel(QString::fromLocal8Bit("地址:"), this);
	QLabel *setPortLabel = new QLabel(QString::fromLocal8Bit("端口:"), this);
	QLabel *setAccountLabel = new QLabel(QString::fromLocal8Bit("账号:"), this);
	QLabel *setPasswordLabel = new QLabel(QString::fromLocal8Bit("密码:"), this);
	QLabel *setRegionLabel = new QLabel(QString::fromLocal8Bit("域:"), this);
	LoginComboBox *setTypeComboBox = new LoginComboBox(this);
	setAddrLineEdit = new LoginLineEdit(this);
	setPortLineEdit = new LoginLineEdit(this);
	setAccountLineEdit = new LoginLineEdit(this);
	setPasswordLineEdit = new LoginLineEdit(this);
	setRegionLineEdit = new LoginLineEdit(this);
	setPortLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
	setPasswordLineEdit->setEchoMode(QLineEdit::Password);

	setTypeLabel->setStyleSheet("QLabel{font: 14px 'Microsoft YaHei';color: rgb(102, 102, 102);}");
	setAddrLabel->setStyleSheet("QLabel{font: 14px 'Microsoft YaHei';color: rgb(102, 102, 102);}");
	setPortLabel->setStyleSheet("QLabel{font: 14px 'Microsoft YaHei';color: rgb(102, 102, 102);}");
	setAccountLabel->setStyleSheet("QLabel{font: 14px 'Microsoft YaHei';color: rgb(102, 102, 102);}");
	setPasswordLabel->setStyleSheet("QLabel{font: 14px 'Microsoft YaHei';color: rgb(102, 102, 102);}");
	setRegionLabel->setStyleSheet("QLabel{font: 14px 'Microsoft YaHei';color: rgb(102, 102, 102);}");

	setTypeComboBox->addItem(QString::fromLocal8Bit("  不使用代理"));
	setTypeComboBox->addItem(QString::fromLocal8Bit("  HTTP代理"));
	setTypeComboBox->addItem(QString::fromLocal8Bit("  SOCK5代理"));
	setTypeComboBox->addItem(QString::fromLocal8Bit("  浏览器代理"));

	connect(setTypeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setTypeCurentIndexChanged(int)));

	setTypeLabel->setGeometry(35, 65, 60, 20);
	setAddrLabel->setGeometry(35, 115, 60, 20);
	setPortLabel->setGeometry(35, 165, 60, 20);
	setAccountLabel->setGeometry(35, 215, 60, 20);
	setPasswordLabel->setGeometry(35, 265, 60, 20);
	setRegionLabel->setGeometry(35, 315, 60, 20);

	setTypeComboBox->setGeometry(110, 55, 250, 40);
	setAddrLineEdit->setGeometry(110, 105, 250, 40);
	setPortLineEdit->setGeometry(110, 155, 250, 40);
	setAccountLineEdit->setGeometry(110, 205, 250, 40);
	setPasswordLineEdit->setGeometry(110, 255, 250, 40);
	setRegionLineEdit->setGeometry(110, 305, 250, 40);


	testSetLael = new QLabel(QString::fromLocal8Bit("测试"), this);
	tipSetLael = new QLabel(this);
	tipSetLael->setAlignment(Qt::AlignLeft);
	tipSetLael->setGeometry(110, 348, 100, 20);
	tipSetLael->setStyleSheet("font: 14px 'Microsoft YaHei';color: rgb(241, 0, 32);");
	tipSetLael->hide();
	testSetLael->setCursor(Qt::PointingHandCursor);
	testSetLael->setStyleSheet("color: rgb(153, 153, 153);font: 14px 'Microsoft YaHei';");
	testSetLael->setGeometry(320, 350, 30, 15);
	QPushButton *checkButton = new QPushButton(QString::fromLocal8Bit("确定"), this);
	checkButton->setStyleSheet("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));"
		"border-radius:4px;font:18px 'Microsoft YaHei';color:rgba(255, 255, 255, 1);}"
		"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));"
		"border-radius:4px;font:18px 'Microsoft YaHei';color:rgba(255, 255, 255, 1);};");
	checkButton->setGeometry(110, 375, 120, 40);
	connect(checkButton, &QPushButton::clicked, this, &LoginSetWidget::checkclicked);



	QPushButton *cancelButton = new QPushButton(QString::fromLocal8Bit("取消"), this);
	cancelButton->setStyleSheet("QPushButton{ background:rgba(255,255,255,1); border:1px solid rgba(222,222,222,1); border-radius:4px;font:18px 'Microsoft YaHei'; color:rgba(51,51,51,1);}"
		"QPushButton:hover,pressed{ background:rgba(255,255,255,1); font:18px 'Microsoft YaHei';"
		"color:rgba(30,140,238,1);border:1px solid rgba(30,140,238,1); border-radius:4px;}");
	cancelButton->setGeometry(240, 375, 120, 40);
	connect(cancelButton, SIGNAL(clicked()), this, SIGNAL(cancelButtonSignals()));
	setTypeCurentIndexChanged(0);
}


//确认设置代理
void LoginSetWidget::checkclicked()
{
	tipSetLael->hide();
	if (m_typeCurentIndex == 1 || m_typeCurentIndex == 2)
	{
		if (setAddrLineEdit->text().isEmpty())
		{
			setAddrLineEdit->errorStyle();
			tipSetLael->setText(QString::fromLocal8Bit("地址不能为空！"));
			tipSetLael->show();
			//ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("地址不能为空！"));
			return;
		}
		if (setPortLineEdit->text().isEmpty())
		{
			setPortLineEdit->errorStyle();
			tipSetLael->setText(QString::fromLocal8Bit("端口不能为空！"));
			tipSetLael->show();
			//ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("端口不能为空！"));
			return;
		}
	}
	QNetworkProxy proxy = getNetworkProxy();
	QNetworkProxy::setApplicationProxy(proxy);

	QSettings setting(QApplication::applicationDirPath() + "/net", QSettings::IniFormat);//生成配置文件
	setting.setValue("/proxy/type", proxy.type());
	setting.setValue("/proxy/host", proxy.hostName());
	setting.setValue("/proxy/port", proxy.port());
	setting.setValue("/proxy/user", proxy.user());
	setting.setValue("/proxy/pwd", proxy.password());
	emit cancelButtonSignals();
}


QNetworkProxy LoginSetWidget::getNetworkProxy()
{
	QNetworkProxy proxy;
	switch (m_typeCurentIndex)
	{
	case 0:
	{
		//不使用代理
		proxy.setType(QNetworkProxy::NoProxy);
		break;
	}
	case 1:
	{
		//HTTP代理
		proxy.setType(QNetworkProxy::HttpProxy);
		proxy.setHostName(setAddrLineEdit->text());
		proxy.setPort(setPortLineEdit->text().toInt());
		if (!setAccountLineEdit->text().isEmpty())
		{
			proxy.setUser(setAccountLineEdit->text());//可不填
			if (!setPasswordLineEdit->text().isEmpty())
				proxy.setPassword(setPasswordLineEdit->text());//可不填
		}
		//if (!setRegionLineEdit->text().isEmpty())
		//{
		//	QNetworkCookie 	networkCookie;
		//	networkCookie.setDomain(setRegionLineEdit->text());
		//}
		break;
	}
	case 2:
	{
		//SOCK5代理
		proxy.setType(QNetworkProxy::Socks5Proxy);
		proxy.setHostName(setAddrLineEdit->text());
		proxy.setPort(setPortLineEdit->text().toInt());
		if (!setAccountLineEdit->text().isEmpty())
		{
			proxy.setUser(setAccountLineEdit->text());//可不填
			if (!setPasswordLineEdit->text().isEmpty())
				proxy.setPassword(setPasswordLineEdit->text());//可不填
		}
		break;
	}
	case 3:
	{
		//浏览器代理
		QNetworkProxyQuery proxyQuery(QUrl::fromUserInput("https://www.baidu.com"));
		QList<QNetworkProxy> proxyList = QNetworkProxyFactory::systemProxyForQuery(proxyQuery);
		if (proxyList.count() > 0)
			proxy = proxyList.at(0);
		else
			proxy.setType(QNetworkProxy::NoProxy);
		break;
	}
	default:
		proxy.setType(QNetworkProxy::NoProxy);
	}
	return proxy;
}

bool LoginSetWidget::eventFilter(QObject *target, QEvent *e)
{
	if (e->type() == QEvent::MouseButtonRelease)
	{
		if (target == testSetLael)
		{
			//测试代理
			testClicke();
		}
	}
	return QWidget::eventFilter(target, e);
}

bool LoginSetWidget::testClicke()
{
	tipSetLael->hide();
	if (m_typeCurentIndex == 1 || m_typeCurentIndex == 2)
	{
		if (setAddrLineEdit->text().isEmpty())
		{
			setAddrLineEdit->errorStyle();
			tipSetLael->setText(QString::fromLocal8Bit("地址不能为空！"));
			tipSetLael->show();
			//ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("地址不能为空！"));
			return false;
		}
		if (setPortLineEdit->text().isEmpty())
		{
			setPortLineEdit->errorStyle();
			tipSetLael->setText(QString::fromLocal8Bit("端口不能为空！"));
			tipSetLael->show();
			//ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("端口不能为空！"));
			return false;
		}
	}

	emit lodingStartSiganl();
	QNetworkAccessManager networkAccessManager;

	QString strUrl = ZcloudComFun::getHostName() + "/general/get-server-time";
	QUrl url(strUrl);
	QNetworkRequest request;
	QNetworkProxy networkProxy = getNetworkProxy();// QNetworkProxy::applicationProxy();
	if (networkProxy.type() != QNetworkProxy::NoProxy)
		networkAccessManager.setProxy(networkProxy);

	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	request.setUrl(url);

	// 开始请求
	QNetworkReply *pReply = networkAccessManager.get(request);

	QEventLoop loop;
	QTimer timer;
	timer.setSingleShot(true);
	timer.start(5000);
	connect(&timer, SIGNAL(timeout()),&loop,SLOT(quit()));
	connect(pReply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();

	emit lodingFilishSiganl();
	// 获取歌曲信息
	if (timer.isActive())
	{
		QByteArray bytes = pReply->readAll();
		int nHttpCode = pReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();//http返回码
		int nErrorCode = pReply->error();
		if (nErrorCode == QNetworkReply::NoError)
		{
			tipSetLael->setText(QString::fromLocal8Bit("连接到代理服务器,成功！"));
			tipSetLael->show();
			//ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("代理测试结果"), QString::fromLocal8Bit("连接到代理服务器,成功！"));
			return true;
		}
		tipSetLael->setText(QString::fromLocal8Bit("无法连接到代理服务器！"));
		tipSetLael->show();
		//ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("代理测试结果"), QString::fromLocal8Bit("无法连接到代理服务器！"));
		return false;
	}
	else
	{
		tipSetLael->setText(QString::fromLocal8Bit("连接服务器失败！"));
		tipSetLael->show();
		return false;
	}
}



void LoginSetWidget::setTypeCurentIndexChanged(int curentIndex)
{
	tipSetLael->hide();
	m_typeCurentIndex = curentIndex;
	setAddrLineEdit->clear();
	setPortLineEdit->clear();
	setAccountLineEdit->clear();
	setPasswordLineEdit->clear();
	setRegionLineEdit->clear();
	switch (curentIndex)
	{
	case 0:
	case 3:
	{
		setAddrLineEdit->setEnabled(false);
		setPortLineEdit->setEnabled(false);
		setAccountLineEdit->setEnabled(false);
		setPasswordLineEdit->setEnabled(false);
		setRegionLineEdit->setEnabled(false);
		testSetLael->removeEventFilter(this);
		break;
	}
	case 1:
	{
		setAddrLineEdit->setEnabled(true);
		setPortLineEdit->setEnabled(true);
		setAccountLineEdit->setEnabled(true);
		setPasswordLineEdit->setEnabled(true);
		setRegionLineEdit->setEnabled(true);
		testSetLael->installEventFilter(this);
		break;
	}
	case 2:
	{
		setAddrLineEdit->setEnabled(true);
		setPortLineEdit->setEnabled(true);
		setAccountLineEdit->setEnabled(true);
		setPasswordLineEdit->setEnabled(true);
		setRegionLineEdit->setEnabled(false);
		testSetLael->installEventFilter(this);
		break;
	}
	default:
		break;
	}
	//setTypeComboBox->addItem(QString::fromLocal8Bit("不使用代理"));
	//setTypeComboBox->addItem(QString::fromLocal8Bit("HTTP代理"));
	//setTypeComboBox->addItem(QString::fromLocal8Bit("SOCK5代理"));
	//setTypeComboBox->addItem(QString::fromLocal8Bit("浏览器代理"));)

}
LoginSetWidget::~LoginSetWidget()
{
}

LoginWeChartWidget::LoginWeChartWidget(int logingIn,QWidget *parent)
	: QWidget(parent)
	, getQRCodeWidget(new QWidget(this))
{
	this->setAttribute(Qt::WA_TranslucentBackground, false);
	getQRCodeWidget->setObjectName("getQRCodeWidget");
	getQRCodeWidget->setStyleSheet("QWidget#getQRCodeWidget{border-image: url(:/ZcloudDesk/image/weChartBack.png);}");
	QRCodeLabel = new QLabel(getQRCodeWidget);
	QRCodeLabel->setGeometry(100, 94, 200, 200);
	qrCMovie = new QMovie(":/ZcloudDesk/image/QRCode.gif");
	phoneLoginLabel = new QLabel(this);
	phoneLoginLabel->setGeometry(306, 364, 92, 84);
	phoneLoginLabel->installEventFilter(this);
	phoneLoginLabel->setCursor(Qt::PointingHandCursor);
	phoneLoginLabel->setPixmap(QPixmap(":/ZcloudDesk/image/userLogin.png"));
	phoneLoginLabel->raise();

	getQRCodeWidget->setGeometry(0, 0, 400, 450);
	connect(this, SIGNAL(showWCWidgetSignals(int)), this, SLOT(showWCWidget(int)), Qt::QueuedConnection);
	wCharPhotoLabel = new QLabel(this);
	wCharPhotoLabel->hide();
	if (logingIn == 2)
	{
		//提示安装开票软件
		QPushButton *installSoftwareButton = new QPushButton(this);
		installSoftwareButton->setGeometry(140,380,120,36);
		installSoftwareButton->setText(QString::fromLocal8Bit("安装开票软件"));
		installSoftwareButton->setStyleSheet(QString::fromLocal8Bit("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 1), stop:1 rgba(244, 244, 244, 1));\
						 border: 1px solid #DEDEDE;border-radius:4px;font: 14px \"微软雅黑\";color: #333333;}\
						 			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 1), stop:1 rgba(251, 251, 251, 1));\
												border: 1px solid #DEDEDE;border-radius:4px;font: 14px \"微软雅黑\";color: #333333;}"));
		connect(installSoftwareButton, SIGNAL(clicked()), this, SIGNAL(installSoftwareSignal()));
	}

}

void LoginWeChartWidget::initBindingWidget()
{

	if (!bindingPhoneWidget)
	{
		bindingPhoneWidget = new QWidget(this);
		//绑定手机号
		m_bindingHintLabel = new QLabel(bindingPhoneWidget);
		m_bindingHintLabel->setAlignment(Qt::AlignLeft);
		m_bindingHintLabel->setStyleSheet("font: 14px 'Microsoft YaHei';color: rgb(241, 0, 32);");
		m_bindingHintLabel->setGeometry(35, 167, 300, 20);
		m_bindingHintLabel_2 = new QLabel(bindingPhoneWidget);
		m_bindingHintLabel_2->setAlignment(Qt::AlignLeft);
		m_bindingHintLabel_2->setStyleSheet("font: 14px 'Microsoft YaHei';color: rgb(241, 0, 32);");
		m_bindingHintLabel_2->setGeometry(35, 242, 300, 20);

		bindingLabel = new QLabel(QString::fromLocal8Bit("绑定手机号"), bindingPhoneWidget);
		bindingLabel->setStyleSheet("QLabel{font: 24px 'Microsoft YaHei';font-weight:bold;color: rgb(51, 51, 51);}");
		bindingLabel_2 = new QLabel(QString::fromLocal8Bit("通过绑定手机号提高账号安全"), bindingPhoneWidget);
		bindingLabel_2->setStyleSheet("QLabel{font: 14px 'Microsoft YaHei';font-weight:bold;color: rgb(51, 51, 51);}");
		wCharPhotoLabel->setParent(bindingPhoneWidget);
		accountLineEdit = new LoginLineEdit(bindingPhoneWidget, QString::fromLocal8Bit("请输入手机号"));
		verificationCodeLineEdit = new LoginLineEdit(bindingPhoneWidget, QString::fromLocal8Bit("请输入验证码"));
		verificationCodeLabel = new QLabel(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font-size:14px 'Microsoft YaHei';font-weight:800; color:#dedede;\">|</span>"
			"<span style=\" font-size:14px;\"/><span style=\" font-size:14px; color:#1e8cee;\"> 获取验证码</span></p></body></html>"),
			bindingPhoneWidget);
		verificationCodeLabel->installEventFilter(this);
		verificationCodeLabel->setCursor(Qt::PointingHandCursor);
		verificationCodeLabel->raise();


		bindingButton = new QPushButton(bindingPhoneWidget);
		bindingButton->setText(QString::fromLocal8Bit("提交"));
		bindingButton->setShortcut(QKeySequence::InsertParagraphSeparator);
		bindingButton->setStyleSheet("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));"
			"border-radius:4px;font: 20px 'Microsoft YaHei';font-weight:400;color:rgba(255, 255, 255, 1);}"
			"border-radius:4px;font: 20px 'Microsoft YaHei';font-weight:400;color:rgba(255, 255, 255, 1);};");

		//QRegExp phoneNumberExp("^((13[0-9])|(14[5,7])|(15[0-3,5-9])|(17[0,3,5-8])|(18[0-9])|166|198|199|(147))\\d{8}$");
		QRegExp phoneNumberExp("^1\\d{10}$");
		QValidator *validator = new QRegExpValidator(phoneNumberExp, accountLineEdit);
		accountLineEdit->setValidator(validator);

		bindingLabel->setGeometry(35, 25, 250, 30);
		bindingLabel_2->setGeometry(35, 62, 200, 20);
		wCharPhotoLabel->setGeometry(315, 30, 45, 45);
		accountLineEdit->setGeometry(35, 115, 320, 50);
		verificationCodeLineEdit->setGeometry(35, 190, 320, 50);
		verificationCodeLabel->setGeometry(265, 205, 130, 20);
		bindingButton->setGeometry(35, 265, 320, 50);

		bindingPhoneWidget->setGeometry(0, 0, 400, 450);
		connect(bindingButton, &QPushButton::clicked, [this]()
		{
			m_bindingHintLabel->hide();
			m_bindingHintLabel_2->hide();
			QString accountStr = accountLineEdit->text();
			QString verificationCodeStr = verificationCodeLineEdit->text();
			if (accountStr.size() != 11)
			{
				//手机号不符合规定
				accountLineEdit->errorStyle();
				m_bindingHintLabel->setText(QString::fromLocal8Bit("请输入正确的手机号"));
				m_bindingHintLabel->show();
			}
			else if (verificationCodeStr.isEmpty())
			{
				verificationCodeLineEdit->errorStyle();
				m_bindingHintLabel_2->setText(QString::fromLocal8Bit("请输入验证码"));
				m_bindingHintLabel_2->show();
			}
			else
			{
				emit changeLoginWaySiganl(1);
				m_bindingThread->setValue(LoginThread::BindingPhoneWay, accountStr, verificationCodeStr, strPkid);
				m_bindingThread->start();
			}
		});

		bindingTimer = new QTimer(this);
		connect(bindingTimer, &QTimer::timeout, [this]{
			if (bindingTimerInt > 0)
			{
				verificationCodeLabel->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font-size:14px 'Microsoft YaHei';font-weight:800; color:#dedede;\">|</span>"
					"<span style=\" font-size:14px;\"/><span style=\" font-size:14px 'Microsoft YaHei'; color:#999999;\"> %1s后重发</span></p></body></html>")
					.arg(bindingTimerInt--));
			}
			else
			{
				bindingTimer->stop();
				bindingTimerInt = 60;
				verificationCodeLabel->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font-size:14px;font-weight:800; color:#dedede;\">|</span>"
					"<span style=\" font-size:14px 'Microsoft YaHei';\"/><span style=\" font-size:14px 'Microsoft YaHei'; color:#1e8cee;\"> 获取验证码</span></p></body></html>"));
			}
		});

		m_bindingThread = new LoginThread(this);
		connect(m_bindingThread, SIGNAL(loginSignals(int, UserInfoStruct)), this, SLOT(bindingFlishSlot(int, UserInfoStruct)));

		connect(m_bindingThread, &LoginThread::getFilishSignals, [this](int status)
		{
			LoginThread::WayEnum wayEnum = m_bindingThread->getWayEnum();
			if (status != 0)
			{
				//错误提示
				switch (wayEnum)
				{
				case LoginThread::AuthWay:		//获取验证码
				{
					bindingTimer->stop();
					bindingTimerInt = 60;
					if (30048 == status)
					{
						//手机号不存在
					}
					verificationCodeLabel->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font:14px 'Microsoft YaHei';font-weight:800; color:#dedede;\">|</span>"
						"<span style=\" font:14px 'Microsoft YaHei';\"/><span style=\" font:14px 'Microsoft YaHei'; color:#1e8cee;\"> 获取验证码</span></p></body></html>"));
					m_bindingHintLabel_2->setText(QString::fromLocal8Bit("获取验证码失败"));
					m_bindingHintLabel_2->show();
					break;
				}
				default:
					break;
				}
			}
		});
	}
	bindingPhoneWidget->show();
}



void LoginWeChartWidget::bindingFlishSlot(int status, UserInfoStruct userInfoStruct)
{
	if (status == 0)
	{
		emit weChartLoginSucceed(userInfoStruct);
	}
	else
	{
		QString errorStr = QString::fromLocal8Bit("绑定失败，请重新绑定。错误码%1").arg(status);
		if (status == 30021)
		{
			errorStr = QString::fromLocal8Bit("验证码错误，请重新输入");
			verificationCodeLineEdit->errorStyle();
			m_bindingHintLabel_2->setText(errorStr);
			m_bindingHintLabel_2->show();
		}
		else if (30071 == status)// 手机号已绑定企业
		{
			errorStr = QString::fromLocal8Bit("手机号已绑定该企业");
			verificationCodeLineEdit->errorStyle();
			m_bindingHintLabel_2->setText(errorStr);
			m_bindingHintLabel_2->show();
		}
		else if (status == 30056)
		{
			errorStr = QString::fromLocal8Bit("该手机号已绑定其他微信用户");
			accountLineEdit->errorStyle();
			m_bindingHintLabel->setText(errorStr);
			m_bindingHintLabel->show();
		}
		else
		{
			m_bindingHintLabel_2->setText(errorStr);
			m_bindingHintLabel_2->show();
		}
		emit changeLoginWaySiganl(2);
	}
}

void LoginWeChartWidget::showWCWidget(int i)
{
	if (1 == i)
	{
		if (bindingPhoneWidget) bindingPhoneWidget->hide();
		getQRCodeWidget->show();
	}
	else
	{
		getQRCodeWidget->hide();
		initBindingWidget();
	}
	phoneLoginLabel->raise();
}

LoginWeChartWidget::~LoginWeChartWidget()
{

}

void LoginWeChartWidget::getQRCode()
{
	if (!isLodingPhoto)
	{
		closeLoginWeChartWidget();
		isLodingPhoto = true;
		isGetStatus = false;
		QRCodeLabel->setMovie(qrCMovie);
		qrCMovie->start();
		showWCWidget(1);
		future = QtConcurrent::run(this, &LoginWeChartWidget::getNetworkPic);//多线程执行死循环启动
	}
}

void LoginWeChartWidget::getNetworkPic()
{
	HttpInterface interface;
	QString retrunStr;
	isGetCode = true;
	while (isLodingPhoto)
	{
		interface.winHttpGetQRCode(zhicloudStrToken,zhicloudStrUserId, retrunStr);
		QByteArray byte_array = retrunStr.toUtf8();
		QJsonParseError json_error;
		QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
		if (json_error.error == QJsonParseError::NoError)
		{
			if (parse_doucment.isObject())
			{

				QJsonObject obj = parse_doucment.object();
				int code = obj.take("status").toInt();
				if (code == 0)
				{
					QJsonObject data = obj.take("data").toObject();
					QString szUrl = data.take("qrcode").toString();
					strPkid = data.take("pkid").toString();
					qrCMovie->stop();
					QRCodeLabel->setPixmap(getNetworkPic(szUrl).scaled(200, 200)); // 你在QLabel显示图片
					if (isLodingPhoto)
					{
						isGetStatus = true;
						future = QtConcurrent::run(this, &LoginWeChartWidget::getStatus);
						isLodingPhoto = false;
						isGetCode = false;
						return;
					}

				}
			}
		}
		//如果获取失败 等待1s后再获取二维码
		if (!isGetCode) return;
		::_sleep(500);
		if (!isGetCode) return;
		::_sleep(500);
		if (!isGetCode) return;
		::_sleep(500);
		if (!isGetCode) return;
		::_sleep(500);
		if (!isGetCode) return;
		::_sleep(500);
		if (!isGetCode) return;
		::_sleep(500);
	}
}

QPixmap LoginWeChartWidget::getNetworkPic(QString strUrl)
{
	QUrl url(strUrl);
	QNetworkAccessManager manager;
	QEventLoop loop;

	// qDebug() << "Reading picture form " << url;
	QNetworkReply *reply = manager.get(QNetworkRequest(url));
	//请求结束并下载完成后，退出子事件循环
	QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	//开启子事件循环
	loop.exec();

	QByteArray jpegData = reply->readAll();
	QPixmap pixmap;
	pixmap.loadFromData(jpegData);
	return pixmap;
}

void LoginWeChartWidget::getStatus()
{
	int timerQR = 0;
	while (isGetStatus)
	{
		HttpInterface interface;
		QString retrunStr;
		interface.winHttpCheckScanStatus(strPkid, zhicloudStrToken,zhicloudStrUserId, retrunStr);
		QByteArray byte_array = retrunStr.toUtf8();
		QJsonParseError json_error;
		QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
		if (json_error.error == QJsonParseError::NoError)
		{
			if (parse_doucment.isObject())
			{
				QJsonObject obj = parse_doucment.object();
				int code = obj.take("status").toInt();
				if (code == 0)
				{
					isGetStatus = false;
					QJsonObject data = obj.take("data").toObject();
					int bind_status = data.take("bind_status").toInt();
					if (bind_status == 0)
					{
						//未绑定 开始绑定
						QJsonObject wechat_inf_bj = data.take("wechat_info").toObject();
						QString nickname = wechat_inf_bj.take("nickname").toString();
						QString headimgurl = wechat_inf_bj.take("headimgurl").toString();
						wCharPhotoLabel->setPixmap(getNetworkPic(headimgurl).scaled(45, 45));
						emit showWCWidgetSignals(2);
					}
					else
					{
						//已绑定 获取用户信息
						UserInfoStruct userInfoStruct;
						QJsonObject company_user_info_obj = data.take("company_user_info").toObject();
						analysisUserData(company_user_info_obj, userInfoStruct);
						LoginSetingStruct loginSetingStruct;
						loginSetingStruct.userName = userInfoStruct.m_strMobile;
						loginSetingStruct.token = userInfoStruct.m_strToken;
						loginSetingStruct.autoLogin = true;
						loginSetingStruct.firstLogin = false;
						loginSetingStruct.loginByTax = -1;

						if(zhicloudStrToken.isEmpty()) Database::GetInstance()->setLoginSet(loginSetingStruct);
						emit weChartLoginSucceed(userInfoStruct);
					}
					return;

				}
				else if (code == 30056)
				{
					timerQR += 1;
					::_sleep(250);
					if (!isGetStatus) return;
					::_sleep(250);
					if (!isGetStatus) return;
					::_sleep(250);
					if (!isGetStatus) return;
					::_sleep(250);
					if (!isGetStatus) return;
					if (timerQR >= 120)
					{
						isGetStatus = false;
						getQRCode();
						return;
					}
					continue;
				}
				else
				{
					//其它错误码
				}
			}
		}
		timerQR += 1;
		::_sleep(250);
		if (!isGetStatus) return;
		::_sleep(250);
		if (!isGetStatus) return;
		::_sleep(250);
		if (!isGetStatus) return;
		::_sleep(250);
		if (!isGetStatus) return;
		if (timerQR >= 120)
		{
			isGetStatus = false;
			getQRCode();
			return;
		}
		continue;
	}


}

void LoginWeChartWidget::analysisUserData(QJsonObject company_user_info_obj, UserInfoStruct &userInfoStruct)
{
	userInfoStruct.m_strCompanyId = company_user_info_obj.take("company_id").toString();			//公司业务编号
	userInfoStruct.m_strCompanyName = company_user_info_obj.take("company_name").toString();		//公司名字
	userInfoStruct.m_strTaxNumber = company_user_info_obj.take("tax_number").toString();			//税号
	userInfoStruct.m_strUsername = company_user_info_obj.take("username").toString();			//登录账号
	userInfoStruct.m_strTruename = company_user_info_obj.take("truename").toString();			//真实名字
	userInfoStruct.m_strJob = company_user_info_obj.take("job").toString();			//真实名字
	userInfoStruct.m_strUserId = company_user_info_obj.take("user_id").toString();			//用户编号

	userInfoStruct.m_strProvinceId = QString::number(company_user_info_obj.take("province_id").toInt());		//省Id
	userInfoStruct.m_strCityId = QString::number(company_user_info_obj.take("city_id").toInt());			//市Id
	userInfoStruct.m_strAreaId = QString::number(company_user_info_obj.take("area_id").toInt());			//区Id
	userInfoStruct.m_strHzsId = QString::number(company_user_info_obj.take("hzs_id").toInt());				//合作商Id
	userInfoStruct.m_logoUrl = company_user_info_obj.take("logo").toString();							//LOGO链接地址
	userInfoStruct.m_logoPath = LoginThread::checkLogoExist(userInfoStruct.m_logoUrl);
	userInfoStruct.m_strToken = company_user_info_obj.take("token").toString();				//token 
	userInfoStruct.m_timeChargeExpire = QDateTime::fromTime_t(company_user_info_obj.take("charge_expire").toInt());	//服务费到期时间
	userInfoStruct.m_isHxNumber = (company_user_info_obj.take("is_hx_member").toInt() == 0 ? false : true);
	userInfoStruct.m_bHideAppClass = company_user_info_obj.take("hide_desktop_apps").toBool();
	userInfoStruct.m_strMobile = company_user_info_obj.take("mobile").toString();
	userInfoStruct.m_bHasMember = company_user_info_obj.take("has_member").toInt();
	QJsonValue memberValue = company_user_info_obj.take("member_list");
	if (memberValue.isArray())
	{
		QJsonArray memberArray = memberValue.toArray();
		for (int j = 0; j < memberArray.size(); j++)
		{
			QJsonObject memberData = memberArray.at(j).toObject();
			QString memberLevel = memberData.take("member_grade_id").toString();
			QString membername = memberData.take("member_name").toString();
			QString memberEndTime = QString::number(memberData.take("member_end_time").toInt());
			userInfoStruct.m_strListAppVipList.append(memberLevel);
			userInfoStruct.m_strListAppVipNameList.append(membername);
			userInfoStruct.m_vipDateTimeList.append(memberEndTime);
		}
	}
	userInfoStruct.m_bLoginByTax = -1;
	Database::GetInstance()->setUserData(userInfoStruct);
	if (!Database::GetInstance()->isUserConfigExist(userInfoStruct.m_strUserId))
	{
		Database::GetInstance()->replaceUserConfig(userInfoStruct.m_strUserId);
	}
}

bool LoginWeChartWidget::eventFilter(QObject *target, QEvent *e)
{
	if (e->type() == QEvent::MouseButtonRelease)
	{
		if (target == phoneLoginLabel)
		{
			this->isLodingPhoto = false;
			this->isGetStatus = false;
			emit changeLoginWaySiganl(0);
		}
		else if (target == verificationCodeLabel)
		{
			//获取验证码
			if (accountLineEdit->text().size() != 11)
			{
				//手机号不符合规定
				m_bindingHintLabel->setText(QString::fromLocal8Bit("请输入正确的手机号"));
				m_bindingHintLabel->show();
			}
			else
			{
				if (!bindingTimer->isActive())
				{
					verificationCodeLineEdit->clear();
					m_bindingHintLabel->hide();
					verificationCodeLabel->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font:14px 'Microsoft YaHei';font-weight:800; color:#dedede;\">|</span>"
						"<span style=\" font:14px 'Microsoft YaHei';\"/><span style=\" font:14px 'Microsoft YaHei'; color:#999999;\"> 60s后重发</span></p></body></html>"));
					//获取验证码
					bindingTimer->start(1000); // 每隔1s 
					m_bindingThread->setValue(LoginThread::AuthWay, accountLineEdit->text(), "", "bind_mobile");
					m_bindingThread->start();
				}
			}
		}
	}

	return QWidget::eventFilter(target, e);
}


BindingEinWidget::BindingEinWidget(QStringList phoneNumberList,QWidget *parent)
	:QWidget(parent)
	, m_listPhoneNumberList(phoneNumberList)
	, putInButton(new QPushButton(this))
	, numberComboBox(new QComboBox(this))
	, m_bindingThread(new LoginThread(this))
	, m_changeBindingWayLabel(new QLabel(this))
{
	QLabel *statusLabel = new QLabel(this);
	statusLabel->setText(QString::fromLocal8Bit("绑定手机号"));
	statusLabel->setStyleSheet("QLabel{font: 24px 'Microsoft YaHei';font-weight:bold;color: rgb(51, 51, 51);}");
	statusLabel->setGeometry(35, 30, 200, 30);
	QLabel *statusLabel_2 = new QLabel(QString::fromLocal8Bit("请选择需要绑定的手机号"), this);
	statusLabel_2->setStyleSheet("QLabel{font: 14px 'Microsoft YaHei';font-weight:bold;color: rgb(102, 102, 101);}");
	statusLabel_2->setGeometry(35, 60, 170, 20);


	connect(m_bindingThread, &LoginThread::loginSignals, this, &BindingEinWidget::getFilishSlot);
	putInButton->setStyleSheet("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));"
		"border-radius:4px;font: 20px 'Microsoft YaHei';font-weight:400;color:rgba(255, 255, 255, 1);}"
		"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));"
		"border-radius:4px;font: 20px 'Microsoft YaHei';font-weight:400;color:rgba(255, 255, 255, 1);};");
	putInButton->setText(QString::fromLocal8Bit("提交"));
	putInButton->setShortcut(QKeySequence::InsertParagraphSeparator);

	connect(putInButton, &QPushButton::clicked, this, &BindingEinWidget::putInButtonSlot);
	m_changeBindingWayLabel->installEventFilter(this);
	m_changeBindingWayLabel->setText(QString::fromLocal8Bit("<html><head/><body><p>"
		"<span style=\" font-size:14px 'Microsoft YaHei';\"/><span style=\" font-size:14px 'Microsoft YaHei'; color:#1e8cee;\"> 其它方式登录</span></p></body></html>"));
	m_changeBindingWayLabel->setGeometry(155, 260, 90, 20);


	QStringList disposePhoneList;
	int listSize = m_listPhoneNumberList.size();
	for (int i = 0; i < listSize; i++)
	{
		QString phoneNumber = phoneNumberList.at(i);
		if (phoneNumber.size() == 11)
		{
			disposePhoneList.append(phoneNumber.mid(0, 3) + "****" + phoneNumber.mid(7, 4));
		}
		else
		{
			m_listPhoneNumberList.removeOne(phoneNumber);
		}
	}
	putInButton->setGeometry(40, 200, 320, 50);
	numberComboBox->setGeometry(40, 120, 320, 50);
	numberComboBox->setStyleSheet(QString::fromLocal8Bit("QComboBox{background:rgba(255,255,255,1);border:1px solid rgba(222,222,222,1);border-radius:4px;font-size:14px 'Microsoft Yahei';padding-left: 15px;}"
		"QComboBox::drop-down{border-top-right-radius: 4px;border-bottom-right-radius: 4px;subcontrol-origin: padding;subcontrol-position: top right; width:40px;}"
		"QComboBox::down-arrow{ image: url(:/ZcloudDesk/image/downBinding.png); }"
		"QComboBox QAbstractItemView { }"
		"QComboBox QAbstractItemView::item { height: 50px;}"));
	numberComboBox->addItems(disposePhoneList);
}

BindingEinWidget::~BindingEinWidget()
{
}


void BindingEinWidget::putInButtonSlot()
{
	if (m_tipLabel) m_tipLabel->hide();
	m_bindingThread->setValue(LoginThread::BindingEin, m_listPhoneNumberList.at(numberComboBox->currentIndex()),"");
	m_bindingThread->start();
	emit changeLoginWaySiganl(1);

}

void BindingEinWidget::getFilishSlot(int status, UserInfoStruct userInfo)
{
	if (status == 0)
	{
		emit bindingEinSoucces(userInfo);
	}
	else
	{
		//增加错误提示
		if (!m_tipLabel) {
			m_tipLabel = new QLabel(this);
			m_tipLabel->setGeometry(40, 175, 320, 25);
			m_tipLabel->setStyleSheet("font: 14px 'Microsoft YaHei';color: rgb(241, 0, 32);");
		}
		QString strTipStr = QString::fromLocal8Bit("绑定失败，错误码：%1").arg(status);
		if (20019 == status)// 手机号不能为空
		{
			strTipStr = QString::fromLocal8Bit("手机号错误");
		}
		else if (10004 == status)// 手机号不正确
		{
			strTipStr = QString::fromLocal8Bit("手机号不正确");
		}
		//else if (30020 == status)// 验证码过期
		//{
		//	strTipStr = QString::fromLocal8Bit("验证码过期");
		//}
		//else if (30021 == status)// 验证码错误
		//{
		//	strTipStr = QString::fromLocal8Bit("验证码错误");
		//}
		else if (30071 == status)// 手机号已绑定企业
		{
			strTipStr = QString::fromLocal8Bit("手机号已绑定该企业");
		}
		else if (30032 == status)
		{
			strTipStr = QString::fromLocal8Bit("手机号已存在");
		}
		else if (30064 == status)// 手机号绑定失败
		{
			strTipStr = QString::fromLocal8Bit("手机号绑定失败");
		}
		else if (-1 == status)
		{
			strTipStr = QString::fromLocal8Bit("手机号绑定失败，请稍后再试或选择其它方式绑定！");
		}
		m_tipLabel->setText(strTipStr);
		m_tipLabel->show();
		emit changeLoginWaySiganl(2);
	}
}

bool BindingEinWidget::eventFilter(QObject *target, QEvent *e)
{
	if (e->type() == QEvent::MouseButtonRelease)
	{
		if (target == m_changeBindingWayLabel)
		{
			emit changeLoginWaySiganl(0);
		}
	}
	return QWidget::eventFilter(target, e);
}




