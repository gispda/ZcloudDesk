#ifndef SWITCHACCWIDGET_H
#define SWITCHACCWIDGET_H

#include <QWidget>
#include "ui_SwitchAccWidget.h"
#include "qevent.h"
#include "Database.h"

class SwitchAccWidget : public QWidget
{
	Q_OBJECT

public:
	SwitchAccWidget(QString strUid,QString strToken, QString strUserName,QString strMobile,QString strCompId, QWidget *parent = 0);
	~SwitchAccWidget();

signals:
	void sigSwitchAcc(int, bool, QString, QString);
private slots:
	void onTextChanged(const QString& strText);
	void onSwitchAcc(int nLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd);
protected:
	bool eventFilter(QObject *target, QEvent *e);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	//!��ȡ��ǰ�û�����������ҵ
	bool winHttpGetCompanyList(QString strTaxno, QString strToken, QString& strRet);

	//!��ȡ��ǰ�û�����������ҵ
	void getCompanyList();

	//!��ʾ�б�
	void showListWidget(QString strText);

	//!��ȡ�л��˺��б�
	void getSwitchInfo();

	//!ע���˰���������ݿ���д���(��ʾ������¼���������ݿ���������Ϣ)
	bool isTaxExistRegedit(QString strTaxNo);

	//!�ӿڻ�ȡ�������������ݿ���д���(��ʾ������¼���������ݿ���������Ϣ)
	bool isTaxExistInterface(QString strUid, QString strCompId);

	//!��ǰ��¼�˺�uid
	QString m_strUid;
	QString	m_strToken;
	//!��ǰ��¼��˾id
	QString	m_strCompId;
	QString	m_strUserName;
	QString	m_strMobile;
	vtrSwitchAccInfos m_vtrAccInfos;

	Ui::SwitchAccWidget ui;
	QPoint dPos;
};

#endif // SWITCHACCWIDGET_H
