#pragma once

#include "databasemanager.h"
#include <QMainWindow>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int userId, DatabaseManager* dbManager, QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui; // <-- ui теперь указатель
    int userId_;
    DatabaseManager* dbManager_;
};
