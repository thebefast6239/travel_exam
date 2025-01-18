#pragma once
#include <QMainWindow>
#include "ui_login_window.h"
#include "usermanager.h"
#include "mainwindow.h"
#include "registerwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~LoginWindow() override;

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();

private:
    Ui_login_widget *ui; // <-- Правильное имя класса
    UserManager userManager_;
    DatabaseManager* dbManager_;
};
