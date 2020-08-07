/********************************************************************************
** Form generated from reading UI file 'WorkerCommentWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKERCOMMENTWIDGET_H
#define UI_WORKERCOMMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkerCommentWidget
{
public:
    QPushButton *buttonOK;
    QLabel *labelTitle_3;
    QPushButton *buttonGrade1;
    QPushButton *buttonGrade2;
    QPushButton *buttonGrade3;
    QPushButton *buttonGrade5;
    QPushButton *buttonGrade4;
    QLabel *labellevel;
    QTextEdit *editContent;
    QPushButton *buttonCancel;
    QLabel *labestar1;
    QLabel *labestar2;
    QLabel *labestar3;
    QLabel *labestar5;
    QLabel *labestar6;
    QLabel *labestar4;

    void setupUi(QWidget *WorkerCommentWidget)
    {
        if (WorkerCommentWidget->objectName().isEmpty())
            WorkerCommentWidget->setObjectName(QStringLiteral("WorkerCommentWidget"));
        WorkerCommentWidget->resize(478, 409);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WorkerCommentWidget->sizePolicy().hasHeightForWidth());
        WorkerCommentWidget->setSizePolicy(sizePolicy);
        WorkerCommentWidget->setMinimumSize(QSize(300, 300));
        WorkerCommentWidget->setMaximumSize(QSize(840, 500));
        WorkerCommentWidget->setStyleSheet(QStringLiteral("QWidget#FinanMemberWidget{background-color: rgb(255, 255, 255);border-radius:8px;}"));
        buttonOK = new QPushButton(WorkerCommentWidget);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));
        buttonOK->setGeometry(QRect(140, 370, 80, 32));
        sizePolicy.setHeightForWidth(buttonOK->sizePolicy().hasHeightForWidth());
        buttonOK->setSizePolicy(sizePolicy);
        buttonOK->setMinimumSize(QSize(72, 32));
        buttonOK->setMaximumSize(QSize(100, 32));
        buttonOK->setStyleSheet(QString::fromUtf8("QPushButton{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2, 164, 253, 1), stop:1 rgba(31, 139, 237, 1));border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"			QPushButton:hover,pressed{ background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(40, 178, 253, 1),stop:1 rgba(64, 156, 240, 1));\n"
"		  border-radius:4px;font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";color:rgba(255, 255, 255, 1);}\n"
"QPushButton:disabled{ background-color:rgba(200,200,200,1);border-radius:4px;};"));
        labelTitle_3 = new QLabel(WorkerCommentWidget);
        labelTitle_3->setObjectName(QStringLiteral("labelTitle_3"));
        labelTitle_3->setGeometry(QRect(0, 20, 400, 18));
        sizePolicy.setHeightForWidth(labelTitle_3->sizePolicy().hasHeightForWidth());
        labelTitle_3->setSizePolicy(sizePolicy);
        labelTitle_3->setMinimumSize(QSize(80, 18));
        labelTitle_3->setMaximumSize(QSize(400, 18));
        labelTitle_3->setStyleSheet(QString::fromUtf8("font: 16px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        labelTitle_3->setAlignment(Qt::AlignCenter);
        buttonGrade1 = new QPushButton(WorkerCommentWidget);
        buttonGrade1->setObjectName(QStringLiteral("buttonGrade1"));
        buttonGrade1->setGeometry(QRect(60, 80, 40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/EntCenterWidget/image/faspace.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonGrade1->setIcon(icon);
        buttonGrade1->setIconSize(QSize(40, 40));
        buttonGrade1->setFlat(true);
        buttonGrade2 = new QPushButton(WorkerCommentWidget);
        buttonGrade2->setObjectName(QStringLiteral("buttonGrade2"));
        buttonGrade2->setGeometry(QRect(140, 80, 40, 40));
        buttonGrade2->setIcon(icon);
        buttonGrade2->setIconSize(QSize(40, 40));
        buttonGrade2->setFlat(true);
        buttonGrade3 = new QPushButton(WorkerCommentWidget);
        buttonGrade3->setObjectName(QStringLiteral("buttonGrade3"));
        buttonGrade3->setGeometry(QRect(210, 80, 40, 40));
        buttonGrade3->setIcon(icon);
        buttonGrade3->setIconSize(QSize(40, 40));
        buttonGrade3->setFlat(true);
        buttonGrade5 = new QPushButton(WorkerCommentWidget);
        buttonGrade5->setObjectName(QStringLiteral("buttonGrade5"));
        buttonGrade5->setGeometry(QRect(360, 80, 40, 40));
        buttonGrade5->setIcon(icon);
        buttonGrade5->setIconSize(QSize(40, 40));
        buttonGrade5->setCheckable(false);
        buttonGrade5->setChecked(false);
        buttonGrade5->setFlat(true);
        buttonGrade4 = new QPushButton(WorkerCommentWidget);
        buttonGrade4->setObjectName(QStringLiteral("buttonGrade4"));
        buttonGrade4->setGeometry(QRect(290, 80, 40, 40));
        buttonGrade4->setIcon(icon);
        buttonGrade4->setIconSize(QSize(40, 40));
        buttonGrade4->setFlat(true);
        labellevel = new QLabel(WorkerCommentWidget);
        labellevel->setObjectName(QStringLiteral("labellevel"));
        labellevel->setGeometry(QRect(40, 140, 371, 20));
        labellevel->setStyleSheet(QString::fromUtf8("font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(51, 51, 51);\n"
"border-bottom:0px;"));
        labellevel->setAlignment(Qt::AlignCenter);
        editContent = new QTextEdit(WorkerCommentWidget);
        editContent->setObjectName(QStringLiteral("editContent"));
        editContent->setGeometry(QRect(40, 240, 411, 111));
        buttonCancel = new QPushButton(WorkerCommentWidget);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setGeometry(QRect(260, 370, 80, 32));
        sizePolicy.setHeightForWidth(buttonCancel->sizePolicy().hasHeightForWidth());
        buttonCancel->setSizePolicy(sizePolicy);
        buttonCancel->setMinimumSize(QSize(72, 32));
        buttonCancel->setMaximumSize(QSize(100, 32));
        buttonCancel->setStyleSheet(QStringLiteral(""));
        labestar1 = new QLabel(WorkerCommentWidget);
        labestar1->setObjectName(QStringLiteral("labestar1"));
        labestar1->setGeometry(QRect(40, 170, 120, 23));
        labestar2 = new QLabel(WorkerCommentWidget);
        labestar2->setObjectName(QStringLiteral("labestar2"));
        labestar2->setGeometry(QRect(190, 170, 120, 23));
        labestar3 = new QLabel(WorkerCommentWidget);
        labestar3->setObjectName(QStringLiteral("labestar3"));
        labestar3->setGeometry(QRect(350, 170, 120, 23));
        labestar5 = new QLabel(WorkerCommentWidget);
        labestar5->setObjectName(QStringLiteral("labestar5"));
        labestar5->setGeometry(QRect(190, 200, 120, 23));
        labestar6 = new QLabel(WorkerCommentWidget);
        labestar6->setObjectName(QStringLiteral("labestar6"));
        labestar6->setGeometry(QRect(350, 200, 120, 23));
        labestar4 = new QLabel(WorkerCommentWidget);
        labestar4->setObjectName(QStringLiteral("labestar4"));
        labestar4->setGeometry(QRect(40, 200, 120, 23));

        retranslateUi(WorkerCommentWidget);

        QMetaObject::connectSlotsByName(WorkerCommentWidget);
    } // setupUi

    void retranslateUi(QWidget *WorkerCommentWidget)
    {
        WorkerCommentWidget->setWindowTitle(QApplication::translate("WorkerCommentWidget", "FinanMemberWidget", 0));
        buttonOK->setText(QApplication::translate("WorkerCommentWidget", "\347\241\256\345\256\232", 0));
        labelTitle_3->setText(QApplication::translate("WorkerCommentWidget", "\350\257\267\345\257\271\346\234\254\346\254\241\346\234\215\345\212\241\350\277\233\350\241\214\350\257\204\344\273\267", 0));
        buttonGrade1->setText(QString());
        buttonGrade2->setText(QString());
        buttonGrade3->setText(QString());
        buttonGrade5->setText(QString());
        buttonGrade4->setText(QString());
        labellevel->setText(QString());
        editContent->setPlaceholderText(QApplication::translate("WorkerCommentWidget", "\345\241\253\345\206\231\346\233\264\345\244\232\347\232\204\345\206\205\345\256\271\357\274\214\344\273\245\345\270\256\345\212\251\346\210\221\344\273\254\346\233\264\345\245\275\347\232\204\344\270\272\346\202\250\346\234\215\345\212\241", 0));
        buttonCancel->setText(QApplication::translate("WorkerCommentWidget", "\346\232\202\344\270\215\350\257\204\344\273\267", 0));
        labestar1->setText(QString());
        labestar2->setText(QString());
        labestar3->setText(QString());
        labestar5->setText(QString());
        labestar6->setText(QString());
        labestar4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WorkerCommentWidget: public Ui_WorkerCommentWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERCOMMENTWIDGET_H
