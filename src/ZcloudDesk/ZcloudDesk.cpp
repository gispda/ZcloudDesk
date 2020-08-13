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
	, m_strSwitchTax(loadJsbTax())//防止插入金税宝 登录   拔出时 税号为空 
{

	QIcon icon(":/ZcloudDesk/image/ycs_logo.png");
	system_tray = new QSystemTrayIcon(this);
	system_tray->setIcon(icon);
	system_tray->setToolTip(QString::fromLocal8Bit("云财税"));

	connect(system_tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));
	//显示托盘
	system_tray->show();




	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowSystemMenuHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowTitle(g_strAppName);
	setStyleSheet("outline: none");

	ZcloudComFun::writeRegReboot(ZcloudComFun::EN_REBOOT_PARAMS);

	resizeAllWidget();
	connect(QApplication::desktop(), SIGNAL(workAreaResized(int)), this, SLOT(resizeAllWidget()));
	
	//!大数据采集线程
	m_pBigDataInterface = ZcloudBigDataInterface::GetInstance();

	//!消息
	m_pMsgCenter = ZcloudMsgCenter::createNew();
	connect(m_pMsgCenter, SIGNAL(changeUnreadMsgNum(int, bool)), this, SLOT(onChangeUnreadMsgNum(int, bool)));
	connect(m_pMsgCenter, SIGNAL(checkTokenFailed(int)), this, SLOT(onCheckTokenFailed(int)));
	connect(m_pMsgCenter, SIGNAL(sigReduceUnreadNum(int)), this, SLOT(onReduceUnreadNum(int)));
	connect(m_pMsgCenter, SIGNAL(sigSendMessageRespone(QString)), this, SLOT(onReciveMsgPopUp(QString)));
	
	//!检测是否更新
	QString strDownloadUrl, strMd5;
	CheckUpdater obj;
	if (obj.checkUpdater(m_stUserInfo.m_strUserId,m_stUserInfo.m_strToken))
	{
		obj.startUpdaterProcess(true);
	}
	
	//!监控服务线程
	m_pCheckServiceThread = new CheckServiceThread(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, m_stUserInfo.m_strHzsId, this);
	connect(m_pCheckServiceThread, &QThread::finished, m_pCheckServiceThread, &QObject::deleteLater);
	m_pCheckServiceThread->start();

	//!管道通信线程
	m_pPipeServerThread = new PipeServerThread(this);
	connect(m_pPipeServerThread, SIGNAL(sigReciveMsgPopUp(QString)), this, SLOT(onReciveMsgPopUp(QString)));
	connect(m_pPipeServerThread, &QThread::finished, m_pPipeServerThread, &QObject::deleteLater);
	m_pPipeServerThread->start();

	//!点击响应
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
		//双击托盘图标
		//双击后显示主程序窗口
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
	//!关闭顶栏窗口
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

		//!解析json
		analysisTopTool(strRet, topToolInfos);

		//!清除内存 !插入数据库
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

	//!从数据库查询出跟本地匹配后的数据
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


		//删除  多余的顶栏应用
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
					//删除顶栏应用
					Database::GetInstance()->removeTopToolInfo(m_stUserInfo.m_strUserId, pInfo->m_strAppId);
				}

			}
		}
		//!清除内存
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
		if (QString::fromLocal8Bit("会员中心") == pInfo->m_strAppName)
		{
			button = new QPushButton(ui.ZcloudTopWidget);
			button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
			
			button->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/ZcloudDesk/image/vip.png);"
				"color:rgb(255,255,255);font: 12px \"微软雅黑\";padding-left:5px;padding-right:5px;}"
			"QPushButton:hover{border-image:url(:/ZcloudDesk/image/vip_hover.png);color:rgb(255,255,255);font:12px \"微软雅黑\"}"
			"QPushButton:pressed{border-image:url(:/ZcloudDesk/image/vip_hover.png);color:rgb(255,255,255);font:12px \"微软雅黑\"};"));
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

	if (strToolName == QString::fromLocal8Bit("财税计算器"))
	{
		openTaxCalculatorWidget(pInfo->m_strAppDownloadUrl);
	}
	else if (strToolName == QString::fromLocal8Bit("财税日历"))
	{
		openFiscalCalendarWidget(pInfo->m_strAppDownloadUrl);
	}
	else if (strToolName == QString::fromLocal8Bit("壁纸"))
	{
		openWallpaperWidget(pInfo->m_strAppDownloadUrl);
	}
	else if (strToolName == QString::fromLocal8Bit("活动"))
	{
		openActivityCenterWidget(pInfo->m_strAppDownloadUrl);
	}

	
	else if (strToolName == QString::fromLocal8Bit("锁屏"))
	{
		//ui.billListButton
		/////借用下来测试添加创建企业   测试ok
		/*if (m_pEntCenter == NULL)
			createEnterCenterMgr();
		m_pEntCenter->createEntCenter(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken);*/


		//////二维码客户经理邀请加入 测试ok
		
		///CustomerManagerinvite();

		////上传 图片   测试ok
		
		//QString strRet;
		//ZcloudClient::winHttpUploadImage("", m_stUserInfo.m_strToken, strRet);

		/////更新企业开户行信息   测试成功

		//CompanyBankInfo  bankinfo;
		//bankinfo.m_strTaxno = "210624197305200017";
		//bankinfo.m_strBankname = QString::fromLocal8Bit("中国银行成都市双林南支路支行");
		//bankinfo.m_strBankaccount = "609358084893";
		//bankinfo.m_strAddress = QString::fromLocal8Bit("成都市成华区双林南支路28号");
		//bankinfo.m_strTelno = "028 82909982";
		//QString strRet;
		//ZcloudClient::winHttpUpdatebankInfo(bankinfo, m_stUserInfo.m_strToken, strRet);

		//lockScreen();
	}
	else if (strToolName == QString::fromLocal8Bit("搜索"))
	{
		openSearch();
	}
	else if (strToolName == QString::fromLocal8Bit("截图"))
	{
		openScreenShot();
	}
	else if (strToolName == QString::fromLocal8Bit("签到"))
	{
		openSignInWidegt(this);
	}
	else if (strToolName == QString::fromLocal8Bit("会员中心"))
	{
		openVipCenterWidget();
	}
	else 
	{
		//！别的应用分类
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
					////设置用户名称
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
		m_pActionCustomerManager->setText(QString::fromLocal8Bit("由客户经理邀请加入"));
		m_pActionEnterpriseManager->setText(QString::fromLocal8Bit("由企业管理员邀请加入"));
		m_pActionCreateEntCompany->setText(QString::fromLocal8Bit("创建新企业"));

		m_pMenu->addAction(m_pActionCustomerManager);
		m_pMenu->addAction(m_pActionEnterpriseManager);
		m_pMenu->addAction(m_pActionCreateEntCompany);

		ui.twobarcodebtn->setMenu(m_pMenu);
		

		connect(m_pActionCustomerManager, &QAction::triggered, this, &ZcloudDesk::CustomerManagerinvite);
		connect(m_pActionEnterpriseManager, &QAction::triggered, this, &ZcloudDesk::EnterpriseManagerinvite);

		connect(m_pActionCreateEntCompany, &QAction::triggered, this, &ZcloudDesk::openCreateEntDlg);


		m_pMenu->setAttribute(Qt::WA_TranslucentBackground);
		m_pMenu->setStyleSheet(QString::fromLocal8Bit(
			"QMenu{background-color:rgba(255, 255, 255, 1);"//整个背景
			"border:1px solid rgba(222, 222, 222,1);"//整个菜单边缘
			"font-size:12px 'Microsoft Yahei';"
			"text-align:center;"
			"color:rgb(51, 51, 51);}"
			"QMenu::item{"//字体颜色
			"height:30px;"
			"background-color:rgb(255, 255, 255);"
			"margin:0px 0px;"//设置菜单项的外边距
			"padding:1px 20px;}"//设置菜单项文字上下和左右的内边距，效果就是菜单中的条目左右上下有了间隔
			"QMenu::item:pressed{"
			"background-color:rgb(242,242,242);"//选中的样式
			"font-size: 12px 'Microsoft Yahei';color:rgb(51,51,51);}"//字体颜色
			"QMenu::item:selected{"//菜单项按下效果
			"font-size: 12px 'Microsoft Yahei';color:rgb(51,51,51);"//字体颜色
			"background-color:rgb(242, 242, 242);}"));

		

		//m_pEntCenter->createEntCenter();

		//	return;
	}


	m_pEntCenter->openEntCenter(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, m_stUserInfo.m_strTruename, m_stUserInfo.m_strJob, m_stUserInfo.m_bLoginByTax, m_stUserInfo.m_strMobile, m_stUserInfo.m_strCompanyId, m_stUserInfo.m_strUsername);
	m_pBigDataInterface->produceData("M01", "OP001", "TTA013");
}
//!客户经理邀请
void ZcloudDesk::CustomerManagerinvite(){
	TwobarCodeWidget* ptwobarCodeWidget = new TwobarCodeWidget(m_stUserInfo.m_strCompanyId,m_stUserInfo.m_strToken,QString::fromLocal8Bit("由客户经理邀请加入"),NULL);
	ptwobarCodeWidget->show();
};
//!企业管理员邀请
void ZcloudDesk::EnterpriseManagerinvite(){
	TwobarCodeWidget* ptwobarCodeWidget = new TwobarCodeWidget("", m_stUserInfo.m_strToken, QString::fromLocal8Bit("由企业管理员邀请加入"), NULL);
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
	//vipTimeList 会员到期时间
	m_stUserInfo.m_strListAppVipNameList = vipNameList;
	m_stUserInfo.m_strListAppVipList = vipIdList;
	m_stUserInfo.m_vipDateTimeList = vipTimeList;
	//修改数据库
	Database::GetInstance()->setUserData(m_stUserInfo);
	//设置应用中心
	if (m_zhicloudApp)
	{
		m_zhicloudApp->setVipList(vipNameList, vipIdList, vipTimeList);
	}
	//修改顶栏的vip
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
			if (QString::fromLocal8Bit("财税计算器") == pWidget->windowTitle())
			{
				return;
			}
		}
		QString strTaxCalculatorUrl = ZcloudComFun::getTopToolUrl(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, strUrl);
		CalculatorWidget* pCalculatorWidget = new CalculatorWidget(QString::fromLocal8Bit("财税计算器"), strTaxCalculatorUrl, this);
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

	//注册插拔事件
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
		//发现金税宝  隐藏 开票软件 和重装开票
		m_stUserInfo.isHideNR = true;
		if (m_zhicloudApp) m_zhicloudApp->setIsHideNR(true);
		if (m_strSwitchTax != strTaxNo)
		{
			m_strSwitchTax = strTaxNo;
			if (strTaxNo != m_stUserInfo.m_strTaxNumber)
			{
				if (ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_BINDING, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("系统检测到新的移动开票设备\r\n已插入,是否立即切换税号？"),
					QString::fromLocal8Bit("立即切换"), QString::fromLocal8Bit("取消")) == QDialog::Accepted)
				{
					//切换新的税号  待处理
					onSwitchAcc(1, false, m_strSwitchTax,"");
				}
			}
		}
	}
	else if (!flag && !m_strSwitchTax.isEmpty())
	{
		//发现金税宝  隐藏 开票软件 和重装开票
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
				QString	strMsg = QString::fromLocal8Bit("%1(%2)").arg(QString::fromLocal8Bit("未读消息")).arg(m_nUnreadCount);
				ui.msgButton->setToolTip(strMsg);
			}
			else
			{
				ui.msgButton->setToolTip(QString::fromLocal8Bit("暂无未读消息"));
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
			//cs 应用查询版本
			if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("检测到有新的的版本，\r\n是否立即升级？")) == QDialog::Accepted)
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
						bool isNewVerson = false;//是否是 最新版本
						//如果是首次安装则不匹配 版本 
						bool isInstallFlag = m_zhicloudApp->getVer(pData, isNewVerson);
						if (isInstallFlag)//判断 已经安装了的  且是最新版本(如果是第一次安装 就不会判定版本)
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
		// m_isBindingPhone == 0时才判定试用到期时间
		if (!pData.m_isBindingPhone  &&  !pData.m_experienceTime.isEmpty() && pData.m_experienceTime != "0")
		{
			if (pData.m_enExperienceTime.isEmpty() || pData.m_enExperienceTime == "0")
			{
				//提醒登录或者试用
				//if (ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_BINDING, QString::fromLocal8Bit("试用应用"), QString::fromLocal8Bit("绑定手机号后,您将享受%1更多功能").arg(g_strAppName),
				//	QString::fromLocal8Bit("登录绑定"), QString::fromLocal8Bit("开始试用")) == QDialog::Accepted)
				//{
				//	bingdingPhoneSlot();
				//	return;
				//}
				//else
				//{
					//开始试用  修改试用到期时间
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
				//判断是否到期
				if (pData.m_enExperienceTime.toInt() < QDateTime::currentDateTime().toTime_t())
				{
					//if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"),
					//	QString::fromLocal8Bit("绑定手机号后,您将享受%1更多功能").arg(g_strAppName))
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
			//cs应用打开失败，需要安装  走开票软件的安装流程
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

				//测试 切换税号时指针释放，是否释放 pData 的内存
				if (ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("该应用未安装，\r\n是否立即安装此应用服务？")) == QDialog::Accepted)
				{
					if (ZhicloudApp::openDownloadSoftware(3, pData.m_strAppDownloadUrl) == QDialog::Accepted)
					{
						bool isNewVerson = false;//是否是 最新版本
						//查询注册表下载完成
						//防止切换税号时 正在下载应用，顶栏应用已经 清空
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
							//如果是首次安装则不匹配 版本 
							bool isInstallFlag = m_zhicloudApp->getVer(*pInfo, isNewVerson);
							if (isInstallFlag)//判断 已经安装了的  且是最新版本(如果是第一次安装 就不会判定版本)
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
	
	////游客登陆
	if (m_stUserInfo.m_bLoginByTax==-8){
		ui.labelCompName->setMinimumWidth(0);


		strText = queryTaxInfo();
		ui.labelCompName->setText(strText);
		//设置图标
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
			strText = QString::fromLocal8Bit("暂未查询到您的企业");
		}
		else
		{
			QString strCompanyName = m_stUserInfo.m_strCompanyName;
			//if (strCompanyName.isEmpty() || strCompanyName.contains("wechat_") || strCompanyName.contains("nick_") || strCompanyName.contains("user_"))
			if (strCompanyName.isEmpty() )

			{
				strText = QString::fromLocal8Bit("加入企业");
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
			int fontSize = fontMetrics.width(strText);//获取之前设置的字符串的像素大小

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
		//打开登录界面
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
	//{"status":30070, "message" : "token已失效"}
		//30001 账号或者密码错误
		//10002 token格式不正确
		showDlgWait(false);
		QString tipStr = QString::fromLocal8Bit("切换账号失败，请稍后重试!错误码：%1").arg(loginFlag);
		if (30070 == loginFlag || 10002 == loginFlag)
		{
			tipStr = QString::fromLocal8Bit("切换账号失败，该账号已过期，\r\n请选择其他账号重新登录!");
		}
		else if (loginFlag == -1)
		{
			tipStr = QString::fromLocal8Bit("切换账号失败，\r\n请选择其他账号!");
		}
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), tipStr, this);
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
			switchAccDlgWait = new DlgWait(QString::fromLocal8Bit("绑定手机，请稍后..."), this);
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
			switchAccDlgWait = new DlgWait(QString::fromLocal8Bit("切换中，请稍后..."), this);
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
	//!应用中心关闭
	m_zhicloudApp->exitAppCenterThread();
	m_pMsgCenter->stopMsgThread();
	emit startInitSignal(flag);
}
void ZcloudDesk::onlyExitThread(UserInfoStruct& userInfo,QString strOldUserId, QString strNewUserId, QString strNewToken)
{
	if (!strOldUserId.isEmpty() && !strNewUserId.isEmpty())
	{
		//更新数据库 所有含有 userId 的数据
		//更改登录选项
		//更改顶栏应用
		Database::GetInstance()->changeSetUsrId(strOldUserId, strNewUserId,m_stUserInfo.m_strCompanyId);
		//更改服务程序
		ServerDatabase::GetInstance()->changeServerUsrId(strOldUserId, strNewUserId);
		//更改企业中心
		Database::GetInstance()->changeEndUsrId(strOldUserId, strNewUserId);
		//更改消息中心
		Database::GetInstance()->changeMsgUsrId(strOldUserId, strNewUserId);
		//更改应用中心
		if (m_zhicloudApp)
		{
			m_zhicloudApp->changeAppUserId(strOldUserId, strNewUserId);
			//由于应用中心应用加密 删除该用户所有应用 重新拉取重新加密
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
		//ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("发生了错误，请重新登录！"));
		return;
	}
}

void ZcloudDesk::closeAllWindows(int flag)
{
	if (0 == flag)
	{
		//!企业中心关闭
		if (m_pEntCenter != NULL)
		{
			m_pEntCenter->closeAllEntWidget();
			m_pEntCenter = NULL;
		}
	}
	


	//!消息中心关闭
	if (m_pMsgCenter!=NULL)
	m_pMsgCenter->closeAllMsgWidget();
	//!应用中心关闭
	if (m_zhicloudApp!=NULL)
	m_zhicloudApp->closeAppCenter();

	//!关闭顶栏窗口
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
	//!初始化顶栏工具
	getTopTool();


	////将企业中心的创建函数提到这里，方便从注册表读取的税号到后台匹配。


	///createEnterCenterMgr();


	//!设置公司名字、头像
	showCompInfo();

	//!使用新的用户 大数据上报
	m_pBigDataInterface->initData(m_stUserInfo.m_strUserId, m_stUserInfo.m_strCompanyId, m_stUserInfo.m_strHzsId, m_stUserInfo.m_strProvinceId, m_stUserInfo.m_strCityId, m_stUserInfo.m_strAreaId);

	//!设置顶栏、右侧显示
	bool bShowTop = true, bShowRight = true;
	Database::GetInstance()->queryUserConfig(m_stUserInfo.m_strUserId, bShowTop, bShowRight);
	onTopCheckChanged(bShowTop);
	onRightCheckChanged(bShowRight);

	//!消息中心
	m_pMsgCenter->startMsgThread(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, m_stUserInfo.m_strCompanyId);
	m_pMsgCenter->setUserData(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, m_stUserInfo.m_strCompanyId);
	
	//设置用户数据 初始化用测应用
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
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("系统退出"), QString::fromLocal8Bit("服务器异常"));
	}
	if (!parse_doucment.isObject())
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("系统退出"), QString::fromLocal8Bit("服务器异常"));
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("code").toInt();

	bool jmsg;
	if (0 == status)
	{
		jmsg = obj.take("data").toBool();	
		if (jmsg)
		{
			//ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("系统退出"), QString::fromLocal8Bit("正常退出"));
		}
		else
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("系统退出"), QString::fromLocal8Bit("退出失败"));
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
	//绑定手机号
	//打开登录界面
	//if (m_stUserInfo.m_strTaxNumber.isEmpty())
	//{
	//	//只是账号登录
	//	ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("非常抱歉，您是账号登录！\r\n不能绑定！"));
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
				//绑定成功，但手机号为空
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("手机号为空，绑定失败！"));
			}
		}
	}
	else
	{
		//主窗口 未设置 手机号
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("该账号已绑定手机，请不要重新绑定！"));
	}
}

