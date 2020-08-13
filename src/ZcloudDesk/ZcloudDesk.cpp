#include "ZcloudDesk.h"
#include <QThread>
#include <QDesktopWidget>
#include <QJsonParseError>
#include <QFileInfo>
#include <QJsonObject>
#include <QJsonArray>
#include <QProcess>
#include <QDesktopServices>
#include <QtConcurrent/QtConcurrentRun>
#include <QSettings>
#include <qt_windows.h>
#include <Dbt.h> 
#include <QLibrary>
#include "ZcloudCommon.h"
#include <qt_windows.h>
#include "WallpaperWidget.h"
#include "HttpInterface.h"
#include "TopToolWidget.h"
#include "LoginDialog.h"
#include "SettingWidget.h"
#include "ActivityWidget.h"
#include "CheckUpdater.h"
#include "dlgwait.h"
#include "CalculatorWidget.h"
#include "Database.h"
#include "NoviceDlg.h"
#include "JsInterface.h"
#include <SignInWidget.h>
#include <QMenu>
#include <TwobarCodeWidget.h>
#include "ZcloudEntCenter.h"
#include "ZcloudClient.h"

QString zhicloudStrToken;
QString zhicloudStrUserId;
extern QString g_strAppName;

ZcloudDesk::ZcloudDesk(UserInfoStruct userInfoStruct, QWidget *parent)
	: QMainWindow(parent)
	, m_zhicloudApp(new ZhicloudApp(this))
	, m_stUserInfo(userInfoStruct)
	, m_strSwitchTax(loadJsbTax())//��ֹ�����˰�� ��¼   �γ�ʱ ˰��Ϊ�� 
{

	QIcon icon(":/ZcloudDesk/image/ycs_logo.png");
	system_tray = new QSystemTrayIcon(this);
	system_tray->setIcon(icon);
	system_tray->setToolTip(QString::fromLocal8Bit("�Ʋ�˰"));

	connect(system_tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));
	//��ʾ����
	system_tray->show();




	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowSystemMenuHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowTitle(g_strAppName);
	setStyleSheet("outline: none");

	ZcloudComFun::writeRegReboot(ZcloudComFun::EN_REBOOT_PARAMS);

	resizeAllWidget();
	connect(QApplication::desktop(), SIGNAL(workAreaResized(int)), this, SLOT(resizeAllWidget()));
	
	//!�����ݲɼ��߳�
	m_pBigDataInterface = ZcloudBigDataInterface::GetInstance();

	//!��Ϣ
	m_pMsgCenter = ZcloudMsgCenter::createNew();
	connect(m_pMsgCenter, SIGNAL(changeUnreadMsgNum(int, bool)), this, SLOT(onChangeUnreadMsgNum(int, bool)));
	connect(m_pMsgCenter, SIGNAL(checkTokenFailed(int)), this, SLOT(onCheckTokenFailed(int)));
	connect(m_pMsgCenter, SIGNAL(sigReduceUnreadNum(int)), this, SLOT(onReduceUnreadNum(int)));
	connect(m_pMsgCenter, SIGNAL(sigSendMessageRespone(QString)), this, SLOT(onReciveMsgPopUp(QString)));
	
	//!����Ƿ����
	QString strDownloadUrl, strMd5;
	CheckUpdater obj;
	if (obj.checkUpdater(m_stUserInfo.m_strUserId,m_stUserInfo.m_strToken))
	{
		obj.startUpdaterProcess(true);
	}
	
	//!��ط����߳�
	m_pCheckServiceThread = new CheckServiceThread(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, m_stUserInfo.m_strHzsId, this);
	connect(m_pCheckServiceThread, &QThread::finished, m_pCheckServiceThread, &QObject::deleteLater);
	m_pCheckServiceThread->start();

	//!�ܵ�ͨ���߳�
	m_pPipeServerThread = new PipeServerThread(this);
	connect(m_pPipeServerThread, SIGNAL(sigReciveMsgPopUp(QString)), this, SLOT(onReciveMsgPopUp(QString)));
	connect(m_pPipeServerThread, &QThread::finished, m_pPipeServerThread, &QObject::deleteLater);
	m_pPipeServerThread->start();

	//!�����Ӧ
	ui.labelCompName->installEventFilter(this);
	connect(ui.settingButton, SIGNAL(clicked()), this, SLOT(openSettingCenterWidget()));
	connect(ui.appButton, SIGNAL(clicked()), this, SLOT(openAppCenterWidget()));
	connect(ui.hideButton, SIGNAL(clicked()), this, SLOT(hideWindow()));

	connect(ui.billListButton, SIGNAL(clicked()), this, SLOT(openWorkers()));


	//connect(ui.msgButton, SIGNAL(clicked()), this, SLOT(openMsgCenterWidget()));
	//ui.msgButton->setNumber(0);
	//ui.msgButton->installEventFilter(this);

	connect(this, SIGNAL(startInitSignal(int)), this, SLOT(startInitSlot(int)));
	connect(m_zhicloudApp, &ZhicloudApp::bindingPhoneSignals, this, &ZcloudDesk::bingdingPhoneSlot);
	connect(m_zhicloudApp, &ZhicloudApp::buyVipListSignals,this, &ZcloudDesk::buyMembershipSlot);
	connect(m_zhicloudApp, SIGNAL(changeTaxSignals(QString, QString)), this, SLOT(onChangeTax(QString, QString)));

	registerDevice();

	startInitWork();

	QTimer::singleShot(0, this, SLOT(noviceSlot()));
}

void ZcloudDesk::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason){
	case QSystemTrayIcon::Trigger:
		this->hide();
		break;
	case QSystemTrayIcon::DoubleClick:
		//˫������ͼ��
		//˫������ʾ�����򴰿�
		this->show();
		break;
	default:
		break;
	}
}

ZcloudDesk::~ZcloudDesk()
{

	release();
}
void ZcloudDesk::startInitSlot(int flag)
{
	closeAllWindows(flag);
	startInitWork();
	this->setEnabled(true);
	switchAcc = false;
	m_bCheckToken = true;
	showDlgWait(false);
	showDlgWait(false,true);
}

void ZcloudDesk::getScreenInfo()
{
	QDesktopWidget *deskWgt = QApplication::desktop();
	QRect availableRect = deskWgt->availableGeometry();
	m_nAvailableWidth = availableRect.width();
	m_nAvailableHeight = availableRect.height();
}

void ZcloudDesk::resizeAllWidget()
{
	getScreenInfo();

	this->setGeometry(0, 0, m_nAvailableWidth, m_nAvailableHeight);
	ui.ZcloudTopWidget->setGeometry(0, 0, m_nAvailableWidth, 30);

	this->setFocus();
	this->activateWindow();
	this->raise();
}

void ZcloudDesk::onChangeUnreadMsgNum(int nNum,bool bAdd)
{
	if (bAdd)
	{
		m_nUnreadCount += nNum;
	}
	else
	{
		m_nUnreadCount = nNum;
	}
	refreshMsgToolTip();
	if (m_pMsgCenter->msgCenterShow())
	{
		m_pMsgCenter->refreshMsgCenter(m_nUnreadCount);
	}
}

void ZcloudDesk::getTopTool()
{
	//!�رն�������
	QList<CommWidget*>	list = findChildren<CommWidget*>("AppCommWidgetWidget");
	foreach(CommWidget *obj, list)
	{
		obj->deleteLater();
		obj = NULL;
	}

	clearTopTool();

	HttpInterface	hInter;
	QString   strRet;
	if (hInter.winHttpGetTopToolInfo(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, strRet))
	{
		vtrAppDataInfos topToolInfos;

		//!����json
		analysisTopTool(strRet, topToolInfos);

		//!����ڴ� !�������ݿ�
		vtrAppDataInfos::iterator itr = topToolInfos.begin();
		for (; itr != topToolInfos.end();	++itr)
		{
			AppDataInfo*	pInfo = (*itr);
			if (NULL != pInfo)
			{
				Database::GetInstance()->insertTopToolInfo(pInfo, m_stUserInfo.m_strUserId);
				delete pInfo;
				pInfo = NULL;
			}
		}
		topToolInfos.clear();
	}

	//!�����ݿ��ѯ��������ƥ��������
	vtrAppDataInfos topToolInfos;
	Database::GetInstance()->queryTopToolInfo(m_stUserInfo.m_strUserId, topToolInfos);
	showTopTool(topToolInfos);
}

