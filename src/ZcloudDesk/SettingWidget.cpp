#include "SettingWidget.h"
#include "HttpInterface.h"
#include "Database.h"
#include "ZcloudCommon.h"
#include <QDesktopServices>
#include <QDialog>
#include "CheckUpdater.h"
#include "ZcloudBigData.h"
#include "VerDesWidget.h"
extern QString g_strAppName;
const QString strStyle1 = QString::fromLocal8Bit(
	"QPushButton{background-color: #FFFFFF;border-radius:4px;font:14px \"微软雅黑\";color:#666666;border:1px solid #DEDEDE;"
	"border-top-right-radius:0px;border-bottom-right-radius:0px;}"
	"QPushButton:hover,pressed{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1),"
	"stop:1 rgba(64, 156, 240, 1));border-radius:4px;font:14px \"微软雅黑\";color:rgba(255, 255, 255, 1);"
	"border-top-right-radius:0px;border-bottom-right-radius:0px;}");

const QString strStyle2 = QString::fromLocal8Bit(
	"QPushButton{background-color: #FFFFFF;border-radius:4px;font:14px \"微软雅黑\";color:#666666;border:1px solid #DEDEDE;"
	"border-radius:0px;}"
	"QPushButton:hover,pressed{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1),"
	"stop:1 rgba(64, 156, 240, 1));border-radius:4px;font:14px \"微软雅黑\";color:rgba(255, 255, 255, 1);"
	"border-radius:0px;}");

const QString strStyle3 = QString::fromLocal8Bit(
	"QPushButton{background-color: #FFFFFF;border-radius:4px;font:14px \"微软雅黑\";color:#666666;border:1px solid #DEDEDE;"
	"border-top-left-radius:0px;border-bottom-left-radius:0px;}"
	"QPushButton:hover,pressed{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1),"
	"stop:1 rgba(64, 156, 240, 1));border-radius:4px;font:14px \"微软雅黑\";color:rgba(255, 255, 255, 1);"
	"border-top-left-radius:0px;border-bottom-left-radius:0px;}");

const QString strSelectStyle1 = QString::fromLocal8Bit(
	"QPushButton{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1),"
	"stop:1 rgba(64, 156, 240, 1));border-radius:4px;font:14px \"微软雅黑\";color:rgba(255, 255, 255, 1);"
	"border-top-right-radius:0px;border-bottom-right-radius:0px;}");

const QString strSelectStyle2 = QString::fromLocal8Bit(
	"QPushButton{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1),"
	"stop:1 rgba(64, 156, 240, 1));border-radius:4px;font:14px \"微软雅黑\";color:rgba(255, 255, 255, 1);"
	"border-radius:0px;}");

const QString strSelectStyle3 = QString::fromLocal8Bit(
	"QPushButton{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1),"
	"stop:1 rgba(64, 156, 240, 1));border-radius:4px;font:14px \"微软雅黑\";color:rgba(255, 255, 255, 1);"
	"border-top-left-radius:0px;border-bottom-left-radius:0px;}");

#ifdef VERSION_FOR_GZ
const QString strBannerOn = "QWidget#bannerWidget{background-image:url(:/ZcloudDesk/image/afw_banner2_on.png);border-radius:0px};";
const QString strBannerOff = "QWidget#bannerWidget{background-image:url(:/ZcloudDesk/image/afw_banner2_off.png);border-radius:0px};";
#else
const QString strBannerOn = "QWidget#bannerWidget{background-image:url(:/ZcloudDesk/image/banner2_on.png);border-radius:0px};";
const QString strBannerOff = "QWidget#bannerWidget{background-image:url(:/ZcloudDesk/image/banner2_off.png);border-radius:0px};";
#endif


SettingWidget::SettingWidget(QString strUid, QString strToken, QString strProvinceId,QWidget *parent)
	:AppCommWidget("", true, parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
	, m_strProvinceId(strProvinceId)
{
	ui.setupUi(m_widget);
	resize(816, 616);
	setObjectName("SettingWidget");
	setWindowTitle(QString::fromLocal8Bit("设置"));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setAttribute(Qt::WA_DeleteOnClose);
	setStyleSheet("outline: none");

	connect(ui.deskSettingButton, SIGNAL(clicked()), this, SLOT(onDeskSettingBtnClick()));
	connect(ui.feedBackButton, SIGNAL(clicked()), this, SLOT(onFeedBackBtnClick()));
	connect(ui.helperButton, SIGNAL(clicked()), this, SLOT(onHelperBtnClick()));
	connect(ui.aboutUsButton, SIGNAL(clicked()), this, SLOT(onAboutUsBtnClick()));

	connect(ui.closeButton, &QPushButton::clicked, [this]()
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSI006");
		close();
	});

	ui.RightTopWidget->hide();
	ui.DeskWidget->hide();
	ui.FeedBackWidget->hide();
	ui.HelperWidget->hide();
	ui.AboutUsWidget->hide();	

	emit ui.deskSettingButton->click();
}

