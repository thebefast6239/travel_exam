#include "createroutewindow.h"
#include "ui_create_route_window.h"
#include <QDebug>
#include <QMouseEvent>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QInputDialog>

CreateRouteWindow::CreateRouteWindow(int userId, DatabaseManager *dbManager, QWidget *parent)
    : QWidget(parent),
    ui(new Ui_create_route_widget),
    userId_(userId),
    dbManager_(dbManager)
{
    ui->setupUi(this);
    qDebug() << "User ID in CreateRouteWindow:" << userId_;
    connect(ui->saveButton, &QPushButton::clicked, this, &CreateRouteWindow::on_saveButton_clicked); // <-- Вернули connect
    connect(ui->cancelButton, &QPushButton::clicked, this, &CreateRouteWindow::on_cancelButton_clicked);
    connect(ui->addPointButton, &QPushButton::clicked, this, [this](){ on_addPointButton_clicked(); });
}

CreateRouteWindow::~CreateRouteWindow()
{
    delete ui;
}

void CreateRouteWindow::mousePressEvent(QMouseEvent *event){

}

void CreateRouteWindow::on_addPointButton_clicked()
{
    bool ok;
    QString pointName = QInputDialog::getText(this, "Новая точка", "Введите название точки:", QLineEdit::Normal, "", &ok);
    if (ok && !pointName.isEmpty()){
        ui->routePointsList->addItem(pointName);
    }
}

void CreateRouteWindow::on_saveButton_clicked()
{
    QString title = ui->titleEdit->text();
    QString description = ui->descriptionEdit->toPlainText();
    int groupId = 1; // Заглушка
    QList<QString> points;
    for (int i = 0; i < ui->routePointsList->count(); ++i) {
        points.append(ui->routePointsList->item(i)->text());
    }

    if (dbManager_->saveRoute(userId_, title, description, groupId, points)) {
        QMessageBox::information(this, "Успех", "Маршрут " + title + " сохранен.");
        this->deleteLater();
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить маршрут.");
    }
}

void CreateRouteWindow::on_cancelButton_clicked()
{
    this->close();
}

void CreateRouteWindow::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);
}
