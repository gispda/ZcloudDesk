/********************************************************************************
** Form generated from reading UI file 'UserCenterAccWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCENTERACCWIDGET_H
#define UI_USERCENTERACCWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserCenterAccWidget
{
public:
    QLabel *labelFirstName;
    QLabel *label;
    QLabel *labelUserName;
    QLabel *label_2;
    QLabel *labelTrueName;
    QLabel *labelJob;
    QLabel *label_3;
    QLabel *labelInfoEdit;
    QLabel *label_4;
    QWidget *widgetPhone;
    QLabel *label_5;
    QLabel *labelPhone;
    QLabel *labelPhoneIcon;
    QLabel *labelPhone1;
    QLabel *label_6;
    QLabel *labelPhone2;
    QWidget *widgetPwd;
    QLabel *label_7;
    QLabel *labelPwd;
    QLabel *labelPwdIcon;
    QLabel *labelPwd1;
    QLabel *label_8;
    QLabel *labelPwd2;
    QWidget *widgetEmail;
    QLabel *label_9;
    QLabel *labelEmail;
    QLabel *labelEmailIcon;
    QLabel *labelEmail1;
    QLabel *label_10;
    QLabel *labelEmail2;
    QWidget *widgetAddr;
    QLabel *label_11;
    QLabel *labelAddr;
    QLabel *labelAddrIcon;
    QLabel *labelAddr1;
    QLabel *label_12;
    QLabel *labelAddr2;

    void setupUi(QWidget *UserCenterAccWidget)
    {
        if (UserCenterAccWidget->objectName().isEmpty())
            UserCenterAccWidget->setObjectName(QStringLiteral("UserCenterAccWidget"));
        UserCenterAccWidget->resize(750, 620);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserCenterAccWidget->sizePolicy().hasHeightForWidth());
        UserCenterAccWidget->setSizePolicy(sizePolicy);
        UserCenterAccWidget->setMinimumSize(QSize(750, 500));
        UserCenterAccWidget->setMaximumSize(QSize(800, 620));
        UserCenterAccWidget->setStyleSheet(QStringLiteral("QWidget#AccSettingWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        labelFirstName = new QLabel(UserCenterAccWidget);
        labelFirstName->setObjectName(QStringLiteral("labelFirstName"));
        labelFirstName->setGeometry(QRect(15, 23, 60, 60));
        sizePolicy.setHeightForWidth(labelFirstName->sizePolicy().hasHeightForWidth());
        labelFirstName->setSizePolicy(sizePolicy);
        labelFirstName->setMinimumSize(QSize(60, 60));
        labelFirstName->setMaximumSize(QSize(60, 60));
        labelFirstName->setStyleSheet(QString::fromUtf8("background:#5FD999;border-radius:30px;font:33px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#FDFDFD;"));
        labelFirstName->setAlignment(Qt::AlignCenter);
        label = new QLabel(UserCenterAccWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(119, 31, 61, 14));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 14));
        label->setMaximumSize(QSize(16777215, 14));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        labelUserName = new QLabel(UserCenterAccWidget);
        labelUserName->setObjectName(QStringLiteral("labelUserName"));
        labelUserName->setGeometry(QRect(190, 31, 321, 15));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelUserName->sizePolicy().hasHeightForWidth());
        labelUserName->setSizePolicy(sizePolicy1);
        labelUserName->setMinimumSize(QSize(140, 15));
        labelUserName->setMaximumSize(QSize(16777215, 15));
        labelUserName->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        label_2 = new QLabel(UserCenterAccWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(119, 59, 35, 14));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(35, 14));
        label_2->setMaximumSize(QSize(16777215, 14));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        labelTrueName = new QLabel(UserCenterAccWidget);
        labelTrueName->setObjectName(QStringLiteral("labelTrueName"));
        labelTrueName->setGeometry(QRect(160, 59, 240, 15));
        sizePolicy.setHeightForWidth(labelTrueName->sizePolicy().hasHeightForWidth());
        labelTrueName->setSizePolicy(sizePolicy);
        labelTrueName->setMinimumSize(QSize(240, 15));
        labelTrueName->setMaximumSize(QSize(240, 15));
        labelTrueName->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        labelJob = new QLabel(UserCenterAccWidget);
        labelJob->setObjectName(QStringLiteral("labelJob"));
        labelJob->setGeometry(QRect(450, 59, 230, 15));
        sizePolicy.setHeightForWidth(labelJob->sizePolicy().hasHeightForWidth());
        labelJob->setSizePolicy(sizePolicy);
        labelJob->setMinimumSize(QSize(230, 15));
        labelJob->setMaximumSize(QSize(230, 15));
        labelJob->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        label_3 = new QLabel(UserCenterAccWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(409, 59, 35, 14));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(35, 14));
        label_3->setMaximumSize(QSize(16777215, 14));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        labelInfoEdit = new QLabel(UserCenterAccWidget);
        labelInfoEdit->setObjectName(QStringLiteral("labelInfoEdit"));
        labelInfoEdit->setGeometry(QRect(705, 46, 30, 14));
        sizePolicy.setHeightForWidth(labelInfoEdit->sizePolicy().hasHeightForWidth());
        labelInfoEdit->setSizePolicy(sizePolicy);
        labelInfoEdit->setMinimumSize(QSize(0, 14));
        labelInfoEdit->setMaximumSize(QSize(16777215, 14));
        labelInfoEdit->setCursor(QCursor(Qt::PointingHandCursor));
        labelInfoEdit->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #1E8BED;\n"
"border-bottom:0px;"));
        label_4 = new QLabel(UserCenterAccWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(5, 103, 740, 1));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(740, 1));
        label_4->setMaximumSize(QSize(740, 1));
        label_4->setStyleSheet(QStringLiteral("border:2px dashed rgba(222,222,222,1);"));
        widgetPhone = new QWidget(UserCenterAccWidget);
        widgetPhone->setObjectName(QStringLiteral("widgetPhone"));
        widgetPhone->setGeometry(QRect(5, 124, 740, 60));
        sizePolicy.setHeightForWidth(widgetPhone->sizePolicy().hasHeightForWidth());
        widgetPhone->setSizePolicy(sizePolicy);
        widgetPhone->setMinimumSize(QSize(740, 60));
        widgetPhone->setMaximumSize(QSize(740, 60));
        widgetPhone->setStyleSheet(QLatin1String("QWidget#widgetPhone{background:rgba(252,252,252,1);\n"
"border:1px solid rgba(235,235,235,1);\n"
"border-radius:4px;}"));
        label_5 = new QLabel(widgetPhone);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(29, 23, 60, 15));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(60, 15));
        label_5->setMaximumSize(QSize(16777215, 15));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        labelPhone = new QLabel(widgetPhone);
        labelPhone->setObjectName(QStringLiteral("labelPhone"));
        labelPhone->setGeometry(QRect(165, 23, 200, 20));
        sizePolicy1.setHeightForWidth(labelPhone->sizePolicy().hasHeightForWidth());
        labelPhone->setSizePolicy(sizePolicy1);
        labelPhone->setMinimumSize(QSize(200, 20));
        labelPhone->setMaximumSize(QSize(16777215, 20));
        labelPhone->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        labelPhoneIcon = new QLabel(widgetPhone);
        labelPhoneIcon->setObjectName(QStringLiteral("labelPhoneIcon"));
        labelPhoneIcon->setGeometry(QRect(600, 23, 16, 16));
        sizePolicy.setHeightForWidth(labelPhoneIcon->sizePolicy().hasHeightForWidth());
        labelPhoneIcon->setSizePolicy(sizePolicy);
        labelPhoneIcon->setMinimumSize(QSize(16, 16));
        labelPhoneIcon->setMaximumSize(QSize(16, 16));
        labelPhoneIcon->setStyleSheet(QStringLiteral(""));
        labelPhone1 = new QLabel(widgetPhone);
        labelPhone1->setObjectName(QStringLiteral("labelPhone1"));
        labelPhone1->setGeometry(QRect(619, 23, 45, 15));
        sizePolicy1.setHeightForWidth(labelPhone1->sizePolicy().hasHeightForWidth());
        labelPhone1->setSizePolicy(sizePolicy1);
        labelPhone1->setMinimumSize(QSize(45, 15));
        labelPhone1->setMaximumSize(QSize(16777215, 15));
        labelPhone1->setStyleSheet(QStringLiteral(""));
        label_6 = new QLabel(widgetPhone);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(671, 24, 1, 12));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(1, 12));
        label_6->setMaximumSize(QSize(1, 12));
        label_6->setStyleSheet(QStringLiteral("border:1px solid rgba(222,222,222,1);"));
        labelPhone2 = new QLabel(widgetPhone);
        labelPhone2->setObjectName(QStringLiteral("labelPhone2"));
        labelPhone2->setGeometry(QRect(681, 23, 30, 15));
        sizePolicy.setHeightForWidth(labelPhone2->sizePolicy().hasHeightForWidth());
        labelPhone2->setSizePolicy(sizePolicy);
        labelPhone2->setMinimumSize(QSize(0, 15));
        labelPhone2->setMaximumSize(QSize(16777215, 15));
        labelPhone2->setCursor(QCursor(Qt::PointingHandCursor));
        labelPhone2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #1E8BED;\n"
"border-bottom:0px;"));
        widgetPwd = new QWidget(UserCenterAccWidget);
        widgetPwd->setObjectName(QStringLiteral("widgetPwd"));
        widgetPwd->setGeometry(QRect(5, 205, 740, 60));
        sizePolicy.setHeightForWidth(widgetPwd->sizePolicy().hasHeightForWidth());
        widgetPwd->setSizePolicy(sizePolicy);
        widgetPwd->setMinimumSize(QSize(740, 60));
        widgetPwd->setMaximumSize(QSize(740, 60));
        widgetPwd->setStyleSheet(QLatin1String("QWidget#widgetPwd{background:rgba(252,252,252,1);\n"
"border:1px solid rgba(235,235,235,1);\n"
"border-radius:4px;}"));
        label_7 = new QLabel(widgetPwd);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(29, 23, 60, 15));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(60, 15));
        label_7->setMaximumSize(QSize(16777215, 15));
        label_7->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        labelPwd = new QLabel(widgetPwd);
        labelPwd->setObjectName(QStringLiteral("labelPwd"));
        labelPwd->setGeometry(QRect(165, 23, 200, 15));
        sizePolicy1.setHeightForWidth(labelPwd->sizePolicy().hasHeightForWidth());
        labelPwd->setSizePolicy(sizePolicy1);
        labelPwd->setMinimumSize(QSize(200, 15));
        labelPwd->setMaximumSize(QSize(16777215, 15));
        labelPwd->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        labelPwdIcon = new QLabel(widgetPwd);
        labelPwdIcon->setObjectName(QStringLiteral("labelPwdIcon"));
        labelPwdIcon->setGeometry(QRect(600, 23, 16, 16));
        sizePolicy.setHeightForWidth(labelPwdIcon->sizePolicy().hasHeightForWidth());
        labelPwdIcon->setSizePolicy(sizePolicy);
        labelPwdIcon->setMinimumSize(QSize(16, 16));
        labelPwdIcon->setMaximumSize(QSize(16, 16));
        labelPwdIcon->setStyleSheet(QStringLiteral(""));
        labelPwd1 = new QLabel(widgetPwd);
        labelPwd1->setObjectName(QStringLiteral("labelPwd1"));
        labelPwd1->setGeometry(QRect(619, 23, 45, 15));
        sizePolicy1.setHeightForWidth(labelPwd1->sizePolicy().hasHeightForWidth());
        labelPwd1->setSizePolicy(sizePolicy1);
        labelPwd1->setMinimumSize(QSize(45, 15));
        labelPwd1->setMaximumSize(QSize(16777215, 15));
        labelPwd1->setStyleSheet(QStringLiteral(""));
        label_8 = new QLabel(widgetPwd);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(671, 24, 1, 12));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(1, 12));
        label_8->setMaximumSize(QSize(1, 12));
        label_8->setStyleSheet(QStringLiteral("border:1px solid rgba(222,222,222,1);"));
        labelPwd2 = new QLabel(widgetPwd);
        labelPwd2->setObjectName(QStringLiteral("labelPwd2"));
        labelPwd2->setGeometry(QRect(681, 23, 30, 15));
        sizePolicy.setHeightForWidth(labelPwd2->sizePolicy().hasHeightForWidth());
        labelPwd2->setSizePolicy(sizePolicy);
        labelPwd2->setMinimumSize(QSize(0, 15));
        labelPwd2->setMaximumSize(QSize(16777215, 15));
        labelPwd2->setCursor(QCursor(Qt::PointingHandCursor));
        labelPwd2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #1E8BED;\n"
"border-bottom:0px;"));
        widgetEmail = new QWidget(UserCenterAccWidget);
        widgetEmail->setObjectName(QStringLiteral("widgetEmail"));
        widgetEmail->setGeometry(QRect(5, 284, 740, 60));
        sizePolicy.setHeightForWidth(widgetEmail->sizePolicy().hasHeightForWidth());
        widgetEmail->setSizePolicy(sizePolicy);
        widgetEmail->setMinimumSize(QSize(740, 60));
        widgetEmail->setMaximumSize(QSize(740, 60));
        widgetEmail->setStyleSheet(QLatin1String("QWidget#widgetEmail{background:rgba(252,252,252,1);\n"
"border:1px solid rgba(235,235,235,1);\n"
"border-radius:4px;}"));
        label_9 = new QLabel(widgetEmail);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(29, 23, 60, 15));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(60, 15));
        label_9->setMaximumSize(QSize(16777215, 15));
        label_9->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        labelEmail = new QLabel(widgetEmail);
        labelEmail->setObjectName(QStringLiteral("labelEmail"));
        labelEmail->setGeometry(QRect(165, 23, 200, 20));
        sizePolicy1.setHeightForWidth(labelEmail->sizePolicy().hasHeightForWidth());
        labelEmail->setSizePolicy(sizePolicy1);
        labelEmail->setMinimumSize(QSize(200, 20));
        labelEmail->setMaximumSize(QSize(16777215, 20));
        labelEmail->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        labelEmailIcon = new QLabel(widgetEmail);
        labelEmailIcon->setObjectName(QStringLiteral("labelEmailIcon"));
        labelEmailIcon->setGeometry(QRect(600, 23, 16, 16));
        sizePolicy.setHeightForWidth(labelEmailIcon->sizePolicy().hasHeightForWidth());
        labelEmailIcon->setSizePolicy(sizePolicy);
        labelEmailIcon->setMinimumSize(QSize(16, 16));
        labelEmailIcon->setMaximumSize(QSize(16, 16));
        labelEmailIcon->setStyleSheet(QStringLiteral(""));
        labelEmail1 = new QLabel(widgetEmail);
        labelEmail1->setObjectName(QStringLiteral("labelEmail1"));
        labelEmail1->setGeometry(QRect(619, 23, 45, 15));
        sizePolicy1.setHeightForWidth(labelEmail1->sizePolicy().hasHeightForWidth());
        labelEmail1->setSizePolicy(sizePolicy1);
        labelEmail1->setMinimumSize(QSize(45, 15));
        labelEmail1->setMaximumSize(QSize(16777215, 15));
        labelEmail1->setStyleSheet(QStringLiteral(""));
        label_10 = new QLabel(widgetEmail);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(671, 24, 1, 12));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(1, 12));
        label_10->setMaximumSize(QSize(1, 12));
        label_10->setStyleSheet(QStringLiteral("border:1px solid rgba(222,222,222,1);"));
        labelEmail2 = new QLabel(widgetEmail);
        labelEmail2->setObjectName(QStringLiteral("labelEmail2"));
        labelEmail2->setGeometry(QRect(681, 23, 30, 15));
        sizePolicy.setHeightForWidth(labelEmail2->sizePolicy().hasHeightForWidth());
        labelEmail2->setSizePolicy(sizePolicy);
        labelEmail2->setMinimumSize(QSize(0, 15));
        labelEmail2->setMaximumSize(QSize(16777215, 15));
        labelEmail2->setCursor(QCursor(Qt::PointingHandCursor));
        labelEmail2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #1E8BED;\n"
"border-bottom:0px;"));
        widgetAddr = new QWidget(UserCenterAccWidget);
        widgetAddr->setObjectName(QStringLiteral("widgetAddr"));
        widgetAddr->setGeometry(QRect(5, 364, 740, 60));
        sizePolicy.setHeightForWidth(widgetAddr->sizePolicy().hasHeightForWidth());
        widgetAddr->setSizePolicy(sizePolicy);
        widgetAddr->setMinimumSize(QSize(740, 60));
        widgetAddr->setMaximumSize(QSize(740, 60));
        widgetAddr->setStyleSheet(QLatin1String("QWidget#widgetAddr{background:rgba(252,252,252,1);\n"
"border:1px solid rgba(235,235,235,1);\n"
"border-radius:4px;}"));
        label_11 = new QLabel(widgetAddr);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(29, 23, 60, 15));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(60, 15));
        label_11->setMaximumSize(QSize(16777215, 15));
        label_11->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        labelAddr = new QLabel(widgetAddr);
        labelAddr->setObjectName(QStringLiteral("labelAddr"));
        labelAddr->setGeometry(QRect(165, 23, 301, 15));
        sizePolicy1.setHeightForWidth(labelAddr->sizePolicy().hasHeightForWidth());
        labelAddr->setSizePolicy(sizePolicy1);
        labelAddr->setMinimumSize(QSize(200, 15));
        labelAddr->setMaximumSize(QSize(16777215, 15));
        labelAddr->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #666666;\n"
"border-bottom:0px;"));
        labelAddrIcon = new QLabel(widgetAddr);
        labelAddrIcon->setObjectName(QStringLiteral("labelAddrIcon"));
        labelAddrIcon->setGeometry(QRect(600, 23, 16, 16));
        sizePolicy.setHeightForWidth(labelAddrIcon->sizePolicy().hasHeightForWidth());
        labelAddrIcon->setSizePolicy(sizePolicy);
        labelAddrIcon->setMinimumSize(QSize(16, 16));
        labelAddrIcon->setMaximumSize(QSize(16, 16));
        labelAddrIcon->setStyleSheet(QStringLiteral(""));
        labelAddr1 = new QLabel(widgetAddr);
        labelAddr1->setObjectName(QStringLiteral("labelAddr1"));
        labelAddr1->setGeometry(QRect(619, 23, 45, 15));
        sizePolicy1.setHeightForWidth(labelAddr1->sizePolicy().hasHeightForWidth());
        labelAddr1->setSizePolicy(sizePolicy1);
        labelAddr1->setMinimumSize(QSize(45, 15));
        labelAddr1->setMaximumSize(QSize(16777215, 15));
        labelAddr1->setStyleSheet(QStringLiteral(""));
        label_12 = new QLabel(widgetAddr);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(671, 24, 1, 12));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMinimumSize(QSize(1, 12));
        label_12->setMaximumSize(QSize(1, 12));
        label_12->setStyleSheet(QStringLiteral("border:1px solid rgba(222,222,222,1);"));
        labelAddr2 = new QLabel(widgetAddr);
        labelAddr2->setObjectName(QStringLiteral("labelAddr2"));
        labelAddr2->setGeometry(QRect(681, 23, 30, 15));
        sizePolicy.setHeightForWidth(labelAddr2->sizePolicy().hasHeightForWidth());
        labelAddr2->setSizePolicy(sizePolicy);
        labelAddr2->setMinimumSize(QSize(0, 15));
        labelAddr2->setMaximumSize(QSize(16777215, 15));
        labelAddr2->setCursor(QCursor(Qt::PointingHandCursor));
        labelAddr2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #1E8BED;\n"
"border-bottom:0px;"));

        retranslateUi(UserCenterAccWidget);

        QMetaObject::connectSlotsByName(UserCenterAccWidget);
    } // setupUi

    void retranslateUi(QWidget *UserCenterAccWidget)
    {
        UserCenterAccWidget->setWindowTitle(QApplication::translate("UserCenterAccWidget", "AccSettingWidget", 0));
        labelFirstName->setText(QString());
        label->setText(QApplication::translate("UserCenterAccWidget", "\347\231\273\345\275\225\350\264\246\345\217\267\357\274\232", 0));
        labelUserName->setText(QString());
        label_2->setText(QApplication::translate("UserCenterAccWidget", "\345\247\223\345\220\215\357\274\232", 0));
        labelTrueName->setText(QString());
        labelJob->setText(QString());
        label_3->setText(QApplication::translate("UserCenterAccWidget", "\350\201\214\345\212\241\357\274\232", 0));
        labelInfoEdit->setText(QApplication::translate("UserCenterAccWidget", "\344\277\256\346\224\271", 0));
        label_4->setText(QString());
        label_5->setText(QApplication::translate("UserCenterAccWidget", "\346\211\213\346\234\272\347\273\221\345\256\232", 0));
        labelPhone->setText(QString());
        labelPhoneIcon->setText(QString());
        labelPhone1->setText(QString());
        label_6->setText(QString());
        labelPhone2->setText(QString());
        label_7->setText(QApplication::translate("UserCenterAccWidget", "\347\231\273\345\275\225\345\257\206\347\240\201", 0));
        labelPwd->setText(QString());
        labelPwdIcon->setText(QString());
        labelPwd1->setText(QString());
        label_8->setText(QString());
        labelPwd2->setText(QString());
        label_9->setText(QApplication::translate("UserCenterAccWidget", "\351\202\256\347\256\261\347\273\221\345\256\232", 0));
        labelEmail->setText(QString());
        labelEmailIcon->setText(QString());
        labelEmail1->setText(QString());
        label_10->setText(QString());
        labelEmail2->setText(QString());
        label_11->setText(QApplication::translate("UserCenterAccWidget", "\346\224\266\350\264\247\345\234\260\345\235\200", 0));
        labelAddr->setText(QString());
        labelAddrIcon->setText(QString());
        labelAddr1->setText(QString());
        label_12->setText(QString());
        labelAddr2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserCenterAccWidget: public Ui_UserCenterAccWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCENTERACCWIDGET_H
