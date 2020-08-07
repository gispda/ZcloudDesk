#include "WorkerItemWidget.h"
#include "ZcloudCommon.h"
#include <QMenu>
const QString g_strColor0 = "rgba(95,217,153,1)";
const QString g_strColor1 = "rgba(237,164,60,1)";
const QString g_strColor2 = "rgba(60,148,237,1)";
const QString g_strColor3 = "rgba(217,95,216,1)";
const QString g_strColor4 = "rgba(67,222,224,1)";
const QString g_strColor5 = "rgba(255,120,102,1)";

WorkerItemWidget::WorkerItemWidget(WorkerInfo _info, QString strAction2, QWidget *parent)
	: QWidget(parent)
	, m_strAction2(strAction2)
{
	m_info = _info;
	
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, false);
	setWindowModality(Qt::WindowModal);
	setStyleSheet("outline: none");



	QString strFirstName;


	QString strColor;
	if (m_info.strStatedesc == "待受理"){
		strColor = g_strColor0;
	}
	else if (m_info.strStatedesc == "受理中"){
		strColor = g_strColor1;
	}
	else if (m_info.strStatedesc == "已完成"){
		strColor = g_strColor2;
	}
	else{
		strColor = g_strColor3;
	}
	QString str = QString::fromLocal8Bit("border:2px solid %1;\nborder-radius:5px;").arg(strColor);
	ui.labelStateColor->setStyleSheet(str);
	//ui.labelStateColor->setText(QString::fromLocal8Bit("T"));

	ui.labelOrderCode->setText(m_info.strWorkerid);
	ui.labelOrderName->setText(m_info.strWorkertitle);
	ui.labelState->setText(m_info.strStatedesc);
	ui.labelCreateTime->setText(m_info._dtCreateTime.toString("yyyy.MM.dd hh : mm"));
	ui.buttonAction->setText(m_strAction2);

	connect(ui.buttonDetial, &QPushButton::clicked, [this](){
		sigDetial(m_strOrderCode);
	});


	connect(ui.buttonAction, &QPushButton::clicked, [this](){
		emit sigEvaluate(m_info);
	});


	//ZcloudComFun::setElideText(14, ui.labelJob, strJob);


}

void WorkerItemWidget::test(QString code){
	QString a = code;
	QString b;
}

WorkerItemWidget::~WorkerItemWidget()
{
}
