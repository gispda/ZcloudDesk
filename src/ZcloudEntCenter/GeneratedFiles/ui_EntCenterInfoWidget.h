/********************************************************************************
** Form generated from reading UI file 'EntCenterInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTCENTERINFOWIDGET_H
#define UI_ENTCENTERINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EntCenterInfoWidget
{
public:
    QLabel *label;
    QLabel *labelAvatar;
    QLabel *labelCompany;
    QLabel *labelTaxCode;
    QLabel *label_9;
    QWidget *invoiceEditWidget;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_12;
    QWidget *entEditWidget;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_11;
    QLabel *label_13;
    QWidget *entWidget;
    QLabel *label_3;
    QLabel *labelArea;
    QLabel *labelName;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *labelMobile;
    QLabel *label_14;
    QWidget *invoiceWidget;
    QLabel *label_6;
    QLabel *labelAcc;
    QLabel *label_7;
    QLabel *labelPhone;
    QLabel *labelAddr;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *labelBank;
    QLabel *label_19;

    void setupUi(QWidget *EntCenterInfoWidget)
    {
        if (EntCenterInfoWidget->objectName().isEmpty())
            EntCenterInfoWidget->setObjectName(QStringLiteral("EntCenterInfoWidget"));
        EntCenterInfoWidget->resize(750, 620);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EntCenterInfoWidget->sizePolicy().hasHeightForWidth());
        EntCenterInfoWidget->setSizePolicy(sizePolicy);
        EntCenterInfoWidget->setMinimumSize(QSize(750, 620));
        EntCenterInfoWidget->setMaximumSize(QSize(750, 620));
        EntCenterInfoWidget->setStyleSheet(QStringLiteral("QWidget#EntCenterInfoWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        label = new QLabel(EntCenterInfoWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 70, 121, 14));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 14));
        label->setMaximumSize(QSize(16777215, 14));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelAvatar = new QLabel(EntCenterInfoWidget);
        labelAvatar->setObjectName(QStringLiteral("labelAvatar"));
        labelAvatar->setGeometry(QRect(20, 20, 80, 80));
        sizePolicy.setHeightForWidth(labelAvatar->sizePolicy().hasHeightForWidth());
        labelAvatar->setSizePolicy(sizePolicy);
        labelAvatar->setMinimumSize(QSize(80, 80));
        labelAvatar->setMaximumSize(QSize(80, 80));
        labelAvatar->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/img_tx_d.png);"));
        labelCompany = new QLabel(EntCenterInfoWidget);
        labelCompany->setObjectName(QStringLiteral("labelCompany"));
        labelCompany->setGeometry(QRect(140, 30, 400, 20));
        sizePolicy1.setHeightForWidth(labelCompany->sizePolicy().hasHeightForWidth());
        labelCompany->setSizePolicy(sizePolicy1);
        labelCompany->setMinimumSize(QSize(0, 14));
        labelCompany->setMaximumSize(QSize(400, 20));
        labelCompany->setStyleSheet(QString::fromUtf8("font: 75 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelTaxCode = new QLabel(EntCenterInfoWidget);
        labelTaxCode->setObjectName(QStringLiteral("labelTaxCode"));
        labelTaxCode->setGeometry(QRect(280, 70, 400, 14));
        sizePolicy1.setHeightForWidth(labelTaxCode->sizePolicy().hasHeightForWidth());
        labelTaxCode->setSizePolicy(sizePolicy1);
        labelTaxCode->setMinimumSize(QSize(0, 14));
        labelTaxCode->setMaximumSize(QSize(400, 14));
        labelTaxCode->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_9 = new QLabel(EntCenterInfoWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(140, 108, 65, 20));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(65, 20));
        label_9->setMaximumSize(QSize(65, 20));
        label_9->setStyleSheet(QString::fromUtf8("font:16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        invoiceEditWidget = new QWidget(EntCenterInfoWidget);
        invoiceEditWidget->setObjectName(QStringLiteral("invoiceEditWidget"));
        invoiceEditWidget->setGeometry(QRect(660, 280, 70, 20));
        sizePolicy.setHeightForWidth(invoiceEditWidget->sizePolicy().hasHeightForWidth());
        invoiceEditWidget->setSizePolicy(sizePolicy);
        invoiceEditWidget->setMinimumSize(QSize(70, 20));
        invoiceEditWidget->setMaximumSize(QSize(70, 20));
        invoiceEditWidget->setCursor(QCursor(Qt::PointingHandCursor));
        label_17 = new QLabel(invoiceEditWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 3, 14, 14));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setMinimumSize(QSize(14, 14));
        label_17->setMaximumSize(QSize(14, 14));
        label_17->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/edit.png);"));
        label_18 = new QLabel(invoiceEditWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(28, 2, 30, 14));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setMinimumSize(QSize(30, 14));
        label_18->setMaximumSize(QSize(30, 14));
        label_18->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1E8BED;\n"
"border-bottom:0px;"));
        label_12 = new QLabel(EntCenterInfoWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(720, 132, 54, 20));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setMinimumSize(QSize(0, 20));
        label_12->setMaximumSize(QSize(16777215, 20));
        label_12->setStyleSheet(QStringLiteral("text-top:1px;"));
        entEditWidget = new QWidget(EntCenterInfoWidget);
        entEditWidget->setObjectName(QStringLiteral("entEditWidget"));
        entEditWidget->setGeometry(QRect(660, 122, 70, 20));
        sizePolicy.setHeightForWidth(entEditWidget->sizePolicy().hasHeightForWidth());
        entEditWidget->setSizePolicy(sizePolicy);
        entEditWidget->setMinimumSize(QSize(70, 20));
        entEditWidget->setMaximumSize(QSize(70, 20));
        entEditWidget->setCursor(QCursor(Qt::PointingHandCursor));
        label_15 = new QLabel(entEditWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 3, 14, 14));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setMinimumSize(QSize(14, 14));
        label_15->setMaximumSize(QSize(14, 14));
        label_15->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/edit.png);"));
        label_16 = new QLabel(entEditWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(28, 2, 30, 14));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);
        label_16->setMinimumSize(QSize(30, 14));
        label_16->setMaximumSize(QSize(30, 14));
        label_16->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1E8BED;\n"
"border-bottom:0px;"));
        label_11 = new QLabel(EntCenterInfoWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(214, 119, 500, 1));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(500, 1));
        label_11->setMaximumSize(QSize(600, 1));
        label_11->setStyleSheet(QStringLiteral("border:2px dashed rgba(222,222,222,1);"));
        label_13 = new QLabel(EntCenterInfoWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(214, 275, 500, 1));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setMinimumSize(QSize(500, 1));
        label_13->setMaximumSize(QSize(556, 1));
        label_13->setStyleSheet(QStringLiteral("border:2px dashed rgba(222,222,222,1);"));
        entWidget = new QWidget(EntCenterInfoWidget);
        entWidget->setObjectName(QStringLiteral("entWidget"));
        entWidget->setGeometry(QRect(140, 142, 600, 80));
        sizePolicy.setHeightForWidth(entWidget->sizePolicy().hasHeightForWidth());
        entWidget->setSizePolicy(sizePolicy);
        entWidget->setMinimumSize(QSize(600, 60));
        entWidget->setMaximumSize(QSize(630, 110));
        label_3 = new QLabel(entWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 68, 16));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(68, 16));
        label_3->setMaximumSize(QSize(68, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelArea = new QLabel(entWidget);
        labelArea->setObjectName(QStringLiteral("labelArea"));
        labelArea->setGeometry(QRect(80, 10, 500, 16));
        sizePolicy1.setHeightForWidth(labelArea->sizePolicy().hasHeightForWidth());
        labelArea->setSizePolicy(sizePolicy1);
        labelArea->setMinimumSize(QSize(300, 16));
        labelArea->setMaximumSize(QSize(16777215, 16));
        labelArea->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelName = new QLabel(entWidget);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(90, 45, 220, 16));
        sizePolicy.setHeightForWidth(labelName->sizePolicy().hasHeightForWidth());
        labelName->setSizePolicy(sizePolicy);
        labelName->setMinimumSize(QSize(220, 16));
        labelName->setMaximumSize(QSize(220, 16));
        labelName->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_4 = new QLabel(entWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 45, 80, 16));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(80, 16));
        label_4->setMaximumSize(QSize(80, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_5 = new QLabel(entWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(320, 45, 92, 16));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(92, 16));
        label_5->setMaximumSize(QSize(92, 16));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelMobile = new QLabel(entWidget);
        labelMobile->setObjectName(QStringLiteral("labelMobile"));
        labelMobile->setGeometry(QRect(420, 45, 180, 16));
        sizePolicy.setHeightForWidth(labelMobile->sizePolicy().hasHeightForWidth());
        labelMobile->setSizePolicy(sizePolicy);
        labelMobile->setMinimumSize(QSize(180, 16));
        labelMobile->setMaximumSize(QSize(180, 16));
        labelMobile->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_14 = new QLabel(EntCenterInfoWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(140, 264, 65, 20));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMinimumSize(QSize(65, 20));
        label_14->setMaximumSize(QSize(65, 20));
        label_14->setStyleSheet(QString::fromUtf8("font:16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        invoiceWidget = new QWidget(EntCenterInfoWidget);
        invoiceWidget->setObjectName(QStringLiteral("invoiceWidget"));
        invoiceWidget->setGeometry(QRect(140, 302, 600, 105));
        sizePolicy.setHeightForWidth(invoiceWidget->sizePolicy().hasHeightForWidth());
        invoiceWidget->setSizePolicy(sizePolicy);
        invoiceWidget->setMinimumSize(QSize(530, 105));
        invoiceWidget->setMaximumSize(QSize(630, 105));
        label_6 = new QLabel(invoiceWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 10, 68, 16));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(68, 16));
        label_6->setMaximumSize(QSize(68, 16));
        label_6->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelAcc = new QLabel(invoiceWidget);
        labelAcc->setObjectName(QStringLiteral("labelAcc"));
        labelAcc->setGeometry(QRect(80, 10, 220, 16));
        sizePolicy.setHeightForWidth(labelAcc->sizePolicy().hasHeightForWidth());
        labelAcc->setSizePolicy(sizePolicy);
        labelAcc->setMinimumSize(QSize(220, 16));
        labelAcc->setMaximumSize(QSize(220, 16));
        labelAcc->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_7 = new QLabel(invoiceWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 80, 68, 16));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(68, 16));
        label_7->setMaximumSize(QSize(68, 16));
        label_7->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelPhone = new QLabel(invoiceWidget);
        labelPhone->setObjectName(QStringLiteral("labelPhone"));
        labelPhone->setGeometry(QRect(80, 80, 300, 16));
        sizePolicy1.setHeightForWidth(labelPhone->sizePolicy().hasHeightForWidth());
        labelPhone->setSizePolicy(sizePolicy1);
        labelPhone->setMinimumSize(QSize(300, 16));
        labelPhone->setMaximumSize(QSize(16777215, 16));
        labelPhone->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelAddr = new QLabel(invoiceWidget);
        labelAddr->setObjectName(QStringLiteral("labelAddr"));
        labelAddr->setGeometry(QRect(80, 45, 500, 16));
        sizePolicy1.setHeightForWidth(labelAddr->sizePolicy().hasHeightForWidth());
        labelAddr->setSizePolicy(sizePolicy1);
        labelAddr->setMinimumSize(QSize(220, 16));
        labelAddr->setMaximumSize(QSize(16777215, 16));
        labelAddr->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_8 = new QLabel(invoiceWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 45, 68, 16));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(68, 16));
        label_8->setMaximumSize(QSize(68, 16));
        label_8->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_10 = new QLabel(invoiceWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(320, 10, 68, 16));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(68, 16));
        label_10->setMaximumSize(QSize(68, 16));
        label_10->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelBank = new QLabel(invoiceWidget);
        labelBank->setObjectName(QStringLiteral("labelBank"));
        labelBank->setGeometry(QRect(385, 10, 220, 16));
        sizePolicy.setHeightForWidth(labelBank->sizePolicy().hasHeightForWidth());
        labelBank->setSizePolicy(sizePolicy);
        labelBank->setMinimumSize(QSize(220, 16));
        labelBank->setMaximumSize(QSize(225, 16));
        labelBank->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_19 = new QLabel(invoiceWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 80, 68, 16));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setMinimumSize(QSize(68, 16));
        label_19->setMaximumSize(QSize(68, 16));
        label_19->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));

        retranslateUi(EntCenterInfoWidget);

        QMetaObject::connectSlotsByName(EntCenterInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *EntCenterInfoWidget)
    {
        EntCenterInfoWidget->setWindowTitle(QApplication::translate("EntCenterInfoWidget", "EntInfoWidget", 0));
        label->setText(QApplication::translate("EntCenterInfoWidget", "\347\273\237\344\270\200\347\244\276\344\274\232\344\277\241\347\224\250\344\273\243\347\240\201\357\274\232", 0));
        labelAvatar->setText(QString());
        labelCompany->setText(QApplication::translate("EntCenterInfoWidget", "\346\210\220\351\203\275\346\237\220\346\237\220\346\234\211\351\231\220\345\205\254\345\217\270", 0));
        labelTaxCode->setText(QApplication::translate("EntCenterInfoWidget", "90219734589359865E", 0));
        label_9->setText(QApplication::translate("EntCenterInfoWidget", "\344\274\201\344\270\232\350\265\204\346\226\231", 0));
        label_17->setText(QString());
        label_18->setText(QApplication::translate("EntCenterInfoWidget", "\347\274\226\350\276\221", 0));
        label_12->setText(QString());
        label_15->setText(QString());
        label_16->setText(QApplication::translate("EntCenterInfoWidget", "\347\274\226\350\276\221", 0));
        label_11->setText(QString());
        label_13->setText(QString());
        label_3->setText(QApplication::translate("EntCenterInfoWidget", "\346\263\250\345\206\214\345\234\260\345\235\200\357\274\232", 0));
        labelArea->setText(QString());
        labelName->setText(QString());
        label_4->setText(QApplication::translate("EntCenterInfoWidget", "\350\264\242\347\250\216\350\264\237\350\264\243\344\272\272\357\274\232", 0));
        label_5->setText(QApplication::translate("EntCenterInfoWidget", "\350\264\237\350\264\243\344\272\272\346\211\213\346\234\272\345\217\267\357\274\232", 0));
        labelMobile->setText(QString());
        label_14->setText(QApplication::translate("EntCenterInfoWidget", "\345\274\200\347\245\250\344\277\241\346\201\257", 0));
        label_6->setText(QApplication::translate("EntCenterInfoWidget", "\345\274\200\346\210\267\350\264\246\345\217\267\357\274\232", 0));
        labelAcc->setText(QString());
        label_7->setText(QString());
        labelPhone->setText(QString());
        labelAddr->setText(QString());
        label_8->setText(QApplication::translate("EntCenterInfoWidget", "\345\212\236\345\205\254\345\234\260\345\235\200\357\274\232", 0));
        label_10->setText(QApplication::translate("EntCenterInfoWidget", "\345\274\200\346\210\267\351\223\266\350\241\214\357\274\232", 0));
        labelBank->setText(QString());
        label_19->setText(QApplication::translate("EntCenterInfoWidget", "\345\233\272\345\256\232\347\224\265\350\257\235\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class EntCenterInfoWidget: public Ui_EntCenterInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTCENTERINFOWIDGET_H
