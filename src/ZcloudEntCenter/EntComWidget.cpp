#include "EntComWidget.h"
#include <QGraphicsDropShadowEffect>
#include <QWebFrame>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include "ZcloudBigData.h"
#include "JsInterface.h"
EntComWidget::EntComWidget(QString strTitle, QString strUrl, bool bBig, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(strTitle);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");
	setAttribute(Qt::WA_ShowModal, true);
	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
	//������Ӱ����
	shadow->setOffset(0, 0);
	//������Ӱ��ɫ
	shadow->setColor(QColor("#666666"));
	//������ӰԲ��
	shadow->setBlurRadius(8);
	//��Ƕ��QWidget������Ӱ
	this->setGraphicsEffect(shadow);

	ui.labelTitle->setText(strTitle);
	m_pWebView = new WebView(ui.FilletWidget);

	if (bBig)
	{
		resize(866, 606);
		m_pWebView->setGeometry(0, 50, 850, 540);
	}
	else
	{
		resize(866, 536);
		m_pWebView->setGeometry(0, 50, 850, 470);
	}
	
	m_pWebView->setStyleSheet("border-radius:8px;");
	m_pWebView->load(QUrl::fromUserInput(strUrl));
	connect(m_pWebView, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished(bool)));
	connect(JsInterface::GetInstance(), SIGNAL(sigGetVipList(const QString&)), this, SLOT(onGetVipList(const QString&)));
	connect(JsInterface::GetInstance(), SIGNAL(sigAccountSetSucessed(const QString&, const QString&)), this, SIGNAL(sigAccountSetSucessed(const QString&, const QString&)));
	connect(JsInterface::GetInstance(), SIGNAL(sigSignBindingSucceeded( const QString&)), this, SIGNAL(sigSignBindingSucceeded( const QString&)));
	connect(JsInterface::GetInstance(), SIGNAL(sigSignCompeteSucessed(bool,int)), this, SIGNAL(sigSignCompanySucessed(bool,int)));


	connect(ui.closeButton, &QPushButton::clicked, [this]()
	{
		closeWindow();
	});
}

EntComWidget::~EntComWidget()
{
}

void EntComWidget::mousePressEvent(QMouseEvent *event)
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

void EntComWidget::mouseMoveEvent(QMouseEvent *event)
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

void EntComWidget::closeWindow()
{
	QString strText = ui.labelTitle->text();
	if (strText == QString::fromLocal8Bit("�����Ա"))
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BFM009");
	}
	else if (strText == QString::fromLocal8Bit("�˺�����"))
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BAS024");
	}
	else if (strText == QString::fromLocal8Bit("��ҵ����"))
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBD009");
	}
	else if (strText == QString::fromLocal8Bit("������Ϣ"))
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BTR007");
	}
	else if (strText == QString::fromLocal8Bit("������ҵ"))
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BJC008");
	}
	close();
}

void EntComWidget::onLoadFinished(bool)
{
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("JsInterface", (QObject*)JsInterface::GetInstance());
}

void EntComWidget::onGetVipList(const QString& strJson)
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
