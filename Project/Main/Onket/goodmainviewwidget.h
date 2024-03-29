﻿#ifndef GOODMAINVIEWWIDGET_H
#define GOODMAINVIEWWIDGET_H

#include <QScrollArea>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDir>
#include <QComboBox>
#include <QSpinBox>

#include "good.h"
#include "User.h"
#include "commentitemstatus.h"
#include "goodpropertywidget.h"
#include "goodgenralinfowidget.h"
#include "commentlistwidget.h"
#include "discussionlistwidget.h"




namespace Ui {
class goodMainviewWidget;
}

class goodMainViewWidget : public QScrollArea
{
    Q_OBJECT
    QString good_id,user_id;
    bool info_valid=false;
    QPushButton* bnt_return=nullptr,*bnt_comment=nullptr,*bnt_discussion=nullptr;
    QWidget* center_widget=nullptr;
    QGridLayout* main_lay=nullptr;
    QVBoxLayout* lay_picture=nullptr,*lay_body=nullptr,*lay_comment_items=nullptr,*lay_buy=nullptr,*lay_return=nullptr,*lay_area=nullptr;
    QHBoxLayout* lay_buttons=nullptr;
    QLabel* lab_img=nullptr;
    QComboBox* color_selection=nullptr;
    QSpinBox* item_number=nullptr;
    QPushButton* bnt_add_to_basket=nullptr;
    GoodPropertyWidget* g_properties=nullptr;
    CommentItemStatus* c_status;
    GoodGenralInfoWidget* g_general=nullptr;
    CommentListWidget* comments_area=nullptr;
    DiscussionListWidget* discussion_area=nullptr;

    void setupSTyleSheet();
    void setupLayout();
    void setupComboBox();
signals:
    void updateGoodsRequest();
private slots:
    void on_bnt_return_clicked();
    void on_bnt_add_to_basket_clicked();
    void on_bnt_comment_clicked();
    void on_bnt_discussion_clicked();
    void color_section_current_text_chenged(const QString& current_color);

public slots:
    void update();
public:
    explicit goodMainViewWidget(const QString& good_id,const QString& user_id,QWidget *parent = nullptr);
    ~goodMainViewWidget();

private:
    Ui::goodMainviewWidget *ui;
};

#endif // GOODMAINVIEWWIDGET_H
