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



EntCenterNewWidget::EntCenterNewWidget(EntCenterInfo* pEntInfo, UserInfoStruct* userInfo, QWidget *parent)
	:m_pEntInfo(pEntInfo), m_userInfo(userInfo), QWidget(parent)
{
	ui.setupUi(this);
	/*resize(1002, 620);
	setWindowTitle(QString::fromLocal8Bit("企业中心"));*/
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
	m_pFinishEntInfo = NULL;
}



void EntCenterNewWidget::init(EntCenterInfo*	info){
	m_pEntInfo = info;
	mp_EntCenterInfo->init(info);

	mp_EntCenterMain->init(info,m_userInfo);
	
	mp_EntCenterMember->init(info);

}
void EntCenterNewWidget::onShowInfo(){

	JoinEntMoreStep();

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

bool EntCenterNewWidget::winHttpAppealJoinEnt(QString strToken, QString& strRet,QString& strMsg,int& stateCode)
{

	QString strUrl = QString("/ucenter/company/appeal");
	QString strPost = QString("token=%1&company_name=%2&tax=%3&province_id=%4&city_id=%5&area_id=%6&address=%7&legal_person_phone=%8&legal_person_name=%9&office_province_id=%10&office_city_id=%11&office_area_id=%12&office_address=%13&license=%14")
		.arg(strToken).arg(m_pFinishEntInfo->_strCompName).arg(m_pFinishEntInfo->_nProvinceid)
		.arg(m_pFinishEntInfo->_nCityid).arg(m_pFinishEntInfo->_nAreaid).arg(m_pFinishEntInfo->_strRegisterFulladdress)
		.arg(m_pFinishEntInfo->_strlegalbossmobile).arg(m_pFinishEntInfo->_strlegalboss)
		.arg(m_pFinishEntInfo->_nOfficeProvinceid).arg(m_pFinishEntInfo->_nOfficeCityid).arg(m_pFinishEntInfo->_nOfficeAreaid)
		.arg(m_pFinishEntInfo->_strOfficeFulladdress).arg(m_pFinishEntInfo->strLicenseUrl);
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
			strMsg = QString::fromLocal8Bit("系统不存在此用户信息，请确认你的操作");
			break;
		case 20001:
			strMsg = QString::fromLocal8Bit("企业名称不能为空");
			break; 
		case 20002:
				strMsg = QString::fromLocal8Bit("企业名称长度输入不正确（4-50）");
				break;
		case 20003:
			strMsg = QString::fromLocal8Bit("税号不能为空");
			break;
		case 20004:
			strMsg = QString::fromLocal8Bit("税号输入不正确");
			break;
		case 20005:
			strMsg = QString::fromLocal8Bit("税号长度输入不正确（至少15个字符）");
			break;
		case 20006:
			strMsg = QString::fromLocal8Bit("所属区域省份不能为空");
			break;
		case 20007:
			strMsg = QString::fromLocal8Bit("所属区域省份输入不正确，纯数字");
			break;
		case 20008:
			strMsg = QString::fromLocal8Bit("所属区域城市不能为空");
			break;
		case 20009:
			strMsg = QString::fromLocal8Bit("所属区域城市输入不正确，纯数字");
			break;
		case 20010:
			strMsg = QString::fromLocal8Bit("所属区域地区不能为空");
			break;
		case 20011:
			strMsg = QString::fromLocal8Bit("所属区域地区输入不正确 ，纯数字");
			break;
		case 20012:
			strMsg = QString::fromLocal8Bit("企业地址不能为空");
			break;
		case 20013:
			strMsg = QString::fromLocal8Bit("企业地址输入不正确（5-50个字符）");
			break;
		case 20014:
			strMsg = QString::fromLocal8Bit("企业法人不能为空");
			break;
		case 20015:
			strMsg = QString::fromLocal8Bit("企业法人输入不正确");
			break;
		case 20016:
			strMsg = QString::fromLocal8Bit("企业法人电话不能为空");
			break;
		case 20017:
			strMsg = QString::fromLocal8Bit("企业法人电话输入类型不正确");
			break;
		case 20018:
			strMsg = QString::fromLocal8Bit("企业法人电话输入长度不正确（11位数字）");
			break;
		case 20019:
			strMsg = QString::fromLocal8Bit("所属区域不正确");
			break;
		case 20034:
			strMsg = QString::fromLocal8Bit("系统不存在此企业信息，请确认你的操作");
			break;
		case 20035:
			strMsg = QString::fromLocal8Bit("企业信息操作失败");
			break;
		case 20038:
			strMsg = QString::fromLocal8Bit("当前企业已经绑定过管理员了");
		case 20040:
			strMsg = QString::fromLocal8Bit("税控盘类型不能为空");
			break;
		case 20041:
			strMsg = QString::fromLocal8Bit("税控盘类型不正确");
			break;
		case 20042:
			strMsg = QString::fromLocal8Bit("系统已存在此名称的企业信息");
			break;
		case 20043:
			strMsg = QString::fromLocal8Bit("所属办公区域省份不能为空");
			break;
		case 20044:
			strMsg = QString::fromLocal8Bit("所属办公区域省份输入不正确");
			break;
		case 20045:
			strMsg = QString::fromLocal8Bit("所属办公区域城市不能为空");
			break;
		case 20046:
			strMsg = QString::fromLocal8Bit("所属办公区域城市输入不正确");
			break;
		case 20047:
			strMsg = QString::fromLocal8Bit("所属办公区域地区不能为空");
			break;
		case 20048:
			strMsg = QString::fromLocal8Bit("所属办公区域地区输入不正确");
			break;
		case 20049:
			strMsg = QString::fromLocal8Bit("企业办公地址不能为空");
			break;
		case 20050:
			strMsg = QString::fromLocal8Bit("企业办公地址输入不正确");
			break;
		case 20051:
			strMsg = QString::fromLocal8Bit("所属办公区域不正确");
			break;
			break;
		case 20052:
			strMsg = QString::fromLocal8Bit("请上传您的营业执照");
			break;
		case 40001:
			strMsg = QString::fromLocal8Bit("你已经提交过此信息了，系统正在处理中，请不要重复提交");
			break;
		case 40002:
			strMsg = QString::fromLocal8Bit("当前企业未绑定管理员，无法申诉");
			break;
		default:
			break;
		}




		return false;
	}

	bool jmsg = obj.take("data").toBool();
	if (jmsg)
		strMsg = QString::fromLocal8Bit("更新成功");
	else
		strMsg = QString::fromLocal8Bit("更新失败");
	return jmsg;
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
	//m_strLocalTaxno = "210624197305200017";

	//用代码设置了样式  看起来很奇怪
	QString strtaxno, struserorjoin1, strrole, strjoinaction;
	//未查询到企业名字
	if (m_userInfo->m_strCompanyName.isEmpty())
	{
		///////游客或者正常用户没有直接对应的企业的显示处理，需要首先查询本地注册表税号，然后去后台数据库取比对。然后取回来显示.
		ui.labelComName->setText(QString::fromLocal8Bit("暂未查询到企业名称"));

		///取出多个注册表，以,分割，然后传到后台
		m_strLocalTaxno = ZcloudComFun::getTaxnumbers(); 

		/////注册表查询不到，临时赋值，用189账号登陆
		m_strLocalTaxno = "210624197305200017,91458732MA5UYRPW7R";
		bret = ZcloudComFun::winHttpQueryCompanyInfoLocalTax(m_strLocalTaxno, m_userInfo->m_strToken, m_info);
		//已加入企业
		if (m_info.nIsjoin == 1)
		{
			////正常用户的对应公司名未空情况下说明没有加入企业，所以一般不会返回有加入的企业，所以这样情况也不会发生。
			showaddCompanyInfoTitle(m_info.strCompany, m_userInfo->m_strTaxNumber, m_userInfo->m_strUsername, m_info.strRoletype);
		}
		else
		{
			////正常用户（18980084535）登陆后没有对应公司，然后返回本地多个税号查询到的用户关联的企业列表中匹配的第一个企业税号及相关信息，并显示
			////加入信息要显示  您还没加入该企业 立即加入，
			/////也包括游客登陆

			struserorjoin1 = QString::fromLocal8Bit("您还没加入该企业，");
			strjoinaction = QString::fromLocal8Bit("立即加入，");
			showUnaddCompanyInfoTitle(m_info.strCompany, m_info.strTaxno, struserorjoin1, strjoinaction);

		}

	}
	else  /////正常用户有当前关联企业情况下显示
	{
		bret = ZcloudComFun::winHttpQueryCompanyInfoLocalTax(m_userInfo->m_strTaxNumber, m_userInfo->m_strToken, m_info);
		//已加入企业
		if (m_info.nIsjoin == 1)
		{
			showaddCompanyInfoTitle(m_info.strCompany, m_userInfo->m_strTaxNumber, m_userInfo->m_strUsername, m_info.strRoletype);

			////隐藏加入按钮
			//ui.labeJoin1->hide();
			//ui.labelJoin2->hide();	
			////显示人名 职务
			//
			//ui.labeluser->show();
			//ui.labeluserline->show();
			//ui.labeluserroletype->show();

			//ui.labeluser->setText(m_pEntInfo->_strUsername);
			////if (m_info.nroletype == 1)
			//if (m_pEntInfo->_nrole_type == 1){
			//	ui.labeluserroletype->setText(QString::fromLocal8Bit("管理员"));
			//}
			//else{
			//	ui.labeluserroletype->setText(QString::fromLocal8Bit("财务人员"));
			//}
		}
		else{
			//ui.labeJoin1->show();
			//ui.labelJoin2->show();

			//ui.labeluser->hide();
			//ui.labeluserline->hide();
			//ui.labeluserroletype->hide();

			//struser = QString::fromLocal8Bit("您还没加入该企业，");
			//straddcompany = QString::fromLocal8Bit("立即加入，");
			////用正常用户对应的税号取查用户关联企业列表，一般不会查到没有加入的企业信息情况，这段代码多半不会执行。
			showUnaddCompanyInfoTitle(m_info.strCompany, m_userInfo->m_strTaxNumber, m_userInfo->m_strUsername, strjoinaction);
		}


		//if (m_info.nIsjoin == 1)
		//	showaddCompanyInfoTitle(m_info.strCompany, m_userInfo->m_strTaxNumber, m_userInfo->m_strUsername, strrole);
		//else if (m_info.nIsjoin != 0)
		//{
		//	struser = QString::fromLocal8Bit("您还没加入该企业，");
		//	straddcompany = QString::fromLocal8Bit("立即加入，");
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


	//公司名
	if (m_userInfo->m_strCompanyName.isEmpty() && m_info.strCompany.isEmpty())
	{
		ui.labelComName->setText(QString::fromLocal8Bit("暂未查询到企业名称"));
	}
	else if (!m_info.strCompany.isEmpty())
	{
		ui.labelComName->setText(m_info.strCompany);
	}
	else
	{
		ui.labelComName->setText(m_userInfo->m_strCompanyName);
	}

	//税号
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

	//已经加入企业
	if (m_info.nIsjoin == 1)
	{
		//加入按钮
		ui.labeJoin1->hide();
		ui.labelJoin2->hide();
		//个人信息
		ui.labeluser->show();
		ui.labeluserline->show();
		ui.labeluserroletype->show();




		m_info.nIsjoin = nsjoin;
	}
	else
	{
		//未加入企业

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
	ui.labelJoin2->setText("");
	ui.labeJoin1->setText("");
	ui.labeluser->setText("");
	//ui.labelroletype->setText("");
	ui.labelJoin2->hide();
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
	ui.labeJoin1->setGeometry(35, 195, 126, 18);


	ui.labeJoin1->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(102, 102, 102, 1);line-height:21px;\"> %1</span></p></body></html>").arg(_strUserorjoin1));
	//ui.labeluser->setStyleSheet("font-size:14px;font - family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(102, 102, 102, 1);line-height:21px; ");
	ui.labeJoin1->show();
	ui.labelTaxNo->setGeometry(64, 163, 122, 16);



	ui.labelTaxNo->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:12px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(51, 51, 51, 1);line-height:18px;\"> %1</span></p></body></html>").arg(_strtaxno));
	ui.labelTaxNo->show();
	ui.labelJoin2->show();
	ui.labeluserroletype->hide();
	ui.labeluserline->hide();
	ui.labeluser->hide();

	ui.labelJoin2->setGeometry(161, 195, 56, 18);

	ui.labelJoin2->setText(QString::fromLocal8Bit("<html><head/><body><p><span style=\"font-size:14px;font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(30, 139, 237, 1);line-height:21px;\"> %1</span></p></body></html>").arg(_strjoinaction));

	//ui.labelAddComp->setStyleSheet("font-size:14px;	font-family:SourceHanSansCN - Normal, SourceHanSansCN;font-weight:400;color:rgba(30, 139, 237, 1);line-height:21px; ");

	//ui.switchButton->setGeometry(75, 229, 100, 38);
	

	//ui.copyTaxButton->setGeometry(191, 162, 16, 16);
	ui.copyTaxButton->setStyleSheet("QPushButton{border-image: url(:/EntCenterWidget/image/copy.png);}\nQPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/copy_sel.png);}");
	ui.copyTaxButton->show();


	
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
	ui.labelJoin2->hide();

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
////加入企业，用于正常用户登陆后，无对应企业，或者游客登陆，从注册表中读出税号对应的公司的加入企业操作等等
////正常用户打开企业中心后显示的企业并非对应公司的情况下（可能是从注册表税号中比对的信息），对成员管理，企业资料，我的工单等进行操作时候，
////首先弹出加入企业温馨提示，
void EntCenterNewWidget::JoinEntMoreStep()
{
	if (m_info.nIsjoin == 0)
	{

		int nReturn = ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("温馨提示"), QString::fromLocal8Bit("抱歉，您还没有正式加入\"%1\",您先加入企业后再继续操作！").arg(m_info.strCompany), QString::fromLocal8Bit("立即加入"), QString::fromLocal8Bit("暂不加入"), this);
		if (nReturn == QDialog::Accepted)
		{


			////完善企业资料，绑丁不绑定，都需要完善企业资料
			if (JoinStep2FinishEntinfo())
			{
				////完善企业资料成功
				////点击加入后，首先判断这个企业是否绑定企业管理员，然后完善资料

				
				if (m_info.isbindEnt == false)
				{
					////递交加入企业申请
					if (DoapplyJoinEnt())
					{
						////成功递交加入企业申请
						//ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n财务负责人姓名不正确！"));
					}
					else
					{
						///递交加入企业申请失败
						return;
					}

				}
				else  ////如果绑定企业管理员，完善企业资料后，下一步就点击申诉
				{
					////申诉
					int nReturn1 = ZcloudComFun::openMessageTipDlg_2(ZcloudComFun::EN_OKCANCEL, QString::fromLocal8Bit("温馨提示"), QString::fromLocal8Bit("抱歉，您还没有正式加入\"%1\",您先加入企业后再继续操作！").arg(m_info.strCompany), QString::fromLocal8Bit("申诉"), QString::fromLocal8Bit("取消"), this);
					if (nReturn1 == QDialog::Accepted)
					{

						UploadLicenseDlg updlg(m_userInfo);
						if (updlg.exec() == QDialog::Accepted)
						{
							////成功的完善企业的信息和上传的营业执照都在这个企业数据结构的指针里
							m_pFinishEntInfo->strLicenseUrl = updlg.getLicenseUrl();
							////申诉


						}

					}
					else
					{
						return;
					}
				}

			}
			else   ////返回相当于不加入
			{
				return;
			}

		

	
			//立即加入
			//JoinEntWidget  父类修改为QDialog  使用exec方法才能阻断当前线程
			//if (m_pJoinEntWidget == NULL)
			//	m_pJoinEntWidget = new JoinEntWidget(m_userInfo->m_strUserId, m_userInfo->m_strToken, this);



			////m_pJoinEntWidget->show();
			//m_pJoinEntWidget->exec();

			/////----------------------------加入企业ok



		
			return;
		}
		else
		{
			///ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "TAU009");
			return;
		}
	}
}