SettingWidget::~SettingWidget()
{
	clearListWidget();
}

void SettingWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		dPos = event->globalPos() - pos();
		event->accept();
	}
}

void SettingWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - dPos);
		event->accept();
	}
}

void SettingWidget::onDeskSettingBtnClick()
{
	QMutexLocker mutexLocker(&m_setMutex);
	ui.RightTopWidget->setStyleSheet("QWidget#RightTopWidget{background-image:url(:/ZcloudDesk/image/banner1_on.png);border-top-left-radius:0px;"
		"border-bottom-left-radius:0px;border-bottom-right-radius:0px;};");
	ui.RightTopWidget->show();
	ui.DeskWidget->show();
	ui.FeedBackWidget->hide();
	ui.HelperWidget->hide();
	ui.AboutUsWidget->hide();

	deskSettingConnect();

	clearListWidget();

	init();

	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSI001");
}

void SettingWidget::onFeedBackBtnClick()
{
	QMutexLocker mutexLocker(&m_setMutex);
	ui.RightTopWidget->setStyleSheet("QWidget#RightTopWidget{background-color:#FFFFFF;border-top-left-radius:0px;"
		"border-bottom-left-radius:0px;border-bottom-right-radius:0px;};");
	ui.RightTopWidget->show();
	QRect rect = ui.DeskWidget->geometry(); 
	ui.DeskWidget->hide();
	ui.FeedBackWidget->setGeometry(rect);
	ui.FeedBackWidget->show();
	ui.HelperWidget->hide();
	ui.AboutUsWidget->hide();

	feedBackConnect();

	emit ui.designButton->click();

	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSI002");
}

void SettingWidget::onHelperBtnClick()
{
	QMutexLocker mutexLocker(&m_setMutex);
	ui.RightTopWidget->setStyleSheet("QWidget#RightTopWidget{background-color:#FFFFFF;border-top-left-radius:0px;"
		"border-bottom-left-radius:0px;border-bottom-right-radius:0px;};");
	ui.RightTopWidget->show();
	QRect rect = ui.DeskWidget->geometry();
	ui.DeskWidget->hide();
	ui.FeedBackWidget->hide();
	ui.HelperWidget->setGeometry(rect);
	ui.HelperWidget->show();
	ui.AboutUsWidget->hide();

	helpCenterConnect();

	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSI003");
}

void SettingWidget::onAboutUsBtnClick()
{
	QMutexLocker mutexLocker(&m_setMutex);
	ui.RightTopWidget->setStyleSheet("QWidget#RightTopWidget{background-color:#FFFFFF;border-top-left-radius:0px;"
		"border-bottom-left-radius:0px;border-bottom-right-radius:0px;};");
	ui.RightTopWidget->show();
	QRect rect = ui.DeskWidget->geometry();
	ui.DeskWidget->hide();
	ui.FeedBackWidget->hide();
	ui.HelperWidget->hide();
	ui.AboutUsWidget->setGeometry(rect);
	ui.AboutUsWidget->show();

	QString mainverResult = ZcloudComFun::getFileVertion(QApplication::applicationFilePath());
	ui.labelVersion->setText(mainverResult);

	QString strStyle;
#ifdef VERSION_FOR_GZ
	strStyle = "border-image:url(:/ZcloudDesk/image/afw_logo.png);";
#else
	strStyle = "border-image:url(:/ZcloudDesk/image/ycs_logo.png);";
#endif
	ui.labelName->setText(g_strAppName);
	ui.labelIcon->setStyleSheet(strStyle);

	aboutUsConnect();

	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSI004");
}

