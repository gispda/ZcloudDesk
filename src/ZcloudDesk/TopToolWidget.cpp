#include "TopToolWidget.h"
#include <QScrollBar>
#include <QGraphicsDropShadowEffect>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QToolButton>
#include "ZcloudDesk.h"
TopToolWidget::TopToolWidget(TopToolInfo* pInfo,QWidget *parent)
	:AppCommWidget("", true, parent)
	, m_pInfo(pInfo)
{
	ui.setupUi(m_widget);
	resize(396, 358);
	setObjectName("TopToolWidget");
	setWindowTitle(pInfo->_strToolName);
	ui.labelTilte->setText(pInfo->_strToolName);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setAttribute(Qt::WA_DeleteOnClose);
	setStyleSheet("outline: none");

	setVerScrollBarStyle();

	analysisAppArray();

	if (m_mpAppBtn.size()	==	1)
	{
		emit m_mpAppBtn.firstKey()->clicked();
	}
	else
	{
		show();
	}
}

TopToolWidget::~TopToolWidget()
{
	QMapIterator<QToolButton*, QString> i(m_mpAppBtn);
	while (i.hasNext()) 
	{
		QToolButton*	pBtn = i.next().key();
		if (NULL != pBtn)
		{
			pBtn->deleteLater();
			pBtn = NULL;
		}
	}
}

void TopToolWidget::mousePressEvent(QMouseEvent *event)
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

void TopToolWidget::mouseMoveEvent(QMouseEvent *event)
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

void TopToolWidget::setVerScrollBarStyle()
{
	ui.scrollArea->verticalScrollBar()->setStyleSheet("QScrollBar:vertical"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,0%);"
		"margin:0px,0px,0px,0px;"
		"padding-top:9px;"
		"padding-bottom:9px;"
		"}"
		"QScrollBar::handle:vertical"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,25%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::handle:vertical:hover"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,50%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::add-line:vertical"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/3.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:vertical"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/1.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-line:vertical:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/4.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:vertical:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/2.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical"
		"{"
		"background:rgba(0,0,0,10%);"
		"border-radius:4px;"
		"}"
		);
}

void TopToolWidget::analysisAppArray()
{
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(m_pInfo->_arryToolList, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray btnArray = parse_doucment.array();
			QLayout*		pLayout = ui.scrollAreaWidgetContents->layout();
			QGridLayout*	pBoxLayout = (QGridLayout*)pLayout;
			ZcloudDesk*		pDesk = qobject_cast<ZcloudDesk*>(parentWidget());
			for (int nIndex = 0; nIndex < btnArray.size(); ++nIndex)
			{
				QJsonObject child = btnArray.at(nIndex).toObject();
				QString strAppId  = child.take("app_id").toString();

				QString strAppName, strAppIcon;
				pDesk->getAppData(strAppId, strAppName, strAppIcon);
				QToolButton*   pp = new QToolButton(ui.scrollAreaWidgetContents);
				pp->setFixedSize(160, 100);
				pp->setText(strAppName);
				QIcon icon;
				icon.addFile(strAppIcon, QSize(), QIcon::Normal, QIcon::Off);
				pp->setIcon(icon);
				pp->setIconSize(QSize(56, 56));
				pp->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
				pp->setStyleSheet("QToolButton{border-image:url(:/ZcloudDesk/image/toolApp.png);padding-top:15px;}"
					"QToolButton:hover{border-image:url(:/ZcloudDesk/image/toolApp_hov.png);}"
					"QToolButton:pressed{border-image:url(:/ZcloudDesk/image/toolApp_hov.png);};");
				connect(pp, SIGNAL(clicked()), this, SLOT(onAppBtnClick()));
				pBoxLayout->addWidget(pp, nIndex / 2, nIndex % 2);

				m_mpAppBtn[pp] = strAppId;
			}
		}
	}
}

void TopToolWidget::onAppBtnClick()
{
	QMutexLocker	locker(&m_mutex);
	QObject*	pObj = sender();
	if (NULL == pObj)
	{
		return;
	}
	QToolButton*	pButton = qobject_cast<QToolButton*>(pObj);
	if (NULL == pButton)
	{
		return;
	}

	QString strAppId = m_mpAppBtn[pButton];
	ZcloudDesk*		pDesk = qobject_cast<ZcloudDesk*>(parentWidget());
	if (NULL == pDesk)
	{
		return;
	}
	pDesk->openApp(strAppId);
}
