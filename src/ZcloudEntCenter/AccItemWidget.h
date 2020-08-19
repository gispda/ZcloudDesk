#ifndef ACCITEMWIDGET_H
#define ACCITEMWIDGET_H

#include <QWidget>
#include "ui_AccItemWidget.h"
#include "Database.h"
class AccItemWidget : public QWidget
{
	Q_OBJECT

public:
	AccItemWidget(bool bLogin, stSwitchAccInfo* pAccInfo, QString strFindText, QWidget *parent = 0);
	AccItemWidget(QString strComId, QString strTaxNo, QString strComName, QString strLogo, int nState, QWidget *parent = 0);
	~AccItemWidget();

	void setReviewStatue(bool bStatue);
protected:
	bool eventFilter(QObject *target, QEvent *e);
signals:
	void sigSwitchAcc(int, bool, QString, QString);
	void sigJoinEnt(QString);
	void sigCancelReview(QString);
private slots:
	void onSwitchBtnClick();
	void onJoinEntBtnClick();
private:
	void setElideText(int nPixSize, QLabel* pLabel, const QString& strText);

	Ui::AccItemWidget ui;
	bool m_bLogin = false;
	QString			m_strComId;
	stSwitchAccInfo* m_pAccInfo;
};

#endif // ACCITEMWIDGET_H
