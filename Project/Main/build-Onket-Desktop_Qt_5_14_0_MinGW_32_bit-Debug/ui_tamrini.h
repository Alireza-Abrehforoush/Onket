/********************************************************************************
** Form generated from reading UI file 'tamrini.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAMRINI_H
#define UI_TAMRINI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tamrini
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *Tamrini)
    {
        if (Tamrini->objectName().isEmpty())
            Tamrini->setObjectName(QString::fromUtf8("Tamrini"));
        Tamrini->resize(400, 300);
        tableWidget = new QTableWidget(Tamrini);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(110, 70, 256, 192));

        retranslateUi(Tamrini);

        QMetaObject::connectSlotsByName(Tamrini);
    } // setupUi

    void retranslateUi(QWidget *Tamrini)
    {
        Tamrini->setWindowTitle(QCoreApplication::translate("Tamrini", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tamrini: public Ui_Tamrini {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAMRINI_H
