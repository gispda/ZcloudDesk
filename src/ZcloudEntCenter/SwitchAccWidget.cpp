#include "SwitchAccWidget.h"
#include <QGraphicsDropShadowEffect>
#include "AccItemWidget.h"
#include <QSettings>
#include "ZcloudBigData.h"
#include <QDebug>
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>

SwitchAccWidget::SwitchAccWidget(QString strUid, QString strToken, QString strUserName, QString strMobile, QString strCompId, QWidget *parent)
	: QWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
	, m_strCompId(strCompId)
	, m_strUserName(strUserName)
	, m_strMobile(strMobile)
{
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

	ui.labelOtherAcc->setStyleSheet("font:14px \"微软雅黑\";color:#1E8BED;");
	ui.labelOtherAcc->installEventFilter(this);
	ui.label->hide();

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BCA003");
		close();
	});
	connect(ui.lineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(onTextChanged(const QString&)));

	getSwitchInfo();

	showListWidget("");
}

SwitchAccWidget::~SwitchAccWidget()
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

void SwitchAccWidget::mousePressEvent(QMouseEvent *event)
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

void SwitchAccWidget::mouseMoveEvent(QMouseEvent *event)
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

bool SwitchAccWidget::eventFilter(QObject *target, QEvent *e)
{
	if (target == ui.labelOtherAcc)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			emit sigSwitchAcc(0, true,"", "");
		}
		else if (e->type() == QEvent::Enter)
		{
			ui.labelOtherAcc->setStyleSheet("font:14px \"微软雅黑\";color:#02a4fc;");
		}
		else if (e->type() == QEvent::Leave)
		{
			ui.labelOtherAcc->setStyleSheet("font:14px \"微软雅黑\";color:#1E8BED;");
		}
	}
	return QWidget::eventFilter(target, e);
}

void SwitchAccWidget::onTextChanged(const QString& strText)
{
	showListWidget(strText);
}

void SwitchAccWidget::showListWidget(QString strText)
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
			if (pInfo->strUid == m_strUid	&& pInfo->strCompId	==	m_strCompId)
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
				if (pInfo->strUid == m_strUid && pInfo->strCompId == m_strCompId)
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

void SwitchAccWidget::getSwitchInfo()
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

bool SwitchAccWidget::isTaxExistRegedit(QString strTaxNo)
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

void SwitchAccWidget::onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd)
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

bool SwitchAccWidget::winHttpGetCompanyList(QString strTaxno, QString strToken, QString& strRet)
{
	QString strUrl = QString("/ucenter/user/company-list");



	QString strPost;


	if (strTaxno.isEmpty())
		strPost = QString("token=%1").arg(strToken);
	else
	   strPost = QString("tax=%1&token=%2").arg(strTaxno).arg(m_strToken);

    
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet,false,1);
}

void SwitchAccWidget::getCompanyList()
{

	QString strTaxno = ZcloudComFun::getTaxnumber();


	QString strRet;



	if (!winHttpGetCompanyList(strTaxno, m_strToken, strRet))
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
		if (!isTaxExistInterface(m_strUid, strCompId))
		{
			stSwitchAccInfo*	pSwitchInfo = new stSwitchAccInfo;
			pSwitchInfo->strTaxNo		= strTaxNo;
			pSwitchInfo->bLoginByTax	= 1;
			pSwitchInfo->strUserName	= m_strUserName;
			pSwitchInfo->strMobliePhone = m_strMobile;
			pSwitchInfo->strLogoPath	= strLogoPath;
			pSwitchInfo->strCompName	= strCompName;
			pSwitchInfo->strUid			= m_strUid;
			pSwitchInfo->strCompId		= strCompId;
			m_vtrAccInfos.push_back(pSwitchInfo);
		}	
	}
}

bool SwitchAccWidget::isTaxExistInterface(QString strUid, QString strCompId)
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
