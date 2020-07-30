/********************************************************************************
** Form generated from reading UI file 'ZBrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZBROWSER_H
#define UI_ZBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "webtabwidget.h"

QT_BEGIN_NAMESPACE

class Ui_ZBrowserClass
{
public:
    QGridLayout *gridLayout;
    QFrame *browserFrame;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *backPushButton;
    QPushButton *forwardPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *flushPushButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *name_label;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *miniPushButton;
    QPushButton *maxPushButton;
    QPushButton *closePushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *progressBar;
    WebTabWidget *tabWidget;

    void setupUi(QWidget *ZBrowserClass)
    {
        if (ZBrowserClass->objectName().isEmpty())
            ZBrowserClass->setObjectName(QStringLiteral("ZBrowserClass"));
        ZBrowserClass->resize(1404, 762);
        gridLayout = new QGridLayout(ZBrowserClass);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(8, 8, 8, 8);
        browserFrame = new QFrame(ZBrowserClass);
        browserFrame->setObjectName(QStringLiteral("browserFrame"));
        browserFrame->setStyleSheet(QLatin1String("QFrame#browserFrame{background-color: rgb(239, 243, 245);\n"
"border-radius:4px;\n"
"}"));
        browserFrame->setFrameShape(QFrame::StyledPanel);
        browserFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(browserFrame);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(browserFrame);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 50));
        frame->setMaximumSize(QSize(16777215, 50));
        frame->setStyleSheet(QStringLiteral("border-radius:4px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(21, 0, 9, 0);
        backPushButton = new QPushButton(frame);
        backPushButton->setObjectName(QStringLiteral("backPushButton"));
        backPushButton->setEnabled(false);
        backPushButton->setMinimumSize(QSize(29, 22));
        backPushButton->setMaximumSize(QSize(29, 22));
        backPushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/Image/left_nor.png);\n"
"}\n"
"QPushButton:hover,pressed{\n"
"	border-image: url(:/Image/left_hov.png);\n"
"}\n"
"QPushButton:!enabled{\n"
"	border-image: url(:/Image/left_off.png);\n"
"}"));
        backPushButton->setIconSize(QSize(8, 14));

        horizontalLayout->addWidget(backPushButton);

        forwardPushButton = new QPushButton(frame);
        forwardPushButton->setObjectName(QStringLiteral("forwardPushButton"));
        forwardPushButton->setEnabled(false);
        forwardPushButton->setMinimumSize(QSize(29, 22));
        forwardPushButton->setMaximumSize(QSize(29, 22));
        forwardPushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/Image/right_nor.png);\n"
"}\n"
"QPushButton:hover,pressed{\n"
"	\n"
"	border-image: url(:/Image/right_hov.png);\n"
"}\n"
"QPushButton:!enabled{\n"
"	border-image: url(:/Image/right_off.png);\n"
"}"));

        horizontalLayout->addWidget(forwardPushButton);

        horizontalSpacer = new QSpacerItem(20, 17, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        flushPushButton = new QPushButton(frame);
        flushPushButton->setObjectName(QStringLiteral("flushPushButton"));
        flushPushButton->setMinimumSize(QSize(30, 24));
        flushPushButton->setMaximumSize(QSize(30, 24));
        flushPushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/Image/refresh_nor.png);\n"
"}\n"
"QPushButton:hover,pressed{\n"
"	border-image: url(:/Image/refresh_hov.png);\n"
"}"));

        horizontalLayout->addWidget(flushPushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        name_label = new QLabel(frame);
        name_label->setObjectName(QStringLiteral("name_label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(name_label->sizePolicy().hasHeightForWidth());
        name_label->setSizePolicy(sizePolicy);
        name_label->setMinimumSize(QSize(0, 40));
        name_label->setMaximumSize(QSize(16777215, 40));
        name_label->setStyleSheet(QLatin1String("font-size:16px;\n"
"font-family:Microsoft YaHei;\n"
"font-weight:bold;\n"
"color:rgba(51,51,51,1);"));
        name_label->setTextFormat(Qt::AutoText);
        name_label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(name_label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        miniPushButton = new QPushButton(frame);
        miniPushButton->setObjectName(QStringLiteral("miniPushButton"));
        miniPushButton->setMinimumSize(QSize(32, 28));
        miniPushButton->setMaximumSize(QSize(32, 28));
        miniPushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	border-image: url(:/Image/browser_mini_nor.png);\n"
"}\n"
"QPushButton:hover,pressed{\n"
"border-image: url(:/Image/browser_mini_hov.png);\n"
"}"));
        miniPushButton->setIconSize(QSize(4, 14));

        horizontalLayout->addWidget(miniPushButton);

        maxPushButton = new QPushButton(frame);
        maxPushButton->setObjectName(QStringLiteral("maxPushButton"));
        maxPushButton->setMinimumSize(QSize(32, 28));
        maxPushButton->setMaximumSize(QSize(32, 28));
        maxPushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/Image/browser_max_nor.png);\n"
"}\n"
"QPushButton:hover,pressed{\n"
"border-image: url(:/Image/browser_max_hov.png);\n"
"}"));
        maxPushButton->setIconSize(QSize(14, 14));

        horizontalLayout->addWidget(maxPushButton);

        closePushButton = new QPushButton(frame);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        closePushButton->setMinimumSize(QSize(32, 28));
        closePushButton->setMaximumSize(QSize(32, 28));
        closePushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/Image/browser_close_nor.png);\n"
"}\n"
"QPushButton:hover,pressed{\n"
"border-image: url(:/Image/browser_close_hov.png);\n"
"}"));

        horizontalLayout->addWidget(closePushButton);


        verticalLayout->addWidget(frame);

        widget = new QWidget(browserFrame);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximumSize(QSize(16777215, 1));
        progressBar->setStyleSheet(QStringLiteral("QProgressBar {border: 0px } QProgressBar::chunk { background-color: red; }"));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);

        verticalLayout_2->addWidget(progressBar);

        tabWidget = new WebTabWidget(widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setStyleSheet(QLatin1String("QTabWidget::tab-bar {\n"
"    left: 60px;\n"
"	background:rgb(235,235,235);\n"
"}\n"
""));

        verticalLayout_2->addWidget(tabWidget);


        verticalLayout->addWidget(widget);


        gridLayout->addWidget(browserFrame, 0, 0, 1, 1);


        retranslateUi(ZBrowserClass);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(ZBrowserClass);
    } // setupUi

    void retranslateUi(QWidget *ZBrowserClass)
    {
        ZBrowserClass->setWindowTitle(QApplication::translate("ZBrowserClass", "ZBrowser", 0));
        backPushButton->setText(QString());
        forwardPushButton->setText(QString());
        flushPushButton->setText(QString());
        name_label->setText(QApplication::translate("ZBrowserClass", "\350\207\264\344\272\221\347\247\221\346\212\200", 0));
        miniPushButton->setText(QString());
        maxPushButton->setText(QString());
        closePushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ZBrowserClass: public Ui_ZBrowserClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZBROWSER_H
