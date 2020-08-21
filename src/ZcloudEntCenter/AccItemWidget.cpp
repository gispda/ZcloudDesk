#include "AccItemWidget.h"
#include <QFileInfo>
#include <QPainter>

AccItemWidget::AccItemWidget(bool bLogin, stSwitchAccInfo* pAccInfo, QString strFindText, QWidget *parent)
	: QWidget(parent)
	,m_bLogin(bLogin)
	, m_pAccInfo(pAccInfo)
{
	m_strTaxNum = pAccInfo->strTaxNo;
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Widget);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");
	ui.loginedButton->setText(QString::fromLocal8Bit("已登录"));
	if (1 == pAccInfo->nIsjoin){
		ui.switchButton->setText(QString::fromLocal8Bit("切换"));
	}
	else{
		ui.switchButton->setText(QString::fromLocal8Bit("加入"));
	}
	ui.inReviewWidget->hide();
	if (bLogin)
	{
		QRect rect = ui.switchButton->geometry();
		ui.loginedButton->setGeometry(rect);
		ui.switchButton->hide();
	}
	else
	{
		ui.loginedButton->hide();
		ui.switchButton->hide();
	}

	QString strName;
	QString strCompName = pAccInfo->strCompName;
	QString strUserName = pAccInfo->strUserName;
	int     loginByTax  = pAccInfo->bLoginByTax;

	if (strCompName.isEmpty())
	{
		if (1 == loginByTax)
		{
			strCompName = QString::fromLocal8Bit("暂未查询到您的企业");
		}
		else
		{
			strCompName = QString::fromLocal8Bit("您还未加入企业");
		}
	}

	if (strUserName.isEmpty() || strUserName.contains("wechat_") || strUserName.contains("nick_") || strUserName.contains("user_"))
	{
		if (pAccInfo->strMobliePhone.isEmpty())
		{
			strName = QString::fromLocal8Bit("%1").arg(strCompName);
		}
		else
		{
			strName = QString::fromLocal8Bit("%1(%2)").arg(strCompName).arg(pAccInfo->strMobliePhone);
		}
		
	}
	else
	{
		strName = QString::fromLocal8Bit("%1(%2)").arg(strCompName).arg(strUserName);
	}
	setElideText(14, ui.labelName, strName);

	QString strTax = pAccInfo->strTaxNo;
	if (strTax.isEmpty())
	{
		strTax = QString::fromLocal8Bit("——");
	}
	if (!strFindText.isEmpty())
	{
		QString strColorText = QString::fromLocal8Bit("<span style=\"font-size:14px;color:#2299fe;\">%1</span>").arg(strFindText);
		strTax.replace(strFindText, strColorText);
	}
	ui.labelTaxNo->setText(strTax);
	this->m_strComId = m_pAccInfo->strCompId;
	
	QString strAvatarPath = pAccInfo->strLogoPath;
	QFileInfo fileInfo(strAvatarPath);
	if (!fileInfo.isFile())
	{
		strAvatarPath = ":/EntCenterWidget/image/img_tx_d.png";
	}
	QPixmap pixmapa;
	pixmapa.load(strAvatarPath);
	QRect	rectLabel = ui.labelAvatar->geometry();
	QPixmap pixmap(rectLabel.width(), rectLabel.height());
	pixmap.fill(Qt::transparent);
	QPainter painter(&pixmap);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	QPainterPath path;
	path.addEllipse(0, 0, rectLabel.width(), rectLabel.height());
	painter.setClipPath(path);
	painter.drawPixmap(0, 0, rectLabel.width(), rectLabel.height(), pixmapa);
	ui.labelAvatar->setPixmap(pixmap);
	this->installEventFilter(this);
	connect(ui.switchButton , SIGNAL(clicked()), this, SLOT(onSwitchBtnClick()));
}

