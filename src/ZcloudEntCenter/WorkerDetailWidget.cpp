#include "WorkerDetailWidget.h"
#include "ZcloudCommon.h"
#include <QMenu>

#include "ZcloudCommon.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QModelIndex>
#include "QMessageBox"
#include "QWidget"
#include <QLayout>
#include <QtWidgets/QVBoxLayout>

const QString g_strColor0 = "rgba(95,217,153,1)";
const QString g_strColor1 = "rgba(237,164,60,1)";
const QString g_strColor2 = "rgba(60,148,237,1)";
const QString g_strColor3 = "rgba(217,95,216,1)";
const QString g_strColor4 = "rgba(67,222,224,1)";
const QString g_strColor5 = "rgba(255,120,102,1)";

WorkerDetailWidget::WorkerDetailWidget(QString strworkid, QString strToken, QWidget *parent)
	: QWidget(parent)
	, m_strWorkerid(strworkid)
	, m_strToken(strToken)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, false);
	setWindowModality(Qt::WindowModal);
	setStyleSheet("outline: none");


	m_ItemModel = new QStandardItemModel(this);

	connect(ui.closeButton, &QPushButton::clicked, [this](){
		close();
	});

	connect(ui.buttonOkay, &QPushButton::clicked, [this](){
		close();
	});

	QString strFirstName;

	
	showWorkerDetail();

	blockSize = 3;
	//m_pageWidget = new PageWidget();
	////QVBoxLayout* playout = new QVBoxLayout();
//	this->setLayout(playout);
//	playout->addWidget(m_pageWidget);
	//ZcloudComFun::setElideText(14, ui.labelJob, strJob);


}

WorkerDetailWidget::~WorkerDetailWidget()
{
	delete m_ItemModel;
	//delete m_pageWidget;
}



void WorkerDetailWidget::mousePressEvent(QMouseEvent *event)
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

void WorkerDetailWidget::mouseMoveEvent(QMouseEvent *event)
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

QString WorkerDetailWidget::getStateColorStyle(QString _state)
{
	QString strColor;
	if (_state == "待受理"){
		strColor = g_strColor0;
	}
	else if (_state == "受理中"){
		strColor = g_strColor1;
	}
	else if (_state == "已完成"){
		strColor = g_strColor2;
	}
	else{
		strColor = g_strColor3;
	}
	return QString::fromLocal8Bit("border:2px solid %1;\nborder-radius:5px;").arg(strColor);
}

QString WorkerDetailWidget::getStateColorStyleByTime(QString sttime)
{
	QString strColor;
	if (sttime.isEmpty()){
		strColor = g_strColor0;
	}
	else{
		strColor = g_strColor3;
	}
	return QString::fromLocal8Bit("border:2px solid %1;\nborder-radius:5px;").arg(strColor);
}


void WorkerDetailWidget::showWorkerDetail()
{
	
	//ui.labelStartcolor->setStyleSheet(str);

	//ui.labelStateColor->setText(QString::fromLocal8Bit("T"));

	//ui.labelOrderCode->setText(m_strWorkerid);
	//ui.labelCodeName->setText(m_strWorkertitle);
	//ui.label_7->setText(m_strState);
	//ui.labelTimeCreate->setText(m_strCreateTime);
	if (m_info.strWorkerid.isEmpty())
		return;

	ui.textContent->setText(m_strWokerdesc);

	QString strstyle;
	strstyle = getStateColorStyleByTime(m_subtime);
	ui.labelsubmitcolor->setStyleSheet(strstyle);
	ui.labelTimeCreate->setText(m_subtime);

	strstyle = getStateColorStyleByTime(m_starttime);
	ui.labelStartcolor->setStyleSheet(strstyle);
	ui.labelTimeStart->setText(m_starttime);

	strstyle = getStateColorStyleByTime(m_completetime);
	ui.labelEndcolor->setStyleSheet(strstyle);
	ui.labelTimeEnd->setText(m_completetime);
    
	QList<QString> keyList = m_annexmap.keys();
	QString strfile;
	QString strfileurl;



	QStandardItem *item;
	for (QList<QString>::iterator it = keyList.begin();
		it != keyList.end();
		it++)
	{
		strfile = *it;
		strfileurl = m_annexmap[*it];
		item = new QStandardItem(strfile);
		m_ItemModel->appendRow(item);
		//strList.append(strfileurl);
	}
	ui.listFiles->setModel(m_ItemModel);

	connect(ui.listFiles, SIGNAL(clicked(QModelIndex)), this, SLOT(openannexClick(QModelIndex)));

	this->show();
}



void WorkerDetailWidget::onworkerDetail(QString strworkerid)
{

	QString  strRet;
	if (!winHttpGetWorksDetail(strworkerid, m_strToken, strRet))
	{
		return;
	}
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
	int status = obj.take("code").toInt();
	if (0 != status)
	{
		return;
	}

	QJsonObject data = obj.take("data").toObject();

	QString dtCreateTime;
	//int		nAdmin = data.take("is_admin").toInt();
	m_info.strWorkerid = data.take("worker_id").toString();
	
	m_info.strAcceptid = data.take("accept_id").toString();


	m_info.strCompanyid = data.take("company_id").toString();
	m_info.strUid = data.take("user_id").toString();

	m_info.iLevel = data.take("level").toInt();
	m_info.strWorkertitle = data.take("worker_title").toString();
	m_info.iState = data.take("state").toInt();
	m_info.bIsread = data.take("is_read").toBool();
	m_info.strLeveldesc = data.take("level_desc").toString();
	m_info.strStatedesc = data.take("state_desc").toString();

	dtCreateTime = data.take("create_time").toString();
	m_info._dtCreateTime = QDateTime::fromString(dtCreateTime, "yyyy.MM.dd hh:mm");
	m_strWokerdesc = data.take("worker_desc").toString();



	QJsonObject time_series = obj.take("time_series").toObject();

	m_subtime = obj.take("submit_time").toString();
	m_starttime = obj.take("dealwith_time").toString();
	m_completetime = obj.take("complete_time").toString();
	m_iscomment = obj.take("is_comment").toInt();

	//int		nAuditCount = data.take("audit_count").toInt();

	
	QJsonValue list = data.take("annex");
	if (list.isArray())
	{
	
		QJsonArray listArray = list.toArray();
		int nSize = listArray.size();
		QString strfilename;
		QString strfileurl;
		for (int nIndex = 0; nIndex < nSize; ++nIndex)
		{
		QJsonObject dataList = listArray.at(nIndex).toObject();
		strfilename = dataList.take("filename").toString();
		strfileurl = dataList.take("filepath").toString();
		m_annexmap.insert(strfilename, strfileurl);
		/*info.strWorkerid = dataList.take("worker_id").toString();
		info.strAcceptid = dataList.take("accept_id").toString();
		info.strCompanyid = dataList.take("company_id").toString();
		info.strUid = dataList.take("user_id").toString();*/
		}
    }
	showWorkerDetail();
}

bool WorkerDetailWidget::winHttpGetWorksDetail(QString strWorkerid, QString strToken, QString& strRet)
{
	
	QString strUrl = QString("/serviceorder/pc-worker/info");

	QString strPost = QString("token=%1&worker_id=%2").arg(strToken).arg(strWorkerid);
		//	.arg(strName).arg(strMobile).arg(strAddr).arg(m_addrInfo._nProId).arg(m_addrInfo._nCityId).arg(m_addrInfo._nAreaId);

	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);



}

void WorkerDetailWidget::openannexClick(QModelIndex index)
{
	QString strTemp;
	strTemp = index.data().toString();

	//QMessageBox msg;
	//msg.setText(m_annexmap.value(strTemp));
	//msg.exec();
	ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("工单附件"), m_annexmap.value(strTemp));
}

