#include "profilewindow.h"
#include "ui_profile_window.h"
#include <QDebug>
#include <QMessageBox>

ProfileWindow::ProfileWindow(int userId, DatabaseManager* dbManager, QWidget *parent)
    : QWidget(parent),
    ui(new Ui_profile_widget),
    userId_(userId),
    dbManager_(dbManager)
{
    ui->setupUi(this);
    qDebug() << "User ID in ProfileWindow:" << userId_;
    connect(ui->backButton, &QPushButton::clicked, this, &ProfileWindow::on_backButton_clicked);
    connect(ui->editRouteButton, &QPushButton::clicked, this, &ProfileWindow::on_editRouteButton_clicked);
    connect(ui->deleteRouteButton, &QPushButton::clicked, this, &ProfileWindow::on_deleteRouteButton_clicked);
    loadUserRoutes();
}

ProfileWindow::~ProfileWindow()
{
    delete ui;
}

void ProfileWindow::on_backButton_clicked()
{
    this->deleteLater();// <-- Удаляем окно ПОСЛЕ показа нового
}
void ProfileWindow::on_editRouteButton_clicked()
{
    QMessageBox::information(this, "Редактирование", "Редактирование маршрутов пока не реализовано.");
}
void ProfileWindow::on_deleteRouteButton_clicked()
{
    if (ui->listWidget->currentItem() == nullptr) {
        QMessageBox::warning(this, "Ошибка", "Выберите маршрут для удаления");
        return;
    }
    QString routeTitle = ui->listWidget->currentItem()->text();

    if (dbManager_->deleteRoute(userId_, routeTitle)) {
        QMessageBox::information(this, "Успех", "Маршрут " + routeTitle + " удален.");
        ui->listWidget->setCurrentItem(nullptr);
        loadUserRoutes();
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось удалить маршрут " + routeTitle);
    }
}

void ProfileWindow::loadUserRoutes()
{
    QList<QVariantList> routes = dbManager_->getUserRoutes(userId_);
    ui->listWidget->clear();
    if(routes.isEmpty()){
        ui->listWidget->addItem("Нет созданных маршрутов");
    }else{
        for (const QVariantList& route : routes) {
            ui->listWidget->addItem(route[0].toString());
        }
    }
}
