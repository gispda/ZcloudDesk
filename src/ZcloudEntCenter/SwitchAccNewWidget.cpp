#include "SwitchAccNewWidget.h"
#include <QGraphicsDropShadowEffect>
#include "AccItemWidget.h"
#include <QSettings>
#include "ZcloudBigData.h"
#include <QDebug>
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QMenu>
#include <TwobarCodeWidget.h>
#include <EntCenterNewWidget.h>
#include "CreateEntInfoWidget.h"



SwitchAccNewWidget::SwitchAccNewWidget(UserInfoStruct* userInfo, EntCenterInfo* EntInfo, QWidget *parent)
	: QWidget(parent)

	
{
	m_userInfo = userInfo;
	m_pEntInfo = EntInfo;
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("账号切换"));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setAttribute(Qt::WA_ShowModal, true);
	setStyleSheet("outline: none");
	
	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);			//阴影模糊度
	//设置阴影距离
	shadow->setOffset(0, 0);
	//设置阴影颜色
	shadow->setColor(QColor("#666666"));
	//设置阴影圆角
	shadow->setBlurRadius(8);
	//给嵌套QWidget设置阴影
	this->setGraphicsEffect(shadow);


	ui.label->hide();

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BCA003");
		close();
	});


	//"加入"按钮添加菜单
	QMenu* m_pMenu = new QMenu(ui.joinButton);
	QAction* m_pActionCustomerManager = new QAction(m_pMenu);
	QAction* m_pActionEnterpriseManager = new QAction(m_pMenu);
	m_pActionCustomerManager->setText(QString::fromLocal8Bit("由客户经理邀请加入"));
	m_pActionEnterpriseManager->setText(QString::fromLocal8Bit("由企业管理员邀请加入"));

	m_pMenu->addAction(m_pActionCustomerManager);
	m_pMenu->addAction(m_pActionEnterpriseManager);
	m_pMenu->setAttribute(Qt::WA_TranslucentBackground);

	ui.joinButton->setMenu(m_pMenu);


	connect(m_pActionCustomerManager, &QAction::triggered, this, &SwitchAccNewWidget::CustomerManagerinvite);
	connect(m_pActionEnterpriseManager, &QAction::triggered, this, &SwitchAccNewWidget::EnterpriseManagerinvite);


	connect(ui.createButton, &QPushButton::clicked, this, &SwitchAccNewWidget::openCreateEntDlg); 

	//m_pMenu->setStyleSheet(QString::fromLocal8Bit(
	//	"QMenu{background-color:rgba(255, 255, 255, 1);"//整个背景
	//	"border:1px solid rgba(222, 222, 222,1);"//整个菜单边缘
	//	"font-size:12px 'Microsoft Yahei';"
	//	"text-align:center;"
	//	"color:rgb(51, 51, 51);}"
	//	"QMenu::item{"//字体颜色
	//	"height:30px;"
	//	"background-color:rgb(255, 255, 255);"
	//	"margin:0px 0px;"//设置菜单项的外边距
	//	"padding:1px 20px;}"//设置菜单项文字上下和左右的内边距，效果就是菜单中的条目左右上下有了间隔
	//	"QMenu::item:pressed{"
	//	"background-color:rgb(242,242,242);"//选中的样式
	//	"font-size: 12px 'Microsoft Yahei';color:rgb(51,51,51);}"//字体颜色
	//	"QMenu::item:selected{"//菜单项按下效果
	//	"font-size: 12px 'Microsoft Yahei';color:rgb(51,51,51);"//字体颜色
	//	"background-color:rgb(242, 242, 242);}"));




	getSwitchInfo();

	showListWidget("");
}
//!客户经理邀请
void SwitchAccNewWidget::CustomerManagerinvite(){
	TwobarCodeWidget* ptwobarCodeWidget = new TwobarCodeWidget(m_pEntInfo->_strCompId, m_pEntInfo->_strToken, QString::fromLocal8Bit("由客户经理邀请加入"), NULL);
	ptwobarCodeWidget->show();
};
//!企业管理员邀请
void SwitchAccNewWidget::EnterpriseManagerinvite(){
	TwobarCodeWidget* ptwobarCodeWidget = new TwobarCodeWidget("", m_pEntInfo->_strToken, QString::fromLocal8Bit("由企业管理员邀请加入"), NULL);
	ptwobarCodeWidget->show();
};
SwitchAccNewWidget::~SwitchAccNewWidget()
{
	//!清空列表
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

	vtrSwitchAccInfos::iterator itr = m_vtrAccInfos.begin();
	for (; itr != m_vtrAccInfos.end();	++itr)
	{
		stSwitchAccInfo* pInfo = (*itr);
		if (NULL != pInfo)
		{
			delete pInfo;
			pInfo = NULL;
		}
	}
	m_vtrAccInfos.clear();
}

