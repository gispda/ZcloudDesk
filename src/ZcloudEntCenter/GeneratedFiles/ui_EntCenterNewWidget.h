/********************************************************************************
** Form generated from reading UI file 'EntCenterNewWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTCENTERNEWWIDGET_H
#define UI_ENTCENTERNEWWIDGET_H

#include <AvatarLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EntCenterNewWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QWidget *EntLeftWidget;
    QToolButton *switchButton;
    AvatarLabel *labelAvatar;
    QPushButton *copyTaxButton;
    QLabel *labeltaxno;
    QLabel *labelTaxNo;
    QLabel *labelSpaceLeft;
    QLabel *labelMore;
    QLabel *labelEntInfo;
    QLabel *labelMember;
    QPushButton *entInfoButton;
    QPushButton *memberButton;
    QLabel *labelAddComp;
    QLabel *labelVip;
    QLabel *labelComName;
    QLabel *labeluser;
    QLabel *labelroletype;
    QLabel *labelline;
    QWidget *EntRightWidget;

    void setupUi(QWidget *EntCenterNewWidget)
    {
        if (EntCenterNewWidget->objectName().isEmpty())
            EntCenterNewWidget->setObjectName(QStringLiteral("EntCenterNewWidget"));
        EntCenterNewWidget->resize(1002, 696);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EntCenterNewWidget->sizePolicy().hasHeightForWidth());
        EntCenterNewWidget->setSizePolicy(sizePolicy);
        EntCenterNewWidget->setMinimumSize(QSize(1002, 620));
        EntCenterNewWidget->setMaximumSize(QSize(1002, 6200));
        EntCenterNewWidget->setStyleSheet(QStringLiteral("QWidget#EntCenterWidget{background-color: rgb(255, 255, 255);};"));
        horizontalLayout_2 = new QHBoxLayout(EntCenterNewWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        EntLeftWidget = new QWidget(EntCenterNewWidget);
        EntLeftWidget->setObjectName(QStringLiteral("EntLeftWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(EntLeftWidget->sizePolicy().hasHeightForWidth());
        EntLeftWidget->setSizePolicy(sizePolicy1);
        EntLeftWidget->setMinimumSize(QSize(250, 680));
        EntLeftWidget->setMaximumSize(QSize(250, 680));
        EntLeftWidget->setStyleSheet(QStringLiteral("QWidget#EntLeftWidget{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #EDF4FF, stop:1 #FAFCFF);border-top-left-radius:8px;border-bottom-left-radius:8px;border-right:1px solid #EBEBEB;}"));
        switchButton = new QToolButton(EntLeftWidget);
        switchButton->setObjectName(QStringLiteral("switchButton"));
        switchButton->setGeometry(QRect(75, 229, 100, 38));
        sizePolicy1.setHeightForWidth(switchButton->sizePolicy().hasHeightForWidth());
        switchButton->setSizePolicy(sizePolicy1);
        switchButton->setMinimumSize(QSize(100, 38));
        switchButton->setMaximumSize(QSize(100, 38));
        switchButton->setLayoutDirection(Qt::LeftToRight);
        switchButton->setStyleSheet(QString::fromUtf8("QToolButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);padding-left:8px;}\n"
"QToolButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/EntCenterWidget/image/swtich.png"), QSize(), QIcon::Normal, QIcon::Off);
        switchButton->setIcon(icon);
        switchButton->setIconSize(QSize(16, 14));
        switchButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        labelAvatar = new AvatarLabel(EntLeftWidget);
        labelAvatar->setObjectName(QStringLiteral("labelAvatar"));
        labelAvatar->setGeometry(QRect(95, 59, 60, 60));
        sizePolicy1.setHeightForWidth(labelAvatar->sizePolicy().hasHeightForWidth());
        labelAvatar->setSizePolicy(sizePolicy1);
        labelAvatar->setMinimumSize(QSize(60, 60));
        labelAvatar->setMaximumSize(QSize(60, 60));
        labelAvatar->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/img_tx_d.png);"));
        copyTaxButton = new QPushButton(EntLeftWidget);
        copyTaxButton->setObjectName(QStringLiteral("copyTaxButton"));
        copyTaxButton->setGeometry(QRect(191, 162, 16, 16));
        sizePolicy1.setHeightForWidth(copyTaxButton->sizePolicy().hasHeightForWidth());
        copyTaxButton->setSizePolicy(sizePolicy1);
        copyTaxButton->setMinimumSize(QSize(16, 16));
        copyTaxButton->setMaximumSize(QSize(16, 16));
        copyTaxButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/copy.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/copy_sel.png);}"));
        labeltaxno = new QLabel(EntLeftWidget);
        labeltaxno->setObjectName(QStringLiteral("labeltaxno"));
        labeltaxno->setGeometry(QRect(50, 100, 122, 12));
        sizePolicy1.setHeightForWidth(labeltaxno->sizePolicy().hasHeightForWidth());
        labeltaxno->setSizePolicy(sizePolicy1);
        labeltaxno->setMinimumSize(QSize(122, 12));
        labeltaxno->setMaximumSize(QSize(122, 12));
        labeltaxno->setStyleSheet(QLatin1String("font-size:12px;\n"
"font-family:SourceHanSansCN-Normal,SourceHanSansCN;\n"
"font-weight:400;\n"
"color:rgba(51,51,51,1);\n"
"line-height:18px;"));
        labeltaxno->setAlignment(Qt::AlignCenter);
        labeltaxno->setWordWrap(true);
        labelTaxNo = new QLabel(EntLeftWidget);
        labelTaxNo->setObjectName(QStringLiteral("labelTaxNo"));
        labelTaxNo->setGeometry(QRect(64, 163, 150, 12));
        sizePolicy1.setHeightForWidth(labelTaxNo->sizePolicy().hasHeightForWidth());
        labelTaxNo->setSizePolicy(sizePolicy1);
        labelTaxNo->setMinimumSize(QSize(150, 12));
        labelTaxNo->setMaximumSize(QSize(150, 12));
        labelTaxNo->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelTaxNo->setAlignment(Qt::AlignCenter);
        labelSpaceLeft = new QLabel(EntLeftWidget);
        labelSpaceLeft->setObjectName(QStringLiteral("labelSpaceLeft"));
        labelSpaceLeft->setGeometry(QRect(0, 287, 250, 1));
        sizePolicy1.setHeightForWidth(labelSpaceLeft->sizePolicy().hasHeightForWidth());
        labelSpaceLeft->setSizePolicy(sizePolicy1);
        labelSpaceLeft->setMinimumSize(QSize(250, 1));
        labelSpaceLeft->setMaximumSize(QSize(250, 1));
        labelSpaceLeft->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        labelMore = new QLabel(EntLeftWidget);
        labelMore->setObjectName(QStringLiteral("labelMore"));
        labelMore->setGeometry(QRect(29, 332, 57, 15));
        sizePolicy1.setHeightForWidth(labelMore->sizePolicy().hasHeightForWidth());
        labelMore->setSizePolicy(sizePolicy1);
        labelMore->setMinimumSize(QSize(57, 15));
        labelMore->setMaximumSize(QSize(57, 15));
        labelMore->setStyleSheet(QString::fromUtf8("font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight:bold;\n"
"color:#333333;"));
        labelEntInfo = new QLabel(EntLeftWidget);
        labelEntInfo->setObjectName(QStringLiteral("labelEntInfo"));
        labelEntInfo->setGeometry(QRect(60, 371, 10, 10));
        sizePolicy1.setHeightForWidth(labelEntInfo->sizePolicy().hasHeightForWidth());
        labelEntInfo->setSizePolicy(sizePolicy1);
        labelEntInfo->setMinimumSize(QSize(10, 10));
        labelEntInfo->setMaximumSize(QSize(10, 10));
        labelEntInfo->setStyleSheet(QLatin1String("border:2px solid rgba(223,70,100,1);\n"
"border-radius:5px;"));
        labelMember = new QLabel(EntLeftWidget);
        labelMember->setObjectName(QStringLiteral("labelMember"));
        labelMember->setGeometry(QRect(60, 414, 10, 10));
        sizePolicy1.setHeightForWidth(labelMember->sizePolicy().hasHeightForWidth());
        labelMember->setSizePolicy(sizePolicy1);
        labelMember->setMinimumSize(QSize(10, 10));
        labelMember->setMaximumSize(QSize(10, 10));
        labelMember->setStyleSheet(QLatin1String("border:2px solid rgba(90,168,255,1);\n"
"border-radius:5px;"));
        entInfoButton = new QPushButton(EntLeftWidget);
        entInfoButton->setObjectName(QStringLiteral("entInfoButton"));
        entInfoButton->setGeometry(QRect(80, 360, 80, 30));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(entInfoButton->sizePolicy().hasHeightForWidth());
        entInfoButton->setSizePolicy(sizePolicy2);
        entInfoButton->setMinimumSize(QSize(57, 30));
        entInfoButton->setMaximumSize(QSize(570, 30));
        entInfoButton->setLayoutDirection(Qt::LeftToRight);
        entInfoButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(51, 51, 51, 1);padding-left:-20px;}\n"
"QPushButton:hover,pressed{ background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(31,139,237,1);}"));
        memberButton = new QPushButton(EntLeftWidget);
        memberButton->setObjectName(QStringLiteral("memberButton"));
        memberButton->setGeometry(QRect(80, 403, 80, 30));
        sizePolicy2.setHeightForWidth(memberButton->sizePolicy().hasHeightForWidth());
        memberButton->setSizePolicy(sizePolicy2);
        memberButton->setMinimumSize(QSize(57, 30));
        memberButton->setMaximumSize(QSize(570, 30));
        memberButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(51, 51, 51, 1);padding-left:-20px;}\n"
"QPushButton:hover,pressed{ background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(31,139,237,1);}"));
        labelAddComp = new QLabel(EntLeftWidget);
        labelAddComp->setObjectName(QStringLiteral("labelAddComp"));
        labelAddComp->setGeometry(QRect(180, 195, 81, 14));
        labelAddComp->setMaximumSize(QSize(126, 14));
        labelAddComp->setStyleSheet(QLatin1String("font-size:14px;\n"
"font-family:SourceHanSansCN-Normal,SourceHanSansCN;\n"
"font-weight:400;\n"
"color:rgba(30,139,237,1);\n"
"line-height:21px;"));
        labelVip = new QLabel(EntLeftWidget);
        labelVip->setObjectName(QStringLiteral("labelVip"));
        labelVip->setGeometry(QRect(95, 59, 60, 60));
        sizePolicy1.setHeightForWidth(labelVip->sizePolicy().hasHeightForWidth());
        labelVip->setSizePolicy(sizePolicy1);
        labelVip->setMinimumSize(QSize(60, 60));
        labelVip->setMaximumSize(QSize(60, 60));
        labelVip->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/qyzx_icon_vip_wjr.png);"));
        labelComName = new QLabel(EntLeftWidget);
        labelComName->setObjectName(QStringLiteral("labelComName"));
        labelComName->setGeometry(QRect(55, 139, 140, 14));
        sizePolicy1.setHeightForWidth(labelComName->sizePolicy().hasHeightForWidth());
        labelComName->setSizePolicy(sizePolicy1);
        labelComName->setMinimumSize(QSize(140, 14));
        labelComName->setMaximumSize(QSize(140, 14));
        labelComName->setStyleSheet(QLatin1String("font-size:14px;\n"
"font-family:SourceHanSansCN-Normal,SourceHanSansCN;\n"
"font-weight:400;\n"
"color:rgba(51,51,51,1);\n"
"line-height:21px;"));
        labelComName->setAlignment(Qt::AlignCenter);
        labelComName->setWordWrap(true);
        labeluser = new QLabel(EntLeftWidget);
        labeluser->setObjectName(QStringLiteral("labeluser"));
        labeluser->setGeometry(QRect(79, 195, 60, 14));
        labeluser->setMaximumSize(QSize(126, 14));
        labeluser->setStyleSheet(QLatin1String("font-size:14px;\n"
"font-family:SourceHanSansCN-Normal,SourceHanSansCN;\n"
"font-weight:400;\n"
"color:rgba(102,102,102,1);\n"
"line-height:21px;"));
        labelroletype = new QLabel(EntLeftWidget);
        labelroletype->setObjectName(QStringLiteral("labelroletype"));
        labelroletype->setGeometry(QRect(128, 195, 60, 14));
        labelroletype->setMaximumSize(QSize(126, 14));
        labelroletype->setStyleSheet(QLatin1String("font-size:14px;\n"
"font-family:SourceHanSansCN-Normal,SourceHanSansCN;\n"
"font-weight:400;\n"
"color:rgba(102,102,102,1);\n"
"line-height:21px;"));
        labelline = new QLabel(EntLeftWidget);
        labelline->setObjectName(QStringLiteral("labelline"));
        labelline->setGeometry(QRect(110, 140, 1, 14));
        labelline->setMaximumSize(QSize(126, 14));
        labelline->setStyleSheet(QLatin1String("background:rgba(51,51,51,1);\n"
"opacity:0.3;"));

        horizontalLayout->addWidget(EntLeftWidget);

        EntRightWidget = new QWidget(EntCenterNewWidget);
        EntRightWidget->setObjectName(QStringLiteral("EntRightWidget"));
        sizePolicy1.setHeightForWidth(EntRightWidget->sizePolicy().hasHeightForWidth());
        EntRightWidget->setSizePolicy(sizePolicy1);
        EntRightWidget->setMinimumSize(QSize(750, 680));
        EntRightWidget->setMaximumSize(QSize(750, 680));
        EntRightWidget->setStyleSheet(QStringLiteral("QWidget#EntRightWidget{background-color: rgb(252, 252, 252);border-top-right-radius:8px;border-bottom-right-radius:8px;}"));

        horizontalLayout->addWidget(EntRightWidget);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(EntCenterNewWidget);

        QMetaObject::connectSlotsByName(EntCenterNewWidget);
    } // setupUi

    void retranslateUi(QWidget *EntCenterNewWidget)
    {
        EntCenterNewWidget->setWindowTitle(QApplication::translate("EntCenterNewWidget", "EntCenterWidget", 0));
        switchButton->setText(QApplication::translate("EntCenterNewWidget", "\345\210\207\346\215\242\344\274\201\344\270\232", 0));
        labelAvatar->setText(QString());
#ifndef QT_NO_TOOLTIP
        copyTaxButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        copyTaxButton->setText(QString());
        labeltaxno->setText(QString());
        labelTaxNo->setText(QString());
        labelSpaceLeft->setText(QString());
        labelMore->setText(QApplication::translate("EntCenterNewWidget", "\346\233\264\345\244\232\344\277\241\346\201\257", 0));
        labelEntInfo->setText(QString());
        labelMember->setText(QString());
        entInfoButton->setText(QApplication::translate("EntCenterNewWidget", "\344\274\201\344\270\232\350\265\204\346\226\231", 0));
        memberButton->setText(QApplication::translate("EntCenterNewWidget", "\350\264\242\345\212\241\346\210\220\345\221\230", 0));
        labelAddComp->setText(QApplication::translate("EntCenterNewWidget", "\345\212\240\345\205\245\344\274\201\344\270\232", 0));
        labelVip->setText(QString());
        labelComName->setText(QString());
        labeluser->setText(QString());
        labelroletype->setText(QApplication::translate("EntCenterNewWidget", "\347\256\241\347\220\206\345\221\230", 0));
        labelline->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EntCenterNewWidget: public Ui_EntCenterNewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTCENTERNEWWIDGET_H
