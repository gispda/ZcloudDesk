#include "zwebdowloadmanager.h"
#include <QtWebKit/QWebSettings>
#include <QPainter>

ZWebDowloadManager::ZWebDowloadManager(QWidget *parent) :
    QDialog(parent)
 // , m_autoSaver(new AutoSaver(this))
  , m_iconProvider(0)
  , m_removePolicy(Never)
{
   setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground, true);

    m_bg.load(":/new/imageFile/ZWebViewBrowserImage/downloadList.png");

    setStyleSheet("outline: none");
    downloadsView->setShowGrid(false);
    downloadsView->verticalHeader()->hide();
    downloadsView->horizontalHeader()->hide();
    downloadsView->setAlternatingRowColors(true);
    downloadsView->horizontalHeader()->setStretchLastSection(true);
    m_model = new ZWebDownloadModel(this);
    downloadsView->setModel(m_model);
    connect(cleanupButton, SIGNAL(clicked()), this, SLOT(cleanup()));
    load();
}

ZWebDowloadManager::~ZWebDowloadManager()
{
    save();
}

void ZWebDowloadManager::download(QNetworkReply *reply)
{
	if (!reply || reply->url().isEmpty())
	{
		if (reply)
			reply->deleteLater();
		return;
	}
       
    QVariant header = reply->header(QNetworkRequest::ContentLengthHeader);
    bool ok;
    int size = header.toInt(&ok);
	if (ok && size == 0)
	{
		reply->deleteLater();
		return;
	}
        
    ZWebDownloadItem *widgetItem = new ZWebDownloadItem(reply);
    addItem(widgetItem);
}

void ZWebDowloadManager::cleanup()
{
    if (m_downloadItems.isEmpty())
        return;
    m_model->removeRows(0, m_downloadItems.count());
    updateItemCount();
    if (m_downloadItems.isEmpty() && m_iconProvider) {
        delete m_iconProvider;
        m_iconProvider = 0;
    }
}

ZWebDowloadManager::RemovePolicy ZWebDowloadManager::removePolicy() const
{
    return m_removePolicy;
}

int ZWebDowloadManager::activeDownloads() const
{
    int count = 0;
    for (int i = 0; i < m_downloadItems.count(); ++i) {
        if (m_downloadItems.at(i)->stopIsEnabled())
            ++count;
    }
    return count;
}

void ZWebDowloadManager::addItem(ZWebDownloadItem *widgetItem)
{
    //下载完成
    connect(widgetItem, SIGNAL(statusChanged()),this, SLOT(updateRow()));
    int row = m_downloadItems.count();
    m_model->beginInsertRows(QModelIndex(), row, row);
    m_downloadItems.append(widgetItem);
    m_model->endInsertRows();
    updateItemCount();
    if (row == 0)
        show();
    downloadsView->setIndexWidget(m_model->index(row, 0), widgetItem);
    QIcon icon = style()->standardIcon(QStyle::SP_FileIcon);
    widgetItem->fileIcon->setPixmap(icon.pixmap(48, 48));
	downloadsView->setRowHeight(row, widgetItem->sizeHint().height());
}

void ZWebDowloadManager::updateItemCount()
{
    int count = m_downloadItems.count();
    itemCount->setText(count == 1 ? tr("1 ") : tr("%1 ").arg(count));
}

void ZWebDowloadManager::load()
{
    QSettings settings;
    settings.beginGroup(QLatin1String("downloadmanager"));
    QSize size = settings.value(QLatin1String("size")).toSize();
    if (size.isValid())
        resize(size);
    QByteArray value = settings.value(QLatin1String("removeDownloadsPolicy"), QLatin1String("Never")).toByteArray();
    QMetaEnum removePolicyEnum = staticMetaObject.enumerator(staticMetaObject.indexOfEnumerator("RemovePolicy"));
    m_removePolicy = removePolicyEnum.keyToValue(value) == -1 ?
                        Never :
                        static_cast<RemovePolicy>(removePolicyEnum.keyToValue(value));

    int i = 0;
    QString key = QString(QLatin1String("download_%1_")).arg(i);
    while (settings.contains(key + QLatin1String("url"))) {
        QUrl url = settings.value(key + QLatin1String("url")).toUrl();
        QString fileName = settings.value(key + QLatin1String("location")).toString();
        bool done = settings.value(key + QLatin1String("done"), true).toBool();
        if (!url.isEmpty() && !fileName.isEmpty()) {
            ZWebDownloadItem *item = new ZWebDownloadItem(0, this);
            item->m_output.setFileName(fileName);
            item->fileNameLabel->setText(QFileInfo(item->m_output.fileName()).fileName());
            item->m_url = url;
            item->m_downloadStatus = DownloadStatus::STOP;
            item->setButton();
            if(done)
            {
                item->openDirButton->setEnabled(true);
                item->openDirButton->show();
                item->openButton->setEnabled(true);
                item->openButton->show();
                item->stopButton->setEnabled(false);
                item->stopButton->hide();
                item->suspendButton->setEnabled(false);
                item->suspendButton->hide();
            }
            addItem(item);
        }
        key = QString(QLatin1String("download_%1_")).arg(++i);
    }
    settings.endGroup();
    cleanupButton->setEnabled(m_downloadItems.count() - activeDownloads() > 0);
}

