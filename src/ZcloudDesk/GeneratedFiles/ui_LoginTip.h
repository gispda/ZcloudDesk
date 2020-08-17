/********************************************************************************
** Form generated from reading UI file 'LoginTip.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINTIP_H
#define UI_LOGINTIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZcloudLoginTip
{
public:
    QToolButton *okButton;
    QToolButton *closeButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *ZcloudLoginTip)
    {
        if (ZcloudLoginTip->objectName().isEmpty())
            ZcloudLoginTip->setObjectName(QStringLiteral("ZcloudLoginTip"));
        ZcloudLoginTip->resize(370, 386);
        ZcloudLoginTip->setStyleSheet(QLatin1String("background:rgba(255,255,255,1);\n"
"box-shadow:0px 2px 15px 0px rgba(0,0,0,0.15);\n"
"border-radius:4px;\n"
"border:1px solid rgba(226,226,226,1);"));
        okButton = new QToolButton(ZcloudLoginTip);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(193, 332, 100, 38));
        okButton->setStyleSheet(QString::fromUtf8("QToolButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);padding-left:8px;}\n"
"QToolButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}"));
        closeButton = new QToolButton(ZcloudLoginTip);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(77, 332, 100, 38));
        closeButton->setStyleSheet(QLatin1String("QToolButton{border-radius:4px;\n"
"border:1px solid rgba(222,222,222,1);}"));
        label = new QLabel(ZcloudLoginTip);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(53, 118, 265, 174));
        label->setPixmap(QPixmap(QString::fromUtf8(":/ZcloudDesk/image/logintip.png")));
        label_2 = new QLabel(ZcloudLoginTip);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(35, 60, 300, 18));
        label_2->setStyleSheet(QLatin1String("background:rgba(255,255,255,1);\n"
"box-shadow:0px 2px 15px 0px rgba(0,0,0,0.15);\n"
"border-radius:4px;\n"
"border:1px solid rgba(226,226,226,1);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(ZcloudLoginTip);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(95, 24, 180, 20));
        label_3->setStyleSheet(QLatin1String("font-size:20px;\n"
"font-family:PingFangSC-Regular,PingFang SC;\n"
"font-weight:400;\n"
"color:rgba(51,51,51,1);\n"
"line-height:20px;"));
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(ZcloudLoginTip);

        QMetaObject::connectSlotsByName(ZcloudLoginTip);
    } // setupUi

    void retranslateUi(QWidget *ZcloudLoginTip)
    {
        ZcloudLoginTip->setWindowTitle(QApplication::translate("ZcloudLoginTip", "Form", 0));
        okButton->setText(QApplication::translate("ZcloudLoginTip", "\347\253\213\345\210\273\347\231\273\351\231\206", 0));
        closeButton->setText(QApplication::translate("ZcloudLoginTip", "\346\232\202\344\270\215\347\231\273\351\231\206", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("ZcloudLoginTip", "\347\231\273\345\275\225\345\220\216\345\217\257\344\275\223\351\252\214\346\233\264\345\244\232\345\212\237\350\203\275", 0));
        label_3->setText(QApplication::translate("ZcloudLoginTip", "\346\254\242\350\277\216\344\275\277\347\224\250\344\272\221\350\264\242\347\250\216\345\271\263\345\217\260", 0));
    } // retranslateUi

};

namespace Ui {
    class ZcloudLoginTip: public Ui_ZcloudLoginTip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINTIP_H
