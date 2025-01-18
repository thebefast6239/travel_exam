#include "loginwindow.h"
#include "ui_login_window.h"

LoginWindow::LoginWindow(DatabaseManager *dbManager, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui_login_widget),
    userManager_(dbManager),
    dbManager_(dbManager)
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWindow::on_loginButton_clicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginWindow::on_registerButton_clicked);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if(username.isEmpty() || password.isEmpty()){
        ui->loginMessage->setText("Пожалуйста, введите имя пользователя и пароль.");
        return;
    }
    if (userManager_.authenticate(username, password)) {
        int userId = userManager_.getUserId(username);
        MainWindow *mainWindow = new MainWindow(userId, dbManager_);
        mainWindow->show();
        this->deleteLater(); // <-- Отложенное удаление окна ПОСЛЕ показа нового
    } else {
        ui->loginMessage->setText("Неверное имя пользователя или пароль.");
    }
}

void LoginWindow::on_registerButton_clicked()
{
    // Создаем новое окно регистрации
    RegisterWindow *registerWindow = new RegisterWindow(dbManager_);
    registerWindow->setAttribute(Qt::WA_DeleteOnClose); // Удаление окна при закрытии
    registerWindow->show();

    // Закрываем текущее окно
    this->close();
}
