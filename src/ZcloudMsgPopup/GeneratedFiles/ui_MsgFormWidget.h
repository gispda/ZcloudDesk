/********************************************************************************
** Form generated from reading UI file 'MsgFormWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGFORMWIDGET_H
#define UI_MSGFORMWIDGET_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgFormWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *FormFilletWidget;
    QPushButton *closeButton;
    QWebView *webView;

    void setupUi(QWidget *MsgFormWidget)
    {
        if (MsgFormWidget->objectName().isEmpty())
            MsgFormWidget->setObjectName(QStringLiteral("MsgFormWidget"));
        MsgFormWidget->resize(396, 456);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MsgFormWidget->sizePolicy().hasHeightForWidth());
        MsgFormWidget->setSizePolicy(sizePolicy);
        MsgFormWidget->setMinimumSize(QSize(396, 456));
        MsgFormWidget->setMaximumSize(QSize(396, 456));
        verticalLayout = new QVBoxLayout(MsgFormWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        FormFilletWidget = new QWidget(MsgFormWidget);
        FormFilletWidget->setObjectName(QStringLiteral("FormFilletWidget"));
        sizePolicy.setHeightForWidth(FormFilletWidget->sizePolicy().hasHeightForWidth());
        FormFilletWidget->setSizePolicy(sizePolicy);
        FormFilletWidget->setMinimumSize(QSize(380, 440));
        FormFilletWidget->setMaximumSize(QSize(380, 440));
        FormFilletWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        closeButton = new QPushButton(FormFilletWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(345, 2, 32, 28));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(32, 28));
        closeButton->setMaximumSize(QSize(32, 28));
        closeButton->setStyleSheet(QLatin1String("QPushButton{border-image: url(:/ZcloudMsgPopup/image/close.png);}\n"
"QPushButton:hover,pressed{border-image: url(:/ZcloudMsgPopup/image/close_sel.png);};"));
        webView = new QWebView(FormFilletWidget);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setGeometry(QRect(9, 29, 371, 401));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        verticalLayout->addWidget(FormFilletWidget);


        retranslateUi(MsgFormWidget);

        QMetaObject::connectSlotsByName(MsgFormWidget);
    } // setupUi

    void retranslateUi(QWidget *MsgFormWidget)
    {
        MsgFormWidget->setWindowTitle(QApplication::translate("MsgFormWidget", "MsgFormWidget", 0));
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MsgFormWidget: public Ui_MsgFormWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGFORMWIDGET_H