void SettingWidget::feedBackConnect()
{
	connect(ui.commitButton, SIGNAL(clicked()), this, SLOT(onCommitBtnClick()),Qt::UniqueConnection);
	connect(ui.deskAppButton, SIGNAL(clicked()), this, SLOT(onDeskAppBtnClick()), Qt::UniqueConnection);
	connect(ui.designButton, SIGNAL(clicked()), this, SLOT(onDesignBtnClick()), Qt::UniqueConnection);
	connect(ui.errorButton, SIGNAL(clicked()), this, SLOT(onErrorBtnClick()), Qt::UniqueConnection);
	connect(ui.majorButton, SIGNAL(clicked()), this, SLOT(onMajorBtnClick()), Qt::UniqueConnection);
	connect(ui.otherButton, SIGNAL(clicked()), this, SLOT(onOtherBtnClick()), Qt::UniqueConnection);
	connect(ui.textEdit, SIGNAL(textChanged()), this, SLOT(onTextChanged()),Qt::UniqueConnection);
}

void SettingWidget::onCommitBtnClick()
{
	HttpInterface	sInter;
	QString			strRet;
	QString strContent = ui.textEdit->toPlainText();
	QString strContactWay = ui.lineEdit->text();
	if (strContactWay.isEmpty())
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提交失败"), QString::fromLocal8Bit("请填写联系方式！"), this);
		return;
	}
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSB002");
	if (sInter.winHttpSendFeedback(m_strUid, m_strToken, m_strFeedBackType, strContent, strContactWay, strRet))
	{
		QString strFeedBackId;
		int nRet = anyliseJson(strRet, strFeedBackId);
		if (0 == nRet)
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSB003", strFeedBackId);
			ui.textEdit->clear();
			ui.lineEdit->clear();
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("提交成功"), QString::fromLocal8Bit("我们会尽快处理，非常感谢！"), this);
		}
		else
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSB004", QString("%1").arg(nRet));
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提交失败"), QString::fromLocal8Bit("请检查您的网络设置！"), this);
		}	
	}
	else
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSB004");
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("提交失败"), QString::fromLocal8Bit("请检查您的网络设置！"), this);
	}
}

void SettingWidget::onDeskAppBtnClick()
{
	//桌面应用
	ui.deskAppButton->setStyleSheet(strSelectStyle2);
	ui.errorButton->setStyleSheet(strStyle2);
	ui.designButton->setStyleSheet(strStyle1);
	ui.majorButton->setStyleSheet(strStyle2);
	ui.otherButton->setStyleSheet(strStyle3);
	m_strFeedBackType = "3";
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSB001", "3");
}

void SettingWidget::onDesignBtnClick()
{
	//界面设计
	ui.designButton->setStyleSheet(strSelectStyle1);
	ui.deskAppButton->setStyleSheet(strStyle2);
	ui.errorButton->setStyleSheet(strStyle2);
	ui.majorButton->setStyleSheet(strStyle2);
	ui.otherButton->setStyleSheet(strStyle3);
	m_strFeedBackType = "1";
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSB001","1");
}

void SettingWidget::onErrorBtnClick()
{
	//平台故障
	ui.errorButton->setStyleSheet(strSelectStyle2);
	ui.deskAppButton->setStyleSheet(strStyle2);
	ui.designButton->setStyleSheet(strStyle1);
	ui.majorButton->setStyleSheet(strStyle2);
	ui.otherButton->setStyleSheet(strStyle3);
	m_strFeedBackType = "4";
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSB001", "4");
}

void SettingWidget::onMajorBtnClick()
{
	//功能优化
	ui.majorButton->setStyleSheet(strSelectStyle2);
	ui.deskAppButton->setStyleSheet(strStyle2);
	ui.errorButton->setStyleSheet(strStyle2);
	ui.designButton->setStyleSheet(strStyle1);
	ui.otherButton->setStyleSheet(strStyle3);
	m_strFeedBackType = "2";
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSB001", "2");
}

void SettingWidget::onOtherBtnClick()
{
	//其它
	ui.otherButton->setStyleSheet(strSelectStyle3);
	ui.deskAppButton->setStyleSheet(strStyle2);
	ui.designButton->setStyleSheet(strStyle1);
	ui.majorButton->setStyleSheet(strStyle2);
	ui.errorButton->setStyleSheet(strStyle2);
	m_strFeedBackType = "5";
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TSB001", "5");
}

