#include "zwebviewbrowser.h"
#include "ui_zwebviewbrowser.h"
#include <QPropertyAnimation>
#include "bigData/bigDataInterface.h"


#define leftSty			"QPushButton{border-image: url(:/new/imageFile/ZWebViewBrowserImage/left.png);}QPushButton:hover{ border-image: url(:/new/imageFile/ZWebViewBrowserImage/left_click.png); }QPushButton:pressed{ border-image: url(:/new/imageFile/ZWebViewBrowserImage/left_click.png); }; "
#define leftStyEnabled	"border-image: url(:/new/imageFile/ZWebViewBrowserImage/left_off.png);"
#define rightSty		"QPushButton{border-image: url(:/new/imageFile/ZWebViewBrowserImage/right.png);}QPushButton:hover{ border - image: url(:/new/imageFile/ZWebViewBrowserImage/right_click.png); }QPushButton:pressed{ border-image: url(:/new/imageFile/ZWebViewBrowserImage/right_click.png); }; "
#define rightStyEnabled	"border-image: url(:/new/imageFile/ZWebViewBrowserImage/right_off.png);"

NetworkAccessManager *ZWebViewBrowser::s_networkAccessManager = 0;

ZWebViewBrowser::ZWebViewBrowser(QString classId, QString appId, bool bShow, QWidget *parent) :
    QWidget(parent),
	m_classId(classId),
	m_appId(appId),
    m_titleName(""),
    m_tabWidget(new WebTabWidget(this)),
    m_progressBar(new QProgressBar(this)),
    m_webDowloadManager(NULL),
    ui(new Ui::ZWebViewBrowser)
{
    ui->setupUi(this);
   // setAttribute(Qt::WA_DeleteOnClose);
	if (bShow)
	{
		resize(1195, 755);
		setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);//关闭后父控件不关闭
	}
	else
	{
		resize(1195, 755);
		setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);//关闭后父控件不关闭
		ui->maxPushButton->hide();
	}
    m_progressBar->setMaximumHeight(1);
    m_progressBar->setTextVisible(false);
    m_progressBar->setStyleSheet(QStringLiteral("QProgressBar {border: 0px } QProgressBar::chunk { background-color: red; }"));
    QVBoxLayout *layout = new QVBoxLayout(ui->widget);
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->addWidget(m_progressBar);
    layout->addWidget(m_tabWidget);

    connect(m_tabWidget, &WebTabWidget::loadProgress, this, &ZWebViewBrowser::handleWebViewLoadProgress);
    connect(m_tabWidget, &WebTabWidget::webActionEnabledChanged, this, &ZWebViewBrowser::handleWebActionEnabledChanged);

    connect(m_tabWidget, SIGNAL(download(QNetworkReply*)),
            this, SLOT(downloadRequested(QNetworkReply*)));
	connect(ui->closePushButton, &QPushButton::clicked, [this]()
	{
		ui->closePushButton->setEnabled(false);
		m_tabWidget->clostTabAll();
	});
	connect(m_tabWidget, SIGNAL(tabWidgetClose()), this, SLOT(onClose()), Qt::QueuedConnection);
    ui->backPushButton->setStyleSheet(leftStyEnabled);
    ui->backPushButton->setEnabled(false);
    ui->forwardPushButton->setStyleSheet(rightStyEnabled);
    ui->forwardPushButton->setEnabled(false);

   // load("","");
}

ZWebViewBrowser::~ZWebViewBrowser()
{
    delete ui;
	if (!s_networkAccessManager)
	{
		delete s_networkAccessManager;
		s_networkAccessManager = NULL;
	}
}


void ZWebViewBrowser::downloadRequested(QNetworkReply *reply)
{
	QDesktopServices::openUrl(reply->url());
	/*if(m_webDowloadManager == NULL)
	{
	m_webDowloadManager = new ZWebDowloadManager(this);
	}
	m_webDowloadManager->download(reply);
	m_webDowloadManager->show();*/
}

void ZWebViewBrowser::handleWebActionEnabledChanged(QWebPage::WebAction action, bool enabled)
{
    switch (action) {
    case QWebPage::Back:
        ui->backPushButton->setEnabled(enabled);
        if (!enabled)
            ui->backPushButton->setStyleSheet(leftStyEnabled);
        else
            ui->backPushButton->setStyleSheet(leftSty);
        break;
    case QWebPage::Forward:
        ui->forwardPushButton->setEnabled(enabled);
        if (!enabled)
            ui->forwardPushButton->setStyleSheet(rightStyEnabled);
        else
            ui->forwardPushButton->setStyleSheet(rightSty);
        break;
    case QWebPage::Reload:
        ui->flushPushButton->setEnabled(enabled);
        break;
    case QWebPage::Stop:

        break;
    default:
        qWarning("Unhandled webActionChanged singal");
    }
}

