#ifndef CUSTOMER_BNUB
#define CUSTOMER_BNUB
#include "User.h"
#include "Order.h"
#include "item.h"
#include <QVector>
class Customer :
	public User
{
protected:
private:
	const int mode = 0;
    QDate birthday;
	QString phone_number;
    QVector<Item> basket;
    QVector<QString> order_ids;
	QVector<QString> addresses;
public:
    int getMode() const;
    Customer(QString username, QString password);
    QVector<Item>& getBasket();
    void addToBasket(Item itm);
    void removeFromBasket(Item itm);
    void setBirthday(QDate birthday);
    QDate getBirthday() const;
	void setPhoneNumber(QString phone_number);
    int findIndexOfBasketItems(QString good_id, QString color);
    QVector<QString>& getOrderIds();
    QString getPhoneNumber() const;
    QVector<QString>& getAddresses();
	void addAddress(QString address);
	void removeAddressAt(int at);
    int buy(QVector<Item> my_basket);
    void sell(QString good_id, QString color, QString number);
    ~Customer();
};

#endif
