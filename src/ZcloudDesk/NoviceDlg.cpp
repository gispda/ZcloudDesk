#include "NoviceDlg.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <QSettings>
#include <QTimer>
#include "SingleApplication.h"
#include "ZcloudDesk.h"

NoviceDlg::NoviceDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setModal(true);
	m_bg.load(":/ZcloudDesk/image/Novice/appHelpBg.png");

	//setAttribute(Qt::WA_DeleteOnClose);
	QDesktopWidget* desktop = QApplication::desktop();
	QRect availableRect = desktop->availableGeometry();
	this->setGeometry(availableRect);

	photoX = (availableRect.width() - 814) / 2;
	photoY = (availableRect.height() - 714) / 2;
	ui.photoWidget->move(photoX, photoY);
	connect(ui.nextPushButton, SIGNAL(clicked()), this, SLOT(onNextBtn()));
	QTimer::singleShot(20, this, SLOT(onNextBtn()));
	connect(ui.skipPushButton, SIGNAL(clicked()), this, SLOT(onClose()));
	this->installEventFilter(this);
}

NoviceDlg::~NoviceDlg()
{
}



bool NoviceDlg::eventFilter(QObject * obj, QEvent * e)
{
	if (obj == this)
	{
		if (e->type() == QEvent::MouseButtonRelease)
		{
			onNextBtn();
		}
	}
	return QDialog::eventFilter(obj, e);
}


void NoviceDlg::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Escape:
		break;
	case  Qt::Key_F4:
		if (event->modifiers() == Qt::AltModifier)
		{
			event->ignore();
			break;
		}
	default:
		QDialog::keyPressEvent(event);
	}
}


void NoviceDlg::paintEvent(QPaintEvent* event)
{
	QPainter painter;
	painter.begin(this);
	painter.drawPixmap(rect(), m_bg);
	painter.end();
}

void NoviceDlg::onNextBtn()
{
	m_nPage++;
	ZcloudDesk *ptr = qobject_cast<ZcloudDesk*>(SingleApplication::instance()->mainWindow);
	if (!ptr) return;

	QRect rect;

	ui.frame2->hide();
	switch (m_nPage)
	{
	case 1:
		rect = ptr->getWidgetRect(1);
		ui.frame->move(rect.x(), rect.y());
		break;
	case 2:
	{
		rect = ptr->getWidgetRect(2);
		ui.photoWidget->setStyleSheet("QWidget#photoWidget{border-image: url(:/ZcloudDesk/image/Novice/appCenter.png);}");
		ui.frame->setStyleSheet("border-image: url(:/ZcloudDesk/image/Novice/appCenter_1.png);");
		ui.frame->setGeometry(rect.x(), rect.y(),106,34);
		ui.frame2->move(this->width() - 287, 70);
		ui.frame2->show();
		break;
	}
	case 3:
		rect = ptr->getWidgetRect(4);
		ui.photoWidget->setStyleSheet("QWidget#photoWidget{border-image: url(:/ZcloudDesk/image/Novice/msgCenter.png);}");
		ui.frame->setStyleSheet("border-image: url(:/ZcloudDesk/image/Novice/msgCenter_1.png);");
		ui.frame->setGeometry(rect.x() - 18, rect.y(), 78, 34);
		break;
	case 4:
	{
		//计算器
		ui.photoWidget->setStyleSheet("QWidget#photoWidget{border-image: url(:/ZcloudDesk/image/Novice/calculator.png);}");
		ui.frame->hide();

	}
	break;
	case 5:
	{
		//日历
		ui.photoWidget->setStyleSheet("QWidget#photoWidget{border-image: url(:/ZcloudDesk/image/Novice/calendar.png);}");
		ui.frame->hide();
		break;
	}
	case 6:
		rect = ptr->getWidgetRect(5);
		ui.photoWidget->setStyleSheet("QWidget#photoWidget{border-image: url(:/ZcloudDesk/image/Novice/setCenter.png);}");
		ui.frame->setStyleSheet("border-image: url(:/ZcloudDesk/image/Novice/setCenter_1.png);");
		ui.frame->setGeometry(rect.x() - 18, rect.y(), 78, 34);
		ui.nextPushButton->setText(QString::fromLocal8Bit("立即体验"));
		ui.frame->show();
		break;
	case 7:
	{
		onClose();
		return;
	}
	break;
	default:
		break;
	}
	this->show();
}

void NoviceDlg::onClose()
{
	Database::GetInstance()->setLoginSet(QString("update loginSet set showGuide=false where id='1';"));
	close();
}
