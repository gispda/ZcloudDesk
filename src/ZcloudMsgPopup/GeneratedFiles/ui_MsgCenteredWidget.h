/********************************************************************************
** Form generated from reading UI file 'MsgCenteredWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGCENTEREDWIDGET_H
#define UI_MSGCENTEREDWIDGET_H

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

class Ui_MsgCenteredWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *MsgFilletWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labelIcon;
    QLabel *labelTitle;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelMsgTitle;
    QLabel *labelTime;
    QLabel *labelSpace;
    QWidget *MsgContentWidget;
    QWidget *MsgBtnWidget;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *MsgCenteredWidget)
    {
        if (MsgCenteredWidget->objectName().isEmpty())
            MsgCenteredWidget->setObjectName(QStringLiteral("MsgCenteredWidget"));
        MsgCenteredWidget->setWindowModality(Qt::NonModal);
        MsgCenteredWidget->resize(716, 516);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MsgCenteredWidget->sizePolicy().hasHeightForWidth());
        MsgCenteredWidget->setSizePolicy(sizePolicy);
        MsgCenteredWidget->setMinimumSize(QSize(716, 516));
        MsgCenteredWidget->setMaximumSize(QSize(716, 516));
        verticalLayout = new QVBoxLayout(MsgCenteredWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        MsgFilletWidget = new QWidget(MsgCenteredWidget);
        MsgFilletWidget->setObjectName(QStringLiteral("MsgFilletWidget"));
        MsgFilletWidget->setStyleSheet(QLatin1String("QWidget#MsgFilletWidget{background-color: rgb(255, 255, 255);\n"
"border-radius:8px;}\n"
""));
        verticalLayout_4 = new QVBoxLayout(MsgFilletWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(20, 20, 20, 10);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelIcon = new QLabel(MsgFilletWidget);
        labelIcon->setObjectName(QStringLiteral("labelIcon"));
        sizePolicy.setHeightForWidth(labelIcon->sizePolicy().hasHeightForWidth());
        labelIcon->setSizePolicy(sizePolicy);
        labelIcon->setMinimumSize(QSize(30, 30));
        labelIcon->setMaximumSize(QSize(30, 30));
        labelIcon->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudMsgPopup/image/msg_icon.png);"));

        horizontalLayout->addWidget(labelIcon);

        labelTitle = new QLabel(MsgFilletWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        sizePolicy.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy);
        labelTitle->setMinimumSize(QSize(70, 16));
        labelTitle->setMaximumSize(QSize(70, 16));
        labelTitle->setStyleSheet(QString::fromUtf8("font: 75 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1F8BED;"));

        horizontalLayout->addWidget(labelTitle);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        label = new QLabel(MsgFilletWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 20));
        label->setMaximumSize(QSize(16777215, 20));

        verticalLayout_3->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelMsgTitle = new QLabel(MsgFilletWidget);
        labelMsgTitle->setObjectName(QStringLiteral("labelMsgTitle"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelMsgTitle->sizePolicy().hasHeightForWidth());
        labelMsgTitle->setSizePolicy(sizePolicy2);
        labelMsgTitle->setMinimumSize(QSize(0, 20));
        labelMsgTitle->setMaximumSize(QSize(16777215, 16777215));
        labelMsgTitle->setStyleSheet(QString::fromUtf8("font: 75 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelMsgTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelMsgTitle->setWordWrap(true);
        labelMsgTitle->setMargin(0);

        verticalLayout_2->addWidget(labelMsgTitle);

        labelTime = new QLabel(MsgFilletWidget);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        sizePolicy1.setHeightForWidth(labelTime->sizePolicy().hasHeightForWidth());
        labelTime->setSizePolicy(sizePolicy1);
        labelTime->setMinimumSize(QSize(0, 20));
        labelTime->setMaximumSize(QSize(16777215, 20));
        labelTime->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#666666;"));

        verticalLayout_2->addWidget(labelTime);

        labelSpace = new QLabel(MsgFilletWidget);
        labelSpace->setObjectName(QStringLiteral("labelSpace"));
        sizePolicy1.setHeightForWidth(labelSpace->sizePolicy().hasHeightForWidth());
        labelSpace->setSizePolicy(sizePolicy1);
        labelSpace->setMinimumSize(QSize(0, 10));
        labelSpace->setMaximumSize(QSize(16777215, 10));

        verticalLayout_2->addWidget(labelSpace);

        MsgContentWidget = new QWidget(MsgFilletWidget);
        MsgContentWidget->setObjectName(QStringLiteral("MsgContentWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(MsgContentWidget->sizePolicy().hasHeightForWidth());
        MsgContentWidget->setSizePolicy(sizePolicy3);
        MsgContentWidget->setStyleSheet(QStringLiteral("border-bottom-right-radius:0px;"));

        verticalLayout_2->addWidget(MsgContentWidget);


        verticalLayout_3->addLayout(verticalLayout_2);

        MsgBtnWidget = new QWidget(MsgFilletWidget);
        MsgBtnWidget->setObjectName(QStringLiteral("MsgBtnWidget"));
        sizePolicy1.setHeightForWidth(MsgBtnWidget->sizePolicy().hasHeightForWidth());
        MsgBtnWidget->setSizePolicy(sizePolicy1);
        MsgBtnWidget->setMinimumSize(QSize(0, 58));
        MsgBtnWidget->setMaximumSize(QSize(16777215, 58));
        MsgBtnWidget->setStyleSheet(QStringLiteral("border-bottom-right-radius:0px;"));
        horizontalLayout_7 = new QHBoxLayout(MsgBtnWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout_3->addWidget(MsgBtnWidget);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout->addWidget(MsgFilletWidget);


        retranslateUi(MsgCenteredWidget);

        QMetaObject::connectSlotsByName(MsgCenteredWidget);
    } // setupUi

    void retranslateUi(QWidget *MsgCenteredWidget)
    {
        MsgCenteredWidget->setWindowTitle(QApplication::translate("MsgCenteredWidget", "MsgCenteredWidget", 0));
        labelIcon->setText(QString());
        labelTitle->setText(QApplication::translate("MsgCenteredWidget", "\347\263\273\347\273\237\346\266\210\346\201\257", 0));
        label->setText(QString());
        labelMsgTitle->setText(QString());
        labelTime->setText(QString());
        labelSpace->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MsgCenteredWidget: public Ui_MsgCenteredWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGCENTEREDWIDGET_H
