#pragma once

#include "AppCenterHomeWidget.h"
#include "ui_AppCenterWidget.h"
#include "AppCommWidget.h"
#include "AppCenterTools.h"
#include "AppParticularsDialog.h"
#include <QButtonGroup>


class AppCenterWidget : public QWidget
{
	friend class RightClassAppWidget;
	Q_OBJECT
public:
	AppCenterWidget(QWidget *parent = Q_NULLPTR);
	~AppCenterWidget();
	void clickedMainHomeButton()
	{
		ui.mainPushButton->click();
	};
	void flushAppCenter();
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	QPixmap	m_bg;
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;
private:
	QButtonGroup *pButtonGroup = NULL;
public:
	//���͸���Ӧ��
	void pushPayInstall(const QString& strJson);
	//�Զ�����   isInstall = false ������
	void setAutoDownload(AppDataInfo pData);
	//�ر������޸İ�ť״̬
	void changeButtonStatus(QString appId);
private:
	//����ҳ��
	AppDownLoadAppWidget * appDownLoadAppWidget = NULL;

	//!��ǰ������� 0��ʼ
	int	m_nCurretIndex = 0;
	//��ֹ �������
	QMutex mutex;

	//Ӧ��������ҳ ��ȡ�ֲ�ͼ��ר��Ӧ��  ʮ���� ��ȡһ��
	QTimer *homePageTimer = NULL;

	//Ӧ������
	AppParticularsDialog *appParticularsDialog = NULL;
private:
	Ui::AppCenterWidget ui;

	//����ui ������ ��label  ��ʾ��Ӧ��(�����õ�ǰ���� �ĸ�����)
	void setLabelNotApp( bool isShowLabel = true );
	void closeCenterWidget();

private slots:
	//��ҳ
	void on_mainPushButton_clicked(bool checked = false);
	//���
	void on_categoryPushButton_clicked(bool checked = false);

	//���������
	void on_managerPushButton_clicked(bool checked = false);
	
	//�����б�
	void on_downloadButton_clicked();

	//��Ӧ������
	void openAppParticularsSlot();
	//ͼƬ�е�Ӧ��
	void openAppParticularsSlot(QString appId);

	//����
	void onFindBtnClick();
public slots:
	//��� ����
	void addDownloadItem(AppDownLoadItem *);
signals:
	//������� nȡֵ0 ��װ  1��� 2�Ƴ�  3ж��
	void installFilish(int n, AppDataInfo*	pData);
	//ˢ�½��� ���µ�����
	void newFlushClass(QString cateId);
};
