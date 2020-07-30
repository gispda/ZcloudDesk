/********************************************************************************
** Form generated from reading UI file 'DownloadHelper.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADHELPER_H
#define UI_DOWNLOADHELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloadHelperClass
{
public:

    void setupUi(QWidget *DownloadHelperClass)
    {
        if (DownloadHelperClass->objectName().isEmpty())
            DownloadHelperClass->setObjectName(QStringLiteral("DownloadHelperClass"));
        DownloadHelperClass->resize(600, 400);

        retranslateUi(DownloadHelperClass);

        QMetaObject::connectSlotsByName(DownloadHelperClass);
    } // setupUi

    void retranslateUi(QWidget *DownloadHelperClass)
    {
        DownloadHelperClass->setWindowTitle(QApplication::translate("DownloadHelperClass", "DownloadHelper", 0));
    } // retranslateUi

};

namespace Ui {
    class DownloadHelperClass: public Ui_DownloadHelperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADHELPER_H
