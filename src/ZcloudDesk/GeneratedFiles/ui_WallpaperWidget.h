/********************************************************************************
** Form generated from reading UI file 'WallpaperWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WALLPAPERWIDGET_H
#define UI_WALLPAPERWIDGET_H

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

class Ui_WallpaperWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QWidget *TopWidget;
    QLabel *label;
    QPushButton *closeButton;

    void setupUi(QWidget *WallpaperWidget)
    {
        if (WallpaperWidget->objectName().isEmpty())
            WallpaperWidget->setObjectName(QStringLiteral("WallpaperWidget"));
        WallpaperWidget->resize(1100, 690);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WallpaperWidget->sizePolicy().hasHeightForWidth());
        WallpaperWidget->setSizePolicy(sizePolicy);
        WallpaperWidget->setMinimumSize(QSize(1100, 690));
        WallpaperWidget->setMaximumSize(QSize(1100, 690));
        verticalLayout = new QVBoxLayout(WallpaperWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FilletWidget = new QWidget(WallpaperWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(1100, 690));
        FilletWidget->setStyleSheet(QLatin1String("background:rgba(245,245,245);\n"
"border-radius:8px;"));
        TopWidget = new QWidget(FilletWidget);
        TopWidget->setObjectName(QStringLiteral("TopWidget"));
        TopWidget->setGeometry(QRect(0, 0, 1100, 50));
        sizePolicy.setHeightForWidth(TopWidget->sizePolicy().hasHeightForWidth());
        TopWidget->setSizePolicy(sizePolicy);
        TopWidget->setMinimumSize(QSize(1100, 50));
        TopWidget->setMaximumSize(QSize(1100, 50));
        TopWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-bottom-left-radius:0px;\n"
"border-bottom-right-radius:0px;"));
        label = new QLabel(TopWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 13, 70, 24));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(70, 24));
        label->setMaximumSize(QSize(70, 24));
        label->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/wallpaper.png);"));
        closeButton = new QPushButton(TopWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(1058, 11, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudDesk/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/close_sel.png);};"));

        verticalLayout->addWidget(FilletWidget);


        retranslateUi(WallpaperWidget);

        QMetaObject::connectSlotsByName(WallpaperWidget);
    } // setupUi

    void retranslateUi(QWidget *WallpaperWidget)
    {
        WallpaperWidget->setWindowTitle(QApplication::translate("WallpaperWidget", "WallpaperWidget", 0));
        label->setText(QString());
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WallpaperWidget: public Ui_WallpaperWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WALLPAPERWIDGET_H
