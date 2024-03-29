#include "dashboard.h"
#include "ui_dashboard.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

Dashboard::Dashboard(User* current_user, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
    , property_center_widget(new QWidget(this))
    , comment_center_widget(new QWidget(this))
    , lay_good_property(new QGridLayout(this))
    , good_property_center_widget(new QWidget(this))
    , lay_property(new QVBoxLayout(this))
    , lay_comment(new QVBoxLayout(this))
{
    ui->setupUi(this);
    if(MainWindow::getCurrentUser()->getMode() == 0)
    {
        ui->admin->hide();
        ui->customer->show();




        ui->my_orders->hide();
        ui->lists->hide();
        ui->comments->hide();
        ui->messages->hide();
        ui->last_activities->hide();
        ui->customer_account_info->hide();
        ui->customer_account_edit->hide();

        ui->customer_firstname_line_edit->setText(MainWindow::getCurrentUser()->getFirstname());
        ui->customer_lastname_line_edit->setText(MainWindow::getCurrentUser()->getLastname());
        ui->customer_username_line_edit->setText(MainWindow::getCurrentUser()->getUsername());
        ui->customer_password_line_edit->setText(MainWindow::getCurrentUser()->getPassword());
        ui->customer_birthday_edit->setDate(MainWindow::getCurrentUser()->getBirthday());
        ui->customer_email_line_edit->setText(MainWindow::getCurrentUser()->getUsername());
        ui->customer_phone_number_line_edit->setText(MainWindow::getCurrentUser()->getPhoneNumber());

        ui->customer_password_line_edit->setEchoMode(QLineEdit::Password);
        ui->customer_address_number->setRange(1, MainWindow::getCurrentUser()->getAddresses().size());
        ui->customer_show_address->setText(MainWindow::getCurrentUser()->getAddresses().at(0));
        ui->customer_address_number_edit->setRange(1, MainWindow::getCurrentUser()->getAddresses().size());
        ui->customer_addresses_to_be_removed->setText(MainWindow::getCurrentUser()->getAddresses().at(0));

        for(int i = 0; i < MainWindow::getCurrentUser()->getLastActivities().size(); i++)
        {
            ui->customer_last_activities->insertPlainText(MainWindow::getCurrentUser()->getLastActivities().at(i).toString());
            if(i%2 == 0 && i != MainWindow::getCurrentUser()->getLastActivities().size() - 1) ui->customer_last_activities->insertPlainText("_");
            if(i%2 == 1 && i != MainWindow::getCurrentUser()->getLastActivities().size() - 1) ui->customer_last_activities->insertPlainText("\n");
        }

    }
    else if(MainWindow::getCurrentUser()->getMode() == 1)
    {
        ui->admin->show();
        ui->customer->hide();

        ui->goods_management->hide();
        ui->user_management->hide();
        ui->site_settings->hide();
        ui->finance->hide();
        ui->employeement->hide();
        ui->messages_2->hide();
        ui->admin_account_info->hide();
        ui->foreign_connections->hide();
        ui->admin_account_edit->hide();

        ui->admin_password_line_edit->setEchoMode(QLineEdit::Password);
        ui->first_and_lastname->setText(MainWindow::getCurrentUser()->getFirstname() + " " + MainWindow::getCurrentUser()->getLastname());
        ui->username->setText(MainWindow::getCurrentUser()->getUsername());
        ui->admin_firstname_line_edit->setText(MainWindow::getCurrentUser()->getFirstname());
        ui->admin_lastname_line_edit->setText(MainWindow::getCurrentUser()->getLastname());
        ui->admin_username_line_edit->setText(MainWindow::getCurrentUser()->getUsername());
        ui->admin_password_line_edit->setText(MainWindow::getCurrentUser()->getPassword());
////////////////////////////////////////////
        property_center_widget->setLayout(lay_property);
        comment_center_widget->setLayout(lay_comment);
        good_property_center_widget->setLayout(lay_good_property);
        ui->scrollArea_properties->setWidget(property_center_widget);
        ui->scrollArea_comment_item->setWidget(comment_center_widget);
        ui->scrollArea_set_properties_of_good_to_make->setWidget(good_property_center_widget);
        ui->scrollArea_properties->setWidgetResizable(true);
        ui->scrollArea_comment_item->setWidgetResizable(true);
        ui->scrollArea_set_properties_of_good_to_make->setWidgetResizable(true);
        ui->scrollArea_properties->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ui->scrollArea_properties->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ui->scrollArea_comment_item->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ui->scrollArea_comment_item->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ui->scrollArea_set_properties_of_good_to_make->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ui->scrollArea_set_properties_of_good_to_make->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    }

    QDir dir("Database/User");
    QFileInfoList list = dir.entryInfoList(QDir::AllEntries);
    for(int i = 2; i < list.size(); i++)
    {
        int pos = list.at(i).fileName().lastIndexOf(QChar('.'));
        QString kem = list.at(i).fileName().left(pos);
        if(User::getUser(kem)->getMode() == 0)
        {
            ui->username_of_customer->addItem(kem);
        }
    }
}

void Dashboard::hideAdminWidgets()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->hide();
    ui->messages_2->hide();
    ui->admin_account_info->hide();
    ui->foreign_connections->hide();
    ui->admin_account_edit->hide();
}

