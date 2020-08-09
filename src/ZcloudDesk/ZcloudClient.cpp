#include "ZcloudClient.h"
#include <QFile>
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include "QHttpMultiPart"
#include "QFileInfo"

ZcloudClient::ZcloudClient(QObject *parent)
	: QObject(parent)
{
}

ZcloudClient::~ZcloudClient()
{
}

bool ZcloudClient::winHttpUpdatebankInfo(QString strUid, QString strToken, QString& strRet)
{


	return true;
}

bool ZcloudClient::winHttpUploadImage(QString strFile, QString strToken, QString& strRet)
{
	strFile = "D:\\111.png";



	QFileInfo fileInfo("D:\\111.png");

	

	QFile *file = new QFile(strFile);
	bool isop = file->open(QIODevice::ReadOnly);
	//imagePart.setBodyDevice(file);
	//file->setParent(multiPart); // we cannot delete the file now, so delete it with the multiPart


	//multiPart->append(imagePart);

	QString strUrl = QString("/ucenter/company/upload-license?token=%1").arg(strToken);

	
	

	QString boundary("eidevelop1010101010");
	QString contentType("multipart/form-data; boundary=" + boundary);
	QByteArray data;

	data += QString("--" + boundary + "\r\n").toUtf8();
	data += QString("Content-Disposition: form-data; name=\"file\";filename=" + fileInfo.fileName() + "\r\n").toUtf8();
	data += QString("Content-Type: image/png\r\n\r\n").toUtf8();
	data += file->readAll();
	data += "\r\n";
	data += QString("--" + boundary + "\r\n").toUtf8();


	




	QString strPost = data;
	return ZcloudComFun::httpPostFile(strUrl, data, 5000, strRet, false, 1);

}
