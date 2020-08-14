
#include <QWidget>
#include "qevent.h"
#include "ui_EntCenterInfoWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"
#include "ZcloudCommonWidget.h"
#include "EntInfoDataDefine.h"
#include "Database.h"

class EntCenterInfoWidget : public QWidget
{
	Q_OBJECT

public:
	EntCenterInfoWidget(EntCenterInfo*	info, UserInfoStruct* userInfo, QWidget *parent = 0);
	~EntCenterInfoWidget();

	//!初始化用户信息 
	void init(EntCenterInfo* info);

	private slots:
	void onEntEditBtnClick();
	void onInvoiceEditBtnClick();
	void onUpdateinvoiceSucessed();
	void onUpdateEntSucessed();

protected:
	bool eventFilter(QObject *target, QEvent *e);
private:

	//!获取企业资料
	bool winHttpGetEntInfo(QString strUid, QString strToken, QString& strRet);

	UserInfoStruct* m_userInfo;
	EntCenterInfo*	m_pInfo;
	//stEntInfo		m_stEntInfo;
	//stInvoiceInfo	m_stInvoiceInfo;
	//QString			m_strUid;
	//QString			m_strToken;
	Ui::EntCenterInfoWidget ui;
};
