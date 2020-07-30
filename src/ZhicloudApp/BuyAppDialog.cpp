#include "BuyAppDialog.h"
#include <QDesktopWidget>
#include "ZcloudCommon.h"
#include "ZcloudBigData.h"
#include <QApplication>
#include <QNetworkReply>
#include <QScrollBar>
#include <QtWebKitWidgets/QWebFrame>
#include <QtWebKitWidgets/QWebPage>
#include <QPushButton>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDesktopServices>
#include "AppDatabase/AppCenterDatabase.h"
#include "JsInterface.h"

BuyAppDialog::BuyAppDialog(QString appId, QString strUserId, QString strToken, bool isBuyApp, QString strUrl, QWidget *parent)
	: AppCommDialog(parent)
	, m_isBuyApp(isBuyApp)
{
	this->resize(786, 616);
	closeButton = new QPushButton(m_widget);
	closeButton->setStyleSheet("QPushButton{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_nor.png);}"
		"QPushButton:hover{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_hov.png);}"
		"QPushButton:pressed{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_hov.png);};");
	closeButton->setGeometry( 734, 5, 32, 28);
	connect(closeButton, &QPushButton::clicked, [this]()
	{
		//购买成功
		this->close();
	});
	m_pWebView = new QWebView(m_widget);
	m_pWebView->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
	connect(m_pWebView->page()->networkAccessManager(),
		&QNetworkAccessManager::sslErrors,
		[this](QNetworkReply* reply, const QList<QSslError> &)
	{
		reply->ignoreSslErrors();
	}
	);
	connect(m_pWebView, SIGNAL(loadFinished(bool)),	this, SLOT(loadFinished()));
	m_pWebView->setStyleSheet("border-radius:4px;");
	m_pWebView->setGeometry(0,0, 772, 600);

	m_pWebView->setUrl(QUrl::fromUserInput(strUrl));

	QDesktopWidget* desktop = QApplication::desktop(); 
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	closeButton->raise();

}

BuyAppDialog::~BuyAppDialog()
{
	if (NULL != m_pWebView)
	{
		m_pWebView->stop();
		m_pWebView->close();
		m_pWebView->deleteLater();
	}
}

void BuyAppDialog::mousePressEvent(QMouseEvent *event)
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

void BuyAppDialog::mouseMoveEvent(QMouseEvent *event)
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

void BuyAppDialog::buyStatusChangeSlot(QString appId, int expireDateInt, bool status, QString strMd5)
{
	// 购买应用
	QString key = "ed186a5e0dd54b1e8f0307c9b2e9b253";
	
	QString keyStr = appId + QString::number(expireDateInt) + key;
	QByteArray ba = QCryptographicHash::hash(keyStr.toUtf8(), QCryptographicHash::Md5);
	QString hMd5 = ba.toHex().constData();
	if (strMd5 == hMd5)
	{
		if (status)
		{
			//购买成功
			if (m_isBuyApp)
			{
				//更改应用到期时间
				if (AppCenterDatabase::instance()->updateAppPaidTime(appId, expireDateInt, true))
				{
					this->accept();
					return;
				}
				else
				{
					//插入数据失败
					this->reject();
				}
			}
			else
			{
				//更改会员到期时间
				//{
				//	this->accept();
				//	return;
				//}
				//else
				//{
				//	//插入数据失败
				//	this->reject();
				//}
			}
		
		}
		else
		{
			//购买失败
			this->reject();
		}
	}
	else
	{
		//非法数据
	}
}

void BuyAppDialog::loadFinished()
{
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("BuyAppDialog", this);
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("JsInterface", this);
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("buyVipSlot", this);
	disconnect(JsInterface::GetInstance(), SIGNAL(changeUserIdtokenSignal(const QString, const QString)), this, SLOT(getNewUserIdToken(const QString, const QString)));
	connect(JsInterface::GetInstance(), SIGNAL(changeUserIdtokenSignal(const QString, const QString)), this, SLOT(getNewUserIdToken(const QString, const QString)));
}

void BuyAppDialog::closeBuySlot()
{
	this->close();
}


void BuyAppDialog::notBuy()
{
	isOpen = true;
	this->done(3);
}

void BuyAppDialog::getVipList(const QString& strJson)
{
	//带处理 是否返回所有已购买的会员（有可能返回的是当前购买的会员）
	QByteArray byte_array = strJson.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (parse_doucment.isArray())
		{
			QJsonArray data = parse_doucment.array();
			int nSize = data.size();
			for (int nIndex = 0; nIndex < nSize; ++nIndex)
			{
				QJsonObject appJsonObject = data.at(nIndex).toObject();
				m_strListAppVipNameList << appJsonObject.take("member_grade_name").toString();
				m_strListAppVipList << appJsonObject.take("member_grade_id").toString();
				m_strEndTimeList << QString::number(appJsonObject.take("member_end_time").toInt());
				//会员等级  member_grade  int类型
			}
		}
	}
	this->accept();
}

void BuyAppDialog::slotChangeWindowsSize(const bool &isMaxSize)
{
	if (isMaxSize)
	{
		this->resize(1116, 696);
		m_pWebView->setGeometry(0, 0, 772 + 334, 680);
		closeButton->setGeometry(720 + 334, 5, 32, 28);
	}
	else
	{
		this->resize(772, 616);
		m_pWebView->setGeometry(0, 0, 772, 600);
		closeButton->setGeometry(720, 5, 32, 28);

	}
	update();
	return;
}

void BuyAppDialog::slotOpenDefaultWeb(const QString &strUrl)
{
	QDesktopServices::openUrl(QUrl::fromUserInput(strUrl));
}

void BuyAppDialog::slotBindingPhone()
{
	//绑定手机号
	this->done(2);
}

void BuyAppDialog::getNewUserIdToken(const QString strUserId, const QString strToken)
{
	m_pWebView->page()->mainFrame()->evaluateJavaScript(QString("setNewUserIdToken('%1','%2')").arg(strUserId).arg(strToken));
}

