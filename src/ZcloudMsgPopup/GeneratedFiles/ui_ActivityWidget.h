/********************************************************************************
** Form generated from reading UI file 'ActivityWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVITYWIDGET_H
#define UI_ACTIVITYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActivityWidget
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *ActivityWidget)
    {
        if (ActivityWidget->objectName().isEmpty())
            ActivityWidget->setObjectName(QStringLiteral("ActivityWidget"));
        ActivityWidget->resize(94, 26);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ActivityWidget->sizePolicy().hasHeightForWidth());
        ActivityWidget->setSizePolicy(sizePolicy);
        ActivityWidget->setMinimumSize(QSize(0, 26));
        ActivityWidget->setMaximumSize(QSize(16777215, 26));
        verticalLayout = new QVBoxLayout(ActivityWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(ActivityWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(0, 26));
        pushButton->setMaximumSize(QSize(16777215, 26));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 242, 239);\n"
"	border-top-left-radius:13px;	\n"
"	border-bottom-left-radius:13px;\n"
"	border-style: solid;\n"
"  	border-width: 1px;\n"
"  	border-color: rgb(244, 236, 232);\n"
"	color: rgb(34, 153, 254);\n"
"	font: 12px \\\"\345\276\256\350\275\257\351\233\205\351\273\221\\\";\n"
"  	padding-left:12px;\n"
"	padding-right:12px;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ZcloudMsgPopup/image/activtyFire.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(16, 26));

        verticalLayout->addWidget(pushButton);


        retranslateUi(ActivityWidget);

        QMetaObject::connectSlotsByName(ActivityWidget);
    } // setupUi

    void retranslateUi(QWidget *ActivityWidget)
    {
        ActivityWidget->setWindowTitle(QApplication::translate("ActivityWidget", "ActivityWidget", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ActivityWidget: public Ui_ActivityWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVITYWIDGET_H
