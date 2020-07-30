/********************************************************************************
** Form generated from reading UI file 'dlgwait.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGWAIT_H
#define UI_DLGWAIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DlgWait
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QLabel *waitLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *hintLabel;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *DlgWait)
    {
        if (DlgWait->objectName().isEmpty())
            DlgWait->setObjectName(QStringLiteral("DlgWait"));
        DlgWait->resize(812, 532);
        DlgWait->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(DlgWait);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(17, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(288, 100, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        waitLabel = new QLabel(DlgWait);
        waitLabel->setObjectName(QStringLiteral("waitLabel"));
        waitLabel->setMinimumSize(QSize(100, 100));
        waitLabel->setMaximumSize(QSize(100, 100));

        gridLayout->addWidget(waitLabel, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(288, 100, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        hintLabel = new QLabel(DlgWait);
        hintLabel->setObjectName(QStringLiteral("hintLabel"));
        hintLabel->setLayoutDirection(Qt::LeftToRight);
        hintLabel->setStyleSheet(QString::fromUtf8("font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        hintLabel->setTextFormat(Qt::AutoText);
        hintLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(hintLabel, 2, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(17, 62, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);


        retranslateUi(DlgWait);

        QMetaObject::connectSlotsByName(DlgWait);
    } // setupUi

    void retranslateUi(QDialog *DlgWait)
    {
        DlgWait->setWindowTitle(QApplication::translate("DlgWait", "Dialog", 0));
        waitLabel->setText(QString());
        hintLabel->setText(QApplication::translate("DlgWait", "\345\212\240\350\275\275\344\270\255...", 0));
    } // retranslateUi

};

namespace Ui {
    class DlgWait: public Ui_DlgWait {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGWAIT_H
