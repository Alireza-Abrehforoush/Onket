#ifndef DISCUSSIONITEM_H
#define DISCUSSIONITEM_H
#include <QString>
#include <QDate>
#include <QXmlStreamWriter>


#include "filefunctions.h"
class DiscussionItem
{
protected:
    QString id;
    QString sender_id;
    QString content;
    QDate date_create;

protected:
    bool isValidInXml(const QString & input);
public:


    bool setContent(const QString& content);

    QString getId()const;
    QString getSenderId()const;
    QString getContent()const;
    QDate getDateCreate()const;
    DiscussionItem(const QDate& date_create, const QString& id,const QString& sender_id,const QString& content );
    ~DiscussionItem();
    virtual void addToFile(QXmlStreamWriter & xml_writer)=0;

};

#endif // DISCUSSIONITEM_H