void ZcloudDesk::analysisTopTool(const QString& strJson, vtrAppDataInfos& topToolInfos)
{
	QByteArray byte_array = strJson.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return;
	}
	if (!parse_doucment.isObject())
	{
		return;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("status").toInt();

	if (status == 0)
	{
		QJsonValue data = obj.take("data");
		if (!data.isArray())
		{
			return;
		}
		QJsonArray jsonArray = data.toArray();
		int nSize = jsonArray.size();

		QStringList newTopToolIdList;
		for (int nIndex = 0; nIndex < nSize; ++nIndex)
		{
			QString strToolIconPath;
			int		nDbUpdateTime	= -1;
			bool    bShow			= true;
			QJsonObject dataTool = jsonArray.at(nIndex).toObject();
			QString strName = dataTool.take("top_app_name").toString();
			QString strToolId = dataTool.take("top_app_id").toString();
			newTopToolIdList << strToolId;
			int nJsonUpdateTime = dataTool.take("update_time").toInt();
			if (Database::GetInstance()->queryUpdateToolInfo(m_stUserInfo.m_strUserId, strToolId, nDbUpdateTime, strToolIconPath, bShow))
			{
				if (nJsonUpdateTime == nDbUpdateTime	&&	QFile::exists(strToolIconPath))
				{
					continue;
				}
			}
			AppDataInfo* pToolInfo = new AppDataInfo;
			pToolInfo->m_strAppId = strToolId;
			pToolInfo->m_strAppName = strName;
			pToolInfo->m_strAppAlias = dataTool.take("alias_name").toString();
			pToolInfo->m_strAppIconDownUrl = dataTool.take("icon").toString();
			pToolInfo->m_strAppIconPath = ZcloudComFun::downloadPic(pToolInfo->m_strAppIconDownUrl, QApplication::applicationDirPath().append("/CacheImage/topToolImage"));
			pToolInfo->m_bAppType = dataTool.take("app_type").toInt() == 1 ? true : false;
			pToolInfo->m_strAppDownloadUrl = dataTool.take("url").toString();
			pToolInfo->m_strAppOnLineVerson = dataTool.take("version").toString();
			pToolInfo->m_intAppSize = dataTool.take("size").toInt();
			pToolInfo->m_strAppDesc = dataTool.take("introduce").toString();
			pToolInfo->m_strAppUpdateSpecification = dataTool.take("update_introduce").toString();
			pToolInfo->m_strAppParams = dataTool.take("allow_send_third_party").toInt() ? dataTool.take("send_third_party_config").toString() : "";
			pToolInfo->bSMethod = dataTool.take("send_third_party_method").toInt();
			pToolInfo->m_bAppIsDefaultWeb = dataTool.take("is_default_browser").toInt();
			pToolInfo->m_iUpMethod = dataTool.take("update_method").toInt();
			pToolInfo->m_isBindingPhone = dataTool.take("trigger_register").toInt();
			pToolInfo->m_strAppExecName = dataTool.take("execution_path").toString();
			pToolInfo->bAuth = dataTool.take("auth").toInt();
			pToolInfo->bState = dataTool.take("state").toInt();
			pToolInfo->m_update_time =nJsonUpdateTime;
			pToolInfo->m_dtAppCreatTimer = QDateTime::fromTime_t(dataTool.take("create_time").toInt());

			pToolInfo->m_intAppSort = dataTool.take("sort").toInt();

			topToolInfos.push_back(pToolInfo);
		}


		//ɾ��  ����Ķ���Ӧ��
		vtrAppDataInfos oldTopToolInfos;
		if (Database::GetInstance()->queryTopToolInfo(m_stUserInfo.m_strUserId, oldTopToolInfos))
		{
			int nCount = oldTopToolInfos.count();
			vtrAppDataInfos::const_iterator	itr = oldTopToolInfos.begin();
			for (int index = 0; itr != oldTopToolInfos.end(), index < nCount; index++, ++itr)
			{
				AppDataInfo*  pInfo = (*itr);

				if (!newTopToolIdList.contains(pInfo->m_strAppId))
				{
					//ɾ������Ӧ��
					Database::GetInstance()->removeTopToolInfo(m_stUserInfo.m_strUserId, pInfo->m_strAppId);
				}

			}
		}
		//!����ڴ�
		vtrAppDataInfos::iterator oldItr = oldTopToolInfos.begin();
		for (; oldItr != oldTopToolInfos.end(); ++oldItr)
		{
			AppDataInfo*	pInfo = (*oldItr);
			if (NULL != pInfo)
			{
				delete pInfo;
				pInfo = NULL;
			}
		}
	}

}

void ZcloudDesk::showTopTool(const vtrAppDataInfos& topToolInfos)
{
	QLayout*	pLayout = ui.ZcloudTopWidget->layout();
	QBoxLayout*	pBoxLayout = (QBoxLayout*)pLayout;
	int nCount = topToolInfos.count();
	vtrAppDataInfos::const_iterator	itr = topToolInfos.begin();
	for (int index = 0; itr != topToolInfos.end(), index < nCount; index++, ++itr)
	{
		AppDataInfo*  pInfo = (*itr);
		QPushButton *button = NULL;
		if (QString::fromLocal8Bit("��Ա����") == pInfo->m_strAppName)
		{
			button = new QPushButton(ui.ZcloudTopWidget);
			button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
			
			button->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/ZcloudDesk/image/vip.png);"
				"color:rgb(255,255,255);font: 12px \"΢���ź�\";padding-left:5px;padding-right:5px;}"
			"QPushButton:hover{border-image:url(:/ZcloudDesk/image/vip_hover.png);color:rgb(255,255,255);font:12px \"΢���ź�\"}"
			"QPushButton:pressed{border-image:url(:/ZcloudDesk/image/vip_hover.png);color:rgb(255,255,255);font:12px \"΢���ź�\"};"));
		}
		else
		{
			QPixmap pixmap;
			if (!QFile::exists(pInfo->m_strAppIconPath))
			{
				pixmap.load(":/ZcloudDesk/image/default.png");
			}
			else
			{
				pixmap.load(pInfo->m_strAppIconPath);
			}
			QIcon icon(pixmap);
			button = new QPushButton(ui.ZcloudTopWidget);
			button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
			button->setIconSize(QSize(pixmap.size().width(), 26));
			button->setIcon(icon);
			button->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/ZcloudDesk/image/bg_transparent.png);color: rgb(255, 255, 255);\n"
				"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";padding-left:8px;padding-right:8px;}\n"
				"QPushButton:hover{border-image: url(:/ZcloudDesk/image/bg_transparent_hover.png);color: rgb(255, 255, 255);\n"
				"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";padding-left:8px;padding-right:8px;}\n"
				"QPushButton:pressed{border-image: url(:/ZcloudDesk/image/bg_transparent_pre.png);color: rgb(255, 255, 255);\n"
				"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";padding-left:8px;padding-right:8px;};\n"
				""));	
		}
		button->setText(pInfo->m_strAppAlias.isEmpty() ? pInfo->m_strAppName : pInfo->m_strAppAlias);
		button->setFixedHeight(26);
		button->adjustSize();
		connect(button, SIGNAL(clicked()), this, SLOT(onTopToolClick()));
		button->setVisible(pInfo->bState);
		m_mpTopToolBtnInfos[button] = pInfo;
		pBoxLayout->insertWidget(index + 5, button);
	}
	//pBoxLayout->addWidget(ui.spaceButton);
	//pBoxLayout->addWidget(ui.settingButton);
	//pBoxLayout->insertStretch(0);
}

void ZcloudDesk::openSettingCenterWidget()
{
	SettingWidget*	pSettingWidget = findChild<SettingWidget*>(QString::fromLocal8Bit("SettingWidget"));
	if (NULL != pSettingWidget)
	{
		return;
	}
	SettingWidget*	pWidget = new SettingWidget(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, m_stUserInfo.m_strProvinceId,this);
	connect(pWidget, SIGNAL(sigTopCheckChanged(bool)), this, SLOT(onTopCheckChanged(bool)));
	connect(pWidget, SIGNAL(showNoviceDlgSignal(bool)), this, SLOT(noviceSlot(bool)));
	connect(pWidget, SIGNAL(sigRightCheckChanged(bool)), this, SLOT(onRightCheckChanged(bool)));
	connect(pWidget, SIGNAL(sigToolCheckChanged(QString, bool)), this, SLOT(onToolCheckChanged(QString, bool))); 
	connect(pWidget, SIGNAL(sigLogout()), this, SLOT(onLogout()));
	pWidget->show();
	m_pBigDataInterface->produceData("M01", "OP001", "TTA006");
}

void ZcloudDesk::onTopToolClick()
{
	QObject*	pObj = sender();
	if (NULL == pObj)
	{
		return;
	}
	QPushButton*	pButton = qobject_cast<QPushButton*>(pObj);
	if (NULL == pButton)
	{
		return;
	}
	AppDataInfo* pInfo = m_mpTopToolBtnInfos[pButton];
	QString strToolName = pButton->text();

	if (strToolName == QString::fromLocal8Bit("��˰������"))
	{
		openTaxCalculatorWidget(pInfo->m_strAppDownloadUrl);
	}
	else if (strToolName == QString::fromLocal8Bit("��˰����"))
	{
		openFiscalCalendarWidget(pInfo->m_strAppDownloadUrl);
	}
	else if (strToolName == QString::fromLocal8Bit("��ֽ"))
	{
		openWallpaperWidget(pInfo->m_strAppDownloadUrl);
	}
	else if (strToolName == QString::fromLocal8Bit("�"))
	{
		openActivityCenterWidget(pInfo->m_strAppDownloadUrl);
	}

	
	else if (strToolName == QString::fromLocal8Bit("����"))
	{
		//ui.billListButton
		/////��������������Ӵ�����ҵ   ����ok
		/*if (m_pEntCenter == NULL)
			createEnterCenterMgr();
		m_pEntCenter->createEntCenter(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken);*/


		//////��ά��ͻ������������ ����ok
		
		///CustomerManagerinvite();

		////�ϴ� ͼƬ   ����ok
		
		//QString strRet;
		//ZcloudClient::winHttpUploadImage("", m_stUserInfo.m_strToken, strRet);

		/////������ҵ��������Ϣ   ���Գɹ�

		//CompanyBankInfo  bankinfo;
		//bankinfo.m_strTaxno = "210624197305200017";
		//bankinfo.m_strBankname = QString::fromLocal8Bit("�й����гɶ���˫����֧·֧��");
		//bankinfo.m_strBankaccount = "609358084893";
		//bankinfo.m_strAddress = QString::fromLocal8Bit("�ɶ��гɻ���˫����֧·28��");
		//bankinfo.m_strTelno = "028 82909982";
		//QString strRet;
		//ZcloudClient::winHttpUpdatebankInfo(bankinfo, m_stUserInfo.m_strToken, strRet);

		//lockScreen();
	}
	else if (strToolName == QString::fromLocal8Bit("����"))
	{
		openSearch();
	}
	else if (strToolName == QString::fromLocal8Bit("��ͼ"))
	{
		openScreenShot();
	}
	else if (strToolName == QString::fromLocal8Bit("ǩ��"))
	{
		openSignInWidegt(this);
	}
	else if (strToolName == QString::fromLocal8Bit("��Ա����"))
	{
		openVipCenterWidget();
	}
	else 
	{
		//�����Ӧ�÷���
		//TopToolWidget*	pWidget = findChild<TopToolWidget*>(QString::fromLocal8Bit("TopToolWidget"));
		//if (NULL != pWidget)
		//{
		//	if (pInfo->m_strAppName == pWidget->windowTitle())
		//	{
		//		return;
		//	}
		//}
		//TopToolWidget*	pTopToolWidget = new TopToolWidget(pInfo,this);

		m_pBigDataInterface->produceData("M01", "OP001", "TTA005");
		openApp(pInfo);
	}
}

void ZcloudDesk::openEntCenterWidget()
{
	if (m_stUserInfo.m_strUsername.isEmpty()){
		LoginDialog loginDialog;
		QString strTip;
		int logingInt;
		loginDialog.isUserNameLogin();
		//logingInt = loginDialog.checkLogin(strTip);
		loginDialog.initWeChartWidget(logingInt);
			if (loginDialog.exec() == QDialog::Accepted)
			{
				UserInfoStruct userInfo = loginDialog.getUserInfoStruct();
				if (!userInfo.m_strUsername.isEmpty()){
					/*m_stUserInfo = userInfo;
					startInitWork();*/
					//showDlgWait(true);
					m_stUserInfo = userInfo;
					m_nUnreadCount = 0;
					QFuture<void>	funIr = QtConcurrent::run(this, &ZcloudDesk::exitThread, 0);
				}
				else
				{
					////�����û�����
					loginDialog.initModifyUserNameWidget();
					if (loginDialog.exec() == QDialog::Accepted)
					{
						userInfo = loginDialog.getUserInfoStruct();
						//	userInfo.m_strUsername = "";
						if (!userInfo.m_strUsername.isEmpty()){
							/*m_stUserInfo = userInfo;
							startInitWork();*/

							showDlgWait(true);
							m_stUserInfo = userInfo;
							m_nUnreadCount = 0;
							QFuture<void>	funIr = QtConcurrent::run(this, &ZcloudDesk::exitThread, 0);
						}

					}

				}
			}
		return;
	}


	


	createEnterCenterMgr();

	InitEntCenter();


	if ((m_stUserInfo.m_strCompanyName.isEmpty())){

		QMenu* m_pMenu = new QMenu();
		QAction* m_pActionCustomerManager = new QAction(m_pMenu);
		QAction* m_pActionEnterpriseManager = new QAction(m_pMenu);
		QAction* m_pActionCreateEntCompany = new QAction(m_pMenu);
		m_pActionCustomerManager->setText(QString::fromLocal8Bit("�ɿͻ������������"));
		m_pActionEnterpriseManager->setText(QString::fromLocal8Bit("����ҵ����Ա�������"));
		m_pActionCreateEntCompany->setText(QString::fromLocal8Bit("��������ҵ"));

		m_pMenu->addAction(m_pActionCustomerManager);
		m_pMenu->addAction(m_pActionEnterpriseManager);
		m_pMenu->addAction(m_pActionCreateEntCompany);

		ui.twobarcodebtn->setMenu(m_pMenu);
		

		connect(m_pActionCustomerManager, &QAction::triggered, this, &ZcloudDesk::CustomerManagerinvite);
		connect(m_pActionEnterpriseManager, &QAction::triggered, this, &ZcloudDesk::EnterpriseManagerinvite);

		connect(m_pActionCreateEntCompany, &QAction::triggered, this, &ZcloudDesk::openCreateEntDlg);


		m_pMenu->setAttribute(Qt::WA_TranslucentBackground);
		m_pMenu->setStyleSheet(QString::fromLocal8Bit(
			"QMenu{background-color:rgba(255, 255, 255, 1);"//��������
			"border:1px solid rgba(222, 222, 222,1);"//�����˵���Ե
			"font-size:12px 'Microsoft Yahei';"
			"text-align:center;"
			"color:rgb(51, 51, 51);}"
			"QMenu::item{"//������ɫ
			"height:30px;"
			"background-color:rgb(255, 255, 255);"
			"margin:0px 0px;"//���ò˵������߾�
			"padding:1px 20px;}"//���ò˵����������º����ҵ��ڱ߾࣬Ч�����ǲ˵��е���Ŀ�����������˼��
			"QMenu::item:pressed{"
			"background-color:rgb(242,242,242);"//ѡ�е���ʽ
			"font-size: 12px 'Microsoft Yahei';color:rgb(51,51,51);}"//������ɫ
			"QMenu::item:selected{"//�˵����Ч��
			"font-size: 12px 'Microsoft Yahei';color:rgb(51,51,51);"//������ɫ
			"background-color:rgb(242, 242, 242);}"));

		

		//m_pEntCenter->createEntCenter();

		//	return;
	}


	m_pEntCenter->openEntCenter(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, m_stUserInfo.m_strTruename, m_stUserInfo.m_strJob, m_stUserInfo.m_bLoginByTax, m_stUserInfo.m_strMobile, m_stUserInfo.m_strCompanyId, m_stUserInfo.m_strUsername);
	m_pBigDataInterface->produceData("M01", "OP001", "TTA013");
}
//!�ͻ���������
void ZcloudDesk::CustomerManagerinvite(){
	TwobarCodeWidget* ptwobarCodeWidget = new TwobarCodeWidget(m_stUserInfo.m_strCompanyId,m_stUserInfo.m_strToken,QString::fromLocal8Bit("�ɿͻ������������"),NULL);
	ptwobarCodeWidget->show();
};
//!��ҵ����Ա����
void ZcloudDesk::EnterpriseManagerinvite(){
	TwobarCodeWidget* ptwobarCodeWidget = new TwobarCodeWidget("", m_stUserInfo.m_strToken, QString::fromLocal8Bit("����ҵ����Ա�������"), NULL);
	ptwobarCodeWidget->show();
};

ZcloudEntCenter* ZcloudDesk::getEntCenter(){
	if (NULL == m_pEntCenter)
	{
		m_pEntCenter = ZcloudEntCenter::createNew();
		connect(m_pEntCenter, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));
		connect(m_pEntCenter, SIGNAL(bingdingPhoneSignal()), this, SLOT(bingdingPhoneSlot()));
		connect(m_pEntCenter, SIGNAL(sigSignBindingSucceeded(const QString&)), this, SLOT(slotChangeMobile(const QString&)));
		connect(m_pEntCenter, SIGNAL(openSignInWidegt()), this, SLOT(openSignInWidegt()));
		connect(m_pEntCenter, &ZcloudEntCenter::sendVipListSignals, this, &ZcloudDesk::buyMembershipSlot);
		connect(m_pEntCenter, &ZcloudEntCenter::trueNameJobChange, [this](QString trueName, QString strJob)
		{
			m_stUserInfo.m_strTruename = trueName;
			m_stUserInfo.m_strJob = strJob;

		});
	}
	return m_pEntCenter;
}
void ZcloudDesk::openCreateEntDlg()
{
	ZcloudEntCenter* pEntCenter = getEntCenter();
	pEntCenter->createEntCenter(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken);
}
void  ZcloudDesk::openWorkers(){
	ZcloudEntCenter* pEntCenter=getEntCenter();
	pEntCenter->openWorkers(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken);

}



void  ZcloudDesk::buyMembershipSlot(QStringList vipNameList, QStringList vipIdList, QStringList vipTimeList)
{
	//vipTimeList ��Ա����ʱ��
	m_stUserInfo.m_strListAppVipNameList = vipNameList;
	m_stUserInfo.m_strListAppVipList = vipIdList;
	m_stUserInfo.m_vipDateTimeList = vipTimeList;
	//�޸����ݿ�
	Database::GetInstance()->setUserData(m_stUserInfo);
	//����Ӧ������
	if (m_zhicloudApp)
	{
		m_zhicloudApp->setVipList(vipNameList, vipIdList, vipTimeList);
	}
	//�޸Ķ�����vip
	ui.labelAvatar->setPic(m_stUserInfo.m_logoPath, true);
	ui.labelAvatar->repaint();
}

void ZcloudDesk::openMsgCenterWidget()
{
	m_pMsgCenter->openMsgCenter(m_nUnreadCount);
	m_pBigDataInterface->produceData("M01", "OP001", "TTA007");
}

void ZcloudDesk::hideWindow(){
	//setWindowState(Qt::WindowMinimized);
	this->hide();
}
void ZcloudDesk::showWindow(){
	if (this->isHidden()){
		this->show();
	}
}


void ZcloudDesk::openAppCenterWidget()
{
	m_zhicloudApp->openAppCenterDlg();
	m_pBigDataInterface->produceData("M01", "OP001", "TTA010");
}

void ZcloudDesk::openVipCenterWidget()
{
	ZcloudEntCenter* pEntCenter = getEntCenter();

	bool bJoinEnt = true;
	if (m_stUserInfo.m_strCompanyName.isEmpty())
	{
		if (1 != m_stUserInfo.m_bLoginByTax)
		{
			bJoinEnt	=	false;
		}
	}
	pEntCenter->openVipInfoCenter(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, bJoinEnt, m_stUserInfo.m_bHasMember);
	m_pBigDataInterface->produceData("M01", "OP001", "TTA009");
}

void ZcloudDesk::openWallpaperWidget(QString strUrl)
{
	m_pBigDataInterface->produceData("M01", "OP001", "TTA004");
	if (ZcloudComFun::winHttpSSO(m_stUserInfo.m_strToken, m_stUserInfo.m_strUserId))
	{
		WallpaperWidget*	pWidget = findChild<WallpaperWidget*>(QString::fromLocal8Bit("WallpaperWidget"));
		if (NULL != pWidget)
		{
			return;
		}
		QString strWallpaperUrl = ZcloudComFun::getTopToolUrl(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, strUrl);
		WallpaperWidget* pWallpaperWidget = new WallpaperWidget(strWallpaperUrl, this);
		pWallpaperWidget->show();
	}
}

