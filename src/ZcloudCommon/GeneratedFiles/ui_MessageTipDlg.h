/********************************************************************************
** Form generated from reading UI file 'MessageTipDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGETIPDLG_H
#define UI_MESSAGETIPDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageTipDlg
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QLabel *labelIcon;
    QLabel *labelTilte;
    QLabel *labelMsg;
    QWidget *BtnWidget1;
    QPushButton *closeButton;
    QWidget *BtnWidget2;
    QPushButton *updateButton;
    QPushButton *noUpdateButton;
    QWidget *BtnWidget3;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QWidget *BtnWidget4;
    QPushButton *bindingButton;
    QPushButton *notBindingButton;
    QPushButton *clostPushButton;

    void setupUi(QDialog *MessageTipDlg)
    {
        if (MessageTipDlg->objectName().isEmpty())
            MessageTipDlg->setObjectName(QStringLiteral("MessageTipDlg"));
        MessageTipDlg->resize(366, 296);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MessageTipDlg->sizePolicy().hasHeightForWidth());
        MessageTipDlg->setSizePolicy(sizePolicy);
        MessageTipDlg->setMinimumSize(QSize(366, 296));
        MessageTipDlg->setMaximumSize(QSize(3660, 2960));
        verticalLayout = new QVBoxLayout(MessageTipDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        FilletWidget = new QWidget(MessageTipDlg);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(350, 280));
        FilletWidget->setMaximumSize(QSize(3500, 2800));
        FilletWidget->setStyleSheet(QLatin1String("border-radius:4px;\n"
"background-color: rgb(255, 255, 255);"));
        labelIcon = new QLabel(FilletWidget);
        labelIcon->setObjectName(QStringLiteral("labelIcon"));
        labelIcon->setGeometry(QRect(145, 30, 60, 60));
        sizePolicy.setHeightForWidth(labelIcon->sizePolicy().hasHeightForWidth());
        labelIcon->setSizePolicy(sizePolicy);
        labelIcon->setMinimumSize(QSize(60, 60));
        labelIcon->setMaximumSize(QSize(60, 60));
        labelIcon->setStyleSheet(QStringLiteral(""));
        labelTilte = new QLabel(FilletWidget);
        labelTilte->setObjectName(QStringLiteral("labelTilte"));
        labelTilte->setGeometry(QRect(5, 110, 340, 20));
        sizePolicy.setHeightForWidth(labelTilte->sizePolicy().hasHeightForWidth());
        labelTilte->setSizePolicy(sizePolicy);
        labelTilte->setMinimumSize(QSize(340, 20));
        labelTilte->setMaximumSize(QSize(340, 20));
        labelTilte->setStyleSheet(QString::fromUtf8("font: 75 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1F8BED;"));
        labelTilte->setAlignment(Qt::AlignCenter);
        labelMsg = new QLabel(FilletWidget);
        labelMsg->setObjectName(QStringLiteral("labelMsg"));
        labelMsg->setGeometry(QRect(5, 140, 340, 40));
        sizePolicy.setHeightForWidth(labelMsg->sizePolicy().hasHeightForWidth());
        labelMsg->setSizePolicy(sizePolicy);
        labelMsg->setMinimumSize(QSize(340, 40));
        labelMsg->setMaximumSize(QSize(340, 40));
        labelMsg->setStyleSheet(QString::fromUtf8("font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#666666;"));
        labelMsg->setAlignment(Qt::AlignCenter);
        labelMsg->setWordWrap(true);
        BtnWidget1 = new QWidget(FilletWidget);
        BtnWidget1->setObjectName(QStringLiteral("BtnWidget1"));
        BtnWidget1->setGeometry(QRect(8, 190, 330, 80));
        sizePolicy.setHeightForWidth(BtnWidget1->sizePolicy().hasHeightForWidth());
        BtnWidget1->setSizePolicy(sizePolicy);
        BtnWidget1->setMinimumSize(QSize(330, 80));
        BtnWidget1->setMaximumSize(QSize(330, 80));
        closeButton = new QPushButton(BtnWidget1);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(110, 20, 120, 40));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(120, 40));
        closeButton->setMaximumSize(QSize(120, 40));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: #FFFFFF;border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE}\n"
"QPushButton:hover,pressed{ background-color: #F4F4F4;border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        BtnWidget2 = new QWidget(FilletWidget);
        BtnWidget2->setObjectName(QStringLiteral("BtnWidget2"));
        BtnWidget2->setGeometry(QRect(8, 280, 330, 80));
        sizePolicy.setHeightForWidth(BtnWidget2->sizePolicy().hasHeightForWidth());
        BtnWidget2->setSizePolicy(sizePolicy);
        BtnWidget2->setMinimumSize(QSize(330, 80));
        BtnWidget2->setMaximumSize(QSize(330, 80));
        updateButton = new QPushButton(BtnWidget2);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(30, 20, 120, 40));
        sizePolicy.setHeightForWidth(updateButton->sizePolicy().hasHeightForWidth());
        updateButton->setSizePolicy(sizePolicy);
        updateButton->setMinimumSize(QSize(120, 40));
        updateButton->setMaximumSize(QSize(120, 40));
        updateButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));\n"
"			border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}"));
        noUpdateButton = new QPushButton(BtnWidget2);
        noUpdateButton->setObjectName(QStringLiteral("noUpdateButton"));
        noUpdateButton->setGeometry(QRect(180, 20, 120, 40));
        sizePolicy.setHeightForWidth(noUpdateButton->sizePolicy().hasHeightForWidth());
        noUpdateButton->setSizePolicy(sizePolicy);
        noUpdateButton->setMinimumSize(QSize(120, 40));
        noUpdateButton->setMaximumSize(QSize(120, 40));
        noUpdateButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: #FFFFFF;border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE}\n"
"QPushButton:hover,pressed{ background-color: #F4F4F4;border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        BtnWidget3 = new QWidget(FilletWidget);
        BtnWidget3->setObjectName(QStringLiteral("BtnWidget3"));
        BtnWidget3->setGeometry(QRect(8, 370, 330, 80));
        sizePolicy.setHeightForWidth(BtnWidget3->sizePolicy().hasHeightForWidth());
        BtnWidget3->setSizePolicy(sizePolicy);
        BtnWidget3->setMinimumSize(QSize(330, 80));
        BtnWidget3->setMaximumSize(QSize(330, 80));
        okButton = new QPushButton(BtnWidget3);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(30, 20, 120, 40));
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setMinimumSize(QSize(120, 40));
        okButton->setMaximumSize(QSize(120, 40));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));\n"
"			border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}"));
        cancelButton = new QPushButton(BtnWidget3);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(180, 20, 120, 40));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        cancelButton->setMinimumSize(QSize(120, 40));
        cancelButton->setMaximumSize(QSize(120, 40));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: #FFFFFF;border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE}\n"
"QPushButton:hover,pressed{ background-color: #F4F4F4;border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        BtnWidget4 = new QWidget(FilletWidget);
        BtnWidget4->setObjectName(QStringLiteral("BtnWidget4"));
        BtnWidget4->setGeometry(QRect(10, 470, 330, 80));
        sizePolicy.setHeightForWidth(BtnWidget4->sizePolicy().hasHeightForWidth());
        BtnWidget4->setSizePolicy(sizePolicy);
        BtnWidget4->setMinimumSize(QSize(330, 80));
        BtnWidget4->setMaximumSize(QSize(330, 80));
        bindingButton = new QPushButton(BtnWidget4);
        bindingButton->setObjectName(QStringLiteral("bindingButton"));
        bindingButton->setGeometry(QRect(30, 20, 120, 40));
        sizePolicy.setHeightForWidth(bindingButton->sizePolicy().hasHeightForWidth());
        bindingButton->setSizePolicy(sizePolicy);
        bindingButton->setMinimumSize(QSize(120, 40));
        bindingButton->setMaximumSize(QSize(120, 40));
        bindingButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));\n"
"			border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}"));
        notBindingButton = new QPushButton(BtnWidget4);
        notBindingButton->setObjectName(QStringLiteral("notBindingButton"));
        notBindingButton->setGeometry(QRect(180, 20, 120, 40));
        sizePolicy.setHeightForWidth(notBindingButton->sizePolicy().hasHeightForWidth());
        notBindingButton->setSizePolicy(sizePolicy);
        notBindingButton->setMinimumSize(QSize(120, 40));
        notBindingButton->setMaximumSize(QSize(120, 40));
        notBindingButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: #FFFFFF;border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE}\n"
"QPushButton:hover,pressed{ background-color: #F4F4F4;border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        clostPushButton = new QPushButton(FilletWidget);
        clostPushButton->setObjectName(QStringLiteral("clostPushButton"));
        clostPushButton->setGeometry(QRect(310, 10, 32, 28));
        clostPushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/ZcloudCommon/image/browser_close_nor.png);}\n"
"QPushButton:hover,pressed{\n"
"border-image: url(:/ZcloudCommon/image/browser_close_hov.png);\n"
"}"));

        verticalLayout->addWidget(FilletWidget);


        retranslateUi(MessageTipDlg);
        QObject::connect(cancelButton, SIGNAL(clicked()), MessageTipDlg, SLOT(reject()));
        QObject::connect(closeButton, SIGNAL(clicked()), MessageTipDlg, SLOT(reject()));
        QObject::connect(bindingButton, SIGNAL(clicked()), MessageTipDlg, SLOT(accept()));
        QObject::connect(updateButton, SIGNAL(clicked()), MessageTipDlg, SLOT(accept()));
        QObject::connect(okButton, SIGNAL(clicked()), MessageTipDlg, SLOT(accept()));
        QObject::connect(noUpdateButton, SIGNAL(clicked()), MessageTipDlg, SLOT(reject()));
        QObject::connect(clostPushButton, SIGNAL(clicked()), MessageTipDlg, SLOT(reject()));
        QObject::connect(notBindingButton, SIGNAL(clicked()), MessageTipDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(MessageTipDlg);
    } // setupUi

    void retranslateUi(QDialog *MessageTipDlg)
    {
        MessageTipDlg->setWindowTitle(QApplication::translate("MessageTipDlg", "MessageTipDlg", 0));
        labelIcon->setText(QString());
        labelTilte->setText(QString());
        labelMsg->setText(QString());
        closeButton->setText(QApplication::translate("MessageTipDlg", "\345\205\263\351\227\255", 0));
        updateButton->setText(QApplication::translate("MessageTipDlg", "\347\253\213\345\215\263\345\215\207\347\272\247", 0));
        noUpdateButton->setText(QApplication::translate("MessageTipDlg", "\346\232\202\344\270\215\345\215\207\347\272\247", 0));
        okButton->setText(QApplication::translate("MessageTipDlg", "\347\241\256\345\256\232", 0));
        cancelButton->setText(QApplication::translate("MessageTipDlg", "\345\217\226\346\266\210", 0));
        bindingButton->setText(QApplication::translate("MessageTipDlg", "\347\231\273\345\275\225\347\273\221\345\256\232", 0));
        notBindingButton->setText(QApplication::translate("MessageTipDlg", "\346\232\202\344\270\215\347\273\221\345\256\232", 0));
        clostPushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MessageTipDlg: public Ui_MessageTipDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGETIPDLG_H
