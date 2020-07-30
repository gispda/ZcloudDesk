/********************************************************************************
** Form generated from reading UI file 'EntComWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTCOMWIDGET_H
#define UI_ENTCOMWIDGET_H

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

class Ui_EntComWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QWidget *TopWidget;
    QLabel *labelTitle;
    QPushButton *closeButton;

    void setupUi(QWidget *EntComWidget)
    {
        if (EntComWidget->objectName().isEmpty())
            EntComWidget->setObjectName(QStringLiteral("EntComWidget"));
        EntComWidget->resize(866, 606);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EntComWidget->sizePolicy().hasHeightForWidth());
        EntComWidget->setSizePolicy(sizePolicy);
        EntComWidget->setMinimumSize(QSize(866, 536));
        EntComWidget->setMaximumSize(QSize(866, 606));
        EntComWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(EntComWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        FilletWidget = new QWidget(EntComWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        FilletWidget->setStyleSheet(QLatin1String("border-radius:8px;\n"
"background-color: rgb(255, 255, 255);"));
        TopWidget = new QWidget(FilletWidget);
        TopWidget->setObjectName(QStringLiteral("TopWidget"));
        TopWidget->setGeometry(QRect(0, 0, 850, 50));
        sizePolicy.setHeightForWidth(TopWidget->sizePolicy().hasHeightForWidth());
        TopWidget->setSizePolicy(sizePolicy);
        TopWidget->setMinimumSize(QSize(850, 50));
        TopWidget->setMaximumSize(QSize(850, 50));
        TopWidget->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);\n"
"border-bottom:1px solid rgb(222, 222, 222);\n"
"border-bottom-right-radius:0px;\n"
"border-bottom-left-radius:0px;"));
        labelTitle = new QLabel(TopWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(21, 15, 80, 18));
        sizePolicy.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy);
        labelTitle->setMinimumSize(QSize(80, 18));
        labelTitle->setMaximumSize(QSize(80, 18));
        labelTitle->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        closeButton = new QPushButton(TopWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(810, 10, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton#closeButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton#closeButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));

        verticalLayout->addWidget(FilletWidget);


        retranslateUi(EntComWidget);

        QMetaObject::connectSlotsByName(EntComWidget);
    } // setupUi

    void retranslateUi(QWidget *EntComWidget)
    {
        EntComWidget->setWindowTitle(QApplication::translate("EntComWidget", "EntComWidget", 0));
        labelTitle->setText(QString());
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EntComWidget: public Ui_EntComWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTCOMWIDGET_H
