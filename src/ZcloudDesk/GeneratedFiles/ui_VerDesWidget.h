/********************************************************************************
** Form generated from reading UI file 'VerDesWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERDESWIDGET_H
#define UI_VERDESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerDesWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QPushButton *closeButton;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *VerDesWidget)
    {
        if (VerDesWidget->objectName().isEmpty())
            VerDesWidget->setObjectName(QStringLiteral("VerDesWidget"));
        VerDesWidget->resize(366, 296);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VerDesWidget->sizePolicy().hasHeightForWidth());
        VerDesWidget->setSizePolicy(sizePolicy);
        VerDesWidget->setMinimumSize(QSize(366, 296));
        VerDesWidget->setMaximumSize(QSize(366, 296));
        VerDesWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(VerDesWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        widget = new QWidget(VerDesWidget);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(350, 280));
        widget->setMaximumSize(QSize(350, 280));
        widget->setStyleSheet(QLatin1String("QWidget#widget{background:rgba(255,255,255);\n"
"border-radius:8px;}"));
        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(315, 5, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudDesk/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudDesk/image/close_sel.png);};"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 20, 80, 20));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(80, 20));
        label->setMaximumSize(QSize(80, 20));
        label->setStyleSheet(QString::fromUtf8("font: 18px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#1E8BED;"));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(5, 50, 340, 221));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMinimumSize(QSize(340, 0));
        textEdit->setMaximumSize(QSize(340, 16777215));
        textEdit->setContextMenuPolicy(Qt::NoContextMenu);
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit#textEdit{background-color: rgb(255, 255, 255);font:14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:#333333;border:0px;border-radius:2px;};\n"
"QScrollBar::vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;}QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%); border-radius:4px;min-height:20;}QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/3.png);subcontrol-position:bottom;}QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/1.png);subcontrol-position:top;}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;};"));
        textEdit->setFrameShape(QFrame::StyledPanel);
        textEdit->setLineWidth(0);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setReadOnly(true);
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(widget);


        retranslateUi(VerDesWidget);

        QMetaObject::connectSlotsByName(VerDesWidget);
    } // setupUi

    void retranslateUi(QDialog *VerDesWidget)
    {
        VerDesWidget->setWindowTitle(QApplication::translate("VerDesWidget", "VerDesWidget", 0));
        closeButton->setText(QString());
        label->setText(QApplication::translate("VerDesWidget", "\347\211\210\346\234\254\350\257\264\346\230\216", 0));
        textEdit->setHtml(QApplication::translate("VerDesWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:14px; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">\343\200\220\345\205\250\346\226\260\350\247\206\350\247\211\343\200\221\346\226\260\351\243\216\346\240\274\357\274\214\346\226\260\344\275\223\351\252\214\357\274\214\346\223\215\344\275\234\346\233\264\346\265\201\347\225\205</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">\343\200\220\347\224\250\346\210\267\344\270\255\345\277\203\343\200\221\346\226\260\345\242\236\344"
                        "\272\244\346\230\223\344\277\241\346\201\257\343\200\201\344\272\221\345\270\201\344\273\273\345\212\241\347\255\211\345\212\237\350\203\275\357\274\214\344\274\230\345\214\226\344\272\244\344\272\222\344\275\223\351\252\214</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">\343\200\220\345\272\224\347\224\250\344\270\255\345\277\203\343\200\221\345\205\250\346\226\260\344\275\223\351\252\214\345\215\207\347\272\247\357\274\214\346\226\260\345\242\236\347\203\255\351\227\250\345\272\224\347\224\250\346\216\250\350\215\220\357\274\214\346\211\276\345\210\260\346\202\250\347\232\204\344\270\223\345\261\236\345\272\224\347\224\250</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">\343\200\220\346\266\210\346\201\257\344\270\255\345\277\203\343\200\221\344\274\230\345\214\226\346\266"
                        "\210\346\201\257\345\274\271\347\252\227\357\274\214\346\226\260\345\242\236\346\266\210\346\201\257\346\217\220\351\206\222\357\274\214\344\275\277\346\266\210\346\201\257\346\237\245\347\234\213\346\233\264\346\265\201\347\225\205</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">\343\200\220\344\272\221\345\270\201\347\255\276\345\210\260\343\200\221\347\255\276\345\210\260\345\276\227\344\272\221\345\270\201\357\274\214\345\217\257\344\273\245\345\205\221\346\215\242\344\270\260\345\257\214\345\245\226\345\223\201</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">\343\200\220\344\274\232\345\221\230\344\270\255\345\277\203\343\200\221\346\226\260\345\242\236\344\274\232\345\221\230\345\212\237\350\203\275\357\274\214\345\260\212\344\272\253\346\233\264\345\244\232\346\235\203"
                        "\347\233\212</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class VerDesWidget: public Ui_VerDesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERDESWIDGET_H
