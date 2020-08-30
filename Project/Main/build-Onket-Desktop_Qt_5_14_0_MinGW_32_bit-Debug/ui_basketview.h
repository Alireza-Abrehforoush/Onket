/********************************************************************************
** Form generated from reading UI file 'basketview.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASKETVIEW_H
#define UI_BASKETVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>

QT_BEGIN_NAMESPACE

class Ui_BasketView
{
public:

    void setupUi(QScrollArea *BasketView)
    {
        if (BasketView->objectName().isEmpty())
            BasketView->setObjectName(QString::fromUtf8("BasketView"));
        BasketView->resize(400, 300);
        BasketView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(BasketView);

        QMetaObject::connectSlotsByName(BasketView);
    } // setupUi

    void retranslateUi(QScrollArea *BasketView)
    {
        BasketView->setWindowTitle(QCoreApplication::translate("BasketView", "ScrollArea", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BasketView: public Ui_BasketView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASKETVIEW_H
