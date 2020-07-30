/********************************************************************************
** Form generated from reading UI file 'QPayInvoiceDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPAYINVOICEDIALOG_H
#define UI_QPAYINVOICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_PayInvoiceDialog
{
public:
    QToolButton *payToolButton;
    QToolButton *invoiceToolButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *PayInvoiceDialog)
    {
        if (PayInvoiceDialog->objectName().isEmpty())
            PayInvoiceDialog->setObjectName(QStringLiteral("PayInvoiceDialog"));
        PayInvoiceDialog->resize(364, 209);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PayInvoiceDialog->sizePolicy().hasHeightForWidth());
        PayInvoiceDialog->setSizePolicy(sizePolicy);
        PayInvoiceDialog->setMinimumSize(QSize(364, 209));
        PayInvoiceDialog->setMaximumSize(QSize(364, 209));
        PayInvoiceDialog->setStyleSheet(QStringLiteral(""));
        payToolButton = new QToolButton(PayInvoiceDialog);
        payToolButton->setObjectName(QStringLiteral("payToolButton"));
        payToolButton->setGeometry(QRect(6, 32, 181, 177));
        payToolButton->setMinimumSize(QSize(181, 177));
        payToolButton->setMaximumSize(QSize(181, 177));
        payToolButton->setStyleSheet(QLatin1String("QToolButton{border-image: url(:/new/imageFile/icon_zzjf_nor.png);}\n"
"QToolButton:hover{border-image: url(:/new/imageFile/icon_zzjf_sel.png);}\n"
"QToolButton:pressed{border-image: url(:/new/imageFile/icon_zzjf_sel.png);};"));
        invoiceToolButton = new QToolButton(PayInvoiceDialog);
        invoiceToolButton->setObjectName(QStringLiteral("invoiceToolButton"));
        invoiceToolButton->setGeometry(QRect(187, 32, 181, 177));
        invoiceToolButton->setMinimumSize(QSize(181, 177));
        invoiceToolButton->setMaximumSize(QSize(181, 177));
        invoiceToolButton->setStyleSheet(QLatin1String("QToolButton{border-image: url(:/new/imageFile/icon_wyfp_nor.png);}\n"
"QToolButton:hover{border-image: url(:/new/imageFile/icon_wyfp_sel.png);}\n"
"QToolButton:pressed{border-image: url(:/new/imageFile/icon_wyfp_sel.png);};W"));
        pushButton_3 = new QPushButton(PayInvoiceDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 5, 20, 20));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(20, 20));
        pushButton_3->setMaximumSize(QSize(20, 20));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/new/imageFile/gb_nor.png);}\n"
"QPushButton:hover{border-image: url(:/new/imageFile/gb_sel.png);}\n"
"QPushButton:pressed{border-image: url(:/new/imageFile/gb_sel.png);};"));

        retranslateUi(PayInvoiceDialog);
        QObject::connect(pushButton_3, SIGNAL(clicked()), PayInvoiceDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(PayInvoiceDialog);
    } // setupUi

    void retranslateUi(QDialog *PayInvoiceDialog)
    {
        PayInvoiceDialog->setWindowTitle(QApplication::translate("PayInvoiceDialog", "PayInvoiceDialog", 0));
        payToolButton->setText(QString());
        invoiceToolButton->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PayInvoiceDialog: public Ui_PayInvoiceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPAYINVOICEDIALOG_H
