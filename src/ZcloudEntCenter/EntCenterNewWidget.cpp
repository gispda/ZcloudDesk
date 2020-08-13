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


EntCenterNewWidget::EntCenterNewWidget(UserInfoStruct _userInfo,QWidget *parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	/*resize(1002, 620);
	setWindowTitle(QString::fromLocal8Bit("企业中心"));*/
	//setWindowFlags(Qt::FramelessWindowHint);
	//setAttribute(Qt::WA_TranslucentBackground, true);
	//setStyleSheet("outline: none");



	m_userInfo = _userInfo;
	m_bjoin = false;
	mp_EntCenterMember = new EntCenterMemberWidget(_userInfo,ui.EntRightWidget);
	mp_EntCenterInfo = new EntCenterInfoWidget(_userInfo,ui.EntRightWidget);
	mp_EntCenterMain = new EntCenterMainWidget(_userInfo,ui.EntRightWidget);
	mp_EntCenterMember->hide();
	mp_EntCenterInfo->hide();

//	m_userInfo = _userInfo;
	//connect(ui.entInfoButton, &QPushButton::clicked, this, &EntCenterNewWidget::onEntInfoBtnClick);
	connect(ui.entInfoButton, SIGNAL(clicked()), this, SLOT(onShowInfo()));
	connect(ui.memberButton, SIGNAL(clicked()), this, SLOT(onShowMember()));
	connect(ui.copyTaxButton, SIGNAL(clicked()), this, SLOT(onCopyBtnClick()));
	connect(ui.switchButton, SIGNAL(clicked()), this, SLOT(onSwitchBtnClick()));

	
	ui.labelAddComp->installEventFilter(this);

	m_strLocalTaxno = ZcloudComFun::getTaxnumber();

	ui.labelline->setGeometry(117, 195, 1, 14);
	
	ui.labelline->hide();

	showUserCompanyInfoTitle();



	pWidget = NULL;

	m_pJoinEntWidget = NULL;
	
}

void EntCenterNewWidget::setUserInfo(QString strUid, QString strToken, QString strTrueName, QString strJob, int isLoginByTax, QString strMobile, QString strCompId, QString strUserName)
{
	m_strUid = strUid;
	m_strToken = strToken;
	m_strTrueName = strTrueName;
	m_strJob = strJob;
	m_isLoginByTax = isLoginByTax;
	m_strMobile = strMobile;
	m_strCompId = strCompId;
	m_strUserName = strUserName;
}

