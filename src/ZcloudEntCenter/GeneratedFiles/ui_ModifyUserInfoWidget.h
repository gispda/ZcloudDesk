/********************************************************************************
** Form generated from reading UI file 'ModifyUserInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYUSERINFOWIDGET_H
#define UI_MODIFYUSERINFOWIDGET_H

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

class Ui_ModifyUserInfoWidget
{
public:
    QPushButton *closeButton;
    QLabel *label_2;
    QLabel *label_9;
    QLabel *label_5;
    QPushButton *okButton;
    QLineEdit *lineEditName;
    QPushButton *cancelButton;
    QLabel *label;
    QLineEdit *lineEditJob;
    QLabel *label_6;

    void setupUi(QWidget *ModifyUserInfoWidget)
    {
        if (ModifyUserInfoWidget->objectName().isEmpty())
            ModifyUserInfoWidget->setObjectName(QStringLiteral("ModifyUserInfoWidget"));
        ModifyUserInfoWidget->resize(454, 254);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ModifyUserInfoWidget->sizePolicy().hasHeightForWidth());
        ModifyUserInfoWidget->setSizePolicy(sizePolicy);
        ModifyUserInfoWidget->setMinimumSize(QSize(454, 254));
        ModifyUserInfoWidget->setMaximumSize(QSize(454, 254));
        ModifyUserInfoWidget->setStyleSheet(QStringLiteral("QWidget#ModifyUserInfoWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        closeButton = new QPushButton(ModifyUserInfoWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(415, 10, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label_2 = new QLabel(ModifyUserInfoWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(64, 80, 35, 18));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(35, 18));
        label_2->setMaximumSize(QSize(35, 18));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(ModifyUserInfoWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(128, 170, 141, 15));
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
        label_5 = new QLabel(ModifyUserInfoWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 140, 33, 18));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(33, 18));
        label_5->setMaximumSize(QSize(33, 18));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_5->setTextFormat(Qt::AutoText);
        label_5->setAlignment(Qt::AlignCenter);
        okButton = new QPushButton(ModifyUserInfoWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(129, 200, 72, 32));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setMinimumSize(QSize(72, 32));
        okButton->setMaximumSize(QSize(72, 32));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        lineEditName = new QLineEdit(ModifyUserInfoWidget);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(126, 70, 268, 40));
        sizePolicy.setHeightForWidth(lineEditName->sizePolicy().hasHeightForWidth());
        lineEditName->setSizePolicy(sizePolicy);
        lineEditName->setMinimumSize(QSize(268, 40));
        lineEditName->setMaximumSize(QSize(268, 40));
        lineEditName->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        cancelButton = new QPushButton(ModifyUserInfoWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(221, 200, 72, 32));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        cancelButton->setMinimumSize(QSize(72, 32));
        cancelButton->setMaximumSize(QSize(72, 32));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE;}\n"
"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        label = new QLabel(ModifyUserInfoWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 19, 90, 14));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(90, 14));
        label->setMaximumSize(QSize(90, 14));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        lineEditJob = new QLineEdit(ModifyUserInfoWidget);
        lineEditJob->setObjectName(QStringLiteral("lineEditJob"));
        lineEditJob->setGeometry(QRect(126, 130, 268, 40));
        sizePolicy.setHeightForWidth(lineEditJob->sizePolicy().hasHeightForWidth());
        lineEditJob->setSizePolicy(sizePolicy);
        lineEditJob->setMinimumSize(QSize(268, 40));
        lineEditJob->setMaximumSize(QSize(268, 40));
        lineEditJob->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        label_6 = new QLabel(ModifyUserInfoWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(128, 110, 131, 15));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(0, 15));
        label_6->setMaximumSize(QSize(16777215, 15));
        label_6->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));

        retranslateUi(ModifyUserInfoWidget);

        QMetaObject::connectSlotsByName(ModifyUserInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *ModifyUserInfoWidget)
    {
        ModifyUserInfoWidget->setWindowTitle(QApplication::translate("ModifyUserInfoWidget", "ModifyUserInfoWidget", 0));
        closeButton->setText(QString());
        label_2->setText(QApplication::translate("ModifyUserInfoWidget", "<font color = red>*</font><font color =#333333>\345\247\223\345\220\215</font>", 0));
        label_9->setText(QApplication::translate("ModifyUserInfoWidget", "\350\257\267\350\276\223\345\205\245\346\234\200\345\244\23210\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
        label_5->setText(QApplication::translate("ModifyUserInfoWidget", "\350\201\214\345\212\241", 0));
        okButton->setText(QApplication::translate("ModifyUserInfoWidget", "\347\241\256\345\256\232", 0));
        lineEditName->setText(QString());
        lineEditName->setPlaceholderText(QApplication::translate("ModifyUserInfoWidget", "\350\257\267\350\276\223\345\205\245\347\234\237\345\256\236\345\247\223\345\220\215", 0));
        cancelButton->setText(QApplication::translate("ModifyUserInfoWidget", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("ModifyUserInfoWidget", "\344\277\256\346\224\271\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        lineEditJob->setPlaceholderText(QApplication::translate("ModifyUserInfoWidget", "\344\270\215\350\266\205\350\277\20710\344\270\252\345\255\227", 0));
        label_6->setText(QApplication::translate("ModifyUserInfoWidget", "\350\257\267\350\276\223\345\205\2452\357\275\23620\344\270\252\344\273\273\346\204\217\345\255\227\347\254\246", 0));
    } // retranslateUi

};

namespace Ui {
    class ModifyUserInfoWidget: public Ui_ModifyUserInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYUSERINFOWIDGET_H
