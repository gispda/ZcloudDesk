/********************************************************************************
** Form generated from reading UI file 'MsgRightWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGRIGHTWIDGET_H
#define UI_MSGRIGHTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgRightWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *MsgFilletWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *MsgTopWidget;
    QLabel *labelIcon;
    QLabel *labelTilte;
    QPushButton *closeButton;
    QWidget *MsgBottomWidget;
    QLabel *labelMsgTilte;
    QLabel *labelMsgContent;
    QPushButton *moreButton;

    void setupUi(QWidget *MsgRightWidget)
    {
        if (MsgRightWidget->objectName().isEmpty())
            MsgRightWidget->setObjectName(QStringLiteral("MsgRightWidget"));
        MsgRightWidget->resize(416, 266);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MsgRightWidget->sizePolicy().hasHeightForWidth());
        MsgRightWidget->setSizePolicy(sizePolicy);
        MsgRightWidget->setMinimumSize(QSize(416, 266));
        MsgRightWidget->setMaximumSize(QSize(416, 266));
        MsgRightWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(MsgRightWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        MsgFilletWidget = new QWidget(MsgRightWidget);
        MsgFilletWidget->setObjectName(QStringLiteral("MsgFilletWidget"));
        sizePolicy.setHeightForWidth(MsgFilletWidget->sizePolicy().hasHeightForWidth());
        MsgFilletWidget->setSizePolicy(sizePolicy);
        MsgFilletWidget->setMinimumSize(QSize(400, 250));
        MsgFilletWidget->setMaximumSize(QSize(400, 250));
        MsgFilletWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(MsgFilletWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        MsgTopWidget = new QWidget(MsgFilletWidget);
        MsgTopWidget->setObjectName(QStringLiteral("MsgTopWidget"));
        sizePolicy.setHeightForWidth(MsgTopWidget->sizePolicy().hasHeightForWidth());
        MsgTopWidget->setSizePolicy(sizePolicy);
        MsgTopWidget->setMinimumSize(QSize(400, 40));
        MsgTopWidget->setMaximumSize(QSize(400, 40));
        MsgTopWidget->setStyleSheet(QLatin1String("QWidget#MsgTopWidget{background-color: rgb(245, 247, 254);\n"
"border-top-left-radius:8px;border-top-right-radius:8px;}"));
        labelIcon = new QLabel(MsgTopWidget);
        labelIcon->setObjectName(QStringLiteral("labelIcon"));
        labelIcon->setGeometry(QRect(10, 9, 22, 22));
        sizePolicy.setHeightForWidth(labelIcon->sizePolicy().hasHeightForWidth());
        labelIcon->setSizePolicy(sizePolicy);
        labelIcon->setMinimumSize(QSize(22, 22));
        labelIcon->setMaximumSize(QSize(22, 22));
        labelIcon->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudMsgPopup/image/msg_right_icon.png);"));
        labelTilte = new QLabel(MsgTopWidget);
        labelTilte->setObjectName(QStringLiteral("labelTilte"));
        labelTilte->setGeometry(QRect(40, 10, 200, 20));
        sizePolicy.setHeightForWidth(labelTilte->sizePolicy().hasHeightForWidth());
        labelTilte->setSizePolicy(sizePolicy);
        labelTilte->setMinimumSize(QSize(200, 20));
        labelTilte->setMaximumSize(QSize(200, 20));
        labelTilte->setStyleSheet(QString::fromUtf8("font: 75 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        closeButton = new QPushButton(MsgTopWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(358, 5, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudMsgPopup/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudMsgPopup/image/close_sel.png);};"));

        verticalLayout_2->addWidget(MsgTopWidget);

        MsgBottomWidget = new QWidget(MsgFilletWidget);
        MsgBottomWidget->setObjectName(QStringLiteral("MsgBottomWidget"));
        sizePolicy.setHeightForWidth(MsgBottomWidget->sizePolicy().hasHeightForWidth());
        MsgBottomWidget->setSizePolicy(sizePolicy);
        MsgBottomWidget->setMinimumSize(QSize(400, 210));
        MsgBottomWidget->setMaximumSize(QSize(400, 210));
        MsgBottomWidget->setStyleSheet(QStringLiteral("QWidget#MsgBottomWidget{background-color: rgb(255, 255, 255);border-bottom-left-radius:8px;border-bottom-right-radius:8px;}"));
        labelMsgTilte = new QLabel(MsgBottomWidget);
        labelMsgTilte->setObjectName(QStringLiteral("labelMsgTilte"));
        labelMsgTilte->setGeometry(QRect(68, 14, 264, 24));
        sizePolicy.setHeightForWidth(labelMsgTilte->sizePolicy().hasHeightForWidth());
        labelMsgTilte->setSizePolicy(sizePolicy);
        labelMsgTilte->setMinimumSize(QSize(264, 24));
        labelMsgTilte->setMaximumSize(QSize(264, 24));
        labelMsgTilte->setStyleSheet(QString::fromUtf8("font: 75 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelMsgTilte->setAlignment(Qt::AlignCenter);
        labelMsgContent = new QLabel(MsgBottomWidget);
        labelMsgContent->setObjectName(QStringLiteral("labelMsgContent"));
        labelMsgContent->setGeometry(QRect(36, 52, 322, 80));
        sizePolicy.setHeightForWidth(labelMsgContent->sizePolicy().hasHeightForWidth());
        labelMsgContent->setSizePolicy(sizePolicy);
        labelMsgContent->setMinimumSize(QSize(322, 80));
        labelMsgContent->setMaximumSize(QSize(322, 80));
        labelMsgContent->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#666666;"));
        labelMsgContent->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelMsgContent->setWordWrap(true);
        moreButton = new QPushButton(MsgBottomWidget);
        moreButton->setObjectName(QStringLiteral("moreButton"));
        moreButton->setGeometry(QRect(300, 162, 80, 32));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(moreButton->sizePolicy().hasHeightForWidth());
        moreButton->setSizePolicy(sizePolicy1);
        moreButton->setMinimumSize(QSize(80, 32));
        moreButton->setMaximumSize(QSize(500, 32));
        moreButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));\n"
"			border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}"));

        verticalLayout_2->addWidget(MsgBottomWidget);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addWidget(MsgFilletWidget);


        retranslateUi(MsgRightWidget);

        QMetaObject::connectSlotsByName(MsgRightWidget);
    } // setupUi

    void retranslateUi(QWidget *MsgRightWidget)
    {
        MsgRightWidget->setWindowTitle(QApplication::translate("MsgRightWidget", "MsgRightWidget", 0));
        labelIcon->setText(QString());
        labelTilte->setText(QApplication::translate("MsgRightWidget", "\347\263\273\347\273\237\346\266\210\346\201\257", 0));
        closeButton->setText(QString());
        labelMsgTilte->setText(QString());
        labelMsgContent->setText(QString());
        moreButton->setText(QApplication::translate("MsgRightWidget", "\346\237\245\347\234\213\346\233\264\345\244\232", 0));
    } // retranslateUi

};

namespace Ui {
    class MsgRightWidget: public Ui_MsgRightWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGRIGHTWIDGET_H
