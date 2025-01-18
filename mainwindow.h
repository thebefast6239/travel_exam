#pragma once

#include "databasemanager.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "profilewindow.h"
#include "createroutewindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int userId, DatabaseManager* dbManager, QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_profilebutton_clicked();
    void on_createRouteButton_clicked();

private:
    void loadTravelGroups();
    //  bool isProfileWindowOpen_ = false; // <-- Удалили флаг
    //  bool isCreateRouteWindowOpen_ = false; // <-- Удалили флаг

private:
    Ui::MainWindow *ui;
    int userId_;
    DatabaseManager* dbManager_;
};