void ZWebDowloadManager::save() const
{
    QSettings settings;
    settings.beginGroup(QLatin1String("downloadmanager"));
    QMetaEnum removePolicyEnum = staticMetaObject.enumerator(staticMetaObject.indexOfEnumerator("RemovePolicy"));
    settings.setValue(QLatin1String("removeDownloadsPolicy"), QLatin1String(removePolicyEnum.valueToKey(m_removePolicy)));
    settings.setValue(QLatin1String("size"), size());
    if (m_removePolicy == Exit)
        return;

    for (int i = 0; i < m_downloadItems.count(); ++i) {
        QString key = QString(QLatin1String("download_%1_")).arg(i);
        settings.setValue(key + QLatin1String("url"), m_downloadItems[i]->m_url);
        settings.setValue(key + QLatin1String("location"), QFileInfo(m_downloadItems[i]->m_output).filePath());
        settings.setValue(key + QLatin1String("done"), m_downloadItems[i]->downloadedSuccessfully());
    }
    int i = m_downloadItems.count();
    QString key = QString(QLatin1String("download_%1_")).arg(i);
    while (settings.contains(key + QLatin1String("url"))) {
        settings.remove(key + QLatin1String("url"));
        settings.remove(key + QLatin1String("location"));
        settings.remove(key + QLatin1String("done"));
        key = QString(QLatin1String("download_%1_")).arg(++i);
    }
    settings.endGroup();
}

//下载完成
void ZWebDowloadManager::updateRow()
{
    ZWebDownloadItem *widget = qobject_cast<ZWebDownloadItem*>(sender());
    int row = m_downloadItems.indexOf(widget);//找到索引位置
    if (-1 == row)
        return;
    if (!m_iconProvider)
        m_iconProvider = new QFileIconProvider();
    QIcon icon = m_iconProvider->icon(widget->m_output.fileName());
    if (icon.isNull())
        icon = style()->standardIcon(QStyle::SP_FileIcon);
    widget->fileIcon->setPixmap(icon.pixmap(48, 48));
    downloadsView->setRowHeight(row, widget->minimumSizeHint().height());

    bool remove = false;

    QWebSettings *globalSettings = QWebSettings::globalSettings();
    if (!widget->downloading()
        && globalSettings->testAttribute(QWebSettings::PrivateBrowsingEnabled))
        remove = true;

    if (widget->downloadedSuccessfully()
        && removePolicy() == ZWebDowloadManager::SuccessFullDownload) {
        remove = true;
    }
    if (remove)
        m_model->removeRow(row);

    cleanupButton->setEnabled(m_downloadItems.count() - activeDownloads() > 0);
}

void ZWebDowloadManager::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();            // 获得部件当前位置
    this->mousePos = event->globalPos();     // 获得鼠标位置
    this->dPos = mousePos - windowPos;       // 移动后部件所在的位置
}

void ZWebDowloadManager::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

void ZWebDowloadManager::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.drawPixmap(rect(), m_bg);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////



ZWebDownloadModel::ZWebDownloadModel(ZWebDowloadManager *downloadManager, QObject *parent)
    : QAbstractListModel(parent)
    , m_downloadManager(downloadManager)
{

}

QVariant ZWebDownloadModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= rowCount(index.parent()))
        return QVariant();
    if(role == Qt::ToolTipRole)
        if(!m_downloadManager->m_downloadItems.at(index.row())->downloadedSuccessfully())
            return m_downloadManager->m_downloadItems.at(index.row())->getdownloadInfoLabelText();
    return QVariant();
}

int ZWebDownloadModel::rowCount(const QModelIndex &parent) const
{
    return (parent.isValid()) ? 0 : m_downloadManager->m_downloadItems.count();;
}

bool ZWebDownloadModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(parent.isValid())
        return false;
    int lastRow = row + count - 1;
    for(int i = lastRow; i >= row; -- i)
    {
        if(m_downloadManager->m_downloadItems.at(i)->downloadedSuccessfully())
        {
           beginRemoveRows(parent, i, i);
           m_downloadManager->m_downloadItems.takeAt(i)->deleteLater();
           endRemoveRows();
        }
    }
    //m_downloadManager->m_autoSaver->changeOccurred();
    return true;
}