void SettingWidget::onTextChanged()
{
	QString textContent = ui.textEdit->toPlainText();
	int length = textContent.count();
	int maxLengch = 1000;
	if (length > maxLengch) {
		int position = ui.textEdit->textCursor().position();
		QTextCursor textCursor = ui.textEdit->textCursor();
		textContent.remove(position - (length - maxLengch), length - maxLengch);
		ui.textEdit->setText(textContent);
		textCursor.setPosition(position - (length - maxLengch));
		ui.textEdit->setTextCursor(textCursor);
	}
	ui.numberLabel->setText(QString("%1/1000").arg(ui.textEdit->textCursor().position()));
	if (0 < length)
	{
		ui.commitButton->setEnabled(true);
		
	}
	else
	{
		ui.commitButton->setEnabled(false);
	}	
}

void SettingWidget::helpCenterConnect()
{
	connect(ui.demoButton, SIGNAL(clicked()), this, SLOT(onDemoBtnClick()), Qt::UniqueConnection);
	connect(ui.guideButton, SIGNAL(clicked()), this, SLOT(onGuideBtnClick()), Qt::UniqueConnection);
	connect(ui.helpButton, SIGNAL(clicked()), this, SLOT(onHelpBtnClick()), Qt::UniqueConnection);
	connect(ui.questionButton, SIGNAL(clicked()), this, SLOT(onQuestionBtnClick()), Qt::UniqueConnection);
}

void SettingWidget::onDemoBtnClick()
{
	QDesktopServices::openUrl(QUrl::fromUserInput(QString("http://help.zhicloud.com/main.do-target=helpcenter.html?province=%1&help_type=vedio").arg(m_strProvinceId)));
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "THC002");
}

void SettingWidget::onGuideBtnClick()
{
	emit showNoviceDlgSignal(true);
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "THC004");
}

void SettingWidget::onHelpBtnClick()
{
	QDesktopServices::openUrl(QUrl::fromUserInput(QString("http://help.zhicloud.com/main.do-target=helpcenter.html?province=%1&help_type=manual").arg(m_strProvinceId)));
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "THC001");
}

void SettingWidget::onQuestionBtnClick()
{
	QDesktopServices::openUrl(QUrl::fromUserInput("https://www.wenjuan.in/s/E7F7Jbp"));
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "THC003");
}

void SettingWidget::aboutUsConnect()
{
	connect(ui.checkUpdateButton, SIGNAL(clicked()), this, SLOT(onCheckUpdateBtnClick()), Qt::UniqueConnection);
	ui.labelLogout->installEventFilter(this);
	ui.labelVerDes->installEventFilter(this);
}

void SettingWidget::onCheckUpdateBtnClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TAU001");
	QString strDownloadUrl, strMd5;
	CheckUpdater obj;
	if (obj.checkUpdater(m_strUid, m_strToken))
	{
		int nRet = ZcloudComFun::openMessageTipDlg(ZcloudComFun::ZEN_UPDATE, QString::fromLocal8Bit("检测到新版本"), QString::fromLocal8Bit("升级到最新版，享受更专业的财税办公服务"), this);
		if (nRet == QDialog::Accepted)
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TAU002");
			obj.startUpdaterProcess(false);
		}
		else
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TAU006");
		}
	}
	else
	{
		ui.checkUpdateButton->setText(QString::fromLocal8Bit("已是最新版本"));
		ui.checkUpdateButton->setEnabled(false);
	}
}

void SettingWidget::onLogoutClick()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TAU007");
	int nReturn	=	ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("您确定要退出%1吗？").arg(g_strAppName), QString::fromLocal8Bit("退出后，您将不能享受更多财税相关服务哦！"), this);
	if (nReturn == QDialog::Accepted)
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TAU008","",true);
		this->hide();
		emit sigLogout();
	}
	else
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TAU009");
	}
}

bool SettingWidget::eventFilter(QObject *target, QEvent *e)
{
	if (target == ui.labelLogout)
	{
		if (e->type() == QEvent::MouseButtonRelease)
		{
			onLogoutClick();
		}
	}
	else if (target ==  ui.labelVerDes)
	{
		if (e->type() == QEvent::MouseButtonRelease)
		{
			openVerDes();
		}
	}
	return QWidget::eventFilter(target, e);
}

