#include "OrderListWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QScrollBar>
#include "OrderListItemWidget.h"
#include "OrderCommentWidget.h"
#include "OrderDetialWidget.h"


//#include "AddMemberWidget.h"
//#include "AuditMemberWidget.h"
//#include "ModifyMemberWidget.h"
#include "ZcloudBigData.h"
#define   SCROLLBARSTYESHEET  "QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"
OrderListWidget::OrderListWidget(QString strUid, QString strToken, QWidget *parent)
	: QWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
{
	ui.setupUi(this);
	resize(840, 430);
	setWindowTitle(QString::fromLocal8Bit("财务成员"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("financialMember");
	setAttribute(Qt::WA_ShowModal, true);

	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, false);
	setWindowModality(Qt::WindowModal);
	setStyleSheet("outline: none");

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});
	/*connect(ui.closeButton, &QPushButton::clicked, [this](){
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BFM009");
		close();
	});*/

	showOrderList();
	//if (!showOrderList())
	//{
	//	/*ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n打开财务成员失败，请稍后再试！"));
	//	close();*/
	//}

	//ui.labelAudit->installEventFilter(this);
	//connect(ui.addMemberButton, &QPushButton::clicked, this, &OrderListWidget::onAddMember);

	ui.listWidget->verticalScrollBar()->setStyleSheet(SCROLLBARSTYESHEET);
}

OrderListWidget::~OrderListWidget()
{
}

bool OrderListWidget::winHttpGetOrderList(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/v2/company/member-index?user_id=%1&token=%2").arg(m_strUid).arg(m_strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}


void OrderListWidget::orderDetial(QString ordercode){
	
	OrderDetialWidget*	pWidget = new OrderDetialWidget("", this);
	//connect(pWidget, &ModifyMemberWidget::sigModifyMember, this, &FinanMemberWidget::onModifyMemberSucess);
	pWidget->show();
}
void OrderListWidget::orderComment(QString ordercode){
	OrderCommentWidget*	pWidget = new OrderCommentWidget("", this);
	//connect(pWidget, &ModifyMemberWidget::sigModifyMember, this, &FinanMemberWidget::onModifyMemberSucess);
	pWidget->show();
}
bool OrderListWidget::showOrderList()
{
	{

		QListWidgetItem* pListWidgetItem = new QListWidgetItem;

		
		OrderListItemWidget* pItem = new OrderListItemWidget("12311414", QString::fromLocal8Bit("测试"), QString::fromLocal8Bit("已完成"), "2020-10-01 12:00:00", QString::fromLocal8Bit("评价"), ui.listWidget);
		ui.listWidget->insertItem(0,pListWidgetItem);
		QSize size = pItem->size();
		pListWidgetItem->setSizeHint(size);
		ui.listWidget->setItemWidget(pListWidgetItem, pItem);

		connect(pItem, &OrderListItemWidget::sigDetial, this, &OrderListWidget::orderDetial);
		connect(pItem, &OrderListItemWidget::sigEvaluate, this, &OrderListWidget::orderComment);


		return true;

	}



	QString  strRet;
	if (!winHttpGetOrderList(m_strUid, m_strToken, strRet))
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
	int		nAdmin = data.take("is_admin").toInt();
	int		nAuditCount = data.take("audit_count").toInt();
	QJsonValue list = data.take("user_list");
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
		//OrderListItemWidget* pItem = new OrderListItemWidget(nAdmin, nIndex % 6, strUid, strUserName, strTrueName, strJob, strMobile, nRoleType, ui.listWidget);
		//connect(pItem, &OrderListItemWidget::sigRemoveMember, this, &OrderListWidget::onRemoveMember);
		//connect(pItem, &OrderListItemWidget::sigModifyMember, this, &OrderListWidget::onModifyMember);
		//connect(pItem, &OrderListItemWidget::sigHandOver, this, &OrderListWidget::onHandOver);

		if (1 == nRoleType)
		{
			ui.listWidget->insertItem(0, pListWidgetItem);
		}
		else
		{
			ui.listWidget->addItem(pListWidgetItem);
		}

		/*QSize size = pItem->size();
		pListWidgetItem->setSizeHint(size);
		ui.listWidget->setItemWidget(pListWidgetItem, pItem);*/
	}
	/*if (nAuditCount >= 0)
	{
		ui.labelAudit->setText(QString::fromLocal8Bit("成员审核(%1)").arg(nAuditCount));
		ui.labelAudit->adjustSize();
	}
	if (1 != nAdmin)
	{
		ui.addMemberButton->hide();
		ui.labelAudit->hide();
	}*/
	return true;
}


bool OrderListWidget::eventFilter(QObject *target, QEvent *e)
{
	//if (target == ui.labelAudit)
	//{
	//	if (e->type() == QEvent::MouseButtonRelease) //
	//	{
	//		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BFM001");
	//		AuditMemberWidget*	pWidget = new AuditMemberWidget(m_strUid,m_strToken,this);
	//		connect(pWidget, &AuditMemberWidget::sigRefreshOrderList, this, &OrderListWidget::onFreshOrderList);
	//		pWidget->show();
	//	}
	//}
	return QWidget::eventFilter(target, e);
}

void OrderListWidget::onFreshOrderList()
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
	showOrderList();
}

void OrderListWidget::mousePressEvent(QMouseEvent *event)
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

void OrderListWidget::mouseMoveEvent(QMouseEvent *event)
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

//void OrderListWidget::onModifyMember(QString strTrueName,QString strJob,QString strUserId)
//{
//	/*ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BFM003");
//	ModifyMemberWidget*	pWidget = new ModifyMemberWidget(strTrueName, strJob,m_strUid, m_strToken, strUserId, this);
//	connect(pWidget, &ModifyMemberWidget::sigModifyMember, this, &OrderListWidget::onModifyMemberSucess);
//	pWidget->show();*/
//}



//bool OrderListWidget::winHttpRemoveMember(QString strUid, QString strToken, QString strUserId, QString& strRet)
//{
//	QString strUrl = QString("/v2/company/remove-member?user_id=%1&token=%2").arg(m_strUid).arg(m_strToken);
//	QString strPost = QString("u_id=%1").arg(strUserId);
//	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet);
//}

//void OrderListWidget::onAddMemberSucess()
//{
//	/*AddMemberWidget*	pWidget = qobject_cast<AddMemberWidget*>(sender());
//	if (NULL != pWidget)
//	{
//		pWidget->close();
//	}
//	onFreshOrderList();*/
//}


