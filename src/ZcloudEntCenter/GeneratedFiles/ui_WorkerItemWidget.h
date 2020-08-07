/********************************************************************************
** Form generated from reading UI file 'WorkerItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKERITEMWIDGET_H
#define UI_WORKERITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkerItemWidget
{
public:
    QWidget *FilletWidget;
    QLabel *labelCreateTime;
    QLabel *labelState;
    QLabel *labelOrderCode;
    QLabel *labelOrderName;
    QLabel *labelStateColor;
    QPushButton *buttonDetial;
    QPushButton *buttonAction;

    void setupUi(QWidget *WorkerItemWidget)
    {
        if (WorkerItemWidget->objectName().isEmpty())
            WorkerItemWidget->setObjectName(QStringLiteral("WorkerItemWidget"));
        WorkerItemWidget->resize(780, 70);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WorkerItemWidget->sizePolicy().hasHeightForWidth());
        WorkerItemWidget->setSizePolicy(sizePolicy);
        WorkerItemWidget->setMinimumSize(QSize(730, 70));
        WorkerItemWidget->setMaximumSize(QSize(780, 70));
        WorkerItemWidget->setStyleSheet(QStringLiteral("QWidget#MemberItemWidget{background-color: rgb(255, 255, 255);};"));
        FilletWidget = new QWidget(WorkerItemWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        FilletWidget->setGeometry(QRect(0, 5, 780, 60));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(730, 60));
        FilletWidget->setMaximumSize(QSize(780, 60));
        FilletWidget->setStyleSheet(QLatin1String("QWidget#FilletWidget{background:rgb(252,252,252);border-radius:4px;border:1px solid rgb(235,235,235);}\n"
"QWidget#FilletWidget:hover,pressed{background:rgb(246,251,255);border-radius:4px;border:1px solid rgb(187,223,255);};"));
        labelCreateTime = new QLabel(FilletWidget);
        labelCreateTime->setObjectName(QStringLiteral("labelCreateTime"));
        labelCreateTime->setGeometry(QRect(520, 10, 150, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelCreateTime->sizePolicy().hasHeightForWidth());
        labelCreateTime->setSizePolicy(sizePolicy1);
        labelCreateTime->setMinimumSize(QSize(80, 16));
        labelCreateTime->setMaximumSize(QSize(180, 40));
        labelCreateTime->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;"));
        labelState = new QLabel(FilletWidget);
        labelState->setObjectName(QStringLiteral("labelState"));
        labelState->setGeometry(QRect(440, 10, 70, 40));
        sizePolicy1.setHeightForWidth(labelState->sizePolicy().hasHeightForWidth());
        labelState->setSizePolicy(sizePolicy1);
        labelState->setMinimumSize(QSize(70, 16));
        labelState->setMaximumSize(QSize(178, 40));
        labelState->setStyleSheet(QLatin1String("border:px solid rgba(223,70,100,1);\n"
"border-radius:5px;"));
        labelOrderCode = new QLabel(FilletWidget);
        labelOrderCode->setObjectName(QStringLiteral("labelOrderCode"));
        labelOrderCode->setGeometry(QRect(10, 10, 90, 40));
        sizePolicy.setHeightForWidth(labelOrderCode->sizePolicy().hasHeightForWidth());
        labelOrderCode->setSizePolicy(sizePolicy);
        labelOrderCode->setMinimumSize(QSize(40, 40));
        labelOrderCode->setMaximumSize(QSize(200, 40));
        labelOrderCode->setStyleSheet(QStringLiteral(""));
        labelOrderCode->setAlignment(Qt::AlignCenter);
        labelOrderName = new QLabel(FilletWidget);
        labelOrderName->setObjectName(QStringLiteral("labelOrderName"));
        labelOrderName->setGeometry(QRect(110, 10, 300, 40));
        sizePolicy1.setHeightForWidth(labelOrderName->sizePolicy().hasHeightForWidth());
        labelOrderName->setSizePolicy(sizePolicy1);
        labelOrderName->setMinimumSize(QSize(80, 16));
        labelOrderName->setMaximumSize(QSize(300, 40));
        labelOrderName->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;"));
        labelStateColor = new QLabel(FilletWidget);
        labelStateColor->setObjectName(QStringLiteral("labelStateColor"));
        labelStateColor->setGeometry(QRect(420, 25, 10, 10));
        sizePolicy1.setHeightForWidth(labelStateColor->sizePolicy().hasHeightForWidth());
        labelStateColor->setSizePolicy(sizePolicy1);
        labelStateColor->setMinimumSize(QSize(10, 10));
        labelStateColor->setMaximumSize(QSize(178, 40));
        labelStateColor->setStyleSheet(QLatin1String("border:5px solid rgba(223,70,100,1);\n"
"border-radius:5px;"));
        buttonDetial = new QPushButton(FilletWidget);
        buttonDetial->setObjectName(QStringLiteral("buttonDetial"));
        buttonDetial->setGeometry(QRect(680, 10, 40, 40));
        buttonDetial->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;color:blue"));
        buttonDetial->setFlat(true);
        buttonAction = new QPushButton(FilletWidget);
        buttonAction->setObjectName(QStringLiteral("buttonAction"));
        buttonAction->setGeometry(QRect(730, 10, 40, 40));
        buttonAction->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;color:blue"));
        buttonAction->setFlat(true);

        retranslateUi(WorkerItemWidget);

        QMetaObject::connectSlotsByName(WorkerItemWidget);
    } // setupUi

    void retranslateUi(QWidget *WorkerItemWidget)
    {
        WorkerItemWidget->setWindowTitle(QApplication::translate("WorkerItemWidget", "MemberItemWidget", 0));
        labelCreateTime->setText(QString());
        labelState->setText(QString());
        labelOrderCode->setText(QString());
        labelOrderName->setText(QString());
        labelStateColor->setText(QString());
        buttonDetial->setText(QApplication::translate("WorkerItemWidget", "\350\257\246\346\203\205", 0));
        buttonAction->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WorkerItemWidget: public Ui_WorkerItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERITEMWIDGET_H
