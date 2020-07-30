#include "AppParticularsDialog.h"
#include <QLabel>
#include <QTextEdit>
#include <QScrollArea>
#include <QScrollBar>
#include <QDir>
#include "RightClassAppWidget.h"
#include "AppCommFun.h"
#include "AppDatabase/AppCenterDatabase.h"
#include "ZhicloudApp.h"
#include "ZcloudCommon.h"
#include "DownloadFile/DownLoadManager.h"
#include "ZhicloudAppDataDefine.h"
#include <QPropertyAnimation> 
#include "ZcloudBigData.h"


extern UserInfoStruct app_userInfo;
//Ӧ������
AppParticularsDialog::AppParticularsDialog(AppDataInfo pData, APPSTATUS APPSTATUSFlag, QWidget *parent /*= nullptr*/)
	:QDialog(parent)
	, m_desktopAppInfo(pData)
{
	setMinimumSize(1000 ,538);
	setMaximumSize(1000, 538);
	//this->move(0,0);
	setWindowModality(Qt::WindowModal);
	//���ô���͸��
	//this->setAttribute(Qt::WA_TranslucentBackground, true);
	//�����ޱ߿�
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setObjectName("AppParticularsDialog");
    this->setStyleSheet(QString::fromLocal8Bit("QDialog#AppParticularsDialog{background-color: rgba(51, 51, 51,0.6);border-bottom-left-radius:8px;border-bottom-right-radius:8px;}"));
	
	
	QWidget *widget = new QWidget();
	widget->setStyleSheet("background-color: rgb(255, 255, 255);");
	////////////////////////////////Ӧ��widget//////////////////////////////////////////
	QWidget *appWidget = new QWidget(this);
	appWidget->setObjectName("appWidget");
	appWidget->setStyleSheet("QWidget#appWidget{background-color: rgb(249, 249, 249);}");
	appWidget->setGeometry(20, 1, 960, 130);
	


	QPushButton * closeButton = new QPushButton(appWidget);
	closeButton->setAttribute(Qt::WA_TranslucentBackground, true);
	closeButton->setStyleSheet(QString::fromLocal8Bit(
		"QPushButton{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_nor.png);}\
		QPushButton:hover{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_hov.png);}\
		QPushButton:pressed{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_hov.png);};\
										"));
	closeButton->setGeometry(918, 7, 32, 28);
	connect(closeButton, &QPushButton::clicked,this, &AppParticularsDialog::clostClickeSlot);
	

	//ͼ��
	QLabel *photoLabel = new QLabel(appWidget);
	photoLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	photoLabel->setGeometry(20, 20, 90, 90);

	QFile *file = new QFile(m_desktopAppInfo.m_strAppIconPath);
	file->open(QIODevice::ReadOnly);
	QPixmap iconpixmap;
	iconpixmap.loadFromData(file->readAll());

	photoLabel->setPixmap(iconpixmap.scaled(90, 90, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	//����
	QLabel *nameLabel = new QLabel(appWidget);
	QString strliasName =  m_desktopAppInfo.m_strAppAlias;
	if (strliasName.isEmpty())
		strliasName = m_desktopAppInfo.m_strAppName;
	nameLabel->setText(AppCommFun::getElidedText(strliasName,20));
	nameLabel->setStyleSheet(QString::fromLocal8Bit("color: #333333;font: 20px \"΢���ź�\";font-weight:bold;"));
	nameLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	nameLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	nameLabel->setGeometry(129, 20, 430, 30);
	//ʱ��
	QLabel *timeLabelTip = new QLabel(QString::fromLocal8Bit("����ʱ�� : ") + m_desktopAppInfo.m_dtAppCreatTimer.toString("yyyy-MM-dd"), appWidget);
	timeLabelTip->setStyleSheet(QString::fromLocal8Bit("color: #666666;font: 14px \"΢���ź�\";"));
	timeLabelTip->setAttribute(Qt::WA_TranslucentBackground, true);
	timeLabelTip->setGeometry(129, 90, 150, 20);
	timeLabelTip->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

	//m_desktopAppInfo.m_intAppSize = "23.2";
	//m_desktopAppInfo.m_strAppCurrentVerson = "222222222";
	//m_desktopAppInfo.m_strAppUpdateSpecification = QString::fromLocal8Bit("���Ǹ���˵����������׶λ�afsdfasdfasd����㷢�����ֶ����ֶ�����˹�ٷҰ�ʱ�򷢷�˳�ṫ˾�Ĺɷ�··�ڸ����뿪�����˾��˽Ⱓ��˾ͷֿ�fasdfasd fasdf asdf asdfasf asdf��ʱ�俨��ʥ���ڷ����ϵļӷ������ɻ����յ��˰���ʱ�����������۰�ʱ��θ�������¥�з��۰�˹�ٻ��ֿ��ӵ��������÷������Ǹ���˵����������׶λ�afsdfasdfasd����㷢�����ֶ����ֶ�����˹�ٷҰ�ʱ�򷢷�˳�ṫ˾�Ĺɷ�··�ڸ����뿪�����˾��˽Ⱓ��˾ͷֿ�fasdfasd fasdf asdf asdfasf asdf��ʱ�俨��ʥ���ڷ����ϵļӷ������ɻ����յ��˰���ʱ�����������۰�ʱ��θ�������¥�з��۰�˹�ٻ��ֿ��ӵ��������÷������Ǹ���˵����������׶λ�afsdfasdfasd����㷢�����ֶ����ֶ�����˹�ٷҰ�ʱ�򷢷�˳�ṫ˾�Ĺɷ�··�ڸ����뿪�����˾��˽Ⱓ��˾ͷֿ�fasdfasd fasdf asdf asdfasf asdf��ʱ�俨��ʥ���ڷ����ϵļӷ������ɻ����յ��˰���ʱ�����������۰�ʱ��θ�������¥�з��۰�˹�ٻ��ֿ��ӵ��������÷������Ǹ���˵����������׶λ�afsdfasdfasd����㷢�����ֶ����ֶ�����˹�ٷҰ�ʱ�򷢷�˳�ṫ˾�Ĺɷ�··�ڸ����뿪�����˾��˽Ⱓ��˾ͷֿ�fasdfasd fasdf asdf asdfasf asdf��ʱ�俨��ʥ���ڷ����ϵļӷ������ɻ����յ��˰���ʱ�����������۰�ʱ��θ�������¥�з��۰�˹�ٻ��ֿ��ӵ��������÷���");
	//m_desktopAppInfo.m_strAppDesc = QString::fromLocal8Bit("���Ǹ���˵����������׶λ�afsdfasdfasd����㷢�����ֶ����ֶ�����˹�ٷҰ�ʱ�򷢷�˳�ṫ˾�Ĺɷ�··�ڸ����뿪�����˾��˽Ⱓ��˾ͷֿ�fasdfasd fasdf asdf asdfasf asdf��ʱ�俨��ʥ���ڷ����ϵļӷ������ɻ����յ��˰���ʱ�����������۰�ʱ��θ�������¥�з��۰�˹�ٻ��ֿ��ӵ��������÷������Ǹ���˵����������׶λ�afsdfasdfasd����㷢�����ֶ����ֶ�����˹�ٷҰ�ʱ�򷢷�˳�ṫ˾�Ĺɷ�··�ڸ����뿪�����˾��˽Ⱓ��˾ͷֿ�fasdfasd fasdf asdf asdfasf asdf��ʱ�俨��ʥ���ڷ����ϵļӷ������ɻ����յ��˰���ʱ�����������۰�ʱ��θ�������¥�з��۰�˹�ٻ��ֿ��ӵ��������÷������Ǹ���˵����������׶λ�afsdfasdfasd����㷢�����ֶ����ֶ�����˹�ٷҰ�ʱ�򷢷�˳�ṫ˾�Ĺɷ�··�ڸ����뿪�����˾��˽Ⱓ��˾ͷֿ�fasdfasd fasdf asdf asdfasf asdf��ʱ�俨��ʥ���ڷ����ϵļӷ������ɻ����յ��˰���ʱ�����������۰�ʱ��θ�������¥�з��۰�˹�ٻ��ֿ��ӵ��������÷������Ǹ���˵����������׶λ�afsdfasdfasd����㷢�����ֶ����ֶ�����˹�ٷҰ�ʱ�򷢷�˳�ṫ˾�Ĺɷ�··�ڸ����뿪�����˾��˽Ⱓ��˾ͷֿ�fasdfasd fasdf asdf asdfasf asdf��ʱ�俨��ʥ���ڷ����ϵļӷ������ɻ����յ��˰���ʱ�����������۰�ʱ��θ�������¥�з��۰�˹�ٻ��ֿ��ӵ��������÷������Ǽ�鷢��㷢ʿ��򰸷���ʱ����������׶�fasd fas daf adsffffffffffffffffffffffffffffffff���ֿ���ʱ�俨��ʥ���ڷ����ϵļӷ������ɻ����յ��˰���ʱ�����������۰�ʱ��θ�������¥�з��۰�˹�ٻ��ֿ��ӵ��������÷���");
	

	//�����С
	if ((!m_desktopAppInfo.m_bAppType && !m_desktopAppInfo.m_strAppDownloadUrl.isEmpty()))
	{
		int appSize = m_desktopAppInfo.m_intAppSize;
		QLabel *sizeLabel = new QLabel(appWidget);
		sizeLabel->setStyleSheet(QString::fromLocal8Bit("color: #666666;font: 14px \"΢���ź�\";"));
		sizeLabel->setAttribute(Qt::WA_TranslucentBackground, true);
		sizeLabel->setGeometry(314, 90, 120, 20);
		sizeLabel->setAlignment(Qt::AlignTop);
		if (m_desktopAppInfo.m_intAppSize)
		{
			QString unit;
			if (appSize < 1024) {
				unit = tr("kB");
			}
			else {
				appSize /= 1024;
				unit = tr("MB");
			}
			sizeLabel->setText(QString::fromLocal8Bit("��С : ") + QString("%1 %2").arg(appSize).arg(unit));
		}
		else
			sizeLabel->setText(QString::fromLocal8Bit("��С : ") + "--");
	}


	//�汾
	if (!m_desktopAppInfo.m_strAppCurrentVerson.isEmpty())
	{

	
		QLabel *versonLabelTip = new QLabel(QString::fromLocal8Bit("�汾 : ") + m_desktopAppInfo.m_strAppCurrentVerson, appWidget);
		versonLabelTip->setStyleSheet(QString::fromLocal8Bit("color: #666666;font: 14px \"΢���ź�\";"));
		versonLabelTip->setAttribute(Qt::WA_TranslucentBackground, true);
		versonLabelTip->setGeometry(380, 90, 200, 20);
		versonLabelTip->setAlignment(Qt::AlignRight);

	
	}
	


	

	//if (!m_desktopAppInfo.m_bAppType  && !m_desktopAppInfo.m_strAppDownloadUrl.isEmpty() && m_desktopAppInfo.m_bAppIsInstall == "1" && !m_desktopAppInfo.m_strAppCurrentVerson.isEmpty())
	//{
	//	QLabel *currentversonLabelTip = new QLabel(QString::fromLocal8Bit("��ǰ�汾 : "), appWidget);
	//	QLabel *currentversonLabel = new QLabel(m_desktopAppInfo.m_strAppCurrentVerson, appWidget);
	//	currentversonLabelTip->setStyleSheet(QString::fromLocal8Bit("color: rgb(102,102,102);font: 14px \"΢���ź�\";"));
	//	currentversonLabelTip->setAttribute(Qt::WA_TranslucentBackground, true);
	//	currentversonLabelTip->setGeometry(10, yHight, 80, 20);
	//	currentversonLabelTip->setAlignment(Qt::AlignRight);
	//	currentversonLabel->setStyleSheet(QString::fromLocal8Bit("color: rgb(51,51,51);font: 14px \"΢���ź�\";"));
	//	currentversonLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	//	currentversonLabel->setGeometry(90, yHight, 100, 20);
	//	currentversonLabel->setAlignment(Qt::AlignLeft);
	//}

	


	//�ʷ�
	QString freeStr;
	QString freePhotStr;
	if (m_desktopAppInfo.m_strAppFree.toFloat() == 0)
	{
		freeStr = QString::fromLocal8Bit("���");
		freePhotStr = ":/new/imageFile/AppCenterPng/NullM.png";
	}
	else
	{
		freeStr = QString::fromLocal8Bit("�շ�");
		freePhotStr = ":/new/imageFile/AppCenterPng/changeM.png";

	}
	//�ʷ�
	QLabel *freePhotoLabel = new QLabel(appWidget);
	freePhotoLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	freePhotoLabel->setGeometry(130, 60, 22, 20);
	freePhotoLabel->setPixmap(QPixmap(freePhotStr).scaled(22, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));

	QLabel *freeLabel = new QLabel(freeStr, appWidget);
	freeLabel->setStyleSheet(QString::fromLocal8Bit("color: #666666; font: 14px \"΢���ź�\";"));
	freeLabel->setAttribute(Qt::WA_TranslucentBackground, true);
	freeLabel->setGeometry(154, 53, 60, 30);
	freeLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

	//��Ա

	QStringList strList = m_desktopAppInfo.m_strListAppVipList;
	if (strList.size() > 0 && strList.at(0) != "0")
	{
		QLabel *vipPhotoLabel = new QLabel(appWidget);
		vipPhotoLabel->setAttribute(Qt::WA_TranslucentBackground, true);
		vipPhotoLabel->setGeometry(197, 60, 22, 20);
		vipPhotoLabel->setPixmap(QPixmap(":/new/imageFile/AppCenterPng/vipManagement").scaled(22, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));

		QLabel *vipLabel = new QLabel(QString::fromLocal8Bit("��Ա����"), appWidget);
		vipLabel->setStyleSheet(QString::fromLocal8Bit("color:  #666666;font: 14px \"΢���ź�\";"));
		vipLabel->setAttribute(Qt::WA_TranslucentBackground, true);
		vipLabel->setGeometry(220, 53, 60, 30);
		vipLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	}

	


	button = new QPushButton(appWidget);
	button->setText(QString::fromLocal8Bit("��װ"));
	button->setGeometry(820, 68, 120, 40);
	connect(button, SIGNAL(clicked()), this, SLOT(clickedStautusButton()));

	QLabel *wLabel = new QLabel(appWidget);
	wLabel->setStyleSheet("background-color: rgb(222, 222, 222);");
	wLabel->setGeometry(0, 129, 960, 1);
	////////////////////////////////////����//////////////////////////////////////
	


	int yHight = 13;

	//���� 228
	QLabel *descLabelTip = new QLabel(QString::fromLocal8Bit("Ӧ�ü��"), widget);
	QString strAppDesc = m_desktopAppInfo.m_strAppDesc;
	strAppDesc = strAppDesc.split(QRegExp("[\r\n]"), QString::SkipEmptyParts).join("");
	QTextEdit *descTextEdit = new QTextEdit(strAppDesc, widget);
	int  descTextEditH = (m_desktopAppInfo.m_strAppDesc.toLocal8Bit().length() / 130) * 20 + 24;
	descLabelTip->setStyleSheet(QString::fromLocal8Bit("color: rgb(51,51,51);font: 16px \"΢���ź�\";font-weight:bold;"));
	descLabelTip->setAttribute(Qt::WA_TranslucentBackground, true);
	descLabelTip->setGeometry(20, yHight, 80, 27);

	yHight += 30;
	descTextEdit->setStyleSheet(QString::fromLocal8Bit("background:transparent;border-width:0;border-style:outset;color: rgb(51,51,51);font: 14px \"΢���ź�\";"));
	descTextEdit->setAttribute(Qt::WA_TranslucentBackground, true);
	descTextEdit->setGeometry(15, yHight, 920, descTextEditH );
	descTextEdit->setAlignment(Qt::AlignLeft);
	descTextEdit->setReadOnly(true);
	descTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	descTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//����˵�� 232
	yHight += (descTextEditH + 30);
	QLabel *upSLabelTip = new QLabel(QString::fromLocal8Bit("����˵��"), widget); 
	QTextEdit *upSTextEdit = new QTextEdit(m_desktopAppInfo.m_strAppUpdateSpecification, widget);
	int upSTextEditH = 20 * (m_desktopAppInfo.m_strAppUpdateSpecification.toLocal8Bit().length() / 130) + 24;
	upSLabelTip->setStyleSheet(QString::fromLocal8Bit("color: rgb(51,51,51);font: 16px \"΢���ź�\";font-weight:bold;"));
	upSLabelTip->setAttribute(Qt::WA_TranslucentBackground, true);
	upSLabelTip->setGeometry(20, yHight, 80, 27);
	yHight += 30;
	upSTextEdit->setStyleSheet(QString::fromLocal8Bit("background:transparent;border-width:0;border-style:outset;color: rgb(51,51,51);font: 14px \"΢���ź�\";"));
	upSTextEdit->setAttribute(Qt::WA_TranslucentBackground, true);
	upSTextEdit->setGeometry(15, yHight , 920, upSTextEditH);
	upSTextEdit->setAlignment(Qt::AlignLeft);
	upSTextEdit->setReadOnly(true);
	upSTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	upSTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	int hSize = upSTextEdit->y() + upSTextEditH + 5;
	if (hSize < 386)
	{
		hSize = 386;
	}
	widget->setMinimumHeight(hSize);
	widget->resize(960, hSize);
	QScrollArea *particularsScrollArea = new QScrollArea(this);
	particularsScrollArea->setStyleSheet("background-color: rgb(255, 255, 255);");
	particularsScrollArea->verticalScrollBar()->setStyleSheet(SCROLLBARSTYESHEET);
	particularsScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	particularsScrollArea->setFrameShape(QFrame::NoFrame);
	particularsScrollArea->setGeometry(20, 131, 960, 386); 
	particularsScrollArea->setWidget(widget);


	statusChanged(APPSTATUSFlag);



	QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "geometry");
	pAnimation->setDuration(400);
	pAnimation->setStartValue(QRect(8, 388, 1000, 538));
	pAnimation->setEndValue(QRect(8, 88, 1000, 538));
	pAnimation->setEasingCurve(QEasingCurve::Linear);  // �������߷��
	pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "APD001",m_desktopAppInfo.m_strAppId );
}

AppParticularsDialog::~AppParticularsDialog()
{

}



void AppParticularsDialog::clostClickeSlot()
{
	ZcloudBigDataInterface::GetInstance()->produceData("M00", "OP001", "APD006", m_desktopAppInfo.m_strAppId);
	this->close();
	AppCenterWidget *ptr = qobject_cast<AppCenterWidget*>(parentWidget());
	if (ptr)
	{
		ptr->changeButtonStatus(m_desktopAppInfo.m_strAppId);
	}
}

//��ť״̬
void AppParticularsDialog::statusChanged(APPSTATUS flag)
{
	m_APPSTATUSFlag = flag;
	switch (m_APPSTATUSFlag)
	{
	case  E_INSTALL:
	{
		button->setText(QString::fromLocal8Bit("��װ"));
		button->setStyleSheet(QString::fromLocal8Bit("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));\
			border-radius:4px;font: 18px \"΢���ź�\";color:rgba(255, 255, 255, 1);}\
			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\
		  border-radius:4px;font: 18px \"΢���ź�\";color:rgba(255, 255, 255, 1);}\
		  " ));
		button->setEnabled(true);
		break;
	}
	case  E_INSTALLDEFEAT:
		break;
	case  E_INSTALLING:
	{
		button->setEnabled(false);
		m_desktopAppInfo.m_bAppIsInstall ? button->setText(QString::fromLocal8Bit("������")) : button->setText(QString::fromLocal8Bit("��װ��"));
		button->setStyleSheet(QString::fromLocal8Bit(
			"QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(128, 209, 254, 1), stop:1 rgba(143, 197, 246, 1));\
			border-radius:4px;font: 18px \"΢���ź�\";color:rgba(255, 255, 255, 1);}\
			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\
			border-radius:4px;font: 18px \"΢���ź�\";color:rgba(255, 255, 255, 1);}\
			"));
		break;
	}
	case  E_UNINSTALL:
	case  E_OPEN:
	case  E_UPDATE:
		button->setText(QString::fromLocal8Bit("��"));
		button->setStyleSheet(QString::fromLocal8Bit(
			"QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 1), stop:1 rgba(244, 244, 244, 1));\
			border: 1px solid #DEDEDE;border-radius:4px;font: 18px \"΢���ź�\";color: #333333;}\
			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 1), stop:1 rgba(251, 251, 251, 1));\
			border: 1px solid #DEDEDE;border-radius:4px;font: 18px \"΢���ź�\";color: #333333;}\
			"));
		button->setEnabled(true);
		break;
	case  E_UNINSTALLDEFEAT:
		break;
	case  E_UNINSTALLING:
		button->setStyleSheet(QString::fromLocal8Bit("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgb(242, 242, 242, 1), stop:1 rgba(235, 235, 235, 1));\
					border-radius:4px;font: 18px \"΢���ź�\";color:rgba(255, 255, 255, 1);}\
						 			"));
		button->setEnabled(false);
		button->setText(QString::fromLocal8Bit("ж����"));
		break;
	
	case  E_UPDATEDEFEAT:
		break;
	case  E_UPDATEING:
		button->setEnabled(false);
		button->setText(QString::fromLocal8Bit("������"));
		button->setStyleSheet(QString::fromLocal8Bit(
			"QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgb(242, 242, 242, 1), stop:1 rgba(235, 235, 235, 1));\
					border-radius:4px;font: 18px \"΢���ź�\";color:rgba(255, 255, 255, 1);}\
											 			"));
		break;

	default:
		break;

	}

}

