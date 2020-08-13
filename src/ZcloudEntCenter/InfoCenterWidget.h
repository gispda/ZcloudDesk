#ifndef InfoCenterWidget_H
#define InfoCenterWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_InfoCenterWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"
#include "EntCenterNewWidget.h"
#include "UserCenterWidget.h"
#include "Database.h"

class InfoCenterWidget : public QWidget
{
	Q_OBJECT

public:
	InfoCenterWidget(UserInfoStruct* _userInfo, QWidget *parent = 0);
	~InfoCenterWidget();
	//!设置用户数据
	void setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId, QString strUserName);

	bool winHttpGetEntInfo(QString strTaxno, QString strToken, QString& strRet);

	bool loadEntInfo();


	void init();

signals:

	void sigSwitchAcc(int, bool, QString, QString);

protected:
	//bool eventFilter(QObject *target, QEvent *e);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);


private slots:
void showEntCenter();
void showUserCenter();	

void onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd);

private:
	//!查询企业信息
	bool winHttpGetCompanyInfo(QString strUid, QString strToken, QString& strRet);
	//!解析企业信息
	bool analysisJson(const QString& strJson, EntCenterInfo& info);
	//!检测用户头像是否存在 存在返回路径 不存在下载之后返回路径
	QString checkLogoExist(QString strUrl);
	Ui::InfoCenterWidget ui;
	QWidget* m_pUserDefault = NULL;
	EntCenterNewWidget* m_pEntCenter = NULL;
	UserCenterWidget* m_pUserCenter = NULL;
	QPoint dPos;


	EntCenterInfo m_stEntInfo;
	UserInfoStruct* m_userInfo;


	QString m_strUserName;
	QString m_strUid;
	QString m_strToken;
	QString m_strTrueName;
	QString m_strJob;
	QString m_strMobile;
	int		m_isLoginByTax;
	QString m_strCompId;
	bool	m_isNetActive = true;
	bool	m_bJoinEnt = true;
	bool	m_bHasMember = true;
};

#endif // InfoCenterWidget_H