void Dashboard::hideCustomerWidgets()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->customer_account_info->hide();
    ui->customer_account_edit->hide();
}

void Dashboard::clearAddGoodNumberFields()
{
    ui->good_id_for_adding_to_storage->clear();
    ui->good_color_for_adding_to_storage->setCurrentIndex(0);
    ui->good_number_for_adding_to_storage->setValue(1);
}

void Dashboard::clearInventoryFields()
{
    ui->good_id_for_get_inventory->clear();
    ui->good_color_for_get_inventory->setCurrentIndex(0);
}

void Dashboard::clearAddGoodFields()
{
    ui->name_of_good_to_make->clear();
    ui->good_type_line_edit->clear();
    ui->seller_code->clear();
    ui->price_to_make->setValue(0);
    ui->discount_SpinBox->setValue(0);
    ui->picture_of_good_to_make->clear();
    delete this->lay_good_property;
    this->lay_good_property = new QGridLayout(this);
    delete this->good_property_center_widget;
    this->good_property_center_widget=new QWidget(this);
    this->good_property_center_widget->setLayout(lay_good_property);
    ui->scrollArea_set_properties_of_good_to_make->setWidget(good_property_center_widget);

}

void Dashboard::clearAddTypeFields()
{
    ui->name_of_type_to_make->clear();
    ui->name_of_type->clear();
    delete this->lay_comment;
    delete this->lay_property;
    this->lay_comment=nullptr;
    this->lay_property=nullptr;
    this->lay_comment=new QVBoxLayout(this);
    this->lay_property=new QVBoxLayout(this);
    delete this->comment_center_widget;
    this->comment_center_widget=new QWidget(this);
    delete this->property_center_widget;
    this->property_center_widget=new QWidget(this);
    this->comment_center_widget->setLayout(lay_comment);
    this->property_center_widget->setLayout(lay_property);
    ui->scrollArea_properties->setWidget(property_center_widget);
    ui->scrollArea_comment_item->setWidget(comment_center_widget);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_pushButton_9_clicked()
{
    this->hideCustomerWidgets();
    ui->my_orders->show();
}

void Dashboard::on_pushButton_10_clicked()
{
    this->hideCustomerWidgets();
    ui->lists->show();
}

void Dashboard::on_pushButton_11_clicked()
{
    this->hideCustomerWidgets();
    ui->comments->show();
}

void Dashboard::on_pushButton_13_clicked()
{
    this->hideCustomerWidgets();
    ui->messages->show();

    QFile messages("Database/Dashboard/customers_messages.txt");
    QTextStream read_messages(&messages);
    read_messages.setCodec("UTF-8");
    QString content;
    if(messages.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        content = read_messages.readAll();
    }
    ui->message_sent_by_admin->setText(content);
}

void Dashboard::on_pushButton_14_clicked()
{
    this->hideCustomerWidgets();
    ui->last_activities->show();
}

void Dashboard::on_pushButton_15_clicked()
{
    this->hideCustomerWidgets();
    ui->customer_account_info->show();

    ui->customer_first_and_last_name->setText(MainWindow::getCurrentUser()->getFirstname() + " " + MainWindow::getCurrentUser()->getLastname());
    ui->customer_username->setText(MainWindow::getCurrentUser()->getUsername());
    //ui->customer_password->setText(MainWindow::getCurrentUser()->getPassword());
    ui->customer_phone_number->setText(MainWindow::getCurrentUser()->getPhoneNumber());
    ui->customer_birthday->setText(MainWindow::getCurrentUser()->getBirthday().toString());
    ui->customer_email->setText(MainWindow::getCurrentUser()->getUsername());
    ui->customer_show_address->setText(MainWindow::getCurrentUser()->getAddresses().at(ui->customer_address_number->value() - 1));

    ui->customer_address_number_edit->clear();
}

void Dashboard::on_goods_clicked()
{
    this->hideAdminWidgets();
    ui->goods_management->show();
}

void Dashboard::on_users_management_clicked()
{
    this->hideAdminWidgets();
    ui->user_management->show();
}

void Dashboard::on_pushButton_3_clicked()
{
    this->hideAdminWidgets();
    ui->site_settings->show();
}

void Dashboard::on_financial_management_clicked()
{
    this->hideAdminWidgets();
    ui->finance->show();
}

void Dashboard::on_pushButton_5_clicked()
{
    this->hideAdminWidgets();
    ui->employeement->show();
}

void Dashboard::on_send_message_clicked()
{
    this->hideAdminWidgets();
    ui->messages_2->show();
}

void Dashboard::on_account_management_clicked()
{
    this->hideAdminWidgets();
    ui->admin_account_info->show();
}

void Dashboard::on_pushButton_8_clicked()
{
    this->hideAdminWidgets();
    ui->foreign_connections->show();
}

void Dashboard::on_customer_address_edit_of_valueChanged(int arg1)
{
    this->ui->customer_addresses_to_be_removed->setText(MainWindow::getCurrentUser()->getAddresses().at(arg1-1));
}

void Dashboard::on_remove_this_address_button_clicked()
{
    if(MainWindow::getCurrentUser()->getAddresses().size() != 1)
    {
        MainWindow::getCurrentUser()->getAddresses().remove(this->ui->customer_address_number_edit->value() - 1);
        QMessageBox::information(this, "پیام", "آدرس مورد نظر حذف شد");
        this->ui->customer_addresses_to_be_removed->clear();
        this->ui->customer_address_number->setRange(1, MainWindow::getCurrentUser()->getAddresses().size());
        this->ui->customer_address_number_edit->setRange(1, MainWindow::getCurrentUser()->getAddresses().size());
    }
    else
    {
        QMessageBox::information(this, "پیام", "حداقل یک آدرس را وارد کنید");
    }
}

void Dashboard::on_customer_address_number_edit_valueChanged(int arg1)
{
    this->ui->customer_addresses_to_be_removed->setText(MainWindow::getCurrentUser()->getAddresses().at(arg1 - 1));
}

void Dashboard::on_add_this_address_button_clicked()
{
    if(!this->ui->add_address_line_edit->text().isEmpty() && !MainWindow::getCurrentUser()->getAddresses().contains(this->ui->add_address_line_edit->text()))
    {
        MainWindow::getCurrentUser()->addAddress(this->ui->add_address_line_edit->text());
        QMessageBox::information(this, "پیام", "آدرس جدید با موفقیت اضافه شد");
        this->ui->add_address_line_edit->clear();
        this->ui->customer_address_number->setRange(1, MainWindow::getCurrentUser()->getAddresses().size());
        this->ui->customer_address_number_edit->setRange(1, MainWindow::getCurrentUser()->getAddresses().size());
    }
}

void Dashboard::on_customer_apply_changes_button_clicked()
{
    QFile data_remove("Database/User/" + MainWindow::getCurrentUser()->getUsername() + ".csv");
    data_remove.remove();
    MainWindow::getCurrentUser()->setFirstname(this->ui->customer_firstname_line_edit->text());
    MainWindow::getCurrentUser()->setLastname(this->ui->customer_lastname_line_edit->text());
    MainWindow::getCurrentUser()->setUsername(this->ui->customer_username_line_edit->text());
    MainWindow::getCurrentUser()->setPassword(this->ui->customer_password_line_edit->text());
    MainWindow::getCurrentUser()->setBirthday(this->ui->customer_birthday_edit->date());
    MainWindow::getCurrentUser()->setPhoneNumber(this->ui->customer_phone_number->text());
    User::addUser(MainWindow::getCurrentUser());
}

void Dashboard::on_show_password_checkBox_stateChanged()
{
    if(ui->show_password_checkBox->checkState()) ui->customer_password_line_edit->setEchoMode(QLineEdit::Normal);
    else ui->customer_password_line_edit->setEchoMode(QLineEdit::Password);
}

void Dashboard::on_customer_edit_clicked()
{
    this->ui->customer_account_info->hide();
    ui->customer_firstname_line_edit->setText(MainWindow::getCurrentUser()->getFirstname());
    ui->customer_lastname_line_edit->setText(MainWindow::getCurrentUser()->getLastname());
    ui->customer_username_line_edit->setText(MainWindow::getCurrentUser()->getUsername());
    ui->customer_password_line_edit->setText(MainWindow::getCurrentUser()->getPassword());
    ui->customer_birthday_edit->setDate(MainWindow::getCurrentUser()->getBirthday());
    ui->customer_email_line_edit->setText(MainWindow::getCurrentUser()->getUsername());
    ui->customer_phone_number_line_edit->setText(MainWindow::getCurrentUser()->getPhoneNumber());
    this->ui->customer_account_edit->show();
}

void Dashboard::on_back_clicked()
{
    MainWindow::setDashboard(nullptr);
    MainWindow::showMainScrollArea();
//    ui->show_password_checkBox->setCheckState(Qt::Unchecked);
//    hideCustomerWidgets();
//    this->close();
}

void Dashboard::on_customer_address_number_valueChanged(int arg1)
{
    ui->customer_show_address->setText(MainWindow::getCurrentUser()->getAddresses().at(/*arg1 - 1*/ui->customer_address_number->value() - 1));
    return;
}

void Dashboard::on_logout_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "پیام", "آیا می خواهید خارج شوید؟", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        MainWindow::getCurrentUser()->getLastActivities().push_back(QDateTime::currentDateTime());
        QFile data_remove("Database/User/" + MainWindow::getCurrentUser()->getUsername() + ".csv");
        data_remove.remove();
        User::addUser(MainWindow::getCurrentUser());
        hideCustomerWidgets();
        this->ui->back->click();
        MainWindow::setCurrentUser(new Guest);
        MainWindow::showMainScrollArea();
    }
    else
    {
        return;
    }
}

