/********************************************************************************
** Form generated from reading UI file 'Zcloudbrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZCLOUDBROWSER_H
#define UI_ZCLOUDBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Zcloudbrower
{
public:
    QVBoxLayout *vboxLayout;

    void setupUi(QWidget *Zcloudbrower)
    {
        if (Zcloudbrower->objectName().isEmpty())
            Zcloudbrower->setObjectName(QStringLiteral("Zcloudbrower"));
        Zcloudbrower->resize(1140, 760);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Zcloudbrower->sizePolicy().hasHeightForWidth());
        Zcloudbrower->setSizePolicy(sizePolicy);
        Zcloudbrower->setMinimumSize(QSize(1140, 760));
        Zcloudbrower->setMaximumSize(QSize(1140, 760));
        vboxLayout = new QVBoxLayout(Zcloudbrower);
        vboxLayout->setSpacing(0);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Zcloudbrower);

        QMetaObject::connectSlotsByName(Zcloudbrower);
    } // setupUi

    void retranslateUi(QWidget *Zcloudbrower)
    {
        Zcloudbrower->setWindowTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class Zcloudbrower: public Ui_Zcloudbrower {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZCLOUDBROWSER_H
