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
	QTimer *clickTimer;//������  �����϶���ʱ��
    int m_scaling;			//��С�� ����
    int m_InitialScaling;	//��ǰ���ű���
    QPoint m_mouseSrcPos;//��С���ű���

    QPixmap m_pixmap;
    QString m_text;

	AppDataInfo	m_pData;
	bool	m_bIsDrag;		//!�Ƿ��϶�
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);//����
    void mouseReleaseEvent(QMouseEvent *);//�ͷ�
    void mouseMoveEvent(QMouseEvent *);//�ƶ�
	void mouseDoubleClickEvent ( QMouseEvent * event );

signals:
    void release_signal();
    void drag_signal();//�϶�ʱ�����ź�
    void dragClicked();
	void dragDoubleClicked();
	//�ر����ص��ź�
	void closeDownload(QString);
public slots:
    void zoomIn();//�Ŵ�
    void zoomOut();//��С
    void hold_slot();
private slots:
	void upDownloadProcess(qint64 bytesReceived, qint64 bytesTotal);
	void upStatusChanged(APPDOWNLOADETYPE appDownloadType);
private:
	void gradientArc(QPainter *painter, int radius, int startAngle, int angleLength, int arcHeight, QColor color, bool isArc = true);
	//QImage cvImageRGB(int red, int green, int blue, QImage imag);

};

#endif // DRAWBUTTON_H
