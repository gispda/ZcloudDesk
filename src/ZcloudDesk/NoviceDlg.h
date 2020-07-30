#pragma once

#include <QDialog>
#include "ui_NoviceDlg.h"

class NoviceDlg : public QDialog
{
	Q_OBJECT

public:
	NoviceDlg(QWidget *parent = Q_NULLPTR);
	~NoviceDlg();

private:
	Ui::NoviceDlg ui;


public slots:
	void onNextBtn();
	void onClose();
protected:
	void paintEvent(QPaintEvent*	event);
	void keyPressEvent(QKeyEvent *event);
	bool eventFilter(QObject * obj, QEvent * e);
private:
	QPixmap			m_bg;
	int				m_nPage = 0;
	int photoX;
	int photoY;
};
