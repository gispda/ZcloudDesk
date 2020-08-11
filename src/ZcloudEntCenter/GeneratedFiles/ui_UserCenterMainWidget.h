/********************************************************************************
** Form generated from reading UI file 'UserCenterMainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCENTERMAINWIDGET_H
#define UI_USERCENTERMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserCenterMainWidget
{
public:
    QWidget *EntRightWidget;
    QLabel *labelSpaceRight;
    QWidget *ServiceFeeWidget;
    QLabel *label_3;
    QWidget *SignInWidget;
    QPushButton *SignInButton;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_16;
    QWidget *CompeteDataWidget;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_17;
    QPushButton *CompeteDataButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *labelFirstName;
    QLabel *labelUserName;
    QLabel *labelUserJob;

    void setupUi(QWidget *UserCenterMainWidget)
    {
        if (UserCenterMainWidget->objectName().isEmpty())
            UserCenterMainWidget->setObjectName(QStringLiteral("UserCenterMainWidget"));
        UserCenterMainWidget->resize(750, 620);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserCenterMainWidget->sizePolicy().hasHeightForWidth());
        UserCenterMainWidget->setSizePolicy(sizePolicy);
        UserCenterMainWidget->setMinimumSize(QSize(750, 620));
        UserCenterMainWidget->setMaximumSize(QSize(1002, 6200));
        UserCenterMainWidget->setStyleSheet(QStringLiteral("QWidget#EntCenterWidget{background-color: rgb(255, 255, 255);};"));
        EntRightWidget = new QWidget(UserCenterMainWidget);
        EntRightWidget->setObjectName(QStringLiteral("EntRightWidget"));
        EntRightWidget->setGeometry(QRect(0, 0, 750, 618));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(EntRightWidget->sizePolicy().hasHeightForWidth());
        EntRightWidget->setSizePolicy(sizePolicy1);
        EntRightWidget->setMinimumSize(QSize(750, 618));
        EntRightWidget->setMaximumSize(QSize(750, 618));
        EntRightWidget->setStyleSheet(QStringLiteral("QWidget#EntRightWidget{background-color: rgb(252, 252, 252);border-top-right-radius:8px;border-bottom-right-radius:8px;}"));
        labelSpaceRight = new QLabel(EntRightWidget);
        labelSpaceRight->setObjectName(QStringLiteral("labelSpaceRight"));
        labelSpaceRight->setGeometry(QRect(0, 80, 750, 1));
        sizePolicy1.setHeightForWidth(labelSpaceRight->sizePolicy().hasHeightForWidth());
        labelSpaceRight->setSizePolicy(sizePolicy1);
        labelSpaceRight->setMinimumSize(QSize(750, 1));
        labelSpaceRight->setMaximumSize(QSize(750, 1));
        labelSpaceRight->setStyleSheet(QStringLiteral("background-color: rgb(235, 235, 235);"));
        ServiceFeeWidget = new QWidget(EntRightWidget);
        ServiceFeeWidget->setObjectName(QStringLiteral("ServiceFeeWidget"));
        ServiceFeeWidget->setGeometry(QRect(20, 140, 710, 180));
        sizePolicy1.setHeightForWidth(ServiceFeeWidget->sizePolicy().hasHeightForWidth());
        ServiceFeeWidget->setSizePolicy(sizePolicy1);
        ServiceFeeWidget->setMinimumSize(QSize(710, 80));
        ServiceFeeWidget->setMaximumSize(QSize(710, 180));
        ServiceFeeWidget->setStyleSheet(QLatin1String("QWidget#ServiceFeeWidget{background-color: rgb(252, 252, 252);border:1px solid rgba(235,235,235,1);\n"
"border-radius:10px;}"));
        label_3 = new QLabel(ServiceFeeWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 710, 180));
        label_3->setMaximumSize(QSize(710, 180));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/EntCenterWidget/image/userVipDefualt.png")));
        SignInWidget = new QWidget(EntRightWidget);
        SignInWidget->setObjectName(QStringLiteral("SignInWidget"));
        SignInWidget->setGeometry(QRect(20, 399, 710, 80));
        sizePolicy1.setHeightForWidth(SignInWidget->sizePolicy().hasHeightForWidth());
        SignInWidget->setSizePolicy(sizePolicy1);
        SignInWidget->setMinimumSize(QSize(710, 80));
        SignInWidget->setMaximumSize(QSize(710, 80));
        SignInWidget->setStyleSheet(QLatin1String("QWidget#SignInWidget{background-color: rgb(252, 252, 252);border:1px solid rgba(235,235,235,1);\n"
"border-radius:10px;}"));
        SignInButton = new QPushButton(SignInWidget);
        SignInButton->setObjectName(QStringLiteral("SignInButton"));
        SignInButton->setEnabled(false);
        SignInButton->setGeometry(QRect(618, 24, 72, 32));
        sizePolicy1.setHeightForWidth(SignInButton->sizePolicy().hasHeightForWidth());
        SignInButton->setSizePolicy(sizePolicy1);
        SignInButton->setMinimumSize(QSize(72, 32));
        SignInButton->setMaximumSize(QSize(72, 32));
        SignInButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        label_8 = new QLabel(SignInWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 15, 50, 50));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(50, 50));
        label_8->setMaximumSize(QSize(50, 50));
        label_8->setStyleSheet(QStringLiteral("QLabel{border-image: url(:/EntCenterWidget/image/signIn.png);}"));
        label_10 = new QLabel(SignInWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(89, 31, 56, 15));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(56, 15));
        label_10->setMaximumSize(QSize(56, 15));
        label_10->setStyleSheet(QString::fromUtf8("QLabel{font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;}"));
        label_12 = new QLabel(SignInWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(260, 31, 20, 20));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setMinimumSize(QSize(20, 20));
        label_12->setMaximumSize(QSize(20, 20));
        label_12->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/score.png);"));
        label_14 = new QLabel(SignInWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(290, 32, 20, 15));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMinimumSize(QSize(20, 15));
        label_14->setMaximumSize(QSize(20, 15));
        label_14->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label_16 = new QLabel(SignInWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(451, 32, 56, 15));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);
        label_16->setMinimumSize(QSize(56, 15));
        label_16->setMaximumSize(QSize(56, 15));
        label_16->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        CompeteDataWidget = new QWidget(EntRightWidget);
        CompeteDataWidget->setObjectName(QStringLiteral("CompeteDataWidget"));
        CompeteDataWidget->setEnabled(true);
        CompeteDataWidget->setGeometry(QRect(20, 499, 710, 80));
        sizePolicy1.setHeightForWidth(CompeteDataWidget->sizePolicy().hasHeightForWidth());
        CompeteDataWidget->setSizePolicy(sizePolicy1);
        CompeteDataWidget->setMinimumSize(QSize(710, 80));
        CompeteDataWidget->setMaximumSize(QSize(710, 80));
        CompeteDataWidget->setStyleSheet(QLatin1String("QWidget#CompeteDataWidget{background-color: rgb(252, 252, 252);border:1px solid rgba(235,235,235,1);\n"
"border-radius:10px;}"));
        label_9 = new QLabel(CompeteDataWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 15, 50, 50));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(50, 50));
        label_9->setMaximumSize(QSize(50, 50));
        label_9->setStyleSheet(QStringLiteral("QLabel{border-image: url(:/EntCenterWidget/image/completeInfo.png);}"));
        label_11 = new QLabel(CompeteDataWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(89, 31, 56, 15));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(56, 15));
        label_11->setMaximumSize(QSize(56, 15));
        label_11->setStyleSheet(QString::fromUtf8("QLabel{font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;}"));
        label_13 = new QLabel(CompeteDataWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(260, 31, 20, 20));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);
        label_13->setMinimumSize(QSize(20, 20));
        label_13->setMaximumSize(QSize(20, 20));
        label_13->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/score.png);"));
        label_15 = new QLabel(CompeteDataWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(290, 32, 20, 15));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setMinimumSize(QSize(20, 15));
        label_15->setMaximumSize(QSize(20, 15));
        label_15->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label_17 = new QLabel(CompeteDataWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(451, 32, 70, 15));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);
        label_17->setMinimumSize(QSize(70, 15));
        label_17->setMaximumSize(QSize(70, 15));
        label_17->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        CompeteDataButton = new QPushButton(CompeteDataWidget);
        CompeteDataButton->setObjectName(QStringLiteral("CompeteDataButton"));
        CompeteDataButton->setEnabled(false);
        CompeteDataButton->setGeometry(QRect(619, 24, 72, 32));
        sizePolicy1.setHeightForWidth(CompeteDataButton->sizePolicy().hasHeightForWidth());
        CompeteDataButton->setSizePolicy(sizePolicy1);
        CompeteDataButton->setMinimumSize(QSize(72, 32));
        CompeteDataButton->setMaximumSize(QSize(72, 32));
        CompeteDataButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));\n"
"			border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        label = new QLabel(EntRightWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(25, 100, 64, 17));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(64, 17));
        label->setMaximumSize(QSize(64, 17));
        label->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label_2 = new QLabel(EntRightWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(25, 359, 64, 17));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(64, 17));
        label_2->setMaximumSize(QSize(64, 17));
        label_2->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelFirstName = new QLabel(EntRightWidget);
        labelFirstName->setObjectName(QStringLiteral("labelFirstName"));
        labelFirstName->setGeometry(QRect(26, 30, 30, 30));
        sizePolicy1.setHeightForWidth(labelFirstName->sizePolicy().hasHeightForWidth());
        labelFirstName->setSizePolicy(sizePolicy1);
        labelFirstName->setMinimumSize(QSize(30, 30));
        labelFirstName->setMaximumSize(QSize(30, 30));
        labelFirstName->setStyleSheet(QString::fromUtf8("background:rgba(95,217,153,1);\n"
"border-radius:15px;\n"
"font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#FDFDFD;"));
        labelFirstName->setAlignment(Qt::AlignCenter);
        labelUserName = new QLabel(EntRightWidget);
        labelUserName->setObjectName(QStringLiteral("labelUserName"));
        labelUserName->setGeometry(QRect(62, 36, 28, 16));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelUserName->sizePolicy().hasHeightForWidth());
        labelUserName->setSizePolicy(sizePolicy2);
        labelUserName->setMinimumSize(QSize(28, 16));
        labelUserName->setMaximumSize(QSize(16777215, 16));
        labelUserName->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelUserJob = new QLabel(EntRightWidget);
        labelUserJob->setObjectName(QStringLiteral("labelUserJob"));
        labelUserJob->setGeometry(QRect(62, 58, 60, 18));
        sizePolicy2.setHeightForWidth(labelUserJob->sizePolicy().hasHeightForWidth());
        labelUserJob->setSizePolicy(sizePolicy2);
        labelUserJob->setMinimumSize(QSize(60, 18));
        labelUserJob->setMaximumSize(QSize(16777215, 18));
        labelUserJob->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#3EACF7;\n"
"background-color: rgb(237, 244, 255);\n"
"padding-left:2px;\n"
"border-radius:2px;"));

        retranslateUi(UserCenterMainWidget);

        QMetaObject::connectSlotsByName(UserCenterMainWidget);
    } // setupUi

    void retranslateUi(QWidget *UserCenterMainWidget)
    {
        UserCenterMainWidget->setWindowTitle(QApplication::translate("UserCenterMainWidget", "EntCenterWidget", 0));
        labelSpaceRight->setText(QString());
        label_3->setText(QString());
        SignInButton->setText(QApplication::translate("UserCenterMainWidget", "\345\216\273\345\256\214\346\210\220", 0));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("UserCenterMainWidget", "\345\256\214\346\210\220\347\255\276\345\210\260\357\274\214\345\217\257\350\216\267\345\276\227\344\272\221\345\270\201+10", 0));
#endif // QT_NO_TOOLTIP
        label_8->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_10->setToolTip(QApplication::translate("UserCenterMainWidget", "\345\256\214\346\210\220\347\255\276\345\210\260\357\274\214\345\217\257\350\216\267\345\276\227\344\272\221\345\270\201+10", 0));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("UserCenterMainWidget", "\346\257\217\346\227\245\347\255\276\345\210\260", 0));
        label_12->setText(QString());
        label_14->setText(QApplication::translate("UserCenterMainWidget", "10", 0));
        label_16->setText(QApplication::translate("UserCenterMainWidget", "\346\227\245\345\270\270\344\273\273\345\212\241", 0));
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("UserCenterMainWidget", "\345\256\214\345\226\204\344\270\252\344\272\272\350\265\204\346\226\231\357\274\214\345\217\257\350\216\267\345\276\227\344\272\221\345\270\201+50", 0));
#endif // QT_NO_TOOLTIP
        label_9->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_11->setToolTip(QApplication::translate("UserCenterMainWidget", "\345\256\214\345\226\204\344\270\252\344\272\272\350\265\204\346\226\231\357\274\214\345\217\257\350\216\267\345\276\227\344\272\221\345\270\201+50", 0));
#endif // QT_NO_TOOLTIP
        label_11->setText(QApplication::translate("UserCenterMainWidget", "\345\256\214\345\226\204\350\265\204\346\226\231", 0));
        label_13->setText(QString());
        label_15->setText(QApplication::translate("UserCenterMainWidget", "50", 0));
        label_17->setText(QApplication::translate("UserCenterMainWidget", "\344\270\200\346\254\241\346\200\247\344\273\273\345\212\241", 0));
        CompeteDataButton->setText(QApplication::translate("UserCenterMainWidget", "\345\216\273\345\256\214\346\210\220", 0));
        label->setText(QApplication::translate("UserCenterMainWidget", "\344\270\252\344\272\272\346\234\215\345\212\241", 0));
        label_2->setText(QApplication::translate("UserCenterMainWidget", "\344\272\221\345\270\201\344\273\273\345\212\241", 0));
        labelFirstName->setText(QString());
        labelUserName->setText(QString());
        labelUserJob->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserCenterMainWidget: public Ui_UserCenterMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCENTERMAINWIDGET_H
