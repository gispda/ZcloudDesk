#pragma once
#include <QString>
typedef struct ENT_INFO
{
	QString _strCompId;		//!��˾Id
	QString _strCompName;	//!��˾����
	QString	_strTaxNo;		//!˰��
	QString _strLogoPath;	//!ͷ���ַ
	int		_nTradeId;		//!��ҵId
	QString	_strTradeName;	//!��ҵ����
	int		_nProId;		//!ʡid
	QString	_strPro;		//!ʡ
	int		_nCityId;		//!��Id
	QString	_strCity;		//!��
	int		_nAreaId;		//!��Id
	QString	_strArea;		//!��
	QString _strOfficeName;	//!��˰������
	QString _strOfficeMobile;	//!�������ֻ�
}stEntInfo;

typedef struct ENT_INVOICE_INFO
{
	QString _strBankAccount;//!�����˺�
	QString _strBankName;	//!��������
	QString	_strTelNo;		//!�����绰
	QString _strAddr;		//!��ַ
}stInvoiceInfo;

