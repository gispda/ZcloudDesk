#include "FinanMemberWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QScrollBar>
#include "MemberItemWidget.h"
#include "AddMemberWidget.h"
#include "AuditMemberWidget.h"
#include "ModifyMemberWidget.h"
#include "ZcloudBigData.h"
#define   SCROLLBARSTYESHEET  "QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"
FinanMemberWidget::FinanMemberWidget(QString strUid, QString strToken, QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
{
	ui.setupUi(getContentWidget());
	resize(800, 500);
	setWindowTitle(QString::fromLocal8Bit("财务成员"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("financialMember");
	setAttribute(Qt::WA_ShowModal, true);

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BFM009");
		close();
	});

	if (!showMemberInfo())
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n打开财务成员失败，请稍后再试！"));
		close();
	}

	ui.labelAudit->installEventFilter(this);
	connect(ui.addMemberButton, &QPushButton::clicked, this, &FinanMemberWidget::onAddMember);

	ui.listWidget->verticalScrollBar()->setStyleSheet(SCROLLBARSTYESHEET);
}

FinanMemberWidget::~FinanMemberWidget()
{
}

bool FinanMemberWidget::winHttpGetMemberInfo(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/ucenter/user/user-list");
	QString strPost = QString("token=%1").arg(strToken);

	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet,false,1);
}

bool FinanMemberWidget::showMemberInfo()
{
	QString  strRet;
	if (!winHttpGetMemberInfo(m_strUid, m_strToken, strRet))
	{
		return false;
	}
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return false;
	}
	if (!parse_doucment.isObject())
	{
		return false;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("status").toInt();
	if (0 != status)
	{
		return false;
	}
	
	QJsonObject data = obj.take("data").toObject();
	int		nAdmin;
	int		nAuditCount = data.take("audit_count").toInt();
	QJsonValue list = data.take("list");
	if (!list.isArray())
	{
		return false;
	}
	QJsonArray listArray = list.toArray();
	int nSize = listArray.size();
	for (int nIndex = 0; nIndex < nSize; ++nIndex)
	{
		QJsonObject dataList = listArray.at(nIndex).toObject();
		QString strUid = dataList.take("user_id").toString();
		QString strUserName = dataList.take("username").toString();
		QString strTrueName = dataList.take("truename").toString();
		QString strJob = dataList.take("job").toString();
		QString strMobile = dataList.take("mobile").toString();
		int		nRoleType = dataList.take("role_type").toInt();

		QListWidgetItem* pListWidgetItem = new QListWidgetItem;

		MemberItemWidget* pItem = new MemberItemWidget(nAdmin, nIndex % 6, strUid, strUserName, strTrueName, strJob, strMobile, nRoleType, ui.listWidget);
		connect(pItem, &MemberItemWidget::sigRemoveMember, this, &FinanMemberWidget::onRemoveMember);
		connect(pItem, &MemberItemWidget::sigModifyMember, this, &FinanMemberWidget::onModifyMember);
		connect(pItem, &MemberItemWidget::sigHandOver, this, &FinanMemberWidget::onHandOver);

		if (1 == nRoleType)
		{
			ui.listWidget->insertItem(0, pListWidgetItem);
		}
		else
		{
			ui.listWidget->addItem(pListWidgetItem);
		}

		QSize size = pItem->size();
		pListWidgetItem->setSizeHint(size);
		ui.listWidget->setItemWidget(pListWidgetItem, pItem);
	}
	if (nAuditCount >= 0)
	{
		ui.labelAudit->setText(QString::fromLocal8Bit("成员审核(%1)").arg(nAuditCount));
		ui.labelAudit->adjustSize();
	}
	if (1 != nAdmin)
	{
		ui.addMemberButton->hide();
		ui.labelAudit->hide();
	}
	return true;
}

void FinanMemberWidget::onAddMember()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BFM007");
	AddMemberWidget*	pWidget	=	new AddMemberWidget(m_strUid,m_strToken,this);
	connect(pWidget, &AddMemberWidget::sigAddMember, this, &FinanMemberWidget::onAddMemberSucess);
	pWidget->show();
}

