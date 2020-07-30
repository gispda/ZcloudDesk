/********************************************************************************
** Form generated from reading UI file 'SwitchAccWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWITCHACCWIDGET_H
#define UI_SWITCHACCWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SwitchAccWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QWidget *TopWidget;
    QLabel *labelTitle;
    QPushButton *closeButton;
    QLineEdit *lineEdit;
    QLabel *labelOtherAcc;
    QLabel *labelSpace;
    QListWidget *listWidget;
    QLabel *label;

    void setupUi(QWidget *SwitchAccWidget)
    {
        if (SwitchAccWidget->objectName().isEmpty())
            SwitchAccWidget->setObjectName(QStringLiteral("SwitchAccWidget"));
        SwitchAccWidget->resize(816, 516);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SwitchAccWidget->sizePolicy().hasHeightForWidth());
        SwitchAccWidget->setSizePolicy(sizePolicy);
        SwitchAccWidget->setMinimumSize(QSize(816, 516));
        SwitchAccWidget->setMaximumSize(QSize(816, 516));
        verticalLayout = new QVBoxLayout(SwitchAccWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        FilletWidget = new QWidget(SwitchAccWidget);
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
        lineEdit = new QLineEdit(FilletWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 72, 400, 36));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(400, 36));
        lineEdit->setMaximumSize(QSize(400, 36));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{border-radius:0px;\n"
"border-image: url(:/EntCenterWidget/image/lineEdit.png);padding-left:30px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgb(153,153,153);}\n"
"QLineEdit:hover,pressed{border-radius:0px;\n"
"border-image: url(:/EntCenterWidget/image/lineEdit_sel.png);}\n"
"QLineEdit:focus{border-radius:0px;\n"
"border-image: url(:/EntCenterWidget/image/lineEdit_sel.png);}"));
        labelOtherAcc = new QLabel(FilletWidget);
        labelOtherAcc->setObjectName(QStringLiteral("labelOtherAcc"));
        labelOtherAcc->setGeometry(QRect(445, 82, 85, 14));
        sizePolicy.setHeightForWidth(labelOtherAcc->sizePolicy().hasHeightForWidth());
        labelOtherAcc->setSizePolicy(sizePolicy);
        labelOtherAcc->setMinimumSize(QSize(85, 14));
        labelOtherAcc->setMaximumSize(QSize(85, 14));
        labelOtherAcc->setCursor(QCursor(Qt::PointingHandCursor));
        labelOtherAcc->setStyleSheet(QStringLiteral(""));
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

        verticalLayout->addWidget(FilletWidget);


        retranslateUi(SwitchAccWidget);

        QMetaObject::connectSlotsByName(SwitchAccWidget);
    } // setupUi

    void retranslateUi(QWidget *SwitchAccWidget)
    {
        SwitchAccWidget->setWindowTitle(QApplication::translate("SwitchAccWidget", "SwitchAccWidget", 0));
        labelTitle->setText(QApplication::translate("SwitchAccWidget", "\350\264\246\345\217\267\345\210\207\346\215\242", 0));
        closeButton->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("SwitchAccWidget", "\350\257\267\350\276\223\345\205\245\344\274\201\344\270\232\347\273\237\344\270\200\347\244\276\344\274\232\344\277\241\347\224\250\344\273\243\347\240\201\346\220\234\347\264\242", 0));
        labelOtherAcc->setText(QApplication::translate("SwitchAccWidget", "\345\205\266\344\273\226\350\264\246\345\217\267\347\231\273\345\275\225", 0));
        labelSpace->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SwitchAccWidget: public Ui_SwitchAccWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCHACCWIDGET_H
