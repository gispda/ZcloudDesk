#include <QWidget>
#include <QMenu>
#include "ui_EntAppealDlg.h"
#include "ZcloudCommonWidget.h"
#include "EntInfoDataDefine.h"
#include "Database.h"
class EntAppealDlg : public QDialog
{
	Q_OBJECT

public:
	EntAppealDlg(stEntInfo* stEntInfo,UserInfoStruct* _userinfo, QWidget *parent = 0);
	~EntAppealDlg();
	bool eventFilter(QObject *target, QEvent *e);

public:
	QString getLicenseUrl() const
	{
		return m_strUrl;
	}
signals:
	void sigUpdateSucessed();
private slots:
	bool onOpenFile();
	void upload();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:


	Ui::EntAppealDlg ui;

	stEntInfo* m_stEntInfo;
	UserInfoStruct* m_userinfo;
	QString m_strUrl;
	QPoint dPos;
};
