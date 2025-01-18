/********************************************************************************
** Form generated from reading UI file 'register_window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_WINDOW_H
#define UI_REGISTER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_register_widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *register_widget_layout;
    QLabel *registerUsernameLabel;
    QLineEdit *registerUsernameEdit;
    QLabel *registerPasswordLabel;
    QLineEdit *registerPasswordEdit;
    QLabel *registerConfirmPasswordLabel;
    QLineEdit *registerConfirmPasswordEdit;
    QPushButton *registerRegisterButton;
    QPushButton *registerCancelButton;
    QLabel *registerMessageLabel;

    void setupUi(QWidget *register_widget)
    {
        if (register_widget->objectName().isEmpty())
            register_widget->setObjectName("register_widget");
        register_widget->resize(236, 280);
        layoutWidget = new QWidget(register_widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 20, 191, 231));
        register_widget_layout = new QVBoxLayout(layoutWidget);
        register_widget_layout->setObjectName("register_widget_layout");
        register_widget_layout->setContentsMargins(0, 0, 0, 0);
        registerUsernameLabel = new QLabel(layoutWidget);
        registerUsernameLabel->setObjectName("registerUsernameLabel");

        register_widget_layout->addWidget(registerUsernameLabel);

        registerUsernameEdit = new QLineEdit(layoutWidget);
        registerUsernameEdit->setObjectName("registerUsernameEdit");

        register_widget_layout->addWidget(registerUsernameEdit);

        registerPasswordLabel = new QLabel(layoutWidget);
        registerPasswordLabel->setObjectName("registerPasswordLabel");

        register_widget_layout->addWidget(registerPasswordLabel);

        registerPasswordEdit = new QLineEdit(layoutWidget);
        registerPasswordEdit->setObjectName("registerPasswordEdit");

        register_widget_layout->addWidget(registerPasswordEdit);

        registerConfirmPasswordLabel = new QLabel(layoutWidget);
        registerConfirmPasswordLabel->setObjectName("registerConfirmPasswordLabel");

        register_widget_layout->addWidget(registerConfirmPasswordLabel);

        registerConfirmPasswordEdit = new QLineEdit(layoutWidget);
        registerConfirmPasswordEdit->setObjectName("registerConfirmPasswordEdit");

        register_widget_layout->addWidget(registerConfirmPasswordEdit);

        registerRegisterButton = new QPushButton(layoutWidget);
        registerRegisterButton->setObjectName("registerRegisterButton");

        register_widget_layout->addWidget(registerRegisterButton);

        registerCancelButton = new QPushButton(layoutWidget);
        registerCancelButton->setObjectName("registerCancelButton");

        register_widget_layout->addWidget(registerCancelButton);

        registerMessageLabel = new QLabel(layoutWidget);
        registerMessageLabel->setObjectName("registerMessageLabel");

        register_widget_layout->addWidget(registerMessageLabel);


        retranslateUi(register_widget);

        QMetaObject::connectSlotsByName(register_widget);
    } // setupUi

    void retranslateUi(QWidget *register_widget)
    {
        register_widget->setWindowTitle(QCoreApplication::translate("register_widget", "Form", nullptr));
        registerUsernameLabel->setText(QCoreApplication::translate("register_widget", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        registerUsernameEdit->setPlaceholderText(QCoreApplication::translate("register_widget", "kriper2004", nullptr));
        registerPasswordLabel->setText(QCoreApplication::translate("register_widget", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        registerPasswordEdit->setPlaceholderText(QCoreApplication::translate("register_widget", "pass", nullptr));
        registerConfirmPasswordLabel->setText(QCoreApplication::translate("register_widget", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        registerConfirmPasswordEdit->setPlaceholderText(QCoreApplication::translate("register_widget", "pass", nullptr));
        registerRegisterButton->setText(QCoreApplication::translate("register_widget", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217!", nullptr));
        registerCancelButton->setText(QCoreApplication::translate("register_widget", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        registerMessageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class register_widget: public Ui_register_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_WINDOW_H
