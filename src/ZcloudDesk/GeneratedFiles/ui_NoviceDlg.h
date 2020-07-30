/********************************************************************************
** Form generated from reading UI file 'NoviceDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOVICEDLG_H
#define UI_NOVICEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoviceDlg
{
public:
    QLabel *frame2;
    QLabel *frame;
    QWidget *photoWidget;
    QPushButton *skipPushButton;
    QPushButton *nextPushButton;

    void setupUi(QDialog *NoviceDlg)
    {
        if (NoviceDlg->objectName().isEmpty())
            NoviceDlg->setObjectName(QStringLiteral("NoviceDlg"));
        NoviceDlg->resize(1810, 1119);
        frame2 = new QLabel(NoviceDlg);
        frame2->setObjectName(QStringLiteral("frame2"));
        frame2->setGeometry(QRect(1490, 120, 287, 549));
        frame2->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/Novice/app_class.png);"));
        frame = new QLabel(NoviceDlg);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(1230, 20, 196, 34));
        frame->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/Novice/userCenter_1.png);"));
        photoWidget = new QWidget(NoviceDlg);
        photoWidget->setObjectName(QStringLiteral("photoWidget"));
        photoWidget->setGeometry(QRect(280, 130, 814, 714));
        photoWidget->setStyleSheet(QLatin1String("QWidget#photoWidget{\n"
"border-image: url(:/ZcloudDesk/image/Novice/userCenter.png);\n"
"}"));
        skipPushButton = new QPushButton(photoWidget);
        skipPushButton->setObjectName(QStringLiteral("skipPushButton"));
        skipPushButton->setGeometry(QRect(760, 20, 32, 28));
        skipPushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	border-image: url(:/ZcloudDesk/image/Novice/close_nor.png);\n"
" }\n"
"QPushButton:hover,pressed{\n"
"border-image: url(:/ZcloudDesk/image/Novice/close_hov.png);\n"
"}"));
        nextPushButton = new QPushButton(photoWidget);
        nextPushButton->setObjectName(QStringLiteral("nextPushButton"));
        nextPushButton->setGeometry(QRect(332, 600, 150, 40));
        nextPushButton->setMinimumSize(QSize(150, 40));
        nextPushButton->setMaximumSize(QSize(150, 40));
        nextPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(6, 167, 253, 255), stop:1 rgba(33, 143, 237, 255));\n"
"border-radius:4px;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
" }\n"
"\n"
"QPushButton:hover,pressed{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 255), stop:1 rgba(64, 156, 250, 255));\n"
"border-radius:4px;\n"
"color: rgb(255, 255, 255);\n"
"	font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"};"));

        retranslateUi(NoviceDlg);

        QMetaObject::connectSlotsByName(NoviceDlg);
    } // setupUi

    void retranslateUi(QDialog *NoviceDlg)
    {
        NoviceDlg->setWindowTitle(QApplication::translate("NoviceDlg", "NoviceDlg", 0));
        frame2->setText(QString());
        frame->setText(QString());
        skipPushButton->setText(QString());
        nextPushButton->setText(QApplication::translate("NoviceDlg", "\344\270\213\344\270\200\346\255\245", 0));
    } // retranslateUi

};

namespace Ui {
    class NoviceDlg: public Ui_NoviceDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOVICEDLG_H
