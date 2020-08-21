#include "EntCenterNewWidget.h"
#include <QClipboard>
#include "SwitchAccWidget.h"
#include "EntComWidget.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileInfo>
#include <QDialog>
#include "ZcloudBigData.h"
#include "VipInfoWidget.h"
#include "DefaultVipWidget.h"
#include "JoinEntWidget.h"
#include "EntInfoWidget.h"
#include "FinanMemberWidget.h"
#include "AccSettingWidget.h"
#include "UploadLicenseDlg.h"
#include "InfoCenterWidget.h"



EntCenterNewWidget::EntCenterNewWidget(EntCenterInfo* pEntInfo, UserInfoStruct* userInfo, QWidget *parent)
	 :QWidget(parent)
{
	m_userInfo = userInfo;
	//EntCenterInfo* m_pEntInfo = pEntInfo;
	m_pEnt = pEntInfo;


	ui.setupUi(this);
	/*resize(1002, 620);
	setWindowTitle(QString::fromLocal8Bit("��ҵ����"));*/
	//setWindowFlags(Qt::FramelessWindowHint);
	//setAttribute(Qt::WA_TranslucentBackground, true);
	//setStyleSheet("outline: none");
	m_bIsloadDb = false;

	
	mp_EntCenterMember = new EntCenterMemberWidget(pEntInfo, userInfo, ui.EntRightWidget);
	mp_EntCenterInfo = new EntCenterInfoWidget(pEntInfo, userInfo, ui.EntRightWidget);
	mp_EntCenterMain = new EntCenterMainWidget(pEntInfo, userInfo, ui.EntRightWidget);




	mp_EntCenterMember->hide();
	mp_EntCenterInfo->hide();

	///m_userInfo = userInfo;
	//connect(ui.entInfoButton, &QPushButton::clicked, this, &EntCenterNewWidget::onEntInfoBtnClick);
	connect(ui.mainButton, SIGNAL(clicked()), this, SLOT(onShowMain()));
	connect(ui.entInfoButton, SIGNAL(clicked()), this, SLOT(onShowInfo()));
	connect(ui.memberButton, SIGNAL(clicked()), this, SLOT(onShowMember()));
	connect(ui.copyTaxButton, SIGNAL(clicked()), this, SLOT(onCopyBtnClick()));
	connect(ui.switchButton, SIGNAL(clicked()), this, SLOT(onSwitchBtnClick()));


	ui.labelJoin2->installEventFilter(this);
	ui.labelJoin2->show();

	//ui.labelline->setGeometry(117, 195, 1, 14);

	//ui.labeluserline->hide();
	m_pEnt;

	showUserCompanyInfoTitle(m_pEnt);
	m_pEnt;


	pSwitchWidget = NULL;

	m_pJoinEntWidget = NULL;

	m_pEditEntinfo = NULL;

}



void EntCenterNewWidget::init(EntCenterInfo*	info){


	mp_EntCenterInfo->init(info);

	mp_EntCenterMain->init(info, m_userInfo);

	mp_EntCenterMember->init(info);

}
void EntCenterNewWidget::onShowInfo(){


	if (decideJoinEnt())
	{

		JoinEntMoreStep(m_pEnt);
		return;
	}

	mp_EntCenterInfo->show();
	mp_EntCenterMain->hide();
	mp_EntCenterMember->hide();
}

void EntCenterNewWidget::onShowMember(){

	if (decideJoinEnt())
	{
		JoinEntMoreStep(m_pEnt);
		return;
	}
	mp_EntCenterInfo->hide();
	mp_EntCenterMain->hide();
	mp_EntCenterMember->show();
}
void EntCenterNewWidget::onShowMain(){
	mp_EntCenterInfo->hide();
	mp_EntCenterMain->show();
	mp_EntCenterMember->hide();
}

EntCenterNewWidget ::~EntCenterNewWidget(){
	if (mp_EntCenterMember != NULL){
		mp_EntCenterMember->deleteLater();
		mp_EntCenterMember = NULL;
	}
	if (mp_EntCenterInfo != NULL){
		mp_EntCenterInfo->deleteLater();
		mp_EntCenterInfo = NULL;
	}
	if (mp_EntCenterMain != NULL){
		mp_EntCenterMain->deleteLater();
		mp_EntCenterMain = NULL;
	}
}


bool EntCenterNewWidget::winHttpJoinEnt(QString strToken, QString strComId, QString& strRet)
{

	QString strUrl = QString("/ucenter/company/apply-join");
	QString strPost = QString("company_id=%1&token=%2").arg(strComId).arg(strToken);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);
}

