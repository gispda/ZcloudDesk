/********************************************************************************
** Form generated from reading UI file 'AccItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCITEMWIDGET_H
#define UI_ACCITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccItemWidget
{
public:
    QWidget *FilletWidget;
    QLabel *labelAvatar;
    QLabel *labelName;
    QLabel *labelTaxNo;
    QPushButton *switchButton;
    QToolButton *loginedButton;
    QWidget *inReviewWidget;
    QLabel *label;
    QLabel *labelCancel;

    void setupUi(QWidget *AccItemWidget)
    {
        if (AccItemWidget->objectName().isEmpty())
            AccItemWidget->setObjectName(QStringLiteral("AccItemWidget"));
        AccItemWidget->resize(730, 70);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AccItemWidget->sizePolicy().hasHeightForWidth());
        AccItemWidget->setSizePolicy(sizePolicy);
        AccItemWidget->setMinimumSize(QSize(730, 70));
        AccItemWidget->setMaximumSize(QSize(730, 70));
        AccItemWidget->setStyleSheet(QStringLiteral("QWidget#AccItemWidget{background-color: rgb(255, 255, 255);};"));
        FilletWidget = new QWidget(AccItemWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        FilletWidget->setGeometry(QRect(0, 5, 730, 60));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(730, 60));
        FilletWidget->setMaximumSize(QSize(730, 60));
        FilletWidget->setStyleSheet(QLatin1String("QWidget#FilletWidget{background:rgb(252,252,252);border-radius:4px;border:1px solid rgb(235,235,235);}\n"
"QWidget#FilletWidget:hover,pressed{background:rgb(246,251,255);border-radius:4px;border:1px solid rgb(187,223,255);};"));
        labelAvatar = new QLabel(FilletWidget);
        labelAvatar->setObjectName(QStringLiteral("labelAvatar"));
        labelAvatar->setGeometry(QRect(20, 10, 40, 40));
        sizePolicy.setHeightForWidth(labelAvatar->sizePolicy().hasHeightForWidth());
        labelAvatar->setSizePolicy(sizePolicy);
        labelAvatar->setMinimumSize(QSize(40, 40));
        labelAvatar->setMaximumSize(QSize(40, 40));
        labelAvatar->setStyleSheet(QStringLiteral(""));
        labelName = new QLabel(FilletWidget);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(69, 10, 371, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelName->sizePolicy().hasHeightForWidth());
        labelName->setSizePolicy(sizePolicy1);
        labelName->setMinimumSize(QSize(0, 20));
        labelName->setMaximumSize(QSize(16777215, 20));
        labelName->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(51,51,51);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;"));
        labelTaxNo = new QLabel(FilletWidget);
        labelTaxNo->setObjectName(QStringLiteral("labelTaxNo"));
        labelTaxNo->setGeometry(QRect(69, 34, 251, 16));
        sizePolicy1.setHeightForWidth(labelTaxNo->sizePolicy().hasHeightForWidth());
        labelTaxNo->setSizePolicy(sizePolicy1);
        labelTaxNo->setMinimumSize(QSize(0, 16));
        labelTaxNo->setMaximumSize(QSize(16777215, 16));
        labelTaxNo->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(102,102,102);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;"));
        switchButton = new QPushButton(FilletWidget);
        switchButton->setObjectName(QStringLiteral("switchButton"));
        switchButton->setGeometry(QRect(647, 0, 82, 60));
        switchButton->setMinimumSize(QSize(82, 60));
        switchButton->setMaximumSize(QSize(82, 60));
        switchButton->setStyleSheet(QString::fromUtf8("QPushButton{border-top-left-radius:0px;border-bottom-left-radius:0px;background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-top-right-radius:4px;border-bottom-right-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-top-right-radius:4px;border-bottom-right-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}"));
        loginedButton = new QToolButton(FilletWidget);
        loginedButton->setObjectName(QStringLiteral("loginedButton"));
        loginedButton->setGeometry(QRect(550, 0, 82, 60));
        loginedButton->setMinimumSize(QSize(82, 60));
        loginedButton->setMaximumSize(QSize(82, 60));
        loginedButton->setStyleSheet(QString::fromUtf8("border-top-right-radius:4px;border-bottom-right-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#1E8BED;padding-left:5px;\n"
"background-color: rgba(255, 255, 255, 0);border:0px;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/EntCenterWidget/image/notExpired.png"), QSize(), QIcon::Normal, QIcon::Off);
        loginedButton->setIcon(icon);
        loginedButton->setIconSize(QSize(16, 14));
        loginedButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        inReviewWidget = new QWidget(FilletWidget);
        inReviewWidget->setObjectName(QStringLiteral("inReviewWidget"));
        inReviewWidget->setGeometry(QRect(460, 0, 82, 60));
        sizePolicy.setHeightForWidth(inReviewWidget->sizePolicy().hasHeightForWidth());
        inReviewWidget->setSizePolicy(sizePolicy);
        inReviewWidget->setMinimumSize(QSize(82, 60));
        inReviewWidget->setMaximumSize(QSize(82, 60));
        label = new QLabel(inReviewWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(15, 15, 54, 16));
        label->setStyleSheet(QString::fromUtf8("font: 17px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgba(244,114,63,1);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;"));
        label->setAlignment(Qt::AlignCenter);
        labelCancel = new QLabel(inReviewWidget);
        labelCancel->setObjectName(QStringLiteral("labelCancel"));
        labelCancel->setGeometry(QRect(15, 35, 54, 12));
        labelCancel->setCursor(QCursor(Qt::PointingHandCursor));
        labelCancel->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgba(153,153,153,1);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:0px;"));
        labelCancel->setAlignment(Qt::AlignCenter);

        retranslateUi(AccItemWidget);

        QMetaObject::connectSlotsByName(AccItemWidget);
    } // setupUi

    void retranslateUi(QWidget *AccItemWidget)
    {
        AccItemWidget->setWindowTitle(QApplication::translate("AccItemWidget", "AccItemWidget", 0));
        labelAvatar->setText(QString());
        labelName->setText(QString());
        labelTaxNo->setText(QString());
        switchButton->setText(QApplication::translate("AccItemWidget", "\345\210\207\346\215\242", 0));
        loginedButton->setText(QApplication::translate("AccItemWidget", "\345\267\262\347\231\273\345\275\225", 0));
        label->setText(QApplication::translate("AccItemWidget", "\345\256\241\346\240\270\344\270\255", 0));
        labelCancel->setText(QApplication::translate("AccItemWidget", "\345\217\226\346\266\210\345\256\241\346\240\270", 0));
    } // retranslateUi

};

namespace Ui {
    class AccItemWidget: public Ui_AccItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCITEMWIDGET_H
