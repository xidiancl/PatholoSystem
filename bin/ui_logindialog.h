/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_logindialog
{
public:
    QLabel *labelDialog;
    QLineEdit *lineEditPassWord;
    QPushButton *pushButtonCancel;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButtonOk;
    QLineEdit *lineEditUserName;

    void setupUi(QDialog *logindialog)
    {
        if (logindialog->objectName().isEmpty())
            logindialog->setObjectName(QStringLiteral("logindialog"));
        logindialog->resize(615, 350);
        logindialog->setMinimumSize(QSize(615, 350));
        logindialog->setMaximumSize(QSize(615, 350));
        logindialog->setStyleSheet(QStringLiteral(""));
        labelDialog = new QLabel(logindialog);
        labelDialog->setObjectName(QStringLiteral("labelDialog"));
        labelDialog->setGeometry(QRect(-1, -1, 616, 351));
        labelDialog->setStyleSheet(QStringLiteral("border-image: url(:/image/image/login.png);"));
        labelDialog->setScaledContents(true);
        lineEditPassWord = new QLineEdit(logindialog);
        lineEditPassWord->setObjectName(QStringLiteral("lineEditPassWord"));
        lineEditPassWord->setGeometry(QRect(430, 220, 150, 22));
        lineEditPassWord->setMinimumSize(QSize(150, 0));
        lineEditPassWord->setEchoMode(QLineEdit::Password);
        pushButtonCancel = new QPushButton(logindialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(500, 289, 75, 23));
        label_2 = new QLabel(logindialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 220, 70, 22));
        label_2->setMinimumSize(QSize(50, 22));
        label_2->setStyleSheet(QStringLiteral(""));
        label = new QLabel(logindialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 190, 70, 22));
        label->setMinimumSize(QSize(50, 22));
        label->setStyleSheet(QStringLiteral(""));
        pushButtonOk = new QPushButton(logindialog);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(413, 289, 75, 23));
        lineEditUserName = new QLineEdit(logindialog);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));
        lineEditUserName->setGeometry(QRect(430, 190, 150, 22));
        lineEditUserName->setMinimumSize(QSize(150, 0));
        QWidget::setTabOrder(pushButtonOk, pushButtonCancel);
        QWidget::setTabOrder(pushButtonCancel, lineEditPassWord);
        QWidget::setTabOrder(lineEditPassWord, lineEditUserName);

        retranslateUi(logindialog);

        QMetaObject::connectSlotsByName(logindialog);
    } // setupUi

    void retranslateUi(QDialog *logindialog)
    {
        logindialog->setWindowTitle(QApplication::translate("logindialog", "Dialog", 0));
        labelDialog->setText(QString());
        pushButtonCancel->setText(QApplication::translate("logindialog", "\345\217\226\346\266\210", 0));
        label_2->setText(QApplication::translate("logindialog", "\345\257\206    \347\240\201\357\274\232", 0));
        label->setText(QApplication::translate("logindialog", "\347\231\273\345\275\225\345\220\215\347\247\260\357\274\232", 0));
        pushButtonOk->setText(QApplication::translate("logindialog", "\347\241\256\350\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class logindialog: public Ui_logindialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
