/********************************************************************************
** Form generated from reading UI file 'route_card_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUTE_CARD_WIDGET_H
#define UI_ROUTE_CARD_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_route_card_widget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *routeCardTitleLabel;
    QLabel *routeCardDescriptionLabel;
    QListWidget *routeCardPointsList;
    QGraphicsView *routeCardMapView;
    QPushButton *routeCardRateButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *route_card_widget)
    {
        if (route_card_widget->objectName().isEmpty())
            route_card_widget->setObjectName("route_card_widget");
        route_card_widget->resize(689, 452);
        widget = new QWidget(route_card_widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 40, 441, 321));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        routeCardTitleLabel = new QLabel(widget);
        routeCardTitleLabel->setObjectName("routeCardTitleLabel");

        gridLayout->addWidget(routeCardTitleLabel, 0, 0, 1, 3);

        routeCardDescriptionLabel = new QLabel(widget);
        routeCardDescriptionLabel->setObjectName("routeCardDescriptionLabel");

        gridLayout->addWidget(routeCardDescriptionLabel, 1, 0, 1, 3);

        routeCardPointsList = new QListWidget(widget);
        routeCardPointsList->setObjectName("routeCardPointsList");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(routeCardPointsList->sizePolicy().hasHeightForWidth());
        routeCardPointsList->setSizePolicy(sizePolicy);

        gridLayout->addWidget(routeCardPointsList, 2, 0, 1, 1);

        routeCardMapView = new QGraphicsView(widget);
        routeCardMapView->setObjectName("routeCardMapView");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(routeCardMapView->sizePolicy().hasHeightForWidth());
        routeCardMapView->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(routeCardMapView, 2, 2, 1, 1);

        routeCardRateButton = new QPushButton(widget);
        routeCardRateButton->setObjectName("routeCardRateButton");

        gridLayout->addWidget(routeCardRateButton, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);


        retranslateUi(route_card_widget);

        QMetaObject::connectSlotsByName(route_card_widget);
    } // setupUi

    void retranslateUi(QWidget *route_card_widget)
    {
        route_card_widget->setWindowTitle(QCoreApplication::translate("route_card_widget", "Form", nullptr));
        routeCardTitleLabel->setText(QCoreApplication::translate("route_card_widget", "routeCardTitleLabel", nullptr));
        routeCardDescriptionLabel->setText(QCoreApplication::translate("route_card_widget", "routeCardDescriptionLabel", nullptr));
        routeCardRateButton->setText(QCoreApplication::translate("route_card_widget", "\320\236\321\206\320\265\320\275\320\270\321\202\321\214 \320\274\320\260\321\200\321\210\321\200\321\203\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class route_card_widget: public Ui_route_card_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTE_CARD_WIDGET_H
