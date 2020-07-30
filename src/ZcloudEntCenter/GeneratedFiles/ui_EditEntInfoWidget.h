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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditEntInfoWidget
{
public:
    QPushButton *closeButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBoxTrade;
    QLineEdit *lineEditOffice;
    QLineEdit *lineEditPhone;
    QPushButton *cancelButton;
    QPushButton *okButton;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *comboBoxPro;
    QComboBox *comboBoxCity;
    QComboBox *comboBoxArea;
    QLabel *label_8;

    void setupUi(QWidget *EditEntInfoWidget)
    {
        if (EditEntInfoWidget->objectName().isEmpty())
            EditEntInfoWidget->setObjectName(QStringLiteral("EditEntInfoWidget"));
        EditEntInfoWidget->resize(515, 382);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditEntInfoWidget->sizePolicy().hasHeightForWidth());
        EditEntInfoWidget->setSizePolicy(sizePolicy);
        EditEntInfoWidget->setMinimumSize(QSize(515, 382));
        EditEntInfoWidget->setMaximumSize(QSize(515, 382));
        EditEntInfoWidget->setStyleSheet(QStringLiteral("QWidget#EditEntInfoWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        closeButton = new QPushButton(EditEntInfoWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(480, 5, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label = new QLabel(EditEntInfoWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 15, 91, 14));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(56, 14));
        label->setMaximumSize(QSize(100, 14));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_2 = new QLabel(EditEntInfoWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 72, 61, 15));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(56, 15));
        label_2->setMaximumSize(QSize(100, 15));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_3 = new QLabel(EditEntInfoWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 125, 71, 30));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(56, 30));
        label_3->setMaximumSize(QSize(100, 30));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_4 = new QLabel(EditEntInfoWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 193, 72, 16));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(56, 16));
        label_4->setMaximumSize(QSize(100, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_5 = new QLabel(EditEntInfoWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 253, 91, 15));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(56, 15));
        label_5->setMaximumSize(QSize(100, 15));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        comboBoxTrade = new QComboBox(EditEntInfoWidget);
        comboBoxTrade->setObjectName(QStringLiteral("comboBoxTrade"));
        comboBoxTrade->setGeometry(QRect(116, 60, 368, 40));
        sizePolicy.setHeightForWidth(comboBoxTrade->sizePolicy().hasHeightForWidth());
        comboBoxTrade->setSizePolicy(sizePolicy);
        comboBoxTrade->setMinimumSize(QSize(368, 40));
        comboBoxTrade->setMaximumSize(QSize(368, 40));
        comboBoxTrade->setStyleSheet(QString::fromUtf8("QComboBox{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
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
        comboBoxTrade->setEditable(true);
        lineEditOffice = new QLineEdit(EditEntInfoWidget);
        lineEditOffice->setObjectName(QStringLiteral("lineEditOffice"));
        lineEditOffice->setGeometry(QRect(116, 180, 368, 40));
        sizePolicy.setHeightForWidth(lineEditOffice->sizePolicy().hasHeightForWidth());
        lineEditOffice->setSizePolicy(sizePolicy);
        lineEditOffice->setMinimumSize(QSize(368, 40));
        lineEditOffice->setMaximumSize(QSize(368, 40));
        lineEditOffice->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditPhone = new QLineEdit(EditEntInfoWidget);
        lineEditPhone->setObjectName(QStringLiteral("lineEditPhone"));
        lineEditPhone->setGeometry(QRect(116, 240, 368, 40));
        sizePolicy.setHeightForWidth(lineEditPhone->sizePolicy().hasHeightForWidth());
        lineEditPhone->setSizePolicy(sizePolicy);
        lineEditPhone->setMinimumSize(QSize(368, 40));
        lineEditPhone->setMaximumSize(QSize(368, 40));
        lineEditPhone->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        cancelButton = new QPushButton(EditEntInfoWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(269, 310, 72, 32));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        cancelButton->setMinimumSize(QSize(72, 32));
        cancelButton->setMaximumSize(QSize(72, 32));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE;}\n"
"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        okButton = new QPushButton(EditEntInfoWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(177, 310, 72, 32));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setMinimumSize(QSize(72, 32));
        okButton->setMaximumSize(QSize(72, 32));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        label_6 = new QLabel(EditEntInfoWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 220, 131, 15));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(0, 15));
        label_6->setMaximumSize(QSize(16777215, 15));
        label_6->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_7 = new QLabel(EditEntInfoWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 280, 141, 15));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(0, 15));
        label_7->setMaximumSize(QSize(16777215, 15));
        label_7->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        comboBoxPro = new QComboBox(EditEntInfoWidget);
        comboBoxPro->setObjectName(QStringLiteral("comboBoxPro"));
        comboBoxPro->setGeometry(QRect(116, 120, 140, 40));
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
        comboBoxCity = new QComboBox(EditEntInfoWidget);
        comboBoxCity->setObjectName(QStringLiteral("comboBoxCity"));
        comboBoxCity->setGeometry(QRect(261, 120, 120, 40));
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
        comboBoxArea = new QComboBox(EditEntInfoWidget);
        comboBoxArea->setObjectName(QStringLiteral("comboBoxArea"));
        comboBoxArea->setGeometry(QRect(385, 120, 98, 40));
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
        label_8 = new QLabel(EditEntInfoWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(120, 160, 131, 15));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(0, 15));
        label_8->setMaximumSize(QSize(16777215, 15));
        label_8->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));

        retranslateUi(EditEntInfoWidget);

        QMetaObject::connectSlotsByName(EditEntInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *EditEntInfoWidget)
    {
        EditEntInfoWidget->setWindowTitle(QApplication::translate("EditEntInfoWidget", "EditEntInfoWidget", 0));
        closeButton->setText(QString());
        label->setText(QApplication::translate("EditEntInfoWidget", "\347\274\226\350\276\221\344\274\201\344\270\232\350\265\204\346\226\231", 0));
        label_2->setText(QApplication::translate("EditEntInfoWidget", "\346\211\200\345\261\236\350\241\214\344\270\232", 0));
        label_3->setText(QApplication::translate("EditEntInfoWidget", "<font color = red>*</font><font color =#333333>\350\241\214\346\224\277\345\214\272\345\237\237</font>", 0));
        label_4->setText(QApplication::translate("EditEntInfoWidget", "\350\264\242\347\250\216\350\264\237\350\264\243\344\272\272", 0));
        label_5->setText(QApplication::translate("EditEntInfoWidget", "\350\264\237\350\264\243\344\272\272\346\211\213\346\234\272\345\217\267", 0));
        comboBoxTrade->setCurrentText(QString());
        lineEditOffice->setText(QString());
        lineEditOffice->setPlaceholderText(QApplication::translate("EditEntInfoWidget", "\350\257\267\350\276\223\345\205\245\350\264\242\347\250\216\350\264\237\350\264\243\344\272\272\345\247\223\345\220\215", 0));
        lineEditPhone->setText(QString());
        lineEditPhone->setPlaceholderText(QApplication::translate("EditEntInfoWidget", "\350\257\267\350\276\223\345\205\245\350\264\237\350\264\243\344\272\272\346\211\213\346\234\272\345\217\267", 0));
        cancelButton->setText(QApplication::translate("EditEntInfoWidget", "\345\217\226\346\266\210", 0));
        okButton->setText(QApplication::translate("EditEntInfoWidget", "\347\241\256\345\256\232", 0));
        label_6->setText(QApplication::translate("EditEntInfoWidget", "\350\257\267\350\276\223\345\205\2452\357\275\23620\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
        label_7->setText(QApplication::translate("EditEntInfoWidget", "\350\257\267\350\276\223\345\205\24511\344\275\215\346\255\243\347\241\256\347\232\204\346\211\213\346\234\272\345\217\267", 0));
        label_8->setText(QApplication::translate("EditEntInfoWidget", "\350\257\267\351\200\211\346\213\251\345\256\214\345\226\204\347\232\204\350\241\214\346\224\277\345\214\272\345\237\237", 0));
    } // retranslateUi

};

namespace Ui {
    class EditEntInfoWidget: public Ui_EditEntInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITENTINFOWIDGET_H
