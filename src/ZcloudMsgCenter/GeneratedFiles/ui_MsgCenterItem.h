/********************************************************************************
** Form generated from reading UI file 'MsgCenterItem.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGCENTERITEM_H
#define UI_MSGCENTERITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgCenterItem
{
public:
    QLabel *labelIcon;
    QLabel *labelTitle;
    QLabel *labelTime;
    QPushButton *delMsgButton;
    QLabel *labelContent;

    void setupUi(QWidget *MsgCenterItem)
    {
        if (MsgCenterItem->objectName().isEmpty())
            MsgCenterItem->setObjectName(QStringLiteral("MsgCenterItem"));
        MsgCenterItem->resize(260, 76);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MsgCenterItem->sizePolicy().hasHeightForWidth());
        MsgCenterItem->setSizePolicy(sizePolicy);
        MsgCenterItem->setMinimumSize(QSize(260, 76));
        MsgCenterItem->setMaximumSize(QSize(260, 76));
        MsgCenterItem->setStyleSheet(QLatin1String("QWidget#MsgCenterItem{background:#F6F7FF;}\n"
"QWidget#MsgCenterItem:hover{background:#FFFFFF;}\n"
"QWidget#MsgCenterItem:pressed{background:#FFFFFF;}"));
        labelIcon = new QLabel(MsgCenterItem);
        labelIcon->setObjectName(QStringLiteral("labelIcon"));
        labelIcon->setGeometry(QRect(10, 20, 16, 16));
        sizePolicy.setHeightForWidth(labelIcon->sizePolicy().hasHeightForWidth());
        labelIcon->setSizePolicy(sizePolicy);
        labelIcon->setMinimumSize(QSize(16, 16));
        labelIcon->setMaximumSize(QSize(16, 16));
        labelIcon->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudMsgCenter/image/sys_msg.png);"));
        labelTitle = new QLabel(MsgCenterItem);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(32, 19, 160, 16));
        sizePolicy.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy);
        labelTitle->setMinimumSize(QSize(160, 16));
        labelTitle->setMaximumSize(QSize(160, 16));
        labelTitle->setStyleSheet(QString::fromUtf8("QToolTip{background:rgba(255,255,255,1);border:1px solid rgba(153, 153, 153, 1);border-radius:0px}\n"
"\n"
"QLabel#labelTitle{\n"
"background-color:rgba(255,255,255,0);\n"
"border:0px;\n"
"font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight:400;\n"
"color:#333333;\n"
"}:"));
        labelTime = new QLabel(MsgCenterItem);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setGeometry(QRect(200, 19, 50, 16));
        sizePolicy.setHeightForWidth(labelTime->sizePolicy().hasHeightForWidth());
        labelTime->setSizePolicy(sizePolicy);
        labelTime->setMinimumSize(QSize(50, 16));
        labelTime->setMaximumSize(QSize(50, 16));
        labelTime->setLayoutDirection(Qt::RightToLeft);
        labelTime->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border:0px;\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#999999;"));
        labelTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        delMsgButton = new QPushButton(MsgCenterItem);
        delMsgButton->setObjectName(QStringLiteral("delMsgButton"));
        delMsgButton->setGeometry(QRect(235, 43, 12, 14));
        sizePolicy.setHeightForWidth(delMsgButton->sizePolicy().hasHeightForWidth());
        delMsgButton->setSizePolicy(sizePolicy);
        delMsgButton->setMinimumSize(QSize(12, 14));
        delMsgButton->setMaximumSize(QSize(12, 14));
        delMsgButton->setStyleSheet(QLatin1String("QPushButton{border-bottom-left-radius:0px;border-image: url(:/ZcloudMsgCenter/image/del_msg.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudMsgCenter/image/del_msg_sel.png);};\n"
"\n"
""));
        labelContent = new QLabel(MsgCenterItem);
        labelContent->setObjectName(QStringLiteral("labelContent"));
        labelContent->setGeometry(QRect(32, 43, 180, 14));
        sizePolicy.setHeightForWidth(labelContent->sizePolicy().hasHeightForWidth());
        labelContent->setSizePolicy(sizePolicy);
        labelContent->setMinimumSize(QSize(180, 14));
        labelContent->setMaximumSize(QSize(180, 14));
        labelContent->setStyleSheet(QString::fromUtf8("QToolTip{background:rgba(255,255,255,1);border:1px solid rgba(153, 153, 153, 1);border-radius:0px}\n"
"\n"
"QLabel#labelContent\n"
"{background-color:rgba(255,255,255,0);\n"
"border:0px;\n"
"font:12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight:400;\n"
"color:#999999;\n"
"}"));

        retranslateUi(MsgCenterItem);

        QMetaObject::connectSlotsByName(MsgCenterItem);
    } // setupUi

    void retranslateUi(QWidget *MsgCenterItem)
    {
        MsgCenterItem->setWindowTitle(QApplication::translate("MsgCenterItem", "MsgCenterItem", 0));
        labelIcon->setText(QString());
#ifndef QT_NO_TOOLTIP
        labelTitle->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        labelTitle->setText(QApplication::translate("MsgCenterItem", "\347\263\273\347\273\237\346\266\210\346\201\257", 0));
        labelTime->setText(QApplication::translate("MsgCenterItem", "18/03/21", 0));
        delMsgButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        labelContent->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        labelContent->setText(QApplication::translate("MsgCenterItem", "\346\210\221\346\230\257\345\206\205\345\256\271", 0));
    } // retranslateUi

};

namespace Ui {
    class MsgCenterItem: public Ui_MsgCenterItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGCENTERITEM_H
