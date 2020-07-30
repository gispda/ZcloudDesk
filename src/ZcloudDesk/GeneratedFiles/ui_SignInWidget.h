/********************************************************************************
** Form generated from reading UI file 'SignInWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINWIDGET_H
#define UI_SIGNINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignInWidget
{
public:
    QLabel *label_round2;
    QLabel *label_12;
    QLabel *labelPic;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *labelCoin;
    QLabel *label_round1;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_round4;
    QLabel *label_11;
    QLabel *label_2;
    QLabel *label_line3;
    QLabel *label_4;
    QLabel *label_round3;
    QLabel *label_8;
    QLabel *label_line2;
    QLabel *labelDay;
    QPushButton *closeButton;
    QLabel *label_line1;
    QPushButton *signInButton;
    QLabel *label_9;
    QLabel *label_line4;

    void setupUi(QWidget *SignInWidget)
    {
        if (SignInWidget->objectName().isEmpty())
            SignInWidget->setObjectName(QStringLiteral("SignInWidget"));
        SignInWidget->resize(460, 523);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SignInWidget->sizePolicy().hasHeightForWidth());
        SignInWidget->setSizePolicy(sizePolicy);
        SignInWidget->setMinimumSize(QSize(460, 523));
        SignInWidget->setMaximumSize(QSize(460, 523));
        SignInWidget->setFocusPolicy(Qt::NoFocus);
        SignInWidget->setStyleSheet(QStringLiteral("QWidget#SignInWidget{border-image: url(:/ZcloudDesk/image/signIn.png);border-radius:8px;}"));
        label_round2 = new QLabel(SignInWidget);
        label_round2->setObjectName(QStringLiteral("label_round2"));
        label_round2->setGeometry(QRect(168, 260, 21, 21));
        sizePolicy.setHeightForWidth(label_round2->sizePolicy().hasHeightForWidth());
        label_round2->setSizePolicy(sizePolicy);
        label_round2->setMinimumSize(QSize(21, 21));
        label_round2->setMaximumSize(QSize(21, 21));
        label_round2->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/round.png);"));
        label_12 = new QLabel(SignInWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(357, 218, 34, 35));
        label_12->setStyleSheet(QString::fromUtf8("border-image: url(:/ZcloudDesk/image/coin_tips.png);\n"
"color: rgb(255, 255, 255);\n"
"font: 10px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_12->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        labelPic = new QLabel(SignInWidget);
        labelPic->setObjectName(QStringLiteral("labelPic"));
        labelPic->setGeometry(QRect(20, 413, 420, 90));
        sizePolicy.setHeightForWidth(labelPic->sizePolicy().hasHeightForWidth());
        labelPic->setSizePolicy(sizePolicy);
        labelPic->setMinimumSize(QSize(420, 90));
        labelPic->setMaximumSize(QSize(420, 90));
        label_6 = new QLabel(SignInWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(151, 298, 54, 16));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(51, 51, 51);\n"
"font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_6->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(SignInWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(162, 218, 34, 35));
        label_10->setStyleSheet(QString::fromUtf8("border-image: url(:/ZcloudDesk/image/coin_tips.png);\n"
"color: rgb(255, 255, 255);\n"
"font: 10px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_10->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        labelCoin = new QLabel(SignInWidget);
        labelCoin->setObjectName(QStringLiteral("labelCoin"));
        labelCoin->setGeometry(QRect(60, 63, 121, 15));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelCoin->sizePolicy().hasHeightForWidth());
        labelCoin->setSizePolicy(sizePolicy1);
        labelCoin->setMinimumSize(QSize(0, 15));
        labelCoin->setMaximumSize(QSize(16777215, 15));
        labelCoin->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_round1 = new QLabel(SignInWidget);
        label_round1->setObjectName(QStringLiteral("label_round1"));
        label_round1->setGeometry(QRect(70, 260, 21, 21));
        sizePolicy.setHeightForWidth(label_round1->sizePolicy().hasHeightForWidth());
        label_round1->setSizePolicy(sizePolicy);
        label_round1->setMinimumSize(QSize(21, 21));
        label_round1->setMaximumSize(QSize(21, 21));
        label_round1->setStyleSheet(QStringLiteral("QLabel#label_round1{border-image: url(:/ZcloudDesk/image/round.png);}"));
        label = new QLabel(SignInWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 63, 41, 15));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 15));
        label->setMaximumSize(QSize(16777215, 15));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_7 = new QLabel(SignInWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(248, 298, 54, 16));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(51, 51, 51);\n"
"font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_7->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(SignInWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(52, 298, 54, 16));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(51, 51, 51);\n"
"font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_5->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(SignInWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(384, 62, 61, 14));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(0, 14));
        label_3->setMaximumSize(QSize(16777215, 14));
        label_3->setFocusPolicy(Qt::NoFocus);
        label_3->setStyleSheet(QString::fromUtf8("QToolTip{background:rgba(255,253,244,1);border:1px solid rgba(255, 253, 244, 1);color:#333333;font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";}\n"
"QLabel#label_3{color:rgb(255, 255, 255);font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";};\n"
"\n"
""));
        label_round4 = new QLabel(SignInWidget);
        label_round4->setObjectName(QStringLiteral("label_round4"));
        label_round4->setGeometry(QRect(359, 255, 31, 31));
        sizePolicy.setHeightForWidth(label_round4->sizePolicy().hasHeightForWidth());
        label_round4->setSizePolicy(sizePolicy);
        label_round4->setMinimumSize(QSize(31, 31));
        label_round4->setMaximumSize(QSize(31, 31));
        label_round4->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/gift.png);"));
        label_11 = new QLabel(SignInWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(260, 218, 34, 35));
        label_11->setStyleSheet(QString::fromUtf8("border-image: url(:/ZcloudDesk/image/coin_tips.png);\n"
"color: rgb(255, 255, 255);\n"
"font: 10px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_11->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_2 = new QLabel(SignInWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(174, 140, 112, 14));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(112, 14));
        label_2->setMaximumSize(QSize(16777215, 14));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_line3 = new QLabel(SignInWidget);
        label_line3->setObjectName(QStringLiteral("label_line3"));
        label_line3->setGeometry(QRect(220, 270, 90, 1));
        sizePolicy.setHeightForWidth(label_line3->sizePolicy().hasHeightForWidth());
        label_line3->setSizePolicy(sizePolicy);
        label_line3->setMinimumSize(QSize(90, 1));
        label_line3->setMaximumSize(QSize(90, 1));
        label_line3->setStyleSheet(QStringLiteral("background-color: rgb(229, 237, 240);"));
        label_4 = new QLabel(SignInWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(366, 63, 14, 14));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(14, 14));
        label_4->setMaximumSize(QSize(14, 14));
        label_4->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/tip.png);"));
        label_round3 = new QLabel(SignInWidget);
        label_round3->setObjectName(QStringLiteral("label_round3"));
        label_round3->setGeometry(QRect(266, 260, 21, 21));
        sizePolicy.setHeightForWidth(label_round3->sizePolicy().hasHeightForWidth());
        label_round3->setSizePolicy(sizePolicy);
        label_round3->setMinimumSize(QSize(21, 21));
        label_round3->setMaximumSize(QSize(21, 21));
        label_round3->setStyleSheet(QStringLiteral("border-image: url(:/ZcloudDesk/image/round.png);"));
        label_8 = new QLabel(SignInWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(348, 298, 54, 16));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(51, 51, 51);\n"
"font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_8->setAlignment(Qt::AlignCenter);
        label_line2 = new QLabel(SignInWidget);
        label_line2->setObjectName(QStringLiteral("label_line2"));
        label_line2->setGeometry(QRect(130, 270, 90, 1));
        sizePolicy.setHeightForWidth(label_line2->sizePolicy().hasHeightForWidth());
        label_line2->setSizePolicy(sizePolicy);
        label_line2->setMinimumSize(QSize(90, 1));
        label_line2->setMaximumSize(QSize(90, 1));
        label_line2->setStyleSheet(QStringLiteral("background-color: rgb(229, 237, 240);"));
        labelDay = new QLabel(SignInWidget);
        labelDay->setObjectName(QStringLiteral("labelDay"));
        labelDay->setGeometry(QRect(190, 62, 81, 57));
        sizePolicy1.setHeightForWidth(labelDay->sizePolicy().hasHeightForWidth());
        labelDay->setSizePolicy(sizePolicy1);
        labelDay->setMinimumSize(QSize(0, 57));
        labelDay->setMaximumSize(QSize(16777215, 57));
        labelDay->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 72px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        labelDay->setAlignment(Qt::AlignCenter);
        closeButton = new QPushButton(SignInWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(425, 5, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudDesk/image/white_close.png);border-radius:none;background-color: rgba(255, 255, 255, 0);}\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/white_close_sel.png);};"));
        label_line1 = new QLabel(SignInWidget);
        label_line1->setObjectName(QStringLiteral("label_line1"));
        label_line1->setGeometry(QRect(40, 270, 90, 1));
        sizePolicy.setHeightForWidth(label_line1->sizePolicy().hasHeightForWidth());
        label_line1->setSizePolicy(sizePolicy);
        label_line1->setMinimumSize(QSize(90, 1));
        label_line1->setMaximumSize(QSize(90, 1));
        label_line1->setStyleSheet(QStringLiteral("background-color: rgb(229, 237, 240);"));
        signInButton = new QPushButton(SignInWidget);
        signInButton->setObjectName(QStringLiteral("signInButton"));
        signInButton->setGeometry(QRect(150, 338, 160, 40));
        sizePolicy.setHeightForWidth(signInButton->sizePolicy().hasHeightForWidth());
        signInButton->setSizePolicy(sizePolicy);
        signInButton->setMinimumSize(QSize(160, 40));
        signInButton->setMaximumSize(QSize(160, 40));
        signInButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);padding-left:8px;}\n"
"QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        label_9 = new QLabel(SignInWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(64, 218, 34, 35));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/ZcloudDesk/image/coin_tips.png);\n"
"color: rgb(255, 255, 255);\n"
"font: 10px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_9->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_9->setIndent(-1);
        label_line4 = new QLabel(SignInWidget);
        label_line4->setObjectName(QStringLiteral("label_line4"));
        label_line4->setGeometry(QRect(310, 270, 120, 1));
        sizePolicy.setHeightForWidth(label_line4->sizePolicy().hasHeightForWidth());
        label_line4->setSizePolicy(sizePolicy);
        label_line4->setMinimumSize(QSize(120, 1));
        label_line4->setMaximumSize(QSize(120, 1));
        label_line4->setStyleSheet(QStringLiteral("background-color: rgb(229, 237, 240);"));

        retranslateUi(SignInWidget);

        QMetaObject::connectSlotsByName(SignInWidget);
    } // setupUi

    void retranslateUi(QWidget *SignInWidget)
    {
        SignInWidget->setWindowTitle(QApplication::translate("SignInWidget", "SignInWidget", 0));
        label_round2->setText(QString());
        label_12->setText(QApplication::translate("SignInWidget", "<html><head/><body><p style='line-height:15px'>+100</p><p style='line-height:-5px'>\344\272\221\345\270\201</p></body></html>", 0));
        labelPic->setText(QString());
        label_6->setText(QApplication::translate("SignInWidget", "10\345\244\251", 0));
        label_10->setText(QApplication::translate("SignInWidget", "<html><head/><body><p style='line-height:15px'>+30</p><p style='line-height:-5px'>\344\272\221\345\270\201</p></body></html>", 0));
        labelCoin->setText(QApplication::translate("SignInWidget", "0", 0));
#ifndef QT_NO_TOOLTIP
        label_round1->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_round1->setText(QString());
        label->setText(QApplication::translate("SignInWidget", "\344\272\221\345\270\201\357\274\232", 0));
        label_7->setText(QApplication::translate("SignInWidget", "15\345\244\251", 0));
        label_5->setText(QApplication::translate("SignInWidget", "5\345\244\251", 0));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("SignInWidget", "1\343\200\201\346\257\217\346\227\245\347\255\276\345\210\260\345\217\257\350\216\267\345\276\22710\344\272\221\345\270\201\n"
"2\343\200\201\346\257\217\346\234\210\347\264\257\350\256\241\347\255\276\345\210\2605\345\244\251\343\200\20110\345\244\251\343\200\20115\345\244\251\343\200\201\n"
"20\345\244\251\357\274\214\345\217\257\345\210\206\345\210\253\350\216\267\345\276\227\351\242\235\345\244\226\345\245\226\345\212\26110\343\200\20130\343\200\201\n"
"60\343\200\201100\344\272\221\345\270\201\345\245\226\345\212\261\n"
"3\343\200\201\347\264\257\350\256\241\347\255\276\345\210\260\345\244\251\346\225\260\344\273\245\350\207\252\347\204\266\346\234\210\344\270\272\345\221\250\346\234\237\357\274\214\n"
"\346\257\217\346\234\210\345\210\235\351\207\215\346\226\260\350\256\241\347\256\227       ", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("SignInWidget", "\347\255\276\345\210\260\350\247\204\345\210\231", 0));
        label_round4->setText(QString());
        label_11->setText(QApplication::translate("SignInWidget", "<html><head/><body><p style='line-height:15px'>+60</p><p style='line-height:-5px'>\344\272\221\345\270\201</p></body></html>", 0));
        label_2->setText(QApplication::translate("SignInWidget", "\346\234\254\346\234\210\347\264\257\350\256\241\347\255\276\345\210\260\345\244\251\346\225\260", 0));
        label_line3->setText(QString());
        label_4->setText(QString());
        label_round3->setText(QString());
        label_8->setText(QApplication::translate("SignInWidget", "20\345\244\251", 0));
        label_line2->setText(QString());
        labelDay->setText(QApplication::translate("SignInWidget", "0", 0));
        closeButton->setText(QString());
        label_line1->setText(QString());
        signInButton->setText(QApplication::translate("SignInWidget", "\347\253\213\345\215\263\347\255\276\345\210\260", 0));
        label_9->setText(QApplication::translate("SignInWidget", "<html><head/><body><p style='line-height:15px'>+10</p><p style='line-height:-5px'>\344\272\221\345\270\201</p></body></html>", 0));
        label_line4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignInWidget: public Ui_SignInWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINWIDGET_H
