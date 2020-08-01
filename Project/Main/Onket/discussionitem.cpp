#include "discussionitem.h"


bool DiscussionItem::isValidInXml(const QString &input)
{

    for(auto it=input.cbegin();it != input.cend();it++)
    {
        if(*it=='<'||*it== '>')
        {
            return false;
        }
    }


        return true;
}

QString DiscussionItem::toQString(const QDate& input)
{
    QString resault=QString::number(input.year());
    resault.append(",");
    resault.append(QString::number(input.month()));
    resault.append(",");
    resault.append(QString::number(input.day()));
    return  resault;
}

QDate DiscussionItem::toQDate(const QString &input)
{

   QStringList date_list=input.split(",");
//    int year=date_list[0].toInt();
//      int month=date_list[1].toInt();
//        int day=date_list[2].toInt();

   QDate resualt(date_list[0].toInt(),date_list[1].toInt(),date_list[2].toInt());
   return resualt;
}


bool DiscussionItem::setContent(const QString &content)
{
    if(this->isValidInXml(content) == false)
    {
        return false;
    }
    this->content=content;
    return true;
}

QString DiscussionItem::getId()
{
    return this->id;

}

QString DiscussionItem::getSenderId()
{
    return  this->sender_id;
}

QString DiscussionItem::getContent()
{
    return  this->content;
}

QDate DiscussionItem::getDateCreate()
{
    return this->date_create;
}



DiscussionItem::DiscussionItem(const QDate& date_create, const QString &id, const QString &sender_id, const QString &content)
    :date_create(date_create)
{
    this->id=id;
    this->sender_id=sender_id;
    this->setContent(content);
}

DiscussionItem::~DiscussionItem()
{

}





