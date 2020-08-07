#include "WorkersWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QScrollBar>
#include "WorkerItemWidget.h"
#include "WorkerCommentWidget.h"
#include "WorkerDetailWidget.h"
#include "WorkerDataBase.h"

//#include "AddMemberWidget.h"
//#include "AuditMemberWidget.h"
//#include "ModifyMemberWidget.h"
#include "ZcloudBigData.h"
#include "QBoxLayout"
#define   SCROLLBARSTYESHEET  "QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"
WorkersWidget::WorkersWidget(QString strUid, QString strToken, QWidget *parent)
	: QWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
{
	ui.setupUi(this);
	//resize(840, 630);
	setWindowTitle(QString::fromLocal8Bit("我的工单"));
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("worker");
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
	m_pDetailWidget = new WorkerDetailWidget("",strToken, this);
	m_pCommentWidget = new WorkerCommentWidget("", strToken,this);
	showWorkers();
	//if (!showOrderList())
	//{
	//	/*ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n打开财务成员失败，请稍后再试！"));
	//	close();*/
	//}

	//ui.labelAudit->installEventFilter(this);
	//connect(ui.addMemberButton, &QPushButton::clicked, this, &OrderListWidget::onAddMember);

	ui.listWidget->verticalScrollBar()->setStyleSheet(SCROLLBARSTYESHEET);


	setBlockSize(3);
	initializePages();

	maxPage = 0;
	setMaxPage(1);
	connect(this, SIGNAL(currentPageChanged(int)), this, SLOT(getCurrentPageView(int)));
}

WorkersWidget::~WorkersWidget()
{
	delete m_pDetailWidget;
	delete m_pCommentWidget;
	cleanAllWorker();

}

bool WorkersWidget::winHttpGetWorks(QString strPage, QString strToken, QString& strRet)
{
	QString strUrl = QString("/serviceorder/pc-worker/get-list");
	 
	QString strPost;
	if (strPage == "")
	strPost= QString("token=%1").arg(strToken);
	else
	strPost = QString("token=%1&page=%2").arg(strToken).arg(strPage);
	//	.arg(strName).arg(strMobile).arg(strAddr).arg(m_addrInfo._nProId).arg(m_addrInfo._nCityId).arg(m_addrInfo._nAreaId);

	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);
}


//void WorkersWidget::onworkerComment(QString ordercode){
//	
//	//connect(pWidget, &ModifyMemberWidget::sigModifyMember, this, &FinanMemberWidget::onModifyMemberSucess);
//
//
//
//	m_pCommentWidget->show();
//}
bool WorkersWidget::showWorkers()
{
	/*{

		QListWidgetItem* pListWidgetItem = new QListWidgetItem;

		
		OrderListItemWidget* pItem = new OrderListItemWidget("12311414", QString::fromLocal8Bit("测试"), QString::fromLocal8Bit("已完成"), "2020-10-01 12:00:00", QString::fromLocal8Bit("评价"), ui.listWidget);
		
		
		
		
		ui.listWidget->insertItem(0,pListWidgetItem);
		QSize size = pItem->size();
		pListWidgetItem->setSizeHint(size);
		ui.listWidget->setItemWidget(pListWidgetItem, pItem);

		connect(pItem, &OrderListItemWidget::sigDetial, this, &OrderListWidget::orderDetial);
		connect(pItem, &OrderListItemWidget::sigEvaluate, this, &OrderListWidget::orderComment);


		return true;

	}*/



	return fillPages("");


	

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

}

