//���½�Զ�̷���
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
	//!0���ǻ�Ա  -1��Ա��ʱ  1��Ա����ʹ��
	static int  checkVipState(QString strTaxNo);
};

#endif // QREMOTESERVICEDLG_H
