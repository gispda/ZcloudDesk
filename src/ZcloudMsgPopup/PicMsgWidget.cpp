#include "PicMsgWidget.h"
#include <QGraphicsDropShadowEffect>
#include <QJsonParseError>
#include <QJsonArray>
#include "..\ZcloudMsgCenter\MsgFormWidget.h"
#include "ZcloudCommon.h"
PicMsgWidget::PicMsgWidget(stMsgInfo msgInfo,QWidget *parent)
	: QWidget(parent)
	, m_msgInfo(msgInfo)
{
	ui.setupUi(this);

	setWindowTitle(QString::fromLocal8Bit("图片消息"));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground);
	setAttribute(Qt::WA_DeleteOnClose);
	setStyleSheet("outline: none");

	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
	//shadow->setBlurRadius(0.8);				//阴影模糊度
	//设置阴影距离
	shadow->setOffset(0, 0);
	//设置阴影颜色
	shadow->setColor(QColor("#666666"));
	//设置阴影圆角
	shadow->setBlurRadius(1);
	//给嵌套QWidget设置阴影
	this->setGraphicsEffect(shadow);

	m_pClient = new NamePipeClinet;
	m_pClient->connectToServer("ZcloudMsgNamePipe");
	m_pClient->sendMessage(5, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, "", 0, "", true);

	m_dtLast = QDateTime::currentDateTime();

	this->installEventFilter(this);

	ui.MsgBtnWidget->hide();

	init();
}

PicMsgWidget::~PicMsgWidget()
{
}

void PicMsgWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		dPos = event->globalPos() - pos();
		event->accept();
	}
}

void PicMsgWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - dPos);
		event->accept();
	}
}
bool PicMsgWidget::eventFilter(QObject *target, QEvent *e)
{
	if (target == this)
	{
		if (e->type() == QEvent::MouseButtonRelease)
		{
			QDateTime	now = QDateTime::currentDateTime();
			if (m_dtLast.msecsTo(now) >= 1000)
			{
				m_dtLast = now;
				if (!m_msgInfo._bIsRead)
				{
					m_pClient->sendMessage(3, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, "", m_msgInfo._nTargetType, m_msgInfo._strTarget, false);
					m_msgInfo._bIsRead = true;
				}
				else
				{
					m_pClient->sendMessage(3, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, "", m_msgInfo._nTargetType, m_msgInfo._strTarget, true);
				}
			}
		}
	}
	return QWidget::eventFilter(target, e);
}

