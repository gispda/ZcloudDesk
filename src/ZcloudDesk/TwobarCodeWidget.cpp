#include "TwobarCodeWidget.h"
#include "ZcloudCommon.h"
#include <QMenu>
#include <QPushButton>
//#include "qrencode.h"
#include <QPainter>
#include <QPixmap>


#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>


const QString g_strColor0 = "rgba(95,217,153,1)";
const QString g_strColor1 = "rgba(237,164,60,1)";
const QString g_strColor2 = "rgba(60,148,237,1)";
const QString g_strColor3 = "rgba(217,95,216,1)";
const QString g_strColor4 = "rgba(67,222,224,1)";
const QString g_strColor5 = "rgba(255,120,102,1)";

TwobarCodeWidget::TwobarCodeWidget(QString strcompanyid, QString strToken, QString strTitle, QWidget *parent)
	: QWidget(parent)
	, m_strcompanyid(strcompanyid)
	, m_strToken(strToken)
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

	ui.labelStr->setText(strTitle);

	getCodeImg();
	//QPixmap map = generateQRcode("1234567");
	

	
	//ui->label->setStyleSheet("border-image:url(:/2.png);");
	

	
	

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



QPixmap TwobarCodeWidget::generateQRcode(char *string){



	//unsigned int    unWidth, x, y, l, n, unWidthAdjusted, unDataBytes;
	//unsigned char*  pRGBData, *pSourceData, *pDestData;
	//QRcode*         pQRC;
	//FILE*           f;
	//if (pQRC = QRcode_encodeString(string, 1, QR_ECLEVEL_L, QR_MODE_8, 1))
	//{
	//	unWidth = pQRC->width;
	//	unWidthAdjusted = unWidth * 8 * 3;
	//	if (unWidthAdjusted % 4)
	//		unWidthAdjusted = (unWidthAdjusted / 4 + 1) * 4;
	//	unDataBytes = unWidthAdjusted * unWidth * 8;
	//	// Allocate pixels buffer
	//	if (!(pRGBData = (unsigned char*)malloc(unDataBytes)))
	//	{
	//		return NULL;
	//	}
	//	//// Preset to white
	//	//memset(pRGBData, 0xff, unDataBytes);
	//	//// Prepare bmp headers
	//	//BITMAPFILEHEADER kFileHeader;
	//	//kFileHeader.bfType = 0x4d42;  // "BM"
	//	//kFileHeader.bfSize = sizeof(BITMAPFILEHEADER) +
	//	//	sizeof(BITMAPINFOHEADER) +
	//	//	unDataBytes;
	//	//kFileHeader.bfReserved1 = 0;
	//	//kFileHeader.bfReserved2 = 0;
	//	//kFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) +
	//	//	sizeof(BITMAPINFOHEADER);
	//	//BITMAPINFOHEADER kInfoHeader;
	//	//kInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
	//	//kInfoHeader.biWidth = unWidth * 8;
	//	//kInfoHeader.biHeight = -((int)unWidth * 8);
	//	//kInfoHeader.biPlanes = 1;
	//	//kInfoHeader.biBitCount = 24;
	//	//kInfoHeader.biCompression = BI_RGB;
	//	//kInfoHeader.biSizeImage = 0;
	//	//kInfoHeader.biXPelsPerMeter = 0;
	//	//kInfoHeader.biYPelsPerMeter = 0;
	//	//kInfoHeader.biClrUsed = 0;
	//	//kInfoHeader.biClrImportant = 0;
	//	// Convert QrCode bits to bmp pixels
	//	//pSourceData = pQRC->data;
	//	//for (y = 0; y < unWidth; y++)
	//	//{
	//	//	pDestData = pRGBData + unWidthAdjusted * y * 8;
	//	//	for (x = 0; x < unWidth; x++)
	//	//	{
	//	//		if (*pSourceData & 1)
	//	//		{
	//	//			for (l = 0; l < 8; l++)
	//	//			{
	//	//				for (n = 0; n < 8; n++)
	//	//				{
	//	//					//this is qrcode color default black
	//	//					*(pDestData + n * 3 + unWidthAdjusted * l) = 0x00;
	//	//					*(pDestData + 1 + n * 3 + unWidthAdjusted * l) = 0;
	//	//					*(pDestData + 2 + n * 3 + unWidthAdjusted * l) = 0;
	//	//				}
	//	//			}
	//	//		}
	//	//		pDestData += 3 * 8;
	//	//		pSourceData++;
	//	//	}
	//	//}
	//	int temp_width = unWidth * 8;
	//	int temp_height = unWidth * 8;
	//	QImage mainimg = QImage(temp_width, temp_height, QImage::Format_ARGB32);
	//	QPainter painter(&mainimg);
	//	QColor background(Qt::white);
	//	painter.setBrush(background);
	//	painter.setPen(Qt::NoPen);
	//	painter.drawRect(0, 0, temp_width, temp_height);
	//	QColor foreground(Qt::black);
	//	painter.setBrush(foreground);
	//	int qrcode_width = 100;
	//	double scale_x = (double)temp_width / (double)qrcode_width; //二维码图片的缩放比例
	//	double scale_y = (double)temp_height / (double)qrcode_width;
	//	for (qint32 y = 0; y < qrcode_width; y++)
	//	{
	//		for (qint32 x = 0; x < qrcode_width; x++)
	//		{
	//			unsigned char b = pQRC->data[y * qrcode_width + x];
	//			if (b & 0x01)
	//			{
	//				QRectF r(x * scale_x, y * scale_y, scale_x, scale_y);
	//				painter.drawRects(&r, 1);
	//			}
	//		}
	//	}
	//	QPixmap mainmap = QPixmap::fromImage(mainimg);

	//	// Free data
	//	free(pRGBData);
	//	QRcode_free(pQRC);
	//	return mainmap;
	//}
	//else
	//{
	//	return NULL;
	//}
return NULL;
}

void TwobarCodeWidget::getCodeImg()
{
	QString strRet;
	if (!winHttpGetTwoCodeInfo(m_strcompanyid, m_strToken, strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n更新企业资料失败，请稍后再试！"));
		return;
	}




	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return;
	}
	if (!parse_doucment.isObject())
	{
		return;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("code").toInt();
	if (0 != status)
	{
		return;
	}

	QJsonObject data = obj.take("data").toObject();

	m_tbid = data.take("flag").toString();

	m_tburl = data.take("qrimg").toString();
		
	//m_tblocalpath = ZcloudComFun::downloadPic(m_tburl, QApplication::applicationDirPath().append("/CacheImage/qrImage"));

	ZcloudComFun::LoadAvatar(m_tburl.toStdString(), ui.labelCode);

}

bool TwobarCodeWidget::winHttpGetTwoCodeInfo(QString strCompanyid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/ucenter/qr/min-qrcode");
	QString strPost = QString("token=%1&company_id=%2")
		.arg(strToken).arg(strCompanyid);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);
}
