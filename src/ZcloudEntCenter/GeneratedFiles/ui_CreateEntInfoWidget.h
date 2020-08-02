/********************************************************************************
** Form generated from reading UI file 'CreateEntInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEENTINFOWIDGET_H
#define UI_CREATEENTINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateEntInfoWidget
{
public:
    QLabel *labelCompanyNotFound;
    QComboBox *comboBoxArea;
    QLineEdit *lineEditPhone;
    QLabel *labelPhoneError;
    QPushButton *closeButton;
    QLabel *label;
    QLabel *label_11;
    QComboBox *comboBoxCity;
    QLabel *labelLegalPeasonError;
    QComboBox *comboBoxPro;
    QLabel *label_5;
    QLineEdit *lineEditCompanyName;
    QLabel *label_2;
    QLineEdit *lineEditAddress;
    QLabel *label_10;
    QPushButton *buttonOK;
    QLineEdit *lineEditLegalPeasonName;
    QLabel *label_4;
    QPushButton *buttonSearch;
    QLineEdit *lineEditSocietyCode;
    QLabel *labelAddressError;
    QLabel *labelAreaError;
    QLabel *label_3;
    QPushButton *buttonCancel;

    void setupUi(QWidget *CreateEntInfoWidget)
    {
        if (CreateEntInfoWidget->objectName().isEmpty())
            CreateEntInfoWidget->setObjectName(QStringLiteral("CreateEntInfoWidget"));
        CreateEntInfoWidget->resize(539, 493);
        CreateEntInfoWidget->setMinimumSize(QSize(539, 493));
        CreateEntInfoWidget->setMaximumSize(QSize(539, 493));
        labelCompanyNotFound = new QLabel(CreateEntInfoWidget);
        labelCompanyNotFound->setObjectName(QStringLiteral("labelCompanyNotFound"));
        labelCompanyNotFound->setGeometry(QRect(158, 110, 131, 15));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelCompanyNotFound->sizePolicy().hasHeightForWidth());
        labelCompanyNotFound->setSizePolicy(sizePolicy);
        labelCompanyNotFound->setMinimumSize(QSize(0, 15));
        labelCompanyNotFound->setMaximumSize(QSize(16777215, 15));
        labelCompanyNotFound->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        comboBoxArea = new QComboBox(CreateEntInfoWidget);
        comboBoxArea->setObjectName(QStringLiteral("comboBoxArea"));
        comboBoxArea->setGeometry(QRect(424, 190, 98, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxArea->sizePolicy().hasHeightForWidth());
        comboBoxArea->setSizePolicy(sizePolicy1);
        comboBoxArea->setMinimumSize(QSize(98, 40));
        comboBoxArea->setMaximumSize(QSize(98, 40));
        comboBoxArea->setStyleSheet(QString::fromUtf8("QComboBox{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"\n"
"QComboBox:focus{border:1px solid rgba(30,140,238,1);}\n"
"\n"
"QComboBox::drop-down{subcontrol-origin:padding;subcontrol-position:top right;width:32px;border-radius:4px;}\n"
"\n"
"QComboBox:down-arrow{image:url(:/ZcloudDesk/image/comboBoxDownArrow.png);}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"	border-radius:0px;\n"
"	border: 1px solid rgb(161,161,161);\n"
"	outline: 0px;	\n"
"}\n"
"QComboBox QAbstractItemView::item \n"
"{\n"
"	font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    height:32px;\n"
"}"));
        comboBoxArea->setEditable(true);
        lineEditPhone = new QLineEdit(CreateEntInfoWidget);
        lineEditPhone->setObjectName(QStringLiteral("lineEditPhone"));
        lineEditPhone->setGeometry(QRect(154, 370, 368, 40));
        sizePolicy1.setHeightForWidth(lineEditPhone->sizePolicy().hasHeightForWidth());
        lineEditPhone->setSizePolicy(sizePolicy1);
        lineEditPhone->setMinimumSize(QSize(368, 40));
        lineEditPhone->setMaximumSize(QSize(368, 40));
        lineEditPhone->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditPhone->setMaxLength(11);
        labelPhoneError = new QLabel(CreateEntInfoWidget);
        labelPhoneError->setObjectName(QStringLiteral("labelPhoneError"));
        labelPhoneError->setGeometry(QRect(158, 410, 141, 15));
        sizePolicy.setHeightForWidth(labelPhoneError->sizePolicy().hasHeightForWidth());
        labelPhoneError->setSizePolicy(sizePolicy);
        labelPhoneError->setMinimumSize(QSize(0, 15));
        labelPhoneError->setMaximumSize(QSize(16777215, 15));
        labelPhoneError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        closeButton = new QPushButton(CreateEntInfoWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(478, 15, 32, 28));
        sizePolicy1.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy1);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label = new QLabel(CreateEntInfoWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(18, 25, 91, 14));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(56, 14));
        label->setMaximumSize(QSize(100, 14));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_11 = new QLabel(CreateEntInfoWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(18, 375, 91, 30));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(56, 30));
        label_11->setMaximumSize(QSize(100, 30));
        label_11->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        comboBoxCity = new QComboBox(CreateEntInfoWidget);
        comboBoxCity->setObjectName(QStringLiteral("comboBoxCity"));
        comboBoxCity->setGeometry(QRect(299, 190, 120, 40));
        sizePolicy1.setHeightForWidth(comboBoxCity->sizePolicy().hasHeightForWidth());
        comboBoxCity->setSizePolicy(sizePolicy1);
        comboBoxCity->setMinimumSize(QSize(120, 40));
        comboBoxCity->setMaximumSize(QSize(120, 40));
        comboBoxCity->setStyleSheet(QString::fromUtf8("QComboBox{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"\n"
"QComboBox:focus{border:1px solid rgba(30,140,238,1);}\n"
"\n"
"QComboBox::drop-down{subcontrol-origin:padding;subcontrol-position:top right;width:32px;border-radius:4px;}\n"
"\n"
"QComboBox:down-arrow{image:url(:/ZcloudDesk/image/comboBoxDownArrow.png);}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"	border-radius:0px;\n"
"	border: 1px solid rgb(161,161,161);\n"
"	outline: 0px;	\n"
"}\n"
"QComboBox QAbstractItemView::item \n"
"{\n"
"	font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    height:32px;\n"
"}"));
        comboBoxCity->setEditable(true);
        labelLegalPeasonError = new QLabel(CreateEntInfoWidget);
        labelLegalPeasonError->setObjectName(QStringLiteral("labelLegalPeasonError"));
        labelLegalPeasonError->setGeometry(QRect(158, 350, 131, 15));
        sizePolicy.setHeightForWidth(labelLegalPeasonError->sizePolicy().hasHeightForWidth());
        labelLegalPeasonError->setSizePolicy(sizePolicy);
        labelLegalPeasonError->setMinimumSize(QSize(0, 15));
        labelLegalPeasonError->setMaximumSize(QSize(16777215, 15));
        labelLegalPeasonError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        comboBoxPro = new QComboBox(CreateEntInfoWidget);
        comboBoxPro->setObjectName(QStringLiteral("comboBoxPro"));
        comboBoxPro->setGeometry(QRect(154, 190, 140, 40));
        sizePolicy1.setHeightForWidth(comboBoxPro->sizePolicy().hasHeightForWidth());
        comboBoxPro->setSizePolicy(sizePolicy1);
        comboBoxPro->setMinimumSize(QSize(140, 40));
        comboBoxPro->setMaximumSize(QSize(140, 40));
        comboBoxPro->setStyleSheet(QString::fromUtf8("QComboBox{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"\n"
"QComboBox:focus{border:1px solid rgba(30,140,238,1);}\n"
"\n"
"QComboBox::drop-down{subcontrol-origin:padding;subcontrol-position:top right;width:32px;border-radius:4px;}\n"
"\n"
"QComboBox:down-arrow{image:url(:/ZcloudDesk/image/comboBoxDownArrow.png);}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"	border-radius:0px;\n"
"	border: 1px solid rgb(161,161,161);\n"
"	outline: 0px;	\n"
"}\n"
"QComboBox QAbstractItemView::item \n"
"{\n"
"	font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    height:32px;\n"
"}"));
        comboBoxPro->setEditable(true);
        label_5 = new QLabel(CreateEntInfoWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(18, 315, 91, 30));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(56, 15));
        label_5->setMaximumSize(QSize(100, 30));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        lineEditCompanyName = new QLineEdit(CreateEntInfoWidget);
        lineEditCompanyName->setObjectName(QStringLiteral("lineEditCompanyName"));
        lineEditCompanyName->setGeometry(QRect(154, 70, 298, 40));
        sizePolicy1.setHeightForWidth(lineEditCompanyName->sizePolicy().hasHeightForWidth());
        lineEditCompanyName->setSizePolicy(sizePolicy1);
        lineEditCompanyName->setMinimumSize(QSize(260, 40));
        lineEditCompanyName->setMaximumSize(QSize(368, 40));
        lineEditCompanyName->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditCompanyName->setReadOnly(false);
        label_2 = new QLabel(CreateEntInfoWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(18, 75, 61, 30));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(56, 15));
        label_2->setMaximumSize(QSize(100, 30));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        lineEditAddress = new QLineEdit(CreateEntInfoWidget);
        lineEditAddress->setObjectName(QStringLiteral("lineEditAddress"));
        lineEditAddress->setGeometry(QRect(154, 250, 368, 40));
        sizePolicy1.setHeightForWidth(lineEditAddress->sizePolicy().hasHeightForWidth());
        lineEditAddress->setSizePolicy(sizePolicy1);
        lineEditAddress->setMinimumSize(QSize(368, 40));
        lineEditAddress->setMaximumSize(QSize(368, 40));
        lineEditAddress->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditAddress->setMaxLength(100);
        label_10 = new QLabel(CreateEntInfoWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(18, 140, 120, 30));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(56, 30));
        label_10->setMaximumSize(QSize(120, 30));
        label_10->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        buttonOK = new QPushButton(CreateEntInfoWidget);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));
        buttonOK->setGeometry(QRect(218, 450, 72, 32));
        sizePolicy1.setHeightForWidth(buttonOK->sizePolicy().hasHeightForWidth());
        buttonOK->setSizePolicy(sizePolicy1);
        buttonOK->setMinimumSize(QSize(72, 32));
        buttonOK->setMaximumSize(QSize(72, 32));
        buttonOK->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        lineEditLegalPeasonName = new QLineEdit(CreateEntInfoWidget);
        lineEditLegalPeasonName->setObjectName(QStringLiteral("lineEditLegalPeasonName"));
        lineEditLegalPeasonName->setGeometry(QRect(154, 310, 368, 40));
        sizePolicy1.setHeightForWidth(lineEditLegalPeasonName->sizePolicy().hasHeightForWidth());
        lineEditLegalPeasonName->setSizePolicy(sizePolicy1);
        lineEditLegalPeasonName->setMinimumSize(QSize(368, 40));
        lineEditLegalPeasonName->setMaximumSize(QSize(368, 40));
        lineEditLegalPeasonName->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditLegalPeasonName->setMaxLength(15);
        label_4 = new QLabel(CreateEntInfoWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(18, 255, 72, 30));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(56, 16));
        label_4->setMaximumSize(QSize(100, 30));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        buttonSearch = new QPushButton(CreateEntInfoWidget);
        buttonSearch->setObjectName(QStringLiteral("buttonSearch"));
        buttonSearch->setGeometry(QRect(452, 70, 70, 40));
        sizePolicy1.setHeightForWidth(buttonSearch->sizePolicy().hasHeightForWidth());
        buttonSearch->setSizePolicy(sizePolicy1);
        buttonSearch->setMinimumSize(QSize(70, 32));
        buttonSearch->setMaximumSize(QSize(72, 40));
        buttonSearch->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        lineEditSocietyCode = new QLineEdit(CreateEntInfoWidget);
        lineEditSocietyCode->setObjectName(QStringLiteral("lineEditSocietyCode"));
        lineEditSocietyCode->setGeometry(QRect(154, 135, 368, 40));
        sizePolicy1.setHeightForWidth(lineEditSocietyCode->sizePolicy().hasHeightForWidth());
        lineEditSocietyCode->setSizePolicy(sizePolicy1);
        lineEditSocietyCode->setMinimumSize(QSize(368, 40));
        lineEditSocietyCode->setMaximumSize(QSize(368, 40));
        lineEditSocietyCode->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditSocietyCode->setReadOnly(true);
        labelAddressError = new QLabel(CreateEntInfoWidget);
        labelAddressError->setObjectName(QStringLiteral("labelAddressError"));
        labelAddressError->setGeometry(QRect(158, 290, 131, 15));
        sizePolicy.setHeightForWidth(labelAddressError->sizePolicy().hasHeightForWidth());
        labelAddressError->setSizePolicy(sizePolicy);
        labelAddressError->setMinimumSize(QSize(0, 15));
        labelAddressError->setMaximumSize(QSize(16777215, 15));
        labelAddressError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        labelAreaError = new QLabel(CreateEntInfoWidget);
        labelAreaError->setObjectName(QStringLiteral("labelAreaError"));
        labelAreaError->setGeometry(QRect(158, 230, 131, 15));
        sizePolicy.setHeightForWidth(labelAreaError->sizePolicy().hasHeightForWidth());
        labelAreaError->setSizePolicy(sizePolicy);
        labelAreaError->setMinimumSize(QSize(0, 15));
        labelAreaError->setMaximumSize(QSize(16777215, 15));
        labelAreaError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_3 = new QLabel(CreateEntInfoWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(18, 195, 71, 30));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(56, 30));
        label_3->setMaximumSize(QSize(100, 30));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        buttonCancel = new QPushButton(CreateEntInfoWidget);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setGeometry(QRect(310, 450, 72, 32));
        sizePolicy1.setHeightForWidth(buttonCancel->sizePolicy().hasHeightForWidth());
        buttonCancel->setSizePolicy(sizePolicy1);
        buttonCancel->setMinimumSize(QSize(72, 32));
        buttonCancel->setMaximumSize(QSize(72, 32));
        buttonCancel->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE;}\n"
"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));

        retranslateUi(CreateEntInfoWidget);

        QMetaObject::connectSlotsByName(CreateEntInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *CreateEntInfoWidget)
    {
        CreateEntInfoWidget->setWindowTitle(QApplication::translate("CreateEntInfoWidget", "Form", 0));
        labelCompanyNotFound->setText(QApplication::translate("CreateEntInfoWidget", "\346\234\252\346\237\245\350\257\242\345\210\260\350\257\245\345\205\254\345\217\270\357\274\214\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245", 0));
        lineEditPhone->setText(QString());
        lineEditPhone->setPlaceholderText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\245\350\264\237\350\264\243\344\272\272\346\211\213\346\234\272\345\217\267", 0));
        labelPhoneError->setText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\24511\344\275\215\346\255\243\347\241\256\347\232\204\346\211\213\346\234\272\345\217\267", 0));
        closeButton->setText(QString());
        label->setText(QApplication::translate("CreateEntInfoWidget", "\345\210\233\345\273\272\346\226\260\344\274\201\344\270\232", 0));
        label_11->setText(QApplication::translate("CreateEntInfoWidget", "<font color = red>*</font><font color =#333333>\350\264\237\350\264\243\344\272\272\346\211\213\346\234\272</font>", 0));
        labelLegalPeasonError->setText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\2452\357\275\23615\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
        label_5->setText(QApplication::translate("CreateEntInfoWidget", "<font color = red>*</font><font color =#333333>\344\274\201\344\270\232\350\264\237\350\264\243\344\272\272</font>", 0));
        lineEditCompanyName->setText(QString());
        lineEditCompanyName->setPlaceholderText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\245\345\256\214\346\225\264\347\232\204\345\205\254\345\217\270\345\220\215\347\247\260\345\220\216\347\202\271\345\207\273\346\237\245\350\257\242", 0));
        label_2->setText(QApplication::translate("CreateEntInfoWidget", "<font color = red>*</font><font color =#333333>\345\205\254\345\217\270\345\220\215\347\247\260</font>", 0));
        lineEditAddress->setText(QString());
        lineEditAddress->setPlaceholderText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\245\350\241\227\351\201\223\343\200\201\346\245\274\347\211\214\345\217\267\347\255\211", 0));
        label_10->setText(QApplication::translate("CreateEntInfoWidget", "<font color = red>*</font><font color =#333333>\347\273\237\344\270\200\347\244\276\344\274\232\344\277\241\347\224\250\344\273\243\347\240\201</font>", 0));
        buttonOK->setText(QApplication::translate("CreateEntInfoWidget", "\347\241\256\345\256\232", 0));
        lineEditLegalPeasonName->setText(QString());
        lineEditLegalPeasonName->setPlaceholderText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\245\344\274\201\344\270\232\350\264\237\350\264\243\344\272\272\345\247\223\345\220\215", 0));
        label_4->setText(QApplication::translate("CreateEntInfoWidget", "<font color = red>*</font><font color =#333333>\350\257\246\347\273\206\345\234\260\345\235\200</font>", 0));
        buttonSearch->setText(QApplication::translate("CreateEntInfoWidget", "\346\237\245\350\257\242", 0));
        lineEditSocietyCode->setText(QString());
        lineEditSocietyCode->setPlaceholderText(QString());
        labelAddressError->setText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\2455\357\275\236100\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
        labelAreaError->setText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\351\200\211\346\213\251\345\256\214\345\226\204\347\232\204\350\241\214\346\224\277\345\214\272\345\237\237", 0));
        label_3->setText(QApplication::translate("CreateEntInfoWidget", "<font color = red>*</font><font color =#333333>\346\211\200\345\234\250\345\234\260\345\214\272</font>", 0));
        buttonCancel->setText(QApplication::translate("CreateEntInfoWidget", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateEntInfoWidget: public Ui_CreateEntInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEENTINFOWIDGET_H