void ZcloudDesk::openActivityCenterWidget(QString strUrl)
{
	m_pBigDataInterface->produceData("M01", "OP001", "TTA015");
	if (ZcloudComFun::winHttpSSO(m_stUserInfo.m_strToken, m_stUserInfo.m_strUserId))
	{
		ActivityWidget*	pWidget = findChild<ActivityWidget*>(QString::fromLocal8Bit("ActivityWidget"));
		if (NULL != pWidget)
		{
			return;
		}
		QString strActivityUrl = ZcloudComFun::getTopToolUrl(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, strUrl);
		ActivityWidget* pActivityWidget = new ActivityWidget(strActivityUrl, this);
		pActivityWidget->show();	
	}
}

void ZcloudDesk::openScreenShot()
{
	QProcess::startDetached("SoftWare\\SnapShot.exe", QStringList());
	m_pBigDataInterface->produceData("M01", "OP001", "TTA002");
}

void ZcloudDesk::lockScreen()
{
	typedef VOID(*MYPROC)();
	HINSTANCE hinstLib;
	MYPROC ProcAdd;
	BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;
	hinstLib = LoadLibraryA("user32.dll");
	if (hinstLib != NULL)
	{
		ProcAdd = (MYPROC)GetProcAddress(hinstLib, "LockWorkStation");
		if (fRunTimeLinkSuccess = (ProcAdd != NULL))
			(ProcAdd)();
		fFreeResult = FreeLibrary(hinstLib);
	}
	m_pBigDataInterface->produceData("M01", "OP001", "TTA003");
}

void ZcloudDesk::openSearch()
{
	QProcess::startDetached("SoftWare\\Everything\\Everything.exe");
	m_pBigDataInterface->produceData("M01", "OP001","TTA001");
}

void ZcloudDesk::openTaxCalculatorWidget(QString strUrl)
{
	m_pBigDataInterface->produceData("M01", "OP001", "TTA011");
	if (ZcloudComFun::winHttpSSO(m_stUserInfo.m_strToken, m_stUserInfo.m_strUserId))
	{
		CalculatorWidget*	pWidget = findChild<CalculatorWidget*>(QString::fromLocal8Bit("CalculatorWidget"));
		if (NULL != pWidget)
		{
			if (QString::fromLocal8Bit("��˰������") == pWidget->windowTitle())
			{
				return;
			}
		}
		QString strTaxCalculatorUrl = ZcloudComFun::getTopToolUrl(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, strUrl);
		CalculatorWidget* pCalculatorWidget = new CalculatorWidget(QString::fromLocal8Bit("��˰������"), strTaxCalculatorUrl, this);
		pCalculatorWidget->show();
	}
}

void ZcloudDesk::keyPressEvent(QKeyEvent * e)
{
	return QWidget::keyPressEvent(e);
}


void ZcloudDesk::registerDevice()
{
	static const GUID GUID_DEVINTERFACE_LIST[] =
	{
		// GUID_DEVINTERFACE_USB_DEVICE
		{ 0xA5DCBF10, 0x6530, 0x11D2, { 0x90, 0x1F, 0x00, 0xC0, 0x4F, 0xB9, 0x51, 0xED } },
		// GUID_DEVINTERFACE_DISK
		{ 0x53f56307, 0xb6bf, 0x11d0, { 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b } },
		// GUID_DEVINTERFACE_HID,
		{ 0x4D1E55B2, 0xF16F, 0x11CF, { 0x88, 0xCB, 0x00, 0x11, 0x11, 0x00, 0x00, 0x30 } },
		// GUID_NDIS_LAN_CLASS
		{ 0xad498944, 0x762f, 0x11d0, { 0x8d, 0xcb, 0x00, 0xc0, 0x4f, 0xc3, 0x35, 0x8c } }
		//// GUID_DEVINTERFACE_COMPORT
		//{ 0x86e0d1e0, 0x8089, 0x11d0, { 0x9c, 0xe4, 0x08, 0x00, 0x3e, 0x30, 0x1f, 0x73 } },
		//// GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR
		//{ 0x4D36E978, 0xE325, 0x11CE, { 0xBF, 0xC1, 0x08, 0x00, 0x2B, 0xE1, 0x03, 0x18 } },
		//// GUID_DEVINTERFACE_PARALLEL
		//{ 0x97F76EF0, 0xF883, 0x11D0, { 0xAF, 0x1F, 0x00, 0x00, 0xF8, 0x00, 0x84, 0x5C } },
		//// GUID_DEVINTERFACE_PARCLASS
		//{ 0x811FC6A5, 0xF728, 0x11D0, { 0xA5, 0x37, 0x00, 0x00, 0xF8, 0x75, 0x3E, 0xD1 } }
	};

	//ע�����¼�
	HDEVNOTIFY hDevNotify;
	DEV_BROADCAST_DEVICEINTERFACE NotifacationFiler;
	ZeroMemory(&NotifacationFiler, sizeof(DEV_BROADCAST_DEVICEINTERFACE));
	NotifacationFiler.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
	NotifacationFiler.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;

	for (int i = 0; i < sizeof(GUID_DEVINTERFACE_LIST) / sizeof(GUID); i++)
	{
		NotifacationFiler.dbcc_classguid = GUID_DEVINTERFACE_LIST[i];//GetCurrentUSBGUID();//m_usb->GetDriverGUID();

		hDevNotify = RegisterDeviceNotification((HANDLE)this->winId(), &NotifacationFiler, DEVICE_NOTIFY_WINDOW_HANDLE);
		if (!hDevNotify)
		{
			int Err = GetLastError();
			qDebug() << "RegisterDevice failed" << endl;
		}
	}
}

bool ZcloudDesk::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
	if (eventType == "windows_generic_MSG" || eventType == "windows_dispatcher_MSG")
	{
		MSG *msg = (MSG *)message;
		if ((msg->message == WM_QUERYENDSESSION) && (msg->lParam != ENDSESSION_LOGOFF))
		{
			//isIgnalClose = false;
			//onLogout();
		}
		else if (msg->message == WM_KEYDOWN || msg->message == WM_SYSKEYDOWN)
		{
			if ((VK_F4 == msg->wParam) && (::GetKeyState(VK_MENU) & 0xF000))
			{
				return TRUE;
			}
		}
		else if (msg->message == WM_DEVICECHANGE)
		{
			PDEV_BROADCAST_HDR lpdb = (PDEV_BROADCAST_HDR)msg->lParam;
			if (msg->wParam == DBT_DEVICEARRIVAL)
			{
				QTimer::singleShot(1000, this, SLOT(onSwitchTip()));
			}
			else if (msg->wParam == DBT_DEVICEREMOVECOMPLETE)
			{
				onSwitchTip(false);
			}
		}
	}
	return QWidget::nativeEvent(eventType, message, result);
}


void ZcloudDesk::onSwitchTip(bool flag /*= true*/)
{
	QString strTaxNo = loadJsbTax();
	if (!m_stUserInfo.m_strTaxNumber.isEmpty() && !strTaxNo.isEmpty())
	{
		//���ֽ�˰��  ���� ��Ʊ��� ����װ��Ʊ
		m_stUserInfo.isHideNR = true;
		if (m_zhicloudApp) m_zhicloudApp->setIsHideNR(true);
		if (m_strSwitchTax != strTaxNo)
		{
			m_strSwitchTax = strTaxNo;
			if (strTaxNo != m_stUserInfo.m_strTaxNumber)
			{
				if (ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_BINDING, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("ϵͳ��⵽�µ��ƶ���Ʊ�豸\r\n�Ѳ���,�Ƿ������л�˰�ţ�"),
					QString::fromLocal8Bit("�����л�"), QString::fromLocal8Bit("ȡ��")) == QDialog::Accepted)
				{
					//�л��µ�˰��  ������
					onSwitchAcc(1, false, m_strSwitchTax,"");
				}
			}
		}
	}
	else if (!flag && !m_strSwitchTax.isEmpty())
	{
		//���ֽ�˰��  ���� ��Ʊ��� ����װ��Ʊ
		m_strSwitchTax.clear();
		if (m_zhicloudApp) m_zhicloudApp->setIsHideNR(false);
	}

}

QString ZcloudDesk::loadJsbTax()
{
	QString strTaxNo = "";
	typedef char* (_stdcall *pfnGetJsbMsg)();
	QLibrary lib("GetJsbMsg2.dll");
	if (lib.load())
	{
		pfnGetJsbMsg getJsbMsg = (pfnGetJsbMsg)lib.resolve("GetJsbMsg_TaxCode");
		if (getJsbMsg)
		{
			strTaxNo = getJsbMsg();
			strTaxNo = strTaxNo.replace("$", "");
			m_stUserInfo.isHideNR = !strTaxNo.isEmpty();
		}
	}
	return strTaxNo;
}

void ZcloudDesk::closeEvent(QCloseEvent *event)
{
	//if (isIgnalClose)
	//{
	//	event->ignore();
	//	return;
	//}
	return QWidget::closeEvent(event);
}

bool ZcloudDesk::eventFilter(QObject *target, QEvent *e)
{
	if (ui.labelCompName == target)
	{
		if (e->type() == QEvent::MouseButtonRelease)
		{
			ui.labelCompName->removeEventFilter(this);
			openEntCenterWidget();
			ui.labelCompName->installEventFilter(this);
		}
	}
	/*else if (ui.msgButton == target)
	{
		if (e->type() == QEvent::Enter)
		{
			if (m_nUnreadCount	>	0)
			{
				QString	strMsg = QString::fromLocal8Bit("%1(%2)").arg(QString::fromLocal8Bit("δ����Ϣ")).arg(m_nUnreadCount);
				ui.msgButton->setToolTip(strMsg);
			}
			else
			{
				ui.msgButton->setToolTip(QString::fromLocal8Bit("����δ����Ϣ"));
			}	
		}
	}*/
	return QMainWindow::eventFilter(target, e);
}

