#include "QRemoteServiceDlg.h"
#include <QPainter>
#include <QSettings>
#include "AppCommFun.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTimer>
#include <QPushButton>
#include "AppHttpInterface.h"
#include "ZcloudCommon.h"
#include "Database.h"
extern UserInfoStruct app_userInfo;
QRemoteServiceDlg::QRemoteServiceDlg(QString strAppParams, bool bShow, QWidget *parent)
	: AppCommDialog(parent)
	
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none;");
	this->resize(516, 366);
	m_widget->setStyleSheet(QString::fromLocal8Bit("QWidget#AppCommDialogDialog{border-image: url(:/new/imageFile/invoice_bg.png);border-radius:8px;}"));
	QPushButton *closeButton = new QPushButton(m_widget);
	closeButton->setStyleSheet("QPushButton{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_nor.png);}\
								QPushButton:hover{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_hov.png);}\
								QPushButton:pressed{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_hov.png);};");
	closeButton->setGeometry(457, 11, 32, 28);
	connect(closeButton, &QPushButton::clicked, this, &QRemoteServiceDlg::reject);

	QPushButton *invoceInstallButton = new QPushButton(m_widget);
	QPushButton *otherButton = new QPushButton(m_widget);
	QPushButton *vipButton = new QPushButton(m_widget);
	invoceInstallButton->setStyleSheet("QPushButton{border-image: url(:/new/imageFile/kprj.png);}QPushButton:hover{border-image: url(:/new/imageFile/kprj_sel.png);}");
	otherButton->setStyleSheet("QPushButton{border-image: url(:/new/imageFile/pt.png);}QPushButton:hover{border-image: url(:/new/imageFile/pt_sel.png);}");
	vipButton->setStyleSheet("QPushButton{border-image: url(:/new/imageFile/vip_app.png);}QPushButton:hover{border-image: url(:/new/imageFile/vip_app_sel.png);}");
	

	if (!bShow	&&	strAppParams.isEmpty())
	{
		invoceInstallButton->setGeometry(140, 70, 220, 120);
		otherButton->setGeometry(140, 210, 220, 120);
		vipButton->hide();
	}
	else
	{
		invoceInstallButton->setGeometry(20, 70, 220, 120);
		otherButton->setGeometry(20, 210, 220, 120);
		vipButton->setGeometry(260, 70, 220, 260);
	}
	connect(invoceInstallButton, SIGNAL(clicked()), this, SLOT(onInvoceBtnClick()));
	connect(otherButton, SIGNAL(clicked()), this, SLOT(onOtherBtnClick()));
	connect(vipButton, SIGNAL(clicked()), this, SLOT(onVipBtnClick()));
}

QRemoteServiceDlg::~QRemoteServiceDlg()
{

}

void QRemoteServiceDlg::onInvoceBtnClick()
{
	IVO = 0;
	this->accept();
}

void QRemoteServiceDlg::onOtherBtnClick()
{
	IVO = 1;
	this->accept();
	
}

void QRemoteServiceDlg::onVipBtnClick()
{
	IVO = 2;
	this->accept();
}

int QRemoteServiceDlg::checkVipState(QString strTaxNo)
{
	AppHttpInterface sInter;
	QString strRet;
	if (sInter.WinHttpGetVipInfoByTaxCode(strTaxNo, strRet))
	{
		QByteArray byte_arrayNotice = strRet.toLocal8Bit();
		QJsonParseError json_errorNotice;
		QJsonDocument parse_doucmentNotice = QJsonDocument::fromJson(byte_arrayNotice, &json_errorNotice);
		if (json_errorNotice.error != QJsonParseError::NoError)
			return 0;

		if (!parse_doucmentNotice.isObject())
			return 0;

		QJsonObject objNotice = parse_doucmentNotice.object();
		QString strBackCode = objNotice.take("code").toString();
		QString strDescription = objNotice.take("description").toString();
		QString strBeginTime = objNotice.take("begintime").toString();
		QString strEndTime = objNotice.take("endtime").toString();

		if (strBackCode == "0")
		{
			QDateTime endDateTime = QDateTime::fromString(strEndTime, "yyyy-MM-dd hh:mm:ss");
			if (AppCommFun::getSystemTime() <= endDateTime)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
	}
	return 0;
}
