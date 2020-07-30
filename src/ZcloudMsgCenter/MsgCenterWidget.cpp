#include "MsgCenterWidget.h"
#include <QMovie>
#include <QScrollBar>
#include <QDateTime>
#include <QGridLayout>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QJsonParseError>
#include <QJsonArray>
#include <QGraphicsDropShadowEffect>
#include <QFileInfo>
#include "MsgCenterItem.h"
#include "MsgDataBase.h"
#include "ZcloudBigData.h"
#include "MsgFormWidget.h"
#include "ZcloudCommon.h"
#include <QWebPage>
#include <QWebFrame>
NoFocusFrameDelegate::NoFocusFrameDelegate(QWidget *parent /*= 0*/)
{

}
void NoFocusFrameDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	QStyleOptionViewItem itemOption(option);
	if (itemOption.state & QStyle::State_HasFocus)
	{
		itemOption.state ^= QStyle::State_HasFocus;
	}
	QStyledItemDelegate::paint(painter, itemOption, index);
}

MsgCenterWidget::MsgCenterWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("消息"));
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");
	
	NoFocusFrameDelegate* itemDelegate = new NoFocusFrameDelegate();
	ui.comboBox->setItemDelegate(itemDelegate);
	ui.listWidget->setItemDelegate(itemDelegate);

	m_dtLast = QDateTime::currentDateTime();
	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
	//shadow->setBlurRadius(0.8);				//阴影模糊度
	//设置阴影距离
	shadow->setOffset(0, 0);
	//设置阴影颜色
	shadow->setColor(QColor("#666666"));
	//设置阴影圆角
	shadow->setBlurRadius(8);
	//给嵌套QWidget设置阴影
	this->setGraphicsEffect(shadow);

	connect(ui.minPushButton, &QPushButton::clicked, [this]()
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TME004");
		showMinimized();
	});
	connect(ui.maxPushButton,  &QPushButton::clicked, [this]()
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TME006");
		onMaxBtn();
	});
	connect(ui.closePushButton, &QPushButton::clicked, [this]()
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TME005");
		hide();
	});
	connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onCbxIndexChanged(int)));
	connect(ui.listWidget->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(onSliderChanged(int)));
	ui.labelNoMsg->hide();

	createMsgWidget();
}

MsgCenterWidget::~MsgCenterWidget()
{
	if (m_pMovieImage != NULL)
	{
		m_pMovieImage->stop();
		m_pMovieImage->deleteLater();
	}
}

void MsgCenterWidget::mousePressEvent(QMouseEvent *event)
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

void MsgCenterWidget::mouseMoveEvent(QMouseEvent *event)
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

void MsgCenterWidget::onMaxBtn()
{
	if (isMaximized())	//!现在是全屏，将向普通转换
	{
		m_bIsMax = false;
		setStyle(m_bIsMax);
		ui.maxPushButton->setStyleSheet("QPushButton{border-image:url(:/ZcloudMsgCenter/image/max.png);}"
			"QPushButton:hover, pressed{border-image:url(:/ZcloudMsgCenter/image/max_sel.png);};");
		showNormal();
	}
	else			//!现在是普通，将向全屏转换
	{
		m_bIsMax = true;
		setStyle(m_bIsMax);
		ui.maxPushButton->setStyleSheet("QPushButton{border-image:url(:/ZcloudMsgCenter/image/back.png);}"
			"QPushButton:hover, pressed{border-image:url(:/ZcloudMsgCenter/image/back_sel.png);};");
		showMaximized();
	}
}

void MsgCenterWidget::setStyle(bool  bIsMax)
{
	if (bIsMax)
	{
		this->layout()->setContentsMargins(0, 0, 0, 0);
		ui.MsgLeftTopWidget->setStyleSheet("border-bottom:1px solid #EBEBEB;"
			"border-right:1px solid #EBEBEB;"
			"background-color:#FAFBFF;"
			"border-top-left-radius:0px;");

		ui.MsgLeftBottomWidget->setStyleSheet("background-color:rgb(246, 247, 255);"
			"border-right:1px solid #EBEBEB;"
			"border-bottom-left-radius:0px;");

		ui.MsgRightTopWidget->setStyleSheet("border-bottom:1px solid #EBEBEB;"
			"background-color:rgb(255,255,255);"
			"border-top-right-radius:0px;");

		ui.MsgBtnWidget->setStyleSheet("border-bottom-right-radius:0px;"
			"background-color:rgb(255,255,255);");
	}
	else
	{
		this->layout()->setContentsMargins(8, 8, 8, 8);
		ui.MsgLeftTopWidget->setStyleSheet("border-bottom:1px solid #EBEBEB;"
			"border-right:1px solid #EBEBEB;"
			"background-color:#FAFBFF;"
			"border-top-left-radius:8px; ");

		ui.MsgLeftBottomWidget->setStyleSheet("background-color:rgb(246,247,255);"
			"border-right:1px solid #EBEBEB; "
			"border-bottom-left-radius:8px;");

		ui.MsgRightTopWidget->setStyleSheet("border-bottom:1px solid #EBEBEB;"
			"background-color:rgb(255,255,255);"
			"border-top-right-radius:8px; ");

		ui.MsgBtnWidget->setStyleSheet("border-bottom-right-radius:8px;"
			"background-color:rgb(255,255,255);");
	}
}
void MsgCenterWidget::setAllMsg()
{
	if (!m_mutex.tryLock())
	{
		return;
	}
	ui.comboBox->setCurrentIndex(0);

	m_nType = 0;

	delListWidget();
	
	showMsgList(m_nType);

	m_mutex.unlock();

	if (0 == ui.listWidget->count())
	{
		//!没有剩余item,直接返回,清空数据，设置默认提示图 
		ui.listWidget->hide();
		ui.labelNoMsg->show();
	}
	else
	{
		ui.listWidget->show();
		ui.labelNoMsg->hide();
	}
	m_pPicMsgWidget->hide();
	ui.MsgBtnWidget->hide();
	m_pNorMsgWidget->hide();
	m_pNoMsgWidget->show();
}

void MsgCenterWidget::showListItem(const vtrMsgInfo& msgInfos)
{
	vtrMsgInfo::const_iterator itr = msgInfos.begin();
	for (; itr != msgInfos.end();	++itr)
	{
		stMsgInfo* pMsgInfo = (*itr);
		QListWidgetItem* pListWidgetItem = new QListWidgetItem;
		MsgCenterItem* pItem = new MsgCenterItem(pMsgInfo, pListWidgetItem,ui.listWidget);
		connect(pItem, SIGNAL(sigClickItem(stMsgInfo*, bool)), this, SLOT(onClickItem(stMsgInfo*, bool)));
		connect(pItem, SIGNAL(sigDeleteItem(QString)), this, SLOT(onDeleteItem(QString)));
		connect(pItem, SIGNAL(sigReduceUnreadNum()), this, SLOT(onReduceUnreadNum()));

		QSize size = pItem->size();
		pListWidgetItem->setSizeHint(size);
		ui.listWidget->addItem(pListWidgetItem);
		ui.listWidget->setItemWidget(pListWidgetItem, pItem);
	}
}

void MsgCenterWidget::onClickItem(stMsgInfo* pMsgInfo, bool bRead)
{
	if (!m_mutex.tryLock())
	{
		return;
	}
	m_bUpdateScroll = false;
	if (!bRead)
	{
		sendMessageRespone(0, pMsgInfo->_strUid, pMsgInfo->_strToken, pMsgInfo->_strComId,pMsgInfo->_strMsgId, "", 0, "", false);
	}
	if (NULL == pMsgInfo)
	{
		m_mutex.unlock();
		return;
	}
	
	if (pMsgInfo->_nMsgType	==	2)
	{
		m_pNoMsgWidget->hide();
		m_pNorMsgWidget->hide();
		m_pPicMsgWidget->show();
		ui.MsgBtnWidget->show();
		showPicMsg(pMsgInfo->_strMsgContent);
	}
	else
	{
		m_pNoMsgWidget->hide();
		m_pPicMsgWidget->hide();
		m_pNorMsgWidget->show();
		ui.MsgBtnWidget->show();
		showNorMsg(pMsgInfo->_strMsgTitle, pMsgInfo->_nSendTime, pMsgInfo->_strMsgContent);
	}
	releaseBtnInfo();

	analysisBtnArray(pMsgInfo);

	m_mutex.unlock();

	m_pNowMsgInfo = pMsgInfo;
}

void MsgCenterWidget::onLinkClicked(const QUrl& url)
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TMD001");
	QDesktopServices::openUrl(url);
}

void MsgCenterWidget::paintEvent(QPaintEvent * event)
{
	ui.MsgLeftBottomWidget->update();
	ui.MsgRightBottomWidget->update();
	QWidget::paintEvent(event);
}

void MsgCenterWidget::showWindow()
{
	if (m_bIsMax)	//!显示全屏
	{
		setStyle(m_bIsMax);
		ui.maxPushButton->setStyleSheet("QPushButton{border-image:url(:/ZcloudMsgCenter/image/back.png);}"
			"QPushButton:hover, pressed{border-image:url(:/ZcloudMsgCenter/image/back_sel.png);};");
		showMaximized();
	}
	else		//!显示普通
	{
		setStyle(m_bIsMax);
		ui.maxPushButton->setStyleSheet("QPushButton{border-image:url(:/ZcloudMsgCenter/image/max.png);}"
			"QPushButton:hover, pressed{border-image:url(:/ZcloudMsgCenter/image/max_sel.png);};");
		showNormal();
	}
}

void MsgCenterWidget::onCbxIndexChanged(int index)
{
	switch (index)
	{
		case 0:
		{
			setAllMsg();
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TME001","0");
			break;
		}
		case 1:
		{
			setReadMsg();
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TME001", "1");
			break;
		}
		case 2:
		{
			setUnreadMsg();
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TME001", "2");
			break;
		}
	default:
		break;
	}
}

void MsgCenterWidget::onSliderChanged(int value)
{
	int n = ui.listWidget->verticalScrollBar()->maximum();
	if (value == n)
	{
		showMsgList(m_nType);
	}
}

void MsgCenterWidget::showMsgList(int nType)
{
	int nItemCount = ui.listWidget->count();
	vtrMsgInfo	msgInfos;
	if (!MsgDataBase::GetInstance()->queryMsgInfo(msgInfos, nItemCount, nType))
	{
		return;
	}
	showListItem(msgInfos);
}

void MsgCenterWidget::delListWidget()
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

void MsgCenterWidget::setReadMsg()
{
	if (!m_mutex.tryLock())
	{
		return;
	}
	m_nType = 1;

	delListWidget();

	showMsgList(m_nType);

	m_mutex.unlock();

	if (0 == ui.listWidget->count())
	{
		//!没有剩余item,直接返回,清空数据，设置默认提示图 
		ui.listWidget->hide();
		ui.labelNoMsg->show();
	}
	else
	{
		ui.listWidget->show();
		ui.labelNoMsg->hide();
	}
	m_pPicMsgWidget->hide();
	ui.MsgBtnWidget->hide();
	m_pNorMsgWidget->hide();
	m_pNoMsgWidget->show();
}

void MsgCenterWidget::setUnreadMsg()
{
	if (!m_mutex.tryLock())
	{
		return;
	}
	m_nType = 2;

	delListWidget();

	showMsgList(m_nType);

	m_mutex.unlock();

	if (0 == ui.listWidget->count())
	{
		//!没有剩余item,直接返回,清空数据，设置默认提示图 
		ui.listWidget->hide();
		ui.labelNoMsg->show();
	}
	else
	{
		ui.listWidget->show();
		ui.labelNoMsg->hide();
	}
	m_pPicMsgWidget->hide();
	ui.MsgBtnWidget->hide();
	m_pNorMsgWidget->hide();
	m_pNoMsgWidget->show();
}

void MsgCenterWidget::setUnreadMsgCount(int nUnread)
{
	m_nUnreadCount = nUnread;

	QString strUnreadText = m_nUnreadCount>99 ? QString::fromLocal8Bit("未读消息(99+)") : QString::fromLocal8Bit("未读消息(%1)").arg(m_nUnreadCount);
	ui.comboBox->setItemText(2, strUnreadText);
}

