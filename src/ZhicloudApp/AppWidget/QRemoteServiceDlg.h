//！新疆远程服务
#ifndef QREMOTESERVICEDLG_H
#define QREMOTESERVICEDLG_H

#include "publicWidgets/AppCommDialog.h"
#include <QMouseEvent>
#include "ZhicloudAppDataDefine.h"
class QRemoteServiceDlg : public AppCommDialog
{
	Q_OBJECT

public:
	QRemoteServiceDlg(QString strAppParams, bool bShow, QWidget *parent = NULL);
	~QRemoteServiceDlg();
	int IVO;
private slots:
	void onInvoceBtnClick();
	void onOtherBtnClick();
	void onVipBtnClick();
protected:
public:
	//!0不是会员  -1会员超时  1会员正常使用
	static int  checkVipState(QString strTaxNo);
};

#endif // QREMOTESERVICEDLG_H
