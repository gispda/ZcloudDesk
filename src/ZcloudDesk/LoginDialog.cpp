#include "LoginDialog.h"
#include <qdrawutil.h>
#include <QGraphicsDropShadowEffect >
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QDesktopServices>
#include <QRegExpValidator>
#include <QMovie>
#include <QListWidget>
#include <QStyledItemDelegate>
#include <QAbstractItemView>
#include <QSettings>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QApplication>
#include <QLibrary>
#include "ZcloudDesk.h"
#include <QProcess>
#include <QNetworkInterface>
#include <QNetworkCookie>
#include <QNetworkReply>
#include <QTimer>
#include "ZcloudBigData.h"

#define LOGIN_MARGIN_WITH 8

extern QString zhicloudStrToken;
extern QString zhicloudStrUserId;

LoginDialog::LoginDialog(bool bShowMinBtn,QWidget *parent)
	: QDialog(parent)
{
	//登录窗口
	initLoginDialog(bShowMinBtn);
}


LoginDialog::~LoginDialog()
{
}

void LoginDialog::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Escape:
		break;
	default:
		QDialog::keyPressEvent(event);
	}
}

void LoginDialog::initLoginDialog(bool bShowMinBtn)
{
	loginWidget = new LoginWidget( this);
	setButton = new QPushButton(this);
	lodingLabel = new QLabel(this);
	movie = new QMovie(":/ZcloudDesk/image/loginLoding.gif");
	this->resize(816, 516);
	m_bg.load(":/ZcloudDesk/image/loginBack.png");
	//设置窗体透明WindowModal
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	//设置无边框
	this->setWindowFlags(Qt::FramelessWindowHint);

	QPushButton *miniButton = new QPushButton(this);
	miniButton->setStyleSheet("QPushButton{border-image: url(:/ZcloudDesk/image/appcenter_min_nor.png);}\
	QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/appcenter_min_hov.png);};");
	miniButton->setGeometry(732, 20, 32, 28);
	connect(miniButton, &QPushButton::clicked, this, &QDialog::showMinimized);

	QPushButton *closeButton = new QPushButton(this);
	closeButton->setStyleSheet("QPushButton{border-image: url(:/ZcloudDesk/image/appcenter_close_nor.png);}\
							   QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/appcenter_close_hov.png);};");
	
	closeButton->setGeometry(766, 20, 32, 28);

	setButton->setStyleSheet("QPushButton{border-image: url(:/ZcloudDesk/image/login_set_nor.png);}\
							 QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/login_set_hov.png);};");
	setButton->setGeometry(702, 20, 32, 28);

	if (bShowMinBtn)
	{
		miniButton->show();
		miniButton->setGeometry(732, 20, 32, 28);
		setButton->setGeometry(702, 20, 32, 28);
	}
	else
	{
		miniButton->hide();
		setButton->setGeometry(732, 20, 32, 28);
	}
	
	connect(closeButton, &QPushButton::clicked, [this]()
	{
		this->hide();
		if (weChartWidget) weChartWidget->closeLoginWeChartWidget();
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "SLG007");
		this->reject();
	});
	connect(setButton, &QPushButton::clicked, this, &LoginDialog::onSetButtonClicked);

	lodingLabel->setMovie(movie);
	lodingLabel->hide();
	lodingLabel->setGeometry(558, 208, 100, 100);

	loginWidget->setGeometry(408, 58, 400, 450);
	connect(loginWidget, SIGNAL(lodingStartSiganl()), this, SLOT(loadgingStartSlot()));
	connect(loginWidget, SIGNAL(lodingFilishSiganl()), this, SLOT(loadgingFilish()));
	connect(loginWidget, SIGNAL(logingSucceed()), this, SLOT(isAccept()));
	connect(loginWidget, SIGNAL(installSoftwareSignal()), this, SLOT(installSoftwareSlot()));
	connect(loginWidget, &LoginWidget::qrChartLoginSingal, [this]()
	{
		//切换微信登录
		loginWidget->hide();
		initWeChartWidget();
	});
	loginWidget->hide();

}
void LoginDialog::initSetWidget()
{
	if (!setWidget)
	{
		setWidget = new LoginSetWidget(this);
		setWidget->setGeometry(408, 58, 400, 450);
		connect(setWidget, SIGNAL(cancelButtonSignals()), this, SLOT(onCancelButtonClicked()));
		connect(setWidget, SIGNAL(lodingStartSiganl()), this, SLOT(loadgingStartSlot()));
		connect(setWidget, SIGNAL(lodingFilishSiganl()), this, SLOT(loadgingFilish()));
	}
	if (bindingEinWidget) bindingEinWidget->hide();
	if (weChartWidget) weChartWidget->hide();
	setWidget->show();
}

