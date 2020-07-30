#include "MessageTipDlg.h"
#include <QGraphicsDropShadowEffect>
MessageTipDlg::MessageTipDlg(EN_BTN_TYPE enBtnType, QString strTitle, QString strMsg, QWidget *parent)
	: QDialog(parent)
	, m_enBtnType(enBtnType)
	, m_strTitle(strTitle)
	, m_strMsg(strMsg)
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
	switch (m_enBtnType)
	{
	case EN_CLOSE:
	{
		ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudDeskUpdater/Resources/msgTip.png);");
		ui.BtnWidget1->show();
		ui.BtnWidget2->hide();
		ui.BtnWidget3->hide();
		break;
	}
	case EN_OKCANCEL:
	{
		ui.labelIcon->setStyleSheet("border-image: url(:/ZcloudDeskUpdater/Resources/sucess.png);");
		QRect rect = ui.BtnWidget1->geometry();
		ui.BtnWidget1->hide();
		ui.BtnWidget2->hide();
		ui.BtnWidget3->setGeometry(rect);
		ui.BtnWidget3->show();
		break;
	}
	default:
		break;
	}
	ui.labelTilte->setText(m_strTitle);
	ui.labelMsg->setText(m_strMsg);
}
