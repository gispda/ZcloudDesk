#include "dlgwait.h"
#include "ui_dlgwait.h"
#include <QPainter>
#include "QDesktopWidget"

DlgWait::DlgWait(QString hint,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgWait)
{
    ui->setupUi(this);
	setStyleSheet("outline: none");
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowSystemMenuHint);
	setAttribute(Qt::WA_TranslucentBackground, true);

	//if (!hint.isEmpty())
	QString strText = QString::fromLocal8Bit("<html><head/><body><p><span style=\" font:18px \"Î¢ÈíÑÅºÚ\";color:rgb(102,102,102);\">%1</span></p></body></html>").arg(hint);
	ui->hintLabel->setText(strText);

    ui->waitLabel->setScaledContents(true);
	movie = new QMovie(":/new/imageFile/Ellipsis_loading.gif");
    ui->waitLabel->setMovie(movie);
    movie->start();
	this->setModal(true);
	this->raise();
	this->show();
}

DlgWait::~DlgWait()
{
	stop();
	movie->deleteLater();
    delete ui;
}

void DlgWait::stop()
{
	movie->stop();
	this->hide();
}

void DlgWait::start()
{
	movie->start();
	this->show();
}

void DlgWait::setText(QString str)
{
	QString strText = QString::fromLocal8Bit("<html><head/><body><p><span style=\" color:#ffffff; \">   %1</span></p></body></html>").arg(str);
	ui->hintLabel->setText(strText);
}

void DlgWait::stopMovie()
{
	movie->stop();
	this->close();
}






LoginWait::LoginWait(QWidget *parent) :
QDialog(parent)
{
	setStyleSheet("outline: none");
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint );
	setAttribute(Qt::WA_TranslucentBackground, true);
	
	QLabel *textLabel = new QLabel(QString::fromLocal8Bit("                     µÇÂ¼ÖÐ..."),this);
	textLabel->setGeometry(185, 156, 164, 58);
	textLabel->setStyleSheet(QString::fromLocal8Bit("QLabel{border-image: url(:/new/imageFile/login_dl_bg .png);font: 14px \"Î¢ÈíÑÅºÚ\";color: rgb(255,255,255);};"));
	QLabel *waitLabel = new QLabel(this);
	waitLabel->setGeometry(207, 170, 30, 30);
	waitLabel->setScaledContents(true);

	movie = new QMovie(":/new/imageFile/loginWait.gif");
	//QPainter painter;
	//painter.setRenderHint(QPainter::Antialiasing, true);
	//waitLabel->setPain
	waitLabel->setMovie(movie);
	movie->start();
	this->setModal(true);
	this->show();
}

LoginWait::~LoginWait()
{
	stop();
	movie->deleteLater();
}

void LoginWait::stop()
{
	movie->stop();
	this->hide();
}