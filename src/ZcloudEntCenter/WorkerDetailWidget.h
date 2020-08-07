#pragma once

#include <QWidget>
#include "ui_WorkerDetailWidget.h"
#include "ZcloudCommonWidget.h"
#include "WorkerDataBase.h"
#include <QMap>

#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>


class WorkerDetailWidget : public QWidget
{
	Q_OBJECT

public:
	WorkerDetailWidget(QString strworkid,QString strToken, QWidget *parent = Q_NULLPTR);


	
	~WorkerDetailWidget();

signals:
	//!详情
	void sigDetail(QString);
	//！评价
	void sigEvaluate(QString, QString, QString);

public slots:
	void onworkerDetail(QString strworkerid);
private slots:
	void openannexClick(QModelIndex index);
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);




	//获取工单详情
	bool winHttpGetWorksDetail(QString strWorkerid, QString strToken, QString& strRet);
	QString getStateColorStyle(QString _state);
	QString getStateColorStyleByTime(QString sttime);

public:

	
	void showWorkerDetail();


private:

	Ui::WorkerDetailWidget ui;
	//QMenu	*m_pMenu;
	//QAction *m_pActionRemoveOrderList;
	//QAction *m_pActionModifyOrderList;
	//QAction *m_pActionHandOver;
	//QString m_strUid;
	//QString m_strTrueName;
	//QString	m_strJob;
	QString m_strWorkerid;
	WorkerInfo m_info;
	QString m_strToken;
	QString m_strWokerdesc;
	QString m_subtime;
	QString m_starttime;
	QString m_completetime;

	int m_iscomment;

	QMap<QString, QString> m_annexmap;



	QStringListModel *m_Model;
	QStandardItemModel *m_ItemModel;


	QString m_strAction2;
	QPoint dPos;


	int blockSize;
	int maxPage;
	int currentPage;
	QList<QLabel *> *pageLabels;

	void setBlockSize(int blockSize);
	void updatePageLabels();
	void initializePages();
};
