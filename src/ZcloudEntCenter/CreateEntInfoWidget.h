#include <QWidget>
#include <QMenu>
#include "ui_CreateEntInfoWidget.h"
#include "ZcloudCommonWidget.h"
#include "EntInfoDataDefine.h"
#include "Database.h"

class CreateEntInfoWidget : public QWidget
{
	Q_OBJECT

public:
	CreateEntInfoWidget(UserInfoStruct* _userinfo, QString strUid, QString strToken, QWidget *parent = 0);
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


	bool onCheckEntName();
	bool onCheckEntCode();

	bool onCheckAddress();
	bool onCheckAddressOffice();

	bool onCheckArea();
	bool onCheckAreaOffice();

	bool onCheckLegalPeason();
	bool onCheckPhone();

	void onSearchkBtnClick();
	void onRadioBtnAddressRegClick();
	void onRadioBtnAddressNewClick();
	void onOkBtnClick();
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
private:

	///ǰ����ҵ��Ϣ���߼��жϲ���ʾ����
	void submitCompany();

	void clear();

	bool showAreaData(QComboBox* pComBoBox,int nCode);
	//!��ȡʡ����
	bool winHttpGetAreaList(int code,QString& strRet);
	bool initProData();
	//!������ҵ����
	bool winHttpCreateCompanyInfo(QString strUid, QString strToken, stEntInfo* m_stEntInfo, QString& strRet);
	Ui::CreateEntInfoWidget ui;
	
	UserInfoStruct* m_userinfo;
	//QString	m_strUid;
	//QString	m_strToken;





	QString	m_strUid;
	QString	m_strToken;
	QPoint dPos;
};
