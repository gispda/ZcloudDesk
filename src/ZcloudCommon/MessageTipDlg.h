#ifndef MESSAGETIPDLG_H
#define MESSAGETIPDLG_H

#include <QDialog>
#include "ui_MessageTipDlg.h"
#include "qevent.h"
#include "ZcloudCommon.h"
class MessageTipDlg : public QDialog
{
	Q_OBJECT

public:
	MessageTipDlg(ZcloudComFun::EN_BTN_TYPE enBtnType, QString strTitle, QString strMsg, QWidget *parent = 0);
	MessageTipDlg(ZcloudComFun::EN_BTN_TYPE enBtnType, QString strTitle, QString strMsg, QString buttonStr_1, QString buttonStr_2, QWidget *parent = 0);
	~MessageTipDlg();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private:
	void init();
private:
	Ui::MessageTipDlg ui;
	QPoint dPos;
	ZcloudComFun::EN_BTN_TYPE	m_enBtnType;
	QString m_strTitle;
	QString m_strMsg;
	QString m_buttonStr_1;
	QString m_buttonStr_2;
};

#endif // MESSAGETIPDLG_H
