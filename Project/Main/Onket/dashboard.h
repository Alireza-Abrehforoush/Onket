#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QImage>
#include <QLabel>
#include <QLineEdit>
#include "User.h"
#include "type.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dashboard; }
QT_END_NAMESPACE

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    Dashboard(User* current_user, QWidget *parent = nullptr);
    void hideAdminWidgets();
    void hideCustomerWidgets();
    void clearAddGoodNumberFields();
    void clearInventoryFields();
    void clearAddGoodFields();
    void clearAddTypeFields();
    ~Dashboard();

private slots:
    void on_pushButton_15_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_account_management_clicked();

    void on_goods_clicked();

    void on_users_management_clicked();

    void on_pushButton_3_clicked();

    void on_financial_management_clicked();

    void on_pushButton_5_clicked();

    void on_send_message_clicked();

    void on_pushButton_8_clicked();

    void on_customer_address_edit_of_valueChanged(int arg1);

    void on_remove_this_address_button_clicked();

    void on_customer_address_number_edit_valueChanged(int arg1);

    void on_add_this_address_button_clicked();

    void on_customer_apply_changes_button_clicked();

    void on_show_password_checkBox_stateChanged();

    void on_customer_edit_clicked();

    void on_back_clicked();

    void on_customer_address_number_valueChanged(int arg1);

    void on_logout_clicked();

    void on_send_clicked();

    void on_add_to_storage_clicked();

    void on_admin_back_clicked();

    void on_inventory_clicked();

    void on_make_good_button_clicked();

    void on_admin_apply_changes_button_clicked();

    void on_show_password_checkBox_2_stateChanged();

    void on_admin_edit_clicked();

    void on_admin_edit_back_clicked();

    void on_admin_info_back_clicked();

    void on_choose_picture_for_good_clicked();

    void on_make_type_button_clicked();

    void on_name_of_type_to_make_editingFinished();

    void on_pushButton_add_properties_clicked();

    void on_pushButton_add_comment_item_clicked();
    
    void on_name_of_good_to_make_editingFinished();

    void on_good_type_line_edit_editingFinished();

    void on_good_id_for_adding_to_storage_editingFinished();

    void on_good_id_for_get_inventory_editingFinished();

    void on_logout_2_clicked();

    void on_username_of_customer_currentTextChanged(const QString &arg1);

    void on_user_management_back_clicked();

    void on_admin_back_2_clicked();

    void on_messages_2_back_clicked();

    void on_site_settings_back_clicked();

    void on_foreign_conncections_back_clicked();

    void on_finance_back_clicked();

    void on_employeement_back_clicked();

    void on_website_management_clicked();

    void on_comments_back_clicked();

    void on_customer_account_edit_back_clicked();

    void on_customer_account_info_back_clicked();

    void on_last_activities_back_clicked();

    void on_my_orders_back_clicked();

    void on_lists_back_clicked();

    void on_messages_back_clicked();

private:
    QWidget* property_center_widget,* comment_center_widget,*good_property_center_widget;
    QVBoxLayout* lay_property,*lay_comment;
    QGridLayout* lay_good_property;
    QVector<QString> property_list,comment_list;
    QMap<QLabel*,QLineEdit*> good_property_list_widgets;
    QString img_path;
    Ui::Dashboard *ui;
    void addPropertyItemToScrollArea(const QString& property_name);

signals:
    void updateGoodsRequest(const QString& type_id);
    void updateTypesRequest();
};
#endif // DASHBOARD_H
