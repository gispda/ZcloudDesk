#include "drawbutton.h"

DragButton::DragButton(QWidget *parent) :
QToolButton(parent), isPress(0), isHold(0), m_scaling(8), m_InitialScaling(8), m_mouseSrcPos(0, 0)
, m_bIsDrag(false)
{
	m_aniTimer = new QTimer(this);
	m_aniTimer->setInterval(7);

	m_holdTimer = new QTimer(this);
	m_holdTimer->setInterval(1000);
	m_holdTimer->setSingleShot(true);
	connect(m_holdTimer, SIGNAL(timeout()), this, SLOT(hold_slot()));

	clickTimer = new QTimer(this);
}

void DragButton::setInitialScaling(double scaling)
{
	if (scaling <= 1 && scaling > 0)
	{
		m_InitialScaling = scaling;
		m_scaling = scaling;
	}
}

void DragButton::setPixmap(QString pixmapPath)
{
	QByteArray pData;
	int i = 0;
	QFile file(pixmapPath);
	file.open(QIODevice::ReadOnly);
	pData = file.readAll();
	m_pixmap.loadFromData(pData);
	if (m_pixmap.isNull())
	{
		qDebug() << "pixmapPath:" << pixmapPath;
	}
	file.close();
}

void DragButton::setPixmap(QPixmap pixmap)
{
	m_pixmap = pixmap;
}

void DragButton::setText(QString str)
{
	m_text = str;
}

void DragButton::setIsHold(bool flag)
{
	isHold = flag;
}

//设置数据
void DragButton::settUserData(AppDataInfo pData)
{
	m_pData = pData;
}

AppDataInfo DragButton::userData()
{
	return m_pData;
}

