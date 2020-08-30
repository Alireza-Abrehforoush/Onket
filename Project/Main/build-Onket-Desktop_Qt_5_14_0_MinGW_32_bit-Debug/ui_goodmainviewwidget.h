/********************************************************************************
** Form generated from reading UI file 'goodmainviewwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODMAINVIEWWIDGET_H
#define UI_GOODMAINVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>

QT_BEGIN_NAMESPACE

class Ui_goodMainviewWidget
{
public:

    void setupUi(QScrollArea *goodMainviewWidget)
    {
        if (goodMainviewWidget->objectName().isEmpty())
            goodMainviewWidget->setObjectName(QString::fromUtf8("goodMainviewWidget"));
        goodMainviewWidget->resize(400, 300);
        goodMainviewWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(goodMainviewWidget);

        QMetaObject::connectSlotsByName(goodMainviewWidget);
    } // setupUi

    void retranslateUi(QScrollArea *goodMainviewWidget)
    {
        goodMainviewWidget->setWindowTitle(QCoreApplication::translate("goodMainviewWidget", "ScrollArea", nullptr));
    } // retranslateUi

};

namespace Ui {
    class goodMainviewWidget: public Ui_goodMainviewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODMAINVIEWWIDGET_H
