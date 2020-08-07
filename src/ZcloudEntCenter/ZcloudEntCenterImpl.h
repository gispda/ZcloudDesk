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

	//!销毁对象
	virtual void destroy();
	//!新建企业
	virtual void createEntCenter();
	//!打开工单列表
	virtual void openWorkers(QString strUid, QString strToken);

	//!打开企业中心
	virtual void openEntCenter(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId, QString strUserName);

	//! 企业中心是否显示
	virtual bool isEntCenterShow();

	//设置手机号
	virtual void setMobile(QString mobile);
	virtual void setToken(QString strToken);

	//!打开会员中心
	virtual void openVipInfoCenter(QString strUid, QString strToken, bool bJoinEnt, bool bHasMember);

	//!打开服务费续费窗口
	virtual void openServiceFeeCenter(QString strUrl);

	//!关闭所有企业对话框
	virtual void closeAllEntWidget();

	//!签到成功修改云币数据
	virtual void modifyCoinCount(int nCount);

private:
	EntCenterWidget*		m_pEntCenterWidget = NULL;
	VipInfoWidget*			m_pVipInfoWidget = NULL;
};
#endif // ZCLOUDENTCENTERIMPL_H