void DragButton::paintEvent(QPaintEvent *e)
{
	if (m_pixmap.isNull())
		return;

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setRenderHint(QPainter::SmoothPixmapTransform);
	if (isPress)
	{
		painter.setPen(Qt::NoPen);
		//painter.setBrush(QColor(0,0,0,0));
		//painter.drawRoundedRect(rect(),20,20);
	}

	int pMeg = (double)width() * 0.2;//图片边框宽度
	int pointH = 30;// height() * 0.15;//字体的高度
	int w = width() - pMeg - m_scaling;
	//int h = height() - pMeg - pointH - m_scaling;
	QPixmap drawPixmap = m_pixmap.scaled(w, w, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	painter.drawPixmap(QRect((pMeg + m_scaling) / 2, (pMeg + m_scaling) / 2, w, w),
		drawPixmap, drawPixmap.rect());

	painter.setPen(QColor(255, 255, 255));
	QFont font("Microsoft YaHei");

	font.setPixelSize(14);

	painter.setFont(font);
	int flags = Qt::TextWordWrap | Qt::AlignHCenter;

	//设置字体
	QString textFont = m_text;
	//安装
	if (!m_pData.m_bAppIsInstall)
	{

		switch (statusAppButton)
		{
		case mapp_DOWNLOADING:
			textFont = QString::fromLocal8Bit("下载中");
			break;
		case mapp_ERROR:
			textFont = QString::fromLocal8Bit("下载错误");
			break;
		case mapp_TIMEOUTERROR:
			textFont = QString::fromLocal8Bit("下载超时");
			break;
		case mapp_FINISH:
			textFont = QString::fromLocal8Bit("安装中");
			break;
		case mapp_INSTALLFINLSH:
		{
			m_pData.m_bAppIsInstall = true;
			break;
		}

		case mapp_INSTALLERROR:
			textFont = QString::fromLocal8Bit("安装错误");
			break;
		case mapp_PAUSE:
			textFont = QString::fromLocal8Bit("暂停中");
			break;
		case mapp_CLOSE:
		{
			//关闭下载 刷新界面
			//emit closeDownload(m_pData.mStrAppCateId);
			return QToolButton::paintEvent(e);
		}
		default:
			break;
		}

		if (statusAppButton != mapp_FINISH && statusAppButton != mapp_INSTALLFINLSH && statusAppButton != mapp_CLOSE)
		{
			QPixmap roundPixmap(":/new/imageFile/appIconRound.png");
			QPixmap rPixmap = roundPixmap.scaled(w, w, Qt::KeepAspectRatio, Qt::SmoothTransformation);
			painter.drawPixmap(QRect((pMeg + m_scaling) / 2, (pMeg + m_scaling) / 2, w, w),
				rPixmap, rPixmap.rect());
		}


		if (textFont.length() >= 4)
		{
			painter.drawText(QRect(0, height() - pointH - 3, width(), (pointH + 10) / 2), flags, textFont.left(4));
			painter.drawText(QRect(0, height() - pointH + pointH / 2 - 3, width(), (pointH + 10) / 2), flags, textFont.right(textFont.length() - 4));
		}
		else
		{
			painter.drawText(QRect(0, height() - pointH, width() - 3, pointH + 10), flags, textFont);
		}

		//设置图标状态
		int radius = w / 2 - 9;
		switch (statusAppButton)
		{
		case mapp_DOWNLOADING:
		{
			// >> 1（右移1位）相当于width() / 2
			painter.translate(width() >> 1, ((height() - pointH) >> 1));
			int  scale = 0;
			if (m_bytesTotal != 0)
			{
				scale = m_bytesReceived * 360 / m_bytesTotal;
			}
			gradientArc(&painter, radius, 45, scale, radius, QColor(255, 255, 250, 0));
			gradientArc(&painter, radius, 90, 360 - scale, radius, QColor(0, 0, 0, 153));
			painter.save();
			painter.setRenderHint(QPainter::Antialiasing, true);
			painter.translate(- width() / 2, - ((height() - pointH) /2));
			break;
		}
		case mapp_INSTALLERROR:
		case mapp_ERROR:
		{
			int d = radius * 2;
			int pixX = (pMeg + m_scaling + w - d) >> 1;
			//下载错误
			QPixmap stopPixmap(":/new/imageFile/appIconRound_error.png");
			stopPixmap = stopPixmap.scaled(d, d, Qt::KeepAspectRatio, Qt::SmoothTransformation);
			painter.drawPixmap(QRect(pixX, pixX, d, d),
				stopPixmap, stopPixmap.rect());
			break;
		}
		case mapp_FINISH:
			break;
		case mapp_INSTALLFINLSH:
			break;
		case mapp_TIMEOUTERROR:
		case mapp_PAUSE:
		{
			int d = radius * 2;
			int pixX = (pMeg + m_scaling + w - d) >> 1;
			//暂停 
			QPixmap stopPixmap(":/new/imageFile/appIconRound_stop.png");
			QPixmap SstopPixmap = stopPixmap.scaled(d, d, Qt::KeepAspectRatio, Qt::SmoothTransformation);
			painter.drawPixmap(QRect(pixX, pixX, d, d),
				SstopPixmap, SstopPixmap.rect());
			break;
		}
		case mapp_CLOSE:
			break;
		default:
			break;
		}

	}
	else//更新
	{
		switch (statusAppButton)
		{
		case mapp_DOWNLOADING:
			textFont = QString::fromLocal8Bit("下载中");
			break;
		case mapp_FINISH:
			textFont = QString::fromLocal8Bit("安装中");
			break;
		case mapp_CLOSE:
		{
			//关闭下载 刷新界面  现在的状态是安装
			//emit closeDownload(m_pData.mStrAppCateId);
			//return QToolButton::paintEvent(e);
		}
		default:
			break;
		}

		if (textFont.length() >= 4)
		{
			painter.drawText(QRect(0, height() - pointH - 3, width(), (pointH + 10) / 2), flags, textFont.left(4));
			painter.drawText(QRect(0, height() - pointH + pointH / 2 - 3, width(), (pointH + 10) / 2), flags, textFont.right(textFont.length() - 4));
		}
		else
		{
			painter.drawText(QRect(0, height() - pointH, width() - 3, pointH + 10), flags, textFont);
		}





		if (statusAppButton == mapp_DOWNLOADING)
		{
			QPixmap roundPixmap(":/new/imageFile/appIconRound.png");
			QPixmap rPixmap = roundPixmap.scaled(w, w, Qt::KeepAspectRatio, Qt::SmoothTransformation);
			painter.drawPixmap(QRect((pMeg + m_scaling) / 2, (pMeg + m_scaling) / 2, w, w),
				rPixmap, rPixmap.rect());
			//设置图标状态
			int radius = w / 2 - 9;
			// >> 1（右移1位）相当于width() / 2
			painter.translate(width() >> 1, ((height() - pointH) >> 1));
			int  scale = 0;
			if (m_bytesTotal != 0)
			{
				scale = m_bytesReceived * 360 / m_bytesTotal;
			}
			gradientArc(&painter, radius, 45, scale, radius, QColor(255, 255, 250, 0));
			gradientArc(&painter, radius, 90, 360 - scale, radius, QColor(0, 0, 0, 153));
			//painter.save();
			painter.translate(- width() /2, - ((height() - pointH) / 2));
			painter.setRenderHint(QPainter::Antialiasing, true);
		}

	}
	
	//消息
	if (m_haveMessage)
	{
		int rR = 4;//红点的半径
		int rX = (width() + w) / 2 - 4;
		int rY = ((height() - pointH) - w) / 2 + 4;
		painter.translate(rX , rY);
		gradientArc(&painter, rR, 0, 360, rR, QColor(255, 0, 0), true);
		painter.translate( - rX, - rY);
	}

	//有升级
	if (m_pData.m_bAppIsInstall && m_isUpdate)
	{
		QPixmap uPixmap(":/new/imageFile/update.png");

		int pX = (width() + w) / 2 - 14;
		int pY = ((height() - pointH) - w) / 2 - 6;
		QPixmap uSPixmap = uPixmap.scaled(13, 16, Qt::KeepAspectRatio, Qt::SmoothTransformation);
		painter.drawPixmap(QRect(pX, pY, 13, 16),
			uSPixmap, uSPixmap.rect());
	}

	//会员
	QStringList strList = m_pData.m_strListAppVipList;
	if (strList.size() > 0 && strList.at(0) != "0")
	{
		int pR = 12;//图片直径
		QPixmap vPixmap(":/new/imageFile/vip.png");
		int pX = (width() + w) / 2 - pR;
		int pY = ((height() - pointH) + w) / 2 - pR;
		QPixmap rSPixmap = vPixmap.scaled(pR, pR, Qt::KeepAspectRatio, Qt::SmoothTransformation);
		painter.drawPixmap(QRect(pX, pY , pR, pR),
			rSPixmap, rSPixmap.rect());
	}
	painter.setRenderHint(QPainter::Antialiasing, true);

	return QToolButton::paintEvent(e);
	
//gradientArc(&painter, radius, 0, 360, pMeg / 2, QColor(0, 0, 0, 153), false); //圆圈
//painter.restore();

}


//QImage DragButton::cvImageRGB(int red, int green, int blue, QImage img)
//{
//	QImage reImg;
//	for (int y = 0; y < img.height; y++)
//	{
//		unsigned char *ptr = (unsigned char *)(img.imageData + y * img.widthStep);
//		unsigned char *ptr1 = (unsigned char *)(img1->imageData + y * img1->widthStep);
//		for (int x = 0; x < img.width; x++)
//		{
//			bool ok;
//			//蓝色设置  
//			if (blue)
//			{
//				ptr[3 * x + 0] = blue;
//			}
//			else
//			{
//				ptr[3 * x + 0] = ptr1[3 * x + 0];
//			}
//			//绿色设置  
//			if (green)
//			{
//				ptr[3 * x + 1] = green;
//			}
//			else
//			{
//				ptr[3 * x + 1] = ptr1[3 * x + 1];
//			}
//			//红色设置  
//			if (red)
//			{
//				ptr[3 * x + 2] = red;
//			}
//			else
//			{
//				ptr[3 * x + 2] = ptr1[3 * x + 2];
//			}
//		}
//	}
//	cvShowImage("jdh2", img2);
//}


/**
* 参数二：半径
* 参数三：开始的角度
* 参数四：指扫取的角度-顺时针（360度 / 8 = 45度）
* 参数五：圆环的高度
* 参数六：填充色
**/
void DragButton::gradientArc(QPainter *painter, int radius, int startAngle, int angleLength, int arcHeight, QColor color, bool isArc)
{
	// 渐变色
	QRadialGradient gradient(0, 0, radius);
	gradient.setColorAt(0, Qt::white);
	gradient.setColorAt(0, color);
	painter->setBrush(gradient);
	QRectF rect(-radius, -radius, radius << 1, radius << 1);
	QPainterPath path;
	path.arcTo(rect, startAngle, angleLength);
	painter->setPen(Qt::NoPen);
	// path为扇形 subPath为椭圆
	if (!isArc)
	{
		QPainterPath subPath;
		subPath.addEllipse(rect.adjusted(arcHeight, arcHeight, -arcHeight, -arcHeight));
		path -= subPath;
		//painter->setPen(Qt::darkBlue);
	}
	painter->drawPath(path);
}


void DragButton::enterEvent(QEvent *)
{
	disconnect(m_aniTimer, SIGNAL(timeout()), this, SLOT(zoomOut()));
	connect(m_aniTimer, SIGNAL(timeout()), this, SLOT(zoomIn()));
	m_aniTimer->start();
}

void DragButton::leaveEvent(QEvent *)
{
	disconnect(m_aniTimer, SIGNAL(timeout()), this, SLOT(zoomIn()));
	connect(m_aniTimer, SIGNAL(timeout()), this, SLOT(zoomOut()));
	m_aniTimer->start();
}

//按下
void DragButton::mousePressEvent(QMouseEvent *e)
{
	if (!m_bIsDrag)
	{
		return;
	}
	if (e->button() == Qt::LeftButton)
	{
		if (!isHold)
		{
			isPress = 1;
			isHold = 1;
		}
		m_holdTimer->start();
		m_mouseSrcPos = e->pos();
		clickTimer->start(150);
		clickTimer->setSingleShot(true);//定时器只运行一次
	}
	QToolButton::mousePressEvent(e);
}

//释放
void DragButton::mouseReleaseEvent(QMouseEvent *e)
{
	if (!m_bIsDrag)
	{
		if (e->button() == Qt::LeftButton)
		{
			emit dragDoubleClicked();
		}
		return;
	}
	if (e->button() == Qt::LeftButton)
	{
		m_holdTimer->stop();

		isPress = 0;
		isHold = 0;

		if (rect().contains(e->pos()))
			emit dragClicked();

		if (clickTimer->isActive())
		{
			emit dragDoubleClicked();
			clickTimer->stop();
		}

		emit release_signal();
	}
	QToolButton::mouseReleaseEvent(e);
}

//移动
void DragButton::mouseMoveEvent(QMouseEvent *e)
{
	if (!m_bIsDrag)
	{
		return;
	}

	if (isHold)
	{
		move(pos() - m_mouseSrcPos + e->pos());
		emit drag_signal();
	}
	else
		m_mouseSrcPos = e->pos();
	QToolButton::mouseMoveEvent(e);
}

void DragButton::zoomIn()
{
	m_scaling -= 1;
	if (m_scaling <= 0)
	{
		m_scaling = 0;
		m_aniTimer->stop();
		update();
	}
}

void DragButton::zoomOut()
{
	m_scaling += 1;
	if (m_scaling >= m_InitialScaling)
	{
		m_scaling = m_InitialScaling;
		m_aniTimer->stop();
		update();
	}
}

void DragButton::mouseDoubleClickEvent(QMouseEvent * event)
{

	//do something
	//if(rect().contains(event->pos()))
	//	emit dragDoubleClicked();
}


void DragButton::hold_slot()
{
	isHold = 1;
	isPress = 0;
	m_aniTimer->stop();
	m_scaling = m_InitialScaling;
}


void DragButton::upDownloadProcess(qint64 bytesReceived, qint64 bytesTotal)
{
	m_bytesReceived = bytesReceived;
	m_bytesTotal = bytesTotal;
}

void DragButton::upStatusChanged(APPDOWNLOADETYPE appDownloadType)
{
	statusAppButton = appDownloadType;
	update();
}