#include <qwidget.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkProxy>

class HttpTest : public QWidget{
public:
	HttpTest();
	~HttpTest();
	void access();
	QNetworkReply* replay;
	private slots:
	void finishedSlot(QNetworkReply *reply);
	void finishSlot();
};