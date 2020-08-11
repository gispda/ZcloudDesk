/********************************************************************************
** Form generated from reading UI file 'InfoCenterWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOCENTERWIDGET_H
#define UI_INFOCENTERWIDGET_H

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

class Ui_InfoCenterWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetTop;
    QLabel *label;
    QPushButton *pushButtonBack;
    QLabel *labelSubTitle;
    QLabel *label_2;
    QPushButton *pushButtonEntCenter;
    QPushButton *pushButtonUserCenter;
    QLabel *labelEntCenter;
    QLabel *labelUserCenter;
    QWidget *widgetCenter;

    void setupUi(QWidget *InfoCenterWidget)
    {
        if (InfoCenterWidget->objectName().isEmpty())
            InfoCenterWidget->setObjectName(QStringLiteral("InfoCenterWidget"));
        InfoCenterWidget->resize(1002, 680);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InfoCenterWidget->sizePolicy().hasHeightForWidth());
        InfoCenterWidget->setSizePolicy(sizePolicy);
        InfoCenterWidget->setMinimumSize(QSize(1002, 620));
        InfoCenterWidget->setMaximumSize(QSize(1002, 680));
        InfoCenterWidget->setStyleSheet(QStringLiteral("QWidget#EntCenterWidget{background-color: rgb(255, 255, 255);};"));
        verticalLayout_2 = new QVBoxLayout(InfoCenterWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetTop = new QWidget(InfoCenterWidget);
        widgetTop->setObjectName(QStringLiteral("widgetTop"));
        widgetTop->setMaximumSize(QSize(1002, 60));
        widgetTop->setStyleSheet(QStringLiteral("background-color: rgb(252, 252, 252);"));
        label = new QLabel(widgetTop);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 0, 2, 60));
        label->setStyleSheet(QStringLiteral("border:2px solid rgba(222,222,222,1);"));
        pushButtonBack = new QPushButton(widgetTop);
        pushButtonBack->setObjectName(QStringLiteral("pushButtonBack"));
        pushButtonBack->setGeometry(QRect(270, 15, 30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/EntCenterWidget/image/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonBack->setIcon(icon);
        pushButtonBack->setFlat(true);
        labelSubTitle = new QLabel(widgetTop);
        labelSubTitle->setObjectName(QStringLiteral("labelSubTitle"));
        labelSubTitle->setGeometry(QRect(310, 15, 300, 30));
        labelSubTitle->setStyleSheet(QString::fromUtf8("font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        label_2 = new QLabel(widgetTop);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(270, 15, 100, 30));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pushButtonEntCenter = new QPushButton(widgetTop);
        pushButtonEntCenter->setObjectName(QStringLiteral("pushButtonEntCenter"));
        pushButtonEntCenter->setGeometry(QRect(10, 15, 120, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        pushButtonEntCenter->setFont(font);
        pushButtonEntCenter->setStyleSheet(QStringLiteral("color:#1E8BED;"));
        pushButtonEntCenter->setFlat(true);
        pushButtonUserCenter = new QPushButton(widgetTop);
        pushButtonUserCenter->setObjectName(QStringLiteral("pushButtonUserCenter"));
        pushButtonUserCenter->setGeometry(QRect(125, 15, 120, 30));
        pushButtonUserCenter->setFont(font);
        pushButtonUserCenter->setStyleSheet(QStringLiteral("color:#000000;"));
        pushButtonUserCenter->setFlat(true);
        labelEntCenter = new QLabel(widgetTop);
        labelEntCenter->setObjectName(QStringLiteral("labelEntCenter"));
        labelEntCenter->setGeometry(QRect(10, 55, 120, 2));
        labelEntCenter->setStyleSheet(QStringLiteral("border:2px solid #1E8BED;"));
        labelUserCenter = new QLabel(widgetTop);
        labelUserCenter->setObjectName(QStringLiteral("labelUserCenter"));
        labelUserCenter->setGeometry(QRect(125, 55, 120, 2));
        labelUserCenter->setStyleSheet(QStringLiteral("border:2px solid #1E8BED;"));

        verticalLayout_2->addWidget(widgetTop);

        widgetCenter = new QWidget(InfoCenterWidget);
        widgetCenter->setObjectName(QStringLiteral("widgetCenter"));
        widgetCenter->setMaximumSize(QSize(1002, 620));
        widgetCenter->setStyleSheet(QStringLiteral("border:2px lineed rgba(222,222,222,1);"));

        verticalLayout_2->addWidget(widgetCenter);


        retranslateUi(InfoCenterWidget);

        QMetaObject::connectSlotsByName(InfoCenterWidget);
    } // setupUi

    void retranslateUi(QWidget *InfoCenterWidget)
    {
        InfoCenterWidget->setWindowTitle(QApplication::translate("InfoCenterWidget", "EntCenterWidget", 0));
        label->setText(QString());
        pushButtonBack->setText(QString());
        labelSubTitle->setText(QApplication::translate("InfoCenterWidget", "\346\240\207\351\242\230", 0));
        label_2->setText(QApplication::translate("InfoCenterWidget", "\351\246\226\351\241\265", 0));
        pushButtonEntCenter->setText(QApplication::translate("InfoCenterWidget", "\344\274\201\344\270\232\344\270\255\345\277\203", 0));
        pushButtonUserCenter->setText(QApplication::translate("InfoCenterWidget", "\347\224\250\346\210\267\344\270\255\345\277\203", 0));
        labelEntCenter->setText(QString());
        labelUserCenter->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InfoCenterWidget: public Ui_InfoCenterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOCENTERWIDGET_H
