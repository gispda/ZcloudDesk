#include "JoinEntWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include "AccItemWidget.h"
#include "ZcloudBigData.h"

JoinEntWidget::JoinEntWidget(QString strUid, QString strToken, QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
{
	ui.setupUi(getContentWidget());
	resize(800,500);
	setWindowTitle(QString::fromLocal8Bit("加入企业"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("addEntEnter");
	setAttribute(Qt::WA_ShowModal, true);
	
	ui.listWidget->hide();
	ui.noEntWidget->hide();
	ui.labelNoContent->show();

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BJC008");
		close();
	});

	connect(ui.searchButton, &QPushButton::clicked, this, &JoinEntWidget::onSearchBtnClick);
}

JoinEntWidget::~JoinEntWidget()
{
}

bool JoinEntWidget::winHttpSearchCompany(QString strUserid, QString strToken, QString strKeyWord, QString& strRet)
{
	QString strUrl = QString("/ucenter/company/info");
	QString strPost = QString("tax=%1&token=%2").arg(strKeyWord).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet,false,1);
}

void JoinEntWidget::onSearchBtnClick()
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

	QString strKeyWord = ui.lineEdit->text();
	if (strKeyWord.isEmpty())
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BJC001");
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("搜索失败"), QString::fromLocal8Bit("\r\n请输入完整的企业名称或统一社会信用代码！"));
		return;
	}
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BJC001", strKeyWord);
	QString strRet;

	if (!winHttpSearchCompany(m_strUid, m_strToken, strKeyWord, strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("搜索失败"), QString::fromLocal8Bit("\r\n搜索企业信息失败，请稍后再试！"));
		ui.listWidget->hide();
		ui.noEntWidget->hide();
		ui.labelNoContent->show();
		return;
	}
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return ;
	}
	if (!parse_doucment.isObject())
	{
		return ;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("code").toInt();

	if (status == 0)
	{
		QJsonObject data = obj.take("data").toObject();
		if (data.isEmpty())
		{
			ui.listWidget->hide();
			ui.labelNoContent->hide();
			ui.noEntWidget->show();
		}
		else
		{
			ui.listWidget->show();
			ui.labelNoContent->hide();
			ui.noEntWidget->hide();

			QString strComId	= data.take("company_id").toString();
			QString	strTaxNo	= data.take("tax_number").toString();
			QString	strComName	= data.take("company_name").toString();
			QString	strLogo		= ZcloudComFun::downloadPic(data.take("logo").toString(), QApplication::applicationDirPath().append("/CacheImage/logoImage"));
			int		nState = data.take("is_join").toInt();;

			QListWidgetItem* pListWidgetItem = new QListWidgetItem;
			AccItemWidget* pItem = new AccItemWidget(strComId, strTaxNo, strComName, strLogo, nState, ui.listWidget);
			connect(pItem, SIGNAL(sigJoinEnt(QString)), this, SLOT(onJoinEnt(QString)));
			connect(pItem, SIGNAL(sigCancelReview(QString)), this, SLOT(onCancelReview(QString)));
			ui.listWidget->addItem(pListWidgetItem);
			QSize size = pItem->size();
			pListWidgetItem->setSizeHint(size);
			ui.listWidget->setItemWidget(pListWidgetItem, pItem);
		}
	}
	else if (20029	==	status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("搜索失败"), QString::fromLocal8Bit("\r\n请输入完整的企业名称或统一社会信用代码！"));
		ui.listWidget->hide();
		ui.noEntWidget->hide();
		ui.labelNoContent->show();
	}
	else
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("搜索失败"), QString::fromLocal8Bit("\r\n搜索企业信息失败，请稍后再试！"));
		ui.listWidget->hide();
		ui.noEntWidget->hide();
		ui.labelNoContent->show();
	}
}

void JoinEntWidget::onJoinEnt(QString strComId)
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BJC004", strComId);
	QString strRet;
	if (!winHttpJoinEnt(m_strUid, m_strToken, strComId, strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n提交加入申请失败，请稍后再试！"));
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
	int status = obj.take("code").toInt();
	if (0 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("已成功提交加入申请，\r\n请等待对方管理员审核通过！"));
		QWidget*	pWidget = ui.listWidget->itemWidget(ui.listWidget->item(0));
		if (NULL == pWidget)
		{
			return;
		}
		AccItemWidget*	pItem = qobject_cast<AccItemWidget*>(pWidget);
		if (NULL == pItem)
		{
			return;
		}
		pItem->setReviewStatue(true);
	}
	else if (20034 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n加入申请失败，系统不存在此企业信息，请确认你的操作！"));
	}
	else if (60001 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n加入申请失败，申请的企业不能为空！"));
	}
	else if (60002 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n加入申请失败，申请的企业id类型不正确！"));
	}
	else if (60003 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作提示"), QString::fromLocal8Bit("\r\n加入申请失败，你已提交过此申请了，请等待企业管理员审核！"));
	}
	else if (60004 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作提示"), QString::fromLocal8Bit("\r\n加入申请失败，你已经是企业的成员了，请不要重复加入！"));
	}
	else
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n加入申请失败，请稍后再试！"));
	}
}

void JoinEntWidget::onCancelReview(QString strComId)
{
	QString strRet;
	if (!winHttpCancelJoinEnt(m_strUid, m_strToken, strComId, strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n取消加入申请失败，请稍后再试！"));
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
	if (0 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n已成功取消加入申请！"));
		QWidget*	pWidget = ui.listWidget->itemWidget(ui.listWidget->item(0));
		if (NULL == pWidget)
		{
			return;
		}
		AccItemWidget*	pItem = qobject_cast<AccItemWidget*>(pWidget);
		if (NULL == pItem)
		{
			return;
		}
		pItem->setReviewStatue(false);
	}
	else if (20004 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n取消加入申请失败，企业编号不存在！"));
	}
	else if (10055 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n取消加入申请失败，企业编号错误！"));
	}
	else
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n取消加入申请失败，请稍后再试！"));
	}
}

bool JoinEntWidget::winHttpJoinEnt(QString strUid, QString strToken, QString strComId, QString& strRet)
{
	QString strUrl = QString("/ucenter/company/apply-join");
	QString strPost = QString("company_id=%1&token=%2").arg(strComId).arg(m_strToken);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet,false,1);
}

bool JoinEntWidget::winHttpCancelJoinEnt(QString strUid, QString strToken, QString strComId, QString& strRet)
{
	QString strUrl = QString("/v2/company/cancel-join-company?user_id=%1&token=%2").arg(m_strUid).arg(m_strToken);
	QString strPost = QString("company_id=%1").arg(strComId);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}
