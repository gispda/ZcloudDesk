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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateEntInfoWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QComboBox *comboBoxArea;
    QLabel *labelAddressError;
    QLineEdit *lineEditSocietyCode;
    QLabel *label_4;
    QLabel *labelAreaError;
    QLineEdit *lineEditCompanyName;
    QPushButton *closeButton;
    QComboBox *comboBoxPro;
    QLabel *label_2;
    QLineEdit *lineEditAddress;
    QRadioButton *radioButtonAddressNew;
    QLabel *label;
    QRadioButton *radioButtonAddressReg;
    QLabel *label_10;
    QLabel *label_3;
    QPushButton *buttonSearch;
    QLabel *labelCompanyNotFound;
    QComboBox *comboBoxCity;
    QWidget *widgetAddressOffice;
    QComboBox *comboBoxProOffice;
    QLineEdit *lineEditAddressOffice;
    QLabel *labelAddressOfficeError;
    QComboBox *comboBoxAreaOffice;
    QLabel *labelAreaOfficeError;
    QComboBox *comboBoxCityOffice;
    QWidget *widget_2;
    QLineEdit *lineEditPhone;
    QLabel *label_11;
    QLabel *label_5;
    QLabel *labelPhoneError;
    QLabel *labelLegalPeasonError;
    QLineEdit *lineEditLegalPeasonName;
    QWidget *widget_3;
    QPushButton *buttonCancel;
    QPushButton *buttonOK;

    void setupUi(QWidget *CreateEntInfoWidget)
    {
        if (CreateEntInfoWidget->objectName().isEmpty())
            CreateEntInfoWidget->setObjectName(QStringLiteral("CreateEntInfoWidget"));
        CreateEntInfoWidget->resize(540, 650);
        CreateEntInfoWidget->setMinimumSize(QSize(539, 493));
        CreateEntInfoWidget->setMaximumSize(QSize(800, 900));
        verticalLayoutWidget = new QWidget(CreateEntInfoWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 541, 641));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(verticalLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(540, 320));
        comboBoxArea = new QComboBox(widget);
        comboBoxArea->setObjectName(QStringLiteral("comboBoxArea"));
        comboBoxArea->setGeometry(QRect(425, 180, 98, 40));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxArea->sizePolicy().hasHeightForWidth());
        comboBoxArea->setSizePolicy(sizePolicy);
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
        labelAddressError = new QLabel(widget);
        labelAddressError->setObjectName(QStringLiteral("labelAddressError"));
        labelAddressError->setGeometry(QRect(159, 280, 191, 15));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelAddressError->sizePolicy().hasHeightForWidth());
        labelAddressError->setSizePolicy(sizePolicy1);
        labelAddressError->setMinimumSize(QSize(0, 15));
        labelAddressError->setMaximumSize(QSize(16777215, 15));
        labelAddressError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        lineEditSocietyCode = new QLineEdit(widget);
        lineEditSocietyCode->setObjectName(QStringLiteral("lineEditSocietyCode"));
        lineEditSocietyCode->setGeometry(QRect(155, 125, 368, 40));
        sizePolicy.setHeightForWidth(lineEditSocietyCode->sizePolicy().hasHeightForWidth());
        lineEditSocietyCode->setSizePolicy(sizePolicy);
        lineEditSocietyCode->setMinimumSize(QSize(368, 40));
        lineEditSocietyCode->setMaximumSize(QSize(368, 40));
        lineEditSocietyCode->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditSocietyCode->setReadOnly(false);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(18, 290, 100, 30));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(56, 30));
        label_4->setMaximumSize(QSize(100, 30));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        labelAreaError = new QLabel(widget);
        labelAreaError->setObjectName(QStringLiteral("labelAreaError"));
        labelAreaError->setGeometry(QRect(159, 220, 131, 15));
        sizePolicy1.setHeightForWidth(labelAreaError->sizePolicy().hasHeightForWidth());
        labelAreaError->setSizePolicy(sizePolicy1);
        labelAreaError->setMinimumSize(QSize(0, 15));
        labelAreaError->setMaximumSize(QSize(16777215, 15));
        labelAreaError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        lineEditCompanyName = new QLineEdit(widget);
        lineEditCompanyName->setObjectName(QStringLiteral("lineEditCompanyName"));
        lineEditCompanyName->setGeometry(QRect(155, 60, 298, 40));
        sizePolicy.setHeightForWidth(lineEditCompanyName->sizePolicy().hasHeightForWidth());
        lineEditCompanyName->setSizePolicy(sizePolicy);
        lineEditCompanyName->setMinimumSize(QSize(260, 40));
        lineEditCompanyName->setMaximumSize(QSize(368, 40));
        lineEditCompanyName->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditCompanyName->setReadOnly(false);
        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(479, 5, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        comboBoxPro = new QComboBox(widget);
        comboBoxPro->setObjectName(QStringLiteral("comboBoxPro"));
        comboBoxPro->setGeometry(QRect(155, 180, 140, 40));
        sizePolicy.setHeightForWidth(comboBoxPro->sizePolicy().hasHeightForWidth());
        comboBoxPro->setSizePolicy(sizePolicy);
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
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(18, 65, 61, 30));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(56, 15));
        label_2->setMaximumSize(QSize(100, 30));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        lineEditAddress = new QLineEdit(widget);
        lineEditAddress->setObjectName(QStringLiteral("lineEditAddress"));
        lineEditAddress->setGeometry(QRect(155, 240, 368, 40));
        sizePolicy.setHeightForWidth(lineEditAddress->sizePolicy().hasHeightForWidth());
        lineEditAddress->setSizePolicy(sizePolicy);
        lineEditAddress->setMinimumSize(QSize(368, 40));
        lineEditAddress->setMaximumSize(QSize(368, 40));
        lineEditAddress->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditAddress->setMaxLength(100);
        radioButtonAddressNew = new QRadioButton(widget);
        radioButtonAddressNew->setObjectName(QStringLiteral("radioButtonAddressNew"));
        radioButtonAddressNew->setGeometry(QRect(351, 300, 151, 16));
        radioButtonAddressNew->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(18, 15, 91, 14));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(56, 14));
        label->setMaximumSize(QSize(100, 14));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        radioButtonAddressReg = new QRadioButton(widget);
        radioButtonAddressReg->setObjectName(QStringLiteral("radioButtonAddressReg"));
        radioButtonAddressReg->setGeometry(QRect(161, 300, 161, 16));
        radioButtonAddressReg->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        radioButtonAddressReg->setChecked(true);
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(18, 130, 120, 30));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(56, 30));
        label_10->setMaximumSize(QSize(120, 30));
        label_10->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(18, 185, 100, 30));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(56, 30));
        label_3->setMaximumSize(QSize(100, 30));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        buttonSearch = new QPushButton(widget);
        buttonSearch->setObjectName(QStringLiteral("buttonSearch"));
        buttonSearch->setGeometry(QRect(453, 60, 70, 40));
        sizePolicy.setHeightForWidth(buttonSearch->sizePolicy().hasHeightForWidth());
        buttonSearch->setSizePolicy(sizePolicy);
        buttonSearch->setMinimumSize(QSize(70, 32));
        buttonSearch->setMaximumSize(QSize(72, 40));
        buttonSearch->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        labelCompanyNotFound = new QLabel(widget);
        labelCompanyNotFound->setObjectName(QStringLiteral("labelCompanyNotFound"));
        labelCompanyNotFound->setGeometry(QRect(159, 100, 271, 15));
        sizePolicy1.setHeightForWidth(labelCompanyNotFound->sizePolicy().hasHeightForWidth());
        labelCompanyNotFound->setSizePolicy(sizePolicy1);
        labelCompanyNotFound->setMinimumSize(QSize(0, 15));
        labelCompanyNotFound->setMaximumSize(QSize(16777215, 15));
        labelCompanyNotFound->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        comboBoxCity = new QComboBox(widget);
        comboBoxCity->setObjectName(QStringLiteral("comboBoxCity"));
        comboBoxCity->setGeometry(QRect(300, 180, 120, 40));
        sizePolicy.setHeightForWidth(comboBoxCity->sizePolicy().hasHeightForWidth());
        comboBoxCity->setSizePolicy(sizePolicy);
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

        verticalLayout->addWidget(widget);

        widgetAddressOffice = new QWidget(verticalLayoutWidget);
        widgetAddressOffice->setObjectName(QStringLiteral("widgetAddressOffice"));
        widgetAddressOffice->setMaximumSize(QSize(540, 130));
        comboBoxProOffice = new QComboBox(widgetAddressOffice);
        comboBoxProOffice->setObjectName(QStringLiteral("comboBoxProOffice"));
        comboBoxProOffice->setGeometry(QRect(155, 10, 140, 40));
        sizePolicy.setHeightForWidth(comboBoxProOffice->sizePolicy().hasHeightForWidth());
        comboBoxProOffice->setSizePolicy(sizePolicy);
        comboBoxProOffice->setMinimumSize(QSize(140, 40));
        comboBoxProOffice->setMaximumSize(QSize(140, 40));
        comboBoxProOffice->setStyleSheet(QString::fromUtf8("QComboBox{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
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
        comboBoxProOffice->setEditable(true);
        lineEditAddressOffice = new QLineEdit(widgetAddressOffice);
        lineEditAddressOffice->setObjectName(QStringLiteral("lineEditAddressOffice"));
        lineEditAddressOffice->setGeometry(QRect(155, 70, 368, 40));
        sizePolicy.setHeightForWidth(lineEditAddressOffice->sizePolicy().hasHeightForWidth());
        lineEditAddressOffice->setSizePolicy(sizePolicy);
        lineEditAddressOffice->setMinimumSize(QSize(368, 40));
        lineEditAddressOffice->setMaximumSize(QSize(368, 40));
        lineEditAddressOffice->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditAddressOffice->setMaxLength(100);
        labelAddressOfficeError = new QLabel(widgetAddressOffice);
        labelAddressOfficeError->setObjectName(QStringLiteral("labelAddressOfficeError"));
        labelAddressOfficeError->setGeometry(QRect(159, 110, 191, 15));
        sizePolicy1.setHeightForWidth(labelAddressOfficeError->sizePolicy().hasHeightForWidth());
        labelAddressOfficeError->setSizePolicy(sizePolicy1);
        labelAddressOfficeError->setMinimumSize(QSize(0, 15));
        labelAddressOfficeError->setMaximumSize(QSize(16777215, 15));
        labelAddressOfficeError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        comboBoxAreaOffice = new QComboBox(widgetAddressOffice);
        comboBoxAreaOffice->setObjectName(QStringLiteral("comboBoxAreaOffice"));
        comboBoxAreaOffice->setGeometry(QRect(425, 10, 98, 40));
        sizePolicy.setHeightForWidth(comboBoxAreaOffice->sizePolicy().hasHeightForWidth());
        comboBoxAreaOffice->setSizePolicy(sizePolicy);
        comboBoxAreaOffice->setMinimumSize(QSize(98, 40));
        comboBoxAreaOffice->setMaximumSize(QSize(98, 40));
        comboBoxAreaOffice->setStyleSheet(QString::fromUtf8("QComboBox{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
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
        comboBoxAreaOffice->setEditable(true);
        labelAreaOfficeError = new QLabel(widgetAddressOffice);
        labelAreaOfficeError->setObjectName(QStringLiteral("labelAreaOfficeError"));
        labelAreaOfficeError->setGeometry(QRect(159, 50, 131, 15));
        sizePolicy1.setHeightForWidth(labelAreaOfficeError->sizePolicy().hasHeightForWidth());
        labelAreaOfficeError->setSizePolicy(sizePolicy1);
        labelAreaOfficeError->setMinimumSize(QSize(0, 15));
        labelAreaOfficeError->setMaximumSize(QSize(16777215, 15));
        labelAreaOfficeError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        comboBoxCityOffice = new QComboBox(widgetAddressOffice);
        comboBoxCityOffice->setObjectName(QStringLiteral("comboBoxCityOffice"));
        comboBoxCityOffice->setGeometry(QRect(300, 10, 120, 40));
        sizePolicy.setHeightForWidth(comboBoxCityOffice->sizePolicy().hasHeightForWidth());
        comboBoxCityOffice->setSizePolicy(sizePolicy);
        comboBoxCityOffice->setMinimumSize(QSize(120, 40));
        comboBoxCityOffice->setMaximumSize(QSize(120, 40));
        comboBoxCityOffice->setStyleSheet(QString::fromUtf8("QComboBox{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
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
        comboBoxCityOffice->setEditable(true);

        verticalLayout->addWidget(widgetAddressOffice);

        widget_2 = new QWidget(verticalLayoutWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(540, 130));
        lineEditPhone = new QLineEdit(widget_2);
        lineEditPhone->setObjectName(QStringLiteral("lineEditPhone"));
        lineEditPhone->setGeometry(QRect(160, 70, 368, 40));
        sizePolicy.setHeightForWidth(lineEditPhone->sizePolicy().hasHeightForWidth());
        lineEditPhone->setSizePolicy(sizePolicy);
        lineEditPhone->setMinimumSize(QSize(368, 40));
        lineEditPhone->setMaximumSize(QSize(368, 40));
        lineEditPhone->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditPhone->setMaxLength(11);
        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 75, 91, 30));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(56, 30));
        label_11->setMaximumSize(QSize(100, 30));
        label_11->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 15, 91, 30));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(56, 15));
        label_5->setMaximumSize(QSize(100, 30));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        labelPhoneError = new QLabel(widget_2);
        labelPhoneError->setObjectName(QStringLiteral("labelPhoneError"));
        labelPhoneError->setGeometry(QRect(162, 110, 141, 15));
        sizePolicy1.setHeightForWidth(labelPhoneError->sizePolicy().hasHeightForWidth());
        labelPhoneError->setSizePolicy(sizePolicy1);
        labelPhoneError->setMinimumSize(QSize(0, 15));
        labelPhoneError->setMaximumSize(QSize(16777215, 15));
        labelPhoneError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        labelLegalPeasonError = new QLabel(widget_2);
        labelLegalPeasonError->setObjectName(QStringLiteral("labelLegalPeasonError"));
        labelLegalPeasonError->setGeometry(QRect(162, 50, 131, 15));
        sizePolicy1.setHeightForWidth(labelLegalPeasonError->sizePolicy().hasHeightForWidth());
        labelLegalPeasonError->setSizePolicy(sizePolicy1);
        labelLegalPeasonError->setMinimumSize(QSize(0, 15));
        labelLegalPeasonError->setMaximumSize(QSize(16777215, 15));
        labelLegalPeasonError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        lineEditLegalPeasonName = new QLineEdit(widget_2);
        lineEditLegalPeasonName->setObjectName(QStringLiteral("lineEditLegalPeasonName"));
        lineEditLegalPeasonName->setGeometry(QRect(160, 10, 368, 40));
        sizePolicy.setHeightForWidth(lineEditLegalPeasonName->sizePolicy().hasHeightForWidth());
        lineEditLegalPeasonName->setSizePolicy(sizePolicy);
        lineEditLegalPeasonName->setMinimumSize(QSize(368, 40));
        lineEditLegalPeasonName->setMaximumSize(QSize(368, 40));
        lineEditLegalPeasonName->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditLegalPeasonName->setMaxLength(15);

        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(verticalLayoutWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(540, 60));
        buttonCancel = new QPushButton(widget_3);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setGeometry(QRect(280, 15, 72, 32));
        sizePolicy.setHeightForWidth(buttonCancel->sizePolicy().hasHeightForWidth());
        buttonCancel->setSizePolicy(sizePolicy);
        buttonCancel->setMinimumSize(QSize(72, 32));
        buttonCancel->setMaximumSize(QSize(72, 32));
        buttonCancel->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE;}\n"
"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        buttonOK = new QPushButton(widget_3);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));
        buttonOK->setGeometry(QRect(188, 15, 72, 32));
        sizePolicy.setHeightForWidth(buttonOK->sizePolicy().hasHeightForWidth());
        buttonOK->setSizePolicy(sizePolicy);
        buttonOK->setMinimumSize(QSize(72, 32));
        buttonOK->setMaximumSize(QSize(72, 32));
        buttonOK->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));

        verticalLayout->addWidget(widget_3);


        retranslateUi(CreateEntInfoWidget);

        QMetaObject::connectSlotsByName(CreateEntInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *CreateEntInfoWidget)
    {
        CreateEntInfoWidget->setWindowTitle(QApplication::translate("CreateEntInfoWidget", "Form", 0));
        labelAddressError->setText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\2455\357\275\236100\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
        lineEditSocietyCode->setText(QString());
        lineEditSocietyCode->setPlaceholderText(QString());
        label_4->setText(QApplication::translate("CreateEntInfoWidget", "<font color = red>*</font><font color =#333333>\344\274\201\344\270\232\345\212\236\345\205\254\345\234\260\345\235\200</font>", 0));
        labelAreaError->setText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\351\200\211\346\213\251\345\256\214\345\226\204\347\232\204\350\241\214\346\224\277\345\214\272\345\237\237", 0));
        lineEditCompanyName->setText(QString());
        lineEditCompanyName->setPlaceholderText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\245\345\256\214\346\225\264\347\232\204\345\205\254\345\217\270\345\220\215\347\247\260\345\220\216\347\202\271\345\207\273\346\237\245\350\257\242", 0));
        closeButton->setText(QString());
        label_2->setText(QApplication::translate("CreateEntInfoWidget", "<font color = red>*</font><font color =#333333>\345\205\254\345\217\270\345\220\215\347\247\260</font>", 0));
        lineEditAddress->setText(QString());
        lineEditAddress->setPlaceholderText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\245\350\241\227\351\201\223\343\200\201\346\245\274\347\211\214\345\217\267\347\255\211", 0));
        radioButtonAddressNew->setText(QApplication::translate("CreateEntInfoWidget", "\344\275\277\347\224\250\346\226\260\345\234\260\345\235\200", 0));
        label->setText(QApplication::translate("CreateEntInfoWidget", "\345\210\233\345\273\272\346\226\260\344\274\201\344\270\232", 0));
        radioButtonAddressReg->setText(QApplication::translate("CreateEntInfoWidget", "\344\275\277\347\224\250\344\274\201\344\270\232\346\263\250\345\206\214\345\234\260\345\235\200", 0));
        label_10->setText(QApplication::translate("CreateEntInfoWidget", "<font color = red>*</font><font color =#333333>\347\273\237\344\270\200\347\244\276\344\274\232\344\277\241\347\224\250\344\273\243\347\240\201</font>", 0));
        label_3->setText(QApplication::translate("CreateEntInfoWidget", "<font color = red>*</font><font color =#333333>\344\274\201\344\270\232\346\263\250\345\206\214\345\234\260\345\235\200</font>", 0));
        buttonSearch->setText(QApplication::translate("CreateEntInfoWidget", "\346\237\245\350\257\242", 0));
        labelCompanyNotFound->setText(QApplication::translate("CreateEntInfoWidget", "\346\234\252\346\237\245\350\257\242\345\210\260\350\257\245\345\205\254\345\217\270\357\274\214\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245", 0));
        lineEditAddressOffice->setText(QString());
        lineEditAddressOffice->setPlaceholderText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\245\350\241\227\351\201\223\343\200\201\346\245\274\347\211\214\345\217\267\347\255\211", 0));
        labelAddressOfficeError->setText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\2455\357\275\236100\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
        labelAreaOfficeError->setText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\351\200\211\346\213\251\345\256\214\345\226\204\347\232\204\350\241\214\346\224\277\345\214\272\345\237\237", 0));
        lineEditPhone->setText(QString());
        lineEditPhone->setPlaceholderText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\245\350\264\237\350\264\243\344\272\272\346\211\213\346\234\272\345\217\267", 0));
        label_11->setText(QApplication::translate("CreateEntInfoWidget", "<font color = red>*</font><font color =#333333>\350\264\237\350\264\243\344\272\272\346\211\213\346\234\272</font>", 0));
        label_5->setText(QApplication::translate("CreateEntInfoWidget", "<font color = red>*</font><font color =#333333>\344\274\201\344\270\232\350\264\237\350\264\243\344\272\272</font>", 0));
        labelPhoneError->setText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\24511\344\275\215\346\255\243\347\241\256\347\232\204\346\211\213\346\234\272\345\217\267", 0));
        labelLegalPeasonError->setText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\2452\357\275\23615\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
        lineEditLegalPeasonName->setText(QString());
        lineEditLegalPeasonName->setPlaceholderText(QApplication::translate("CreateEntInfoWidget", "\350\257\267\350\276\223\345\205\245\344\274\201\344\270\232\350\264\237\350\264\243\344\272\272\345\247\223\345\220\215", 0));
        buttonCancel->setText(QApplication::translate("CreateEntInfoWidget", "\345\217\226\346\266\210", 0));
        buttonOK->setText(QApplication::translate("CreateEntInfoWidget", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateEntInfoWidget: public Ui_CreateEntInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEENTINFOWIDGET_H