void EntCenterNewWidget::init(EntCenterInfo*	info){
	mp_EntCenterInfo->init(info);
	mp_EntCenterInfo->showEntInfo();

	mp_EntCenterMain->setUserInfo(m_userInfo.m_strUserId, m_userInfo.m_strToken, m_userInfo.m_strTruename, m_userInfo.m_strJob, m_userInfo.m_bLoginByTax, m_userInfo.m_strMobile, m_userInfo.m_strCompanyId, m_userInfo.m_strUsername);
	mp_EntCenterMain->init(info);
	
	mp_EntCenterMember->setUserInfo(m_userInfo.m_strUserId, m_userInfo.m_strToken, m_userInfo.m_strTruename, m_userInfo.m_strJob, m_userInfo.m_bLoginByTax, m_userInfo.m_strMobile, m_userInfo.m_strCompanyId, m_userInfo.m_strUsername);
	mp_EntCenterMember->init(info);

}
void EntCenterNewWidget::onShowInfo(){

	if (m_bjoin == false)
	{

		int nReturn = ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("温馨提示"), QString::fromLocal8Bit("抱歉，您还没有正式加入\"%1\",您先加入企业后再继续操作！").arg(m_strCompany), this);
		if (nReturn == QDialog::Accepted)
		{
			//	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TAU008", "", true);
			//this->hide();
			//emit sigLogout();
			//立即加入
		/*	if (m_pJoinEntWidget == NULL)
				m_pJoinEntWidget = new JoinEntWidget(m_userInfo.m_strUserId, m_userInfo.m_strToken, this);
			m_pJoinEntWidget->show();*/
			QString strRet;
			if (!winHttpJoinEnt(m_userInfo.m_strToken, m_strCompId, strRet))
			{
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("加入企业"), QString::fromLocal8Bit("加入失败"));
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
			if (0 != status)
			{
				/*	switch (status)
					{
					case 20012:
					strMsg = QString::fromLocal8Bit("企业地址不能为空");
					break;
					case 20013:
					strMsg = QString::fromLocal8Bit("企业地址输入不正确");
					break;
					case 20027:
					strMsg = QString::fromLocal8Bit("开户帐号不能为空");
					break;
					case 20028:
					strMsg = QString::fromLocal8Bit("开户帐号输入类型不正确");
					break;
					case 20029:
					strMsg = QString::fromLocal8Bit("开户帐号输入长度不正确");
					break;
					case 20030:
					strMsg = QString::fromLocal8Bit("开户银行不能为空");
					break;
					case 20031:
					strMsg = QString::fromLocal8Bit("开户银行输入类型不正确");
					break;
					case 20032:
					strMsg = QString::fromLocal8Bit("电话不能为空");
					break;
					case 20033:
					strMsg = QString::fromLocal8Bit("电话长度不正确");
					break;
					default:
					break;
					}*/




				return;
			}

			int nmsg = obj.take("data").toInt();

			if (nmsg==1)
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("加入企业"), QString::fromLocal8Bit("加入成功"));
			else
				ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("加入企业"), QString::fromLocal8Bit("加入失败"));
			return;
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
	QString strPost = QString("company_id=%1&token=%2").arg(strComId).arg(m_strToken);
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);
}

