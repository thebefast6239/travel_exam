/********************************************************************************
** Form generated from reading UI file 'profile_window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_WINDOW_H
#define UI_PROFILE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profile_widget
{
public:
    QWidget *layoutWidget;
    QGridLayout *profile_widget_layout;
    QPushButton *editRouteButton;
    QPushButton *backButton;
    QSpacerItem *verticalSpacer;
    QPushButton *deleteRouteButton;
    QListWidget *listWidget;

    void setupUi(QWidget *profile_widget)
    {
        if (profile_widget->objectName().isEmpty())
            profile_widget->setObjectName("profile_widget");
        profile_widget->resize(425, 305);
        layoutWidget = new QWidget(profile_widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 20, 379, 278));
        profile_widget_layout = new QGridLayout(layoutWidget);
        profile_widget_layout->setObjectName("profile_widget_layout");
        profile_widget_layout->setContentsMargins(0, 0, 0, 0);
        editRouteButton = new QPushButton(layoutWidget);
        editRouteButton->setObjectName("editRouteButton");

        profile_widget_layout->addWidget(editRouteButton, 0, 1, 2, 1);

        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName("backButton");

        profile_widget_layout->addWidget(backButton, 6, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        profile_widget_layout->addItem(verticalSpacer, 3, 1, 1, 1);

        deleteRouteButton = new QPushButton(layoutWidget);
        deleteRouteButton->setObjectName("deleteRouteButton");

        profile_widget_layout->addWidget(deleteRouteButton, 4, 1, 1, 1);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);

        profile_widget_layout->addWidget(listWidget, 0, 0, 5, 1);


        retranslateUi(profile_widget);

        QMetaObject::connectSlotsByName(profile_widget);
    } // setupUi

    void retranslateUi(QWidget *profile_widget)
    {
        profile_widget->setWindowTitle(QCoreApplication::translate("profile_widget", "Travelfimov | \320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        editRouteButton->setText(QCoreApplication::translate("profile_widget", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\321\203\321\202\321\214", nullptr));
        backButton->setText(QCoreApplication::translate("profile_widget", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\275\320\260\320\267\320\260\320\264", nullptr));
        deleteRouteButton->setText(QCoreApplication::translate("profile_widget", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\321\203\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profile_widget: public Ui_profile_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_WINDOW_H
