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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Formulario
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QPushButton *pushButton_Agregar;
    QPushButton *pushButton_VerStock;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Formulario)
    {
        if (Formulario->objectName().isEmpty())
            Formulario->setObjectName(QString::fromUtf8("Formulario"));
        Formulario->resize(349, 265);
        centralwidget = new QWidget(Formulario);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(140, 20, 191, 31));
        pushButton_Agregar = new QPushButton(centralwidget);
        pushButton_Agregar->setObjectName(QString::fromUtf8("pushButton_Agregar"));
        pushButton_Agregar->setGeometry(QRect(10, 20, 121, 31));
        pushButton_VerStock = new QPushButton(centralwidget);
        pushButton_VerStock->setObjectName(QString::fromUtf8("pushButton_VerStock"));
        pushButton_VerStock->setGeometry(QRect(10, 190, 331, 31));
        Formulario->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Formulario);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 349, 22));
        Formulario->setMenuBar(menubar);
        statusbar = new QStatusBar(Formulario);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Formulario->setStatusBar(statusbar);

        retranslateUi(Formulario);

        QMetaObject::connectSlotsByName(Formulario);
    } // setupUi

    void retranslateUi(QMainWindow *Formulario)
    {
        Formulario->setWindowTitle(QCoreApplication::translate("Formulario", "Formulario", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Formulario", "Guitarra", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Formulario", "Viento", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Formulario", "Teclado", nullptr));

        pushButton_Agregar->setText(QCoreApplication::translate("Formulario", "Agregar Instrumento", nullptr));
        pushButton_VerStock->setText(QCoreApplication::translate("Formulario", "Ver Stock", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Formulario: public Ui_Formulario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIO_H