void ZcloudDesk::openApp(QString strAppId)
{
	m_zhicloudApp->openZhicloudApp(strAppId);
}

void ZcloudDesk::openApp(AppDataInfo* pInfo, QString type)
{
	AppDataInfo pData = (*pInfo);
	if (!pData.m_bAppType)
	{
		bool isNewVerson = false;
		m_zhicloudApp->getVer(pData, isNewVerson, false);
		if (!isNewVerson)
		{
			//cs Ӧ�ò�ѯ�汾
			if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��⵽���µĵİ汾��\r\n�Ƿ�����������")) == QDialog::Accepted)
			{
				if (ZhicloudApp::openDownloadSoftware(0, pData.m_strAppDownloadUrl) == QDialog::Accepted)
				{
					bool isSwitch = true;
					std::map<QPushButton*, AppDataInfo*>::iterator itr = m_mpTopToolBtnInfos.begin();
					for (; itr != m_mpTopToolBtnInfos.end(); ++itr)
					{
						AppDataInfo*	pTopInfo = itr->second;
						if (pTopInfo == pInfo) isSwitch = false;
					}
					if (!isSwitch && pInfo)
					{
						bool isNewVerson = false;//�Ƿ��� ���°汾
						//������״ΰ�װ��ƥ�� �汾 
						bool isInstallFlag = m_zhicloudApp->getVer(pData, isNewVerson);
						if (isInstallFlag)//�ж� �Ѿ���װ�˵�  �������°汾(����ǵ�һ�ΰ�װ �Ͳ����ж��汾)
						{
							Database::GetInstance()->insertTopToolInfo(&pData, m_stUserInfo.m_strUserId);
						}
					}
				}
				return;
			}
		}
	}


	if (!m_zhicloudApp->openZhicloudApp(pData, type))
	{
		// m_isBindingPhone == 0ʱ���ж����õ���ʱ��
		if (!pData.m_isBindingPhone  &&  !pData.m_experienceTime.isEmpty() && pData.m_experienceTime != "0")
		{
			if (pData.m_enExperienceTime.isEmpty() || pData.m_enExperienceTime == "0")
			{
				//���ѵ�¼��������
				//if (ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_BINDING, QString::fromLocal8Bit("����Ӧ��"), QString::fromLocal8Bit("���ֻ��ź�,��������%1���๦��").arg(g_strAppName),
				//	QString::fromLocal8Bit("��¼��"), QString::fromLocal8Bit("��ʼ����")) == QDialog::Accepted)
				//{
				//	bingdingPhoneSlot();
				//	return;
				//}
				//else
				//{
					//��ʼ����  �޸����õ���ʱ��
					int endTime = QDateTime::currentDateTime().toTime_t() + pData.m_experienceTime.toInt() * 24 * 60 * 60;
					if (Database::GetInstance()->updateTopAppPaidTime(pData.m_strAppId, m_stUserInfo.m_strUserId, endTime, false))
					{
						if (pInfo)
						{
							pInfo->m_enExperienceTime = QString::number(endTime);
							m_zhicloudApp->openZhicloudApp(pData, type);
						}
					}
				//}
			}
			else
			{
				//�ж��Ƿ���
				if (pData.m_enExperienceTime.toInt() < QDateTime::currentDateTime().toTime_t())
				{
					//if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ʾ"),
					//	QString::fromLocal8Bit("���ֻ��ź�,��������%1���๦��").arg(g_strAppName))
					//	== QDialog::Accepted)
					//{
						bingdingPhoneSlot();
					//}
					return;
				}
			}
		}
		else
		{
			//csӦ�ô�ʧ�ܣ���Ҫ��װ  �߿�Ʊ����İ�װ����
			if (!pData.m_bAppType)
			{
				if (pInfo)
				{
					bool isNewVerson = false;
					if (m_zhicloudApp->getVer(*pInfo, isNewVerson))
					{
						Database::GetInstance()->updateTopApp(*pInfo, m_stUserInfo.m_strUserId);
						m_zhicloudApp->openZhicloudApp(*pInfo, type);
						return;
					}
				}

				//���� �л�˰��ʱָ���ͷţ��Ƿ��ͷ� pData ���ڴ�
				if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��Ӧ��δ��װ��\r\n�Ƿ�������װ��Ӧ�÷���")) == QDialog::Accepted)
				{
					if (ZhicloudApp::openDownloadSoftware(3, pData.m_strAppDownloadUrl) == QDialog::Accepted)
					{
						bool isNewVerson = false;//�Ƿ��� ���°汾
						//��ѯע����������
						//��ֹ�л�˰��ʱ ��������Ӧ�ã�����Ӧ���Ѿ� ���
						bool isSwitch = true;
						std::map<QPushButton*, AppDataInfo*>::iterator itr = m_mpTopToolBtnInfos.begin();
						for (; itr != m_mpTopToolBtnInfos.end(); ++itr)
						{
							AppDataInfo*	pTopInfo = itr->second;
							if (pTopInfo == pInfo) isSwitch = false;
						}
						if (!isSwitch &&  pInfo)
						{
							pInfo->m_strAppCurrentVerson = pInfo->m_strAppOnLineVerson;
							//������״ΰ�װ��ƥ�� �汾 
							bool isInstallFlag = m_zhicloudApp->getVer(*pInfo, isNewVerson);
							if (isInstallFlag)//�ж� �Ѿ���װ�˵�  �������°汾(����ǵ�һ�ΰ�װ �Ͳ����ж��汾)
							{
								if (pInfo)
								{
									pInfo->m_bAppIsInstall = true;
								}
							}
							Database::GetInstance()->updateTopApp(*pInfo, m_stUserInfo.m_strUserId);
						}
					}
				}
			}
		}
	}
}


void ZcloudDesk::showCompInfo()
{

	
	ui.labelAvatar->setVisible(false);
	ui.billListButton->setVisible(false);
	ui.customServiceButton->setVisible(false);
	ui.spaceButtonName->setVisible(false);
	ui.usernameButton->setVisible(false);
	QString strText;
	
	////�ο͵�½
	if (m_stUserInfo.m_bLoginByTax==-8){
		ui.labelCompName->setMinimumWidth(0);


		strText = queryTaxInfo();
		ui.labelCompName->setText(strText);
		//����ͼ��
		//ui.labelCompName->setPixmap();
		return;
	}
	else{
		ui.spaceButtonName->setVisible(true);
		ui.usernameButton->setVisible(true);
		ui.usernameButton->setText(m_stUserInfo.m_strUsername);
	}




	
	strText = m_stUserInfo.m_strCompanyName;

	if (strText.isEmpty())
	{
		if (1 == m_stUserInfo.m_bLoginByTax)
		{
			strText = QString::fromLocal8Bit("��δ��ѯ��������ҵ");
		}
		else
		{
			QString strCompanyName = m_stUserInfo.m_strCompanyName;
			//if (strCompanyName.isEmpty() || strCompanyName.contains("wechat_") || strCompanyName.contains("nick_") || strCompanyName.contains("user_"))
			if (strCompanyName.isEmpty() )

			{
				strText = QString::fromLocal8Bit("������ҵ");
			}
			else
			{
				strText = strCompanyName;
			}
			
			ui.labelAvatar->setVisible(true);
			ui.billListButton->setVisible(true);
			ui.customServiceButton->setVisible(true);
		}	
	}
	else
	{
		if (strText.length() > 12)
		{
			ui.labelCompName->setMinimumWidth(150);
			QFontMetrics fontMetrics(ui.labelCompName->font());
			int fontSize = fontMetrics.width(strText);//��ȡ֮ǰ���õ��ַ��������ش�С

			QString strElideText = fontMetrics.elidedText(strText, Qt::ElideRight, ui.labelCompName->width());
			ui.labelCompName->setText(strElideText);
			//setElideText(12, ui.labelCompName, strText);
		}
		else
		{
			ui.labelCompName->setMinimumWidth(0);
			ui.labelCompName->setText(strText);
		}
		ui.labelAvatar->setVisible(true);
		ui.billListButton->setVisible(true);
		ui.customServiceButton->setVisible(true);

	}
	bool bVip = (0 == m_stUserInfo.m_strListAppVipList.size()) ? false : true;
	QFileInfo fileInfo(m_stUserInfo.m_logoPath);
	if (!fileInfo.isFile())
	{
		m_stUserInfo.m_logoPath = ":/ZcloudDesk/image/img_tx.png";
	}
	ui.labelAvatar->setPic(m_stUserInfo.m_logoPath, bVip);
	ui.labelAvatar->repaint();
}

void ZcloudDesk::refreshMsgToolTip()
{
	//if (0 < m_nUnreadCount)
	//{
	//	ui.msgButton->setNumber(1);
	//}
	//else
	//{
	//	ui.msgButton->setNumber(0);
	//}
}