void MsgCenterWidget::onDeleteItem(QString strId)
{
	//!删除数据库
	if (!MsgDataBase::GetInstance()->deleteMsg(strId))
	{
		return;
	}

	//!删除item
	QObject* pObj = sender();
	if (NULL == pObj)
	{
		return;
	}
	MsgCenterItem* pMsgItem = dynamic_cast<MsgCenterItem*>(pObj);
	QListWidgetItem*	pItem = NULL;
	if (NULL != pMsgItem)
	{
		pItem = pMsgItem->getListItem();
	}
	else
	{
		pItem = ui.listWidget->currentItem();
	}
	//!得到当前行数
	int nCurrentIndex = ui.listWidget->row(pItem);
	int nItemCount = ui.listWidget->count();

	//!删除当前行，释放资源
	if (NULL != pItem)
	{
		delete pItem;
		pItem = NULL;
		delete pMsgItem;
		pMsgItem = NULL;
	}

	int	nShowItem = 0;
	if (nCurrentIndex + 1	< nItemCount)
	{
		//!非最后一条，显示后一条
		nShowItem = nCurrentIndex;	
	}
	else
	{
		//!最后一条数据被删除，显示前一条
		nShowItem = nCurrentIndex-1;
	}
	showDetail(nShowItem);
}

void MsgCenterWidget::showDetail(int nRow)
{
	if (0 == ui.listWidget->count() || nRow	<	0)
	{
		//!没有剩余item,直接返回,清空数据，设置默认提示图 
		ui.listWidget->hide();
		ui.labelNoMsg->show();
		m_pPicMsgWidget->hide();
		ui.MsgBtnWidget->hide();
		m_pNorMsgWidget->hide();
		m_pNoMsgWidget->show();
		return;
	}
	ui.labelNoMsg->hide();
	ui.listWidget->show();
	QWidget*	pItemWidget = ui.listWidget->itemWidget(ui.listWidget->item(nRow));
	if (NULL == pItemWidget)
	{
		return;
	}
	MsgCenterItem* pMsgItem = dynamic_cast<MsgCenterItem*>(pItemWidget);
	if (NULL == pMsgItem)
	{
		return;
	}
	pMsgItem->clickItem();
	ui.listWidget->setCurrentRow(nRow);		
}

bool MsgCenterWidget::eventFilter(QObject *target, QEvent *e)
{
	if (target == m_pLabelImage)
	{
		if (e->type() == QEvent::MouseButtonRelease)
		{
			QDateTime	now = QDateTime::currentDateTime();
			if (m_dtLast.msecsTo(now) >= 1000)
			{
				m_dtLast = now;
				sendMessageRespone(3, m_pNowMsgInfo->_strUid, m_pNowMsgInfo->_strToken, m_pNowMsgInfo->_strComId, m_pNowMsgInfo->_strMsgId, "", m_pNowMsgInfo->_nTargetType, m_pNowMsgInfo->_strTarget, true);
			}
		}
	}
	return QWidget::eventFilter(target, e);
}

void MsgCenterWidget::analysisBtnArray(const stMsgInfo* pMsgInfo)
{
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(pMsgInfo->_arryBtnList, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray btnArray		= parse_doucment.array();
			QLayout*	pLayout		= ui.MsgBtnWidget->layout();
			QBoxLayout*	pBoxLayout  = (QBoxLayout*)pLayout;
			for (int nIndex = 0; nIndex < btnArray.size(); ++nIndex)
			{
				stMsgBtnInfo*	pBtnInfo = new stMsgBtnInfo;
				QJsonObject child	 = btnArray.at(nIndex).toObject();
				int nBtnType = child.take("btn_type").toInt();
				if (4 == nBtnType || 0 == nBtnType || 5 == nBtnType)
				{
					continue;
				}
				pBtnInfo->_strBtnId		= child.take("btn_id").toString();
				pBtnInfo->_strBtnName	= child.take("btn_name").toString();
				pBtnInfo->_nBtnType		= nBtnType;
				pBtnInfo->_strBtnTarget = child.take("btn_target").toString();
				pBtnInfo->_nMsgType		= pMsgInfo->_nMsgType;
				pBtnInfo->_strMsgId		= pMsgInfo->_strMsgId;
				QPushButton*	pButton = new QPushButton(ui.MsgBtnWidget);
				pButton->setText(pBtnInfo->_strBtnName);
				pButton->setStyleSheet(
					"QPushButton{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:1,y2:0,stop:0 rgba(2,164,253,1),stop:1 rgba(31,139,237,1));"
					"border-radius:4px;font:14px \"微软雅黑\";color:rgba(255,255,255,1);padding-left:25px;padding-right:25px;}"
					"QPushButton:hover,pressed{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:1,y2:0,stop:0 rgba(40,178,253,1),stop:1 rgba(64,156,240,1));"
					"border-radius:4px;font:14px \"微软雅黑\";color:rgba(255,255,255,1);padding-left:25px;padding-right:25px;}"
					);
				pButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
				pButton->setFixedHeight(35);
				pButton->adjustSize();
				connect(pButton, SIGNAL(clicked()), this, SLOT(onMsgBtnClick()));
				m_mpBtnInfos[pButton] = pBtnInfo;
				pBoxLayout->addWidget(pButton);
			}
		}
	}
}

void MsgCenterWidget::releaseBtnInfo()
{
	std::map<QPushButton*, stMsgBtnInfo*>::iterator itr = m_mpBtnInfos.begin();
	for (; itr != m_mpBtnInfos.end();	++itr)
	{
		stMsgBtnInfo*	pBtnInfo = itr->second;
		if (NULL != pBtnInfo)
		{
			delete pBtnInfo;
			pBtnInfo = NULL;
		}
		QPushButton*	pButton = itr->first;
		if (NULL != pButton)
		{
			pButton->deleteLater();
			pButton = NULL;
		}
	}
	m_mpBtnInfos.clear();
}

void MsgCenterWidget::onMsgBtnClick()
{
	QDateTime	now = QDateTime::currentDateTime();
	if (m_dtLast.msecsTo(now) >= 1000)
	{
		m_dtLast = now;

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
		stMsgBtnInfo*	pBtnInfo = m_mpBtnInfos[pButton];
		if (NULL == pBtnInfo)
		{
			return;
		}

		switch (pBtnInfo->_nBtnType)
		{
		case 3:
		{
			//!弹出表单
			QString strUrl = QString("%1&user_id=%2&token=%3").arg(pBtnInfo->_strBtnTarget).arg(m_pNowMsgInfo->_strUid).arg(m_pNowMsgInfo->_strToken);
			MsgFormWidget*	pMsgFormWidget = new MsgFormWidget(strUrl, this);
			connect(pMsgFormWidget, SIGNAL(sigCommitStatue()), this, SLOT(onCommitStatue()));
			connect(pMsgFormWidget, SIGNAL(sigMsgFormClose()), this, SLOT(onMsgFormClose()));
			QPoint pt = ui.MsgBtnWidget->mapTo(this, pButton->pos());	
			pMsgFormWidget->setGeometry(x() + pt.x() + 5 + pButton->width() - pMsgFormWidget->width(), y() + pt.y() - pMsgFormWidget->height(), pMsgFormWidget->width(), pMsgFormWidget->height());
			pMsgFormWidget->show();
			break;
		}
		default:
			break;
		}
		sendMessageRespone(1, m_pNowMsgInfo->_strUid, m_pNowMsgInfo->_strToken, m_pNowMsgInfo->_strComId,m_pNowMsgInfo->_strMsgId, pBtnInfo->_strBtnId, pBtnInfo->_nBtnType, pBtnInfo->_strBtnTarget, true);
	}	
}

void MsgCenterWidget::onReduceUnreadNum()
{
	if (m_nUnreadCount>0)
	{
		m_nUnreadCount--;
	}
	QString strUnreadText = m_nUnreadCount > 99 ? QString::fromLocal8Bit("未读消息(99+)") : QString::fromLocal8Bit("未读消息(%1)").arg(m_nUnreadCount);
	ui.comboBox->setItemText(2, strUnreadText);

	emit sigReduceUnreadNum(m_nUnreadCount);
}

void MsgCenterWidget::openAssignMsg(QString strMsgid)
{
	for (int i = 0; i < ui.listWidget->count();i++)
	{
		QWidget*	pItemWidget = ui.listWidget->itemWidget(ui.listWidget->item(i));
		if (NULL == pItemWidget)
		{
			return;
		}
		MsgCenterItem* pMsgItem = dynamic_cast<MsgCenterItem*>(pItemWidget);
		if (NULL == pMsgItem)
		{
			return;
		}
		if (pMsgItem->getMsgId() == strMsgid)
		{
			pMsgItem->clickItem();
			ui.listWidget->setCurrentRow(i);
			break;
		}
	}	
}

