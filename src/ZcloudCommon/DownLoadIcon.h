#ifndef CLOUDDOWNLOAD_H
#define CLOUDDOWNLOAD_H
#include <QThread>
#include <QDateTime>
#include <QFile>
#include <QFileInfo>
#include <QEventLoop>
#include <QTimer>
#include <QDir>
#include <QtNetwork/QNetworkReply>
class DownLoadIcon : public QThread
{
    Q_OBJECT

public:
	explicit DownLoadIcon(int msec=3000,QObject *parent = 0);

	void setValue(QString flilePath, QString url, QString id = "");
	QString filePath;//����� �ļ�����·�����������ص��ļ�·��
	void run();

	void startAyalseUrl(QString strUrl);
	bool errorFlag = false;
signals:
    void readProgress(qint64 totalBytes,qint64 bytesRead);

    void finished_signal();//������ɵ��ź�

public slots:
    void requestTimeout();//����ʱ

    void requestFinished();//��������ź�

    void httpReadyRead() ;//�����ݿɶ�

private:
    QNetworkAccessManager* m_pNetworkManager;//���������
    QNetworkReply* m_pNetworkReply; //��װ���󷵻���Ϣ
    QEventLoop *loop;

    QTimer * m_pTimer;//��ʱ��ʱ��
    QString m_Url;
	QString appID;
	int		m_msec;
    QFile *file = NULL;
	QString down_name;
protected:
    

};

#endif // CLOUDDOWNLOAD_H
