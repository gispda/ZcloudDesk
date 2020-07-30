/********************************************************************************
** Form generated from reading UI file 'EditInvoiceInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITINVOICEINFOWIDGET_H
#define UI_EDITINVOICEINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "CommentTextEdit.h"

QT_BEGIN_NAMESPACE

class Ui_EditInvoiceInfoWidget
{
public:
    QPushButton *closeButton;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditAcc;
    QLineEdit *lineEditBank;
    QLineEdit *lineEditTelNo;
    CommentTextEdit *textEditAddr;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QWidget *EditInvoiceInfoWidget)
    {
        if (EditInvoiceInfoWidget->objectName().isEmpty())
            EditInvoiceInfoWidget->setObjectName(QStringLiteral("EditInvoiceInfoWidget"));
        EditInvoiceInfoWidget->resize(454, 423);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditInvoiceInfoWidget->sizePolicy().hasHeightForWidth());
        EditInvoiceInfoWidget->setSizePolicy(sizePolicy);
        EditInvoiceInfoWidget->setMinimumSize(QSize(454, 423));
        EditInvoiceInfoWidget->setMaximumSize(QSize(454, 423));
        EditInvoiceInfoWidget->setStyleSheet(QStringLiteral("QWidget#EditInvoiceInfoWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        closeButton = new QPushButton(EditInvoiceInfoWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(415, 10, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label = new QLabel(EditInvoiceInfoWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 19, 91, 14));
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
        label_5 = new QLabel(EditInvoiceInfoWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(51, 263, 56, 14));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(56, 14));
        label_5->setMaximumSize(QSize(100, 14));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_4 = new QLabel(EditInvoiceInfoWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(51, 204, 56, 14));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(56, 14));
        label_4->setMaximumSize(QSize(100, 14));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_2 = new QLabel(EditInvoiceInfoWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(51, 82, 61, 14));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(56, 14));
        label_2->setMaximumSize(QSize(100, 14));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_3 = new QLabel(EditInvoiceInfoWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(51, 143, 61, 14));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(56, 14));
        label_3->setMaximumSize(QSize(100, 14));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        lineEditAcc = new QLineEdit(EditInvoiceInfoWidget);
        lineEditAcc->setObjectName(QStringLiteral("lineEditAcc"));
        lineEditAcc->setGeometry(QRect(126, 70, 268, 40));
        sizePolicy.setHeightForWidth(lineEditAcc->sizePolicy().hasHeightForWidth());
        lineEditAcc->setSizePolicy(sizePolicy);
        lineEditAcc->setMinimumSize(QSize(268, 40));
        lineEditAcc->setMaximumSize(QSize(268, 40));
        lineEditAcc->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditBank = new QLineEdit(EditInvoiceInfoWidget);
        lineEditBank->setObjectName(QStringLiteral("lineEditBank"));
        lineEditBank->setGeometry(QRect(126, 131, 268, 40));
        sizePolicy.setHeightForWidth(lineEditBank->sizePolicy().hasHeightForWidth());
        lineEditBank->setSizePolicy(sizePolicy);
        lineEditBank->setMinimumSize(QSize(268, 40));
        lineEditBank->setMaximumSize(QSize(268, 40));
        lineEditBank->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditTelNo = new QLineEdit(EditInvoiceInfoWidget);
        lineEditTelNo->setObjectName(QStringLiteral("lineEditTelNo"));
        lineEditTelNo->setGeometry(QRect(126, 191, 268, 40));
        sizePolicy.setHeightForWidth(lineEditTelNo->sizePolicy().hasHeightForWidth());
        lineEditTelNo->setSizePolicy(sizePolicy);
        lineEditTelNo->setMinimumSize(QSize(268, 40));
        lineEditTelNo->setMaximumSize(QSize(268, 40));
        lineEditTelNo->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        textEditAddr = new CommentTextEdit(EditInvoiceInfoWidget);
        textEditAddr->setObjectName(QStringLiteral("textEditAddr"));
        textEditAddr->setGeometry(QRect(126, 251, 268, 80));
        sizePolicy.setHeightForWidth(textEditAddr->sizePolicy().hasHeightForWidth());
        textEditAddr->setSizePolicy(sizePolicy);
        textEditAddr->setMinimumSize(QSize(268, 80));
        textEditAddr->setMaximumSize(QSize(268, 80));
        textEditAddr->setStyleSheet(QLatin1String("QTextEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QTextEdit:laceholder{color:rgba(51,51,51,1);}QTextEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QTextEdit:disabled{background-color: rgb(247,248, 250);}\n"
"QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"));
        textEditAddr->setFrameShape(QFrame::StyledPanel);
        okButton = new QPushButton(EditInvoiceInfoWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(127, 360, 72, 32));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setMinimumSize(QSize(72, 32));
        okButton->setMaximumSize(QSize(72, 32));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        cancelButton = new QPushButton(EditInvoiceInfoWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(219, 360, 72, 32));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        cancelButton->setMinimumSize(QSize(72, 32));
        cancelButton->setMaximumSize(QSize(72, 32));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE;}\n"
"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        label_6 = new QLabel(EditInvoiceInfoWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(130, 110, 131, 15));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(0, 15));
        label_6->setMaximumSize(QSize(16777215, 15));
        label_6->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_7 = new QLabel(EditInvoiceInfoWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 171, 131, 15));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(0, 15));
        label_7->setMaximumSize(QSize(16777215, 15));
        label_7->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_8 = new QLabel(EditInvoiceInfoWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(130, 331, 131, 15));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(0, 15));
        label_8->setMaximumSize(QSize(16777215, 15));
        label_8->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_9 = new QLabel(EditInvoiceInfoWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(130, 231, 131, 15));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(0, 15));
        label_9->setMaximumSize(QSize(16777215, 15));
        label_9->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));

        retranslateUi(EditInvoiceInfoWidget);

        QMetaObject::connectSlotsByName(EditInvoiceInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *EditInvoiceInfoWidget)
    {
        EditInvoiceInfoWidget->setWindowTitle(QApplication::translate("EditInvoiceInfoWidget", "EditInvoiceInfoWidget", 0));
        closeButton->setText(QString());
        label->setText(QApplication::translate("EditInvoiceInfoWidget", "\347\274\226\350\276\221\345\274\200\347\245\250\344\277\241\346\201\257", 0));
        label_5->setText(QApplication::translate("EditInvoiceInfoWidget", "\350\257\246\347\273\206\345\234\260\345\235\200", 0));
        label_4->setText(QApplication::translate("EditInvoiceInfoWidget", "\345\233\272\345\256\232\347\224\265\350\257\235", 0));
        label_2->setText(QApplication::translate("EditInvoiceInfoWidget", "\345\274\200\346\210\267\350\264\246\345\217\267", 0));
        label_3->setText(QApplication::translate("EditInvoiceInfoWidget", "\345\274\200\346\210\267\351\223\266\350\241\214", 0));
        lineEditAcc->setText(QString());
        lineEditAcc->setPlaceholderText(QApplication::translate("EditInvoiceInfoWidget", "\350\257\267\350\276\223\345\205\245\344\274\201\344\270\232\345\274\200\346\210\267\350\264\246\345\217\267", 0));
        lineEditBank->setText(QString());
        lineEditBank->setPlaceholderText(QApplication::translate("EditInvoiceInfoWidget", "\350\257\267\350\276\223\345\205\245\344\274\201\344\270\232\345\274\200\346\210\267\351\223\266\350\241\214\345\220\215\347\247\260", 0));
        lineEditTelNo->setText(QString());
        lineEditTelNo->setPlaceholderText(QApplication::translate("EditInvoiceInfoWidget", "\350\257\267\350\276\223\345\205\245\344\274\201\344\270\232\345\233\272\345\256\232\347\224\265\350\257\235", 0));
        textEditAddr->setPlaceholderText(QApplication::translate("EditInvoiceInfoWidget", "\350\257\267\350\276\223\345\205\245\350\201\224\347\263\273\345\234\260\345\235\200", 0));
        okButton->setText(QApplication::translate("EditInvoiceInfoWidget", "\347\241\256\345\256\232", 0));
        cancelButton->setText(QApplication::translate("EditInvoiceInfoWidget", "\345\217\226\346\266\210", 0));
        label_6->setText(QApplication::translate("EditInvoiceInfoWidget", "\350\257\267\350\276\223\345\205\245\346\255\243\347\241\256\347\232\204\345\274\200\346\210\267\350\264\246\345\217\267", 0));
        label_7->setText(QApplication::translate("EditInvoiceInfoWidget", "\350\257\267\350\276\223\345\205\245\346\234\200\345\244\23250\344\270\252\345\255\227\347\254\246", 0));
        label_8->setText(QApplication::translate("EditInvoiceInfoWidget", "\350\257\267\350\276\223\345\205\245\346\234\200\345\244\232200\344\270\252\345\255\227\347\254\246", 0));
        label_9->setText(QApplication::translate("EditInvoiceInfoWidget", "\350\257\267\350\276\223\345\205\245\346\255\243\347\241\256\347\232\204\345\233\272\345\256\232\347\224\265\350\257\235", 0));
    } // retranslateUi

};

namespace Ui {
    class EditInvoiceInfoWidget: public Ui_EditInvoiceInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITINVOICEINFOWIDGET_H
