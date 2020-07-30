#ifndef DRAWBUTTON_H
#define DRAWBUTTON_H
#include <QWidget>
#include <QPainter>
#include <QToolButton>
#include <QTimer>
#include <QImage>
#include <QMouseEvent>
#include <QVector>
#include <QDebug>
#include "ZhicloudAppDataDefine.h"




class DragButton : public QToolButton
{
    Q_OBJECT
public:
    DragButton(QWidget *parent = 0);

    void setInitialScaling(double scaling);
    void setPixmap(QString pixmap);
	void setPixmap(QPixmap pixmap);
    void setText(QString str);
    void setIsHold(bool flag);
	void settUserData(AppDataInfo	pData);
	AppDataInfo userData();
	APPDOWNLOADETYPE statusAppButton = mapp_INSTALLFINLSH;
	qint64 m_bytesReceived = 0;
	qint64 m_bytesTotal = 0;
	bool m_isUpdate = false;
	bool m_haveMessage = false;
protected:
    int isPress;
    int isHold;

    QTimer *m_aniTimer;
    QTimer *m_holdTimer;
	QTimer *clickTimer;//单击打开  长按拖动定时器
    int m_scaling;			//缩小的 像素
    int m_InitialScaling;	//当前缩放比例
    QPoint m_mouseSrcPos;//最小缩放比例

    QPixmap m_pixmap;
    QString m_text;

	AppDataInfo	m_pData;
	bool	m_bIsDrag;		//!是否拖动
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);//按下
    void mouseReleaseEvent(QMouseEvent *);//释放
    void mouseMoveEvent(QMouseEvent *);//移动
	void mouseDoubleClickEvent ( QMouseEvent * event );

signals:
    void release_signal();
    void drag_signal();//拖动时发出信号
    void dragClicked();
	void dragDoubleClicked();
	//关闭下载的信号
	void closeDownload(QString);
public slots:
    void zoomIn();//放大
    void zoomOut();//缩小
    void hold_slot();
private slots:
	void upDownloadProcess(qint64 bytesReceived, qint64 bytesTotal);
	void upStatusChanged(APPDOWNLOADETYPE appDownloadType);
private:
	void gradientArc(QPainter *painter, int radius, int startAngle, int angleLength, int arcHeight, QColor color, bool isArc = true);
	//QImage cvImageRGB(int red, int green, int blue, QImage imag);

};

#endif // DRAWBUTTON_H