void SettingWidget::init()
{
	bool bShowTop = true, bShowRight =true;
	Database::GetInstance()->queryUserConfig(m_strUid, bShowTop, bShowRight);
	ui.topCheckBox->setChecked(bShowTop);
	ui.rightCheckBox->setChecked(bShowRight);

	if (bShowTop	&&	bShowRight)
	{
		ui.RightTopWidget->setStyleSheet("QWidget#RightTopWidget{background-image:url(:/ZcloudDesk/image/banner1_on.png);"
			"border-top-left-radius:0px;border-bottom-left-radius:0px;border-bottom-right-radius:0px;};");

		ui.bannerWidget->setStyleSheet(strBannerOn);
	}
	else
	{
		ui.RightTopWidget->setStyleSheet("QWidget#RightTopWidget{background-image:url(:/ZcloudDesk/image/banner1_off.png);"
			"border-top-left-radius:0px;border-bottom-left-radius:0px;border-bottom-right-radius:0px;};");

		ui.bannerWidget->setStyleSheet(strBannerOff);
	}
	vtrAppDataInfos	toolInfos;
	Database::GetInstance()->queryTopToolInfo(m_strUid, toolInfos,true);

	vtrAppDataInfos::iterator itr = toolInfos.begin();
	for (int i = 0; itr != toolInfos.end(), i<toolInfos.size(); ++itr,i++)
	{
		QString strBkImage = QString("background-image: url(:/ZcloudDesk/image/setTool%1.png);").arg(i % 5 + 1);
		QListWidgetItem* pListWidgetItem = new QListWidgetItem;
		SettingItemWidget* pItem = new SettingItemWidget(strBkImage, (*itr), ui.listWidget);
		connect(pItem, SIGNAL(sigToolCheckChanged(QString, bool)), this, SIGNAL(sigToolCheckChanged(QString, bool)), Qt::UniqueConnection);
		QSize size = pItem->size();
		pListWidgetItem->setSizeHint(size);
		ui.listWidget->addItem(pListWidgetItem);
		ui.listWidget->setItemWidget(pListWidgetItem, pItem);
	}
}

void SettingWidget::deskSettingConnect()
{
	connect(ui.topCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onTopCheckChanged(int)), Qt::UniqueConnection);
	connect(ui.rightCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onRightCheckChanged(int)), Qt::UniqueConnection);
}

void SettingWidget::onTopCheckChanged(int state)
{
	bool bShow = true;
	if (Qt::Unchecked == state)
	{
		ui.RightTopWidget->setStyleSheet("QWidget#RightTopWidget{background-image:url(:/ZcloudDesk/image/banner1_off.png);"
			"border-top-left-radius:0px;border-bottom-left-radius:0px;border-bottom-right-radius:0px;};");

		ui.bannerWidget->setStyleSheet(strBannerOff);

		bShow = false;
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP005", "TBS001", "1");
	}
	else if (Qt::Checked == state)
	{
		if (Qt::Checked == ui.rightCheckBox->checkState())
		{
			ui.RightTopWidget->setStyleSheet("QWidget#RightTopWidget{background-image:url(:/ZcloudDesk/image/banner1_on.png);"
				"border-top-left-radius:0px;border-bottom-left-radius:0px;border-bottom-right-radius:0px;};");

			ui.bannerWidget->setStyleSheet(strBannerOn);
		}
		else
		{
			ui.RightTopWidget->setStyleSheet("QWidget#RightTopWidget{background-image:url(:/ZcloudDesk/image/banner1_off.png);"
				"border-top-left-radius:0px;border-bottom-left-radius:0px;border-bottom-right-radius:0px;};");

			ui.bannerWidget->setStyleSheet(strBannerOff);
		}
		bShow = true;
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP004", "TBS001","1");
	}
	emit sigTopCheckChanged(bShow);
}

void SettingWidget::onRightCheckChanged(int state)
{
	bool bShow = true;
	if (Qt::Unchecked == state)
	{
		ui.RightTopWidget->setStyleSheet("QWidget#RightTopWidget{background-image:url(:/ZcloudDesk/image/banner1_off.png);"
			"border-top-left-radius:0px;border-bottom-left-radius:0px;border-bottom-right-radius:0px;};");

		ui.bannerWidget->setStyleSheet(strBannerOff);

		bShow = false;
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP005", "TBS001", "2");
	}
	else if (Qt::Checked == state)
	{
		if (Qt::Checked == ui.topCheckBox->checkState())
		{
			ui.RightTopWidget->setStyleSheet("QWidget#RightTopWidget{background-image:url(:/ZcloudDesk/image/banner1_on.png);"
				"border-top-left-radius:0px;border-bottom-left-radius:0px;border-bottom-right-radius:0px;};");

			ui.bannerWidget->setStyleSheet(strBannerOn);
		}
		else
		{
			ui.RightTopWidget->setStyleSheet("QWidget#RightTopWidget{background-image:url(:/ZcloudDesk/image/banner1_off.png);"
				"border-top-left-radius:0px;border-bottom-left-radius:0px;border-bottom-right-radius:0px;};");

			ui.bannerWidget->setStyleSheet(strBannerOff);
		}
		bShow = true;
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP004", "TBS001", "2");
	}
	emit sigRightCheckChanged(bShow);
}

void SettingWidget::clearListWidget()
{
	int nCount = ui.listWidget->count();
	for (int i = nCount - 1; i >= 0; i--)
	{
		QListWidgetItem* pListItem = ui.listWidget->item(i);
		if (NULL != pListItem)
		{
			QWidget *pWidget = ui.listWidget->itemWidget(pListItem);
			if (NULL != pWidget)
			{
				delete pWidget;
				pWidget = NULL;
			}
			delete pListItem;
			pListItem = NULL;
		}
	}
}

#include <QJsonObject>
#include <QJsonParseError>
int SettingWidget::anyliseJson(const QString& strJson, QString& strFeedBackId)
{
	QByteArray byte_array = strJson.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return -1;
	}
	if (!parse_doucment.isObject())
	{
		return -1;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("status").toInt();

	if (status == 0)
	{
		QJsonObject data = obj.take("data").toObject();
		strFeedBackId = data.take("feedback_id").toString();
	}
	return status;
}

void SettingWidget::openVerDes()
{
	VerDesWidget*	pVerDesWidget = new VerDesWidget(ui.AboutUsWidget);
	pVerDesWidget->setAttribute(Qt::WA_DeleteOnClose);
	pVerDesWidget->exec();
}

SettingItemWidget::SettingItemWidget(QString strBkImage, AppDataInfo* pInfo, QWidget *parent /*= 0*/)
	: QWidget(parent)
	, m_pInfo(pInfo)
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::Widget);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");

	this->setFixedSize(485, 50);
	QLabel*	pLabelIcon = new QLabel(this);
	pLabelIcon->setGeometry(10, 9, 30, 30);
	QString strIconPath = pInfo->m_strAppIconPath;
	if (!QFile::exists(strIconPath))
	{
		strIconPath = ":/ZcloudDesk/image/default.png";
	}
	QString strstyle = QString("%1image: url(%2);").arg(strBkImage).arg(strIconPath);
	pLabelIcon->setStyleSheet(strstyle);
	pLabelIcon->show();

	QLabel*	pLabelName = new QLabel(this);
	pLabelName->move(50,15);
	pLabelName->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	pLabelName->setStyleSheet(QString::fromLocal8Bit("font: 14px \"微软雅黑\";color:#333333;"));
	pLabelName->setFixedHeight(15);
	pLabelName->setText(pInfo->m_strAppName);
	pLabelName->adjustSize();
	pLabelName->show();

	QCheckBox*	pCheckBox = new QCheckBox(this);
	pCheckBox->setStyleSheet("QCheckBox::indicator{width:58px;height:26px;}"
		"QCheckBox::indicator:unchecked{image:url(:/ZcloudDesk/image/switch_off.png);}"
		"QCheckBox::indicator:checked{image:url(:/ZcloudDesk/image/switch_on.png);}");
	pCheckBox->setChecked(pInfo->bState);
	connect(pCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onToolCheckChanged(int)), Qt::UniqueConnection);
	pCheckBox->setGeometry(423, 10, 58, 26);
	pCheckBox->show();
}

SettingItemWidget::~SettingItemWidget()
{
	if (NULL != m_pInfo)
	{
		delete m_pInfo;
		m_pInfo = NULL;
	}
}

void SettingItemWidget::onToolCheckChanged(int state)
{
	bool bShow = (state == 0 ? false:true);
	if (bShow)
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP004", "TBS002", m_pInfo->m_strAppId);
	}
	else
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP005", "TBS002", m_pInfo->m_strAppId);
	}
	emit sigToolCheckChanged(m_pInfo->m_strAppId, bShow);
}
