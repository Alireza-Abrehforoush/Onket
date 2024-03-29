#include "Customer.h"
#include "item.h"
#include "mainwindow.h"

#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

int Customer::getMode() const
{
	return mode;
}

Customer::Customer(QString username, QString password)
    :User(username, password)
{

}

QVector<Item>& Customer::getBasket()
{
    return this->basket;
}

void Customer::addToBasket(Item itm)
{
    for(auto it  = this->basket.begin();it != basket.end();it++)
    {
        if(it->getItemId()==itm.getItemId() && it->getItemColor()==itm.getItemColor())
        {
            it->setItemNumber(itm.getNumber());
            return;
        }
    }
    basket.push_back(itm);
    return;
}

void Customer::removeFromBasket(Item itm)
{
    int temp = this->basket.indexOf(itm);
    if(temp != -1)
    {
        this->basket.remove(this->basket.indexOf(itm));
    }
    return;
}

void Customer::setBirthday(QDate birthday)
{
	this->birthday = birthday;
	return;
}

QDate Customer::getBirthday() const
{
	return this->birthday;
}

void Customer::setPhoneNumber(QString phone_number)
{
	this->phone_number = phone_number;
    return;
}

int Customer::findIndexOfBasketItems(QString good_id, QString color)
{
    for(int i = 0; i < this->basket.size(); i++)
    {
        if(this->basket.at(i).getItemId() == good_id && this->basket.at(i).getItemColor() == color)
        {
            return i;
        }
    }
    return -1;
}

QVector<QString>& Customer::getOrderIds()
{
    return this->order_ids;
}

QVector<QString>& Customer::getAddresses()
{
    return this->addresses;
}

QString Customer::getPhoneNumber() const
{
	return this->phone_number;
}

void Customer::addAddress(QString address)
{
    this->addresses.push_back(address);
	return;
}

void Customer::removeAddressAt(int at)
{
	this->addresses.removeAt(at);
	return;
}

int Customer::buy(QVector<Item> my_basket)
{
    Order new_order(this->getUsername() + QString::number(this->getOrderIds().size()+1), QDateTime::currentDateTime(), this->getFirstname() + " " + this->getLastname(), this->getPhoneNumber(), this->getAddresses().at(0), QDateTime::currentDateTime().addDays(5), 10000);
    new_order.setBasket(my_basket);
    Order::addOrder(new_order);
    for(int i = 0; i < my_basket.size(); i++)
    {
        MainWindow::getOnketRepository().removeGood(my_basket.at(i).getItemId(), my_basket.at(i).getItemColor(), my_basket.at(i).getNumber());

    }
    QFile data_read("Database/User/" + this->getUsername() + ".csv");
    if(data_read.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&data_read);
        QString content = in.readAll();
        QStringList list_1 = content.split("\n");
        list_1[1].append(this->getUsername() + QString::number(this->getOrderIds().size()+1));
        list_1[1].append("─");
        data_read.close();
        QFile data_write("Database/User/" + this->getUsername() + ".csv");
        if(data_write.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&data_write);
            out << list_1.at(0) << "\n" << list_1.at(1) << "\n" << list_1.at(2);
            data_write.close();
        }
        else return 0;
        data_read.close();
        this->basket.clear();
        return 1;
    }
    else return 0;
}

void Customer::sell(QString good_id, QString color, QString number)
{
}

Customer::~Customer()
{
    return;
}
