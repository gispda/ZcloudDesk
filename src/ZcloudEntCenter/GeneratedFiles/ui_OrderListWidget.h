/********************************************************************************
** Form generated from reading UI file 'OrderListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERLISTWIDGET_H
#define UI_ORDERLISTWIDGET_H

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

class Ui_OrderListWidget
{
public:
    QWidget *TopWidget;
    QLabel *labelTitle;
    QPushButton *closeButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QListWidget *listWidget;
    QLabel *label_5;

    void setupUi(QWidget *OrderListWidget)
    {
        if (OrderListWidget->objectName().isEmpty())
            OrderListWidget->setObjectName(QStringLiteral("OrderListWidget"));
        OrderListWidget->resize(840, 540);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OrderListWidget->sizePolicy().hasHeightForWidth());
        OrderListWidget->setSizePolicy(sizePolicy);
        OrderListWidget->setMinimumSize(QSize(800, 400));
        OrderListWidget->setMaximumSize(QSize(840, 600));
        OrderListWidget->setStyleSheet(QStringLiteral("QWidget#FinanMemberWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        TopWidget = new QWidget(OrderListWidget);
        TopWidget->setObjectName(QStringLiteral("TopWidget"));
        TopWidget->setGeometry(QRect(0, 0, 840, 52));
        sizePolicy.setHeightForWidth(TopWidget->sizePolicy().hasHeightForWidth());
        TopWidget->setSizePolicy(sizePolicy);
        TopWidget->setMinimumSize(QSize(800, 52));
        TopWidget->setMaximumSize(QSize(840, 52));
        TopWidget->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);\n"
"border-bottom:1px solid rgb(222, 222, 222);\n"
"border-top-right-radius:8px;\n"
"border-top-left-radius:8px;"));
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
        closeButton->setGeometry(QRect(760, 10, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label = new QLabel(OrderListWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 74, 60, 15));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(27, 15));
        label->setMaximumSize(QSize(270, 15));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_2 = new QLabel(OrderListWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 74, 60, 15));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(27, 15));
        label_2->setMaximumSize(QSize(270, 15));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_4 = new QLabel(OrderListWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(450, 74, 27, 15));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(27, 15));
        label_4->setMaximumSize(QSize(270, 15));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_6 = new QLabel(OrderListWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(710, 74, 27, 15));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(27, 15));
        label_6->setMaximumSize(QSize(270, 15));
        label_6->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        listWidget = new QListWidget(OrderListWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 100, 780, 420));
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMinimumSize(QSize(740, 310));
        listWidget->setMaximumSize(QSize(780, 600));
        listWidget->setStyleSheet(QLatin1String("QListWidget{border-bottom-left-radius:0px;}\n"
"QListWidget::Item{background:rgb(255,255,255);}"));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        label_5 = new QLabel(OrderListWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(550, 74, 60, 15));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(27, 15));
        label_5->setMaximumSize(QSize(270, 15));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));

        retranslateUi(OrderListWidget);

        QMetaObject::connectSlotsByName(OrderListWidget);
    } // setupUi

    void retranslateUi(QWidget *OrderListWidget)
    {
        OrderListWidget->setWindowTitle(QApplication::translate("OrderListWidget", "FinanMemberWidget", 0));
        labelTitle->setText(QApplication::translate("OrderListWidget", "\346\210\221\347\232\204\345\267\245\345\215\225", 0));
        closeButton->setText(QString());
        label->setText(QApplication::translate("OrderListWidget", "\345\267\245\345\215\225\347\274\226\345\217\267", 0));
        label_2->setText(QApplication::translate("OrderListWidget", "\345\267\245\345\215\225\346\240\207\351\242\230", 0));
        label_4->setText(QApplication::translate("OrderListWidget", "\347\212\266\346\200\201", 0));
        label_6->setText(QApplication::translate("OrderListWidget", "\346\223\215\344\275\234", 0));
        label_5->setText(QApplication::translate("OrderListWidget", "\345\210\233\345\273\272\346\227\266\351\227\264", 0));
    } // retranslateUi

};

namespace Ui {
    class OrderListWidget: public Ui_OrderListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERLISTWIDGET_H
