/********************************************************************************
** Form generated from reading UI file 'AppCenterHomeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPCENTERHOMEWIDGET_H
#define UI_APPCENTERHOMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppCenterHomeWidget
{
public:
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *AppCenterHomeWidget)
    {
        if (AppCenterHomeWidget->objectName().isEmpty())
            AppCenterHomeWidget->setObjectName(QStringLiteral("AppCenterHomeWidget"));
        AppCenterHomeWidget->resize(1000, 528);
        AppCenterHomeWidget->setStyleSheet(QStringLiteral("QWidget#AppCenterHomeWidget{background: transparent;}"));
        label_2 = new QLabel(AppCenterHomeWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 263, 682, 1));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        label = new QLabel(AppCenterHomeWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(752, 263, 228, 1));
        label->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));

        retranslateUi(AppCenterHomeWidget);

        QMetaObject::connectSlotsByName(AppCenterHomeWidget);
    } // setupUi

    void retranslateUi(QWidget *AppCenterHomeWidget)
    {
        AppCenterHomeWidget->setWindowTitle(QApplication::translate("AppCenterHomeWidget", "AppCenterHomeWidget", 0));
        label_2->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AppCenterHomeWidget: public Ui_AppCenterHomeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPCENTERHOMEWIDGET_H
