/********************************************************************************
** Form generated from reading UI file 'comparewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPAREWIDGET_H
#define UI_COMPAREWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompareWidget
{
public:

    void setupUi(QWidget *CompareWidget)
    {
        if (CompareWidget->objectName().isEmpty())
            CompareWidget->setObjectName(QString::fromUtf8("CompareWidget"));
        CompareWidget->resize(400, 300);
        CompareWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(CompareWidget);

        QMetaObject::connectSlotsByName(CompareWidget);
    } // setupUi

    void retranslateUi(QWidget *CompareWidget)
    {
        CompareWidget->setWindowTitle(QCoreApplication::translate("CompareWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompareWidget: public Ui_CompareWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPAREWIDGET_H
