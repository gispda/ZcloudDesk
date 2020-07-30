#include "MsgCenterItem.h"
#include "MsgDataBase.h"
#include <QDateTime>
#include <QDialog>
#include "ZcloudBigData.h"
#include "ZcloudCommon.h"
MsgCenterItem::MsgCenterItem(stMsgInfo* pMsgInfo, QListWidgetItem* pListWidgetItem,	QWidget *parent)
	: QWidget(parent)
	, m_pMsgInfo(pMsgInfo)
	, m_pListWidgetItem(pListWidgetItem)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Widget);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");

	setElideText(14,ui.labelTitle, m_pMsgInfo->_strMsgTitle);
	ui.labelTitle->setToolTip(m_pMsgInfo->_strMsgTitle);
	setElideText(13,ui.labelContent, m_pMsgInfo->_strAbstruct);

	QDate dateBegin = QDate::currentDate();
	QDateTime dateTimeBegin(dateBegin);
	QDate dateEnd = dateBegin.addDays(1);
	QDateTime dateTimeEnd(dateEnd);
	QDateTime time = QDateTime::fromTime_t(pMsgInfo->_nSendTime);
	QString strSendTime;
	if (time >= dateTimeBegin	&&	time <= dateTimeEnd)
	{
		strSendTime = time.toString("hh:mm");
	}
	else
	{
		strSendTime  = time.toString("yy/MM/dd");
	}
	ui.labelTime->setText(strSendTime);
	ui.labelTime->adjustSize();
	ui.delMsgButton->hide();

	setIcon();

	connect(ui.delMsgButton, SIGNAL(clicked()), this, SLOT(onDeleteBtnClick()));
	this->installEventFilter(this);
}

MsgCenterItem::~MsgCenterItem()
{
	if (NULL != m_pMsgInfo)
	{
		delete m_pMsgInfo;
		m_pMsgInfo = NULL;
	}
}

void MsgCenterItem::setElideText(int nPixSize,QLabel* pLabel, const QString& strText)
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
	strElideText = strElideText.simplified();
	pLabel->setText(strElideText);
}

void MsgCenterItem::setIcon()
{
	if (!m_pMsgInfo->_bIsRead)
	{
		ui.labelIcon->setFixedSize(19, 17);
		switch (m_pMsgInfo->_nMsgType)
		{
		case 1:
		case 2:
			{
				ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudMsgCenter/image/sys_msg_un.png);");
				break;
			}
		case 3:
			{
				ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudMsgCenter/image/back_msg_un.png);");
				break;
			}
		case 4:
			{
				ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudMsgCenter/image/fee_msg_un.png);");
				break;
			}
		default:
			{
				ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudMsgCenter/image/sys_msg_un.png);");
				break;
			}
		}
	}
	else
	{
		ui.labelIcon->setFixedSize(16, 16);
		switch (m_pMsgInfo->_nMsgType)
		{
			case 1:
			case 2:
			{
				ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudMsgCenter/image/sys_msg.png);");
				break;
			}
			case 3:
			{
				ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudMsgCenter/image/back_msg.png);");
				break;
			}
			case 4:
			{
				ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudMsgCenter/image/fee_msg.png);");
				break;
			}
			default:
			{
				ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudMsgCenter/image/sys_msg.png);");
				break;
			}
		}
	}
}

bool MsgCenterItem::eventFilter(QObject *target, QEvent *e)
{
	if (target == this)
	{
		if (e->type() == QEvent::Enter) //
		{
			ui.delMsgButton->show();
		}
		else if (e->type() == QEvent::Leave)
		{
			ui.delMsgButton->hide();
		}
		else if (e->type() == QEvent::MouseButtonRelease)
		{
			clickItem();
		}
	}
	return QWidget::eventFilter(target, e);
}

void MsgCenterItem::clickItem()
{
	bool bRead = true;
	if (!m_pMsgInfo->_bIsRead)
	{
		bRead = false;
		m_pMsgInfo->_bIsRead = true;
		MsgDataBase::GetInstance()->changeMsgState(m_pMsgInfo->_strMsgId);
		setIcon();
		//emit sigReduceUnreadNum();
	}
	QString strNotes = QString("%1-%2").arg(m_pMsgInfo->_strMsgId).arg(m_pMsgInfo->_nMsgType);
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TME002", strNotes);
	emit sigClickItem(m_pMsgInfo, bRead);
}

void MsgCenterItem::onDeleteBtnClick()
{
	if (NULL == m_pMsgInfo)
	{
		return;
	}
	if (QDialog::Accepted == ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("确认删除此条消息？")))
	{
		QString strNotes = QString("%1-%2").arg(m_pMsgInfo->_strMsgId).arg(m_pMsgInfo->_nMsgType);
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TME003", strNotes);
		emit sigDeleteItem(m_pMsgInfo->_strMsgId);
	}	
}

QListWidgetItem* MsgCenterItem::getListItem()
{
	return m_pListWidgetItem;
}

QString MsgCenterItem::getMsgId()
{
	return m_pMsgInfo->_strMsgId;
}
