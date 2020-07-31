/********************************************************************************
** Form generated from reading UI file 'ServiceFeeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICEFEEWIDGET_H
#define UI_SERVICEFEEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServiceFeeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *ServiceFilletWidget;
    QLabel *labelIcon;
    QLabel *labelTilte;
    QLabel *labelContent;
    QWidget *MsgBtnWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ServiceFeeWidget)
    {
        if (ServiceFeeWidget->objectName().isEmpty())
            ServiceFeeWidget->setObjectName(QStringLiteral("ServiceFeeWidget"));
        ServiceFeeWidget->resize(596, 346);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ServiceFeeWidget->sizePolicy().hasHeightForWidth());
        ServiceFeeWidget->setSizePolicy(sizePolicy);
        ServiceFeeWidget->setMinimumSize(QSize(596, 346));
        ServiceFeeWidget->setMaximumSize(QSize(596, 346));
        verticalLayout = new QVBoxLayout(ServiceFeeWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        ServiceFilletWidget = new QWidget(ServiceFeeWidget);
        ServiceFilletWidget->setObjectName(QStringLiteral("ServiceFilletWidget"));
        ServiceFilletWidget->setStyleSheet(QLatin1String("QWidget#ServiceFilletWidget{background-color: rgb(255, 255, 255);border-radius:8px;}\n"
""));
        labelIcon = new QLabel(ServiceFilletWidget);
        labelIcon->setObjectName(QStringLiteral("labelIcon"));
        labelIcon->setGeometry(QRect(30, 60, 110, 106));
        sizePolicy.setHeightForWidth(labelIcon->sizePolicy().hasHeightForWidth());
        labelIcon->setSizePolicy(sizePolicy);
        labelIcon->setMinimumSize(QSize(110, 106));
        labelIcon->setMaximumSize(QSize(110, 106));
        labelIcon->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudMsgPopup/image/fee_tip.png);"));
        labelTilte = new QLabel(ServiceFilletWidget);
        labelTilte->setObjectName(QStringLiteral("labelTilte"));
        labelTilte->setGeometry(QRect(189, 59, 350, 19));
        sizePolicy.setHeightForWidth(labelTilte->sizePolicy().hasHeightForWidth());
        labelTilte->setSizePolicy(sizePolicy);
        labelTilte->setMinimumSize(QSize(350, 19));
        labelTilte->setMaximumSize(QSize(350, 19));
        labelTilte->setStyleSheet(QString::fromUtf8("font: 75 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelContent = new QLabel(ServiceFilletWidget);
        labelContent->setObjectName(QStringLiteral("labelContent"));
        labelContent->setGeometry(QRect(190, 106, 350, 134));
        sizePolicy.setHeightForWidth(labelContent->sizePolicy().hasHeightForWidth());
        labelContent->setSizePolicy(sizePolicy);
        labelContent->setMinimumSize(QSize(350, 134));
        labelContent->setMaximumSize(QSize(350, 134));
        labelContent->setStyleSheet(QString::fromUtf8("font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#666666;"));
        labelContent->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelContent->setWordWrap(true);
        MsgBtnWidget = new QWidget(ServiceFilletWidget);
        MsgBtnWidget->setObjectName(QStringLiteral("MsgBtnWidget"));
        MsgBtnWidget->setGeometry(QRect(10, 265, 560, 58));
        sizePolicy.setHeightForWidth(MsgBtnWidget->sizePolicy().hasHeightForWidth());
        MsgBtnWidget->setSizePolicy(sizePolicy);
        MsgBtnWidget->setMinimumSize(QSize(560, 58));
        MsgBtnWidget->setMaximumSize(QSize(560, 58));
        horizontalLayout_2 = new QHBoxLayout(MsgBtnWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(ServiceFilletWidget);


        retranslateUi(ServiceFeeWidget);

        QMetaObject::connectSlotsByName(ServiceFeeWidget);
    } // setupUi

    void retranslateUi(QWidget *ServiceFeeWidget)
    {
        ServiceFeeWidget->setWindowTitle(QApplication::translate("ServiceFeeWidget", "ServiceFeeWidget", 0));
        labelIcon->setText(QString());
        labelTilte->setText(QApplication::translate("ServiceFeeWidget", "\346\234\215\345\212\241\350\264\271\345\210\260\346\234\237\346\217\220\351\206\222", 0));
        labelContent->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ServiceFeeWidget: public Ui_ServiceFeeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICEFEEWIDGET_H
