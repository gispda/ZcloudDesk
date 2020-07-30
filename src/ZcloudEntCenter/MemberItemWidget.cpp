#include "MemberItemWidget.h"
#include "ZcloudCommon.h"
#include <QMenu>
const QString g_strColor0 = "rgba(95,217,153,1)";
const QString g_strColor1 = "rgba(237,164,60,1)";
const QString g_strColor2 = "rgba(60,148,237,1)";
const QString g_strColor3 = "rgba(217,95,216,1)";
const QString g_strColor4 = "rgba(67,222,224,1)";
const QString g_strColor5 = "rgba(255,120,102,1)";

MemberItemWidget::MemberItemWidget(int nAdmin,int nIndex, QString strUid, QString strUserName, QString strTrueName, QString strJob, QString strMobile, int nRoleType, QWidget *parent)
	: QWidget(parent)
	, m_strUid(strUid)
	, m_strTrueName(strTrueName)
	, m_strJob(strJob)
{
	ui.setupUi(this);

	QString strFirstName;
	if (strTrueName.isEmpty())
	{
		strFirstName = "";
	}
	else
	{
		strFirstName = strTrueName.left(1);
	}

	QString strColor;
	switch (nIndex)
	{
	case 0:
		strColor = g_strColor0;
		break;
	case 1:
		strColor = g_strColor1;
		break;
	case 2:
		strColor = g_strColor2;
		break;
	case 3:
		strColor = g_strColor3;
		break;
	case 4:
		strColor = g_strColor4;
		break;
	case 5:
		strColor = g_strColor5;
		break;
	default:
		break;
	}
	ui.labelFirstName->setStyleSheet(QString::fromLocal8Bit("background:%1;border-radius:20px;font:18px \"΢���ź�\";color:#FDFDFD;").arg(strColor));
	ui.labelFirstName->setText(strFirstName);

	//!����
	if (1 == nRoleType)
	{
		if (strTrueName.length()>2)
		{
			strTrueName = strTrueName.left(2) + "...";
		}
		ui.labelTrueName->setText(strTrueName + QString::fromLocal8Bit("(����Ա)"));
	}
	else
	{
		ZcloudComFun::setElideText(14, ui.labelTrueName, strTrueName);
	}

	//!�˺�
	if (strUserName.isEmpty() || strUserName.contains("wechat_") || strUserName.contains("nick_") || strUserName.contains("user_"))
	{
		strUserName = QString::fromLocal8Bit("����");
	}
	ZcloudComFun::setElideText(14, ui.labelUserName, strUserName);

	//!�ֻ���
	if (strMobile.isEmpty())
	{
		strMobile = QString::fromLocal8Bit("����");
	}
	ui.labelMobile->setText(strMobile);

	//!ְ��
	if (strJob.isEmpty())
	{
		strJob = QString::fromLocal8Bit("����");
	}
	ZcloudComFun::setElideText(14, ui.labelJob, strJob);

	if (nAdmin	==	1)
	{
		m_pMenu = new QMenu();
		m_pActionRemoveMember = new QAction(m_pMenu);
		connect(m_pActionRemoveMember, &QAction::triggered, [this](){
			emit sigRemoveMember(m_strUid);
		});
		m_pActionModifyMember = new QAction(m_pMenu);
		connect(m_pActionModifyMember, &QAction::triggered, [this](){
			emit sigModifyMember(m_strTrueName,m_strJob,m_strUid);
		});
		m_pActionHandOver = new QAction(m_pMenu);
		connect(m_pActionHandOver, &QAction::triggered, [this](){
			emit sigHandOver(m_strUid);
		});
		m_pActionRemoveMember->setText(QString::fromLocal8Bit("�Ƴ���Ա"));
		m_pActionModifyMember->setText(QString::fromLocal8Bit("�༭����"));
		m_pActionHandOver->setText(QString::fromLocal8Bit("�ƽ�����Ա"));

		if (1 != nRoleType)
		{
			m_pMenu->addAction(m_pActionHandOver);
			m_pMenu->addAction(m_pActionRemoveMember);
			m_pMenu->setFixedSize(96, 96);
		}
		else
		{
			m_pMenu->setFixedSize(96, 32);
		}
		m_pMenu->addAction(m_pActionModifyMember);
		m_pMenu->setAttribute(Qt::WA_TranslucentBackground);
		m_pMenu->setStyleSheet(QString::fromLocal8Bit(
			"QMenu{background-color:rgba(255, 255, 255, 1);"//��������
			"border:1px solid rgba(222, 222, 222,1);"//�����˵���Ե
			"font-size:12px 'Microsoft Yahei';"
			"text-align:center;"
			"color:rgb(51, 51, 51);}"
			"QMenu::item{"//������ɫ
			"height:30px;"
			"background-color:rgb(255, 255, 255);"
			"margin:0px 0px;"//���ò˵������߾�
			"padding:1px 20px;}"//���ò˵����������º����ҵ��ڱ߾࣬Ч�����ǲ˵��е���Ŀ�����������˼��
			"QMenu::item:pressed{"
			"background-color:rgb(242,242,242);"//ѡ�е���ʽ
			"font-size: 12px 'Microsoft Yahei';color:rgb(51,51,51);}"//������ɫ
			"QMenu::item:selected{"//�˵����Ч��
			"font-size: 12px 'Microsoft Yahei';color:rgb(51,51,51);"//������ɫ
			"background-color:rgb(242, 242, 242);}"));
		ui.operButton->setMenu(m_pMenu);
	}
	else
	{
		ui.operButton->hide();
	}	
}

MemberItemWidget::~MemberItemWidget()
{
}
