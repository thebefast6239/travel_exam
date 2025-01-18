#pragma once
#include <QWidget>
#include "databasemanager.h"
#include "ui_create_route_window.h"
#include <QGraphicsView>
#include <QMouseEvent>
#include <QCloseEvent>


namespace Ui {
class CreateRouteWindow;
}

class CreateRouteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CreateRouteWindow(int userId, DatabaseManager* dbManager, QWidget *parent = nullptr);
    ~CreateRouteWindow() override;

private slots:
    void on_addPointButton_clicked();
    void on_saveButton_clicked(); // <-- Вернули слот
    void on_cancelButton_clicked();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
private:
    Ui_create_route_widget *ui;
    int userId_;
    DatabaseManager* dbManager_;
};
