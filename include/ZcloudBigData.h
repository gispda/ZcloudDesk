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
	//!����ʵ������(����ģʽ ����ģ���ε��� ��ֻ����һ��)
	static ZcloudBigDataInterface * GetInstance();

	//!ѹ��������ַ���
	virtual void produceData(QString strMsgClsId, QString strOperationId, QString strOperandId, QString strNotes = "", bool isImmediately = false) = 0;

	//!�ж��̲߳��ȴ�����
	virtual void stopThread()	=	0;

	//!�����û�����
	virtual void initData(QString strUserId, QString strCompanyId, QString strHzsId, QString strProvinceId, QString strCityId, QString strAreaId,QString strFlag="1")=0;
};

#endif // ZCLOUDBIGDATA_H
