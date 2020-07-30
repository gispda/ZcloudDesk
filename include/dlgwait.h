#ifndef DLGWAIT_H
#define DLGWAIT_H

#include <QDialog>
#include <QMovie>

#include <QtCore/qglobal.h>

#ifdef ZHICLOUDAPP_LIB
# define ZHICLOUDAPP_EXPORT Q_DECL_EXPORT
#else
# define ZHICLOUDAPP_EXPORT Q_DECL_IMPORT
#endif




namespace Ui {
class DlgWait;
}
class ZHICLOUDAPP_EXPORT DlgWait : public QDialog
{
    Q_OBJECT

public:
	explicit DlgWait(QString hint = "", QWidget *parent = 0);
    ~DlgWait();
	void stop();
	void start();
	void stopMovie();
	void	setText(QString str);
private:
    Ui::DlgWait *ui;
    QMovie *movie;
};



class LoginWait : public QDialog
{
	Q_OBJECT

public:
	explicit LoginWait(QWidget *parent = 0);
	~LoginWait();
	void stop();
private:
	QMovie *movie;
};

#endif // DLGWAIT_H
