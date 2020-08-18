#ifndef UPDATETIPDLG_H
#define UPDATETIPDLG_H

#include <QDialog>
#include "ui_UpdateTipDlg.h"
#include "qevent.h"
#include "ZcloudCommon.h"
class UpdateTipDlg : public QDialog
{
	Q_OBJECT

public:
	UpdateTipDlg( QWidget *parent = 0);
	~UpdateTipDlg();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private:
	Ui::UpdateTipDlg ui;
	QPoint dPos;

};

#endif // UPDATETIPDLG_H
