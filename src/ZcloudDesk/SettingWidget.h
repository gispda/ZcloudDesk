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
	*	左侧按钮响应槽
	*/

	//!桌面设置
	void onDeskSettingBtnClick();

	//!意见反馈
	void onFeedBackBtnClick();

	//!帮助中心
	void onHelperBtnClick();

	//!关于我们 
	void onAboutUsBtnClick();

	/*
	*	桌面设置内按钮响应槽
	*/
	void onTopCheckChanged(int state);

	void onRightCheckChanged(int state);

	/*
	*	意见反馈内按钮响应槽
	*/

	//!提交
	void onCommitBtnClick();

	//!桌面应用
	void onDeskAppBtnClick();

	//!界面设计
	void onDesignBtnClick();

	//!平台故障
	void onErrorBtnClick();

	//!功能优化
	void onMajorBtnClick();

	//!其他
	void onOtherBtnClick();

	//!文本框变化
	void onTextChanged();

	//!解析意见反馈json
	int anyliseJson(const QString& strJson,QString& strFeedBackId);
	/*
	*	帮助中心内按钮响应槽
	*/

	//!操作演示
	void onDemoBtnClick();

	//!功能引导
	void onGuideBtnClick();

	//！使用帮助
	void onHelpBtnClick();

	//！调查问卷
	void onQuestionBtnClick();


	/*
	*	关于我们内按钮响应槽
	*/

	//!检查更新
	void onCheckUpdateBtnClick();

	//!退出登录
	void onLogoutClick();

	//!版本说明
	void openVerDes();

private:
	//!初始化
	void init();

	//!清空列表
	void clearListWidget();

	//!桌面设置connect绑定
	void deskSettingConnect();

	//!意见反馈connect绑定
	void feedBackConnect();

	//!帮助中心connect绑定
	void helpCenterConnect();

	//!关于我们connect绑定
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
