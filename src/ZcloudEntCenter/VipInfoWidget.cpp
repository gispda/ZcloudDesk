#include "VipInfoWidget.h"
#include <QGraphicsDropShadowEffect>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QWebFrame>
#include <QDialog>
#include "ZcloudCommon.h"
#include "ZcloudBigData.h"
#include "JsInterface.h"

VipInfoWidget::VipInfoWidget(QString strUid, QString strToken, QString strUrl, QWidget *parent)
	: m_strUrl(strUrl),
	QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("��Ա����"));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowModality(Qt::WindowModal);
	setStyleSheet("outline: none");

	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
	//������Ӱ����
	shadow->setOffset(0, 0);
	//������Ӱ��ɫ
	shadow->setColor(QColor("#666666"));
	//������ӰԲ��
	shadow->setBlurRadius(8);
	//��Ƕ��QWidget������Ӱ
	this->setGraphicsEffect(shadow);

	m_pWebView = new WebView(ui.FilletWidget);
	m_pWebView->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
	m_pWebView->lower();
	m_pWebView->setGeometry(ui.FilletWidget->geometry());
	m_pWebView->setStyleSheet("border-radius:8px;");
	m_pWebView->load(QUrl::fromUserInput(m_strUrl));
	connect(m_pWebView, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished(bool)));
	connect(JsInterface::GetInstance(), SIGNAL(sigGetVipList(const QString&)), this, SLOT(onGetVipList(const QString&)));
	
	m_pCloseBtn = new QPushButton(ui.FilletWidget);
	m_pCloseBtn->setGeometry(1065, 5, 32, 28);
	m_pCloseBtn->setStyleSheet("QPushButton{border-image:url(:/EntCenterWidget/image/close.png);}"
		"QPushButton:hover,pressed{border-image:url(:/EntCenterWidget/image/close_sel.png);};");
	connect(m_pCloseBtn, &QPushButton::clicked, [this]()
	{
		disconnect();
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "VPC005");
		close();
	});
	connect(JsInterface::GetInstance(), SIGNAL(signalBindingPhone()), this, SLOT(vipWidgetBingdingPhone()));
}

VipInfoWidget::~VipInfoWidget()
{
	if (NULL != m_pCloseBtn)
	{
		m_pCloseBtn->deleteLater();
		m_pCloseBtn = NULL;
	}
}

void VipInfoWidget::vipWidgetBingdingPhone()
{
	//if (ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_BINDING, QString::fromLocal8Bit("���Ȱ��ֻ���"), QString::fromLocal8Bit("���ֻ��ź�,�������ܸ��๦��"),
	//	QString::fromLocal8Bit("��¼��"), QString::fromLocal8Bit("�´���˵")) == QDialog::Accepted)
	//{
		emit bingdingPhoneSignal();
	//}
}

void VipInfoWidget::mousePressEvent(QMouseEvent *event)
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

void VipInfoWidget::mouseMoveEvent(QMouseEvent *event)
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

void VipInfoWidget::showWindow(QString strUrl)
{
	m_pWebView->load(QUrl::fromUserInput(strUrl));
	showNormal();
}

void VipInfoWidget::onLoadFinished(bool)
{
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("JsInterface", (QObject*)JsInterface::GetInstance());
	disconnect(JsInterface::GetInstance(), SIGNAL(changeUserIdtokenSignal(const QString, const QString)), this, SLOT(getNewUserIdToken(const QString, const QString)));
	connect(JsInterface::GetInstance(), SIGNAL(changeUserIdtokenSignal(const QString, const QString)), this, SLOT(getNewUserIdToken(const QString, const QString)));
}

void VipInfoWidget::onGetVipList(const QString& strJson)
{
	//����ɹ�
	//����json����
	QStringList strListAppVipNameList;//vip�ȼ���������
	QStringList strListAppVipList;		//vip�ȼ�����
	QStringList strTimeList;
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
				strListAppVipNameList << appJsonObject.take("member_grade_name").toString();
				strListAppVipList << appJsonObject.take("member_grade_id").toString();
				strTimeList << QString::number(appJsonObject.take("member_end_time").toInt());
				//��Ա�ȼ�  member_grade  int����
			}
		}
		emit sendVipListSignals(strListAppVipNameList, strListAppVipList, strTimeList);
	}
}

void VipInfoWidget::getNewUserIdToken(const QString strUserId, const QString strToken)
{
	m_pWebView->page()->mainFrame()->evaluateJavaScript(QString("setNewUserIdToken('%1','%2')").arg(strUserId).arg(strToken));
}
