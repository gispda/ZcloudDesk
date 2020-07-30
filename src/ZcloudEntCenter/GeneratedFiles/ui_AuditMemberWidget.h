/********************************************************************************
** Form generated from reading UI file 'AuditMemberWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDITMEMBERWIDGET_H
#define UI_AUDITMEMBERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuditMemberWidget
{
public:
    QLabel *label;
    QPushButton *closeButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *AuditMemberWidget)
    {
        if (AuditMemberWidget->objectName().isEmpty())
            AuditMemberWidget->setObjectName(QStringLiteral("AuditMemberWidget"));
        AuditMemberWidget->resize(454, 366);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AuditMemberWidget->sizePolicy().hasHeightForWidth());
        AuditMemberWidget->setSizePolicy(sizePolicy);
        AuditMemberWidget->setMinimumSize(QSize(454, 366));
        AuditMemberWidget->setMaximumSize(QSize(454, 366));
        AuditMemberWidget->setStyleSheet(QStringLiteral("QWidget#AuditMemberWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        label = new QLabel(AuditMemberWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 19, 56, 15));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(56, 15));
        label->setMaximumSize(QSize(56, 15));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        closeButton = new QPushButton(AuditMemberWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(415, 10, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        tableWidget = new QTableWidget(AuditMemberWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 67, 414, 290));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(414, 290));
        tableWidget->setMaximumSize(QSize(414, 290));
        tableWidget->setStyleSheet(QStringLiteral(""));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->setColumnCount(0);

        retranslateUi(AuditMemberWidget);

        QMetaObject::connectSlotsByName(AuditMemberWidget);
    } // setupUi

    void retranslateUi(QWidget *AuditMemberWidget)
    {
        AuditMemberWidget->setWindowTitle(QApplication::translate("AuditMemberWidget", "AuditMemberWidget", 0));
        label->setText(QApplication::translate("AuditMemberWidget", "\346\210\220\345\221\230\345\256\241\346\240\270", 0));
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AuditMemberWidget: public Ui_AuditMemberWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDITMEMBERWIDGET_H