void Dashboard::on_send_clicked()
{
    QDir dashboard_director;
    dashboard_director.mkpath("Database/Dashboard");
    QFile data("Database/Dashboard/customers_messages.txt");
    QString content;
    if(data.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&data);
        in.setCodec("UTF-8");
        content = in.readAll();
        data.close();
    }
    if(data.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&data);
        out.setCodec("UTF-8");
        out << QString::fromUtf8("پیام از طرف ");
        out << MainWindow::getCurrentUser()->getFirstname().toUtf8() << " " << MainWindow::getCurrentUser()->getLastname().toUtf8() << ":";
        out << "\n";
        out << this->ui->message_text->toPlainText();
        out << "\n\n";
        out << content;
        data.close();
    }
}

void Dashboard::on_add_to_storage_clicked()
{
    if(ui->good_id_for_adding_to_storage->text().isEmpty()==true)
    {
        QMessageBox::information(this, "پیام", "کد کالا را وارد نمایید");
        return;
    }
    QString temp;
    if(this->ui->good_color_for_adding_to_storage->currentText() == "سبز") temp = "Green";
    else if(this->ui->good_color_for_adding_to_storage->currentText() == "قرمز") temp = "Red";
    else if(this->ui->good_color_for_adding_to_storage->currentText() == "آبی") temp = "Blue";
    else if(this->ui->good_color_for_adding_to_storage->currentText() == "بنفش") temp = "Purple";
    else if(this->ui->good_color_for_adding_to_storage->currentText() == "زرد") temp = "Yellow";
    else if(this->ui->good_color_for_adding_to_storage->currentText() == "صورتی") temp = "Pink";
    else if(this->ui->good_color_for_adding_to_storage->currentText() == "قهوه ای") temp = "Brown";
    else if(this->ui->good_color_for_adding_to_storage->currentText() == "مشکی") temp = "Black";
    else if(this->ui->good_color_for_adding_to_storage->currentText() == "سفید") temp = "White";
    MainWindow::getOnketRepository().addGood(this->ui->good_id_for_adding_to_storage->text(), temp, this->ui->good_number_for_adding_to_storage->value());
    QMessageBox::information(this, "پیام", "اضافه شد");
    this->clearAddGoodNumberFields();
    return;
}

void Dashboard::on_admin_back_clicked()
{
    MainWindow::setDashboard(nullptr);
    MainWindow::showMainScrollArea();
}

void Dashboard::on_inventory_clicked()
{
    if(ui->good_id_for_get_inventory->text().isEmpty()==true)
    {
        QMessageBox::information(this,"پیام","کد کالا را وارد نمایید");
        return;
    }
    QString temp;
    if(MainWindow::getOnketRepository().getRemaining().contains(ui->good_id_for_get_inventory->text()))
    {
        if(ui->good_color_for_get_inventory->currentText() == "همه موارد")
        {
            ui->show_inventory_label->setText(QString::number(MainWindow::getOnketRepository().getCommodityOf(ui->good_id_for_get_inventory->text()).inventory()) + "عدد در انبار موجود است");
        }
        else
        {
            if(ui->good_color_for_get_inventory->currentText() == "سبز") temp = "Green";
            else if(ui->good_color_for_get_inventory->currentText() == "قرمز") temp = "Red";
            else if(ui->good_color_for_get_inventory->currentText() == "آبی") temp = "Blue";
            else if(ui->good_color_for_get_inventory->currentText() == "بنفش") temp = "Purple";
            else if(ui->good_color_for_get_inventory->currentText() == "زرد") temp = "Yellow";
            else if(ui->good_color_for_get_inventory->currentText() == "صورتی") temp = "Pink";
            else if(ui->good_color_for_get_inventory->currentText() == "قهوه ای") temp = "Brown";
            else if(ui->good_color_for_get_inventory->currentText() == "مشکی") temp = "Black";
            else if(ui->good_color_for_get_inventory->currentText() == "سفید") temp = "White";
            ui->show_inventory_label->setText(QString::number(MainWindow::getOnketRepository().getCommodityOf(ui->good_id_for_get_inventory->text()).inventoryOf(temp)) + "عدد در انبار موجود است ");
        }
        this->clearInventoryFields();
    }
    else
    {
        ui->show_inventory_label->setText("چنین کالایی وجود ندارد");
    }
}

