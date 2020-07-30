#include "JsInterface.h"
#include <QDesktopServices>
#include <QUrl>
JsInterface *JsInterface::m_Instance = NULL;
JsInterface::JsInterface(QObject *parent)
	: QObject(parent)
{

}

JsInterface * JsInterface::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new JsInterface();
	}
	return m_Instance;
}

void JsInterface::DestoryInstance()
{
	if (m_Instance != NULL)
	{
		delete m_Instance;
		m_Instance = NULL;
	}
}

void JsInterface::accountSetSucessed(const QString& strName, const QString& strJob)
{
	emit sigAccountSetSucessed(strName, strJob);
}

void JsInterface::getVipList(const QString& strJson)
{
	emit sigGetVipList(strJson);
}

void JsInterface::signInSucessed(bool bSucess,int coin)
{
	emit sigSignInSucessed(bSucess, coin);
}

void JsInterface::wallpaperDownload(const QString& strDownloadLink)
{
	emit sigWallpaperDownloadLink(strDownloadLink);
}

void JsInterface::enterpriseDataSucessed(bool bSucess, int coin)
{
	//完善企业资料后  js交互
	emit sigSignCompeteSucessed(bSucess, coin);
}
void JsInterface::slotOpenDefaultWeb(const QString& strUrl)
{
	QDesktopServices::openUrl(QUrl::fromUserInput(strUrl));
}

void JsInterface::slotBindingSucceeded( const QString &strMobile)
{
	emit sigSignBindingSucceeded( strMobile);
}

void JsInterface::commitStatue(bool bSucess)
{
	emit sigCommitStatue(bSucess);
}
	
void JsInterface::slotBindingPhone()
{
	emit signalBindingPhone();
}

void JsInterface::changeUserIdtoken(const QString strUserId,const QString strToken)
{
	emit changeUserIdtokenSignal(strUserId, strToken);
}