void SwitchAccNewWidget::mousePressEvent(QMouseEvent *event)
{
	if (!isMaximized())
	{
		if (event->button() == Qt::LeftButton)
		{
			dPos = event->globalPos() - pos();
			event->accept();
		}
	}
}

void SwitchAccNewWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (!isMaximized())
	{
		if (event->buttons()&Qt::LeftButton)
		{
			move(event->globalPos() - dPos);
			event->accept();
		}
	}
}

bool SwitchAccNewWidget::eventFilter(QObject *target, QEvent *e)
{
	
	return QWidget::eventFilter(target, e);
}

void SwitchAccNewWidget::onTextChanged(const QString& strText)
{
	showListWidget(strText);
}

void SwitchAccNewWidget::showListWidget(QString strText)
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
	ui.label->show();
	if (strText.isEmpty())
	{
		vtrSwitchAccInfos::iterator itr	=	 m_vtrAccInfos.begin();
		for (; itr != m_vtrAccInfos.end();	++itr)
		{
			ui.label->hide();
			stSwitchAccInfo* pInfo = (*itr);
			if (NULL == pInfo)
			{
				continue;
			}
			QListWidgetItem* pListWidgetItem = new QListWidgetItem;
			AccItemWidget* pItem = NULL;
		/*	if (pInfo->strCompName == QString::fromLocal8Bit("暂未查询到您的企业"))
				continue;*/
			if (pInfo->strUid == m_userInfo->m_strUserId	&& pInfo->strCompId == m_pEntInfo->_strCompId)
			{
				pItem = new AccItemWidget(true, pInfo, "", ui.listWidget);
				ui.listWidget->insertItem(0, pListWidgetItem);
			}
			else
			{
				pItem = new AccItemWidget(false, pInfo, "", ui.listWidget);
				ui.listWidget->addItem(pListWidgetItem);
			}
			connect(pItem, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));
			connect(pItem, SIGNAL(sigJoinEnt(QString)), this, SLOT(onJoinEnt( QString)));
			QSize size = pItem->size();
			pListWidgetItem->setSizeHint(size);
			ui.listWidget->setItemWidget(pListWidgetItem, pItem);	
		}
	}
	else
	{
		vtrSwitchAccInfos::iterator itr = m_vtrAccInfos.begin();
		for (; itr != m_vtrAccInfos.end(); ++itr)
		{
			ui.label->hide();
			stSwitchAccInfo* pInfo = (*itr);
			if (NULL == pInfo)
			{
				continue;
			}
			if (pInfo->strTaxNo.contains(strText))
			{
				QListWidgetItem* pListWidgetItem = new QListWidgetItem;
				AccItemWidget* pItem = NULL;
				if (pInfo->strUid == m_pEntInfo ->_strUid && pInfo->strCompId == m_pEntInfo->_strCompId)
				{
					pItem = new AccItemWidget(true, pInfo, strText, ui.listWidget);
				}
				else
				{
					pItem = new AccItemWidget(false, pInfo, strText, ui.listWidget);
				}
				connect(pItem, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SIGNAL(sigSwitchAcc(int, bool, QString, QString)));
				QSize size = pItem->size();
				pListWidgetItem->setSizeHint(size);
				ui.listWidget->addItem(pListWidgetItem);
				ui.listWidget->setItemWidget(pListWidgetItem, pItem);
			}		
		}
	}
}
void SwitchAccNewWidget::onJoinEnt(QString companyid){
	int stcode = -1;
	emit sigJoinEnt(companyid);
}
void SwitchAccNewWidget::getSwitchInfo()
{
	//!查询数据已有账号
	Database::GetInstance()->querySwitchInfo(m_vtrAccInfos);

	//!查询用户所属所有企业
	getCompanyList();

	//!查询注册表获取税号信息
	QSettings *settings = new QSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\fwkp.exe", QSettings::NativeFormat);
	QStringList groupsList = settings->childGroups();
	foreach(QString group, groupsList)
	{
		settings->beginGroup(group);
		QString strCode = settings->value("code", QVariant()).toString();			//！企业税号
		strCode = strCode.replace(" ", "");
		settings->endGroup();
		if (!strCode.isEmpty())
		{
			if (!isTaxExistRegedit(strCode))
			{
				stSwitchAccInfo*	pSwitchInfo = new stSwitchAccInfo;
				pSwitchInfo->strTaxNo = strCode;
				pSwitchInfo->bLoginByTax = 1;
				m_vtrAccInfos.push_back(pSwitchInfo);
			}	
		}
	}
	delete settings;
}

