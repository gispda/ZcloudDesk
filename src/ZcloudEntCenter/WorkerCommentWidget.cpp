#include "WorkerCommentWidget.h"
#include "ZcloudCommon.h"

#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QMenu>
#include "QString"
#include "QMessageBox"


const QString g_strColor0 = "rgba(95,217,153,1)";
const QString g_strColor1 = "rgba(237,164,60,1)";
const QString g_strColor2 = "rgba(60,148,237,1)";
const QString g_strColor3 = "rgba(217,95,216,1)";
const QString g_strColor4 = "rgba(67,222,224,1)";
const QString g_strColor5 = "rgba(255,120,102,1)";

WorkerCommentWidget::WorkerCommentWidget(QString strworkerid, QString strToken,QWidget *parent)
	: QWidget(parent)
	, m_strWorkerid(strworkerid)
	, m_strToken(strToken)
{

	ui.setupUi(this);

	QString strFirstName;
	ui.setupUi(this);


	//setAttribute(Qt::WA_DeleteOnClose);
	setObjectName("workerInfo");
	setAttribute(Qt::WA_ShowModal, true);



	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground, false);
	setWindowModality(Qt::WindowModal);
	setStyleSheet("outline: none");

	//setGrade(3);

	connect(ui.buttonGrade1, &QPushButton::clicked, this, &WorkerCommentWidget::push1);
	connect(ui.buttonGrade2, &QPushButton::clicked, this, &WorkerCommentWidget::push2);
	connect(ui.buttonGrade3, &QPushButton::clicked, this, &WorkerCommentWidget::push3);
	connect(ui.buttonGrade4, &QPushButton::clicked, this, &WorkerCommentWidget::push4);
	connect(ui.buttonGrade5, &QPushButton::clicked, this, &WorkerCommentWidget::push5);
	//connect(ui.labestar1, &QLabel::, this, &WorkerCommentWidget::push5);

	

	m_blbstar1 = false;
	m_blbstar2 = false;
	m_blbstar3 = false;
	m_blbstar4 = false;
	m_blbstar5 = false;
	m_blbstar6 = false;


	ui.labestar1->installEventFilter(this);
	ui.labestar2->installEventFilter(this);
	ui.labestar3->installEventFilter(this);
	ui.labestar4->installEventFilter(this);
	ui.labestar5->installEventFilter(this);
	ui.labestar6->installEventFilter(this);
	

	connect(ui.buttonCancel, &QPushButton::clicked, [this](){
		close();
	});


	connect(ui.buttonOK, &QPushButton::clicked, [this](){
		submitComment();
	});

	m_curlevel = 0;

	/*QString strColor;
	if (strOrderState == "待受理"){
		strColor = g_strColor0;
	}
	else if (strOrderState == "受理中"){
		strColor = g_strColor1;
	}
	else if (strOrderState == "已完成"){
		strColor = g_strColor2;
	}
	else{
		strColor = g_strColor3;
	}*/
	//QString str = QString::fromLocal8Bit("border:2px solid %1;\nborder-radius:5px;").arg(strColor);
	//ui.labelStateColor->setStyleSheet(str);
	////ui.labelStateColor->setText(QString::fromLocal8Bit("T"));

	//ui.labelOrderCode->setText(m_strOrderCode);
	//ui.labelOrderName->setText(m_strOrderName);
	//ui.labelState->setText(m_strOrderState);
	//ui.labelCreateTime->setText(m_strCreateTime);
	//ui.labelAction2->setText(m_strAction2);


	//ZcloudComFun::setElideText(14, ui.labelJob, strJob);


}

