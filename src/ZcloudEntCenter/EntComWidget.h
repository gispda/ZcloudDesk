#ifndef ENTCOMWIDGET_H
#define ENTCOMWIDGET_H

#include <QWidget>
#include "ui_EntComWidget.h"
#include "qevent.h"
#include "WebView.h"
class EntComWidget : public QWidget
{
	Q_OBJECT

public:
	EntComWidget(QString strTitle,QString strUrl,bool bBig,QWidget *parent = 0);
	~EntComWidget();
signals:
	//�޸���ҵ���ϳɹ�
	void sigSignCompeteSucessed(bool,int);
	//�޸��û���ְλ
	void sigAccountSetSucessed(const QString& strName, const QString& strJob);
	//������
	void sigSignCompanySucessed(bool, int);
	//���ֻ��ųɹ�
	void sigSignBindingSucceeded(const QString&);

	void sendVipListSignals(QStringList, QStringList, QStringList);
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private slots:
	void closeWindow();
	void onLoadFinished(bool);
	void onGetVipList(const QString&);
private:
	QPoint dPos;
	WebView*	m_pWebView = NULL;
	Ui::EntComWidget ui;
};

#endif // ENTCOMWIDGET_H
