/********************************************************************************
** Form generated from reading UI file 'MemberItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMBERITEMWIDGET_H
#define UI_MEMBERITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemberItemWidget
{
public:
    QWidget *FilletWidget;
    QLabel *labelJob;
    QLabel *labelMobile;
    QLabel *labelFirstName;
    QPushButton *operButton;
    QLabel *labelUserName;
    QLabel *labelTrueName;
    QLabel *labelRole;

    void setupUi(QWidget *MemberItemWidget)
    {
        if (MemberItemWidget->objectName().isEmpty())
            MemberItemWidget->setObjectName(QStringLiteral("MemberItemWidget"));
        MemberItemWidget->resize(730, 90);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MemberItemWidget->sizePolicy().hasHeightForWidth());
        MemberItemWidget->setSizePolicy(sizePolicy);
        MemberItemWidget->setMinimumSize(QSize(730, 90));
        MemberItemWidget->setMaximumSize(QSize(730, 90));
        MemberItemWidget->setStyleSheet(QStringLiteral("QWidget#MemberItemWidget{background-color: rgb(255, 255, 255);};"));
        FilletWidget = new QWidget(MemberItemWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        FilletWidget->setGeometry(QRect(0, 5, 730, 60));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(730, 60));
        FilletWidget->setMaximumSize(QSize(730, 60));
        FilletWidget->setStyleSheet(QLatin1String("QWidget#FilletWidget{background:rgb(252,252,252);border-radius:4px;border:1px solid rgb(235,235,235);}\n"
"QWidget#FilletWidget:hover,pressed{background:rgb(246,251,255);border-radius:4px;border:1px solid rgb(187,223,255);};"));
        labelJob = new QLabel(FilletWidget);
        labelJob->setObjectName(QStringLiteral("labelJob"));
        labelJob->setGeometry(QRect(490, 22, 90, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelJob->sizePolicy().hasHeightForWidth());
        labelJob->setSizePolicy(sizePolicy1);
        labelJob->setMinimumSize(QSize(80, 16));
        labelJob->setMaximumSize(QSize(180, 16));
        labelJob->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;"));
        labelMobile = new QLabel(FilletWidget);
        labelMobile->setObjectName(QStringLiteral("labelMobile"));
        labelMobile->setGeometry(QRect(320, 22, 160, 16));
        sizePolicy1.setHeightForWidth(labelMobile->sizePolicy().hasHeightForWidth());
        labelMobile->setSizePolicy(sizePolicy1);
        labelMobile->setMinimumSize(QSize(80, 16));
        labelMobile->setMaximumSize(QSize(178, 16));
        labelMobile->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;"));
        labelFirstName = new QLabel(FilletWidget);
        labelFirstName->setObjectName(QStringLiteral("labelFirstName"));
        labelFirstName->setGeometry(QRect(10, 10, 40, 40));
        sizePolicy.setHeightForWidth(labelFirstName->sizePolicy().hasHeightForWidth());
        labelFirstName->setSizePolicy(sizePolicy);
        labelFirstName->setMinimumSize(QSize(40, 40));
        labelFirstName->setMaximumSize(QSize(40, 40));
        labelFirstName->setStyleSheet(QStringLiteral(""));
        labelFirstName->setAlignment(Qt::AlignCenter);
        operButton = new QPushButton(FilletWidget);
        operButton->setObjectName(QStringLiteral("operButton"));
        operButton->setGeometry(QRect(690, 20, 10, 18));
        sizePolicy.setHeightForWidth(operButton->sizePolicy().hasHeightForWidth());
        operButton->setSizePolicy(sizePolicy);
        operButton->setMinimumSize(QSize(10, 18));
        operButton->setMaximumSize(QSize(10, 18));
        operButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/oper.png);}\n"
"QPushButton::menu-indicator{image:none;}\n"
""));
        labelUserName = new QLabel(FilletWidget);
        labelUserName->setObjectName(QStringLiteral("labelUserName"));
        labelUserName->setGeometry(QRect(173, 22, 150, 16));
        sizePolicy1.setHeightForWidth(labelUserName->sizePolicy().hasHeightForWidth());
        labelUserName->setSizePolicy(sizePolicy1);
        labelUserName->setMinimumSize(QSize(80, 16));
        labelUserName->setMaximumSize(QSize(150, 16));
        labelUserName->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;"));
        labelTrueName = new QLabel(FilletWidget);
        labelTrueName->setObjectName(QStringLiteral("labelTrueName"));
        labelTrueName->setGeometry(QRect(60, 22, 110, 16));
        sizePolicy1.setHeightForWidth(labelTrueName->sizePolicy().hasHeightForWidth());
        labelTrueName->setSizePolicy(sizePolicy1);
        labelTrueName->setMinimumSize(QSize(80, 16));
        labelTrueName->setMaximumSize(QSize(110, 16));
        labelTrueName->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;"));
        labelRole = new QLabel(FilletWidget);
        labelRole->setObjectName(QStringLiteral("labelRole"));
        labelRole->setGeometry(QRect(590, 22, 90, 16));
        sizePolicy1.setHeightForWidth(labelRole->sizePolicy().hasHeightForWidth());
        labelRole->setSizePolicy(sizePolicy1);
        labelRole->setMinimumSize(QSize(80, 16));
        labelRole->setMaximumSize(QSize(180, 16));
        labelRole->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;"));

        retranslateUi(MemberItemWidget);

        QMetaObject::connectSlotsByName(MemberItemWidget);
    } // setupUi

    void retranslateUi(QWidget *MemberItemWidget)
    {
        MemberItemWidget->setWindowTitle(QApplication::translate("MemberItemWidget", "MemberItemWidget", 0));
        labelJob->setText(QString());
        labelMobile->setText(QString());
        labelFirstName->setText(QString());
        operButton->setText(QString());
        labelUserName->setText(QString());
        labelTrueName->setText(QString());
        labelRole->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MemberItemWidget: public Ui_MemberItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMBERITEMWIDGET_H
