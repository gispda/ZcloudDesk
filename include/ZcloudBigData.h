#ifndef ZCLOUDBIGDATA_H
#define ZCLOUDBIGDATA_H
#include <QtCore/qglobal.h>
#ifdef ZCLOUDBIGDATA_LIB
# define ZCLOUDBIGDATA_EXPORT Q_DECL_EXPORT
#else
# define ZCLOUDBIGDATA_EXPORT Q_DECL_IMPORT
#endif

class ZCLOUDBIGDATA_EXPORT ZcloudBigDataInterface
{
public:
	//!创建实例对象(单例模式 所有模块多次调用 但只建立一个)
	static ZcloudBigDataInterface * GetInstance();

	//!压入大数据字符串
	virtual void produceData(QString strMsgClsId, QString strOperationId, QString strOperandId, QString strNotes = "", bool isImmediately = false) = 0;

	//!中断线程并等待结束
	virtual void stopThread()	=	0;

	//!设置用户数据
	virtual void initData(QString strUserId, QString strCompanyId, QString strHzsId, QString strProvinceId, QString strCityId, QString strAreaId,QString strFlag="1")=0;
};

#endif // ZCLOUDBIGDATA_H