bool EntCenterNewWidget ::eventFilter(QObject *target, QEvent *e)
{
	//if (target == ui.copyTaxButton)
	//{
	//	if (e->type() == QEvent::Enter) //
	//	{
	//		QString strText = ui.labelCopy->text();
	//		if (QString::fromLocal8Bit("复制")!=	strText)
	//		{
	//			ui.labelCopy->setText(QString::fromLocal8Bit("复制"));
	//		}
	//		ui.labelCopy->show();
	//	}
	//	else if (e->type() == QEvent::Leave)
	//	{
	//		ui.labelCopy->hide();
	//	}
	//}
	//else 
	if (target == ui.labelAddComp)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC003");
			if (ZcloudComFun::winHttpSSO(m_userInfo.m_strToken, m_userInfo.m_strUserId))
			{

				

				if (!this->findChild <JoinEntWidget*>("addEntEnter"))
				{
					if (m_pJoinEntWidget==NULL)
					m_pJoinEntWidget = new JoinEntWidget(m_userInfo.m_strUserId, m_userInfo.m_strToken, this);
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
	QClipboard *clipboard = QApplication::clipboard();   //获取系统剪贴板指针  
	if (NULL == clipboard)
	{
//		ui.labelCopy->setText(QString::fromLocal8Bit("复制失败"));
	//	ui.copyTaxButton->setEnabled(true);
		return;
	}
	QString originalText = clipboard->text();         //获取剪贴板上文本信息  
	clipboard->setText(strTaxNo);
//	ui.labelCopy->setText(QString::fromLocal8Bit("已复制"));
	ui.copyTaxButton->setEnabled(true);	
}

void EntCenterNewWidget ::onSwitchBtnClick()
{
	if (pWidget == NULL)
	{
		pWidget = new SwitchAccWidget(m_userInfo.m_strUserId, m_userInfo.m_strToken, m_userInfo.m_strUsername, m_userInfo.m_strMobile, m_userInfo.m_strCompanyId, this);
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
   
	QString strServerUserid,strRet;
	bool bret = false;
	bool bisjoin = false;
	int nroletype = -1;
	m_strLocalTaxno = "210624197305200017";

	QString strtaxno, struser, strrole, straddcompany;
	if (m_userInfo.m_strCompanyName.isEmpty())
	{
		m_strCompany = QString::fromLocal8Bit("暂未查询到您的企业");


		if (!m_strLocalTaxno.isEmpty())
		{
			


			bret = ZcloudComFun::winHttpQueryCompanyInfoLocalTax(m_strLocalTaxno, m_userInfo.m_strToken, bisjoin, m_strCompany, nroletype, m_strCompId);
			//ui.labelAddComp->setText("");
			//ui.labelComName->setText(strCompany);
			struser = m_userInfo.m_strUsername;
			//ui.labelCopy->show();
			if (nroletype == 1)
			{
				//ui.labelline->show();
				//ui.labelroletype->setText(QString::fromLocal8Bit("管理员"));
				strrole = QString::fromLocal8Bit("管理员");
			}
			if (bisjoin)
			{			

				ui.labelAddComp->setText("");
				ui.labelAddComp->hide();

				m_bjoin = bisjoin;
			}
			else
			{		
		
				struser = QString::fromLocal8Bit("您还没加入该企业，");
				straddcompany = QString::fromLocal8Bit("立即加入，");


				showUnaddCompanyInfoTitle(m_strCompany, m_strLocalTaxno, struser, straddcompany);
				//ui.labelAddComp->show();

			}
		}
		else
		{
			ui.labelTaxNo->setText("");
			ui.labelAddComp->setText("");
			ui.labelAddComp->hide();
		}
	}
	else
	{


		bret = ZcloudComFun::winHttpQueryCompanyInfoLocalTax(m_userInfo.m_strTaxNumber, m_userInfo.m_strToken, bisjoin, m_strCompany, nroletype, m_strCompId);


		if (bisjoin)
		{

			ui.labelAddComp->setText("");
			ui.labelAddComp->hide();

			m_bjoin = bisjoin;
		}

		if (nroletype == 1)
		{
			//ui.labelline->show();
			//ui.labelroletype->setText(QString::fromLocal8Bit("管理员"));
			strrole = QString::fromLocal8Bit("管理员");
		}
		else
			strrole = QString::fromLocal8Bit("财务人员");

		if (bisjoin)
			showaddCompanyInfoTitle(m_strCompany, m_userInfo.m_strTaxNumber, m_userInfo.m_strUsername, strrole);
		else if (bisjoin == false)
		{
			struser = QString::fromLocal8Bit("您还没加入该企业，");
			straddcompany = QString::fromLocal8Bit("立即加入，");
			showUnaddCompanyInfoTitle(m_strCompany, m_userInfo.m_strTaxNumber, m_userInfo.m_strUsername, straddcompany);
		}
	}
}

void EntCenterNewWidget::clearUserCompanyInfoTitle()
{
	ui.labelComName->setText("");
	ui.labelTaxNo->setText("");
	ui.labelAddComp->setText("");

	ui.labeluser->setText("");
	ui.labelroletype->setText("");
	ui.labelAddComp->hide();
	ui.labelline->hide();
//	ui.labelCopy->hide();
}

void EntCenterNewWidget::showUnaddCompanyInfoTitle(QString _strcompany,QString _strtaxno,QString _strUser,QString _straddcompany)
{

	ui.labelAvatar->setGeometry(95, 59, 60, 60);
	//ui.labelAvatar->setStyleSheet("background:rgba(216,216,216,1);	border:1px solid rgba(151, 151, 151, 1); ");

	ui.labelComName->setGeometry(55, 139, 140, 14);
	ui.labelComName->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;	font-weight:400;color:rgba(51, 51, 51, 1);line-height:21px; \"> %1</span></p></body></html>").arg(_strcompany));

	ui.labeluser->setGeometry(35, 195, 126, 14);
	

	ui.labeluser->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(102, 102, 102, 1);line-height:21px;\"> %1</span></p></body></html>").arg(_strUser));
	//ui.labeluser->setStyleSheet("font-size:14px;font - family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(102, 102, 102, 1);line-height:21px; ");
	
	ui.labelTaxNo->setGeometry(64, 163, 122, 12);

	

	ui.labelTaxNo->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:12px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(51, 51, 51, 1);line-height:18px;\"> %1</span></p></body></html>").arg(_strtaxno));

	ui.labelAddComp->show();
	ui.labelroletype->hide();
	ui.labelline->hide();

	ui.labelAddComp->setGeometry(161, 195, 56, 14);

	ui.labelAddComp->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(30, 139, 237, 1);line-height:21px;\"> %1</span></p></body></html>").arg(_straddcompany));

	//ui.labelAddComp->setStyleSheet("font-size:14px;	font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(30, 139, 237, 1);line-height:21px; ");

	ui.switchButton->setGeometry(75, 229, 100, 38);