AccItemWidget::AccItemWidget(QString strComId, QString strTaxNo, QString strComName, QString strLogo, int nState, QWidget *parent /*= 0*/)
	: QWidget(parent)
	, m_bLogin(true)
	, m_pAccInfo(NULL)
	, m_strComId(strComId)
{
	m_strTaxNum = strTaxNo;
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Widget);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setStyleSheet("outline: none");
	ui.loginedButton->setText(QString::fromLocal8Bit("已加入"));
	ui.switchButton->setText(QString::fromLocal8Bit("加入"));

	if (1 == nState)
	{
		QRect rect = ui.switchButton->geometry();
		ui.loginedButton->setGeometry(rect);
		ui.switchButton->hide();
		ui.inReviewWidget->hide();
	}
	else if (0 == nState)
	{
		QRect rect = ui.switchButton->geometry();
		ui.inReviewWidget->setGeometry(rect);
		ui.labelCancel->installEventFilter(this);
		ui.switchButton->hide();
		ui.loginedButton->hide();

	}
	else
	{
		ui.inReviewWidget->hide();
		ui.loginedButton->hide();
		ui.switchButton->show();
	}
	if (strComName.isEmpty())
	{
		ui.labelName->setText(QString::fromLocal8Bit("暂未查询到您的企业"));
	}
	else
	{
		ui.labelName->setText(strComName);
		ui.labelName->adjustSize();
	}
	ui.labelTaxNo->setText(strTaxNo);

	QString strAvatarPath = strLogo;
	QFileInfo fileInfo(strAvatarPath);
	if (!fileInfo.isFile())
	{
		strAvatarPath = ":/EntCenterWidget/image/img_tx_d.png";
	}
	QPixmap pixmapa;
	pixmapa.load(strAvatarPath);
	QRect	rectLabel = ui.labelAvatar->geometry();
	QPixmap pixmap(rectLabel.width(), rectLabel.height());
	pixmap.fill(Qt::transparent);
	QPainter painter(&pixmap);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	QPainterPath path;
	path.addEllipse(0, 0, rectLabel.width(), rectLabel.height());
	painter.setClipPath(path);
	painter.drawPixmap(0, 0, rectLabel.width(), rectLabel.height(), pixmapa);
	ui.labelAvatar->setPixmap(pixmap);

	connect(ui.switchButton, SIGNAL(clicked()), this, SLOT(onJoinEntBtnClick()));
}

AccItemWidget::~AccItemWidget()
{
}

bool AccItemWidget::eventFilter(QObject *target, QEvent *e)
{
	if (target == this)
	{
		if (e->type() == QEvent::Enter) //
		{
			if (!m_bLogin)
			{
				ui.switchButton->show();
			}
		}
		else if (e->type() == QEvent::Leave)
		{
			if (!m_bLogin)
			{
				ui.switchButton->hide();
			}
		}
	}
	else if (target == ui.labelCancel)
	{
		if (e->type() == QEvent::MouseButtonRelease) //
		{
			emit sigCancelReview(m_strComId);
		}
	}
	return QWidget::eventFilter(target, e);
}

void AccItemWidget::setElideText(int nPixSize, QLabel* pLabel, const QString& strText)
{
	QFont font("Microsoft YaHei");
	font.setPixelSize(nPixSize);
	pLabel->setFont(font);
	QFontMetrics fontMetrics(pLabel->font());
	int fontSize = fontMetrics.width(strText);//获取之前设置的字符串的像素大小
	QString strElideText;
	if (fontSize > pLabel->width())
	{
		strElideText = fontMetrics.elidedText(strText, Qt::ElideRight, pLabel->width());//返回一个带有省略号的字符串
	}
	else
	{
		strElideText = strText;
	}
	pLabel->setText(strElideText);
	pLabel->adjustSize();
}

void AccItemWidget::onSwitchBtnClick()
{
	QString strData;
	QString strPwd;
	if (1 == m_pAccInfo->nIsjoin){

		if (1 == m_pAccInfo->bLoginByTax)
		{
			strData = m_pAccInfo->strTaxNo;
			strPwd = m_pAccInfo->strUid;
		}
		else if (0 == m_pAccInfo->bLoginByTax)
		{
			strData = m_pAccInfo->strUserName.isEmpty() ? m_pAccInfo->strMobliePhone : m_pAccInfo->strUserName;
			strPwd = m_pAccInfo->strPwd;
		}
		else if (-1 == m_pAccInfo->bLoginByTax || -2 == m_pAccInfo->bLoginByTax)
		{
			strData = m_pAccInfo->strMobliePhone;
			strPwd = m_pAccInfo->strToken;
		}

		if (!m_pAccInfo->strTaxNo.isEmpty() && (-1 == m_pAccInfo->bLoginByTax || -2 == m_pAccInfo->bLoginByTax))
		{
			emit sigSwitchAcc(1, false, m_pAccInfo->strTaxNo, m_pAccInfo->strUid);
			return;
		}
		emit sigSwitchAcc(m_pAccInfo->bLoginByTax, false, strData, strPwd);
	}
	else{
		//加入企业
		onJoinEntBtnClick();
	}


	
}

void AccItemWidget::onJoinEntBtnClick()
{
	emit sigJoinEnt(m_strTaxNum);
}

void AccItemWidget::setReviewStatue(bool bStatue)
{
	if (bStatue)
	{
		QRect rect = ui.switchButton->geometry();
		ui.inReviewWidget->setGeometry(rect);
		ui.inReviewWidget->show();
		ui.labelCancel->installEventFilter(this);
		ui.switchButton->hide();
		ui.loginedButton->hide();
	}
	else
	{
		ui.inReviewWidget->hide();
		ui.loginedButton->hide();
		ui.switchButton->show();
	}
}
