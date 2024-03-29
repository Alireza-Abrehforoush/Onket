#include "User.h"
#include "Admin.h"
#include "Customer.h"
#include "Guest.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

User::User(QString username, QString password)
    :username(username),
    password(decryptPassword(password))
{

}

QDate User::getBirthday() const
{
    return QDate::currentDate();
}

QString User::getPhoneNumber() const
{
    return "";
}

void User::setBirthday(QDate birthday)
{
    return;
}

void User::setPhoneNumber(QString phone_number)
{
    return;
}

QVector<QString>& User::getAddresses()
{
    QVector<QString> temp;
    return temp;
}

void User::addAddress(QString address)
{
    return;
}

void User::removeAddressAt(int at)
{
    return;
}

QVector<QString>& User::getOrderIds()
{

}

QVector<Item> &User::getBasket()
{
    QVector<Item> temp;
    return temp;
}

void User::addToBasket(Item itm)
{
    return;
}

void User::removeFromBasket(Item itm)
{
    return;
}

int User::buy(QVector<Item> my_basket)
{
    return 0;
}

QVector<QDateTime>& User::getLastActivities()
{
    return this->last_activities;
}

void User::setFirstname(QString firstname)
{
	this->firstname = firstname;
	return;
}

void User::setLastname(QString lastname)
{
	this->lastname = lastname;
	return;
}

void User::setUsername(QString username)
{
	this->username = username;
	return;
}

void User::setPassword(QString password)
{
	this->password = this->encryptPassword(password);
	return;
}

QString User::getFirstname() const
{
	return this->firstname;
}

QString User::getLastname() const
{
	return this->lastname;
}

QString User::getUsername() const
{
	return this->username;
}

QString User::getPassword() const
{
	return this->password;
}

QString User::encryptPassword(QString password)
{
	QString temp1 = "";
	std::string temp2 = password.toStdString();
	char temp3;
	int length = password.length();
    for (int i = 0; i < length; i++)
	{
		temp3 = temp2.at(i);
		temp3 += (i * i + 7) % 128;
		temp1.append(temp3);
	}
    return password;
//    return temp1;
}

QString User::decryptPassword(QString password)
{
	QString temp1 = "";
	std::string temp2 = password.toStdString();
	char temp3;
	int length = password.length();
    for (int i = 0; i < length; i++)
	{
		temp3 = temp2.at(i);
		temp3 -= (i * i + 7) % 128;
		temp1.append(temp3);
	}
    return password;
//    return temp1;
}

void User::addActivity(QDateTime new_login)
{
	this->last_activities.push_back(new_login);
    return;
}

int User::userExist(QString username)
{
    QFile data("Database/User/" + username + ".csv");
    return data.exists();
}

User *User::getUser(QString username)
{
    User* pointer_to_user = nullptr;
    if(userExist(username))
    {
        QFile read_user("Database/User/" + username + ".csv");
        read_user.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&read_user);
        in.setCodec("UTF-8");
        QString content = in.readAll();
        QStringList list_1 = content.split("\n");
        QStringList list_2 = list_1.at(0).split(",");
        if(list_2.at(2).toInt() == 0)
        {
            pointer_to_user = new Customer(list_2.at(0), list_2.at(1));
            pointer_to_user->setBirthday(QDate::fromString(list_2.at(5)));
            pointer_to_user->setPhoneNumber(list_2.at(6));
            pointer_to_user->setFirstname(list_2.at(3));
            pointer_to_user->setLastname(list_2.at(4));
            QStringList list_3 = list_2.at(7).split("|");
            for(int i = 0; i<list_3.size(); i++)
            {
                pointer_to_user->addAddress(list_3.at(i));
            }
            QStringList list_4 = list_1.at(1).split("-");
            for(int i = 0; i < list_4.size(); i++)
            {
                pointer_to_user->getOrderIds().push_back(list_4.at(i));
            }
            QStringList list_5 = list_1.at(2).split("|");
            for(int i = 1; i < list_5.size() - 1; i++)
            {
                QStringList list_6 = list_5.at(i).split("_");
                if(list_6.size() == 2)
                {
                    pointer_to_user->addActivity(QDateTime::fromString(list_6.at(0)));
                    pointer_to_user->addActivity(QDateTime::fromString(list_6.at(1)));
                }
            }
        }
        else
        {
            pointer_to_user = new Admin(list_2.at(0), list_2.at(1));
            pointer_to_user->setFirstname(list_2.at(3));
            pointer_to_user->setLastname(list_2.at(4));
        }
    }
    return pointer_to_user;
}

int User::addUser(User* new_user)
{
    if (!(userExist(new_user->getUsername())))
    {
        QDir data;
        data.mkpath("Database/User");
        QFile user_personal("Database/User/" + new_user->getUsername() + ".csv");
        if(user_personal.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&user_personal);
            out.setCodec("UTF-8");
            out << new_user->getUsername() << "," << new_user->getPassword() << "," << new_user->getMode() << "," << new_user->getFirstname().toUtf8() << "," << new_user->getLastname().toUtf8() << "," ;
            if(new_user->getMode()==0)
            {
                out << new_user->getBirthday().toString() << "," << new_user->getPhoneNumber() << ",";
                for(int i = 0; i<new_user->getAddresses().size(); i++)
                {
                    if(i!=new_user->getAddresses().size()-1)
                    {
                        out << new_user->getAddresses().at(i) << "|";
                    }
                    else
                    {
                        out << new_user->getAddresses().at(i);
                    }
                }
                out << "\n";
                for(int i = 0; i < new_user->getOrderIds().size(); i++)
                {
                    out << new_user->getOrderIds().at(i);
                    if(i != new_user->getOrderIds().size() - 1) out << "|";
                }
                out << "\n";
                out << "Account created in " << QDateTime::currentDateTime().toString() << "|";
                for(int i = 0; i < new_user->getLastActivities().size(); i++)
                {
                    out << new_user->getLastActivities().at(i).toString();
                    if(i%2 == 0/* && i != new_user->getLastActivities().size() - 1*/) out << "_";
                    if(i%2 == 1) out << "|";
                }
            }
            user_personal.close();
            return 1;
        }
        else
        {
            return 0;
        }
        //open file
        //write info
        //close file
    }
	else
	{
        return 0;
	}
}

void User::removeUser(QString username)
{

}
