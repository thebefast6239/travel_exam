/********************************************************************************
** Form generated from reading UI file 'create_route_window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_ROUTE_WINDOW_H
#define UI_CREATE_ROUTE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_create_route_widget
{
public:
    QWidget *layoutWidget;
    QGridLayout *create_route_widget_layout;
    QGraphicsView *mapView;
    QLabel *descriptionLabel;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QTextEdit *descriptionEdit;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *titleEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addPointButton;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QListWidget *routePointsList;

    void setupUi(QWidget *create_route_widget)
    {
        if (create_route_widget->objectName().isEmpty())
            create_route_widget->setObjectName("create_route_widget");
        create_route_widget->resize(666, 501);
        layoutWidget = new QWidget(create_route_widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 561, 461));
        create_route_widget_layout = new QGridLayout(layoutWidget);
        create_route_widget_layout->setObjectName("create_route_widget_layout");
        create_route_widget_layout->setContentsMargins(0, 0, 0, 0);
        mapView = new QGraphicsView(layoutWidget);
        mapView->setObjectName("mapView");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mapView->sizePolicy().hasHeightForWidth());
        mapView->setSizePolicy(sizePolicy);

        create_route_widget_layout->addWidget(mapView, 5, 6, 5, 1);

        descriptionLabel = new QLabel(layoutWidget);
        descriptionLabel->setObjectName("descriptionLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(descriptionLabel->sizePolicy().hasHeightForWidth());
        descriptionLabel->setSizePolicy(sizePolicy1);
        descriptionLabel->setFrameShape(QFrame::Shape::NoFrame);
        descriptionLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        create_route_widget_layout->addWidget(descriptionLabel, 2, 1, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        create_route_widget_layout->addItem(verticalSpacer_2, 3, 3, 1, 4);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        create_route_widget_layout->addItem(verticalSpacer, 1, 3, 1, 4);

        descriptionEdit = new QTextEdit(layoutWidget);
        descriptionEdit->setObjectName("descriptionEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(descriptionEdit->sizePolicy().hasHeightForWidth());
        descriptionEdit->setSizePolicy(sizePolicy2);

        create_route_widget_layout->addWidget(descriptionEdit, 2, 3, 1, 4);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        create_route_widget_layout->addItem(horizontalSpacer_3, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(5, 5, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        create_route_widget_layout->addItem(horizontalSpacer, 2, 7, 1, 1);

        titleLabel = new QLabel(layoutWidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        create_route_widget_layout->addWidget(titleLabel, 0, 1, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 90, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        create_route_widget_layout->addItem(verticalSpacer_3, 7, 5, 1, 1);

        titleEdit = new QLineEdit(layoutWidget);
        titleEdit->setObjectName("titleEdit");

        create_route_widget_layout->addWidget(titleEdit, 0, 3, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        create_route_widget_layout->addItem(horizontalSpacer_2, 7, 4, 1, 1);

        addPointButton = new QPushButton(layoutWidget);
        addPointButton->setObjectName("addPointButton");

        create_route_widget_layout->addWidget(addPointButton, 5, 4, 2, 2);

        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName("saveButton");

        create_route_widget_layout->addWidget(saveButton, 8, 4, 1, 2);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName("cancelButton");

        create_route_widget_layout->addWidget(cancelButton, 9, 4, 1, 2);

        routePointsList = new QListWidget(layoutWidget);
        routePointsList->setObjectName("routePointsList");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(routePointsList->sizePolicy().hasHeightForWidth());
        routePointsList->setSizePolicy(sizePolicy3);

        create_route_widget_layout->addWidget(routePointsList, 5, 2, 5, 2);


        retranslateUi(create_route_widget);

        QMetaObject::connectSlotsByName(create_route_widget);
    } // setupUi

    void retranslateUi(QWidget *create_route_widget)
    {
        create_route_widget->setWindowTitle(QCoreApplication::translate("create_route_widget", "Form", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("create_route_widget", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        titleLabel->setText(QCoreApplication::translate("create_route_widget", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        addPointButton->setText(QCoreApplication::translate("create_route_widget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", nullptr));
        saveButton->setText(QCoreApplication::translate("create_route_widget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        cancelButton->setText(QCoreApplication::translate("create_route_widget", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class create_route_widget: public Ui_create_route_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_ROUTE_WINDOW_H
