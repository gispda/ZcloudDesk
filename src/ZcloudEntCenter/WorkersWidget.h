#pragma once

#include <QWidget>
#include "ui_WorkersWidget.h"
#include "ZcloudCommonWidget.h"
#include "WorkerDetailWidget.h"
#include "WorkerCommentWidget.h"

class WorkersWidget : public QWidget
{
	Q_OBJECT

public:
	WorkersWidget(QString strUid, QString strToken,QWidget *parent = Q_NULLPTR);
	~WorkersWidget();

signals:
	void sigEditMemberSucessed(const QString&, const QString&);

public:
	int getBlockSize() const;
	int getMaxPage() const;
	int getCurrentPage() const;



	// 其他组件只需要调用这两个函数即可
	void setMaxPage(int maxPage);   // 当总页数改变时调用
	void setCurrentPage(int currentPage, bool signalEmitted = false); // 修改当前页时调用
protected:
	virtual bool eventFilter(QObject *watched, QEvent *e);

signals:
	void currentPageChanged(int page);


protected:

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:

	//void onworkerComment(QString);
	bool getCurrentPageView(int curpage);
	
private:
	//!显示工单
	bool showWorkers();

	bool fillPages(QString strpage);
	

	void onFreshWorkers();

	void cleanAllWorker();

private:
	//!获取工单
	bool winHttpGetWorks(QString strPage, QString strToken, QString& strRet);



	void setBlockSize(int blockSize);
	void updatePageLabels();
	void initializePages();






	Ui::WorkersWidget ui;

	int blockSize;
	int maxPage;
	int currentPage;
	QList<QLabel *> *pageLabels;

	QString m_strUid;
	QString	m_strToken;
	QPoint dPos;

	WorkerDetailWidget*	m_pDetailWidget;
	WorkerCommentWidget*	m_pCommentWidget;
};
