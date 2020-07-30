/********************************************************************************
** Form generated from reading UI file 'BindMobileWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINDMOBILEWIDGET_H
#define UI_BINDMOBILEWIDGET_H

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

class Ui_BindMobileWidget
{
public:
    QPushButton *closeButton;
    QLabel *labelTitle;
    QWidget *widgetMobile;
    QLabel *label_5;
    QLineEdit *lineEditMobile;
    QLineEdit *lineEditMobileCode;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_11;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QPushButton *sendCodeButton;
    QLabel *labelPhone;

    void setupUi(QWidget *BindMobileWidget)
    {
        if (BindMobileWidget->objectName().isEmpty())
            BindMobileWidget->setObjectName(QStringLiteral("BindMobileWidget"));
        BindMobileWidget->resize(454, 254);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BindMobileWidget->sizePolicy().hasHeightForWidth());
        BindMobileWidget->setSizePolicy(sizePolicy);
        BindMobileWidget->setMinimumSize(QSize(454, 254));
        BindMobileWidget->setMaximumSize(QSize(454, 254));
        BindMobileWidget->setStyleSheet(QStringLiteral("QWidget#BindMobileWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        closeButton = new QPushButton(BindMobileWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(415, 10, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        labelTitle = new QLabel(BindMobileWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(20, 19, 100, 14));
        sizePolicy.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy);
        labelTitle->setMinimumSize(QSize(100, 14));
        labelTitle->setMaximumSize(QSize(100, 14));
        labelTitle->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        widgetMobile = new QWidget(BindMobileWidget);
        widgetMobile->setObjectName(QStringLiteral("widgetMobile"));
        widgetMobile->setGeometry(QRect(0, 50, 454, 191));
        sizePolicy.setHeightForWidth(widgetMobile->sizePolicy().hasHeightForWidth());
        widgetMobile->setSizePolicy(sizePolicy);
        widgetMobile->setMinimumSize(QSize(454, 0));
        widgetMobile->setMaximumSize(QSize(454, 16777215));
        label_5 = new QLabel(widgetMobile);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(51, 32, 45, 15));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(45, 15));
        label_5->setMaximumSize(QSize(45, 15));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_5->setTextFormat(Qt::AutoText);
        label_5->setAlignment(Qt::AlignCenter);
        lineEditMobile = new QLineEdit(widgetMobile);
        lineEditMobile->setObjectName(QStringLiteral("lineEditMobile"));
        lineEditMobile->setGeometry(QRect(126, 20, 268, 40));
        sizePolicy.setHeightForWidth(lineEditMobile->sizePolicy().hasHeightForWidth());
        lineEditMobile->setSizePolicy(sizePolicy);
        lineEditMobile->setMinimumSize(QSize(268, 40));
        lineEditMobile->setMaximumSize(QSize(268, 40));
        lineEditMobile->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        lineEditMobileCode = new QLineEdit(widgetMobile);
        lineEditMobileCode->setObjectName(QStringLiteral("lineEditMobileCode"));
        lineEditMobileCode->setGeometry(QRect(126, 80, 268, 40));
        sizePolicy.setHeightForWidth(lineEditMobileCode->sizePolicy().hasHeightForWidth());
        lineEditMobileCode->setSizePolicy(sizePolicy);
        lineEditMobileCode->setMinimumSize(QSize(268, 40));
        lineEditMobileCode->setMaximumSize(QSize(268, 40));
        lineEditMobileCode->setStyleSheet(QLatin1String("QLineEdit{border-radius:4px;color:rgba(51,51,51,1);border:1px solid rgb(222,222,222);font:14px 'Microsoft Yahei';padding-left:10px;}\n"
"QLineEdit:laceholder{color:rgba(51,51,51,1);}QLineEdit:focus{border:1px solid rgba(30,140,238,1);}\n"
"QLineEdit:disabled{background-color: rgb(247,248, 250);};"));
        label_7 = new QLabel(widgetMobile);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(54, 90, 45, 15));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(45, 15));
        label_7->setMaximumSize(QSize(45, 15));
        label_7->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_7->setTextFormat(Qt::AutoText);
        label_7->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(widgetMobile);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(130, 120, 261, 15));
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
        label_11 = new QLabel(widgetMobile);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(130, 60, 141, 15));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(0, 15));
        label_11->setMaximumSize(QSize(16777215, 15));
        label_11->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #ff0000;\n"
"border-bottom:0px;"));
        okButton = new QPushButton(widgetMobile);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(129, 150, 72, 32));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setMinimumSize(QSize(72, 32));
        okButton->setMaximumSize(QSize(72, 32));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        cancelButton = new QPushButton(widgetMobile);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(221, 150, 72, 32));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        cancelButton->setMinimumSize(QSize(72, 32));
        cancelButton->setMaximumSize(QSize(72, 32));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE;}\n"
"QPushButton:hover,pressed{background-color:#F4F4F4;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        sendCodeButton = new QPushButton(widgetMobile);
        sendCodeButton->setObjectName(QStringLiteral("sendCodeButton"));
        sendCodeButton->setGeometry(QRect(315, 92, 70, 15));
        sizePolicy.setHeightForWidth(sendCodeButton->sizePolicy().hasHeightForWidth());
        sendCodeButton->setSizePolicy(sizePolicy);
        sendCodeButton->setMinimumSize(QSize(70, 15));
        sendCodeButton->setMaximumSize(QSize(70, 15));
        sendCodeButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#1E8BED;}\n"
"QPushButton:hover,pressed{background-color:#FFFFFF;border-radius:4px;font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(64, 156, 240, 1);}\n"
"QPushButton:disabled{ background-color:#FFFFFF;color:#666666};"));
        labelPhone = new QLabel(widgetMobile);
        labelPhone->setObjectName(QStringLiteral("labelPhone"));
        labelPhone->setGeometry(QRect(150, 0, 268, 12));
        sizePolicy.setHeightForWidth(labelPhone->sizePolicy().hasHeightForWidth());
        labelPhone->setSizePolicy(sizePolicy);
        labelPhone->setMinimumSize(QSize(268, 0));
        labelPhone->setMaximumSize(QSize(268, 16777215));
        labelPhone->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #333333;\n"
"border-bottom:0px;"));

        retranslateUi(BindMobileWidget);

        QMetaObject::connectSlotsByName(BindMobileWidget);
    } // setupUi

    void retranslateUi(QWidget *BindMobileWidget)
    {
        BindMobileWidget->setWindowTitle(QApplication::translate("BindMobileWidget", "ModifyCommonWidget", 0));
        closeButton->setText(QString());
        labelTitle->setText(QApplication::translate("BindMobileWidget", "\346\211\213\346\234\272\347\273\221\345\256\232", 0));
        label_5->setText(QApplication::translate("BindMobileWidget", "\346\211\213\346\234\272\345\217\267", 0));
        lineEditMobile->setPlaceholderText(QApplication::translate("BindMobileWidget", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\346\211\213\346\234\272\345\217\267", 0));
        lineEditMobileCode->setPlaceholderText(QApplication::translate("BindMobileWidget", "\350\257\267\350\276\223\345\205\245\351\252\214\350\257\201\347\240\201", 0));
        label_7->setText(QApplication::translate("BindMobileWidget", "\351\252\214\350\257\201\347\240\201", 0));
        label_9->setText(QApplication::translate("BindMobileWidget", "\350\257\267\350\276\223\345\205\245\346\255\243\347\241\256\347\232\204\351\252\214\350\257\201\347\240\201", 0));
        label_11->setText(QApplication::translate("BindMobileWidget", "\350\257\267\350\276\223\345\205\24511\344\275\215\346\255\243\347\241\256\347\232\204\346\211\213\346\234\272\345\217\267", 0));
        okButton->setText(QApplication::translate("BindMobileWidget", "\347\241\256\345\256\232", 0));
        cancelButton->setText(QApplication::translate("BindMobileWidget", "\345\217\226\346\266\210", 0));
        sendCodeButton->setText(QApplication::translate("BindMobileWidget", "\345\217\221\351\200\201\351\252\214\350\257\201\347\240\201", 0));
        labelPhone->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BindMobileWidget: public Ui_BindMobileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINDMOBILEWIDGET_H