void ZcloudDesk::onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd)
{
	if (switchAcc) return;
	this->setEnabled(false);
	
	switchAcc = true;
	m_bCheckToken = false;
	int loginFlag = -1;	
	UserInfoStruct userInfoStruct = m_stUserInfo;
	if (bOther)
	{
		zhicloudStrToken = "";
		zhicloudStrUserId = "";
		//�򿪵�¼����
		LoginDialog loginDialog(false);
		loginDialog.initWeChartWidget();
		if (loginDialog.exec() == QDialog::Accepted)
		{
			userInfoStruct = loginDialog.getUserInfoStruct();
			loginFlag = 0;
		}
		else
		{
			switchAcc = false;
			m_bCheckToken = true;
			this->setEnabled(true);
			return;
		}
	}
	else
	{
		showDlgWait(true);
		loginFlag = LoginThread::httpLogin(bLoginByTax, strTaxNo_userName, strPwd, userInfoStruct);
	}

	if (loginFlag == 0)
	{
		showDlgWait(true);
		m_stUserInfo = userInfoStruct;
		m_nUnreadCount = 0;
		QFuture<void>	funIr	=	QtConcurrent::run(this, &ZcloudDesk::exitThread, 0);
		//funIr.waitForFinished();
	}
	else
	{
	//{"status":30070, "message" : "token��ʧЧ"}
		//30001 �˺Ż����������
		//10002 token��ʽ����ȷ
		showDlgWait(false);
		QString tipStr = QString::fromLocal8Bit("�л��˺�ʧ�ܣ����Ժ�����!�����룺%1").arg(loginFlag);
		if (30070 == loginFlag || 10002 == loginFlag)
		{
			tipStr = QString::fromLocal8Bit("�л��˺�ʧ�ܣ����˺��ѹ��ڣ�\r\n��ѡ�������˺����µ�¼!");
		}
		else if (loginFlag == -1)
		{
			tipStr = QString::fromLocal8Bit("�л��˺�ʧ�ܣ�\r\n��ѡ�������˺�!");
		}
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), tipStr, this);
		switchAcc = false;
		m_bCheckToken = true;	
		this->setEnabled(true);
	}
}

void ZcloudDesk::showDlgWait(bool isShow, bool bBind)
{
	if (bBind)
	{
		DlgWait*	switchAccDlgWait = findChild<DlgWait*>(QString::fromLocal8Bit("bindWait"));
		if (!switchAccDlgWait)
		{
			if (!isShow) return;
			switchAccDlgWait = new DlgWait(QString::fromLocal8Bit("���ֻ������Ժ�..."), this);
			switchAccDlgWait->setObjectName(QString::fromLocal8Bit("bindWait"));
		}
		QDesktopWidget* desktop = QApplication::desktop();
		switchAccDlgWait->move((desktop->width() - switchAccDlgWait->width()) / 2, (desktop->height() - switchAccDlgWait->height()) / 2);

		if (isShow)
		{
			switchAccDlgWait->start();
		}
		else
		{
			switchAccDlgWait->stop();
		}
	}
	else
	{
		DlgWait*	switchAccDlgWait = findChild<DlgWait*>(QString::fromLocal8Bit("switchAccDlgWait"));
		if (!switchAccDlgWait)
		{
			if (!isShow) return;
			switchAccDlgWait = new DlgWait(QString::fromLocal8Bit("�л��У����Ժ�..."), this);
			switchAccDlgWait->setObjectName(QString::fromLocal8Bit("switchAccDlgWait"));
		}
		QDesktopWidget* desktop = QApplication::desktop();
		switchAccDlgWait->move((desktop->width() - switchAccDlgWait->width()) / 2, (desktop->height() - switchAccDlgWait->height()) / 2);

		if (isShow)
		{
			switchAccDlgWait->start();
		}
		else
		{
			switchAccDlgWait->stop();
		}
	}
	QCoreApplication::processEvents();
}

void ZcloudDesk::exitThread(int flag)
{
	//!Ӧ�����Ĺر�
	m_zhicloudApp->exitAppCenterThread();
	m_pMsgCenter->stopMsgThread();
	emit startInitSignal(flag);
}
void ZcloudDesk::onlyExitThread(UserInfoStruct& userInfo,QString strOldUserId, QString strNewUserId, QString strNewToken)
{
	if (!strOldUserId.isEmpty() && !strNewUserId.isEmpty())
	{
		//�������ݿ� ���к��� userId ������
		//���ĵ�¼ѡ��
		//���Ķ���Ӧ��
		Database::GetInstance()->changeSetUsrId(strOldUserId, strNewUserId,m_stUserInfo.m_strCompanyId);
		//���ķ������
		ServerDatabase::GetInstance()->changeServerUsrId(strOldUserId, strNewUserId);
		//������ҵ����
		Database::GetInstance()->changeEndUsrId(strOldUserId, strNewUserId);
		//������Ϣ����
		Database::GetInstance()->changeMsgUsrId(strOldUserId, strNewUserId);
		//����Ӧ������
		if (m_zhicloudApp)
		{
			m_zhicloudApp->changeAppUserId(strOldUserId, strNewUserId);
			//����Ӧ������Ӧ�ü��� ɾ�����û�����Ӧ�� ������ȡ���¼���
			m_zhicloudApp->removeAppClassAll(strOldUserId);
		}	
		showDlgWait(true,true);
		m_stUserInfo = userInfo;
		if (m_pEntCenter)
		{
			if (m_pEntCenter->isEntCenterShow())
			{
				m_pEntCenter->openEntCenter(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, m_stUserInfo.m_strTruename, m_stUserInfo.m_strJob, m_stUserInfo.m_bLoginByTax, m_stUserInfo.m_strMobile, m_stUserInfo.m_strCompanyId, m_stUserInfo.m_strUsername);
			}	
		}	
		QFuture<void>	funIr = QtConcurrent::run(this, &ZcloudDesk::exitThread, 1);	
	}
	else
	{
		//ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�����˴��������µ�¼��"));
		return;
	}
}

void ZcloudDesk::closeAllWindows(int flag)
{
	if (0 == flag)
	{
		//!��ҵ���Ĺر�
		if (m_pEntCenter != NULL)
		{
			m_pEntCenter->closeAllEntWidget();
			m_pEntCenter = NULL;
		}
	}
	


	//!��Ϣ���Ĺر�
	if (m_pMsgCenter!=NULL)
	m_pMsgCenter->closeAllMsgWidget();
	//!Ӧ�����Ĺر�
	if (m_zhicloudApp!=NULL)
	m_zhicloudApp->closeAppCenter();

	//!�رն�������
	QList<CommWidget*>	list = findChildren<CommWidget*>("AppCommWidgetWidget");
	foreach(CommWidget *obj, list)
	{
		obj->deleteLater();
		obj = NULL;
	}

	clearTopTool();
}

void ZcloudDesk::onRightCheckChanged(bool bShow)
{
	m_zhicloudApp->setClassIsHind(m_stUserInfo.m_bHideAppClass, !bShow);
	Database::GetInstance()->updateUserConfig(m_stUserInfo.m_strUserId, bShow, 1);
}

void ZcloudDesk::onTopCheckChanged(bool bShow)
{
	ui.ZcloudTopWidget->setHaveHide(!bShow);
	Database::GetInstance()->updateUserConfig(m_stUserInfo.m_strUserId, bShow, 0);
}

void ZcloudDesk::onToolCheckChanged(QString strToolId, bool bShow)
{
	std::map<QPushButton*, AppDataInfo*>::iterator itr = m_mpTopToolBtnInfos.begin();
	for (; itr != m_mpTopToolBtnInfos.end();	++itr)
	{
		QPushButton*	pButton		=	itr->first;
		AppDataInfo*	pTopInfo = itr->second;
		if (NULL == pTopInfo)
		{
			continue;
		}
		if (strToolId == pTopInfo->m_strAppId)
		{
			if (NULL != pButton)
			{
				pButton->setVisible(bShow);
				Database::GetInstance()->updateToolInfo(m_stUserInfo.m_strUserId, strToolId, bShow);
			}
		}
	}
}

void ZcloudDesk::clearTopTool()
{
	std::map<QPushButton*, AppDataInfo*>::iterator itr = m_mpTopToolBtnInfos.begin();
	for (; itr != m_mpTopToolBtnInfos.end();	++itr)
	{
		QPushButton*	pBtn		= itr->first;
		AppDataInfo*	pTopTool = itr->second;
		if (NULL != pTopTool)
		{
			delete pTopTool;
			pTopTool = NULL;
		}
		if (NULL != pBtn)
		{
			pBtn->close();
			pBtn->deleteLater();
			pBtn = NULL;
		}
	}
	m_mpTopToolBtnInfos.clear();
}

void ZcloudDesk::startInitWork()
{
	//!��ʼ����������
	getTopTool();


	////����ҵ���ĵĴ��������ᵽ��������ע����ȡ��˰�ŵ���̨ƥ�䡣


	///createEnterCenterMgr();


	//!���ù�˾���֡�ͷ��
	showCompInfo();

	//!ʹ���µ��û� �������ϱ�
	m_pBigDataInterface->initData(m_stUserInfo.m_strUserId, m_stUserInfo.m_strCompanyId, m_stUserInfo.m_strHzsId, m_stUserInfo.m_strProvinceId, m_stUserInfo.m_strCityId, m_stUserInfo.m_strAreaId);

	//!���ö������Ҳ���ʾ
	bool bShowTop = true, bShowRight = true;
	Database::GetInstance()->queryUserConfig(m_stUserInfo.m_strUserId, bShowTop, bShowRight);
	onTopCheckChanged(bShowTop);
	onRightCheckChanged(bShowRight);

	//!��Ϣ����
	m_pMsgCenter->startMsgThread(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, m_stUserInfo.m_strCompanyId);
	m_pMsgCenter->setUserData(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, m_stUserInfo.m_strCompanyId);
	
	//�����û����� ��ʼ���ò�Ӧ��
	m_zhicloudApp->setUserInfo(m_stUserInfo,
	//m_zhicloudApp->setUserInfo(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, m_stUserInfo.m_strTaxNumber, m_stUserInfo.m_strMachine, m_stUserInfo.m_strHzsId,
	//	m_stUserInfo.m_strTruename, m_stUserInfo.m_strCompanyName, m_stUserInfo.m_strListAppVipList, m_stUserInfo.m_strListAppVipNameList, m_stUserInfo.m_isHxNumber,
	//	m_stUserInfo.m_strMobile,
		this);
}

