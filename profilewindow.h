#pragma once
#include <QWidget>
#include "databasemanager.h"
#include "ui_profile_window.h"

class ProfileWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileWindow(int userId, DatabaseManager* dbManager, QWidget *parent = nullptr);
    ~ProfileWindow() override;

private slots:
    void on_backButton_clicked();
    void on_editRouteButton_clicked();
    void on_deleteRouteButton_clicked();

private:
    void loadUserRoutes();

private:
    Ui_profile_widget *ui;
    int userId_;
    DatabaseManager* dbManager_;
    bool isRouteCardWindowOpen_ = false; // <-- Флаг для окна профиля
};