//	ui.switchButton->setStyleSheet("background:linear - gradient(90deg, rgba(2, 164, 253, 1) 0 % , rgba(31, 139, 237, 1) 100 % );box - shadow:0px 3px 8px - 2px rgba(2, 165, 253, 0.85), 0px 6px 11px - 2px rgba(2, 165, 253, 0.64);border - radius:4px; ");


	ui.copyTaxButton->setGeometry(191, 162,16, 16);
	ui.copyTaxButton->setStyleSheet("QPushButton{border-image: url(:/EntCenterWidget/image/copy.png);}\nQPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/copy_sel.png);}");


	
	//ui.labelline->show();
//	ui.labelroletype->setText(QString::fromLocal8Bit("管理员"));
	
	
//	ui.labelAddComp->setText("");
	//ui.labelAddComp->hide();
	
}

void EntCenterNewWidget::showUnqueryCompanyInfoTitle()
{

}

void EntCenterNewWidget::showaddCompanyInfoTitle(QString _strcompany, QString _strtaxno, QString _strUser, QString _straroletype)
{





	ui.labelAvatar->setGeometry(95, 59, 60, 60);
	//ui.labelAvatar->setStyleSheet("background:rgba(216,216,216,1);	border:1px solid rgba(151, 151, 151, 1); ");

	ui.labelComName->setGeometry(55, 100, 140, 14);

	ui.labelComName->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\" background:rgba(216,216,216,1);	border:1px solid rgba(151, 151, 151, 1); \"> %1</span></p></body></html>").arg(_strcompany));

	
	ui.labeluser->setGeometry(79, 195, 126, 14);
	
	ui.labeluser->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"background:linear-gradient(180deg,rgba(237,244,255,1) 0%,rgba(250,252,255,1) 100%);border - radius:8px 0px 0px 8px;\"> %1</span></p></body></html>").arg(_strUser));

	ui.labelTaxNo->setGeometry(64, 163, 122, 12);
	
	ui.labelTaxNo->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:12px;font - family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(51, 51, 51, 1);line-height:18px;\"> %1</span></p></body></html>").arg(_strtaxno));



	ui.labelAddComp->hide();
	ui.labelroletype->show();
	ui.labelline->show();
	ui.labelroletype->setGeometry(128, 195, 42, 14);
	
	ui.labelroletype->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(102, 102, 102, 1);line-height:21px;\"> %1</span></p></body></html>").arg(_straroletype));


	ui.switchButton->setGeometry(75, 229, 100, 38);
	//	ui.switchButton->setStyleSheet("background:linear - gradient(90deg, rgba(2, 164, 253, 1) 0 % , rgba(31, 139, 237, 1) 100 % );box - shadow:0px 3px 8px - 2px rgba(2, 165, 253, 0.85), 0px 6px 11px - 2px rgba(2, 165, 253, 0.64);border - radius:4px; ");


	ui.copyTaxButton->setGeometry(191, 162, 16, 16);
	ui.copyTaxButton->setStyleSheet("QPushButton{border-image: url(:/EntCenterWidget/image/copy.png);}\nQPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/copy_sel.png);}");




	


	
	
	
	
	//ui.labelAddComp->setStyleSheet("font-size:14px;	font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(30, 139, 237, 1);line-height:21px; ");


}

