#ifndef PAYINVOICEDIALOG_H
#define PAYINVOICEDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include "ui_QPayInvoiceDialog.h"
#include "ZhicloudAppDataDefine.h"

class PayInvoiceDialog : public QDialog
{
	Q_OBJECT

public:
	PayInvoiceDialog(QString strTaxNo,AppDataInfo pData,QWidget *parent);
	~PayInvoiceDialog();

private slots:
	void on_payToolButton_clicked();

	void on_invoiceToolButton_clicked();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent*	event);
	//void keyPressEvent(QKeyEvent * event);

private:
	Ui::PayInvoiceDialog ui;
	QString m_strTaxNo;
	AppDataInfo	m_pData;
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;
	QPixmap m_bg;
	QWidget *m_parent;
};

#endif // PAYINVOICEDIALOG_H