void ZcloudDesk::onLogout()
{
	ZcloudComFun::writeRegReboot(ZcloudComFun::EN_REBOOT_PARAMS);



	QString strUrl = QString("/ucenter/user/logout");




	QString strPost,strRet;

	strPost = QString("token=%1").arg(m_stUserInfo.m_strToken);


	bool bret = ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);

	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		//return false;
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("ϵͳ�˳�"), QString::fromLocal8Bit("�������쳣"));
	}
	if (!parse_doucment.isObject())
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("ϵͳ�˳�"), QString::fromLocal8Bit("�������쳣"));
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("code").toInt();

	bool jmsg;
	if (0 == status)
	{
		jmsg = obj.take("data").toBool();	
		if (jmsg)
		{
			//ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("ϵͳ�˳�"), QString::fromLocal8Bit("�����˳�"));
		}
		else
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("ϵͳ�˳�"), QString::fromLocal8Bit("�˳�ʧ��"));
	}

    
	

	QProcess p;
	QString c = "taskkill /im ZcloudDesk.exe /f";
	p.execute(c);
	p.close();
}

void ZcloudDesk::release()
{
	
	if (NULL != system_tray)
	{
		system_tray->hide();
		system_tray = NULL;
	}
	if (NULL != m_pBigDataInterface)
	{
		m_pBigDataInterface->stopThread();
		m_pBigDataInterface = NULL;
	}
	if (NULL != m_pPipeServerThread)
	{
		m_pPipeServerThread->stopThread();
		m_pPipeServerThread->wait(-1);
		m_pPipeServerThread->deleteLater();
		m_pPipeServerThread = NULL;
	}
	if (NULL != m_pCheckServiceThread)
	{
		m_pCheckServiceThread->stopImmediately();
		m_pCheckServiceThread->wait(-1);
		m_pCheckServiceThread->deleteLater();
		m_pCheckServiceThread = NULL;
	}
	if (NULL != m_pMsgCenter)
	{
		m_pMsgCenter->destroy();
		m_pMsgCenter = NULL;
	}
	if (NULL != m_pEntCenter)
	{
		m_pEntCenter->destroy();
		m_pEntCenter = NULL;
	}

	if (NULL != m_zhicloudApp)
	{
		m_zhicloudApp->closeAppCenter();
		m_zhicloudApp->deleteLater();
		m_zhicloudApp = NULL;
	}

	clearTopTool();
}

void ZcloudDesk::onChangeTax(QString strTaxNo, QString strMachine)
{
	onSwitchAcc(true, false, strTaxNo, "");
}

bool ZcloudDesk::getAppData(QString appId, QString &appName, QString &appIconPath)
{
	return m_zhicloudApp->getAppData(appId, appName, appIconPath);
}

void ZcloudDesk::bingdingPhoneSlot()
{
	//���ֻ���
	//�򿪵�¼����
	//if (m_stUserInfo.m_strTaxNumber.isEmpty())
	//{
	//	//ֻ���˺ŵ�¼
	//	ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�ǳ���Ǹ�������˺ŵ�¼��\r\n���ܰ󶨣�"));
	//}
	//else 
		if (m_stUserInfo.m_strMobile.isEmpty())
	{
		zhicloudStrToken = m_stUserInfo.m_strToken;
		zhicloudStrUserId = m_stUserInfo.m_strUserId;
		LoginDialog loginDialog;
		loginDialog.initBindingEinWidget();
		if (loginDialog.exec() == QDialog::Accepted)
		{
			UserInfoStruct userInfo = loginDialog.getUserInfoStruct();
			QString mobile = userInfo.m_strMobile;
			if (!mobile.isEmpty())
			{
				slotBindingSucceeded(userInfo,userInfo.m_strUserId, mobile, userInfo.m_strToken);
			}
			else
			{
				//�󶨳ɹ������ֻ���Ϊ��
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�ֻ���Ϊ�գ���ʧ�ܣ�"));
			}
		}
	}
	else
	{
		//������ δ���� �ֻ���
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���˺��Ѱ��ֻ����벻Ҫ���°󶨣�"));
	}
}

void ZcloudDesk::slotBindingSucceeded(UserInfoStruct& userInfo,const QString &strUserId, const QString &strMobile, const QString &strToken)
{
	if (strUserId.isEmpty() || strMobile.isEmpty() || strToken.isEmpty())
	{
		return;
	}
	//�޸����ݿ���˺ŵ��ֻ���
	Database::GetInstance()->addPhoneNumber(strMobile, m_stUserInfo.m_strUserId);

	LoginSetingStruct loginSetingStruct;
	Database::GetInstance()->findLoginSet(loginSetingStruct);

	if (loginSetingStruct.loginByTax	==	0)
	{
		//ֻ���˺ŵ�¼ �´ε�¼��ʽ���ֻ���+token
		loginSetingStruct.loginByTax = -1;
		loginSetingStruct.userName = strMobile;
	}
	loginSetingStruct.token = strToken;
	loginSetingStruct.uid = strUserId;
	Database::GetInstance()->setLoginSet(loginSetingStruct);

	slotChangeMobile(strMobile);
	if (strUserId != m_stUserInfo.m_strUserId)
	{
		this->setEnabled(false);
		JsInterface::GetInstance()->changeUserIdtoken(strUserId, strToken);
		onlyExitThread(userInfo,m_stUserInfo.m_strUserId, strUserId, strToken);
		return;
	}
	if (strToken != m_stUserInfo.m_strToken &&	!strToken.isEmpty())
	{
		m_stUserInfo.m_strToken = strToken;
		JsInterface::GetInstance()->changeUserIdtoken(strUserId, strToken);
		if (m_zhicloudApp) m_zhicloudApp->setToken(m_stUserInfo.m_strToken);
		if (m_pEntCenter)  m_pEntCenter->setToken(m_stUserInfo.m_strToken);
		//������Ϣ���ĵ� token ������
	}
}

void ZcloudDesk::slotChangeMobile(const QString &strMobile)
{
	if (strMobile.isEmpty())
	{
		return;
	}
	m_stUserInfo.m_strMobile = strMobile;
	if (m_zhicloudApp) m_zhicloudApp->setMobile(strMobile);
	if (m_pEntCenter) m_pEntCenter->setMobile(strMobile);
}

void ZcloudDesk::onCheckTokenFailed(int status)
{
	if (!m_bCheckToken)
	{
		return;
	}
	if (-1 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ĵ�¼�ѹ��ڣ������µ�¼��"));
	}
	else if (-2 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�����˺����������ط���¼�������������˲�\r\n������ע���˺Ű�ȫ��"));
	}
	ZcloudComFun::writeRegReboot(ZcloudComFun::EN_NOREBOOT);
	QProcess p;
	QString c = "taskkill /im ZcloudDesk.exe /f";
	p.execute(c);
	p.close();
}

void ZcloudDesk::openFiscalCalendarWidget(QString strUrl)
{
	m_pBigDataInterface->produceData("M01", "OP001", "TTA017");
	if (ZcloudComFun::winHttpSSO(m_stUserInfo.m_strToken, m_stUserInfo.m_strUserId))
	{
		CalculatorWidget*	pWidget = findChild<CalculatorWidget*>(QString::fromLocal8Bit("CalculatorWidget"));
		if (NULL != pWidget)
		{
			if (QString::fromLocal8Bit("��˰����") == pWidget->windowTitle())
			{
				return;
			}
		}
		QString strFiscalCalendarUrl = ZcloudComFun::getTopToolUrl(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, strUrl);
		CalculatorWidget* pCalculatorWidget = new CalculatorWidget(QString::fromLocal8Bit("��˰����"), strFiscalCalendarUrl, this);
		pCalculatorWidget->show();
	}
}

void ZcloudDesk::openSignInWidegt(QWidget* pParentWidget)
{
	m_pBigDataInterface->produceData("M01", "OP001", "TTA014");
	SignInWidget*	pWidget = findChild<SignInWidget*>(QString::fromLocal8Bit("SignInWidget"));
	if (NULL != pWidget)
	{
		return;
	}
	bool bBindPhone = true;
	if (m_stUserInfo.m_strMobile.isEmpty())
	{
		bBindPhone = false;
	}
	if (!bBindPhone)
	{
		bingdingPhoneSlot();
	}
	else
	{
		SignInWidget*	pSignInWidget = new SignInWidget(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, pParentWidget);
		connect(pSignInWidget, SIGNAL(sigAdvertisingClick(int, QString)), this, SLOT(onAdvertisingClick(int, QString)));
		connect(pSignInWidget, SIGNAL(modifyCoinCount(int)), this, SLOT(onModifyCoinCount(int)));
		pSignInWidget->show();
	}	
}

void ZcloudDesk::onReduceUnreadNum(int nUnread)
{
	m_nUnreadCount = nUnread;
	refreshMsgToolTip();
}

void ZcloudDesk::onReciveMsgPopUp(QString strText)
{
	QStringList strTextList;
	strTextList = strText.split("+");

	int nSize = strTextList.size();
	if (nSize < 10)
	{
		return;
	}
	int nResType		= strTextList.at(0).toInt();
	QString strUid		= strTextList.at(1);
	QString strToken	= strTextList.at(2); 
	QString strCompId	= strTextList.at(3);
	QString strMsgId	= strTextList.at(4); 
	QString strBtnId	= strTextList.at(5); 
	int nBtnType		= strTextList.at(6).toInt();
	QString strTarget	= strTextList.at(7);
	bool bRead			= strTextList.at(8).toInt();
	bool bFromPopUp		= strTextList.at(9).toInt();
	if (!bRead)
	{
		m_pMsgCenter->reportMsgInfo(strUid, strMsgId,strCompId);
		if (m_nUnreadCount>0)
		{
			m_nUnreadCount--;
			m_pMsgCenter->reduceUnreadNum();
		}
		refreshMsgToolTip();
		ServerDatabase::GetInstance()->insertMsgOper(strUid, strToken, strCompId, m_stUserInfo.m_strHzsId, strMsgId, 1, "");
	}
	
	if (1 == nResType)	//����ť���
	{
		if (1 == nBtnType)	//!������
		{
			QString strOperandId = bFromPopUp ? "TMP004" : "TMD012";
			m_pBigDataInterface->produceData("M00", "OP001", strOperandId, QString::fromLocal8Bit("%1-%2").arg(strMsgId).arg(strTarget));
			QDesktopServices::openUrl(QUrl::fromUserInput(strTarget));
		}
		else if (2 == nBtnType)
		{
			QString strOperandId = bFromPopUp ? "TMP006" : "TMD013";
			m_pBigDataInterface->produceData("M00", "OP001", strOperandId, strMsgId);
			openApp(strTarget);
		}
		else if (0 == nBtnType)	//!����Ĭ�Ϲر�
		{
			m_pBigDataInterface->produceData("M00", "OP001", "TMP005", strMsgId);
		}
		else if (3 == nBtnType)	//!����ť
		{
			QString strOperandId = bFromPopUp ? "TMP007" : "TMD004";
			m_pBigDataInterface->produceData("M00", "OP001", strOperandId, strMsgId);
		}
		else if (4 == nBtnType)	//!���½ǵ����ر�
		{
			m_pBigDataInterface->produceData("M00", "OP001", "TMP002", strMsgId);
		}
		else if (5 == nBtnType)	//!�鿴����
		{
			m_pBigDataInterface->produceData("M00", "OP001", "TMP001", strMsgId);
			m_pMsgCenter->openAssignMsgCenter(m_nUnreadCount, strMsgId);
		}
		else if (6 == nBtnType)	//!��������
		{
			QString strOperandId = bFromPopUp ? "TMP015" : "TMD002";
			m_pBigDataInterface->produceData("M00", "OP001", strOperandId, strMsgId);

			QString strUrl = QString("%1?user_id=%2&token=%3").arg(strTarget).arg(strUid).arg(strToken);
			openServiceFee(strUrl);
		}
		ServerDatabase::GetInstance()->insertMsgOper(strUid, strToken, strCompId, m_stUserInfo.m_strHzsId, strMsgId, 2, strBtnId);
	}
	else if (2 == nResType)		//!���رհ�ť
	{
		QString strOperandId = bFromPopUp ? "TMP014" : "TMD011";
		m_pBigDataInterface->produceData("M00", "OP001", strOperandId, strMsgId);
	}
	else if (3 == nResType)	//!ͼƬ���
	{
		if (1 == nBtnType)	//!������
		{
			QString strOperandId = bFromPopUp ? "TMP016" : "TMD014";
			m_pBigDataInterface->produceData("M00", "OP001", strOperandId, strMsgId);
			QDesktopServices::openUrl(QUrl::fromUserInput(strTarget));
		}
		else if (2 == nBtnType)
		{
			QString strOperandId = bFromPopUp ? "TMP017" : "TMD015";
			m_pBigDataInterface->produceData("M00", "OP001", strOperandId, strMsgId);
			openApp(strTarget);
		}
		ServerDatabase::GetInstance()->insertMsgOper(strUid, strToken, strCompId, m_stUserInfo.m_strHzsId, strMsgId, 3, "");
	}
	else if (4 == nResType)	//!����
	{
		m_pBigDataInterface->produceData("M00", "OP001", "TMP018", strMsgId);
		std::map<QPushButton*, AppDataInfo*>::iterator itr = m_mpTopToolBtnInfos.begin();
		for (; itr != m_mpTopToolBtnInfos.end();	++itr)
		{
			AppDataInfo*	pInfo = itr->second;
			if (pInfo->m_strAppAlias	==	QString::fromLocal8Bit("�"))
			{
				QPushButton*	pBtn = itr->first;
				if (NULL	!=	pBtn)
				{
					emit pBtn->clicked();
				}
			}
		}
	}
	else if (5 == nResType)	//!ͼƬ��Ϣ��������
	{
		m_pBigDataInterface->produceData("M00", "OP000", "TMP021", strMsgId);
	}
	else if (6 == nResType)	//!���½���Ϣ��������
	{
		m_pBigDataInterface->produceData("M00", "OP000", "TMP019", strMsgId);
	}
	else if (7 == nResType)	//!������Ϣ��������
	{
		m_pBigDataInterface->produceData("M00", "OP000", "TMP020", strMsgId);
	}
	else if (8 == nResType)	//!����ѵ��ڴ�������
	{
		m_pBigDataInterface->produceData("M00", "OP000", "TMP022", strMsgId);
	}
	else if (9 == nResType)	//!��Ϣ�������������
	{
		QString strOperandId = bFromPopUp ? "TMP024" : "TMD016";
		m_pBigDataInterface->produceData("M00", "OP006", strOperandId, strMsgId);
	}
}
QRect ZcloudDesk::getWidgetRect(int i)
{
	int x, y, w, h;
	switch (i)
	{
	case 1:
		x = ui.labelAvatar->pos().x();
		y = ui.labelAvatar->pos().y();
		w = ui.labelAvatar->width() + ui.labelCompName->width() + 10;
		h = ui.labelAvatar->height();
		break;
	case 2:
		x = ui.appButton->pos().x();
		y = ui.appButton->pos().y();
		w = ui.appButton->width();
		h = ui.appButton->height();
		break;
	case 3:
		if (m_zhicloudApp)
		{
			return m_zhicloudApp->getRightRect();
		}
		//x = ui.rightWidget->x();// m_nAvailableWidth - 120;
		//y = ui.rightWidget->y();
		//w = ui.rightWidget->width();
		//h = ui.rightWidget->height();//zpppMenuButtonList.size() * 100;
		break;
	case 4:
		/*x = ui.msgButton->x();
		y = ui.msgButton->y();
		w = ui.msgButton->width();
		h = ui.msgButton->height();*/
		break;
	case 5:
		x = ui.settingButton->x();
		y = ui.settingButton->y();
		w = ui.settingButton->width();
		h = ui.settingButton->height();
		break;

	default:
		break;
	}
	return QRect(x, y, w, h);
}

void ZcloudDesk::noviceSlot(bool flag)
{
	LoginSetingStruct  loginSetingStruct;
	if (flag || Database::GetInstance()->findLoginSet(loginSetingStruct) && loginSetingStruct.bShowGuide)
	{
		//if (ui.rightWidget->isInitClass())
		NoviceDlg* paa = new NoviceDlg(this);
		//else
		//	QTimer::singleShot(2000, this, SLOT(noviceSlot()));
	}
	onSwitchTip();
}

void ZcloudDesk::setElideText(int nPixSize, QLabel* pLabel, const QString& strText)
{
	QFont font("Microsoft YaHei");
	font.setPixelSize(nPixSize);
	pLabel->setFont(font);
	QFontMetrics fontMetrics(pLabel->font());
	int fontSize = fontMetrics.width(strText);//��ȡ֮ǰ���õ��ַ��������ش�С
	QString strElideText;
	if (fontSize > pLabel->width())
	{
		strElideText = fontMetrics.elidedText(strText, Qt::ElideRight, pLabel->width());//����һ������ʡ�Ժŵ��ַ���
	}
	else
	{
		strElideText = strText;
	}
	pLabel->setText(strElideText);
	pLabel->adjustSize();
}

void ZcloudDesk::onAdvertisingClick(int nType, QString strTarget)
{
	if (1 == nType)
	{
		QDesktopServices::openUrl(QUrl::fromUserInput(strTarget));
	}
	else if (2 == nType)
	{
		openApp(strTarget);
	}
}

void ZcloudDesk::openServiceFee(QString strUrl)
{
	ZcloudEntCenter* pEntCenter = getEntCenter();
	pEntCenter->openServiceFeeCenter(strUrl);
}

void ZcloudDesk::onModifyCoinCount(int nCount)
{
	if (NULL	!=	m_pEntCenter)
	{
		m_pEntCenter->modifyCoinCount(nCount);
	}
}

QString ZcloudDesk::queryTaxInfo()
{
	QString strTaxno = ZcloudComFun::getTaxnumber();

	//strTaxno = "210624197305200017";
	bool bret = false;
	bool bisjoin = false;
	int nroletype = -1;
	QString strcompanyid;
	////�ο͵�½
	if (m_stUserInfo.m_bLoginByTax == -8)
	{
	///	m_stUserInfo.m_strTaxNumber = strTaxno;

		QString strRet, strCompany, strServerUserid;
		bool bret;
		if (!strTaxno.isEmpty())
		{
			bret = ZcloudComFun::winHttpQueryCompanyInfoLocalTax(strTaxno, m_stUserInfo.m_strToken, bisjoin, strCompany, nroletype, strcompanyid);

			return strCompany;
		}
		else
		{
			strCompany = QString::fromLocal8Bit("��δ��ѯ��������ҵ");
			return strCompany;
		}

	}
	else
	{
		return "";
	}
}
void ZcloudDesk::createEnterCenterMgr()
{
	

	if (NULL == m_pEntCenter)
	{
		m_pEntCenter = ZcloudEntCenter::createNew();
		m_pEntCenter->setUserInfo(m_stUserInfo);
///		m_pEntCenter->InitCompanyInfo(m_stUserInfo);

	}
	
}

void ZcloudDesk::InitEntCenter()
{

	connect(m_pEntCenter, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));
	connect(m_pEntCenter, SIGNAL(bingdingPhoneSignal()), this, SLOT(bingdingPhoneSlot()));
	connect(m_pEntCenter, SIGNAL(sigSignBindingSucceeded(const QString&)), this, SLOT(slotChangeMobile(const QString&)));
	connect(m_pEntCenter, SIGNAL(openSignInWidget(QWidget*)), this, SLOT(openSignInWidegt(QWidget*)));
	connect(m_pEntCenter, &ZcloudEntCenter::sendVipListSignals, this, &ZcloudDesk::buyMembershipSlot);
	connect(m_pEntCenter, &ZcloudEntCenter::trueNameJobChange, [this](QString trueName, QString strJob)
	{
		m_stUserInfo.m_strTruename = trueName;
		m_stUserInfo.m_strJob = strJob;

	});
}