bool EntCenterNewWidget::winHttpAppealJoinEnt(EntCenterInfo* m_pFinishEntInfo,QString strToken, QString& strRet, QString& strMsg, int& stateCode)
{

	QString strUrl = QString("/ucenter/user/appeal");
	QString strPost = QString("token=%1&company_name=%2&tax=%3&province_id=%4&city_id=%5&area_id=%6&address=%7&legal_person_phone=%8&legal_person_name=%9&office_province_id=%10&office_city_id=%11&office_area_id=%12&office_address=%13&license=%14")
		.arg(strToken).arg(m_pFinishEntInfo->_strCompName).arg(m_pFinishEntInfo->_strTaxNo).arg(m_pFinishEntInfo->_nProvinceid)
		.arg(m_pFinishEntInfo->_nCityid).arg(m_pFinishEntInfo->_nAreaid).arg(m_pFinishEntInfo->_strAddress)
		.arg(m_pFinishEntInfo->_strlegalbossmobile).arg(m_pFinishEntInfo->_strlegalboss)
		.arg(m_pFinishEntInfo->_nOfficeProvinceid).arg(m_pFinishEntInfo->_nOfficeCityid).arg(m_pFinishEntInfo->_nOfficeAreaid)
		.arg(m_pFinishEntInfo->_strOfficeaddress).arg(m_pFinishEntInfo->strLicenseUrl);
	bool bret = ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);



	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return false;
	}
	if (!parse_doucment.isObject())
	{
		return false;
	}
	QJsonObject obj = parse_doucment.object();
	stateCode = obj.take("code").toInt();
	if (0 != stateCode)
	{
		switch (stateCode)
		{
		case 10013:
			strMsg = QString::fromLocal8Bit("ϵͳ�����ڴ��û���Ϣ����ȷ����Ĳ���");
			break;
		case 20001:
			strMsg = QString::fromLocal8Bit("��ҵ���Ʋ���Ϊ��");
			break;
		case 20002:
			strMsg = QString::fromLocal8Bit("��ҵ���Ƴ������벻��ȷ��4-50��");
			break;
		case 20003:
			strMsg = QString::fromLocal8Bit("˰�Ų���Ϊ��");
			break;
		case 20004:
			strMsg = QString::fromLocal8Bit("˰�����벻��ȷ");
			break;
		case 20005:
			strMsg = QString::fromLocal8Bit("˰�ų������벻��ȷ������15���ַ���");
			break;
		case 20006:
			strMsg = QString::fromLocal8Bit("��������ʡ�ݲ���Ϊ��");
			break;
		case 20007:
			strMsg = QString::fromLocal8Bit("��������ʡ�����벻��ȷ��������");
			break;
		case 20008:
			strMsg = QString::fromLocal8Bit("����������в���Ϊ��");
			break;
		case 20009:
			strMsg = QString::fromLocal8Bit("��������������벻��ȷ��������");
			break;
		case 20010:
			strMsg = QString::fromLocal8Bit("���������������Ϊ��");
			break;
		case 20011:
			strMsg = QString::fromLocal8Bit("��������������벻��ȷ ��������");
			break;
		case 20012:
			strMsg = QString::fromLocal8Bit("��ҵ��ַ����Ϊ��");
			break;
		case 20013:
			strMsg = QString::fromLocal8Bit("��ҵ��ַ���벻��ȷ��5-50���ַ���");
			break;
		case 20014:
			strMsg = QString::fromLocal8Bit("��ҵ���˲���Ϊ��");
			break;
		case 20015:
			strMsg = QString::fromLocal8Bit("��ҵ�������벻��ȷ");
			break;
		case 20016:
			strMsg = QString::fromLocal8Bit("��ҵ���˵绰����Ϊ��");
			break;
		case 20017:
			strMsg = QString::fromLocal8Bit("��ҵ���˵绰�������Ͳ���ȷ");
			break;
		case 20018:
			strMsg = QString::fromLocal8Bit("��ҵ���˵绰���볤�Ȳ���ȷ��11λ���֣�");
			break;
		case 20019:
			strMsg = QString::fromLocal8Bit("����������ȷ");
			break;
		case 20034:
			strMsg = QString::fromLocal8Bit("ϵͳ�����ڴ���ҵ��Ϣ����ȷ����Ĳ���");
			break;
		case 20035:
			strMsg = QString::fromLocal8Bit("��ҵ��Ϣ����ʧ��");
			break;
		case 20038:
			strMsg = QString::fromLocal8Bit("��ǰ��ҵ�Ѿ��󶨹�����Ա��");
		case 20040:
			strMsg = QString::fromLocal8Bit("˰�������Ͳ���Ϊ��");
			break;
		case 20041:
			strMsg = QString::fromLocal8Bit("˰�������Ͳ���ȷ");
			break;
		case 20042:
			strMsg = QString::fromLocal8Bit("ϵͳ�Ѵ��ڴ����Ƶ���ҵ��Ϣ");
			break;
		case 20043:
			strMsg = QString::fromLocal8Bit("�����칫����ʡ�ݲ���Ϊ��");
			break;
		case 20044:
			strMsg = QString::fromLocal8Bit("�����칫����ʡ�����벻��ȷ");
			break;
		case 20045:
			strMsg = QString::fromLocal8Bit("�����칫������в���Ϊ��");
			break;
		case 20046:
			strMsg = QString::fromLocal8Bit("�����칫����������벻��ȷ");
			break;
		case 20047:
			strMsg = QString::fromLocal8Bit("�����칫�����������Ϊ��");
			break;
		case 20048:
			strMsg = QString::fromLocal8Bit("�����칫����������벻��ȷ");
			break;
		case 20049:
			strMsg = QString::fromLocal8Bit("��ҵ�칫��ַ����Ϊ��");
			break;
		case 20050:
			strMsg = QString::fromLocal8Bit("��ҵ�칫��ַ���벻��ȷ");
			break;
		case 20051:
			strMsg = QString::fromLocal8Bit("�����칫������ȷ");
			break;
			break;
		case 20052:
			strMsg = QString::fromLocal8Bit("���ϴ�����Ӫҵִ��");
			break;
		case 40000:
			strMsg = QString::fromLocal8Bit("���Ѿ��ύ������Ϣ�ˣ�ϵͳ���ڴ����У��벻Ҫ�ظ��ύ");
			break;
		case 40001:
			strMsg = QString::fromLocal8Bit("��ǰ��ҵδ�󶨹���Ա���޷�����");
			break;
		default:
			break;
		}




		return false;
	}

	int jmsg = obj.take("data").toInt();
	if (jmsg==1)
		strMsg = QString::fromLocal8Bit("���³ɹ�");
	else
		strMsg = QString::fromLocal8Bit("����ʧ��");
	return jmsg;
}