void Dashboard::on_make_good_button_clicked()
{
    Good::readFile();

    if(ui->name_of_good_to_make->text()==""|| ui->good_type_line_edit->text()=="")
    {
        QMessageBox::information(this,"پیام","همه فیلد ها را پر کنید");
        return;
    }
    if(Good::existGoodName(ui->name_of_good_to_make->text())==true)
    {
        QMessageBox::information(this,"پیام","نام کالا تکراری است");
        return;
    }

    Good temp(ui->name_of_good_to_make->text(), ui->good_type_line_edit->text(), ui->seller_code->text(), ui->price_to_make->value());
    Good& g=Good::getGood(temp.getId());
    g.setDiscountPercent(ui->discount_SpinBox->value()/100);
    for(auto it=this->good_property_list_widgets.cbegin();it!=this->good_property_list_widgets.cend();it++)
    {
        g.setPropertyValue(it.key()->text(),it.value()->text());
    }
    QString path="Database/GoodPicture/"+g.getId()+".png";
    if(QFile::exists(path)==true)
    {
        QFile::remove(path);
    }
    QFile::copy(this->img_path,path);
    QMessageBox::information(this,"پیام","کالا ساخته شد");
    this->img_path.clear();
    this->good_property_list_widgets.clear();
    Good::WriteFile();
    Type::WriteToFile();
    this->clearAddGoodFields();
    emit this->updateGoodsRequest(Type::getCurrentTypeId());
    return;
}

