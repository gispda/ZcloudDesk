#include "ServiceFeeWidget.h"
#include <QGraphicsDropShadowEffect>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>

ServiceFeeWidget::ServiceFeeWidget(stMsgInfo msgInfo,QWidget *parent)
	: QWidget(parent)
	, m_msgInfo(msgInfo)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("服务费到期提醒"));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
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
	m_pClient->sendMessage(8, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, "", 0, "", true);

	init();

	m_dtLast = QDateTime::currentDateTime();
}

ServiceFeeWidget::~ServiceFeeWidget()
{

}
void ServiceFeeWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		dPos = event->globalPos() - pos();
		event->accept();
	}
}

void ServiceFeeWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - dPos);
		event->accept();
	}
}

void ServiceFeeWidget::setElideText(int nPixSize, QLabel* pLabel, const QString& strText)
{
	QFont font("Microsoft YaHei");
	font.setPixelSize(nPixSize);
	pLabel->setFont(font);
	QFontMetrics fontMetrics(pLabel->font());
	int fontWidth = fontMetrics.width(strText);//获取之前设置的字符串的像素大小
	int fontHeight = pLabel->height() / fontMetrics.height();	 //获取之前设置的字符串的像素大小
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
void ServiceFeeWidget::init()
{
	QString strText = m_msgInfo._strMsgTitle;
	if (strText.isEmpty())
	{
		strText = QString::fromLocal8Bit("服务费到期提醒");
	}
	ui.labelTilte->setText(strText);
	ui.labelContent->setText(m_msgInfo._strAbstruct);
	analysisBtnArray(m_msgInfo._arryBtnList);
}

void ServiceFeeWidget::analysisBtnArray(QByteArray byteJsonArray)
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
				QLayout*	pLayout = ui.MsgBtnWidget->layout();
				QBoxLayout*	pBoxLayout = (QBoxLayout*)pLayout;
				for (int nIndex = 0; nIndex < btnArray.size(); ++nIndex)
				{
					QJsonObject child = btnArray.at(nIndex).toObject();
					int nBtnType = child.take("btn_type").toInt();
					if (4 == nBtnType || 5 == nBtnType)
					{
						continue;
					}
					stMsgBtnInfo*	pBtnInfo = new stMsgBtnInfo;
					pBtnInfo->_strBtnId = child.take("btn_id").toString();
					pBtnInfo->_strBtnName = child.take("btn_name").toString();
					pBtnInfo->_nBtnType = nBtnType;
					pBtnInfo->_strBtnTarget = child.take("btn_target").toString();
					QPushButton*	pButton = new QPushButton(ui.MsgBtnWidget);
					pButton->setText(pBtnInfo->_strBtnName);
					if (0 == nBtnType)
					{
						pButton->setStyleSheet(
							"QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"微软雅黑\";color:#333333;border:1px solid #DEDEDE;padding-left:25px;padding-right:25px;}"
							"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"微软雅黑\";color:#333333;padding-left:25px;padding-right:25px;}"
							);

					}
					else
					{
						pButton->setStyleSheet(
							"QPushButton{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:1,y2:0,stop:0 rgba(2,164,253,1),stop:1 rgba(31,139,237,1));"
							"border-radius:4px;font:14px \"微软雅黑\";color:rgba(255,255,255,1);padding-left:25px;padding-right:25px;}"
							"QPushButton:hover,pressed{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:1,y2:0,stop:0 rgba(40,178,253,1),stop:1 rgba(64,156,240,1));"
							"border-radius:4px;font:14px \"微软雅黑\";color:rgba(255,255,255,1);padding-left:25px;padding-right:25px;}"
							);
					}
					pButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
					pButton->setFixedHeight(35);
					pButton->adjustSize();
					connect(pButton, SIGNAL(clicked()), this, SLOT(onMsgBtnClick()));
					pBoxLayout->addWidget(pButton);
					m_mpBtnInfos[pButton] = pBtnInfo;
				}
			}
		}
	}
}

void ServiceFeeWidget::onMsgBtnClick()
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
		if (!m_msgInfo._bIsRead)
		{
			m_pClient->sendMessage(1, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, pBtnInfo->_strBtnId, pBtnInfo->_nBtnType, pBtnInfo->_strBtnTarget, false);
			m_msgInfo._bIsRead = true;
		}
		else
		{
			m_pClient->sendMessage(1, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, pBtnInfo->_strBtnId, pBtnInfo->_nBtnType, pBtnInfo->_strBtnTarget, true);
		}

		if (0 == pBtnInfo->_nBtnType)
		{
			close();
		}
	}
}
