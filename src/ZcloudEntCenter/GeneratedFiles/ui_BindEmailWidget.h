/********************************************************************************
** Form generated from reading UI file 'BindEmailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINDEMAILWIDGET_H
#define UI_BINDEMAILWIDGET_H

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

class Ui_BindEmailWidget
{
public:
    QLabel *label_9;
    QLabel *label_5;
    QLineEdit *lineEditEmail;
    QPushButton *okButton;
    QLineEdit *lineEditEmailCode;
    QPushButton *cancelButton;
    QPushButton *closeButton;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_6;
    QPushButton *sendCodeButton;

    void setupUi(QWidget *BindEmailWidget)
    {
        if (BindEmailWidget->objectName().isEmpty())
            BindEmailWidget->setObjectName(QStringLiteral("BindEmailWidget"));
        BindEmailWidget->resize(454, 254);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BindEmailWidget->sizePolicy().hasHeightForWidth());
        BindEmailWidget->setSizePolicy(sizePolicy);
        BindEmailWidget->setMinimumSize(QSize(454, 254));
        BindEmailWidget->setMaximumSize(QSize(454, 254));
        BindEmailWidget->setStyleSheet(QStringLiteral("QWidget#BindEmailWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        label_9 = new QLabel(BindEmailWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(130, 170, 141, 15));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(0, 15));
        label_9->setMaximumSize(QSize(16777215, 15));
        label_9->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_5 = new QLabel(BindEmailWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(51, 141, 60, 18));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(60, 18));
        label_5->setMaximumSize(QSize(60, 18));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_5->setTextFormat(Qt::AutoText);
        label_5->setAlignment(Qt::AlignCenter);
        lineEditEmail = new QLineEdit(BindEmailWidget);
        lineEditEmail->setObjectName(QStringLiteral("lineEditEmail"));
        lineEditEmail->setGeometry(QRect(128, 70, 268, 40));
        sizePolicy.setHeightForWidth(lineEditEmail->sizePolicy().hasHeightForWidth());
        lineEditEmail->setSizePolicy(sizePolicy);
        lineEditEmail->setMinimumSize(QSize(268, 40));
        lineEditEmail->setMaximumSize(QSize(268, 40));
        lineEditEmail->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        okButton = new QPushButton(BindEmailWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(131, 200, 72, 32));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setMinimumSize(QSize(72, 32));
        okButton->setMaximumSize(QSize(72, 32));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        lineEditEmailCode = new QLineEdit(BindEmailWidget);
        lineEditEmailCode->setObjectName(QStringLiteral("lineEditEmailCode"));
        lineEditEmailCode->setGeometry(QRect(128, 130, 268, 40));
        sizePolicy.setHeightForWidth(lineEditEmailCode->sizePolicy().hasHeightForWidth());
        lineEditEmailCode->setSizePolicy(sizePolicy);
        lineEditEmailCode->setMinimumSize(QSize(268, 40));
        lineEditEmailCode->setMaximumSize(QSize(268, 40));
        lineEditEmailCode->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        cancelButton = new QPushButton(BindEmailWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(223, 200, 72, 32));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        cancelButton->setMinimumSize(QSize(72, 32));
        cancelButton->setMaximumSize(QSize(72, 32));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE;}\n"
"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        closeButton = new QPushButton(BindEmailWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(415, 10, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label_2 = new QLabel(BindEmailWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(51, 81, 35, 18));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(35, 18));
        label_2->setMaximumSize(QSize(35, 18));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        label = new QLabel(BindEmailWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 19, 90, 14));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(90, 14));
        label->setMaximumSize(QSize(90, 14));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        label_6 = new QLabel(BindEmailWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(130, 110, 131, 15));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(0, 15));
        label_6->setMaximumSize(QSize(16777215, 15));
        label_6->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        sendCodeButton = new QPushButton(BindEmailWidget);
        sendCodeButton->setObjectName(QStringLiteral("sendCodeButton"));
        sendCodeButton->setGeometry(QRect(315, 142, 70, 15));
        sizePolicy.setHeightForWidth(sendCodeButton->sizePolicy().hasHeightForWidth());
        sendCodeButton->setSizePolicy(sizePolicy);
        sendCodeButton->setMinimumSize(QSize(70, 15));
        sendCodeButton->setMaximumSize(QSize(70, 15));
        sendCodeButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#1E8BED;}\n"
"QPushButton:hover,pressed{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(64, 156, 240, 1);}\n"
"QPushButton:disabled{ background-color:#FFFFFF;color:#666666};"));

        retranslateUi(BindEmailWidget);

        QMetaObject::connectSlotsByName(BindEmailWidget);
    } // setupUi

    void retranslateUi(QWidget *BindEmailWidget)
    {
        BindEmailWidget->setWindowTitle(QApplication::translate("BindEmailWidget", "BindEmailWidget", 0));
        label_9->setText(QApplication::translate("BindEmailWidget", "\350\257\267\350\276\223\345\205\245\346\255\243\347\241\256\347\232\204\351\252\214\350\257\201\347\240\201", 0));
        label_5->setText(QApplication::translate("BindEmailWidget", "\351\202\256\347\256\261\351\252\214\350\257\201", 0));
        lineEditEmail->setText(QString());
        lineEditEmail->setPlaceholderText(QApplication::translate("BindEmailWidget", "\350\257\267\350\276\223\345\205\245\351\202\256\347\256\261\345\234\260\345\235\200", 0));
        okButton->setText(QApplication::translate("BindEmailWidget", "\347\241\256\345\256\232", 0));
        lineEditEmailCode->setPlaceholderText(QApplication::translate("BindEmailWidget", "\350\257\267\350\276\223\345\205\245\351\202\256\347\256\261\351\252\214\350\257\201\347\240\201", 0));
        cancelButton->setText(QApplication::translate("BindEmailWidget", "\345\217\226\346\266\210", 0));
        closeButton->setText(QString());
        label_2->setText(QApplication::translate("BindEmailWidget", "\351\202\256\347\256\261", 0));
        label->setText(QApplication::translate("BindEmailWidget", "\351\202\256\347\256\261\347\273\221\345\256\232", 0));
        label_6->setText(QApplication::translate("BindEmailWidget", "\350\257\267\350\276\223\345\205\245\346\255\243\347\241\256\347\232\204\351\202\256\347\256\261\345\234\260\345\235\200", 0));
        sendCodeButton->setText(QApplication::translate("BindEmailWidget", "\345\217\221\351\200\201\351\252\214\350\257\201\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class BindEmailWidget: public Ui_BindEmailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINDEMAILWIDGET_H
