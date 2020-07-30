/********************************************************************************
** Form generated from reading UI file 'EntInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTINFOWIDGET_H
#define UI_ENTINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EntInfoWidget
{
public:
    QWidget *TopWidget;
    QLabel *labelTitle;
    QPushButton *closeButton;
    QWidget *widgetInfo;
    QLabel *labelAvatar;
    QLabel *label;
    QLabel *labelTaxNo;
    QLabel *labelCompName;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *entWidget;
    QLabel *label_2;
    QLabel *labelIndustry;
    QLabel *label_3;
    QLabel *labelArea;
    QLabel *labelName;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *labelMobile;
    QLabel *label_13;
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
    QWidget *entEditWidget;
    QLabel *label_15;
    QLabel *label_16;
    QWidget *invoiceEditWidget;
    QLabel *label_17;
    QLabel *label_18;

    void setupUi(QWidget *EntInfoWidget)
    {
        if (EntInfoWidget->objectName().isEmpty())
            EntInfoWidget->setObjectName(QStringLiteral("EntInfoWidget"));
        EntInfoWidget->resize(800, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EntInfoWidget->sizePolicy().hasHeightForWidth());
        EntInfoWidget->setSizePolicy(sizePolicy);
        EntInfoWidget->setMinimumSize(QSize(800, 500));
        EntInfoWidget->setMaximumSize(QSize(800, 500));
        EntInfoWidget->setStyleSheet(QStringLiteral("QWidget#EntInfoWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        TopWidget = new QWidget(EntInfoWidget);
        TopWidget->setObjectName(QStringLiteral("TopWidget"));
        TopWidget->setGeometry(QRect(0, 0, 800, 52));
        sizePolicy.setHeightForWidth(TopWidget->sizePolicy().hasHeightForWidth());
        TopWidget->setSizePolicy(sizePolicy);
        TopWidget->setMinimumSize(QSize(800, 52));
        TopWidget->setMaximumSize(QSize(800, 52));
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
        widgetInfo = new QWidget(EntInfoWidget);
        widgetInfo->setObjectName(QStringLiteral("widgetInfo"));
        widgetInfo->setGeometry(QRect(0, 52, 800, 130));
        sizePolicy.setHeightForWidth(widgetInfo->sizePolicy().hasHeightForWidth());
        widgetInfo->setSizePolicy(sizePolicy);
        widgetInfo->setMinimumSize(QSize(800, 130));
        widgetInfo->setMaximumSize(QSize(800, 130));
        widgetInfo->setStyleSheet(QStringLiteral(""));
        labelAvatar = new QLabel(widgetInfo);
        labelAvatar->setObjectName(QStringLiteral("labelAvatar"));
        labelAvatar->setGeometry(QRect(30, 30, 90, 90));
        sizePolicy.setHeightForWidth(labelAvatar->sizePolicy().hasHeightForWidth());
        labelAvatar->setSizePolicy(sizePolicy);
        labelAvatar->setMinimumSize(QSize(90, 90));
        labelAvatar->setMaximumSize(QSize(90, 90));
        labelAvatar->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/img_tx_d.png);"));
        label = new QLabel(widgetInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(145, 80, 121, 14));
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
        labelTaxNo = new QLabel(widgetInfo);
        labelTaxNo->setObjectName(QStringLiteral("labelTaxNo"));
        labelTaxNo->setGeometry(QRect(265, 80, 301, 14));
        sizePolicy1.setHeightForWidth(labelTaxNo->sizePolicy().hasHeightForWidth());
        labelTaxNo->setSizePolicy(sizePolicy1);
        labelTaxNo->setMinimumSize(QSize(300, 14));
        labelTaxNo->setMaximumSize(QSize(16777215, 14));
        labelTaxNo->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelCompName = new QLabel(widgetInfo);
        labelCompName->setObjectName(QStringLiteral("labelCompName"));
        labelCompName->setGeometry(QRect(145, 44, 300, 18));
        sizePolicy1.setHeightForWidth(labelCompName->sizePolicy().hasHeightForWidth());
        labelCompName->setSizePolicy(sizePolicy1);
        labelCompName->setMinimumSize(QSize(300, 18));
        labelCompName->setMaximumSize(QSize(16777215, 18));
        labelCompName->setStyleSheet(QString::fromUtf8("font: 75 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        scrollArea = new QScrollArea(EntInfoWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 182, 800, 318));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(800, 318));
        scrollArea->setMaximumSize(QSize(800, 318));
        scrollArea->setStyleSheet(QStringLiteral("QWidget#scrollAreaWidgetContents{background-color: rgb(255, 255, 255);borde:0px;};"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 800, 318));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(140, 6, 65, 20));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(65, 20));
        label_9->setMaximumSize(QSize(65, 20));
        label_9->setStyleSheet(QString::fromUtf8("font:16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(214, 17, 556, 1));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(556, 1));
        label_11->setMaximumSize(QSize(556, 1));
        label_11->setStyleSheet(QStringLiteral("border:2px dashed rgba(222,222,222,1);"));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(720, 30, 54, 20));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setMinimumSize(QSize(0, 20));
        label_12->setMaximumSize(QSize(16777215, 20));
        label_12->setStyleSheet(QStringLiteral("text-top:1px;"));
        entWidget = new QWidget(scrollAreaWidgetContents);
        entWidget->setObjectName(QStringLiteral("entWidget"));
        entWidget->setGeometry(QRect(140, 40, 630, 110));
        sizePolicy.setHeightForWidth(entWidget->sizePolicy().hasHeightForWidth());
        entWidget->setSizePolicy(sizePolicy);
        entWidget->setMinimumSize(QSize(630, 110));
        entWidget->setMaximumSize(QSize(630, 110));
        label_2 = new QLabel(entWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 68, 16));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(68, 16));
        label_2->setMaximumSize(QSize(68, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelIndustry = new QLabel(entWidget);
        labelIndustry->setObjectName(QStringLiteral("labelIndustry"));
        labelIndustry->setGeometry(QRect(80, 10, 300, 16));
        sizePolicy1.setHeightForWidth(labelIndustry->sizePolicy().hasHeightForWidth());
        labelIndustry->setSizePolicy(sizePolicy1);
        labelIndustry->setMinimumSize(QSize(300, 16));
        labelIndustry->setMaximumSize(QSize(16777215, 16));
        labelIndustry->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_3 = new QLabel(entWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 45, 68, 16));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(68, 16));
        label_3->setMaximumSize(QSize(68, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelArea = new QLabel(entWidget);
        labelArea->setObjectName(QStringLiteral("labelArea"));
        labelArea->setGeometry(QRect(80, 45, 300, 16));
        sizePolicy1.setHeightForWidth(labelArea->sizePolicy().hasHeightForWidth());
        labelArea->setSizePolicy(sizePolicy1);
        labelArea->setMinimumSize(QSize(300, 16));
        labelArea->setMaximumSize(QSize(16777215, 16));
        labelArea->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelName = new QLabel(entWidget);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(90, 80, 220, 16));
        sizePolicy.setHeightForWidth(labelName->sizePolicy().hasHeightForWidth());
        labelName->setSizePolicy(sizePolicy);
        labelName->setMinimumSize(QSize(220, 16));
        labelName->setMaximumSize(QSize(220, 16));
        labelName->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_4 = new QLabel(entWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 80, 80, 16));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(80, 16));
        label_4->setMaximumSize(QSize(80, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_5 = new QLabel(entWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(320, 80, 92, 16));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(92, 16));
        label_5->setMaximumSize(QSize(92, 16));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelMobile = new QLabel(entWidget);
        labelMobile->setObjectName(QStringLiteral("labelMobile"));
        labelMobile->setGeometry(QRect(420, 80, 190, 16));
        sizePolicy.setHeightForWidth(labelMobile->sizePolicy().hasHeightForWidth());
        labelMobile->setSizePolicy(sizePolicy);
        labelMobile->setMinimumSize(QSize(190, 16));
        labelMobile->setMaximumSize(QSize(190, 16));
        labelMobile->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(214, 173, 556, 1));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setMinimumSize(QSize(556, 1));
        label_13->setMaximumSize(QSize(556, 1));
        label_13->setStyleSheet(QStringLiteral("border:2px dashed rgba(222,222,222,1);"));
        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(140, 162, 65, 20));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMinimumSize(QSize(65, 20));
        label_14->setMaximumSize(QSize(65, 20));
        label_14->setStyleSheet(QString::fromUtf8("font:16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        invoiceWidget = new QWidget(scrollAreaWidgetContents);
        invoiceWidget->setObjectName(QStringLiteral("invoiceWidget"));
        invoiceWidget->setGeometry(QRect(140, 200, 630, 105));
        sizePolicy.setHeightForWidth(invoiceWidget->sizePolicy().hasHeightForWidth());
        invoiceWidget->setSizePolicy(sizePolicy);
        invoiceWidget->setMinimumSize(QSize(630, 105));
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
        label_7->setGeometry(QRect(10, 45, 68, 16));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(68, 16));
        label_7->setMaximumSize(QSize(68, 16));
        label_7->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelPhone = new QLabel(invoiceWidget);
        labelPhone->setObjectName(QStringLiteral("labelPhone"));
        labelPhone->setGeometry(QRect(80, 45, 300, 16));
        sizePolicy1.setHeightForWidth(labelPhone->sizePolicy().hasHeightForWidth());
        labelPhone->setSizePolicy(sizePolicy1);
        labelPhone->setMinimumSize(QSize(300, 16));
        labelPhone->setMaximumSize(QSize(16777215, 16));
        labelPhone->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        labelAddr = new QLabel(invoiceWidget);
        labelAddr->setObjectName(QStringLiteral("labelAddr"));
        labelAddr->setGeometry(QRect(80, 80, 221, 16));
        sizePolicy1.setHeightForWidth(labelAddr->sizePolicy().hasHeightForWidth());
        labelAddr->setSizePolicy(sizePolicy1);
        labelAddr->setMinimumSize(QSize(220, 16));
        labelAddr->setMaximumSize(QSize(16777215, 16));
        labelAddr->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        label_8 = new QLabel(invoiceWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 80, 68, 16));
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
        labelBank->setGeometry(QRect(385, 10, 225, 16));
        sizePolicy.setHeightForWidth(labelBank->sizePolicy().hasHeightForWidth());
        labelBank->setSizePolicy(sizePolicy);
        labelBank->setMinimumSize(QSize(225, 16));
        labelBank->setMaximumSize(QSize(225, 16));
        labelBank->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102,102,102);\n"
"border-bottom:0px;"));
        entEditWidget = new QWidget(scrollAreaWidgetContents);
        entEditWidget->setObjectName(QStringLiteral("entEditWidget"));
        entEditWidget->setGeometry(QRect(710, 20, 70, 20));
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
        invoiceEditWidget = new QWidget(scrollAreaWidgetContents);
        invoiceEditWidget->setObjectName(QStringLiteral("invoiceEditWidget"));
        invoiceEditWidget->setGeometry(QRect(710, 178, 70, 20));
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
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(EntInfoWidget);

        QMetaObject::connectSlotsByName(EntInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *EntInfoWidget)
    {
        EntInfoWidget->setWindowTitle(QApplication::translate("EntInfoWidget", "EntInfoWidget", 0));
        labelTitle->setText(QApplication::translate("EntInfoWidget", "\344\274\201\344\270\232\350\265\204\346\226\231", 0));
        closeButton->setText(QString());
        labelAvatar->setText(QString());
        label->setText(QApplication::translate("EntInfoWidget", "\347\273\237\344\270\200\347\244\276\344\274\232\344\277\241\347\224\250\344\273\243\347\240\201\357\274\232", 0));
        labelTaxNo->setText(QString());
        labelCompName->setText(QString());
        label_9->setText(QApplication::translate("EntInfoWidget", "\344\274\201\344\270\232\350\265\204\346\226\231", 0));
        label_11->setText(QString());
        label_12->setText(QString());
        label_2->setText(QApplication::translate("EntInfoWidget", "\346\211\200\345\261\236\350\241\214\344\270\232\357\274\232", 0));
        labelIndustry->setText(QString());
        label_3->setText(QApplication::translate("EntInfoWidget", "\350\241\214\346\224\277\345\214\272\345\237\237\357\274\232", 0));
        labelArea->setText(QString());
        labelName->setText(QString());
        label_4->setText(QApplication::translate("EntInfoWidget", "\350\264\242\347\250\216\350\264\237\350\264\243\344\272\272\357\274\232", 0));
        label_5->setText(QApplication::translate("EntInfoWidget", "\350\264\237\350\264\243\344\272\272\346\211\213\346\234\272\345\217\267\357\274\232", 0));
        labelMobile->setText(QString());
        label_13->setText(QString());
        label_14->setText(QApplication::translate("EntInfoWidget", "\345\274\200\347\245\250\344\277\241\346\201\257", 0));
        label_6->setText(QApplication::translate("EntInfoWidget", "\345\274\200\346\210\267\350\264\246\345\217\267\357\274\232", 0));
        labelAcc->setText(QString());
        label_7->setText(QApplication::translate("EntInfoWidget", "\345\233\272\345\256\232\347\224\265\350\257\235\357\274\232", 0));
        labelPhone->setText(QString());
        labelAddr->setText(QString());
        label_8->setText(QApplication::translate("EntInfoWidget", "\350\257\246\347\273\206\345\234\260\345\235\200\357\274\232", 0));
        label_10->setText(QApplication::translate("EntInfoWidget", "\345\274\200\346\210\267\351\223\266\350\241\214\357\274\232", 0));
        labelBank->setText(QString());
        label_15->setText(QString());
        label_16->setText(QApplication::translate("EntInfoWidget", "\347\274\226\350\276\221", 0));
        label_17->setText(QString());
        label_18->setText(QApplication::translate("EntInfoWidget", "\347\274\226\350\276\221", 0));
    } // retranslateUi

};

namespace Ui {
    class EntInfoWidget: public Ui_EntInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTINFOWIDGET_H
