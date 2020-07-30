/********************************************************************************
** Form generated from reading UI file 'CalculatorWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORWIDGET_H
#define UI_CALCULATORWIDGET_H

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

class Ui_CalculatorWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QWidget *TopWidget;
    QLabel *label;
    QPushButton *closeButton;

    void setupUi(QWidget *CalculatorWidget)
    {
        if (CalculatorWidget->objectName().isEmpty())
            CalculatorWidget->setObjectName(QStringLiteral("CalculatorWidget"));
        CalculatorWidget->resize(1140, 760);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CalculatorWidget->sizePolicy().hasHeightForWidth());
        CalculatorWidget->setSizePolicy(sizePolicy);
        CalculatorWidget->setMinimumSize(QSize(1140, 760));
        CalculatorWidget->setMaximumSize(QSize(1140, 760));
        verticalLayout = new QVBoxLayout(CalculatorWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FilletWidget = new QWidget(CalculatorWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(1140, 760));
        FilletWidget->setMaximumSize(QSize(1140, 760));
        FilletWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:8px;"));
        TopWidget = new QWidget(FilletWidget);
        TopWidget->setObjectName(QStringLiteral("TopWidget"));
        TopWidget->setGeometry(QRect(0, 0, 1140, 50));
        sizePolicy.setHeightForWidth(TopWidget->sizePolicy().hasHeightForWidth());
        TopWidget->setSizePolicy(sizePolicy);
        TopWidget->setMinimumSize(QSize(1140, 50));
        TopWidget->setMaximumSize(QSize(1140, 50));
        TopWidget->setStyleSheet(QLatin1String("QWidget#TopWidget{border-bottom:1px solid #DDDDDD;\n"
"border-bottom-left-radius:0px;\n"
"border-bottom-right-radius:0px;background-color: rgb(239, 243, 245);}\n"
""));
        label = new QLabel(TopWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(520, 17, 85, 18));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(85, 18));
        label->setMaximumSize(QSize(85, 18));
        label->setStyleSheet(QString::fromUtf8("QLabel{font:16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;background-color: rgb(239, 243, 245)}"));
        label->setAlignment(Qt::AlignCenter);
        closeButton = new QPushButton(TopWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(1100, 10, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudDesk/image/close.png);border-radius:none;background-color: rgba(255, 255, 255, 0);}\n"
"\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/close_sel.png);};"));

        verticalLayout->addWidget(FilletWidget);


        retranslateUi(CalculatorWidget);

        QMetaObject::connectSlotsByName(CalculatorWidget);
    } // setupUi

    void retranslateUi(QWidget *CalculatorWidget)
    {
        CalculatorWidget->setWindowTitle(QApplication::translate("CalculatorWidget", "CalculatorWidget", 0));
        label->setText(QApplication::translate("CalculatorWidget", "\350\264\242\347\250\216\350\256\241\347\256\227\345\231\250", 0));
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CalculatorWidget: public Ui_CalculatorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORWIDGET_H
