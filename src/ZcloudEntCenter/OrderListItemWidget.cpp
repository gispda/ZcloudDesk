#include "OrderListItemWidget.h"
#include "ZcloudCommon.h"
#include <QMenu>
const QString g_strColor0 = "rgba(95,217,153,1)";
const QString g_strColor1 = "rgba(237,164,60,1)";
const QString g_strColor2 = "rgba(60,148,237,1)";
const QString g_strColor3 = "rgba(217,95,216,1)";
const QString g_strColor4 = "rgba(67,222,224,1)";
const QString g_strColor5 = "rgba(255,120,102,1)";

OrderListItemWidget::OrderListItemWidget( QString strOrderCode, QString strOrderName, QString strOrderState, QString strCreateTime, QString strAction2, QWidget *parent)
	: QWidget(parent)
	, m_strOrderCode(strOrderCode)
	, m_strOrderName(strOrderName)
	, m_strOrderState(strOrderState)
	, m_strCreateTime(strCreateTime)
	, m_strAction2(strAction2)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, false);
	setWindowModality(Qt::WindowModal);
	setStyleSheet("outline: none");



	QString strFirstName;


	QString strColor;
	if (strOrderState == "待受理"){
		strColor = g_strColor0;
	}
	else if (strOrderState == "受理中"){
		strColor = g_strColor1;
	}
	else if (strOrderState == "已完成"){
		strColor = g_strColor2;
	}
	else{
		strColor = g_strColor3;
	}
	QString str = QString::fromLocal8Bit("border:2px solid %1;\nborder-radius:5px;").arg(strColor);
	ui.labelStateColor->setStyleSheet(str);
	//ui.labelStateColor->setText(QString::fromLocal8Bit("T"));

	ui.labelOrderCode->setText(m_strOrderCode);
	ui.labelOrderName->setText(m_strOrderName);
	ui.labelState->setText(m_strOrderState);
	ui.labelCreateTime->setText(m_strCreateTime);
	ui.buttonAction->setText(m_strAction2);

	connect(ui.buttonDetial, &QPushButton::clicked, [this](){
		sigDetial(m_strOrderCode);
	});


	connect(ui.buttonAction, &QPushButton::clicked, [this](){
		emit sigEvaluate(m_strOrderCode);
	});


	//ZcloudComFun::setElideText(14, ui.labelJob, strJob);


}

void OrderListItemWidget::test(QString code){
	QString a = code;
	QString b;
}

OrderListItemWidget::~OrderListItemWidget()
{
}
