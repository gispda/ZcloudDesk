#include "TwobarCodeWidget.h"
#include "ZcloudCommon.h"
#include <QMenu>
#include <QPushButton>
#include <QRcode.h>
const QString g_strColor0 = "rgba(95,217,153,1)";
const QString g_strColor1 = "rgba(237,164,60,1)";
const QString g_strColor2 = "rgba(60,148,237,1)";
const QString g_strColor3 = "rgba(217,95,216,1)";
const QString g_strColor4 = "rgba(67,222,224,1)";
const QString g_strColor5 = "rgba(255,120,102,1)";

TwobarCodeWidget::TwobarCodeWidget(QString code, QString str, QWidget *parent )
	: QWidget(parent)
	, m_code(code)
	, m_str(str)
{

	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("createtEntInfo");
	setAttribute(Qt::WA_ShowModal, true);
	


	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, false);
	setWindowModality(Qt::WindowModal);
	setStyleSheet("outline: none");


	connect(ui.closeButton, &QPushButton::clicked, this, &QWidget::close);

	ui.labelStr->setText(str);

}


QPixmap TwobarCodeWidget::generateQRcode(QString tempstr)

{

	QRcode *qrcode; //二维码数据

	//QR_ECLEVEL_Q 容错等级

	char*  ch;

	QByteArray ba = tempstr.toUtf8();

	ch = ba.data();

	qrcode = QRcode_encodeString(ch, 2, QR_ECLEVEL_Q, QR_MODE_8, 1);

	qint32 temp_width = 200; //二维码图片的大小

	qint32 temp_height = 200;

	qint32 qrcode_width = qrcode->width > 0 ? qrcode->width : 1;

	double scale_x = (double)temp_width / (double)qrcode_width; //二维码图片的缩放比例

	double scale_y = (double)temp_height / (double)qrcode_width;

	QImage mainimg = QImage(temp_width, temp_height, QImage::Format_ARGB32);

	QPainter painter(&mainimg);

	QColor background(Qt::white);

	painter.setBrush(background);

	painter.setPen(Qt::NoPen);

	painter.drawRect(0, 0, temp_width, temp_height);

	QColor foreground(Qt::black);

	painter.setBrush(foreground);

	for (qint32 y = 0; y < qrcode_width; y++)

	{

		for (qint32 x = 0; x < qrcode_width; x++)

		{

			unsigned char b = qrcode->data[y * qrcode_width + x];

			if (b & 0x01)

			{

				QRectF r(x * scale_x, y * scale_y, scale_x, scale_y);

				painter.drawRects(&r, 1);

			}

		}

	}

	QPixmap mainmap = QPixmap::fromImage(mainimg);

	return mainmap;

}

TwobarCodeWidget::~TwobarCodeWidget()
{
}




void TwobarCodeWidget::mousePressEvent(QMouseEvent *event)
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

void TwobarCodeWidget::mouseMoveEvent(QMouseEvent *event)
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