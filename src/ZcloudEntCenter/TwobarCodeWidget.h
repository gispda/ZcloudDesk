#pragma once

#include <QWidget>
#include "ui_TwobarCodeWidget.h"
#include "ZcloudCommonWidget.h"

class TwobarCodeWidget : public QWidget
{
	Q_OBJECT

public:
	TwobarCodeWidget(QString strcompanyid, QString strToken,QString strTitle, QWidget *parent = Q_NULLPTR);
	~TwobarCodeWidget();

signals:
	//!����
	void sigDetial(QString);
	//������
	void sigEvaluate(QString, QString, QString);

protected:

	void setGrade(int);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	QPixmap generateQRcode(char *string);


	///��Զ�̷�������ȡ��ά��
	void getCodeImg();
	bool winHttpGetTwoCodeInfo(QString strCompanyid, QString strToken, QString& strRet);

private:

	Ui::TwobarCodeWidget ui;


	QString m_strcompanyid;
	QString m_strToken;

	QString m_tbid;
	QString m_tburl;
	QString m_tblocalpath;

	QPoint dPos;
};