void LoginDialog::initWeChartWidget(int logingInt)
{
	if (bindingEinWidget) bindingEinWidget->hide();
	if (setWidget) setWidget->hide();
#ifdef WCLOGINHIDE
	if (weChartWidget)weChartWidget->hide();
	loginWidget->setShowDownloadSoftware(logingInt);
	loginWidget->show();
	return;
#endif // WCLOGINHIDE

	//微信二维码登录
	if (!weChartWidget)
	{
		weChartWidget = new LoginWeChartWidget(logingInt,this);
		weChartWidget->setGeometry(408, 58, 400, 450);
		connect(weChartWidget, &LoginWeChartWidget::changeLoginWaySiganl, [this](int type)
		{
			if (type == 0)
			{
				//切换为账号登录
				weChartWidget->hide();
				loginWidget->show();
			}
			else if (type == 1)
			{
				weChartWidget->hide();
				setButton->setEnabled(false);
				lodingLabel->show();
				movie->start();
			}
			else if (type == 2)
			{
				lodingLabel->hide();
				movie->stop();
				setButton->setEnabled(true);
				weChartWidget->show();
			}
		});

		connect(weChartWidget, SIGNAL(weChartLoginSucceed(UserInfoStruct)), this, SLOT(wxLoginSoucceedSlog(UserInfoStruct)), Qt::QueuedConnection);
		connect(weChartWidget, SIGNAL(installSoftwareSignal()), this, SLOT(installSoftwareSlot()));
	}
	weChartWidget->show();
	weChartWidget->getQRCode();
}

void LoginDialog::initBindingEinWidget()
{
	//手机号绑定税号
	QStringList readPhoneNumberList;
	Database::GetInstance()->queryPhoneNumber(readPhoneNumberList);
	if (readPhoneNumberList.isEmpty())
	{
		initWeChartWidget();
		return;
	}
	QStringList uniquenessPhoneNumberList;
	for each (QString var in readPhoneNumberList)
	{
		if (!uniquenessPhoneNumberList.contains(var))
		{
			uniquenessPhoneNumberList.append(var);
		}
	}


	if (bindingEinWidget == NULL)
	{
		bindingEinWidget = new BindingEinWidget(uniquenessPhoneNumberList, this);
		bindingEinWidget->setGeometry(408, 58, 400, 450);
		connect(bindingEinWidget, &BindingEinWidget::changeLoginWaySiganl, [this](int type)
		{
			if (type == 0)
			{
				//切换为账号登录
				initWeChartWidget();
			}
			else if (type == 1)
			{
				bindingEinWidget->hide();
				setButton->setEnabled(false);
				lodingLabel->show();
				movie->start();
			}
			else if (type == 2)
			{
				lodingLabel->hide();
				movie->stop();
				setButton->setEnabled(true);
				bindingEinWidget->show();
			}
		});

		connect(bindingEinWidget, &BindingEinWidget::bindingEinSoucces, [this](UserInfoStruct userInfo)
		{
			loginWidget->m_userInfoStruct = userInfo;
			this->accept();

		});
	}
	if (weChartWidget) weChartWidget->hide();
	if (setWidget) setWidget->hide();
	bindingEinWidget->show();
}

void LoginDialog::paintEvent(QPaintEvent* event)
{
	QPainter painter;

	painter.begin(this);
	painter.drawPixmap(rect(), m_bg);
	painter.end();
	return QWidget::paintEvent(event);
}
void  LoginDialog::mousePressEvent(QMouseEvent *event)
{
	this->windowPos = this->pos();            // 获得部件当前位置
	this->mousePos = event->globalPos();     // 获得鼠标位置
	this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
	return QWidget::mousePressEvent(event);
}

void LoginDialog::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->globalPos() - this->dPos);
	return QWidget::mouseMoveEvent(event);
}

void LoginDialog::onSetButtonClicked()
{
	if(weChartWidget) weChartWidget->hide();
	loginWidget->hide();
	initSetWidget();
}

void LoginDialog::onCancelButtonClicked()
{
	if (setWidget) setWidget->hide();
	if (weChartWidget) weChartWidget->hide();
	loginWidget->show();
}

void LoginDialog::loadgingStartSlot()
{
	QObject *wedgetObj = sender();
	if (wedgetObj == loginWidget)
	{
		loginWidget->hide();
		widgetFlag = 0;
	}
	else if (wedgetObj == setWidget)
	{
		setWidget->hide();
		widgetFlag = 1;
	}
	else if (wedgetObj == weChartWidget)
	{
		weChartWidget->hide();
		widgetFlag = 2;
	}
	setButton->setEnabled(false);
	lodingLabel->show();
	movie->start();
}

void LoginDialog::loadgingFilish()
{
	lodingLabel->hide();
	movie->stop();
	setButton->setEnabled(true);
	QObject *wedgetObj = sender();
	if (wedgetObj == loginWidget)
	{
		loginWidget->show();
		widgetFlag = 0;
	}
	else if (wedgetObj == setWidget)
	{
		setWidget->show();
		widgetFlag = 1;
	}
	else if (wedgetObj == weChartWidget)
	{
		weChartWidget->show();
		widgetFlag = 2;
	}
}

void LoginDialog::isAccept()
{
	this->accept();
}

void LoginDialog::wxLoginSoucceedSlog(UserInfoStruct userInfoStruct)
{
	loginWidget->m_userInfoStruct = userInfoStruct;
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "SLG005", ZcloudComFun::getOsVerQt() + "-" + userInfoStruct.m_strMobile + "-" + "2");
	this->accept();
}

void LoginDialog::installSoftwareSlot()
{
	QString softUrl;
	QString softVersion;
	if (ZcloudComFun::getSoftwareData(softUrl, softVersion))
	{
		this->hide();
		if (weChartWidget) weChartWidget->closeLoginWeChartWidget();
		ZhicloudApp::openDownloadSoftware(0, softUrl);
		//重启软件
		QProcess::startDetached(qApp->applicationFilePath(), QStringList());
	}
	else
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("获取开票软件失败，请稍后再试！"));

}

void LoginDialog::initModifyUserNameWidget()
{

	lodingLabel->hide();
	movie->stop();
	setButton->setEnabled(true);
	loginWidget->initModifyUserNameWidget();
}
