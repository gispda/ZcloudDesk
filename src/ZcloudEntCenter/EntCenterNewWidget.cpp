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

EntCenterNewWidget::EntCenterNewWidget(QWidget *parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	/*resize(1002, 620);
	setWindowTitle(QString::fromLocal8Bit("企业中心"));*/
	//setWindowFlags(Qt::FramelessWindowHint);
	//setAttribute(Qt::WA_TranslucentBackground, true);
	//setStyleSheet("outline: none");





	mp_EntCenterMember = new EntCenterMemberWidget(ui.EntRightWidget);
	mp_EntCenterInfo = new EntCenterInfoWidget(ui.EntRightWidget);
	mp_EntCenterMain = new EntCenterMainWidget(ui.EntRightWidget);
	mp_EntCenterMember->hide();
	mp_EntCenterInfo->hide();


	//connect(ui.entInfoButton, &QPushButton::clicked, this, &EntCenterNewWidget::onEntInfoBtnClick);
	connect(ui.entInfoButton, SIGNAL(clicked()), this, SLOT(onShowInfo()));
	connect(ui.memberButton, SIGNAL(clicked()), this, SLOT(onShowMember()));
	connect(ui.copyTaxButton, SIGNAL(clicked()), this, SLOT(onCopyBtnClick()));
	connect(ui.switchButton, SIGNAL(clicked()), this, SLOT(onSwitchBtnClick()));


	
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

	mp_EntCenterMain->setUserInfo(m_strUid, m_strToken, m_strTrueName, m_strJob, m_isLoginByTax, m_strMobile, m_strCompId, m_strUserName);
	mp_EntCenterMain->init(info);
	
	mp_EntCenterMember->setUserInfo(m_strUid, m_strToken, m_strTrueName, m_strJob, m_isLoginByTax, m_strMobile, m_strCompId, m_strUserName);
	mp_EntCenterMember->init(info);

}
void EntCenterNewWidget::onShowInfo(){
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

bool EntCenterNewWidget ::eventFilter(QObject *target, QEvent *e)
{
	if (target == ui.copyTaxButton)
	{
		if (e->type() == QEvent::Enter) //
		{
			QString strText = ui.labelCopy->text();
			if (QString::fromLocal8Bit("复制")!=	strText)
			{
				ui.labelCopy->setText(QString::fromLocal8Bit("复制"));
			}
			ui.labelCopy->show();
		}
		else if (e->type() == QEvent::Leave)
		{
			ui.labelCopy->hide();
		}
	}
	else if (target == ui.labelAddComp)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC003");
			if (ZcloudComFun::winHttpSSO(m_strToken, m_strUid))
			{
				if (!this->findChild <JoinEntWidget*>("addEntEnter"))
				{
					JoinEntWidget*	pJoinEntWidget = new JoinEntWidget(m_strUid,m_strToken,this);
					pJoinEntWidget->show();
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
		ui.labelCopy->setText(QString::fromLocal8Bit("复制失败"));
		ui.copyTaxButton->setEnabled(true);
		return;
	}
	QString originalText = clipboard->text();         //获取剪贴板上文本信息  
	clipboard->setText(strTaxNo);
	ui.labelCopy->setText(QString::fromLocal8Bit("已复制"));
	ui.copyTaxButton->setEnabled(true);	
}

void EntCenterNewWidget ::onSwitchBtnClick()
{
	SwitchAccWidget*	pWidget = new SwitchAccWidget(m_strUid,m_strToken,m_strUserName,m_strMobile,m_strCompId,this);
	connect(pWidget, SIGNAL(sigSwitchAcc(int, bool, QString, QString)), this, SIGNAL(sigSwitchAcc(int, bool, QString, QString)));
	pWidget->setAttribute(Qt::WA_DeleteOnClose);
	pWidget->show();
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "BBC010");
}

