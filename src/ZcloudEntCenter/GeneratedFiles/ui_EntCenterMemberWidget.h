/********************************************************************************
** Form generated from reading UI file 'EntCenterMemberWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTCENTERMEMBERWIDGET_H
#define UI_ENTCENTERMEMBERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EntCenterMemberWidget
{
public:
    QPushButton *addMemberButton;
    QLabel *labelAudit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QListWidget *listWidget;
    QLabel *label_5;

    void setupUi(QWidget *EntCenterMemberWidget)
    {
        if (EntCenterMemberWidget->objectName().isEmpty())
            EntCenterMemberWidget->setObjectName(QStringLiteral("EntCenterMemberWidget"));
        EntCenterMemberWidget->resize(750, 620);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EntCenterMemberWidget->sizePolicy().hasHeightForWidth());
        EntCenterMemberWidget->setSizePolicy(sizePolicy);
        EntCenterMemberWidget->setMinimumSize(QSize(700, 620));
        EntCenterMemberWidget->setMaximumSize(QSize(800, 620));
        EntCenterMemberWidget->setStyleSheet(QStringLiteral("QWidget#FinanMemberWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        addMemberButton = new QPushButton(EntCenterMemberWidget);
        addMemberButton->setObjectName(QStringLiteral("addMemberButton"));
        addMemberButton->setGeometry(QRect(37, 13, 88, 32));
        sizePolicy.setHeightForWidth(addMemberButton->sizePolicy().hasHeightForWidth());
        addMemberButton->setSizePolicy(sizePolicy);
        addMemberButton->setMinimumSize(QSize(88, 32));
        addMemberButton->setMaximumSize(QSize(88, 32));
        addMemberButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE;}\n"
"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        labelAudit = new QLabel(EntCenterMemberWidget);
        labelAudit->setObjectName(QStringLiteral("labelAudit"));
        labelAudit->setGeometry(QRect(670, 22, 61, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(15);
        sizePolicy1.setHeightForWidth(labelAudit->sizePolicy().hasHeightForWidth());
        labelAudit->setSizePolicy(sizePolicy1);
        labelAudit->setMinimumSize(QSize(0, 16));
        labelAudit->setMaximumSize(QSize(16777215, 16));
        labelAudit->setCursor(QCursor(Qt::PointingHandCursor));
        labelAudit->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #1E8BED;\n"
"border-bottom:0px;"));
        label = new QLabel(EntCenterMemberWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(81, 74, 27, 15));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(27, 15));
        label->setMaximumSize(QSize(270, 15));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_2 = new QLabel(EntCenterMemberWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(195, 74, 27, 15));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(27, 15));
        label_2->setMaximumSize(QSize(270, 15));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_3 = new QLabel(EntCenterMemberWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(330, 74, 45, 15));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(45, 15));
        label_3->setMaximumSize(QSize(270, 15));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_4 = new QLabel(EntCenterMemberWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(510, 74, 27, 15));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMinimumSize(QSize(27, 15));
        label_4->setMaximumSize(QSize(270, 15));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_6 = new QLabel(EntCenterMemberWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(700, 74, 27, 15));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setMinimumSize(QSize(27, 15));
        label_6->setMaximumSize(QSize(270, 15));
        label_6->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        listWidget = new QListWidget(EntCenterMemberWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 110, 730, 310));
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMinimumSize(QSize(730, 310));
        listWidget->setMaximumSize(QSize(740, 310));
        listWidget->setStyleSheet(QLatin1String("QListWidget{border-bottom-left-radius:0px;}\n"
"QListWidget::Item{background:rgb(255,255,255);}"));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        label_5 = new QLabel(EntCenterMemberWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(610, 74, 28, 15));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMinimumSize(QSize(27, 15));
        label_5->setMaximumSize(QSize(270, 15));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));

        retranslateUi(EntCenterMemberWidget);

        QMetaObject::connectSlotsByName(EntCenterMemberWidget);
    } // setupUi

    void retranslateUi(QWidget *EntCenterMemberWidget)
    {
        EntCenterMemberWidget->setWindowTitle(QApplication::translate("EntCenterMemberWidget", "FinanMemberWidget", 0));
        addMemberButton->setText(QApplication::translate("EntCenterMemberWidget", "\346\267\273\345\212\240\346\210\220\345\221\230", 0));
        labelAudit->setText(QApplication::translate("EntCenterMemberWidget", "\346\210\220\345\221\230\345\256\241\346\240\270", 0));
        label->setText(QApplication::translate("EntCenterMemberWidget", "\345\247\223\345\220\215", 0));
        label_2->setText(QApplication::translate("EntCenterMemberWidget", "\350\264\246\345\217\267", 0));
        label_3->setText(QApplication::translate("EntCenterMemberWidget", "\346\211\213\346\234\272\345\217\267", 0));
        label_4->setText(QApplication::translate("EntCenterMemberWidget", "\350\201\214\345\212\241", 0));
        label_6->setText(QApplication::translate("EntCenterMemberWidget", "\346\223\215\344\275\234", 0));
        label_5->setText(QApplication::translate("EntCenterMemberWidget", "\350\247\222\350\211\262", 0));
    } // retranslateUi

};

namespace Ui {
    class EntCenterMemberWidget: public Ui_EntCenterMemberWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTCENTERMEMBERWIDGET_H
