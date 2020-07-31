/********************************************************************************
** Form generated from reading UI file 'PicMsgWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICMSGWIDGET_H
#define UI_PICMSGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PicMsgWidget
{
public:
    QWidget *MsgBtnWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *PicMsgWidget)
    {
        if (PicMsgWidget->objectName().isEmpty())
            PicMsgWidget->setObjectName(QStringLiteral("PicMsgWidget"));
        PicMsgWidget->resize(400, 300);
        PicMsgWidget->setStyleSheet(QStringLiteral(""));
        MsgBtnWidget = new QWidget(PicMsgWidget);
        MsgBtnWidget->setObjectName(QStringLiteral("MsgBtnWidget"));
        MsgBtnWidget->setGeometry(QRect(9, 233, 50, 58));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MsgBtnWidget->sizePolicy().hasHeightForWidth());
        MsgBtnWidget->setSizePolicy(sizePolicy);
        MsgBtnWidget->setMinimumSize(QSize(0, 58));
        MsgBtnWidget->setMaximumSize(QSize(16777215, 58));
        MsgBtnWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(MsgBtnWidget);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 0, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(PicMsgWidget);

        QMetaObject::connectSlotsByName(PicMsgWidget);
    } // setupUi

    void retranslateUi(QWidget *PicMsgWidget)
    {
        PicMsgWidget->setWindowTitle(QApplication::translate("PicMsgWidget", "PicMsgWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class PicMsgWidget: public Ui_PicMsgWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICMSGWIDGET_H
