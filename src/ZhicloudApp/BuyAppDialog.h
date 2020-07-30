#ifndef WALLPAPERWIDGET_H
#define WALLPAPERWIDGET_H

#include <QWidget>
#include "qevent.h"
#include "WebView.h"
#include "AppCommDialog.h"

class BuyAppDialog : public AppCommDialog
{
	Q_OBJECT

public:
	//isBuyApp: true ����Ӧ��  false:�����Ա
	BuyAppDialog(QString appId, QString strUid, QString strToken, bool isBuyApp,QString strUrl, QWidget *parent = 0);
	~BuyAppDialog();
	QStringList m_strListAppVipNameList;//vip�ȼ���������
	QStringList m_strListAppVipList;		//vip�ȼ�����
	QStringList m_strEndTimeList;
	//���� Ӧ���ڹ������ݲ����� ʹ�ã�ֱ�Ӵ�Ӧ��
	bool isOpen = false;
public slots:
	void buyStatusChangeSlot(QString appId, int expireDateInt, bool status, QString strMd5);
	void getVipList(const QString& strJson);
	void closeBuySlot();
	void notBuy();
	void loadFinished();
	void slotChangeWindowsSize(const bool &isMaxSize);
	void slotOpenDefaultWeb(const QString &strUrl);
	void slotBindingPhone();
	void getNewUserIdToken(const QString, const QString);
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private:
	QWebView*	m_pWebView = NULL;
	QPoint dPos;
	bool m_isBuyApp;
	QPushButton * closeButton = NULL;
};

#endif // WALLPAPERWIDGET_H
