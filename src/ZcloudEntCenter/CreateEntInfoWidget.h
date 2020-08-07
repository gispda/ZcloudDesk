#include <QWidget>
#include <QMenu>
#include "ui_CreateEntInfoWidget.h"
#include "ZcloudCommonWidget.h"
#include "EntInfoDataDefine.h"

class CreateEntInfoWidget : public QDialog
{
	Q_OBJECT

public:
	CreateEntInfoWidget(QString strUid, QString strToken, QWidget *parent = 0);
	~CreateEntInfoWidget();

signals:
	void sigUpdateSucessed();
private slots:
	void onProIndexChanged(int index);
	void onCityIndexChanged(int index);
	void onAreaIndexChanged(int index);
	void onProOfficeIndexChanged(int index);
	void onCityOfficeIndexChanged(int index);
	void onAreaOfficeIndexChanged(int index);
	void onAddressEditingFinished();
	void onAddressOfficeEditingFinished();
	void onLegalPeasonEditingFinished();
	void onPhoneEditingFinished();
	void onEditOkBtnClick();
	void onSearchkBtnClick();
	void onRadioBtnAddressRegClick();
	void onRadioBtnAddressNewClick();
	void onOkBtnClick();
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:
	bool showAreaData(QComboBox* pComBoBox,int nCode);
	//!获取省市区
	bool winHttpGetAreaList(int code,QString& strRet);
	//!更新企业资料
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

	QString	m_strUid;
	QString	m_strToken;
	QPoint dPos;
};
