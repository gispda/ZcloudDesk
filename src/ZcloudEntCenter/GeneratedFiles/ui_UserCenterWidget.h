/********************************************************************************
** Form generated from reading UI file 'UserCenterWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCENTERWIDGET_H
#define UI_USERCENTERWIDGET_H

#include <AvatarLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserCenterWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QWidget *EntLeftWidget;
    AvatarLabel *labelAvatar;
    QLabel *labelUserName;
    QLabel *labelUserID;
    QLabel *labelSpaceLeft;
    QLabel *labelMore;
    QLabel *labelEntInfo;
    QPushButton *mainButton;
    QLabel *labelUser;
    QLabel *labelEntInfo_2;
    QPushButton *pushButtonAcc;
    QWidget *widgetUnLogin;
    QLabel *label;
    QPushButton *pushButtonLogin;
    QWidget *widgetLogin;
    QLabel *labelName;
    QLabel *labelID;
    QLabel *label_2;
    QWidget *RightWidget;
    QHBoxLayout *rightLayout;
    QVBoxLayout *layout;

    void setupUi(QWidget *UserCenterWidget)
    {
        if (UserCenterWidget->objectName().isEmpty())
            UserCenterWidget->setObjectName(QStringLiteral("UserCenterWidget"));
        UserCenterWidget->resize(1002, 620);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserCenterWidget->sizePolicy().hasHeightForWidth());
        UserCenterWidget->setSizePolicy(sizePolicy);
        UserCenterWidget->setMinimumSize(QSize(1002, 620));
        UserCenterWidget->setMaximumSize(QSize(1002, 6200));
        horizontalLayout_2 = new QHBoxLayout(UserCenterWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        EntLeftWidget = new QWidget(UserCenterWidget);
        EntLeftWidget->setObjectName(QStringLiteral("EntLeftWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(EntLeftWidget->sizePolicy().hasHeightForWidth());
        EntLeftWidget->setSizePolicy(sizePolicy1);
        EntLeftWidget->setMinimumSize(QSize(250, 618));
        EntLeftWidget->setMaximumSize(QSize(250, 618));
        EntLeftWidget->setStyleSheet(QStringLiteral("QWidget#EntLeftWidget{background-color: rgb(252, 252, 252);}"));
        labelAvatar = new AvatarLabel(EntLeftWidget);
        labelAvatar->setObjectName(QStringLiteral("labelAvatar"));
        labelAvatar->setGeometry(QRect(95, 30, 60, 60));
        sizePolicy1.setHeightForWidth(labelAvatar->sizePolicy().hasHeightForWidth());
        labelAvatar->setSizePolicy(sizePolicy1);
        labelAvatar->setMinimumSize(QSize(60, 60));
        labelAvatar->setMaximumSize(QSize(60, 60));
        labelAvatar->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/img_tx_d.png);"));
        labelUserName = new QLabel(EntLeftWidget);
        labelUserName->setObjectName(QStringLiteral("labelUserName"));
        labelUserName->setGeometry(QRect(21, 100, 210, 35));
        sizePolicy1.setHeightForWidth(labelUserName->sizePolicy().hasHeightForWidth());
        labelUserName->setSizePolicy(sizePolicy1);
        labelUserName->setMinimumSize(QSize(210, 35));
        labelUserName->setMaximumSize(QSize(210, 35));
        labelUserName->setStyleSheet(QString::fromUtf8("font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight:bold;\n"
"color:#333333;"));
        labelUserName->setAlignment(Qt::AlignCenter);
        labelUserName->setWordWrap(true);
        labelUserID = new QLabel(EntLeftWidget);
        labelUserID->setObjectName(QStringLiteral("labelUserID"));
        labelUserID->setGeometry(QRect(52, 144, 150, 12));
        sizePolicy1.setHeightForWidth(labelUserID->sizePolicy().hasHeightForWidth());
        labelUserID->setSizePolicy(sizePolicy1);
        labelUserID->setMinimumSize(QSize(150, 12));
        labelUserID->setMaximumSize(QSize(150, 12));
        labelUserID->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelUserID->setAlignment(Qt::AlignCenter);
        labelSpaceLeft = new QLabel(EntLeftWidget);
        labelSpaceLeft->setObjectName(QStringLiteral("labelSpaceLeft"));
        labelSpaceLeft->setGeometry(QRect(0, 287, 250, 1));
        sizePolicy1.setHeightForWidth(labelSpaceLeft->sizePolicy().hasHeightForWidth());
        labelSpaceLeft->setSizePolicy(sizePolicy1);
        labelSpaceLeft->setMinimumSize(QSize(250, 1));
        labelSpaceLeft->setMaximumSize(QSize(250, 1));
        labelSpaceLeft->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        labelMore = new QLabel(EntLeftWidget);
        labelMore->setObjectName(QStringLiteral("labelMore"));
        labelMore->setGeometry(QRect(29, 332, 57, 15));
        sizePolicy1.setHeightForWidth(labelMore->sizePolicy().hasHeightForWidth());
        labelMore->setSizePolicy(sizePolicy1);
        labelMore->setMinimumSize(QSize(57, 15));
        labelMore->setMaximumSize(QSize(57, 15));
        labelMore->setStyleSheet(QString::fromUtf8("font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelEntInfo = new QLabel(EntLeftWidget);
        labelEntInfo->setObjectName(QStringLiteral("labelEntInfo"));
        labelEntInfo->setGeometry(QRect(60, 371, 10, 10));
        sizePolicy1.setHeightForWidth(labelEntInfo->sizePolicy().hasHeightForWidth());
        labelEntInfo->setSizePolicy(sizePolicy1);
        labelEntInfo->setMinimumSize(QSize(10, 10));
        labelEntInfo->setMaximumSize(QSize(10, 10));
        labelEntInfo->setStyleSheet(QLatin1String("border:2px solid rgba(223,70,100,1);\n"
"border-radius:5px;"));
        mainButton = new QPushButton(EntLeftWidget);
        mainButton->setObjectName(QStringLiteral("mainButton"));
        mainButton->setGeometry(QRect(80, 360, 80, 30));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mainButton->sizePolicy().hasHeightForWidth());
        mainButton->setSizePolicy(sizePolicy2);
        mainButton->setMinimumSize(QSize(57, 30));
        mainButton->setMaximumSize(QSize(570, 30));
        mainButton->setLayoutDirection(Qt::LeftToRight);
        mainButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(51, 51, 51, 1);padding-left:-20px;}\n"
"QPushButton:hover,pressed{ background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(31,139,237,1);}"));
        labelUser = new QLabel(EntLeftWidget);
        labelUser->setObjectName(QStringLiteral("labelUser"));
        labelUser->setGeometry(QRect(95, 30, 60, 60));
        sizePolicy1.setHeightForWidth(labelUser->sizePolicy().hasHeightForWidth());
        labelUser->setSizePolicy(sizePolicy1);
        labelUser->setMinimumSize(QSize(60, 60));
        labelUser->setMaximumSize(QSize(60, 60));
        labelUser->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/qyzx_icon_vip_wjr.png);"));
        labelEntInfo_2 = new QLabel(EntLeftWidget);
        labelEntInfo_2->setObjectName(QStringLiteral("labelEntInfo_2"));
        labelEntInfo_2->setGeometry(QRect(60, 422, 10, 10));
        sizePolicy1.setHeightForWidth(labelEntInfo_2->sizePolicy().hasHeightForWidth());
        labelEntInfo_2->setSizePolicy(sizePolicy1);
        labelEntInfo_2->setMinimumSize(QSize(10, 10));
        labelEntInfo_2->setMaximumSize(QSize(10, 10));
        labelEntInfo_2->setStyleSheet(QLatin1String("border:2px solid rgba(223,70,100,1);\n"
"border-radius:5px;"));
        pushButtonAcc = new QPushButton(EntLeftWidget);
        pushButtonAcc->setObjectName(QStringLiteral("pushButtonAcc"));
        pushButtonAcc->setGeometry(QRect(80, 410, 80, 30));
        sizePolicy2.setHeightForWidth(pushButtonAcc->sizePolicy().hasHeightForWidth());
        pushButtonAcc->setSizePolicy(sizePolicy2);
        pushButtonAcc->setMinimumSize(QSize(57, 30));
        pushButtonAcc->setMaximumSize(QSize(570, 30));
        pushButtonAcc->setLayoutDirection(Qt::LeftToRight);
        pushButtonAcc->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(51, 51, 51, 1);padding-left:-20px;}\n"
"QPushButton:hover,pressed{ background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(31,139,237,1);}"));
        widgetUnLogin = new QWidget(EntLeftWidget);
        widgetUnLogin->setObjectName(QStringLiteral("widgetUnLogin"));
        widgetUnLogin->setGeometry(QRect(0, 120, 250, 100));
        label = new QLabel(widgetUnLogin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 40, 250, 35));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(250, 35));
        label->setMaximumSize(QSize(250, 35));
        label->setStyleSheet(QString::fromUtf8("font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        pushButtonLogin = new QPushButton(widgetUnLogin);
        pushButtonLogin->setObjectName(QStringLiteral("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(85, 10, 80, 30));
        pushButtonLogin->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1E8BED;"));
        pushButtonLogin->setFlat(true);
        widgetLogin = new QWidget(EntLeftWidget);
        widgetLogin->setObjectName(QStringLiteral("widgetLogin"));
        widgetLogin->setGeometry(QRect(0, 120, 250, 100));
        labelName = new QLabel(widgetLogin);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(90, 10, 70, 20));
        labelName->setStyleSheet(QString::fromUtf8("font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelName->setAlignment(Qt::AlignCenter);
        labelID = new QLabel(widgetLogin);
        labelID->setObjectName(QStringLiteral("labelID"));
        labelID->setGeometry(QRect(50, 60, 150, 12));
        labelID->setStyleSheet(QString::fromUtf8("font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelID->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(widgetLogin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 10, 20, 20));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/EntCenterWidget/image/notExpired.png")));

        horizontalLayout->addWidget(EntLeftWidget);

        RightWidget = new QWidget(UserCenterWidget);
        RightWidget->setObjectName(QStringLiteral("RightWidget"));
        sizePolicy1.setHeightForWidth(RightWidget->sizePolicy().hasHeightForWidth());
        RightWidget->setSizePolicy(sizePolicy1);
        RightWidget->setMinimumSize(QSize(750, 618));
        RightWidget->setMaximumSize(QSize(750, 618));
        RightWidget->setStyleSheet(QStringLiteral("QWidget#RightWidget{background-color: rgb(252, 252, 252);}"));
        rightLayout = new QHBoxLayout(RightWidget);
        rightLayout->setSpacing(0);
        rightLayout->setContentsMargins(11, 11, 11, 11);
        rightLayout->setObjectName(QStringLiteral("rightLayout"));
        rightLayout->setContentsMargins(0, 0, 0, 0);
        layout = new QVBoxLayout();
        layout->setSpacing(0);
        layout->setObjectName(QStringLiteral("layout"));

        rightLayout->addLayout(layout);


        horizontalLayout->addWidget(RightWidget);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(UserCenterWidget);

        QMetaObject::connectSlotsByName(UserCenterWidget);
    } // setupUi

    void retranslateUi(QWidget *UserCenterWidget)
    {
        UserCenterWidget->setWindowTitle(QApplication::translate("UserCenterWidget", "EntCenterWidget", 0));
        labelAvatar->setText(QString());
        labelUserName->setText(QString());
        labelUserID->setText(QString());
        labelSpaceLeft->setText(QString());
        labelMore->setText(QApplication::translate("UserCenterWidget", "\346\233\264\345\244\232", 0));
        labelEntInfo->setText(QString());
        mainButton->setText(QApplication::translate("UserCenterWidget", "\351\246\226        \351\241\265", 0));
        mainButton->setShortcut(QApplication::translate("UserCenterWidget", "Ctrl+S, Esc", 0));
        labelUser->setText(QString());
        labelEntInfo_2->setText(QString());
        pushButtonAcc->setText(QApplication::translate("UserCenterWidget", "\350\264\246\345\217\267\350\256\276\347\275\256", 0));
        pushButtonAcc->setShortcut(QApplication::translate("UserCenterWidget", "Ctrl+S, Esc", 0));
        label->setText(QApplication::translate("UserCenterWidget", "\347\231\273\345\275\225\345\220\216\345\217\257\344\275\223\351\252\214\346\233\264\345\244\232\345\212\237\350\203\275", 0));
        pushButtonLogin->setText(QApplication::translate("UserCenterWidget", "\347\253\213\345\215\263\347\231\273\345\275\225", 0));
        labelName->setText(QApplication::translate("UserCenterWidget", "TextLabel", 0));
        labelID->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserCenterWidget: public Ui_UserCenterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCENTERWIDGET_H