void MsgCenterWidget::createMsgWidget()
{
	QVBoxLayout* pVBoxLayout1= new QVBoxLayout();
	m_pNoMsgWidget = new QWidget(ui.MsgRightBottomWidget);
	m_pNoMsgWidget->setStyleSheet("image:url(:/ZcloudMsgCenter/image/noContent.png);background-color:white;");
	m_pNoMsgWidget->hide();
	pVBoxLayout1->addWidget(m_pNoMsgWidget);

	m_pPicMsgWidget = new QWidget(ui.MsgRightBottomWidget);
	m_pPicMsgWidget->setStyleSheet("background-color:white;");

	m_pLabelImage = new QLabel(m_pPicMsgWidget);
	m_pLabelImage->installEventFilter(this);
	QVBoxLayout* pVBoxLayout = new QVBoxLayout();
	QHBoxLayout* pHBoxLayoutH1 = new QHBoxLayout();
	pHBoxLayoutH1->addStretch();
	pHBoxLayoutH1->addWidget(m_pLabelImage);
	pHBoxLayoutH1->addStretch();
	pVBoxLayout->addLayout(pHBoxLayoutH1);

	m_pPicMsgWidget->setLayout(pVBoxLayout);
	m_pPicMsgWidget->hide();
	pVBoxLayout1->addWidget(m_pPicMsgWidget);
	
	m_pNorMsgWidget  = new QWidget(ui.MsgRightBottomWidget);
	m_pNorMsgWidget->setStyleSheet("background-color:white;");

	QVBoxLayout* pVBoxLayout2 = new QVBoxLayout();

	m_pMsgTitle = new QLabel(m_pNorMsgWidget);
	m_pMsgTitle->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	m_pMsgTitle->setMinimumHeight(20);
	m_pMsgTitle->setMaximumHeight(40);
	m_pMsgTitle->setStyleSheet(QString::fromLocal8Bit("QLabel{font:16px \"微软雅黑\";font-weight:bold;color:#2E3041;}"));
	pVBoxLayout2->addWidget(m_pMsgTitle);

	m_pMsgTime = new QLabel(m_pNorMsgWidget);
	m_pMsgTime->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	m_pMsgTime->setFixedHeight(20);
	m_pMsgTime->setStyleSheet(QString::fromLocal8Bit("QLabel{font:12px \"微软雅黑\";color:#666666;}"));
	pVBoxLayout2->addWidget(m_pMsgTime);

	m_pSapce = new QLabel(m_pNorMsgWidget);
	m_pSapce->setFixedHeight(10);
	pVBoxLayout2->addWidget(m_pSapce);

	m_pMsgWebView = new QWebView(m_pNorMsgWidget);
	m_pMsgWebView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
	connect(m_pMsgWebView, SIGNAL(linkClicked(const QUrl &)), this, SLOT(onLinkClicked(const QUrl&)));
	connect(m_pMsgWebView->page(), SIGNAL(scrollRequested(int, int, const QRect &)), this, SLOT(onScrollRequested(int, int, const QRect &)));
	m_pMsgWebView->setContextMenuPolicy(Qt::NoContextMenu);
	QHBoxLayout* pHBoxLayoutH2 = new QHBoxLayout();
	pVBoxLayout2->addWidget(m_pMsgWebView);

	m_pNorMsgWidget->setLayout(pVBoxLayout2);
	m_pNorMsgWidget->hide();

	pVBoxLayout1->addWidget(m_pNorMsgWidget);
	pVBoxLayout1->setSpacing(0);
	ui.MsgRightBottomWidget->setLayout(pVBoxLayout1);
}