void AppParticularsDialog::clickedStautusButton()
{
	switch (m_APPSTATUSFlag)
	{
	case  E_INSTALL:
	{
		downloadApp();
		break;
	}
	case  E_INSTALLDEFEAT:
		break;
	case  E_INSTALLING:
	{
		//AppCenterWidget *ptr = RightClassAppWidget::GetInstance()->getAppCenterWidget();
		//if (ptr)
		//	ptr->onInstall(m_desktopAppInfo);
		break;
	}
	case  E_UNINSTALL:
	case  E_UPDATE:
	case  E_OPEN:
	{
		//Ӧ��������û��ж�غ������������ж��˵���Ѱ�װ
		RightClassAppWidget *ptr = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance());
		if (ptr)
			ptr->openApp(m_desktopAppInfo);
		break;
	}
	case  E_UNINSTALLDEFEAT:
		break;
	case  E_UNINSTALLING:
		break;
	case  E_UPDATEDEFEAT:
		break;
	case  E_UPDATEING:
		break;
	default:
		break;

	}
}

void AppParticularsDialog::downloadApp()
{
	RightClassAppWidget *ptr = qobject_cast<RightClassAppWidget*>(RightClassAppWidget::GetInstance()); // �������ֻ����һ��
	if (!ptr) return;
	
	statusChanged(E_INSTALLING);
	QString catid = m_desktopAppInfo.mStrAppCateId;
	QString appId = m_desktopAppInfo.m_strAppId;

	if (!m_desktopAppInfo.m_bAppType && !m_desktopAppInfo.m_strAppDownloadUrl.isEmpty())//cs  Ӧ��
	{
		DownLoadManager*	pDownloadManager = RightClassAppWidget::getDownLoadManager();
		AppDownLoadThread *downloadThread = pDownloadManager->isRightManager(m_desktopAppInfo.m_strAppName, m_desktopAppInfo.m_strAppId);
		if (downloadThread == NULL)
		{
			downloadThread = new AppDownLoadThread(m_desktopAppInfo);
			AppDownLoadItem *appDownLoadItem = new AppDownLoadItem(downloadThread);
			//appDownLoadAppWidget->addDownload(appDownLoadItem);

			disconnect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), this, SLOT(onDownloadStatusChanged(APPDOWNLOADETYPE)));
			connect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), this, SLOT(onDownloadStatusChanged(APPDOWNLOADETYPE)));

		
			AppCenterWidget *appCenterWidget = RightClassAppWidget::GetInstance()->getAppCenterWidget();
			if (appCenterWidget)
				appCenterWidget->addDownloadItem(appDownLoadItem);

			// ��url �л�ȡ�ļ����������Ƕ���Ч;
			QFileInfo fileInfo(QUrl::fromUserInput(m_desktopAppInfo.m_strAppDownloadUrl).path());
			QString appFileName = fileInfo.fileName();
			QString fileName = QApplication::applicationDirPath().append("/downloadApp/");
			QDir fileD(fileName);
			if (!fileD.exists())
				fileD.mkpath(fileName);
			fileName = fileName + appFileName + DOWNLOAD_FILE_SUFFIX;
			pDownloadManager->beginDownload(downloadThread, m_desktopAppInfo, fileName, 0, 0);
			downloadThread->start();
			ptr->flushButton(m_desktopAppInfo.mStrAppCateId, false);
		}
		else
		{
			disconnect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), this, SLOT(onDownloadStatusChanged(APPDOWNLOADETYPE)));
			connect(downloadThread, SIGNAL(signalStatusChanged(APPDOWNLOADETYPE)), this, SLOT(onDownloadStatusChanged(APPDOWNLOADETYPE)));
			if (!downloadThread->isRunning())
			{
				if (downloadThread->m_APPDOWNLOADETYPE != mapp_PAUSE)
				{
					downloadThread->reset();
					downloadThread->start();
				}
				else
					downloadThread->continueDownload();

			}
			ptr->flushButton(m_desktopAppInfo.mStrAppCateId, false);
		}
	}
	else // ��ҳ bs
	{
		m_desktopAppInfo.m_bAppIsInstall = true;
		AppCenterDatabase::instance()->updateApp(m_desktopAppInfo);
		ptr->flushButton(m_desktopAppInfo.mStrAppCateId, false);
		statusChanged(E_OPEN);
	}
}


//�޸�״̬ ����״̬
void AppParticularsDialog::onDownloadStatusChanged(APPDOWNLOADETYPE type)
{
	switch (type)
	{
	case mapp_DOWNLOADING://������
	case mapp_FINISH:		//��װ��
	{
		statusChanged(E_INSTALLING);
		break;
	}
	case mapp_TIMEOUTERROR:
	case mapp_ERROR:
	case mapp_PAUSE:	//��ͣ��
	{
		if (m_desktopAppInfo.m_bAppIsInstall)
			statusChanged(E_OPEN);
		else
			statusChanged(E_INSTALL);
		break;
	}
	case mapp_INSTALLFINLSH://��װ���
	{
		statusChanged(E_OPEN);
		break;
	}
	case mapp_INSTALLERROR://��װ����
	case mapp_CLOSE:
	{
		statusChanged(E_INSTALL);
		break;
	}
	default:
		break;
	}
}