bool EntCenterNewWidget::eventFilter(QObject *target, QEvent *e)
{
	//if (target == ui.copyTaxButton)
	//{
	//	if (e->type() == QEvent::Enter) //
	//	{
	//		QString strText = ui.labelCopy->text();
	//		if (QString::fromLocal8Bit("����")!=	strText)
	//		{
	//			ui.labelCopy->setText(QString::fromLocal8Bit("����"));
	//		}
	//		ui.labelCopy->show();
	//	}
	//	else if (e->type() == QEvent::Leave)
	//	{
	//		ui.labelCopy->hide();
	//	}
	//}
	//else 
	if (target == ui.labelJoin2)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC003");


			if (decideJoinEnt())
				DoJoinEntMoreStep(m_pEnt,m_info.isbindEnt == false);
		/*	if (ZcloudComFun::winHttpSSO(m_pEntInfo->_strToken, m_pEntInfo->_strUid))
			{



				if (!this->findChild <JoinEntWidget*>("addEntEnter"))
				{
					if (m_pJoinEntWidget == NULL)
						m_pJoinEntWidget = new JoinEntWidget(m_pEntInfo->_strUid, m_pEntInfo->_strToken, this);
					m_pJoinEntWidget->show();
				}
			}*/
		}
	}
	return QWidget::eventFilter(target, e);
}

void EntCenterNewWidget::onCopyBtnClick()
{
	ui.copyTaxButton->setEnabled(false);
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC002");
	QString strTaxNo = ui.labelTaxNo->text();
	QClipboard *clipboard = QApplication::clipboard();   //��ȡϵͳ������ָ��  
	if (NULL == clipboard)
	{
		//		ui.labelCopy->setText(QString::fromLocal8Bit("����ʧ��"));
		//	ui.copyTaxButton->setEnabled(true);
		return;
	}
	QString originalText = clipboard->text();         //��ȡ���������ı���Ϣ  
	clipboard->setText(strTaxNo);
	//	ui.labelCopy->setText(QString::fromLocal8Bit("�Ѹ���"));
	ui.copyTaxButton->setEnabled(true);
}

