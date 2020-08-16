/********************************************************************************
** Form generated from reading UI file 'EditEntInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITENTINFOWIDGET_H
#define UI_EDITENTINFOWIDGET_H

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

class Ui_EditEntInfoWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QComboBox *comboBoxArea;
    QLineEdit *lineEditAddress;
    QLabel *label_10;
    QRadioButton *radioButtonAddressReg;
    QComboBox *comboBoxPro;
    QPushButton *closeButton;
    QLabel *label_3;
    QLabel *labelAddressError;
    QLabel *label;
    QComboBox *comboBoxCity;
    QLabel *labelAreaError;
    QRadioButton *radioButtonAddressNew;
    QWidget *widgetAddressOffice;
    QLabel *labelAddressOfficeError;
    QLabel *labelAreaOfficeError;
    QComboBox *comboBoxCityOffice;
    QComboBox *comboBoxProOffice;
    QComboBox *comboBoxAreaOffice;
    QLineEdit *lineEditOfficeOffice;
    QWidget *widget_3;
    QPushButton *cancelButton;
    QLabel *label_5;
    QLineEdit *lineEditLegalPeason;
    QPushButton *okButton;
    QLabel *labelLegalPeasonError;
    QLineEdit *lineEditPhone;
    QLabel *label_4;
    QLabel *labelPhoneError;
    QPushButton *nextbutton;

    void setupUi(QWidget *EditEntInfoWidget)
    {
        if (EditEntInfoWidget->objectName().isEmpty())
            EditEntInfoWidget->setObjectName(QStringLiteral("EditEntInfoWidget"));
        EditEntInfoWidget->resize(540, 517);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditEntInfoWidget->sizePolicy().hasHeightForWidth());
        EditEntInfoWidget->setSizePolicy(sizePolicy);
        EditEntInfoWidget->setMinimumSize(QSize(515, 382));
        EditEntInfoWidget->setMaximumSize(QSize(900, 900));
        EditEntInfoWidget->setStyleSheet(QStringLiteral("QWidget#EditEntInfoWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        verticalLayoutWidget = new QWidget(EditEntInfoWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 541, 521));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(verticalLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(540, 200));
        comboBoxArea = new QComboBox(widget);
        comboBoxArea->setObjectName(QStringLiteral("comboBoxArea"));
        comboBoxArea->setGeometry(QRect(430, 50, 98, 40));
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
        lineEditAddress = new QLineEdit(widget);
        lineEditAddress->setObjectName(QStringLiteral("lineEditAddress"));
        lineEditAddress->setGeometry(QRect(160, 110, 368, 40));
        sizePolicy.setHeightForWidth(lineEditAddress->sizePolicy().hasHeightForWidth());
        lineEditAddress->setSizePolicy(sizePolicy);
        lineEditAddress->setMinimumSize(QSize(368, 40));
        lineEditAddress->setMaximumSize(QSize(368, 40));
        lineEditAddress->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 170, 100, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(56, 30));
        label_10->setMaximumSize(QSize(100, 30));
        label_10->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        radioButtonAddressReg = new QRadioButton(widget);
        radioButtonAddressReg->setObjectName(QStringLiteral("radioButtonAddressReg"));
        radioButtonAddressReg->setGeometry(QRect(180, 180, 151, 16));
        radioButtonAddressReg->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        radioButtonAddressReg->setChecked(true);
        comboBoxPro = new QComboBox(widget);
        comboBoxPro->setObjectName(QStringLiteral("comboBoxPro"));
        comboBoxPro->setGeometry(QRect(160, 50, 140, 40));
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
        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(490, 5, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 55, 100, 30));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(56, 30));
        label_3->setMaximumSize(QSize(100, 30));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        labelAddressError = new QLabel(widget);
        labelAddressError->setObjectName(QStringLiteral("labelAddressError"));
        labelAddressError->setGeometry(QRect(165, 150, 131, 15));
        sizePolicy1.setHeightForWidth(labelAddressError->sizePolicy().hasHeightForWidth());
        labelAddressError->setSizePolicy(sizePolicy1);
        labelAddressError->setMinimumSize(QSize(0, 15));
        labelAddressError->setMaximumSize(QSize(16777215, 15));
        labelAddressError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 15, 91, 14));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(56, 14));
        label->setMaximumSize(QSize(100, 14));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        comboBoxCity = new QComboBox(widget);
        comboBoxCity->setObjectName(QStringLiteral("comboBoxCity"));
        comboBoxCity->setGeometry(QRect(305, 50, 120, 40));
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
        labelAreaError = new QLabel(widget);
        labelAreaError->setObjectName(QStringLiteral("labelAreaError"));
        labelAreaError->setGeometry(QRect(165, 90, 131, 15));
        sizePolicy1.setHeightForWidth(labelAreaError->sizePolicy().hasHeightForWidth());
        labelAreaError->setSizePolicy(sizePolicy1);
        labelAreaError->setMinimumSize(QSize(0, 15));
        labelAreaError->setMaximumSize(QSize(16777215, 15));
        labelAreaError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        radioButtonAddressNew = new QRadioButton(widget);
        radioButtonAddressNew->setObjectName(QStringLiteral("radioButtonAddressNew"));
        radioButtonAddressNew->setGeometry(QRect(360, 180, 131, 16));
        radioButtonAddressNew->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));

        verticalLayout->addWidget(widget);

        widgetAddressOffice = new QWidget(verticalLayoutWidget);
        widgetAddressOffice->setObjectName(QStringLiteral("widgetAddressOffice"));
        widgetAddressOffice->setMaximumSize(QSize(540, 130));
        labelAddressOfficeError = new QLabel(widgetAddressOffice);
        labelAddressOfficeError->setObjectName(QStringLiteral("labelAddressOfficeError"));
        labelAddressOfficeError->setGeometry(QRect(165, 110, 131, 15));
        sizePolicy1.setHeightForWidth(labelAddressOfficeError->sizePolicy().hasHeightForWidth());
        labelAddressOfficeError->setSizePolicy(sizePolicy1);
        labelAddressOfficeError->setMinimumSize(QSize(0, 15));
        labelAddressOfficeError->setMaximumSize(QSize(16777215, 15));
        labelAddressOfficeError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        labelAreaOfficeError = new QLabel(widgetAddressOffice);
        labelAreaOfficeError->setObjectName(QStringLiteral("labelAreaOfficeError"));
        labelAreaOfficeError->setGeometry(QRect(165, 50, 131, 15));
        sizePolicy1.setHeightForWidth(labelAreaOfficeError->sizePolicy().hasHeightForWidth());
        labelAreaOfficeError->setSizePolicy(sizePolicy1);
        labelAreaOfficeError->setMinimumSize(QSize(0, 15));
        labelAreaOfficeError->setMaximumSize(QSize(16777215, 15));
        labelAreaOfficeError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        comboBoxCityOffice = new QComboBox(widgetAddressOffice);
        comboBoxCityOffice->setObjectName(QStringLiteral("comboBoxCityOffice"));
        comboBoxCityOffice->setGeometry(QRect(305, 10, 120, 40));
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
        comboBoxProOffice = new QComboBox(widgetAddressOffice);
        comboBoxProOffice->setObjectName(QStringLiteral("comboBoxProOffice"));
        comboBoxProOffice->setGeometry(QRect(160, 10, 140, 40));
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
        comboBoxAreaOffice = new QComboBox(widgetAddressOffice);
        comboBoxAreaOffice->setObjectName(QStringLiteral("comboBoxAreaOffice"));
        comboBoxAreaOffice->setGeometry(QRect(430, 10, 98, 40));
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
        lineEditOfficeOffice = new QLineEdit(widgetAddressOffice);
        lineEditOfficeOffice->setObjectName(QStringLiteral("lineEditOfficeOffice"));
        lineEditOfficeOffice->setGeometry(QRect(160, 70, 368, 40));
        sizePolicy.setHeightForWidth(lineEditOfficeOffice->sizePolicy().hasHeightForWidth());
        lineEditOfficeOffice->setSizePolicy(sizePolicy);
        lineEditOfficeOffice->setMinimumSize(QSize(368, 40));
        lineEditOfficeOffice->setMaximumSize(QSize(368, 40));
        lineEditOfficeOffice->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));

        verticalLayout->addWidget(widgetAddressOffice);

        widget_3 = new QWidget(verticalLayoutWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(540, 180));
        cancelButton = new QPushButton(widget_3);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(300, 140, 72, 32));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        cancelButton->setMinimumSize(QSize(72, 32));
        cancelButton->setMaximumSize(QSize(72, 32));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE;}\n"
"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(28, 83, 91, 15));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(56, 15));
        label_5->setMaximumSize(QSize(100, 15));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        lineEditLegalPeason = new QLineEdit(widget_3);
        lineEditLegalPeason->setObjectName(QStringLiteral("lineEditLegalPeason"));
        lineEditLegalPeason->setGeometry(QRect(158, 10, 368, 40));
        sizePolicy.setHeightForWidth(lineEditLegalPeason->sizePolicy().hasHeightForWidth());
        lineEditLegalPeason->setSizePolicy(sizePolicy);
        lineEditLegalPeason->setMinimumSize(QSize(368, 40));
        lineEditLegalPeason->setMaximumSize(QSize(368, 40));
        lineEditLegalPeason->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        okButton = new QPushButton(widget_3);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(208, 140, 72, 32));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setMinimumSize(QSize(72, 32));
        okButton->setMaximumSize(QSize(72, 32));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        labelLegalPeasonError = new QLabel(widget_3);
        labelLegalPeasonError->setObjectName(QStringLiteral("labelLegalPeasonError"));
        labelLegalPeasonError->setGeometry(QRect(163, 50, 131, 15));
        sizePolicy1.setHeightForWidth(labelLegalPeasonError->sizePolicy().hasHeightForWidth());
        labelLegalPeasonError->setSizePolicy(sizePolicy1);
        labelLegalPeasonError->setMinimumSize(QSize(0, 15));
        labelLegalPeasonError->setMaximumSize(QSize(16777215, 15));
        labelLegalPeasonError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        lineEditPhone = new QLineEdit(widget_3);
        lineEditPhone->setObjectName(QStringLiteral("lineEditPhone"));
        lineEditPhone->setGeometry(QRect(158, 70, 368, 40));
        sizePolicy.setHeightForWidth(lineEditPhone->sizePolicy().hasHeightForWidth());
        lineEditPhone->setSizePolicy(sizePolicy);
        lineEditPhone->setMinimumSize(QSize(368, 40));
        lineEditPhone->setMaximumSize(QSize(368, 40));
        lineEditPhone->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(28, 23, 72, 16));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(56, 16));
        label_4->setMaximumSize(QSize(100, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        labelPhoneError = new QLabel(widget_3);
        labelPhoneError->setObjectName(QStringLiteral("labelPhoneError"));
        labelPhoneError->setGeometry(QRect(163, 110, 141, 15));
        sizePolicy1.setHeightForWidth(labelPhoneError->sizePolicy().hasHeightForWidth());
        labelPhoneError->setSizePolicy(sizePolicy1);
        labelPhoneError->setMinimumSize(QSize(0, 15));
        labelPhoneError->setMaximumSize(QSize(16777215, 15));
        labelPhoneError->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        nextbutton = new QPushButton(widget_3);
        nextbutton->setObjectName(QStringLiteral("nextbutton"));
        nextbutton->setGeometry(QRect(210, 140, 72, 32));
        sizePolicy.setHeightForWidth(nextbutton->sizePolicy().hasHeightForWidth());
        nextbutton->setSizePolicy(sizePolicy);
        nextbutton->setMinimumSize(QSize(72, 32));
        nextbutton->setMaximumSize(QSize(72, 32));
        nextbutton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));

        verticalLayout->addWidget(widget_3);


        retranslateUi(EditEntInfoWidget);

        QMetaObject::connectSlotsByName(EditEntInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *EditEntInfoWidget)
    {
        EditEntInfoWidget->setWindowTitle(QApplication::translate("EditEntInfoWidget", "EditEntInfoWidget", 0));
        lineEditAddress->setText(QString());
        lineEditAddress->setPlaceholderText(QApplication::translate("EditEntInfoWidget", "\350\257\267\350\276\223\345\205\245\350\241\227\351\201\223\343\200\201\346\245\274\347\211\214\345\217\267\347\255\211", 0));
        label_10->setText(QApplication::translate("EditEntInfoWidget", "<font color = red>*</font><font color =#333333>\344\274\201\344\270\232\345\212\236\345\205\254\345\234\260\345\235\200</font>", 0));
        radioButtonAddressReg->setText(QApplication::translate("EditEntInfoWidget", "\344\275\277\347\224\250\344\274\201\344\270\232\346\263\250\345\206\214\345\234\260\345\235\200", 0));
        closeButton->setText(QString());
        label_3->setText(QApplication::translate("EditEntInfoWidget", "<font color = red>*</font><font color =#333333>\344\274\201\344\270\232\346\263\250\345\206\214\345\234\260\345\235\200</font>", 0));
        labelAddressError->setText(QApplication::translate("EditEntInfoWidget", "\350\257\267\350\276\223\345\205\2455\357\275\236100\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
        label->setText(QApplication::translate("EditEntInfoWidget", "\347\274\226\350\276\221\344\274\201\344\270\232\350\265\204\346\226\231", 0));
        labelAreaError->setText(QApplication::translate("EditEntInfoWidget", "\350\257\267\351\200\211\346\213\251\345\256\214\345\226\204\347\232\204\350\241\214\346\224\277\345\214\272\345\237\237", 0));
        radioButtonAddressNew->setText(QApplication::translate("EditEntInfoWidget", "\344\275\277\347\224\250\346\226\260\345\234\260\345\235\200", 0));
        labelAddressOfficeError->setText(QApplication::translate("EditEntInfoWidget", "\350\257\267\351\200\211\346\213\251\345\256\214\345\226\204\347\232\204\350\241\214\346\224\277\345\214\272\345\237\237", 0));
        labelAreaOfficeError->setText(QApplication::translate("EditEntInfoWidget", "\350\257\267\351\200\211\346\213\251\345\256\214\345\226\204\347\232\204\350\241\214\346\224\277\345\214\272\345\237\237", 0));
        lineEditOfficeOffice->setText(QString());
        lineEditOfficeOffice->setPlaceholderText(QApplication::translate("EditEntInfoWidget", "\350\257\267\350\276\223\345\205\245\350\241\227\351\201\223\343\200\201\346\245\274\347\211\214\345\217\267\347\255\211", 0));
        cancelButton->setText(QApplication::translate("EditEntInfoWidget", "\345\217\226\346\266\210", 0));
        label_5->setText(QApplication::translate("EditEntInfoWidget", "\350\264\237\350\264\243\344\272\272\346\211\213\346\234\272\345\217\267", 0));
        lineEditLegalPeason->setText(QString());
        lineEditLegalPeason->setPlaceholderText(QApplication::translate("EditEntInfoWidget", "\350\257\267\350\276\223\345\205\245\350\264\242\347\250\216\350\264\237\350\264\243\344\272\272\345\247\223\345\220\215", 0));
        okButton->setText(QApplication::translate("EditEntInfoWidget", "\347\241\256\345\256\232", 0));
        labelLegalPeasonError->setText(QApplication::translate("EditEntInfoWidget", "\350\257\267\350\276\223\345\205\2452\357\275\23620\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
        lineEditPhone->setText(QString());
        lineEditPhone->setPlaceholderText(QApplication::translate("EditEntInfoWidget", "\350\257\267\350\276\223\345\205\245\350\264\237\350\264\243\344\272\272\346\211\213\346\234\272\345\217\267", 0));
        label_4->setText(QApplication::translate("EditEntInfoWidget", "\344\274\201\344\270\232\350\264\237\350\264\243\344\272\272", 0));
        labelPhoneError->setText(QApplication::translate("EditEntInfoWidget", "\350\257\267\350\276\223\345\205\24511\344\275\215\346\255\243\347\241\256\347\232\204\346\211\213\346\234\272\345\217\267", 0));
        nextbutton->setText(QApplication::translate("EditEntInfoWidget", "\344\270\213\344\270\200\346\255\245", 0));
    } // retranslateUi

};

namespace Ui {
    class EditEntInfoWidget: public Ui_EditEntInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITENTINFOWIDGET_H
