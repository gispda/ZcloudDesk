#ifndef NAMEPIPECLINET_H
#define NAMEPIPECLINET_H

#include <QObject>
#include <QLocalSocket>

class NamePipeClinet : public QObject
{
	Q_OBJECT

public:
	NamePipeClinet(QObject *parent=0);
	~NamePipeClinet();

	bool connectToServer(const QString &strServerName);
	
	//!nResType 1��ť��� 2���ر� 3ͼƬ��� 4���� 5ͼƬ��Ϣ�������� 6���½���Ϣ�������� 7������Ϣ�������� 8����ѵ��ڴ������� 9��Ϣ�������ݹ�����
	void sendMessage(int nResType, QString strUid, QString strToken,QString strCompId, QString strMsgId, QString strBtnId, int nBtnType, QString strBtnTarget, bool bRead,bool bFromPopUp=true);

public slots:
	void onConnected();
	void onDisConnected();
	void onSocketError(QLocalSocket::LocalSocketError);
private:
	QLocalSocket* m_pLocalSocket = NULL;
};

#endif // NAMEPIPECLINET_H
