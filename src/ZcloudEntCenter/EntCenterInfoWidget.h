
#include <QWidget>
#include "qevent.h"
#include "ui_EntCenterInfoWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"
#include "ZcloudCommonWidget.h"
#include "EntInfoDataDefine.h"
#include "Database.h"

class EntCenterInfoWidget : public AppCommWidget
{
	Q_OBJECT

public:
	EntCenterInfoWidget(EntCenterInfo*	info, QWidget *parent = 0);
	~EntCenterInfoWidget();

	//!��ʼ���û���Ϣ 
	void init(EntCenterInfo* info);

	private slots:
	void onEntEditBtnClick();
	void onInvoiceEditBtnClick();
	void onUpdateinvoiceSucessed();
	void onUpdateEntSucessed();

protected:
	bool eventFilter(QObject *target, QEvent *e);
private:

	//!��ȡ��ҵ����
	bool winHttpGetEntInfo(QString strUid, QString strToken, QString& strRet);


	EntCenterInfo*	m_pInfo;
	//stEntInfo		m_stEntInfo;
	//stInvoiceInfo	m_stInvoiceInfo;
	//QString			m_strUid;
	//QString			m_strToken;
	Ui::EntCenterInfoWidget ui;
};
