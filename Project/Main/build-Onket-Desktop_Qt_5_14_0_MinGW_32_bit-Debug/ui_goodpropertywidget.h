/********************************************************************************
** Form generated from reading UI file 'goodpropertywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODPROPERTYWIDGET_H
#define UI_GOODPROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GoodPropertyWidget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *table_property;

    void setupUi(QWidget *GoodPropertyWidget)
    {
        if (GoodPropertyWidget->objectName().isEmpty())
            GoodPropertyWidget->setObjectName(QString::fromUtf8("GoodPropertyWidget"));
        GoodPropertyWidget->resize(400, 300);
        widget = new QWidget(GoodPropertyWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 10, 291, 261));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label);

        table_property = new QTableWidget(widget);
        table_property->setObjectName(QString::fromUtf8("table_property"));
        table_property->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 0, 0);"));

        verticalLayout->addWidget(table_property);


        retranslateUi(GoodPropertyWidget);

        QMetaObject::connectSlotsByName(GoodPropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *GoodPropertyWidget)
    {
        GoodPropertyWidget->setWindowTitle(QCoreApplication::translate("GoodPropertyWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("GoodPropertyWidget", "\331\205\330\264\330\256\330\265\330\247\330\252 \332\251\330\247\331\204\330\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GoodPropertyWidget: public Ui_GoodPropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODPROPERTYWIDGET_H
