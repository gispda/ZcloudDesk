#ifndef MESSAGETIPDLG_H
#define MESSAGETIPDLG_H

#include <QDialog>
#include "ui_MessageTipDlg.h"
#include "qevent.h"

class MessageTipDlg : public QDialog
{
	Q_OBJECT

public:
	enum EN_BTN_TYPE
	{
		EN_CLOSE = 0,		//!ֻһ���رհ�ť
		EN_OKCANCEL = 1,	//!ȷ��ȡ����ť
		EN_UPDATE = 2,		//!��������������ť
	};

	MessageTipDlg(EN_BTN_TYPE enBtnType, QString strTitle, QString strMsg, QWidget *parent = 0);
	~MessageTipDlg();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private:
	void init();
private:
	Ui::MessageTipDlg ui;
	QPoint dPos;
	EN_BTN_TYPE	m_enBtnType;
	QString m_strTitle;
	QString m_strMsg;
};

#endif // MESSAGETIPDLG_H