WorkerCommentWidget::~WorkerCommentWidget()
{
}
void WorkerCommentWidget::push1(){
	cleanWidget();
	setStarlabel(1);
	setStartname(1);
	setGrade(1);

	m_curlevel = 1;

}void WorkerCommentWidget::push2(){
	cleanWidget();
	setStarlabel(2);
	setStartname(2);
	setGrade(2);
	m_curlevel = 2;
}void WorkerCommentWidget::push3(){
	cleanWidget();
	setStarlabel(3);
	setStartname(3);
	setGrade(3);
	m_curlevel = 3;
}void WorkerCommentWidget::push4(){
	cleanWidget();
	setStarlabel(4);
	setStartname(4);
	setGrade(4);
	m_curlevel = 4;
}void WorkerCommentWidget::push5(){
	cleanWidget();
	setStarlabel(5);
	setStartname(5);
	setGrade(5);
	m_curlevel = 5;
}
void WorkerCommentWidget::setStarlabel(int star_level)
{
		QStringList _starlabells = m_starinfo.value(star_level).strStarlabel;

		for (int i = 0; i < _starlabells.size(); i++)
		{
			switch (i)
			{
			case 0:
				ui.labestar1->setText(_starlabells.at(i));
				ui.labestar1->setVisible(true);
				break;
			case 1:
				ui.labestar2->setText(_starlabells.at(i));
				ui.labestar2->setVisible(true);

				break;
			case 2:
				ui.labestar3->setText(_starlabells.at(i));
				ui.labestar3->setVisible(true);

				break;
			case 3:
				ui.labestar4->setText(_starlabells.at(i));
				ui.labestar4->setVisible(true);

				break;
			case 4:
				ui.labestar5->setText(_starlabells.at(i));
				ui.labestar5->setVisible(true);

				break;
			case 5:
				ui.labestar6->setText(_starlabells.at(i));
				ui.labestar6->setVisible(true);

				break;
			default:
				break;
			}
		}
}


void WorkerCommentWidget::setGrade(int pushindex){
	
	if (grades == pushindex){
		grades = grades - 1;
	}
	else{
		grades = pushindex;
	}
	QIcon iconfull(":/EntCenterWidget/image/fafull.png");

	QIcon iconspace(":/EntCenterWidget/image/faspace.png");
	if (grades < 1){
		ui.buttonGrade1->setIcon(iconspace);
	}
	else{
		ui.buttonGrade1->setIcon(iconfull);
	}
	if (grades < 2){
		ui.buttonGrade2->setIcon(iconspace);
	}
	else{
		ui.buttonGrade2->setIcon(iconfull);
	}
	if (grades < 3){
		ui.buttonGrade3->setIcon(iconspace);
	}
	else{
		ui.buttonGrade3->setIcon(iconfull);
	}
	if (grades < 4){
		ui.buttonGrade4->setIcon(iconspace);
	}
	else{
		ui.buttonGrade4->setIcon(iconfull);
	}
	if (grades < 5){
		ui.buttonGrade5->setIcon(iconspace);
	}
	else{
		ui.buttonGrade5->setIcon(iconfull);
	}
	ui.buttonGrade1->repaint();
	ui.buttonGrade2->repaint();
	ui.buttonGrade3->repaint();
	ui.buttonGrade4->repaint();
	ui.buttonGrade5->repaint();
}

void WorkerCommentWidget::mousePressEvent(QMouseEvent *event)
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

void WorkerCommentWidget::mouseMoveEvent(QMouseEvent *event)
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

bool WorkerCommentWidget::winHttpGetStarlabels(QString strcompanyid,QString strToken, QString& strRet)
{


	QString strUrl = QString("/serviceorder/pc-worker/star-level-setup");

	QString strPost;
	
	strPost = QString("token=%1").arg(strToken);
	
	
	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);
}

bool WorkerCommentWidget::onworkerComment(WorkerInfo _sinfo)
{

	m_info = _sinfo;

	QString  strRet;
	
	cleanWidget();

	if (!winHttpGetStarlabels(m_info.strCompanyid, m_strToken, strRet))
	{
		return false;
	}
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
	int status = obj.take("code").toInt();
	if (0 != status)
	{
		return false;
	}

	QJsonValue list = obj.take("data").toArray();
	
	
	if (!list.isArray())
	{
		return false;
	}
	QJsonArray listArray = list.toArray();
	int nSize = listArray.size();

	WorkerStarInfo _info;

	for (int nIndex = 0; nIndex < nSize; ++nIndex)
	{
		QJsonObject dataList = listArray.at(nIndex).toObject();

		_info.iStarlevel = dataList.take("star_level").toInt();
		_info.iStarscore = dataList.take("star_score").toInt();
		_info.strStarname = dataList.take("star_name").toString();


		QJsonValue slist = dataList.take("star_label").toArray();


		if (!slist.isArray())
		{
			return false;
		}
		QJsonArray slistArray = slist.toArray();
		int nsSize = slistArray.size();
		QString strlabel;
		for (int nsIndex = 0; nsIndex < nsSize; ++nsIndex)
		{
			strlabel = slistArray.at(nsIndex).toString();
			_info.strStarlabel << strlabel;
		}
		m_starinfo.insert(_info.iStarlevel, _info);
		_info.strStarlabel.clear();
	}


	this->show();
	cleanWidget();
	return true;
}