void EntCenterNewWidget::onSwitchBtnClick()
{
	SwitchBtnClick(m_pEnt);
}
void EntCenterNewWidget::SwitchBtnClick(EntCenterInfo*	m_pEntInfo)
{
	m_pEnt;
	//if (pSwitchWidget == NULL)
	//{
	//pWidget = new SwitchAccWidget(m_userInfo->m_strUserId, m_userInfo->m_strToken, m_userInfo->m_strUsername, m_userInfo->m_strCompanyId, this);

	pSwitchWidget = new SwitchAccNewWidget(m_userInfo, m_pEntInfo, this);
	pSwitchWidget->setAttribute(Qt::WA_DeleteOnClose);

	connect(pSwitchWidget, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));
	connect(pSwitchWidget, SIGNAL(sigJoinEnt(QString)), this, SLOT(onJoinEnt(QString)));

	pSwitchWidget->setAttribute(Qt::WA_DeleteOnClose);



	//}
	pSwitchWidget->show();


	//ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC010");
}

void EntCenterNewWidget::onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd)
{
	emit sigSwitchAcc(bLoginByTax, bOther, strTaxNo_userName, strPwd);
}

void EntCenterNewWidget::showUserCompanyInfoTitle(EntCenterInfo*	m_pEntInfo)
{
	clearUserCompanyInfoTitle();

	QString strServerUserid, strRet;
	bool bret = false;
	int nsjoin = 0;
	int nroletype = -1;
	//m_strLocalTaxno = "210624197305200017";

	//�ô�����������ʽ  �����������
	QString strtaxno, struserorjoin1, strrole, strjoinaction;
	//δ��ѯ����ҵ����
	if (m_userInfo->m_strCompanyName.isEmpty())
	{
		///////�οͻ��������û�û��ֱ�Ӷ�Ӧ����ҵ����ʾ������Ҫ���Ȳ�ѯ����ע���˰�ţ�Ȼ��ȥ��̨���ݿ�ȡ�ȶԡ�Ȼ��ȡ������ʾ.
		ui.labelComName->setText(QString::fromLocal8Bit("��δ��ѯ����ҵ����"));

		///ȡ�����ע�����,�ָȻ�󴫵���̨
		m_strLocalTaxno = ZcloudComFun::getTaxnumbers();

		/////ע����ѯ��������ʱ��ֵ����189�˺ŵ�½
		///m_strLocalTaxno = "210624197305200017,91458732MA5UYRPW7R";
		bret = ZcloudComFun::winHttpQueryCompanyInfoLocalTax(m_strLocalTaxno, m_userInfo->m_strToken, m_info);
		//�Ѽ�����ҵ
		if (bret)
		{
			if (m_info.nIsjoin == 1)
			{
				////�����û��Ķ�Ӧ��˾��δ�������˵��û�м�����ҵ������һ�㲻�᷵���м������ҵ�������������Ҳ���ᷢ����
				showaddCompanyInfoTitle(m_info.strCompany, m_userInfo->m_strTaxNumber, m_userInfo->m_strUsername, m_info.strRoletype);
			}
			else
			{
				////�����û���18980084535����½��û�ж�Ӧ��˾��Ȼ�󷵻ر��ض��˰�Ų�ѯ�����û���������ҵ�б���ƥ��ĵ�һ����ҵ˰�ż������Ϣ������ʾ
				////������ϢҪ��ʾ  ����û�������ҵ �������룬
				/////Ҳ�����ο͵�½

				struserorjoin1 = QString::fromLocal8Bit("����û�������ҵ��");
				strjoinaction = QString::fromLocal8Bit("�������룬");
				showUnaddCompanyInfoTitle(m_info.strCompany, m_info.strTaxno, struserorjoin1, strjoinaction);

			}
		}
		else
		{
			showUnaddCompanyInfoTitle(m_info.strCompany, "", "", "");


		}
	}
	else  /////�����û��е�ǰ������ҵ�������ʾ
	{
		bret = ZcloudComFun::winHttpQueryCompanyInfoLocalTax(m_userInfo->m_strTaxNumber, m_userInfo->m_strToken, m_info);
		//�Ѽ�����ҵ
		if (m_info.nIsjoin == 1)
		{
			showaddCompanyInfoTitle(m_info.strCompany, m_userInfo->m_strTaxNumber, m_userInfo->m_strUsername, m_info.strRoletype);

			////���ؼ��밴ť
			//ui.labeJoin1->hide();
			////ui.labelJoin2->hide();	
			////��ʾ���� ְ��
			//
			//ui.labeluser->show();
			//ui.labeluserline->show();
			//ui.labeluserroletype->show();

			//ui.labeluser->setText(m_pEntInfo->_strUsername);
			////if (m_info.nroletype == 1)
			//if (m_pEntInfo->_nrole_type == 1){
			//	ui.labeluserroletype->setText(QString::fromLocal8Bit("����Ա"));
			//}
			//else{
			//	ui.labeluserroletype->setText(QString::fromLocal8Bit("������Ա"));
			//}
		}
		else{
			//ui.labeJoin1->show();
			//ui.labelJoin2->show();

			//ui.labeluser->hide();
			//ui.labeluserline->hide();
			//ui.labeluserroletype->hide();

			//struser = QString::fromLocal8Bit("����û�������ҵ��");
			//straddcompany = QString::fromLocal8Bit("�������룬");
			////�������û���Ӧ��˰��ȡ���û�������ҵ�б�һ�㲻��鵽û�м������ҵ��Ϣ�������δ����벻��ִ�С�
			showUnaddCompanyInfoTitle(m_info.strCompany, m_userInfo->m_strTaxNumber, m_userInfo->m_strUsername, strjoinaction);
		}


		//if (m_info.nIsjoin == 1)
		//	showaddCompanyInfoTitle(m_info.strCompany, m_userInfo->m_strTaxNumber, m_userInfo->m_strUsername, strrole);
		//else if (m_info.nIsjoin != 0)
		//{
		//	struser = QString::fromLocal8Bit("����û�������ҵ��");
		//	straddcompany = QString::fromLocal8Bit("�������룬");
		//	showUnaddCompanyInfoTitle(m_info.strCompany, m_userInfo->m_strTaxNumber, m_userInfo->m_strUsername, straddcompany);
		//}
	}


	//Logo
	if (m_userInfo->m_logoUrl.isEmpty()){
		ui.labelAvatar->setStyleSheet("border-image: url(:/EntCenterWidget/image/img_tx_d.png);");
	}
	else{

		ZcloudComFun::LoadAvatar(m_userInfo->m_logoUrl.toStdString(), ui.labelAvatar);
	}


	//��˾��
	if (m_userInfo->m_strCompanyName.isEmpty() && m_info.strCompany.isEmpty())
	{
		ui.labelComName->setText(QString::fromLocal8Bit("��δ��ѯ����ҵ����"));
	}
	else if (!m_info.strCompany.isEmpty())
	{
		ui.labelComName->setText(m_info.strCompany);
	}
	else
	{
		ui.labelComName->setText(m_userInfo->m_strCompanyName);
	}

	//˰��
	if (!m_pEntInfo->_strTaxNo.isEmpty())
	{
		//bret = ZcloudComFun::winHttpQueryCompanyInfoLocalTax(m_strLocalTaxno, m_userInfo->m_strToken, m_info);
		ui.labelTaxNo->show();
		ui.labelTaxNo->setText(m_pEntInfo->_strTaxNo);
		ui.copyTaxButton->show();

	}
	else
	{
		ui.copyTaxButton->hide();
		ui.copyTaxButton->hide();
		ui.copyTaxButton->setText("");
	}

	//�Ѿ�������ҵ
	if (m_info.nIsjoin == 1)
	{
		//���밴ť
		ui.labeJoin1->hide();
		//ui.labelJoin2->hide();
		//������Ϣ
		ui.labeluser->show();
		ui.labeluserline->show();
		ui.labeluserroletype->show();




		m_info.nIsjoin = nsjoin;
	}
	else
	{
		//δ������ҵ

		ui.labeJoin1->show();
		ui.labelJoin2->show();

		ui.labeluser->hide();
		ui.labeluserline->hide();
		ui.labeluserroletype->hide();

	}
}

