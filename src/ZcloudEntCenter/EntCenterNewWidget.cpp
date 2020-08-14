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


EntCenterNewWidget::EntCenterNewWidget(EntCenterInfo* pEntInfo, UserInfoStruct* userInfo, QWidget *parent)
	:m_pEntInfo(pEntInfo), m_userInfo(userInfo), QWidget(parent)
{
	ui.setupUi(this);
	/*resize(1002, 620);
	setWindowTitle(QString::fromLocal8Bit("��ҵ����"));*/
	//setWindowFlags(Qt::FramelessWindowHint);
	//setAttribute(Qt::WA_TranslucentBackground, true);
	//setStyleSheet("outline: none");

	mp_EntCenterMember = new EntCenterMemberWidget(pEntInfo, userInfo,ui.EntRightWidget);
	mp_EntCenterInfo = new EntCenterInfoWidget(pEntInfo,userInfo, ui.EntRightWidget);
	mp_EntCenterMain = new EntCenterMainWidget(pEntInfo, userInfo, ui.EntRightWidget);




	mp_EntCenterMember->hide();
	mp_EntCenterInfo->hide();

	m_userInfo = userInfo;
	//connect(ui.entInfoButton, &QPushButton::clicked, this, &EntCenterNewWidget::onEntInfoBtnClick);
	connect(ui.mainButton, SIGNAL(clicked()), this, SLOT(onShowMain()));
	connect(ui.entInfoButton, SIGNAL(clicked()), this, SLOT(onShowInfo()));
	connect(ui.memberButton, SIGNAL(clicked()), this, SLOT(onShowMember()));
	connect(ui.copyTaxButton, SIGNAL(clicked()), this, SLOT(onCopyBtnClick()));
	connect(ui.switchButton, SIGNAL(clicked()), this, SLOT(onSwitchBtnClick()));

	
	ui.labelJoin2->installEventFilter(this);


	//ui.labelline->setGeometry(117, 195, 1, 14);
	
	//ui.labeluserline->hide();

	showUserCompanyInfoTitle();



	pWidget = NULL;

	m_pJoinEntWidget = NULL;
	
}



void EntCenterNewWidget::init(EntCenterInfo*	info){
	m_pEntInfo = info;
	mp_EntCenterInfo->init(info);

	mp_EntCenterMain->init(info,m_userInfo);
	
	mp_EntCenterMember->init(info);

}
void EntCenterNewWidget::onShowInfo(){

	if (m_info.nIsjoin == 0)
	{

		int nReturn = ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("��ܰ��ʾ"), QString::fromLocal8Bit("��Ǹ������û����ʽ����\"%1\",���ȼ�����ҵ���ټ���������").arg(m_info.strCompany), this);
		if (nReturn == QDialog::Accepted)
		{


			if (m_info.isbindEnt == false)
			{
				if (m_pEditEntinfo == NULL)
					m_pEditEntinfo = new EditEntInfoWidget(m_userInfo, m_pEntInfo);

				m_pEditEntinfo->show();
			}

			//	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TAU008", "", true);
			//this->hide();
			//emit sigLogout();
			//��������
			/*	if (m_pJoinEntWidget == NULL)
			m_pJoinEntWidget = new JoinEntWidget(m_userInfo.m_strUserId, m_userInfo.m_strToken, this);
			m_pJoinEntWidget->show();*/

			/////----------------------------������ҵok


			/*QString strRet;
			if (!winHttpJoinEnt(m_userInfo.m_strToken, m_info.strcompanyid, strRet))
			{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("������ҵ"), QString::fromLocal8Bit("����ʧ��"));
			return;
			}


			QByteArray byte_array = strRet.toUtf8();
			QJsonParseError json_error;
			QJsonObject obj;
			QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
			if (json_error.error != QJsonParseError::NoError)
			{
			return;
			}
			if (!parse_doucment.isObject())
			{
			return;
			}
			obj = parse_doucment.object();
			int status = obj.take("code").toInt();
			if (0 == status)
			{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("�����ɹ�"), QString::fromLocal8Bit("�ѳɹ��ύ�������룬\r\n��ȴ��Է�����Ա���ͨ����"));

			}
			else if (20034 == status)
			{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��������ʧ�ܣ�ϵͳ�����ڴ���ҵ��Ϣ����ȷ����Ĳ�����"));
			}
			else if (60001 == status)
			{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��������ʧ�ܣ��������ҵ����Ϊ�գ�"));
			}
			else if (60002 == status)
			{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��������ʧ�ܣ��������ҵid���Ͳ���ȷ��"));
			}
			else if (60003 == status)
			{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("\r\n��������ʧ�ܣ������ύ���������ˣ���ȴ���ҵ����Ա��ˣ�"));
			}
			else if (60004 == status)
			{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("\r\n��������ʧ�ܣ����Ѿ�����ҵ�ĳ�Ա�ˣ��벻Ҫ�ظ����룡"));
			}
			else
			{
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("����ʧ��"), QString::fromLocal8Bit("\r\n��������ʧ�ܣ����Ժ����ԣ�"));
			}
			return;*/
		}
		else
		{
			///ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TAU009");
			return;
		}
	}

	mp_EntCenterInfo->show();
	mp_EntCenterMain->hide();
	mp_EntCenterMember->hide();
}

