#ifndef EntCenterNewWidget_H
#define EntCenterNewWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_EntCenterNewWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"
#include "EntCenterMemberWidget.h"
#include "EntCenterInfoWidget.h"
#include "EntCenterMainWidget.h"



class EntCenterNewWidget : public QWidget
{
	Q_OBJECT

public:
	EntCenterNewWidget(QWidget *parent = 0);
	~EntCenterNewWidget();

	void init(EntCenterInfo*	info);
	//!设置用户数据
	void setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId, QString strUserName);

signals:
	//!切换账号
	void sigSwitchAcc(int, bool, QString, QString);

protected:
	bool eventFilter(QObject *target, QEvent *e);


	private slots:
	void onShowInfo();
	void onShowMember();
	void onShowMain();
	//!复制税号
	void onCopyBtnClick();
	//!账号切换
	void onSwitchBtnClick();

private:


	QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;
	bool	m_isNetActive	= true;
	Ui::EntCenterNewWidget ui;

	bool	m_bJoinEnt = true;
	bool	m_bHasMember = true;
	QWidget* m_pUserDefult = NULL;
	EntCenterMemberWidget* mp_EntCenterMember;
	EntCenterInfoWidget* mp_EntCenterInfo;
	EntCenterMainWidget* mp_EntCenterMain;


};

#endif // EntCenterNewWidget_H