void EntCenterNewWidget::clearUserCompanyInfoTitle()
{
	ui.labelComName->setText("");
	ui.labelTaxNo->setText("");
	ui.labeJoin1->setText("");
	ui.labeluser->setText("");
	//ui.labelroletype->setText("");
	//ui.labelJoin2->hide();
	ui.labeJoin1->hide();
	ui.labeluserline->hide();
	ui.labeluser->hide();
	ui.labelTaxNo->hide();
	//ui.labelCopy->hide();
}


void EntCenterNewWidget::showUnaddCompanyInfoTitle(QString _strcompany, QString _strtaxno, QString _strUserorjoin1, QString _strjoinaction)
{

	ui.labelAvatar->setGeometry(95, 59, 60, 60);
	ui.labelAvatar->setStyleSheet("background:rgba(216,216,216,1);	border:1px solid rgba(151, 151, 151, 1); ");

	ui.labelComName->setGeometry(55, 139, 140, 14);
	ui.labelComName->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;	font-weight:400;color:rgba(51, 51, 51, 1);line-height:21px; \"> %1</span></p></body></html>").arg(_strcompany));
	ui.labelComName->show();

	if (!_strUserorjoin1.isEmpty())
	{
		ui.labeJoin1->setGeometry(35, 195, 126, 18);
		ui.labeJoin1->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(102, 102, 102, 1);line-height:21px;\"> %1</span></p></body></html>").arg(_strUserorjoin1));
		//ui.labeluser->setStyleSheet("font-size:14px;font - family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(102, 102, 102, 1);line-height:21px; ");
		ui.labeJoin1->show();
	}
	else
		ui.labeJoin1->hide();



	if (!_strtaxno.isEmpty())
	{
		ui.labelTaxNo->setGeometry(64, 163, 122, 16);
		ui.labelTaxNo->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:12px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(51, 51, 51, 1);line-height:18px;\"> %1</span></p></body></html>").arg(_strtaxno));
		ui.labelTaxNo->show();
	}
	else
		ui.labelTaxNo->hide();

	if (!_strjoinaction.isEmpty())
	{
		ui.labelJoin2->setGeometry(161, 195, 56, 18);
		ui.labelJoin2->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(30, 139, 237, 1);line-height:21px;\"> %1</span></p></body></html>").arg(_strjoinaction));
		ui.labelJoin2->show();
	}
	else
		//ui.labelJoin2->hide();
	ui.labeluserroletype->hide();
	ui.labeluserline->hide();
	ui.labeluser->hide();

	
	//ui.labelAddComp->setStyleSheet("font-size:14px;	font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(30, 139, 237, 1);line-height:21px; ");

	//ui.switchButton->setGeometry(75, 229, 100, 38);


	//ui.copyTaxButton->setGeometry(191, 162, 16, 16);
	ui.copyTaxButton->setStyleSheet("QPushButton{border-image: url(:/EntCenterWidget/image/copy.png);}\nQPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/copy_sel.png);}");
	ui.copyTaxButton->hide();



}