void EntCenterNewWidget::onShowMember(){
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
	QString strPost = QString("company_id=%1&token=%2").arg(strComId).arg(m_pEntInfo->_strToken);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);
}

bool EntCenterNewWidget ::eventFilter(QObject *target, QEvent *e)
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
			if (ZcloudComFun::winHttpSSO(m_pEntInfo->_strToken, m_pEntInfo->_strUid))
			{

				

				if (!this->findChild <JoinEntWidget*>("addEntEnter"))
				{
					if (m_pJoinEntWidget==NULL)
						m_pJoinEntWidget = new JoinEntWidget(m_pEntInfo->_strUid, m_pEntInfo->_strToken, this);
					m_pJoinEntWidget->show();
				}
			}
		}
	}
	return QWidget::eventFilter(target, e);
}

void EntCenterNewWidget ::onCopyBtnClick()
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

void EntCenterNewWidget ::onSwitchBtnClick()
{
	if (pWidget == NULL)
	{
		pWidget = new SwitchAccWidget(m_userInfo->m_strUserId, m_userInfo->m_strToken, m_userInfo->m_strUsername, m_userInfo->m_strCompanyId, this);
		connect(pWidget, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));
		//connect(this, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SLOT(onSwitchAcc(int, bool, QString, QString)));

		pWidget->setAttribute(Qt::WA_DeleteOnClose);
	}
	pWidget->show();
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC010");
}

void EntCenterNewWidget::onSwitchAcc(int bLoginByTax, bool bOther, QString strTaxNo_userName, QString strPwd)
{
	emit sigSwitchAcc(bLoginByTax, bOther, strTaxNo_userName, strPwd);
}

void EntCenterNewWidget::showUserCompanyInfoTitle()
{
	clearUserCompanyInfoTitle();

	QString strServerUserid, strRet;
	bool bret = false;
	int nsjoin = 0;
	int nroletype = -1;
	m_strLocalTaxno = "210624197305200017";

	//QString strtaxno, struser, strrole, straddcompany;

	//Logo
	if (m_userInfo->m_logoUrl.isEmpty()){
		ui.labelAvatar->setStyleSheet("border-image: url(:/EntCenterWidget/image/img_tx_d.png);");
	}
	else{
		
		ZcloudComFun::LoadAvatar(m_userInfo->m_logoUrl.toStdString(), ui.labelAvatar);
	}
	

	//��˾��
	if (m_userInfo->m_strCompanyName.isEmpty())
		{
			ui.labelComName->setText(QString::fromLocal8Bit("��δ��ѯ����ҵ����"));			
		}
		else
		{
			ui.labelComName->setText(m_userInfo->m_strCompanyName);
		}

	//˰��
	if (!m_pEntInfo->_strTaxNo.isEmpty())
	{
		//bret = ZcloudComFun::winHttpQueryCompanyInfoLocalTax(m_strLocalTaxno, m_userInfo->m_strToken, m_info);
		ui.labeltaxno->show();
		ui.labeltaxno->setText(m_pEntInfo->_strTaxNo);
		ui.copyTaxButton->show();

	}
	else
	{
		ui.copyTaxButton->hide();
		ui.labeltaxno->hide();
		ui.labeltaxno->setText("");
	}

	//�Ѿ�������ҵ
	if (m_info.nIsjoin == 1)
	{
		//���밴ť
		ui.labeJoin1->hide();
		ui.labelJoin2->hide();
		//������Ϣ
		ui.labeluser->show();
		ui.labeluserline->show();
		ui.labeluserroletype->show();

		ui.labeluser->setText(m_pEntInfo->_strUsername);
		if (m_pEntInfo->_nrole_type == 1){
			ui.labeluserroletype->setText(QString::fromLocal8Bit("����Ա"));
		}
		else{
			ui.labeluserroletype->setText(QString::fromLocal8Bit("������Ա"));
		}


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



	//if (m_userInfo->m_strCompanyName.isEmpty())
	//{
	//	ui.labelComName->setText(QString::fromLocal8Bit("��δ��ѯ����ҵ����"));

	//	
	//}
	//else
	//{


	//	bret = ZcloudComFun::winHttpQueryCompanyInfoLocalTax(m_userInfo->m_strTaxNumber, m_userInfo->m_strToken, m_info);


	//	if (m_info.nIsjoin == 1)
	//	{

	//		ui.labelAddComp->setText("");
	//		ui.labelAddComp->hide();

	//		
	//	}

	//	if (m_info.nroletype == 1)
	//	{
	//		//ui.labelline->show();
	//		//ui.labelroletype->setText(QString::fromLocal8Bit("����Ա"));
	//		strrole = QString::fromLocal8Bit("����Ա");
	//	}
	//	else
	//		strrole = QString::fromLocal8Bit("������Ա");

	//	if (m_info.nIsjoin == 1)
	//		showaddCompanyInfoTitle(m_info.strCompany, m_userInfo->m_strTaxNumber, m_userInfo->m_strUsername, strrole);
	//	else if (m_info.nIsjoin != 0)
	//	{
	//		struser = QString::fromLocal8Bit("����û�������ҵ��");
	//		straddcompany = QString::fromLocal8Bit("�������룬");
	//		showUnaddCompanyInfoTitle(m_info.strCompany, m_userInfo->m_strTaxNumber, m_userInfo->m_strUsername, straddcompany);
	//	}
	//}
}

void EntCenterNewWidget::clearUserCompanyInfoTitle()
{
	//ui.labelComName->setText("");
	//ui.labelTaxNo->setText("");
	//ui.labelAddComp->setText("");

	//ui.labeluser->setText("");
	//ui.labelroletype->setText("");
	//ui.labelAddComp->hide();
	//ui.labelline->hide();
	//	ui.labelCopy->hide();
}


void EntCenterNewWidget::showUnaddCompanyInfoTitle(QString _strcompany, QString _strtaxno, QString _strUser, QString _straddcompany)
{

	////ui.labelAvatar->setGeometry(95, 59, 60, 60);
	////ui.labelAvatar->setStyleSheet("background:rgba(216,216,216,1);	border:1px solid rgba(151, 151, 151, 1); ");

	////ui.labelComName->setGeometry(55, 139, 140, 14);
	//ui.labelComName->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;	font-weight:400;color:rgba(51, 51, 51, 1);line-height:21px; \"> %1</span></p></body></html>").arg(_strcompany));

	////ui.labeluser->setGeometry(35, 195, 126, 14);


	//ui.labeluser->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(102, 102, 102, 1);line-height:21px;\"> %1</span></p></body></html>").arg(_strUser));
	////ui.labeluser->setStyleSheet("font-size:14px;font - family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(102, 102, 102, 1);line-height:21px; ");
	//ui.labeluser->show();
	////ui.labelTaxNo->setGeometry(64, 163, 122, 12);



	//ui.labelTaxNo->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:12px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(51, 51, 51, 1);line-height:18px;\"> %1</span></p></body></html>").arg(_strtaxno));
	//ui.labelTaxNo->show();
	//ui.labelAddComp->show();
	//ui.labelroletype->hide();
	//ui.labelline->hide();

	////ui.labelAddComp->setGeometry(161, 195, 56, 14);

	//ui.labelAddComp->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(30, 139, 237, 1);line-height:21px;\"> %1</span></p></body></html>").arg(_straddcompany));

	////ui.labelAddComp->setStyleSheet("font-size:14px;	font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(30, 139, 237, 1);line-height:21px; ");

	////ui.switchButton->setGeometry(75, 229, 100, 38);
	////	ui.switchButton->setStyleSheet("background:linear - gradient(90deg, rgba(2, 164, 253, 1) 0 % , rgba(31, 139, 237, 1) 100 % );box - shadow:0px 3px 8px - 2px rgba(2, 165, 253, 0.85), 0px 6px 11px - 2px rgba(2, 165, 253, 0.64);border - radius:4px; ");


	////ui.copyTaxButton->setGeometry(191, 162, 16, 16);
	//ui.copyTaxButton->setStyleSheet("QPushButton{border-image: url(:/EntCenterWidget/image/copy.png);}\nQPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/copy_sel.png);}");
	//ui.copyTaxButton->show();


	////ui.labelline->show();
	////	ui.labelroletype->setText(QString::fromLocal8Bit("����Ա"));


	////	ui.labelAddComp->setText("");
	////ui.labelAddComp->hide();

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
	////ui.labelAvatar->setStyleSheet("background:rgba(216,216,216,1);	border:1px solid rgba(151, 151, 151, 1); ");

	////ui.labelComName->setGeometry(55, 139, 140, 14);

	//ui.labelComName->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font - family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(51, 51, 51, 1);line-height:21px; \"> %1</span></p></body></html>").arg(_strcompany));


	////ui.labeluser->setGeometry(59, 195, 126, 14);

	//ui.labeluser->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font - family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(51, 51, 51, 1);	line-height:21px; \"> %1</span></p></body></html>").arg(_strUser));

	//ui.labeluser->show();

	////ui.labelTaxNo->setGeometry(64, 163, 122, 12);

	//ui.labelTaxNo->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:12px;font - family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(51, 51, 51, 1);line-height:18px;\"> %1</span></p></body></html>").arg(_strtaxno));

	//ui.labelTaxNo->show();

	//ui.labelAddComp->hide();
	//ui.labelroletype->show();
	//ui.labelline->show();
	////ui.labelroletype->setGeometry(128, 195, 42, 14);

	//ui.labelroletype->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(102, 102, 102, 1);line-height:21px;\"> %1</span></p></body></html>").arg(_straroletype));


	////ui.switchButton->setGeometry(75, 229, 100, 38);
	////	ui.switchButton->setStyleSheet("background:linear - gradient(90deg, rgba(2, 164, 253, 1) 0 % , rgba(31, 139, 237, 1) 100 % );box - shadow:0px 3px 8px - 2px rgba(2, 165, 253, 0.85), 0px 6px 11px - 2px rgba(2, 165, 253, 0.64);border - radius:4px; ");


	////ui.copyTaxButton->setGeometry(191, 162, 16, 16);
	//ui.copyTaxButton->setStyleSheet("QPushButton{border-image: url(:/EntCenterWidget/image/copy.png);}\nQPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/copy_sel.png);}");
	//ui.copyTaxButton->show();










	////ui.labelAddComp->setStyleSheet("font-size:14px;	font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(30, 139, 237, 1);line-height:21px; ");


}