void Dashboard::on_admin_apply_changes_button_clicked()
{
    QFile data_remove("Database/User/" + MainWindow::getCurrentUser()->getUsername() + ".csv");
    data_remove.remove();
    MainWindow::getCurrentUser()->setFirstname(this->ui->admin_firstname_line_edit->text());
    MainWindow::getCurrentUser()->setLastname(this->ui->admin_lastname_line_edit->text());
    MainWindow::getCurrentUser()->setUsername(this->ui->admin_username_line_edit->text());
    MainWindow::getCurrentUser()->setPassword(this->ui->admin_password_line_edit->text());
    User::addUser(MainWindow::getCurrentUser());
    QMessageBox::information(this, "پیام", "تفییرات با موفقیت اعمال شد");
    ui->admin_account_edit->hide();
    ui->admin_account_info->show();
}

void Dashboard::on_show_password_checkBox_2_stateChanged()
{
    if(ui->show_password_checkBox_2->checkState()) ui->admin_password_line_edit->setEchoMode(QLineEdit::Normal);
    else ui->admin_password_line_edit->setEchoMode(QLineEdit::Password);
}

void Dashboard::on_admin_edit_clicked()
{
    this->ui->admin_account_info->hide();
    ui->admin_firstname_line_edit->setText(MainWindow::getCurrentUser()->getFirstname());
    ui->admin_lastname_line_edit->setText(MainWindow::getCurrentUser()->getLastname());
    ui->admin_username_line_edit->setText(MainWindow::getCurrentUser()->getUsername());
    ui->admin_password_line_edit->setText(MainWindow::getCurrentUser()->getPassword());
    this->ui->admin_account_edit->show();
}

void Dashboard::on_admin_edit_back_clicked()
{
    this->ui->admin_account_edit->hide();
    this->ui->admin_account_info->show();
}

void Dashboard::on_admin_info_back_clicked()
{
    this->ui->admin_account_info->hide();
}

void Dashboard::on_choose_picture_for_good_clicked()
{
    img_path = QFileDialog::getOpenFileName(this,"Open File","Database/GoodPicture","*.png");
    QImage img;
    if(img.load(img_path)==false)
    {
        return;
    }
    ui->picture_of_good_to_make->setPixmap(QPixmap::fromImage(img));
    ui->picture_of_good_to_make->setScaledContents(true);
}
void Dashboard::on_make_type_button_clicked()
{

    if(ui->name_of_type->text().isEmpty()  || ui->name_of_type_to_make->text().isEmpty())
    {
        QMessageBox::information(this,"پیام","همه فیلد ها را پر کنید");
        return;
    }

    Type temp(ui->name_of_type->text(),ui->name_of_type_to_make->text());
    const Type& t=Type::getType(temp.getId());
    for(auto it : property_list)
    {
        t.addProperty(it);
    }
    for(auto it : comment_list)
    {
        t.addCommentItem(it);
    }
    this->comment_list.clear();
    this->property_list.clear();
    Type::WriteToFile();
    QMessageBox::information(this,"پیام","نوع جدید اضافه شد");
    this->clearAddTypeFields();
    emit updateTypesRequest();
    return;
}

void Dashboard::on_name_of_type_to_make_editingFinished()
{
    Type::readFile();
    if(ui->name_of_type_to_make->text()=="none")
    {
        return;
    }
    if(ui->name_of_type_to_make->text() != "" && Type::existTypeId(ui->name_of_type_to_make->text())==true )
    {
        const Type& t=Type::getType(ui->name_of_type_to_make->text());
        for(t.setPropertySeekBegin();t.PropertySeekAtEnd()==false;)
        {
            QString property_name=t.readPropertyName();
            QLabel* lab_property=new QLabel(property_name,this);
            lab_property->setFixedSize(200,40);
            this->lay_property->addWidget(lab_property);
            this->property_list.push_back(property_name);

        }
        for(t.setCommentSeekBegin();t.CommentSeekAtEnd()==false;)
        {

            QString comment_name=t.readCommentItem();
            QLabel* lab_comment=new QLabel(comment_name,this);
            lab_comment->setFixedSize(200,40);
            this->lay_comment->addWidget(lab_comment);
            this->comment_list.push_back(comment_name);
        }
    }
}

void Dashboard::on_pushButton_add_properties_clicked()
{
    QString property_name=ui->propery_name_line_edit->text();
    this->property_list.push_back(property_name);
    QLabel* lab_property=new QLabel(property_name,this);
    lab_property->setFixedSize(200,40);
    this->lay_property->addWidget(lab_property);
    ui->propery_name_line_edit->clear();
}

void Dashboard::on_pushButton_add_comment_item_clicked()
{
    QString item_name=ui->item_name_line_edit->text();
    this->comment_list.push_back(item_name);
    QLabel* lab_comment=new QLabel(item_name,this);
    lab_comment->setFixedSize(200,40);
    this->lay_comment->addWidget(lab_comment);
    ui->item_name_line_edit->clear();
    
}

void Dashboard::on_name_of_good_to_make_editingFinished()
{
    QString good_name=ui->name_of_good_to_make->text();
    if(Good::existGoodName(good_name)==true)
    {
        QMessageBox::information(this,"پیام","نام کالا تکراری است");
        return;
    }
}

void Dashboard::on_good_type_line_edit_editingFinished()
{
    Type::readFile();

    if(Type::existTypeId(ui->good_type_line_edit->text().toUtf8())==false && ui->good_type_line_edit->text()!="")
    {
        QMessageBox::information(this,"پیام","نوع کالا موجود نیست");
        return;
    }
    else if(ui->good_type_line_edit->text()=="")
    {
        QMessageBox::information(this,"پیام","نوع کالا را وارد کنید");
        return;
    }
    else
    {
        const Type& t=Type::getType(ui->good_type_line_edit->text().toUtf8());
        for(t.setPropertySeekBegin();t.PropertySeekAtEnd()==false;)
        {
            QString property_name=t.readPropertyName();
            this->addPropertyItemToScrollArea(property_name);
        }
    }
}

void Dashboard::addPropertyItemToScrollArea(const QString &property_name)
{
    static int row=0;
    QLabel* lab_property_name=new QLabel(property_name,this);
    QLineEdit* le_property_value=new QLineEdit("",this);
    lab_property_name->setFixedSize(200,40);
    le_property_value->setFixedSize(200,40);
    le_property_value->setStyleSheet("background-color: rgb(255, 255, 255);");
    this->good_property_list_widgets.insert(lab_property_name,le_property_value);
    this->lay_good_property->addWidget(lab_property_name,row,0);
    this->lay_good_property->addWidget(le_property_value,row,1);
    row++;
}

void Dashboard::on_good_id_for_adding_to_storage_editingFinished()
{
    Type::readFile();
    Good::readFile();
    if(Good::existGoodId(ui->good_id_for_adding_to_storage->text())==false)
    {
        ui->add_to_storage->setToolTip("کد کالای مورد نظر وجود ندارد");
    }
    else
    {
        Good& g=Good::getGood(ui->good_id_for_adding_to_storage->text());
        QString tooltip=g.getName()+","+QString::number(g.getFinalPrice())+" تومان";
        ui->add_to_storage->setToolTip(tooltip);
    }
}

void Dashboard::on_good_id_for_get_inventory_editingFinished()
{
    Type::readFile();
    Good::readFile();
    if(Good::existGoodId(ui->good_id_for_get_inventory->text())==false)
    {
        ui->inventory->setToolTip("کد کالای مورد نظر وجود ندارد");
    }
    else
    {
        Good& g=Good::getGood(ui->good_id_for_get_inventory->text());
        QString tooltip=g.getName()+","+QString::number(g.getFinalPrice())+" تومان";
        ui->inventory->setToolTip(tooltip);
    }
}

void Dashboard::on_logout_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "پیام", "آیا می خواهید خارج شوید؟", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        MainWindow::getCurrentUser()->getLastActivities().push_back(QDateTime::currentDateTime());
        QFile data_remove("Database/User/" + MainWindow::getCurrentUser()->getUsername() + ".csv");
        data_remove.remove();
        User::addUser(MainWindow::getCurrentUser());
        this->ui->admin_back->click();
        MainWindow::setCurrentUser(new Guest);
        MainWindow::showMainScrollArea();
    }
    else
    {
        return;
    }
}

void Dashboard::on_username_of_customer_currentTextChanged(const QString &arg1)
{
    QDir dir("Database/User");
    int temp1 = ui->username_of_customer->count();
    int temp2 = dir.count();
    if(ui->username_of_customer->count() - 1 == dir.count() - 5 && ui->username_of_customer->currentIndex() != 0)
    {
        User* temp = User::getUser(ui->username_of_customer->currentText());
        ui->user_management_label_customer_firstname->setText(temp->getFirstname());
        ui->user_management_label_customer_lastname->setText(temp->getLastname());
        ui->user_management_label_customer_password->setText(temp->getPassword());
        ui->user_management_label_customer_birthday->setText(temp->getBirthday().toString());
        ui->user_management_label_customer_phone->setText(temp->getPhoneNumber());
        ui->comboBox_addresses_of_customer->clear();
        ui->customer_activity_log->clear();
        for(int i = 0; i < temp->getAddresses().size(); i++)
        {
            ui->comboBox_addresses_of_customer->addItem(temp->getAddresses().at(i));
        }
        //orders
        ui->customer_orders_log->clear();
        for(int i = 0; i < temp->getOrderIds().size(); i++)
        {
            Order kemp = Order::getOrder(temp->getOrderIds().at(i));
            ui->customer_orders_log->append("کد سفارش: " + kemp.getOrderId() + "\n"
                                            + "تاریخ ثبت سفارش: " + kemp.getOrderDate().toString() + "\n" + "کالاهای خریداری شده:");
            for(int j = 0; j < kemp.getBasket().size(); j++)
            {
                ui->customer_orders_log->append(kemp.getBasket().at(j).getItemId() + "|" + kemp.getBasket().at(j).getItemColor()+ "|" + kemp.getBasket().at(j).getNumber());
            }
            ui->customer_orders_log->append("آدرس تحویل: " + kemp.getDeliverAddress());
            ui->customer_orders_log->append("قیمت کل: " + QString::number(kemp.totalPrice()));
            ui->customer_orders_log->append("تاریخ تحویل: " + kemp.getDeliverDate().toString());
            ui->customer_orders_log->append("______________________________________________________________________");
        }
        for(int i = 0; i < temp->getLastActivities().size(); i+=2)
        {
            if(i % 2 == 0) ui->customer_activity_log->append(temp->getLastActivities().at(i).toString() + "-" + temp->getLastActivities().at(i+1).toString());
        }
        return;
    }
    else return;
}

void Dashboard::on_user_management_back_clicked()
{
    ui->username_of_customer->setCurrentIndex(0);
    ui->user_management_label_customer_firstname->clear();
    ui->user_management_label_customer_lastname->clear();
    ui->user_management_label_customer_password->clear();
    ui->user_management_label_customer_birthday->clear();
    ui->user_management_label_customer_phone->clear();
    ui->comboBox_addresses_of_customer->clear();
    //orders
    ui->customer_activity_log->clear();
    ui->user_management->hide();
}

void Dashboard::on_admin_back_2_clicked()
{
    void clearAddGoodNumberFields();
    void clearInventoryFields();
    void clearAddGoodFields();
    void clearAddTypeFields();
    ui->goods_management->hide();
}

void Dashboard::on_messages_2_back_clicked()
{
    ui->receiver->setCurrentText(0);
    ui->message_text->clear();
    ui->messages_2->hide();
}

void Dashboard::on_site_settings_back_clicked()
{
    ui->site_settings->hide();
}

void Dashboard::on_foreign_conncections_back_clicked()
{
    ui->foreign_connections->hide();
}

void Dashboard::on_finance_back_clicked()
{
    ui->finance->hide();
}

void Dashboard::on_employeement_back_clicked()
{
    ui->employeement->hide();
}

void Dashboard::on_website_management_clicked()
{
    this->hideAdminWidgets();
    ui->site_settings->show();
}

void Dashboard::on_comments_back_clicked()
{
    ui->comments->hide();
}

void Dashboard::on_customer_account_edit_back_clicked()
{
    ui->customer_account_edit->hide();
    ui->customer_account_info->show();
}

void Dashboard::on_customer_account_info_back_clicked()
{
    ui->customer_account_info->hide();
}

void Dashboard::on_last_activities_back_clicked()
{
    ui->last_activities->hide();
}

void Dashboard::on_my_orders_back_clicked()
{
    ui->my_orders->hide();
}

void Dashboard::on_lists_back_clicked()
{
    ui->lists->hide();
}

void Dashboard::on_messages_back_clicked()
{
    ui->messages->hide();
}