void ZcloudDesk::slotBindingSucceeded(UserInfoStruct& userInfo,const QString &strUserId, const QString &strMobile, const QString &strToken)
{
	if (strUserId.isEmpty() || strMobile.isEmpty() || strToken.isEmpty())
	{
		return;
	}
	//修改数据库该账号的手机号
	Database::GetInstance()->addPhoneNumber(strMobile, m_stUserInfo.m_strUserId);

	LoginSetingStruct loginSetingStruct;
	Database::GetInstance()->findLoginSet(loginSetingStruct);

	if (loginSetingStruct.loginByTax	==	0)
	{
		//只是账号登录 下次登录方式走手机号+token
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
		//更改消息中心的 token 待处理
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
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("您的登录已过期，请重新登录！"));
	}
	else if (-2 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("您的账号已在其他地方登录，若不是您本人操\r\n作，请注意账号安全！"));
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
			if (QString::fromLocal8Bit("办税日历") == pWidget->windowTitle())
			{
				return;
			}
		}
		QString strFiscalCalendarUrl = ZcloudComFun::getTopToolUrl(m_stUserInfo.m_strUserId, m_stUserInfo.m_strToken, strUrl);
		CalculatorWidget* pCalculatorWidget = new CalculatorWidget(QString::fromLocal8Bit("办税日历"), strFiscalCalendarUrl, this);
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
	
	if (1 == nResType)	//！按钮点击
	{
		if (1 == nBtnType)	//!打开链接
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
		else if (0 == nBtnType)	//!居中默认关闭
		{
			m_pBigDataInterface->produceData("M00", "OP001", "TMP005", strMsgId);
		}
		else if (3 == nBtnType)	//!表单按钮
		{
			QString strOperandId = bFromPopUp ? "TMP007" : "TMD004";
			m_pBigDataInterface->produceData("M00", "OP001", strOperandId, strMsgId);
		}
		else if (4 == nBtnType)	//!右下角弹窗关闭
		{
			m_pBigDataInterface->produceData("M00", "OP001", "TMP002", strMsgId);
		}
		else if (5 == nBtnType)	//!查看更多
		{
			m_pBigDataInterface->produceData("M00", "OP001", "TMP001", strMsgId);
			m_pMsgCenter->openAssignMsgCenter(m_nUnreadCount, strMsgId);
		}
		else if (6 == nBtnType)	//!立即续费
		{
			QString strOperandId = bFromPopUp ? "TMP015" : "TMD002";
			m_pBigDataInterface->produceData("M00", "OP001", strOperandId, strMsgId);

			QString strUrl = QString("%1?user_id=%2&token=%3").arg(strTarget).arg(strUid).arg(strToken);
			openServiceFee(strUrl);
		}
		ServerDatabase::GetInstance()->insertMsgOper(strUid, strToken, strCompId, m_stUserInfo.m_strHzsId, strMsgId, 2, strBtnId);
	}
	else if (2 == nResType)		//!表单关闭按钮
	{
		QString strOperandId = bFromPopUp ? "TMP014" : "TMD011";
		m_pBigDataInterface->produceData("M00", "OP001", strOperandId, strMsgId);
	}
	else if (3 == nResType)	//!图片点击
	{
		if (1 == nBtnType)	//!打开链接
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
	else if (4 == nResType)	//!活动点击
	{
		m_pBigDataInterface->produceData("M00", "OP001", "TMP018", strMsgId);
		std::map<QPushButton*, AppDataInfo*>::iterator itr = m_mpTopToolBtnInfos.begin();
		for (; itr != m_mpTopToolBtnInfos.end();	++itr)
		{
			AppDataInfo*	pInfo = itr->second;
			if (pInfo->m_strAppAlias	==	QString::fromLocal8Bit("活动"))
			{
				QPushButton*	pBtn = itr->first;
				if (NULL	!=	pBtn)
				{
					emit pBtn->clicked();
				}
			}
		}
	}
	else if (5 == nResType)	//!图片消息窗口启动
	{
		m_pBigDataInterface->produceData("M00", "OP000", "TMP021", strMsgId);
	}
	else if (6 == nResType)	//!右下角消息窗口启动
	{
		m_pBigDataInterface->produceData("M00", "OP000", "TMP019", strMsgId);
	}
	else if (7 == nResType)	//!居中消息窗口启动
	{
		m_pBigDataInterface->produceData("M00", "OP000", "TMP020", strMsgId);
	}
	else if (8 == nResType)	//!服务费到期窗口启动
	{
		m_pBigDataInterface->produceData("M00", "OP000", "TMP022", strMsgId);
	}
	else if (9 == nResType)	//!消息详情滚动条下拉
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
	int fontSize = fontMetrics.width(strText);//获取之前设置的字符串的像素大小
	QString strElideText;
	if (fontSize > pLabel->width())
	{
		strElideText = fontMetrics.elidedText(strText, Qt::ElideRight, pLabel->width());//返回一个带有省略号的字符串
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
	////游客登陆
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
			strCompany = QString::fromLocal8Bit("暂未查询到您的企业");
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

