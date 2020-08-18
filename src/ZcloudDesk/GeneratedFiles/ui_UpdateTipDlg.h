/********************************************************************************
** Form generated from reading UI file 'UpdateTipDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATETIPDLG_H
#define UI_UPDATETIPDLG_H

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

class Ui_UpdateTipDlg
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QPushButton *updateButton;
    QPushButton *noUpdateButton;
    QLabel *label;

    void setupUi(QDialog *UpdateTipDlg)
    {
        if (UpdateTipDlg->objectName().isEmpty())
            UpdateTipDlg->setObjectName(QStringLiteral("UpdateTipDlg"));
        UpdateTipDlg->resize(514, 458);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UpdateTipDlg->sizePolicy().hasHeightForWidth());
        UpdateTipDlg->setSizePolicy(sizePolicy);
        UpdateTipDlg->setMinimumSize(QSize(514, 458));
        UpdateTipDlg->setMaximumSize(QSize(514, 458));
        verticalLayout = new QVBoxLayout(UpdateTipDlg);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FilletWidget = new QWidget(UpdateTipDlg);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(350, 280));
        FilletWidget->setMaximumSize(QSize(3500, 2800));
        FilletWidget->setStyleSheet(QLatin1String("border-radius:4px;\n"
"background-color: rgb(255, 255, 255);"));
        updateButton = new QPushButton(FilletWidget);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(107, 380, 120, 40));
        sizePolicy.setHeightForWidth(updateButton->sizePolicy().hasHeightForWidth());
        updateButton->setSizePolicy(sizePolicy);
        updateButton->setMinimumSize(QSize(120, 40));
        updateButton->setMaximumSize(QSize(120, 40));
        updateButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));\n"
"			border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}"));
        noUpdateButton = new QPushButton(FilletWidget);
        noUpdateButton->setObjectName(QStringLiteral("noUpdateButton"));
        noUpdateButton->setGeometry(QRect(287, 380, 120, 40));
        sizePolicy.setHeightForWidth(noUpdateButton->sizePolicy().hasHeightForWidth());
        noUpdateButton->setSizePolicy(sizePolicy);
        noUpdateButton->setMinimumSize(QSize(120, 40));
        noUpdateButton->setMaximumSize(QSize(120, 40));
        noUpdateButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: #FFFFFF;border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE}\n"
"QPushButton:hover,pressed{ background-color: #F4F4F4;border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}"));
        label = new QLabel(FilletWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(2, 2, 510, 454));
        label->setMinimumSize(QSize(510, 454));
        label->setMaximumSize(QSize(510, 454));
        label->setPixmap(QPixmap(QString::fromUtf8(":/ZcloudCommon/image/img_update.png")));
        label->raise();
        noUpdateButton->raise();
        updateButton->raise();

        verticalLayout->addWidget(FilletWidget);


        retranslateUi(UpdateTipDlg);
        QObject::connect(updateButton, SIGNAL(clicked()), UpdateTipDlg, SLOT(accept()));
        QObject::connect(noUpdateButton, SIGNAL(clicked()), UpdateTipDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(UpdateTipDlg);
    } // setupUi

    void retranslateUi(QDialog *UpdateTipDlg)
    {
        UpdateTipDlg->setWindowTitle(QApplication::translate("UpdateTipDlg", "MessageTipDlg", 0));
        updateButton->setText(QApplication::translate("UpdateTipDlg", "\347\253\213\345\215\263\345\215\207\347\272\247", 0));
        noUpdateButton->setText(QApplication::translate("UpdateTipDlg", "\346\232\202\344\270\215\345\215\207\347\272\247", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UpdateTipDlg: public Ui_UpdateTipDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATETIPDLG_H
