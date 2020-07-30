/********************************************************************************
** Form generated from reading UI file 'SettingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWIDGET_H
#define UI_SETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CommentTextEdit.h"

QT_BEGIN_NAMESPACE

class Ui_SettingWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FilletWidget;
    QWidget *LeftWidget;
    QRadioButton *deskSettingButton;
    QRadioButton *feedBackButton;
    QRadioButton *helperButton;
    QRadioButton *aboutUsButton;
    QWidget *RightTopWidget;
    QPushButton *closeButton;
    QWidget *DeskWidget;
    QWidget *bannerWidget;
    QLabel *leftLabel;
    QLabel *label;
    QLabel *rightLabel;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *leftLabel_2;
    QLabel *rightLabel_2;
    QLabel *label_4;
    QLabel *label_10;
    QLabel *label_11;
    QCheckBox *topCheckBox;
    QCheckBox *rightCheckBox;
    QListWidget *listWidget;
    QWidget *FeedBackWidget;
    QFrame *frame;
    CommentTextEdit *textEdit;
    QLabel *numberLabel;
    QLabel *label_17;
    QLineEdit *lineEdit;
    QPushButton *commitButton;
    QPushButton *otherButton;
    QPushButton *errorButton;
    QPushButton *designButton;
    QPushButton *deskAppButton;
    QPushButton *majorButton;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QWidget *HelperWidget;
    QPushButton *helpButton;
    QPushButton *demoButton;
    QPushButton *questionButton;
    QPushButton *guideButton;
    QWidget *AboutUsWidget;
    QLabel *labelIcon;
    QLabel *labelName;
    QLabel *label_21;
    QLabel *labelVersion;
    QPushButton *checkUpdateButton;
    QLabel *labelLogout;
    QLabel *labelVerDes;

    void setupUi(QWidget *SettingWidget)
    {
        if (SettingWidget->objectName().isEmpty())
            SettingWidget->setObjectName(QStringLiteral("SettingWidget"));
        SettingWidget->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingWidget->sizePolicy().hasHeightForWidth());
        SettingWidget->setSizePolicy(sizePolicy);
        SettingWidget->setMinimumSize(QSize(800, 600));
        SettingWidget->setMaximumSize(QSize(800, 600));
        SettingWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(SettingWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FilletWidget = new QWidget(SettingWidget);
        FilletWidget->setObjectName(QStringLiteral("FilletWidget"));
        sizePolicy.setHeightForWidth(FilletWidget->sizePolicy().hasHeightForWidth());
        FilletWidget->setSizePolicy(sizePolicy);
        FilletWidget->setMinimumSize(QSize(800, 600));
        FilletWidget->setMaximumSize(QSize(800, 600));
        FilletWidget->setStyleSheet(QLatin1String("QWidget#FilletWidget{border-radius:4px;\n"
"border-image: url(:/ZcloudDesk/image/white.png);}\n"
"\n"
""));
        LeftWidget = new QWidget(FilletWidget);
        LeftWidget->setObjectName(QStringLiteral("LeftWidget"));
        LeftWidget->setGeometry(QRect(0, 0, 150, 600));
        sizePolicy.setHeightForWidth(LeftWidget->sizePolicy().hasHeightForWidth());
        LeftWidget->setSizePolicy(sizePolicy);
        LeftWidget->setMinimumSize(QSize(150, 600));
        LeftWidget->setMaximumSize(QSize(150, 600));
        LeftWidget->setStyleSheet(QLatin1String("border-top-right-radius:0px;\n"
"border-bottom-right-radius:0px;\n"
"background-color: rgb(239,243,245);"));
        deskSettingButton = new QRadioButton(LeftWidget);
        deskSettingButton->setObjectName(QStringLiteral("deskSettingButton"));
        deskSettingButton->setGeometry(QRect(0, 0, 150, 100));
        sizePolicy.setHeightForWidth(deskSettingButton->sizePolicy().hasHeightForWidth());
        deskSettingButton->setSizePolicy(sizePolicy);
        deskSettingButton->setMinimumSize(QSize(150, 100));
        deskSettingButton->setMaximumSize(QSize(150, 100));
        deskSettingButton->setMouseTracking(false);
        deskSettingButton->setFocusPolicy(Qt::TabFocus);
        deskSettingButton->setStyleSheet(QLatin1String("QRadioButton::indicator {width:150px;height:100px;}\n"
"QRadioButton::indicator::unchecked{border-image:url(:/ZcloudDesk/image/deskset_nor.png);}\n"
"QRadioButton::indicator::unchecked:hover,pressed{border-image: url(:/ZcloudDesk/image/deskset_hov.png);}\n"
"QRadioButton::indicator::checked{border-image: url(:/ZcloudDesk/image/deskset_hov.png);};"));
        deskSettingButton->setCheckable(true);
        deskSettingButton->setAutoRepeat(false);
        deskSettingButton->setAutoExclusive(true);
        feedBackButton = new QRadioButton(LeftWidget);
        feedBackButton->setObjectName(QStringLiteral("feedBackButton"));
        feedBackButton->setGeometry(QRect(0, 100, 150, 100));
        sizePolicy.setHeightForWidth(feedBackButton->sizePolicy().hasHeightForWidth());
        feedBackButton->setSizePolicy(sizePolicy);
        feedBackButton->setMinimumSize(QSize(150, 100));
        feedBackButton->setMaximumSize(QSize(150, 100));
        feedBackButton->setStyleSheet(QLatin1String("QRadioButton::indicator {width:150px;height:100px;}\n"
"QRadioButton::indicator::unchecked{border-image:url(:/ZcloudDesk/image/feedback_nor.png);}\n"
"QRadioButton::indicator::unchecked:hover,pressed{border-image: url(:/ZcloudDesk/image/feedback_hov.png);}\n"
"QRadioButton::indicator::checked{border-image: url(:/ZcloudDesk/image/feedback_hov.png);};"));
        helperButton = new QRadioButton(LeftWidget);
        helperButton->setObjectName(QStringLiteral("helperButton"));
        helperButton->setGeometry(QRect(0, 200, 150, 100));
        sizePolicy.setHeightForWidth(helperButton->sizePolicy().hasHeightForWidth());
        helperButton->setSizePolicy(sizePolicy);
        helperButton->setMinimumSize(QSize(150, 100));
        helperButton->setMaximumSize(QSize(150, 100));
        helperButton->setStyleSheet(QLatin1String("QRadioButton::indicator {width:150px;height:100px;}\n"
"QRadioButton::indicator::unchecked{border-image:url(:/ZcloudDesk/image/helpcenter_nor.png);}\n"
"QRadioButton::indicator::unchecked:hover,pressed{border-image: url(:/ZcloudDesk/image/helpcenter_hov.png);}\n"
"QRadioButton::indicator::checked{border-image: url(:/ZcloudDesk/image/helpcenter_hov.png);};"));
        aboutUsButton = new QRadioButton(LeftWidget);
        aboutUsButton->setObjectName(QStringLiteral("aboutUsButton"));
        aboutUsButton->setGeometry(QRect(0, 300, 150, 100));
        sizePolicy.setHeightForWidth(aboutUsButton->sizePolicy().hasHeightForWidth());
        aboutUsButton->setSizePolicy(sizePolicy);
        aboutUsButton->setMinimumSize(QSize(150, 100));
        aboutUsButton->setMaximumSize(QSize(150, 100));
        aboutUsButton->setStyleSheet(QLatin1String("QRadioButton::indicator {width:150px;height:100px;}\n"
"QRadioButton::indicator::unchecked{border-image:url(:/ZcloudDesk/image/about_nor.png);}\n"
"QRadioButton::indicator::unchecked:hover,pressed{border-image: url(:/ZcloudDesk/image/about_hov.png);}\n"
"QRadioButton::indicator::checked{border-image: url(:/ZcloudDesk/image/about_hov.png);};"));
        RightTopWidget = new QWidget(FilletWidget);
        RightTopWidget->setObjectName(QStringLiteral("RightTopWidget"));
        RightTopWidget->setGeometry(QRect(150, 0, 650, 30));
        sizePolicy.setHeightForWidth(RightTopWidget->sizePolicy().hasHeightForWidth());
        RightTopWidget->setSizePolicy(sizePolicy);
        RightTopWidget->setMinimumSize(QSize(650, 30));
        RightTopWidget->setMaximumSize(QSize(650, 30));
        RightTopWidget->setStyleSheet(QStringLiteral(""));
        closeButton = new QPushButton(RightTopWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(615, 5, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudDesk/image/close.png);border-radius:none;background-color: rgba(255, 255, 255, 0);}\n"
"\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/close_sel.png);};"));
        DeskWidget = new QWidget(FilletWidget);
        DeskWidget->setObjectName(QStringLiteral("DeskWidget"));
        DeskWidget->setGeometry(QRect(150, 30, 650, 530));
        sizePolicy.setHeightForWidth(DeskWidget->sizePolicy().hasHeightForWidth());
        DeskWidget->setSizePolicy(sizePolicy);
        DeskWidget->setMinimumSize(QSize(650, 530));
        DeskWidget->setMaximumSize(QSize(650, 530));
        DeskWidget->setStyleSheet(QStringLiteral(""));
        bannerWidget = new QWidget(DeskWidget);
        bannerWidget->setObjectName(QStringLiteral("bannerWidget"));
        bannerWidget->setGeometry(QRect(0, 0, 650, 110));
        sizePolicy.setHeightForWidth(bannerWidget->sizePolicy().hasHeightForWidth());
        bannerWidget->setSizePolicy(sizePolicy);
        bannerWidget->setMinimumSize(QSize(650, 110));
        bannerWidget->setMaximumSize(QSize(650, 110));
        bannerWidget->setStyleSheet(QStringLiteral(""));
        leftLabel = new QLabel(DeskWidget);
        leftLabel->setObjectName(QStringLiteral("leftLabel"));
        leftLabel->setGeometry(QRect(62, 145, 220, 1));
        sizePolicy.setHeightForWidth(leftLabel->sizePolicy().hasHeightForWidth());
        leftLabel->setSizePolicy(sizePolicy);
        leftLabel->setMinimumSize(QSize(220, 1));
        leftLabel->setMaximumSize(QSize(220, 1));
        leftLabel->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(30,139,237, 0), stop:1 rgba(30,139,237, 1));"));
        label = new QLabel(DeskWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(311, 137, 29, 14));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(29, 14));
        label->setMaximumSize(QSize(29, 14));
        label->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1E8BED;"));
        rightLabel = new QLabel(DeskWidget);
        rightLabel->setObjectName(QStringLiteral("rightLabel"));
        rightLabel->setGeometry(QRect(370, 145, 220, 1));
        sizePolicy.setHeightForWidth(rightLabel->sizePolicy().hasHeightForWidth());
        rightLabel->setSizePolicy(sizePolicy);
        rightLabel->setMinimumSize(QSize(220, 1));
        rightLabel->setMaximumSize(QSize(220, 1));
        rightLabel->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(30,139,237, 1), stop:1 rgba(30,139,237, 0));"));
        label_2 = new QLabel(DeskWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 162, 30, 30));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(30, 30));
        label_2->setMaximumSize(QSize(30, 30));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/icon_top.png);"));
        label_3 = new QLabel(DeskWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 212, 30, 30));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(30, 30));
        label_3->setMaximumSize(QSize(30, 30));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/icon_right.png);"));
        leftLabel_2 = new QLabel(DeskWidget);
        leftLabel_2->setObjectName(QStringLiteral("leftLabel_2"));
        leftLabel_2->setGeometry(QRect(62, 267, 220, 1));
        sizePolicy.setHeightForWidth(leftLabel_2->sizePolicy().hasHeightForWidth());
        leftLabel_2->setSizePolicy(sizePolicy);
        leftLabel_2->setMinimumSize(QSize(220, 1));
        leftLabel_2->setMaximumSize(QSize(220, 1));
        leftLabel_2->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(30,139,237, 0), stop:1 rgba(30,139,237, 1));"));
        rightLabel_2 = new QLabel(DeskWidget);
        rightLabel_2->setObjectName(QStringLiteral("rightLabel_2"));
        rightLabel_2->setGeometry(QRect(370, 267, 220, 1));
        sizePolicy.setHeightForWidth(rightLabel_2->sizePolicy().hasHeightForWidth());
        rightLabel_2->setSizePolicy(sizePolicy);
        rightLabel_2->setMinimumSize(QSize(220, 1));
        rightLabel_2->setMaximumSize(QSize(220, 1));
        rightLabel_2->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(30,139,237, 1), stop:1 rgba(30,139,237, 0));"));
        label_4 = new QLabel(DeskWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(311, 260, 29, 14));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(29, 14));
        label_4->setMaximumSize(QSize(29, 14));
        label_4->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1E8BED;"));
        label_10 = new QLabel(DeskWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(130, 168, 71, 15));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(71, 15));
        label_10->setMaximumSize(QSize(71, 15));
        label_10->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label_11 = new QLabel(DeskWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(130, 218, 71, 15));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(71, 15));
        label_11->setMaximumSize(QSize(71, 15));
        label_11->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        topCheckBox = new QCheckBox(DeskWidget);
        topCheckBox->setObjectName(QStringLiteral("topCheckBox"));
        topCheckBox->setGeometry(QRect(502, 164, 58, 26));
        sizePolicy.setHeightForWidth(topCheckBox->sizePolicy().hasHeightForWidth());
        topCheckBox->setSizePolicy(sizePolicy);
        topCheckBox->setMinimumSize(QSize(58, 26));
        topCheckBox->setMaximumSize(QSize(58, 26));
        topCheckBox->setStyleSheet(QLatin1String("QCheckBox::indicator { \n"
"    width: 58px;\n"
"    height: 26px;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/ZcloudDesk/image/switch_off.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/ZcloudDesk/image/switch_on.png);\n"
"}"));
        rightCheckBox = new QCheckBox(DeskWidget);
        rightCheckBox->setObjectName(QStringLiteral("rightCheckBox"));
        rightCheckBox->setGeometry(QRect(502, 214, 58, 26));
        sizePolicy.setHeightForWidth(rightCheckBox->sizePolicy().hasHeightForWidth());
        rightCheckBox->setSizePolicy(sizePolicy);
        rightCheckBox->setMinimumSize(QSize(58, 26));
        rightCheckBox->setMaximumSize(QSize(58, 26));
        rightCheckBox->setStyleSheet(QLatin1String("QCheckBox::indicator { \n"
"    width: 58px;\n"
"    height: 26px;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/ZcloudDesk/image/switch_off.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/ZcloudDesk/image/switch_on.png);\n"
"}"));
        listWidget = new QListWidget(DeskWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(80, 285, 500, 230));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMinimumSize(QSize(500, 230));
        listWidget->setMaximumSize(QSize(500, 230));
        listWidget->setStyleSheet(QLatin1String("QListWidget{border-bottom-left-radius:0px;}\n"
"QListWidget::Item:hover{background:#FFFFFF;}\n"
"QListWidget::item:selected{background:#FFFFFF;}\n"
"QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        FeedBackWidget = new QWidget(FilletWidget);
        FeedBackWidget->setObjectName(QStringLiteral("FeedBackWidget"));
        FeedBackWidget->setGeometry(QRect(850, 20, 650, 530));
        sizePolicy.setHeightForWidth(FeedBackWidget->sizePolicy().hasHeightForWidth());
        FeedBackWidget->setSizePolicy(sizePolicy);
        FeedBackWidget->setMinimumSize(QSize(650, 530));
        FeedBackWidget->setMaximumSize(QSize(650, 530));
        FeedBackWidget->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(FeedBackWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 112, 610, 250));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(610, 250));
        frame->setMaximumSize(QSize(610, 250));
        frame->setStyleSheet(QStringLiteral("QFrame#frame{border: 1px solid #dddddd;border-radius: 2px; }"));
        textEdit = new CommentTextEdit(frame);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(2, 2, 606, 211));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMinimumSize(QSize(606, 210));
        textEdit->setMaximumSize(QSize(210, 16777215));
        textEdit->setFocusPolicy(Qt::WheelFocus);
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit#textEdit{font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:0px;border-radius:2px;};\n"
"QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"));
        textEdit->setPlaceholderText(QString::fromUtf8("\350\257\267\346\217\217\350\277\260\346\202\250\351\201\207\345\210\260\347\232\204\351\227\256\351\242\230\346\210\226\345\273\272\350\256\256"));
        numberLabel = new QLabel(frame);
        numberLabel->setObjectName(QStringLiteral("numberLabel"));
        numberLabel->setGeometry(QRect(500, 220, 100, 20));
        sizePolicy.setHeightForWidth(numberLabel->sizePolicy().hasHeightForWidth());
        numberLabel->setSizePolicy(sizePolicy);
        numberLabel->setMinimumSize(QSize(100, 20));
        numberLabel->setMaximumSize(QSize(100, 20));
        numberLabel->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        numberLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_17 = new QLabel(FeedBackWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 395, 64, 14));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setMinimumSize(QSize(64, 14));
        label_17->setMaximumSize(QSize(64, 14));
        label_17->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        lineEdit = new QLineEdit(FeedBackWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 382, 530, 40));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(530, 40));
        lineEdit->setMaximumSize(QSize(530, 40));
        lineEdit->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lineEdit->setFont(font);
        lineEdit->setFocusPolicy(Qt::WheelFocus);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"  border-radius: 2px;\n"
"  border: 1px solid #e5e5e5;  \n"
"  background-color: rgb(255, 255, 255);\n"
"  font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"  color:#333333;\n"
"}"));
        lineEdit->setMaxLength(50);
        lineEdit->setCursorPosition(0);
        lineEdit->setDragEnabled(false);
        lineEdit->setClearButtonEnabled(false);
        commitButton = new QPushButton(FeedBackWidget);
        commitButton->setObjectName(QStringLiteral("commitButton"));
        commitButton->setEnabled(false);
        commitButton->setGeometry(QRect(255, 442, 140, 40));
        sizePolicy.setHeightForWidth(commitButton->sizePolicy().hasHeightForWidth());
        commitButton->setSizePolicy(sizePolicy);
        commitButton->setMinimumSize(QSize(140, 40));
        commitButton->setMaximumSize(QSize(140, 40));
        commitButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));\n"
"			border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"\n"
"QPushButton:disabled{ background-color:#c0c0c0;border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}"));
        otherButton = new QPushButton(FeedBackWidget);
        otherButton->setObjectName(QStringLiteral("otherButton"));
        otherButton->setGeometry(QRect(507, 52, 123, 40));
        sizePolicy.setHeightForWidth(otherButton->sizePolicy().hasHeightForWidth());
        otherButton->setSizePolicy(sizePolicy);
        otherButton->setMinimumSize(QSize(123, 40));
        otherButton->setMaximumSize(QSize(123, 40));
        otherButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: #FFFFFF;border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#666666;border:1px solid #DEDEDE;\n"
"border-top-left-radius:0px;border-bottom-left-radius:0px;}\n"
"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\n"
"border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);border-top-left-radius:0px;border-bottom-left-radius:0px;}"));
        errorButton = new QPushButton(FeedBackWidget);
        errorButton->setObjectName(QStringLiteral("errorButton"));
        errorButton->setGeometry(QRect(385, 52, 123, 40));
        sizePolicy.setHeightForWidth(errorButton->sizePolicy().hasHeightForWidth());
        errorButton->setSizePolicy(sizePolicy);
        errorButton->setMinimumSize(QSize(123, 40));
        errorButton->setMaximumSize(QSize(123, 40));
        errorButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: #FFFFFF;border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#666666;border:1px solid #DEDEDE;border-radius:0px;}\n"
"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);border-radius:0px;}"));
        designButton = new QPushButton(FeedBackWidget);
        designButton->setObjectName(QStringLiteral("designButton"));
        designButton->setGeometry(QRect(20, 52, 123, 40));
        sizePolicy.setHeightForWidth(designButton->sizePolicy().hasHeightForWidth());
        designButton->setSizePolicy(sizePolicy);
        designButton->setMinimumSize(QSize(123, 40));
        designButton->setMaximumSize(QSize(123, 40));
        designButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: #FFFFFF;border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#666666;border:1px solid #DEDEDE;border-top-right-radius:0px;border-bottom-right-radius:0px;}QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\n"
"border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);border-top-right-radius:0px;border-bottom-right-radius:0px;}"));
        deskAppButton = new QPushButton(FeedBackWidget);
        deskAppButton->setObjectName(QStringLiteral("deskAppButton"));
        deskAppButton->setGeometry(QRect(264, 52, 123, 40));
        sizePolicy.setHeightForWidth(deskAppButton->sizePolicy().hasHeightForWidth());
        deskAppButton->setSizePolicy(sizePolicy);
        deskAppButton->setMinimumSize(QSize(123, 40));
        deskAppButton->setMaximumSize(QSize(123, 40));
        deskAppButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: #FFFFFF;border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#666666;border:1px solid #DEDEDE;border-radius:0px;}\n"
"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\n"
"border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);border-radius:0px;}"));
        majorButton = new QPushButton(FeedBackWidget);
        majorButton->setObjectName(QStringLiteral("majorButton"));
        majorButton->setGeometry(QRect(142, 52, 123, 40));
        sizePolicy.setHeightForWidth(majorButton->sizePolicy().hasHeightForWidth());
        majorButton->setSizePolicy(sizePolicy);
        majorButton->setMinimumSize(QSize(123, 40));
        majorButton->setMaximumSize(QSize(123, 40));
        majorButton->setStyleSheet(QString::fromUtf8("QPushButton{ background-color: #FFFFFF;border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#666666;border:1px solid #DEDEDE;border-radius:0px;}\n"
"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(40, 178, 253, 1), stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);border-radius:0px;}"));
        label_18 = new QLabel(FilletWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(377, 570, 20, 20));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setMinimumSize(QSize(20, 20));
        label_18->setMaximumSize(QSize(20, 20));
        label_18->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/icon_service.png);"));
        label_19 = new QLabel(FilletWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(403, 573, 112, 15));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setMinimumSize(QSize(112, 15));
        label_19->setMaximumSize(QSize(112, 15));
        label_19->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#666666;"));
        label_20 = new QLabel(FilletWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(523, 573, 49, 15));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);
        label_20->setMinimumSize(QSize(49, 15));
        label_20->setMaximumSize(QSize(49, 15));
        label_20->setStyleSheet(QString::fromUtf8("font: 75 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1F8BED;"));
        HelperWidget = new QWidget(FilletWidget);
        HelperWidget->setObjectName(QStringLiteral("HelperWidget"));
        HelperWidget->setGeometry(QRect(130, 630, 650, 530));
        sizePolicy.setHeightForWidth(HelperWidget->sizePolicy().hasHeightForWidth());
        HelperWidget->setSizePolicy(sizePolicy);
        HelperWidget->setMinimumSize(QSize(650, 530));
        HelperWidget->setMaximumSize(QSize(650, 530));
        HelperWidget->setStyleSheet(QStringLiteral(""));
        helpButton = new QPushButton(HelperWidget);
        helpButton->setObjectName(QStringLiteral("helpButton"));
        helpButton->setGeometry(QRect(20, 52, 295, 200));
        sizePolicy.setHeightForWidth(helpButton->sizePolicy().hasHeightForWidth());
        helpButton->setSizePolicy(sizePolicy);
        helpButton->setMinimumSize(QSize(295, 200));
        helpButton->setMaximumSize(QSize(295, 200));
        helpButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudDesk/image/help_nor.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/help_hov.png);};"));
        demoButton = new QPushButton(HelperWidget);
        demoButton->setObjectName(QStringLiteral("demoButton"));
        demoButton->setEnabled(false);
        demoButton->setGeometry(QRect(335, 272, 295, 200));
        sizePolicy.setHeightForWidth(demoButton->sizePolicy().hasHeightForWidth());
        demoButton->setSizePolicy(sizePolicy);
        demoButton->setMinimumSize(QSize(295, 200));
        demoButton->setMaximumSize(QSize(295, 200));
        demoButton->setStyleSheet(QStringLiteral("QPushButton{border-image: url(:/ZcloudDesk/image/default_setting.png);}"));
        questionButton = new QPushButton(HelperWidget);
        questionButton->setObjectName(QStringLiteral("questionButton"));
        questionButton->setGeometry(QRect(335, 52, 295, 200));
        sizePolicy.setHeightForWidth(questionButton->sizePolicy().hasHeightForWidth());
        questionButton->setSizePolicy(sizePolicy);
        questionButton->setMinimumSize(QSize(295, 200));
        questionButton->setMaximumSize(QSize(295, 200));
        questionButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudDesk/image/questionnaire_nor.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/questionnaire_hov.png);};"));
        guideButton = new QPushButton(HelperWidget);
        guideButton->setObjectName(QStringLiteral("guideButton"));
        guideButton->setGeometry(QRect(20, 272, 295, 200));
        sizePolicy.setHeightForWidth(guideButton->sizePolicy().hasHeightForWidth());
        guideButton->setSizePolicy(sizePolicy);
        guideButton->setMinimumSize(QSize(295, 200));
        guideButton->setMaximumSize(QSize(295, 200));
        guideButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudDesk/image/guide_nor.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/guide_hov.png);};"));
        AboutUsWidget = new QWidget(FilletWidget);
        AboutUsWidget->setObjectName(QStringLiteral("AboutUsWidget"));
        AboutUsWidget->setGeometry(QRect(800, 610, 650, 530));
        sizePolicy.setHeightForWidth(AboutUsWidget->sizePolicy().hasHeightForWidth());
        AboutUsWidget->setSizePolicy(sizePolicy);
        AboutUsWidget->setMinimumSize(QSize(650, 530));
        AboutUsWidget->setMaximumSize(QSize(650, 530));
        AboutUsWidget->setStyleSheet(QStringLiteral(""));
        labelIcon = new QLabel(AboutUsWidget);
        labelIcon->setObjectName(QStringLiteral("labelIcon"));
        labelIcon->setGeometry(QRect(285, 150, 80, 80));
        sizePolicy.setHeightForWidth(labelIcon->sizePolicy().hasHeightForWidth());
        labelIcon->setSizePolicy(sizePolicy);
        labelIcon->setMinimumSize(QSize(80, 80));
        labelIcon->setMaximumSize(QSize(80, 80));
        labelIcon->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/ycs_logo.png);"));
        labelName = new QLabel(AboutUsWidget);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(295, 245, 59, 20));
        sizePolicy.setHeightForWidth(labelName->sizePolicy().hasHeightForWidth());
        labelName->setSizePolicy(sizePolicy);
        labelName->setMinimumSize(QSize(59, 20));
        labelName->setMaximumSize(QSize(59, 20));
        labelName->setStyleSheet(QString::fromUtf8("font: 75 20px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        label_21 = new QLabel(AboutUsWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(237, 279, 64, 14));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);
        label_21->setMinimumSize(QSize(64, 14));
        label_21->setMaximumSize(QSize(64, 14));
        label_21->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        labelVersion = new QLabel(AboutUsWidget);
        labelVersion->setObjectName(QStringLiteral("labelVersion"));
        labelVersion->setGeometry(QRect(308, 279, 50, 14));
        sizePolicy.setHeightForWidth(labelVersion->sizePolicy().hasHeightForWidth());
        labelVersion->setSizePolicy(sizePolicy);
        labelVersion->setMinimumSize(QSize(50, 14));
        labelVersion->setMaximumSize(QSize(50, 14));
        labelVersion->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#333333;"));
        checkUpdateButton = new QPushButton(AboutUsWidget);
        checkUpdateButton->setObjectName(QStringLiteral("checkUpdateButton"));
        checkUpdateButton->setGeometry(QRect(265, 312, 120, 36));
        sizePolicy.setHeightForWidth(checkUpdateButton->sizePolicy().hasHeightForWidth());
        checkUpdateButton->setSizePolicy(sizePolicy);
        checkUpdateButton->setMinimumSize(QSize(120, 36));
        checkUpdateButton->setMaximumSize(QSize(120, 36));
        checkUpdateButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #FFFFFF;border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:1px solid #DEDEDE}\n"
"QPushButton:hover,pressed{background-color: #F4F4F4;border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;}\n"
"QPushButton:disabled{background-color:rgba(252,252,252,1);border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(153,153,153,1);};"));
        labelLogout = new QLabel(AboutUsWidget);
        labelLogout->setObjectName(QStringLiteral("labelLogout"));
        labelLogout->setGeometry(QRect(296, 486, 57, 14));
        sizePolicy.setHeightForWidth(labelLogout->sizePolicy().hasHeightForWidth());
        labelLogout->setSizePolicy(sizePolicy);
        labelLogout->setMinimumSize(QSize(57, 14));
        labelLogout->setMaximumSize(QSize(57, 14));
        labelLogout->setCursor(QCursor(Qt::PointingHandCursor));
        labelLogout->setStyleSheet(QString::fromUtf8("QLabel{font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#666666;}\n"
"QLabel:hover,pressed{font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#1F8BED;}"));
        labelVerDes = new QLabel(AboutUsWidget);
        labelVerDes->setObjectName(QStringLiteral("labelVerDes"));
        labelVerDes->setGeometry(QRect(360, 279, 64, 14));
        sizePolicy.setHeightForWidth(labelVerDes->sizePolicy().hasHeightForWidth());
        labelVerDes->setSizePolicy(sizePolicy);
        labelVerDes->setMinimumSize(QSize(64, 14));
        labelVerDes->setMaximumSize(QSize(64, 14));
        labelVerDes->setCursor(QCursor(Qt::PointingHandCursor));
        labelVerDes->setStyleSheet(QString::fromUtf8("font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1E8BED;"));

        verticalLayout->addWidget(FilletWidget);


        retranslateUi(SettingWidget);

        QMetaObject::connectSlotsByName(SettingWidget);
    } // setupUi

    void retranslateUi(QWidget *SettingWidget)
    {
        SettingWidget->setWindowTitle(QApplication::translate("SettingWidget", "SettingWidget", 0));
        deskSettingButton->setText(QString());
        feedBackButton->setText(QString());
        helperButton->setText(QString());
        aboutUsButton->setText(QString());
        closeButton->setText(QString());
        leftLabel->setText(QString());
        label->setText(QApplication::translate("SettingWidget", "\347\273\204\344\273\266", 0));
        rightLabel->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        leftLabel_2->setText(QString());
        rightLabel_2->setText(QString());
        label_4->setText(QApplication::translate("SettingWidget", "\345\267\245\345\205\267", 0));
        label_10->setText(QApplication::translate("SettingWidget", "\351\241\266\351\203\250\350\217\234\345\215\225\346\240\217", 0));
        label_11->setText(QApplication::translate("SettingWidget", "\344\276\247\350\276\271\345\272\224\347\224\250", 0));
        topCheckBox->setText(QApplication::translate("SettingWidget", "CheckBox", 0));
        rightCheckBox->setText(QApplication::translate("SettingWidget", "CheckBox", 0));
        numberLabel->setText(QApplication::translate("SettingWidget", "0/1000", 0));
        label_17->setText(QApplication::translate("SettingWidget", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", 0));
        lineEdit->setPlaceholderText(QApplication::translate("SettingWidget", "\346\202\250\345\217\257\344\273\245\347\225\231\344\270\213\347\224\265\350\257\235\346\210\226\351\202\256\347\256\261\344\273\245\344\276\277\344\270\216\346\202\250\345\217\226\345\276\227\350\201\224\347\263\273", 0));
        commitButton->setText(QApplication::translate("SettingWidget", "\346\217\220\344\272\244", 0));
        otherButton->setText(QApplication::translate("SettingWidget", "\345\205\266\344\273\226", 0));
        errorButton->setText(QApplication::translate("SettingWidget", "\345\271\263\345\217\260\346\225\205\351\232\234", 0));
        designButton->setText(QApplication::translate("SettingWidget", "\347\225\214\351\235\242\350\256\276\350\256\241", 0));
        deskAppButton->setText(QApplication::translate("SettingWidget", "\346\241\214\351\235\242\345\272\224\347\224\250", 0));
        majorButton->setText(QApplication::translate("SettingWidget", "\345\212\237\350\203\275\344\274\230\345\214\226", 0));
        label_18->setText(QString());
        label_19->setText(QApplication::translate("SettingWidget", "\350\210\252\345\244\251\344\277\241\346\201\257\345\256\242\346\234\215\347\203\255\347\272\277", 0));
        label_20->setText(QApplication::translate("SettingWidget", "95113", 0));
        helpButton->setText(QString());
        demoButton->setText(QString());
        questionButton->setText(QString());
        guideButton->setText(QString());
        labelIcon->setText(QString());
        labelName->setText(QApplication::translate("SettingWidget", "\344\272\221\350\264\242\347\250\216", 0));
        label_21->setText(QApplication::translate("SettingWidget", "\345\275\223\345\211\215\347\211\210\346\234\254\357\274\232", 0));
        labelVersion->setText(QApplication::translate("SettingWidget", "5.0.0", 0));
        checkUpdateButton->setText(QApplication::translate("SettingWidget", "\346\243\200\346\265\213\346\233\264\346\226\260", 0));
        labelLogout->setText(QApplication::translate("SettingWidget", "\351\200\200\345\207\272\347\231\273\345\275\225", 0));
        labelVerDes->setText(QApplication::translate("SettingWidget", "\347\211\210\346\234\254\350\257\264\346\230\216", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingWidget: public Ui_SettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWIDGET_H
