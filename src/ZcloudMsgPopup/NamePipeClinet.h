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
	
	//!nResType 1按钮点击 2表单关闭 3图片点击 4活动点击 5图片消息窗口启动 6右下角消息窗口启动 7居中消息窗口启动 8服务费到期窗口启动 9消息详情内容滚动条
	void sendMessage(int nResType, QString strUid, QString strToken,QString strCompId, QString strMsgId, QString strBtnId, int nBtnType, QString strBtnTarget, bool bRead,bool bFromPopUp=true);

public slots:
	void onConnected();
	void onDisConnected();
	void onSocketError(QLocalSocket::LocalSocketError);
private:
	QLocalSocket* m_pLocalSocket = NULL;
};

#endif // NAMEPIPECLINET_H
