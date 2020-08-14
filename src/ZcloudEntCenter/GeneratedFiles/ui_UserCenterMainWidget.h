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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserCenterMainWidget
{
public:
    QLabel *label;
    QLabel *label_2;

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
        UserCenterMainWidget->setMaximumSize(QSize(750, 620));
        UserCenterMainWidget->setStyleSheet(QStringLiteral("QWidget#UserCenterMainWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        label = new QLabel(UserCenterMainWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 340, 250, 16));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(UserCenterMainWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(275, 90, 200, 200));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/ycs_logo.png);"));

        retranslateUi(UserCenterMainWidget);

        QMetaObject::connectSlotsByName(UserCenterMainWidget);
    } // setupUi

    void retranslateUi(QWidget *UserCenterMainWidget)
    {
        UserCenterMainWidget->setWindowTitle(QApplication::translate("UserCenterMainWidget", "EntCenterWidget", 0));
        label->setText(QApplication::translate("UserCenterMainWidget", "\345\212\237\350\203\275\345\273\272\350\256\276\344\270\255\357\274\214\346\225\254\350\257\267\346\234\237\345\276\205~", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserCenterMainWidget: public Ui_UserCenterMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCENTERMAINWIDGET_H
