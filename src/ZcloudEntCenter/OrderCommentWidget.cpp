#include "OrderCommentWidget.h"
#include "ZcloudCommon.h"
#include <QMenu>
const QString g_strColor0 = "rgba(95,217,153,1)";
const QString g_strColor1 = "rgba(237,164,60,1)";
const QString g_strColor2 = "rgba(60,148,237,1)";
const QString g_strColor3 = "rgba(217,95,216,1)";
const QString g_strColor4 = "rgba(67,222,224,1)";
const QString g_strColor5 = "rgba(255,120,102,1)";

OrderCommentWidget::OrderCommentWidget(QString strOrderCode, QWidget *parent)
	: QWidget(parent)
	, m_strOrderCode(strOrderCode)
{

	ui.setupUi(this);

	QString strFirstName;
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, false);
	setWindowModality(Qt::WindowModal);
	setStyleSheet("outline: none");

	setGrade(3);

	connect(ui.buttonGrade1, &QPushButton::clicked, this, &OrderCommentWidget::push1);
	connect(ui.buttonGrade2, &QPushButton::clicked, this, &OrderCommentWidget::push2);
	connect(ui.buttonGrade3, &QPushButton::clicked, this, &OrderCommentWidget::push3);
	connect(ui.buttonGrade4, &QPushButton::clicked, this, &OrderCommentWidget::push4);
	connect(ui.buttonGrade5, &QPushButton::clicked, this, &OrderCommentWidget::push5);



	connect(ui.buttonCancel, &QPushButton::clicked, [this](){
		close();
	});
	/*QString strColor;
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
	}*/
	//QString str = QString::fromLocal8Bit("border:2px solid %1;\nborder-radius:5px;").arg(strColor);
	//ui.labelStateColor->setStyleSheet(str);
	////ui.labelStateColor->setText(QString::fromLocal8Bit("T"));

	//ui.labelOrderCode->setText(m_strOrderCode);
	//ui.labelOrderName->setText(m_strOrderName);
	//ui.labelState->setText(m_strOrderState);
	//ui.labelCreateTime->setText(m_strCreateTime);
	//ui.labelAction2->setText(m_strAction2);


	//ZcloudComFun::setElideText(14, ui.labelJob, strJob);


}

OrderCommentWidget::~OrderCommentWidget()
{
}
void OrderCommentWidget::push1(){
	setGrade(1);
}void OrderCommentWidget::push2(){
	setGrade(2);
}void OrderCommentWidget::push3(){
	setGrade(3);
}void OrderCommentWidget::push4(){
	setGrade(4);
}void OrderCommentWidget::push5(){
	setGrade(5);
}

void OrderCommentWidget::setGrade(int pushindex){
	
	if (grades == pushindex){
		grades = grades - 1;
	}
	else{
		grades = pushindex;
	}
	QIcon iconfull(":/EntCenterWidget/image/fafull.png");

	QIcon iconspace(":/EntCenterWidget/image/faspace.png");
	if (grades < 1){
		ui.buttonGrade1->setIcon(iconspace);
	}
	else{
		ui.buttonGrade1->setIcon(iconfull);
	}
	if (grades < 2){
		ui.buttonGrade2->setIcon(iconspace);
	}
	else{
		ui.buttonGrade2->setIcon(iconfull);
	}
	if (grades < 3){
		ui.buttonGrade3->setIcon(iconspace);
	}
	else{
		ui.buttonGrade3->setIcon(iconfull);
	}
	if (grades < 4){
		ui.buttonGrade4->setIcon(iconspace);
	}
	else{
		ui.buttonGrade4->setIcon(iconfull);
	}
	if (grades < 5){
		ui.buttonGrade5->setIcon(iconspace);
	}
	else{
		ui.buttonGrade5->setIcon(iconfull);
	}
	ui.buttonGrade1->repaint();
	ui.buttonGrade2->repaint();
	ui.buttonGrade3->repaint();
	ui.buttonGrade4->repaint();
	ui.buttonGrade5->repaint();
}

void OrderCommentWidget::mousePressEvent(QMouseEvent *event)
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

void OrderCommentWidget::mouseMoveEvent(QMouseEvent *event)
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