#include "window.h"
#include <QGridLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

Window::Window():
QDialog()
{
    layout_ = new QGridLayout(this);

    list_widget_ = new QListWidget(this);
    list_widget_->setSelectionMode(QAbstractItemView::SingleSelection);

    line_edit_ = new QLineEdit(this);

    add_button_ = new QPushButton("Add", this);
    add_button_->setDisabled(true);

    remove_button_ = new QPushButton("Remove", this);
    remove_button_->setDisabled(true);

    layout_->addWidget(list_widget_, 0, 0, 1, 3);
    layout_->addWidget(line_edit_, 1, 0);
    layout_->addWidget(add_button_, 1, 1);
    layout_->addWidget(remove_button_, 1, 2);

    connect(line_edit_, &QLineEdit::textChanged, this,
    [this](const QString &text){
        add_button_->setDisabled(text.isEmpty());
    });
    connect(list_widget_, &QListWidget::itemSelectionChanged, this,
    [this](){
        remove_button_->setDisabled(list_widget_->selectedItems().isEmpty());
    });

    connect(add_button_, &QPushButton::clicked, this,
    [this](){
        auto item = new QListWidgetItem(line_edit_->text(), list_widget_);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        line_edit_->setText("");
    });

    connect(list_widget_, &QListWidget::itemChanged, this,
    [this](QListWidgetItem *item){
        item->checkState() == Qt::Checked ? item->setBackground(QColor(115, 195, 15)) : item->setBackground(QColor(255, 255, 255));
    });

    connect(remove_button_, &QPushButton::clicked, this,
    [this](){
        auto removed_item = list_widget_->selectedItems().back();
        delete removed_item;
    });
}