#include "EntAppealDlg.h"
#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileDialog>
#include <QStandardPaths>
#include "ZcloudBigData.h"
#include "ZcloudClient.h"
#include <QGraphicsDropShadowEffect>

EntAppealDlg::EntAppealDlg(stEntInfo* stEntInfo,UserInfoStruct* _userinfo, QWidget *parent)
	: m_stEntInfo(stEntInfo), QDialog(parent)
{

	ui.setupUi(this);
	m_userinfo = _userinfo;
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowTitle(QString::fromLocal8Bit("��ʾ"));
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowModality(Qt::NonModal);
	setStyleSheet("outline: none");

	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);			//��Ӱģ����
	//������Ӱ����
	shadow->setOffset(0, 0);
	//������Ӱ��ɫ
	shadow->setColor(QColor("#666666"));
	//������ӰԲ��
	shadow->setBlurRadius(8);
	//��Ƕ��QWidget������Ӱ
	this->setGraphicsEffect(shadow);


	ui.labelLicense->hide();

	connect(ui.clostPushButton, &QPushButton::clicked, [this](){
		close();
	});

	

	//connect(ui.labelLicense, SIGNAL(clicked()), this, SLOT(onOpenFile()));

	ui.labelLicense->installEventFilter(this);
	connect(ui.labelUpload, SIGNAL(clicked()), this, SLOT(onOpenFile()));
	connect(ui.buttonOK, &QPushButton::clicked, this, &EntAppealDlg::upload);

	m_strUrl = "";

}

EntAppealDlg::~EntAppealDlg()
{
}

bool EntAppealDlg::eventFilter(QObject *target, QEvent *e)
{
	
	if (target == ui.labelLicense)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			onOpenFile();
		}
	}
	return QWidget::eventFilter(target, e);
}

void EntAppealDlg::upload()
{
	if (this->m_strUrl.isEmpty()){
		return;
	}

	QString strRet;
	QString strUrl = QString("/ucenter/user/appeal");
	QString strPost = QString("token=%1&company_name=%2&tax=%3&province_id=%4&city_id=%5&area_id=%6&address=%7&legal_person_phone=%8&legal_person_name=%9&office_province_id=%10&office_city_id=%11&office_area_id=%12&office_address=%13&license=%14")
		.arg(this->m_userinfo->m_strToken).arg(m_stEntInfo->_strCompName).arg(m_stEntInfo->_strTaxNo).arg(m_stEntInfo->m_registerAddress._nProId)
		.arg(m_stEntInfo->m_registerAddress._nCityId).arg(m_stEntInfo->m_registerAddress._nAreaId).arg(m_stEntInfo->m_registerAddress._address)
		.arg(m_stEntInfo->_strOfficeMobile).arg(m_stEntInfo->_strOfficeName).arg(m_stEntInfo->m_officeAddress._nProId)
		.arg(m_stEntInfo->m_officeAddress._nCityId).arg(m_stEntInfo->m_officeAddress._nAreaId).arg(m_stEntInfo->m_officeAddress._address).arg(this->m_strUrl);
	bool rst= ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);
	if (rst){
		QByteArray byte_array = strRet.toUtf8();
		QJsonParseError json_error;
		QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
		if (json_error.error != QJsonParseError::NoError)
		{
			return;
		}
		if (!parse_doucment.isObject())
		{
			return;
		}
		QJsonObject obj = parse_doucment.object();
		int statecode = obj.take("data").toInt();
		if (statecode == 1){
			ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("�����ύ�ɹ�"), QString::fromLocal8Bit("�����������ύ�ɹ������ǻᾡ��Ϊ������\r\n�����ĵȴ�"));
			this->accept();
		}
	}
	
	ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�����ύʧ��"));
		

}

bool EntAppealDlg::onOpenFile()
{
	//QString path = QDir::currentPath();
	QString path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
	QString title = QString::fromLocal8Bit("ѡ��Ӫҵִ��ͼƬ");
	QString filter = QString::fromLocal8Bit("ͼƬ(*.jpg *.png);");
	QString filename = QFileDialog::getOpenFileName(this,title,path,filter);
	if (!filename.isEmpty()){

		QString strRet, stUrl;
		if (ZcloudClient::winHttpUploadImage(filename, m_userinfo->m_strToken, strRet, stUrl))
		{
			m_strUrl = stUrl;
			ZcloudComFun::LoadAvatar(m_strUrl.toStdString(), ui.labelLicense);
			ui.labelLicense->show();
			ui.labelUpload->hide();
			ui.labelTilte->hide();

		}
		else{
			int result = ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_CLOSE, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("Ӫҵִ���ϴ�ʧ��"));

		}

		
	}

	return true;
}


void EntAppealDlg::mousePressEvent(QMouseEvent *event)
{
	if (!isMaximized())
	{
		if (event->button() == Qt::LeftButton)
		{
			dPos = event->globalPos() - pos();
			event->accept();
		}
	}
}

void EntAppealDlg::mouseMoveEvent(QMouseEvent *event)
{
	if (!isMaximized())
	{
		if (event->buttons()&Qt::LeftButton)
		{
			move(event->globalPos() - dPos);
			event->accept();
		}
	}
}