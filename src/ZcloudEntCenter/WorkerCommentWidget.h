#pragma once

#include <QWidget>
#include "ui_WorkerCommentWidget.h"
#include "ZcloudCommonWidget.h"
#include "WorkerDataBase.h"

class WorkerCommentWidget : public QWidget
{
	Q_OBJECT

public:
	WorkerCommentWidget(QString strworkid,QString strToken, QWidget *parent = Q_NULLPTR);
	~WorkerCommentWidget();

private:
	void cleanWidget();
	void fillWidget();

protected:
	bool eventFilter(QObject * watched, QEvent * event);
	void setLabelclicked(QLabel* plabel,bool isclicked);

	QString subString(QString& _ptext,QString strstart,QString strend)
	{
		int nst=0, ned=0;
		nst = _ptext.indexOf(strstart);
		ned = _ptext.lastIndexOf(strend);
		QString str = _ptext.mid(nst + 1, ned - nst - 1);
		return  str;
	}

public: 
signals:

	void sigDetial(QString);

	void sigEvaluate(QString, QString, QString);
public slots:
	bool onworkerComment(WorkerInfo _sinfo);


private slots:
	void push1();

	void setStarlabel(int star_level);

	void push2();
	void push3();
	void push4();
	void push5();
protected:

	void setGrade(int);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);



private:


	bool winHttpGetStarlabels(QString strcompanyid,QString strToken, QString& strRet);
	bool winHttpPostsubmitComment(QString strPost, QString strToken, QString& strRet);
	void setStartname(int starlevel);

private 
slots:
	void submitComment();
private:

	Ui::WorkerCommentWidget ui;
	//QMenu	*m_pMenu;
	//QAction *m_pActionRemoveOrderList;
	//QAction *m_pActionModifyOrderList;
	//QAction *m_pActionHandOver;
	//QString m_strUid;
	//QString m_strTrueName;
	//QString	m_strJob;
	bool m_blbstar1;
	bool m_blbstar2;
	bool m_blbstar3;
	bool m_blbstar4;
	bool m_blbstar5;
	bool m_blbstar6;

	int m_curlevel;

	WorkerInfo m_info;
	QMap<int,WorkerStarInfo> m_starinfo;

	QString m_strToken;
	QString m_strWorkerid;
	QString m_strWorkertitle;
	QString m_strState;
	QString m_strCreateTime;
	QString m_strAction2;
	QPoint dPos;
	int grades;

};
