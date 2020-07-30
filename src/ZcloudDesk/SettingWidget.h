#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include "ui_SettingWidget.h"
#include "qevent.h"
#include "CommWidget.h"
#include "Database.h"
#include "AppCommWidget.h"
class SettingItemWidget: public QWidget
{
	Q_OBJECT

public:
	SettingItemWidget(QString strBkImage, AppDataInfo* pInfo, QWidget *parent = 0);
	~SettingItemWidget();
signals:
	void sigToolCheckChanged(QString, bool);
private slots:
	void onToolCheckChanged(int state);
private:
	AppDataInfo* m_pInfo = NULL;

};
class SettingWidget : public AppCommWidget
{
	Q_OBJECT

public:
	SettingWidget(QString strUid, QString strToken, QString strProvinceId,QWidget *parent = 0);
	~SettingWidget();

signals:
	void sigTopCheckChanged(bool);
	void sigRightCheckChanged(bool);
	void sigToolCheckChanged(QString strToolId, bool);
	void sigLogout();
	void showNoviceDlgSignal(bool);
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	bool eventFilter(QObject *target, QEvent *e);
private slots:
	
	/*
	*	��ఴť��Ӧ��
	*/

	//!��������
	void onDeskSettingBtnClick();

	//!�������
	void onFeedBackBtnClick();

	//!��������
	void onHelperBtnClick();

	//!�������� 
	void onAboutUsBtnClick();

	/*
	*	���������ڰ�ť��Ӧ��
	*/
	void onTopCheckChanged(int state);

	void onRightCheckChanged(int state);

	/*
	*	��������ڰ�ť��Ӧ��
	*/

	//!�ύ
	void onCommitBtnClick();

	//!����Ӧ��
	void onDeskAppBtnClick();

	//!�������
	void onDesignBtnClick();

	//!ƽ̨����
	void onErrorBtnClick();

	//!�����Ż�
	void onMajorBtnClick();

	//!����
	void onOtherBtnClick();

	//!�ı���仯
	void onTextChanged();

	//!�����������json
	int anyliseJson(const QString& strJson,QString& strFeedBackId);
	/*
	*	���������ڰ�ť��Ӧ��
	*/

	//!������ʾ
	void onDemoBtnClick();

	//!��������
	void onGuideBtnClick();

	//��ʹ�ð���
	void onHelpBtnClick();

	//�������ʾ�
	void onQuestionBtnClick();


	/*
	*	���������ڰ�ť��Ӧ��
	*/

	//!������
	void onCheckUpdateBtnClick();

	//!�˳���¼
	void onLogoutClick();

	//!�汾˵��
	void openVerDes();

private:
	//!��ʼ��
	void init();

	//!����б�
	void clearListWidget();

	//!��������connect��
	void deskSettingConnect();

	//!�������connect��
	void feedBackConnect();

	//!��������connect��
	void helpCenterConnect();

	//!��������connect��
	void aboutUsConnect();

	QString		m_strFeedBackType;
	QString		m_strUid;
	QString		m_strToken;
	QString     m_strProvinceId;
	Ui::SettingWidget ui;
	QPoint		dPos;
	QMutex		m_setMutex;
};

#endif // SETTINGWIDGET_H
