/********************************************************************************
** Form generated from reading UI file 'SwitchAccNewWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWITCHACCNEWWIDGET_H
#define UI_SWITCHACCNEWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SwitchAccNewWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QWidget *TopWidget;
    QLabel *labelTitle;
    QPushButton *closeButton;
    QLabel *labelSpace;
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *joinButton;
    QPushButton *createButton;

    void setupUi(QWidget *SwitchAccNewWidget)
    {
        if (SwitchAccNewWidget->objectName().isEmpty())
            SwitchAccNewWidget->setObjectName(QStringLiteral("SwitchAccNewWidget"));
        SwitchAccNewWidget->resize(816, 516);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SwitchAccNewWidget->sizePolicy().hasHeightForWidth());
        SwitchAccNewWidget->setSizePolicy(sizePolicy);
        SwitchAccNewWidget->setMinimumSize(QSize(816, 516));
        SwitchAccNewWidget->setMaximumSize(QSize(816, 516));
        verticalLayout = new QVBoxLayout(SwitchAccNewWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        FilletWidget = new QWidget(SwitchAccNewWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        FilletWidget->setStyleSheet(QLatin1String("border-radius:8px;\n"
"background-color: rgb(255, 255, 255);"));
        TopWidget = new QWidget(FilletWidget);
        TopWidget->setObjectName(QStringLiteral("TopWidget"));
        TopWidget->setGeometry(QRect(0, 0, 800, 52));
        sizePolicy.setHeightForWidth(TopWidget->sizePolicy().hasHeightForWidth());
        TopWidget->setSizePolicy(sizePolicy);
        TopWidget->setMinimumSize(QSize(800, 52));
        TopWidget->setMaximumSize(QSize(800, 52));
        TopWidget->setStyleSheet(QLatin1String("background-color: rgb(252, 252, 252);\n"
"border-bottom:1px solid rgb(222, 222, 222);\n"
"border-bottom-right-radius:0px;\n"
"border-bottom-left-radius:0px;"));
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
        labelSpace = new QLabel(FilletWidget);
        labelSpace->setObjectName(QStringLiteral("labelSpace"));
        labelSpace->setGeometry(QRect(30, 118, 730, 1));
        sizePolicy.setHeightForWidth(labelSpace->sizePolicy().hasHeightForWidth());
        labelSpace->setSizePolicy(sizePolicy);
        labelSpace->setMinimumSize(QSize(730, 1));
        labelSpace->setMaximumSize(QSize(730, 1));
        labelSpace->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        listWidget = new QListWidget(FilletWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 129, 740, 360));
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMinimumSize(QSize(740, 360));
        listWidget->setMaximumSize(QSize(740, 360));
        listWidget->setStyleSheet(QLatin1String("QListWidget{border-bottom-left-radius:0px;}\n"
"QListWidget::Item{background:rgb(255,255,255);}\n"
"QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        label = new QLabel(FilletWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 240, 246, 105));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(246, 105));
        label->setMaximumSize(QSize(246, 105));
        label->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/icon_zwxx.png);"));
        joinButton = new QPushButton(FilletWidget);
        joinButton->setObjectName(QStringLiteral("joinButton"));
        joinButton->setGeometry(QRect(40, 65, 100, 38));
        sizePolicy.setHeightForWidth(joinButton->sizePolicy().hasHeightForWidth());
        joinButton->setSizePolicy(sizePolicy);
        joinButton->setMinimumSize(QSize(100, 38));
        joinButton->setMaximumSize(QSize(100, 38));
        joinButton->setLayoutDirection(Qt::LeftToRight);
        joinButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);padding-left:8px;}\n"
"QToolButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}"));
        createButton = new QPushButton(FilletWidget);
        createButton->setObjectName(QStringLiteral("createButton"));
        createButton->setGeometry(QRect(180, 65, 100, 38));
        sizePolicy.setHeightForWidth(createButton->sizePolicy().hasHeightForWidth());
        createButton->setSizePolicy(sizePolicy);
        createButton->setMinimumSize(QSize(100, 38));
        createButton->setMaximumSize(QSize(100, 38));
        createButton->setLayoutDirection(Qt::LeftToRight);
        createButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);padding-left:8px;}\n"
"QToolButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}"));

        verticalLayout->addWidget(FilletWidget);


        retranslateUi(SwitchAccNewWidget);

        QMetaObject::connectSlotsByName(SwitchAccNewWidget);
    } // setupUi

    void retranslateUi(QWidget *SwitchAccNewWidget)
    {
        SwitchAccNewWidget->setWindowTitle(QApplication::translate("SwitchAccNewWidget", "SwitchAccWidget", 0));
        labelTitle->setText(QApplication::translate("SwitchAccNewWidget", "\350\264\246\345\217\267\344\274\201\344\270\232", 0));
        closeButton->setText(QString());
        labelSpace->setText(QString());
        label->setText(QString());
        joinButton->setText(QApplication::translate("SwitchAccNewWidget", "\345\212\240\345\205\245\344\274\201\344\270\232", 0));
        createButton->setText(QApplication::translate("SwitchAccNewWidget", "\345\210\233\345\273\272\344\274\201\344\270\232", 0));
    } // retranslateUi

};

namespace Ui {
    class SwitchAccNewWidget: public Ui_SwitchAccNewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCHACCNEWWIDGET_H
