/********************************************************************************
** Form generated from reading UI file 'JoinEntWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINENTWIDGET_H
#define UI_JOINENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JoinEntWidget
{
public:
    QLineEdit *lineEdit;
    QWidget *TopWidget;
    QLabel *labelTitle;
    QPushButton *closeButton;
    QPushButton *searchButton;
    QLabel *labelNoContent;
    QListWidget *listWidget;
    QLabel *labelSpace;
    QWidget *noEntWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *JoinEntWidget)
    {
        if (JoinEntWidget->objectName().isEmpty())
            JoinEntWidget->setObjectName(QStringLiteral("JoinEntWidget"));
        JoinEntWidget->resize(800, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(JoinEntWidget->sizePolicy().hasHeightForWidth());
        JoinEntWidget->setSizePolicy(sizePolicy);
        JoinEntWidget->setMinimumSize(QSize(800, 500));
        JoinEntWidget->setMaximumSize(QSize(800, 500));
        JoinEntWidget->setStyleSheet(QStringLiteral("QDialog#JoinEntWidget{background-color: rgb(252, 252, 252);border-top-right-radius:8px;border-radius:8px;}"));
        lineEdit = new QLineEdit(JoinEntWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 71, 640, 36));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(640, 36));
        lineEdit->setMaximumSize(QSize(640, 36));
        lineEdit->setFocusPolicy(Qt::ClickFocus);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{border-radius:0px;\n"
"border-image: url(:/EntCenterWidget/image/search_nor.png);padding-left:30px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgb(153,153,153);}\n"
"QLineEdit:hover,pressed{border-radius:0px;\n"
"border-image: url(:/EntCenterWidget/image/search_sel.png);}\n"
"QLineEdit:focus{border-radius:0px;\n"
"border-image: url(:/EntCenterWidget/image/search_sel.png);}"));
        TopWidget = new QWidget(JoinEntWidget);
        TopWidget->setObjectName(QStringLiteral("TopWidget"));
        TopWidget->setGeometry(QRect(0, 0, 800, 52));
        sizePolicy.setHeightForWidth(TopWidget->sizePolicy().hasHeightForWidth());
        TopWidget->setSizePolicy(sizePolicy);
        TopWidget->setMinimumSize(QSize(800, 52));
        TopWidget->setMaximumSize(QSize(800, 52));
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
        searchButton = new QPushButton(JoinEntWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(690, 71, 80, 36));
        sizePolicy.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy);
        searchButton->setMinimumSize(QSize(80, 36));
        searchButton->setMaximumSize(QSize(80, 36));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        labelNoContent = new QLabel(JoinEntWidget);
        labelNoContent->setObjectName(QStringLiteral("labelNoContent"));
        labelNoContent->setGeometry(QRect(170, 180, 420, 261));
        sizePolicy.setHeightForWidth(labelNoContent->sizePolicy().hasHeightForWidth());
        labelNoContent->setSizePolicy(sizePolicy);
        labelNoContent->setMinimumSize(QSize(420, 261));
        labelNoContent->setMaximumSize(QSize(420, 261));
        labelNoContent->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/noContent.png);"));
        listWidget = new QListWidget(JoinEntWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(35, 140, 740, 345));
        listWidget->setMinimumSize(QSize(740, 345));
        listWidget->setMaximumSize(QSize(740, 345));
        listWidget->setStyleSheet(QLatin1String("QListWidget{border-bottom-left-radius:0px;}\n"
"QListWidget::Item{background:rgb(255,255,255);}\n"
"QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"));
        labelSpace = new QLabel(JoinEntWidget);
        labelSpace->setObjectName(QStringLiteral("labelSpace"));
        labelSpace->setGeometry(QRect(35, 120, 730, 1));
        sizePolicy.setHeightForWidth(labelSpace->sizePolicy().hasHeightForWidth());
        labelSpace->setSizePolicy(sizePolicy);
        labelSpace->setMinimumSize(QSize(730, 1));
        labelSpace->setMaximumSize(QSize(730, 1));
        labelSpace->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        noEntWidget = new QWidget(JoinEntWidget);
        noEntWidget->setObjectName(QStringLiteral("noEntWidget"));
        noEntWidget->setGeometry(QRect(170, 180, 420, 261));
        sizePolicy.setHeightForWidth(noEntWidget->sizePolicy().hasHeightForWidth());
        noEntWidget->setSizePolicy(sizePolicy);
        noEntWidget->setMinimumSize(QSize(420, 261));
        noEntWidget->setMaximumSize(QSize(420, 261));
        verticalLayout_2 = new QVBoxLayout(noEntWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(noEntWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(170, 116));
        label->setMaximumSize(QSize(170, 116));
        label->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/no_ent.png);"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(noEntWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(0, 15));
        label_2->setMaximumSize(QSize(16777215, 15));
        label_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #999999;\n"
"border-bottom:0px;"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        lineEdit->raise();
        TopWidget->raise();
        searchButton->raise();
        listWidget->raise();
        labelSpace->raise();
        labelNoContent->raise();
        noEntWidget->raise();

        retranslateUi(JoinEntWidget);

        QMetaObject::connectSlotsByName(JoinEntWidget);
    } // setupUi

    void retranslateUi(QWidget *JoinEntWidget)
    {
        JoinEntWidget->setWindowTitle(QApplication::translate("JoinEntWidget", "JoinEntWidget", 0));
        lineEdit->setPlaceholderText(QApplication::translate("JoinEntWidget", "\350\257\267\350\276\223\345\205\245\345\256\214\346\225\264\347\232\204\344\274\201\344\270\232\345\220\215\347\247\260\346\210\226\347\273\237\344\270\200\347\244\276\344\274\232\344\277\241\347\224\250\344\273\243\347\240\201", 0));
        labelTitle->setText(QApplication::translate("JoinEntWidget", "\345\212\240\345\205\245\344\274\201\344\270\232", 0));
        closeButton->setText(QString());
        searchButton->setText(QApplication::translate("JoinEntWidget", "\347\241\256\345\256\232", 0));
        labelNoContent->setText(QString());
        labelSpace->setText(QString());
        label->setText(QString());
        label_2->setText(QApplication::translate("JoinEntWidget", "\346\234\252\346\237\245\350\257\242\345\210\260\350\257\245\344\274\201\344\270\232\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class JoinEntWidget: public Ui_JoinEntWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINENTWIDGET_H
