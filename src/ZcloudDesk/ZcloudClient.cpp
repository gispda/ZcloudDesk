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

bool ZcloudClient::winHttpUpdatebankInfo(CompanyBankInfo _bankinfo, QString strToken, QString& strRet, QString& strMsg)
{

	bool bret;

	int iret;
	QString strUrl = QString("/ucenter/company/update-bank-info");


	

	QString strPost;

	strPost = QString("token=%1&address=%2&bank_account=%3&bank_name=%4&tel_number=%5&tax=%6").
		arg(strToken).arg(_bankinfo.m_strAddress).arg(_bankinfo.m_strBankaccount)
		.arg(_bankinfo.m_strBankname).arg(_bankinfo.m_strTelno).arg(_bankinfo.m_strTaxno);


	bret = ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);


	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return false;
	}
	if (!parse_doucment.isObject())
	{
		return false;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("code").toInt();
	if (0 != status)
	{
		switch (status)
		{
		case 20012:
			strMsg = QString::fromLocal8Bit("企业地址不能为空");
			break;
		case 20013:
			strMsg = QString::fromLocal8Bit("企业地址输入不正确");
			break;
		case 20027:
			strMsg = QString::fromLocal8Bit("开户帐号不能为空");
			break;
		case 20028:
			strMsg = QString::fromLocal8Bit("开户帐号输入类型不正确");
			break;
		case 20029:
			strMsg = QString::fromLocal8Bit("开户帐号输入长度不正确");
			break;
		case 20030:
			strMsg = QString::fromLocal8Bit("开户银行不能为空");
			break;
		case 20031:
			strMsg = QString::fromLocal8Bit("开户银行输入类型不正确");
			break;
		case 20032:
			strMsg = QString::fromLocal8Bit("电话不能为空");
			break;
		case 20033:
			strMsg = QString::fromLocal8Bit("电话长度不正确");
			break;
		default:
			break;
		}




		return false;
	}

	bool jmsg = obj.take("data").toBool();
	if (jmsg)
		strMsg = QString::fromLocal8Bit("更新成功");
	else
		strMsg = QString::fromLocal8Bit("更新失败");
	return jmsg;

}

bool ZcloudClient::winHttpUploadImage(QString strFile, QString strToken, QString& strRet, QString& strMsg)
{
	///strFile = "D:\\111.png";



	QFileInfo fileInfo(strMsg);



	QFile *file = new QFile(strFile);
	bool isop = file->open(QIODevice::ReadOnly);

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





	bool bret;
	bret = ZcloudComFun::httpPostFile(strUrl, data, 5000, strRet, false, 1);



	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return false;
	}
	if (!parse_doucment.isObject())
	{
		return false;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("code").toInt();
	if (0 != status)
	{
		//switch (status)
		//{
		//case 20012:
		//	strMsg = QString::fromLocal8Bit("企业地址不能为空");
		//	break;
		//case 20013:
		//	strMsg = QString::fromLocal8Bit("企业地址输入不正确");
		//	break;
		//case 20027:
		//	strMsg = QString::fromLocal8Bit("开户帐号不能为空");
		//	break;
		//case 20028:
		//	strMsg = QString::fromLocal8Bit("开户帐号输入类型不正确");
		//	break;
		//case 20029:
		//	strMsg = QString::fromLocal8Bit("开户帐号输入长度不正确");
		//	break;
		//case 20030:
		//	strMsg = QString::fromLocal8Bit("开户银行不能为空");
		//	break;
		//case 20031:
		//	strMsg = QString::fromLocal8Bit("开户银行输入类型不正确");
		//	break;
		//case 20032:
		//	strMsg = QString::fromLocal8Bit("电话不能为空");
		//	break;
		//case 20033:
		//	strMsg = QString::fromLocal8Bit("电话长度不正确");
		//	break;
		//default:
		//	break;
		//}




		return false;
	}

	QJsonObject jdata = obj.take("data").toObject();

	QString url = jdata.take("url").toString();

	bool jmsg = false;
	if (!url.isEmpty())
	{
	
	strMsg = QString::fromLocal8Bit("上传营业执照成功");
	jmsg = true;
    }
	else
		strMsg = QString::fromLocal8Bit("上传营业执照失败");
	return jmsg;
}

bool ZcloudClient::winHttpQueryCompanyInfoLocalTax(QString strTaxno, QString strToken, QString& strServerUserid,QString& strRet, QString& strCompany)
{

	QString strUrl = QString("/ucenter/company/info");
	QString strPost;

	if (strTaxno.isEmpty())
		strPost = QString("token=%1").arg(strToken);
	else
		strPost = QString("tax=%1&token=%2").arg(strTaxno).arg(strToken);

	bool bret;
	bret =  ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);




	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return false;
	}
	if (!parse_doucment.isObject())
	{
		return false;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("code").toInt();
	if (0 != status)
	{
		//switch (status)
		//{
		//case 20012:
		//	strMsg = QString::fromLocal8Bit("企业地址不能为空");
		//	break;
		//case 20013:
		//	strMsg = QString::fromLocal8Bit("企业地址输入不正确");
		//	break;
		//case 20027:
		//	strMsg = QString::fromLocal8Bit("开户帐号不能为空");
		//	break;
		//case 20028:
		//	strMsg = QString::fromLocal8Bit("开户帐号输入类型不正确");
		//	break;
		//case 20029:
		//	strMsg = QString::fromLocal8Bit("开户帐号输入长度不正确");
		//	break;
		//case 20030:
		//	strMsg = QString::fromLocal8Bit("开户银行不能为空");
		//	break;
		//case 20031:
		//	strMsg = QString::fromLocal8Bit("开户银行输入类型不正确");
		//	break;
		//case 20032:
		//	strMsg = QString::fromLocal8Bit("电话不能为空");
		//	break;
		//case 20033:
		//	strMsg = QString::fromLocal8Bit("电话长度不正确");
		//	break;
		//default:
		//	break;
		//}


		strCompany = QString::fromLocal8Bit("暂未查询到您的企业");

		return false;
	}

	QJsonObject jdata = obj.take("data").toObject();

	strCompany = jdata.take("company_name").toString();

	QJsonObject userdata = jdata.take("user").toObject();

	strServerUserid = userdata.take("user_id").toString();

	bool jmsg = false;
	if (!strCompany.isEmpty())
	{		
		jmsg = true;
	}
	else
		strCompany = QString::fromLocal8Bit("暂未查询到您的企业");
	return jmsg;
}
