#include "WallpaperWidget.h"
#include <QDesktopWidget>
#include <QFileInfo>
#include "ZcloudCommon.h"
#include "ZcloudBigData.h"
#include "JsInterface.h"
#include <qt_windows.h>
#include <wininet.h>
#include <ShlObj.h>
#include <ObjBase.h>
#include <QWebFrame>
WallpaperWidget::WallpaperWidget(QString strUrl, QWidget *parent)
	:  AppCommWidget("", true, parent)
{
	ui.setupUi(m_widget);
	resize(1116, 706);
	setObjectName("WallpaperWidget");
	setWindowTitle(QString::fromLocal8Bit("±ÚÖ½"));
	setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setAttribute(Qt::WA_DeleteOnClose);
	setStyleSheet("outline: none");

	connect(ui.closeButton, &QPushButton::clicked, [this]()
	{
		ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TWP003");
		close();
	});
	m_pWebView = new WebView(ui.FilletWidget);
	m_pWebView->setContextMenuPolicy(Qt::NoContextMenu);
	m_pWebView->setGeometry(0,50,1100,640);
	m_pWebView->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
	m_pWebView->load(QUrl::fromUserInput(strUrl));
	connect(m_pWebView, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished(bool)));
	connect(JsInterface::GetInstance(), SIGNAL(sigWallpaperDownloadLink(const QString&)), this, SLOT(onDownloadLink(const QString&)));

	QDesktopWidget* desktop = QApplication::desktop(); 
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
}

WallpaperWidget::~WallpaperWidget()
{
}

void WallpaperWidget::mousePressEvent(QMouseEvent *event)
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

void WallpaperWidget::mouseMoveEvent(QMouseEvent *event)
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

void WallpaperWidget::onLoadFinished(bool)
{
	m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("JsInterface", (QObject*)JsInterface::GetInstance());
}

void WallpaperWidget::onDownloadLink(const QString& strLink)
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TWP001", strLink);
	QString strFilePath = ZcloudComFun::downloadPic(strLink, QApplication::applicationDirPath().append("/CacheImage/wallpaperImage"));
	QFileInfo fileInfo(strFilePath);
	if (fileInfo.isFile())
	{
		setWallPaper(strFilePath);
	}
	else
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("ÌáÊ¾"), QString::fromLocal8Bit("ÏÂÔØÊ§°Ü£¬ÇëÉÔºóÖØÊÔ!"), this);
	}
	m_pWebView->page()->mainFrame()->evaluateJavaScript(QString("downloadCallback('1');"));
}

void WallpaperWidget::setWallPaper(QString strPicPath)
{
	QFileInfo fileInfo(strPicPath);
	strPicPath.replace("/", "\\");
	::CoInitialize(NULL);
	HRESULT	hr;
	IActiveDesktop*	pIAD;

	hr = CoCreateInstance(CLSID_ActiveDesktop, NULL, CLSCTX_INPROC_SERVER, IID_IActiveDesktop, (void**)&pIAD);

	if (!SUCCEEDED(hr))
	{
		return;
	}

	WCHAR	wszPath[MAX_PATH];
	const wchar_t * encodedName = reinterpret_cast<const wchar_t *>(strPicPath.utf16());


	hr = pIAD->SetWallpaper(encodedName, 0);
	if (!SUCCEEDED(hr))
	{
		return;
	}

	WALLPAPEROPT	wp = { 0 };
	wp.dwSize = sizeof(WALLPAPEROPT);

	QImage	img(strPicPath);
	int nImageWidth = img.width();
	int nImageHeight = img.height();
	if (nImageWidth < 800 || nImageHeight < 600)
	{
		wp.dwStyle |= WPSTYLE_CENTER;
	}
	else
	{
		wp.dwStyle |= WPSTYLE_STRETCH;
	}

	hr = pIAD->SetWallpaperOptions(&wp, 0);
	if (!SUCCEEDED(hr))
	{
		return;
	}

	hr = pIAD->ApplyChanges(AD_APPLY_ALL);
	if (!SUCCEEDED(hr))
	{
		return;
	}
	::CoUninitialize();
}
