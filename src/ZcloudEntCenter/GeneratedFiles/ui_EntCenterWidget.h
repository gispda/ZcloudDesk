/********************************************************************************
** Form generated from reading UI file 'EntCenterWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTCENTERWIDGET_H
#define UI_ENTCENTERWIDGET_H

#include <AvatarLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EntCenterWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QWidget *EntLeftWidget;
    QToolButton *switchButton;
    AvatarLabel *labelAvatar;
    QPushButton *copyTaxButton;
    QLabel *labelComName;
    QLabel *labelTaxNo;
    QLabel *labelSpaceLeft;
    QPushButton *scoreButton;
    QPushButton *couponButton;
    QLabel *labelMore;
    QLabel *labelEntInfo;
    QLabel *labelTransInfo;
    QLabel *labelMember;
    QLabel *labelAccSet;
    QPushButton *entInfoButton;
    QPushButton *transInfoButton;
    QPushButton *memberButton;
    QPushButton *accSetButton;
    QLabel *labelScore;
    QLabel *labelCoupon;
    QLabel *labelCopy;
    QLabel *labelAddComp;
    QLabel *labelVip;
    QWidget *EntRightWidget;
    QLabel *labelSpaceRight;
    QWidget *ServiceFeeWidget;
    QPushButton *ServiceFeeButton;
    QLabel *labelExpired;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *labelFeeTime;
    QLabel *labelFeeTime_2;
    QLabel *label_5;
    QLabel *labelDays;
    QProgressBar *progressBar;
    QLabel *labelNoServerFee;
    QWidget *EntVipWidget;
    QPushButton *EntVipButton;
    QLabel *labelExpired_2;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *SignInWidget;
    QPushButton *SignInButton;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_16;
    QWidget *CompeteDataWidget;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_17;
    QPushButton *CompeteDataButton;
    QPushButton *minButton;
    QPushButton *closeButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *labelFirstName;
    QLabel *labelUserName;
    QLabel *labelUserJob;

    void setupUi(QWidget *EntCenterWidget)
    {
        if (EntCenterWidget->objectName().isEmpty())
            EntCenterWidget->setObjectName(QStringLiteral("EntCenterWidget"));
        EntCenterWidget->resize(1002, 620);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EntCenterWidget->sizePolicy().hasHeightForWidth());
        EntCenterWidget->setSizePolicy(sizePolicy);
        EntCenterWidget->setMinimumSize(QSize(1002, 620));
        EntCenterWidget->setMaximumSize(QSize(1002, 6200));
        EntCenterWidget->setStyleSheet(QStringLiteral("QWidget#EntCenterWidget{background-color: rgb(255, 255, 255);};"));
        horizontalLayout_2 = new QHBoxLayout(EntCenterWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        EntLeftWidget = new QWidget(EntCenterWidget);
        EntLeftWidget->setObjectName(QStringLiteral("EntLeftWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(EntLeftWidget->sizePolicy().hasHeightForWidth());
        EntLeftWidget->setSizePolicy(sizePolicy1);
        EntLeftWidget->setMinimumSize(QSize(250, 618));
        EntLeftWidget->setMaximumSize(QSize(250, 618));
        EntLeftWidget->setStyleSheet(QStringLiteral("QWidget#EntLeftWidget{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #EDF4FF, stop:1 #FAFCFF);border-top-left-radius:8px;border-bottom-left-radius:8px;border-right:1px solid #EBEBEB;}"));
        switchButton = new QToolButton(EntLeftWidget);
        switchButton->setObjectName(QStringLiteral("switchButton"));
        switchButton->setGeometry(QRect(75, 168, 100, 38));
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
        labelAvatar->setGeometry(QRect(95, 30, 60, 60));
        sizePolicy1.setHeightForWidth(labelAvatar->sizePolicy().hasHeightForWidth());
        labelAvatar->setSizePolicy(sizePolicy1);
        labelAvatar->setMinimumSize(QSize(60, 60));
        labelAvatar->setMaximumSize(QSize(60, 60));
        labelAvatar->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/img_tx_d.png);"));
        copyTaxButton = new QPushButton(EntLeftWidget);
        copyTaxButton->setObjectName(QStringLiteral("copyTaxButton"));
        copyTaxButton->setGeometry(QRect(212, 143, 14, 14));
        sizePolicy1.setHeightForWidth(copyTaxButton->sizePolicy().hasHeightForWidth());
        copyTaxButton->setSizePolicy(sizePolicy1);
        copyTaxButton->setMinimumSize(QSize(14, 14));
        copyTaxButton->setMaximumSize(QSize(14, 14));
        copyTaxButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/copy.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/copy_sel.png);}"));
        labelComName = new QLabel(EntLeftWidget);
        labelComName->setObjectName(QStringLiteral("labelComName"));
        labelComName->setGeometry(QRect(21, 100, 210, 35));
        sizePolicy1.setHeightForWidth(labelComName->sizePolicy().hasHeightForWidth());
        labelComName->setSizePolicy(sizePolicy1);
        labelComName->setMinimumSize(QSize(210, 35));
        labelComName->setMaximumSize(QSize(210, 35));
        labelComName->setStyleSheet(QString::fromUtf8("font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight:bold;\n"
"color:#333333;"));
        labelComName->setAlignment(Qt::AlignCenter);
        labelComName->setWordWrap(true);
        labelTaxNo = new QLabel(EntLeftWidget);
        labelTaxNo->setObjectName(QStringLiteral("labelTaxNo"));
        labelTaxNo->setGeometry(QRect(52, 144, 150, 12));
        sizePolicy1.setHeightForWidth(labelTaxNo->sizePolicy().hasHeightForWidth());
        labelTaxNo->setSizePolicy(sizePolicy1);
        labelTaxNo->setMinimumSize(QSize(150, 12));
        labelTaxNo->setMaximumSize(QSize(150, 12));
        labelTaxNo->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelTaxNo->setAlignment(Qt::AlignCenter);
        labelSpaceLeft = new QLabel(EntLeftWidget);
        labelSpaceLeft->setObjectName(QStringLiteral("labelSpaceLeft"));
        labelSpaceLeft->setGeometry(QRect(0, 221, 250, 1));
        sizePolicy1.setHeightForWidth(labelSpaceLeft->sizePolicy().hasHeightForWidth());
        labelSpaceLeft->setSizePolicy(sizePolicy1);
        labelSpaceLeft->setMinimumSize(QSize(250, 1));
        labelSpaceLeft->setMaximumSize(QSize(250, 1));
        labelSpaceLeft->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        scoreButton = new QPushButton(EntLeftWidget);
        scoreButton->setObjectName(QStringLiteral("scoreButton"));
        scoreButton->setGeometry(QRect(60, 251, 20, 20));
        sizePolicy1.setHeightForWidth(scoreButton->sizePolicy().hasHeightForWidth());
        scoreButton->setSizePolicy(sizePolicy1);
        scoreButton->setMinimumSize(QSize(20, 20));
        scoreButton->setMaximumSize(QSize(20, 20));
        scoreButton->setStyleSheet(QStringLiteral("QPushButton{border-image: url(:/EntCenterWidget/image/score.png);}"));
        couponButton = new QPushButton(EntLeftWidget);
        couponButton->setObjectName(QStringLiteral("couponButton"));
        couponButton->setGeometry(QRect(170, 251, 20, 20));
        sizePolicy1.setHeightForWidth(couponButton->sizePolicy().hasHeightForWidth());
        couponButton->setSizePolicy(sizePolicy1);
        couponButton->setMinimumSize(QSize(20, 20));
        couponButton->setMaximumSize(QSize(20, 20));
        couponButton->setStyleSheet(QStringLiteral("QPushButton{border-image: url(:/EntCenterWidget/image/coupon.png);}"));
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
        labelTransInfo = new QLabel(EntLeftWidget);
        labelTransInfo->setObjectName(QStringLiteral("labelTransInfo"));
        labelTransInfo->setGeometry(QRect(60, 414, 10, 10));
        sizePolicy1.setHeightForWidth(labelTransInfo->sizePolicy().hasHeightForWidth());
        labelTransInfo->setSizePolicy(sizePolicy1);
        labelTransInfo->setMinimumSize(QSize(10, 10));
        labelTransInfo->setMaximumSize(QSize(10, 10));
        labelTransInfo->setStyleSheet(QLatin1String("border:2px solid rgba(48,196,48,1);\n"
"border-radius:5px;"));
        labelMember = new QLabel(EntLeftWidget);
        labelMember->setObjectName(QStringLiteral("labelMember"));
        labelMember->setGeometry(QRect(60, 455, 10, 10));
        sizePolicy1.setHeightForWidth(labelMember->sizePolicy().hasHeightForWidth());
        labelMember->setSizePolicy(sizePolicy1);
        labelMember->setMinimumSize(QSize(10, 10));
        labelMember->setMaximumSize(QSize(10, 10));
        labelMember->setStyleSheet(QLatin1String("border:2px solid rgba(90,168,255,1);\n"
"border-radius:5px;"));
        labelAccSet = new QLabel(EntLeftWidget);
        labelAccSet->setObjectName(QStringLiteral("labelAccSet"));
        labelAccSet->setGeometry(QRect(60, 497, 10, 10));
        sizePolicy1.setHeightForWidth(labelAccSet->sizePolicy().hasHeightForWidth());
        labelAccSet->setSizePolicy(sizePolicy1);
        labelAccSet->setMinimumSize(QSize(10, 10));
        labelAccSet->setMaximumSize(QSize(10, 10));
        labelAccSet->setStyleSheet(QLatin1String("border:2px solid rgba(223,149,70,1);\n"
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
        transInfoButton = new QPushButton(EntLeftWidget);
        transInfoButton->setObjectName(QStringLiteral("transInfoButton"));
        transInfoButton->setGeometry(QRect(80, 403, 80, 30));
        sizePolicy2.setHeightForWidth(transInfoButton->sizePolicy().hasHeightForWidth());
        transInfoButton->setSizePolicy(sizePolicy2);
        transInfoButton->setMinimumSize(QSize(57, 30));
        transInfoButton->setMaximumSize(QSize(570, 30));
        transInfoButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(51, 51, 51, 1);padding-left:-20px;}\n"
"QPushButton:hover,pressed{ background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(31,139,237,1);}"));
        memberButton = new QPushButton(EntLeftWidget);
        memberButton->setObjectName(QStringLiteral("memberButton"));
        memberButton->setGeometry(QRect(80, 444, 80, 30));
        sizePolicy2.setHeightForWidth(memberButton->sizePolicy().hasHeightForWidth());
        memberButton->setSizePolicy(sizePolicy2);
        memberButton->setMinimumSize(QSize(57, 30));
        memberButton->setMaximumSize(QSize(570, 30));
        memberButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(51, 51, 51, 1);padding-left:-20px;}\n"
"QPushButton:hover,pressed{ background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(31,139,237,1);}"));
        accSetButton = new QPushButton(EntLeftWidget);
        accSetButton->setObjectName(QStringLiteral("accSetButton"));
        accSetButton->setGeometry(QRect(80, 486, 80, 30));
        sizePolicy2.setHeightForWidth(accSetButton->sizePolicy().hasHeightForWidth());
        accSetButton->setSizePolicy(sizePolicy2);
        accSetButton->setMinimumSize(QSize(57, 30));
        accSetButton->setMaximumSize(QSize(570, 30));
        accSetButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(51, 51, 51, 1);padding-left:-20px;}\n"
"QPushButton:hover,pressed{ background-color:rgba(255,255,255,0);font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(31,139,237,1);}"));
        labelScore = new QLabel(EntLeftWidget);
        labelScore->setObjectName(QStringLiteral("labelScore"));
        labelScore->setGeometry(QRect(45, 281, 50, 13));
        sizePolicy1.setHeightForWidth(labelScore->sizePolicy().hasHeightForWidth());
        labelScore->setSizePolicy(sizePolicy1);
        labelScore->setMinimumSize(QSize(50, 13));
        labelScore->setMaximumSize(QSize(50, 13));
        labelScore->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#666666;"));
        labelScore->setAlignment(Qt::AlignCenter);
        labelCoupon = new QLabel(EntLeftWidget);
        labelCoupon->setObjectName(QStringLiteral("labelCoupon"));
        labelCoupon->setGeometry(QRect(155, 280, 50, 13));
        sizePolicy1.setHeightForWidth(labelCoupon->sizePolicy().hasHeightForWidth());
        labelCoupon->setSizePolicy(sizePolicy1);
        labelCoupon->setMinimumSize(QSize(50, 13));
        labelCoupon->setMaximumSize(QSize(50, 13));
        labelCoupon->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#666666;"));
        labelCoupon->setAlignment(Qt::AlignCenter);
        labelCopy = new QLabel(EntLeftWidget);
        labelCopy->setObjectName(QStringLiteral("labelCopy"));
        labelCopy->setGeometry(QRect(200, 114, 42, 20));
        sizePolicy1.setHeightForWidth(labelCopy->sizePolicy().hasHeightForWidth());
        labelCopy->setSizePolicy(sizePolicy1);
        labelCopy->setMinimumSize(QSize(42, 20));
        labelCopy->setMaximumSize(QSize(42, 20));
        labelCopy->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 169, 255);\n"
"font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#FFFFFF;"));
        labelCopy->setAlignment(Qt::AlignCenter);
        labelAddComp = new QLabel(EntLeftWidget);
        labelAddComp->setObjectName(QStringLiteral("labelAddComp"));
        labelAddComp->setGeometry(QRect(97, 130, 61, 21));
        labelAddComp->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1E8BED;"));
        labelVip = new QLabel(EntLeftWidget);
        labelVip->setObjectName(QStringLiteral("labelVip"));
        labelVip->setGeometry(QRect(95, 30, 60, 60));
        sizePolicy1.setHeightForWidth(labelVip->sizePolicy().hasHeightForWidth());
        labelVip->setSizePolicy(sizePolicy1);
        labelVip->setMinimumSize(QSize(60, 60));
        labelVip->setMaximumSize(QSize(60, 60));
        labelVip->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/qyzx_icon_vip_wjr.png);"));

        horizontalLayout->addWidget(EntLeftWidget);

        EntRightWidget = new QWidget(EntCenterWidget);
        EntRightWidget->setObjectName(QStringLiteral("EntRightWidget"));
        sizePolicy1.setHeightForWidth(EntRightWidget->sizePolicy().hasHeightForWidth());
        EntRightWidget->setSizePolicy(sizePolicy1);
        EntRightWidget->setMinimumSize(QSize(750, 618));
        EntRightWidget->setMaximumSize(QSize(750, 618));
        EntRightWidget->setStyleSheet(QStringLiteral("QWidget#EntRightWidget{background-color: rgb(252, 252, 252);border-top-right-radius:8px;border-bottom-right-radius:8px;}"));
        labelSpaceRight = new QLabel(EntRightWidget);
        labelSpaceRight->setObjectName(QStringLiteral("labelSpaceRight"));
        labelSpaceRight->setGeometry(QRect(0, 80, 750, 1));
        sizePolicy1.setHeightForWidth(labelSpaceRight->sizePolicy().hasHeightForWidth());
        labelSpaceRight->setSizePolicy(sizePolicy1);
        labelSpaceRight->setMinimumSize(QSize(750, 1));
        labelSpaceRight->setMaximumSize(QSize(750, 1));
        labelSpaceRight->setStyleSheet(QStringLiteral("background-color: rgb(235, 235, 235);"));
        ServiceFeeWidget = new QWidget(EntRightWidget);
        ServiceFeeWidget->setObjectName(QStringLiteral("ServiceFeeWidget"));
        ServiceFeeWidget->setGeometry(QRect(20, 140, 710, 80));
        sizePolicy1.setHeightForWidth(ServiceFeeWidget->sizePolicy().hasHeightForWidth());
        ServiceFeeWidget->setSizePolicy(sizePolicy1);
        ServiceFeeWidget->setMinimumSize(QSize(710, 80));
        ServiceFeeWidget->setMaximumSize(QSize(710, 80));
        ServiceFeeWidget->setStyleSheet(QLatin1String("QWidget#ServiceFeeWidget{background-color: rgb(252, 252, 252);border:1px solid rgba(235,235,235,1);\n"
"border-radius:10px;}"));
        ServiceFeeButton = new QPushButton(ServiceFeeWidget);
        ServiceFeeButton->setObjectName(QStringLiteral("ServiceFeeButton"));
        ServiceFeeButton->setGeometry(QRect(619, 24, 72, 32));
        sizePolicy1.setHeightForWidth(ServiceFeeButton->sizePolicy().hasHeightForWidth());
        ServiceFeeButton->setSizePolicy(sizePolicy1);
        ServiceFeeButton->setMinimumSize(QSize(72, 32));
        ServiceFeeButton->setMaximumSize(QSize(72, 32));
        ServiceFeeButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        labelExpired = new QLabel(ServiceFeeWidget);
        labelExpired->setObjectName(QStringLiteral("labelExpired"));
        labelExpired->setGeometry(QRect(20, 19, 16, 16));
        sizePolicy1.setHeightForWidth(labelExpired->sizePolicy().hasHeightForWidth());
        labelExpired->setSizePolicy(sizePolicy1);
        labelExpired->setMinimumSize(QSize(16, 16));
        labelExpired->setMaximumSize(QSize(16, 16));
        labelExpired->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/expired.png);"));
        label_3 = new QLabel(ServiceFeeWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(45, 18, 97, 16));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(97, 16));
        label_3->setMaximumSize(QSize(97, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label_4 = new QLabel(ServiceFeeWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 22, 1, 10));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(1, 10));
        label_4->setMaximumSize(QSize(1, 10));
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        labelFeeTime = new QLabel(ServiceFeeWidget);
        labelFeeTime->setObjectName(QStringLiteral("labelFeeTime"));
        labelFeeTime->setGeometry(QRect(160, 19, 77, 14));
        sizePolicy1.setHeightForWidth(labelFeeTime->sizePolicy().hasHeightForWidth());
        labelFeeTime->setSizePolicy(sizePolicy1);
        labelFeeTime->setMinimumSize(QSize(77, 14));
        labelFeeTime->setMaximumSize(QSize(77, 14));
        labelFeeTime->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelFeeTime_2 = new QLabel(ServiceFeeWidget);
        labelFeeTime_2->setObjectName(QStringLiteral("labelFeeTime_2"));
        labelFeeTime_2->setGeometry(QRect(239, 19, 30, 14));
        sizePolicy1.setHeightForWidth(labelFeeTime_2->sizePolicy().hasHeightForWidth());
        labelFeeTime_2->setSizePolicy(sizePolicy1);
        labelFeeTime_2->setMinimumSize(QSize(30, 14));
        labelFeeTime_2->setMaximumSize(QSize(30, 14));
        labelFeeTime_2->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label_5 = new QLabel(ServiceFeeWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(275, 22, 1, 10));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(1, 10));
        label_5->setMaximumSize(QSize(1, 10));
        label_5->setStyleSheet(QStringLiteral("background-color: rgb(222, 222, 222);"));
        labelDays = new QLabel(ServiceFeeWidget);
        labelDays->setObjectName(QStringLiteral("labelDays"));
        labelDays->setGeometry(QRect(285, 15, 231, 14));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelDays->sizePolicy().hasHeightForWidth());
        labelDays->setSizePolicy(sizePolicy3);
        labelDays->setMinimumSize(QSize(30, 14));
        labelDays->setMaximumSize(QSize(3000, 140));
        labelDays->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        progressBar = new QProgressBar(ServiceFeeWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 51, 574, 10));
        sizePolicy1.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy1);
        progressBar->setMinimumSize(QSize(574, 10));
        progressBar->setMaximumSize(QSize(574, 10));
        progressBar->setStyleSheet(QLatin1String("QProgressBar {border:0px;border-radius:5px; background-color:#ebebeb;}\n"
"QProgressBar::chunk{border:0px;border-radius:5px;background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #02D1FD, stop:1 #419AEF);}\n"
"QProgressBar {border:0px;border-radius:5px;text-align: center;}"));
        progressBar->setMaximum(365);
        progressBar->setValue(90);
        progressBar->setTextVisible(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        labelNoServerFee = new QLabel(ServiceFeeWidget);
        labelNoServerFee->setObjectName(QStringLiteral("labelNoServerFee"));
        labelNoServerFee->setGeometry(QRect(45, 48, 251, 16));
        labelNoServerFee->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        EntVipWidget = new QWidget(EntRightWidget);
        EntVipWidget->setObjectName(QStringLiteral("EntVipWidget"));
        EntVipWidget->setGeometry(QRect(20, 240, 710, 80));
        sizePolicy1.setHeightForWidth(EntVipWidget->sizePolicy().hasHeightForWidth());
        EntVipWidget->setSizePolicy(sizePolicy1);
        EntVipWidget->setMinimumSize(QSize(710, 80));
        EntVipWidget->setMaximumSize(QSize(710, 80));
        EntVipWidget->setStyleSheet(QLatin1String("QWidget#EntVipWidget{background-color: rgb(252, 252, 252);border:1px solid rgba(235,235,235,1);\n"
"border-radius:10px;}"));
        EntVipButton = new QPushButton(EntVipWidget);
        EntVipButton->setObjectName(QStringLiteral("EntVipButton"));
        EntVipButton->setGeometry(QRect(619, 24, 72, 32));
        sizePolicy1.setHeightForWidth(EntVipButton->sizePolicy().hasHeightForWidth());
        EntVipButton->setSizePolicy(sizePolicy1);
        EntVipButton->setMinimumSize(QSize(72, 32));
        EntVipButton->setMaximumSize(QSize(72, 32));
        EntVipButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));\n"
"			border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        labelExpired_2 = new QLabel(EntVipWidget);
        labelExpired_2->setObjectName(QStringLiteral("labelExpired_2"));
        labelExpired_2->setGeometry(QRect(20, 19, 16, 16));
        sizePolicy1.setHeightForWidth(labelExpired_2->sizePolicy().hasHeightForWidth());
        labelExpired_2->setSizePolicy(sizePolicy1);
        labelExpired_2->setMinimumSize(QSize(16, 16));
        labelExpired_2->setMaximumSize(QSize(16, 16));
        labelExpired_2->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/expired.png);"));
        label_6 = new QLabel(EntVipWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(46, 19, 56, 15));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(56, 15));
        label_6->setMaximumSize(QSize(56, 15));
        label_6->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label_7 = new QLabel(EntVipWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(46, 48, 476, 15));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(476, 15));
        label_7->setMaximumSize(QSize(476, 15));
        label_7->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        SignInWidget = new QWidget(EntRightWidget);
        SignInWidget->setObjectName(QStringLiteral("SignInWidget"));
        SignInWidget->setGeometry(QRect(20, 399, 710, 80));
        sizePolicy1.setHeightForWidth(SignInWidget->sizePolicy().hasHeightForWidth());
        SignInWidget->setSizePolicy(sizePolicy1);
        SignInWidget->setMinimumSize(QSize(710, 80));
        SignInWidget->setMaximumSize(QSize(710, 80));
        SignInWidget->setStyleSheet(QLatin1String("QWidget#SignInWidget{background-color: rgb(252, 252, 252);border:1px solid rgba(235,235,235,1);\n"
"border-radius:10px;}"));
        SignInButton = new QPushButton(SignInWidget);
        SignInButton->setObjectName(QStringLiteral("SignInButton"));
        SignInButton->setEnabled(false);
        SignInButton->setGeometry(QRect(618, 24, 72, 32));
        sizePolicy1.setHeightForWidth(SignInButton->sizePolicy().hasHeightForWidth());
        SignInButton->setSizePolicy(sizePolicy1);
        SignInButton->setMinimumSize(QSize(72, 32));
        SignInButton->setMaximumSize(QSize(72, 32));
        SignInButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        label_8 = new QLabel(SignInWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 15, 50, 50));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(50, 50));
        label_8->setMaximumSize(QSize(50, 50));
        label_8->setStyleSheet(QStringLiteral("QLabel{border-image: url(:/EntCenterWidget/image/signIn.png);}"));
        label_10 = new QLabel(SignInWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(89, 31, 56, 15));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(56, 15));
        label_10->setMaximumSize(QSize(56, 15));
        label_10->setStyleSheet(QString::fromUtf8("QLabel{font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;}"));
        label_12 = new QLabel(SignInWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(260, 31, 20, 20));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setMinimumSize(QSize(20, 20));
        label_12->setMaximumSize(QSize(20, 20));
        label_12->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/score.png);"));
        label_14 = new QLabel(SignInWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(290, 32, 20, 15));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMinimumSize(QSize(20, 15));
        label_14->setMaximumSize(QSize(20, 15));
        label_14->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label_16 = new QLabel(SignInWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(451, 32, 56, 15));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);
        label_16->setMinimumSize(QSize(56, 15));
        label_16->setMaximumSize(QSize(56, 15));
        label_16->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        CompeteDataWidget = new QWidget(EntRightWidget);
        CompeteDataWidget->setObjectName(QStringLiteral("CompeteDataWidget"));
        CompeteDataWidget->setEnabled(true);
        CompeteDataWidget->setGeometry(QRect(20, 499, 710, 80));
        sizePolicy1.setHeightForWidth(CompeteDataWidget->sizePolicy().hasHeightForWidth());
        CompeteDataWidget->setSizePolicy(sizePolicy1);
        CompeteDataWidget->setMinimumSize(QSize(710, 80));
        CompeteDataWidget->setMaximumSize(QSize(710, 80));
        CompeteDataWidget->setStyleSheet(QLatin1String("QWidget#CompeteDataWidget{background-color: rgb(252, 252, 252);border:1px solid rgba(235,235,235,1);\n"
"border-radius:10px;}"));
        label_9 = new QLabel(CompeteDataWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 15, 50, 50));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(50, 50));
        label_9->setMaximumSize(QSize(50, 50));
        label_9->setStyleSheet(QStringLiteral("QLabel{border-image: url(:/EntCenterWidget/image/completeInfo.png);}"));
        label_11 = new QLabel(CompeteDataWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(89, 31, 56, 15));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(56, 15));
        label_11->setMaximumSize(QSize(56, 15));
        label_11->setStyleSheet(QString::fromUtf8("QLabel{font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;}"));
        label_13 = new QLabel(CompeteDataWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(260, 31, 20, 20));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);
        label_13->setMinimumSize(QSize(20, 20));
        label_13->setMaximumSize(QSize(20, 20));
        label_13->setStyleSheet(QStringLiteral("border-image: url(:/EntCenterWidget/image/score.png);"));
        label_15 = new QLabel(CompeteDataWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(290, 32, 20, 15));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setMinimumSize(QSize(20, 15));
        label_15->setMaximumSize(QSize(20, 15));
        label_15->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label_17 = new QLabel(CompeteDataWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(451, 32, 70, 15));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);
        label_17->setMinimumSize(QSize(70, 15));
        label_17->setMaximumSize(QSize(70, 15));
        label_17->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        CompeteDataButton = new QPushButton(CompeteDataWidget);
        CompeteDataButton->setObjectName(QStringLiteral("CompeteDataButton"));
        CompeteDataButton->setEnabled(false);
        CompeteDataButton->setGeometry(QRect(619, 24, 72, 32));
        sizePolicy1.setHeightForWidth(CompeteDataButton->sizePolicy().hasHeightForWidth());
        CompeteDataButton->setSizePolicy(sizePolicy1);
        CompeteDataButton->setMinimumSize(QSize(72, 32));
        CompeteDataButton->setMaximumSize(QSize(72, 32));
        CompeteDataButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));\n"
"			border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        minButton = new QPushButton(EntRightWidget);
        minButton->setObjectName(QStringLiteral("minButton"));
        minButton->setGeometry(QRect(672, 5, 32, 28));
        sizePolicy1.setHeightForWidth(minButton->sizePolicy().hasHeightForWidth());
        minButton->setSizePolicy(sizePolicy1);
        minButton->setMinimumSize(QSize(32, 28));
        minButton->setMaximumSize(QSize(32, 28));
        minButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/min.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/min_sel.png);};"));
        closeButton = new QPushButton(EntRightWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(710, 5, 32, 28));
        sizePolicy1.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy1);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/EntCenterWidget/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/EntCenterWidget/image/close_sel.png);};"));
        label = new QLabel(EntRightWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(25, 100, 64, 17));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(64, 17));
        label->setMaximumSize(QSize(64, 17));
        label->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label_2 = new QLabel(EntRightWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(25, 359, 64, 17));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(64, 17));
        label_2->setMaximumSize(QSize(64, 17));
        label_2->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelFirstName = new QLabel(EntRightWidget);
        labelFirstName->setObjectName(QStringLiteral("labelFirstName"));
        labelFirstName->setGeometry(QRect(26, 30, 30, 30));
        sizePolicy1.setHeightForWidth(labelFirstName->sizePolicy().hasHeightForWidth());
        labelFirstName->setSizePolicy(sizePolicy1);
        labelFirstName->setMinimumSize(QSize(30, 30));
        labelFirstName->setMaximumSize(QSize(30, 30));
        labelFirstName->setStyleSheet(QString::fromUtf8("background:rgba(95,217,153,1);\n"
"border-radius:15px;\n"
"font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#FDFDFD;"));
        labelFirstName->setAlignment(Qt::AlignCenter);
        labelUserName = new QLabel(EntRightWidget);
        labelUserName->setObjectName(QStringLiteral("labelUserName"));
        labelUserName->setGeometry(QRect(62, 36, 28, 16));
        sizePolicy2.setHeightForWidth(labelUserName->sizePolicy().hasHeightForWidth());
        labelUserName->setSizePolicy(sizePolicy2);
        labelUserName->setMinimumSize(QSize(28, 16));
        labelUserName->setMaximumSize(QSize(16777215, 16));
        labelUserName->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelUserJob = new QLabel(EntRightWidget);
        labelUserJob->setObjectName(QStringLiteral("labelUserJob"));
        labelUserJob->setGeometry(QRect(62, 58, 60, 18));
        sizePolicy2.setHeightForWidth(labelUserJob->sizePolicy().hasHeightForWidth());
        labelUserJob->setSizePolicy(sizePolicy2);
        labelUserJob->setMinimumSize(QSize(60, 18));
        labelUserJob->setMaximumSize(QSize(16777215, 18));
        labelUserJob->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#3EACF7;\n"
"background-color: rgb(237, 244, 255);\n"
"padding-left:2px;\n"
"border-radius:2px;"));

        horizontalLayout->addWidget(EntRightWidget);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(EntCenterWidget);

        QMetaObject::connectSlotsByName(EntCenterWidget);
    } // setupUi

    void retranslateUi(QWidget *EntCenterWidget)
    {
        EntCenterWidget->setWindowTitle(QApplication::translate("EntCenterWidget", "EntCenterWidget", 0));
        switchButton->setText(QApplication::translate("EntCenterWidget", "\350\264\246\345\217\267\345\210\207\346\215\242", 0));
        labelAvatar->setText(QString());
#ifndef QT_NO_TOOLTIP
        copyTaxButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        copyTaxButton->setText(QString());
        labelComName->setText(QString());
        labelTaxNo->setText(QString());
        labelSpaceLeft->setText(QString());
#ifndef QT_NO_TOOLTIP
        scoreButton->setToolTip(QApplication::translate("EntCenterWidget", "\344\272\221\345\270\201", 0));
#endif // QT_NO_TOOLTIP
        scoreButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        couponButton->setToolTip(QApplication::translate("EntCenterWidget", "\344\274\230\346\203\240\345\212\265", 0));
#endif // QT_NO_TOOLTIP
        couponButton->setText(QString());
        labelMore->setText(QApplication::translate("EntCenterWidget", "\346\233\264\345\244\232\344\277\241\346\201\257", 0));
        labelEntInfo->setText(QString());
        labelTransInfo->setText(QString());
        labelMember->setText(QString());
        labelAccSet->setText(QString());
        entInfoButton->setText(QApplication::translate("EntCenterWidget", "\344\274\201\344\270\232\350\265\204\346\226\231", 0));
        transInfoButton->setText(QApplication::translate("EntCenterWidget", "\344\272\244\346\230\223\344\277\241\346\201\257", 0));
        memberButton->setText(QApplication::translate("EntCenterWidget", "\350\264\242\345\212\241\346\210\220\345\221\230", 0));
        accSetButton->setText(QApplication::translate("EntCenterWidget", "\350\264\246\345\217\267\350\256\276\347\275\256", 0));
        labelScore->setText(QApplication::translate("EntCenterWidget", "0", 0));
        labelCoupon->setText(QApplication::translate("EntCenterWidget", "0", 0));
        labelCopy->setText(QApplication::translate("EntCenterWidget", "\345\244\215\345\210\266", 0));
        labelAddComp->setText(QApplication::translate("EntCenterWidget", "\345\212\240\345\205\245\344\274\201\344\270\232", 0));
        labelVip->setText(QString());
        labelSpaceRight->setText(QString());
        ServiceFeeButton->setText(QApplication::translate("EntCenterWidget", "\347\273\255\350\264\271", 0));
        labelExpired->setText(QString());
        label_3->setText(QApplication::translate("EntCenterWidget", "\351\230\262\344\274\252\347\250\216\346\216\247\346\234\215\345\212\241\350\264\271", 0));
        label_4->setText(QString());
        labelFeeTime->setText(QString());
        labelFeeTime_2->setText(QApplication::translate("EntCenterWidget", "\345\210\260\346\234\237", 0));
        label_5->setText(QString());
        labelDays->setText(QString());
        labelNoServerFee->setText(QApplication::translate("EntCenterWidget", "\346\232\202\346\227\266\346\234\252\350\216\267\345\217\226\346\202\250\347\232\204\344\274\201\344\270\232\351\230\262\344\274\252\347\250\216\346\216\247\346\234\215\345\212\241\350\264\271\344\277\241\346\201\257", 0));
        EntVipButton->setText(QApplication::translate("EntCenterWidget", "\350\257\246\346\203\205", 0));
        labelExpired_2->setText(QString());
        label_6->setText(QApplication::translate("EntCenterWidget", "\344\274\201\344\270\232\344\274\232\345\221\230", 0));
        label_7->setText(QApplication::translate("EntCenterWidget", "\346\202\250\346\232\202\346\234\252\345\274\200\351\200\232\344\274\201\344\270\232\344\274\232\345\221\230\357\274\214\346\227\240\346\263\225\344\272\253\345\217\227\346\233\264\345\244\232\344\274\201\344\270\232\346\235\203\347\233\212", 0));
        SignInButton->setText(QApplication::translate("EntCenterWidget", "\345\216\273\345\256\214\346\210\220", 0));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("EntCenterWidget", "\345\256\214\346\210\220\347\255\276\345\210\260\357\274\214\345\217\257\350\216\267\345\276\227\344\272\221\345\270\201+10", 0));
#endif // QT_NO_TOOLTIP
        label_8->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_10->setToolTip(QApplication::translate("EntCenterWidget", "\345\256\214\346\210\220\347\255\276\345\210\260\357\274\214\345\217\257\350\216\267\345\276\227\344\272\221\345\270\201+10", 0));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("EntCenterWidget", "\346\257\217\346\227\245\347\255\276\345\210\260", 0));
        label_12->setText(QString());
        label_14->setText(QApplication::translate("EntCenterWidget", "10", 0));
        label_16->setText(QApplication::translate("EntCenterWidget", "\346\227\245\345\270\270\344\273\273\345\212\241", 0));
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("EntCenterWidget", "\345\256\214\345\226\204\344\270\252\344\272\272\350\265\204\346\226\231\357\274\214\345\217\257\350\216\267\345\276\227\344\272\221\345\270\201+50", 0));
#endif // QT_NO_TOOLTIP
        label_9->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_11->setToolTip(QApplication::translate("EntCenterWidget", "\345\256\214\345\226\204\344\270\252\344\272\272\350\265\204\346\226\231\357\274\214\345\217\257\350\216\267\345\276\227\344\272\221\345\270\201+50", 0));
#endif // QT_NO_TOOLTIP
        label_11->setText(QApplication::translate("EntCenterWidget", "\345\256\214\345\226\204\350\265\204\346\226\231", 0));
        label_13->setText(QString());
        label_15->setText(QApplication::translate("EntCenterWidget", "50", 0));
        label_17->setText(QApplication::translate("EntCenterWidget", "\344\270\200\346\254\241\346\200\247\344\273\273\345\212\241", 0));
        CompeteDataButton->setText(QApplication::translate("EntCenterWidget", "\345\216\273\345\256\214\346\210\220", 0));
        minButton->setText(QString());
        closeButton->setText(QString());
        label->setText(QApplication::translate("EntCenterWidget", "\344\274\201\344\270\232\346\234\215\345\212\241", 0));
        label_2->setText(QApplication::translate("EntCenterWidget", "\344\272\221\345\270\201\344\273\273\345\212\241", 0));
        labelFirstName->setText(QString());
        labelUserName->setText(QString());
        labelUserJob->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EntCenterWidget: public Ui_EntCenterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTCENTERWIDGET_H