bool WorkersWidget::fillPages(QString strpage)
{
	QString  strRet;
	if (!winHttpGetWorks(strpage, m_strToken, strRet))
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
	//int		nAdmin = data.take("is_admin").toInt();
	int total_num = data.take("total_num").toInt();
	int total_page = data.take("total_page").toInt();

	maxPage = total_page;

	//int		nAuditCount = data.take("audit_count").toInt();
	QJsonValue list = data.take("list");
	if (!list.isArray())
	{
		return false;
	}
	QJsonArray listArray = list.toArray();
	int nSize = listArray.size();

	WorkerItemWidget* pItem;
	WorkerInfo info;
	QString dtCreateTime;
	for (int nIndex = 0; nIndex < nSize; ++nIndex)
	{
		QJsonObject dataList = listArray.at(nIndex).toObject();

		info.strWorkerid = dataList.take("worker_id").toString();
		info.strAcceptid = dataList.take("accept_id").toString();
		info.strCompanyid = dataList.take("company_id").toString();
		info.strUid = dataList.take("user_id").toString();

		info.iLevel = dataList.take("level").toInt();
		info.strWorkertitle = dataList.take("worker_title").toString();
		info.iState = dataList.take("state").toInt();
		info.bIsread = dataList.take("is_read").toBool();
		info.strLeveldesc = dataList.take("level_desc").toString();
		info.strStatedesc = dataList.take("state_desc").toString();

		dtCreateTime = dataList.take("create_time").toString();
		info._dtCreateTime = QDateTime::fromString(dtCreateTime, "yyyy.MM.dd hh:mm");


		QListWidgetItem* pListWidgetItem = new QListWidgetItem;
		pItem = new WorkerItemWidget(info, QString::fromLocal8Bit("评价"), ui.listWidget);

		ui.listWidget->insertItem(0, pListWidgetItem);
		QSize size = pItem->size();
		pListWidgetItem->setSizeHint(size);
		ui.listWidget->setItemWidget(pListWidgetItem, pItem);

		//connect(pItem, &OrderListItemWidget::sigRemoveMember, this, &OrderListWidget::onRemoveMember);
		//connect(pItem, &OrderListItemWidget::sigModifyMember, this, &OrderListWidget::onModifyMember);
		//connect(pItem, &OrderListItemWidget::sigHandOver, this, &OrderListWidget::onHandOver);
		connect(pItem, &WorkerItemWidget::sigDetial, m_pDetailWidget, &WorkerDetailWidget::onworkerDetail);
		connect(pItem, &WorkerItemWidget::sigEvaluate, m_pCommentWidget, &WorkerCommentWidget::onworkerComment);


		/*QSize size = pItem->size();
		pListWidgetItem->setSizeHint(size);
		ui.listWidget->setItemWidget(pListWidgetItem, pItem);*/
	}
	return true;
}


bool WorkersWidget::eventFilter(QObject *target, QEvent *e)
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
	if (e->type() == QEvent::MouseButtonRelease) {
		int page = -1;
		if (target == ui.previousPageLabel) { page = getCurrentPage() - 1; }

		if (target == ui.nextPageLabel) { page = getCurrentPage() + 1; }

		for (int i = 0; i < pageLabels->count(); ++i) {
			if (target == pageLabels->at(i)) {
				page = pageLabels->at(i)->text().toInt();
				break;
			}
		}

		if (-1 != page) {
			setCurrentPage(page, true);
			return true;
		}
	}

	if (target == ui.pageLineEdit && e->type() == QEvent::KeyRelease) {
		QKeyEvent *ke = static_cast<QKeyEvent *>(e);
		if (ke->key() == Qt::Key_Enter || ke->key() == Qt::Key_Return) {
			setCurrentPage(ui.pageLineEdit->text().toInt(), true);
			//setMaxPage(ui->pageLineEdit->text().toInt()); // 测试生成多个页码
			return true;
		}
	}
	return QWidget::eventFilter(target, e);
}

void WorkersWidget::onFreshWorkers()
{
	cleanAllWorker();

	showWorkers();
}

void WorkersWidget::cleanAllWorker()
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


void WorkersWidget::mousePressEvent(QMouseEvent *event)
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

void WorkersWidget::mouseMoveEvent(QMouseEvent *event)
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


void WorkersWidget::initializePages()
{
	ui.pageLineEdit->installEventFilter(this);
	ui.pageLineEdit->setValidator(new QIntValidator(1, 10000000, this));

	ui.nextPageLabel->setProperty("page", "true");
	ui.previousPageLabel->setProperty("page", "true");
	ui.nextPageLabel->installEventFilter(this);
	ui.previousPageLabel->installEventFilter(this);

	pageLabels = new QList<QLabel *>();

	QHBoxLayout *leftLayout = new QHBoxLayout();
	QHBoxLayout *centerLayout = new QHBoxLayout();
	QHBoxLayout *rightLayout = new QHBoxLayout();
	leftLayout->setContentsMargins(0, 0, 0, 0);
	leftLayout->setSpacing(0);
	centerLayout->setContentsMargins(0, 0, 0, 0);
	centerLayout->setSpacing(0);
	rightLayout->setContentsMargins(0, 0, 0, 0);
	rightLayout->setSpacing(0);

	for (int i = 0; i < blockSize * 3; ++i) {
		QLabel *label = new QLabel(QString::number(i + 1));
		label->setProperty("page", "true");
		label->installEventFilter(this);

		pageLabels->append(label);

		if (i < blockSize) {
			leftLayout->addWidget(label);
		}
		else if (i < blockSize * 2) {
			centerLayout->addWidget(label);
		}
		else {
			rightLayout->addWidget(label);
		}
	}
	
	ui.leftPagesWidget->setLayout(leftLayout);
	ui.centerPagesWidget->setLayout(centerLayout);
	ui.rightPagesWidget->setLayout(rightLayout);
}

void WorkersWidget::updatePageLabels()
{


	ui.leftSeparateLabel->hide();
	ui.rightSeparateLabel->hide();

	if (maxPage <= blockSize * 3) {
		for (int i = 0; i < pageLabels->count(); i += 1) {
			QLabel *label = pageLabels->at(i);

			if (i < maxPage) {
				label->setText(QString::number(i + 1));
				label->show();
			}
			else {
				label->hide();
			}

			if (currentPage - 1 == i) {
				label->setProperty("currentPage", "true");
			}
			else {
				label->setProperty("currentPage", "false");
			}

			label->setStyleSheet("/**/");
		}
		return;
	}

	// 以下情况为maxPageNumber大于blockSize * 3, 所有的页码label都要显示
	// c 为 currentPage
	// n 为 block size
	// m 为 maxPage

	// 1. c ∈ [1, n + n/2 + 1]: 显示前 n * 2 个, 后 n 个: 只显示右边的分隔符
	// 2. c ∈ [m - n - n/2, m]: 显示前 n 个, 后 n * 2 个: 只显示左边的分隔符
	// 3. 显示[1, n], [c - n/2, c + n/2], [m - 2*n + 1, m]: 两个分隔符都显示

	int c = currentPage;
	int n = blockSize;
	int m = maxPage;
	int centerStartPage = 0;

	if (c >= 1 && c <= n + n / 2 + 1) {
		// 1. c ∈ [1, n + n/2 + 1]: 显示前 n * 2 个, 后 n 个: 只显示右边的分隔符
		centerStartPage = n + 1;
		ui.rightSeparateLabel->show();
	}
	else if (c >= m - n - n / 2 && c <= m) {
		// 2. c ∈ [m - n - n/2, m]: 显示前 n 个, 后 n * 2 个: 只显示左边的分隔符
		centerStartPage = m - n - n + 1;
		ui.leftSeparateLabel->show();
	}
	else {
		// 3. 显示[1, n], [c - n/2, c + n/2], [m - n + 1, m]: 两个分隔符都显示
		centerStartPage = c - n / 2;
		ui.rightSeparateLabel->show();
		ui.leftSeparateLabel->show();
	}

	for (int i = 0; i < n; ++i) {
		pageLabels->at(i)->setText(QString::number(i + 1));                     // 前面 n 个
		pageLabels->at(n + i)->setText(QString::number(centerStartPage + i));   // 中间 n 个
		pageLabels->at(3 * n - i - 1)->setText(QString::number(m - i));         // 后面 n 个
	}

	for (int i = 0; i < pageLabels->count(); ++i) {
		QLabel *label = pageLabels->at(i);
		int page = label->text().toInt();
		if (page == currentPage) {
			label->setProperty("currentPage", "true");
		}
		else {
			label->setProperty("currentPage", "false");
		}

		label->setStyleSheet("/**/");
		label->show();
	}
}

void WorkersWidget::setBlockSize(int blockSize)
{
	// 为了便于计算, block size 必须是奇数, 且最小为3
	blockSize = qMax(blockSize, 3);
	if (blockSize % 2 == 0) {
		++blockSize;
	}
	this->blockSize = blockSize;
}




void WorkersWidget::setCurrentPage(int page, bool signalEmitted /*= false*/)
{
	page = qMax(page, 1);
	page = qMin(page, maxPage);

	if (page != this->currentPage) {
		this->currentPage = page;
		updatePageLabels();

		if (signalEmitted) {
			emit currentPageChanged(page);
		}
	}
}

void WorkersWidget::setMaxPage(int page)
{
	page = qMax(page, 1);

	if (maxPage != page) {
		this->maxPage = page;
		this->currentPage = 1;
		updatePageLabels();
	}
}

int WorkersWidget::getCurrentPage() const
{
	return currentPage;
}

int WorkersWidget::getMaxPage() const
{
	return maxPage;
}


int WorkersWidget::getBlockSize() const
{
	return blockSize;
}

bool WorkersWidget::getCurrentPageView(int curpage)
{
	//throw std::logic_error("The method or operation is not implemented.");
	cleanAllWorker();
	return fillPages(QString::number(curpage));
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


