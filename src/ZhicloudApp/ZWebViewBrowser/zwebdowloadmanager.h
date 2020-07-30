#ifndef ZWEBDOWLOADMANAGER_H
#define ZWEBDOWLOADMANAGER_H

#include <QDialog>
#include <QWidget>
#include <QAbstractListModel>
#include <QFileIconProvider>
#include <QIcon>
#include <QList>
#include <QMouseEvent>
#include <QMetaEnum>
#include "ui_zwebdowloadmanager.h"
#include "zwebdownloaditem.h"
class ZWebDownloadModel;


class DownloadModel;
class ZWebDowloadManager : public QDialog ,public Ui_ZWebDowloadManager
{
    Q_OBJECT

public:
    enum RemovePolicy {
        Never,
        Exit,
        SuccessFullDownload
    };
    Q_ENUM(RemovePolicy)

    explicit ZWebDowloadManager(QWidget *parent = 0);
    ~ZWebDowloadManager();

    ZWebDowloadManager::RemovePolicy removePolicy() const;
    int activeDownloads() const;
public slots:
    void download(QNetworkReply *download);
    void cleanup();
private slots:
    void updateRow();

    void save() const;
private:


//    //AutoSaver *m_autoSaver;
    ZWebDownloadModel *m_model;
    QFileIconProvider *m_iconProvider;
    QList<ZWebDownloadItem *> m_downloadItems;
    RemovePolicy m_removePolicy;
    friend class ZWebDownloadModel;
    void addItem(ZWebDownloadItem *widgetItem);
    void updateItemCount();
    void load();
    friend class ZWebDownloadModel;

    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
	QPixmap m_bg;
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent* event);
};



class ZWebDownloadModel : public QAbstractListModel
{
    friend class ZWebDowloadManager;
    Q_OBJECT

public:
    ZWebDownloadModel(ZWebDowloadManager *downloadManager, QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());


private:
    ZWebDowloadManager *m_downloadManager;
};



#endif // ZWEBDOWLOADMANAGER_H


