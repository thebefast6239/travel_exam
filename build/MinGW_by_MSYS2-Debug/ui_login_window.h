/********************************************************************************
** Form generated from reading UI file 'login_window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_WINDOW_H
#define UI_LOGIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login_widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *login_widget_layout;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QLabel *loginMessage;

    void setupUi(QWidget *login_widget)
    {
        if (login_widget->objectName().isEmpty())
            login_widget->setObjectName("login_widget");
        login_widget->resize(400, 258);
        layoutWidget = new QWidget(login_widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 30, 361, 221));
        login_widget_layout = new QVBoxLayout(layoutWidget);
        login_widget_layout->setObjectName("login_widget_layout");
        login_widget_layout->setContentsMargins(0, 0, 0, 0);
        usernameLabel = new QLabel(layoutWidget);
        usernameLabel->setObjectName("usernameLabel");

        login_widget_layout->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(layoutWidget);
        usernameEdit->setObjectName("usernameEdit");

        login_widget_layout->addWidget(usernameEdit);

        passwordLabel = new QLabel(layoutWidget);
        passwordLabel->setObjectName("passwordLabel");

        login_widget_layout->addWidget(passwordLabel);

        passwordEdit = new QLineEdit(layoutWidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        login_widget_layout->addWidget(passwordEdit);

        loginButton = new QPushButton(layoutWidget);
        loginButton->setObjectName("loginButton");

        login_widget_layout->addWidget(loginButton);

        registerButton = new QPushButton(layoutWidget);
        registerButton->setObjectName("registerButton");

        login_widget_layout->addWidget(registerButton);

        loginMessage = new QLabel(layoutWidget);
        loginMessage->setObjectName("loginMessage");

        login_widget_layout->addWidget(loginMessage);


        retranslateUi(login_widget);

        QMetaObject::connectSlotsByName(login_widget);
    } // setupUi

    void retranslateUi(QWidget *login_widget)
    {
        login_widget->setWindowTitle(QCoreApplication::translate("login_widget", "Travelfimov | Login", nullptr));
        usernameLabel->setText(QCoreApplication::translate("login_widget", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("login_widget", "login", nullptr));
        passwordLabel->setText(QCoreApplication::translate("login_widget", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("login_widget", "password", nullptr));
        loginButton->setText(QCoreApplication::translate("login_widget", "\320\222\321\205\320\276\320\264", nullptr));
        registerButton->setText(QCoreApplication::translate("login_widget", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        loginMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login_widget: public Ui_login_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_WINDOW_H
