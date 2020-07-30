#include "MessageTipDlg.h"
#include <QGraphicsDropShadowEffect>
MessageTipDlg::MessageTipDlg(ZcloudComFun::EN_BTN_TYPE enBtnType, QString strTitle, QString strMsg, QWidget *parent)
	: QDialog(parent)
	, m_enBtnType(enBtnType)
	, m_strTitle(strTitle)
	, m_strMsg(strMsg)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("提示"));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");

	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);			//阴影模糊度
	//设置阴影距离
	shadow->setOffset(0, 0);
	//设置阴影颜色
	shadow->setColor(QColor("#666666"));
	//设置阴影圆角
	shadow->setBlurRadius(8);
	//给嵌套QWidget设置阴影
	this->setGraphicsEffect(shadow);

	init();
}


MessageTipDlg::MessageTipDlg(ZcloudComFun::EN_BTN_TYPE enBtnType, QString strTitle, QString strMsg,QString buttonStr_1, QString buttonStr_2, QWidget *parent)
	: QDialog(parent)
	, m_enBtnType(enBtnType)
	, m_strTitle(strTitle)
	, m_strMsg(strMsg)
	, m_buttonStr_1(buttonStr_1)
	, m_buttonStr_2(buttonStr_2)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("提示"));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");

	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);			//阴影模糊度
	//设置阴影距离
	shadow->setOffset(0, 0);
	//设置阴影颜色
	shadow->setColor(QColor("#666666"));
	//设置阴影圆角
	shadow->setBlurRadius(8);
	//给嵌套QWidget设置阴影
	this->setGraphicsEffect(shadow);

	init();
}



MessageTipDlg::~MessageTipDlg()
{

}

void MessageTipDlg::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		dPos = event->globalPos() - pos();
		event->accept();
	}
}

void MessageTipDlg::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - dPos);
		event->accept();
	}
}

void MessageTipDlg::init()
{
	ui.clostPushButton->hide();
	switch (m_enBtnType)
	{
	case ZcloudComFun::EN_CLOSE:
	{
		ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudCommon/image/sucess.png);");
		ui.BtnWidget1->show();
		ui.BtnWidget2->hide();
		ui.BtnWidget3->hide();
		ui.BtnWidget4->hide();
		break;
	}
	case ZcloudComFun::EN_TIP:
	{
		ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudCommon/image/tip.png);");
		ui.BtnWidget1->show();
		ui.BtnWidget2->hide();
		ui.BtnWidget3->hide();
		ui.BtnWidget4->hide();
		break;
	}
	case ZcloudComFun::ZEN_UPDATE:
	{
		ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudCommon/image/tip.png);");
		QRect rect = ui.BtnWidget1->geometry();
		ui.BtnWidget1->hide();
		ui.BtnWidget2->setGeometry(rect);
		ui.BtnWidget2->show();
		ui.BtnWidget3->hide();
		ui.BtnWidget4->hide();
		break;
	}
	case ZcloudComFun::EN_OKCANCEL:
	{
		ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudCommon/image/tip.png);");
		QRect rect = ui.BtnWidget1->geometry();
		ui.BtnWidget1->hide();
		ui.BtnWidget2->hide();
		ui.BtnWidget3->setGeometry(rect);
		ui.BtnWidget3->show();
		ui.BtnWidget4->hide();
		break;
	}
	case ZcloudComFun::EN_BINDING:
	{
		ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudCommon/image/tip.png);");
		QRect rect = ui.BtnWidget1->geometry();
		ui.BtnWidget1->hide();
		ui.BtnWidget2->hide();
		ui.BtnWidget3->hide();
		ui.BtnWidget4->show();
		ui.BtnWidget4->setGeometry(rect);
		if (!m_buttonStr_1.isEmpty() && !m_buttonStr_2.isEmpty())
		{
			ui.bindingButton->setText(m_buttonStr_1);
			ui.notBindingButton->setText(m_buttonStr_2);
			if (m_buttonStr_1 == QString::fromLocal8Bit("购买会员") && m_buttonStr_2 == QString::fromLocal8Bit("购买应用"))
			{
				ui.notBindingButton->disconnect();
				ui.clostPushButton->show();
				connect(ui.notBindingButton, &QPushButton::clicked, [this]()
				{
					this->done(3);
				});
			}
		}

		break;
	}
	default:
		break;
	}
	ui.labelTilte->setText(m_strTitle);
	ui.labelMsg->setText(m_strMsg);
}