void PicMsgWidget::init()
{
	m_pLabelImage = new QLabel(this);
	QString strImage = m_msgInfo._strMsgContent;
	if (strImage.isEmpty() || !QFile::exists(strImage))
	{
		close();
	}
	else
	{
		QFile file(strImage);
		file.open(QIODevice::ReadOnly);
		QPixmap pixmap;
		pixmap.loadFromData(file.readAll());
		file.close();

		QSize photoSize = pixmap.size();
		m_pLabelImage->setFixedSize(photoSize.width(), photoSize.height());

		QString strFix = strImage.mid(strImage.lastIndexOf("."));
		strFix = strFix.toUpper();
		if (strFix == ".GIF")
		{
			QMovie *movie = new QMovie(strImage);
			m_pLabelImage->setMovie(movie);
			movie->start();
		}
		else
		{
			m_pLabelImage->setPixmap(pixmap.scaled(photoSize.width(), photoSize.height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
		}
	}

	this->setFixedSize(m_pLabelImage->width(), m_pLabelImage->height() + 12 + 58 + 2);

	analysisBtnArray(m_msgInfo._arryBtnList);
}

void PicMsgWidget::onCloseBtnClick()
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
	close();
}

void PicMsgWidget::analysisBtnArray(QByteArray byteJsonArray)
{
	bool isHaveCloseButton = false;
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
				ui.MsgBtnWidget->setGeometry(0, m_pLabelImage->height() + 12, m_pLabelImage->width(), 58);
				ui.MsgBtnWidget->show();
				QLayout*	pLayout = ui.MsgBtnWidget->layout();
				QBoxLayout*	pBoxLayout = (QBoxLayout*)pLayout;
				for (int nIndex = 0; nIndex < btnArray.size(); ++nIndex)
				{
					QJsonObject child = btnArray.at(nIndex).toObject();
					int nBtnType = child.take("btn_type").toInt();
					if (5 == nBtnType || 0 == nBtnType)
					{
						continue;
					}
					stMsgBtnInfo*	pBtnInfo = new stMsgBtnInfo;
					pBtnInfo->_strBtnId		= child.take("btn_id").toString();
					pBtnInfo->_strBtnName	= child.take("btn_name").toString();
					pBtnInfo->_nBtnType		= nBtnType;
					pBtnInfo->_strBtnTarget = child.take("btn_target").toString();
					if (4 == nBtnType)
					{
						isHaveCloseButton = true;
						QPushButton* pButton = new QPushButton(this);
						pButton->setStyleSheet("QPushButton{border-image:url(:/ZcloudMsgPopup/image/msg_clos_nor.png);}"
							"QPushButton:hover,pressed{border-image:url(:/ZcloudMsgPopup/image/msg_close.png);};");
						pButton->setGeometry(m_pLabelImage->width() - 31, 1, 30, 30);
						connect(pButton, SIGNAL(clicked()), this, SLOT(onCloseBtnClick()));
						m_mpBtnInfos[pButton] = pBtnInfo;
						continue;
					}
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
					pBoxLayout->addWidget(pButton);
					m_mpBtnInfos[pButton] = pBtnInfo;
				}
			}
		}
	}

	if (!isHaveCloseButton)
	{
		stMsgBtnInfo*	closeBtnInfo = new stMsgBtnInfo;
		closeBtnInfo->_strBtnId = "-1";
		closeBtnInfo->_strBtnName = QString::fromLocal8Bit("关闭");
		closeBtnInfo->_nBtnType = 0;
		closeBtnInfo->_strBtnTarget = "0";

		QPushButton*	closeButton = new QPushButton(this);
		closeButton->setStyleSheet("QPushButton{border-image:url(:/ZcloudMsgPopup/image/msg_clos_nor.png);}"
			"QPushButton:hover,pressed{border-image:url(:/ZcloudMsgPopup/image/msg_close.png);};");
		closeButton->setGeometry(m_pLabelImage->width() - 31, 1, 30, 30);
		connect(closeButton, SIGNAL(clicked()), this, SLOT(onCloseBtnClick()));
		m_mpBtnInfos[closeButton] = closeBtnInfo;
	}
}

void PicMsgWidget::onMsgBtnClick()
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
		else if (3 == pBtnInfo->_nBtnType)
		{
			QString strUrl = QString("%1&user_id=%2&token=%3").arg(pBtnInfo->_strBtnTarget).arg(m_msgInfo._strUid).arg(m_msgInfo._strToken);
			MsgFormWidget*	pMsgFormWidget = new MsgFormWidget(strUrl, this);
			connect(pMsgFormWidget, SIGNAL(sigCommitStatue()), this, SLOT(onCommitStatue()));
			connect(pMsgFormWidget, SIGNAL(sigMsgFormClose()), this, SLOT(onMsgFormClose()));
			QPoint pt = ui.MsgBtnWidget->mapTo(this, pButton->pos());
			pMsgFormWidget->setGeometry(x() + pt.x() + 5 + pButton->width() - pMsgFormWidget->width(), y() + pt.y() - pMsgFormWidget->height(), pMsgFormWidget->width(), pMsgFormWidget->height());
			pMsgFormWidget->show();
		}
	}
}

void PicMsgWidget::onCommitStatue()
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

void PicMsgWidget::onMsgFormClose()
{
	m_pClient->sendMessage(2, m_msgInfo._strUid, m_msgInfo._strToken, m_msgInfo._strCompId, m_msgInfo._strMsgId, "", 0, "", true);
}
