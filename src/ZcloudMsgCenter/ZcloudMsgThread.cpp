#include "ZcloudMsgThread.h"
#include <QDateTime>
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QApplication>
#include "MsgDataBase.h"
#include <QSettings>
#include <QFileInfo>
#include "Database.h"
#include "ZcloudBigData.h"
#include "..\ZcloudBigData\BigDataImpl.h"
ZcloudMsgThread::ZcloudMsgThread(QObject *parent)
	: QThread(parent)
{

}

ZcloudMsgThread::~ZcloudMsgThread()
{

}

void ZcloudMsgThread::run()
{
	m_bBreak = true;

	QDateTime last = QDateTime::currentDateTime();
	QDateTime now;
	while (true)
	{
		for (int i = 0; i < 36;++i)
		{
			sleep(5);
			QMutexLocker locker(&m_mutex);
			if (!m_bBreak)
			{
				return;
			}
		}
		QString strUid, strToken,strCompId;
		{
			QMutexLocker locker(&m_mutex);
			strUid		= m_strUid;
			strToken	= m_strToken;
			strCompId	= m_strCompId;
		}
		int nRet = pullMsg(strUid, strToken,strCompId);
		if (-1 == nRet || -2 == nRet)
		{
			QMutexLocker locker(&m_mutex);
			return;
		}
		
		now = QDateTime::currentDateTime();
		if (last.msecsTo(now) >= 60* 60 * 1000)
		{
			pullActivity(strUid, strToken,strCompId);
			last = now;
		}
	}
}

int ZcloudMsgThread::pullMsg(QString strUid, QString strToken, QString strCompId)
{
	QString strRet;
	if (!winHttpGetMessage(strUid, strToken, strRet))
	{
		return 0;
	}
	vtrMsgInfo	msgInfos;
	QString    strMsg;
	QString    strPicPath;
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return 0;
	}
	if (!parse_doucment.isObject())
	{
		return 0;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("status").toInt();
	if (-1 == status)
	{
		emit checkTokenFailed(-1);
		return -1;
	}
	else if (-2 == status)
	{
		emit checkTokenFailed(-2);
		return -2;
	}
	else if (status == 0)
	{
		QJsonValue data = obj.take("data");
		if (!data.isArray())
		{
			return 0;
		}
		QJsonArray jsonArray = data.toArray();
		int nSize = jsonArray.size();
		if (0 == nSize)
		{
			return 0;
		}
		for (int nIndex = 0; nIndex < nSize; ++nIndex)
		{
			stMsgInfo*	pMsgInfo		=	new stMsgInfo;
			QJsonObject dataMsg			=	jsonArray.at(nIndex).toObject();
			pMsgInfo->_strUid			=	strUid;
			pMsgInfo->_strToken			=	strToken;
			pMsgInfo->_strComId			=	strCompId;
			pMsgInfo->_nMsgType			=	dataMsg.take("message_type").toInt();
			pMsgInfo->_strMsgId			=	dataMsg.take("message_id").toString();
			if (0 == nIndex)
			{
				strMsg = pMsgInfo->_strMsgId;
			}
			pMsgInfo->_strFeedBackId	=	dataMsg.take("feedback_id").toString();
			pMsgInfo->_strMsgTitle		=	dataMsg.take("title").toString();
			if (2	==	pMsgInfo->_nMsgType)
			{
				QString strPicUrl = dataMsg.take("content").toString();
				pMsgInfo->_strMsgContent = ZcloudComFun::downloadPic(strPicUrl, QApplication::applicationDirPath().append("/CacheImage/picMsgImage"));
				if (0 == nIndex)
				{
					strPicPath = pMsgInfo->_strMsgContent;
				}
				if (pMsgInfo->_strMsgContent.isEmpty())
				{
					pMsgInfo->_strMsgContent = strPicUrl;
				}
			}
			else
			{
				pMsgInfo->_strMsgContent = dataMsg.take("content").toString();
			}
			
			pMsgInfo->_strAbstruct		=	dataMsg.take("abstruct").toString();
			pMsgInfo->_nPosition		=	dataMsg.take("position").toInt();
			pMsgInfo->_nSendTime		=	dataMsg.take("send_time").toInt();
			pMsgInfo->_nValidStartTime	=	dataMsg.take("valid_start_time").toInt();
			pMsgInfo->_nValidEndTime	=	dataMsg.take("valid_end_time").toInt();
			pMsgInfo->_nTargetType		=	dataMsg.take("content_target_type").toInt();
			pMsgInfo->_strTarget		=	dataMsg.take("content_target").toString();

			QJsonValue jsonValue = dataMsg.take("btn_list");
			if (jsonValue.isArray())
			{
				QJsonArray BtnArray = jsonValue.toArray();
				QJsonDocument document;
				document.setArray(BtnArray);
				QByteArray byte_array = document.toJson(QJsonDocument::Compact);
				pMsgInfo->_arryBtnList = byte_array;
			}
			msgInfos.push_back(pMsgInfo);

			if (0 == pMsgInfo->_nPosition)
			{
				ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP000", "TMP023", pMsgInfo->_strMsgId);
			}
		}
	}
	if (MsgDataBase::GetInstance()->insertMsgInfo(msgInfos))
	{
		emit sendMsgInfo(QStringList() << strUid << strToken <<	strCompId << strMsg << strPicPath, msgInfos.size());
	}
	if (0 != msgInfos.size())
	{
		vtrMsgInfo::iterator itr = msgInfos.begin();
		for (; itr != msgInfos.end(); ++itr)
		{
			stMsgInfo* pMsgInfo = (*itr);
			if (NULL != pMsgInfo)
			{
				delete pMsgInfo;
				pMsgInfo = NULL;
			}
		}
		msgInfos.clear();
	}	
	return 1;
}

void ZcloudMsgThread::pullActivity(QString strUid, QString strToken,QString strCompId)
{
	QString strRet;
	if (!winHttpGetActivity(strUid, strToken, strRet))
	{
		return;
	}
	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return;
	}
	if (!parse_doucment.isObject())
	{
		return;
	}
	QJsonObject obj = parse_doucment.object();
	int status = obj.take("status").toInt();
	if (status == 0)
	{
		QJsonObject data	=	obj.take("data").toObject();
		QString strId		=	data.take("activity_id").toString();
		if (strId != m_strActivityId)
		{
			m_strActivityId = strId;
			QString strTitle = data.take("description").toString();
			if (!strTitle.isEmpty())
			{
				emit sendActivityInfo(QStringList() << strUid << strToken << strCompId << strId << strTitle);
			}
		}	
	}
}

void ZcloudMsgThread::stopImmediately()
{
	QMutexLocker	locker(&m_mutex);
	this->m_bBreak = false;
}

bool ZcloudMsgThread::winHttpGetMessage(QString strUid,QString strToken, QString& strRet)
{
	QString strUrl = QString("/push/get-message?user_id=%1&token=%2").arg(strUid).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}

void ZcloudMsgThread::setUserData(QString strUid, QString strToken, QString strCompId)
{
	pullActivity(strUid, strToken, strCompId);
	QMutexLocker	locker(&m_mutex);
	m_strUid	=	strUid;
	m_strToken	=	strToken;
	m_strCompId =	strCompId;
	m_strActivityId.clear();
}

QString ZcloudMsgThread::getStringFromJsonObject(const QJsonObject& jsonObject)
{
	QJsonDocument doc(jsonObject);
	return doc.toJson(QJsonDocument::Compact);
}

bool ZcloudMsgThread::winHttpGetActivity(QString strUid, QString strToken, QString& strRet)
{
	QString strUrl = QString("/general/get-top-activity?user_id=%1&token=%2").arg(strUid).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, "", 5000, strRet);
}