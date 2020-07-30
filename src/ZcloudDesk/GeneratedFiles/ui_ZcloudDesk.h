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
#include <zappmenubutton.h>
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
    LabelEx *labelAvatar;
    QLabel *labelCompName;
    QPushButton *appButton;
    ZAppMenuButton *msgButton;
    QPushButton *spaceButton;
    QPushButton *settingButton;

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
        ZcloudTopWidget->setGeometry(QRect(310, 330, 391, 30));
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

        labelAvatar = new LabelEx(ZcloudTopWidget);
        labelAvatar->setObjectName(QStringLiteral("labelAvatar"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/ZcloudDesk/image/icon_yyzx.png"), QSize(), QIcon::Normal, QIcon::Off);
        appButton->setIcon(icon);
        appButton->setIconSize(QSize(14, 26));

        horizontalLayout->addWidget(appButton);

        msgButton = new ZAppMenuButton(ZcloudTopWidget);
        msgButton->setObjectName(QStringLiteral("msgButton"));
        sizePolicy1.setHeightForWidth(msgButton->sizePolicy().hasHeightForWidth());
        msgButton->setSizePolicy(sizePolicy1);
        msgButton->setMinimumSize(QSize(60, 26));
        msgButton->setMaximumSize(QSize(60, 26));
        msgButton->setStyleSheet(QString::fromUtf8("QPushButton{border-image: url(:/ZcloudDesk/image/bg_transparent.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";}\n"
"QPushButton:hover{border-image: url(:/ZcloudDesk/image/bg_transparent_hover.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"}\n"
"QPushButton:pressed{border-image: url(:/ZcloudDesk/image/bg_transparent_pre.png);color: rgb(255, 255, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\"};"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ZcloudDesk/image/icon_xxzx.png"), QSize(), QIcon::Normal, QIcon::Off);
        msgButton->setIcon(icon1);
        msgButton->setIconSize(QSize(14, 26));

        horizontalLayout->addWidget(msgButton);

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
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ZcloudDesk/image/setPng.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingButton->setIcon(icon2);
        settingButton->setIconSize(QSize(15, 26));

        horizontalLayout->addWidget(settingButton);

        ZcloudDesk->setCentralWidget(centralWidget);

        retranslateUi(ZcloudDesk);

        QMetaObject::connectSlotsByName(ZcloudDesk);
    } // setupUi

    void retranslateUi(QMainWindow *ZcloudDesk)
    {
        ZcloudDesk->setWindowTitle(QApplication::translate("ZcloudDesk", "ZcloudDesk", 0));
        labelAvatar->setText(QString());
        labelCompName->setText(QString());
        appButton->setText(QApplication::translate("ZcloudDesk", "\345\272\224\347\224\250\344\270\255\345\277\203", 0));
        msgButton->setText(QApplication::translate("ZcloudDesk", "\346\266\210\346\201\257", 0));
        spaceButton->setText(QString());
        settingButton->setText(QApplication::translate("ZcloudDesk", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class ZcloudDesk: public Ui_ZcloudDesk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZCLOUDDESK_H
