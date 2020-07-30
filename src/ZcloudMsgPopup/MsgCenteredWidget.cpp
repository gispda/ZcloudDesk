#include "MsgCenteredWidget.h"
#include <QGraphicsDropShadowEffect>
#include <QDateTime>
#include <QDesktopServices>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include "MsgFormWidget.h"
#include "ZcloudCommon.h"

MsgCenteredWidget::MsgCenteredWidget(stMsgInfo msgInfo, QWidget *parent)
	: QWidget(parent)
	, m_msgInfo(msgInfo)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("ϵͳ��Ϣ"));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground);
	setAttribute(Qt::WA_DeleteOnClose);
	setStyleSheet("outline: none");

	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
	//shadow->setBlurRadius(0.8);				//��Ӱģ����
	//������Ӱ����
	shadow->setOffset(0, 0);
	//������Ӱ��ɫ
	shadow->setColor(QColor("#666666"));
	//������ӰԲ��
	shadow->setBlurRadius(8);
	//��Ƕ��QWidget������Ӱ
	this->setGraphicsEffect(shadow);

	m_pClient = new NamePipeClinet;
	m_pClient->connectToServer("ZcloudMsgNamePipe");
	m_pClient->sendMessage(7, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, "", 0, "", true);
	m_pWebView = new QWebView(ui.MsgFilletWidget);
	m_pWebView->setContextMenuPolicy(Qt::NoContextMenu);
	m_pWebView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
	connect(m_pWebView, SIGNAL(linkClicked(const QUrl &)), this, SLOT(onLinkClicked(const QUrl&)));
	connect(m_pWebView->page(), SIGNAL(scrollRequested(int, int, const QRect &)), this, SLOT(onScrollRequested(int, int, const QRect &)));
	m_pWebView->show();
	m_pWebView->installEventFilter(this);

	m_dtLast = QDateTime::currentDateTime();
	init();
}

MsgCenteredWidget::~MsgCenteredWidget()
{

}
void MsgCenteredWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		dPos = event->globalPos() - pos();
		event->accept();
	}
}

void MsgCenteredWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - dPos);
		event->accept();
	}
}

void MsgCenteredWidget::init()
{
	ui.labelMsgTitle->setText(m_msgInfo._strMsgTitle);
	ui.labelMsgTitle->adjustSize();

	QDateTime time = QDateTime::fromTime_t(m_msgInfo._nSendTime);
	QString strSendTime = time.toString("yyyy-MM-dd hh:mm:ss");
	ui.labelTime->setText(strSendTime);

	m_pWebView->setHtml(m_msgInfo._strMsgContent);

	analysisBtnArray(m_msgInfo._arryBtnList);
}

void MsgCenteredWidget::paintEvent(QPaintEvent * event)
{
	if (NULL != m_pWebView)
	{
		QRect rect = ui.MsgContentWidget->geometry();
		m_pWebView->setGeometry(rect);
	}
	QWidget::paintEvent(event);
}

void MsgCenteredWidget::onLinkClicked(const QUrl& url)
{
	QDesktopServices::openUrl(url);
}

void MsgCenteredWidget::analysisBtnArray(QByteArray byteJsonArray)
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
							"QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"΢���ź�\";color:#333333;border:1px solid #DEDEDE;padding-left:25px;padding-right:25px;}"
							"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"΢���ź�\";color:#333333;padding-left:25px;padding-right:25px;}"
							);
						
					}
					else
					{
						pButton->setStyleSheet(
							"QPushButton{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:1,y2:0,stop:0 rgba(2,164,253,1),stop:1 rgba(31,139,237,1));"
							"border-radius:4px;font:14px \"΢���ź�\";color:rgba(255,255,255,1);padding-left:25px;padding-right:25px;}"
							"QPushButton:hover,pressed{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:1,y2:0,stop:0 rgba(40,178,253,1),stop:1 rgba(64,156,240,1));"
							"border-radius:4px;font:14px \"΢���ź�\";color:rgba(255,255,255,1);padding-left:25px;padding-right:25px;}"
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

void MsgCenteredWidget::onMsgBtnClick()
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
			m_pClient->sendMessage(1, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId,m_msgInfo._strMsgId, pBtnInfo->_strBtnId, pBtnInfo->_nBtnType, pBtnInfo->_strBtnTarget, false);
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
		else if (3 == pBtnInfo->_nBtnType)
		{
			QString strUrl = QString("%1&user_id=%2&token=%3").arg(pBtnInfo->_strBtnTarget).arg(m_msgInfo._strUid).arg(m_msgInfo._strToken);
			MsgFormWidget*	pMsgFormWidget = new MsgFormWidget(strUrl, this);
			connect(pMsgFormWidget, SIGNAL(sigCommitStatue()), this, SLOT(onCommitStatue()));
			connect(pMsgFormWidget, SIGNAL(sigMsgFormClose()), this, SLOT(onMsgFormClose()));
			QPoint pt = ui.MsgBtnWidget->mapTo(this, pButton->pos());
			pMsgFormWidget->setGeometry(x() + pt.x() +5 + pButton->width() - pMsgFormWidget->width(), y() + pt.y() - pMsgFormWidget->height(), pMsgFormWidget->width(), pMsgFormWidget->height());
			pMsgFormWidget->show();
		}
	}
}

void MsgCenteredWidget::onCommitStatue()
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
	ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("�ύ�ɹ�"), QString::fromLocal8Bit("����д����Ϣ�ѳɹ��ύ��"), this);
}

void MsgCenteredWidget::onMsgFormClose()
{
	m_pClient->sendMessage(2, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, "", 0, "", true);
}

void MsgCenteredWidget::onScrollRequested(int dx, int dy, const QRect& rectToScroll)
{
	if (!m_bUpdate)
	{
		m_pClient->sendMessage(9, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, "", 0, "", true);
		m_bUpdate = true;
	}	
}
