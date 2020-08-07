#ifndef ZCLOUDENTCENTERIMPL_H
#define ZCLOUDENTCENTERIMPL_H
#include <QObject>
#include "ZcloudEntCenter.h"
#include "EntCenterWidget.h"
#include "VipInfoWidget.h"
class ZcloudEntCenterImpl : public ZcloudEntCenter
{
	Q_OBJECT

public:
	ZcloudEntCenterImpl();
	~ZcloudEntCenterImpl();

	//!���ٶ���
	virtual void destroy();
	//!�½���ҵ
	virtual void createEntCenter();
	//!�򿪹����б�
	virtual void openWorkers(QString strUid, QString strToken);

	//!����ҵ����
	virtual void openEntCenter(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId, QString strUserName);

	//! ��ҵ�����Ƿ���ʾ
	virtual bool isEntCenterShow();

	//�����ֻ���
	virtual void setMobile(QString mobile);
	virtual void setToken(QString strToken);

	//!�򿪻�Ա����
	virtual void openVipInfoCenter(QString strUid, QString strToken, bool bJoinEnt, bool bHasMember);

	//!�򿪷�������Ѵ���
	virtual void openServiceFeeCenter(QString strUrl);

	//!�ر�������ҵ�Ի���
	virtual void closeAllEntWidget();

	//!ǩ���ɹ��޸��Ʊ�����
	virtual void modifyCoinCount(int nCount);

private:
	EntCenterWidget*		m_pEntCenterWidget = NULL;
	VipInfoWidget*			m_pVipInfoWidget = NULL;
};
#endif // ZCLOUDENTCENTERIMPL_H
