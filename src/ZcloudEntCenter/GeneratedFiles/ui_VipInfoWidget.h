/********************************************************************************
** Form generated from reading UI file 'VipInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIPINFOWIDGET_H
#define UI_VIPINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VipInfoWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *FilletWidget;

    void setupUi(QWidget *VipInfoWidget)
    {
        if (VipInfoWidget->objectName().isEmpty())
            VipInfoWidget->setObjectName(QStringLiteral("VipInfoWidget"));
        VipInfoWidget->resize(1116, 696);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VipInfoWidget->sizePolicy().hasHeightForWidth());
        VipInfoWidget->setSizePolicy(sizePolicy);
        VipInfoWidget->setMinimumSize(QSize(1116, 696));
        VipInfoWidget->setMaximumSize(QSize(1116, 696));
        horizontalLayout = new QHBoxLayout(VipInfoWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(8, 8, 8, 8);
        FilletWidget = new QWidget(VipInfoWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(1100, 680));
        FilletWidget->setMaximumSize(QSize(1100, 680));
        FilletWidget->setStyleSheet(QStringLiteral("QWidget#FilletWidget{border-radius:8px;background-color: rgb(255, 255, 255);};"));

        horizontalLayout->addWidget(FilletWidget);


        retranslateUi(VipInfoWidget);

        QMetaObject::connectSlotsByName(VipInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *VipInfoWidget)
    {
        VipInfoWidget->setWindowTitle(QApplication::translate("VipInfoWidget", "VipInfoWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class VipInfoWidget: public Ui_VipInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIPINFOWIDGET_H
