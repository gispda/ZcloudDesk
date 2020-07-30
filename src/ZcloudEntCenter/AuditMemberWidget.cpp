#include "AuditMemberWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QHBoxLayout>
#include "ZcloudBigData.h"
AuditMemberWidget::AuditMemberWidget(QString strUid, QString strToken,QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
{
	ui.setupUi(getContentWidget());
	resize(454, 366);
	setWindowTitle(QString::fromLocal8Bit("成员审核"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("auditMember");
	setAttribute(Qt::WA_ShowModal, true);

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAL003");
		close();
	});

	ui.tableWidget->setStyleSheet("QHeaderView{"
		"width:414px;"
		"height:30px;"
		"background:rgba(246,246,246,1);}"
		"QHeaderView::section{"
		"font-size:14px;"
		"font-family:'Microsoft YaHei';"
		"color:#333333;"
		"background:rgba(246, 246, 246,1);"
		"border:none;"
		"text-align:left;"
		"min-height:30px;"
		"max-height:30px;"
		"min-width:100px;"
		"max-width:100px;"
		"margin-left:0px;"
		"padding-left:10px;}"
		"QTableWidget{"
		"background:#FFFFFF;"
		"border:none;"
		"font-size:14px;"
		"font-family:'Microsoft YaHei';"
		"color:#333333;}"
		"QScrollBar::vertical{"
		"width:8px;background:rgba(0,0,0,0%);"
		"margin:0px,0px,0px,0px;}"
		"QScrollBar::handle:vertical{"
		"width:8px;background:rgba(0,0,0,25%);border-radius:4px;min-height:20;}"
		"QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%);border-radius:4px;min-height:20;}"
		"QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}"
		"QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}"
		"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"
		);

	ui.tableWidget->setColumnCount(3);

	QStringList header;
	header << QString::fromLocal8Bit("账号") << QString::fromLocal8Bit("申请时间") << QString::fromLocal8Bit("操作");
	ui.tableWidget->setHorizontalHeaderLabels(header);

	ui.tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	ui.tableWidget->setColumnWidth(0, 150);
	ui.tableWidget->setColumnWidth(1, 150);
	ui.tableWidget->verticalHeader()->setVisible(false);
	ui.tableWidget->setFocusPolicy(Qt::NoFocus);

	if (!getAuditList(m_strUid, m_strToken))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n打开审核成员列表失败，请稍后再试！"));
		close();
	}
}

AuditMemberWidget::~AuditMemberWidget()
{
}

bool AuditMemberWidget::winHttpGetAuditList(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/v2/company/get-audit-list?user_id=%1&token=%2").arg(strUid).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

bool AuditMemberWidget::getAuditList(QString strUid, QString strToken)
{
	QString	strRet;
	if (!winHttpGetAuditList(strUid, strToken, strRet))
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
	
	QJsonValue list = obj.take("data");
	if (!list.isArray())
	{
		return false;
	}
	QJsonArray listArray = list.toArray();
	int nSize = listArray.size();
	ui.tableWidget->setRowCount(nSize);
	for (int nIndex = 0; nIndex < nSize; ++nIndex)
	{
		QJsonObject dataList = listArray.at(nIndex).toObject();
		QString strAuditId = dataList.take("audit_id").toString();
		QString strCreateTime = dataList.take("create_time").toString();
		QString strUid = dataList.take("user_id").toString();
		QString strUserName = dataList.take("username").toString();
		QString strMobile = dataList.take("mobile").toString();

		ui.tableWidget->setItem(nIndex, 0, new QTableWidgetItem(strUserName));
		ui.tableWidget->setItem(nIndex, 1, new QTableWidgetItem(strCreateTime));
		AuditOperWidget*	pOperWidget = new AuditOperWidget(strAuditId, this);
		connect(pOperWidget, &AuditOperWidget::sigAuditOper, this, &AuditMemberWidget::onAuditOper);
		ui.tableWidget->setCellWidget(nIndex, 2, pOperWidget);
	}
	return true;
}

void AuditMemberWidget::onAuditOper(QString strAuditId, int state)
{
	QString strRet;
	if (!winHttpDoAudit(m_strUid, m_strToken, strAuditId, state, strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n审核失败，请稍后再试！"));
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
	int status = obj.take("status").toInt();
	if (0 == status)
	{
		if (1 == state)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n您已通过此财务成员的加入申请！"));
		}
		else if (-1 == state)
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("\r\n您已拒绝此财务成员的加入申请！"));
		}
		int nRow = ui.tableWidget->currentRow();
		ui.tableWidget->removeRow(nRow);

		emit sigRefreshFinanMember();	
	}
	else if (30069 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n对不起，您没有审核权限！"));
	}
	else if (30065 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n对不起，审核记录不存在！"));
	}
	else if (30066 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n对不起，该记录已在别处被审核！"));
	}
	else 
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n审核失败，请稍后再试！"));
	}
}

bool AuditMemberWidget::winHttpDoAudit(QString strUid, QString strToken, QString strAuditId, int state, QString& strRet)
{
	QString strUrl = QString("/v2/company/do-audit?user_id=%1&token=%2").arg(strUid).arg(strToken);
	QString strPost = QString("audit_id=%1&state=%2").arg(strAuditId).arg(state);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
}

AuditOperWidget::AuditOperWidget(QString strAuditId,QWidget *parent /*= Q_NULLPTR*/)
	: QWidget(parent)
	, m_strAuditId(strAuditId)
	, m_pPass(new QLabel(QString::fromLocal8Bit("通过"),this))
	, m_pRefuse(new QLabel(QString::fromLocal8Bit("拒绝"), this))
{
	m_pPass->setFixedSize(28, 14);
	m_pPass->setStyleSheet(QString::fromLocal8Bit("font:14px \"微软雅黑\";color:#1E8BED;"));
	m_pPass->setCursor(Qt::PointingHandCursor);
	m_pPass->installEventFilter(this);

	m_pRefuse->setFixedSize(28, 14);
	m_pRefuse->setStyleSheet(QString::fromLocal8Bit("font:14px \"微软雅黑\";color:#F10020;"));
	m_pRefuse->setCursor(Qt::PointingHandCursor);
	m_pRefuse->installEventFilter(this);

	QHBoxLayout*	pLayout = new QHBoxLayout;
	pLayout->addWidget(m_pPass);
	pLayout->addWidget(m_pRefuse);
	pLayout->addSpacing(10);
	setLayout(pLayout);
}

AuditOperWidget::~AuditOperWidget()
{

}

bool AuditOperWidget::eventFilter(QObject *target, QEvent *e)
{
	if (target == m_pPass)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAL001", m_strAuditId);
			emit sigAuditOper(m_strAuditId, 1);
		}
	}
	else if (target == m_pRefuse)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAL002",m_strAuditId);
			emit sigAuditOper(m_strAuditId, -1);
		}
	}
	return QWidget::eventFilter(target, e);
}
