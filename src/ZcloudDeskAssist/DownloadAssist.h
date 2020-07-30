#pragma once
#include <QObject>
#include <QTimer>
#include <QFile>

class DownloadAssist : public QObject
{
	Q_OBJECT

public:
	DownloadAssist(QObject *parent=Q_NULLPTR);
	~DownloadAssist();

private slots:
	void onTimerOut();

private:
	//!��ʼ
	bool startWork();

	//!����
	bool download(QString strDownloadUrl,QString strMd5,QString& strFileName);

	//!��װ
	bool install(QString strFileName);

	//!��ȡ����������Ϣ
	bool winHttpGetDownloadAssistant(QString& strUrl,QString& strVer,QString& strMd5);

private:
	//!ϵͳ�汾
	QString getOsVer();

	//!��ȡ˰��
	QString getTaxs();

	//!��ȡmac��ַ
	QString getMacAddr();

	//����ȡ����IP
	QString getPublicIp();

	//!��ȡʡ��
	bool getLocation(QString& strPro, QString& strCity);

	//!http����
	bool httpPost(QString strDownloadUrl, QString strPost, int nTimeout, QString& strRet);

	//!�ԱȰ汾��
	bool isNewVer(QString oldVer, QString newVer);

	QTimer*	m_pTimer = NULL;
};
