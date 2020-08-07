/********************************************************************************
** Form generated from reading UI file 'WorkersWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKERSWIDGET_H
#define UI_WORKERSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkersWidget
{
public:
    QListWidget *listWidget;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label;
    QWidget *TopWidget;
    QLabel *labelTitle;
    QPushButton *closeButton;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *previousPageLabel;
    QLabel *label_3;
    QLabel *leftSeparateLabel;
    QLabel *nextPageLabel;
    QLabel *label_7;
    QWidget *centerPagesWidget;
    QWidget *leftPagesWidget;
    QLabel *rightSeparateLabel;
    QWidget *rightPagesWidget;
    QLineEdit *pageLineEdit;

    void setupUi(QWidget *WorkersWidget)
    {
        if (WorkersWidget->objectName().isEmpty())
            WorkersWidget->setObjectName(QStringLiteral("WorkersWidget"));
        WorkersWidget->resize(840, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WorkersWidget->sizePolicy().hasHeightForWidth());
        WorkersWidget->setSizePolicy(sizePolicy);
        WorkersWidget->setMinimumSize(QSize(800, 400));
        WorkersWidget->setMaximumSize(QSize(840, 600));
        WorkersWidget->setStyleSheet(QStringLiteral("QWidget#FinanMemberWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        listWidget = new QListWidget(WorkersWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 116, 780, 431));
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMinimumSize(QSize(740, 310));
        listWidget->setMaximumSize(QSize(780, 600));
        listWidget->setStyleSheet(QLatin1String("QListWidget{border-bottom-left-radius:0px;}\n"
"QListWidget::Item{background:rgb(255,255,255);}"));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        label_6 = new QLabel(WorkersWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(710, 90, 27, 15));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(27, 15));
        label_6->setMaximumSize(QSize(270, 15));
        label_6->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_4 = new QLabel(WorkersWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(450, 90, 27, 15));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(27, 15));
        label_4->setMaximumSize(QSize(270, 15));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label = new QLabel(WorkersWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 90, 60, 15));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(27, 15));
        label->setMaximumSize(QSize(270, 15));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        TopWidget = new QWidget(WorkersWidget);
        TopWidget->setObjectName(QStringLiteral("TopWidget"));
        TopWidget->setGeometry(QRect(0, 16, 840, 52));
        sizePolicy.setHeightForWidth(TopWidget->sizePolicy().hasHeightForWidth());
        TopWidget->setSizePolicy(sizePolicy);
        TopWidget->setMinimumSize(QSize(800, 52));
        TopWidget->setMaximumSize(QSize(840, 52));
        TopWidget->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);\n"
"border-bottom:1px solid rgb(222, 222, 222);\n"
"border-top-right-radius:8px;\n"
"border-top-left-radius:8px;"));
        labelTitle = new QLabel(TopWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(21, 15, 80, 18));
        sizePolicy.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy);
        labelTitle->setMinimumSize(QSize(80, 18));
        labelTitle->setMaximumSize(QSize(80, 18));
        labelTitle->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        closeButton = new QPushButton(TopWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(760, 10, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label_2 = new QLabel(WorkersWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 90, 60, 15));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(27, 15));
        label_2->setMaximumSize(QSize(270, 15));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        label_5 = new QLabel(WorkersWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(550, 90, 60, 15));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(27, 15));
        label_5->setMaximumSize(QSize(270, 15));
        label_5->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;\n"
"border-bottom:0px;"));
        previousPageLabel = new QLabel(WorkersWidget);
        previousPageLabel->setObjectName(QStringLiteral("previousPageLabel"));
        previousPageLabel->setGeometry(QRect(401, 563, 16, 36));
        label_3 = new QLabel(WorkersWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(495, 563, 15, 36));
        leftSeparateLabel = new QLabel(WorkersWidget);
        leftSeparateLabel->setObjectName(QStringLiteral("leftSeparateLabel"));
        leftSeparateLabel->setGeometry(QRect(427, 563, 16, 36));
        nextPageLabel = new QLabel(WorkersWidget);
        nextPageLabel->setObjectName(QStringLiteral("nextPageLabel"));
        nextPageLabel->setGeometry(QRect(479, 563, 16, 36));
        label_7 = new QLabel(WorkersWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(560, 563, 15, 36));
        centerPagesWidget = new QWidget(WorkersWidget);
        centerPagesWidget->setObjectName(QStringLiteral("centerPagesWidget"));
        centerPagesWidget->setGeometry(QRect(443, 563, 10, 36));
        leftPagesWidget = new QWidget(WorkersWidget);
        leftPagesWidget->setObjectName(QStringLiteral("leftPagesWidget"));
        leftPagesWidget->setGeometry(QRect(417, 563, 10, 36));
        rightSeparateLabel = new QLabel(WorkersWidget);
        rightSeparateLabel->setObjectName(QStringLiteral("rightSeparateLabel"));
        rightSeparateLabel->setGeometry(QRect(453, 563, 16, 36));
        rightPagesWidget = new QWidget(WorkersWidget);
        rightPagesWidget->setObjectName(QStringLiteral("rightPagesWidget"));
        rightPagesWidget->setGeometry(QRect(469, 563, 10, 36));
        pageLineEdit = new QLineEdit(WorkersWidget);
        pageLineEdit->setObjectName(QStringLiteral("pageLineEdit"));
        pageLineEdit->setGeometry(QRect(510, 570, 50, 21));
        pageLineEdit->setMinimumSize(QSize(50, 0));
        pageLineEdit->setMaximumSize(QSize(50, 16777215));
        pageLineEdit->setAlignment(Qt::AlignCenter);

        retranslateUi(WorkersWidget);

        QMetaObject::connectSlotsByName(WorkersWidget);
    } // setupUi

    void retranslateUi(QWidget *WorkersWidget)
    {
        WorkersWidget->setWindowTitle(QApplication::translate("WorkersWidget", "FinanMemberWidget", 0));
        label_6->setText(QApplication::translate("WorkersWidget", "\346\223\215\344\275\234", 0));
        label_4->setText(QApplication::translate("WorkersWidget", "\347\212\266\346\200\201", 0));
        label->setText(QApplication::translate("WorkersWidget", "\345\267\245\345\215\225\347\274\226\345\217\267", 0));
        labelTitle->setText(QApplication::translate("WorkersWidget", "\346\210\221\347\232\204\345\267\245\345\215\225", 0));
        closeButton->setText(QString());
        label_2->setText(QApplication::translate("WorkersWidget", "\345\267\245\345\215\225\346\240\207\351\242\230", 0));
        label_5->setText(QApplication::translate("WorkersWidget", "\345\210\233\345\273\272\346\227\266\351\227\264", 0));
#ifndef QT_NO_TOOLTIP
        previousPageLabel->setToolTip(QApplication::translate("WorkersWidget", "\344\270\212\344\270\200\351\241\265", 0));
#endif // QT_NO_TOOLTIP
        previousPageLabel->setText(QApplication::translate("WorkersWidget", "<<", 0));
        label_3->setText(QApplication::translate("WorkersWidget", "\347\254\254", 0));
#ifndef QT_NO_TOOLTIP
        leftSeparateLabel->setToolTip(QApplication::translate("WorkersWidget", "\344\270\213\344\270\200\351\241\265", 0));
#endif // QT_NO_TOOLTIP
        leftSeparateLabel->setText(QApplication::translate("WorkersWidget", "..", 0));
#ifndef QT_NO_TOOLTIP
        nextPageLabel->setToolTip(QApplication::translate("WorkersWidget", "\344\270\213\344\270\200\351\241\265", 0));
#endif // QT_NO_TOOLTIP
        nextPageLabel->setText(QApplication::translate("WorkersWidget", ">>", 0));
        label_7->setText(QApplication::translate("WorkersWidget", "\351\241\265", 0));
#ifndef QT_NO_TOOLTIP
        rightSeparateLabel->setToolTip(QApplication::translate("WorkersWidget", "\344\270\213\344\270\200\351\241\265", 0));
#endif // QT_NO_TOOLTIP
        rightSeparateLabel->setText(QApplication::translate("WorkersWidget", "..", 0));
    } // retranslateUi

};

namespace Ui {
    class WorkersWidget: public Ui_WorkersWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERSWIDGET_H
