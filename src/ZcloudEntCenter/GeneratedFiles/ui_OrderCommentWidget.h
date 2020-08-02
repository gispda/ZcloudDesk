/********************************************************************************
** Form generated from reading UI file 'OrderCommentWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERCOMMENTWIDGET_H
#define UI_ORDERCOMMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderCommentWidget
{
public:
    QPushButton *buttonOK;
    QLabel *labelTitle_3;
    QPushButton *buttonGrade1;
    QPushButton *buttonGrade2;
    QPushButton *buttonGrade3;
    QPushButton *buttonGrade5;
    QPushButton *buttonGrade4;
    QLabel *labelGrade;
    QPushButton *buttonDelay;
    QPushButton *buttonService;
    QPushButton *buttonProfessional;
    QTextEdit *editContent;
    QPushButton *buttonCancel;
    QLineEdit *lineEdit;

    void setupUi(QWidget *OrderCommentWidget)
    {
        if (OrderCommentWidget->objectName().isEmpty())
            OrderCommentWidget->setObjectName(QStringLiteral("OrderCommentWidget"));
        OrderCommentWidget->resize(400, 347);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OrderCommentWidget->sizePolicy().hasHeightForWidth());
        OrderCommentWidget->setSizePolicy(sizePolicy);
        OrderCommentWidget->setMinimumSize(QSize(300, 300));
        OrderCommentWidget->setMaximumSize(QSize(840, 500));
        OrderCommentWidget->setStyleSheet(QStringLiteral("QWidget#FinanMemberWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        buttonOK = new QPushButton(OrderCommentWidget);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));
        buttonOK->setGeometry(QRect(100, 300, 80, 32));
        sizePolicy.setHeightForWidth(buttonOK->sizePolicy().hasHeightForWidth());
        buttonOK->setSizePolicy(sizePolicy);
        buttonOK->setMinimumSize(QSize(72, 32));
        buttonOK->setMaximumSize(QSize(100, 32));
        buttonOK->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        labelTitle_3 = new QLabel(OrderCommentWidget);
        labelTitle_3->setObjectName(QStringLiteral("labelTitle_3"));
        labelTitle_3->setGeometry(QRect(0, 20, 400, 18));
        sizePolicy.setHeightForWidth(labelTitle_3->sizePolicy().hasHeightForWidth());
        labelTitle_3->setSizePolicy(sizePolicy);
        labelTitle_3->setMinimumSize(QSize(80, 18));
        labelTitle_3->setMaximumSize(QSize(400, 18));
        labelTitle_3->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        labelTitle_3->setAlignment(Qt::AlignCenter);
        buttonGrade1 = new QPushButton(OrderCommentWidget);
        buttonGrade1->setObjectName(QStringLiteral("buttonGrade1"));
        buttonGrade1->setGeometry(QRect(60, 80, 40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/EntCenterWidget/image/fafull.ico"), QSize(), QIcon::Normal, QIcon::Off);
        buttonGrade1->setIcon(icon);
        buttonGrade1->setIconSize(QSize(40, 40));
        buttonGrade1->setFlat(true);
        buttonGrade2 = new QPushButton(OrderCommentWidget);
        buttonGrade2->setObjectName(QStringLiteral("buttonGrade2"));
        buttonGrade2->setGeometry(QRect(120, 80, 40, 40));
        buttonGrade2->setIcon(icon);
        buttonGrade2->setIconSize(QSize(40, 40));
        buttonGrade2->setFlat(true);
        buttonGrade3 = new QPushButton(OrderCommentWidget);
        buttonGrade3->setObjectName(QStringLiteral("buttonGrade3"));
        buttonGrade3->setGeometry(QRect(180, 80, 40, 40));
        buttonGrade3->setIcon(icon);
        buttonGrade3->setIconSize(QSize(40, 40));
        buttonGrade3->setFlat(true);
        buttonGrade5 = new QPushButton(OrderCommentWidget);
        buttonGrade5->setObjectName(QStringLiteral("buttonGrade5"));
        buttonGrade5->setGeometry(QRect(300, 80, 40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/EntCenterWidget/image/faspace.ico"), QSize(), QIcon::Normal, QIcon::Off);
        buttonGrade5->setIcon(icon1);
        buttonGrade5->setIconSize(QSize(40, 40));
        buttonGrade5->setFlat(true);
        buttonGrade4 = new QPushButton(OrderCommentWidget);
        buttonGrade4->setObjectName(QStringLiteral("buttonGrade4"));
        buttonGrade4->setGeometry(QRect(240, 80, 40, 40));
        buttonGrade4->setIcon(icon1);
        buttonGrade4->setIconSize(QSize(40, 40));
        buttonGrade4->setFlat(true);
        labelGrade = new QLabel(OrderCommentWidget);
        labelGrade->setObjectName(QStringLiteral("labelGrade"));
        labelGrade->setGeometry(QRect(0, 140, 400, 12));
        labelGrade->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        labelGrade->setAlignment(Qt::AlignCenter);
        buttonDelay = new QPushButton(OrderCommentWidget);
        buttonDelay->setObjectName(QStringLiteral("buttonDelay"));
        buttonDelay->setGeometry(QRect(40, 170, 100, 23));
        buttonDelay->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        buttonService = new QPushButton(OrderCommentWidget);
        buttonService->setObjectName(QStringLiteral("buttonService"));
        buttonService->setGeometry(QRect(150, 170, 100, 23));
        buttonService->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        buttonProfessional = new QPushButton(OrderCommentWidget);
        buttonProfessional->setObjectName(QStringLiteral("buttonProfessional"));
        buttonProfessional->setGeometry(QRect(260, 170, 100, 23));
        buttonProfessional->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        editContent = new QTextEdit(OrderCommentWidget);
        editContent->setObjectName(QStringLiteral("editContent"));
        editContent->setGeometry(QRect(40, 200, 320, 71));
        buttonCancel = new QPushButton(OrderCommentWidget);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setGeometry(QRect(220, 300, 80, 32));
        sizePolicy.setHeightForWidth(buttonCancel->sizePolicy().hasHeightForWidth());
        buttonCancel->setSizePolicy(sizePolicy);
        buttonCancel->setMinimumSize(QSize(72, 32));
        buttonCancel->setMaximumSize(QSize(100, 32));
        buttonCancel->setStyleSheet(QStringLiteral(""));
        lineEdit = new QLineEdit(OrderCommentWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(270, 130, 113, 20));

        retranslateUi(OrderCommentWidget);

        QMetaObject::connectSlotsByName(OrderCommentWidget);
    } // setupUi

    void retranslateUi(QWidget *OrderCommentWidget)
    {
        OrderCommentWidget->setWindowTitle(QApplication::translate("OrderCommentWidget", "FinanMemberWidget", 0));
        buttonOK->setText(QApplication::translate("OrderCommentWidget", "\347\241\256\345\256\232", 0));
        labelTitle_3->setText(QApplication::translate("OrderCommentWidget", "\350\257\267\345\257\271\346\234\254\346\254\241\346\234\215\345\212\241\350\277\233\350\241\214\350\257\204\344\273\267", 0));
        buttonGrade1->setText(QString());
        buttonGrade2->setText(QString());
        buttonGrade3->setText(QString());
        buttonGrade5->setText(QString());
        buttonGrade4->setText(QString());
        labelGrade->setText(QApplication::translate("OrderCommentWidget", "\344\270\200\350\210\254", 0));
        buttonDelay->setText(QApplication::translate("OrderCommentWidget", "\351\227\256\351\242\230\345\244\204\347\220\206\344\270\215\345\217\212\346\227\266", 0));
        buttonService->setText(QApplication::translate("OrderCommentWidget", "\345\267\245\344\275\234\344\272\272\345\221\230\346\200\201\345\272\246\344\270\215\345\245\275", 0));
        buttonProfessional->setText(QApplication::translate("OrderCommentWidget", "\345\267\245\344\275\234\344\272\272\345\221\230\344\270\215\345\244\237\344\270\223\344\270\232", 0));
        editContent->setPlaceholderText(QApplication::translate("OrderCommentWidget", "\345\241\253\345\206\231\346\233\264\345\244\232\347\232\204\345\206\205\345\256\271\357\274\214\344\273\245\345\270\256\345\212\251\346\210\221\344\273\254\346\233\264\345\245\275\347\232\204\344\270\272\346\202\250\346\234\215\345\212\241", 0));
        buttonCancel->setText(QApplication::translate("OrderCommentWidget", "\346\232\202\344\270\215\350\257\204\344\273\267", 0));
    } // retranslateUi

};

namespace Ui {
    class OrderCommentWidget: public Ui_OrderCommentWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERCOMMENTWIDGET_H
