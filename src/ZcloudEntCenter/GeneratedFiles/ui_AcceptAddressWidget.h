/********************************************************************************
** Form generated from reading UI file 'AcceptAddressWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCEPTADDRESSWIDGET_H
#define UI_ACCEPTADDRESSWIDGET_H

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
#include "CommentTextEdit.h"

QT_BEGIN_NAMESPACE

class Ui_AcceptAddressWidget
{
public:
    QPushButton *closeButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QLineEdit *lineEditMobile;
    QLabel *label_3;
    QComboBox *comboBoxArea;
    QComboBox *comboBoxPro;
    QComboBox *comboBoxCity;
    QLabel *label_4;
    CommentTextEdit *textEditAddr;
    QLabel *label_5;
    QPushButton *cancelButton;
    QPushButton *okButton;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QWidget *AcceptAddressWidget)
    {
        if (AcceptAddressWidget->objectName().isEmpty())
            AcceptAddressWidget->setObjectName(QStringLiteral("AcceptAddressWidget"));
        AcceptAddressWidget->resize(515, 423);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AcceptAddressWidget->sizePolicy().hasHeightForWidth());
        AcceptAddressWidget->setSizePolicy(sizePolicy);
        AcceptAddressWidget->setMinimumSize(QSize(515, 423));
        AcceptAddressWidget->setMaximumSize(QSize(515, 423));
        AcceptAddressWidget->setStyleSheet(QStringLiteral("QWidget#AcceptAddressWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        closeButton = new QPushButton(AcceptAddressWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(480, 5, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label = new QLabel(AcceptAddressWidget);
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
        label_2 = new QLabel(AcceptAddressWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 65, 56, 30));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(56, 30));
        label_2->setMaximumSize(QSize(100, 30));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        lineEditName = new QLineEdit(AcceptAddressWidget);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(110, 60, 368, 40));
        sizePolicy.setHeightForWidth(lineEditName->sizePolicy().hasHeightForWidth());
        lineEditName->setSizePolicy(sizePolicy);
        lineEditName->setMinimumSize(QSize(368, 40));
        lineEditName->setMaximumSize(QSize(368, 40));
        lineEditName->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditMobile = new QLineEdit(AcceptAddressWidget);
        lineEditMobile->setObjectName(QStringLiteral("lineEditMobile"));
        lineEditMobile->setGeometry(QRect(110, 120, 368, 40));
        sizePolicy.setHeightForWidth(lineEditMobile->sizePolicy().hasHeightForWidth());
        lineEditMobile->setSizePolicy(sizePolicy);
        lineEditMobile->setMinimumSize(QSize(368, 40));
        lineEditMobile->setMaximumSize(QSize(368, 40));
        lineEditMobile->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        label_3 = new QLabel(AcceptAddressWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 126, 56, 30));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(56, 30));
        label_3->setMaximumSize(QSize(100, 30));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        comboBoxArea = new QComboBox(AcceptAddressWidget);
        comboBoxArea->setObjectName(QStringLiteral("comboBoxArea"));
        comboBoxArea->setGeometry(QRect(380, 180, 98, 40));
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
        comboBoxPro = new QComboBox(AcceptAddressWidget);
        comboBoxPro->setObjectName(QStringLiteral("comboBoxPro"));
        comboBoxPro->setGeometry(QRect(111, 180, 140, 40));
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
        comboBoxCity = new QComboBox(AcceptAddressWidget);
        comboBoxCity->setObjectName(QStringLiteral("comboBoxCity"));
        comboBoxCity->setGeometry(QRect(256, 180, 120, 40));
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
        label_4 = new QLabel(AcceptAddressWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 187, 71, 30));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(60, 30));
        label_4->setMaximumSize(QSize(100, 30));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        textEditAddr = new CommentTextEdit(AcceptAddressWidget);
        textEditAddr->setObjectName(QStringLiteral("textEditAddr"));
        textEditAddr->setGeometry(QRect(110, 240, 368, 80));
        sizePolicy.setHeightForWidth(textEditAddr->sizePolicy().hasHeightForWidth());
        textEditAddr->setSizePolicy(sizePolicy);
        textEditAddr->setMinimumSize(QSize(368, 80));
        textEditAddr->setMaximumSize(QSize(368, 80));
        textEditAddr->setStyleSheet(QLatin1String("QTextEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QTextEdit:laceholder{color:rgba(51,51,51,1);}QTextEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QTextEdit:disabled{background-color: rgb(247,248, 250);}\n"
"QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"));
        textEditAddr->setFrameShape(QFrame::StyledPanel);
        label_5 = new QLabel(AcceptAddressWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 263, 71, 30));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(56, 30));
        label_5->setMaximumSize(QSize(100, 30));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        cancelButton = new QPushButton(AcceptAddressWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(269, 350, 72, 32));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        cancelButton->setMinimumSize(QSize(72, 32));
        cancelButton->setMaximumSize(QSize(72, 32));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE;}\n"
"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        okButton = new QPushButton(AcceptAddressWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(177, 350, 72, 32));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setMinimumSize(QSize(72, 32));
        okButton->setMaximumSize(QSize(72, 32));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        label_6 = new QLabel(AcceptAddressWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(110, 100, 131, 15));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(0, 15));
        label_6->setMaximumSize(QSize(16777215, 15));
        label_6->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_7 = new QLabel(AcceptAddressWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(110, 160, 141, 15));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(0, 15));
        label_7->setMaximumSize(QSize(16777215, 15));
        label_7->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_8 = new QLabel(AcceptAddressWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(110, 220, 131, 15));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(0, 15));
        label_8->setMaximumSize(QSize(16777215, 15));
        label_8->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_9 = new QLabel(AcceptAddressWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(110, 320, 131, 15));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(0, 15));
        label_9->setMaximumSize(QSize(16777215, 15));
        label_9->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));

        retranslateUi(AcceptAddressWidget);

        QMetaObject::connectSlotsByName(AcceptAddressWidget);
    } // setupUi

    void retranslateUi(QWidget *AcceptAddressWidget)
    {
        AcceptAddressWidget->setWindowTitle(QApplication::translate("AcceptAddressWidget", "AcceptAddressWidget", 0));
        closeButton->setText(QString());
        label->setText(QApplication::translate("AcceptAddressWidget", "\346\224\266\350\264\247\345\234\260\345\235\200", 0));
        label_2->setText(QApplication::translate("AcceptAddressWidget", "<font color = red>*</font><font color =#333333>\345\247\223\345\220\215</font>", 0));
        lineEditName->setText(QString());
        lineEditName->setPlaceholderText(QApplication::translate("AcceptAddressWidget", "\350\257\267\350\276\223\345\205\245\347\234\237\345\256\236\345\247\223\345\220\215", 0));
        lineEditMobile->setText(QString());
        lineEditMobile->setPlaceholderText(QApplication::translate("AcceptAddressWidget", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267", 0));
        label_3->setText(QApplication::translate("AcceptAddressWidget", "<font color = red>*</font><font color =#333333>\346\211\213\346\234\272\345\217\267</font>", 0));
        label_4->setText(QApplication::translate("AcceptAddressWidget", "<font color = red>*</font><font color =#333333>\346\211\200\345\234\250\345\234\260\345\214\272</font>", 0));
        textEditAddr->setPlaceholderText(QApplication::translate("AcceptAddressWidget", "\350\257\267\350\276\223\345\205\245\346\224\266\350\264\247\350\257\246\347\273\206\345\234\260\345\235\200", 0));
        label_5->setText(QApplication::translate("AcceptAddressWidget", "<font color = red>*</font><font color =#333333>\350\257\246\347\273\206\345\234\260\345\235\200</font>", 0));
        cancelButton->setText(QApplication::translate("AcceptAddressWidget", "\345\217\226\346\266\210", 0));
        okButton->setText(QApplication::translate("AcceptAddressWidget", "\347\241\256\345\256\232", 0));
        label_6->setText(QApplication::translate("AcceptAddressWidget", "\350\257\267\350\276\223\345\205\2452\357\275\23620\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
        label_7->setText(QApplication::translate("AcceptAddressWidget", "\350\257\267\350\276\223\345\205\24511\344\275\215\346\255\243\347\241\256\347\232\204\346\211\213\346\234\272\345\217\267", 0));
        label_8->setText(QApplication::translate("AcceptAddressWidget", "\350\257\267\351\200\211\346\213\251\346\211\200\345\234\250\345\234\260\345\214\272", 0));
        label_9->setText(QApplication::translate("AcceptAddressWidget", "\350\257\267\350\276\223\345\205\245\346\234\200\345\244\232200\344\270\252\345\255\227\347\254\246", 0));
    } // retranslateUi

};

namespace Ui {
    class AcceptAddressWidget: public Ui_AcceptAddressWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCEPTADDRESSWIDGET_H
