#include "goodgenralinfowidget.h"
#include "ui_goodgenralinfowidget.h"


void GoodGenralInfoWidget::update()
{
    if(this->info_valid==true)
    {
        Good& g=Good::getGood(good_id);
        if(g.getDiscountpercent()==0)
        {
     this->ui->lab_price->setStyleSheet(this->font_regular);

        }
        else
        {
            this->ui->lab_price->setStyleSheet(this->font_skriteout);
        }

        ui->lab_name->setText(g.getName());
        ui->lab_seller->setText(g.getMakerId());
        ui->lab_price->setText(QString::number(g.getPrice()));
        ui->lab_discount_percent->setText(QString::number(g.getDiscountpercent()));
        ui->lab_final_price->setText(QString::number(g.getFinalPrice()));


    }
}

GoodGenralInfoWidget::GoodGenralInfoWidget(const QString& good_id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoodGenralInfoWidget)
{
    ui->setupUi(this);
    this->good_id=good_id;
    if(Good::existGoodId(good_id)==false)
    {
        return;
    }
    else
    {
        this->info_valid=true;

        update();


    }


}


GoodGenralInfoWidget::~GoodGenralInfoWidget()
{
    delete ui;
}