#include "UploadLicenseDlg.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileDialog>
#include <QStandardPaths>
#include "ZcloudBigData.h"

UploadLicenseDlg::UploadLicenseDlg(QWidget *parent)
	: QDialog(parent)
{

	ui.setupUi(this);
	//setAttribute(Qt::WA_DeleteOnClose);
	setWindowTitle(QString::fromLocal8Bit("提示"));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowModality(Qt::NonModal);
	setStyleSheet("outline: none");


	ui.labelLicense->hide();

	connect(ui.clostPushButton, &QPushButton::clicked, [this](){
		close();
	});

	

	connect(ui.labelLicense, SIGNAL(clicked()), this, SLOT(onOpenFile()));
	connect(ui.labelUpload, SIGNAL(clicked()), this, SLOT(onOpenFile()));
	connect(ui.buttonOK, &QPushButton::clicked, this, &UploadLicenseDlg::upload);

}

UploadLicenseDlg::~UploadLicenseDlg()
{
}


bool UploadLicenseDlg::upload()
{
	if (!m_strFileName.isEmpty()){
		//提交数据
		//QString strUrl = QString("/param/trade-list");
		//return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
	}



	return true;
}

bool UploadLicenseDlg::onOpenFile()
{
	//QString path = QDir::currentPath();
	QString path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
	QString title = QString::fromLocal8Bit("选择营业执照图片");
	QString filter = QString::fromLocal8Bit("图片(*.jpg *.png);");
	QString filename = QFileDialog::getOpenFileName(this,title,path,filter);
	if (!filename.isEmpty()){
		this->m_strFileName = filename; 
		QPixmap pixmap;
		pixmap.load(filename);
		
		QPixmap scaledPixmap = pixmap.scaled(340, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation);
		ui.labelLicense->setAlignment(Qt::AlignCenter);
		ui.labelLicense->setPixmap(scaledPixmap);
	}
	
	ui.labelLicense->show();
	ui.labelUpload->hide();
	ui.labelTilte->hide();
	//QString strUrl = QString("/param/trade-list");
	//return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
	return true;
}


void UploadLicenseDlg::mousePressEvent(QMouseEvent *event)
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

void UploadLicenseDlg::mouseMoveEvent(QMouseEvent *event)
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