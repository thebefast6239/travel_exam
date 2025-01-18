#pragma once
#include <QWidget>
#include "usermanager.h"
#include "ui_register_window.h"

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWindow(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~RegisterWindow() override;

private slots:
    void on_registerRegisterButton_clicked();
    void on_registerCancelButton_clicked();

private:
    Ui_register_widget *ui; // <-- Исправленное имя класса
    UserManager userManager_;
    DatabaseManager* dbManager_;
};