void EntCenterNewWidget::showUnqueryCompanyInfoTitle()
{
	////ui.labelAvatar->setGeometry(95, 59, 60, 60);
	////ui.labelAvatar->setStyleSheet("background:rgba(216,216,216,1);	border:1px solid rgba(151, 151, 151, 1); ");

	////ui.labelComName->setGeometry(62, 139, 126, 14);

	//ui.labelComName->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;	font-weight:400;color:rgba(51, 51, 51, 1);line-height:21px; \"> %1</span></p></body></html>").arg(m_info.strCompany));
	//ui.labelAddComp->hide();
	//ui.labelroletype->hide();
	//ui.labelline->hide();

	//ui.labeluser->hide();

	//ui.labelTaxNo->hide();
	//ui.copyTaxButton->hide();
}

void EntCenterNewWidget::showaddCompanyInfoTitle(QString _strcompany, QString _strtaxno, QString _strUser, QString _straroletype)
{

	////ui.labelAvatar->setGeometry(95, 59, 60, 60);
	ui.labelAvatar->setStyleSheet("background:rgba(216,216,216,1);	border:1px solid rgba(151, 151, 151, 1); ");

	////ui.labelComName->setGeometry(55, 139, 140, 14);

	ui.labelComName->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font - family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(51, 51, 51, 1);line-height:21px; \"> %1</span></p></body></html>").arg(_strcompany));


	////ui.labeluser->setGeometry(59, 195, 126, 14);

	ui.labeluser->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font - family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(51, 51, 51, 1);	line-height:21px; \"> %1</span></p></body></html>").arg(_strUser));


	////ui.labelTaxNo->setGeometry(64, 163, 122, 12);

	ui.labelTaxNo->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:12px;font - family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(51, 51, 51, 1);line-height:18px;\"> %1</span></p></body></html>").arg(_strtaxno));

	ui.labelTaxNo->show();

	ui.labeJoin1->hide();
	//ui.labelJoin2->hide();

	ui.labeluser->show();
	ui.labeluserroletype->show();
	ui.labeluserline->show();
	////ui.labelroletype->setGeometry(128, 195, 42, 14);

	ui.labeluserroletype->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(102, 102, 102, 1);line-height:21px;\"> %1</span></p></body></html>").arg(_straroletype));


	////ui.switchButton->setGeometry(75, 229, 100, 38);
	ui.switchButton->setStyleSheet("background:linear - gradient(90deg, rgba(2, 164, 253, 1) 0 % , rgba(31, 139, 237, 1) 100 % );box - shadow:0px 3px 8px - 2px rgba(2, 165, 253, 0.85), 0px 6px 11px - 2px rgba(2, 165, 253, 0.64);border - radius:4px; ");


	////ui.copyTaxButton->setGeometry(191, 162, 16, 16);
	ui.copyTaxButton->setStyleSheet("QPushButton{border-image: url(:/EntCenterWidget/image/copy.png);}\nQPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/copy_sel.png);}");
	ui.copyTaxButton->show();

	ui.labelJoin2->setStyleSheet("font-size:14px;	font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(30, 139, 237, 1);line-height:21px; ");


}
////������ҵ�����������û���½���޶�Ӧ��ҵ�������ο͵�½����ע����ж���˰�Ŷ�Ӧ�Ĺ�˾�ļ�����ҵ�����ȵ�
////�����û�����ҵ���ĺ���ʾ����ҵ���Ƕ�Ӧ��˾������£������Ǵ�ע���˰���бȶԵ���Ϣ�����Գ�Ա������ҵ���ϣ��ҵĹ����Ƚ��в���ʱ��
////���ȵ���������ҵ��ܰ��ʾ��
void EntCenterNewWidget::JoinEntMoreStep(EntCenterInfo* m_pEntInfo)
{

	if (m_info.bloadDb == false && m_userInfo->m_strCompanyName.isEmpty())
	{

		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\nû����ҵ����ȷ�����Ĳ�����"));
		return;
	}

	int nReturn = ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ܰ��ʾ"), QString::fromLocal8Bit("��Ǹ������û����ʽ����\"%1\",���ȼ�����ҵ���ټ���������").arg(m_info.strCompany), QString::fromLocal8Bit("��������"), QString::fromLocal8Bit("�ݲ�����"), this);
	if (nReturn == QDialog::Accepted)
	{
		DoJoinEntMoreStep(m_pEntInfo,m_info.isbindEnt == false);
		return;

	}

}
bool EntCenterNewWidget::decideJoinEnt()
{
	if (m_userInfo->m_strCompanyName.isEmpty() && m_info.nIsjoin == 0)
	{
		return true;
	}
	else
		return false;
		
}

