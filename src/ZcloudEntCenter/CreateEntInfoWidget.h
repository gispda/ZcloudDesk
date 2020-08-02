#include <QWidget>
#include <QMenu>
#include "ui_CreateEntInfoWidget.h"
#include "ZcloudCommonWidget.h"
#include "EntInfoDataDefine.h"

class CreateEntInfoWidget : public QWidget
{
	Q_OBJECT

public:
	CreateEntInfoWidget(QWidget *parent);
	~CreateEntInfoWidget();

signals:
	void sigUpdateSucessed();
private slots:
	void onProIndexChanged(int index);
	void onCityIndexChanged(int index);
	void onAreaIndexChanged(int index);
	void onAddressEditingFinished();
	void onLegalPeasonEditingFinished();
	void onPhoneEditingFinished();
	void onEditOkBtnClick();
	void onSearchkBtnClick();
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	bool showTradeData();

	bool showXzAreaData(QComboBox* pComBoBox,int nCode);

	//!��ȡ��ҵ
	bool winHttpGetTradeList(QString& strRet);
	//!��ȡʡ����
	bool winHttpGetAreaList(int code,QString& strRet);

	//!������ҵ����
	bool winHttpCreateCompanyInfo(QString strUid,QString strToken,int nTradeId,int nProId,int nCityId,int nAreaId,QString strOfficer,QString strPhone,QString& strRet);

	Ui::CreateEntInfoWidget ui;
	stEntInfo m_stEntInfo;
	//QString	m_strUid;
	//QString	m_strToken;

	bool	m_bCompany = true;
	bool	m_bArea = true;
	bool	m_bAddress = true;
	bool	m_bLegalPeason = true;
	bool	m_bPhone = true;
	QPoint dPos;
};
