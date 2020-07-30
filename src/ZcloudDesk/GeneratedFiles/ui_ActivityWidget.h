/********************************************************************************
** Form generated from reading UI file 'ActivityWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVITYWIDGET_H
#define UI_ACTIVITYWIDGET_H

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

class Ui_ActivityWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QWidget *widget;
    QPushButton *closeButton;
    QLabel *label;

    void setupUi(QWidget *ActivityWidget)
    {
        if (ActivityWidget->objectName().isEmpty())
            ActivityWidget->setObjectName(QStringLiteral("ActivityWidget"));
        ActivityWidget->resize(740, 750);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ActivityWidget->sizePolicy().hasHeightForWidth());
        ActivityWidget->setSizePolicy(sizePolicy);
        ActivityWidget->setMinimumSize(QSize(740, 750));
        ActivityWidget->setMaximumSize(QSize(740, 750));
        verticalLayout = new QVBoxLayout(ActivityWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FilletWidget = new QWidget(ActivityWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(740, 750));
        FilletWidget->setMaximumSize(QSize(740, 750));
        FilletWidget->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);\n"
"border-radius:8px;"));
        widget = new QWidget(FilletWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 740, 50));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(740, 50));
        widget->setMaximumSize(QSize(740, 50));
        widget->setStyleSheet(QLatin1String("QWidget#widget{border-bottom:1px solid #DDDDDD;\n"
"border-bottom-left-radius:0px;\n"
"border-bottom-right-radius:0px;}"));
        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(697, 10, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudDesk/image/close.png);border-radius:none;background-color: rgba(255, 255, 255, 0);}\n"
"\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/close_sel.png);};"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 13, 98, 24));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(98, 24));
        label->setMaximumSize(QSize(98, 24));
        label->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/activity.png);"));

        verticalLayout->addWidget(FilletWidget);


        retranslateUi(ActivityWidget);
        QObject::connect(closeButton, SIGNAL(clicked()), ActivityWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(ActivityWidget);
    } // setupUi

    void retranslateUi(QWidget *ActivityWidget)
    {
        ActivityWidget->setWindowTitle(QApplication::translate("ActivityWidget", "ActivityWidget", 0));
        closeButton->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ActivityWidget: public Ui_ActivityWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVITYWIDGET_H
