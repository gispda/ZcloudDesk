#include "QPayInvoiceDialog.h"
#include <QDesktopServices>
#include <QProcess>
#include <QDesktopWidget>

//#include "ZWebViewBrowser\zwebviewbrowser.h"

PayInvoiceDialog::PayInvoiceDialog(QString strTaxNo,AppDataInfo pData,QWidget *parent)
	: QDialog(parent)
	, m_parent(parent)
	, m_pData(pData)
	, m_strTaxNo(strTaxNo)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint| Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	m_bg.load(":/new/imageFile/img_skfwfxf_bg.png");
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
}

PayInvoiceDialog::~PayInvoiceDialog()
{

}

void PayInvoiceDialog::on_payToolButton_clicked()
{
	QString payUrl = QString("http://interface.xjhtxx.cn:8080/IWant.aspx?CUSTAXCODE=%1").arg(m_strTaxNo);
	QStringList paramsList;
	paramsList << "" << m_pData.m_strAppId << QString::fromLocal8Bit("自主缴费") << payUrl << m_pData.m_strAppIconPath;
	QProcess::startDetached(QApplication::applicationDirPath() + "/ZBrowser.exe", paramsList);

	this->accept();
	//QDesktopServices::openUrl(QUrl::fromUserInput(payUrl));
}

void PayInvoiceDialog::on_invoiceToolButton_clicked()
{
	QString invoiceUrl = QString("http://interface.xjhtxx.cn:8080/MyInvoice.aspx?CusCode=%1").arg(m_strTaxNo);
	QStringList paramsList;
	paramsList << "" << m_pData.m_strAppId << QString::fromLocal8Bit("我要发票") << invoiceUrl << m_pData.m_strAppIconPath;
	QProcess::startDetached(QApplication::applicationDirPath() + "/ZBrowser.exe", paramsList);

	this->accept();
	//QDesktopServices::openUrl(QUrl::fromUserInput(invoiceUrl));
}

//void PayInvoiceDialog::keyPressEvent(QKeyEvent *event)
//{
//	switch (event->key())
//	{
//		//进行界面退出，重写Esc键
//	case Qt::Key_Escape:
//		break;
//	default:
//		QDialog::keyPressEvent(event);
//	}
//}


void PayInvoiceDialog::mousePressEvent(QMouseEvent *event)
{
	this->windowPos = this->pos();            // 获得部件当前位置
	this->mousePos = event->globalPos();     // 获得鼠标位置
	this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void PayInvoiceDialog::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->globalPos() - this->dPos);
}

void PayInvoiceDialog::paintEvent(QPaintEvent* event)
{
	QPainter painter;
	painter.begin(this);
	painter.drawPixmap(rect(), m_bg);
	painter.end();
}