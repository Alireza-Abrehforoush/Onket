#include "goodpropertywidget.h"
#include "ui_goodpropertywidget.h"

GoodPropertyWidget::GoodPropertyWidget(const QString& good_id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoodPropertyWidget)
{
    ui->setupUi(this);
    this->good_id=good_id;
    if(Good::existGoodId(good_id)==false)
    {
        return;
    }
    this->info_valid=true;
    Good& g=Good::getGood(good_id);
    ui->table_property->setColumnCount(2);

    ui->table_property->setHorizontalHeaderItem(1,new QTableWidgetItem(""));
    ui->table_property->setHorizontalHeaderItem(0,new QTableWidgetItem(""));

    int cnt=0;
    for(g.setPropertySeekBegin();g.propertySeekAtEnd()==false;cnt++)
    {
       QString property_name=g.readPropertyName();
       ui->table_property->setRowCount(cnt+1);

       QTableWidgetItem* itm_name=new QTableWidgetItem(property_name);
       itm_name->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

       QTableWidgetItem* itm_value=new QTableWidgetItem(g.getPropertyValue(property_name));
       itm_value->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

       ui->table_property->setItem(cnt,0,itm_name);
      ui->table_property->setItem(cnt,1,itm_value);


   this->setFixedSize(400,400);



    }
}

GoodPropertyWidget::~GoodPropertyWidget()
{
    delete ui;
}
