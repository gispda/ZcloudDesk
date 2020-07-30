/********************************************************************************
** Form generated from reading UI file 'ZcloudDesk.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZCLOUDDESK_H
#define UI_ZCLOUDDESK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "EdgeToHide.h"
#include "labelex.h"

QT_BEGIN_NAMESPACE

class Ui_ZcloudDesk
{
public:
    QWidget *centralWidget;
    EdgeToHide *ZcloudTopWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *usernameButton;
    QPushButton *spaceButtonName;
    LabelEx *labelAvatar;
    QLabel *labelCompName;
    QPushButton *spaceButton_2;
    QPushButton *customServiceButton;
    QPushButton *billListButton;
    QPushButton *appButton;
    QPushButton *calendarButton;
    QPushButton *screenShootButton;
    QPushButton *spaceButton;
    QPushButton *settingButton;
    QPushButton *hideButton;

    void setupUi(QMainWindow *ZcloudDesk)
    {
        if (ZcloudDesk->objectName().isEmpty())
            ZcloudDesk->setObjectName(QStringLiteral("ZcloudDesk"));
        ZcloudDesk->resize(1329, 752);
        ZcloudDesk->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(ZcloudDesk);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        ZcloudTopWidget = new EdgeToHide(centralWidget);
        ZcloudTopWidget->setObjectName(QStringLiteral("ZcloudTopWidget"));
        ZcloudTopWidget->setGeometry(QRect(30, 330, 841, 30));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ZcloudTopWidget->sizePolicy().hasHeightForWidth());
        ZcloudTopWidget->setSizePolicy(sizePolicy);
        ZcloudTopWidget->setMinimumSize(QSize(200, 30));
        ZcloudTopWidget->setMaximumSize(QSize(16777215, 30));
        ZcloudTopWidget->setStyleSheet(QLatin1String("border-image: url(:/ZcloudDesk/image/bg_transparent_pre.png);\n"
""));
        horizontalLayout = new QHBoxLayout(ZcloudTopWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        usernameButton = new QPushButton(ZcloudTopWidget);
        usernameButton->setObjectName(QStringLiteral("usernameButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(usernameButton->sizePolicy().hasHeightForWidth());
        usernameButton->setSizePolicy(sizePolicy1);
        usernameButton->setMinimumSize(QSize(0, 26));
        usernameButton->setMaximumSize(QSize(160, 26));
        usernameButton->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/ZcloudDesk/image/bg_transparent.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";}\n"
"QPushButton:hover{border-image: url(:/ZcloudDesk/image/bg_transparent_hover.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"}\n"
"QPushButton:pressed{border-image: url(:/ZcloudDesk/image/bg_transparent_pre.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"};"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ZcloudDesk/image/icon_yyzx.png"), QSize(), QIcon::Normal, QIcon::Off);
        usernameButton->setIcon(icon);
        usernameButton->setIconSize(QSize(14, 26));

        horizontalLayout->addWidget(usernameButton);

        spaceButtonName = new QPushButton(ZcloudTopWidget);
        spaceButtonName->setObjectName(QStringLiteral("spaceButtonName"));
        sizePolicy1.setHeightForWidth(spaceButtonName->sizePolicy().hasHeightForWidth());
        spaceButtonName->setSizePolicy(sizePolicy1);
        spaceButtonName->setMinimumSize(QSize(21, 26));
        spaceButtonName->setMaximumSize(QSize(21, 26));
        spaceButtonName->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/line.png);"));

        horizontalLayout->addWidget(spaceButtonName);

        labelAvatar = new LabelEx(ZcloudTopWidget);
        labelAvatar->setObjectName(QStringLiteral("labelAvatar"));
        sizePolicy1.setHeightForWidth(labelAvatar->sizePolicy().hasHeightForWidth());
        labelAvatar->setSizePolicy(sizePolicy1);
        labelAvatar->setMinimumSize(QSize(26, 26));
        labelAvatar->setMaximumSize(QSize(26, 26));
        labelAvatar->setStyleSheet(QString::fromUtf8("QLabel{border-image: url(:/ZcloudDesk/image/bg_transparent.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";padding-left:8px;padding-right:8px;}"));

        horizontalLayout->addWidget(labelAvatar);

        labelCompName = new QLabel(ZcloudTopWidget);
        labelCompName->setObjectName(QStringLiteral("labelCompName"));
        sizePolicy.setHeightForWidth(labelCompName->sizePolicy().hasHeightForWidth());
        labelCompName->setSizePolicy(sizePolicy);
        labelCompName->setMinimumSize(QSize(0, 26));
        labelCompName->setMaximumSize(QSize(1000, 26));
        labelCompName->setStyleSheet(QString::fromUtf8("QLabel{border-image: url(:/ZcloudDesk/image/bg_transparent.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";padding-left:5px;padding-right:5px;}\n"
"QLabel:hover{border-image: url(:/ZcloudDesk/image/bg_transparent_hover.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";padding-left:5px;padding-right:5px;}\n"
"QLabel:pressed{border-image: url(:/ZcloudDesk/image/bg_transparent_pre.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";padding-left:5px;padding-right:5px;};"));
        labelCompName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelCompName);

        spaceButton_2 = new QPushButton(ZcloudTopWidget);
        spaceButton_2->setObjectName(QStringLiteral("spaceButton_2"));
        sizePolicy1.setHeightForWidth(spaceButton_2->sizePolicy().hasHeightForWidth());
        spaceButton_2->setSizePolicy(sizePolicy1);
        spaceButton_2->setMinimumSize(QSize(21, 26));
        spaceButton_2->setMaximumSize(QSize(21, 26));
        spaceButton_2->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/line.png);"));

        horizontalLayout->addWidget(spaceButton_2);

        customServiceButton = new QPushButton(ZcloudTopWidget);
        customServiceButton->setObjectName(QStringLiteral("customServiceButton"));
        sizePolicy1.setHeightForWidth(customServiceButton->sizePolicy().hasHeightForWidth());
        customServiceButton->setSizePolicy(sizePolicy1);
        customServiceButton->setMinimumSize(QSize(86, 26));
        customServiceButton->setMaximumSize(QSize(86, 26));
        customServiceButton->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/ZcloudDesk/image/bg_transparent.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";}\n"
"QPushButton:hover{border-image: url(:/ZcloudDesk/image/bg_transparent_hover.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"}\n"
"QPushButton:pressed{border-image: url(:/ZcloudDesk/image/bg_transparent_pre.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"};"));
        customServiceButton->setIcon(icon);
        customServiceButton->setIconSize(QSize(14, 26));

        horizontalLayout->addWidget(customServiceButton);

        billListButton = new QPushButton(ZcloudTopWidget);
        billListButton->setObjectName(QStringLiteral("billListButton"));
        sizePolicy1.setHeightForWidth(billListButton->sizePolicy().hasHeightForWidth());
        billListButton->setSizePolicy(sizePolicy1);
        billListButton->setMinimumSize(QSize(86, 26));
        billListButton->setMaximumSize(QSize(86, 26));
        billListButton->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/ZcloudDesk/image/bg_transparent.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";}\n"
"QPushButton:hover{border-image: url(:/ZcloudDesk/image/bg_transparent_hover.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"}\n"
"QPushButton:pressed{border-image: url(:/ZcloudDesk/image/bg_transparent_pre.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"};"));
        billListButton->setIcon(icon);
        billListButton->setIconSize(QSize(14, 26));

        horizontalLayout->addWidget(billListButton);

        appButton = new QPushButton(ZcloudTopWidget);
        appButton->setObjectName(QStringLiteral("appButton"));
        sizePolicy1.setHeightForWidth(appButton->sizePolicy().hasHeightForWidth());
        appButton->setSizePolicy(sizePolicy1);
        appButton->setMinimumSize(QSize(86, 26));
        appButton->setMaximumSize(QSize(86, 26));
        appButton->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/ZcloudDesk/image/bg_transparent.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";}\n"
"QPushButton:hover{border-image: url(:/ZcloudDesk/image/bg_transparent_hover.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"}\n"
"QPushButton:pressed{border-image: url(:/ZcloudDesk/image/bg_transparent_pre.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"};"));
        appButton->setIcon(icon);
        appButton->setIconSize(QSize(14, 26));

        horizontalLayout->addWidget(appButton);

        calendarButton = new QPushButton(ZcloudTopWidget);
        calendarButton->setObjectName(QStringLiteral("calendarButton"));
        sizePolicy1.setHeightForWidth(calendarButton->sizePolicy().hasHeightForWidth());
        calendarButton->setSizePolicy(sizePolicy1);
        calendarButton->setMinimumSize(QSize(60, 26));
        calendarButton->setMaximumSize(QSize(60, 26));
        calendarButton->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/ZcloudDesk/image/bg_transparent.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";}\n"
"QPushButton:hover{border-image: url(:/ZcloudDesk/image/bg_transparent_hover.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"}\n"
"QPushButton:pressed{border-image: url(:/ZcloudDesk/image/bg_transparent_pre.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"};"));
        calendarButton->setIconSize(QSize(14, 26));

        horizontalLayout->addWidget(calendarButton);

        screenShootButton = new QPushButton(ZcloudTopWidget);
        screenShootButton->setObjectName(QStringLiteral("screenShootButton"));
        sizePolicy1.setHeightForWidth(screenShootButton->sizePolicy().hasHeightForWidth());
        screenShootButton->setSizePolicy(sizePolicy1);
        screenShootButton->setMinimumSize(QSize(60, 26));
        screenShootButton->setMaximumSize(QSize(60, 26));
        screenShootButton->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/ZcloudDesk/image/bg_transparent.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";}\n"
"QPushButton:hover{border-image: url(:/ZcloudDesk/image/bg_transparent_hover.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"}\n"
"QPushButton:pressed{border-image: url(:/ZcloudDesk/image/bg_transparent_pre.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"};"));
        screenShootButton->setIconSize(QSize(14, 26));

        horizontalLayout->addWidget(screenShootButton);

        spaceButton = new QPushButton(ZcloudTopWidget);
        spaceButton->setObjectName(QStringLiteral("spaceButton"));
        sizePolicy1.setHeightForWidth(spaceButton->sizePolicy().hasHeightForWidth());
        spaceButton->setSizePolicy(sizePolicy1);
        spaceButton->setMinimumSize(QSize(21, 26));
        spaceButton->setMaximumSize(QSize(21, 26));
        spaceButton->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/line.png);"));

        horizontalLayout->addWidget(spaceButton);

        settingButton = new QPushButton(ZcloudTopWidget);
        settingButton->setObjectName(QStringLiteral("settingButton"));
        sizePolicy1.setHeightForWidth(settingButton->sizePolicy().hasHeightForWidth());
        settingButton->setSizePolicy(sizePolicy1);
        settingButton->setMinimumSize(QSize(60, 26));
        settingButton->setMaximumSize(QSize(60, 26));
        settingButton->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/ZcloudDesk/image/bg_transparent.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";}\n"
"QPushButton:hover{border-image: url(:/ZcloudDesk/image/bg_transparent_hover.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"}\n"
"QPushButton:pressed{border-image: url(:/ZcloudDesk/image/bg_transparent_pre.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"};"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ZcloudDesk/image/setPng.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingButton->setIcon(icon1);
        settingButton->setIconSize(QSize(15, 26));

        horizontalLayout->addWidget(settingButton);

        hideButton = new QPushButton(ZcloudTopWidget);
        hideButton->setObjectName(QStringLiteral("hideButton"));
        sizePolicy1.setHeightForWidth(hideButton->sizePolicy().hasHeightForWidth());
        hideButton->setSizePolicy(sizePolicy1);
        hideButton->setMinimumSize(QSize(60, 26));
        hideButton->setMaximumSize(QSize(60, 26));
        hideButton->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/ZcloudDesk/image/bg_transparent.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";}\n"
"QPushButton:hover{border-image: url(:/ZcloudDesk/image/bg_transparent_hover.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"}\n"
"QPushButton:pressed{border-image: url(:/ZcloudDesk/image/bg_transparent_pre.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"};"));
        hideButton->setIconSize(QSize(15, 26));

        horizontalLayout->addWidget(hideButton);

        ZcloudDesk->setCentralWidget(centralWidget);

        retranslateUi(ZcloudDesk);

        QMetaObject::connectSlotsByName(ZcloudDesk);
    } // setupUi

    void retranslateUi(QMainWindow *ZcloudDesk)
    {
        ZcloudDesk->setWindowTitle(QApplication::translate("ZcloudDesk", "ZcloudDesk", 0));
        usernameButton->setText(QString());
        spaceButtonName->setText(QString());
        labelAvatar->setText(QString());
        labelCompName->setText(QString());
        spaceButton_2->setText(QString());
        customServiceButton->setText(QApplication::translate("ZcloudDesk", "\350\201\224\347\263\273\345\256\242\346\234\215", 0));
        billListButton->setText(QApplication::translate("ZcloudDesk", "\346\210\221\347\232\204\345\267\245\345\215\225", 0));
        appButton->setText(QApplication::translate("ZcloudDesk", "\345\272\224\347\224\250\344\270\255\345\277\203", 0));
        calendarButton->setText(QApplication::translate("ZcloudDesk", "\350\264\242\347\250\216\346\227\245\345\216\206", 0));
        screenShootButton->setText(QApplication::translate("ZcloudDesk", "\346\210\252\345\233\276", 0));
        spaceButton->setText(QString());
        settingButton->setText(QApplication::translate("ZcloudDesk", "\350\256\276\347\275\256", 0));
        hideButton->setText(QApplication::translate("ZcloudDesk", "\351\232\220\350\227\217", 0));
    } // retranslateUi

};

namespace Ui {
    class ZcloudDesk: public Ui_ZcloudDesk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZCLOUDDESK_H
