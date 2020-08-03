/********************************************************************************
** Form generated from reading UI file 'TwobarCodeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWOBARCODEWIDGET_H
#define UI_TWOBARCODEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TwobarCodeWidget
{
public:
    QLabel *labelCode;
    QLabel *labelStr;
    QPushButton *closeButton;

    void setupUi(QWidget *TwobarCodeWidget)
    {
        if (TwobarCodeWidget->objectName().isEmpty())
            TwobarCodeWidget->setObjectName(QStringLiteral("TwobarCodeWidget"));
        TwobarCodeWidget->resize(180, 180);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TwobarCodeWidget->sizePolicy().hasHeightForWidth());
        TwobarCodeWidget->setSizePolicy(sizePolicy);
        TwobarCodeWidget->setMinimumSize(QSize(100, 100));
        TwobarCodeWidget->setMaximumSize(QSize(840, 500));
        TwobarCodeWidget->setStyleSheet(QStringLiteral("QWidget#FinanMemberWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        labelCode = new QLabel(TwobarCodeWidget);
        labelCode->setObjectName(QStringLiteral("labelCode"));
        labelCode->setGeometry(QRect(40, 20, 100, 100));
        labelStr = new QLabel(TwobarCodeWidget);
        labelStr->setObjectName(QStringLiteral("labelStr"));
        labelStr->setGeometry(QRect(10, 140, 160, 20));
        labelStr->setAlignment(Qt::AlignCenter);
        closeButton = new QPushButton(TwobarCodeWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(150, 5, 25, 25));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(20, 20));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));

        retranslateUi(TwobarCodeWidget);

        QMetaObject::connectSlotsByName(TwobarCodeWidget);
    } // setupUi

    void retranslateUi(QWidget *TwobarCodeWidget)
    {
        TwobarCodeWidget->setWindowTitle(QApplication::translate("TwobarCodeWidget", "FinanMemberWidget", 0));
        labelCode->setText(QString());
        labelStr->setText(QString());
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TwobarCodeWidget: public Ui_TwobarCodeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOBARCODEWIDGET_H
