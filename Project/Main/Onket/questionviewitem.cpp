#include "questionviewitem.h"
#include "ui_questionviewitem.h"

void QuestionViewItem::ReplyFinished()
{
    this->r_input->close();
    delete r_input;
    r_input=nullptr;
    emit this->replyAdded();
}

void QuestionViewItem::update()
{
    if(info_valid==false)
    {
        return;
    }
    else
    {
        Good& g=Good::getGood(good_id);
        const Question& q=g.getQuestion(question_id);

        this->ui->txt_content->setText(q.getContent());
        QString number=QString::number(q.getReplyNumber());
        number.append(" نفر به این سوال پاسخ دادند");

        this->ui->txt_content->setReadOnly(true);
        this->ui->txt_content->setText(q.getContent());
        this->ui->lab_reply_number->setText(number);
        this->ui->lab_date->setText(q.getDateCreate().toString());


    }
}

QuestionViewItem::QuestionViewItem(const QString & user_id,const QString & good_id,const QString& question_id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionViewItem)

{
    this->ui->setupUi(this);
    this->user_id=user_id;
    this->good_id=good_id;
    this->question_id=question_id;
    if(Good::existGoodId(good_id)==false)
    {
        this->info_valid=false;
        return;
    }
    Good& g=Good::getGood(good_id);
    if(g.existQuestionId(question_id)==false)
    {
        this->info_valid=false;
        return;
    }

    this->info_valid=true;
    this->ui->bnt_icon->setIcon(QIcon("Database/Icons/Question.png"));

    this->update();

    this->setFixedSize(1200,300);


}

QuestionViewItem::~QuestionViewItem()
{
    delete ui;
}






void QuestionViewItem::on_bnt_show_replys_clicked()
{
    if(info_valid==false)
    {
        return;
    }
    else
    {
        if(ui->bnt_show_replys->text()=="نمایش پاسخ ها")
        {
          emit this->showReplyRequsted(good_id,question_id);
           this->ui->bnt_show_replys->setText("مخفی کردن پاسخ ها");
           return;
        }
        else
        {
            emit this->hideReplyRequsted(good_id,question_id);
            ui->bnt_show_replys->setText("نمایش پاسخ ها");
            return;
        }
    }
}

void QuestionViewItem::on_bnt_add_reply_clicked()
{
    if(info_valid==false)
    {
        return;
    }
    Good& g=Good::getGood(good_id);

    if(g.existReply(user_id,question_id)==true)
    {
        QMessageBox::information(this,"در خواست نا معتبر","شما قبلا پاسخ این سوال را داده اید",QMessageBox::Ok,0);

        return;
    }

    if(this->r_input !=nullptr)
    {
        return;
    }
    else
    {
        r_input=new ReplyInputWidget(good_id,question_id,user_id);
        r_input->show();
        connect(r_input,SIGNAL(replyEditingFinished()),this,SLOT(ReplyFinished()));

    }


}
