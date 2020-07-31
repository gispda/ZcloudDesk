/********************************************************************************
** Form generated from reading UI file 'ZcloudDeskUpdater.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZCLOUDDESKUPDATER_H
#define UI_ZCLOUDDESKUPDATER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZcloudDeskUpdaterWidget
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QWidget *TopWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *labelPercent;
    QProgressBar *progressBar;

    void setupUi(QMainWindow *ZcloudDeskUpdaterWidget)
    {
        if (ZcloudDeskUpdaterWidget->objectName().isEmpty())
            ZcloudDeskUpdaterWidget->setObjectName(QStringLiteral("ZcloudDeskUpdaterWidget"));
        ZcloudDeskUpdaterWidget->resize(500, 296);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ZcloudDeskUpdaterWidget->sizePolicy().hasHeightForWidth());
        ZcloudDeskUpdaterWidget->setSizePolicy(sizePolicy);
        ZcloudDeskUpdaterWidget->setMinimumSize(QSize(500, 296));
        ZcloudDeskUpdaterWidget->setMaximumSize(QSize(500, 296));
        centralWidget = new QWidget(ZcloudDeskUpdaterWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(500, 296));
        centralWidget->setMaximumSize(QSize(500, 296));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        FilletWidget = new QWidget(centralWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(484, 280));
        FilletWidget->setMaximumSize(QSize(484, 280));
        FilletWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:4px;\n"
""));
        TopWidget = new QWidget(FilletWidget);
        TopWidget->setObjectName(QStringLiteral("TopWidget"));
        TopWidget->setGeometry(QRect(0, 0, 484, 160));
        sizePolicy.setHeightForWidth(TopWidget->sizePolicy().hasHeightForWidth());
        TopWidget->setSizePolicy(sizePolicy);
        TopWidget->setMinimumSize(QSize(484, 160));
        TopWidget->setMaximumSize(QSize(484, 160));
        TopWidget->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #02A4FD, stop:1 #1F8BED);border-bottom-left-radius:0px;border-bottom-right-radius:0px;"));
        label = new QLabel(TopWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(121, 50, 60, 60));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(60, 60));
        label->setMaximumSize(QSize(60, 60));
        label->setStyleSheet(QLatin1String("border-image: url(:/ZcloudDeskUpdater/Resources/tip.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_2 = new QLabel(TopWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(201, 71, 163, 18));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(163, 18));
        label_2->setMaximumSize(QSize(163, 18));
        label_2->setStyleSheet(QString::fromUtf8("font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        label_3 = new QLabel(FilletWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(167, 200, 120, 16));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(120, 16));
        label_3->setMaximumSize(QSize(120, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102, 102, 102);"));
        labelPercent = new QLabel(FilletWidget);
        labelPercent->setObjectName(QStringLiteral("labelPercent"));
        labelPercent->setGeometry(QRect(290, 200, 40, 16));
        sizePolicy.setHeightForWidth(labelPercent->sizePolicy().hasHeightForWidth());
        labelPercent->setSizePolicy(sizePolicy);
        labelPercent->setMinimumSize(QSize(40, 16));
        labelPercent->setMaximumSize(QSize(40, 16));
        labelPercent->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(102, 102, 102);"));
        progressBar = new QProgressBar(FilletWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(30, 228, 424, 10));
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setMinimumSize(QSize(424, 10));
        progressBar->setMaximumSize(QSize(424, 10));
        progressBar->setStyleSheet(QLatin1String("QProgressBar {border:0px;border-radius:5px; background-color:#ebebeb;}\n"
"QProgressBar::chunk{border:0px;border-radius:5px;background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #02A4FD, stop:1 #1F8BED);}\n"
"QProgressBar {border:0px;border-radius:5px;text-align: center;}"));
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout->addWidget(FilletWidget);

        ZcloudDeskUpdaterWidget->setCentralWidget(centralWidget);

        retranslateUi(ZcloudDeskUpdaterWidget);

        QMetaObject::connectSlotsByName(ZcloudDeskUpdaterWidget);
    } // setupUi

    void retranslateUi(QMainWindow *ZcloudDeskUpdaterWidget)
    {
        ZcloudDeskUpdaterWidget->setWindowTitle(QApplication::translate("ZcloudDeskUpdaterWidget", "ZcloudDeskUpdater", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("ZcloudDeskUpdaterWidget", "\346\243\200\346\265\213\345\210\260\344\272\221\350\264\242\347\250\216\346\226\260\347\211\210\346\234\254", 0));
        label_3->setText(QApplication::translate("ZcloudDeskUpdaterWidget", "\346\255\243\345\234\250\344\270\213\350\275\275\346\234\200\346\226\260\347\211\210\346\234\254", 0));
        labelPercent->setText(QApplication::translate("ZcloudDeskUpdaterWidget", "0%", 0));
    } // retranslateUi

};

namespace Ui {
    class ZcloudDeskUpdaterWidget: public Ui_ZcloudDeskUpdaterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZCLOUDDESKUPDATER_H
