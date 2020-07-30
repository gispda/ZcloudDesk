#pragma once
#include <QString>
typedef struct ENT_INFO
{
	QString _strCompId;		//!公司Id
	QString _strCompName;	//!公司名称
	QString	_strTaxNo;		//!税号
	QString _strLogoPath;	//!头像地址
	int		_nTradeId;		//!行业Id
	QString	_strTradeName;	//!行业名称
	int		_nProId;		//!省id
	QString	_strPro;		//!省
	int		_nCityId;		//!市Id
	QString	_strCity;		//!市
	int		_nAreaId;		//!区Id
	QString	_strArea;		//!区
	QString _strOfficeName;	//!财税负责人
	QString _strOfficeMobile;	//!负责人手机
}stEntInfo;

typedef struct ENT_INVOICE_INFO
{
	QString _strBankAccount;//!开户账号
	QString _strBankName;	//!开户银行
	QString	_strTelNo;		//!开户电话
	QString _strAddr;		//!地址
}stInvoiceInfo;

