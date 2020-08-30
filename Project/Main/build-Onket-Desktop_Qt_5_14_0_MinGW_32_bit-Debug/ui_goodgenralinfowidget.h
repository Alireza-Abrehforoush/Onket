/********************************************************************************
** Form generated from reading UI file 'goodgenralinfowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODGENRALINFOWIDGET_H
#define UI_GOODGENRALINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GoodGenralInfoWidget
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *lab_name;
    QLabel *lab_1;
    QLabel *lab_seller;
    QLabel *lab_2;
    QLabel *lab_price;
    QLabel *lab_3;
    QLabel *lab_discount_percent;
    QLabel *lab_4;
    QLabel *lab_final_price;
    QLabel *lab_5;
    QLabel *label;

    void setupUi(QWidget *GoodGenralInfoWidget)
    {
        if (GoodGenralInfoWidget->objectName().isEmpty())
            GoodGenralInfoWidget->setObjectName(QString::fromUtf8("GoodGenralInfoWidget"));
        GoodGenralInfoWidget->resize(400, 300);
        GoodGenralInfoWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 75 11pt \"MS Shell Dlg 2\";"));
        layoutWidget = new QWidget(GoodGenralInfoWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 60, 221, 181));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lab_name = new QLabel(layoutWidget);
        lab_name->setObjectName(QString::fromUtf8("lab_name"));

        gridLayout->addWidget(lab_name, 0, 0, 1, 1);

        lab_1 = new QLabel(layoutWidget);
        lab_1->setObjectName(QString::fromUtf8("lab_1"));

        gridLayout->addWidget(lab_1, 0, 1, 1, 1);

        lab_seller = new QLabel(layoutWidget);
        lab_seller->setObjectName(QString::fromUtf8("lab_seller"));

        gridLayout->addWidget(lab_seller, 1, 0, 1, 1);

        lab_2 = new QLabel(layoutWidget);
        lab_2->setObjectName(QString::fromUtf8("lab_2"));

        gridLayout->addWidget(lab_2, 1, 1, 1, 1);

        lab_price = new QLabel(layoutWidget);
        lab_price->setObjectName(QString::fromUtf8("lab_price"));

        gridLayout->addWidget(lab_price, 2, 0, 1, 1);

        lab_3 = new QLabel(layoutWidget);
        lab_3->setObjectName(QString::fromUtf8("lab_3"));

        gridLayout->addWidget(lab_3, 2, 1, 1, 1);

        lab_discount_percent = new QLabel(layoutWidget);
        lab_discount_percent->setObjectName(QString::fromUtf8("lab_discount_percent"));

        gridLayout->addWidget(lab_discount_percent, 3, 0, 1, 1);

        lab_4 = new QLabel(layoutWidget);
        lab_4->setObjectName(QString::fromUtf8("lab_4"));

        gridLayout->addWidget(lab_4, 3, 1, 1, 1);

        lab_final_price = new QLabel(layoutWidget);
        lab_final_price->setObjectName(QString::fromUtf8("lab_final_price"));

        gridLayout->addWidget(lab_final_price, 4, 0, 1, 1);

        lab_5 = new QLabel(layoutWidget);
        lab_5->setObjectName(QString::fromUtf8("lab_5"));
        lab_5->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lab_5, 4, 1, 1, 1);

        label = new QLabel(GoodGenralInfoWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 55, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        retranslateUi(GoodGenralInfoWidget);

        QMetaObject::connectSlotsByName(GoodGenralInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *GoodGenralInfoWidget)
    {
        GoodGenralInfoWidget->setWindowTitle(QCoreApplication::translate("GoodGenralInfoWidget", "Form", nullptr));
        lab_name->setText(QCoreApplication::translate("GoodGenralInfoWidget", "TextLabel", nullptr));
        lab_1->setText(QCoreApplication::translate("GoodGenralInfoWidget", "\331\206\330\247\331\205 \332\251\330\247\331\204\330\247:", nullptr));
        lab_seller->setText(QCoreApplication::translate("GoodGenralInfoWidget", "TextLabel", nullptr));
        lab_2->setText(QCoreApplication::translate("GoodGenralInfoWidget", "\331\206\330\247\331\205 \331\201\330\261\331\210\330\264\331\206\330\257\331\207:", nullptr));
        lab_price->setText(QCoreApplication::translate("GoodGenralInfoWidget", "TextLabel", nullptr));
        lab_3->setText(QCoreApplication::translate("GoodGenralInfoWidget", "\331\202\333\214\331\205\330\252 :", nullptr));
        lab_discount_percent->setText(QCoreApplication::translate("GoodGenralInfoWidget", "TextLabel", nullptr));
        lab_4->setText(QCoreApplication::translate("GoodGenralInfoWidget", "\330\257\330\261\330\265\330\257 \330\252\330\256\331\201\333\214\331\201", nullptr));
        lab_final_price->setText(QCoreApplication::translate("GoodGenralInfoWidget", "TextLabel", nullptr));
        lab_5->setText(QCoreApplication::translate("GoodGenralInfoWidget", "\331\202\333\214\331\205\330\252 \331\206\331\207\330\247\333\214\333\214:", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GoodGenralInfoWidget: public Ui_GoodGenralInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODGENRALINFOWIDGET_H
