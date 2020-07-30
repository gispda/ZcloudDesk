#include "MsgRightWidget.h"
#include <QGraphicsDropShadowEffect>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QDesktopWidget>
MsgRightWidget::MsgRightWidget(stMsgInfo msgInfo, QWidget *parent)
	: QWidget(parent)
	, m_msgInfo(msgInfo)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setAttribute(Qt::WA_DeleteOnClose);
	setStyleSheet("outline: none");

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

	m_pClient = new NamePipeClinet;
	m_pClient->connectToServer("ZcloudMsgNamePipe");
	

	QString strTitle;
	if (1	==	m_msgInfo._nMsgType)
	{
		strTitle = QString::fromLocal8Bit("系统消息");
		m_pClient->sendMessage(6, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, "", 0, "", true);
	}
	else if (3 == m_msgInfo._nMsgType)
	{
		strTitle = QString::fromLocal8Bit("意见反馈回复");
		m_pClient->sendMessage(6, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, "", 0, "", true);
	}
	else if (4 == m_msgInfo._nMsgType)
	{
		strTitle = QString::fromLocal8Bit("服务费到期提醒");
		m_pClient->sendMessage(8, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, "", 0, "", true);
	}
	setWindowTitle(strTitle);
	ui.labelTilte->setText(strTitle);

	init();

	connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(onCloseBtnClick()));
	connect(ui.moreButton, SIGNAL(clicked()), this, SLOT(onMoreBtnClick()));

	QDesktopWidget* desktopWidget = QApplication::desktop();
	m_deskRect = desktopWidget->availableGeometry();
	move(m_deskRect.right() - 416, m_deskRect.bottom() - 266);
}

MsgRightWidget::~MsgRightWidget()
{

}

void MsgRightWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		dPos = event->globalPos() - pos();
		event->accept();
	}
}

void MsgRightWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - dPos);
		event->accept();
	}
}

void MsgRightWidget::onCloseBtnClick()
{
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
	if (!m_msgInfo._bIsRead)
	{
		m_pClient->sendMessage(1, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, pBtnInfo->_strBtnId, pBtnInfo->_nBtnType, pBtnInfo->_strBtnTarget, false);
		m_msgInfo._bIsRead = true;
	}
	else
	{
		m_pClient->sendMessage(1, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, pBtnInfo->_strBtnId, pBtnInfo->_nBtnType, pBtnInfo->_strBtnTarget, true);
	}
	m_bAutoClose = true;
	closeWindow();
}

void MsgRightWidget::onMoreBtnClick()
{
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
	if (!m_msgInfo._bIsRead)
	{
		m_pClient->sendMessage(1, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, pBtnInfo->_strBtnId, pBtnInfo->_nBtnType, pBtnInfo->_strBtnTarget, false);
		m_msgInfo._bIsRead = true;
	}
	else
	{
		m_pClient->sendMessage(1, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, pBtnInfo->_strBtnId, pBtnInfo->_nBtnType, pBtnInfo->_strBtnTarget, true);
	}
	m_bAutoClose = true;
	closeWindow();
}

void MsgRightWidget::init()
{
	setElideText(18, ui.labelMsgTilte, m_msgInfo._strMsgTitle); 

	QString strText = m_msgInfo._strAbstruct;
	strText = strText.simplified();
	if (strText.length()>90)
	{
		strText = strText.left(90) + "...";
	}
	ui.labelMsgContent->setText(strText);
	analysisBtnArray(m_msgInfo._arryBtnList);
}

void MsgRightWidget::analysisBtnArray(QByteArray byteJsonArray)
{
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byteJsonArray, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray btnArray = parse_doucment.array();
			if (0 == btnArray.size())
			{
				return;
			}
			else
			{
				for (int nIndex = 0; nIndex < btnArray.size(); ++nIndex)
				{
					QJsonObject child = btnArray.at(nIndex).toObject();
					int nBtnType = child.take("btn_type").toInt();
					if (1 == nBtnType || 2 == nBtnType || 3 == nBtnType || 0 == nBtnType)
					{
						continue;
					}
					stMsgBtnInfo*	pBtnInfo = new stMsgBtnInfo;
					pBtnInfo->_strBtnId = child.take("btn_id").toString();
					pBtnInfo->_strBtnName = child.take("btn_name").toString();
					pBtnInfo->_nBtnType = nBtnType;
					pBtnInfo->_strBtnTarget = child.take("btn_target").toString();

					if (4 == nBtnType)
					{
						m_mpBtnInfos[ui.closeButton] = pBtnInfo;
						continue;
					}
					else if (5 == nBtnType)
					{
						QString strText = pBtnInfo->_strBtnName;
						if (strText.isEmpty())
						{
							strText = QString::fromLocal8Bit("查看更多");
						}
						ui.moreButton->setText(strText);
						ui.moreButton->adjustSize();
						m_mpBtnInfos[ui.moreButton] = pBtnInfo;
						continue;
					}
					else if (6 == nBtnType)
					{
						QString strText = pBtnInfo->_strBtnName;
						if (strText.isEmpty())
						{
							strText = QString::fromLocal8Bit("立即续费");
						}
						ui.moreButton->setText(strText);
						ui.moreButton->adjustSize();
						m_mpBtnInfos[ui.moreButton] = pBtnInfo;
						continue;
					}
				}
			}
		}
	}
}

void MsgRightWidget::setElideText(int nPixSize, QLabel* pLabel, const QString& strText)
{
	QFont font("Microsoft YaHei");
	font.setPixelSize(nPixSize);
	pLabel->setFont(font);
	QFontMetrics fontMetrics(pLabel->font());
	int fontWidth = fontMetrics.width(strText);//获取之前设置的字符串的像素大小
	int fontHeight = pLabel->height()/ fontMetrics.height();	 //获取之前设置的字符串的像素大小
	QString strElideText;
	if (fontWidth > fontHeight*pLabel->width())
	{
		strElideText = fontMetrics.elidedText(strText, Qt::ElideRight, fontHeight*pLabel->width());//返回一个带有省略号的字符串
	}
	else
	{
		strElideText = strText;
	}
	pLabel->setText(strElideText);
}

void MsgRightWidget::closeWindow()
{
	if (m_bAutoClose)
	{
		m_closeTimer = new QTimer();
		connect(m_closeTimer, SIGNAL(timeout()), this, SLOT(widgetClose()));
		m_closeTimer->start(10);
	}
}

void MsgRightWidget::widgetShow()
{
	m_nCurHeight += 10;
	if (m_nCurHeight >= 266)
	{
		m_showTimer->stop();
	}
	move(m_deskRect.right() - 416, m_deskRect.bottom() - m_nCurHeight);
	show();
	raise();
}

void MsgRightWidget::widgetClose()
{
	m_nCurHeight -= 10;
	if (m_nCurHeight <= 0)
	{
		close();
		m_closeTimer->stop();
		return;
	}
	move(m_deskRect.right() - 416, m_deskRect.bottom() - m_nCurHeight);
	show();
}

void MsgRightWidget::showWindow()
{
	m_showTimer = new QTimer();
	connect(m_showTimer, SIGNAL(timeout()), this, SLOT(widgetShow()));
	m_showTimer->start(10);
}
