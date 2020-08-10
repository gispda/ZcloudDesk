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
	//!获取当前用户所属所有企业
	bool winHttpGetCompanyList(QString strTaxno, QString strToken, QString& strRet);

	//!获取当前用户所属所有企业
	void getCompanyList();

	//!显示列表
	void showListWidget(QString strText);

	//!获取切换账号列表
	void getSwitchInfo();

	//!注册表税号已在数据库表中存在(表示曾经登录过，在数据库留下了信息)
	bool isTaxExistRegedit(QString strTaxNo);

	//!接口获取的数据已在数据库表中存在(表示曾经登录过，在数据库留下了信息)
	bool isTaxExistInterface(QString strUid, QString strCompId);

	//!当前登录账号uid
	QString m_strUid;
	QString	m_strToken;
	//!当前登录公司id
	QString	m_strCompId;
	QString	m_strUserName;
	QString	m_strMobile;
	vtrSwitchAccInfos m_vtrAccInfos;

	Ui::SwitchAccWidget ui;
	QPoint dPos;
};

#endif // SWITCHACCWIDGET_H
