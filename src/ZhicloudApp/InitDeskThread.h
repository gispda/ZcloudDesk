#pragma once

#include <QThread>
#include <QMap>
#include <QDateTime>
#include "AppDatabase/AppCenterDatabase.h"

class InitDeskThread : public QThread
{
	Q_OBJECT

public:
	InitDeskThread(QObject *parent);
	~InitDeskThread();
	bool isRunningFlag = true;
	bool m_emitFlag = false;
	volatile bool is_flush_succeed = true;//�Ƿ�ˢ�³ɹ� ���û��ˢ�³ɹ��ȴ���һ��ѭ���ٷ����ź�ˢ��
protected:
	void run();
signals:
	void initDeskSuccess(bool isSuccess);
	void flashButton();
private:
	//���� ���ڵ� Ӧ��id
	QMap<QString ,int> oldAppIdUpTimeMap;
	QMap<QString, int>  newAppIdUpTimeMap;
	//���� ���ڵ� ����id
	QStringList oldCateIdList;
	QStringList newCateIdList;
	//�����������Ӧ��
	QStringList issueStringList;
	//�����Ѱ�װӦ��
	QStringList deskAppStringList;

	//��ȡ���е�Ӧ�úͷ���id
	void getOldAppData();
	//���� ����json 
	bool analysisJson(const QJsonValue, APPCLASSPAGEFLAG);
	//��ȡ���еķ���
	bool getAllClass();
	//�ж��Ƿ���Ҫ���£�����Ҫ���»�ȡӦ������
	bool upAppData();

	//��ȡӦ���Ƿ����
	bool isUpdateApp(int &last_update_time);

	//��ȡ������ʱ��
	void getDateTime();

	//��ʼ��Ӧ������
	//bool initDatabase(QString cateId, int pageId = 1);
	

	//��ȡͼƬ
	void updateIconPath();

	//�����¼
	void httpCodeError(int code);


	
	//��ȡ�ֲ�ͼ
	bool getSlideshow();


};
