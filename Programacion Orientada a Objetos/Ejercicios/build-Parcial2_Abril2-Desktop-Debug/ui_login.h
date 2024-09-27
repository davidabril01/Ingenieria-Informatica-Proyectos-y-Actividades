/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *LClave;
    QLineEdit *leClave;
    QPushButton *pushButton;
    QLabel *LUsuario;
    QLineEdit *leUsuario;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(343, 155);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        LClave = new QLabel(centralwidget);
        LClave->setObjectName(QString::fromUtf8("LClave"));

        gridLayout->addWidget(LClave, 2, 0, 1, 1);

        leClave = new QLineEdit(centralwidget);
        leClave->setObjectName(QString::fromUtf8("leClave"));

        gridLayout->addWidget(leClave, 2, 1, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 2, 1, 1);

        LUsuario = new QLabel(centralwidget);
        LUsuario->setObjectName(QString::fromUtf8("LUsuario"));

        gridLayout->addWidget(LUsuario, 0, 0, 1, 1);

        leUsuario = new QLineEdit(centralwidget);
        leUsuario->setObjectName(QString::fromUtf8("leUsuario"));

        gridLayout->addWidget(leUsuario, 0, 1, 1, 1);

        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 343, 26));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        LClave->setText(QCoreApplication::translate("Login", "Contrase\303\261a", nullptr));
        pushButton->setText(QCoreApplication::translate("Login", "LogIn", nullptr));
        LUsuario->setText(QCoreApplication::translate("Login", "Usuario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
