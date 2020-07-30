/********************************************************************************
** Form generated from reading UI file 'DefaultVipWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFAULTVIPWIDGET_H
#define UI_DEFAULTVIPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DefaultVipWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *DefaultVipWidget)
    {
        if (DefaultVipWidget->objectName().isEmpty())
            DefaultVipWidget->setObjectName(QStringLiteral("DefaultVipWidget"));
        DefaultVipWidget->resize(566, 356);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DefaultVipWidget->sizePolicy().hasHeightForWidth());
        DefaultVipWidget->setSizePolicy(sizePolicy);
        DefaultVipWidget->setMinimumSize(QSize(566, 356));
        DefaultVipWidget->setMaximumSize(QSize(566, 356));
        verticalLayout = new QVBoxLayout(DefaultVipWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        FilletWidget = new QWidget(DefaultVipWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(550, 340));
        FilletWidget->setMaximumSize(QSize(550, 340));
        FilletWidget->setStyleSheet(QLatin1String("border-radius:8px;\n"
"background-color: rgb(255, 255, 255);"));
        label = new QLabel(FilletWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(175, 60, 200, 136));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(200, 136));
        label->setMaximumSize(QSize(200, 136));
        label->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/defaultVip.png);"));
        label_2 = new QLabel(FilletWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(158, 221, 241, 20));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight:400;\n"
"color:rgba(232,196,135,1);"));
        pushButton = new QPushButton(FilletWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(231, 278, 88, 32));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(88, 32));
        pushButton->setMaximumSize(QSize(88, 32));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: #FFFFFF;border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE}\n"
"QPushButton:hover,pressed{ background-color: #F4F4F4;border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));

        verticalLayout->addWidget(FilletWidget);


        retranslateUi(DefaultVipWidget);
        QObject::connect(pushButton, SIGNAL(clicked()), DefaultVipWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(DefaultVipWidget);
    } // setupUi

    void retranslateUi(QWidget *DefaultVipWidget)
    {
        DefaultVipWidget->setWindowTitle(QApplication::translate("DefaultVipWidget", "DefaultVipWidget", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("DefaultVipWidget", "    \344\274\232\345\221\230\346\255\243\345\234\250\347\255\271\345\244\207\344\270\255,\346\225\254\350\257\267\346\234\237\345\276\205...", 0));
        pushButton->setText(QApplication::translate("DefaultVipWidget", "\347\237\245\351\201\223\344\272\206", 0));
    } // retranslateUi

};

namespace Ui {
    class DefaultVipWidget: public Ui_DefaultVipWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFAULTVIPWIDGET_H
