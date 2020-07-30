#pragma once

#include "AppCenterComponent.h"
#include "ZhicloudAppDataDefine.h"

class AppCenterTools : public QPushButton
{
	Q_OBJECT
	friend class AppCenterWidget;
	friend class AppCenterHomeWidget;
public:
	//ͼƬ   �����֣� ���
	//Ӧ�����
	AppCenterTools(QWidget *parent, AppDataInfo  info, bool ategory_manager = true);
	//��ҳ�Ƽ�Ӧ��
	AppCenterTools(AppDataInfo  info, QWidget *parent = 0);
	//��ҳ����Ӧ��
	AppCenterTools(AppDataInfo  info, int number, QWidget *parent = 0);
public:
	~AppCenterTools();
	//QLabel *vipLabel = NULL;
	AppDataInfo getDesktopAppInfo()
	{
		return m_desktopAppInfo;
	}
public:
	//��ť״̬�ı�
	void statusChanged(APPSTATUS flag, bool isAdd = false);
	//��ǰ��ť״̬
	APPSTATUS m_APPSTATUSFlag;
protected:
	virtual void	enterEvent(QEvent *event);
	virtual void	leaveEvent(QEvent *event);
	//virtual void	paintEvent(QPaintEvent* event);
private:
	AppCenterItemPushButton *statusButton;
	AppDataInfo  m_desktopAppInfo;
	//QPixmap m_bg;
	bool startDownloadAppSlotFLag = false;
private slots:
	//������ʱ���ж��
	void updateUninstall();
	//���״̬��ť
	void clickedStautusButton();
	void onRecommended();
	void unstallFlish(AppDataInfo, bool flag);
	//��� ��ҳ  ͬһ��Ӧ�� ��ʾ���
	void startDownloadAppSlot(QString appId);
	//ж�����
	void unInstallSucceed(AppDataInfo, bool flag);
signals:
	//��� ���� �������б� �ź�
	void  addDownloadItemSignal(AppDownLoadItem *);
	void toolsStatusChanged(APPSTATUS);
	void startDownloadAppSignal(QString appId);
public slots:
	//���� ״̬�ñ�
	void onDownloadStatusChanged(APPDOWNLOADETYPE type);

private:
	//ж��Ӧ��
	void uninstallApp();
	void downloadApp();
	//��ʼ�� �߳�
	void connectThread();

	//�����ж�ػ��߰�װ���޸İ�ť״��
	bool uuChangedStatus(APPSTATUS);


	void getScreenInfo();
	//0 ����Ӧ�õ�button  1 �Ƽ�Ӧ�õ�button   2Ӧ������button   3 ��Ӧ�ù���
	int m_isHotApp = 0;


	QLabel * m_particulars = NULL;
	QLabel * m_numberLabel = NULL;
	QLabel * m_photoLabel = NULL;
	QLabel * m_nameLabel = NULL;
	QString hotAppName_1;
	QString hotAppName_2;


	bool isUpdate = false;
};

