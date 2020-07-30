/********************************************************************************
** Form generated from reading UI file 'TopToolWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPTOOLWIDGET_H
#define UI_TOPTOOLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopToolWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QWidget *TopWidget;
    QLabel *labelTilte;
    QPushButton *closeButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;

    void setupUi(QWidget *TopToolWidget)
    {
        if (TopToolWidget->objectName().isEmpty())
            TopToolWidget->setObjectName(QStringLiteral("TopToolWidget"));
        TopToolWidget->resize(380, 342);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TopToolWidget->sizePolicy().hasHeightForWidth());
        TopToolWidget->setSizePolicy(sizePolicy);
        TopToolWidget->setMinimumSize(QSize(380, 342));
        TopToolWidget->setMaximumSize(QSize(380, 342));
        verticalLayout = new QVBoxLayout(TopToolWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FilletWidget = new QWidget(TopToolWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(380, 342));
        FilletWidget->setMaximumSize(QSize(380, 342));
        FilletWidget->setStyleSheet(QLatin1String("border-radius:4px;\n"
"background-color: #FCFCFC;"));
        TopWidget = new QWidget(FilletWidget);
        TopWidget->setObjectName(QStringLiteral("TopWidget"));
        TopWidget->setGeometry(QRect(0, 0, 380, 50));
        sizePolicy.setHeightForWidth(TopWidget->sizePolicy().hasHeightForWidth());
        TopWidget->setSizePolicy(sizePolicy);
        TopWidget->setMinimumSize(QSize(380, 50));
        TopWidget->setMaximumSize(QSize(380, 50));
        TopWidget->setStyleSheet(QStringLiteral("QWidget#TopWidget{border-bottom:1px solid #DDDDDD;border-bottom-left-radius:0px;border-bottom-right-radius:0px;}"));
        labelTilte = new QLabel(TopWidget);
        labelTilte->setObjectName(QStringLiteral("labelTilte"));
        labelTilte->setGeometry(QRect(19, 14, 191, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelTilte->sizePolicy().hasHeightForWidth());
        labelTilte->setSizePolicy(sizePolicy1);
        labelTilte->setMinimumSize(QSize(70, 20));
        labelTilte->setMaximumSize(QSize(16777215, 20));
        labelTilte->setStyleSheet(QString::fromUtf8("font: 75 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        closeButton = new QPushButton(TopWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(340, 12, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudDesk/image/close.png);border-radius:none;background-color: rgba(255, 255, 255, 0);}\n"
"\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/close_sel.png);};"));
        scrollArea = new QScrollArea(FilletWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 50, 380, 250));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(380, 250));
        scrollArea->setMaximumSize(QSize(380, 250));
        scrollArea->setStyleSheet(QLatin1String("QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}\n"
"QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}\n"
"QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 250));
        scrollAreaWidgetContents->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(12);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label_18 = new QLabel(FilletWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(92, 305, 20, 20));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setMinimumSize(QSize(20, 20));
        label_18->setMaximumSize(QSize(20, 20));
        label_18->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/icon_service.png);"));
        label_19 = new QLabel(FilletWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(118, 305, 112, 15));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setMinimumSize(QSize(112, 15));
        label_19->setMaximumSize(QSize(112, 15));
        label_19->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#666666;"));
        label_20 = new QLabel(FilletWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(238, 305, 49, 15));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);
        label_20->setMinimumSize(QSize(49, 15));
        label_20->setMaximumSize(QSize(49, 15));
        label_20->setStyleSheet(QString::fromUtf8("font: 75 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1F8BED;"));

        verticalLayout->addWidget(FilletWidget);


        retranslateUi(TopToolWidget);
        QObject::connect(closeButton, SIGNAL(clicked()), TopToolWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(TopToolWidget);
    } // setupUi

    void retranslateUi(QWidget *TopToolWidget)
    {
        TopToolWidget->setWindowTitle(QApplication::translate("TopToolWidget", "TopToolWidget", 0));
        labelTilte->setText(QApplication::translate("TopToolWidget", "\345\234\250\347\272\277\345\256\242\346\234\215", 0));
        closeButton->setText(QString());
        label_18->setText(QString());
        label_19->setText(QApplication::translate("TopToolWidget", "\350\210\252\345\244\251\344\277\241\346\201\257\345\256\242\346\234\215\347\203\255\347\272\277", 0));
        label_20->setText(QApplication::translate("TopToolWidget", "95113", 0));
    } // retranslateUi

};

namespace Ui {
    class TopToolWidget: public Ui_TopToolWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPTOOLWIDGET_H
