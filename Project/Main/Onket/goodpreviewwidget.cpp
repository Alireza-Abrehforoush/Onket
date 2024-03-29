#include "goodpreviewwidget.h"
#include "ui_goodpreviewwidget.h"
#include <QMessageBox>



QVector<QString> GoodPreviewWidget::style_sheet={"font: 12pt \"Myanmar Text\";\ncolor: rgb(255, 255, 255);\nbackground-color: rgb(85, 85, 255);","font: 12pt \"Myanmar Text\";\ncolor: rgb(0, 0, 0);\nbackground-color: rgb(255, 255, 0);\n\n","font: 12pt \"Myanmar Text\";\nbackground-color: rgb(0, 255, 0);\ncolor: rgb(255, 255, 255);\n\n"};
QString GoodPreviewWidget::style_error="font: 12pt \"Myanmar Text\";\nbackground-color: rgb(255, 0, 0);\ncolor: rgb(255, 255, 255);\n\n";
int GoodPreviewWidget::style_index=0;
QMap<QString,GoodPreviewWidget*> GoodPreviewWidget::compare;

void GoodPreviewWidget::increaseStyleIndex()
{
    style_index++;
    if(style_index==3)
    {
        style_index=0;
    }
}

QString GoodPreviewWidget::number(unsigned int input)
{
    QString number=QString::number(input);
    QString res;
    for( int  cnt=0;cnt <number.size();cnt++)
    {
        if((number.size()-cnt)%3==0 && cnt!=0 )
        {
            res.append(",");
        }
        res.append(number[cnt]);
    }
    return res;

}

void GoodPreviewWidget::showAll()
{
    ui->lab_img->setHidden(false);
    ui->lab_discount->setHidden(false);
    ui->lab_price->setHidden(false);
    ui->lab_final_price->setHidden(false);
}

void GoodPreviewWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit on_good_preview_clicked(this->good_id);

    QWidget::mouseDoubleClickEvent(event);
}

QVector<QString> GoodPreviewWidget::getCompareList()
{
    QVector<QString>res;
    for(auto it=compare.cbegin();it!=compare.cend();it++)
    {
        res.push_back(it.key());
    }
    return res;
}

void GoodPreviewWidget::clearCompareList()
{
    QVector<QString> key;
    for(auto it=compare.cbegin();it !=compare.cend();it++)
    {
        key.push_back(it.key());
    }
    for(auto it : key)
    {
        compare.find(it).value()->changeCheckedState(false);
    }
}

QString GoodPreviewWidget::getGoodId()
{
    return this->good_id;
}

bool GoodPreviewWidget::getIdValidMode()
{
    return this->id_valid;
}

bool GoodPreviewWidget::getLoadPictureMode()
{
    return load_picture;
}

void GoodPreviewWidget::changeCheckedState(bool mode)
{
    if(mode==true)
    {
        ui->checkBox_compare->setCheckState(Qt::Checked);
    }
    else
    {
        ui->checkBox_compare->setCheckState(Qt::Unchecked);
    }
}

void GoodPreviewWidget::update()
{

      if(Good::existGoodId(good_id)==true)
      {
          this->showAll();

          this->id_valid=true;
          Good& g=Good::getGood(good_id);
          ui->lab_name->setText(g.getName());
          ui->lab_name->setAlignment(Qt::AlignCenter);
          QString discount=QString::number(g.getDiscountpercent()*100);
          QString final_price=this->number(g.getFinalPrice());
          final_price.append("تومان ");
          discount.append("%");
          ui->lab_discount->setText(discount);
          ui->lab_price->setText(this->number(g.getPrice()));
          ui->lab_final_price->setText(final_price);

          ui->lab_discount->setAlignment(Qt::AlignCenter);
          ui->lab_price->setAlignment(Qt::AlignCenter);
          ui->lab_final_price->setAlignment(Qt::AlignCenter);

          if(g.getDiscountpercent()==0)
          {

             ui->lab_price->setHidden(true);
             ui->lab_discount->setHidden(true);

          }
          QString path="Database/GoodPicture/";
          path.append(g.getId());path.append(".png");
          QImage img;
          bool mode_load=img.load(path);

          if(mode_load==false)
          {
              this->load_picture=false;
           ui->lab_img->setAlignment(Qt::AlignCenter);
           ui->lab_img->setStyleSheet(style_sheet[style_index]);
           increaseStyleIndex();
           ui->lab_img->setText(g.getName());
          }
          else
          {
              this->load_picture=true;
              ui->lab_img->setScaledContents(true);


              ui->lab_img->setPixmap(QPixmap::fromImage(img));
          }
    }
}


GoodPreviewWidget::GoodPreviewWidget(const QString &good_id,bool hide,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoodPreviewWidget)
{
    this->setFixedSize(340,340);
    ui->setupUi(this);
    this->good_id=good_id;
    if(Good::existGoodId(good_id)==true)
    {
        this->update();
        if(hide==true)
        {
            ui->checkBox_compare->hide();
        }
    }
      else
      {
          this->id_valid=false;
          this->load_picture=false;
          ui->lab_price->setHidden(true);
          ui->lab_discount->setHidden(true);
          ui->lab_final_price->setHidden(true);
          ui->lab_img->setAlignment(Qt::AlignCenter);
          ui->lab_img->setText("کالای مورد نظر یافت نشد");

      }
}

GoodPreviewWidget::~GoodPreviewWidget()

{
    delete ui;
}

void GoodPreviewWidget::on_checkBox_compare_stateChanged()
{
    if(this->ui->checkBox_compare->checkState() == Qt::Unchecked)
    {
        compare.remove(this->good_id);
        if(compare.size()==0)
        {
            emit this->hideCompareButton();
        }
    }
    else
    {
         if(compare.size() < 5&& compare.contains(this->good_id)==false)
        {
            compare.insert(this->good_id,this);
        }
        else
        {


            if(compare.contains(this->good_id)==true)
            {
                GoodPreviewWidget* befor=compare.find(this->good_id).value();
                ui->checkBox_compare->setCheckState(Qt::Unchecked);
                QMessageBox::information(this,"پیام","این کالا قبلا به لیست مقایسه اضافه شده است");
                compare.insert(this->good_id,befor);


            }
            else
            {

                QMessageBox::information(this, "پیام", "حداکثر پنج کالا را می توان مقایسه کرد");
                compare.insert(this->good_id,this);
                ui->checkBox_compare->setCheckState(Qt::Unchecked);
            }





        }
        emit this->showCompareButton();
    }
}