void ZWebViewBrowser::handleWebViewLoadProgress(int progress)
{
   // static QIcon stopIcon(QStringLiteral(":process-stop.png"));
    //static QIcon reloadIcon(QStringLiteral(":view-refresh.png"));

    if (progress < 100 && progress > 0) {
        //加载中
    }
    else {
        //加载完成
    }
    m_progressBar->setValue(progress < 100 ? progress : 0);
}

void ZWebViewBrowser::load(QString url, QString name)
{
    //url = "http://mirrors.ustc.edu.cn/qtproject/archive/qt/5.7/5.7.1/qt-opensource-windows-x86-msvc2015-5.7.1.exe";
    //url = "https://www.baidu.com/";'
    //url = "http://115.159.158.244/appupdata/进销项发票管理系统V4.369.exe";
	//url = "http://rj.baidu.com/soft/detail/17016.html?ald";
	//url = "http://www.youku.com/";
    m_tabWidget->setUrl(QUrl::fromUserInput(url));
    if (!name.isEmpty())
    {
        m_titleName = name;
        ui->name_label->setText(name);
        setWindowTitle(name);
    }
}


WebTabWidget* ZWebViewBrowser::tabWidget()
{
    return m_tabWidget;
}

//刷新
void ZWebViewBrowser::on_flushPushButton_clicked()
{
    m_tabWidget->triggerWebPageAction(QWebPage::WebAction(QWebPage::Reload));
}

//向后
void ZWebViewBrowser::on_backPushButton_clicked()
{
    m_tabWidget->triggerWebPageAction(QWebPage::Back);
}

//向前
void ZWebViewBrowser::on_forwardPushButton_clicked()
{
    m_tabWidget->triggerWebPageAction(QWebPage::Forward);

}

void ZWebViewBrowser::on_maxPushButton_clicked()
{
    if(!this->isMaximized())
    {
        this->showMaximized();
        ui->maxPushButton->setStyleSheet("QPushButton{border-image: url(:/new/imageFile/ZWebViewBrowserImage/max2.png);}"
                                         "QPushButton:hover{border-image: url(:/new/imageFile/ZWebViewBrowserImage/max2_click.png);}"
                                         "QPushButton:pressed{border-image: url(:/new/imageFile/ZWebViewBrowserImage/max2_click.png);};"
                                         );
    }
    else
    {
        this->showNormal();
        ui->maxPushButton->setStyleSheet("QPushButton{border-image: url(:/new/imageFile/ZWebViewBrowserImage/max.png);}"
                                         "QPushButton:hover{border-image: url(:/new/imageFile/ZWebViewBrowserImage/max_click.png);}"
                                         "QPushButton:pressed{border-image: url(:/new/imageFile/ZWebViewBrowserImage/max_click.png);};"
                                         );
    }
}

void ZWebViewBrowser::on_miniPushButton_clicked()
{
    this->showMinimized();
}



void ZWebViewBrowser::onClose()
{
//	if ((!m_classId.isEmpty()) && (!m_appId.isEmpty()))
//	{
//		BigDataInterface *bigDataInterface = BigDataInterface::GetInstance();
//		bigDataInterface->socketPost(ClosAction, m_classId, m_appId);
//	}
	if (!m_appId.isEmpty())
	{
		BigDataInterface::GetInstance()->socketPost(QString("%1,%2,%3,%4").arg("M01").arg("OP001").arg("AAC013").arg(m_appId));
	}

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacityWeb");
    animation->setDuration(200);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
}


NetworkAccessManager * ZWebViewBrowser::networkAccessManager()
{
    if (!s_networkAccessManager) {
		s_networkAccessManager = new NetworkAccessManager();
        //s_networkAccessManager->setCookieJar(new CookieJar);
    }
    return s_networkAccessManager;
}

void ZWebViewBrowser::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();            // 获得部件当前位置
    this->mousePos = event->globalPos();     // 获得鼠标位置
    this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void ZWebViewBrowser::mouseDoubleClickEvent(QMouseEvent * event)
{
    on_maxPushButton_clicked();

}

void ZWebViewBrowser::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}


void ZWebViewBrowser::keyPressEvent(QKeyEvent  *event)
{
    if (event->modifiers() == (Qt::ShiftModifier | Qt::ControlModifier)  && event->key() == Qt::Key_D )
    {
        if(m_webDowloadManager == NULL)
        {
            m_webDowloadManager = new ZWebDowloadManager(this);
        }
        m_webDowloadManager->show();
    }
}