////实际操作加入企业
bool EntCenterNewWidget::DoapplyJoinEnt()
{
	QString strRet;
	if (!winHttpJoinEnt(m_userInfo->m_strToken, m_info.strcompanyid, strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("加入企业"), QString::fromLocal8Bit("加入失败"));
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
	int status = obj.take("code").toInt();
	if (0 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("操作成功"), QString::fromLocal8Bit("已成功提交加入申请，\r\n请等待对方管理员审核通过！"));
		return true;
	}
	else if (20034 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n加入申请失败，系统不存在此企业信息，请确认你的操作！"));
	}
	else if (60001 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n加入申请失败，申请的企业不能为空！"));
	}
	else if (60002 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n加入申请失败，申请的企业id类型不正确！"));
	}
	else if (60003 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作提示"), QString::fromLocal8Bit("\r\n加入申请失败，你已提交过此申请了，请等待企业管理员审核！"));
	}
	else if (60004 == status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作提示"), QString::fromLocal8Bit("\r\n加入申请失败，你已经是企业的成员了，请不要重复加入！"));
	}
	else
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("操作失败"), QString::fromLocal8Bit("\r\n加入申请失败，请稍后再试！"));
	}
	return false;
}
////完善企业资料，绑丁不绑定，都需要完善企业资料
bool EntCenterNewWidget::JoinStep2FinishEntinfo()
{
	

	if (m_pEditEntinfo == NULL)
		m_pEditEntinfo = new EditEntInfoWidget(m_userInfo, m_pEntInfo);

	m_pEditEntinfo->show();
	m_pFinishEntInfo = m_pEditEntinfo->getFinishEnterInfo();

	if (m_pFinishEntInfo != NULL)
		return true;
	else
		return false;
}

