#include "ActivityWidget.h"
#include <QDesktopWidget>
#include <QApplication>
ActivityWidget::ActivityWidget(QString strUid, QString strToken, QString strCompId, QString strAvId, QString strTitle, QWidget *parent)
	: QWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
	, m_strAvId(strAvId)
	, m_strCompId(strCompId)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("最新活动"));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground);
	setAttribute(Qt::WA_DeleteOnClose);
	setStyleSheet("outline: none");

	m_pClient = new NamePipeClinet;
	m_pClient->connectToServer("ZcloudMsgNamePipe");

	ui.pushButton->setText(strTitle);
	ui.pushButton->adjustSize();
	adjustSize();
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onActivittyBtnClick()));

	QDesktopWidget *deskWgt = QApplication::desktop();
	QRect availableRect = deskWgt->availableGeometry();
	int nAvailableWidth = availableRect.width();
	int nWidth = rect().width();
	setGeometry(nAvailableWidth - nWidth, 30 + 5, nWidth, 26);
	connect(deskWgt, &QDesktopWidget::workAreaResized, [this](int)
	{
		QDesktopWidget *deskWgt = QApplication::desktop();
		QRect availableRect = deskWgt->availableGeometry();
		int nAvailableWidth = availableRect.width();
		int nWidth = rect().width();
		setGeometry(nAvailableWidth - nWidth, 30 + 5, nWidth, 26);
	});
}

ActivityWidget::~ActivityWidget()
{
}

void ActivityWidget::onActivittyBtnClick()
{
	m_pClient->sendMessage(4, m_strUid, m_strToken, m_strCompId,m_strAvId, "", -1, "", true);
}
