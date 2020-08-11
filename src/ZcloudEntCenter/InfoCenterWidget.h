#ifndef InfoCenterWidget_H
#define InfoCenterWidget_H

#include <QWidget>
#include "qevent.h"
#include "ui_InfoCenterWidget.h"
#include "EntDataBase.h"
#include "AppCommWidget.h"
#include "EntCenterNewWidget.h"
#include "UserCenterWidget.h"

class InfoCenterWidget : public QWidget
{
	Q_OBJECT

public:
	InfoCenterWidget(QWidget *parent = 0);
	~InfoCenterWidget();
	//!�����û�����
	void setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId, QString strUserName);

	void init();

signals:

	

protected:
	//bool eventFilter(QObject *target, QEvent *e);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:
void showEntCenter();
void showUserCenter();	



private:
	//!��ѯ��ҵ��Ϣ
	bool winHttpGetCompanyInfo(QString strUid, QString strToken, QString& strRet);
	//!������ҵ��Ϣ
	bool analysisJson(const QString& strJson, EntCenterInfo& info);
	//!����û�ͷ���Ƿ���� ���ڷ���·�� ����������֮�󷵻�·��
	QString checkLogoExist(QString strUrl);
	Ui::InfoCenterWidget ui;
	QWidget* m_pUserDefult = NULL;
	EntCenterNewWidget* m_pEntCenter = NULL;
	UserCenterWidget* m_pUserCenter = NULL;
	QPoint dPos;
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
