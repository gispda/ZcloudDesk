#include "ZqtWidget.h"
#include <QDesktopServices>
#include <QNetworkReply>
#include <QNetworkProxyQuery>
#include <QNetworkAccessManager>
#include "bigData/BigDataInterface.h"

ZqtWidget::ZqtWidget(QString strId,QString strTitle, QString strComName, QString strUrl,QWidget *parent)
	: AppCommWidget(QString(""), 1, parent), m_strAppid(strId)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("ÕþÆóÍ¨"));

	ui.labelTitle->setText(strTitle);
	ui.labelName->setText(strComName);
	m_pWebView = new QWebView(this);
	m_pWebView->page()->setForwardUnsupportedContent(true);
	m_pWebView->setContextMenuPolicy(Qt::NoContextMenu);
	m_pWebView->setGeometry(0, 22, 965, 600);
	QNetworkAccessManager* pNetworkManager = m_pWebView->page()->networkAccessManager();
	QNetworkProxyQuery proxyQuery(QUrl::fromUserInput("https://www.baidu.com"));
	QList<QNetworkProxy> proxyList = QNetworkProxyFactory::systemProxyForQuery(proxyQuery);
	if (proxyList.count() > 0)
	{
		pNetworkManager->setProxy(proxyList.at(0));
	}
	m_pWebView->page()->setNetworkAccessManager(pNetworkManager);
	connect(m_pWebView->page(), SIGNAL(unsupportedContent(QNetworkReply*)), this, SLOT(unsupportedContent(QNetworkReply*)));
	connect(m_pWebView, SIGNAL(linkClicked(const QUrl &)), this, SLOT(onLinkClick(const QUrl&)));
	m_pWebView->setUrl(QUrl::fromUserInput(strUrl));
	m_pWebView->show();
	connect(ui.closeButton, &QPushButton::clicked, [this]()
	{
		BigDataInterface::GetInstance()->socketPost(QString("%1,%2,%3,%4").arg("M01").arg("OP001").arg("AAC013").arg(m_strAppid));
		this->close();
	});
}

ZqtWidget::~ZqtWidget()
{

}

void ZqtWidget::onLinkClick(const QUrl& url)
{
	QDesktopServices::openUrl(url);
}

void ZqtWidget::unsupportedContent(QNetworkReply* reply)
{
	QDesktopServices::openUrl(reply->url());
}