bool FinanMemberWidget::eventFilter(QObject *target, QEvent *e)
{
	if (target == ui.labelAudit)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BFM001");
			AuditMemberWidget*	pWidget = new AuditMemberWidget(m_strUid,m_strToken,this);
			connect(pWidget, &AuditMemberWidget::sigRefreshFinanMember, this, &FinanMemberWidget::onFreshFinanMember);
			pWidget->show();
		}
	}
	return QWidget::eventFilter(target, e);
}

void FinanMemberWidget::onFreshFinanMember()
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
	showMemberInfo();
}

void FinanMemberWidget::onRemoveMember(QString strUserId)
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BFM005",strUserId);
	int nReturn = ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("移除成员"), QString::fromLocal8Bit("移除后，该成员将脱离企业，\r\n是否确认移除？"));
	if (nReturn != QDialog::Accepted)
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BDM001",strUserId);
		return;
	}
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BDM002", strUserId);
	QString strRet;
	if (!winHttpRemoveMember(m_strUid, m_strToken, strUserId, strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n移除用户失败，请稍后再试！"));
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
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n移除财务成员成功！"));
		onFreshFinanMember();
	}
	else if (10001 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n用户编号错误！"));
	}
	else if (30025 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n目标用户不存在！"));
	}
	else if (30026 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n目标用户无法被删除！"));
	}
	else
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n移除用户失败，请稍后再试！"));
	}
}

void FinanMemberWidget::onModifyMember(QString strTrueName,QString strJob,QString strUserId)
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BFM003");
	ModifyMemberWidget*	pWidget = new ModifyMemberWidget(strTrueName, strJob,m_strUid, m_strToken, strUserId, this);
	connect(pWidget, &ModifyMemberWidget::sigModifyMember, this, &FinanMemberWidget::onModifyMemberSucess);
	pWidget->show();
}

void FinanMemberWidget::onHandOver(QString strUserId)
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BFM006", strUserId);
	int nReturn	=	ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("移交管理员"), QString::fromLocal8Bit("移交后，您将失去管理员身份，\r\n是否确认移交？"));
	if (nReturn != QDialog::Accepted)
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BTS002", strUserId);
		return;
	}
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BTS001", strUserId);
	QString strRet;
	if (!winHttpHandOver(m_strUid, m_strToken, strUserId, strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n移交权限失败，请稍后再试！"));
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
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n移交管理员权限成功！"));
		onFreshFinanMember();
	}
	else if (10001 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n用户编号错误！"));
	}
	else if (30069 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n对不起，您没有操作权限！"));
	}
	else if (30025 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n目标用户不存在！"));
	}
	else if (30026 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n目标用户无法被操作！"));
	}
	else
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n移交权限失败，请稍后再试！"));
	}
}

bool FinanMemberWidget::winHttpHandOver(QString strUid, QString strToken, QString strUserId, QString& strRet)
{
	QString strUrl = QString("/v2/company/change-management-authority?user_id=%1&token=%2").arg(m_strUid).arg(m_strToken);
	QString strPost = QString("u_id=%1").arg(strUserId);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

bool FinanMemberWidget::winHttpRemoveMember(QString strUid, QString strToken, QString strUserId, QString& strRet)
{
	QString strUrl = QString("/v2/company/remove-member?user_id=%1&token=%2").arg(m_strUid).arg(m_strToken);
	QString strPost = QString("u_id=%1").arg(strUserId);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

void FinanMemberWidget::onAddMemberSucess()
{
	AddMemberWidget*	pWidget = qobject_cast<AddMemberWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
	onFreshFinanMember();
}

void FinanMemberWidget::onModifyMemberSucess(QString strTrueName, QString strJob, QString strCurUserId)
{
	ModifyMemberWidget*	pWidget = qobject_cast<ModifyMemberWidget*>(sender());
	if (NULL != pWidget)
	{
		pWidget->close();
	}
	onFreshFinanMember();
	if (strCurUserId	==	m_strUid)
	{
		emit sigEditMemberSucessed(strTrueName, strJob);
	}
}
