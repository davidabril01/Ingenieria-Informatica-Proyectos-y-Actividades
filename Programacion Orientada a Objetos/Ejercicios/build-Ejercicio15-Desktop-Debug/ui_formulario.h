/********************************************************************************
** Form generated from reading UI file 'formulario.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIO_H
#define UI_FORMULARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Formulario
{
public:
    QGridLayout *gridLayout;
    QLabel *L_Nombre;
    QLabel *L_Apellido;
    QLabel *L_Legajo;
    QPushButton *PB_Enviar;
    QLineEdit *LE_Captcha;
    QLabel *L_Captcha;
    QLabel *L_CaptchaTitle;
    QLineEdit *LE_Apellido;
    QLineEdit *LE_Nombre;
    QLineEdit *LE_Legajo;

    void setupUi(QWidget *Formulario)
    {
        if (Formulario->objectName().isEmpty())
            Formulario->setObjectName(QString::fromUtf8("Formulario"));
        Formulario->resize(293, 202);
        gridLayout = new QGridLayout(Formulario);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        L_Nombre = new QLabel(Formulario);
        L_Nombre->setObjectName(QString::fromUtf8("L_Nombre"));

        gridLayout->addWidget(L_Nombre, 1, 0, 1, 1);

        L_Apellido = new QLabel(Formulario);
        L_Apellido->setObjectName(QString::fromUtf8("L_Apellido"));

        gridLayout->addWidget(L_Apellido, 4, 0, 1, 1);

        L_Legajo = new QLabel(Formulario);
        L_Legajo->setObjectName(QString::fromUtf8("L_Legajo"));

        gridLayout->addWidget(L_Legajo, 0, 0, 1, 1);

        PB_Enviar = new QPushButton(Formulario);
        PB_Enviar->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(PB_Enviar, 7, 3, 1, 1);

        LE_Captcha = new QLineEdit(Formulario);
        LE_Captcha->setObjectName(QString::fromUtf8("LE_Captcha"));

        gridLayout->addWidget(LE_Captcha, 6, 3, 1, 1);

        L_Captcha = new QLabel(Formulario);
        L_Captcha->setObjectName(QString::fromUtf8("L_Captcha"));

        gridLayout->addWidget(L_Captcha, 6, 0, 1, 2);

        L_CaptchaTitle = new QLabel(Formulario);
        L_CaptchaTitle->setObjectName(QString::fromUtf8("L_CaptchaTitle"));

        gridLayout->addWidget(L_CaptchaTitle, 5, 0, 1, 2);

        LE_Apellido = new QLineEdit(Formulario);
        LE_Apellido->setObjectName(QString::fromUtf8("LE_Apellido"));

        gridLayout->addWidget(LE_Apellido, 4, 1, 1, 3);

        LE_Nombre = new QLineEdit(Formulario);
        LE_Nombre->setObjectName(QString::fromUtf8("LE_Nombre"));

        gridLayout->addWidget(LE_Nombre, 1, 1, 1, 3);

        LE_Legajo = new QLineEdit(Formulario);
        LE_Legajo->setObjectName(QString::fromUtf8("LE_Legajo"));

        gridLayout->addWidget(LE_Legajo, 0, 1, 1, 3);


        retranslateUi(Formulario);

        QMetaObject::connectSlotsByName(Formulario);
    } // setupUi

    void retranslateUi(QWidget *Formulario)
    {
        Formulario->setWindowTitle(QCoreApplication::translate("Formulario", "Form", nullptr));
        L_Nombre->setText(QCoreApplication::translate("Formulario", "Nombre", nullptr));
        L_Apellido->setText(QCoreApplication::translate("Formulario", "Apellido", nullptr));
        L_Legajo->setText(QCoreApplication::translate("Formulario", "Legajo", nullptr));
        PB_Enviar->setText(QCoreApplication::translate("Formulario", "Enviar", nullptr));
        L_Captcha->setText(QString());
        L_CaptchaTitle->setText(QCoreApplication::translate("Formulario", "Captcha", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Formulario: public Ui_Formulario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIO_H
