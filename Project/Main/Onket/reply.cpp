#include "reply.h"





QString Reply::getQuestionId()
{
    return  this->question_id;
}

unsigned int Reply::getLikeNumber()const
{
    return this->like;
}

unsigned int Reply::getDisLikeNumber()const
{
    return this->dislike;
}




Reply::Reply(const QDate &date_create, const QString &id, const QString &sender_id,const QString& question_id, const QString &content)
    :DiscussionItem(date_create,id,sender_id,content)
{
    this->question_id=question_id;
}

void Reply::addLike(const QString &sender_id)
{
    auto it= users_like.find(sender_id);
    if(it != users_like.end())
    {
        if(users_like[sender_id]==false)
        {
            this->dislike--;
            this->like++;
        }
        users_like[sender_id]=true;
    }
    else
    {
        users_like.insert(sender_id,true);
        this->like++;
    }
}

void Reply::addDisLike(const QString &sender_id)
{
    auto it= users_like.find(sender_id);
    if(it != users_like.end())
    {
        if(users_like[sender_id] == true)
        {
            this->like--;
            this->dislike++;
        }
        users_like[sender_id]=false;
    }
    else
    {
        users_like.insert(sender_id,false);
        this->dislike++;
    }
}

bool Reply::removeLiker(const QString &liker_id)
{
    if(this->exist(liker_id)==false)
    {
        return false;
    }
    else
      {
        auto it=this->users_like.find(liker_id);
        if(it.value()==true)
        {
            this->like--;
        }
        else
        {
            this->dislike--;
        }
        this->users_like.remove(liker_id);
        return true;
    }
}

bool Reply::exist(const QString &sender_id)const
{

   auto it=users_like.find(sender_id);
    if(it != users_like.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Reply::getLikeMode(const QString &sender_id)const
{
    if(this->exist(sender_id)==true)
    {
        return users_like[sender_id];
    }
    else
    {
       auto it =this->users_like.find(sender_id);

       return it.value();
    }
}





void Reply::addToFile(QXmlStreamWriter &xml_writer)
{
    xml_writer.writeStartElement("reply");
//        xml_writer.writeAttribute("like",QString::number(this->like));
//        xml_writer.writeAttribute("dislike",QString::number(this->dislike));
        xml_writer.writeTextElement("id",this->id);
         xml_writer.writeTextElement("question_id",this->question_id);
        xml_writer.writeTextElement("sender_id",this->sender_id);
        xml_writer.writeTextElement("date",file_QDate::toQString(this->date_create));
        xml_writer.writeTextElement("content",this->content);
        xml_writer.writeTextElement("users_like",xml_QMap::toQString(this->users_like));
    xml_writer.writeEndElement();
}


