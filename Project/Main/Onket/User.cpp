#include "User.h"
#include "Admin.h"
#include "Customer.h"
#include "Guest.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

User::User(QString username, QString password)
	:username(username)
	,password(decryptPassword(password))
{

}

void User::addAddress(QString address)
{
    return;
}

void User::removeAddressAt(int at)
{
    return;
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
	return temp1;
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
	return temp1;
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
    User* return_user = nullptr;
    if(userExist(username))
    {
        QFile read_user("Database/User/" + username + ".csv");
        read_user.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&read_user);
        QString content = in.readAll();
        QStringList list_1 = content.split("\n");
        QStringList list_2 = list_1.at(0).split(",");
        if(list_2.at(2) == 0)
        {
            return_user=new Customer(list_2.at(0), list_2.at(1), QDateTime::fromString(list_2.at(5)), list_2.at(6));
            return_user->setFirstname(list_2.at(3));
            return_user->setLastname(list_2.at(4));
            QStringList list_3 = list_2.at(7).split("|");
            for(int i = 0; i<=list_3.size(); i++)
            {
                return_user->addAddress(list_3.at(i));
            }
            ////////////////////////////////////// input orders
        }
        else
        {
            return_user=new Admin(list_2.at(0), list_2.at(1));
            return_user->setFirstname(list_2.at(3));
            return_user->setLastname(list_2.at(4));
        }
    }
    else return return_user;
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
            out << new_user->getUsername() << "," << new_user->getPassword() << "," << new_user->getMode() << "," << new_user->getFirstname() << "," << new_user->getLastname() << "," ;
            if(new_user->getMode()==0)
            {
                out << new_user->getBirthday().toString() << "," << new_user->getPhoneNumber() << ",";
                for(int i = 0; i<new_user->getAddresses().size(); i++)
                {
                    if(i==new_user->getAddresses().size()-1)
                    {
                        out << new_user->getAddresses().at(i) << ",";
                    }
                    else
                    {
                        out << new_user->getAddresses().at(i) << "|";
                    }
                }
                out << "\n";
                /////////////////////////////////////////// orders must be written

                QDateTime now=QDateTime::currentDateTime();
                out << "Account created in " << now.toString() << "|";
            }
            else
            {
                out << new_user->getBirthday().toString() << "," << new_user->getPhoneNumber() << ",";
//                for(int i = 0; i<new_user->getAddresses().size(); i++)
//                {
//                    if(i==new_user->getAddresses().size()-1)
//                    {
//                        out << new_user->getAddresses().at(i) << ",";
//                    }
//                    else
//                    {
//                        out << new_user->getAddresses().at(i) << "|";
//                    }
//                }
                out << ",\n\n";

                QDateTime now=QDateTime::currentDateTime();
                out << "Account created in " << now.toString() << "|";
            }
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
