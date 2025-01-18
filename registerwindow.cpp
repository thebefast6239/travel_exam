#include "registerwindow.h"
#include "ui_register_window.h"
#include <QMessageBox>
#include "loginwindow.h"

RegisterWindow::RegisterWindow(DatabaseManager *dbManager, QWidget *parent) :
    QWidget(nullptr), // <-- Создаем RegisterWindow без родителя
    ui(new Ui_register_widget),
    userManager_(dbManager),
    dbManager_(dbManager)
{
    ui->setupUi(this);
    connect(ui->registerRegisterButton, &QPushButton::clicked, this, &RegisterWindow::on_registerRegisterButton_clicked);
    connect(ui->registerCancelButton, &QPushButton::clicked, this, &RegisterWindow::on_registerCancelButton_clicked);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_registerRegisterButton_clicked()
{
    QString username = ui->registerUsernameEdit->text();
    QString password = ui->registerPasswordEdit->text();
    QString confirmPassword = ui->registerConfirmPasswordEdit->text();

    if(username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()){
        ui->registerMessageLabel->setText("Пожалуйста, заполните все поля.");
        return;
    }
    if(password != confirmPassword){
        ui->registerMessageLabel->setText("Пароли не совпадают.");
        return;
    }

    if (userManager_.registerUser(username, password)) {
        QMessageBox::information(this, "Успех", "Регистрация успешна.");
        LoginWindow *loginWindow = new LoginWindow(dbManager_, nullptr); // <-- Создаем LoginWindow без родителя
        loginWindow->show();
        this->close(); // <-- Закрываем текущее окно

    } else {
        ui->registerMessageLabel->setText("Ошибка регистрации. Возможно, пользователь уже существует.");
    }
}

void RegisterWindow::on_registerCancelButton_clicked()
{
    LoginWindow *loginWindow = new LoginWindow(dbManager_, nullptr); // <-- Создаем LoginWindow без родителя
    loginWindow->show();
    this->close(); // <-- Закрываем текущее окно

}
