#include "dashboard.h"
#include "ui_dashboard.h"
#include "mainwindow.h"

Dashboard::Dashboard(User* current_user, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    if(current_user->getMode() == 0)
    {
        ui->admin->hide();
        ui->customer->show();

        ui->my_orders->hide();
        ui->lists->hide();
        ui->comments->hide();
        ui->addresses->hide();
        ui->messages->hide();
        ui->last_activities->hide();
        ui->account_info->hide();
    }
    else if(current_user->getMode() == 1)
    {
        ui->admin->show();
        ui->customer->hide();

        ui->goods_management->hide();
        ui->user_management->hide();
        ui->site_settings->hide();
        ui->finance->hide();
        ui->employeement->hide();
        ui->treaties->hide();
        ui->account_info->hide();
        ui->foreign_connections->hide();
    }
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_pushButton_9_clicked()
{
    ui->my_orders->show();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->account_info->hide();
}

void Dashboard::on_pushButton_10_clicked()
{
    ui->my_orders->hide();
    ui->lists->show();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->account_info->hide();
}

void Dashboard::on_pushButton_11_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->show();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->account_info->hide();
}

void Dashboard::on_pushButton_12_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->show();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->account_info->hide();
}

void Dashboard::on_pushButton_13_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->show();
    ui->last_activities->hide();
    ui->account_info->hide();
}

void Dashboard::on_pushButton_14_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->show();
    ui->account_info->hide();
}

void Dashboard::on_pushButton_15_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->account_info->show();

    ui->customer_first_and_last_name->setText(MainWindow::getCurrentUser()->getFirstname() + " " + MainWindow::getCurrentUser()->getLastname());
    ui->customer_username->setText(MainWindow::getCurrentUser()->getUsername());
    ui->customer_password->setText(MainWindow::getCurrentUser()->getPassword());
    ui->customer_phone_number->setText(MainWindow::getCurrentUser()->getPhoneNumber());
    ui->customer_birthday->setText(MainWindow::getCurrentUser()->getBirthday().toString());
    ui->customer_email->setText(MainWindow::getCurrentUser()->getUsername());
    ui->customer_show_address->setText(MainWindow::getCurrentUser()->getAddresses().at(ui->customer_address_number->value() - 1));

    ui->customer_address_number_edit->clear();
}

void Dashboard::on_pushButton_clicked()
{
    ui->goods_management->show();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->hide();
    ui->treaties->hide();
    ui->account_info->hide();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_2_clicked()
{
    ui->goods_management->hide();
    ui->user_management->show();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->hide();
    ui->treaties->hide();
    ui->account_info->hide();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_3_clicked()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->show();
    ui->finance->hide();
    ui->employeement->hide();
    ui->treaties->hide();
    ui->account_info->hide();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_4_clicked()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->show();
    ui->employeement->hide();
    ui->treaties->hide();
    ui->account_info->hide();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_5_clicked()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->show();
    ui->treaties->hide();
    ui->account_info->hide();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_6_clicked()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->hide();
    ui->treaties->show();
    ui->account_info->hide();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_7_clicked()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->hide();
    ui->treaties->hide();
    ui->account_info->show();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_8_clicked()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->hide();
    ui->treaties->hide();
    ui->account_info->hide();
    ui->foreign_connections->show();
}

void Dashboard::on_customer_address_edit_of_valueChanged(int arg1)
{
    this->ui->customer_addresses_to_be_removed->setText(MainWindow::getCurrentUser()->getAddresses().at(arg1-1));
}
