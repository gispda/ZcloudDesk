#include "ZBrowser.h"
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QDesktopServices>
#include <QNetworkReply>
#include <QSettings>
NetworkAccessManager *ZBrowser::s_networkAccessManager = 0;

ZBrowser::ZBrowser(QString strClassId, QString strAppId, QString url, QString titel, QWidget *parent)
	: QWidget(parent)
	, m_strClassId(strClassId)
	, m_strAppId(strAppId)
{
	ui.setupUi(this);
	resize(1136, 776);
	ui.name_label->setText(titel);

	//���ô���͸��WindowModal
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	//�����ޱ߿�
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
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

	//��һ�� Ϊ�� �޹رհ�ť
	ui.tabWidget->tabBar()->setTabText(0, "");

	ui.tabWidget->tabBar()->setTabButton(0, QTabBar::RightSide, NULL);

	connect(ui.tabWidget, &WebTabWidget::loadProgress, this, &ZBrowser::handleWebViewLoadProgress);
	connect(ui.tabWidget, &WebTabWidget::webActionEnabledChanged, this, &ZBrowser::handleWebActionEnabledChanged);

	connect(ui.tabWidget, SIGNAL(download(QNetworkReply*)),
		this, SLOT(downloadRequested(QNetworkReply*)));

	ui.tabWidget->setUrl(QUrl::fromUserInput(url));
}

ZBrowser::~ZBrowser()
{
	if (!s_networkAccessManager)
	{
		delete s_networkAccessManager;
		s_networkAccessManager = NULL;
	}
}


void ZBrowser::downloadRequested(QNetworkReply *reply)
{
	QDesktopServices::openUrl(reply->url());
	/*if(m_webDowloadManager == NULL)
	{
	m_webDowloadManager = new ZWebDowloadManager(this);
	}
	m_webDowloadManager->download(reply);
	m_webDowloadManager->show();*/
}

void ZBrowser::handleWebActionEnabledChanged(QWebPage::WebAction action, bool enabled)
{
	switch (action) {
	case QWebPage::Back:
		ui.backPushButton->setEnabled(enabled);
		break;
	case QWebPage::Forward:
		ui.forwardPushButton->setEnabled(enabled);
		break;
	case QWebPage::Reload:
		//ui.flushPushButton->setEnabled(enabled);
		break;
	case QWebPage::Stop:

		break;
	default:
		qWarning("Unhandled webActionChanged singal");
	}
}

void ZBrowser::handleWebViewLoadProgress(int progress)
{
	// static QIcon stopIcon(QStringLiteral(":process-stop.png"));
	//static QIcon reloadIcon(QStringLiteral(":view-refresh.png"));

	if (progress < 100 && progress > 0) {
		//������
		ui.flushPushButton->setStyleSheet("QPushButton{	border-image: url(:/Image/refresh_cancel_nor.png);}\
										  										  											QPushButton:hover,pressed{border-image: url(:/Image/refresh_cancel_hov.png);}");
		disconnect(ui.flushPushButton, SIGNAL(clicked()), this, SLOT(flushWeb()));
		connect(ui.flushPushButton, SIGNAL(clicked()), this, SLOT(stopFlushWeb()));
		ui.flushPushButton->setToolTip(QString::fromLocal8Bit("ֹͣ���ش�ҳ"));
	}
	else {
		//�������
		ui.flushPushButton->setStyleSheet("QPushButton{	border-image: url(:/Image/refresh_nor.png);}\
										  										  											QPushButton:hover,pressed{border-image: url(:/Image/refresh_hov.png);}");
		disconnect(ui.flushPushButton, SIGNAL(clicked()), this, SLOT(stopFlushWeb()));
		connect(ui.flushPushButton, SIGNAL(clicked()), this, SLOT(flushWeb()));
		ui.flushPushButton->setToolTip(QString::fromLocal8Bit("���¼��ش�ҳ"));
	}
	ui.progressBar->setValue(progress < 100 ? progress : 0);
}


//WebTabWidget* ZBrowser::tabWidget()
//{
//	return ui.tabWidget;
//}

//ֹͣ����
void ZBrowser::stopFlushWeb()
{
	ui.tabWidget->triggerWebPageAction(QWebPage::WebAction(QWebPage::Stop));
}
//ˢ��
void ZBrowser::flushWeb()
{
	ui.tabWidget->triggerWebPageAction(QWebPage::WebAction(QWebPage::Reload));
}

//���
void ZBrowser::on_backPushButton_clicked()
{
	ui.tabWidget->triggerWebPageAction(QWebPage::Back);
}

//��ǰ
void ZBrowser::on_forwardPushButton_clicked()
{
	ui.tabWidget->triggerWebPageAction(QWebPage::Forward);

}

void ZBrowser::on_maxPushButton_clicked()
{
	if (!this->isMaximized())
	{
		this->layout()->setMargin(0);
		this->showMaximized();
		ui.maxPushButton->setStyleSheet("QPushButton{border-image: url(:/Image/browser_nomal_nor.png);}\
																				QPushButton:hover,pressed{border-image: url(:/Image/browser_nomal_hov.png);}"
																				);
	}
	else
	{
		this->layout()->setMargin(8);
		this->showNormal();
		ui.maxPushButton->setStyleSheet("QPushButton{border-image: url(:/Image/browser_max_nor.png);}\
																				QPushButton:hover,pressed{border-image: url(:/Image/browser_max_hov.png);}"
																				);
	}
}

void ZBrowser::on_miniPushButton_clicked()
{
	this->showMinimized();
}



void ZBrowser::on_closePushButton_clicked()
{
	ui.tabWidget->clostTabAll();
	QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacityWeb");
	animation->setDuration(200);
	animation->setStartValue(1);
	animation->setEndValue(0);
	animation->start();
	connect(animation, SIGNAL(finished()), this, SLOT(close()));
}

NetworkAccessManager * ZBrowser::networkAccessManager()
{
	if (!s_networkAccessManager) {
		s_networkAccessManager = new NetworkAccessManager();

		//------------------------ע���������ô���---------------------------------//

		//s_networkAccessManager->setCookieJar(new CookieJar);
	}
	return s_networkAccessManager;
}

void ZBrowser::mouseDoubleClickEvent(QMouseEvent * event)
{
	on_maxPushButton_clicked();

}

void ZBrowser::mousePressEvent(QMouseEvent *event)
{
	if (event->globalPos().y() < (this->pos().y() + 40))
	{
		this->windowPos = this->pos();            // ��ò�����ǰλ��
		this->mousePos = event->globalPos();     // ������λ��
		this->dPos = mousePos - windowPos;       // �ƶ��󲿼����ڵ�λ��
	}
	return QWidget::mousePressEvent(event);
}

void ZBrowser::mouseMoveEvent(QMouseEvent *event)
{
	if (event->globalPos().y() < (this->pos().y() + 40))
	{
		this->move(event->globalPos() - this->dPos);
	}
	return QWidget::mouseMoveEvent(event);
}


