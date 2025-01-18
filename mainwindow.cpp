#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "profilewindow.h"
#include "createroutewindow.h"

MainWindow::MainWindow(int userId, DatabaseManager *dbManager, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    userId_(userId),
    dbManager_(dbManager)
{
    ui->setupUi(this);
    qDebug() << "User ID in MainWindow:" << userId_;
    connect(ui->profileButton, &QPushButton::clicked, this, &MainWindow::on_profilebutton_clicked);
    connect(ui->createRouteButton, &QPushButton::clicked, this, &MainWindow::on_createRouteButton_clicked);
    loadTravelGroups();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_profilebutton_clicked()
{
    ProfileWindow *profileWindow = new ProfileWindow(userId_, dbManager_, nullptr);
    profileWindow->show();
    connect(profileWindow, &ProfileWindow::destroyed, this, [ profileWindow](){ delete profileWindow;}); // <-- Захват переменной
    this->deleteLater();

}

void MainWindow::on_createRouteButton_clicked()
{
    CreateRouteWindow *createRouteWindow = new CreateRouteWindow(userId_, dbManager_, nullptr);
    createRouteWindow->show();
    connect(createRouteWindow, &CreateRouteWindow::destroyed, this, [ createRouteWindow](){delete createRouteWindow;}); // <-- Захват переменной
    this->deleteLater();
}

void MainWindow::loadTravelGroups()
{
    QList<QString> groups = dbManager_->getTravelGroups();
    ui->travelGroupsList->clear();
    if(groups.isEmpty()){
        ui->travelGroupsList->addItem("Нет доступных групп");
    } else{
        for (const QString& group : groups) {
            ui->travelGroupsList->addItem(group);
        }
    }
}
