/********************************************************************************
** Form generated from reading UI file 'UploadLicenseDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADLICENSEDLG_H
#define UI_UPLOADLICENSEDLG_H

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

class Ui_UploadLicenseDlg
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QLabel *labelTilte;
    QWidget *BtnWidget1;
    QPushButton *buttonOK;
    QPushButton *clostPushButton;
    QLabel *label;
    QLabel *labelLicense;
    QPushButton *labelUpload;

    void setupUi(QDialog *UploadLicenseDlg)
    {
        if (UploadLicenseDlg->objectName().isEmpty())
            UploadLicenseDlg->setObjectName(QStringLiteral("UploadLicenseDlg"));
        UploadLicenseDlg->resize(366, 296);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UploadLicenseDlg->sizePolicy().hasHeightForWidth());
        UploadLicenseDlg->setSizePolicy(sizePolicy);
        UploadLicenseDlg->setMinimumSize(QSize(366, 296));
        UploadLicenseDlg->setMaximumSize(QSize(3660, 2960));
        verticalLayout = new QVBoxLayout(UploadLicenseDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        FilletWidget = new QWidget(UploadLicenseDlg);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(350, 280));
        FilletWidget->setMaximumSize(QSize(3500, 2800));
        FilletWidget->setStyleSheet(QLatin1String("border-radius:4px;\n"
"background-color: rgb(255, 255, 255);"));
        labelTilte = new QLabel(FilletWidget);
        labelTilte->setObjectName(QStringLiteral("labelTilte"));
        labelTilte->setGeometry(QRect(5, 160, 340, 20));
        sizePolicy.setHeightForWidth(labelTilte->sizePolicy().hasHeightForWidth());
        labelTilte->setSizePolicy(sizePolicy);
        labelTilte->setMinimumSize(QSize(340, 20));
        labelTilte->setMaximumSize(QSize(340, 20));
        labelTilte->setStyleSheet(QString::fromUtf8("font: 75 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1F8BED;"));
        labelTilte->setAlignment(Qt::AlignCenter);
        BtnWidget1 = new QWidget(FilletWidget);
        BtnWidget1->setObjectName(QStringLiteral("BtnWidget1"));
        BtnWidget1->setGeometry(QRect(8, 190, 330, 80));
        sizePolicy.setHeightForWidth(BtnWidget1->sizePolicy().hasHeightForWidth());
        BtnWidget1->setSizePolicy(sizePolicy);
        BtnWidget1->setMinimumSize(QSize(330, 80));
        BtnWidget1->setMaximumSize(QSize(330, 80));
        buttonOK = new QPushButton(BtnWidget1);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));
        buttonOK->setGeometry(QRect(110, 20, 120, 40));
        sizePolicy.setHeightForWidth(buttonOK->sizePolicy().hasHeightForWidth());
        buttonOK->setSizePolicy(sizePolicy);
        buttonOK->setMinimumSize(QSize(72, 32));
        buttonOK->setMaximumSize(QSize(200, 100));
        buttonOK->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        clostPushButton = new QPushButton(FilletWidget);
        clostPushButton->setObjectName(QStringLiteral("clostPushButton"));
        clostPushButton->setGeometry(QRect(310, 10, 32, 28));
        clostPushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/ZcloudCommon/image/browser_close_nor.png);}\n"
"QPushButton:hover,pressed{\n"
"border-image: url(:/ZcloudCommon/image/browser_close_hov.png);\n"
"}"));
        label = new QLabel(FilletWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 120, 20));
        labelLicense = new QLabel(FilletWidget);
        labelLicense->setObjectName(QStringLiteral("labelLicense"));
        labelLicense->setGeometry(QRect(5, 30, 340, 150));
        labelUpload = new QPushButton(FilletWidget);
        labelUpload->setObjectName(QStringLiteral("labelUpload"));
        labelUpload->setGeometry(QRect(133, 30, 100, 100));
        labelLicense->raise();
        labelTilte->raise();
        BtnWidget1->raise();
        clostPushButton->raise();
        label->raise();
        labelUpload->raise();

        verticalLayout->addWidget(FilletWidget);


        retranslateUi(UploadLicenseDlg);
        QObject::connect(clostPushButton, SIGNAL(clicked()), UploadLicenseDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(UploadLicenseDlg);
    } // setupUi

    void retranslateUi(QDialog *UploadLicenseDlg)
    {
        UploadLicenseDlg->setWindowTitle(QApplication::translate("UploadLicenseDlg", "MessageTipDlg", 0));
        labelTilte->setText(QApplication::translate("UploadLicenseDlg", "\350\257\267\344\270\212\344\274\2408M\344\273\245\345\206\205\357\274\214JPG/PNG\346\240\274\345\274\217\347\232\204\350\220\245\344\270\232\346\211\247\347\205\247\345\233\276\347\211\207", 0));
        buttonOK->setText(QApplication::translate("UploadLicenseDlg", "\346\217\220\344\272\244", 0));
        clostPushButton->setText(QString());
        label->setText(QApplication::translate("UploadLicenseDlg", "\344\270\212\344\274\240\350\220\245\344\270\232\346\211\247\347\205\247", 0));
        labelLicense->setText(QString());
        labelUpload->setText(QApplication::translate("UploadLicenseDlg", "\344\270\212\344\274\240\345\233\276\347\211\207", 0));
    } // retranslateUi

};

namespace Ui {
    class UploadLicenseDlg: public Ui_UploadLicenseDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADLICENSEDLG_H