////ʵ�ʲ���������ҵ
bool EntCenterNewWidget::DoapplyJoinEnt(QString strCompanyid,int& stcode)
{
	QString strRet;
	if (!winHttpJoinEnt(m_userInfo->m_strToken, strCompanyid, strRet))
	//if (!winHttpJoinEnt(m_userInfo->m_strToken, m_info.strcompanyid, strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("������ҵ"), QString::fromLocal8Bit("����ʧ��"));
		return false;
	}


	QByteArray byte_array = strRet.toUtf8();
	QJsonParseError json_error;
	QJsonObject obj;
	QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
	if (json_error.error != QJsonParseError::NoError)
	{
		return false;
	}
	if (!parse_doucment.isObject())
	{
		return false;
	}
	obj = parse_doucment.object();
	stcode = obj.take("code").toInt();
	if (0 == stcode)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("�����ɹ�"), QString::fromLocal8Bit("�ѳɹ��ύ�������룬\r\n��ȴ��Է�����Ա���ͨ����"));
		return true;
	}
	else if (20034 == stcode)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��������ʧ�ܣ�ϵͳ�����ڴ���ҵ��Ϣ����ȷ����Ĳ�����"));
	}
	else if (60001 == stcode)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��������ʧ�ܣ��������ҵ����Ϊ�գ�"));
	}
	else if (60002 == stcode)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��������ʧ�ܣ��������ҵid���Ͳ���ȷ��"));
	}
	else if (60003 == stcode)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("\r\n��������ʧ�ܣ������ύ���������ˣ���ȴ���ҵ����Ա��ˣ�"));
	}
	else if (60004 == stcode)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("\r\n��������ʧ�ܣ����Ѿ�����ҵ�ĳ�Ա�ˣ��벻Ҫ�ظ����룡"));
	}
	else
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��������ʧ�ܣ����Ժ����ԣ�"));
	}
	return false;
}
////������ҵ���ϣ��󶡲��󶨣�����Ҫ������ҵ����
bool EntCenterNewWidget::JoinStep2FinishEntinfo(EntCenterInfo* m_pEntInfo, EntCenterInfo* m_pFinishEntInfo)
{


	if (m_pEditEntinfo == NULL)
		m_pEditEntinfo = new EditEntInfoWidget(m_userInfo, m_pEntInfo);

	if (m_pEditEntinfo->exec() == QDialog::Accepted)
	{



		m_pFinishEntInfo = m_pEditEntinfo->getFinishEnterInfo();
		///m_pEditEntinfo->accept();
		if (m_pFinishEntInfo != NULL)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool EntCenterNewWidget::JoinStep2AppealGetEntInfo(EntCenterInfo* m_pEntInfo_old, EntCenterInfo* m_pFinishEntInfo)
{
	if (m_pEditEntinfo == NULL)
		m_pEditEntinfo = new EditEntInfoWidget(m_userInfo, m_pEntInfo_old);

	m_pEditEntinfo->ChangeShow(false);
	if (m_pEditEntinfo->exec() == QDialog::Accepted)
	{



		m_pFinishEntInfo = m_pEditEntinfo->getFinishEnterInfo();
		///m_pEditEntinfo->accept();
		if (m_pFinishEntInfo != NULL)
			return true;
		else
			return false;
	}
	else
		return false;
}

void EntCenterNewWidget::DoAppealEnt(EntCenterInfo* m_pEntInfo)
{
	EntCenterInfo* m_pFinishEntInfo;
	if (JoinStep2AppealGetEntInfo(m_pEntInfo,m_pFinishEntInfo))
	{


		UploadLicenseDlg updlg(m_userInfo);
		if (updlg.exec() == QDialog::Accepted)
		{
			////�ɹ���������ҵ����Ϣ���ϴ���Ӫҵִ�ն��������ҵ���ݽṹ��ָ����
			m_pFinishEntInfo->strLicenseUrl = updlg.getLicenseUrl();
			////����
			QString strRet, strMsg;
			int statecode;
			if (!winHttpAppealJoinEnt(m_pFinishEntInfo,m_userInfo->m_strToken, strRet, strMsg, statecode))
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ܰ��ʾ"), QString::fromLocal8Bit("ϵͳ����"), this);
				return;
			}
			if (statecode == 0)
			{

				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ܰ��ʾ"), QString::fromLocal8Bit("�Ѿ��ɹ��ݽ���������"), this);
				return;
			}
			else
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ܰ��ʾ"), strMsg, this);
				return;
			}

		}
	}
	else
	{
		return;
	}
}



