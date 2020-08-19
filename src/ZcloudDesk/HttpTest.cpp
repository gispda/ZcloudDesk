#include "HttpTest.h"
#include "qtimer.h"
#include "QEventLoop"

HttpTest::HttpTest(){}
HttpTest::~HttpTest(){}
void HttpTest::access(){
	QNetworkAccessManager *accessManager = new QNetworkAccessManager(this);

	QNetworkRequest request;

	//strPost = tax=38197397491747194E
	request.setUrl(QUrl("https://testgwuk3ht.zhicloud.com/ucenter/user/get-key?mac=02:50:F2:00:00:02&version=7.0.0.0&system=Microsoft Windows 10"));
	//get
	//accessManager->get(request);

	QByteArray postData;
	postData.append("tax=38197397491747194E");


	connect(accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));
	//post
	replay = accessManager->post(request, postData);
	connect(replay, SIGNAL(finished()), this, SLOT(finishSlot()));
	//QTimer login_pTimer;
	QEventLoop loop;
	connect(replay, SIGNAL(finished()), &loop, SLOT(quit()));
	//login_pTimer.start(200);
	loop.exec();
	finishSlot();


}

void HttpTest::finishSlot(){
	if (replay->error() == QNetworkReply::NoError)
	{
		QByteArray bytes = replay->readAll();
		qDebug() << bytes;
	}
	else
	{
		qDebug() << "finishedSlot errors here";
		qDebug("found error .... code: %d\n", (int)replay->error());
		qDebug(qPrintable(replay->errorString()));
	}
	replay->deleteLater();
}

void HttpTest::finishedSlot(QNetworkReply *rep){
	if (rep->error() == QNetworkReply::NoError)
	{
		QByteArray bytes = rep->readAll();
		qDebug() << bytes;
	}
	else
	{
		qDebug() << "finishedSlot errors here";
		qDebug("found error .... code: %d\n", (int)rep->error());
		qDebug(qPrintable(rep->errorString()));
	}
	rep->deleteLater();
}