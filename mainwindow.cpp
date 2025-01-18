#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(int userId, DatabaseManager *dbManager, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    userId_(userId),
    dbManager_(dbManager)  // <-- выделяем память под ui через new
{
    ui->setupUi(this);
    qDebug() << "User ID in MainWindow:" << userId_;
}

MainWindow::~MainWindow()
{
    delete ui; // <-- удаляем выделенную память
}