void EntCenterNewWidget::DoJoinEntMoreStep(EntCenterInfo* m_pEntInfo,bool isbinding)
{

	//if (m_info.bloadDb == false && m_userInfo->m_strCompanyName.isEmpty())
	//{

	//	ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\nû����ҵ����ȷ�����Ĳ�����"));
	//	return;
	//}

	////�������������ж������ҵ�Ƿ����ҵ����Ա��Ȼ����������
	if (isbinding)
	{

		EntCenterInfo* m_pFinishEntInfo;
		////������ҵ���ϣ�	����û�а󶨵���ҵ���û���ֱ�Ӽ�����ҵ��
		if (JoinStep2FinishEntinfo(m_pEntInfo,m_pFinishEntInfo))
		{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("��ܰ��ʾ"), QString::fromLocal8Bit("�Ѿ�������ҵ"), this);
		}
	}
	else   ////���ˣ���ֻ�ݽ�����
	{
		int stcode = -1;
		////�ݽ�������ҵ����
		//if (DoapplyJoinEnt(m_info.strcompanyid,stcode))

		if (DoapplyJoinEnt(m_pEntInfo->_strCompId, stcode))
			
		{
			////�ɹ��ݽ�������ҵ����
			//ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n����������������ȷ��"));

			////����
			int nReturn1 = ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ܰ��ʾ"), QString::fromLocal8Bit("����������Ϣ���ύ����ȴ���ҵ����Ա��ˡ�������Ե�ǰ��ҵ����Ա��ݴ������ʣ���������"), QString::fromLocal8Bit("����"), QString::fromLocal8Bit("ȡ��"), this);
			if (nReturn1 == QDialog::Accepted)
			{


				DoAppealEnt(m_pEntInfo);
				return;

			}
			else
			{
				return;
			}

		}
		else
		{
			///�ݽ�������ҵ����ʧ��
			if (stcode == 60003)
			{

				////����
				int nReturn1 = ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ܰ��ʾ"), QString::fromLocal8Bit("����������Ϣ���ύ����ȴ���ҵ����Ա��ˡ�������Ե�ǰ��ҵ����Ա��ݴ������ʣ���������"), QString::fromLocal8Bit("����"), QString::fromLocal8Bit("ȡ��"), this);
				if (nReturn1 == QDialog::Accepted)
				{


					DoAppealEnt(m_pEntInfo);
					return;

				}
				else
				{
					return;
				}



			}


			return;
		}

	}
}


bool EntCenterNewWidget::onJoinEnt(QString strTaxNum) {
	/*ZcloudComFun::dbEntInfo pEnt;
	ZcloudComFun::winHttpQueryCompanyInfoLocalTax(strTaxNum, m_userInfo->m_strToken, pEnt);*/

	EntCenterInfo	info;
	QString strRet;
	//��ȡ��ҵ��Ϣ
	if (InfoCenterWidget::getEntInfo(&info, strTaxNum, m_userInfo->m_strToken, strRet))
	{
		
		DoJoinEntMoreStep(&info, info._nisbinds);
	}
	

	return true;
}

