/********************************************************************************
** Form generated from reading UI file 'basketviewitem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASKETVIEWITEM_H
#define UI_BASKETVIEWITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BasketViewItem
{
public:
    QLabel *item_picture;
    QLabel *item_name;
    QLabel *number;
    QSpinBox *item_number;
    QPushButton *remove;
    QLabel *color;
    QLabel *total_price;
    QLabel *seller_code;
    QLabel *inventory;

    void setupUi(QWidget *BasketViewItem)
    {
        if (BasketViewItem->objectName().isEmpty())
            BasketViewItem->setObjectName(QString::fromUtf8("BasketViewItem"));
        BasketViewItem->resize(1000, 300);
        BasketViewItem->setLayoutDirection(Qt::LeftToRight);
        item_picture = new QLabel(BasketViewItem);
        item_picture->setObjectName(QString::fromUtf8("item_picture"));
        item_picture->setGeometry(QRect(790, 50, 200, 200));
        item_name = new QLabel(BasketViewItem);
        item_name->setObjectName(QString::fromUtf8("item_name"));
        item_name->setGeometry(QRect(254, 10, 501, 31));
        item_name->setStyleSheet(QString::fromUtf8("font: 11pt \"MS Shell Dlg 2\";"));
        number = new QLabel(BasketViewItem);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(690, 260, 31, 25));
        item_number = new QSpinBox(BasketViewItem);
        item_number->setObjectName(QString::fromUtf8("item_number"));
        item_number->setGeometry(QRect(613, 260, 71, 25));
        remove = new QPushButton(BasketViewItem);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(460, 260, 80, 25));
        remove->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        color = new QLabel(BasketViewItem);
        color->setObjectName(QString::fromUtf8("color"));
        color->setGeometry(QRect(364, 60, 400, 20));
        total_price = new QLabel(BasketViewItem);
        total_price->setObjectName(QString::fromUtf8("total_price"));
        total_price->setGeometry(QRect(30, 255, 221, 21));
        seller_code = new QLabel(BasketViewItem);
        seller_code->setObjectName(QString::fromUtf8("seller_code"));
        seller_code->setGeometry(QRect(364, 100, 400, 20));
        inventory = new QLabel(BasketViewItem);
        inventory->setObjectName(QString::fromUtf8("inventory"));
        inventory->setGeometry(QRect(364, 140, 400, 20));

        retranslateUi(BasketViewItem);

        QMetaObject::connectSlotsByName(BasketViewItem);
    } // setupUi

    void retranslateUi(QWidget *BasketViewItem)
    {
        BasketViewItem->setWindowTitle(QCoreApplication::translate("BasketViewItem", "Form", nullptr));
        item_picture->setText(QString());
        item_name->setText(QString());
        number->setText(QCoreApplication::translate("BasketViewItem", "\330\252\330\271\330\257\330\247\330\257:", nullptr));
        remove->setText(QCoreApplication::translate("BasketViewItem", "\330\255\330\260\331\201", nullptr));
        color->setText(QString());
        total_price->setText(QString());
        seller_code->setText(QString());
        inventory->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BasketViewItem: public Ui_BasketViewItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASKETVIEWITEM_H