bool SwitchAccNewWidget::isTaxExistRegedit(QString strTaxNo)
{
	vtrSwitchAccInfos::iterator itr = m_vtrAccInfos.begin();
	for (; itr != m_vtrAccInfos.end();	++itr)
	{
		stSwitchAccInfo* pInfo = (*itr);
		if (NULL != pInfo)
		{
			if (pInfo->strTaxNo == strTaxNo)
			{
				return true;
			}
		}
	}
	return false;
}

void SwitchAccNewWidget::onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd)
{
	if (bOther)
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BCA004");
	}
	else
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BCA001", strTaxNo_userName);
	}
	emit sigSwitchAcc(bLoginByTax, bOther, strTaxNo_userName, strPwd);
}

bool SwitchAccNewWidget::winHttpGetCompanyList(QString strTaxno, QString strToken, QString& strRet)
{
	QString strUrl = QString("/ucenter/user/company-list");



	QString strPost;


	if (strTaxno.isEmpty())
		strPost = QString("token=%1").arg(strToken);
	else
		strPost = QString("tax=%1&token=%2").arg(strTaxno).arg(m_pEntInfo->_strToken);

    
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet,false,1);
}

void SwitchAccNewWidget::getCompanyList()
{

	QString strTaxno = ZcloudComFun::getTaxnumbers();


	QString strRet;



	if (!winHttpGetCompanyList(strTaxno, m_pEntInfo->_strToken, strRet))
	{
		return;
	}
	QByteArray byte_array = strRet.toUtf8();
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
	if (0 != status)
	{
		return;
	}
	QJsonValue list = obj.take("data");
	if (!list.isArray())
	{
		return ;
	}
	QJsonArray listArray = list.toArray();
	int nSize = listArray.size();
	if (0 == nSize)
	{
		return;
	}
	for (int nIndex = 0; nIndex < nSize; ++nIndex)
	{
		QJsonObject dataList = listArray.at(nIndex).toObject();
		QString strCompId	= dataList.take("company_id").toString();
		QString	strTaxNo	= dataList.take("tax_number").toString();
		QString	strLogoPath = ZcloudComFun::downloadPic(dataList.take("logo").toString(), QApplication::applicationDirPath().append("/CacheImage/logoImage"));
		QString	strCompName = dataList.take("company_name").toString();
		int	nIsJoin = dataList.take("is_join").toInt();
		int	nIsCurrent = dataList.take("is_current").toInt();

		if (!isTaxExistInterface(m_pEntInfo->_strUid, strCompId))
		{
			stSwitchAccInfo*	pSwitchInfo = new stSwitchAccInfo;
			pSwitchInfo->strTaxNo		= strTaxNo;
			pSwitchInfo->bLoginByTax	= 1;
			pSwitchInfo->strUserName = m_pEntInfo->_strUsername;
			//pSwitchInfo->strMobliePhone = m_strMobile;
			pSwitchInfo->strLogoPath	= strLogoPath;
			pSwitchInfo->strCompName	= strCompName;
			pSwitchInfo->strUid			= m_pEntInfo->_strUid;
			pSwitchInfo->strCompId		= strCompId;
			pSwitchInfo->nIsCurrent = nIsCurrent;
			pSwitchInfo->nIsjoin = nIsJoin;

			m_vtrAccInfos.push_back(pSwitchInfo);
		}	
	}
}

bool SwitchAccNewWidget::isTaxExistInterface(QString strUid, QString strCompId)
{
	vtrSwitchAccInfos::iterator itr = m_vtrAccInfos.begin();
	for (; itr != m_vtrAccInfos.end(); ++itr)
	{
		stSwitchAccInfo* pInfo = (*itr);
		if (NULL != pInfo)
		{
			if (pInfo->strCompId == strCompId	&&	pInfo->strUid == strUid)
			{
				return true;
			}
		}
	}
	return false;
}

void SwitchAccNewWidget::openCreateEntDlg()
{
	
	CreateEntInfoWidget* pEntComWidget = new CreateEntInfoWidget(m_userInfo,m_userInfo->m_strUserId, m_userInfo->m_strToken, this);
	pEntComWidget->setAttribute(Qt::WA_DeleteOnClose);
	pEntComWidget->show();
	
	
	
	
	//if (pEntComWidget->exec() == QDialog::Accepted)
	//{

	//	pEntComWidget->accept();
	//}


	//int result = ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_BINDING, QString::fromLocal8Bit("创建失败"), QString::fromLocal8Bit("该企业已绑定管理员，您可以联系企业管理员将您\r\n添加到企业成员，或申述成为该企业管理员"), QString::fromLocal8Bit("申述"), QString::fromLocal8Bit("取消"));
	//if (result == 1){
	//	上传图片

	/*	UploadLicenseDlg dlg;
	int rst=dlg.exec();

	int result = ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("申述提交成功"), QString::fromLocal8Bit("您的申述已提交成功，我们会尽快为您处理，\r\n请耐心等待"));
	*/
}