void WorkerCommentWidget::fillWidget()
{

}

void WorkerCommentWidget::cleanWidget()
{
	/*ui.labeltest->setText(QString::fromLocal8Bit("afsfdsfsdf十分士大夫"));
	ui.labeltest->setVisible(true);
	ui.labeltest->setVisible(false);*/

	ui.labestar1->setVisible(false);
	ui.labestar2->setVisible(false);
	ui.labestar3->setVisible(false);
	ui.labestar4->setVisible(false);
	ui.labestar5->setVisible(false);
	ui.labestar6->setVisible(false);

	ui.labestar1->setText("");
	ui.labestar2->setText("");
	ui.labestar3->setText("");
	ui.labestar4->setText("");
	ui.labestar5->setText("");
	ui.labestar6->setText("");

	ui.editContent->setText("");
	m_blbstar1 = false;
	m_blbstar2 = false;
	m_blbstar3 = false;
	m_blbstar4 = false;
	m_blbstar5 = false;
	m_blbstar6 = false;
	m_curlevel = 0;
	//ui.buttonstart1->hide();
	//ui.buttonstart1->setText("");
	//ui.buttonOK->hide();
	//ui.buttonOK->setVisible(false);
	//


	//QBrush tb(Qt::transparent); // Transparent brush, solid pattern
	//ui.buttonstart1->setPalette(QPalette(tb, tb, tb, tb, tb, tb, tb, tb, tb)); // Set every color roles to the transparent brush

	//ui.buttonstart1->setStyleSheet("QPushButton { background-color: rgba(10, 0, 0, 0); }");

	//ui.buttonstart1->r
	//ui.btnstarlabel1->hide();
	//ui.btnstarlabel2->hide();
	//ui.btnstarlabel3->hide();
	//ui.btnstarlabel4->hide();
	//ui.btnstarlabel5->hide();
	//ui.btnstarlabel6->hide();
	//ui.btnstarlabel1->repaint();
	//ui.btnstarlabel2->repaint();
	//ui.btnstarlabel3->repaint();
	//ui.btnstarlabel4->repaint();
	//ui.btnstarlabel5->repaint();
	//ui.btnstarlabel6->repaint();
	
}

void WorkerCommentWidget::setStartname(int starlabel)
{
	ui.labellevel->setText(m_starinfo.value(starlabel).strStarname);
	///throw std::logic_error("The method or operation is not implemented.");
}

bool WorkerCommentWidget::eventFilter(QObject * watched, QEvent * event)
{
	if (watched == ui.labestar1 &&
		event->type() == QEvent::MouseButtonPress)
	{
		
	//	QMessageBox::information(NULL, "Title", QStringLiteral("1"), QMessageBox::Cancel);
		if (m_blbstar1 == false)
		{
			this->setLabelclicked(ui.labestar1, true);
			m_blbstar1 = true;
		}
		else
		{
			this->setLabelclicked(ui.labestar1, false);
			m_blbstar1 = false;

		}
	}
	else if (watched == ui.labestar2 &&
		event->type() == QEvent::MouseButtonPress)
	{
	//	QMessageBox::information(NULL, "Title", QStringLiteral("2"), QMessageBox::Cancel);
		if (m_blbstar2 == false)
		{
			this->setLabelclicked(ui.labestar2, true);
			m_blbstar2 = true;
		}
		else
		{
			this->setLabelclicked(ui.labestar2, false);
			m_blbstar2 = false;

		}

	}
	else if (watched == ui.labestar3 &&
		event->type() == QEvent::MouseButtonPress)
	{

		//QMessageBox::information(NULL, "Title", QStringLiteral("3"), QMessageBox::Cancel);
		if (m_blbstar3 == false)
		{
			this->setLabelclicked(ui.labestar3, true);
			m_blbstar3 = true;
		}
		else
		{
			this->setLabelclicked(ui.labestar3, false);
			m_blbstar3 = false;

		}

	}
	else if (watched == ui.labestar4 &&
		event->type() == QEvent::MouseButtonPress)
	{
		//QMessageBox::information(NULL, "Title", QStringLiteral("4"), QMessageBox::Cancel);

		if (m_blbstar4 == false)
		{
			this->setLabelclicked(ui.labestar4, true);
			m_blbstar4 = true;
		}
		else
		{
			this->setLabelclicked(ui.labestar4, false);
			m_blbstar4 = false;

		}

	}
	else if (watched == ui.labestar5 &&
		event->type() == QEvent::MouseButtonPress)
	{
		//QMessageBox::information(NULL, "Title", QStringLiteral("5"), QMessageBox::Cancel);
		if (m_blbstar5 == false)
		{
			this->setLabelclicked(ui.labestar5, true);
			m_blbstar5 = true;
		}
		else
		{
			this->setLabelclicked(ui.labestar5, false);
			m_blbstar5 = false;

		}

	}
	else if (watched == ui.labestar6 &&
		event->type() == QEvent::MouseButtonPress)
	{
	//	QMessageBox::information(NULL, "Title", QStringLiteral("6"), QMessageBox::Cancel);
		if (m_blbstar6 == false)
		{
			this->setLabelclicked(ui.labestar6, true);
			m_blbstar1 = true;
		}
		else
		{
			this->setLabelclicked(ui.labestar6, false);
			m_blbstar6 = false;

		}

	}
	

	
	return QWidget::eventFilter(watched, event);
}

void WorkerCommentWidget::setLabelclicked(QLabel* plabel, bool isclicked)
{
	QString ptext = plabel->text();
	QString pptext;



	int nst = 0, ned = 0;
	if (isclicked)
	pptext= "<font color=\"#00ff00\">" + ptext + "< / font>";
	else
	{
		
		pptext = subString(ptext, ">", "<");
		plabel->setText(pptext);
	}
	plabel->setText(pptext);

}

void WorkerCommentWidget::submitComment()
{
	if (m_curlevel == 0)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("工单评价"), QString::fromLocal8Bit("没有选择填写评价信息"));
		return;
	}



	QString strremark = ui.editContent->toPlainText();
	QString strlevel = QString::number(m_curlevel);
	QString strstar ="";
	if (m_blbstar1)
	{
		if (strstar == "")
		strstar =strstar + subString(ui.labestar1->text(), ">", "<");
		else
		strstar = "," + strstar + subString(ui.labestar1->text(), ">", "<");
	}
	if(m_blbstar2)
	{

		if (strstar == "")
			strstar = strstar + subString(ui.labestar2->text(), ">", "<");
		else
			strstar = strstar + "," + subString(ui.labestar2->text(), ">", "<");

	}
	if (m_blbstar3)
	{
		if (strstar == "")
			strstar = strstar + subString(ui.labestar3->text(), ">", "<");
		else
			strstar = strstar + "," + subString(ui.labestar3->text(), ">", "<");

	}
	if (m_blbstar4)
	{

		if (strstar == "")
			strstar = strstar + subString(ui.labestar4->text(), ">", "<");
		else
			strstar = strstar + ","  + subString(ui.labestar4->text(), ">", "<");

	}
	if (m_blbstar5)
	{
		if (strstar == "")
			strstar = strstar + subString(ui.labestar5->text(), ">", "<");
		else
			strstar = strstar + ","  + subString(ui.labestar5->text(), ">", "<");

	}
	if (m_blbstar6)
	{

		if (strstar == "")
			strstar = strstar + subString(ui.labestar6->text(), ">", "<");
		else
			strstar = strstar + "," + subString(ui.labestar6->text(), ">", "<");

	}
	
	QString strpost = QString("token=%1&worker_id=%2&level=%3&label=%4&remark=%5")
		.arg(m_strToken).arg(m_info.strWorkerid).arg(strlevel).arg(strstar).arg(strremark);

	QString strRet;
	if (!winHttpPostsubmitComment(strpost,m_strToken, strRet))
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("工单评价"), QString::fromLocal8Bit("异常错误"));
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
	QString msg = obj.take("msg").toString();
	if (0 != status)
	{
		ZcloudComFun::openMessageTipDlg(ZcloudComFun::EN_TIP, QString::fromLocal8Bit("工单评价"), msg);
		return;
	}
	this->close();
}



bool WorkerCommentWidget::winHttpPostsubmitComment(QString strPost, QString strToken, QString& strRet)
{


	QString strUrl = QString("/serviceorder/pc-worker/comment");

	


	return ZcloudComFun::httpPost(strUrl, strPost, 5000, strRet, false, 1);
}