#include <QWidget>
#include <QMenu>
#include "ui_UploadLicenseDlg.h"
#include "ZcloudCommonWidget.h"
#include "EntInfoDataDefine.h"
#include "Database.h"
class UploadLicenseDlg : public QDialog
{
	Q_OBJECT

public:
	UploadLicenseDlg(UserInfoStruct* _userinfo,QWidget *parent = 0);
	~UploadLicenseDlg();


public:
	QString getLicenseUrl() const
	{
		return m_strUrl;
	}
signals:
	void sigUpdateSucessed();
private slots:
	bool onOpenFile();
	bool upload();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:


	Ui::UploadLicenseDlg ui;
	QString	m_strFileName;

	UserInfoStruct* m_userinfo;
	QString m_strUrl;
	QPoint dPos;
};
