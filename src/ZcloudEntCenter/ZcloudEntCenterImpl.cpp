#include "ZcloudEntCenterImpl.h"
#include "ZcloudCommon.h"
#include "EntComWidget.h"
#include <QDialog>
#include "DefaultVipWidget.h"
#include "JoinEntWidget.h"
ZcloudEntCenterImpl::ZcloudEntCenterImpl()
{
}

ZcloudEntCenterImpl::~ZcloudEntCenterImpl()
{
	closeAllEntWidget();
}

void ZcloudEntCenterImpl::openEntCenter(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId,QString strUserName)
{
	if (NULL == m_pEntCenterWidget)
	{
		m_pEntCenterWidget = new EntCenterWidget;
		connect(m_pEntCenterWidget, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SIGNAL(sigSwitchAcc(int, bool, QString, QString)));
		connect(m_pEntCenterWidget, SIGNAL(sendVipListSignals(QStringList, QStringList, QStringList)), this, SIGNAL(sendVipListSignals(QStringList, QStringList, QStringList)));
		connect(m_pEntCenterWidget, SIGNAL(trueNameJobChange(QString, QString)), this, SIGNAL(trueNameJobChange(QString, QString)));
		connect(m_pEntCenterWidget, SIGNAL(bingdingPhoneSignal()), this, SIGNAL(bingdingPhoneSignal()));
		connect(m_pEntCenterWidget, SIGNAL(sigSignBindingSucceeded(const QString &)), this, SIGNAL(sigSignBindingSucceeded(const QString &)));
		connect(m_pEntCenterWidget, SIGNAL(openSignInWidget(QWidget*)), this, SIGNAL(openSignInWidget(QWidget*)));
	}
	m_pEntCenterWidget->setUserInfo(strUid, strToken, strTrueName, strJob, isLoginByTax, strMobile, strCompId,strUserName);
	m_pEntCenterWidget->showWindow();
}

void ZcloudEntCenterImpl::setMobile(QString mobile)
{
	if (m_pEntCenterWidget)
	{
		m_pEntCenterWidget->setMobile(mobile);
	}
}

void ZcloudEntCenterImpl::setToken(QString strToken)
{
	if (m_pEntCenterWidget)
	{
		m_pEntCenterWidget->setToken(strToken);
	}
}

ZcloudEntCenter * ZcloudEntCenter::createNew()
{
	return new ZcloudEntCenterImpl();
}

void ZcloudEntCenterImpl::destroy()
{
	delete this;
}

void ZcloudEntCenterImpl::closeAllEntWidget()
{
	if (NULL != m_pEntCenterWidget)
	{
		m_pEntCenterWidget->deleteLater();
		m_pEntCenterWidget = NULL;
	}
	if (NULL != m_pVipInfoWidget)
	{
		m_pVipInfoWidget->deleteLater();
		m_pVipInfoWidget = NULL;
	}
}

void ZcloudEntCenterImpl::openVipInfoCenter(QString strUid, QString strToken,bool bJoinEnt,bool bHasMember)
{
	if (NULL == m_pVipInfoWidget)
	{
		if (!bJoinEnt)
		{
			if (ZcloudComFun::winHttpSSO(strToken, strUid))
			{
				if (!this->findChild <JoinEntWidget*>("addEntEnter"))
				{
					JoinEntWidget*	pJoinEntWidget = new JoinEntWidget(strUid, strToken);
					pJoinEntWidget->show();
				}
			}
			return;
		}
		if (!bHasMember)
		{
			DefaultVipWidget*	pDefaultVipWidget = new DefaultVipWidget;
			pDefaultVipWidget->show();
			return;
		}

		if (ZcloudComFun::winHttpSSO(strToken, strUid))
		{
			QString strUrl = ZcloudComFun::getWvUrl(strUid, strToken, "wv/member/index");
			m_pVipInfoWidget = new VipInfoWidget(strUid, strToken, strUrl);
		}
	}
	if (m_pVipInfoWidget)
	{
		connect(m_pVipInfoWidget, SIGNAL(sendVipListSignals(QStringList, QStringList, QStringList)), this, SLOT(changeVipSucessed(QStringList, QStringList, QStringList)));
		connect(m_pVipInfoWidget, SIGNAL(bingdingPhoneSignal()), this, SIGNAL(bingdingPhoneSignal()));
		QString strUrl = ZcloudComFun::getWvUrl(strUid, strToken, "wv/member/index");
		m_pVipInfoWidget->showWindow(strUrl);
	}
}

void ZcloudEntCenterImpl::openServiceFeeCenter(QString strUrl)
{
	EntComWidget* pEntComWidget = new EntComWidget(QString::fromLocal8Bit("服务费续费"), strUrl, false);
	pEntComWidget->setAttribute(Qt::WA_DeleteOnClose);
	pEntComWidget->show();
}

bool ZcloudEntCenterImpl::isEntCenterShow()
{
	if (NULL != m_pEntCenterWidget)
	{
		return m_pEntCenterWidget->isVisible();
	}
	return false;
}

void ZcloudEntCenterImpl::modifyCoinCount(int nCount)
{
	if (isEntCenterShow())
	{
		m_pEntCenterWidget->modifyCoinCount(nCount);
	}
}
