/********************************************************************************
** Form generated from reading UI file 'ModifyPwdWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYPWDWIDGET_H
#define UI_MODIFYPWDWIDGET_H

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

class Ui_ModifyPwdWidget
{
public:
    QPushButton *closeButton;
    QLabel *label;
    QLineEdit *lineEditOldPwd;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditNewPwd;
    QLineEdit *lineEditComfirmPwd;
    QLabel *label_4;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *labelForgetPwd;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QWidget *ModifyPwdWidget)
    {
        if (ModifyPwdWidget->objectName().isEmpty())
            ModifyPwdWidget->setObjectName(QStringLiteral("ModifyPwdWidget"));
        ModifyPwdWidget->resize(454, 323);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ModifyPwdWidget->sizePolicy().hasHeightForWidth());
        ModifyPwdWidget->setSizePolicy(sizePolicy);
        ModifyPwdWidget->setMinimumSize(QSize(454, 323));
        ModifyPwdWidget->setMaximumSize(QSize(454, 323));
        ModifyPwdWidget->setStyleSheet(QStringLiteral("QWidget#ModifyPwdWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        closeButton = new QPushButton(ModifyPwdWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(415, 5, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label = new QLabel(ModifyPwdWidget);
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
        lineEditOldPwd = new QLineEdit(ModifyPwdWidget);
        lineEditOldPwd->setObjectName(QStringLiteral("lineEditOldPwd"));
        lineEditOldPwd->setGeometry(QRect(130, 60, 268, 40));
        sizePolicy.setHeightForWidth(lineEditOldPwd->sizePolicy().hasHeightForWidth());
        lineEditOldPwd->setSizePolicy(sizePolicy);
        lineEditOldPwd->setMinimumSize(QSize(268, 40));
        lineEditOldPwd->setMaximumSize(QSize(268, 40));
        lineEditOldPwd->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        label_2 = new QLabel(ModifyPwdWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 65, 56, 30));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(56, 30));
        label_2->setMaximumSize(QSize(100, 30));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_3 = new QLabel(ModifyPwdWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 126, 56, 30));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(56, 30));
        label_3->setMaximumSize(QSize(100, 30));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        lineEditNewPwd = new QLineEdit(ModifyPwdWidget);
        lineEditNewPwd->setObjectName(QStringLiteral("lineEditNewPwd"));
        lineEditNewPwd->setGeometry(QRect(130, 120, 268, 40));
        sizePolicy.setHeightForWidth(lineEditNewPwd->sizePolicy().hasHeightForWidth());
        lineEditNewPwd->setSizePolicy(sizePolicy);
        lineEditNewPwd->setMinimumSize(QSize(268, 40));
        lineEditNewPwd->setMaximumSize(QSize(268, 40));
        lineEditNewPwd->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditComfirmPwd = new QLineEdit(ModifyPwdWidget);
        lineEditComfirmPwd->setObjectName(QStringLiteral("lineEditComfirmPwd"));
        lineEditComfirmPwd->setGeometry(QRect(130, 180, 268, 40));
        sizePolicy.setHeightForWidth(lineEditComfirmPwd->sizePolicy().hasHeightForWidth());
        lineEditComfirmPwd->setSizePolicy(sizePolicy);
        lineEditComfirmPwd->setMinimumSize(QSize(268, 40));
        lineEditComfirmPwd->setMaximumSize(QSize(268, 40));
        lineEditComfirmPwd->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        label_4 = new QLabel(ModifyPwdWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 185, 71, 30));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(56, 30));
        label_4->setMaximumSize(QSize(100, 30));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        okButton = new QPushButton(ModifyPwdWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(127, 251, 72, 32));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setMinimumSize(QSize(72, 32));
        okButton->setMaximumSize(QSize(72, 32));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        cancelButton = new QPushButton(ModifyPwdWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(219, 251, 72, 32));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        cancelButton->setMinimumSize(QSize(72, 32));
        cancelButton->setMaximumSize(QSize(72, 32));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE;}\n"
"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        labelForgetPwd = new QLabel(ModifyPwdWidget);
        labelForgetPwd->setObjectName(QStringLiteral("labelForgetPwd"));
        labelForgetPwd->setGeometry(QRect(337, 260, 61, 12));
        sizePolicy1.setHeightForWidth(labelForgetPwd->sizePolicy().hasHeightForWidth());
        labelForgetPwd->setSizePolicy(sizePolicy1);
        labelForgetPwd->setMinimumSize(QSize(0, 12));
        labelForgetPwd->setMaximumSize(QSize(16777215, 12));
        labelForgetPwd->setCursor(QCursor(Qt::PointingHandCursor));
        labelForgetPwd->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1E8BED;\n"
"border-bottom:0px;"));
        label_8 = new QLabel(ModifyPwdWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(130, 100, 211, 15));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(0, 15));
        label_8->setMaximumSize(QSize(16777215, 15));
        label_8->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_9 = new QLabel(ModifyPwdWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(130, 160, 211, 15));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(0, 15));
        label_9->setMaximumSize(QSize(16777215, 15));
        label_9->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        label_10 = new QLabel(ModifyPwdWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(130, 220, 211, 15));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(0, 15));
        label_10->setMaximumSize(QSize(16777215, 15));
        label_10->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));

        retranslateUi(ModifyPwdWidget);

        QMetaObject::connectSlotsByName(ModifyPwdWidget);
    } // setupUi

    void retranslateUi(QWidget *ModifyPwdWidget)
    {
        ModifyPwdWidget->setWindowTitle(QApplication::translate("ModifyPwdWidget", "ModifyPwdWidget", 0));
        closeButton->setText(QString());
        label->setText(QApplication::translate("ModifyPwdWidget", "\344\277\256\346\224\271\345\257\206\347\240\201", 0));
        lineEditOldPwd->setText(QString());
        lineEditOldPwd->setPlaceholderText(QApplication::translate("ModifyPwdWidget", "\350\257\267\350\276\223\345\205\245\345\216\237\347\231\273\345\275\225\345\257\206\347\240\201", 0));
        label_2->setText(QApplication::translate("ModifyPwdWidget", "<font color = red>*</font><font color =#333333>\345\216\237\345\257\206\347\240\201</font>", 0));
        label_3->setText(QApplication::translate("ModifyPwdWidget", "<font color = red>*</font><font color =#333333>\346\226\260\345\257\206\347\240\201</font>", 0));
        lineEditNewPwd->setText(QString());
        lineEditNewPwd->setPlaceholderText(QApplication::translate("ModifyPwdWidget", "\350\257\267\350\276\223\345\205\245\346\226\260\347\231\273\345\275\225\345\257\206\347\240\201", 0));
        lineEditComfirmPwd->setText(QString());
        lineEditComfirmPwd->setPlaceholderText(QApplication::translate("ModifyPwdWidget", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\347\231\273\345\275\225\345\257\206\347\240\201", 0));
        label_4->setText(QApplication::translate("ModifyPwdWidget", "<font color = red>*</font><font color =#333333>\347\241\256\350\256\244\345\257\206\347\240\201</font>", 0));
        okButton->setText(QApplication::translate("ModifyPwdWidget", "\347\241\256\345\256\232", 0));
        cancelButton->setText(QApplication::translate("ModifyPwdWidget", "\345\217\226\346\266\210", 0));
        labelForgetPwd->setText(QApplication::translate("ModifyPwdWidget", "\345\277\230\350\256\260\345\257\206\347\240\201\357\274\237", 0));
        label_8->setText(QApplication::translate("ModifyPwdWidget", "\350\257\267\350\276\223\345\205\2458\357\275\23620\344\270\252\345\255\227\346\257\215\343\200\201\346\225\260\345\255\227\346\210\226\347\211\271\346\256\212\345\255\227\347\254\246", 0));
        label_9->setText(QApplication::translate("ModifyPwdWidget", "\350\257\267\350\276\223\345\205\2458\357\275\23620\344\270\252\345\255\227\346\257\215\343\200\201\346\225\260\345\255\227\346\210\226\347\211\271\346\256\212\345\255\227\347\254\246", 0));
        label_10->setText(QApplication::translate("ModifyPwdWidget", "\350\257\267\350\276\223\345\205\2458\357\275\23620\344\270\252\345\255\227\346\257\215\343\200\201\346\225\260\345\255\227\346\210\226\347\211\271\346\256\212\345\255\227\347\254\246", 0));
    } // retranslateUi

};

namespace Ui {
    class ModifyPwdWidget: public Ui_ModifyPwdWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYPWDWIDGET_H
