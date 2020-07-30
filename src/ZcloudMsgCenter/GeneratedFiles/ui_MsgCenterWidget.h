/********************************************************************************
** Form generated from reading UI file 'MsgCenterWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGCENTERWIDGET_H
#define UI_MSGCENTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgShadowWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QWidget *MsgLeftBottomWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelNoMsg;
    QListWidget *listWidget;
    QWidget *MsgLeftTopWidget;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *MsgRightTopWidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *minPushButton;
    QPushButton *maxPushButton;
    QPushButton *closePushButton;
    QWidget *MsgRightBottomWidget;
    QWidget *MsgBtnWidget;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *MsgShadowWidget)
    {
        if (MsgShadowWidget->objectName().isEmpty())
            MsgShadowWidget->setObjectName(QStringLiteral("MsgShadowWidget"));
        MsgShadowWidget->resize(1016, 634);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MsgShadowWidget->sizePolicy().hasHeightForWidth());
        MsgShadowWidget->setSizePolicy(sizePolicy);
        MsgShadowWidget->setMinimumSize(QSize(1016, 634));
        MsgShadowWidget->setMaximumSize(QSize(16777215, 16777215));
        MsgShadowWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalLayout_2 = new QHBoxLayout(MsgShadowWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        MsgLeftBottomWidget = new QWidget(MsgShadowWidget);
        MsgLeftBottomWidget->setObjectName(QStringLiteral("MsgLeftBottomWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(MsgLeftBottomWidget->sizePolicy().hasHeightForWidth());
        MsgLeftBottomWidget->setSizePolicy(sizePolicy1);
        MsgLeftBottomWidget->setMinimumSize(QSize(280, 558));
        MsgLeftBottomWidget->setMaximumSize(QSize(280, 16777215));
        MsgLeftBottomWidget->setStyleSheet(QLatin1String("background-color: rgb(246, 247, 255);\n"
"border-right:1px solid #EBEBEB;\n"
"border-bottom-left-radius:8px;\n"
""));
        verticalLayout_2 = new QVBoxLayout(MsgLeftBottomWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 8);
        labelNoMsg = new QLabel(MsgLeftBottomWidget);
        labelNoMsg->setObjectName(QStringLiteral("labelNoMsg"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelNoMsg->sizePolicy().hasHeightForWidth());
        labelNoMsg->setSizePolicy(sizePolicy2);
        labelNoMsg->setMinimumSize(QSize(279, 0));
        labelNoMsg->setMaximumSize(QSize(279, 16777215));
        labelNoMsg->setFocusPolicy(Qt::StrongFocus);
        labelNoMsg->setStyleSheet(QString::fromUtf8("QLabel#labelNoMsg{font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#666666;border-bottom-left-radius:0px;border-right:none;};"));
        labelNoMsg->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelNoMsg);

        listWidget = new QListWidget(MsgLeftBottomWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(280, 0));
        listWidget->setMaximumSize(QSize(280, 16777215));
        listWidget->setFocusPolicy(Qt::StrongFocus);
        listWidget->setStyleSheet(QLatin1String("QListWidget{border-bottom-left-radius:0px;}\n"
"QListWidget::Item{background:#F6F7FF;border-bottom:1px solid #EBEBEB;}\n"
"QListWidget::Item:hover{background:#FFFFFF;}\n"
"QListWidget::item:selected{background:#FFFFFF;}\n"
"QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget->setAutoScrollMargin(16);
        listWidget->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout_2->addWidget(listWidget);


        gridLayout->addWidget(MsgLeftBottomWidget, 1, 0, 1, 1);

        MsgLeftTopWidget = new QWidget(MsgShadowWidget);
        MsgLeftTopWidget->setObjectName(QStringLiteral("MsgLeftTopWidget"));
        sizePolicy2.setHeightForWidth(MsgLeftTopWidget->sizePolicy().hasHeightForWidth());
        MsgLeftTopWidget->setSizePolicy(sizePolicy2);
        MsgLeftTopWidget->setMinimumSize(QSize(280, 60));
        MsgLeftTopWidget->setMaximumSize(QSize(280, 60));
        MsgLeftTopWidget->setStyleSheet(QLatin1String("border-bottom:1px solid #EBEBEB;\n"
"border-right:1px solid #EBEBEB;\n"
"background-color: #FAFBFF;\n"
"border-top-left-radius:8px;\n"
""));
        horizontalLayout_9 = new QHBoxLayout(MsgLeftTopWidget);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        comboBox = new QComboBox(MsgLeftTopWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy3);
        comboBox->setMinimumSize(QSize(90, 30));
        comboBox->setMaximumSize(QSize(150, 30));
        comboBox->setFocusPolicy(Qt::StrongFocus);
        comboBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        comboBox->setLayoutDirection(Qt::LeftToRight);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 0px solid gray;\n"
"	font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#333333;\n"
"	padding-left:center;\n"
"}\n"
"QComboBox::drop-down {\n"
"    border-left-width: 1px;\n"
"	padding-top:5px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(:/ZcloudMsgCenter/image/arrow.png);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"	border-radius:0px;\n"
"	border: 1px solid rgb(161,161,161);\n"
"	padding-top:10px;\n"
"	padding-bottom:10px;\n"
"	outline: 0px;\n"
"	\n"
"}\n"
"QComboBox QAbstractItemView::item {\n"
"    height: 30px;\n"
"	font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:#333333;\n"
"}\n"
" \n"
"QListView::item {\n"
"    background: white;\n"
"	padding-left:center;\n"
"}\n"
" \n"
"QListView::item:hover {\n"
"    background: rgb(245,246,247);\n"
"}"));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        comboBox->setIconSize(QSize(16, 16));
        comboBox->setFrame(false);

        horizontalLayout_8->addWidget(comboBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        gridLayout->addWidget(MsgLeftTopWidget, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        MsgRightTopWidget = new QWidget(MsgShadowWidget);
        MsgRightTopWidget->setObjectName(QStringLiteral("MsgRightTopWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(MsgRightTopWidget->sizePolicy().hasHeightForWidth());
        MsgRightTopWidget->setSizePolicy(sizePolicy4);
        MsgRightTopWidget->setMinimumSize(QSize(0, 60));
        MsgRightTopWidget->setMaximumSize(QSize(16777215, 60));
        MsgRightTopWidget->setStyleSheet(QLatin1String("border-bottom:1px solid #EBEBEB;\n"
"border-top-right-radius:8px;\n"
"background-color: rgb(255, 255, 255);"));
        horizontalLayout_5 = new QHBoxLayout(MsgRightTopWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 20);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 5, -1);
        minPushButton = new QPushButton(MsgRightTopWidget);
        minPushButton->setObjectName(QStringLiteral("minPushButton"));
        sizePolicy2.setHeightForWidth(minPushButton->sizePolicy().hasHeightForWidth());
        minPushButton->setSizePolicy(sizePolicy2);
        minPushButton->setMinimumSize(QSize(32, 28));
        minPushButton->setMaximumSize(QSize(32, 28));
        minPushButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudMsgCenter/image/min.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudMsgCenter/image/min_sel.png);};\n"
"\n"
""));

        horizontalLayout_3->addWidget(minPushButton);

        maxPushButton = new QPushButton(MsgRightTopWidget);
        maxPushButton->setObjectName(QStringLiteral("maxPushButton"));
        sizePolicy2.setHeightForWidth(maxPushButton->sizePolicy().hasHeightForWidth());
        maxPushButton->setSizePolicy(sizePolicy2);
        maxPushButton->setMinimumSize(QSize(32, 28));
        maxPushButton->setMaximumSize(QSize(32, 28));
        maxPushButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudMsgCenter/image/max.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudMsgCenter/image/max_sel.png);};"));

        horizontalLayout_3->addWidget(maxPushButton);

        closePushButton = new QPushButton(MsgRightTopWidget);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        sizePolicy2.setHeightForWidth(closePushButton->sizePolicy().hasHeightForWidth());
        closePushButton->setSizePolicy(sizePolicy2);
        closePushButton->setMinimumSize(QSize(32, 28));
        closePushButton->setMaximumSize(QSize(32, 28));
        closePushButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudMsgCenter/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudMsgCenter/image/close_sel.png);};"));

        horizontalLayout_3->addWidget(closePushButton);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_3->addWidget(MsgRightTopWidget);

        MsgRightBottomWidget = new QWidget(MsgShadowWidget);
        MsgRightBottomWidget->setObjectName(QStringLiteral("MsgRightBottomWidget"));
        MsgRightBottomWidget->setFocusPolicy(Qt::StrongFocus);
        MsgRightBottomWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-bottom-right-radius:0px;"));

        verticalLayout_3->addWidget(MsgRightBottomWidget);

        MsgBtnWidget = new QWidget(MsgShadowWidget);
        MsgBtnWidget->setObjectName(QStringLiteral("MsgBtnWidget"));
        sizePolicy4.setHeightForWidth(MsgBtnWidget->sizePolicy().hasHeightForWidth());
        MsgBtnWidget->setSizePolicy(sizePolicy4);
        MsgBtnWidget->setMinimumSize(QSize(0, 58));
        MsgBtnWidget->setMaximumSize(QSize(16777215, 58));
        MsgBtnWidget->setFocusPolicy(Qt::StrongFocus);
        MsgBtnWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-bottom-right-radius:8px;"));
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


        horizontalLayout->addLayout(verticalLayout_3);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(MsgShadowWidget);

        QMetaObject::connectSlotsByName(MsgShadowWidget);
    } // setupUi

    void retranslateUi(QWidget *MsgShadowWidget)
    {
        MsgShadowWidget->setWindowTitle(QApplication::translate("MsgShadowWidget", "MsgCenterWidget", 0));
        labelNoMsg->setText(QApplication::translate("MsgShadowWidget", "\346\232\202\346\227\240\346\266\210\346\201\257\350\256\260\345\275\225", 0));
#ifndef QT_NO_STATUSTIP
        listWidget->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MsgShadowWidget", "\345\205\250\351\203\250\346\266\210\346\201\257", 0)
         << QApplication::translate("MsgShadowWidget", "\345\267\262\350\257\273\346\266\210\346\201\257", 0)
         << QApplication::translate("MsgShadowWidget", "\346\234\252\350\257\273\346\266\210\346\201\257(0)", 0)
        );
        minPushButton->setText(QString());
        maxPushButton->setText(QString());
        closePushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MsgShadowWidget: public Ui_MsgShadowWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGCENTERWIDGET_H