void MsgCenterWidget::showPicMsg(QString strPicPath)
{
	QString strPicDownloadPath;
	if (strPicPath.contains("http"))
	{
		strPicDownloadPath = ZcloudComFun::downloadPic(strPicPath, QApplication::applicationDirPath().append("/CacheImage/picMsgImage"));
		strPicPath = strPicDownloadPath;
	}
	if (strPicPath.isEmpty() || !QFile::exists(strPicPath))
	{
		m_pLabelImage->setFixedSize(100, 50);
		m_pLabelImage->setAlignment(Qt::AlignCenter);
		m_pLabelImage->setStyleSheet("QLabel#labelImage{font: 14px \"微软雅黑\";color:#666666;border-bottom-left-radius:0px;border-right:none;};");
		m_pLabelImage->setText(QString::fromLocal8Bit("图片资源加载失败"));
	}
	else
	{
		QFile file(strPicPath);
		file.open(QIODevice::ReadOnly);
		QPixmap pixmap;
		pixmap.loadFromData(file.readAll());
		file.close();

		QSize photoSize = pixmap.size();
		m_pLabelImage->setFixedSize(photoSize.width(), photoSize.height());

		QString strFix = strPicPath.mid(strPicPath.lastIndexOf("."));
		strFix = strFix.toUpper();
		if (strFix == ".GIF")
		{
			m_pLabelImage->setStyleSheet("");
			if (NULL == m_pMovieImage)
			{
				m_pMovieImage = new QMovie(m_pLabelImage);
			}
			m_pMovieImage->setFileName(strPicPath);
			m_pLabelImage->setMovie(m_pMovieImage);
			m_pMovieImage->start();
		}
		else
		{
			if (NULL != m_pMovieImage)
			{
				if (m_pMovieImage->state() == QMovie::Running)
				{
					m_pMovieImage->stop();
				}
			}
			m_pLabelImage->setPixmap(pixmap.scaled(photoSize.width(), photoSize.height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
		}
	}
}

void MsgCenterWidget::showNorMsg(const QString& strMsgTitle, const int& nSendTime, const QString& strMsgContent)
{
	m_pMsgTitle->setText(strMsgTitle);
	m_pMsgTitle->adjustSize();

	QDateTime time = QDateTime::fromTime_t(nSendTime);
	QString strSendTime = time.toString("yyyy-MM-dd hh:mm:ss");
	m_pMsgTime->setText(strSendTime);

	m_pMsgWebView->setHtml(strMsgContent);
}

void MsgCenterWidget::sendMessageRespone(int nResType, QString strUid, QString strToken, QString strCompId, QString strMsgId, QString strBtnId, int nBtnType, QString strBtnTarget, bool bRead, bool bFromPopUp)
{
	QStringList strTextList;
	strTextList << QString::number(nResType) << strUid << strToken << strCompId << strMsgId << strBtnId << QString::number(nBtnType) << strBtnTarget << QString::number(bRead) << QString::number(bFromPopUp);
	QString strText = strTextList.join("+");

	emit sigSendMessageRespone(strText);
}

void MsgCenterWidget::onCommitStatue()
{
	QObject*	pObj = sender();
	if (NULL == pObj)
	{
		return;
	}
	MsgFormWidget*	pWidget = qobject_cast<MsgFormWidget*>(pObj);
	if (NULL == pWidget)
	{
		return;
	}
	pWidget->close();
	ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("提交成功"), QString::fromLocal8Bit("您填写的信息已成功提交！"), this);
}

void MsgCenterWidget::onMsgFormClose()
{
	sendMessageRespone(2, m_pNowMsgInfo->_strUid, m_pNowMsgInfo->_strToken, m_pNowMsgInfo->_strComId,m_pNowMsgInfo->_strMsgId, "", 0, "", true);
}

void MsgCenterWidget::reduceUnreadNum()
{
	if (m_nUnreadCount > 0)
	{
		m_nUnreadCount--;
	}
	QString strUnreadText = m_nUnreadCount > 99 ? QString::fromLocal8Bit("未读消息(99+)") : QString::fromLocal8Bit("未读消息(%1)").arg(m_nUnreadCount);
	ui.comboBox->setItemText(2, strUnreadText);
}

void MsgCenterWidget::onScrollRequested(int dx, int dy, const QRect& rectToScroll)
{
	if (!m_bUpdateScroll)
	{
		sendMessageRespone(9, m_pNowMsgInfo->_strUid, m_pNowMsgInfo->_strToken, m_pNowMsgInfo->_strComId,m_pNowMsgInfo->_strMsgId, "", 0, "", true);
		m_bUpdateScroll = true;
	}
}
