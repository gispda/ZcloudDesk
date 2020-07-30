/********************************************************************************
** Form generated from reading UI file 'AppCenterWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPCENTERWIDGET_H
#define UI_APPCENTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "AppCenter/AppCenterAtegoryWidget.h"
#include "AppCenter/appcenterhomewidget.h"
#include "AppCenter\AppCenterUUWidget.h"

QT_BEGIN_NAMESPACE

class Ui_AppCenterWidget
{
public:
    QFrame *appCenterFrame;
    QPushButton *mainPushButton;
    QPushButton *categoryPushButton;
    QPushButton *managerPushButton;
    QLineEdit *seekLineEdit;
    QToolButton *downloadButton;
    QPushButton *miniButton;
    QPushButton *closeButton;
    AppCenterHomeWidget *homeWidget;
    AppCenterAtegoryWidget *categoryWidget;
    AppCenterUUWidget *appManagerWidget;

    void setupUi(QWidget *AppCenterWidget)
    {
        if (AppCenterWidget->objectName().isEmpty())
            AppCenterWidget->setObjectName(QStringLiteral("AppCenterWidget"));
        AppCenterWidget->resize(1016, 626);
        AppCenterWidget->setMinimumSize(QSize(1016, 626));
        AppCenterWidget->setMaximumSize(QSize(10080, 6260));
        AppCenterWidget->setStyleSheet(QStringLiteral(""));
        appCenterFrame = new QFrame(AppCenterWidget);
        appCenterFrame->setObjectName(QStringLiteral("appCenterFrame"));
        appCenterFrame->setGeometry(QRect(0, 0, 1016, 626));
        appCenterFrame->setStyleSheet(QStringLiteral("QFrame#appCenterFrame{border-image: url(:/new/imageFile/appCenter_new.png);}"));
        mainPushButton = new QPushButton(appCenterFrame);
        mainPushButton->setObjectName(QStringLiteral("mainPushButton"));
        mainPushButton->setGeometry(QRect(223, 22, 64, 54));
        mainPushButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/new/imageFile/AppCenterPng/rec_nor.png);}\n"
"QPushButton:hover{border-image: url(:/new/imageFile/AppCenterPng/rec_hover.png);}\n"
"QPushButton:checked {border-image: url(:/new/imageFile/AppCenterPng/rec_hov.png);};"));
        mainPushButton->setCheckable(true);
        mainPushButton->setChecked(true);
        mainPushButton->setFlat(true);
        categoryPushButton = new QPushButton(appCenterFrame);
        categoryPushButton->setObjectName(QStringLiteral("categoryPushButton"));
        categoryPushButton->setGeometry(QRect(346, 22, 64, 54));
        categoryPushButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/new/imageFile/AppCenterPng/class_nor.png);}\n"
"QPushButton:hover{border-image: url(:/new/imageFile/AppCenterPng/class_hover.png);}\n"
"QPushButton:checked {border-image: url(:/new/imageFile/AppCenterPng/class_hov.png);};"));
        categoryPushButton->setCheckable(true);
        categoryPushButton->setFlat(true);
        managerPushButton = new QPushButton(appCenterFrame);
        managerPushButton->setObjectName(QStringLiteral("managerPushButton"));
        managerPushButton->setGeometry(QRect(469, 22, 64, 54));
        managerPushButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/new/imageFile/AppCenterPng/desk_nor.png);}\n"
"QPushButton:hover{border-image: url(:/new/imageFile/AppCenterPng/desk_hover.png);}\n"
"QPushButton:checked {border-image: url(:/new/imageFile/AppCenterPng/desk_hov.png);};"));
        managerPushButton->setCheckable(true);
        managerPushButton->setFlat(true);
        seekLineEdit = new QLineEdit(appCenterFrame);
        seekLineEdit->setObjectName(QStringLiteral("seekLineEdit"));
        seekLineEdit->setGeometry(QRect(744, 51, 200, 24));
        seekLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border-image: url(:/new/imageFile/AppCenterPng/search_nor.png);\n"
"	color: rgb(102, 102, 102);\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
""));
        seekLineEdit->setClearButtonEnabled(true);
        downloadButton = new QToolButton(appCenterFrame);
        downloadButton->setObjectName(QStringLiteral("downloadButton"));
        downloadButton->setGeometry(QRect(962, 51, 24, 24));
        downloadButton->setMinimumSize(QSize(24, 24));
        downloadButton->setMaximumSize(QSize(24, 24));
        downloadButton->setStyleSheet(QStringLiteral("QToolButton{border-image: url(:/new/imageFile/AppCenterPng/download_nor.png);}"));
        miniButton = new QPushButton(appCenterFrame);
        miniButton->setObjectName(QStringLiteral("miniButton"));
        miniButton->setGeometry(QRect(934, 15, 32, 28));
        miniButton->setMinimumSize(QSize(32, 28));
        miniButton->setMaximumSize(QSize(32, 28));
        miniButton->setFocusPolicy(Qt::NoFocus);
        miniButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/new/imageFile/AppCenterPng/appcenter_min_nor.png);}\n"
"QPushButton:hover{border-image: url(:/new/imageFile/AppCenterPng/appcenter_min_hov.png);}\n"
"QPushButton:pressed{border-image: url(:/new/imageFile/AppCenterPng/appcenter_min_hov.png);};"));
        closeButton = new QPushButton(appCenterFrame);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(966, 15, 32, 28));
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setFocusPolicy(Qt::NoFocus);
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_nor.png);}\n"
"QPushButton:hover{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_hov.png);}\n"
"QPushButton:pressed{border-image: url(:/new/imageFile/AppCenterPng/appcenter_close_hov.png);};"));
        homeWidget = new AppCenterHomeWidget(appCenterFrame);
        homeWidget->setObjectName(QStringLiteral("homeWidget"));
        homeWidget->setGeometry(QRect(8, 88, 1000, 528));
        categoryWidget = new AppCenterAtegoryWidget(appCenterFrame);
        categoryWidget->setObjectName(QStringLiteral("categoryWidget"));
        categoryWidget->setGeometry(QRect(1080, 190, 1000, 528));
        appManagerWidget = new AppCenterUUWidget(appCenterFrame);
        appManagerWidget->setObjectName(QStringLiteral("appManagerWidget"));
        appManagerWidget->setGeometry(QRect(60, 710, 1000, 528));
        appManagerWidget->setMinimumSize(QSize(1000, 528));
        appManagerWidget->setMaximumSize(QSize(1000, 528));

        retranslateUi(AppCenterWidget);

        QMetaObject::connectSlotsByName(AppCenterWidget);
    } // setupUi

    void retranslateUi(QWidget *AppCenterWidget)
    {
        AppCenterWidget->setWindowTitle(QApplication::translate("AppCenterWidget", "AppCenterWidget", 0));
        mainPushButton->setText(QString());
        categoryPushButton->setText(QString());
        managerPushButton->setText(QString());
        seekLineEdit->setPlaceholderText(QApplication::translate("AppCenterWidget", "\346\220\234\347\264\242", 0));
        downloadButton->setText(QString());
        miniButton->setText(QString());
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AppCenterWidget: public Ui_AppCenterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPCENTERWIDGET_H
