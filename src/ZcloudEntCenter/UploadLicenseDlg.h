#include <QWidget>
#include <QMenu>
#include "ui_UploadLicenseDlg.h"
#include "ZcloudCommonWidget.h"
#include "EntInfoDataDefine.h"

class UploadLicenseDlg : public QDialog
{
	Q_OBJECT

public:
	UploadLicenseDlg(QWidget *parent = 0);
	~UploadLicenseDlg();

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


	QPoint dPos;
};
