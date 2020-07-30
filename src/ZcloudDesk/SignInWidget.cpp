#include "SignInWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QtConcurrent/QtConcurrentRun>
#include <QFileInfo>
#include <QDesktopServices>
#include <QToolTip>
#include <QMouseEvent>

SignInWidget::SignInWidget(QString strUid, QString strToken,QWidget *parent)
	: ZcloudCommonWidget(parent)
	, m_strUid(strUid)
	, m_strToken(strToken)
{
	ui.setupUi(getContentWidget());
	resize(460, 523);
	setObjectName("SignInWidget");
	setWindowTitle(QString::fromLocal8Bit("Ç©µ½"));
	setAttribute(Qt::WA_ShowModal, true);
	setAttribute(Qt::WA_DeleteOnClose);

	connect(ui.closeButton, &QPushButton::clicked, [this]()
	{
		close();
	});
	connect(ui.signInButton, &QPushButton::clicked, this, &SignInWidget::signInBtnClick);
	
	ui.labelPic->installEventFilter(this);

	ui.label_12->hide();
	ui.label_11->hide();
	ui.label_10->hide();
	ui.label_9->hide();

	if (!showDetails())
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("´ò¿ªÊ§°Ü"), QString::fromLocal8Bit("Çë¼ì²éÄúµÄÍøÂçÁ´½Ó£¡"));
		close();
	}
}

SignInWidget::~SignInWidget()
{
}

void SignInWidget::signInBtnClick()
{
	QString strRet;
	if (!winHttpDoSign(m_strUid, m_strToken, strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("Ç©µ½Ê§°Ü"), QString::fromLocal8Bit("Ç©µ½Ê§°Ü£¬ÇëÉÔºóÔÙÊÔ£¡"));
		return;
	}
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return ;
	}
	if (!parse_doucment.isObject())
	{
		return ;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("status").toInt();

	if (status == 0)
	{
		QJsonObject data = obj.take("data").toObject();
		int nSignDay = data.take("current_month_sign_count").toInt();
		int nBasicReward = data.take("basic_reward").toInt();
		int nExtraReward = data.take("extra_reward").toInt();

		SignInTipWidget signInTipWidget(nBasicReward, nExtraReward, nSignDay, this);
		signInTipWidget.exec();
	
		ui.labelDay->setText(QString("%1").arg(nSignDay));
		if (nSignDay >= 5)
		{
			ui.label_line1->setStyleSheet("background-color: rgb(242,186,22);");
			ui.label_round1->setStyleSheet("border-image: url(:/ZcloudDesk/image/round_sel.png);");
			ui.label_9->show();
		}
		if (nSignDay >= 10)
		{
			ui.label_line2->setStyleSheet("background-color: rgb(242,186,22);");
			ui.label_round2->setStyleSheet("border-image: url(:/ZcloudDesk/image/round_sel.png);");
			ui.label_10->show();
		}
		if (nSignDay >= 15)
		{
			ui.label_line3->setStyleSheet("background-color: rgb(242,186,22);");
			ui.label_round3->setStyleSheet("border-image: url(:/ZcloudDesk/image/round_sel.png);");
			ui.label_11->show();
		}
		if (nSignDay >= 20)
		{
			ui.label_line4->setStyleSheet("background-color: rgb(242,186,22);");
			ui.label_round4->setStyleSheet("border-image: url(:/ZcloudDesk/image/gift_sel.png);");
			ui.label_12->show();
		}

		m_nCoinCount = m_nCoinCount + nBasicReward + nExtraReward;
		ui.labelCoin->setText(QString("%1").arg(m_nCoinCount));

		ui.signInButton->setText(QString::fromLocal8Bit("ÒÑÇ©µ½"));
		ui.signInButton->setEnabled(false);
		
		emit modifyCoinCount(m_nCoinCount);
	}
	else if (30028 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("Ç©µ½Ê§°Ü"), QString::fromLocal8Bit("ÄúÒÑÔÚ±ð´¦Ç©µ½£¬ÇëÎðÖØ¸´²Ù×÷£¡"));
	}
	else
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("Ç©µ½Ê§°Ü"), QString::fromLocal8Bit("Ç©µ½Ê§°Ü£¬ÇëÉÔºóÔÙÊÔ£¡"));
	}	
}

bool SignInWidget::winHttpSignInDetails(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/v2/sign/index?user_id=%1&token=%2").arg(strUid).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

bool SignInWidget::showDetails()
{
	QString strRet;
	if (!winHttpSignInDetails(m_strUid, m_strToken, strRet))
	{
		return false;
	}
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return false;
	}
	if (!parse_doucment.isObject())
	{
		return false;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("status").toInt();

	if (status != 0)
	{
		return false;
	}

	QJsonObject data	= obj.take("data").toObject();
	int nSignCount		= data.take("sign_count").toInt();
	ui.labelDay->setText(QString("%1").arg(nSignCount));
	if (nSignCount>=5)
	{
		ui.label_line1->setStyleSheet("background-color: rgb(242,186,22);");
		ui.label_round1->setStyleSheet("border-image: url(:/ZcloudDesk/image/round_sel.png);");
		ui.label_9->show();
	}
	if (nSignCount >= 10)
	{
		ui.label_line2->setStyleSheet("background-color: rgb(242,186,22);");
		ui.label_round2->setStyleSheet("border-image: url(:/ZcloudDesk/image/round_sel.png);");
		ui.label_10->show();
	}
	if (nSignCount >= 15)
	{
		ui.label_line3->setStyleSheet("background-color: rgb(242,186,22);");
		ui.label_round3->setStyleSheet("border-image: url(:/ZcloudDesk/image/round_sel.png);");
		ui.label_11->show();
	}
	if (nSignCount >= 20)
	{
		ui.label_line4->setStyleSheet("background-color: rgb(242,186,22);");
		ui.label_round4->setStyleSheet("border-image: url(:/ZcloudDesk/image/gift_sel.png);");
		ui.label_12->show();
	}

	m_nCoinCount		= data.take("coin_count").toInt();
	ui.labelCoin->setText(QString("%1").arg(m_nCoinCount));

	if (!data.take("today_sign_status").toBool())
	{
		ui.signInButton->setText(QString::fromLocal8Bit("Á¢¼´Ç©µ½"));
		ui.signInButton->setEnabled(true);
	}
	else
	{
		ui.signInButton->setText(QString::fromLocal8Bit("ÒÑÇ©µ½"));
		ui.signInButton->setEnabled(false);
	}
	QJsonObject dataAdvert = data.take("advert").toObject();
	m_bClickAdvert		= dataAdvert.take("isClick").toInt();
	QString strCover	= dataAdvert.take("cover").toString();
	m_nTargetType		= dataAdvert.take("target_type").toInt();
	m_strTarget			= dataAdvert.take("target").toString();
	m_strAdvertId		= dataAdvert.take("advert_id").toString();

	QtConcurrent::run(this, &SignInWidget::loadAdvertPic, strCover);
	connect(this, &SignInWidget::showAdvertPic, this, &SignInWidget::onShowAdvertPic);
	return true;
}

void SignInWidget::loadAdvertPic(QString strPicPath)
{
	QString strFilePath	=	ZcloudComFun::downloadPic(strPicPath, QApplication::applicationDirPath().append("/CacheImage/signInImage"));
	if (strFilePath.isEmpty())
	{
		strFilePath = ":/ZcloudDesk/image/default_advert.png";
	}
	emit showAdvertPic(strFilePath);
}

void SignInWidget::onShowAdvertPic(QString strPicPath)
{
	ui.labelPic->setStyleSheet(QString("border-image:url(%1);").arg(strPicPath));
}

bool SignInWidget::eventFilter(QObject *target, QEvent *e)
{
	if (ui.labelPic == target)
	{
		if (e->type() == QEvent::MouseButtonRelease)
		{
			ui.labelPic->removeEventFilter(this);
			if (m_bClickAdvert)
			{
				winHttpAdvertClickCount(m_strUid, m_strToken, m_strAdvertId);
				emit sigAdvertisingClick(m_nTargetType, m_strTarget);
			}
			ui.labelPic->installEventFilter(this);
		}
	}
	return QWidget::eventFilter(target, e);
}

bool SignInWidget::winHttpAdvertClickCount(QString strUid, QString strToken, QString strAdvertId)
{
	QString strRet;
	QString strUrl = QString("/v2/sign/sign-advert-click-count?user_id=%1&token=%2&advert_id=%3").arg(strUid).arg(strToken).arg(strAdvertId);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

bool SignInWidget::winHttpDoSign(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/v2/sign/do-sign?user_id=%1&token=%2").arg(strUid).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

#include <QGraphicsDropShadowEffect>
SignInTipWidget::SignInTipWidget(int nBaseReward, int nExtraReward, int nSignDay, QWidget *parent /*= Q_NULLPTR*/)
	:QDialog(parent)
{
	resize(256, 284);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");
	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
	//ÉèÖÃÒõÓ°¾àÀë
	shadow->setOffset(0, 0);
	//ÉèÖÃÒõÓ°ÑÕÉ«
	shadow->setColor(QColor("#666666"));
	//ÉèÖÃÒõÓ°Ô²½Ç
	shadow->setBlurRadius(8);
	//¸øÇ¶Ì×QWidgetÉèÖÃÒõÓ°
	this->setGraphicsEffect(shadow);

	m_pWidget = new QWidget(this);
	m_pWidget->setGeometry(8, 8, 240, 268);
	m_pWidget->setStyleSheet("background-color:rgba(255, 255, 255 ,1);border-radius:8px;");

	m_pLabel1 = new QLabel(QString::fromLocal8Bit("Ç©µ½³É¹¦"), m_pWidget);
	m_pLabel1->setAlignment(Qt::AlignCenter);
	m_pLabel1->setStyleSheet("color:rgba(10,165,250,1);font:75 18px \"Î¢ÈíÑÅºÚ\";");
	m_pLabel1->setGeometry(84, 30,71,19);

	m_pLabel2 = new QLabel(QString::fromLocal8Bit("+%1ÔÆ±Ò").arg(nBaseReward), m_pWidget);
	m_pLabel2->setAlignment(Qt::AlignCenter);
	m_pLabel2->setStyleSheet("color:#666666;font:14px \"Î¢ÈíÑÅºÚ\";");
	m_pLabel2->setGeometry(94, 60, 52, 14);

	m_pLabel3 = new QLabel(m_pWidget);
	m_pLabel3->setAlignment(Qt::AlignCenter);
	m_pLabel3->setStyleSheet("border-image:url(:/ZcloudDesk/image/coin.png);");
	m_pLabel3->setGeometry(60, 90, 133, 65);

	if (0	  >=	nExtraReward)
	{
		m_pLabel4 = new QLabel(QString::fromLocal8Bit("ÒÑÀÛ¼ÆÇ©µ½%1Ìì").arg(nSignDay), m_pWidget);
	}
	else
	{
		m_pLabel4 = new QLabel(QString::fromLocal8Bit("ÒÑÀÛ¼ÆÇ©µ½%1Ìì£¬¶îÍâ½±Àø%2ÔÆ±Ò").arg(nSignDay).arg(nExtraReward), m_pWidget);
	}
	m_pLabel4->setAlignment(Qt::AlignCenter);
	m_pLabel4->setStyleSheet("color:#666666;font:12px \"Î¢ÈíÑÅºÚ\";");
	m_pLabel4->setGeometry(30, 178, 180, 13);

	m_pOkBtn = new QPushButton(m_pWidget);
	m_pOkBtn->setText(QString::fromLocal8Bit("È·¶¨"));
	m_pOkBtn->setStyleSheet("QPushButton{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:1,y2:0,stop:0 rgba(2,164,253,1),"
	"stop:1 rgba(31,139,237,1));border-radius:4px;font:14px \"Î¢ÈíÑÅºÚ\";color:rgba(255,255,255,1);padding-left:8px;}"
	"QPushButton:hover,pressed{ background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 rgba(40,178,253,1),"
	"stop:1 rgba(64, 156, 240, 1));border-radius:4px;font:14px \"Î¢ÈíÑÅºÚ\";color:rgba(255, 255, 255, 1);}");
	m_pOkBtn->setGeometry(70, 215, 100, 38);
	connect(m_pOkBtn, &QPushButton::clicked, [this]()
	{
		accept();
	});
}

SignInTipWidget::~SignInTipWidget()
{

}
