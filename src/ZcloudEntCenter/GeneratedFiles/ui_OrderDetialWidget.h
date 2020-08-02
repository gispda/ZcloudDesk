/********************************************************************************
** Form generated from reading UI file 'OrderDetialWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERDETIALWIDGET_H
#define UI_ORDERDETIALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderDetialWidget
{
public:
    QWidget *TopWidget;
    QLabel *labelTitle;
    QPushButton *closeButton;
    QLabel *label;
    QLabel *labelNodeEnd;
    QLabel *labelNodeStart;
    QLabel *labelProgressStart;
    QLabel *labelProgressEnd;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *labelTimeCreate;
    QLabel *labelTimeStart;
    QLabel *labelTimeEnd;
    QLabel *labelCodeName;
    QTextBrowser *textContent;
    QLabel *labelTitle_2;
    QListView *listFiles;
    QPushButton *buttonOK;

    void setupUi(QWidget *OrderDetialWidget)
    {
        if (OrderDetialWidget->objectName().isEmpty())
            OrderDetialWidget->setObjectName(QStringLiteral("OrderDetialWidget"));
        OrderDetialWidget->resize(640, 430);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OrderDetialWidget->sizePolicy().hasHeightForWidth());
        OrderDetialWidget->setSizePolicy(sizePolicy);
        OrderDetialWidget->setMinimumSize(QSize(640, 300));
        OrderDetialWidget->setMaximumSize(QSize(840, 500));
        OrderDetialWidget->setStyleSheet(QStringLiteral("QWidget#FinanMemberWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        TopWidget = new QWidget(OrderDetialWidget);
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
        closeButton->setGeometry(QRect(590, 10, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label = new QLabel(OrderDetialWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 60, 20, 20));
        label->setStyleSheet(QLatin1String("border:10px solid rgba(0,0,255,1);\n"
"border-radius:10px;"));
        labelNodeEnd = new QLabel(OrderDetialWidget);
        labelNodeEnd->setObjectName(QStringLiteral("labelNodeEnd"));
        labelNodeEnd->setGeometry(QRect(500, 60, 20, 20));
        labelNodeEnd->setStyleSheet(QLatin1String("border:10px solid rgba(0,0,255,1);\n"
"border-radius:10px;"));
        labelNodeStart = new QLabel(OrderDetialWidget);
        labelNodeStart->setObjectName(QStringLiteral("labelNodeStart"));
        labelNodeStart->setGeometry(QRect(310, 60, 20, 20));
        labelNodeStart->setStyleSheet(QLatin1String("border:10px solid rgba(0,0,255,1);\n"
"border-radius:10px;"));
        labelProgressStart = new QLabel(OrderDetialWidget);
        labelProgressStart->setObjectName(QStringLiteral("labelProgressStart"));
        labelProgressStart->setGeometry(QRect(140, 68, 170, 4));
        labelProgressStart->setStyleSheet(QStringLiteral("border:2px solid rgba(0,0,240,1)"));
        labelProgressEnd = new QLabel(OrderDetialWidget);
        labelProgressEnd->setObjectName(QStringLiteral("labelProgressEnd"));
        labelProgressEnd->setGeometry(QRect(330, 68, 170, 4));
        labelProgressEnd->setStyleSheet(QStringLiteral("border:2px solid rgba(0,0,240,1)"));
        label_6 = new QLabel(OrderDetialWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(104, 85, 54, 12));
        label_6->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        label_7 = new QLabel(OrderDetialWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(300, 85, 54, 12));
        label_7->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        label_8 = new QLabel(OrderDetialWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(495, 85, 54, 12));
        label_8->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        labelTimeCreate = new QLabel(OrderDetialWidget);
        labelTimeCreate->setObjectName(QStringLiteral("labelTimeCreate"));
        labelTimeCreate->setGeometry(QRect(60, 105, 141, 16));
        labelTimeCreate->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        labelTimeStart = new QLabel(OrderDetialWidget);
        labelTimeStart->setObjectName(QStringLiteral("labelTimeStart"));
        labelTimeStart->setGeometry(QRect(250, 105, 141, 16));
        labelTimeStart->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        labelTimeEnd = new QLabel(OrderDetialWidget);
        labelTimeEnd->setObjectName(QStringLiteral("labelTimeEnd"));
        labelTimeEnd->setGeometry(QRect(440, 105, 141, 16));
        labelTimeEnd->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        labelCodeName = new QLabel(OrderDetialWidget);
        labelCodeName->setObjectName(QStringLiteral("labelCodeName"));
        labelCodeName->setGeometry(QRect(21, 120, 600, 18));
        sizePolicy.setHeightForWidth(labelCodeName->sizePolicy().hasHeightForWidth());
        labelCodeName->setSizePolicy(sizePolicy);
        labelCodeName->setMinimumSize(QSize(80, 18));
        labelCodeName->setMaximumSize(QSize(800, 18));
        labelCodeName->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        textContent = new QTextBrowser(OrderDetialWidget);
        textContent->setObjectName(QStringLiteral("textContent"));
        textContent->setGeometry(QRect(21, 145, 600, 150));
        textContent->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 224, 0%);   border: 0px solid black;"));
        labelTitle_2 = new QLabel(OrderDetialWidget);
        labelTitle_2->setObjectName(QStringLiteral("labelTitle_2"));
        labelTitle_2->setGeometry(QRect(21, 300, 80, 18));
        sizePolicy.setHeightForWidth(labelTitle_2->sizePolicy().hasHeightForWidth());
        labelTitle_2->setSizePolicy(sizePolicy);
        labelTitle_2->setMinimumSize(QSize(80, 18));
        labelTitle_2->setMaximumSize(QSize(80, 18));
        labelTitle_2->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        listFiles = new QListView(OrderDetialWidget);
        listFiles->setObjectName(QStringLiteral("listFiles"));
        listFiles->setGeometry(QRect(21, 325, 600, 60));
        listFiles->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 224, 0%);   border: 0px solid black;"));
        buttonOK = new QPushButton(OrderDetialWidget);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));
        buttonOK->setGeometry(QRect(280, 380, 80, 32));
        sizePolicy.setHeightForWidth(buttonOK->sizePolicy().hasHeightForWidth());
        buttonOK->setSizePolicy(sizePolicy);
        buttonOK->setMinimumSize(QSize(72, 32));
        buttonOK->setMaximumSize(QSize(100, 32));
        buttonOK->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));

        retranslateUi(OrderDetialWidget);

        QMetaObject::connectSlotsByName(OrderDetialWidget);
    } // setupUi

    void retranslateUi(QWidget *OrderDetialWidget)
    {
        OrderDetialWidget->setWindowTitle(QApplication::translate("OrderDetialWidget", "FinanMemberWidget", 0));
        labelTitle->setText(QApplication::translate("OrderDetialWidget", "\345\267\245\345\215\225\350\257\246\346\203\205", 0));
        closeButton->setText(QString());
        label->setText(QString());
        labelNodeEnd->setText(QString());
        labelNodeStart->setText(QString());
        labelProgressStart->setText(QString());
        labelProgressEnd->setText(QString());
        label_6->setText(QApplication::translate("OrderDetialWidget", "\346\217\220\344\272\244\345\267\245\345\215\225", 0));
        label_7->setText(QApplication::translate("OrderDetialWidget", "\345\244\204\347\220\206\344\270\255", 0));
        label_8->setText(QApplication::translate("OrderDetialWidget", "\345\267\262\345\256\214\346\210\220", 0));
        labelTimeCreate->setText(QApplication::translate("OrderDetialWidget", "2020-10-01 12\357\274\23200\357\274\23200", 0));
        labelTimeStart->setText(QApplication::translate("OrderDetialWidget", "2020-10-01 12\357\274\23200\357\274\23200", 0));
        labelTimeEnd->setText(QApplication::translate("OrderDetialWidget", "2020-10-01 12\357\274\23200\357\274\23200", 0));
        labelCodeName->setText(QApplication::translate("OrderDetialWidget", "\346\240\207\351\242\230", 0));
        labelTitle_2->setText(QApplication::translate("OrderDetialWidget", "\351\231\204\344\273\266", 0));
        buttonOK->setText(QApplication::translate("OrderDetialWidget", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class OrderDetialWidget: public Ui_OrderDetialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERDETIALWIDGET_H
