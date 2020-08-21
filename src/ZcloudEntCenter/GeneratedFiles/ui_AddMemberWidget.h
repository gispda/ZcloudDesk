/********************************************************************************
** Form generated from reading UI file 'AddMemberWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMEMBERWIDGET_H
#define UI_ADDMEMBERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddMemberWidget
{
public:
    QPushButton *closeButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *lineEditName;
    QLineEdit *lineEditJob;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label_6;
    QLabel *labelJobErr;
    QWidget *widget;
    QLabel *label_8;
    QLabel *label_3;
    QLineEdit *lineEditAcc;
    QLineEdit *lineEditPwd;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_10;
    QLineEdit *lineEditPhone;
    QLabel *labelPhoneErr;

    void setupUi(QWidget *AddMemberWidget)
    {
        if (AddMemberWidget->objectName().isEmpty())
            AddMemberWidget->setObjectName(QStringLiteral("AddMemberWidget"));
        AddMemberWidget->resize(460, 366);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddMemberWidget->sizePolicy().hasHeightForWidth());
        AddMemberWidget->setSizePolicy(sizePolicy);
        AddMemberWidget->setMinimumSize(QSize(460, 366));
        AddMemberWidget->setMaximumSize(QSize(460, 800));
        AddMemberWidget->setStyleSheet(QStringLiteral("QWidget#AddMemberWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        closeButton = new QPushButton(AddMemberWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(415, 10, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label = new QLabel(AddMemberWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 19, 56, 14));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(56, 14));
        label->setMaximumSize(QSize(56, 14));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        label_2 = new QLabel(AddMemberWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(54, 80, 35, 18));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(35, 18));
        label_2->setMaximumSize(QSize(35, 18));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(AddMemberWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(58, 225, 33, 18));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(33, 18));
        label_5->setMaximumSize(QSize(33, 18));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_5->setTextFormat(Qt::AutoText);
        label_5->setAlignment(Qt::AlignCenter);
        lineEditName = new QLineEdit(AddMemberWidget);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(120, 70, 320, 36));
        sizePolicy.setHeightForWidth(lineEditName->sizePolicy().hasHeightForWidth());
        lineEditName->setSizePolicy(sizePolicy);
        lineEditName->setMinimumSize(QSize(320, 36));
        lineEditName->setMaximumSize(QSize(320, 36));
        lineEditName->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditJob = new QLineEdit(AddMemberWidget);
        lineEditJob->setObjectName(QStringLiteral("lineEditJob"));
        lineEditJob->setGeometry(QRect(120, 220, 320, 36));
        sizePolicy.setHeightForWidth(lineEditJob->sizePolicy().hasHeightForWidth());
        lineEditJob->setSizePolicy(sizePolicy);
        lineEditJob->setMinimumSize(QSize(320, 36));
        lineEditJob->setMaximumSize(QSize(320, 36));
        lineEditJob->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditJob->setMaxLength(10);
        okButton = new QPushButton(AddMemberWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(150, 300, 72, 32));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setMinimumSize(QSize(72, 32));
        okButton->setMaximumSize(QSize(72, 32));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        cancelButton = new QPushButton(AddMemberWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(238, 300, 72, 32));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        cancelButton->setMinimumSize(QSize(72, 32));
        cancelButton->setMaximumSize(QSize(72, 32));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE;}\n"
"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        label_6 = new QLabel(AddMemberWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(122, 106, 131, 15));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(0, 15));
        label_6->setMaximumSize(QSize(16777215, 15));
        label_6->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        labelJobErr = new QLabel(AddMemberWidget);
        labelJobErr->setObjectName(QStringLiteral("labelJobErr"));
        labelJobErr->setGeometry(QRect(122, 260, 141, 15));
        sizePolicy1.setHeightForWidth(labelJobErr->sizePolicy().hasHeightForWidth());
        labelJobErr->setSizePolicy(sizePolicy1);
        labelJobErr->setMinimumSize(QSize(0, 15));
        labelJobErr->setMaximumSize(QSize(16777215, 15));
        labelJobErr->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        widget = new QWidget(AddMemberWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 390, 454, 400));
        widget->setMinimumSize(QSize(454, 400));
        widget->setMaximumSize(QSize(454, 400));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(110, 120, 211, 15));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(0, 15));
        label_8->setMaximumSize(QSize(16777215, 15));
        label_8->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(42, 38, 35, 18));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(35, 18));
        label_3->setMaximumSize(QSize(35, 18));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_3->setTextFormat(Qt::AutoText);
        label_3->setAlignment(Qt::AlignCenter);
        lineEditAcc = new QLineEdit(widget);
        lineEditAcc->setObjectName(QStringLiteral("lineEditAcc"));
        lineEditAcc->setGeometry(QRect(108, 28, 268, 36));
        sizePolicy.setHeightForWidth(lineEditAcc->sizePolicy().hasHeightForWidth());
        lineEditAcc->setSizePolicy(sizePolicy);
        lineEditAcc->setMinimumSize(QSize(268, 36));
        lineEditAcc->setMaximumSize(QSize(268, 36));
        lineEditAcc->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditPwd = new QLineEdit(widget);
        lineEditPwd->setObjectName(QStringLiteral("lineEditPwd"));
        lineEditPwd->setGeometry(QRect(108, 84, 268, 36));
        sizePolicy.setHeightForWidth(lineEditPwd->sizePolicy().hasHeightForWidth());
        lineEditPwd->setSizePolicy(sizePolicy);
        lineEditPwd->setMinimumSize(QSize(268, 36));
        lineEditPwd->setMaximumSize(QSize(268, 36));
        lineEditPwd->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditPwd->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(42, 94, 35, 18));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(35, 18));
        label_4->setMaximumSize(QSize(35, 18));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(110, 64, 301, 15));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(0, 15));
        label_7->setMaximumSize(QSize(16777215, 15));
        label_7->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_10 = new QLabel(AddMemberWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(54, 150, 35, 18));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(35, 18));
        label_10->setMaximumSize(QSize(35, 18));
        label_10->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_10->setTextFormat(Qt::AutoText);
        label_10->setAlignment(Qt::AlignCenter);
        lineEditPhone = new QLineEdit(AddMemberWidget);
        lineEditPhone->setObjectName(QStringLiteral("lineEditPhone"));
        lineEditPhone->setGeometry(QRect(120, 145, 320, 36));
        sizePolicy.setHeightForWidth(lineEditPhone->sizePolicy().hasHeightForWidth());
        lineEditPhone->setSizePolicy(sizePolicy);
        lineEditPhone->setMinimumSize(QSize(320, 36));
        lineEditPhone->setMaximumSize(QSize(320, 36));
        lineEditPhone->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        labelPhoneErr = new QLabel(AddMemberWidget);
        labelPhoneErr->setObjectName(QStringLiteral("labelPhoneErr"));
        labelPhoneErr->setGeometry(QRect(122, 185, 311, 15));
        sizePolicy1.setHeightForWidth(labelPhoneErr->sizePolicy().hasHeightForWidth());
        labelPhoneErr->setSizePolicy(sizePolicy1);
        labelPhoneErr->setMinimumSize(QSize(0, 15));
        labelPhoneErr->setMaximumSize(QSize(16777215, 15));
        labelPhoneErr->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));

        retranslateUi(AddMemberWidget);

        QMetaObject::connectSlotsByName(AddMemberWidget);
    } // setupUi

    void retranslateUi(QWidget *AddMemberWidget)
    {
        AddMemberWidget->setWindowTitle(QApplication::translate("AddMemberWidget", "AddMemberWidget", 0));
        closeButton->setText(QString());
        label->setText(QApplication::translate("AddMemberWidget", "\346\267\273\345\212\240\346\210\220\345\221\230", 0));
        label_2->setText(QApplication::translate("AddMemberWidget", "<font color = red>*</font><font color =#333333>\345\247\223\345\220\215</font>", 0));
        label_5->setText(QApplication::translate("AddMemberWidget", "\350\201\214\345\212\241", 0));
        lineEditName->setText(QString());
        lineEditName->setPlaceholderText(QApplication::translate("AddMemberWidget", "\350\257\267\350\276\223\345\205\245\347\234\237\345\256\236\345\247\223\345\220\215", 0));
        lineEditJob->setPlaceholderText(QApplication::translate("AddMemberWidget", "\350\276\223\345\205\245\350\201\214\345\212\241", 0));
        okButton->setText(QApplication::translate("AddMemberWidget", "\347\241\256\345\256\232", 0));
        cancelButton->setText(QApplication::translate("AddMemberWidget", "\345\217\226\346\266\210", 0));
        label_6->setText(QApplication::translate("AddMemberWidget", "\350\257\267\350\276\223\345\205\2452\357\275\23620\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
        labelJobErr->setText(QApplication::translate("AddMemberWidget", "\350\257\267\350\276\223\345\205\245\346\234\200\345\244\23210\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
        label_8->setText(QApplication::translate("AddMemberWidget", "\350\257\267\350\276\223\345\205\2458\357\275\23620\344\270\252\345\255\227\346\257\215\343\200\201\346\225\260\345\255\227\346\210\226\347\211\271\346\256\212\345\255\227\347\254\246", 0));
        label_3->setText(QApplication::translate("AddMemberWidget", "<font color = red>*</font><font color =#333333>\350\264\246\345\217\267</font>", 0));
        lineEditAcc->setPlaceholderText(QApplication::translate("AddMemberWidget", "6\357\275\23620\344\275\215\346\225\260\345\255\227\343\200\201\345\255\227\346\257\215", 0));
        lineEditPwd->setPlaceholderText(QApplication::translate("AddMemberWidget", "8\357\275\23620\344\275\215\346\225\260\345\255\227\343\200\201\345\255\227\346\257\215\345\222\214\347\211\271\346\256\212\347\254\246\345\217\267", 0));
        label_4->setText(QApplication::translate("AddMemberWidget", "<font color = red>*</font><font color =#333333>\345\257\206\347\240\201</font>", 0));
        label_7->setText(QApplication::translate("AddMemberWidget", "\350\257\267\350\276\223\345\205\2456\357\275\23620\344\270\252\345\255\227\346\257\215\343\200\201\346\225\260\345\255\227\346\210\226\344\270\213\345\210\222\347\272\277\357\274\214\344\270\224\344\273\245\345\255\227\346\257\215\345\274\200\345\244\264", 0));
        label_10->setText(QApplication::translate("AddMemberWidget", "<font color = red>*</font><font color =#333333>\346\211\213\346\234\272\345\217\267</font>", 0));
        lineEditPhone->setText(QString());
        lineEditPhone->setPlaceholderText(QApplication::translate("AddMemberWidget", "\350\276\223\345\205\245\346\263\250\345\206\214\346\211\213\346\234\272\345\217\267", 0));
        labelPhoneErr->setText(QApplication::translate("AddMemberWidget", "\350\257\267\350\276\223\345\205\24511\344\275\215\346\255\243\347\241\256\347\232\204\346\211\213\346\234\272\345\217\267", 0));
    } // retranslateUi

};

namespace Ui {
    class AddMemberWidget: public Ui_AddMemberWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMEMBERWIDGET_H
