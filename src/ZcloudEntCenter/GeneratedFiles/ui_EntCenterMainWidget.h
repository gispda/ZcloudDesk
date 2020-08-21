/********************************************************************************
** Form generated from reading UI file 'EntCenterMainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTCENTERMAINWIDGET_H
#define UI_ENTCENTERMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EntCenterMainWidget
{
public:
    QWidget *ServiceBaseWidget;
    QLabel *labelPic_3;
    QLabel *labelJob;
    QLabel *labelName_5;
    QLabel *label_17;
    QLabel *labelPhone_2;
    QLabel *label_18;
    QLabel *labelName_2;
    QLabel *label_16;
    QLabel *labelWeChat_2;
    QWidget *ServiceFeeWidget_3;
    QLabel *labelworkers;
    QLabel *label_22;
    QLabel *label;
    QWidget *ServiceFeeWidget;
    QPushButton *ServiceFeeButton;
    QLabel *labelExpired_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *labelFeeTime;
    QLabel *labelFeeTime_4;
    QLabel *label_8;
    QLabel *labelDays;
    QProgressBar *progressBar;
    QLabel *labelNoServerFee_2;
    QLabel *label_2;
    QWidget *widgetNotBinding;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *labelTwoBarCode;

    void setupUi(QWidget *EntCenterMainWidget)
    {
        if (EntCenterMainWidget->objectName().isEmpty())
            EntCenterMainWidget->setObjectName(QStringLiteral("EntCenterMainWidget"));
        EntCenterMainWidget->resize(750, 620);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EntCenterMainWidget->sizePolicy().hasHeightForWidth());
        EntCenterMainWidget->setSizePolicy(sizePolicy);
        EntCenterMainWidget->setMinimumSize(QSize(750, 620));
        EntCenterMainWidget->setMaximumSize(QSize(750, 620));
        EntCenterMainWidget->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(235,235,235,1);\n"
"border-radius:10px;"));
        ServiceBaseWidget = new QWidget(EntCenterMainWidget);
        ServiceBaseWidget->setObjectName(QStringLiteral("ServiceBaseWidget"));
        ServiceBaseWidget->setGeometry(QRect(15, 50, 330, 150));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ServiceBaseWidget->sizePolicy().hasHeightForWidth());
        ServiceBaseWidget->setSizePolicy(sizePolicy1);
        ServiceBaseWidget->setMinimumSize(QSize(330, 120));
        ServiceBaseWidget->setMaximumSize(QSize(330, 150));
        ServiceBaseWidget->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(235,235,235,1);\n"
"border-radius:10px;"));
        labelPic_3 = new QLabel(ServiceBaseWidget);
        labelPic_3->setObjectName(QStringLiteral("labelPic_3"));
        labelPic_3->setGeometry(QRect(20, 10, 80, 80));
        labelPic_3->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        labelPic_3->setPixmap(QPixmap(QString::fromUtf8(":/EntCenterWidget/image/completeInfo.png")));
        labelPic_3->setAlignment(Qt::AlignCenter);
        labelJob = new QLabel(ServiceBaseWidget);
        labelJob->setObjectName(QStringLiteral("labelJob"));
        labelJob->setGeometry(QRect(20, 110, 80, 16));
        labelJob->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        labelJob->setAlignment(Qt::AlignCenter);
        labelName_5 = new QLabel(ServiceBaseWidget);
        labelName_5->setObjectName(QStringLiteral("labelName_5"));
        labelName_5->setGeometry(QRect(160, 100, 150, 15));
        labelName_5->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        label_17 = new QLabel(ServiceBaseWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(135, 75, 15, 15));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/EntCenterWidget/image/copy_sel.png")));
        label_17->setAlignment(Qt::AlignCenter);
        labelPhone_2 = new QLabel(ServiceBaseWidget);
        labelPhone_2->setObjectName(QStringLiteral("labelPhone_2"));
        labelPhone_2->setGeometry(QRect(160, 50, 150, 15));
        labelPhone_2->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        label_18 = new QLabel(ServiceBaseWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(135, 100, 15, 15));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/EntCenterWidget/image/edit.png")));
        label_18->setAlignment(Qt::AlignCenter);
        labelName_2 = new QLabel(ServiceBaseWidget);
        labelName_2->setObjectName(QStringLiteral("labelName_2"));
        labelName_2->setGeometry(QRect(135, 25, 160, 15));
        labelName_2->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        label_16 = new QLabel(ServiceBaseWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(135, 50, 15, 15));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/EntCenterWidget/image/copy.png")));
        label_16->setAlignment(Qt::AlignCenter);
        labelWeChat_2 = new QLabel(ServiceBaseWidget);
        labelWeChat_2->setObjectName(QStringLiteral("labelWeChat_2"));
        labelWeChat_2->setGeometry(QRect(160, 75, 150, 15));
        labelWeChat_2->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        ServiceFeeWidget_3 = new QWidget(EntCenterMainWidget);
        ServiceFeeWidget_3->setObjectName(QStringLiteral("ServiceFeeWidget_3"));
        ServiceFeeWidget_3->setGeometry(QRect(395, 50, 330, 150));
        sizePolicy1.setHeightForWidth(ServiceFeeWidget_3->sizePolicy().hasHeightForWidth());
        ServiceFeeWidget_3->setSizePolicy(sizePolicy1);
        ServiceFeeWidget_3->setMinimumSize(QSize(330, 120));
        ServiceFeeWidget_3->setMaximumSize(QSize(330, 150));
        ServiceFeeWidget_3->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(235,235,235,1);\n"
"border-radius:10px;"));
        labelworkers = new QLabel(ServiceFeeWidget_3);
        labelworkers->setObjectName(QStringLiteral("labelworkers"));
        labelworkers->setGeometry(QRect(125, 10, 80, 80));
        labelworkers->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        labelworkers->setPixmap(QPixmap(QString::fromUtf8(":/EntCenterWidget/image/completeInfo.png")));
        labelworkers->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(ServiceFeeWidget_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(0, 110, 330, 15));
        label_22->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        label_22->setAlignment(Qt::AlignCenter);
        label = new QLabel(EntCenterMainWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 210, 80, 17));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(80, 17));
        label->setMaximumSize(QSize(80, 17));
        label->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        ServiceFeeWidget = new QWidget(EntCenterMainWidget);
        ServiceFeeWidget->setObjectName(QStringLiteral("ServiceFeeWidget"));
        ServiceFeeWidget->setGeometry(QRect(15, 240, 710, 80));
        sizePolicy1.setHeightForWidth(ServiceFeeWidget->sizePolicy().hasHeightForWidth());
        ServiceFeeWidget->setSizePolicy(sizePolicy1);
        ServiceFeeWidget->setMinimumSize(QSize(710, 80));
        ServiceFeeWidget->setMaximumSize(QSize(710, 80));
        ServiceFeeWidget->setStyleSheet(QLatin1String("QWidget#ServiceFeeWidget{background-color: rgb(252, 252, 252);border:1px solid rgba(235,235,235,1);\n"
"border-radius:10px;}"));
        ServiceFeeButton = new QPushButton(ServiceFeeWidget);
        ServiceFeeButton->setObjectName(QStringLiteral("ServiceFeeButton"));
        ServiceFeeButton->setGeometry(QRect(619, 24, 72, 32));
        sizePolicy1.setHeightForWidth(ServiceFeeButton->sizePolicy().hasHeightForWidth());
        ServiceFeeButton->setSizePolicy(sizePolicy1);
        ServiceFeeButton->setMinimumSize(QSize(72, 32));
        ServiceFeeButton->setMaximumSize(QSize(72, 32));
        ServiceFeeButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        labelExpired_2 = new QLabel(ServiceFeeWidget);
        labelExpired_2->setObjectName(QStringLiteral("labelExpired_2"));
        labelExpired_2->setGeometry(QRect(20, 19, 16, 16));
        sizePolicy1.setHeightForWidth(labelExpired_2->sizePolicy().hasHeightForWidth());
        labelExpired_2->setSizePolicy(sizePolicy1);
        labelExpired_2->setMinimumSize(QSize(16, 16));
        labelExpired_2->setMaximumSize(QSize(16, 16));
        labelExpired_2->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/expired.png);"));
        label_6 = new QLabel(ServiceFeeWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(45, 18, 105, 16));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(97, 16));
        label_6->setMaximumSize(QSize(105, 16));
        label_6->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        label_7 = new QLabel(ServiceFeeWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(150, 22, 1, 10));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(1, 10));
        label_7->setMaximumSize(QSize(1, 10));
        label_7->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        labelFeeTime = new QLabel(ServiceFeeWidget);
        labelFeeTime->setObjectName(QStringLiteral("labelFeeTime"));
        labelFeeTime->setGeometry(QRect(160, 19, 77, 14));
        sizePolicy1.setHeightForWidth(labelFeeTime->sizePolicy().hasHeightForWidth());
        labelFeeTime->setSizePolicy(sizePolicy1);
        labelFeeTime->setMinimumSize(QSize(77, 14));
        labelFeeTime->setMaximumSize(QSize(77, 14));
        labelFeeTime->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        labelFeeTime_4 = new QLabel(ServiceFeeWidget);
        labelFeeTime_4->setObjectName(QStringLiteral("labelFeeTime_4"));
        labelFeeTime_4->setGeometry(QRect(239, 19, 35, 14));
        sizePolicy1.setHeightForWidth(labelFeeTime_4->sizePolicy().hasHeightForWidth());
        labelFeeTime_4->setSizePolicy(sizePolicy1);
        labelFeeTime_4->setMinimumSize(QSize(30, 14));
        labelFeeTime_4->setMaximumSize(QSize(40, 14));
        labelFeeTime_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        label_8 = new QLabel(ServiceFeeWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(275, 22, 1, 10));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(1, 10));
        label_8->setMaximumSize(QSize(1, 10));
        label_8->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        labelDays = new QLabel(ServiceFeeWidget);
        labelDays->setObjectName(QStringLiteral("labelDays"));
        labelDays->setGeometry(QRect(285, 19, 231, 14));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelDays->sizePolicy().hasHeightForWidth());
        labelDays->setSizePolicy(sizePolicy2);
        labelDays->setMinimumSize(QSize(30, 14));
        labelDays->setMaximumSize(QSize(3000, 140));
        labelDays->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        progressBar = new QProgressBar(ServiceFeeWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 51, 574, 10));
        sizePolicy1.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy1);
        progressBar->setMinimumSize(QSize(574, 10));
        progressBar->setMaximumSize(QSize(574, 10));
        progressBar->setStyleSheet(QLatin1String("QProgressBar {border:0px;border-radius:5px; background-color:#ebebeb;}\n"
"QProgressBar::chunk{border:0px;border-radius:5px;background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #02D1FD, stop:1 #419AEF);}\n"
"QProgressBar {border:0px;border-radius:5px;text-align: center;}"));
        progressBar->setMaximum(365);
        progressBar->setValue(90);
        progressBar->setTextVisible(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        labelNoServerFee_2 = new QLabel(ServiceFeeWidget);
        labelNoServerFee_2->setObjectName(QStringLiteral("labelNoServerFee_2"));
        labelNoServerFee_2->setGeometry(QRect(45, 48, 260, 16));
        labelNoServerFee_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        label_2 = new QLabel(EntCenterMainWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 20, 80, 17));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(80, 17));
        label_2->setMaximumSize(QSize(80, 17));
        label_2->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;\n"
"background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        widgetNotBinding = new QWidget(EntCenterMainWidget);
        widgetNotBinding->setObjectName(QStringLiteral("widgetNotBinding"));
        widgetNotBinding->setGeometry(QRect(15, 50, 330, 150));
        label_19 = new QLabel(widgetNotBinding);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(150, 40, 160, 15));
        label_19->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        label_20 = new QLabel(widgetNotBinding);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(150, 90, 160, 15));
        label_20->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        label_21 = new QLabel(widgetNotBinding);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(150, 110, 160, 15));
        label_21->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;"));
        labelTwoBarCode = new QLabel(widgetNotBinding);
        labelTwoBarCode->setObjectName(QStringLiteral("labelTwoBarCode"));
        labelTwoBarCode->setGeometry(QRect(15, 30, 100, 100));
        labelTwoBarCode->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);border:1px solid rgba(252, 252, 252,0);\n"
"border-radius:10px;\n"
""));
        ServiceBaseWidget->raise();
        ServiceFeeWidget_3->raise();
        label->raise();
        ServiceFeeWidget->raise();
        label_2->raise();
        widgetNotBinding->raise();
        labelworkers->raise();
        labelFeeTime_4->raise();

        retranslateUi(EntCenterMainWidget);

        QMetaObject::connectSlotsByName(EntCenterMainWidget);
    } // setupUi

    void retranslateUi(QWidget *EntCenterMainWidget)
    {
        EntCenterMainWidget->setWindowTitle(QApplication::translate("EntCenterMainWidget", "EntCenterWidget", 0));
        labelPic_3->setText(QString());
        labelJob->setText(QString());
        labelName_5->setText(QApplication::translate("EntCenterMainWidget", "990880", 0));
        label_17->setText(QString());
        labelPhone_2->setText(QApplication::translate("EntCenterMainWidget", "18000000000", 0));
        label_18->setText(QString());
        labelName_2->setText(QApplication::translate("EntCenterMainWidget", "\345\274\240\344\270\211", 0));
        label_16->setText(QString());
        labelWeChat_2->setText(QApplication::translate("EntCenterMainWidget", "sadfsarewr", 0));
        labelworkers->setText(QString());
        label_22->setText(QApplication::translate("EntCenterMainWidget", "\346\210\221\347\232\204\345\267\245\345\215\225", 0));
        label->setText(QApplication::translate("EntCenterMainWidget", "\345\237\272\347\241\200\346\234\215\345\212\241", 0));
        ServiceFeeButton->setText(QApplication::translate("EntCenterMainWidget", "\347\273\255\350\264\271", 0));
        labelExpired_2->setText(QString());
        label_6->setText(QApplication::translate("EntCenterMainWidget", "\351\230\262\344\274\252\347\250\216\346\216\247\346\234\215\345\212\241\350\264\271", 0));
        label_7->setText(QString());
        labelFeeTime->setText(QString());
        labelFeeTime_4->setText(QApplication::translate("EntCenterMainWidget", "\345\210\260\346\234\237", 0));
        label_8->setText(QString());
        labelDays->setText(QString());
        labelNoServerFee_2->setText(QApplication::translate("EntCenterMainWidget", "\346\232\202\346\227\266\346\234\252\350\216\267\345\217\226\346\202\250\347\232\204\344\274\201\344\270\232\351\230\262\344\274\252\347\250\216\346\216\247\346\234\215\345\212\241\350\264\271\344\277\241\346\201\257", 0));
        label_2->setText(QApplication::translate("EntCenterMainWidget", "\345\256\242\346\210\267\346\234\215\345\212\241", 0));
        label_19->setText(QApplication::translate("EntCenterMainWidget", "\346\202\250\347\232\204\344\274\201\344\270\232\350\277\230\346\234\252\347\273\221\345\256\232\345\256\242\346\210\267\347\273\217\347\220\206", 0));
        label_20->setText(QApplication::translate("EntCenterMainWidget", "\345\256\242\346\210\267\347\273\217\347\220\206\346\211\253\346\217\217\346\255\244\344\272\214\347\273\264\347\240\201\345\217\257\345\277\253\351\200\237", 0));
        label_21->setText(QApplication::translate("EntCenterMainWidget", "\347\273\221\345\256\232\344\274\201\344\270\232", 0));
        labelTwoBarCode->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EntCenterMainWidget: public Ui_EntCenterMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTCENTERMAINWIDGET_H
